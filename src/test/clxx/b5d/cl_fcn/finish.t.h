// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_fcn/finish.t.h

/** // doc: clxx/b5d/cl_fcn/finish.t.h {{{
 * \file clxx/b5d/cl_fcn/finish.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED
#define CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_fcn.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_fcn.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class finish_test_suite; }

/** // doc: class clxx::finish_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::finish_test_suite : public CxxTest::TestSuite
{
public:
  ////////////////////////////////////////////////////////////////////////////
  //  finish()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__finish() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish( )
  {
#if CLXX_B5D_PROVIDES(finish)
    T::Dummy_clFinish mock(CL_SUCCESS);
    finish                          ((cl_command_queue)0x344);
    TS_ASSERT(mock.called_once_with((cl_command_queue)0x344));
#else
    TS_SKIP("finish not implemented");
#endif
  }
  /** // doc: test__finish__invalid_command_queue() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__invalid_command_queue( )
  {
#if CLXX_B5D_PROVIDES(finish)
    T::Dummy_clFinish mock(CL_INVALID_COMMAND_QUEUE);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::invalid_command_queue>);
#else
    TS_SKIP("finish not implemented");
#endif
  }
  /** // doc: test__finish__out_of_resources() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__out_of_resources( )
  {
#if CLXX_B5D_PROVIDES(finish)
    T::Dummy_clFinish mock(CL_OUT_OF_RESOURCES);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::out_of_resources>);
#else
    TS_SKIP("finish not implemented");
#endif
  }
  /** // doc: test__finish__out_of_host_memory() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__out_of_host_memory( )
  {
#if CLXX_B5D_PROVIDES(finish)
    T::Dummy_clFinish mock(CL_OUT_OF_HOST_MEMORY);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL),clerror_no<status_t::out_of_host_memory>);
#else
    TS_SKIP("finish not implemented");
#endif
  }
  /** // doc: test__finish__unexpected_clerror() {{{
   * \todo Write documentation
   */ // }}}
  void test__finish__unexpected_clerror( )
  {
#if CLXX_B5D_PROVIDES(finish)
    T::Dummy_clFinish mock(-0x1234567);
    TS_ASSERT_THROWS(finish((cl_command_queue)NULL), unexpected_clerror);
#else
    TS_SKIP("finish not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FCN_FLUSH_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
