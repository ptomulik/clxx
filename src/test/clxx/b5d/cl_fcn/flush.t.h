// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/flush.t.h

/** // doc: clxx/b5d/cl_fcn/flush.t.h {{{
 * \file clxx/b5d/cl_fcn/flush.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class flush_test_suite; }

/** // doc: class clxx::flush_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::flush_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  flush()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__flush() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush( )
  {
#if CLXX_B5D_PROVIDES(flush)
    T::Dummy_clFlush mock(CL_SUCCESS);
    flush                          ((cl_command_queue)0x344);
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x344));
#else
    TS_SKIP("flush not implemented");
#endif
  }
  /** // doc: test__flush__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(flush)
    T::Dummy_clFlush mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("flush not implemented");
#endif
  }
  /** // doc: test__flush__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(flush)
    T::Dummy_clFlush mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("flush not implemented");
#endif
  }
  /** // doc: test__flush__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(flush)
    T::Dummy_clFlush mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("flush not implemented");
#endif
  }
  /** // doc: test__flush__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__flush__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(flush)
    T::Dummy_clFlush mock(-0x1234567);
    TS_ASSERT_THROWS(flush((cl_command_queue)NULL), unexpected_clerror);
#else
    TS_SKIP("flush not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
