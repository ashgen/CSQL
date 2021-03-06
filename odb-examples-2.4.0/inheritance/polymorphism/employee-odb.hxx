// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#ifndef EMPLOYEE_ODB_HXX
#define EMPLOYEE_ODB_HXX

#include <odb/version.hxx>

#if (ODB_VERSION != 20400UL)
#error ODB runtime version mismatch
#endif

#include <odb/pre.hxx>

#include "employee.hxx"

#include <memory>
#include <cstddef>
#include <string>

#include <odb/core.hxx>
#include <odb/traits.hxx>
#include <odb/callback.hxx>
#include <odb/wrapper-traits.hxx>
#include <odb/pointer-traits.hxx>
#include <odb/container-traits.hxx>
#include <odb/no-op-cache-traits.hxx>
#include <odb/polymorphic-info.hxx>
#include <odb/result.hxx>
#include <odb/polymorphic-object-result.hxx>

#include <odb/details/unused.hxx>
#include <odb/details/shared-ptr.hxx>

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

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::std::string discriminator_type;
    typedef polymorphic_map<object_type> map_type;
    typedef polymorphic_concrete_info<object_type> info_type;
    typedef polymorphic_abstract_info<object_type> abstract_info_type;

    static const std::size_t depth = 1UL;

    typedef long unsigned int id_type;

    static const bool auto_id = true;

    static const bool abstract = true;

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

  // employee
  //
  template <>
  struct class_traits< ::employee >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::employee >
  {
    public:
    typedef ::employee object_type;
    typedef ::employee* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::person base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::person >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<object_traits<root_type>::pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<root_type>
    reference_cache_traits;

    static void
    callback (database&, object_type&, callback_event);

    static void
    callback (database&, const object_type&, callback_event);
  };

  // contractor
  //
  template <>
  struct class_traits< ::contractor >
  {
    static const class_kind kind = class_object;
  };

  template <>
  class access::object_traits< ::contractor >
  {
    public:
    typedef ::contractor object_type;
    typedef ::contractor* pointer_type;
    typedef odb::pointer_traits<pointer_type> pointer_traits;

    static const bool polymorphic = true;

    typedef ::person root_type;
    typedef ::person base_type;
    typedef object_traits<root_type>::discriminator_type discriminator_type;
    typedef polymorphic_concrete_info<root_type> info_type;

    static const std::size_t depth = 2UL;

    typedef object_traits< ::person >::id_type id_type;

    static const bool auto_id = false;

    static const bool abstract = false;

    static id_type
    id (const object_type&);

    typedef
    no_op_pointer_cache_traits<object_traits<root_type>::pointer_type>
    pointer_cache_traits;

    typedef
    no_op_reference_cache_traits<root_type>
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
#include <odb/mssql/query.hxx>

namespace odb
{
  // person
  //
  template <typename A>
  struct query_columns< ::person, id_mssql, A >
  {
    // id
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        long unsigned int,
        mssql::id_bigint >::query_type,
      mssql::id_bigint >
    id_type_;

    static const id_type_ id;

    // typeid_
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    typeid__type_;

    static const typeid__type_ typeid_;

    // first
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    first_type_;

    static const first_type_ first;

    // last
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    last_type_;

    static const last_type_ last;
  };

  template <typename A>
  const typename query_columns< ::person, id_mssql, A >::id_type_
  query_columns< ::person, id_mssql, A >::
  id (A::table_name, "[id]", 0);

  template <typename A>
  const typename query_columns< ::person, id_mssql, A >::typeid__type_
  query_columns< ::person, id_mssql, A >::
  typeid_ (A::table_name, "[typeid]", 0, 256);

  template <typename A>
  const typename query_columns< ::person, id_mssql, A >::first_type_
  query_columns< ::person, id_mssql, A >::
  first (A::table_name, "[first]", 0, 512);

  template <typename A>
  const typename query_columns< ::person, id_mssql, A >::last_type_
  query_columns< ::person, id_mssql, A >::
  last (A::table_name, "[last]", 0, 512);

  template <typename A>
  struct pointer_query_columns< ::person, id_mssql, A >:
    query_columns< ::person, id_mssql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::person, id_mssql >:
    public access::object_traits< ::person >
  {
    public:
    static const std::size_t batch = 1UL;

    static const bool rowversion = false;

    typedef object_traits_impl<root_type, id_mssql> root_traits;

    struct discriminator_image_type
    {
      char discriminator_value[257];
      SQLLEN discriminator_size_ind;

      std::size_t version;
    };

    struct id_image_type
    {
      long long id_value;
      SQLLEN id_size_ind;

      std::size_t version;
    };

    static map_type* map;
    static const abstract_info_type info;

    struct image_type
    {
      // id_
      //
      long long id_value;
      SQLLEN id_size_ind;

      // typeid_
      //
      char typeid_value[257];
      SQLLEN typeid_size_ind;

      // first_
      //
      char first_value[513];
      SQLLEN first_size_ind;

      // last_
      //
      char last_value[513];
      SQLLEN last_size_ind;

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

    static discriminator_type
    discriminator (const image_type&);

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

    typedef
    mssql::polymorphic_root_object_statements<object_type>
    statements_type;

    typedef statements_type root_statements_type;

    typedef mssql::query_base query_base_type;

    static const std::size_t column_count = 4UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 1UL;
    static const std::size_t managed_optimistic_column_count = 0UL;
    static const std::size_t discriminator_column_count = 1UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char find_statement[];
    static const char find_discriminator_statement[];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload);

    static void
    discriminator_ (statements_type&,
                    const id_type&,
                    discriminator_type*);

    static root_traits::image_type&
    root_image (image_type&);

    static image_type*
    clone_image (image_type&);

    static void
    copy_image (image_type&, image_type&);

    static void
    free_image (image_type*);
  };

  template <>
  class access::object_traits_impl< ::person, id_common >:
    public access::object_traits_impl< ::person, id_mssql >
  {
  };

  // employee
  //
  template <typename A>
  struct query_columns< ::employee, id_mssql, A >:
    query_columns< ::person, id_mssql, typename A::base_traits >
  {
    // person
    //
    typedef query_columns< ::person, id_mssql, typename A::base_traits > person;

    // id
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        long unsigned int,
        mssql::id_bigint >::query_type,
      mssql::id_bigint >
    id_type_;

    static const id_type_ id;

    // temporary
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        bool,
        mssql::id_bit >::query_type,
      mssql::id_bit >
    temporary_type_;

    static const temporary_type_ temporary;
  };

  template <typename A>
  const typename query_columns< ::employee, id_mssql, A >::id_type_
  query_columns< ::employee, id_mssql, A >::
  id (A::table_name, "[id]", 0);

  template <typename A>
  const typename query_columns< ::employee, id_mssql, A >::temporary_type_
  query_columns< ::employee, id_mssql, A >::
  temporary (A::table_name, "[temporary]", 0);

  template <typename A>
  struct pointer_query_columns< ::employee, id_mssql, A >:
    query_columns< ::employee, id_mssql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::employee, id_mssql >:
    public access::object_traits< ::employee >
  {
    public:
    typedef polymorphic_entry<object_type, id_mssql> entry_type;
    typedef object_traits_impl<root_type, id_mssql> root_traits;
    typedef object_traits_impl<base_type, id_mssql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id_
      //
      long long id_value;
      SQLLEN id_size_ind;

      // temporary_
      //
      unsigned char temporary_value;
      SQLLEN temporary_size_ind;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static void
    bind (mssql::bind*,
          const mssql::bind* id,
          std::size_t id_size,
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
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, mssql::binding*);

    typedef
    mssql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    mssql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef mssql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);

    static root_traits::image_type&
    root_image (image_type&);

    static image_type*
    clone_image (image_type&);

    static void
    copy_image (image_type&, image_type&);

    static void
    free_image (image_type*);
  };

  template <>
  class access::object_traits_impl< ::employee, id_common >:
    public access::object_traits_impl< ::employee, id_mssql >
  {
  };

  // contractor
  //
  template <typename A>
  struct query_columns< ::contractor, id_mssql, A >:
    query_columns< ::person, id_mssql, typename A::base_traits >
  {
    // person
    //
    typedef query_columns< ::person, id_mssql, typename A::base_traits > person;

    // id
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        long unsigned int,
        mssql::id_bigint >::query_type,
      mssql::id_bigint >
    id_type_;

    static const id_type_ id;

    // email
    //
    typedef
    mssql::query_column<
      mssql::value_traits<
        ::std::string,
        mssql::id_string >::query_type,
      mssql::id_string >
    email_type_;

    static const email_type_ email;
  };

  template <typename A>
  const typename query_columns< ::contractor, id_mssql, A >::id_type_
  query_columns< ::contractor, id_mssql, A >::
  id (A::table_name, "[id]", 0);

  template <typename A>
  const typename query_columns< ::contractor, id_mssql, A >::email_type_
  query_columns< ::contractor, id_mssql, A >::
  email (A::table_name, "[email]", 0, 512);

  template <typename A>
  struct pointer_query_columns< ::contractor, id_mssql, A >:
    query_columns< ::contractor, id_mssql, A >
  {
  };

  template <>
  class access::object_traits_impl< ::contractor, id_mssql >:
    public access::object_traits< ::contractor >
  {
    public:
    typedef polymorphic_entry<object_type, id_mssql> entry_type;
    typedef object_traits_impl<root_type, id_mssql> root_traits;
    typedef object_traits_impl<base_type, id_mssql> base_traits;

    typedef root_traits::id_image_type id_image_type;

    static const info_type info;

    struct image_type
    {
      base_traits::image_type* base;

      // id_
      //
      long long id_value;
      SQLLEN id_size_ind;

      // email_
      //
      char email_value[513];
      SQLLEN email_size_ind;

      std::size_t version;
    };

    struct extra_statement_cache_type;

    using object_traits<object_type>::id;

    static void
    bind (mssql::bind*,
          const mssql::bind* id,
          std::size_t id_size,
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
          database*,
          std::size_t = depth);

    static void
    init (id_image_type&, const id_type&);

    static bool
    check_version (const std::size_t*, const image_type&);

    static void
    update_version (std::size_t*, const image_type&, mssql::binding*);

    typedef
    mssql::polymorphic_derived_object_statements<object_type>
    statements_type;

    typedef
    mssql::polymorphic_root_object_statements<root_type>
    root_statements_type;

    typedef mssql::query_base query_base_type;

    static const std::size_t column_count = 2UL;
    static const std::size_t id_column_count = 1UL;
    static const std::size_t inverse_column_count = 0UL;
    static const std::size_t readonly_column_count = 0UL;
    static const std::size_t managed_optimistic_column_count = 0UL;

    static const std::size_t separate_load_column_count = 0UL;
    static const std::size_t separate_update_column_count = 0UL;

    static const bool versioned = false;

    static const char persist_statement[];
    static const char* const find_statements[depth];
    static const std::size_t find_column_counts[depth];
    static const char update_statement[];
    static const char erase_statement[];
    static const char query_statement[];
    static const char erase_query_statement[];

    static const char table_name[];

    static void
    persist (database&, object_type&, bool top = true, bool dyn = true);

    static pointer_type
    find (database&, const id_type&);

    static bool
    find (database&, const id_type&, object_type&, bool dyn = true);

    static bool
    reload (database&, object_type&, bool dyn = true);

    static void
    update (database&, const object_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const id_type&, bool top = true, bool dyn = true);

    static void
    erase (database&, const object_type&, bool top = true, bool dyn = true);

    static result<object_type>
    query (database&, const query_base_type&);

    static unsigned long long
    erase_query (database&, const query_base_type&);

    public:
    static bool
    find_ (statements_type&,
           const id_type*,
           std::size_t = depth);

    static void
    load_ (statements_type&,
           object_type&,
           bool reload,
           std::size_t = depth);

    static void
    load_ (database&, root_type&, std::size_t);

    static root_traits::image_type&
    root_image (image_type&);

    static image_type*
    clone_image (image_type&);

    static void
    copy_image (image_type&, image_type&);

    static void
    free_image (image_type*);
  };

  template <>
  class access::object_traits_impl< ::contractor, id_common >:
    public access::object_traits_impl< ::contractor, id_mssql >
  {
  };

  // person
  //
  // employee
  //
  // contractor
  //
}

#include "employee-odb.ixx"

#include <odb/post.hxx>

#endif // EMPLOYEE_ODB_HXX
