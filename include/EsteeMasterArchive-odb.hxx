// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ESTEE_MASTER_ARCHIVE_ODB_HXX
#define ESTEE_MASTER_ARCHIVE_ODB_HXX

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

#include "EsteeMasterArchive.h"

#include "EsteeMaster-odb.hxx"

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
  // EsteeMaster_Archive
  //
  template <>
  struct class_traits< ::EsteeMaster_Archive >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::EsteeMaster_Archive >
  {
    public:
    typedef ::EsteeMaster_Archive object_type;
    typedef ::boost::shared_ptr< ::EsteeMaster_Archive > pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef object_traits< ::EsteeMaster >::id_type id_type;

    static const bool auto_id = object_traits< ::EsteeMaster >::auto_id;

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
  struct query_columns< ::EsteeMaster_Archive, id_common, A >:
    query_columns< ::EsteeMaster, id_common, A >
  {
    // EsteeMaster
    //
    typedef query_columns< ::EsteeMaster, id_common, A > EsteeMaster;

    // ID
    //
    typedef odb::query_column< int > ID_type_;

    static ID_type_ ID;
  };

#ifdef ODB_COMMON_QUERY_COLUMNS_DEF

  template <typename A>
  typename query_columns< ::EsteeMaster_Archive, id_common, A >::ID_type_
  query_columns< ::EsteeMaster_Archive, id_common, A >::ID;

#endif // ODB_COMMON_QUERY_COLUMNS_DEF

  template <typename A>
  struct pointer_query_columns< ::EsteeMaster_Archive, id_common, A >:
    query_columns< ::EsteeMaster_Archive, id_common, A >
  {
  };

  template <>
  class access::object_traits_impl< ::EsteeMaster_Archive, id_common >:
    public access::object_traits< ::EsteeMaster_Archive >
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

  // EsteeMaster_Archive
  //
}

#include "EsteeMasterArchive-odb.ixx"

#include <odb/post.hxx>

#endif // ESTEE_MASTER_ARCHIVE_ODB_HXX
