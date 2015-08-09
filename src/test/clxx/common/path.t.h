// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/path.t.h

/** // doc: clxx/common/path.t.h {{{
 * \file clxx/common/path.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_PATH_T_H_INCLUDED
#define CLXX_COMMON_PATH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/path.hpp>

namespace clxx { class path_test_suite; }

/** // doc: class clxx::path_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::path_test_suite : public CxxTest::TestSuite
{
#ifdef CLXX_WINDOWS_API
# define SEP "\\"
#else
# define SEP "/"
#endif
public:
  /** // doc: test__path_separator__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__path_separator__1( )
  {
    TS_ASSERT_EQUALS(path_separator(), SEP[0]);
  }
  /** // doc: test__path_join__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__path_join__1( )
  {
    TS_ASSERT_EQUALS(path_join("",""),  "");
    TS_ASSERT_EQUALS(path_join(SEP,""), SEP);
    TS_ASSERT_EQUALS(path_join("",SEP), SEP);
    TS_ASSERT_EQUALS(path_join(SEP,SEP), SEP);
    TS_ASSERT_EQUALS(path_join("foo", ""), "foo");
    TS_ASSERT_EQUALS(path_join("", "bar"), "bar");
    TS_ASSERT_EQUALS(path_join("foo", "bar"), "foo" SEP "bar");
    TS_ASSERT_EQUALS(path_join("foo" SEP, "bar"), "foo" SEP "bar");
    TS_ASSERT_EQUALS(path_join("foo", SEP "bar"), "foo" SEP "bar");
    TS_ASSERT_EQUALS(path_join("foo" SEP, SEP "bar"), "foo" SEP "bar");
    TS_ASSERT_EQUALS(path_join(SEP "foo", "bar"), SEP "foo" SEP "bar");
    TS_ASSERT_EQUALS(path_join(SEP "foo" SEP "bar", "geez"), SEP "foo" SEP "bar" SEP "geez");
  }
};

#endif /* CLXX_COMMON_PATH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
