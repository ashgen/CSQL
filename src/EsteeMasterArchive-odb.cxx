#include <odb/pre.hxx>

#define ODB_COMMON_QUERY_COLUMNS_DEF
#include "EsteeMasterArchive-odb.hxx"
#undef ODB_COMMON_QUERY_COLUMNS_DEF

namespace odb
{
  // EsteeMaster_Archive
  //

  template struct query_columns<
    ::EsteeMaster,
    id_common,
    access::object_traits_impl< ::EsteeMaster_Archive, id_common > >;

  template struct query_columns<
    ::EsteeMaster_Archive,
    id_common,
    access::object_traits_impl< ::EsteeMaster_Archive, id_common > >;

  const access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  function_table_type*
  access::object_traits_impl< ::EsteeMaster_Archive, id_common >::
  function_table[database_count];
}

#include <odb/post.hxx>
