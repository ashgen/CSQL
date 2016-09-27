// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ESTEE_MASTER_ODB_MSSQL_HXX
#define ESTEE_MASTER_ODB_MSSQL_HXX

// Begin prologue.
//
#include <odb/boost/version.hxx>
#if ODB_BOOST_VERSION != 2040000 // 2.4.0
#  error ODB and C++ compilers see different libodb-boost interface versions
#endif
#include <boost/shared_ptr.hpp>
#include <odb/boost/smart-ptr/pointer-traits.hxx>
#include <odb/boost/smart-ptr/wrapper-traits.hxx>
#include <odb/boost/optional/wrapper-traits.hxx>
#include <odb/boost/unordered/container-traits.hxx>
#include <odb/boost/date-time/mssql/gregorian-traits.hxx>
#include <odb/boost/date-time/mssql/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/mssql/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "EsteeMaster.h"

#include "EsteeMaster-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/mssql/version.hxx>
#include <odb/mssql/forward.hxx>
#include <odb/mssql/binding.hxx>
#include <odb/mssql/mssql-types.hxx>
#include <odb/mssql/query.hxx>
#include <odb/mssql/query-dynamic.hxx>

namespace odb
{
  // EsteeMaster
  //
  template <typename A>
  struct query_columns< ::EsteeMaster, id_mssql, A >
  {
    // DataFeed_Ticker
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    DataFeed_Ticker_type_;

    static const DataFeed_Ticker_type_ DataFeed_Ticker;

    // Underlying_Ticker
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Underlying_Ticker_type_;

    static const Underlying_Ticker_type_ Underlying_Ticker;

    // ISIN
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    ISIN_type_;

    static const ISIN_type_ ISIN;

    // Exchange_Code
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Exchange_Code_type_;

    static const Exchange_Code_type_ Exchange_Code;

    // Option_Type
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Option_Type_type_;

    static const Option_Type_type_ Option_Type;

    // Status
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Status_type_;

    static const Status_type_ Status;

    // TOKEN2
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    TOKEN2_type_;

    static const TOKEN2_type_ TOKEN2;

    // Expiry_Date2
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Expiry_Date2_type_;

    static const Expiry_Date2_type_ Expiry_Date2;

    // SERIES
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    SERIES_type_;

    static const SERIES_type_ SERIES;

    // Source
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Source_type_;

    static const Source_type_ Source;

    // UnderlyingEstee_Id
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    UnderlyingEstee_Id_type_;

    static const UnderlyingEstee_Id_type_ UnderlyingEstee_Id;

    // Strike_Price
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        double,
        mssql::id_float8 >::query_type,
      mssql::id_float8 >
    Strike_Price_type_;

    static const Strike_Price_type_ Strike_Price;

    // Tick_Size
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        double,
        mssql::id_float8 >::query_type,
      mssql::id_float8 >
    Tick_Size_type_;

    static const Tick_Size_type_ Tick_Size;

    // Lot_Size
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    Lot_Size_type_;

    static const Lot_Size_type_ Lot_Size;

    // Security_Type
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    Security_Type_type_;

    static const Security_Type_type_ Security_Type;

    // Token
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    Token_type_;

    static const Token_type_ Token;

    // Quote_Size
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    Quote_Size_type_;

    static const Quote_Size_type_ Quote_Size;

    // Instrument_Type
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    Instrument_Type_type_;

    static const Instrument_Type_type_ Instrument_Type;

    // TradingCurrency
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    TradingCurrency_type_;

    static const TradingCurrency_type_ TradingCurrency;

    // SettlementCurrency
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    SettlementCurrency_type_;

    static const SettlementCurrency_type_ SettlementCurrency;

    // TickSizeSlabId
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        int,
        mssql::id_int >::query_type,
      mssql::id_int >
    TickSizeSlabId_type_;

    static const TickSizeSlabId_type_ TickSizeSlabId;

    // AsOfDate
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    AsOfDate_type_;

    static const AsOfDate_type_ AsOfDate;

    // Last_update_time
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    Last_update_time_type_;

    static const Last_update_time_type_ Last_update_time;

    // Expiry_Date
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    Expiry_Date_type_;

    static const Expiry_Date_type_ Expiry_Date;

    // SettlementDate
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    SettlementDate_type_;

    static const SettlementDate_type_ SettlementDate;

    // TradingStartDate
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    TradingStartDate_type_;

    static const TradingStartDate_type_ TradingStartDate;

