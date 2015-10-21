// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/context_property_type.hpp

/** // doc: clxx/common/detail/context_property_type.hpp {{{
 * \file clxx/common/detail/context_property_type.hpp
 * \brief Implements the \ref clxx::context_property_type "context_property_type" metafunction
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED

#include <clxx/common/types.hpp>
#include <clxx/common/detail/context_property_type_fwd.hpp>

namespace clxx { namespace detail {

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <>
  struct context_property_type<context_properties_t::platform>
  { typedef cl_platform_id type; };

#if CLXX_CL_H_VERSION_1_2
template <>
  struct context_property_type<context_properties_t::interop_user_sync>
  { typedef bool type; };
#endif

#if cl_khr_gl_sharing
template<>
  struct context_property_type<context_properties_t::gl_context_khr>
  { typedef void* type; /* OpenGL context handle */ };
template<>
  struct context_property_type<context_properties_t::egl_display_khr>
  { typedef void* type; /* EGLDisplay handle */ };
template<>
  struct context_property_type<context_properties_t::glx_display_khr>
  { typedef void* type; /* X Display handle */ };
template<>
  struct context_property_type<context_properties_t::wgl_hdc_khr>
  { typedef void* type; /* HDC handle */ };
template<>
  struct context_property_type<context_properties_t::cgl_sharegroup_khr>
  { typedef void* type; /* CGL share group handle */ };
#endif

#if cl_khr_dx9_media_sharing && defined(_WIN32)
template<>
  struct context_property_type<context_properties_t::adapter_d3d9_khr>
  { typedef IDirect3DDevice9* type; };
# if !defined(__CYGWIN__)
template<>
  struct context_property_type<context_properties_t::adapter_d3d9ex_khr>
  { typedef IDirect3DDevice9Ex* type; };
# endif
# if (_WIN32_WINNT >= 0x0601)
template<>
  struct context_property_type<context_properties_t::adapter_dxva_khr>
  { typedef IDXVAHD_Device* type; };
# endif
#endif

#if cl_khr_d3d10_sharing
template <>
  struct context_property_type<context_properties_t::d3d10_device_khr>
  { typedef ID3D10Device* type; };
#endif

#if cl_khr_d3d11_sharing
template <>
  struct context_property_type<context_properties_t::d3d11_device_khr>
  { typedef ID3D11Device* type; };
#endif
/** \endcond */

} } // end namespace clxx

#endif /* CLXX_COMMON_DETAIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
