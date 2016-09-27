// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef ESTEE_MASTER_ARCHIVE_ODB_SQLITE_HXX
#define ESTEE_MASTER_ARCHIVE_ODB_SQLITE_HXX

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
#include <odb/boost/date-time/sqlite/gregorian-traits.hxx>
#include <odb/boost/date-time/sqlite/posix-time-traits.hxx>
#include <odb/boost/multi-index/container-traits.hxx>
#include <odb/boost/uuid/sqlite/uuid-traits.hxx>
//
// End prologue.

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "EsteeMasterArchive.h"

#include "EsteeMaster-odb-sqlite.hxx"

#include "EsteeMasterArchive-odb.hxx"

#include <odb/details/buffer.hxx>

#include <odb/sqlite/version.hxx>
#include <odb/sqlite/forward.hxx>
#include <odb/sqlite/binding.hxx>
#include <odb/sqlite/sqlite-types.hxx>
#include <odb/sqlite/query.hxx>
#include <odb/sqlite/query-dynamic.hxx>

namespace odb
{
  // EsteeMaster_Archive
  //
  template <typename A>
  struct query_columns< ::EsteeMaster_Archive, id_sqlite, A >:
    query_columns< ::EsteeMaster, id_sqlite, A >
  {
    // EsteeMaster
    //
    typedef query_columns< ::EsteeMaster, id_sqlite, A > EsteeMaster;

    // ID
    //
    typedef
    sqlite::query_column<
      sqlite::value_traits<
        int,
        sqlite::id_integer >::query_type,
      sqlite::id_integer >
    ID_type_;

    static const ID_type_ ID;
  };

#ifdef ODB_SQLITE_QUERY_COLUMNS_DEF

  template <typename A>
  const typename query_columns< ::EsteeMaster_Archive, id_sqlite, A >::ID_type_
  query_columns< ::EsteeMaster_Archive, id_sqlite, A >::
  ID (query_columns< ::EsteeMaster_Archive, id_common, typename A::common_traits >::ID,
      A::table_name, "\"ID\"", 0);

#endif // ODB_SQLITE_QUERY_COLUMNS_DEF

  template <typename A>
  struct pointer_query_columns< ::EsteeMaster_Archive, id_sqlite, A >:
    query_columns< ::EsteeMaster_Archive, id_sqlite, A >
  {
  };

  template <>
  class access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >:
    public access::object_traits< ::EsteeMaster_Archive >
  {
    public:
    typedef access::object_traits_impl< ::EsteeMaster_Archive, id_common > common_traits;

    typedef object_traits_impl< ::EsteeMaster, id_sqlite >::id_image_type id_image_type;

    struct image_type: object_traits_impl< ::EsteeMaster, id_sqlite >::image_type
    {
      // ID
      //
      long long ID_value;
      bool ID_null;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

    static id_type
    id (const image_type&);

    static bool
    grow (image_type&,
          bool*);

    static void
    bind (sqlite::bind*,
          image_type&,
          sqlite::statement_kind);

    static void
    bind (sqlite::bind*, id_image_type&);

    static bool
    init (image_type&,
          const object_type&,
          sqlite::statement_kind);

    static void
    init (object_type&,
          const image_type&,
          database*);

    static void
    init (id_image_type&, const id_type&);

    typedef sqlite::object_statements<object_type> statements_type;

    typedef sqlite::query_base query_base_type;

    static const std::size_t column_count = 29UL;
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

  // EsteeMaster_Archive
  //
}

#include "EsteeMasterArchive-odb-sqlite.ixx"

#include <odb/post.hxx>

#endif // ESTEE_MASTER_ARCHIVE_ODB_SQLITE_HXX
