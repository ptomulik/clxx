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

// clxx/functions.hpp

/** // doc: clxx/functions.hpp {{{
 * \file clxx/functions.hpp
 * \brief Bare C++ wrappers around OpenCL functions.
 */ // }}}
#ifndef CLXX_FUNCTIONS_HPP_INCLUDED
#define CLXX_FUNCTIONS_HPP_INCLUDED

#include <clxx/types.hpp>

namespace clxx {

/** // {{{ doc: get_platform_ids(...)
 * \ingroup clxx_platform_layer
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 *
 * This function is a C++ wrapper for \c clGetPlatformIDs().
 *
 * \param num_entries
 *    The number of \c cl_platform_id entries that can be added to \c
 *    platforms. If \c platforms is not \c NULL, the \c num_entries must be
 *    greater than zero
 * \param platforms
 *    Returns a list of OpenCL platforms found. The \c cl_platform_id values
 *    returned in \c platforms can be used to identify a specific OpenCL
 *    platform. If platforms argument is \c NULL, this argument is ignored. The
 *    number ofOpenCL platforms returned is the mininum of the value specified
 *    by \c num_entries or the number of OpenCL platforms available
 * \param num_platforms
 *    Returns the number of OpenCL platforms available. If \c num_platforms is
 *    \c NULL, this argument is ignored
 * \return void
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
void get_platform_ids( cl_uint num_entries,
                       cl_platform_id* platforms,
                       cl_uint* num_platforms );

/** // doc: get_platform_info(...) {{{
 * \ingroup clxx_platform_layer
 *
 * \brief Query OpenCL platform layer for platform information.
 *
 * This function is a C++ wrapper for \c clGetGetPlatformInfo().
 *
 * \param platform
 *    The platform ID - one of these returned by clxx::get_platform_ids(),
 *    or can be NULL. If platform is NULL, the behavior is
 *    implementation-defined.
 * \param param_name
 *    An enumeration constant that identifies the platform information being
 *    queried. See \ref platform_info_t for details.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by \c param_value. This
 *    size in bytes must be ≥ size of return type specified in the OpenCL
 *    specification (\c clGetPlatformInfo()).
 * \param param_value
 *    A pointer to memory location where appropriate values for a given
 *    \c param_value will be returned. Possible \c param_value values returned
 *    are described in the OpenCL specification (\c clGetPlatformInfo()). If
 *    \c param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by \c param_value.
 *    If \c param_value_size_ret is \c NULL, it is ignored.
 *
 * \return void
 *
 * \throws clerror_no<status_t::invalid_platform>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_PLATFORM,
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformInfo() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformInfo() returns other status code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformInfo()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_info() has a bug.
 */ // }}}
void
get_platform_info(  cl_platform_id platform,
                    platform_info_t param_name,
                    size_t param_value_size,
                    void* param_value,
                    size_t* param_value_size_ret );

/** // doc: get_device_ids() {{{
 * \ingroup clxx_platform_layer
 * \brief Retrieve device identifiers of locally available OpenCL devices.
 *
 * This function is a C++ wrapper for \c clGetDeviceIDs(). The main difference
 * between clxx::get_device_ids() and \c clGetDeviceIDs() is that it throws
 * exceptions instead of returning error codes.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \b platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \b device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \b device_type are
 *        specified by clxx::device_type_t.
 * \param num_entries
 *        The number of \c cl_device_id entries that can be added to \b
 *        devices. If \b devices is not \c NULL, the \b num_entries must be
 *        greater than zero.
 * \param devices
 *        A list of OpenCL devices found. The \c cl_device_id values returned
 *        in \b devices can be used to identify a specific OpenCL device. If
 *        \b devices argument is \c NULL, this argument is ignored. The number
 *        of OpenCL devices returned is the minimum of the value specified by
 *        \b num_entries or the number of OpenCL devices whose type matches
 *        \b device_type.
 * \param num_devices
 *        Returns the number of OpenCL devices available. If \c num_devices is
 *        \c NULL, this argument is ignored.
 *
 * \return The number of available OpenCL devices
 *
 * \throws clerror_no<status_t::invalid_platform>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_PLATFORM,
 * \throws clerror_no<status_t::invalid_device_type>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_DEVICE_TYPE,
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_resources>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_RESOURCES,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetDeviceIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetDeviceIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_platform_ids() has a bug.
 */ // }}}
void get_device_ids(cl_platform_id platform, device_type_t device_type,
                    cl_uint num_entries, cl_device_id* devices,
                    cl_uint* num_devices);

/** // doc: get_device_info(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Get certain information from device.
 *
 * This is a wrapper around \c clGetDeviceInfo(). The call to this function
 * yields same information as call to
 *   - \c clGetDeviceInfo(device,name,value_size,value,value_size_ret).
 *
 * The main difference between clxx::get_device_info() and \c clGetDeviceInfo()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param device
 *    %device identifier of type cl_device_id.
 * \param name
 *    An enumeration constant that identifies the device information being
 *    queried. It can be one of the values as specified in the OpenCL
 *    specification (\c clGetDeviceInfo()).
 * \param value_size
 *    Specifies the size in bytes of memory pointed to by \c param_value.
 *    This size in bytes must be greater than or equal to size of return type
 *    specified in the OpenCL specification (\c clGetDeviceInfo()).
 * \param value
 *    A pointer to memory location where appropriate values for a given
 *    \c param_name as specified in the OpenCL specification
 *    (\c clGetDeviceInfo()) will be returned. If \c param_value is \c NULL, it
 *    is ignored.
 * \param value_size_ret
 *    Returns the actual size in bytes of data being queried by \c
 *    param_value. If \c param_value_size_ret is \c NULL, it is ignored
 *
 * \throws  clxx::clerror_no<clxx::status_t::invalid_device>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_DEVICE,
 * \throws  clxx::clerror_no<clxx::status_t::invalid_value>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_VALUE,
 * \throws  clxx::clerror_no<clxx::status_t::out_of_resources>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_RESOURCES,
 * \throws  clxx::clerror_no<clxx::status_t::out_of_host_memory>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throws  clxx::unexpected_clerror
 *    when \c clGetDeviceInfo() returns any other error code.
 *
 */ // }}}
void
get_device_info( cl_device_id device, device_info_t name, size_t value_size,
                 void* value, size_t* value_size_ret);

/** // doc: create_context(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Create OpenCL context
 *
 * This is a wrapper around \c clCreateContext(). The call to this function has
 * same effect as call to
 *   - \c clCreateContext(properties,num_devices,devices,pfn_notify,user_data,errcode_ret)
 *
 * The main difference between clxx::create_context() and \c clCreateContext()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param properties
 *    Specifies a list of context property names and their corresponding
 *    values. Each property name is immediately followed by the corresponding
 *    desired value. The list is terminated with \c 0. **properties** can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param num_devices
 *    The number of devices specified in **devices** argument.
 * \param devices
 *    A pointer to a list of unique devices returned by \ref get_device_ids()
 *    or sub-devices created by \ref create_sub_devices().
 * \param pfn_notify
 *    A callback function that can be registered by the application. This
 *    callback function will be used by the OpenCL implementation to report
 *    information on errors during context creation as well as errors that
 *    occur at runtime in this context. This callback function may be called
 *    asynchronously by the OpenCL implementation. It is the application's
 *    responsibility to ensure that the callback function is thread-save. If
 *    **pfn_notify** is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when **pfn_notify** is called.
 *    **user_data** can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the **pfn_notify** callback.
 *    Where these notification go is implementation-defined.
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clCreateContext() returns error \c CL_INVALID_PLATFORM
 * \throw clerror_no<status_t::invalid_property>
 *    When \c clCreateContext() returns error \c CL_INVALID_PROPERTY
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateContext() returns error \c CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateContext() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateContext() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::device_not_available>
 *    When \c clCreateContext() returns error \c CL_DEVICE_NOT_AVAILABLE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateContext() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateContext() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
 * \throw clerror_no<status_t::invalid_dx9_media_adapter_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_DX9_MEDIA_ADAPTER_KHR
 * \throw clerror_no<status_t::invalid_d3d10_device_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_D3D10_DEVICE_KHR
 * \throw clerror_no<status_t::invalid_d3d11_device_khr>
 *    When \c clCreateContext() returns error \c CL_INVALID_D3D11_DEVICE_KHR
 * \throw unexpected_clerror
 *    When \c clCreateContext() returns other error code.
 */ // }}}
cl_context create_context(const cl_context_properties* properties,
               cl_uint num_devices, const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data);

/** // doc: create_context_from_type_from_type(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Create OpenCL context
 *
 * This is a wrapper around \c clCreateContextFromType(). The call to this function has
 * same effect as call to
 *   - \c clCreateContextFromType(properties,static_cast<cl_device_type>(device_type),pfn_notify,user_data,errcode_ret)
 *
 * The main difference between clxx::create_context_from_type() and
 * \c clCreateContextFromType() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param properties
 *    Specifies a list of context property names and their corresponding
 *    values. Each property name is immediately followed by the corresponding
 *    desired value. The list is terminated with \c 0. **properties** can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param device_type
 *    A bit-field that identifies the type of device, see \ref device_type_t.
 * \param pfn_notify
 *    A callback function that can be registered by the application. This
 *    callback function will be used by the OpenCL implementation to report
 *    information on errors during context creation as well as errors that
 *    occur at runtime in this context. This callback function may be called
 *    asynchronously by the OpenCL implementation. It is the application's
 *    responsibility to ensure that the callback function is thread-save. If
 *    **pfn_notify** is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when **pfn_notify** is called.
 *    **user_data** can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the **pfn_notify** callback.
 *    Where these notification go is implementation-defined.
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_PLATFORM
 * \throw clerror_no<status_t::invalid_property>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_PROPERTY
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::device_not_available>
 *    When \c clCreateContextFromType() returns error \c CL_DEVICE_NOT_AVAILABLE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateContextFromType() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateContextFromType() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw clerror_no<status_t::invalid_gl_sharegroup_reference_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_GL_SHAREGROUP_REFERENCE_KHR
 * \throw clerror_no<status_t::invalid_dx9_media_adapter_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_DX9_MEDIA_ADAPTER_KHR
 * \throw clerror_no<status_t::invalid_d3d10_device_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_D3D10_DEVICE_KHR
 * \throw clerror_no<status_t::invalid_d3d11_device_khr>
 *    When \c clCreateContextFromType() returns error \c CL_INVALID_D3D11_DEVICE_KHR
 * \throw unexpected_clerror
 *    When \c clCreateContextFromType() returns other error code.
 */ // }}}
cl_context create_context_from_type(const cl_context_properties* properties,
               device_type_t device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data);

/** // doc: retain_context(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Increment the context reference count
 *
 * This is a wrapper around \c clRetainContext(). The call to this function has
 * same effect as call to
 *  - \c clRetainContext(context)
 *
 * The difference between \ref retain_context() and \c clRetainContext() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    The OpenCL context to retain.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clRetainContext() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainContext() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainContext() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clRetainContext() returns other error code.
 *
 * \note \ref create_context() and \ref create_context_from_type() perform an
 *    implicit retain.
 */ // }}}
void retain_context(cl_context context);

/** // doc: release_context(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Decrement the context reference count
 *
 * This is a wrapper around \c clReleaseContext(). The call to this function has
 * same effect as call to
 *  - \c clReleaseContext(context)
 *
 * The difference between \ref release_context() and \c clReleaseContext() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    The OpenCL context to release.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clReleaseContext() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseContext() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseContext() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clReleaseContext() returns other error code.
 *
 */ // }}}
void release_context(cl_context context);

/** // doc: get_context_info(...) {{{
 * \ingroup clxx_platform_layer
 * \brief Query information about a context.
 *
 * This is a wrapper for \c clGetContextInfo(). The call to \ref
 * get_context_info() has same effect as a call to
 *    - \c clGetContextinfo(context,static_cast<cl_context_info>(param_name),param_value_size,param_value,param_value_size_ret)
 *
 *  The main difference between get_context_info() and \c clGetContextInfo() is
 *  that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    Specifies the OpenCl context being queried.
 * \param param_name
 *    An enumeration constant that specifies the information to query. See \ref
 *    context_info_t.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by **param_value**. This
 *    size must be grater than or equal to the size of return type for
 *    **param_name** as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. if *param_value* is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    **param_value**. If **param_value_size_ret** is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clGetContextInfo() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetContextInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetContextInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetContextInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetContextInfo() returns other error code.
 */ // }}}
void get_context_info(cl_context context, context_info_t param_name,
                      size_t param_value_size, void* param_value,
                      size_t* param_value_size_ret);
} // end namespace clxx

#endif /* CLXX_FUNCTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
