// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/enqueue_map_image.t.h

/** // doc: clxx/b5d/cl_fcn/enqueue_map_image.t.h {{{
 * \file clxx/b5d/cl_fcn/enqueue_map_image.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_ENQUEUE_MAP_IMAGE_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_ENQUEUE_MAP_IMAGE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class enqueue_map_image_test_suite; }

/** // doc: class clxx::enqueue_map_image_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::enqueue_map_image_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  enqueue_map_image()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__enqueue_map_image() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock((void*)0x7654, CL_SUCCESS);

    TS_ASSERT(enqueue_map_image(  (cl_command_queue)0x123,
                                  (cl_mem)0x234,
                                  (cl_bool)1,
                                   map_flags_t::read,
                                  (const size_t*)0x98,
                                  (const size_t*)0x76,
                                  (size_t*)0x54,
                                  (size_t*)0x32,
                                   12u,
                                  (const cl_event*)0x890,
                                  (cl_event*)0x901) == (void*)0x7654);

    TS_ASSERT(mock.called_once());

    TS_ASSERT(std::get<0>(mock.calls().back()) == (cl_command_queue)0x123);
    TS_ASSERT(std::get<1>(mock.calls().back()) == (cl_mem)0x234);
    TS_ASSERT(std::get<2>(mock.calls().back()) == (cl_bool)1);
    TS_ASSERT(std::get<3>(mock.calls().back()) == (cl_map_flags)CL_MAP_READ);
    TS_ASSERT(std::get<4>(mock.calls().back()) == (const size_t*)0x98);
    TS_ASSERT(std::get<5>(mock.calls().back()) == (const size_t*)0x76);
    TS_ASSERT(std::get<6>(mock.calls().back()) == (size_t*)0x54);
    TS_ASSERT(std::get<7>(mock.calls().back()) == (size_t*)0x32);
    TS_ASSERT(std::get<8>(mock.calls().back()) == 12u);
    TS_ASSERT(std::get<9>(mock.calls().back()) == (const cl_event*)0x890);
    TS_ASSERT(std::get<10>(mock.calls().back()) == (cl_event*)0x901);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_VALUE);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_event_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_event_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_EVENT_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_event_wait_list>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_image_size() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_image_size( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_IMAGE_SIZE);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_image_size>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__image_format_not_supported() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__image_format_not_supported( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_IMAGE_FORMAT_NOT_SUPPORTED);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::image_format_not_supported>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__map_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__map_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_MAP_FAILURE);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::map_failure>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__exec_status_error_for_events_in_wait_list() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__exec_status_error_for_events_in_wait_list( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::exec_status_error_for_events_in_wait_list>);
#endif
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__mem_object_allocation_failure() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__mem_object_allocation_failure( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_MEM_OBJECT_ALLOCATION_FAILURE);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::mem_object_allocation_failure>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__invalid_operation() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__invalid_operation( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_INVALID_OPERATION);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::invalid_operation>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
  /** // doc: test__enqueue_map_image__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__enqueue_map_image__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(enqueue_map_image)
    T::Dummy_clEnqueueMapImage mock(nullptr,-0x1234567);
    TS_ASSERT_THROWS(enqueue_map_image((cl_command_queue)NULL,(cl_mem)NULL,0,map_flags_t::read,nullptr,nullptr,nullptr,nullptr,0u,nullptr,nullptr), unexpected_clerror);
#else
    TS_SKIP("enqueue_map_image not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_ENQUEUE_MAP_IMAGE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
