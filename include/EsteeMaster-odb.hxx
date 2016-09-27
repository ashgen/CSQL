// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ESTEE_MASTER_ODB_HXX
#define ESTEE_MASTER_ODB_HXX

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
#include <odb/boost/multi-index/container-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "EsteeMaster.h"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#ifdef BOOST_TR1_MEMORY_HPP_INCLUDED
#  include <odb/tr1/wrapper-traits.hxx>
#  include <odb/tr1/pointer-traits.hxx>
#endif
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/query-dynamic.hxx>
#include <odb/result.hxx>
#include <odb/simple-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

namespace odb
{
  // EsteeMaster
  //
  template <>
  struct class_traits< ::EsteeMaster >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::EsteeMaster >
  {
    public:
    typedef ::EsteeMaster object_type;
    typedef ::boost::shared_ptr< ::EsteeMaster > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef ::std::string id_type;

    static const bool auto_id = true;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<object_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  template <typename A>
  struct query_columns< ::EsteeMaster, id_common, A >
  {
    // DataFeed_Ticker
    //
    typedef odb::query_column< ::std::string > DataFeed_Ticker_type_;

    static DataFeed_Ticker_type_ DataFeed_Ticker;

    // Underlying_Ticker
    //
    typedef odb::query_column< ::std::string > Underlying_Ticker_type_;

    static Underlying_Ticker_type_ Underlying_Ticker;

    // ISIN
    //
    typedef odb::query_column< ::std::string > ISIN_type_;

    static ISIN_type_ ISIN;

    // Exchange_Code
    //
    typedef odb::query_column< ::std::string > Exchange_Code_type_;

    static Exchange_Code_type_ Exchange_Code;

    // Option_Type
    //
    typedef odb::query_column< ::std::string > Option_Type_type_;

    static Option_Type_type_ Option_Type;

    // Status
    //
    typedef odb::query_column< ::std::string > Status_type_;

    static Status_type_ Status;

    // TOKEN2
    //
    typedef odb::query_column< ::std::string > TOKEN2_type_;

    static TOKEN2_type_ TOKEN2;

    // Expiry_Date2
    //
    typedef odb::query_column< ::std::string > Expiry_Date2_type_;

    static Expiry_Date2_type_ Expiry_Date2;

    // SERIES
    //
    typedef odb::query_column< ::std::string > SERIES_type_;

    static SERIES_type_ SERIES;

    // Source
    //
    typedef odb::query_column< ::std::string > Source_type_;

    static Source_type_ Source;

    // UnderlyingEstee_Id
    //
    typedef odb::query_column< ::std::string > UnderlyingEstee_Id_type_;

    static UnderlyingEstee_Id_type_ UnderlyingEstee_Id;

    // Strike_Price
    //
    typedef odb::query_column< double > Strike_Price_type_;

    static Strike_Price_type_ Strike_Price;

    // Tick_Size
    //
    typedef odb::query_column< double > Tick_Size_type_;

    static Tick_Size_type_ Tick_Size;

    // Lot_Size
    //
    typedef odb::query_column< int > Lot_Size_type_;

    static Lot_Size_type_ Lot_Size;

    // Security_Type
    //
    typedef odb::query_column< int > Security_Type_type_;

    static Security_Type_type_ Security_Type;

    // Token
    //
    typedef odb::query_column< int > Token_type_;

    static Token_type_ Token;

    // Quote_Size
    //
    typedef odb::query_column< int > Quote_Size_type_;

    static Quote_Size_type_ Quote_Size;

    // Instrument_Type
    //
    typedef odb::query_column< int > Instrument_Type_type_;

    static Instrument_Type_type_ Instrument_Type;

    // TradingCurrency
    //
    typedef odb::query_column< int > TradingCurrency_type_;

    static TradingCurrency_type_ TradingCurrency;

    // SettlementCurrency
    //
    typedef odb::query_column< int > SettlementCurrency_type_;

    static SettlementCurrency_type_ SettlementCurrency;

    // TickSizeSlabId
    //
    typedef odb::query_column< int > TickSizeSlabId_type_;

    static TickSizeSlabId_type_ TickSizeSlabId;

    // AsOfDate
    //
    typedef odb::query_column< ::boost::posix_time::ptime > AsOfDate_type_;

    static AsOfDate_type_ AsOfDate;

    // Last_update_time
    //
    typedef odb::query_column< ::boost::posix_time::ptime > Last_update_time_type_;

    static Last_update_time_type_ Last_update_time;

    // Expiry_Date
    //
    typedef odb::query_column< ::boost::posix_time::ptime > Expiry_Date_type_;

    static Expiry_Date_type_ Expiry_Date;

    // SettlementDate
    //
    typedef odb::query_column< ::boost::posix_time::ptime > SettlementDate_type_;

    static SettlementDate_type_ SettlementDate;

