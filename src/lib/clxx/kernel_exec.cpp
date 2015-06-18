// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/kernel_exec.cpp {{{
 * \file clxx/kernel_exec.cpp
 * \brief Implements \ref clxx::enqueue_ndrange_kernel(clxx::command_queue const&, clxx::kernel const&, clxx::ndrange const&, clxx::events const&) "enqueue_ndrange_kernel()" and friends.
 */ // }}}
#include <clxx/kernel_exec.hpp>
#include <clxx/functions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T, class X>
static boost::shared_array<T>
_identifiers_impl(X const& x)
{
  typedef boost::shared_array<T> array;
  array a(new T[x.size()]);
  auto op =  [](typename X::const_reference d) -> T { return d.id(); };
  std::transform(x.begin(), x.end(), a.get(), op);
  return a;
}
/* ------------------------------------------------------------------------ */
static boost::shared_array<cl_event>
_identifiers(events const& x)
{
  return _identifiers_impl<cl_event, events>(x);
}
/* ------------------------------------------------------------------------ */
event
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::events const& event_wait_list)
{
  cl_event id;
  enqueue_ndrange_kernel(command_queue.get_valid_id(),
                         kernel.get_valid_id(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         event_wait_list.size(),
                         _identifiers(event_wait_list).get(),
                         &id);
  return event(id);
}
/* ------------------------------------------------------------------------ */
event
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange)
{
  cl_event id;
  enqueue_ndrange_kernel(command_queue.get_valid_id(),
                         kernel.get_valid_id(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         0,
                         nullptr,
                         &id);
  return event(id);
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
