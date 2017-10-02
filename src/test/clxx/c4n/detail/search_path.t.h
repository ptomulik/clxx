// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/search_path.t.h

/** // doc: clxx/c4n/detail/search_path.t.h {{{
 * \file clxx/c4n/detail/search_path.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_SEARCH_PATH_T_H_INCLUDED
#define CLXX_C4N_DETAIL_SEARCH_PATH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/c4n/detail/search_path.hpp>

namespace clxx { namespace detail { class search_path_test_suite; } }

/** // doc: class clxx::detail::search_path_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::search_path_test_suite : public CxxTest::TestSuite
{
#ifdef CLXX_WINDOWS_API
# define SEP L";"
# define EMPTY L""
# define STR2(x) L ## #x
# define STR(x) STR2(x)
#else
# define SEP ":"
# define EMPTY ""
# define STR2(x) #x
# define STR(x) STR2(x)
#endif
public:
  /** // doc: test__search_path_delimiter__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_delimiter__1( )
  {
#ifdef CLXX_WINDOWS_API
    TS_ASSERT_EQUALS(search_path_delimiter(), L';');
#else
    TS_ASSERT_EQUALS(search_path_delimiter(), ':');
#endif
  }
  /** // doc: test__search_path_delimiter_str__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_delimiter_str__1( )
  {
    TS_ASSERT_EQUALS(search_path_delimiter_str(), SEP);
  }
  /** // doc: test__is_search_path_delimiter__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__is_search_path_delimiter__1( )
  {
#ifdef CLXX_WINDOWS_API
    TS_ASSERT(is_search_path_delimiter(L';'));
    TS_ASSERT(!is_search_path_delimiter(L'a'));
    TS_ASSERT(!is_search_path_delimiter(L'\\'));
    TS_ASSERT(!is_search_path_delimiter(L'/'));
    TS_ASSERT(!is_search_path_delimiter(L':'));
#else
    TS_ASSERT(is_search_path_delimiter(':'));
    TS_ASSERT(!is_search_path_delimiter('a'));
    TS_ASSERT(!is_search_path_delimiter('\\'));
    TS_ASSERT(!is_search_path_delimiter('/'));
#endif
  }
  /** // doc: test__search_path_split__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__1( )
  {
    std::vector<path_string> pieces;
    search_path_split(pieces, EMPTY);
    TS_ASSERT_EQUALS(pieces.size(), 1ul);
    if(pieces.size() == 1ul)
      {
        TS_ASSERT_EQUALS(pieces[0], EMPTY);
      }
  }
  /** // doc: test__search_path_split__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__2( )
  {
    std::vector<path_string> pieces;
    {
      search_path_split(pieces, SEP);
      TS_ASSERT_EQUALS(pieces.size(), 2ul);
      if(pieces.size() == 2ul)
        {
          TS_ASSERT_EQUALS(pieces[0], EMPTY);
          TS_ASSERT_EQUALS(pieces[1], EMPTY);
        }
    }
    {
      search_path_split(pieces, SEP SEP);
      TS_ASSERT_EQUALS(pieces.size(), 3ul);
      if(pieces.size() == 3ul)
        {
          TS_ASSERT_EQUALS(pieces[0], EMPTY);
          TS_ASSERT_EQUALS(pieces[1], EMPTY);
          TS_ASSERT_EQUALS(pieces[2], EMPTY);
        }
    }
  }
  /** // doc: test__search_path_split__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__3( )
  {
    std::vector<path_string> pieces;
    {
      search_path_split(pieces, SEP STR(foo));
      TS_ASSERT_EQUALS(pieces.size(), 2ul);
      if(pieces.size() == 2ul)
        {
          TS_ASSERT_EQUALS(pieces[0], EMPTY);
          TS_ASSERT_EQUALS(pieces[1], STR(foo));
        }
    }
    {
      search_path_split(pieces, SEP SEP STR(foo));
      TS_ASSERT_EQUALS(pieces.size(), 3ul);
      if(pieces.size() == 3ul)
        {
          TS_ASSERT_EQUALS(pieces[0], EMPTY);
          TS_ASSERT_EQUALS(pieces[1], EMPTY);
          TS_ASSERT_EQUALS(pieces[2], STR(foo));
        }
    }
  }
  /** // doc: test__search_path_split__4() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__4( )
  {
    std::vector<path_string> pieces;
    {
      search_path_split(pieces, STR(foo) SEP);
      TS_ASSERT_EQUALS(pieces.size(), 2ul);
      if(pieces.size() == 2ul)
        {
          TS_ASSERT_EQUALS(pieces[0], STR(foo));
          TS_ASSERT_EQUALS(pieces[1], EMPTY);
        }
    }
    {
      search_path_split(pieces, STR(foo) SEP SEP);
      TS_ASSERT_EQUALS(pieces.size(), 3ul);
      if(pieces.size() == 3ul)
        {
          TS_ASSERT_EQUALS(pieces[0], STR(foo));
          TS_ASSERT_EQUALS(pieces[1], EMPTY);
          TS_ASSERT_EQUALS(pieces[2], EMPTY);
        }
    }
  }
  /** // doc: test__search_path_split__5() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__5( )
  {
    std::vector<path_string> pieces;
    search_path_split(pieces, STR(foo) SEP STR(bar) SEP STR(geez));
    TS_ASSERT_EQUALS(pieces.size(), 3ul);
    if(pieces.size() == 3ul)
      {
        TS_ASSERT_EQUALS(pieces[0], STR(foo));
        TS_ASSERT_EQUALS(pieces[1], STR(bar));
        TS_ASSERT_EQUALS(pieces[2], STR(geez));
      }
  }
  /** // doc: test__search_path_split__6() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__6( )
  {
#ifdef CLXX_WINDOWS_API
    std::vector<path_string> pieces;
    search_path_split(pieces, L"foo/bar\\geez");
    TS_ASSERT_EQUALS(pieces.size(), 3ul);
    if(pieces.size() == 3ul)
      {
        TS_ASSERT_EQUALS(pieces[0], STR(foo));
        TS_ASSERT_EQUALS(pieces[1], STR(bar));
        TS_ASSERT_EQUALS(pieces[2], STR(geez));
      }
#endif
  }
  /** // doc: test__search_path_split__6() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_split__7( )
  {
    std::vector<std::tuple<const path_char_t*, const path_char_t*> > pieces;
    search_path_split(pieces, STR(foo) SEP STR(bar) SEP STR(geez));
    TS_ASSERT_EQUALS(pieces.size(), 3ul);
    if(pieces.size() == 3ul)
      {
        TS_ASSERT_EQUALS(path_string(std::get<0>(pieces[0]), std::get<1>(pieces[0])), STR(foo));
        TS_ASSERT_EQUALS(path_string(std::get<0>(pieces[1]), std::get<1>(pieces[1])), STR(bar));
        TS_ASSERT_EQUALS(path_string(std::get<0>(pieces[2]), std::get<1>(pieces[2])), STR(geez));
      }
  }
  /** // doc: test__search_path_join__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__1( )
  {
    {
      std::vector<path_string> pieces{};
      TS_ASSERT_EQUALS(search_path_join(pieces), EMPTY);
    }
    {
      std::vector<path_string> pieces{EMPTY};
      TS_ASSERT_EQUALS(search_path_join(pieces), EMPTY);
    }
    {
      std::vector<path_string> pieces{EMPTY, EMPTY};
      TS_ASSERT_EQUALS(search_path_join(pieces), SEP);
    }
  }
  /** // doc: test__search_path_join__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__2( )
  {
    {
      std::vector<path_string> pieces{SEP};
      TS_ASSERT_EQUALS(search_path_join(pieces), SEP);
    }
    {
      std::vector<path_string> pieces{SEP, SEP};
      TS_ASSERT_EQUALS(search_path_join(pieces), SEP SEP SEP);
    }
  }
  /** // doc: test__search_path_join__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__search_path_join__3( )
  {
    {
      std::vector<path_string> pieces{STR(foo), STR(bar)};
      TS_ASSERT_EQUALS(search_path_join(pieces), STR(foo) SEP STR(bar));
    }
    {
      std::vector<path_string> pieces{STR(foo), EMPTY, STR(bar)};
      TS_ASSERT_EQUALS(search_path_join(pieces), STR(foo) SEP SEP STR(bar));
    }
    {
      std::vector<path_string> pieces{STR(foo), EMPTY, EMPTY, STR(bar)};
      TS_ASSERT_EQUALS(search_path_join(pieces), STR(foo) SEP SEP SEP STR(bar));
    }
  }
};

#endif /* CLXX_C4N_DETAIL_SEARCH_PATH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
