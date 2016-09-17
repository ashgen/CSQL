// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // person
  //

  inline
  access::object_traits< ::person >::id_type
  access::object_traits< ::person >::
  id (const object_type& o)
  {
    return o.email_;
  }

  inline
  void access::object_traits< ::person >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::person >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

namespace odb
{
  // basic_name
  //

  inline
  bool access::composite_value_traits< ::basic_name, id_mssql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.first_size_ind == SQL_NULL_DATA;
    r = r && i.last_size_ind == SQL_NULL_DATA;
    return r;
  }

  inline
  void access::composite_value_traits< ::basic_name, id_mssql >::
  set_null (image_type& i,
            mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    i.first_size_ind = SQL_NULL_DATA;
    i.last_size_ind = SQL_NULL_DATA;
  }

  // name_extras
  //

  // name
  //

  // phone_numbers
  //

  inline
  bool access::composite_value_traits< ::phone_numbers, id_mssql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.first_size_ind == SQL_NULL_DATA;
    r = r && i.second_size_ind == SQL_NULL_DATA;
    return r;
  }

  inline
  void access::composite_value_traits< ::phone_numbers, id_mssql >::
  set_null (image_type& i,
            mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    i.first_size_ind = SQL_NULL_DATA;
    i.second_size_ind = SQL_NULL_DATA;
  }

  // email_address
  //

  inline
  bool access::composite_value_traits< ::email_address, id_mssql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.recipient_size_ind == SQL_NULL_DATA;
    r = r && i.domain_size_ind == SQL_NULL_DATA;
    return r;
  }

  inline
  void access::composite_value_traits< ::email_address, id_mssql >::
  set_null (image_type& i,
            mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    i.recipient_size_ind = SQL_NULL_DATA;
    i.domain_size_ind = SQL_NULL_DATA;
  }

  // person
  //

  inline
  void access::object_traits_impl< ::person, id_mssql >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }
}
