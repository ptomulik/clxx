// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/platforms.t.h

/** // doc: clxx/b3c/platforms.t.h {{{
 * \file clxx/b3c/platforms.t.h
 * \brief Unit tests for clxx/b3c/platforms.hpp
 */ // }}}
#ifndef CLXX_B3C_PLATFORMS_T_H_INCLUDED
#define CLXX_B3C_PLATFORMS_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/platforms.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class Platforms_TestSuite; }

/** // doc: class Platforms_TestSuite {{{
 * \todo Write documentation
 */ // }}}
class clxx::Platforms_TestSuite : public CxxTest::TestSuite
{
public:
  /** // doc: test_get_num_platforms_1() {{{
   * \brief Test get_num_platforms()
   */ // }}}
  void test_get_num_platforms( )
  {
    T::Pluggable_clGetPlatformIDs mock([](cl_uint num_entries,
                                          cl_platform_id* platforms,
                                          cl_uint* num_platforms) -> cl_int {

        if(platforms) {
          if(num_entries >=1) platforms[0] = (cl_platform_id)0x1234;
          if(num_entries >=2) platforms[1] = (cl_platform_id)0x5678;
          if(num_platforms)
            *num_platforms = std::min(num_entries, 2u);
        } else if(num_platforms) {
          *num_platforms = 2u;
        }
        return CL_SUCCESS;
    });

    TS_ASSERT_EQUALS(get_num_platforms(), 2);

    TS_ASSERT(mock.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().back()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) != nullptr);
  }
  /** // doc: test_get_platform_ids() {{{
   * \brief Test get_platform_ids()
   */ // }}}
  void test_get_platform_ids( )
  {
    T::Pluggable_clGetPlatformIDs mock([](cl_uint num_entries,
                                          cl_platform_id* platforms,
                                          cl_uint* num_platforms) -> cl_int {

        if(platforms) {
          if(num_entries >=1) platforms[0] = (cl_platform_id)0x1234;
          if(num_entries >=2) platforms[1] = (cl_platform_id)0x5678;
          if(num_platforms)
            *num_platforms = std::min(num_entries, 2u);
        } else if(num_platforms) {
          *num_platforms = 2u;
        }
        return CL_SUCCESS;
    });

    std::vector<cl_platform_id> ids(get_platform_ids());
    TS_ASSERT_EQUALS(ids.size(), 2);
    TS_ASSERT_EQUALS(ids[0], (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(ids[1], (cl_platform_id)0x5678);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().front()) != nullptr);
    //
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) == nullptr);
  }
//  /** // doc: test_get_platforms() {{{
//   * \brief Test get_platforms()
//   */ // }}}
  void test_get_platforms( )
  {
    T::Pluggable_clGetPlatformIDs mock([](cl_uint num_entries,
                                          cl_platform_id* platforms,
                                          cl_uint* num_platforms) -> cl_int {

        if(platforms) {
          if(num_entries >=1) platforms[0] = (cl_platform_id)0x1234;
          if(num_entries >=2) platforms[1] = (cl_platform_id)0x5678;
          if(num_platforms)
            *num_platforms = std::min(num_entries, 2u);
        } else if(num_platforms) {
          *num_platforms = 2u;
        }
        return CL_SUCCESS;
    });

    platforms p(get_platforms());
    TS_ASSERT_EQUALS(p.size(), 2);
    TS_ASSERT_EQUALS(p[0].get(), (cl_platform_id)0x1234);
    TS_ASSERT_EQUALS(p[1].get(), (cl_platform_id)0x5678);

    TS_ASSERT(mock.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().front()), 0u);
    TS_ASSERT(std::get<1>(mock.calls().front()) == nullptr);
    TS_ASSERT(std::get<2>(mock.calls().front()) != nullptr);
    //
    TS_ASSERT_EQUALS(std::get<0>(mock.calls().back()), 2u);
    TS_ASSERT(std::get<1>(mock.calls().back()) != nullptr);
    TS_ASSERT(std::get<2>(mock.calls().back()) == nullptr);
  }
  /** // doc: test_invalid_value() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::invalid_value.
   */ // }}}
  void test_invalid_value( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(get_num_platforms(), clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_platform_ids(), clerror_no<status_t::invalid_value>);
    TS_ASSERT_THROWS(get_platforms(), clerror_no<status_t::invalid_value>);
  }
  /** // doc: test_out_of_host_memory() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        status_t::out_of_host_memory.
   */ // }}}
  void test_out_of_host_memory( )
  {
    T::Dummy_clGetPlatformIDs mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(get_num_platforms(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_platform_ids(), clerror_no<status_t::out_of_host_memory>);
    TS_ASSERT_THROWS(get_platforms(), clerror_no<status_t::out_of_host_memory>);
  }
  /** // doc: test_other_error() {{{
   * \brief Test get_xxx() in a situation when clGetPlatformIDs() returns
   *        unknown error code.
   */ // }}}
  void test_other_error( )
  {
    T::Dummy_clGetPlatformIDs mock(-0x3456);
    TS_ASSERT_THROWS(get_num_platforms(), unexpected_clerror);
    TS_ASSERT_THROWS(get_platform_ids(), unexpected_clerror);
    TS_ASSERT_THROWS(get_platforms(), unexpected_clerror);
  }
};

#endif /* CLXX_B3C_PLATFORMS_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
