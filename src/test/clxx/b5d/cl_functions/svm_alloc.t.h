// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions/svm_alloc.t.h

/** // doc: clxx/b5d/cl_functions/svm_alloc.t.h {{{
 * \file clxx/b5d/cl_functions/svm_alloc.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/cl_functions.hpp>
#include <clxx/b5d/cl_exceptions.hpp>
#include <clxx/b5d/mocks/cl_functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class svm_alloc_test_suite; }

/** // doc: class clxx::svm_alloc_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::svm_alloc_test_suite : public CxxTest::TestSuite
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
#if CLXX_B5D_PROVIDES(svm_alloc)
    T::Dummy_clSVMAlloc mock((void*)0x1234);
    TS_ASSERT(svm_alloc((cl_context)0x7654, svm_mem_flags_t::read_write, 123ul, 12u) == (void*)0x1234);
    TS_ASSERT(mock.called_once_with((cl_context)0x7654, (cl_svm_mem_flags)CL_MEM_READ_WRITE, 123ul, 12u));
#else
    TS_SKIP("svm_alloc not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_CL_FUNCTIONS_SVM_ALLOC_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
