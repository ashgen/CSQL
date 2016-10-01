#include <odb/pre.hxx>

#define ODB_COMMON_QUERY_COLUMNS_DEF
#include "ClosingPrice-odb.hxx"
#undef ODB_COMMON_QUERY_COLUMNS_DEF

namespace odb
{
  // closingPrice
  //

  template struct query_columns<
    ::closingPrice,
    id_common,
    access::object_traits_impl< ::closingPrice, id_common > >;

  const access::object_traits_impl< ::closingPrice, id_common >::
  function_table_type*
  access::object_traits_impl< ::closingPrice, id_common >::
  function_table[database_count];
}

#include <odb/post.hxx>
