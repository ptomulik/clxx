// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/runtime.hpp

/** // doc: clxx/cl/runtime.hpp {{{
 * \file clxx/cl/runtime.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_RUNTIME_HPP_INCLUDED
#define CLXX_CL_RUNTIME_HPP_INCLUDED

#include <clxx/cl/program_lazy_generator.hpp>
#include <clxx/cl/kernel_lazy_ctor.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/devices.hpp>
#include <unordered_map>
#include <string>

namespace clxx {
/** // doc: runtime {{{
 * \todo Write documentation
 */ // }}}
class runtime
{
private:
  typedef std::unordered_map<std::string, program_generator_ptr> program_generator_map_t;
  program_generator_map_t _program_generators;
public:
  /** // doc: get_program_generator(name) {{{
   * \brief Returns named \ref clxx::program "program" generator
   * \param name
   *    Name of the generator in question
   * \returns
   *    Named program generator
   * \throw clxx::invalid_key_error
   *    If \p name does not name a stored program generator
   */ // }}}
  program_generator_ptr const& get_program_generator(std::string const& name) const;
  /** // doc: set_program_generator(generator) {{{
   * \todo Write documentation
   */ // }}}
  program_generator_ptr const& set_program_generator(std::string const& name,
                                                     clxx::program_generator_ptr const& generator);
  /** // doc: has_program_generator(name) {{{
   * \todo Write documentation
   */ // }}}
  bool has_program_generator(std::string const& name) const;
  /** // doc: generate_program(name, context) {{{
   * \todo Write documentation
   */ // }}}
  clxx::program generate_program(std::string const& name, clxx::context const& context) const;
  /** // doc: generate_build_program(program, name, context, build_options, force_build) {{{
   * \todo Write documentation
   */ // }}}
  void generate_build_program(clxx::program& program,
                              std::string const& name,
                              clxx::context const& context,
                              std::string const& build_options = "",
                              bool force_build = false) const;
  /** // doc: generate_build_program(program, name, devices, build_options, force_build) {{{
   * \todo Write documentation
   */ // }}}
  void generate_build_program(clxx::program& program,
                              std::string const& name,
                              clxx::context const& context,
                              clxx::devices const& devices,
                              std::string const& build_options = "",
                              bool force_build = false) const;
};
} // end namespace clxx
#endif /* CLXX_CL_RUNTIME_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
