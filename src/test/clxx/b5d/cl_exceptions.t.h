// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_exceptions.t.h

/** // doc: clxx/b5d/cl_exceptions.t.h {{{
 * \file clxx/b5d/cl_exceptions.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_EXCEPTIONS_T_H_INCLUDED
#define CLXX_B5D_CL_EXCEPTIONS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_exceptions.hpp>

namespace clxx { class cl_exceptions_test_suite; }

/** // doc: class clxx::cl_exceptions_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::cl_exceptions_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__clerror_no__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_no__1( )
  {
    TS_ASSERT_THROWS(throw clerror_no<status_t::invalid_value>(), clerror_no<status_t::invalid_value> const&);
  }
  /** // doc: test__clerror_no__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_no__2( )
  {
    TS_ASSERT_THROWS(throw clerror_no<status_t::invalid_value>(), clerror const&);
  }
  /** // doc: test__clerror_no__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_no__3( )
  {
    TS_ASSERT_THROWS(throw clerror_no<status_t::invalid_value>(), exception const&);
  }
  /** // doc: test__clerror_no__code() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_no__code( )
  {
    TS_ASSERT_EQUALS(clerror_no<status_t::invalid_value>().code(), status_t::invalid_value);
  }
  /** // doc: test__clerror_no__what() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_no__what( )
  {
    TS_ASSERT_EQUALS(clerror_no<status_t::invalid_value>().what(), "invalid value");
  }
};

#endif /* CLXX_B5D_CL_EXCEPTIONS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
