// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj_fcn.hpp

/** // doc: clxx/clobj_fcn.hpp {{{
 * \file clxx/clobj_fcn.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CLOBJ_FCN_HPP_INCLUDED
#define CLXX_CLOBJ_FCN_HPP_INCLUDED

#include <clxx/cl/cl.h>
#include <clxx/functions.hpp>

namespace clxx {
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_command_queue handle)
{
  retain_command_queue(handle);
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_context handle)
{
  retain_context(handle);
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_device_id handle)
{
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
  retain_device(handle);
#else
  (void)handle;
#endif
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_event handle)
{
  retain_event(handle);
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_kernel handle)
{
  retain_kernel(handle);
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_mem handle)
{
  retain_mem_object(handle);
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_platform_id)
{
}
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_program handle)
{
  retain_program(handle);
}
#if 0
/** // doc: retain_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
retain_clobj(cl_sampler handle)
{
  retain_sampler(handle);
}
#endif

/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_command_queue handle)
{
  release_command_queue(handle);
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_context handle)
{
  release_context(handle);
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_device_id handle)
{
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
  release_device(handle);
#else
  (void)handle;
#endif
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_event handle)
{
  release_event(handle);
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_kernel handle)
{
  release_kernel(handle);
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_mem handle)
{
  release_mem_object(handle);
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_platform_id)
{
}
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_program handle)
{
  release_program(handle);
}
#if 0
/** // doc: release_clobj() {{{
 * \todo Write documentation
 */ // }}}
inline void
release_clobj(cl_sampler handle)
{
  release_sampler(handle);
}
#endif

/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_command_queue handle,
               command_queue_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_command_queue_info( handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_context handle,
               context_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_context_info(       handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_device_id handle,
               device_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_device_info(        handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_event handle,
               event_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_event_info(         handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_kernel handle,
               kernel_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_kernel_info(        handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_mem handle,
               mem_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_mem_object_info(    handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_platform_id handle,
               platform_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_platform_info(      handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_program handle,
               program_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_program_info(       handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
#if 0
/** // doc: get_clobj_info() {{{
 * \todo Write documentation
 */ // }}}
inline void
get_clobj_info(cl_sampler handle,
               sampler_info_t param_name,
               size_t param_value_size,
               void* param_value,
               size_t* param_value_size_ret)
{
  get_sampler_info(       handle,
                          param_name,
                          param_value_size,
                          param_value,
                          param_value_size_ret);
}
#endif
} // end namespace clxx

#endif /* CLXX_CLOBJ_FCN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
