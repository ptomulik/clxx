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

// clxx/util/context_property_type.t.h

/** // doc: clxx/util/context_property_type.t.h {{{
 * \file clxx/util/context_property_type.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_CONTEXT_PROPERTY_TYPE_T_H_INCLUDED
#define CLXX_UTIL_CONTEXT_PROPERTY_TYPE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/util/context_property_type.hpp>
#include <type_traits>

namespace clxx { class context_property_type_test_suite; }

/** // doc: class clxx::context_property_type_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::context_property_type_test_suite : public CxxTest::TestSuite
{
  template <context_properties_t T1, class T2>
  constexpr static bool chk_types() noexcept
  {
    return (std::is_same<typename context_property_type<T1>::type,T2>::value);
  }
public:
  /** // doc: test_platform() {{{
   * \todo Write documentation
   */ // }}}
  void test_platform( )
  {
    TS_ASSERT((chk_types<context_properties_t::platform, cl_platform_id>()));
  }
  /** // doc: test_interop_user_sync() {{{
   * \todo Write documentation
   */ // }}}
  void test_interop_user_sync( )
  {
    TS_ASSERT((chk_types<context_properties_t::interop_user_sync, bool>()));
  }
  /** // doc: test_gl_context_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_gl_context_khr( )
  {
#if cl_khr_gl_sharing
    TS_ASSERT((chk_types<context_properties_t::gl_context_khr, void*>()));
#endif
  }
  /** // doc: test_egl_display_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_egl_display_khr( )
  {
#if cl_khr_gl_sharing
    TS_ASSERT((chk_types<context_properties_t::egl_display_khr, void*>()));
#endif
  }
  /** // doc: test_glx_display_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_glx_display_khr( )
  {
#if cl_khr_gl_sharing
    TS_ASSERT((chk_types<context_properties_t::glx_display_khr, void*>()));
#endif
  }
  /** // doc: test_wgl_hdc_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_wgl_hdc_khr( )
  {
#if cl_khr_gl_sharing
    TS_ASSERT((chk_types<context_properties_t::wgl_hdc_khr, void*>()));
#endif
  }
  /** // doc: test_cgl_sharegroup_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_cgl_sharegroup_khr( )
  {
#if cl_khr_gl_sharing
    TS_ASSERT((chk_types<context_properties_t::cgl_sharegroup_khr, void*>()));
#endif
  }
  /** // doc: test_adapter_d3d9_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_adapter_d3d9_khr( )
  {
#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT((chk_types<context_properties_t::adapter_d3d9_khr, IDirect3DDevice9*>()));
#endif
  }
  /** // doc: test_adapter_d3d9ex_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_adapter_d3d9ex_khr( )
  {
#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT((chk_types<context_properties_t::adapter_d3d9ex_khr, IDirect3DDeviceEx*>()));
#endif
  }
  /** // doc: test_adapter_dxva_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_adapter_dxva_khr( )
  {
#if cl_khr_dx9_media_sharing && defined(_WIN32)
    TS_ASSERT((chk_types<context_properties_t::adapter_dxva_khr, IDXVAHD_Device*>()));
#endif
  }
  /** // doc: test_d3d10_device_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_d3d10_device_khr( )
  {
#if cl_khr_d3d10_sharing
    TS_ASSERT((chk_types<context_properties_t::d3d10_device_khr, ID3D10Device*>()));
#endif
  }
  /** // doc: test_d3d11_device_khr() {{{
   * \todo Write documentation
   */ // }}}
  void test_d3d11_device_khr( )
  {
#if cl_khr_d3d11_sharing
    TS_ASSERT((chk_types<context_properties_t::d3d11_device_khr, ID3D11Device*>()));
#endif
  }
};

#endif /* CLXX_UTIL_CONTEXT_PROPERTY_TYPE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
