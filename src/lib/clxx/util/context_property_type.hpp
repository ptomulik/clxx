/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/util/context_property_type.hpp

/** // doc: clxx/util/context_property_type.hpp {{{
 * \file clxx/util/context_property_type.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED
#define CLXX_UTIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/util/context_property_type_fwd.hpp>

namespace clxx {

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <>
  struct context_property_type<context_properties_t::platform>
  { typedef cl_platform_id type; };

template <>
  struct context_property_type<context_properties_t::interop_user_sync>
  { typedef bool type; };

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
template<>
  struct context_property_type<context_properties_t::adapter_d3d9ex_khr>
  { typedef IDirect3DDeviceEx* type; };
template<>
  struct context_property_type<context_properties_t::adapter_dxva_khr>
  { typedef IDXVAHD_Device* type; };
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

} // end namespace clxx

#endif /* CLXX_UTIL_CONTEXT_PROPERTY_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
