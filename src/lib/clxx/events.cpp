// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/events.cpp {{{
 * \file clxx/events.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/events.hpp>
#include <clxx/functions.hpp>

namespace clxx {
void
wait_for_events(clxx::events const& event_list)
{
  if(!event_list.empty())
    {
      wait_for_events(event_list.size(),
                      reinterpret_cast<cl_event const*>(event_list.data()));
    }
}
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
