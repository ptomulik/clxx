// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/program_lazy_generator.t.h

/** // doc: clxx/x10d/program_lazy_generator.t.h {{{
 * \file clxx/x10d/program_lazy_generator.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_PROGRAM_LAZY_GENERATOR_T_H_INCLUDED
#define CLXX_X10D_PROGRAM_LAZY_GENERATOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/x10d/program_lazy_generator.hpp>
#include <clxx/cl/mock.hpp>
#include <type_traits>

namespace clxx { class program_lazy_generator_test_suite; }

/** // doc: class clxx::program_lazy_generator_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::program_lazy_generator_test_suite : public CxxTest::TestSuite
{
  class G0 : public program_lazy_generator
  {
  public:
    mutable int count;
    G0() : program_lazy_generator(), count(0) { }
    std::string program_path(clxx::context const&) const { return "/tmp/clxx/g0.cl"; }
    void generate_program_source(std::string&, clxx::context const&) const
    {
      count++;
    }
  };

  class G1 : public program_lazy_generator
  {
  public:
    mutable int count;
    G1() : program_lazy_generator(), count(0) { }
    std::string program_path(clxx::context const&) const { return "/tmp/clxx/g1.cl"; }
    void generate_program_source(std::string& src, clxx::context const&) const
    {
      src.append("__kernel void foo() {}\n");
      count++;
    }
  };
public:
  /** // doc: test__base_class__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__base_class__1( )
  {
    TS_ASSERT((std::is_base_of<program_generator, program_lazy_generator>::value));
  }
  /** // doc: test__get_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__get_program__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    G0 const& g0 = G0{};
    program_generator const& pg = g0;
    clxx::context const& c{ (cl_context)0x4567 };
    clxx::program const& p1{ pg.get_program(c) };

    TS_ASSERT(mockRetainContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockReleaseContext.never_called());
    TS_ASSERT(mockRetainProgram.never_called());
    TS_ASSERT(mockReleaseProgram.never_called());
    TS_ASSERT(mockCreateProgramWithSource.called_once());
    TS_ASSERT_EQUALS(std::get<0>(mockCreateProgramWithSource.calls().back()), (cl_context)0x4567);
    TS_ASSERT_EQUALS(std::get<1>(mockCreateProgramWithSource.calls().back()), 1);
    TS_ASSERT(p1.get() == (cl_program)0x1234);

    TS_ASSERT_EQUALS(g0.count, 1);
    clxx::program const& p2 { pg.get_program(c) };
    TS_ASSERT_EQUALS(g0.count, 1);
    TS_ASSERT(p1 == p2);
  }

  /** // doc: test__discard_memoized_program__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__discard_memoized_program__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    G0 const& g0 = G0{};
    program_lazy_generator const& plg = G0{};
    program_generator const& pg = G0{};
    clxx::context const& c{ (cl_context)0x4567 };

    TS_ASSERT_EQUALS(plg.discard_memoized_program(c), 0u);
    clxx::program const& p{ pg.get_program(c) };
    TS_ASSERT_EQUALS(plg.discard_memoized_program(c), 1u);

    TS_ASSERT(mockRetainContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockReleaseContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockRetainProgram.never_called());
    TS_ASSERT(mockReleaseProgram.called_once_with((cl_program)0x1234));
    TS_ASSERT(mockCreateProgramWithSource.called_once());
    TS_ASSERT_EQUALS(g0.count, 1);
  }

  /** // doc: test__discard_memoized_programs__1() {{{
   * \todo Write documentation
   */ // }}}
  void test__discard_memoized_programs__1( )
  {
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    G0 const& g0 = G0{};
    program_generator const& pg = G0{};
    program_lazy_generator const& plg = G0{};
    clxx::context const& c{ (cl_context)0x4567 };

    TS_ASSERT_EQUALS(plg.discard_memoized_program(c), 0u);
    clxx::program const& p{ pg.get_program(c) };
    TS_ASSERT_EQUALS(plg.discard_memoized_program(c), 1u);

    TS_ASSERT(mockRetainContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockReleaseContext.called_once_with((cl_context)0x4567));
    TS_ASSERT(mockRetainProgram.never_called());
    TS_ASSERT(mockReleaseProgram.called_once_with((cl_program)0x1234));
    TS_ASSERT(mockCreateProgramWithSource.called_once());
    TS_ASSERT_EQUALS(g0.count, 1);
  }
};

#endif /* CLXX_X10D_PROGRAM_LAZY_GENERATOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
