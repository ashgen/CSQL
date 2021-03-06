// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

namespace odb
{
  // EsteeMaster_Archive
  //

  inline
  access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::id_type
  access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  id (const id_image_type& i)
  {
    return object_traits_impl< ::EsteeMaster, id_sqlite >::id (i);
  }

  inline
  access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::id_type
  access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  id (const image_type& i)
  {
    return object_traits_impl< ::EsteeMaster, id_sqlite >::id (i);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  bind (sqlite::bind* b, id_image_type& i)
  {
    object_traits_impl< ::EsteeMaster, id_sqlite >::bind (b, i);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  init (id_image_type& i, const id_type& id)
  {
    object_traits_impl< ::EsteeMaster, id_sqlite >::init (i, id);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  erase (database& db, const object_type& obj)
  {
    callback (db, obj, callback_event::pre_erase);
    erase (db, id (obj));
    callback (db, obj, callback_event::post_erase);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_sqlite >::
  load_ (statements_type& sts,
         object_type& obj,
         bool)
  {
    ODB_POTENTIALLY_UNUSED (sts);
    ODB_POTENTIALLY_UNUSED (obj);
  }
}

