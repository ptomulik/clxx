/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/context.t.h

/** // doc: clxx/context.t.h {{{
 * \file clxx/context.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONTEXT_T_H_INCLUDED
#define CLXX_CONTEXT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/context.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class context_test_suite; }

/** // doc: class clxx::context_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::context_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test_ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_1( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    context c((cl_context)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_context)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test_ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_2( )
  {
    T::Dummy_clCreateContext mock1((cl_context)0, CL_SUCCESS);
    T::Dummy_clRetainContext mock2(CL_SUCCESS);
    T::Dummy_clReleaseContext mock3(CL_SUCCESS);
    context c(context_properties(), devices(), nullptr, nullptr);
    TS_ASSERT(!c.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
  }
  /** // doc: test_ctor_3() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_3( )
  {
    T::Dummy_clCreateContext mock1((cl_context)0x123, CL_SUCCESS);
    T::Dummy_clRetainContext mock2(CL_SUCCESS);
    T::Dummy_clReleaseContext mock3(CL_SUCCESS);
    context c(context_properties(), devices(), nullptr, nullptr);
    TS_ASSERT(c.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
    TS_ASSERT_EQUALS(c, context((cl_context)0x123));
  }
  /** // doc: test_ctor_4() {{{
   * \todo Write documentation
   */ // }}}
  void test_ctor_4( )
  {
    T::Dummy_clCreateContextFromType mock1((cl_context)0x123, CL_SUCCESS);
    T::Dummy_clRetainContext mock2(CL_SUCCESS);
    T::Dummy_clReleaseContext mock3(CL_SUCCESS);
    context c(context_properties(), device_type_t::gpu, nullptr, nullptr);
    TS_ASSERT(c.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
    TS_ASSERT_EQUALS(c, context((cl_context)0x123));
  }
  /** // doc: test_copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test_copy_ctor( )
  {
    T::Dummy_clCreateContext mock1((cl_context)0x123, CL_SUCCESS);
    T::Dummy_clRetainContext mock2(CL_SUCCESS);
    T::Dummy_clReleaseContext mock3(CL_SUCCESS);
    context c1(context_properties(), devices(), nullptr, nullptr);
    context c2(c1);
    TS_ASSERT(c2.is_initialized());
    TS_ASSERT(mock1.called_once());
    TS_ASSERT(mock2.called_once());
    TS_ASSERT(mock3.never_called());
    TS_ASSERT_EQUALS(c2, context((cl_context)0x123));
  }
  /** // doc: test_dtor() {{{
   * \todo Write documentation
   */ // }}}
  void test_dtor( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    {
      context c((cl_context)0x1234);
      TS_ASSERT(mock1.called_once_with((cl_context)0x1234));
      TS_ASSERT(mock2.never_called());
    }
    TS_ASSERT(mock2.called_once_with((cl_context)0x1234));
  }
  /** // doc: test_op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_assign( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    context c1((cl_context)0x1234);
    context c2((cl_context)0x5678);
    TS_ASSERT(c1 != c2);
    c2 = c1;
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_context)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_context)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test_op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_eq( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    context c1((cl_context)0x1234);
    context c2((cl_context)0x5678);
    context c3((cl_context)0x1234);
    TS_ASSERT(c1 == c1);
    TS_ASSERT(!(c1 == c2));
    TS_ASSERT(!(c2 == c1));
    TS_ASSERT(!(c2 == c3));
    TS_ASSERT(!(c3 == c2));
    TS_ASSERT(c1 == c3);
    TS_ASSERT(c3 == c1);
  }
  /** // doc: test_op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test_op_neq( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    context c1((cl_context)0x1234);
    context c2((cl_context)0x5678);
    context c3((cl_context)0x1234);
    TS_ASSERT(!(c1 != c1));
    TS_ASSERT((c1 != c2));
    TS_ASSERT((c2 != c1));
    TS_ASSERT((c2 != c3));
    TS_ASSERT((c3 != c2));
    TS_ASSERT(!(c1 != c3));
    TS_ASSERT(!(c3 != c1));
  }
  /** // doc: test_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test_assign( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    context c1((cl_context)0x1234);
    context c2((cl_context)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_context)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_context)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test_is_initialized() {{{
   * \todo Write documentation
   */ // }}}
  void test_is_initialized( )
  {
    TS_ASSERT(true); // we've actually tested it with constructors...
  }
  /** // doc: test_get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_info( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    T::Dummy_clGetContextInfo mock3(CL_SUCCESS);
    context c((cl_context)0x1234);
    char value;
    size_t value_size_ret;

    c.get_info(context_info_t::devices, 1, (void*)&value, &value_size_ret);

    TS_ASSERT(mock3.called_once_with((cl_context)0x1234, CL_CONTEXT_DEVICES, 1, (void*)&value, &value_size_ret));
  }
  /** // doc: test_get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_reference_count( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    T::Dummy_clGetContextInfo mock3(CL_SUCCESS);
    context c((cl_context)0x1234);

    c.get_reference_count();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_CONTEXT_REFERENCE_COUNT);
  }
  /** // doc: test_get_num_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_num_devices( )
  {
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    T::Dummy_clGetContextInfo mock3(CL_SUCCESS);
    context c((cl_context)0x1234);

    c.get_num_devices();

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_CONTEXT_NUM_DEVICES);
  }
  /** // doc: test_get_devices() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_devices( )
  {
    cl_device_id array[2] = { (cl_device_id)0x1234, (cl_device_id)0x5678 };
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    T::Dummy_clGetContextInfo mock3(CL_SUCCESS, array, sizeof(array));
    context c((cl_context)0x1234);

    // the exception here is quite normal, as we don't set
    devices devs(c.get_devices());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().front()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().front()), CL_CONTEXT_DEVICES);
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_CONTEXT_DEVICES);

    TS_ASSERT_EQUALS(devs.size(), 2);
    TS_ASSERT_EQUALS(devs[0].id(), (cl_device_id)0x1234);
    TS_ASSERT_EQUALS(devs[1].id(), (cl_device_id)0x5678);
  }
  /** // doc: test_get_properties() {{{
   * \todo Write documentation
   */ // }}}
  void test_get_properties( )
  {
    cl_context_properties array[3] = {
        (cl_context_properties)CL_CONTEXT_INTEROP_USER_SYNC,
        (cl_context_properties)CL_TRUE,
        (cl_context_properties)0ul
    };
    T::Dummy_clRetainContext mock1(CL_SUCCESS);
    T::Dummy_clReleaseContext mock2(CL_SUCCESS);
    T::Dummy_clGetContextInfo mock3(CL_SUCCESS, array, sizeof(array));
    context c((cl_context)0x1234);

    // the exception here is quite normal, as we don't set
    context_properties props(c.get_properties());

    TS_ASSERT(mock3.called_twice());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().front()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().front()), CL_CONTEXT_PROPERTIES);
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_context)0x1234);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), CL_CONTEXT_PROPERTIES);

    TS_ASSERT_EQUALS(props.size(), 1);
    TS_ASSERT_EQUALS(props[0].name(), context_properties_t::interop_user_sync);
    TS_ASSERT_EQUALS(props[0].value(), (cl_context_properties)CL_TRUE);
  }
  void test_foo( )
  {
    TS_ASSERT(true);
  }
};

#endif /* CLXX_CONTEXT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: