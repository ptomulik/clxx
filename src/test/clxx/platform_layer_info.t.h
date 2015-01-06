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

// clxx/platform_layer_info.t.h

/** // doc: clxx/platform_layer_info.t.h {{{
 * \file clxx/platform_layer_info.t.h
 * \brief Unit tests for clxx::platform_layer_info
 */ // }}}
#ifndef CLXX_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define CLXX_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/platform_layer_info.hpp>
#include <clxx/platform_layer_info_fixtures.hpp>
#include <clxx/platform_info.hpp>
#include <clxx/device_info.hpp>

namespace clxx { class platform_layer_info_test_suite; }

/** // doc: class clxx::platform_layer_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::platform_layer_info_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_default_ctor( )
  {
    TS_ASSERT_THROWS_NOTHING(platform_layer_info p);
    TS_ASSERT(platform_layer_info().get_platforms().empty());
    TS_ASSERT(platform_layer_info().get_devices().empty());
  }
  /** // doc: test_mapping_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_mapping_1( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());

    TS_ASSERT_EQUALS(pli.get_platforms().size(), 2);

    const_platform_info_ptr p1(pli.get_platforms()[0]);
    const_platform_info_ptr p2(pli.get_platforms()[1]);

    TS_ASSERT_EQUALS(pli.get_devices().size(), 4);
    TS_ASSERT_EQUALS(pli.get_devices(p1).size(), 2);
    TS_ASSERT_EQUALS(pli.get_devices(p2).size(), 2);

    TS_ASSERT_EQUALS(pli.get_platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(pli.get_platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.get_devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.get_devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.get_devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.get_devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(pli.get_devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(pli.get_devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(pli.get_devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[0]), p1);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[1]), p1);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[2]), p2);
    TS_ASSERT_EQUALS(pli.get_platform(pli.get_devices()[3]), p2);

    // peek some functions via the const platform_layer_info object
    platform_layer_info const& cpli = pli;
    TS_ASSERT_EQUALS(cpli.get_platforms()[0]->name(),"platform 1");
    TS_ASSERT_EQUALS(cpli.get_platforms()[1]->name(),"platform 2");

    TS_ASSERT_EQUALS(cpli.get_devices()[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices()[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.get_devices()[2]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices()[3]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.get_devices(p1)[0]->name(),"platform 1 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices(p1)[1]->name(),"platform 1 device 2");
    TS_ASSERT_EQUALS(cpli.get_devices(p2)[0]->name(),"platform 2 device 1");
    TS_ASSERT_EQUALS(cpli.get_devices(p2)[1]->name(),"platform 2 device 2");

    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[0]), p1);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[1]), p1);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[2]), p2);
    TS_ASSERT_EQUALS(cpli.get_platform(cpli.get_devices()[3]), p2);
  }
  /** // doc: test_remove_device() {{{
   * \todo Write documentation
   */ // }}}
  void test_remove_device( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());

    pli.remove(pli.get_devices(pli.get_platforms()[1])[0]);
    TS_ASSERT_EQUALS(pli.get_devices().size(), 3);
    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 1 device 1")
    TS_ASSERT_EQUALS(pli.get_devices()[1]->name(),"platform 1 device 2")
    TS_ASSERT_EQUALS(pli.get_devices()[2]->name(),"platform 2 device 2")

    pli.remove(pli.get_platforms()[0]);
    TS_ASSERT_EQUALS(pli.get_devices().size(), 1);
    TS_ASSERT_EQUALS(pli.get_platforms().size(), 1);
    TS_ASSERT_EQUALS(pli.get_devices()[0]->name(),"platform 2 device 2");

    pli.remove(pli.get_devices()[0]);
    TS_ASSERT(pli.get_devices().empty());
    TS_ASSERT(pli.get_platforms().empty());
  }
  /** // doc: test_clear() {{{
   * \todo Write documentation
   */ // }}}
  void test_clear( )
  {
    platform_layer_info pli(platform_layer_info_fixtures::_1());
    pli.clear();
    TS_ASSERT(pli.get_platforms().empty());
    TS_ASSERT(pli.get_devices().empty());
  }
  /** // doc: test_empty() {{{
   * \todo Write documentation
   */ // }}}
  void test_empty( )
  {
    platform_layer_info pli;
    TS_ASSERT(pli.empty());
    pli = platform_layer_info_fixtures::_1();
    TS_ASSERT(!pli.empty());
    pli.clear();
    TS_ASSERT(pli.empty());
  }
};

#endif /* CLXX_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
