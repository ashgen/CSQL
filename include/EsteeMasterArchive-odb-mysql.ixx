// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // EsteeMaster_Archive
  //

  inline
  access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::id_type
  access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  id (const id_image_type& i)
  {
    return object_traits_impl< ::EsteeMaster, id_mysql >::id (i);
  }

  inline
  access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::id_type
  access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  id (const image_type& i)
  {
    return object_traits_impl< ::EsteeMaster, id_mysql >::id (i);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  bind (MYSQL_BIND* b, id_image_type& i)
  {
    object_traits_impl< ::EsteeMaster, id_mysql >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EsteeMaster, id_mysql >::init (i, id);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_mysql >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }
}
