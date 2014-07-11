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

// clxx/cl/mocks/corner.hpp

/** // doc: clxx/cl/mocks/corner.hpp {{{
 * \file clxx/cl/mocks/corner.hpp
 *
 * This file implements OpenCL mocks emulating several corner cases, such as
 * memory allocation errors.
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 */ // }}}
#ifndef CLXX_CL_MOCKS_CORNER_HPP_INCLUDED
#define CLXX_CL_MOCKS_CORNER_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)
namespace T {
/** // doc: ErrRet_clGetPlatformIDs {{{
 * \brief Mock for clGetPlatformIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class ErrRet_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs
{
  cl_int _err;
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint* num_platforms);
public:
  ErrRet_clGetPlatformIDs(cl_int err);
};
/** // doc: ErrRet_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class ErrRet_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo
{
  cl_int _err;
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  ErrRet_clGetPlatformInfo(cl_int err);
};
/** // doc: ErrRet_clGetDeviceIDs {{{
 * \brief Mock for clGetDeviceIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class ErrRet_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs
{
  cl_int _err;
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint* num_devices);
public:
  ErrRet_clGetDeviceIDs(cl_int err);
};
/** // doc: ErrRet_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class ErrRet_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo
{
  cl_int _err;
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  ErrRet_clGetDeviceInfo(cl_int err);
};
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {

cl_int ErrRet_clGetPlatformIDs::
clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  (void) num_entries;         /* prevent 'unused parameter' warning */
  (void) platforms;           /* prevent 'unused parameter' warning */
  (void) num_platforms;       /* prevent 'unused parameter' warning */
  return this->_err;
}
ErrRet_clGetPlatformIDs::
ErrRet_clGetPlatformIDs(cl_int err)
  : _err(err)
{
}

cl_int ErrRet_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)platform;             /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return this->_err;
}
ErrRet_clGetPlatformInfo::
ErrRet_clGetPlatformInfo(cl_int err)
  : _err(err)
{
}

cl_int ErrRet_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
{
  (void) platform;            /* prevent 'unused parameter' warning */
  (void) device_type;         /* prevent 'unused parameter' warning */
  (void) num_entries;         /* prevent 'unused parameter' warning */
  (void) devices;             /* prevent 'unused parameter' warning */
  (void) num_devices;         /* prevent 'unused parameter' warning */
  return this->_err;
}
ErrRet_clGetDeviceIDs::
ErrRet_clGetDeviceIDs(cl_int err)
  : _err(err)
{
}

cl_int ErrRet_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  (void)device;               /* prevent 'unused parameter' warning */
  (void)param_name;           /* prevent 'unused parameter' warning */
  (void)param_value_size;     /* prevent 'unused parameter' warning */
  (void)param_value;          /* prevent 'unused parameter' warning */
  (void)param_value_size_ret; /* prevent 'unused parameter' warning */
  return this->_err;
}
ErrRet_clGetDeviceInfo::
ErrRet_clGetDeviceInfo(cl_int err)
  : _err(err)
{
}
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* CLXX_CL_MOCKS_CORNER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
