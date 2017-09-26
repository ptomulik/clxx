// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b3c/program.hpp

/** // doc: clxx/b3c/program.hpp {{{
 * \file clxx/b3c/program.hpp
 * \brief Provides clxx::program class and related functions
 */ // }}}
#ifndef CLXX_B3C_PROGRAM_HPP_INCLUDED
#define CLXX_B3C_PROGRAM_HPP_INCLUDED

#include <clxx/b3c/program_fwd.hpp>
#include <clxx/b3c/devices.hpp>
#include <clxx/b3c/context_fwd.hpp>
#include <clxx/c4n/program_sources.hpp>
#include <clxx/c4n/program_binaries.hpp>
#include <clxx/b3c/program_observer.hpp>
#include <clxx/b5d/cl_types.hpp>
#include <clxx/b3c/clobj.hpp>
#include <vector>
#include <string>

namespace clxx {
/** // doc: program {{{
 * \ingroup clxx_cl_program_objects
 * \brief Encapsulates an OpenCL program object
 *
 * This class represents OpenCL program and forwards basic operations on
 * programs to OpenCL. It encapsulates a \c cl_program identifier and
 * supports following operations:
 *
 * - program creation (constructors), by calling internally \ref
 *   create_program_with_source(), \ref create_program_with_binary(), or
 *   \ref create_program_with_built_in_kernels(),
 * - automatic reference count management by using internally
 *   \ref retain_program() and \ref release_program(),
 * - retrieving program information from OpenCL (via class methods), by
 *   invoking internally \ref get_program_info().
 * - retrieving program build information from OpenCL (via class methods), by
 *   calling internally \ref clxx::get_program_build_info() "get_program_build_info()",
 *
 * Note, that the newly created program (from source) is not compiled. It may
 * be compiled by using \ref clxx::compile_program() "compile_program()",
 * \ref clxx::build_program() "build_program()", and/or \ref clxx::link_program()
 * "link_program()".
 *
 * Although \ref clxx::program "program" maintains internally reference count
 * for its \c cl_program handle, it doesn't prevent one from stealing the \c
 * cl_program handle (\ref get(), \ref chk_get()). This gives rise to
 * manipulate the reference count outside of the \ref clxx::program object for
 * the given OpenCL program object. If you need to steal, use the retrieved
 * handle with care. If you retrieve the handle from \ref clxx::program
 * "program" object, increase its reference count with \ref
 * clxx::retain_program() "retain_program()" as soon as possible, and decrease
 * the reference count with \ref clxx::release_program() "release_program()"
 * once you don't need the handle. If you don't retain the program, it may be
 * unexpectedly released by \ref clxx::program "program's"  destructor,
 * assignment operator or the #assign() method.
 *
 * There are constructors which create new OpenCL program (a costly operation).
 * However, assignment operator and copy constructors just copy over the \c
 * cl_program handle and maintain reference count appropriately. To verify
 * if two \ref clxx::program "program" objects refer to the same OpenCL
 * program, use \c == operator (of \c != operator).
 *
 * An OpenCL program (identified by \c cl_program handle) is not released
 * until there is at least one \ref clxx::program "program" object
 * encapsulating its handle. On the other hand - the program may get released
 * by OpenCL when last \ref clxx::program "program" object gets deleted (the
 * ~program() destructor decreases reference count for its \c cl_program
 * handle with \ref clxx::release_program() "release_program()") or when the
 * last object gets assigned another OpenCL program (assignment operator or the
 * #assign() method).
 */ // }}}
class alignas(cl_program) program
  : public clobj<cl_program>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_program> Base;
  using Base::Base;
  /** // doc: program() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  program() = default;
  /** // doc: program() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  program(program const&) = default;
  /** // doc: program(context const&, program_sources const&) {{{
   * \brief Create program with sources
   *
   * Creates new program by using \ref create_program_with_source().
   *
   * \param ctx OpenCL context (clxx object \ref clxx::context "context"),
   * \param sources sources that comprise the program.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref create_program_with_source().
   */ // }}}
  program(context const& ctx, program_sources const& sources);
  /** // doc: program(context, device_list, binaries, binary_statuses) {{{
   * \brief Create program with binaries
   *
   * Creates new program by using \ref create_program_with_binary().
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, the binaries are loaded for
   *    devices specified in this list,
   * \param binaries
   *    program binaries to be loaded for devices specified in *device_list*,
   *    for each device given by *device_list[i]*, the binary for that device
   *    is given in *binaries[i]*,
   * \param binary_status
   *    returns whether the program binary for each device specified in
   *    *device_list* was loaded successfully or not.
   *
   * \throws clxx::invalid_argument_error when *device_list* is empty or
   *        *device_list* has different size than *binaries*.
   *
   * In addition exceptions originating from \ref create_program_with_binary()
   * may be thrown.
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries,
          std::vector<status_t>& binary_status);
  /** // doc: program(context, device_list, binaries) {{{
   * \brief Create program with binaries
   *
   * Creates new program by using \ref create_program_with_binary().
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, the binaries are loaded for
   *    devices specified in this list,
   * \param binaries
   *    program binaries to be loaded for devices specified in *device_list*,
   *    for each device given by *device_list[i]*, the binary for that device
   *    is given in *binaries[i]*,
   *
   * \throws clxx::invalid_argument_error when *device_list* is empty or
   *        *device_list* has different size than *binaries*.
   *
   * In addition exceptions originating from \ref create_program_with_binary()
   * may be thrown.
   */ // }}}
  program(context const& ctx, devices const& device_list,
          program_binaries const& binaries);
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
  /** // doc: program(context, device_list, kernel_names) {{{
   * \brief Create program with built in kernels
   *
   * Creates new OpenCL program by using
   * \ref create_program_with_built_in_kernels(). Note, that
   * \ref create_program_with_built_in_kernels() performs internal retain.
   *
   * \note Only available if the clxx library is built with OpenCL 1.2 or later.
   *
   * \param ctx
   *    must be a valid \ref clxx::context "context",
   * \param device_list
   *    list of devices that are in context *ctx*, built-in kernels are loaded
   *    for devices specified in this list; the devices associated wit the
   *    program object will be the list of devices specified by *device_list*
   * \param kernel_names
   *    a semi-colon separated list of built-in kernel names.
   *
   * \par Exceptions
   *
   * Throws exceptions originating from \ref create_program_with_built_in_kernels().
   */ // }}}
  program(context const& ctx, devices const& device_list,
          std::string const& kernel_names);
#endif
  /** // doc: get_build_info(...) {{{
   * \brief Returns build information for each device in the program object
   *
   * \param dev
   *    device for which build information is being queried. device must be a
   *    valid device associated with program.
   * \param name
   *    specifies the information to query; the list of supported *name*
   *    types is documented in \ref program_build_info_t.
   * \param value_size
   *    the size in bytes of memory pointed to by *value*; this size must be >=
   *    size of return type as described in the table above
   * \param value
   *    a pointer to memory where the appropriate result being queried is
   *    returned; if *value* is \c NULL, it is ignored,
   * \param value_size_ret
   *    returns the actual size in bytes of data copied to *value*. If
   *    *value_size_ret* is \c NULL, it is ignored.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  void get_build_info(device const& dev, program_build_info_t name,
                      size_t value_size, void* value,
                      size_t* value_size_ret) const;
  /** // doc: get_context() {{{
   * \brief Get context associated with this program
   *
   * \returns context associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  context get_context() const;
  /** // doc: get_num_devices() {{{
   * \brief Get number of devices associated with the program
   *
   * \returns number of devices associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  cl_uint get_num_devices() const;
  /** // doc: get_devices() {{{
   * \brief Get devices associated with the program
   *
   * \returns list of devices associated with the program.
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_program_info().
   */ // }}}
  devices get_devices() const;
  /** // doc: get_source() {{{
   * \brief Get program source
   *
   * \returns source code for the program
   *
   * \par Exceptions
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc when it's unable to allocate memory for device list
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  program_source get_source() const;
  /** // doc: get_binary_sizes() {{{
   * \brief Return sizes of the program binaries
   *
   * \returns
   *    a vector of sizes in bytes of the program binary (could be an
   *    executable binary, compiled binary or library binary) for each device
   *    associated with program; if a binary is not available for a device(s),
   *    a size of zero is returned.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc when the memory for vector can't be allocated,
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  std::vector<size_t> get_binary_sizes() const;
  /** // doc: get_binaries() {{{
   * \brief Return program binaries
   *
   * Return the program binaries (could be an executable binary, compiled
   * binary or library binary) for all devices associated with program.
   * For each device in program, the binary returned can be the binary
   * specified for the device when program is created with binary or it
   * can be the executable binary generated by \ref build_program(),
   * \ref compile_program() or \ref link_program(). The bits returned can be an
   * implementation-specific intermediate representation (a.k.a. IR) or device
   * specific executable bits or both. The decision on which information is
   * returned in the binary is up to the OpenCL implementation.
   *
   * \returns program binaries
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   * \throws std::bad_alloc if a memory for program binaries can't be allocated,
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  program_binaries get_binaries() const;
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  /** // doc: get_num_kernels() {{{
   * \brief Return the number of kernels declared in program
   *
   * Returns the number of kernels declared in program that can be created with
   * clCreateKernel. This information is only available after a successful
   * program executable has been built for at least one device in the list of
   * devices associated with program.
   *
   * \returns the number of kernels declared in program
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  size_t get_num_kernels() const;
  /** // doc: get_kernel_names() {{{
   * \brief Return list of kernel names in program
   *
   * \returns a semi-colon separated list of kernel names in program that can
   *          be created with \ref create_kernel().
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_info().
   */ // }}}
  std::string get_kernel_names() const;
#endif
  /** // doc: get_build_status() {{{
   * \brief Return build, compile or link status
   *
   * Returns the build, compile or link status, whichever was performed last on
   * program for device.
   *
   * \param dev
   *    device associated with the program for which the build status has to be
   *    returned.
   *
   * \returns the status, see \ref build_status_t.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  build_status_t get_build_status(device const& dev) const;
  /** // doc: get_build_options() {{{
   * \brief Return build, compile or link options
   *
   * Return the build, compile or link options specified by the options
   * argument to \ref build_program(), \ref compile_program() or \ref
   * link_program() whichever was performed last on this program for device
   * *dev*. If build status of program for device is \c none, an empty
   * string is returned.
   *
   * \param dev
   *    device associated with the program for which the build options have to
   *    be returned.
   *
   * \returns the options, as specified at the build time.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  std::string get_build_options(device const& dev) const;
  /** // doc: get_build_log() {{{
   * \brief Return build, compile or link log
   *
   * Return the build, compile or link log for \ref build_program() or
   * \ref compile_program() whichever was performed last on this program for
   * device *dev*. If build status of program for device is \c none, an empty
   * string is returned.
   *
   * \param dev
   *    device associated with the program for which the build options have to
   *    be returned.
   *
   * \returns the log string.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  std::string get_build_log(device const& dev) const;
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  /** // doc: get_binary_type() {{{
   * \brief Return the program binary type for a device
   *
   * Return the program binary type for device *dev*. Possible values are
   * defined by \ref program_binary_type_t.
   *
   * \returns program binary type for device *dev*.
   *
   * \throws uninitialized_program_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating from \ref get_program_build_info().
   */ // }}}
  program_binary_type_t get_binary_type(device const& dev) const;
#endif
};
} // end namespace clxx

#endif /* CLXX_B3C_PROGRAM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
