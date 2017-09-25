// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_native_kernel.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_native_kernel.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_native_kernel.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_native_kernel_test_suite; }

/** // doc: class clxx::enqueue_native_kernel_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_native_kernel_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_native_kernel()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_native_kernel() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_native_kernel(
                                      (cl_command_queue)0x123,
                                      (void(CL_CALLBACK*)(void*))0x234,
                                      (void*)0x345,
                                      0x456,
                                      0x567,
                                      (const cl_mem*)0x678,
                                      (const void**)0x789,
                                      0x890,
                                      (const cl_event*)0x901,
                                      (cl_event*)0x134) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (void(CL_CALLBACK*)(void*))0x234,
                                      (void*)0x345,
                                      0x456,
                                      0x567,
                                      (const cl_mem*)0x678,
                                      (const void**)0x789,
                                      0x890,
                                      (const cl_event*)0x901,
                                      (cl_event*)0x134) );
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
  /** // doc: test__enqueue_native_kernel__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_native_kernel__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
    T::Dummy_clEnqueueNativeKernel mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_native_kernel((cl_command_queue)NULL, nullptr, nullptr, 0, 0, nullptr, nullptr, 0, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_native_kernel not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_NATIVE_KERNEL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
