// file      : hello/driver.cxx
// copyright : not copyrighted - public domain

#include <memory>   // std::auto_ptr
#include <iostream>

#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <odb/mssql/database.hxx>

#include "EsteeMaster.h"
#include "EsteeMaster-odb.hxx"


using namespace std;
using namespace odb::core;

static const std::string user ="esteejobs";
static const std::string password ="estee123";
static const std::string dbname ="Dev_Estee_NSE";
static const std::string server ="191.191.191.151";

int main (int argc, char* argv[])
{
  try
  {

    database* db =new odb::mssql::database(user,password,dbname,server);

    typedef odb::query<EsteeMaster> query;
    typedef odb::result<EsteeMaster> result;
    {
      transaction t (db->begin ());

      result r (db->query<EsteeMaster> (query::ISIN=="IN0000000001"));

      for (result::iterator i (r.begin ()); i != r.end (); ++i)
      {
        cout << "Hello, " << i->Estee_ID << endl;
      }

      t.commit ();
    }

    delete db;
  }
  catch (const odb::exception& e)
  {

    cerr << e.what () << endl;
    return 1;
  }
}
