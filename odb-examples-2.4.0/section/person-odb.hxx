// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef PERSON_ODB_HXX
#define PERSON_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "person.hxx"

#include <memory>
#include <cstddef>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>

#include <odb/details/unused.hxx>

namespace odb
{
  // person
  //
  template <>
  struct class_traits< ::person >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::person >
  {
    public:
    typedef ::person object_type;
    typedef ::person* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = false;

    typedef long unsigned int id_type;

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
}

#include <odb/details/buffer.hxx>

#include <odb/mssql/version.hxx>
#include <odb/mssql/forward.hxx>
#include <odb/mssql/binding.hxx>
#include <odb/mssql/mssql-types.hxx>

namespace odb
{
  // person
  //
  template <>
  class access::object_traits_impl< ::person, id_mssql >:
    public access::object_traits< ::person >
  {
    public:
    static const std::size_t batch = 1UL;

    static const bool rowversion = false;

    struct id_image_type
    {
      long long id_value;
      SQLLEN id_size_ind;

      std::size_t version;
    };

    struct image_type
    {
      // id_
      //
      long long id_value;
      SQLLEN id_size_ind;

      // first_
      //
      char first_value[513];
      SQLLEN first_size_ind;

      // last_
      //
      char last_value[513];
      SQLLEN last_size_ind;

      // bio_
      //
      char bio_value[513];
      SQLLEN bio_size_ind;

      std::size_t version;

      mssql::change_callback*
      change_callback ()
      {
        return 0;
      }
    };

    struct extra_statement_cache_type;

    // nicknames_
    //
    struct nicknames_traits
    {
      static const std::size_t id_column_count = 1UL;
      static const std::size_t value_column_count = 1UL;
      static const std::size_t cond_column_count = 2UL;
      static const std::size_t data_column_count = 3UL;

      static const bool versioned = false;

      static const char insert_statement[];
      static const char select_statement[];
      static const char update_statement[];
      static const char delete_statement[];

      typedef ::person::names container_type;
      typedef
      odb::access::container_traits<container_type>
      container_traits_type;
      typedef container_traits_type::index_type index_type;
      typedef container_traits_type::value_type value_type;

      typedef smart_ordered_functions<index_type, value_type> functions_type;
      typedef mssql::smart_container_statements< nicknames_traits > statements_type;

      struct cond_image_type
      {
        // index
        //
        long long index_value;
        SQLLEN index_size_ind;

        std::size_t version;
      };

      struct data_image_type
      {
        // index
        //
        long long index_value;
        SQLLEN index_size_ind;

        // value
        //
        char value_value[513];
        SQLLEN value_size_ind;

        std::size_t version;
      };

      static void
      bind (mssql::bind*,
            const mssql::bind* id,
            std::size_t id_size,
            cond_image_type&);

      static void
      bind (mssql::bind*,
            const mssql::bind* id,
            std::size_t id_size,
            data_image_type&);

      static void
      bind (mssql::bind*,
            const mssql::bind* id,
            std::size_t id_size,
            cond_image_type&,
            data_image_type&);

      static void
      init (data_image_type&,
            index_type*,
            const value_type&);

      static void
      init (cond_image_type&, index_type);

      static void
      init (index_type&,
            value_type&,
            const data_image_type&,
            database*);

      static void
      insert (index_type, const value_type&, void*);

      static bool
      select (index_type&, value_type&, void*);

      static void
      update (index_type, const value_type&, void*);

      static void
      delete_ (index_type, void*);

      static void
      persist (const container_type&,
               statements_type&);

      static void
      load (container_type&,
            statements_type&);

      static void
      update (const container_type&,
              statements_type&);

      static void
      erase (const container_type*, statements_type&);
    };

    // extras_
    //
    struct extras_traits
    {
      typedef object_traits_impl<object_type, id_mssql>::image_type image_type;
      typedef object_traits_impl<object_type, id_mssql>::id_image_type id_image_type;

      static const bool rowversion = false;

      static std::size_t
      bind (mssql::bind*,
            const mssql::bind* id,
            std::size_t id_size,
            image_type&,
            mssql::statement_kind);

      static void
      init (object_type&,
            const image_type&,
            database*);

      static void
      init (image_type&,
            const object_type&);

      static const std::size_t id_column_count = 1UL;
      static const std::size_t managed_optimistic_load_column_count = 0UL;
      static const std::size_t load_column_count = 1UL;
      static const std::size_t managed_optimistic_update_column_count = 0UL;
      static const std::size_t update_column_count = 1UL;

      static const bool versioned = false;

      static const char select_statement[];

      static const char update_statement[];

      typedef mssql::section_statements< object_type, extras_traits > statements_type;

      static void
      load (extra_statement_cache_type&, object_type&);

      static void
      update (extra_statement_cache_type&, const object_type&);
    };

    using object_traits<object_type>::id;

    static id_type
    id (const id_image_type&);

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

    static const std::size_t column_count = 4UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 1UL;
    static const std::size_t separate_update_column_count = 1UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char update_statement[];
    static const char erase_statement[];

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

    static bool
    load (connection&, object_type&, section&);

    static bool
    update (connection&, const object_type&, const section&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);
  };

  template <>
  class access::object_traits_impl< ::person, id_common >:
    public access::object_traits_impl< ::person, id_mssql >
  {
  };
}

#include "person-odb.ixx"

#include <odb/post.hxx>

#endif // PERSON_ODB_HXX