    // TradingStartDate
    //
    typedef odb::query_column< ::boost::posix_time::ptime > TradingStartDate_type_;

    static TradingStartDate_type_ TradingStartDate;

    // LastTradingDate
    //
    typedef odb::query_column< ::boost::posix_time::ptime > LastTradingDate_type_;

    static LastTradingDate_type_ LastTradingDate;

    // Estee_ID
    //
    typedef odb::query_column< ::std::string > Estee_ID_type_;

    static Estee_ID_type_ Estee_ID;
  };

#ifdef ODB_COMMON_QUERY_COLUMNS_DEF

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::DataFeed_Ticker_type_
  query_columns< ::EsteeMaster, id_common, A >::DataFeed_Ticker;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Underlying_Ticker_type_
  query_columns< ::EsteeMaster, id_common, A >::Underlying_Ticker;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::ISIN_type_
  query_columns< ::EsteeMaster, id_common, A >::ISIN;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Exchange_Code_type_
  query_columns< ::EsteeMaster, id_common, A >::Exchange_Code;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Option_Type_type_
  query_columns< ::EsteeMaster, id_common, A >::Option_Type;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Status_type_
  query_columns< ::EsteeMaster, id_common, A >::Status;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::TOKEN2_type_
  query_columns< ::EsteeMaster, id_common, A >::TOKEN2;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Expiry_Date2_type_
  query_columns< ::EsteeMaster, id_common, A >::Expiry_Date2;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::SERIES_type_
  query_columns< ::EsteeMaster, id_common, A >::SERIES;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Source_type_
  query_columns< ::EsteeMaster, id_common, A >::Source;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::UnderlyingEstee_Id_type_
  query_columns< ::EsteeMaster, id_common, A >::UnderlyingEstee_Id;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Strike_Price_type_
  query_columns< ::EsteeMaster, id_common, A >::Strike_Price;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Tick_Size_type_
  query_columns< ::EsteeMaster, id_common, A >::Tick_Size;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Lot_Size_type_
  query_columns< ::EsteeMaster, id_common, A >::Lot_Size;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Security_Type_type_
  query_columns< ::EsteeMaster, id_common, A >::Security_Type;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Token_type_
  query_columns< ::EsteeMaster, id_common, A >::Token;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Quote_Size_type_
  query_columns< ::EsteeMaster, id_common, A >::Quote_Size;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Instrument_Type_type_
  query_columns< ::EsteeMaster, id_common, A >::Instrument_Type;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::TradingCurrency_type_
  query_columns< ::EsteeMaster, id_common, A >::TradingCurrency;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::SettlementCurrency_type_
  query_columns< ::EsteeMaster, id_common, A >::SettlementCurrency;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::TickSizeSlabId_type_
  query_columns< ::EsteeMaster, id_common, A >::TickSizeSlabId;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::AsOfDate_type_
  query_columns< ::EsteeMaster, id_common, A >::AsOfDate;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Last_update_time_type_
  query_columns< ::EsteeMaster, id_common, A >::Last_update_time;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Expiry_Date_type_
  query_columns< ::EsteeMaster, id_common, A >::Expiry_Date;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::SettlementDate_type_
  query_columns< ::EsteeMaster, id_common, A >::SettlementDate;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::TradingStartDate_type_
  query_columns< ::EsteeMaster, id_common, A >::TradingStartDate;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::LastTradingDate_type_
  query_columns< ::EsteeMaster, id_common, A >::LastTradingDate;

  template <typename A>
  typename query_columns< ::EsteeMaster, id_common, A >::Estee_ID_type_
  query_columns< ::EsteeMaster, id_common, A >::Estee_ID;

#endif // ODB_COMMON_QUERY_COLUMNS_DEF

  template <typename A>
  struct pointer_query_columns< ::EsteeMaster, id_common, A >:
    query_columns< ::EsteeMaster, id_common, A >
  {
  };

  template <>
  class access::object_traits_impl< ::EsteeMaster, id_common >:
    public access::object_traits< ::EsteeMaster >
  {
    public:
    typedef odb::query_base query_base_type;

    struct function_table_type
    {
      void (*persist) (database&, object_type&);
      pointer_type (*find1) (database&, const id_type&);
      bool (*find2) (database&, const id_type&, object_type&);
      bool (*reload) (database&, object_type&);
      void (*update) (database&, const object_type&);
      void (*erase1) (database&, const id_type&);
      void (*erase2) (database&, const object_type&);
      result<object_type> (*query) (database&, const query_base_type&);
      unsigned long long (*erase_query) (database&, const query_base_type&);
    };

    static const function_table_type* function_table[database_count];

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

    static unsigned long long
    erase_query (database&, const query_base_type&);
  };

  // EsteeMaster
  //
}

#include "EsteeMaster-odb.ixx"

#include <odb/post.hxx>

#endif // ESTEE_MASTER_ODB_HXX
