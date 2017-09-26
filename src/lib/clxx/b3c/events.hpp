// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/events.hpp

/** // doc: clxx/b3c/events.hpp {{{
 * \file clxx/b3c/events.hpp
 * \brief Defines the \ref clxx::events collection
 */ // }}}
#ifndef CLXX_B3C_EVENTS_HPP_INCLUDED
#define CLXX_B3C_EVENTS_HPP_INCLUDED

#include <clxx/b3c/event.hpp>
#include <vector>

namespace clxx {
/** // doc: events {{{
 * \ingroup clxx_cl_event_objects
 * \brief Collection of clxx::event objects.
 */ // }}}
typedef std::vector<event> events;
} // end namespace clxx

namespace clxx {
/** \ingroup clxx_cl_event_objects
 * @{ */
/** // doc: wait_for_events() {{{
 * \brief Waits on the host thread for commands identified by event objects to complete
 *
 * \param event_list
 *    The events specified in \p event_list act as synchronization points.
 *
 * \par Exceptions
 *
 * Throws exceptions originating from
 * \ref clxx::wait_for_events(cl_uint,const cl_event*) "wait_for_events()".
 */ // }}}
void wait_for_events(clxx::events const& event_list);
/** @} */
}

#endif /* CLXX_B3C_EVENTS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
