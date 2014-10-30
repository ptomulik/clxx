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
/** // {{{
 * \ingroup clxx_platform_layer
 * \brief Get certain information from device.
 *
 * This is a wrapper around \c clGetDeviceInfo(). The call to this function
 * yields same information as call to 
 *   - \c clGetDeviceInfo(device,name,value_size,value,value_size_ret).
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
/** // {{{ doc: get_platform_ids()
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

/** // {{{
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
} // end namespace clxx

#endif /* CLXX_FUNCTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
