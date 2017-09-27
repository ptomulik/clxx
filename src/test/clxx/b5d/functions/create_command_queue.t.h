// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/create_command_queue.t.h

/** // doc: clxx/b5d/functions/create_command_queue.t.h {{{
 * \file clxx/b5d/functions/create_command_queue.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_CREATE_COMMAND_QUEUE_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_CREATE_COMMAND_QUEUE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class create_command_queue_test_suite; }

/** // doc: class clxx::create_command_queue_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::create_command_queue_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  create_command_queue()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__create_command_queue() {{{
   * \brief Test create_command_queue() in a normal situation.
   */ // }}}
  void test__create_command_queue( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)0x1234, CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(create_command_queue((cl_context)NULL,(cl_device_id)NULL, command_queue_properties_t::profiling_enable));
    //TS_ASSERT(mock.called_once_with((cl_context)NULL,0,nullptr,nullptr,nullptr,??? - local variable within create_command_queue(...){...}));
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__invalid_context() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_CONTEXT.
   */ // }}}
  void test__create_command_queue__invalid_context( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_CONTEXT);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_context>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__invalid_device() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_DEVICE.
   */ // }}}
  void test__create_command_queue__invalid_device( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_DEVICE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_device>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__invalid_value() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_INVALID_VALUE.
   */ // }}}
  void test__create_command_queue__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_VALUE);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__invalid_command_queue() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_DEVICE_NOT_AVAILABLE.
   */ // }}}
  void test__create_command_queue__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_INVALID_QUEUE_PROPERTIES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::none), clerror_no<status_t::invalid_queue_properties>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__out_of_resources() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_RESOURCES.
   */ // }}}
  void test__create_command_queue__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__out_of_host_memory() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns CL_OUT_OF_HOST_MEMORY.
   */ // }}}
  void test__create_command_queue__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
  /** // doc: test__create_command_queue__other_error() {{{
   * \brief Test create_command_queue() in a situation when clCreateCommandQueue() returns an unexpected error code.
   */ // }}}
  void test__create_command_queue__other_error( )
  {
#if CLXX_B5D_PROVIDES(create_command_queue)
    T::Dummy_clCreateCommandQueue mock((cl_command_queue)NULL, -0x3456);
    TS_ASSERT_THROWS(create_command_queue((cl_context)NULL,(cl_device_id)NULL,command_queue_properties_t::profiling_enable), unexpected_clerror);
#else
    TS_SKIP("create_command_queue not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_CREATE_COMMAND_QUEUE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
