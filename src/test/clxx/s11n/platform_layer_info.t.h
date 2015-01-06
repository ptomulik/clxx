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

/** // doc: clxx/s11n/platform_layer_info.t.h {{{
 * \file clxx/s11n/platform_layer_info.t.h
 * \brief Unit tests for clxx::platform_layer_info
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_LAYER_INFO_T_H_INCLUDED
#define CLXX_S11N_PLATFORM_LAYER_INFO_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/s11n/platform_layer_info.hpp>
#include <clxx/platform_layer_info_fixtures.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

namespace clxx { class s11n_platform_layer_info_test_suite; }

/** // doc: class clxx::s11n_platform_layer_info_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::s11n_platform_layer_info_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_serialize_text() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_text()
  {
    platform_layer_info orig(platform_layer_info_fixtures::_1());
    platform_layer_info info;

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << orig; // serialize

    boost::archive::text_iarchive ia(ss);
    ia >> info; // deserialize

    TS_ASSERT_EQUALS(info, orig);
  }
  /** // doc: test_serialize_xml() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_xml()
  {
    using boost::serialization::make_nvp;
    platform_layer_info orig(platform_layer_info_fixtures::_1());
    platform_layer_info info;

    std::stringstream ss;

    boost::archive::xml_oarchive oa(ss);
    oa << make_nvp("platform_info", orig); // serialize

    boost::archive::xml_iarchive ia(ss);
    ia >> make_nvp("platform_info", info); // deserialize

    TS_ASSERT_EQUALS(info, orig);
  }
  /** // doc: test_serialize_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_binary()
  {
    platform_layer_info orig(platform_layer_info_fixtures::_1());
    platform_layer_info info;

    std::stringstream ss;

    boost::archive::binary_oarchive oa(ss);
    oa << orig; // serialize

    boost::archive::binary_iarchive ia(ss);
    ia >> info; // deserialize

    TS_ASSERT_EQUALS(info, orig);
  }
};

#endif /* CLXX_S11N_PLATFORM_LAYER_INFO_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
