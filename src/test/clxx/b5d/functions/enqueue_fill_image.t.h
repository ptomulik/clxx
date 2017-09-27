// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/enqueue_fill_image.t.h

/** // doc: clxx/b5d/functions/enqueue_fill_image.t.h {{{
 * \file clxx/b5d/functions/enqueue_fill_image.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_ENQUEUE_FILL_IMAGE_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_ENQUEUE_FILL_IMAGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_fill_image_test_suite; }

/** // doc: class clxx::enqueue_fill_image_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_fill_image_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_fill_image()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_fill_image() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(enqueue_fill_image(
                                      (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (const void*)0x789,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );

    TS_ASSERT(mock.called_once_with(  (cl_command_queue)0x123,
                                      (cl_mem)0x234,
                                      (const void*)0x789,
                                      (const size_t*)0x111,
                                      (const size_t*)0x222,
                                      12u,
                                      (const cl_event*)0x890,
                                      (cl_event*)0x901) );
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__invalid_image_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::invalid_image_size>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__image_format_not_supported( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::image_format_not_supported>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
  /** // doc: test__enqueue_fill_image__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_fill_image__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
    T::Dummy_clEnqueueFillImage mock(-0x1234567);
    TS_ASSERT_THROWS(enqueue_fill_image((cl_command_queue)NULL, (cl_mem)NULL, nullptr, nullptr, nullptr, 0u, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_fill_image not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_ENQUEUE_FILL_IMAGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