    // LastTradingDate
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::boost::posix_time::ptime,
        mssql::id_datetime >::query_type,
      mssql::id_datetime >
    LastTradingDate_type_;

    static const LastTradingDate_type_ LastTradingDate;

    // Estee_ID
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    Estee_ID_type_;

    static const Estee_ID_type_ Estee_ID;
  };

#ifdef ODB_MSSQL_QUERY_COLUMNS_DEF

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::DataFeed_Ticker_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  DataFeed_Ticker (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::DataFeed_Ticker,
                   A::table_name, "[DataFeed_Ticker]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Underlying_Ticker_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Underlying_Ticker (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Underlying_Ticker,
                     A::table_name, "[Underlying_Ticker]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::ISIN_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  ISIN (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::ISIN,
        A::table_name, "[ISIN]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Exchange_Code_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Exchange_Code (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Exchange_Code,
                 A::table_name, "[Exchange_Code]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Option_Type_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Option_Type (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Option_Type,
               A::table_name, "[Option_Type]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Status_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Status (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Status,
          A::table_name, "[Status]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::TOKEN2_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  TOKEN2 (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::TOKEN2,
          A::table_name, "[TOKEN2]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Expiry_Date2_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Expiry_Date2 (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Expiry_Date2,
                A::table_name, "[Expiry_Date2]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::SERIES_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  SERIES (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::SERIES,
          A::table_name, "[SERIES]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Source_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Source (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Source,
          A::table_name, "[Source]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::UnderlyingEstee_Id_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  UnderlyingEstee_Id (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::UnderlyingEstee_Id,
                      A::table_name, "[UnderlyingEstee_Id]", 0, 512);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Strike_Price_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Strike_Price (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Strike_Price,
                A::table_name, "[Strike_Price]", 0, 53);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Tick_Size_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Tick_Size (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Tick_Size,
             A::table_name, "[Tick_Size]", 0, 53);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Lot_Size_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Lot_Size (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Lot_Size,
            A::table_name, "[Lot_Size]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Security_Type_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Security_Type (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Security_Type,
                 A::table_name, "[Security_Type]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Token_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Token (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Token,
         A::table_name, "[Token]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Quote_Size_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Quote_Size (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Quote_Size,
              A::table_name, "[Quote_Size]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Instrument_Type_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Instrument_Type (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Instrument_Type,
                   A::table_name, "[Instrument_Type]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::TradingCurrency_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  TradingCurrency (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::TradingCurrency,
                   A::table_name, "[TradingCurrency]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::SettlementCurrency_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  SettlementCurrency (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::SettlementCurrency,
                      A::table_name, "[SettlementCurrency]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::TickSizeSlabId_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  TickSizeSlabId (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::TickSizeSlabId,
                  A::table_name, "[TickSizeSlabId]", 0);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::AsOfDate_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  AsOfDate (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::AsOfDate,
            A::table_name, "[AsOfDate]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Last_update_time_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Last_update_time (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Last_update_time,
                    A::table_name, "[Last_update_time]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Expiry_Date_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Expiry_Date (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Expiry_Date,
               A::table_name, "[Expiry_Date]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::SettlementDate_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  SettlementDate (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::SettlementDate,
                  A::table_name, "[SettlementDate]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::TradingStartDate_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  TradingStartDate (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::TradingStartDate,
                    A::table_name, "[TradingStartDate]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::LastTradingDate_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  LastTradingDate (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::LastTradingDate,
                   A::table_name, "[LastTradingDate]", 0, 0, 3);

  template <typename A>
  const typename query_columns< ::EsteeMaster, id_mssql, A >::Estee_ID_type_
  query_columns< ::EsteeMaster, id_mssql, A >::
  Estee_ID (query_columns< ::EsteeMaster, id_common, typename A::common_traits >::Estee_ID,
            A::table_name, "[Estee_ID]", 0, 256);

#endif // ODB_MSSQL_QUERY_COLUMNS_DEF

