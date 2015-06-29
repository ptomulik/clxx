// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj.hpp

/** // doc: clxx/clobj.hpp {{{
 * \file clxx/clobj.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CLOBJ_HPP_INCLUDED
#define CLXX_CLOBJ_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/** // doc: clobj_info_type {{{
 * \todo Write documentation
 */ // }}}
template< typename Handle >
  struct clobj_info_type;
/** // doc: invalid_clobj_error {{{
 * \todo Write documentation
 */ // }}}
template< typename Handle >
  struct invalid_clobj_error;
/** // doc: uninitialized_clobj_error {{{
 * \todo Write documentation
 */ // }}}
template< typename Handle >
  struct uninitialized_clobj_error;

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template< >
  struct clobj_info_type<cl_command_queue>
  { typedef command_queue_info_t type; };
template< >
  struct clobj_info_type<cl_context>
  { typedef context_info_t type; };
template< >
  struct clobj_info_type<cl_device_id>
  { typedef device_info_t type; };
template< >
  struct clobj_info_type<cl_event>
  { typedef event_info_t type; };
template< >
  struct clobj_info_type<cl_kernel>
  { typedef kernel_info_t type; };
template< >
  struct clobj_info_type<cl_mem>
  { typedef mem_info_t type; };
template< >
  struct clobj_info_type<cl_platform_id>
  { typedef platform_info_t type; };
template< >
  struct clobj_info_type<cl_program>
  { typedef program_info_t type; };
template< >
  struct clobj_info_type<cl_sampler>
  { typedef sampler_info_t type; };

template< >
  struct invalid_clobj_error<cl_command_queue>
  { static constexpr status_t value = status_t::invalid_command_queue; };
template< >
  struct invalid_clobj_error<cl_context>
  { static constexpr status_t value = status_t::invalid_context; };
template< >
  struct invalid_clobj_error<cl_device_id>
  { static constexpr status_t value = status_t::invalid_device; };
template< >
  struct invalid_clobj_error<cl_event>
  { static constexpr status_t value = status_t::invalid_event; };
template< >
  struct invalid_clobj_error<cl_kernel>
  { static constexpr status_t value = status_t::invalid_kernel; };
template< >
  struct invalid_clobj_error<cl_mem>
  { static constexpr status_t value = status_t::invalid_mem_object; };
template< >
  struct invalid_clobj_error<cl_platform_id>
  { static constexpr status_t value = status_t::invalid_platform; };
template< >
  struct invalid_clobj_error<cl_program>
  { static constexpr status_t value = status_t::invalid_program; };
template< >
  struct invalid_clobj_error<cl_sampler>
  { static constexpr status_t value = status_t::invalid_sampler; };

template<>
  struct uninitialized_clobj_error<cl_command_queue>
  { typedef uninitialized_command_queue_error type; };
template<>
  struct uninitialized_clobj_error<cl_context>
  { typedef uninitialized_context_error type; };
template<>
  struct uninitialized_clobj_error<cl_device_id>
  { typedef uninitialized_device_error type; };
template<>
  struct uninitialized_clobj_error<cl_event>
  { typedef uninitialized_event_error type; };
template<>
  struct uninitialized_clobj_error<cl_kernel>
  { typedef uninitialized_kernel_error type; };
template<>
  struct uninitialized_clobj_error<cl_mem>
  { typedef uninitialized_mem_error type; };
template<>
  struct uninitialized_clobj_error<cl_platform_id>
  { typedef uninitialized_platform_error type; };
template<>
  struct uninitialized_clobj_error<cl_program>
  { typedef uninitialized_program_error type; };
#if 0
template<>
  struct uninitialized_clobj_error<cl_sampler>
  { typedef uninitialized_sampler_error type; };
#endif
/** \endcond */
} // end namespace clxx

