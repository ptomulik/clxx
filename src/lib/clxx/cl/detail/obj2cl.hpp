// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/detail/obj2cl.hpp

/** // doc: clxx/cl/detail/obj2cl.hpp {{{
 * \file clxx/cl/detail/obj2cl.hpp
 * \brief Provides functions that convert clxx objects to corresponding OpenCL objects
 */ // }}}
#ifndef CLXX_CL_DETAIL_OBJ2CL_HPP_INCLUDED
#define CLXX_CL_DETAIL_OBJ2CL_HPP_INCLUDED

#include <clxx/cl/command_queue_fwd.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/device_fwd.hpp>
#include <clxx/cl/event_fwd.hpp>
#include <clxx/cl/kernel_fwd.hpp>
#include <clxx/cl/mem_fwd.hpp>
#include <clxx/cl/platform_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/common/opencl.h>
#include <vector>

namespace clxx { namespace detail {
/** \ingroup clxx_common_util_obj2cl
 * @{ */
/** // doc: obj2cl {{{
 * \brief Converts const clxx::command_queue* to const cl_command_queue*
 */ // }}}
inline cl_command_queue const*
obj2cl(clxx::command_queue const* command_queue)
{
  return reinterpret_cast<cl_command_queue const*>(command_queue);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::command_queue* to cl_command_queue*
 */ // }}}
inline cl_command_queue*
obj2cl(clxx::command_queue* command_queue)
{
  return reinterpret_cast<cl_command_queue*>(command_queue);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::context* to const cl_context*
 */ // }}}
inline cl_context const*
obj2cl(clxx::context const* context)
{
  return reinterpret_cast<cl_context const*>(context);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::context* to cl_context*
 */ // }}}
inline cl_context*
obj2cl(clxx::context* context)
{
  return reinterpret_cast<cl_context*>(context);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::device* to const cl_device_id*
 */ // }}}
inline cl_device_id const*
obj2cl(clxx::device const* device)
{
  return reinterpret_cast<cl_device_id const*>(device);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::device* to cl_device_id*
 */ // }}}
inline cl_device_id*
obj2cl(clxx::device* device)
{
  return reinterpret_cast<cl_device_id*>(device);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::event* to const cl_event*
 */ // }}}
inline cl_event const*
obj2cl(clxx::event const* event)
{
  return reinterpret_cast<cl_event const*>(event);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::event* to cl_event*
 */ // }}}
inline cl_event*
obj2cl(clxx::event* event)
{
  return reinterpret_cast<cl_event*>(event);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::kernel* to const cl_kernel*
 */ // }}}
inline cl_kernel const*
obj2cl(clxx::kernel const* kernel)
{
  return reinterpret_cast<cl_kernel const*>(kernel);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::kernel* to cl_kernel*
 */ // }}}
inline cl_kernel*
obj2cl(clxx::kernel* kernel)
{
  return reinterpret_cast<cl_kernel*>(kernel);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::mem* to const cl_mem*
 */ // }}}
inline cl_mem const*
obj2cl(clxx::mem const* mem)
{
  return reinterpret_cast<cl_mem const*>(mem);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::mem* to cl_mem*
 */ // }}}
inline cl_mem*
obj2cl(clxx::mem* mem)
{
  return reinterpret_cast<cl_mem*>(mem);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::platform* to const cl_platform_id*
 */ // }}}
inline cl_platform_id const*
obj2cl(clxx::platform const* platform)
{
  return reinterpret_cast<cl_platform_id const*>(platform);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::platform* to cl_platform_id*
 */ // }}}
inline cl_platform_id*
obj2cl(clxx::platform* platform)
{
  return reinterpret_cast<cl_platform_id*>(platform);
}
/** // doc: obj2cl {{{
 * \brief Converts const clxx::program* to const cl_program*
 */ // }}}
inline cl_program const*
obj2cl(clxx::program const* program)
{
  return reinterpret_cast<cl_program const*>(program);
}
/** // doc: obj2cl {{{
 * \brief Converts clxx::program* to cl_program*
 */ // }}}
inline cl_program*
obj2cl(clxx::program* program)
{
  return reinterpret_cast<cl_program*>(program);
}
/** // doc: obj2cl {{{
 * \brief Same as obj2cl(v.data())
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T> const& v)
  -> decltype(obj2cl(v.data()))
{
  return obj2cl(v.data());
}
/** // doc: obj2cl {{{
 * \brief Same as obj2cl(v.data())
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T>& v)
  -> decltype(obj2cl(v.data()))
{
  return obj2cl(v.data());
}
/** // doc: obj2cl {{{
 * \brief Same as obj2cl(v->data())
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T> const* v)
  -> decltype(obj2cl(v->data()))
{
  return v ? obj2cl(v->data()) : nullptr;
}
/** // doc: obj2cl {{{
 * \brief Same as obj2cl(v->data())
 */ // }}}
template<typename T>
inline auto
obj2cl(std::vector<T>* v)
  -> decltype(obj2cl(v->data()))
{
  return v ? obj2cl(v->data()) : nullptr;
}
/** @} */
} } // end namespace clxx::detail

#endif /* CLXX_CL_DETAIL_OBJ2CL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
