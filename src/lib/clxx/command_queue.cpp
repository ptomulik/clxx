// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/command_queue.cpp {{{
 * \file clxx/command_queue.cpp
 * \brief Implements the \ref clxx::command_queue "command_queue" class
 */ // }}}
#include <clxx/command_queue.hpp>
#include <clxx/context.hpp>
#include <clxx/device.hpp>
#include <clxx/clobj_impl.hpp>
#include <clxx/functions.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
command_queue::
command_queue(context const& ctx, device const& dev, command_queue_properties_t props)
{
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
  cl_command_queue handle = create_command_queue( ctx.get_valid_handle(),
                                                  dev.get_valid_handle(),
                                                  props );
#elif CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
  cl_queue_properties props_array[3] = {  CL_QUEUE_PROPERTIES,
                                          intval(props),
                                          static_cast<cl_queue_properties>(0) };
  cl_command_queue handle = create_command_queue_with_properties(
                                                  ctx.get_valid_handle(),
                                                  dev.get_valid_handle(),
                                                  props_array );
#endif
  this->_set_handle(handle, false, false);
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
cl_uint command_queue::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, command_queue_info_t::reference_count);
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
  clxx::flush(get_valid_handle());
}
/* ------------------------------------------------------------------------ */
void command_queue::
finish() const
{
  clxx::finish(get_valid_handle());
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
