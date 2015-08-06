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

#ifdef _WIN32
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
#ifdef _WIN32
    TS_ASSERT_EQUALS(search_path_separator(), U';');
#else
    TS_ASSERT_EQUALS(search_path_separator(), U':');
#endif
  }
  /** // doc: test__search_path_split_u32__1__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__1__char32_t( )
  {
    u32search_paths paths;
    
    paths = search_path_split_u32<char32_t>(U"");
    TS_ASSERT(paths.empty());

    paths = search_path_split_u32<char32_t>(SEP32);
    TS_ASSERT(paths.empty());

    paths = search_path_split_u32<char32_t>(SEP32 SEP32);
    TS_ASSERT(paths.empty());
  }
  /** // doc: test__search_path_split_u32__1__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__1__char( )
  {
    u8search_paths paths;
    
    paths = search_path_split_u32<char>(U"");
    TS_ASSERT(paths.empty());

    paths = search_path_split_u32<char>(SEP32);
    TS_ASSERT(paths.empty());

    paths = search_path_split_u32<char>(SEP32 SEP32);
    TS_ASSERT(paths.empty());
  }
  /** // doc: test__search_path_split_u32__2__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__2__char32_t( )
  {
    u32search_paths paths;

    paths = search_path_split_u32<char32_t>(U"/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");

    paths = search_path_split_u32<char32_t>(U"/foo1/bar1" SEP32 "/foo2/bar2");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], U"/foo2/bar2");
  }
  /** // doc: test__search_path_split_u32__2__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__2__char( )
  {
    u8search_paths paths;

    paths = search_path_split_u32<char>(U"/foo1/bar1");
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split_u32<char>(U"/foo1/bar1" SEP32 "/foo2/bar2");
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_split_u32__3__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__3__char32_t( )
  {
    u32search_paths paths;

    paths = search_path_split_u32<char32_t>(SEP32 U"/foo1/bar1" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");

    paths = search_path_split_u32<char32_t>(SEP32 U"/foo1/bar1" SEP32 U"/foo2/bar2" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], U"/foo2/bar2");
  }
  /** // doc: test__search_path_split_u32__3__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__3__char( )
  {
    u8search_paths paths;

    paths = search_path_split_u32<char>(SEP32 U"/foo1/bar1" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");

    paths = search_path_split_u32<char>(SEP32 U"/foo1/bar1" SEP32 U"/foo2/bar2" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], "/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], "/foo2/bar2");
  }
  /** // doc: test__search_path_split_u32__4__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__4__char32_t( )
  {
    u32search_paths paths;

    paths = search_path_split_u32<char32_t>(SEP32 U"/żółć1/jaźń1" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");

    paths = search_path_split_u32<char32_t>(SEP32 U"/żółć1/jaźń1" SEP32 U"/żółć2/jaźń2" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], U"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_split_u32__4__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split_u32__4__char( )
  {
    u8search_paths paths;

    paths = search_path_split_u32<char>(SEP32 U"/żółć1/jaźń1" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");

    paths = search_path_split_u32<char>(SEP32 U"/żółć1/jaźń1" SEP32 U"/żółć2/jaźń2" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], u8"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_split__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__1__char32_t__char32_t( )
  {
    u32search_paths paths;

    paths = search_path_split<char32_t>(SEP32 U"/żółć1/jaźń1" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");

    paths = search_path_split<char32_t>(SEP32 U"/żółć1/jaźń1" SEP32 U"/żółć2/jaźń2" SEP32);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], U"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_split__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__1__char__char( )
  {
    u8search_paths paths;

    paths = search_path_split<char>(SEP8 u8"/żółć1/jaźń1" SEP8);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");

    paths = search_path_split<char>(SEP8 u8"/żółć1/jaźń1" SEP8 u8"/żółć2/jaźń2" SEP8);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], u8"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_split__2__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__2__char32_t__char32_t( )
  {
    u32search_paths paths;

    paths = search_path_split<char32_t>(std::u32string(SEP32 U"/żółć1/jaźń1" SEP32));
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");

    paths = search_path_split<char32_t>(std::u32string(SEP32 U"/żółć1/jaźń1" SEP32 U"/żółć2/jaźń2" SEP32));
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], U"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_split__2__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__2__char__char( )
  {
    u8search_paths paths;

    paths = search_path_split<char>(std::string(SEP8 u8"/żółć1/jaźń1" SEP8));
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");

    paths = search_path_split<char>(std::string(SEP8 u8"/żółć1/jaźń1" SEP8 u8"/żółć2/jaźń2" SEP8));
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], u8"/żółć1/jaźń1");
    TS_ASSERT_EQUALS(paths[1], u8"/żółć2/jaźń2");
  }
  /** // doc: test__search_path_join_u32__1__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join_u32__1__char32_t( )
  {
    TS_ASSERT_EQUALS(search_path_join_u32(u32search_paths{}), U"");
    TS_ASSERT_EQUALS(search_path_join_u32(u32search_paths{U""}), U"");
    TS_ASSERT_EQUALS(search_path_join_u32(u32search_paths{U"",U""}), SEP32);
  }
  /** // doc: test__search_path_join_u32__1__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join_u32__1__char( )
  {
    TS_ASSERT_EQUALS(search_path_join_u32(u8search_paths{}), U"");
    TS_ASSERT_EQUALS(search_path_join_u32(u8search_paths{u8""}), U"");
    TS_ASSERT_EQUALS(search_path_join_u32(u8search_paths{u8"",u8""}), SEP32);
  }
  /** // doc: test__search_path_join_u32__2__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join_u32__2__char32_t( )
  {
    TS_ASSERT_EQUALS(search_path_join_u32(u32search_paths{U"/zażółć/jaźń"}), U"/zażółć/jaźń");
    TS_ASSERT_EQUALS(search_path_join_u32(u32search_paths{U"/zażółć1/jaźń1",U"/zażółć2/jaźń2"}), U"/zażółć1/jaźń1" SEP32 U"/zażółć2/jaźń2");
  }
  /** // doc: test__search_path_join_u32__2__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join_u32__2__char( )
  {
    TS_ASSERT_EQUALS(search_path_join_u32(u8search_paths{u8"/zażółć1/jaźń1"}), U"/zażółć1/jaźń1");
    TS_ASSERT_EQUALS(search_path_join_u32(u8search_paths{u8"/zażółć1/jaźń1",u8"/zażółć2/jaźń2"}), U"/zażółć1/jaźń1" SEP32 U"/zażółć2/jaźń2");
  }
  /** // doc: test__search_path_join__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__1__char__char( )
  {
    TS_ASSERT_EQUALS(search_path_join<char>(u8search_paths{}), u8"");
    TS_ASSERT_EQUALS(search_path_join<char>(u8search_paths{u8""}), u8"");
    TS_ASSERT_EQUALS(search_path_join<char>(u8search_paths{u8"",u8""}), SEP8);
  }
  /** // doc: test__search_path_join__2__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__2__char__char( )
  {
    TS_ASSERT_EQUALS(search_path_join<char>(u8search_paths{u8"/zażółć1/jaźń1"}), u8"/zażółć1/jaźń1");
    TS_ASSERT_EQUALS(search_path_join<char>(u8search_paths{u8"/zażółć1/jaźń1",u8"/zażółć2/jaźń2"}), u8"/zażółć1/jaźń1" SEP8 u8"/zażółć2/jaźń2");
  }
  /** // doc: test__search_path_unique__1__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__1__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2", U"/foo1/bar1" };
    u32search_paths result(search_path_unique(paths));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], U"/foo2/bar2");
  }
  /** // doc: test__search_path_unique__1__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__1__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2", u8"/foo1/bar1" };
    u8search_paths result(search_path_unique(paths));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_unique__2__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__2__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2", U"/foo1/bar1", U"/foo3/bar3" };
    u32search_paths result(search_path_unique(paths, u32search_paths{ U"/foo3/bar3" }));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], U"/foo2/bar2");
  }
  /** // doc: test__search_path_unique__2__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_unique__2__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2", u8"/foo1/bar1", u8"/foo3/bar3" };
    u8search_paths result(search_path_unique(paths, u8search_paths{ u8"/foo3/bar3" }));

    TS_ASSERT_EQUALS(result.size(), 2ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_append__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append__1__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2" };
    u32search_paths result(search_path_append(paths, U"/foo3/bar3" SEP32 U"/foo4/bar4"));

    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], U"/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], U"/foo3/bar3");
    TS_ASSERT_EQUALS(result[3], U"/foo4/bar4");
  }
  /** // doc: test__search_path_append__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append__1__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    u8search_paths result(search_path_append(paths, u8"/foo3/bar3" SEP8 u8"/foo4/bar4"));

    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], u8"/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], u8"/foo3/bar3");
    TS_ASSERT_EQUALS(result[3], u8"/foo4/bar4");
  }
  /** // doc: test__search_path_prepend__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend__1__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2" };
    u32search_paths result(search_path_prepend(paths, U"/foo3/bar3" SEP32 U"/foo4/bar4"));

    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], U"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], U"/foo4/bar4");
    TS_ASSERT_EQUALS(result[2], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[3], U"/foo2/bar2");
  }
  /** // doc: test__search_path_prepend__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend__1__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    u8search_paths result(search_path_prepend(paths, u8"/foo3/bar3" SEP8 u8"/foo4/bar4"));

    TS_ASSERT_EQUALS(result.size(), 4ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], u8"/foo4/bar4");
    TS_ASSERT_EQUALS(result[2], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[3], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_append_unique__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append_unique__1__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2" };
    u32search_paths result(search_path_append_unique(paths, U"/foo3/bar3" SEP32 U"/foo2/bar2" SEP32 U"/foo3/bar3"));

    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], U"/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], U"/foo3/bar3");
  }
  /** // doc: test__search_path_append_unique__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_append_unique__1__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    u8search_paths result(search_path_append_unique(paths, u8"/foo3/bar3" SEP8 u8"/foo2/bar2" SEP8 u8"/foo3/bar3"));

    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[1], u8"/foo2/bar2");
    TS_ASSERT_EQUALS(result[2], u8"/foo3/bar3");
  }
  /** // doc: test__search_path_prepend_unique__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend_unique__1__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2" };
    u32search_paths result(search_path_prepend_unique(paths, U"/foo3/bar3" SEP32 U"/foo2/bar2" SEP32 U"/foo3/bar3"));

    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], U"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], U"/foo1/bar1");
    TS_ASSERT_EQUALS(result[2], U"/foo2/bar2");
  }
  /** // doc: test__search_path_prepend_unique__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_prepend_unique__1__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2" };
    u8search_paths result(search_path_prepend_unique(paths, u8"/foo3/bar3" SEP8 u8"/foo2/bar2" SEP8 u8"/foo3/bar3"));

    TS_ASSERT_EQUALS(result.size(), 3ul);
    TS_ASSERT_EQUALS(result[0], u8"/foo3/bar3");
    TS_ASSERT_EQUALS(result[1], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(result[2], u8"/foo2/bar2");
  }
  /** // doc: test__search_path_erase__1__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__1__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2", U"/foo3/bar3", U"/foo2/bar2"};
    u32search_paths const& pref = search_path_erase(paths, U"/foo2/bar2");
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], U"/foo3/bar3");
  }
  /** // doc: test__search_path_erase__2__char32_t__char32_t() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__2__char32_t__char32_t( )
  {
    u32search_paths paths{ U"/foo1/bar1", U"/foo2/bar2", U"/foo3/bar3", U"/foo2/bar2"};
    u32search_paths const& pref = search_path_erase(paths, U"/foo2/bar2" SEP32 U"/foo3/bar3");
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], U"/foo1/bar1");
  }
  /** // doc: test__search_path_erase__1__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__1__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2", u8"/foo3/bar3", u8"/foo2/bar2"};
    u8search_paths const& pref = search_path_erase(paths, u8"/foo2/bar2");
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 2ul);
    TS_ASSERT_EQUALS(paths[0], u8"/foo1/bar1");
    TS_ASSERT_EQUALS(paths[1], u8"/foo3/bar3");
  }
  /** // doc: test__search_path_erase__2__char__char() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_erase__2__char__char( )
  {
    u8search_paths paths{ u8"/foo1/bar1", u8"/foo2/bar2", u8"/foo3/bar3", u8"/foo2/bar2"};
    u8search_paths const& pref = search_path_erase(paths, u8"/foo2/bar2" SEP8 u8"/foo3/bar3");
    TS_ASSERT(&pref == &paths);
    TS_ASSERT_EQUALS(paths.size(), 1ul);
    TS_ASSERT_EQUALS(paths[0], u8"/foo1/bar1");
  }
};

#endif /* CLXX_COMMON_SEARCH_PATH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