  template <typename A>
  struct pointer_query_columns< ::EsteeMaster, id_mssql, A >:
    query_columns< ::EsteeMaster, id_mssql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::EsteeMaster, id_mssql >:
    public access::object_traits< ::EsteeMaster >
  {
    public:
    static const std::size_t batch = 1UL;

    static const bool rowversion = false;

    typedef access::object_traits_impl< ::EsteeMaster, id_common > common_traits;

    struct id_image_type
    {
      char id_value[257];
      SQLLEN id_size_ind;

      std::size_t version;
    };

    struct image_type
    {
      // DataFeed_Ticker
      //
      char DataFeed_Ticker_value[513];
      SQLLEN DataFeed_Ticker_size_ind;

      // Underlying_Ticker
      //
      char Underlying_Ticker_value[513];
      SQLLEN Underlying_Ticker_size_ind;

      // ISIN
      //
      char ISIN_value[513];
      SQLLEN ISIN_size_ind;

      // Exchange_Code
      //
      char Exchange_Code_value[513];
      SQLLEN Exchange_Code_size_ind;

      // Option_Type
      //
      char Option_Type_value[513];
      SQLLEN Option_Type_size_ind;

      // Status
      //
      char Status_value[513];
      SQLLEN Status_size_ind;

      // TOKEN2
      //
      char TOKEN2_value[513];
      SQLLEN TOKEN2_size_ind;

      // Expiry_Date2
      //
      char Expiry_Date2_value[513];
      SQLLEN Expiry_Date2_size_ind;

      // SERIES
      //
      char SERIES_value[513];
      SQLLEN SERIES_size_ind;

      // Source
      //
      char Source_value[513];
      SQLLEN Source_size_ind;

      // UnderlyingEstee_Id
      //
      char UnderlyingEstee_Id_value[513];
      SQLLEN UnderlyingEstee_Id_size_ind;

      // Strike_Price
      //
      double Strike_Price_value;
      SQLLEN Strike_Price_size_ind;

      // Tick_Size
      //
      double Tick_Size_value;
      SQLLEN Tick_Size_size_ind;

      // Lot_Size
      //
      int Lot_Size_value;
      SQLLEN Lot_Size_size_ind;

      // Security_Type
      //
      int Security_Type_value;
      SQLLEN Security_Type_size_ind;

      // Token
      //
      int Token_value;
      SQLLEN Token_size_ind;

      // Quote_Size
      //
      int Quote_Size_value;
      SQLLEN Quote_Size_size_ind;

      // Instrument_Type
      //
      int Instrument_Type_value;
      SQLLEN Instrument_Type_size_ind;

      // TradingCurrency
      //
      int TradingCurrency_value;
      SQLLEN TradingCurrency_size_ind;

      // SettlementCurrency
      //
      int SettlementCurrency_value;
      SQLLEN SettlementCurrency_size_ind;

      // TickSizeSlabId
      //
      int TickSizeSlabId_value;
      SQLLEN TickSizeSlabId_size_ind;

      // AsOfDate
      //
      mssql::datetime AsOfDate_value;
      SQLLEN AsOfDate_size_ind;

      // Last_update_time
      //
      mssql::datetime Last_update_time_value;
      SQLLEN Last_update_time_size_ind;

      // Expiry_Date
      //
      mssql::datetime Expiry_Date_value;
      SQLLEN Expiry_Date_size_ind;

      // SettlementDate
      //
      mssql::datetime SettlementDate_value;
      SQLLEN SettlementDate_size_ind;

      // TradingStartDate
      //
      mssql::datetime TradingStartDate_value;
      SQLLEN TradingStartDate_size_ind;

      // LastTradingDate
      //
      mssql::datetime LastTradingDate_value;
      SQLLEN LastTradingDate_size_ind;

      // Estee_ID
      //
      char Estee_ID_value[257];
      SQLLEN Estee_ID_size_ind;

      std::size_t version;

      mssql::change_callback change_callback_;

      mssql::change_callback*
      change_callback ()
      {
        return &change_callback_;
      }
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static void
    bind (mssql::bind*,
          image_type&,
          mssql::statement_kind);

    static void
    bind (mssql::bind*, id_image_type&);

    static void
    init (image_type&,
          const object_type&,
          mssql::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef mssql::object_statements<object_type> statements_type;

    typedef mssql::query_base query_base_type;

    static const std::size_t column_count = 28UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&);

    static bool
    reload (database&, object_type&);

    static void
    update (database&, const object_type&);

    static void
    erase (database&, const id_type&);

    static void
    erase (database&, const object_type&);

    static result<object_type>
    query (database&, const query_base_type&);

    static result<object_type>
    query (database&, const odb::query_base&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const odb::query_base&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  // EsteeMaster
  //
}

#include "EsteeMaster-odb-mssql.ixx"

#include <odb/post.hxx>

#endif // ESTEE_MASTER_ODB_MSSQL_HXX
