// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/current_program_with_source_ctor.t.h

/** // doc: clxx/cl/current_program_with_source_ctor.t.h {{{
 * \file clxx/cl/current_program_with_source_ctor.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_CURRENT_PROGRAM_CTOR_T_H_INCLUDED
#define CLXX_CL_CURRENT_PROGRAM_CTOR_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/cl/current_program_with_source_ctor.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/mock.hpp>

namespace clxx { class current_program_with_source_ctor_test_suite; }

/** // doc: class clxx::current_program_with_source_ctor_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::current_program_with_source_ctor_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__current_program_with_source_ctor_binding() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_program_with_source_ctor_binding( )
  {
    clxx::program_with_source_ctor custom;

    current_program_with_source_ctor::reset_binding();
    TS_ASSERT(current_program_with_source_ctor::binding() == current_instance_default_binding());

    current_program_with_source_ctor::bind_static_instance();
    TS_ASSERT(current_program_with_source_ctor::binding() == current_instance_binding_t::static_instance);

    current_program_with_source_ctor::bind_thread_instance();
    TS_ASSERT(current_program_with_source_ctor::binding() == current_instance_binding_t::thread_instance);

    current_program_with_source_ctor::bind_custom_instance(custom);
    TS_ASSERT(current_program_with_source_ctor::binding() == current_instance_binding_t::custom_instance);
  }
  /** // doc: test__current_program_with_source_ctor_get() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_program_with_source_ctor_get( )
  {
    current_program_with_source_ctor::reset_binding();
    TS_ASSERT(&current_program_with_source_ctor::get( ) != nullptr);
  }
  /** // doc: test__current_program_with_source_ctor__custom_subclass() {{{
   * \todo Write documentation
   */ // }}}
  void test__current_program_with_source_ctor__custom_subclass( )
  {
    class C0 : public clxx::program_with_source_ctor {
    public:
      mutable int count;
      C0() : count{0} { }
      clxx::program operator()(clxx::context const& context, clxx::program_sources const& sources) const
      {
        ++count;
        return this->program_with_source_ctor::operator()(context, sources);
      }
    };

    T::Dummy_clRetainProgram mockRetainProgram(CL_SUCCESS);
    T::Dummy_clReleaseProgram mockReleaseProgram(CL_SUCCESS);
    T::Dummy_clRetainContext mockRetainContext(CL_SUCCESS);
    T::Dummy_clReleaseContext mockReleaseContext(CL_SUCCESS);
    T::Dummy_clCreateProgramWithSource mockCreateProgramWithSource((cl_program)0x1234, CL_SUCCESS);

    C0 c0;
    current_program_with_source_ctor::bind_custom_instance(c0);
    TS_ASSERT_EQUALS(c0.count, 0);

    clxx::context c{(cl_context)0x4321};
    clxx::program p{ current_program_with_source_ctor::get()(c, {""}) };

    TS_ASSERT_EQUALS(c0.count, 1);

    {
      current_program_with_source_ctor::get()(c, {""});
      TS_ASSERT_EQUALS(c0.count, 2);
    }
    current_program_with_source_ctor::reset_binding();
  }
};

#endif /* CLXX_CL_CURRENT_PROGRAM_CTOR_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
