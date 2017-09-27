// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/program_observer.hpp

/** // doc: clxx/b3c/program_observer.hpp {{{
 * \file clxx/b3c/program_observer.hpp
 * \brief Defines \ref clxx::program_observer "program_observer" class
 */ // }}}
#ifndef CLXX_B3C_PROGRAM_OBSERVER_HPP_INCLUDED
#define CLXX_B3C_PROGRAM_OBSERVER_HPP_INCLUDED

#include <clxx/b5d/types.hpp>

namespace clxx {
class program;
/** // doc: program_observer {{{
 * \ingroup clxx_cl_program_objects
 * \brief Program observer
 *
 * Use the \ref clxx::program_observer "program_observer" as a base class for
 * your own observers to get notifications when compiling/building/linking
 * OpenCL programs. Original OpenCL functions \c clBuildProgram(),
 * \c clCompileProgram(), or \c clLinkProgram() accept a pointer to callback
 * function to invoke the callback when the build process completes. In clxx,
 * we use observer objects instead, which shall be subclasses of the
 * \ref clxx::program_observer "program_observer".
 */ // }}}
class program_observer
{
public:
  /** // doc: fcn_ptr_t {{{
   * \brief Typedef for the original OpenCL callback function type
   */ // }}}
  typedef void (CL_CALLBACK *fcn_ptr_t)(cl_program, void*);
private:
  static void CL_CALLBACK static_notify(cl_program prog, void* ptr);
protected:
  /** // doc: notify() {{{
   * \brief This function shall be implemented by a derived class
   *
   * This method is called by a \ref clxx::program "program" object, when
   * a program build process has completed (successfully or unsuccessfully).
   */ // }}}
  virtual void notify(program const&) = 0;
public:
  /** // doc: ~program_observer() {{{
   * \brief Destructor
   */ // }}}
  virtual ~program_observer() { }
  /** // doc: fcn_ptr() {{{
   * \brief Retrieve the function address of central dispatcher
   * \returns A pointer to the actual callback function which dispatches
   *          callback invocations to appropriate instances of the
   *          \ref clxx::program_observer "program_observer"
   */ // }}}
  virtual fcn_ptr_t fcn_ptr() const noexcept;
  /** // doc: fcn_arg() {{{
   * \brief Returns an argument, that shall be passed to the actual callback
   *        function
   * \returns Returns \c this pointer converted to \c void*.
   */ // }}}
  virtual void* fcn_arg() noexcept;
};
} // end namespace clxx

#endif /* CLXX_B3C_PROGRAM_OBSERVER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
