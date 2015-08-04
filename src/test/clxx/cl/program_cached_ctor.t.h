// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_cached_ctor.t.h

/** // doc: clxx/cl/program_cached_ctor.t.h {{{
 * \file clxx/cl/program_cached_ctor.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_CACHED_CTOR_T_H_INCLUDED
#define CLXX_CL_PROGRAM_CACHED_CTOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/program_cached_ctor.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_cached_ctor_test_suite; }

/** // doc: class clxx::program_cached_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_cached_ctor_test_suite : public CxxTest::TestSuite
{
#ifdef _WIN32
#define PATHSEP L";"
#else
#define PATHSEP L":"
#endif
public:
  /** // doc: test__clear_default_cache_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__clear_default_cache_path__1( )
  {
    program_cached_ctor::clear_default_cache_path();
    TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"");
  }
  /** // doc: test__append_default_cache_wpath__0() {{{
   * \todo Write documentation
   */ // }}}
  void test__append_default_cache_wpath__0( )
  {
    {
      program_cached_ctor::clear_default_cache_path();
      program_cached_ctor::append_default_cache_wpath(L"");
      TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"")
    }
    {
      program_cached_ctor::clear_default_cache_path();
      program_cached_ctor::append_default_cache_wpath(PATHSEP);
      TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"")
    }
    {
      program_cached_ctor::clear_default_cache_path();
      program_cached_ctor::append_default_cache_wpath(PATHSEP PATHSEP);
      TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"")
    }
  }
  /** // doc: test__append_default_cache_wpath__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__append_default_cache_wpath__1( )
  {
    program_cached_ctor::clear_default_cache_path();
    program_cached_ctor::append_default_cache_wpath(L"foo1/bar1");
    TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"foo1/bar1")
  }
  /** // doc: test__append_default_cache_wpath__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__append_default_cache_wpath__2( )
  {
    program_cached_ctor::clear_default_cache_path();
    program_cached_ctor::append_default_cache_wpath(L"foo1/bar1" PATHSEP "foo2/bar2/geez2");
    TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"foo1/bar1" PATHSEP "foo2/bar2/geez2")
  }
  /** // doc: test__append_default_cache_wpath__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__append_default_cache_wpath__3( )
  {
    program_cached_ctor::clear_default_cache_path();
    program_cached_ctor::append_default_cache_wpath(L"foo1/bar1" PATHSEP PATHSEP "foo2/bar2/geez2");
    TS_ASSERT_EQUALS(program_cached_ctor::get_default_cache_wpath(), L"foo1/bar1" PATHSEP "foo2/bar2/geez2")
  }
};

#endif /* CLXX_CL_PROGRAM_CACHED_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
