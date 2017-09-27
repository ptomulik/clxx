// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b3c/events.cpp {{{
 * \file clxx/b3c/events.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/b3c/events.hpp>
#include <clxx/b5d/functions.hpp>
#include <clxx/b3c/detail/obj2cl.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
void
wait_for_events(clxx::events const& event_list)
{
  if(!event_list.empty())
    {
      wait_for_events(static_cast<cl_uint>(event_list.size()),
                      detail::obj2cl(event_list));
    }
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
