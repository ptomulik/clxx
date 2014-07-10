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

// clxx/info/platform_layer_info_fixtures.hpp

/** // doc: clxx/info/platform_layer_info_fixtures.hpp {{{
 * \file clxx/info/platform_layer_info_fixtures.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_INFO_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED
#define CLXX_INFO_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED

#include <clxx/info/platform_layer_info.hpp>
#include <clxx/info/platform_info.hpp>
#include <clxx/info/device_info.hpp>

namespace clxx {

struct platform_layer_info_fixtures
  {
    static platform_layer_info _1()
    {
      platform_info_ptr p1(new platform_info());
      platform_info_ptr p2(new platform_info());
      device_info_ptr d11(new device_info());
      device_info_ptr d12(new device_info());
      device_info_ptr d21(new device_info());
      device_info_ptr d22(new device_info());

      p1->set_name("platform 1");
      p2->set_name("platform 2");

      d11->set_name("platform 1 device 1");
      d12->set_name("platform 1 device 2");
      d21->set_name("platform 2 device 1");
      d22->set_name("platform 2 device 2");

      platform_layer_info pli;

      pli.push_back(d11,p1);
      pli.push_back(d12,p1);
      pli.push_back(d21,p2);
      pli.push_back(d22,p2);

      return pli;
    }
  };

} // end namespace clxx

#endif /* CLXX_INFO_PLATFORM_LAYER_INFO_FIXTURES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
