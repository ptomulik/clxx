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

// clxx/exception.t.h

/** // doc: clxx/exception.t.h {{{
 * \file clxx/exception.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_EXCEPTION_T_H_INCLUDED
#define CLXX_EXCEPTION_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/exception.hpp>
#include <stdexcept>

namespace clxx { class exception_test; }

/** // doc: class clxx::exception_test {{{
 * \todo Write documentation
 */ // }}}
class clxx::exception_test : public CxxTest::TestSuite
{
public:
  /** // doc: test_exception1() {{{
   * \brief Ensure that we can derive new exceptions from clxx::exception
   */ // }}}
  void test_exception1( )
  {
    struct exception1
      : public clxx::exception,
        public std::exception
    {
      exception1() : clxx::exception(), std::exception() { }
      exception1(exception1 const& e) : clxx::exception(e), std::exception(e) { }
      virtual std::exception const& clxx2std() const noexcept { return *this; }
      virtual const char* what() const noexcept { return "exception1"; }
    };
    TS_ASSERT_EQUALS(exception1().what(), "exception1");
    TS_ASSERT_THROWS(throw exception1(), std::exception const&);
    TS_ASSERT_THROWS(throw exception1(), clxx::exception const&);
    TS_ASSERT_THROWS(throw exception1(), exception1 const&);
  }
  /** // doc: test_exception2() {{{
   * \brief Ensure that we can derive new exceptions from clxx::exception
   */ // }}}
  void test_exception2( )
  {
    struct exception2
      : public clxx::exception,
        public std::runtime_error
    {
      exception2() : clxx::exception(), std::runtime_error("exception2") { }
      exception2(exception2 const& e) : clxx::exception(e), std::runtime_error(e) { }
      virtual std::exception const& clxx2std() const noexcept { return *this; }
    };
    TS_ASSERT_EQUALS(exception2().what(), "exception2");
    TS_ASSERT_THROWS(throw exception2(), std::exception const&);
    TS_ASSERT_THROWS(throw exception2(), std::runtime_error const&);
    TS_ASSERT_THROWS(throw exception2(), clxx::exception const&);
    TS_ASSERT_THROWS(throw exception2(), exception2 const&);
  }
};

#endif /* CLXX_EXCEPTION_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
