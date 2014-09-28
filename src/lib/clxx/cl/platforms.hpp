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

// clxx/cl/platforms.hpp

/** // doc: clxx/cl/platforms.hpp {{{
 * \file clxx/cl/platforms.hpp
 *
 * This file provides functions to retrieve platform identifiers (and platform
 * proxy objects) of (all) locally available OpenCL platforms.
 */ // }}}
#ifndef CLXX_CL_PLATFORMS_HPP_INCLUDED
#define CLXX_CL_PLATFORMS_HPP_INCLUDED

#include <clxx/cl/platform.hpp>
#include <CL/cl.h>
#include <vector>

namespace clxx {

/** // {{{ doc: platforms
 * \ingroup clxx_platform_layer
 * \brief Collection of clxx::platform objects.
 */ // }}}
typedef std::vector<platform> platforms;
/** \ingroup clxx_platform_layer */
/** @{ */
/** // {{{ doc: get_num_platforms()
 * \brief Get number of OpenCL platforms available locally.
 *
 * \return The number of available OpenCL platforms
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
cl_uint get_num_platforms();
/** // {{{ doc: get_platform_ids()
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
/** // {{{ doc: get_platform_ids()
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 * \return Vector of \c cl_platform_id identifiers.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
std::vector<cl_platform_id> get_platform_ids();
/** // {{{ doc: get_platforms()
 * \brief Get proxy platform objects for locally available OpenCL platforms.
 * \return platforms.
 *
 * \throws clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throws clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throws unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The \c clerror_no<status_t::invalid_value> should never appear in practice.
 * Otherwise the function is buggy.
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 */ // }}}
platforms get_platforms();
/** // {{{ doc: make_platforms(ids)
 * \brief Wrap platform identifiers with clxx::platform objects.
 * \param ids OpenCL platform identifiers
 * \return clxx::platforms a collection of platform objects for the given
 *         identifiers
 *
 * Occasionally, exceptions originating from \c std::vector may be raised, for
 * example \c std::bad_alloc. See documentation of the \c std::vector.
 *
 */ // }}}
platforms make_platforms(std::vector<cl_platform_id> const& ids);
/** @} */

} // end namespace clxx

#endif /* CLXX_PLATFORMS_HPP */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: