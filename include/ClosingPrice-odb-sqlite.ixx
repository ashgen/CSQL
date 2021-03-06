// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // id
  //

  inline
  bool access::composite_value_traits< ::id, id_sqlite >::
  get_null (const image_type& i)
  {
    bool r (true);
    r = r && i.Date_null;
    r = r && i.Estee_ID_null;
    return r;
  }

  inline
  void access::composite_value_traits< ::id, id_sqlite >::
  set_null (image_type& i,
            sqlite::statement_kind sk)
  {
    ODB_POTENTIALLY_UNUSED (sk);

    using namespace sqlite;

    i.Date_null = true;
    i.Estee_ID_null = true;
  }

  // closingPrice
  //

  inline
  void access::object_traits_impl< ::closingPrice, id_sqlite >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }

  inline
  void access::object_traits_impl< ::closingPrice, id_sqlite >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }
}

