// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/functions.hpp

/** // doc: clxx/functions.hpp {{{
 * \file clxx/functions.hpp
 * \brief Bare C++ wrappers around OpenCL functions.
 */ // }}}
#ifndef CLXX_FUNCTIONS_HPP_INCLUDED
#define CLXX_FUNCTIONS_HPP_INCLUDED

#include <clxx/types.hpp>

namespace clxx {

/** \ingroup clxx_cl_functions
 *  @{ */
/** // {{{ doc: get_platform_ids(...)
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void get_platform_ids( cl_uint num_entries,
                       cl_platform_id* platforms,
                       cl_uint* num_platforms );

/** // doc: get_platform_info(...) {{{
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void
get_platform_info(  cl_platform_id platform,
                    platform_info_t param_name,
                    size_t param_value_size,
                    void* param_value,
                    size_t* param_value_size_ret );

/** // doc: get_device_ids() {{{
 * \brief Retrieve device identifiers of locally available OpenCL devices.
 *
 * This function is a C++ wrapper for \c clGetDeviceIDs(). The main difference
 * between clxx::get_device_ids() and \c clGetDeviceIDs() is that it throws
 * exceptions instead of returning error codes.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \e platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \e device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \e device_type are
 *        specified by clxx::device_type_t.
 * \param num_entries
 *        The number of \c cl_device_id entries that can be added to \e
 *        devices. If \e devices is not \c NULL, the \e num_entries must be
 *        greater than zero.
 * \param devices
 *        A list of OpenCL devices found. The \c cl_device_id values returned
 *        in \e devices can be used to identify a specific OpenCL device. If
 *        \e devices argument is \c NULL, this argument is ignored. The number
 *        of OpenCL devices returned is the minimum of the value specified by
 *        \e num_entries or the number of OpenCL devices whose type matches
 *        \e device_type.
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void get_device_ids(cl_platform_id platform, device_type_t device_type,
                    cl_uint num_entries, cl_device_id* devices,
                    cl_uint* num_devices);

/** // doc: get_device_info(...) {{{
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
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void
get_device_info( cl_device_id device, device_info_t name, size_t value_size,
                 void* value, size_t* value_size_ret);

/** // doc: create_context(...) {{{
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
 *    desired value. The list is terminated with \c 0. \e properties can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param num_devices
 *    The number of devices specified in \e devices argument.
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
 *    \e pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \e pfn_notify is called.
 *    \e user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \e pfn_notify callback.
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
cl_context create_context(const cl_context_properties* properties,
               cl_uint num_devices, const cl_device_id* devices,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data);

/** // doc: create_context_from_type_from_type(...) {{{
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
 *    desired value. The list is terminated with \c 0. \e properties can be
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
 *    \e pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \e pfn_notify is called.
 *    \e user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \e pfn_notify callback.
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
cl_context create_context_from_type(const cl_context_properties* properties,
               device_type_t device_type,
               void(*pfn_notify)(const char* errinfo, const void* private_info,
                                 size_t cb, void* user_data),
               void* user_data);

/** // doc: retain_context(...) {{{
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void retain_context(cl_context context);

/** // doc: release_context(...) {{{
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
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void release_context(cl_context context);

/** // doc: get_context_info(...) {{{
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
 *    Specifies the size in bytes of memory pointed to by \e param_value. This
 *    size must be grater than or equal to the size of return type for
 *    \e param_name as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. if *param_value* is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    \e param_value. If \e param_value_size_ret is \c NULL, it is ignored.
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
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void get_context_info(cl_context context, context_info_t param_name,
                      size_t param_value_size, void* param_value,
                      size_t* param_value_size_ret);
#if HAVE_OPENCL_clCreateSubDevices
/** // doc: create_sub_devices(...) {{{
 * \brief Creates an array of sub-devices that each reference
 *    a non-intersecting set of compute units within \e in_device.
 *
 * This function is a wrapper around \c clCreateSubDevices(). The main
 * difference between \ref create_sub_devices() and \c clCreateSubDevices() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param in_device
 *    The device to be partitioned
 * \param properties
 *    Specifies how \e in_device is to be partition described by a partition
 *    name and its corresponding value. Each partition name is immediately
 *    followed by the corresponding desired value. The list is terminated with
 *    0. The list of supported partitioning schemes is described by the OpenCL
 *    standard (ver. 1.2 and later), see documentation for
 *    \c clCreateSubDevices().
 * \param num_devices
 *    Size of memory pointed to by **out_devices&& specified as the number of
 *    \c cl_device_id entries.
 * \param out_devices
 *    The buffer where OpenCL sub-devices will be returned. If \e out_devices
 *    is \c NULL, this argument is ignored. If \e out_devices is not \c NULL,
 *    \e num_devices must be greater than or equal to the number of
 *    sub-devices than \e in_device may be partitioned into according to the
 *    partitioning scheme specified in \e properties.
 * \param num_devices_ret
 *    Returns the number of sub-devices that device may be partitioned into
 *    according to the partitioning scheme specified in \e properties. If
 *    \e num_devices_reg is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateSubDevices() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateSubDevices() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::device_partition_failed>
 *    When \c clCreateSubDevices() returns CL_DEVICE_PARTITION_FAILED.
 * \throw clerror_no<status_t::invalid_device_partition_count>
 *    When \c clCreateSubDevices() returns CL_INVALID_DEVICE_PARTITION_COUNT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateSubDevices() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateSubDevices() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateSubDevices() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * |         |         | &radic; |         |
 */ // }}}
void create_sub_devices(cl_device_id in_device,
                        const cl_device_partition_property* properties,
                        cl_uint num_devices,
                        cl_device_id* out_devices,
                        cl_uint *num_devices_ret);
#endif
#if HAVE_OPENCL_clRetainDevice
/** // doc: retain_device(...) {{{
 * \brief Increments the \e devices reference count
 *
 * This function is a wrapper around \c clRetainDevice(). The call to this
 * function has same effect as
 *  - \c clRetainDevice(device)
 *
 * The main difference between \ref retain_device() and
 * \c clRetainDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function increments the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param device
 *    The device to be retained
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clRetainDevice() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainDevice() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainDevice() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainDevice() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * |         |         | &radic; |         |
 */ // }}}
void retain_device(cl_device_id device);
#endif
#if HAVE_OPENCL_clReleaseDevice
/** // doc: release_device(...) {{{
 * \brief Decrements the \e devices reference count
 *
 * This function is a wrapper around \c clReleaseDevice(). The call to this
 * function has same effect as
 *  - \c clReleaseDevice(device)
 *
 * The main difference between \ref release_device() and
 * \c clReleaseDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function decrements the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param device
 *    The device to be released
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clReleaseDevice() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseDevice() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseDevice() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseDevice() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * |         |         | &radic; |         |
 */ // }}}
void release_device(cl_device_id device);
#endif
/** // doc: create_program_with_source(...) {{{
 * \brief Creates a program object for a context, and loads the source
 *    code specified by the text strings in the \e strings array into the program
 *    object.
 *
 * This function is a wrapper around \c clCreateProgramWithSource(). The call
 * to this function has same effect as
 *  - \c clCreateProgramWithSource(context, count, strings, lengths, &errcode_ret)
 * with \c errcode_ret defined internally in create_program_with_source().
 *
 * The main difference between \ref create_program_with_source() and
 * \c clCreateProgramWithSource() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * This function creates a program object for a context, and loads the source
 * code specified by the text strings in the \e strings array into the program
 * object. The devices associated with the program object are the devices
 * associated with \e context. The source code specified by \e strings is
 * either an OpenCL C program source, header or implementation-defined source
 * for custom devices that support an online compiler.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param count
 *    Number of elements in \e strings and \e lengths.
 * \param strings
 *    An array of \e count pointers to optionally null-terminated character
 *    strings that make up the source code.
 * \param lengths
 *    An array with the number of chars in each string (the string length). I
 *    an element in lengths i zero, its accompanuing string is null-terminated.
 *    If \e lengths is NULL, all strings in the \e strings argument are
 *    considered null-terminated. Any length value passed in that is greater
 *    than zero excludes the null terminator in its count.
 *
 * \returns
 *    A valid non-zero program object if the program object is created
 *    successfully (otherwise it throws an exception).
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithSource() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
cl_program create_program_with_source(cl_context context,
                                      cl_uint count,
                                      const char** strings,
                                      const size_t* lengths);
/** // doc: create_program_with_binary(...) {{{
 * \brief Creates a program object for a context, and loads the binary bits
 *    specified by binary into the program object
 *
 * This function is a wrapper around \c clCreateProgramWithBinary(). The call
 * to this function has same effect as
 *  - \c clCreateProgramWithBinary(context, num_devices, device_list, lengths, binaries, binary_status, &errcode_ret)
 * with \c errcode_ret defined internally in create_program_with_binary().
 *
 * The main difference between \ref create_program_with_binary() and
 * \c clCreateProgramWithBinary() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * OpenCL allows applications to create a program object using the program
 * source or binary and build appropriate program executables. This can be very
 * useful as it allows applications to load program source and then compile and
 * link to generate a program executable online on its first instance for
 * appropriate OpenCL devices in the system. These executables can now be
 * queried and cached by the application. Future instances of the application
 * launching will no longer need to compile and link the program executables.
 * The cached executables can be read and loaded by the application, which can
 * help significantly reduce the application initialization time. 
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 *    The devices associated with the program object will be the list of
 *    devices specified by \e device_list. The list of devices specified by \e
 *    device_list must be devices associated with context.
 * \param device_list
 *    A pointer to a list of devices that are in \e context. \c device_list
 *    must be a non-NULL value. The binaries are loaded for devices specified
 *    in this list.
 * \param lengths
 *    Lengths of the \e binaries arrays. For each \c i \e lengths[i] defines
 *    length of \e binaries[i] array.
 * \param binaries
 *    An array of pointers to program binaries to be loaded for devices
 *    specified by \e device_list. For each device given by \e device_list[i],
 *    the pointer to the program binary for that device is given by
 *    \e binaries[i] and the length of this corresponding binary is given by
 *    \e lengths[i]. \e lengths[i] cannot be zero and \e binaries[i] cannot be
 *    a NULL pointer. The program binaries specified by binaries contain the
 *    bits that describe one of the following:
 *      - a program executable to be run on the device(s) associated with \e context.
 *      - a compiled program for \e device(s) associated with context.
 *      - a library of compiled programs for \e device(s) associated with context.
 *    The program binary can consist of either or both of device-specific code
 *    and/or implementation-specific intermediate representation (IR) which
 *    will be converted to the device-specific code.
 * \param binary_status
 *    Returns whether the program binary for each device specified in
 *    device_list was loaded successfully or not. It is an array of
 *    \e num_devices entries and returns \c CL_SUCCESS in \e binary_status[i]
 *    if binary was successfully loaded for device specified by \e device_list[i];
 *    otherwise returns CL_INVALID_VALUE if \e lengths[i] is zero or if
 *    \e binaries[i] is a \c NULL value or \c CL_INVALID_BINARY in
 *    \e binary_status[i] if program binary is not a valid binary for the
 *    specified device. If \e binary_status is \c NULL, it is ignored.
 *
 * \returns
 *    A valid non-zero program object if the program object is created
 *    successfully (otherwise it throws an exception).
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_binary>
 *    When \c clCreateProgramWithSource() returns CL_INVALID_BINARY.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithSource() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithSource() returns other error code.
 *
 * \note This function throws <tt>clerror_no<status_t::invalid_binary></tt>
 *    if any of the provided binaries is invalid. Before raising the exception,
 *    the array pointed to by \e binary_status gets filled with error
 *    information. To ensure that storage for \e binary_status is maintained
 *    properly and does not go out of scope when exception is caught or
 *    propagated, the following (or similar) code pattern should be used
 *    \code
 *      cl_int binary_status[SIZE]; // the array declared in the outer scope
 *      cl_program program = NULL;
 *      try {
 *        program = create_program_with_binary( ..., binary_status );
 *      } catch(clerror_no<status_t::invalid_binary> const& e) {
 *        // scan binary_status to find out which binary caused the problem ...
 *      }
 *    \endcode
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
cl_program create_program_with_binary(cl_context context,
                                      cl_uint num_devices,
                                      const cl_device_id* device_list,
                                      const size_t* lengths,
                                      const unsigned char** binaries,
                                      cl_int* binary_status);
#if HAVE_OPENCL_clCreateProgramWithBuiltInKernels
/** // doc: create_program_with_built_in_kernels(...) {{{
 * \brief  Creates a program object for a context, and loads the information
 * related to the built-in kernels into a program object. 
 *
 * This function is a wrapper around \c clCreateProgramWithBuiltInKernels().
 * The call to this function has same effect as
 *  - \c clCreateProgramWithBuiltInKernels(context, num_devices, device_list, kernel_names, &errcode_ret)
 *
 * with \c errcode_ret defined internally in create_program_with_built_in_kernels().
 *
 * The main difference between \ref create_program_with_built_in_kernels() and
 * \c clCreateProgramWithBuiltInKernels() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function decrements the \e device reference count if \e device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \e device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \e device reference count remains unchanged.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \e device_list.
 * \param device_list
 *    A pointer to a list of devices that are in \e context. \e device_list
 *    must be a non-NULL value. The built-in kernels are loaded for devices
 *    specified in this list. The devices associated with the program object
 *    will be the list of devices specified by \e device_list. The list of
 *    devices specified by device_list must be devices associated with context.
 * \param kernel_names
 *    A semi-colon separated list of built-in kernel names.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithBuiltInKernels() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithBuiltInKernels() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * |         |         | &radic; |         |
 */ // }}}
cl_program create_program_with_built_in_kernels(cl_context context,
                                                cl_uint num_devices,
                                                const cl_device_id* device_list,
                                                const char* kernel_names);
#endif
/** // doc: retain_program(...) {{{
 * \brief Increments the \e program reference count
 *
 * This function is a wrapper around \c clRetainProgram(). The call to this
 * function has same effect as
 *  - \c clRetainProgram(program)
 *
 * The main difference between \ref retain_program() and
 * \c clRetainProgram() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * \note create_program_with_source(), create_program_with_binary() and
 *    create_program_with_built_in_kernels() does an implicit retain. The same
 *    applies to \c clCreateProgramXyz() functions.
 *
 * \param program
 *    The program to be retained
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clRetainProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void retain_program(cl_program program);
/** // doc: release_program(...) {{{
 * \brief Decrements the \e program reference count
 *
 * This function is a wrapper around \c clReleaseProgram(). The call to this
 * function has same effect as
 *  - \c clReleaseProgram(program)
 *
 * The main difference between \ref release_program() and
 * \c clReleaseProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The program object is deleted after all kernel objects associated with
 *    program have been deleted and the program reference count becomes zero.
 *
 * \param program
 *    The program to be released
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clReleaseProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseProgram() returns other error code.
 *
 * \par Available in OpenCL versions
 * |   1.0   |   1.1   |   1.2   |   2.0   |
 * | ------- | ------- | ------- | ------- |
 * | &radic; | &radic; | &radic; |         |
 */ // }}}
void release_program(cl_program program);
/** @} */
} // end namespace clxx

#endif /* CLXX_FUNCTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
