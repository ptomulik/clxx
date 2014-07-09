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

// clxx/unit.t.h

/** // doc: clxx/unit.t.h {{{
 * \file clxx/unit.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UNIT_T_H_INCLUDED
#define CLXX_UNIT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/unit.hpp>

namespace clxx { class unit_test_suite; }

/** // doc: class clxx::unit_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::unit_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_foo() {{{
   * \todo Write documentation
   */ // }}}
  void test_foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_UNIT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
