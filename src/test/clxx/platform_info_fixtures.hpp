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

// clxx/platform_info_fixtures.hpp

/** // doc: clxx/platform_info_fixtures.hpp {{{
 * \file clxx/platform_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED
#define CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED

#include <clxx/platform_info.hpp>

namespace clxx {

struct platform_info_fixtures
{
  static platform_info _1()
  {
    return platform_info()
        .set_id(0x1234ul)
        .set_profile("FULL_PROFILE")
        .set_version("OpenCL 1.2 AMD-APP (1348.4)")
        .set_name("AMD Accelerated Parallel Processing")
        .set_vendor("Advanced Micro Devices, Inc.")
        .set_extensions("cl_khr_icd cl_amd_event_callback cl_amd_offline_devices");
  }

  static platform_info _2()
  {
    return platform_info()
        .set_id(0x54321ul)
        .set_profile("xprofilex")
        .set_version("xversionx")
        .set_name("xnamex")
        .set_vendor("xvendorx")
        .set_extensions("xextensionsx");
  }
};


} // end namespace clxx

#endif /* CLXX_PLATFORM_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
