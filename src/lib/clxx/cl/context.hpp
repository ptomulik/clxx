// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/cl/context.hpp

/** // doc: clxx/cl/context.hpp {{{
 * \file clxx/cl/context.hpp
 * \brief Defines the \ref clxx::context "context" class
 */ // }}}
#ifndef CLXX_CL_CONTEXT_HPP_INCLUDED
#define CLXX_CL_CONTEXT_HPP_INCLUDED

#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/context_properties.hpp>
#include <clxx/cl/devices.hpp>
#include <clxx/cl/clobj.hpp>

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
 * \c cl_context handle (get(), chk_get()). This gives rise to manipulate
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
class alignas(cl_context) context
  : public clobj<cl_context>
{
public:
  /** // doc: Base {{{
   * \brief Typedef for the base class type
   */ // }}}
  typedef clobj<cl_context> Base;
  using Base::Base;
  /** // doc: context() {{{
   * \brief Default constructor, see \ref clobj::clobj()
   */ // }}}
  context() = default;
  /** // doc: context() {{{
   * \brief Copy constructor, see \ref clobj::clobj(clobj const&)
   */ // }}}
  context(context const&) = default;
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
  /** // doc: get_reference_count() {{{
   * \brief   Get the number of devices in context.
   *
   * \return  The number of devices in context, as returned by
   *          get_context_info(this->_id, context_info_t::num_devices, ...)
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
   * get_context_info(this->_id, context_info_t::devices, ...).
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

#include <vector>
namespace clxx {
/** // doc: contexts {{{
 * \brief Sequence of \ref clxx::context "context"s
 *
 * It's basically same as std::vector<clxx::context>.
 */ // }}}
typedef std::vector<context> contexts;
} // end namespace clxx

#endif /* CLXX_CL_CONTEXT_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
