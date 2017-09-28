// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/context_properties.t.h

/** // doc: clxx/b3c/context_properties.t.h {{{
 * \file clxx/b3c/context_properties.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_CONTEXT_PROPERTIES_T_H_INCLUDED
#define CLXX_B3C_CONTEXT_PROPERTIES_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/context_properties.hpp>
#include <clxx/c4n/exceptions.hpp>

namespace clxx { class context_properties_test_suite; }

/** // doc: class clxx::context_properties_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::context_properties_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_context_properties_array_size() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_array_size()
  {
    TS_ASSERT_EQUALS(context_properties_array_size(context_properties()),1);
    TS_ASSERT_EQUALS(context_properties_array_size(context_properties({context_platform(nullptr)})),3);
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(context_properties_array_size(context_properties({context_platform(nullptr), context_interop_user_sync(true)})),5);
#endif
  }
  /** // doc: test_context_properties_fill_array_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_1()
  {
    context_properties props;
    cl_context_properties array[1];
    TS_ASSERT_EQUALS(context_properties_fill_array(props,array,1ul),1ul);
    TS_ASSERT_EQUALS(array[0],(cl_context_properties)0ul);
  }
  /** // doc: test_context_properties_fill_array_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_2()
  {
    context_properties props = { context_platform((cl_platform_id)0x1234ul) };
    cl_context_properties array[5];
    TS_ASSERT_EQUALS(context_properties_fill_array(props,array,5ul),3ul);
    TS_ASSERT_EQUALS(array[0],(cl_context_properties)CL_CONTEXT_PLATFORM);
    TS_ASSERT_EQUALS(array[1],(cl_context_properties)0x1234ul);
    TS_ASSERT_EQUALS(array[2],(cl_context_properties)0ul);
  }
  /** // doc: test_context_properties_fill_array_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_3()
  {
    context_properties props = { context_platform((cl_platform_id)0x1234ul)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
                               , context_interop_user_sync(true)
#endif
    };
    cl_context_properties array[5];
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(context_properties_fill_array(props,array,5ul),5ul);
#else
    TS_ASSERT_EQUALS(context_properties_fill_array(props,array,5ul),3ul);
#endif
    int i = 0;
    TS_ASSERT_EQUALS(array[i++],(cl_context_properties)CL_CONTEXT_PLATFORM);
    TS_ASSERT_EQUALS(array[i++],(cl_context_properties)0x1234ul);
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(array[i++],(cl_context_properties)CL_CONTEXT_INTEROP_USER_SYNC);
    TS_ASSERT_EQUALS(array[i++],(cl_context_properties)CL_TRUE);
#endif
    TS_ASSERT_EQUALS(array[i++],(cl_context_properties)0ul);
  }
  /** // doc: test_context_properties_fill_array_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_4()
  {
    context_properties props;
    TS_ASSERT_THROWS(context_properties_fill_array(props,nullptr,8), invalid_argument_error);
  }
  /** // doc: test_context_properties_fill_array_5() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_5()
  {
    context_properties props = { context_platform((cl_platform_id)0x1234ul)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
                               , context_interop_user_sync(true)
#endif
    };
    cl_context_properties array[1];
    TS_ASSERT_THROWS(context_properties_fill_array(props,array,1), not_enough_space_error);
  }
  /** // doc: test_context_properties_fill_array_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_fill_array_6()
  {
    context_properties props;
    cl_context_properties array[1];
    TS_ASSERT_THROWS(context_properties_fill_array(props,array,0), not_enough_space_error);
  }
  /** // doc: test_context_properties_parse_array_6() {{{
   * \todo Write documentation
   */ // }}}
  void test_context_properties_parse_array_6()
  {
    cl_context_properties array[] = {
      CL_CONTEXT_PLATFORM, (cl_context_properties)0x12345,
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
      CL_CONTEXT_INTEROP_USER_SYNC, (cl_context_properties)CL_TRUE,
#endif
      (cl_context_properties)0ul
    };
    context_properties cp;
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(context_properties_parse_array(cp, array), 4);
#else
    TS_ASSERT_EQUALS(context_properties_parse_array(cp, array), 2);
#endif
    TS_ASSERT_EQUALS(cp[0].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_context_properties)0x12345);
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    TS_ASSERT_EQUALS(cp[1].name(), context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(cp[1].value(), (cl_context_properties)CL_TRUE);
#endif
  }
  /** // doc: test_op_and_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_1()
  {
    context_properties cp(context_platform((cl_platform_id)0x1234)
                         & context_platform((cl_platform_id)0x4321));
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(cp[1].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[1].value(), (cl_context_properties)0x4321);
  }
  /** // doc: test_op_and_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_2()
  {
    context_properties cp1;
    cp1.push_back(context_platform((cl_platform_id)0x1234));
    context_properties cp(cp1 & context_platform((cl_platform_id)0x4321));
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(cp[1].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[1].value(), (cl_context_properties)0x4321);
  }
  /** // doc: test_op_and_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_3()
  {
    context_properties cp2;
    cp2.push_back(context_platform((cl_platform_id)0x4321));
    context_properties cp(context_platform((cl_platform_id)0x1234) & cp2);
    TS_ASSERT_EQUALS(cp.size(), 2);
    TS_ASSERT_EQUALS(cp[0].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(cp[1].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[1].value(), (cl_context_properties)0x4321);
  }
  /** // doc: test_op_and_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_and_4()
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
#if cl_khr_gl_sharing
    context_properties cp(context_platform((cl_platform_id)0x1234) & context_interop_user_sync(true) & context_gl_context_khr((void*)0x5678));
    TS_ASSERT_EQUALS(cp.size(), 3);
    TS_ASSERT_EQUALS(cp[0].name(), context_properties_t::platform);
    TS_ASSERT_EQUALS(cp[0].value(), (cl_context_properties)0x1234);
    TS_ASSERT_EQUALS(cp[1].name(), context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(cp[1].value(), (cl_context_properties)CL_TRUE);
    TS_ASSERT_EQUALS(cp[2].name(), context_properties_t::gl_context_khr);
    TS_ASSERT_EQUALS(cp[2].value(), (cl_context_properties)0x5678);
#endif
#endif
  }
  /** // doc: test_make_context_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_make_context_properties()
  {
    platform p1((cl_platform_id)0x1234);
    platform p2((cl_platform_id)0x5678);
    TS_ASSERT_THROWS_NOTHING(make_context_properties());
    TS_ASSERT_THROWS_NOTHING(make_context_properties(context_platform(p1)));
    TS_ASSERT_THROWS_NOTHING(make_context_properties(p1));

    TS_ASSERT_THROWS_NOTHING(make_context_properties(p1,context_platform((cl_platform_id)0x4321)));
    TS_ASSERT_THROWS_NOTHING(make_context_properties(p1,context_platform((cl_platform_id)0x4321)));
    TS_ASSERT_THROWS_NOTHING(make_context_properties(p1,p2,context_platform((cl_platform_id)0x4321)));
    TS_ASSERT_THROWS_NOTHING(make_context_properties(make_context_properties(p1,p2),context_platform((cl_platform_id)0x4321)));
    TS_ASSERT_THROWS_NOTHING(make_context_properties(p1,make_context_properties(p2,context_platform((cl_platform_id)0x4321))));

    TS_ASSERT_EQUALS(make_context_properties().size(), 0);
    TS_ASSERT_EQUALS(make_context_properties(p1).size(), 1);
    TS_ASSERT_EQUALS(make_context_properties(p1,p2).size(), 2);
    TS_ASSERT_EQUALS(make_context_properties(p1,p2,context_platform((cl_platform_id)0x4321)).size(),3);
  }
};

#endif /* CLXX_B3C_CONTEXT_PROPERTIES_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
