// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/functions/svm_alloc.t.h

/** // doc: clxx/cl/functions/svm_alloc.t.h {{{
 * \file clxx/cl/functions/svm_alloc.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED
#define CLXX_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/functions.hpp>
#include <clxx/common/exceptions.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class functions_svm_alloc_test_suite; }

/** // doc: class clxx::functions_svm_alloc_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::functions_svm_alloc_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  svm_alloc()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__svm_alloc() {{{
   * \brief Test svm_alloc() in a normal situation.
   */ // }}}
  void test__svm_alloc( )
  {
    T::Dummy_clSVMAlloc mock((void*)0x1234);
    TS_ASSERT(svm_alloc((cl_context)0x7654, svm_mem_flags_t::read_write, 123ul, 12u) == (void*)0x1234);
    TS_ASSERT(mock.called_once_with((cl_context)0x7654, (cl_svm_mem_flags)CL_MEM_READ_WRITE, 123ul, 12u));
  }
};

#endif /* CLXX_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
