// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/mem.hpp

/** // doc: clxx/mem.hpp {{{
 * \file clxx/mem.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_MEM_HPP_INCLUDED
#define CLXX_MEM_HPP_INCLUDED

#include <clxx/mem_fwd.hpp>
#include <clxx/context_fwd.hpp>
#include <clxx/types.hpp>
#include <clxx/cl/cl.h>
#include <clxx/clobj.hpp>

namespace clxx {
/** // doc: mem {{{
 * \ingroup clxx_buffer_objects
 * \brief Encapsulates an OpenCL memory object
 *
 * This class represents OpenCL memory object (e.g. buffer or image) and
 * forwards basic operations on memory objects to OpenCL. It encapsulates a
 * \c cl_mem identifier and supports following operations:
 *
 * - memory object creation (constructors),
 * - automatic reference count management by using internally
 *   \ref retain_mem_object() and \ref release_mem_object(),
 * - retrieving mem information from OpenCL (via class methods), by
 *   invoking internally \ref get_mem_object_info() and \ref get_image_info().
 *
 * Although \ref clxx::mem "mem" maintains internally reference count
 * for its \c cl_mem handle, it doesn't prevent one from stealing the
 * \c cl_mem handle (#id(), #get_valid_handle()). This gives rise to manipulate the
 * reference count outside of the \ref clxx::mem object for the given OpenCL
 * memory object. If you need to steal, use the retrieved handle with care. If
 * you retrieve the handle from \ref clxx::mem "mem" object, increase its
 * reference count with \ref clxx::retain_mem_object() "retain_mem_object()"
 * as soon as possible, and decrease the reference count with
 * \ref clxx::release_mem_object() "release_mem_object()" once you don't need
 * the handle. If you don't retain the mem, it may be unexpectedly released by
 * \ref clxx::mem "mem's"  destructor, assignment operator or the #assign()
 * method.
 *
 * There are constructors which create new OpenCL memory object (a costly
 * operation). However, assignment operator and copy constructors just copy
 * over the \c cl_mem handle and maintain reference count appropriately. To
 * verify if two \ref clxx::mem "mem" objects refer to the same OpenCL
 * mem, use \c == operator (of \c != operator).
 *
 * An OpenCL memory object (identified by \c cl_mem handle) is not released
 * until there is at least one \ref clxx::mem "mem" object
 * encapsulating its handle. On the other hand - the mem may get released
 * by OpenCL when last \ref clxx::mem "mem" object gets deleted (the
 * ~mem() destructor decreases reference count for its \c cl_mem
 * handle with \ref clxx::release_mem_object() "release_mem_object()") or when
 * the last object gets assigned another OpenCL memory object (assignment
 * operator or the #assign() method).
 */ // }}}
class alignas(cl_mem) mem
  : public clobj<cl_mem>
{
public:
  typedef clobj<cl_mem> Base;
  using Base::Base;
  mem() = default;
  mem(mem const&) = default;
  /** // doc: mem(context const&, mem_flags_t, size_t, void*) {{{
   * \todo Write documentation
   */ // }}}
  explicit mem(context const& ctx, mem_flags_t flags, size_t size, void* host_ptr);
  /** // doc: get_type() {{{
   * \todo Write documentation
   */ // }}}
  mem_object_type_t get_type() const;
  /** // doc: get_flags() {{{
   * \todo Write documentation
   */ // }}}
  mem_flags_t get_flags() const;
  /** // doc: get_size() {{{
   * \todo Write documentation
   */ // }}}
  size_t get_size() const;
  /** // doc: get_host_ptr() {{{
   * \todo Write documentation
   */ // }}}
  void* get_host_ptr() const;
  /** // doc: get_map_count() {{{
   * \todo Write documentation
   */ // }}}
  cl_uint get_map_count() const;
  /** // doc: get_reference_count() {{{
   * \brief Get reference count for the memory object
   *
   * \returns reference count for the memory object.
   *
   * \throws uninitialized_mem_error if the object was not initialized
   *      properly (see \ref is_initialized()).
   *
   * It also throws exceptions originating fro \ref get_mem_object_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_context() {{{
   * \todo Write documentation
   */ // }}}
  context get_context() const;
#if CLXX_CL_H_VERSION_1_1
  /** // doc: get_associated_memobject() {{{
   * \todo Write documentation
   */ // }}}
  mem get_associated_memobject() const;
  /** // doc: get_offset() {{{
   * \todo Write documentation
   */ // }}}
  size_t get_offset() const;
#endif
#if CLXX_CL_H_VERSION_2_0
  /** // doc: get_uses_svm_pointer() {{{
   * \todo Write documentation
   */ // }}}
  cl_bool get_uses_svm_pointer() const;
#endif
};
} // end namespace clxx

#endif /* CLXX_MEM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
