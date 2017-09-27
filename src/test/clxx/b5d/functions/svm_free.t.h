// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/functions/svm_free.t.h

/** // doc: clxx/b5d/functions/svm_free.t.h {{{
 * \file clxx/b5d/functions/svm_free.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_FUNCTIONS_SVM_FREE_T_H_INCLUDED
#define CLXX_B5D_FUNCTIONS_SVM_FREE_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/functions.hpp>
#include <clxx/b5d/exceptions.hpp>
#include <clxx/b5d/mocks/functions.hpp>

CLXX_DIAGNOSTIC_PUSH
CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING

namespace  clxx { class svm_free_test_suite; }

/** // doc: class clxx::svm_free_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::svm_free_test_suite : public CxxTest::TestSuite
{
public:

  ////////////////////////////////////////////////////////////////////////////
  //  svm_free()
  ////////////////////////////////////////////////////////////////////////////

  /** // doc: test__svm_free() {{{
   * \brief Test svm_free() in a normal situation.
   */ // }}}
  void test__svm_free( )
  {
#if CLXX_B5D_PROVIDES(svm_free)
    T::Dummy_clSVMFree mock;
    TS_ASSERT_THROWS_NOTHING(svm_free((cl_context)0x7654, (void*)0x1234));
    TS_ASSERT(mock.called_once_with((cl_context)0x7654, (void*)0x1234));
#else
    TS_SKIP("svm_free not implemented");
#endif
  }
};

CLXX_DIAGNOSTIC_POP

#endif /* CLXX_B5D_FUNCTIONS_SVM_FREE_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
