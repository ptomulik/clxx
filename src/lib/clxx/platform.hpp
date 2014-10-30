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

// clxx/platform.hpp

/** // doc: clxx/platform.hpp {{{
 * \file clxx/platform.hpp
 * \brief Provides the clxx::platform and clxx::get_platform_info().
 *
 * This file contains clxx::platform class (OpenCL platform proxy object),
 * which provides access to OpenCL platform information.
 *
 */ // }}}
#ifndef CLXX_PLATFORM_HPP_INCLUDED
#define CLXX_PLATFORM_HPP_INCLUDED

#include <clxx/types.hpp>
#include <string>

namespace clxx {

/** // {{{ doc: platform
 * \ingroup clxx_platform_layer
 * \brief OpenCL platform proxy
 *
 * This class provides access to OpenCL platform information, equivalent to
 * OpenCL's \c clGetPlatformInfo(), but:
 *
 * - it has easy to use, type-safe c++ interface,
 * - returns \c std::string instead of plain \c char* data,
 * - replaces OpenCL error codes with exceptions (see \ref clxx_exceptions),
 *
 * The object is lightweight. It encapsulates only a single \c cl_platform_id
 * identifier.
 *
 * The class has non-virtual destructor to not bloat the objects with virtual
 * tables. It should not be used as a base class.
 *
 * 
 * \par Example:
 * Simple functor to print platform info:
 * \snippet platform1.cpp DumpPlatform
 *
 */ // }}}
class platform
{
private:
  cl_platform_id _platform_id;
public:
  /** // {{{
   * \brief Defalt constructor
   *
   * Sets underlying platform ID to NULL, so the proxy object is regarder
   * uninitialized (is_initialized() returns \c false).
   */ // }}}
  platform() noexcept
    : _platform_id(nullptr)
  {
  }
  /** // {{{
   * \brief Copy constructor
   *
   * Initializes this object with the platform ID of another one (\c rhs).
   */ // }}}
  platform(platform const& rhs) noexcept
    : _platform_id(rhs.id())
  {
  }
  /** // {{{
   * \brief Constructor with explicit conversion.
   *
   * Initializes this object with platform ID provided by caller.
   */ // }}}
  explicit platform(cl_platform_id platid) noexcept
    : _platform_id(platid)
  {
  }
  /** // {{{
   * \brief Desctructor
   */ // }}}
  ~platform() noexcept { }
  /** // {{{
   * \brief Assignment operator.
   * \return Reference to this object.
   */ // }}}
  platform& operator=(platform const& rhs) noexcept
  {
    this->assign(rhs);
    return *this;
  }
  /** // {{{
   * \brief Conversion operator.
   * \return %platform ID keept by this proxy object.
   *
   * Casts platform object to \c cl_platform_id.
   */ // }}}
  explicit operator cl_platform_id () const
  {
    return this->id();
  }
  /** // {{{
   * \brief Assignment
   *
   * Assign new platform ID to this proxy object (start proxying to another
   * OpenCL platform).
   */ // }}}
  void assign(platform const& rhs) noexcept
  {
    if(&rhs != this)
      {
        this->_platform_id = rhs.id();
      }
  }
  /** // {{{
   * \brief Tell whether this object is initialised or not
   * \return \c true if object is initialised or \c false otherwise
   */ // }}}
  bool is_initialized() const noexcept
  {
    return (this->_platform_id != NULL);
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform.
   * \return The platform ID of this platform
   */ // }}}
  cl_platform_id id() const
  {
    return this->_platform_id;
  }
  /** // {{{
   * \brief Get the OpenCL platform ID of this platform
   * \return The platform ID of this platform
   *
   * This function also checks, if the platform ID is not NULL (proxy
   * initialized). If it is NULL, then the exception
   * CLXX_EXCEPTION(Uninitialized_Platform) is thrown.
   */ // }}}
  cl_platform_id get_valid_id() const;
  /** // {{{
   * \brief Query OpenCL platform for certain information.
   *
   * \param name
   *    An enumeration constant that identifies the platform information being
   *    queried. It may be \c CL_PLATFORM_PROFILE, \c CL_PLATFORM_VERSION, and
   *    so on. See OpenCL specification (\c clGetPlatformInfo()) for details.
   * \param value_size
   *    Specifies the size in bytes of memory pointed to by param_value. This
   *    size in bytes must be ≥ size of return type specified in the OpenCL
   *    specification (\c clGetPlatformInfo()).
   * \param value
   *    A pointer to memory location where appropriate values for a given
   *    param_value will be returned. Possible param_value values returned are
   *    described in the OpenCL specification (\c clGetPlatformInfo()). If
   *    param_value is NULL, it is ignored.
   * \param value_size_ret
   *    Returns the actual size in bytes of data being queried by param_value.
   *    If param_value_size_ret is NULL, it is ignored.
   *
   * This function maps directly to \c clGetGetPlatformInfo(). The platform ID
   * encapsulated by this proxy object is used as first argument to \c
   * clGetPlatformInfo().
   *
   * If this object holds uninitialized platform ID, then the method throws
   * exception CLXX_EXCEPTION(Uninitialized_Platform).
   *
   */ // }}}
  void get_info(platform_info_t name, size_t value_size, void* value,
                size_t* value_size_ret) const;
  /** // {{{
   * \brief Query the OpenCL for platform profile string.
   *
   * \return The profile name for this platform.
   *
   * This method returns the profile name supported by the implementation.
   * The profile name returned can be one of the following strings:
   * - \c FULL_PROFILE, if the implementation supports the OpenCL
   *   specification (functionality defined as part of the core specification
   *   and does not require any extensions to be supported)
   * - \c EMBEDDED_PROFILE, if the implementation supports the OpenCL
   *   embedded profile. The embedded profile is defined to be a subset
   *   for each version of OpenCL.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS.
   */ // }}}
  std::string get_profile() const;
  /** // {{{
   * \brief Query the OpenCL for platform version string
   * \return OpenCL platform version string.
   *
   * This method returns the OpenCL version supported by the implementation.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VERSION,...)
   * According to OpenCL specification, this version string has the
   * following format:
     \verbatim OpenCL<space><major_version.minor_version><space><platform-specific information> \endverbatim
   * For example, in OpenCL 1.2 the \c major_version.minor_version value
   * returned will be \c 1.2.
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_version() const;
  /** // {{{
   * \brief Query the OpenCL for platform name string.
   * \return The platform name string.
   *
   * This method returns the name of this OpenCL platform.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_NAME,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_name() const;
  /** // {{{
   * \brief Query the OpenCL for platform vendor string
   * \return The platform vendor string.
   *
   * This method returns vendor string shown by this OpenCL platform.
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_VENDOR,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_vendor() const;
  /** // {{{
   * \brief Query the OpenCL for platform extensions string
   * \return Space separated list of platform extension names
   *
   * This method returns a space separated list of extension names (the
   * extension names themselves do not contain any spaces) supported by
   * the platform. Extensions defined here must be supported by all devices
   * associated with this platform.
   *
   * The returned string is same as that returned by
   * \c clGetPlatformInfo(this->id(),CL_PLATFORM_EXTENSIONS,...)
   *
   * In case of error, this method throws one of the exceptions mentioned in
   * CLXX_PLATFORM_GET_INFO_EXCEPTIONS, or the
   * CLXX_EXCEPTION(Bad_Alloc).
   */ // }}}
  std::string get_extensions() const;
};
} // end namespace clxx

#include <clxx/info/platform_info.hpp>
#include <clxx/info/platform_query.hpp>

namespace clxx {
/** // doc: query_platform_info(platform, query) {{{
 * \todo Write documentation
 */ // }}}
platform_info
query_platform_info( platform const& platform,
                     platform_query const& query = platform_query() );
} // end namespace clxx

#endif /* CLXX_PLATFORM_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
