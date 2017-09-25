// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_svm_mem_fill.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_svm_mem_fill.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_svm_mem_fill.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_svm_mem_fill_test_suite; }

/** // doc: class clxx::enqueue_svm_mem_fill_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_svm_mem_fill_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_svm_mem_fill()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_svm_mem_fill() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_svm_mem_fill(
                                      (cl_command_queue)0x123,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      2222ul,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (void*)0x1111,
                                      (const void*)0x2222,
                                      2222ul,
                                      1111ul,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
  /** // doc: test__enqueue_svm_mem_fill__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_svm_mem_fill__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
    T::Dummy_clEnqueueSVMMemFill mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_svm_mem_fill((cl_command_queue)NULL, nullptr, nullptr, 0ul, 0ul, 0u, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_svm_mem_fill not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_SVM_MEM_FILL_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