namespace clxx {
/** // doc: clobj {{{
 * \todo Write documentation
 */ // }}}
template< typename Handle >
class alignas(Handle) clobj
{
private:
  Handle _handle;
public:
  /** // doc: handle_t {{{
   * \todo Write documentation
   */ // }}}
  typedef Handle handle_t;
  /** // doc: info_t {{{
   * \todo Write documentation
   */ // }}}
  typedef typename clobj_info_type<Handle>::type info_t;
protected:
  /** // doc: _set_handle() {{{
   * \todo Write documentation
   */ // }}}
  void _set_handle(handle_t h, bool retain_new, bool release_old);
public:
  /** // doc: clobj() {{{
   * \todo Write documentation
   */ // }}}
  clobj() noexcept;
  /** // doc: clobj(handle_t) {{{
   * \todo Write documentation
   */ // }}}
  explicit clobj(handle_t h);
  /** // doc: clobj(clobj const&) {{{
   * \todo Write documentation
   */ // }}}
  clobj(clobj const& other);
  /** // doc: ~clobj() {{{
   * \todo Write documentation
   */ // }}}
  ~clobj();
  /** // doc: is_initialized() {{{
   * \todo Write documentation
   */ // }}}
  bool is_initialized() const noexcept;
  /** // doc: handle() {{{
   * \todo Write documentation
   */ // }}}
  handle_t handle() const noexcept;
  /** // doc: get_valid_handle() {{{
   * \todo Write documentation
   */ // }}}
  handle_t get_valid_handle() const;
  /** // doc: get_info() {{{
   * \todo Write documentation
   */ // }}}
  void get_info(info_t name, size_t value_size, void* value, size_t* value_size_ret) const;
  /** // doc: operator= {{{
   * \brief Assignment operator
   *
   * \param rhs Another clobj object to be assigned to this object
   *
   *  This operation copies the \c handle_t handle held by \e rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throw uninitialized_clobj_error
   *    when the \e rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_clobj>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_clobj() and release_clobj()
   * \throw unexpected_clerror
   *    propagated from retain_clobj() and release_clobj()
   */ // }}}
  clobj& operator=(clobj const& rhs);
  /** // doc: operator== {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return
   *    Returns <tt>this->handle() == rhs.handle()</tt>
   */ // }}}
  bool operator == (clobj const& rhs) const noexcept;
  /** // doc: operator!= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \returns <tt>this->handle() != rhs.handle()</tt>
   */ // }}}
  bool operator != (clobj const& rhs) const noexcept;
  /** // doc: operator< {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() < rhs.handle())</tt>
   */ // }}}
  bool operator < (clobj const& rhs) const noexcept;
  /** // doc: operator> {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() > rhs.handle()</tt>
   */ // }}}
  bool operator > (clobj const& rhs) const noexcept;
  /** // doc: operator<= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() <= rhs.handle()</tt>
   */ // }}}
  bool operator <= (clobj const& rhs) const noexcept;
  /** // doc: operator>= {{{
   * \brief Compare this clobj with another one
   *
   * \param rhs
   *    Another clobj object to be compared to \c this object.
   *
   * \return <tt>this->handle() >= rhs.handle()</tt>
   */ // }}}
  bool operator >= (clobj const& rhs) const noexcept;
  /** // {{{
   * \brief Assignment
   *
   *  This operation copies the \c handle_t handle held by \e rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \e rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \throw uninitialized_clobj_error
   *    when \e rhs is an uninitialized clobj object.
   * \throw clerror_no<status_t::invalid_clobj>
   *    when \e rhs holds a \c handle_t handle that is invalid.
   * \throw clerror_no<status_t::out_of_resources>
   *    propagated from retain_clobj() and release_clobj()
   * \throw clerror_no<status_t::out_of_host_memory>
   *    propagated from retain_clobj() and release_clobj()
   * \throw unexpected_clerror
   *    propagated from retain_clobj() and release_clobj()
   */ // }}}
  void assign(clobj const& rhs);
};
} // end namespace clxx

#endif /* CLXX_CLOBJ_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
