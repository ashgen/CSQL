#include <odb/pre.hxx>

#define ODB_COMMON_QUERY_COLUMNS_DEF
#include "EsteeMaster-odb.hxx"
#undef ODB_COMMON_QUERY_COLUMNS_DEF

namespace odb
{
  // EsteeMaster
  //

  template struct query_columns<
    ::EsteeMaster,
    id_common,
    access::object_traits_impl< ::EsteeMaster, id_common > >;

  const access::object_traits_impl< ::EsteeMaster, id_common >::
  function_table_type*
  access::object_traits_impl< ::EsteeMaster, id_common >::
  function_table[database_count];
}

#include <odb/post.hxx>
