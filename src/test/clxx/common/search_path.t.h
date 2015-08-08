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
# define SEP8   u8";"
# define SEP32  U";"
#else
# define SEP8   u8":"
# define SEP32  U":"
#endif

namespace clxx { class search_path_test_suite; }

/** // doc: class clxx::search_path_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::search_path_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__search_path_separator__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_separator__1( )
  {
    TS_ASSERT_EQUALS(search_path_separator(), SEP8[0]);
  }
  /** // doc: test__search_path_split__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__1( )
  {
    std::vector<std::string> paths;
    
    paths = search_path_split("");
    TS_ASSERT(paths.empty());

    paths = search_path_split(SEP8);
    TS_ASSERT_EQUALS(paths.size(),2ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "");

    paths = search_path_split(SEP8 SEP8);
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
    std::vector<std::string> paths;

    paths = search_path_split("/foo1/bar1" SEP8);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "");

    paths = search_path_split(SEP8 "/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "");
    TS_ASSERT_EQUALS(paths[1], "/foo1/bar1");

    paths = search_path_split(SEP8 "/foo1/bar1" SEP8);
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
    std::vector<std::string> paths;

    paths = search_path_split("/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split("/foo1/bar1" SEP8 "/foo2/bar2");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");

    paths = search_path_split("/foo1/bar1" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3");
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
    std::vector<std::string> paths;

    paths = search_path_split("/foo1/bar1", std::locale::classic());
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split("/foo1/bar1" SEP8 "/foo2/bar2", std::locale::classic());
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");

    paths = search_path_split("/foo1/bar1" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3", std::locale::classic());
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
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>()), "");
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{""}), "");
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{"",""}), SEP8);
  }
  /** // doc: test__search_path_join__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__2( )
  {
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{"/foo1/bar1"}), "/foo1/bar1");
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{"/foo1/bar1", ""}), "/foo1/bar1" SEP8);
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{"", "/foo1/bar1"}), SEP8 "/foo1/bar1");
    TS_ASSERT_EQUALS(search_path_join(std::vector<std::string>{"/foo1/bar1", "/foo2/bar2"}), "/foo1/bar1" SEP8 "/foo2/bar2");
  }
  /** // doc: test__search_path_unique__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__1( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2", "/foo1/bar1" };
    std::vector<std::string> result(search_path_unique(paths));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_unique__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__2( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2", "/foo1/bar1", "/foo3/bar3" };
    std::vector<std::string> result(search_path_unique(paths, std::vector<std::string>{ "/foo3/bar3" }));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_append__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append__1( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string>& result(search_path_append(paths, "/foo3/bar3" SEP8 "/foo4/bar4"));

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], "/foo3/bar3");
    TS_ASSERT_EQUALS(result[3], "/foo4/bar4");
  }
  /** // doc: test__search_path_append__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append__2( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string>& result(search_path_append(paths, "/foo3/bar3" SEP8 "/foo4/bar4", std::locale::classic()));

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
    std::vector<std::string> paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    std::vector<std::string>& result(search_path_prepend(paths, u8"/foo3/bar3" SEP8 u8"/foo4/bar4"));

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], u8"/foo4/bar4");
    TS_ASSERT_EQUALS(result[2], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[3], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_prepend__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend__2( )
  {
    std::vector<std::string> paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    std::vector<std::string>& result(search_path_prepend(paths, u8"/foo3/bar3" SEP8 u8"/foo4/bar4", std::locale::classic()));

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], u8"/foo4/bar4");
    TS_ASSERT_EQUALS(result[2], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[3], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_append_unique__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append_unique__1( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string>& result(search_path_append_unique(paths, "/foo3/bar3" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3"));

    TS_ASSERT(&result == &paths);
    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], "/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], "/foo3/bar3");
  }
  /** // doc: test__search_path_append_unique__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append_unique__2( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string>& result(search_path_append_unique(paths, "/foo3/bar3" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3", std::locale::classic()));

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
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string> result(search_path_prepend_unique(paths, "/foo3/bar3" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3"));

    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], "/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], "/foo1/bar1");
    TS_ASSERT_EQUALS(result[2], "/foo2/bar2");
  }
  /** // doc: test__search_path_prepend_unique__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend_unique__2( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2" };
    std::vector<std::string> result(search_path_prepend_unique(paths, "/foo3/bar3" SEP8 "/foo2/bar2" SEP8 "/foo3/bar3", std::locale::classic()));

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
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2", "/foo3/bar3", "/foo2/bar2"};
    std::vector<std::string> const& pref = search_path_erase(paths, "/foo2/bar2");
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo3/bar3");
  }
  /** // doc: test__search_path_erase__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__2( )
  {
    std::vector<std::string> paths{ "/foo1/bar1", "/foo2/bar2", "/foo3/bar3", "/foo2/bar2"};
    std::vector<std::string> const& pref = search_path_erase(paths, "/foo2/bar2", std::locale::classic());
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo3/bar3");
  }
//  /** // doc: test__search_path_erase__2__char__char() {{{
//   * \todo Write documentation
//   */ // }}}
//  void test__search_path_erase__2__char__char( )
//  {
//    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2", u8"/foo3/bar3", u8"/foo2/bar2"};
//    u8search_paths const& pref = search_path_erase(paths, u8"/foo2/bar2" SEP8 u8"/foo3/bar3");
//    TS_ASSERT(&pref == &paths);
//    TS_ASSERT_EQUALS(paths.size(), 1ul);
//    TS_ASSERT_EQUALS(paths[0], u8"/foo1/bar1");
//  }
};

#endif /* CLXX_COMMON_SEARCH_PATH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
