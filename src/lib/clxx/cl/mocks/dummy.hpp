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

// clxx/cl/mocks/dummy.hpp

/** // doc: clxx/cl/mocks/dummy.hpp {{{
 * \file clxx/cl/mocks/dummy.hpp
 *
 * This file implements OpenCL mocks emulating several dummy cases, such as
 * memory allocation errors.
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 */ // }}}
#ifndef CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED
#define CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)

#include <tuple>
#include <vector>
#include <cstring>

namespace T {
/** // doc: Dummy_CallArgs {{{
 * \todo Write documentation
 */ // }}}
template<class... Args>
class Dummy_CallArgs
{
public:
  typedef std::tuple<Args...> args_tuple;
  inline void reset() { _calls.clear(); }

  // return the calls
  inline std::vector<args_tuple> const& calls() const { return _calls; }

  // mock tests
  inline bool never_called() const noexcept
  { return _calls.size() == 0ul; }
  inline bool called_once() const noexcept
  { return _calls.size() == 1ul; }
  inline bool called_twice() const noexcept
  { return _calls.size() == 2ul; }
  inline bool called_three_times() const noexcept
  { return _calls.size() == 3ul; }
  inline bool called_four_times() const noexcept
  { return _calls.size() == 3ul; }
  inline bool called_n_times(unsigned long n) const noexcept
  { return _calls.size() == n; }
  inline bool last_called_with(Args... args) const
  { return (_calls.back() == args_tuple(args...)); }
  inline bool called_once_with(Args... args) const
  { return called_once() && last_called_with(args...); }
protected:
  inline void call_with(Args... args)
  {
    _calls.push_back(args_tuple(args...));
  }
  std::vector<args_tuple> _calls;
};

/** // doc: Dummy_clGetPlatformIDs {{{
 * \brief Mock for clGetPlatformIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Dummy_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs,
    public T::Dummy_CallArgs<cl_uint, cl_platform_id*, cl_uint*>
{
  cl_int _err;
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint* num_platforms);
public:
  Dummy_clGetPlatformIDs(cl_int err);
};
/** // doc: Dummy_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo,
    public T::Dummy_CallArgs<cl_platform_id, cl_platform_info, size_t, void*, size_t*>
{
  cl_int _err;
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  Dummy_clGetPlatformInfo(cl_int err);
};
/** // doc: Dummy_clGetDeviceIDs {{{
 * \brief Mock for clGetDeviceIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Dummy_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs,
    public T::Dummy_CallArgs<cl_platform_id, cl_device_type, cl_uint, cl_device_id*, cl_uint*>
{
  cl_int _err;
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint* num_devices);
public:
  Dummy_clGetDeviceIDs(cl_int err);
};
/** // doc: Dummy_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo,
    public T::Dummy_CallArgs<cl_device_id, cl_device_info, size_t, void*, size_t*>
{
  cl_int _err;
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  Dummy_clGetDeviceInfo(cl_int err);
};
/** // doc: Dummy_clCreateContext {{{
 * \brief Default mock for clCreateContext OpenCL function.
 */ // }}}
class Dummy_clCreateContext
  : public T::Base_clCreateContext,
    public T::Dummy_CallArgs< const cl_context_properties*, cl_uint, const cl_device_id*,
                            void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                            void*, cl_int*>
{
  cl_context _ctx;
  cl_int _err;
  cl_context clCreateContext(
      const cl_context_properties* properties, cl_uint num_devices,
      const cl_device_id* devices,
      void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  Dummy_clCreateContext(cl_context ctx, cl_int err);
};

/** // doc: Dummy_clCreateContextFromType {{{
 * \brief Default mock for clCreateContextFromType OpenCL function.
 */ // }}}
class Dummy_clCreateContextFromType
  : public T::Base_clCreateContextFromType,
    public T::Dummy_CallArgs< const cl_context_properties*, const cl_device_type,
                            void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                            void*, cl_int*>
{
  cl_context _ctx;
  cl_int _err;
  cl_context clCreateContextFromType(
      const cl_context_properties* properties,
      cl_device_type device_type,
      void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  Dummy_clCreateContextFromType(cl_context ctx, cl_int err);
};

/** // doc: Dummy_clRetainContext {{{
 * \brief Default mock for clRetainContext OpenCL function.
 */ // }}}
class Dummy_clRetainContext
  : public T::Base_clRetainContext,
    public T::Dummy_CallArgs<cl_context>
{
  cl_int _err;
  cl_int clRetainContext(cl_context);
public:
  Dummy_clRetainContext(cl_int err);
};

/** // doc: Dummy_clReleaseContext {{{
 * \brief Default mock for clReleaseContext OpenCL function.
 */ // }}}
class Dummy_clReleaseContext
  : public T::Base_clReleaseContext,
    public T::Dummy_CallArgs<cl_context>
{
  cl_int _err;
  cl_int clReleaseContext(cl_context);
public:
  Dummy_clReleaseContext(cl_int err);
};
/** // doc: Dummy_clGetContextInfo {{{
 * \brief Default mock for clGetContextInfo OpenCL function.
 */ // }}}
class Dummy_clGetContextInfo
  : public T::Base_clGetContextInfo,
    public T::Dummy_CallArgs<cl_context,cl_context_info,size_t,void*,size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t _param_value_size_ret;
  cl_int clGetContextInfo(cl_context context, cl_context_info param_name,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret);
public:
  Dummy_clGetContextInfo(cl_int err, void* pv = nullptr, size_t pvs = 0);
};
#if HAVE_OPENCL_clCreateSubDevices
/** // doc: Dummy_clCreateSubDevices {{{
 * \brief Default mock for clCreateSubDevices OpenCL function.
 */ // }}}
class Dummy_clCreateSubDevices
  : public T::Base_clCreateSubDevices,
    public T::Dummy_CallArgs<cl_device_id,const cl_device_partition_property*,cl_uint,cl_device_id*,cl_uint*>
{
  cl_int _err;
  cl_device_id const* _out_devices;
  cl_uint const* _num_devices_ret;
  cl_int clCreateSubDevices(cl_device_id in_device,
                            const cl_device_partition_property* properties,
                            cl_uint num_devices,
                            cl_device_id* out_devices,
                            cl_uint* num_devices_ret);
public:
  Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices = nullptr, cl_uint const* num_devices_ret = nullptr);
};
#endif
#if HAVE_OPENCL_clRetainDevice
/** // doc: Dummy_clRetainDevice {{{
 * \brief Default mock for clRetainDevice OpenCL function.
 */ // }}}
class Dummy_clRetainDevice
  : public T::Base_clRetainDevice,
    public T::Dummy_CallArgs<cl_device_id>
{
  cl_int _err;
  cl_int clRetainDevice(cl_device_id device);
public:
  Dummy_clRetainDevice(cl_int err);
};
#endif
#if HAVE_OPENCL_clReleaseDevice
/** // doc: Dummy_clReleaseDevice {{{
 * \brief Default mock for clReleaseDevice OpenCL function.
 */ // }}}
class Dummy_clReleaseDevice
  : public T::Base_clReleaseDevice,
    public T::Dummy_CallArgs<cl_device_id>
{
  cl_int _err;
  cl_int clReleaseDevice(cl_device_id device);
public:
  Dummy_clReleaseDevice(cl_int err);
};
#endif
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetPlatformIDs::
clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  call_with(num_entries, platforms, num_platforms);
  return _err;
}
Dummy_clGetPlatformIDs::
Dummy_clGetPlatformIDs(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  call_with(platform, param_name, param_value_size, param_value, param_value_size_ret);
  return _err;
}
Dummy_clGetPlatformInfo::
Dummy_clGetPlatformInfo(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
{
  call_with(platform, device_type, num_entries, devices, num_devices);
  return _err;
}
Dummy_clGetDeviceIDs::
Dummy_clGetDeviceIDs(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(device, param_name, param_value_size, param_value, param_value_size_ret);
  return _err;
}

Dummy_clGetDeviceInfo::
Dummy_clGetDeviceInfo(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_context Dummy_clCreateContext::
clCreateContext(const cl_context_properties* properties,
                cl_uint num_devices,
                const cl_device_id* devices,
                void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
                void* user_data,
                cl_int* errcode_ret)
{
  call_with(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateContext::
Dummy_clCreateContext(cl_context ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_context Dummy_clCreateContextFromType::
clCreateContextFromType(const cl_context_properties* properties,
                        cl_device_type device_type,
                        void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
                        void* user_data,
                        cl_int* errcode_ret)
{
  call_with(properties, device_type, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_ctx;
}
Dummy_clCreateContextFromType::
Dummy_clCreateContextFromType(cl_context ctx, cl_int err)
  : _ctx(ctx), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainContext::
clRetainContext(cl_context context)
{
  call_with(context);
  return _err;
}
Dummy_clRetainContext::
Dummy_clRetainContext(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseContext::
clReleaseContext(cl_context context)
{
  call_with(context);
  return _err;
}
Dummy_clReleaseContext::
Dummy_clReleaseContext(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetContextInfo::
clGetContextInfo(cl_context context, cl_context_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  call_with(context, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value_size_ret) {
    *param_value_size_ret = _param_value_size_ret;
  }
  if(param_value && _param_value) {
    std::memcpy(param_value, _param_value, std::min(param_value_size, _param_value_size_ret));
  }
  return _err;
}
Dummy_clGetContextInfo::
Dummy_clGetContextInfo(cl_int err, void* pv, size_t pvs)
  : _err(err), _param_value(pv), _param_value_size_ret(pvs)
{
}
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clCreateSubDevices
cl_int Dummy_clCreateSubDevices::
clCreateSubDevices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint* num_devices_ret)
{
  call_with(in_device, properties, num_devices, out_devices, num_devices_ret);
  if(out_devices && _out_devices && _num_devices_ret)
    {
      std::memcpy(out_devices, _out_devices, std::min(num_devices, *_num_devices_ret) * sizeof(cl_device_id));
    }
  if(num_devices_ret && _num_devices_ret)
    {
      *num_devices_ret = *_num_devices_ret;
    }
  return _err;
}
Dummy_clCreateSubDevices::
Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices, cl_uint const* num_devices_ret)
  : _err(err), _out_devices(out_devices), _num_devices_ret(num_devices_ret)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clRetainDevice
cl_int Dummy_clRetainDevice::
clRetainDevice(cl_device_id device)
{
  call_with(device);
  return _err;
}
Dummy_clRetainDevice::
Dummy_clRetainDevice(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if HAVE_OPENCL_clReleaseDevice
cl_int Dummy_clReleaseDevice::
clReleaseDevice(cl_device_id device)
{
  call_with(device);
  return _err;
}
Dummy_clReleaseDevice::
Dummy_clReleaseDevice(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* CLXX_CL_MOCKS_DUMMY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
