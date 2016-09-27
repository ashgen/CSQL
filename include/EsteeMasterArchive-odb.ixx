// This file was generated by ODB, object-relational mapping (ORM)
// compiler for C++.
//

#include <odb/database.hxx>

namespace odb
{
  // EsteeMaster_Archive
  //

  inline
  access::object_traits< ::EsteeMaster_Archive >::id_type
  access::object_traits< ::EsteeMaster_Archive >::
  id (const object_type& o)
  {
    return object_traits< ::EsteeMaster >::id (o);
  }

  inline
  void access::object_traits< ::EsteeMaster_Archive >::
  callback (database& db, object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits< ::EsteeMaster_Archive >::
  callback (database& db, const object_type& x, callback_event e)
  {
    ODB_POTENTIALLY_UNUSED (db);
    ODB_POTENTIALLY_UNUSED (x);
    ODB_POTENTIALLY_UNUSED (e);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  persist (database& db, object_type& o)
  {
    function_table[db.id ()]->persist (db, o);
  }

  inline
  access::object_traits_impl< ::EsteeMaster_Archive, id_common >::pointer_type
  access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  find (database& db, const id_type& id)
  {
    return function_table[db.id ()]->find1 (db, id);
  }

  inline
  bool access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  find (database& db, const id_type& id, object_type& o)
  {
    return function_table[db.id ()]->find2 (db, id, o);
  }

  inline
  bool access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  reload (database& db, object_type& o)
  {
    return function_table[db.id ()]->reload (db, o);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  update (database& db, const object_type& o)
  {
    function_table[db.id ()]->update (db, o);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  erase (database& db, const id_type& id)
  {
    function_table[db.id ()]->erase1 (db, id);
  }

  inline
  void access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  erase (database& db, const object_type& o)
  {
    function_table[db.id ()]->erase2 (db, o);
  }

  inline
  result< access::object_traits_impl< ::EsteeMaster_Archive, id_common >::object_type >
  access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  query (database& db, const query_base_type& q)
  {
    return function_table[db.id ()]->query (db, q);
  }

  inline
  unsigned long long access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  erase_query (database& db, const query_base_type& q)
  {
    return function_table[db.id ()]->erase_query (db, q);
  }
}

