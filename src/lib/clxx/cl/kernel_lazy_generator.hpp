// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/kernel_lazy_generator.hpp

/** // doc: clxx/cl/kernel_lazy_generator.hpp {{{
 * \file clxx/cl/kernel_lazy_generator.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CL_KERNEL_LAZY_GENERATOR_HPP_INCLUDED
#define CLXX_CL_KERNEL_LAZY_GENERATOR_HPP_INCLUDED
#include <clxx/cl/program.hpp>
#include <clxx/cl/kernel.hpp>
#include <string>
#include <map>
#include <mutex>

namespace clxx {
/** // doc: kernel_lazy_generator {{{
 * \todo Write documentation
 */ // }}}
class kernel_lazy_generator
{
public:
  /** // doc: kernel_map_t {{{
   * \todo Write documentation
   */ // }}}
  typedef std::map<std::string, clxx::kernel> kernel_map_t;
  /** // doc: memoized_kernels_t {{{
   * \todo Write documentation
   */ // }}}
  typedef std::map<clxx::program, kernel_map_t> memoized_kernels_t;
private:
  mutable memoized_kernels_t _kernels;
  mutable std::mutex _kernels_mutex;
public:
  /** // doc: ~kernel_lazy_generator() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~kernel_lazy_generator() {}
  /** // doc: get_kernel(program, name) {{{
   * \todo Write documentation
   */ // }}}
  virtual clxx::kernel get_kernel(clxx::program const& program, std::string const& name) const;
  /** // doc: memoize_kernels(program, names) {{{
   * \todo Write documentation
   */ // }}}
  void memoize_kernels(clxx::program const& program, std::string const& names) const;
  /** // doc: memoize_kernels(program) {{{
   * \todo Write documentation
   */ // }}}
  void memoize_kernels(clxx::program const& program) const;
  /** // doc: discard_memoized_kernel(program, kernel) {{{
   * \todo Write documentation
   */ // }}}
  size_t discard_memoized_kernel(clxx::program const& program, std::string const& name) const;
  /** // doc: discard_memoized_kernels(program){{{
   * \todo Write documentation
   */ // }}}
  size_t discard_memoized_kernels(clxx::program const& program) const;
  /** // doc: discard_memoized_kernels() {{{
   * \todo Write documentation
   */ // }}}
  void discard_memoized_kernels() const;
};
} // end namespace clxx
#endif /* CLXX_CL_KERNEL_LAZY_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
