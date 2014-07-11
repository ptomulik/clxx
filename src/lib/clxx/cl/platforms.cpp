/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/cl/platforms.cpp

/** // doc: clxx/cl/platforms.cpp {{{
 * \file clxx/cl/platforms.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/exceptions.hpp>
#include <clxx/cl/mock.hpp>

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
void
get_platform_ids( cl_uint num_entries,
                  cl_platform_id* platforms,
                  cl_uint* num_platforms )
{
  status_t s = static_cast<status_t>(
      T::clGetPlatformIDs(num_entries, platforms, num_platforms)
  );
  if(is_error(s))
    {
      switch(s)
        {
          case status_t::invalid_value:
            throw clerror_no<status_t::invalid_value>();
          case status_t::out_of_host_memory:
            throw clerror_no<status_t::out_of_host_memory>();
          default:
            throw unexpected_clerror(s);
        }
    }
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
