// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/program_cached_ctor.t.h

/** // doc: clxx/x10d/program_cached_ctor.t.h {{{
 * \file clxx/x10d/program_cached_ctor.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_PROGRAM_CACHED_CTOR_T_H_INCLUDED
#define CLXX_X10D_PROGRAM_CACHED_CTOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/x10d/program_cached_ctor.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_cached_ctor_test_suite; }

/** // doc: class clxx::program_cached_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_cached_ctor_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__create_default_search_path__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__create_default_search_path__1( )
  {
#if 0
#ifdef CLXX_WINDOWS_API
    // TODO: write tests for windows once the implementation is ready
#else
    std::vector<std::string> paths(program_cached_ctor::create_default_search_path());
    const char* env;
    if((env = std::getenv("HOME")) != nullptr)
      {
        TS_ASSERT(paths.size() >= 1ul);
        if(paths.size() >= 1ul)
          {
            TS_ASSERT_EQUALS(paths.back(), path_join(env, ".clxx/program_cache"));
            paths.erase(paths.end()-1);
          }
      }
    if((env = std::getenv("CLXX_PROGRAM_CACHE_PATH")) != nullptr)
      {
        TS_ASSERT(paths.size() >= 1ul);
      }
#endif
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

#endif /* CLXX_X10D_PROGRAM_CACHED_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: