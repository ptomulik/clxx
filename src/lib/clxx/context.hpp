/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

// clxx/context.hpp

/** // doc: clxx/context.hpp {{{
 * \file clxx/context.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CONTEXT_HPP_INCLUDED
#define CLXX_CONTEXT_HPP_INCLUDED

#include <clxx/context_properties.hpp>
#include <clxx/devices.hpp>
#include <clxx/types.hpp>

namespace clxx {

/** // doc: context {{{
 * \ingroup clxx_platform_layer
 * \brief Proxy to OpenCL context.
 *
 * This class represents OpenCL context and forwards basic operations on
 * contexts to OpenCL platform layer. It encapsulates a \c cl_context handle
 * and supports following operations:
 *
 * - context creation (constructors), by calling internally
 *   \ref create_context() and \ref create_context_from_type(),
 * - automatic reference count management by using internally
 *   \ref retain_context() and \ref release_context(),
 * - retrieving context information from OpenCL (via class methods),
 *   by invoking internally \ref get_context_info().
 *
 * Although \ref context maintains internally reference count for its
 * \c cl_context handle, it doesn't prevent one from stealing the
 * \c cl_context handle (ctx(), get_valid_ctx()). This gives rise to manipulate
 * the reference count outside of object. If you need to steal, use the
 * retrieved handle with care. If you retrieve the handle from \ref context
 * object, increase its reference count with \ref retain_context() as soon as
 * possible, and decrease the reference count with \ref release_context() once
 * you don't need the handle. If you don't retain the context, it may be
 * unexpectedly released by \ref context's destructor.
 *
 * There are constructors which create new OpenCL context (a costly operation).
 * However, assignment operator and copy constructors just copy over the
 * \c cl_context handle and maintain reference count appropriately. To verify
 * if two context objects refer to the same OpenCL context use \c == operator
 * (or \c != operator).
 *
 * An OpenCL context (identified by \c cl_context handle) is not released until
 * there is at least one context object encapsulating its handle. On the other
 * hand - the context may get released by OpenCL when last \ref context object
 * gets deleted (the ~context() destructor decreases reference count for its
 * \c cl_context handle with \ref release_context()).
 */ // }}}
class context
{
private:
  cl_context  _ctx;
  context();
protected:
  /** // doc: ctx() {{{
   * \brief   Get \c cl_context handle held by \c this object.
   *
   * \return  The \c cl_context handle held by \c this object.
   */ // }}}
  cl_context ctx() const noexcept;
  /** // doc: get_valid_ctx() {{{
   * \brief   Check if \c this object is initialized and return \c cl_context
   *          handle held by this object.
   *
   * \return  The \c cl_context handle to OpenCL context encapsulated within
   *          this object.
   *
   * \throw uninitialized_context_error when the object was not properly
   *        initialized (see is_initialized()).
   */ // }}}
  cl_context get_valid_ctx() const;
  /** // doc: _sdoc: _set_id() {{{
   * \brief Set new \c cl_context handle to this object
   *
   * \param ctx
   *    A \c cl_context handle to OpenCL context. It must be a valid handle if
   *    \c retain_new is true.
   * \param retain_new
   *    If \c true, the reference count for \c ctx gets increased,
   * \param release_old
   *    If \c true, the reference count for old identifier encapsulated to this
   *    end by the object gets decreased,
   *
   * \throw clerror_no<status_t::invalid_context>
   *    when the \c retain_new is true and \c ctx is not a valid \c cl_context
   *    handle or when \c release_old is \c true and \c this object holds an
   *    invalid \c cl_context handle.
   */ // }}}
  void _set_id(cl_context ctx, bool retain_new, bool release_old);
public:
  /** // doc: context(cl_context) {{{
   * \brief Constructor
   *
   * Initializes new \ref context object with OpenCL context handle.
   *
   * \param ctx OpenCL context handle
   *
   * It may throw exceptions described in \ref retain_context().
   */ // }}}
  explicit context(cl_context ctx);
  /** // doc: context(props, devs, pfn_notify, user_data) {{{
   * \brief Constructor - create new OpenCL context (costly).
   *
   * This constructor calls \ref create_context() to create new OpenCL context
   * and stores the returned \c cl_context handle to the newly created context
   * object. It does not increment the reference count internally, as it
   * obtains from OpenCL a new context with reference count set to 1.
   *
   * \param props
   *    A context_properties object which defines properties of newly created
   *    context.
   * \param devs
   *    A \ref clxx::devices object which provides a list of (unique) devices
   *    or sub-devices for use with this context.
   * \param pfn_notify
   *    A callback function that can be registered by the application. This
   *    callback function will be used by the OpenCL implementation to report
   *    information on errors during context creation as well as errors that
   *    occur at runtime in this context. This callback function may be called
   *    asynchronously by the OpenCL implementation. It is the application’s
   *    responsibility to ensure that the callback function is thread-safe. The
   *    parameters to this callback function are:
   *      - \c errinfo is a pointer to an error string,
   *      - \c private_info and \c cb represent a pointer to binary data that
   *        is returned by the OpenCL implementation that can be used to log
   *        additional information helpful in debugging the error,
   *      - \c user_data is a pointer to user supplied data.
   * \param user_data
   *    Will be passed as the \c user_data argument when \c pfn_notify is
   *    called. \c user_data can be \c nullptr.
   *
   * In case of errors, this constructor may throw one of the exceptions
   * defined by \ref context_properties_fill_array() and \ref create_context().
   */ // }}}
  context(context_properties const& props, devices const& devs,
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info, size_t cb,
                            void* user_data) = nullptr,
          void* user_data = nullptr);
  /** // doc: context(props, dev_type, pfn_notify, user_data) {{{
   * \brief Constructor - create new OpenCL context (costly).
   *
   * This constructor calls \ref create_context_from_type() to create new
   * OpenCL context and stores the returned \c cl_context handle to the newly
   * created context object. It does not increment the reference count
   * internally, as it obtains from OpenCL a new context with reference count
   * set to 1.
   *
   * \param props
   *    A \ref context_properties object which defines properties of newly
   *    created context.
   * \param dev_type
   *     A bit-field that identifies the type of device, e.g. (combination of)
   *     \c device_type_t::cpu, \c device_type_t::gpu and so on. For the list
   *     of all valid device types see \ref device_type_t.
   * \param pfn_notify
   *    A callback function that can be registered by the application. This
   *    callback function will be used by the OpenCL implementation to report
   *    information on errors during context creation as well as errors that
   *    occur at runtime in this context. This callback function may be called
   *    asynchronously by the OpenCL implementation. It is the application’s
   *    responsibility to ensure that the callback function is thread-safe. The
   *    parameters to this callback function are:
   *      - \c errinfo is a pointer to an error string,
   *      - \c private_info and \c cb represent a pointer to binary data that
   *        is returned by the OpenCL implementation that can be used to log
   *        additional information helpful in debugging the error,
   *      - \c user_data is a pointer to user supplied data.
   * \param user_data
   *    Will be passed as the \c user_data argument when \c pfn_notify is
   *    called. \c user_data can be nullptr.
   *
   * In case of errors, this constructor may throw one of the exceptions
   * defined by \ref context_properties_fill_array() and
   * \ref create_context_from_type().
   */ // }}}
  context(context_properties const& props,
          device_type_t dev_type,
          void(*pfn_notify)(const char* errinfo,
                            const void* private_info,
                            size_t cb,
                            void* user_data) = nullptr,
          void* user_data = nullptr);
  /** // doc: context(rhs) {{{
   * \brief Copy constructor (reference copy).
   *
   * This constructor creates context object referring to the same OpenCL
   * context as \c rhs does. After that, the newly created (this) object and
   * the \c rhs hold \c cl_context handle to the same OpenCL context. The
   * reference count for this handle is increased by one during
   * copy-construction by performing an internal call to \ref retain_context().
   *
   * \param rhs
   *    Another context object to be assigned to this object.
   *
   * \throw uninitialized_context_error
   *    thrown when \c rhs is uninitialized.
   * \throw clerror_no<status_t::invalid_context>
   *    thrown when \c rhs holds a \c cl_context handle that is invalid.
   */ // }}}
  context(context const& rhs);
  /** // doc: ~context() {{{
   * \brief Destructor
   *
   * Internally decreases reference count for this context.
   */ // }}}
  virtual ~context() noexcept;
  /** // {{{
   * \brief Assignment operator
   *
   * \param rhs Another context object to be assigned to this object
   *
   *  This operation copies the \c cl_context handle held by \c rhs
   *  to \c this object and maintains reference counts appropriately. The
   *  reference count for handle originating from \c rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  identifier held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \return Reference to this object
   *
   * \throw uninitialized_context_error
   *    when the \c rhs object is in uninitialized state
   * \throw clerror_no<status_t::invalid_context>
   *    when the \c rhs holds invalid \c cl_context handle
   */ // }}}
  context& operator=(context const& rhs);
  /** // {{{
   * \brief Compare this context with another one
   *
   * \param rhs
   *    Another context object to be compared to \c this object.
   *
   * \return
   *    Returns \c true if both, \c this and \c rhs, refer to the same OpenCL
   *    context, or \c false otherwise.
   */ // }}}
  bool operator == (context const& rhs) const noexcept;
  /** // {{{
   * \brief Compare this context with another one
   *
   * \param rhs
   *    Another context object to be compared to \c this object.
   *
   * \return <tt>!(*this == rhs)</tt>
   */ // }}}
  bool operator != (context const& rhs) const noexcept;
  /** // {{{
   * \brief Assignment
   *
   *  This operation copies the \c cl_context handle held by \c rhs
   *  to \c this object and maintains reference count appropriately. The
   *  reference count for handle originating from \c rhs gets increased by
   *  one, as it acquires new user (\c this object). The reference count for
   *  handle held up to now by \c this object is decreased by one, as it is
   *  forgotten by one user (namely, by \c this object).
   *
   * \throw uninitialized_context_error
   *    when \c rhs is an uninitialized context object.
   * \throw clerror_no<status_t::invalid_context>
   *    when \c rhs holds a \c cl_context handle that is invalid.
   *
   */ // }}}
  void assign(context const& rhs);
  /** // {{{
   * \brief   Is this object properly initialized?
   *
   * \return  Returns \c true if \c this object is initialized or false
   *          otherwise.
   */ // }}}
  bool is_initialized() const noexcept
  {
    return (this->_ctx != NULL);
  }
  /** // doc: get_info() {{{
   * \brief Get certain context information from OpenCL platform layer.
   *
   * This function calls internally \c get_context_info().
   *
   * \param name
   *     An enumeration constant that specifies the information to query.
   *     It may be for example \ref context_info_t::reference_count,
   *     \ref context_info_t::num_devices and so on. The complete list of
   *     allowed parameter names may be found in \ref context_info_t..
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by \c value. This size
   *    must be greater than or equal to the size of return type as described
   *    in appropriate table in the OpenCL specification (see documentation of
   *    \ref get_context_info()).
   * \param value
   *    A pointer to memory where the appropriate result being queried is
   *    returned. If \c value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by \c value. If
   *    \c value_size_ret is NULL, it is ignored.
   *
   * In case of errors, this function throws one of the exceptions defined by
   * \ref get_context_info().
   */ // }}}
  void get_info(context_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // doc: get_reference_count() {{{
   * \brief   Get reference count for the OpenCL context referred to by
   *          \c this object.
   *
   * \return  The reference count for the OpenCL context referred to by
   *          \c this object as returned by
   *          get_context_info(this->_ctx, context_info_t::reference_count, ...)
   *
   * In case of errors, the method throws one of the exceptions defined
   * by \ref get_context_info().
   */ // }}}
  cl_uint get_reference_count() const;
  /** // doc: get_reference_count() {{{
   * \brief   Get the number of devices in context.
   *
   * \return  The number of devices in context, as returned by
   *          get_context_info(this->_ctx, context_info_t::num_devices, ...)
   *
   * In case of errors, the method throws one of the exceptions defined
   * by \ref get_context_info().
   */ // }}}
  cl_uint get_num_devices() const;
  /** // doc: get_devices() {{{
   * \brief Get the list of devices in context.
   *
   * \return A clxx::devices object with all devices in this context.
   *
   * The returned result contains devices as returned by the call
   * get_context_info(this->_ctx, context_info_t::devices, ...).
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_context_info().
   */ // }}}
  devices get_devices() const;
  /** // doc: get_properties() {{{
   * \brief Get context properties specified at context creation.
   *
   * \return Properties of this OpenCL context.
   *
   * In case of errors, this method throws one of the exceptions defined by
   * \ref get_context_info() or \ref context_properties_parse_array().
   */ // }}}
  context_properties get_properties() const;
};

} // end namespace clxx

#endif /* CLXX_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
