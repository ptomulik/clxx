// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b3c/command_queue.cpp {{{
 * \file clxx/b3c/command_queue.cpp
 * \brief Implements the \ref clxx::command_queue "command_queue" class
 */ // }}}
#include <clxx/b3c/command_queue.hpp>
#include <clxx/b3c/context.hpp>
#include <clxx/b3c/device.hpp>
#include <clxx/b3c/clobj_impl.hpp>
#include <clxx/b5d/functions.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
// Instantiate the base class
template class clobj<cl_command_queue>;
static_assert(
    sizeof(clobj<cl_command_queue>) == sizeof(cl_command_queue),
    "sizeof(clobj<cl_command_queue>) differs from sizeof(cl_command_queue)"
);
/* ------------------------------------------------------------------------ */
command_queue::
command_queue(context const& ctx, device const& dev, command_queue_properties_t props)
{
#if CLXX_B5D_PROVIDES(create_comman_queue)
  cl_command_queue handle = create_command_queue( ctx.chk_get(),
                                                  dev.chk_get(),
                                                  props );
  this->_set_handle(handle, false, false);
#elif CLXX_B5D_PROVIDES(create_command_queue_with_properties)
  cl_queue_properties props_array[3] = {  CL_QUEUE_PROPERTIES,
                                          intval(props),
                                          static_cast<cl_queue_properties>(0) };
  cl_command_queue handle = create_command_queue_with_properties(
                                                  ctx.chk_get(),
                                                  dev.chk_get(),
                                                  props_array );
  this->_set_handle(handle, false, false);
#else
(void)ctx;
(void)dev;
(void)props;
# error Missing clCreateCommandQueue() and clCreateCommandQueueWithProperties() do you have OpenCL library installed?
#endif
}
/* ------------------------------------------------------------------------ */
context command_queue::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, command_queue_info_t::context));
}
/* ------------------------------------------------------------------------ */
device command_queue::
get_device() const
{
  return device(_get_pod_info<cl_device_id>(*this, command_queue_info_t::device));
}
/* ------------------------------------------------------------------------ */
command_queue_properties_t command_queue::
get_properties() const
{
  return static_cast<command_queue_properties_t>(
    _get_pod_info<cl_command_queue_properties>(*this,command_queue_info_t::properties)
  );
}
/* ------------------------------------------------------------------------ */
void command_queue::
flush() const
{
  clxx::flush(chk_get());
}
/* ------------------------------------------------------------------------ */
void command_queue::
finish() const
{
  clxx::finish(chk_get());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
