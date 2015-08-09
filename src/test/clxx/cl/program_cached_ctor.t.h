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
#include <clxx/common/path.hpp>

namespace clxx { class program_cached_ctor_test_suite; }

/** // doc: class clxx::program_cached_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_cached_ctor_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__get_default_search_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_default_search_path__1( )
  {
#ifdef CLXX_WINDOWS_API
    // TODO: write tests for windows once the implementation is ready
#else
    std::vector<std::string> paths(program_cached_ctor::get_default_search_path());
    const char* home;
    if((home = std::getenv("HOME")) != nullptr)
      {
        TS_ASSERT(paths.size() >= 1ul);
        TS_ASSERT_EQUALS(paths.back(), path_join(home, ".clxx/program_cache"));
      }
#endif
  }
  /** // doc: test__foo() {{{
   * \todo Write documentation
   */ // }}}
  void test__foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_CL_PROGRAM_CACHED_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
