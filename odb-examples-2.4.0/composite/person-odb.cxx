// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/pre.hxx>

#include "person-odb.hxx"

#include <cassert>
#include <cstring>  // std::memcpy


#include <odb/mssql/traits.hxx>
#include <odb/mssql/database.hxx>
#include <odb/mssql/transaction.hxx>
#include <odb/mssql/connection.hxx>
#include <odb/mssql/statement.hxx>
#include <odb/mssql/statement-cache.hxx>
#include <odb/mssql/simple-object-statements.hxx>
#include <odb/mssql/container-statements.hxx>
#include <odb/mssql/exceptions.hxx>
#include <odb/mssql/simple-object-result.hxx>

namespace odb
{
  // basic_name
  //

  void access::composite_value_traits< ::basic_name, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // first_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.first_value;
    b[n].size_ind = &i.first_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.first_value));
    n++;

    // last_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.last_value;
    b[n].size_ind = &i.last_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.last_value));
    n++;
  }

  void access::composite_value_traits< ::basic_name, id_mssql >::
  init (image_type& i,
        const value_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    // first_
    //
    {
      ::std::string const& v =
        o.first_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.first_value,
        sizeof (i.first_value) - 1,
        size,
        is_null,
        v);
      i.first_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // last_
    //
    {
      ::std::string const& v =
        o.last_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.last_value,
        sizeof (i.last_value) - 1,
        size,
        is_null,
        v);
      i.last_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }
  }

  void access::composite_value_traits< ::basic_name, id_mssql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // first_
    //
    {
      ::std::string& v =
        o.first_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.first_value,
        static_cast<std::size_t> (i.first_size_ind),
        i.first_size_ind == SQL_NULL_DATA);
    }

    // last_
    //
    {
      ::std::string& v =
        o.last_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.last_value,
        static_cast<std::size_t> (i.last_size_ind),
        i.last_size_ind == SQL_NULL_DATA);
    }
  }

  // name_extras
  //

  // aliases_
  //

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  bind (mssql::bind* b,
        const mssql::bind* id,
        std::size_t id_size,
        data_image_type& d)
  {
    using namespace mssql;

    statement_kind sk (statement_select);
    ODB_POTENTIALLY_UNUSED (sk);

    size_t n (0);

    // object_id
    //
    if (id != 0)
      std::memcpy (&b[n], id, id_size * sizeof (id[0]));
    n += id_size;

    // index
    //
    b[n].type = mssql::bind::bigint;
    b[n].buffer = &d.index_value;
    b[n].size_ind = &d.index_size_ind;
    n++;

    // value
    //
    composite_value_traits< value_type, id_mssql >::bind (
      b + n, d.value_value, sk);
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  init (data_image_type& i,
        index_type* j,
        const value_type& v)
  {
    using namespace mssql;

    statement_kind sk (statement_insert);
    ODB_POTENTIALLY_UNUSED (sk);

    // index
    //
    if (j != 0)
    {
      bool is_null (false);
      mssql::value_traits<
          index_type,
          mssql::id_bigint >::set_image (
        i.index_value, is_null, *j);
      i.index_size_ind = is_null ? SQL_NULL_DATA : 0;
    }

    // value
    //
    {
      composite_value_traits< value_type, id_mssql >::init (
        i.value_value,
        v,
        sk);
    }
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  init (index_type& j,
        value_type& v,
        const data_image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (db);

    // index
    //
    {
      mssql::value_traits<
          index_type,
          mssql::id_bigint >::set_value (
        j,
        i.index_value,
        i.index_size_ind == SQL_NULL_DATA);
    }

    // value
    //
    {
      composite_value_traits< value_type, id_mssql >::init (
        v,
        i.value_value,
        db);
    }
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  insert (index_type i, const value_type& v, void* d)
  {
    using namespace mssql;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (di, &i, v);

    if (sts.data_binding_test_version ())
    {
      const binding& id (sts.id_binding ());
      bind (sts.data_bind (), id.bind, id.count, di);
      sts.data_binding_update_version ();
    }

    if (!sts.insert_statement ().execute ())
      throw object_already_persistent ();
  }

  bool access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  select (index_type& i, value_type& v, void* d)
  {
    using namespace mssql;
    using mssql::select_statement;

    statements_type& sts (*static_cast< statements_type* > (d));
    data_image_type& di (sts.data_image ());

    init (i, v, di, &sts.connection ().database ());

    sts.select_statement ().stream_result ();

    select_statement& st (sts.select_statement ());
    select_statement::result r (st.fetch ());
    return r != select_statement::no_data;
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  delete_ (void* d)
  {
    using namespace mssql;

    statements_type& sts (*static_cast< statements_type* > (d));
    sts.delete_statement ().execute ();
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  persist (const container_type& c,
           statements_type& sts)
  {
    using namespace mssql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::persist (c, fs);
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  load (container_type& c,
        statements_type& sts)
  {
    using namespace mssql;
    using mssql::select_statement;

    const binding& id (sts.id_binding ());

    if (sts.data_binding_test_version ())
    {
      bind (sts.data_bind (), id.bind, id.count, sts.data_image ());
      sts.data_binding_update_version ();
    }

    select_statement& st (sts.select_statement ());
    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());
    bool more (r != select_statement::no_data);

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::load (c, more, fs);
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  update (const container_type& c,
          statements_type& sts)
  {
    using namespace mssql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::update (c, fs);
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::aliases_traits::
  erase (statements_type& sts)
  {
    using namespace mssql;

    functions_type& fs (sts.functions ());
    fs.ordered_ = true;
    container_traits_type::erase (fs);
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // nickname_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.nickname_value;
    b[n].size_ind = &i.nickname_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.nickname_value));
    n++;
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::
  init (image_type& i,
        const value_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    // nickname_
    //
    {
      ::std::string const& v =
        o.nickname_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.nickname_value,
        sizeof (i.nickname_value) - 1,
        size,
        is_null,
        v);
      i.nickname_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }
  }

  void access::composite_value_traits< ::name_extras, id_mssql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // nickname_
    //
    {
      ::std::string& v =
        o.nickname_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.nickname_value,
        static_cast<std::size_t> (i.nickname_size_ind),
        i.nickname_size_ind == SQL_NULL_DATA);
    }
  }

  // name
  //

  void access::composite_value_traits< ::name, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // basic_name base
    //
    composite_value_traits< ::basic_name, id_mssql >::bind (b + n, i, sk);
    n += 2UL;

    // title_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.title_value;
    b[n].size_ind = &i.title_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.title_value));
    n++;

    // extras_
    //
    composite_value_traits< ::name_extras, id_mssql >::bind (
      b + n, i.extras_value, sk);
    n += 1UL;
  }

  void access::composite_value_traits< ::name, id_mssql >::
  init (image_type& i,
        const value_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    // basic_name base
    //
    composite_value_traits< ::basic_name, id_mssql >::init (i, o, sk);

    // title_
    //
    {
      ::std::string const& v =
        o.title_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.title_value,
        sizeof (i.title_value) - 1,
        size,
        is_null,
        v);
      i.title_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // extras_
    //
    {
      ::name_extras const& v =
        o.extras_;

      composite_value_traits< ::name_extras, id_mssql >::init (
        i.extras_value,
        v,
        sk);
    }
  }

  void access::composite_value_traits< ::name, id_mssql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // basic_name base
    //
    composite_value_traits< ::basic_name, id_mssql >::init (o, i, db);

    // title_
    //
    {
      ::std::string& v =
        o.title_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.title_value,
        static_cast<std::size_t> (i.title_size_ind),
        i.title_size_ind == SQL_NULL_DATA);
    }

    // extras_
    //
    {
      ::name_extras& v =
        o.extras_;

      composite_value_traits< ::name_extras, id_mssql >::init (
        v,
        i.extras_value,
        db);
    }
  }

  // phone_numbers
  //

  void access::composite_value_traits< ::phone_numbers, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // first
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.first_value;
    b[n].size_ind = &i.first_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.first_value));
    n++;

    // second
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.second_value;
    b[n].size_ind = &i.second_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.second_value));
    n++;
  }

  void access::composite_value_traits< ::phone_numbers, id_mssql >::
  init (image_type& i,
        const value_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    // first
    //
    {
      ::std::basic_string< char > const& v =
        o.first;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::basic_string< char >,
          mssql::id_string >::set_image (
        i.first_value,
        sizeof (i.first_value) - 1,
        size,
        is_null,
        v);
      i.first_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // second
    //
    {
      ::std::basic_string< char > const& v =
        o.second;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::basic_string< char >,
          mssql::id_string >::set_image (
        i.second_value,
        sizeof (i.second_value) - 1,
        size,
        is_null,
        v);
      i.second_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }
  }

  void access::composite_value_traits< ::phone_numbers, id_mssql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // first
    //
    {
      ::std::basic_string< char >& v =
        o.first;

      mssql::value_traits<
          ::std::basic_string< char >,
          mssql::id_string >::set_value (
        v,
        i.first_value,
        static_cast<std::size_t> (i.first_size_ind),
        i.first_size_ind == SQL_NULL_DATA);
    }

    // second
    //
    {
      ::std::basic_string< char >& v =
        o.second;

      mssql::value_traits<
          ::std::basic_string< char >,
          mssql::id_string >::set_value (
        v,
        i.second_value,
        static_cast<std::size_t> (i.second_size_ind),
        i.second_size_ind == SQL_NULL_DATA);
    }
  }

  // email_address
  //

  void access::composite_value_traits< ::email_address, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (b);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);
    ODB_POTENTIALLY_UNUSED (n);

    // recipient_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.recipient_value;
    b[n].size_ind = &i.recipient_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.recipient_value));
    n++;

    // domain_
    //
    b[n].type = mssql::bind::string;
    b[n].buffer = &i.domain_value;
    b[n].size_ind = &i.domain_size_ind;
    b[n].capacity = static_cast<SQLLEN> (sizeof (i.domain_value));
    n++;
  }

  void access::composite_value_traits< ::email_address, id_mssql >::
  init (image_type& i,
        const value_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    // recipient_
    //
    {
      ::std::string const& v =
        o.recipient_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.recipient_value,
        sizeof (i.recipient_value) - 1,
        size,
        is_null,
        v);
      i.recipient_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }

    // domain_
    //
    {
      ::std::string const& v =
        o.domain_;

      bool is_null (false);
      std::size_t size (0);
      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_image (
        i.domain_value,
        sizeof (i.domain_value) - 1,
        size,
        is_null,
        v);
      i.domain_size_ind =
        is_null ? SQL_NULL_DATA : static_cast<SQLLEN> (size);
    }
  }

  void access::composite_value_traits< ::email_address, id_mssql >::
  init (value_type& o,
        const image_type&  i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // recipient_
    //
    {
      ::std::string& v =
        o.recipient_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.recipient_value,
        static_cast<std::size_t> (i.recipient_size_ind),
        i.recipient_size_ind == SQL_NULL_DATA);
    }

    // domain_
    //
    {
      ::std::string& v =
        o.domain_;

      mssql::value_traits<
          ::std::string,
          mssql::id_string >::set_value (
        v,
        i.domain_value,
        static_cast<std::size_t> (i.domain_size_ind),
        i.domain_size_ind == SQL_NULL_DATA);
    }
  }

  // person
  //

  struct access::object_traits_impl< ::person, id_mssql >::extra_statement_cache_type
  {
    mssql::container_statements_impl< name_extras_aliases_traits > name_extras_aliases_;

    extra_statement_cache_type (
      mssql::connection& c,
      image_type&,
      id_image_type&,
      mssql::binding& id,
      mssql::binding&)
    : name_extras_aliases_ (c, id)
    {
    }
  };

  // aliases_
  //

  const char access::object_traits_impl< ::person, id_mssql >::name_extras_aliases_traits::
  select_statement[] =
  "SELECT "
  "[c_person_name_extras_aliases].[index], "
  "[c_person_name_extras_aliases].[value_first], "
  "[c_person_name_extras_aliases].[value_last] "
  "FROM [c_person_name_extras_aliases] "
  "WHERE [c_person_name_extras_aliases].[object_id_recipient]=? AND [c_person_name_extras_aliases].[object_id_domain]=? ORDER BY [c_person_name_extras_aliases].[index]";

  const char access::object_traits_impl< ::person, id_mssql >::name_extras_aliases_traits::
  insert_statement[] =
  "INSERT INTO [c_person_name_extras_aliases] "
  "([object_id_recipient], "
  "[object_id_domain], "
  "[index], "
  "[value_first], "
  "[value_last]) "
  "VALUES "
  "(?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::person, id_mssql >::name_extras_aliases_traits::
  delete_statement[] =
  "DELETE FROM [c_person_name_extras_aliases] "
  "WHERE [object_id_recipient]=? AND [object_id_domain]=?";

  access::object_traits_impl< ::person, id_mssql >::id_type
  access::object_traits_impl< ::person, id_mssql >::
  id (const image_type& i)
  {
    mssql::database* db (0);
    ODB_POTENTIALLY_UNUSED (db);

    id_type id;
    {
      composite_value_traits< ::email_address, id_mssql >::init (
        id,
        i.email_value,
        db);
    }

    return id;
  }

  void access::object_traits_impl< ::person, id_mssql >::
  bind (mssql::bind* b,
        image_type& i,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    std::size_t n (0);

    // email_
    //
    if (sk != statement_update)
    {
      composite_value_traits< ::email_address, id_mssql >::bind (
        b + n, i.email_value, sk);
      n += 2UL;
    }

    // name_
    //
    composite_value_traits< ::person::name_type, id_mssql >::bind (
      b + n, i.name_value, sk);
    n += 4UL;

    // phone_
    //
    composite_value_traits< ::phone_numbers, id_mssql >::bind (
      b + n, i.phone_value, sk);
    n += 2UL;
  }

  void access::object_traits_impl< ::person, id_mssql >::
  bind (mssql::bind* b, id_image_type& i)
  {
    std::size_t n (0);
    mssql::statement_kind sk (mssql::statement_select);
    composite_value_traits< ::email_address, id_mssql >::bind (
      b + n, i.id_value, sk);
  }

  void access::object_traits_impl< ::person, id_mssql >::
  init (image_type& i,
        const object_type& o,
        mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    if (i.change_callback_.callback != 0)
      (i.change_callback_.callback) (i.change_callback_.context);

    // email_
    //
    if (sk == statement_insert)
    {
      ::email_address const& v =
        o.email_;

      composite_value_traits< ::email_address, id_mssql >::init (
        i.email_value,
        v,
        sk);
    }

    // name_
    //
    {
      ::person::name_type const& v =
        o.name_;

      composite_value_traits< ::person::name_type, id_mssql >::init (
        i.name_value,
        v,
        sk);
    }

    // phone_
    //
    {
      ::phone_numbers const& v =
        o.phone_;

      composite_value_traits< ::phone_numbers, id_mssql >::init (
        i.phone_value,
        v,
        sk);
    }
  }

  void access::object_traits_impl< ::person, id_mssql >::
  init (object_type& o,
        const image_type& i,
        database* db)
  {
    ODB_POTENTIALLY_UNUSED (o);
    ODB_POTENTIALLY_UNUSED (i);
    ODB_POTENTIALLY_UNUSED (db);

    // email_
    //
    {
      ::email_address& v =
        o.email_;

      composite_value_traits< ::email_address, id_mssql >::init (
        v,
        i.email_value,
        db);
    }

    // name_
    //
    {
      ::person::name_type& v =
        o.name_;

      composite_value_traits< ::person::name_type, id_mssql >::init (
        v,
        i.name_value,
        db);
    }

    // phone_
    //
    {
      ::phone_numbers& v =
        o.phone_;

      composite_value_traits< ::phone_numbers, id_mssql >::init (
        v,
        i.phone_value,
        db);
    }
  }

  void access::object_traits_impl< ::person, id_mssql >::
  init (id_image_type& i, const id_type& id)
  {
    mssql::statement_kind sk (mssql::statement_select);
    {
      composite_value_traits< ::email_address, id_mssql >::init (
        i.id_value,
        id,
        sk);
    }
  }

  const char access::object_traits_impl< ::person, id_mssql >::persist_statement[] =
  "INSERT INTO [c_person] "
  "([email_recipient], "
  "[email_domain], "
  "[name_first], "
  "[name_last], "
  "[name_title], "
  "[name_extras_nickname], "
  "[phone_first], "
  "[phone_second]) "
  "VALUES "
  "(?, ?, ?, ?, ?, ?, ?, ?)";

  const char access::object_traits_impl< ::person, id_mssql >::find_statement[] =
  "SELECT "
  "[c_person].[email_recipient], "
  "[c_person].[email_domain], "
  "[c_person].[name_first], "
  "[c_person].[name_last], "
  "[c_person].[name_title], "
  "[c_person].[name_extras_nickname], "
  "[c_person].[phone_first], "
  "[c_person].[phone_second] "
  "FROM [c_person] "
  "WHERE [c_person].[email_recipient]=? AND [c_person].[email_domain]=?";

  const char access::object_traits_impl< ::person, id_mssql >::update_statement[] =
  "UPDATE [c_person] "
  "SET "
  "[name_first]=?, "
  "[name_last]=?, "
  "[name_title]=?, "
  "[name_extras_nickname]=?, "
  "[phone_first]=?, "
  "[phone_second]=? "
  "WHERE [email_recipient]=? AND [email_domain]=?";

  const char access::object_traits_impl< ::person, id_mssql >::erase_statement[] =
  "DELETE FROM [c_person] "
  "WHERE [email_recipient]=? AND [email_domain]=?";

  const char access::object_traits_impl< ::person, id_mssql >::query_statement[] =
  "SELECT "
  "[c_person].[email_recipient], "
  "[c_person].[email_domain], "
  "[c_person].[name_first], "
  "[c_person].[name_last], "
  "[c_person].[name_title], "
  "[c_person].[name_extras_nickname], "
  "[c_person].[phone_first], "
  "[c_person].[phone_second] "
  "FROM [c_person]";

  const char access::object_traits_impl< ::person, id_mssql >::erase_query_statement[] =
  "DELETE FROM [c_person]";

  const char access::object_traits_impl< ::person, id_mssql >::table_name[] =
  "[c_person]";

  void access::object_traits_impl< ::person, id_mssql >::
  persist (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    callback (db,
              obj,
              callback_event::pre_persist);

    image_type& im (sts.image ());
    binding& imb (sts.insert_image_binding ());

    init (im, obj, statement_insert);

    if (im.version != sts.insert_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_insert);
      sts.insert_image_version (im.version);
      imb.version++;
    }

    insert_statement& st (sts.persist_statement ());
    if (!st.execute ())
      throw object_already_persistent ();

    id_image_type& i (sts.id_image ());
    init (i, obj.email_);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // name_.extras_.aliases_
    //
    {
      ::basic_names const& v =
        obj.name_.extras_.aliases_;

      name_extras_aliases_traits::persist (
        v,
        esc.name_extras_aliases_);
    }

    callback (db,
              obj,
              callback_event::post_persist);
  }

  void access::object_traits_impl< ::person, id_mssql >::
  update (database& db, const object_type& obj)
  {
    ODB_POTENTIALLY_UNUSED (db);

    using namespace mssql;
    using mssql::update_statement;

    callback (db, obj, callback_event::pre_update);

    mssql::transaction& tr (mssql::transaction::current ());
    mssql::connection& conn (tr.connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    const id_type& id (
      obj.email_);
    id_image_type& idi (sts.id_image ());
    init (idi, id);

    image_type& im (sts.image ());
    init (im, obj, statement_update);

    bool u (false);
    binding& imb (sts.update_image_binding ());
    if (im.version != sts.update_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_update);
      sts.update_image_version (im.version);
      imb.version++;
      u = true;
    }

    binding& idb (sts.id_image_binding ());
    if (idi.version != sts.update_id_image_version () ||
        idb.version == 0)
    {
      if (idi.version != sts.id_image_version () ||
          idb.version == 0)
      {
        bind (idb.bind, idi);
        sts.id_image_version (idi.version);
        idb.version++;
      }

      sts.update_id_image_version (idi.version);

      if (!u)
        imb.version++;
    }

    update_statement& st (sts.update_statement ());
    if (st.execute () == 0)
      throw object_not_persistent ();

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // name_.extras_.aliases_
    //
    {
      ::basic_names const& v =
        obj.name_.extras_.aliases_;

      name_extras_aliases_traits::update (
        v,
        esc.name_extras_aliases_);
    }

    callback (db, obj, callback_event::post_update);
    pointer_cache_traits::update (db, obj);
  }

  void access::object_traits_impl< ::person, id_mssql >::
  erase (database& db, const id_type& id)
  {
    using namespace mssql;

    ODB_POTENTIALLY_UNUSED (db);

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    id_image_type& i (sts.id_image ());
    init (i, id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // name_.extras_.aliases_
    //
    name_extras_aliases_traits::erase (
      esc.name_extras_aliases_);

    if (sts.erase_statement ().execute () != 1)
      throw object_not_persistent ();

    pointer_cache_traits::erase (db, id);
  }

  access::object_traits_impl< ::person, id_mssql >::pointer_type
  access::object_traits_impl< ::person, id_mssql >::
  find (database& db, const id_type& id)
  {
    using namespace mssql;

    {
      pointer_type p (pointer_cache_traits::find (db, id));

      if (!pointer_traits::null_ptr (p))
        return p;
    }

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);
    auto_result ar;

    if (l.locked ())
    {
      if (!find_ (sts, &id))
        return pointer_type ();

      ar.set (sts.find_statement ());
    }

    pointer_type p (
      access::object_factory<object_type, pointer_type>::create ());
    pointer_traits::guard pg (p);

    pointer_cache_traits::insert_guard ig (
      pointer_cache_traits::insert (db, id, p));

    object_type& obj (pointer_traits::get_ref (p));

    if (l.locked ())
    {
      select_statement& st (sts.find_statement ());
      ODB_POTENTIALLY_UNUSED (st);

      callback (db, obj, callback_event::pre_load);
      init (obj, sts.image (), &db);
      st.stream_result ();
      ar.free ();
      load_ (sts, obj, false);
      sts.load_delayed (0);
      l.unlock ();
      callback (db, obj, callback_event::post_load);
      pointer_cache_traits::load (ig.position ());
    }
    else
      sts.delay_load (id, obj, ig.position ());

    ig.release ();
    pg.release ();
    return p;
  }

  bool access::object_traits_impl< ::person, id_mssql >::
  find (database& db, const id_type& id, object_type& obj)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);
    reference_cache_traits::position_type pos (
      reference_cache_traits::insert (db, id, obj));
    reference_cache_traits::insert_guard ig (pos);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, false);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    reference_cache_traits::load (pos);
    ig.release ();
    return true;
  }

  bool access::object_traits_impl< ::person, id_mssql >::
  reload (database& db, object_type& obj)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());
    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    statements_type::auto_lock l (sts);

    const id_type& id  (
      obj.email_);

    if (!find_ (sts, &id))
      return false;

    select_statement& st (sts.find_statement ());
    ODB_POTENTIALLY_UNUSED (st);

    auto_result ar (st);

    callback (db, obj, callback_event::pre_load);
    init (obj, sts.image (), &db);
    st.stream_result ();
    ar.free ();
    load_ (sts, obj, true);
    sts.load_delayed (0);
    l.unlock ();
    callback (db, obj, callback_event::post_load);
    return true;
  }

  bool access::object_traits_impl< ::person, id_mssql >::
  find_ (statements_type& sts,
         const id_type* id)
  {
    using namespace mssql;

    id_image_type& i (sts.id_image ());
    init (i, *id);

    binding& idb (sts.id_image_binding ());
    if (i.version != sts.id_image_version () || idb.version == 0)
    {
      bind (idb.bind, i);
      sts.id_image_version (i.version);
      idb.version++;
    }

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    select_statement& st (sts.find_statement ());

    st.execute ();
    auto_result ar (st);
    select_statement::result r (st.fetch ());

    if (r != select_statement::no_data)
    {
      ar.release ();
      return true;
    }
    else
      return false;
  }

  void access::object_traits_impl< ::person, id_mssql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool reload)
  {
    ODB_POTENTIALLY_UNUSED (reload);

    extra_statement_cache_type& esc (sts.extra_statement_cache ());

    // name_.extras_.aliases_
    //
    {
      ::basic_names& v =
        obj.name_.extras_.aliases_;

      name_extras_aliases_traits::load (
        v,
        esc.name_extras_aliases_);
    }
  }

  result< access::object_traits_impl< ::person, id_mssql >::object_type >
  access::object_traits_impl< ::person, id_mssql >::
  query (database&, const query_base_type& q)
  {
    using namespace mssql;
    using odb::details::shared;
    using odb::details::shared_ptr;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    statements_type& sts (
      conn.statement_cache ().find_object<object_type> ());

    image_type& im (sts.image ());
    binding& imb (sts.select_image_binding ());

    if (im.version != sts.select_image_version () ||
        imb.version == 0)
    {
      bind (imb.bind, im, statement_select);
      sts.select_image_version (im.version);
      imb.version++;
    }

    std::string text (query_statement);
    if (!q.empty ())
    {
      text += " ";
      text += q.clause ();
    }

    q.init_parameters ();
    shared_ptr<select_statement> st (
      new (shared) select_statement (
        conn,
        text,
        false,
        true,
        q.parameters_binding (),
        imb));

    st->execute ();

    shared_ptr< odb::object_result_impl<object_type> > r (
      new (shared) mssql::object_result_impl<object_type> (
        q, st, sts, 0));

    return result<object_type> (r);
  }

  unsigned long long access::object_traits_impl< ::person, id_mssql >::
  erase_query (database&, const query_base_type& q)
  {
    using namespace mssql;

    mssql::connection& conn (
      mssql::transaction::current ().connection ());

    std::string text (erase_query_statement);
    if (!q.empty ())
    {
      text += ' ';
      text += q.clause ();
    }

    q.init_parameters ();
    delete_statement st (
      conn,
      text,
      q.parameters_binding ());

    return st.execute ();
  }
}

#include <odb/post.hxx>