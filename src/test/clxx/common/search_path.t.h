// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/search_path.t.h

/** // doc: clxx/common/search_path.t.h {{{
 * \file clxx/common/search_path.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_COMMON_SEARCH_PATH_T_H_INCLUDED
#define CLXX_COMMON_SEARCH_PATH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/common/search_path.hpp>

#ifdef CLXX_WINDOWS_API
# define DELIM   ";"
#else
# define DELIM   ":"
#endif

namespace clxx { class search_path_test_suite; }

/** // doc: class clxx::search_path_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::search_path_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__search_path_delimiter__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_delimiter__1( )
  {
    TS_ASSERT_EQUALS(search_path_delimiter(), DELIM[0]);
  }
  /** // doc: test__search_path_split__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__1( )
  {
    search_paths paths;
    
    paths = search_path_split("");
    TS_ASSERT(paths.empty());

    paths = search_path_split(DELIM);
    TS_ASSERT_EQUALS(paths.size(),2ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "");

    paths = search_path_split(DELIM DELIM);
    TS_ASSERT_EQUALS(paths.size(),3ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "");
    TS_ASSERT_EQUALS(paths[2], "");
  }
  /** // doc: test__search_path_split__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__2( )
  {
    search_paths paths;

    paths = search_path_split("/foo1/bar1" DELIM);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "");

    paths = search_path_split(DELIM "/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "/foo1/bar1");

    paths = search_path_split(DELIM "/foo1/bar1" DELIM);
    TS_ASSERT_EQUALS(paths.size(), 3ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[2], "");
  }
  /** // doc: test__search_path_split__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__3( )
  {
    search_paths paths;

    paths = search_path_split("/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split("/foo1/bar1" DELIM "/foo2/bar2");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");

    paths = search_path_split("/foo1/bar1" DELIM "/foo2/bar2" DELIM "/foo3/bar3");
    TS_ASSERT_EQUALS(paths.size(), 3ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(paths[2], "/foo3/bar3");
  }
  /** // doc: test__search_path_split__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__4( )
  {
    search_paths paths;

    paths = search_path_split("/foo1/bar1", std::locale::classic());
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split("/foo1/bar1" DELIM "/foo2/bar2", std::locale::classic());
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");

    paths = search_path_split("/foo1/bar1" DELIM "/foo2/bar2" DELIM "/foo3/bar3", std::locale::classic());
    TS_ASSERT_EQUALS(paths.size(), 3ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(paths[2], "/foo3/bar3");
  }
  /** // doc: test__search_path_join__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__1( )
  {
    TS_ASSERT_EQUALS(search_path_join(search_paths()), "");
    TS_ASSERT_EQUALS(search_path_join(search_paths{""}), "");
    TS_ASSERT_EQUALS(search_path_join(search_paths{"",""}), DELIM);
  }
  /** // doc: test__search_path_join__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__2( )
  {
    TS_ASSERT_EQUALS(search_path_join(search_paths{"/foo1/bar1"}), "/foo1/bar1");
    TS_ASSERT_EQUALS(search_path_join(search_paths{"/foo1/bar1", ""}), "/foo1/bar1" DELIM);
    TS_ASSERT_EQUALS(search_path_join(search_paths{"", "/foo1/bar1"}), DELIM "/foo1/bar1");
    TS_ASSERT_EQUALS(search_path_join(search_paths{"/foo1/bar1", "/foo2/bar2"}), "/foo1/bar1" DELIM "/foo2/bar2");
  }
  /** // doc: test__search_path_unique__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2", "/foo1/bar1" };
    search_paths result(search_path_unique(paths));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_unique__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__2( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2", "/foo1/bar1", "/foo3/bar3" };
    search_paths result(search_path_unique(paths, search_paths{ "/foo3/bar3" }));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_append__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
    search_paths& result = search_path_append(paths, {"/foo3/bar3", "/foo4/bar4"});

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], "/foo3/bar3");
    TS_ASSERT_EQUALS(result[3], "/foo4/bar4");
  }
  /** // doc: test__search_path_prepend__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
    search_paths& result = search_path_prepend(paths, {"/foo3/bar3", "/foo4/bar4"});

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], "/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], "/foo4/bar4");
    TS_ASSERT_EQUALS(result[2], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[3], "/foo2/bar2");
  }
  /** // doc: test__search_path_append_unique__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append_unique__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
    search_paths& result = search_path_append_unique(paths, {"/foo3/bar3", "/foo2/bar2", "/foo3/bar3"});

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], "/foo3/bar3");
  }
  /** // doc: test__search_path_prepend_unique__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend_unique__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2" };
    search_paths& result = search_path_prepend_unique(paths, {"/foo3/bar3", "/foo2/bar2", "/foo3/bar3"});

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], "/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[2], "/foo2/bar2");
  }
  /** // doc: test__search_path_erase__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__1( )
  {
    search_paths paths{ "/foo1/bar1", "/foo2/bar2", "/foo3/bar3", "/foo2/bar2", "/foo4/bar4"};
    search_paths const& pref = search_path_erase(paths, { "/foo2/bar2", "/foo4/bar4" });
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo3/bar3");
  }
};

#endif /* CLXX_COMMON_SEARCH_PATH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
