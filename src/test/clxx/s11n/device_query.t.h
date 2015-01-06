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

// clxx/device_query.t.h

/** // doc: clxx/s11n/device_query.t.h {{{
 * \file clxx/s11n/device_query.t.h
 * \brief Unit tests for clxx::device_query
 */ // }}}
#ifndef CLXX_S11N_DEVICE_QUERY_T_H_INCLUDED
#define CLXX_S11N_DEVICE_QUERY_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/s11n/device_query.hpp>
#include <clxx/device_query_fixtures.hpp>

// For serialization
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <sstream>

namespace clxx { class s11n_device_query_test_suite; }

/** // doc: class clxx::s11n_device_query_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::s11n_device_query_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_serialize_text() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_text( )
  {
    device_query a;
    device_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::text_oarchive oa(ss);
    oa << a;

    boost::archive::text_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_serialize_xml() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_xml( )
  {
    using boost::serialization::make_nvp;
    device_query a;
    device_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::xml_oarchive oa(ss);
    oa << make_nvp("device_query", a);

    boost::archive::xml_iarchive ia(ss);
    ia >> make_nvp("device_query", b);

    TS_ASSERT_EQUALS(a, b);
  }
  /** // doc: test_serialize_binary() {{{
   * \todo Write documentation
   */ // }}}
  void test_serialize_binary( )
  {
    device_query a;
    device_query b;

    a.select_none(); // set all to non-default values

    std::stringstream ss;

    boost::archive::binary_oarchive oa(ss);
    oa << a;

    boost::archive::binary_iarchive ia(ss);
    ia >> b;

    TS_ASSERT_EQUALS(a, b);
  }
};

#endif /* CLXX_S11N_DEVICE_QUERY_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
