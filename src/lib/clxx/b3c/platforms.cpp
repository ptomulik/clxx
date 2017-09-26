// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/platforms.cpp

/** // doc: clxx/b3c/platforms.cpp {{{
 * \file clxx/b3c/platforms.cpp
 * \brief Implements functions for retrieval of \ref clxx::platform "platform" objects
 */ // }}}
#include <clxx/b3c/platforms.hpp>
#include <clxx/b5d/cl_functions.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
cl_uint
get_num_platforms()
{
  cl_uint num_platforms;
  get_platform_ids(0, NULL, &num_platforms);
  return num_platforms;
}
/* ------------------------------------------------------------------------ */
std::vector<cl_platform_id>
get_platform_ids()
{
  std::vector<cl_platform_id> ids(get_num_platforms());
  if(ids.size() > 0)
    get_platform_ids(ids.size(), &ids.front(), NULL);
  return ids;
}
/* ------------------------------------------------------------------------ */
platforms
get_platforms()
{
  return make_platforms(get_platform_ids());
}
/* ------------------------------------------------------------------------ */
platforms
make_platforms(std::vector<cl_platform_id> const& ids)
{
  return platforms(ids.begin(),ids.end());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
