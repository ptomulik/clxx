// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/program_with_source_ctor.t.h

/** // doc: clxx/cl/program_with_source_ctor.t.h {{{
 * \file clxx/cl/program_with_source_ctor.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_T_H_INCLUDED
#define CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/program_with_source_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class program_with_source_ctor_test_suite; }

/** // doc: class clxx::program_with_source_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_with_source_ctor_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__program_with_source_ctor__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__program_with_source_ctor__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    clxx::context c{(cl_context)0x4321};
    clxx::program_with_source_ctor program_ctor;
    clxx::program p { program_ctor(c, {"__kernel void trivial(){ }\n"}) };

    TS_ASSERT(p.get() == (cl_program)0x1234);
    TS_ASSERT(mockCreateProgramWithSource.called_once());
    TS_ASSERT(std::get<0>(mockCreateProgramWithSource.calls().front()) == c.get());
  }
};

#endif /* CLXX_CL_PROGRAM_WITH_SOURCE_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
