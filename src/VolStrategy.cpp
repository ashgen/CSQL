/*
 * VolStrategy.cpp
 *
 *  Created on: 16-Sep-2016
 *      Author: ashish
 */

#include "VolStrategy.h"
#include <spdlog/fmt/ostr.h>
#include <boost/exception/diagnostic_information.hpp>
#include <iterator>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include "eaCommon.h"
using namespace odb::core;
using odb::database;
using odb::transaction;
namespace data {
template <typename T>
void getData(const std::shared_ptr<odb::database> db, const odb::query<T> &statement, odb::result<T> &res) {
  try {
    res = db->query<T>(statement);
  } catch (std::exception &e) {
    std::cout << e.what();
  }
}
}
VolStrategy::VolStrategy(const std::string &path) {
  con = std::shared_ptr<Connection>(new Connection(path));
  esteeId = con->getConfig()->esteeID();
  startdate = con->getConfig()->startdate();
  enddate = con->getConfig()->enddate();
  logger = con->getConfig()->log();
  archivelogger = con->getConfig()->archivelog();
  vollogger = con->getConfig()->vollog();
}
odb::result<closingPrice> VolStrategy::getData(std::string esteeID, btime::ptime startdate, btime::ptime enddate) {
  typedef odb::query<closingPrice> query;
  typedef odb::result<closingPrice> result;
  result res, data;
  query q(query::id.Estee_ID == esteeID && query::id.Date >= startdate && query::id.Date <= enddate);
  data::getData<closingPrice>(con->getConnection(), q, res);
  data = std::move(res);
  for (auto r = res.begin(); r != res.end(); ++r) {
    std::cout << r->_id.Estee_ID << ":" << r->_id.Date << std::endl;
  }
  return data;
}

void VolStrategy::getUnderlyingData() {
  typedef odb::query<closingPrice> query;
  typedef odb::result<closingPrice> result;
  result res;
  transaction t(con->getConnection()->begin());
  // t.tracer (stderr_tracer);
  query q(query::id.Estee_ID == esteeId && query::id.Date >= startdate && query::id.Date <= enddate);
  data::getData<closingPrice>(con->getConnection(), q, res);
  for (auto r = res.begin(); r != res.end(); ++r) {
    std::cout << r->_id.Estee_ID << ":" << r->_id.Date << std::endl;
  }
  t.commit();
}

void VolStrategy::getAllData() {
  typedef odb::query<EsteeMaster_Archive> masterquery;
  typedef odb::result<EsteeMaster_Archive> masterresult;
  typedef odb::query<closingPrice> pricequery;
  typedef odb::result<closingPrice> priceresult;
  transaction t(con->getConnection()->begin());
  try {
    t.tracer(stderr_tracer);
    masterresult res;
    masterquery q(masterquery::UnderlyingEstee_Id == esteeId && masterquery::Expiry_Date >= startdate && masterquery::Expiry_Date <= enddate &&
                  masterquery::Security_Type.in(eaSecurityType::INDEXSPOT, eaSecurityType::INDEXFUTURES, eaSecurityType::INDEXCALL, eaSecurityType::INDEXPUT) /*+
                    /*"ORDER BY" + masterquery::Security_Type*/);
    data::getData<EsteeMaster_Archive>(con->getConnection(), q, res);
    for (EsteeMaster_Archive &b : res) {
      if (((std::find(listOfExpiries.begin(), listOfExpiries.end(), b.Expiry_Date) == listOfExpiries.end()) && !b.Expiry_Date.is_not_a_date_time())) listOfExpiries.push_back(b.Expiry_Date);
    }

    data::getData<EsteeMaster_Archive>(con->getConnection(), q, res);
    std::sort(listOfExpiries.begin(), listOfExpiries.end());
    for (EsteeMaster_Archive &a : res) {
      archivelogger->info("{}", a);
      pricequery querydata(pricequery::id.Estee_ID == a.getEsteeID() && pricequery::id.Date >= startdate && pricequery::id.Date <= enddate && pricequery::Open_Interest > 0 && pricequery::Volume > 0);
      priceresult priceres;
      int index = 0;
      std::shared_ptr<FOUnit> unit;
      data::getData<closingPrice>(con->getConnection(), querydata, priceres);
      for (closingPrice &r : priceres) {
        logger->info("{}", r);
        if (a.Security_Type != eaSecurityType::INDEXSPOT) {
          // Calculate the index
          auto funIndex = [this, &r, &a]() -> int {
            auto i = std::lower_bound(listOfExpiries.begin(), listOfExpiries.end(), r._id.Date);
            auto b = std::find(listOfExpiries.begin(), listOfExpiries.end(), a.Expiry_Date);
            /*
            std::cout << "Date:" << *i << ":"
                      << "ExpiryDate"
                      << ":" << *b << std::endl;*/
            return std::distance(i, b);
          };
          index = funIndex();
        }
        if (mDateFOUnit.find(r._id.Date) == mDateFOUnit.end()) {
          unit = std::make_shared<FOUnit>(new FOUnit(vollogger));
          mDateFOUnit.insert(std::make_pair(r._id.Date, unit));
        } else {
          unit = mDateFOUnit[r._id.Date];
        }

        switch (a.Security_Type) {
          case 4:
            unit->spot = std::shared_ptr<Underlying::Spot>(new Underlying::Spot(r, a));
            break;
          case 5:
            unit->future.insert(std::pair<int, std::shared_ptr<Underlying::Future>>(index, std::shared_ptr<Underlying::Future>(new Underlying::Future(index, a, r))));
            break;
          case 6: {
            auto it = unit->call.find(index);
            if (it == unit->call.end()) {
              auto b = std::shared_ptr<Underlying::Option>(new Underlying::Option(index, a, r));
              std::vector<std::shared_ptr<Underlying::Option>> a;
              a.push_back(b);
              unit->call.insert(std::pair<int, std::vector<std::shared_ptr<Underlying::Option>>>(index, a));
            } else {
              it->second.push_back(std::shared_ptr<Underlying::Option>(new Underlying::Option(index, a, r)));
            }
          } break;
          case 7: {
            auto it = unit->put.find(index);
            if (it == unit->put.end()) {
              auto b = std::shared_ptr<Underlying::Option>(new Underlying::Option(index, a, r));
              std::vector<std::shared_ptr<Underlying::Option>> a;
              a.push_back(b);
              unit->put.insert(std::pair<int, std::vector<std::shared_ptr<Underlying::Option>>>(index, a));
            } else {
              it->second.push_back(std::shared_ptr<Underlying::Option>(new Underlying::Option(index, a, r)));
            }
          } break;
          default:
            break;
        }
      }
    }
    t.commit();
  } catch (odb::exception &e) {
    std::cout << e.what();
  } catch (boost::exception &e) {
    boost::current_exception_diagnostic_information();
  }
}
void VolStrategy::calculate() {
  for (auto &e : mDateFOUnit) {
    logger->info("calculating for the following date{}", e.first);
    e.second->calculate();
  }
}

void VolStrategy::Initialise() {
  initialiseLogger();
  getAllData();
  eaBlackScholes::ComputeNRInitialIVEstimate();
  calculate();
}
void VolStrategy::initialiseLogger() { vollogger->info("Date,Expiry_Date,Type,Strike,timetoExpiry,future,rate,price,IV,delta,gamma,theta,vega,rho"); }
