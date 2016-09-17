// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // employer
  //

  inline
  access::object_traits< ::employer >::id_type
  access::object_traits< ::employer >::
  id (const object_type& o)
  {
    return o.name_;
  }

  inline
  void access::object_traits< ::employer >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::employer >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  // employee
  //

  inline
  access::object_traits< ::employee >::id_type
  access::object_traits< ::employee >::
  id (const object_type& o)
  {
    return o.id_;
  }

  inline
  void access::object_traits< ::employee >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::employee >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }
}

namespace odb
{
  // name
  //

  inline
  bool access::composite_value_traits< ::name, id_mssql >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.first_size_ind == SQL_NULL_DATA;
    r = r && i.last_size_ind == SQL_NULL_DATA;
    return r;
  }

  inline
  void access::composite_value_traits< ::name, id_mssql >::
  set_null (image_type& i,
            mssql::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace mssql;

    i.first_size_ind = SQL_NULL_DATA;
    i.last_size_ind = SQL_NULL_DATA;
  }

  // employer
  //

  inline
  void access::object_traits_impl< ::employer, id_mssql >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }

  inline
  void access::object_traits_impl< ::employer, id_mssql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }

  // employee
  //

  inline
  void access::object_traits_impl< ::employee, id_mssql >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }
}

