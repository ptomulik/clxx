// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b3c/kernel_fcn.cpp {{{
 * \file clxx/b3c/kernel_fcn.cpp
 * \brief Implements \ref clxx::enqueue_ndrange_kernel(clxx::command_queue const&, clxx::kernel const&, clxx::ndrange const&, clxx::events const&, clxx::event*) "enqueue_ndrange_kernel()" and friends.
 */ // }}}
#include <clxx/b3c/kernel_fcn.hpp>
#include <clxx/b5d/functions.hpp>
#include <clxx/b3c/command_queue.hpp>
#include <clxx/b3c/kernel.hpp>
#include <clxx/b3c/detail/obj2cl.hpp>
#include <clxx/c4n/ndrange.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       cl_uint num_events_in_wait_list,
                       clxx::event const* event_wait_list,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         num_events_in_wait_list,
                         detail::obj2cl(event_wait_list),
                         event ? detail::obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::events const& event_wait_list,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         event_wait_list.size(),
                         detail::obj2cl(event_wait_list),
                         event ? detail::obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
void
enqueue_ndrange_kernel(clxx::command_queue const& command_queue,
                       clxx::kernel const& kernel,
                       clxx::ndrange const& ndrange,
                       clxx::event* event)
{
  clxx::event tmp;
  enqueue_ndrange_kernel(command_queue.chk_get(),
                         kernel.chk_get(),
                         static_cast<cl_uint>(ndrange.dimension()),
                         ndrange.global_offset_ptr(),
                         ndrange.global_size_ptr(),
                         ndrange.local_size_ptr(),
                         0,
                         nullptr,
                         event ? detail::obj2cl(&tmp) : nullptr);
  if(event)
    *event = tmp; // maintain reference count in *event
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
