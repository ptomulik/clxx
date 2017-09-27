// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/set_mem_object_destructor_callback.t.h

/** // doc: clxx/b5d/functions/set_mem_object_destructor_callback.t.h {{{
 * \file clxx/b5d/functions/set_mem_object_destructor_callback.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class set_mem_object_destructor_callback_test_suite; }

/** // doc: class clxx::set_mem_object_destructor_callback_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::set_mem_object_destructor_callback_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  set_mem_object_destructor_callback()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__set_mem_object_destructor_callback() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    typedef void (CL_CALLBACK* callback_t)(cl_mem, void*);
    T::Dummy_clSetMemObjectDestructorCallback mock(CL_SUCCESS);
    TS_ASSERT_THROWS_NOTHING(set_mem_object_destructor_callback((cl_mem)0x123, (callback_t)0x7654, (void*)0x9876));
    TS_ASSERT(mock.called_once_with((cl_mem)0x123, (callback_t)0x7654, (void*)0x9876));
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
  /** // doc: test__set_mem_object_destructor_callback__invalid_mem_object() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback__invalid_mem_object( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    T::Dummy_clSetMemObjectDestructorCallback mock(CL_INVALID_MEM_OBJECT);
    TS_ASSERT_THROWS(set_mem_object_destructor_callback((cl_mem)NULL, nullptr, nullptr), clerror_no<status_t::invalid_mem_object>);
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
  /** // doc: test__set_mem_object_destructor_callback__invalid_value() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback__invalid_value( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    T::Dummy_clSetMemObjectDestructorCallback mock(CL_INVALID_VALUE);
    TS_ASSERT_THROWS(set_mem_object_destructor_callback((cl_mem)NULL, nullptr, nullptr), clerror_no<status_t::invalid_value>);
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
  /** // doc: test__set_mem_object_destructor_callback__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    T::Dummy_clSetMemObjectDestructorCallback mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(set_mem_object_destructor_callback((cl_mem)NULL, nullptr, nullptr), clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
  /** // doc: test__set_mem_object_destructor_callback__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    T::Dummy_clSetMemObjectDestructorCallback mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(set_mem_object_destructor_callback((cl_mem)NULL, nullptr, nullptr), clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
  /** // doc: test__set_mem_object_destructor_callback__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__set_mem_object_destructor_callback__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
    T::Dummy_clSetMemObjectDestructorCallback mock(-0x1234567);
    TS_ASSERT_THROWS(set_mem_object_destructor_callback((cl_mem)NULL, nullptr, nullptr), unexpected_clerror);
#else
    TS_SKIP("set_mem_object_destructor_callback not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_SET_MEM_OBJECT_DESTRUCTOR_CALLBACK_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
