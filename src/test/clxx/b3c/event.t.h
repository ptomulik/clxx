// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/event.t.h

/** // doc: clxx/b3c/event.t.h {{{
 * \file clxx/b3c/event.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B3C_EVENT_T_H_INCLUDED
#define CLXX_B3C_EVENT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b3c/event.hpp>
#include <clxx/b3c/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

namespace clxx { class event_test_suite; }

/** // doc: class clxx::event_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::event_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__default_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__default_ctor( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event e;
    TS_ASSERT(!e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)NULL);
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event e((cl_event)0x1234);
    TS_ASSERT(e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)0x1234);
    TS_ASSERT(mock1.called_once_with((cl_event)0x1234));
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_1__null_id() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_1__null_id( )
  {
    T::Dummy_clRetainEvent mock1(CL_INVALID_EVENT);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_THROWS_NOTHING(event((cl_event)NULL));
    TS_ASSERT(mock1.never_called());
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__ctor_2() {{{
   * \todo Write documentation
   */ // }}}
  void test__ctor_2( )
  {
#if CLXX_B5D_OPENCL_PROVIDES(clCreateUserEvent)
    T::Dummy_clCreateUserEvent mock1((cl_event)0x1234, CL_SUCCESS);
    T::Dummy_clRetainEvent mock2(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock3(CL_SUCCESS);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);


    context c((cl_context)0x3456);
    event e(c);

    TS_ASSERT(e.is_initialized());
    TS_ASSERT_EQUALS(e.get(), (cl_event)0x1234);
    TS_ASSERT(mock2.never_called());
    TS_ASSERT(mock3.never_called());
#endif
  }
  /** // doc: test__copy_ctor() {{{
   * \todo Write documentation
   */ // }}}
  void test__copy_ctor( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event k1((cl_event)0x1234);
    event k2(k1);
    TS_ASSERT(k2.is_initialized());
    TS_ASSERT(mock1.called_twice());
    TS_ASSERT(mock2.never_called());
    TS_ASSERT_EQUALS(k2, event((cl_event)0x1234));
  }
  /** // doc: test__dtor__notnull() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__notnull( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    {
      event e((cl_event)0x1234);
    }
    TS_ASSERT(mock2.called_once_with((cl_event)0x1234));
  }
  /** // doc: test__dtor__null() {{{
   * \todo Write documentation
   */ // }}}
  void test__dtor__null( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    {
      event e((cl_event)NULL);
    }
    TS_ASSERT(mock2.never_called());
  }
  /** // doc: test__id() {{{
   * \todo Write documentation
   */ // }}}
  void test__id( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(event((cl_event)0x1234).get(), (cl_event)0x1234);
    TS_ASSERT_EQUALS(event((cl_event)NULL).get(), (cl_event)NULL);
  }
  /** // doc: test__chk_get() {{{
   * \todo Write documentation
   */ // }}}
  void test__chk_get( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);

    TS_ASSERT_EQUALS(event((cl_event)0x1234).chk_get(), (cl_event)0x1234);
    TS_ASSERT_THROWS(event((cl_event)NULL).chk_get(), uninitialized_event_error);
  }
  /** // doc: test__assign__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__1( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event c1((cl_event)0x1234);
    event c2((cl_event)0x5678);
    TS_ASSERT(c1 != c2);
    c2.assign(c1);
    TS_ASSERT(mock1.called_three_times());
    TS_ASSERT(mock1.last_called_with((cl_event)0x1234));
    TS_ASSERT(mock2.called_once_with((cl_event)0x5678));
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__2() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__2( )
  {
    event c1;
    event c2;
    {
      T::Dummy_clRetainEvent mock_clRetainEvent(CL_SUCCESS);
      T::Dummy_clReleaseEvent mock_clReleaseEvent(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainEvent.never_called());
      TS_ASSERT(mock_clReleaseEvent.never_called());
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__assign__3() {{{
   * \todo Write documentation
   */ // }}}
  void test__assign__3( )
  {
    T::Dummy_clRetainEvent mock_clRetainEvent(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock_clReleaseEvent(CL_SUCCESS);
    event c1;
    event c2((cl_event)0x1234);
    {
      T::Dummy_clRetainEvent mock_clRetainEvent2(CL_SUCCESS);
      T::Dummy_clReleaseEvent mock_clReleaseEvent2(CL_SUCCESS);
      TS_ASSERT_THROWS_NOTHING(c2.assign(c1));
      TS_ASSERT(mock_clRetainEvent2.never_called());
      TS_ASSERT(mock_clReleaseEvent2.called_once_with((cl_event)0x1234));
    }
    TS_ASSERT_EQUALS(c1,c2);
  }
  /** // doc: test__op_assign() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_assign( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    event p1((cl_event)0x1234);
    event p2((cl_event)0x5678);
    p1 = p2;
    TS_ASSERT_EQUALS(p1.get(), (cl_event)0x5678);
  }
  /** // doc: test__op_eq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_eq( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) == event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) == event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) == event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) == event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   == event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   == event((cl_event)NULL)));
  }
  /** // doc: test__op_neq() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_neq( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) != event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) != event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) != event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) != event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   != event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   != event((cl_event)NULL)));
  }
  /** // doc: test__op_lt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_lt( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) < event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) < event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) < event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) < event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   < event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   < event((cl_event)NULL)));
  }
  /** // doc: test__op_gt() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_gt( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT(!(event((cl_event)0x1234) > event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) > event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) > event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) > event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   > event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)NULL)   > event((cl_event)NULL)));
  }
  /** // doc: test__op_le() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_le( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) <= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) <= event((cl_event)0x5678)));
    TS_ASSERT(!(event((cl_event)0x5678) <= event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) <= event((cl_event)NULL)));
    TS_ASSERT( (event((cl_event)NULL)   <= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   <= event((cl_event)NULL)));
  }
  /** // doc: test__op_ge() {{{
   * \todo Write documentation
   */ // }}}
  void test__op_ge( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    TS_ASSERT( (event((cl_event)0x1234) >= event((cl_event)0x1234)));
    TS_ASSERT(!(event((cl_event)0x1234) >= event((cl_event)0x5678)));
    TS_ASSERT( (event((cl_event)0x5678) >= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)0x1234) >= event((cl_event)NULL)));
    TS_ASSERT(!(event((cl_event)NULL)   >= event((cl_event)0x1234)));
    TS_ASSERT( (event((cl_event)NULL)   >= event((cl_event)NULL)));
  }
  /** // doc: test__get_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventInfo mock3(CL_SUCCESS);

    event e((cl_event)0x4321);
    e.get_info(event_info_t::command_type, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_event)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_TYPE);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_info__uninitialized_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_info__uninitialized_event( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventInfo mock3(CL_SUCCESS);

    event e((cl_event)NULL);
    TS_ASSERT_THROWS(e.get_info(event_info_t::command_type, 0, nullptr, nullptr), uninitialized_event_error);
  }
  /** // doc: test__get_profiling_info() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_info( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS);

    event e((cl_event)0x4321);
    e.get_profiling_info(profiling_info_t::start, 2, (void*)0x1234, (size_t*)0x5678);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mock3.calls().back()), (cl_event)0x4321);
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_PROFILING_COMMAND_START);
    TS_ASSERT_EQUALS(std::get<2>(mock3.calls().back()), 2);
    TS_ASSERT_EQUALS(std::get<3>(mock3.calls().back()), (void*)0x1234);
    TS_ASSERT_EQUALS(std::get<4>(mock3.calls().back()), (size_t*)0x5678);
  }
  /** // doc: test__get_profiling_info__uninitialized_event() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_info__uninitialized_event( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Dummy_clGetEventProfilingInfo mock3(CL_SUCCESS);

    event e((cl_event)NULL);
    TS_ASSERT_THROWS(e.get_profiling_info(profiling_info_t::start, 0, nullptr, nullptr), uninitialized_event_error);
  }
  /** // doc: test__get_reference_count() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_reference_count( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventInfo mock3([](cl_event,
                                         cl_event_info param_name,
                                         size_t param_value_size,
                                         void* param_value,
                                         size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_EVENT_REFERENCE_COUNT) {
          if(param_value && param_value_size >= sizeof(cl_uint))
            *((cl_uint*)param_value) = 12u;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_uint);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);
    TS_ASSERT_EQUALS(e.get_reference_count(), 12u);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_REFERENCE_COUNT);
  }
  /** // doc: test__get_context() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_context( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventInfo mock3([](cl_event,
                                         cl_event_info param_name,
                                         size_t param_value_size,
                                         void* param_value,
                                         size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_EVENT_CONTEXT) {
          if(param_value && param_value_size >= sizeof(cl_context))
            *((cl_context*)param_value) = (cl_context)12;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_context);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    T::Dummy_clRetainContext mock4(CL_SUCCESS);
    T::Dummy_clReleaseContext mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(e.get_context().get(), (cl_context)12);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_CONTEXT);
#endif
  }
  /** // doc: test__get_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_queue( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventInfo mock3([](cl_event,
                                         cl_event_info param_name,
                                         size_t param_value_size,
                                         void* param_value,
                                         size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_EVENT_COMMAND_QUEUE) {
          if(param_value && param_value_size >= sizeof(cl_command_queue))
            *((cl_command_queue*)param_value) = (cl_command_queue)12;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_command_queue);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    T::Dummy_clRetainCommandQueue mock4(CL_SUCCESS);
    T::Dummy_clReleaseCommandQueue mock5(CL_SUCCESS);
    TS_ASSERT_EQUALS(e.get_command_queue().get(), (cl_command_queue)12);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_QUEUE);
  }
  /** // doc: test__get_command_type() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_type( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventInfo mock3([](cl_event,
                                         cl_event_info param_name,
                                         size_t param_value_size,
                                         void* param_value,
                                         size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_EVENT_COMMAND_TYPE) {
          if(param_value && param_value_size >= sizeof(cl_command_type))
            *((cl_command_type*)param_value) = (cl_command_type)CL_COMMAND_READ_BUFFER;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_command_type);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_command_type(), command_type_t::read_buffer);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_TYPE);
  }
  /** // doc: test__get_command_exec_status() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_command_exec_status( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventInfo mock3([](cl_event,
                                         cl_event_info param_name,
                                         size_t param_value_size,
                                         void* param_value,
                                         size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_uint)CL_EVENT_COMMAND_EXECUTION_STATUS) {
          if(param_value && param_value_size >= sizeof(cl_int))
            *((cl_int*)param_value) = (cl_int)CL_COMPLETE;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_int);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_command_exec_status(), command_exec_status_t::complete);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_uint)CL_EVENT_COMMAND_EXECUTION_STATUS);
  }
  /** // doc: test__get_profiling_command_queued() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_queued( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventProfilingInfo mock3([](cl_event,
                                                  cl_profiling_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_profiling_info)CL_PROFILING_COMMAND_QUEUED) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_queued(), 123ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_QUEUED);
  }
  /** // doc: test__get_profiling_command_submit() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_submit( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventProfilingInfo mock3([](cl_event,
                                                  cl_profiling_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_profiling_info)CL_PROFILING_COMMAND_SUBMIT) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_submit(), 123ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_SUBMIT);
  }
  /** // doc: test__get_profiling_command_start() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_start( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventProfilingInfo mock3([](cl_event,
                                                  cl_profiling_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_profiling_info)CL_PROFILING_COMMAND_START) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_start(), 123ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_START);
  }
  /** // doc: test__get_profiling_command_end() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_end( )
  {
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventProfilingInfo mock3([](cl_event,
                                                  cl_profiling_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_profiling_info)CL_PROFILING_COMMAND_END) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_end(), 123ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_END);
  }
  /** // doc: test__get_profiling_command_complete() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_profiling_command_complete( )
  {
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_0
    T::Dummy_clRetainEvent mock1(CL_SUCCESS);
    T::Dummy_clReleaseEvent mock2(CL_SUCCESS);
    T::Pluggable_clGetEventProfilingInfo mock3([](cl_event,
                                                  cl_profiling_info param_name,
                                                  size_t param_value_size,
                                                  void* param_value,
                                                  size_t* param_value_size_ret) -> cl_int {
        if(param_name == (cl_profiling_info)CL_PROFILING_COMMAND_COMPLETE) {
          if(param_value && param_value_size >= sizeof(cl_ulong))
            *((cl_ulong*)param_value) = 123ul;
          if(param_value_size_ret)
            *param_value_size_ret = sizeof(cl_ulong);
          return CL_SUCCESS;
        } else {
          return CL_INVALID_VALUE;
        }
    });

    event e((cl_event)0x4321);

    TS_ASSERT_EQUALS(e.get_profiling_command_complete(), 123ul);

    TS_ASSERT(mock3.called_once());
    TS_ASSERT_EQUALS(std::get<1>(mock3.calls().back()), (cl_profiling_info)CL_PROFILING_COMMAND_COMPLETE);
#endif
  }
};

#endif /* CLXX_B3C_EVENT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
