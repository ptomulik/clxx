// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

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
 * \brief Helper class for OpenCL mocks
 *
 * This class shall be used as a base for other mock classes (\c T::Dummy_clXxx).
 * It allows to record and check calls to a mock function. An instantiation
 * of this template serves a single mock prototype.
 *
 * The typical usage is to spawn an instance of \ref T::Dummy_CallArgs
 * (more precise, an instance of a derived class), then invoke its member
 * function #call_with() one or more times with appropriate arguments. The
 * object records consecutive calls and arguments. After that, it might be
 * checked with one of the methods #never_called(), #called_once(),
 * #called_twice(), #called_three_times(), #called_four_times(),
 * #called_n_times(), #last_called_with(), #called_once_with() to verify if the
 * recorded call history agrees with an expected call history. A user may also
 * retrieve #calls() to see the full invocation history.
 *
 * \tparam Args List of argument types of an OpenCL function being mocked
 *
 * \par Example
 *
 * Create mock for <tt>clGetPlatformIDs(cl_uint, cl_platform_id*, cl_uint*)</tt>
 *
 * \code
 * class Dummy_clGetPlatformIDs
 *   : public T::Base_clGetPlatformIDs,
 *     public T::Dummy_CallArgs<cl_uint, cl_platform_id*, cl_uint*>
 * {
 *    // ...
 * };
 * // ...
 * cl_int Dummy_clGetPlatformIDs::
 * clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
 *                  cl_uint* num_platforms)
 * {
 *   call_with(num_entries, platforms, num_platforms);
 *   return _err;
 * }
 * \endcode
 *
 * Note, that each time the Dummy_clGetPlatformIDs::clGetPlatformIDs() is
 * invoked, the call gets recorded by the Dummy_clGetPlatformIDs object. It
 * may be later verified by a unit-test code how many times and with what
 * argument values the mock has been invoked.
 */ // }}}
template<class... Args>
class Dummy_CallArgs
{
public:
  /** // doc: args_tuple {{{
   * \brief A tuple used to store arguments of a single call to mock function
   */ // }}}
  typedef std::tuple<Args...> args_tuple;
  /** // doc: reset() {{{
   * \brief Reset the call history
   */ // }}}
  inline void reset() { _calls.clear(); }

  // return the calls
  /** // doc: () {{{
   * \brief Returns the full history of mock invocation.
   */ // }}}
  inline std::vector<args_tuple> const& calls() const { return _calls; }

  // mock tests
  /** // doc: never_called() {{{
   * \brief Whether the mock has never been invoked
   * \returns \c true if mock was not invoked since its creation/reset or \c false otherwise
   */ // }}}
  inline bool never_called() const noexcept
  { return _calls.size() == 0ul; }
  /** // doc: called_once() {{{
   * \brief Whether the mock has been invoked exactly once
   * \returns \c true if mock was invoked exactly once since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_once() const noexcept
  { return _calls.size() == 1ul; }
  /** // doc: called_twice() {{{
   * \brief Whether the mock has been invoked exactly twice
   * \returns \c true if mock was invoked exactly twice since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_twice() const noexcept
  { return _calls.size() == 2ul; }
  /** // doc: called_three_times() {{{
   * \brief Whether the mock has been invoked exactly three times
   * \returns \c true if mock was invoked exactly three times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_three_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_four_times() {{{
   * \brief Whether the mock has been invoked exactly four times
   * \returns \c true if mock was invoked exactly four times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_four_times() const noexcept
  { return _calls.size() == 3ul; }
  /** // doc: called_n_times() {{{
   * \brief Whether the mock has been invoked exactly n times
   * \param n The expected call count
   * \returns \c true if mock was invoked exactly n times since its creation/reset or \c false otherwise
   */ // }}}
  inline bool called_n_times(unsigned long n) const noexcept
  { return _calls.size() == n; }
  /** // doc: last_called_with() {{{
   * \brief Verify the arguments used in last call to the mock
   * \param args Expected argument values
   * \returns \c true if the last call arguments were same as the expected \em args or \c false otherwise
   */ // }}}
  inline bool last_called_with(Args... args) const
  { return (_calls.back() == args_tuple(args...)); }
  /** // doc: caled_once_with() {{{
   * \brief Same as <tt>called_once() && last_called_with_args(args...)</tt>
   */ // }}}
  inline bool called_once_with(Args... args) const
  { return called_once() && last_called_with(args...); }
protected:
  /** // doc: call_with(args) {{{
   * \brief Record a call to the mock
   *
   * This should be invoked from within derived class each time the mock is
   * invoked.
   *
   * \param args The arguments used in the invocation being recorded
   */ // }}}
  inline void call_with(Args... args)
  {
    _calls.push_back(args_tuple(args...));
  }
  /** // doc: call_with(args) {{{
   * \brief Invocation history
   */ // }}}
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
  /** // doc: Dummy_clGetPlatformIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clGetPlatformInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clGetDeviceIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clGetDeviceInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clCreateContext() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param ctx OpenCL context to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clCreateContextFromType() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param ctx OpenCL context to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clRetainContext() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clReleaseContext() {{{
   * \brief Constructor
   *
   * \param err Error code to be returned by the mock
   */ // }}}
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
  /** // doc: Dummy_clGetContextInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param pv Pointer to parameter value that is to be returned
   * \param pvs Size of the parameter value (\em pv) to be returned
   */ // }}}
  Dummy_clGetContextInfo(cl_int err, void* pv = nullptr, size_t pvs = 0);
};
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
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
  /** // doc: Dummy_clCreateSubDevices() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param out_devices Pointer to the device list that is to be returned by the mock
   * \param num_devices_ret Number of devices specified in \em out_devices
   */ // }}}
  Dummy_clCreateSubDevices(cl_int err, cl_device_id const* out_devices = nullptr, cl_uint const* num_devices_ret = nullptr);
};
#endif
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
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
  /** // doc: Dummy_clRetainDevice() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainDevice(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
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
  /** // doc: Dummy_clReleaseDevice() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseDevice(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
/** // doc: Dummy_clCreateCommandQueue {{{
 * \brief Default mock for clCreateCommandQueue OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueue
  : public T::Base_clCreateCommandQueue,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             cl_command_queue_properties, cl_int*>
{
  cl_command_queue _queue;
  cl_int _err;
  cl_command_queue clCreateCommandQueue(
      cl_context context,
      cl_device_id device,
      cl_command_queue_properties properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param queue Command Queue to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateCommandQueue(cl_command_queue queue, cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
/** // doc: Dummy_clCreateCommandQueueWithProperties {{{
 * \brief Default mock for clCreateCommandQueueWithProperties OpenCL function.
 */ // }}}
class Dummy_clCreateCommandQueueWithProperties
  : public T::Base_clCreateCommandQueueWithProperties,
    public T::Dummy_CallArgs<cl_context, cl_device_id,
                             const cl_queue_properties*, cl_int*>
{
  cl_command_queue _queue;
  cl_int _err;
  cl_command_queue clCreateCommandQueueWithProperties(
      cl_context context,
      cl_device_id device,
      const cl_queue_properties* properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param queue Command Queue to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateCommandQueueWithProperties(cl_command_queue queue, cl_int err);
};
#endif
/** // doc: Dummy_clRetainCommandQueue {{{
 * \brief Default mock for clRetainCommandQueue OpenCL function.
 */ // }}}
class Dummy_clRetainCommandQueue
  : public T::Base_clRetainCommandQueue,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clRetainCommandQueue(cl_command_queue);
public:
  /** // doc: Dummy_clRetainCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainCommandQueue(cl_int err);
};

/** // doc: Dummy_clReleaseCommandQueue {{{
 * \brief Default mock for clReleaseCommandQueue OpenCL function.
 */ // }}}
class Dummy_clReleaseCommandQueue
  : public T::Base_clReleaseCommandQueue,
    public T::Dummy_CallArgs<cl_command_queue>
{
  cl_int _err;
  cl_int clReleaseCommandQueue(cl_command_queue);
public:
  /** // doc: Dummy_clReleaseCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseCommandQueue(cl_int err);
};
/** // doc: Dummy_clGetCommandQueueInfo {{{
 * \brief Default mock for clGetCommandQueueInfo OpenCL function.
 */ // }}}
class Dummy_clGetCommandQueueInfo
  : public T::Base_clGetCommandQueueInfo,
    public T::Dummy_CallArgs<cl_command_queue,cl_command_queue_info,size_t,void*,size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t _param_value_size_ret;
  cl_int clGetCommandQueueInfo(cl_command_queue command_queue,
                               cl_command_queue_info param_name,
                               size_t param_value_size, void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetCommandQueueInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param pv Pointer to the parameter value to be returned by a mock
   * \param pvs Size of the parameter value \em pv
   */ // }}}
  Dummy_clGetCommandQueueInfo(cl_int err, void* pv = nullptr, size_t pvs = 0);
};
/** // doc: Dummy_clCreateProgramWithSource {{{
 * \brief Default mock for clCreateProgramWithSource OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithSource
  : public T::Base_clCreateProgramWithSource,
    public T::Dummy_CallArgs<cl_context, cl_uint, const char**, const size_t*, cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithSource(cl_context context,
                                       cl_uint count,
                                       const char** strings,
                                       const size_t* lengths,
                                       cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithSource() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateProgramWithSource(cl_program program, cl_int err);
};
/** // doc: Dummy_clCreateProgramWithBinary {{{
 * \brief Default mock for clCreateProgramWithBinary OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithBinary
  : public T::Base_clCreateProgramWithBinary,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                              const size_t*, const unsigned char**, cl_int*,
                              cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithBinary(cl_context context,
                                       cl_uint num_devices,
                                       const cl_device_id* device_list,
                                       const size_t* lengths,
                                       const unsigned char** binaries,
                                       cl_int* binary_status,
                                       cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithBinary() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateProgramWithBinary(cl_program program, cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
/** // doc: Dummy_clCreateProgramWithBuiltInKernels {{{
 * \brief Default mock for clCreateProgramWithBuiltInKernels OpenCL function.
 */ // }}}
class Dummy_clCreateProgramWithBuiltInKernels
  : public T::Base_clCreateProgramWithBuiltInKernels,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                              const char*, cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clCreateProgramWithBuiltInKernels(cl_context context,
                                               cl_uint num_devices,
                                               const cl_device_id* device_list,
                                               const char* kernel_names,
                                               cl_int* errcode_ret);
public:
  /** // doc: Dummy_clCreateProgramWithBuiltInKernels() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateProgramWithBuiltInKernels(cl_program program, cl_int err);
};
#endif
/** // doc: Dummy_clRetainProgram {{{
 * \brief Default mock for clRetainProgram OpenCL function.
 */ // }}}
class Dummy_clRetainProgram
  : public T::Base_clRetainProgram,
    public T::Dummy_CallArgs<cl_program>
{
  cl_int _err;
  cl_int clRetainProgram(cl_program program);
public:
  /** // doc: Dummy_clRetainProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainProgram(cl_int err);
};
/** // doc: Dummy_clReleaseProgram {{{
 * \brief Default mock for clReleaseProgram OpenCL function.
 */ // }}}
class Dummy_clReleaseProgram
  : public T::Base_clReleaseProgram,
    public T::Dummy_CallArgs<cl_program>
{
  cl_int _err;
  cl_int clReleaseProgram(cl_program program);
public:
  /** // doc: Dummy_clReleaseProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseProgram(cl_int err);
};
/** // doc: Dummy_clBuildProgram {{{
 * \brief Default mock for clBuildProgram OpenCL function.
 */ // }}}
class Dummy_clBuildProgram
  : public T::Base_clBuildProgram,
    public T::Dummy_CallArgs<cl_program, cl_uint, const cl_device_id*, const char*,
                              void (CL_CALLBACK*)(cl_program, void*), void*>
{
  cl_int _err;
  cl_int clBuildProgram(cl_program program,
                        cl_uint num_devices,
                        const cl_device_id* device_list,
                        const char* options,
                        void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                        void* user_data);
public:
  /** // doc: Dummy_clBuildProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clBuildProgram(cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/** // doc: Dummy_clCompileProgram {{{
 * \brief Default mock for clCompileProgram OpenCL function.
 */ // }}}
class Dummy_clCompileProgram
  : public T::Base_clCompileProgram,
    public T::Dummy_CallArgs<cl_program, cl_uint, const cl_device_id*, const char*,
                             cl_uint, const cl_program*, const char**,
                             void (CL_CALLBACK*)(cl_program, void*), void*>
{
  cl_int _err;
  cl_int clCompileProgram(cl_program program,
                        cl_uint num_devices,
                        const cl_device_id* device_list,
                        const char* options,
                        cl_uint num_input_headers,
                        const cl_program* input_headers,
                        const char** header_include_names,
                        void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                        void* user_data);
public:
  /** // doc: Dummy_clCompileProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCompileProgram(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/** // doc: Dummy_clLinkProgram {{{
 * \brief Default mock for clLinkProgram OpenCL function.
 */ // }}}
class Dummy_clLinkProgram
  : public T::Base_clLinkProgram,
    public T::Dummy_CallArgs<cl_context, cl_uint, const cl_device_id*,
                             const char*, cl_uint, const cl_program*,
                             void (CL_CALLBACK*)(cl_program, void*), void*,
                             cl_int*>
{
  cl_program _program;
  cl_int _err;
  cl_program clLinkProgram(cl_context context,
                           cl_uint num_devices,
                           const cl_device_id* device_list,
                           const char* options,
                           cl_uint num_input_programs,
                           const cl_program* input_programs,
                           void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                           void* user_data,
                           cl_int* errcode_ret);
public:
  /** // doc: Dummy_clLinkProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param program An OpenCL program to be returned by the mock
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clLinkProgram(cl_program program, cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
/** // doc: Dummy_clUnloadPlatformCompiler {{{
 * \brief Default mock for clUnloadPlatformCompiler OpenCL function.
 */ // }}}
class Dummy_clUnloadPlatformCompiler
  : public T::Base_clUnloadPlatformCompiler,
    public T::Dummy_CallArgs<cl_platform_id>
{
  cl_int _err;
  cl_int clUnloadPlatformCompiler(cl_platform_id);
public:
  /** // doc: Dummy_clUnloadPlatformCompiler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clUnloadPlatformCompiler(cl_int err);
};
#endif
/** // doc: Dummy_clGetProgramInfo {{{
 * \brief Mock for clGetProgramInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetProgramInfo
  : public T::Base_clGetProgramInfo,
    public T::Dummy_CallArgs<cl_program, cl_program_info, size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetProgramInfo(cl_program program, cl_program_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetProgramInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clGetProgramBuildInfo {{{
 * \brief Mock for clGetProgramBuildInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetProgramBuildInfo
  : public T::Base_clGetProgramBuildInfo,
    public T::Dummy_CallArgs<cl_program, cl_device_id, cl_program_build_info,
                             size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetProgramBuildInfo(cl_program program,
                               cl_device_id device,
                               cl_program_build_info param_name,
                               size_t param_value_size,
                               void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetProgramBuildInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetProgramBuildInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clCreateKernel {{{
 * \brief Default mock for clCreateKernel OpenCL function.
 */ // }}}
class Dummy_clCreateKernel
  : public T::Base_clCreateKernel,
    public T::Dummy_CallArgs< cl_program, const char*, cl_int*>
{
  cl_kernel _kern;
  cl_int _err;
  cl_kernel clCreateKernel(
      cl_program program,
      const char* kernel_name,
      cl_int* errcode_ret
  );
public:
  /** // doc: Dummy_clCreateKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param kern OpenCL kernel to be returned to caller
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clCreateKernel(cl_kernel kern, cl_int err);
};
/** // doc: Dummy_clCreateKernelsInProgram {{{
 * \brief Default mock for clCreateKernelsInProgram OpenCL function.
 */ // }}}
class Dummy_clCreateKernelsInProgram
  : public T::Base_clCreateKernelsInProgram,
    public T::Dummy_CallArgs< cl_program, cl_uint, cl_kernel*, cl_uint*>
{
  cl_int _err;
  cl_kernel* _kernels;
  cl_uint* _num_kernels_ret;
  cl_int clCreateKernelsInProgram(
      cl_program program,
      cl_uint num_kernels,
      cl_kernel* kernels,
      cl_uint* num_kernels_ret 
  );
public:
  /** // doc: Dummy_clCreateKernelsInProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param kernels Keernels to be returned by the mock
   * \param num_kernels_ret Number of kernels to be returned by the mock
   */ // }}}
  Dummy_clCreateKernelsInProgram(cl_int err, cl_kernel* kernels = nullptr, cl_uint* num_kernels_ret = nullptr);
};
/** // doc: Dummy_clGetKernelInfo {{{
 * \brief Mock for clGetKernelInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelInfo
  : public T::Base_clGetKernelInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_kernel_info, size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
/** // doc: Dummy_clGetKernelArgInfo {{{
 * \brief Mock for clGetKernelArgInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelArgInfo
  : public T::Base_clGetKernelArgInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, cl_kernel_arg_info, size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index,
                            cl_kernel_arg_info param_name,
                            size_t param_value_size, void* param_value,
                            size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelArgInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelArgInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
#endif
/** // doc: Dummy_clGetKernelWorkGroupInfo {{{
 * \brief Mock for clGetKernelWorkGroupInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clGetKernelWorkGroupInfo
  : public T::Base_clGetKernelWorkGroupInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_device_id, cl_kernel_work_group_info, size_t, void*, size_t*>
{
  cl_int _err;
  void* _param_value;
  size_t* _param_value_size_ret;
  cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device,
                                  cl_kernel_work_group_info param_name,
                                  size_t param_value_size, void* param_value,
                                  size_t* param_value_size_ret);
public:
  /** // doc: Dummy_clGetKernelWorkGroupInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   * \param param_value A parameter value to be returned by the mock
   * \param param_value_size_ret A parameter value size to be returned by the mock
   */ // }}}
  Dummy_clGetKernelWorkGroupInfo(cl_int err, void* param_value = nullptr, size_t* param_value_size_ret = nullptr);
};
/** // doc: Dummy_clRetainKernel {{{
 * \brief Default mock for clRetainKernel OpenCL function.
 */ // }}}
class Dummy_clRetainKernel
  : public T::Base_clRetainKernel,
    public T::Dummy_CallArgs<cl_kernel>
{
  cl_int _err;
  cl_int clRetainKernel(cl_kernel kernel);
public:
  /** // doc: Dummy_clRetainKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clRetainKernel(cl_int err);
};
/** // doc: Dummy_clReleaseKernel {{{
 * \brief Default mock for clReleaseKernel OpenCL function.
 */ // }}}
class Dummy_clReleaseKernel
  : public T::Base_clReleaseKernel,
    public T::Dummy_CallArgs<cl_kernel>
{
  cl_int _err;
  cl_int clReleaseKernel(cl_kernel kernel);
public:
  /** // doc: Dummy_clReleaseKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clReleaseKernel(cl_int err);
};
/** // doc: Dummy_clSetKernelArg {{{
 * \brief Mock for clSetKernelArg OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelArg
  : public T::Base_clSetKernelArg,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, size_t, const void*>
{
  cl_int _err;
  cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size,
                        const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelArg() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelArg(cl_int err);
};
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
/** // doc: Dummy_clSetKernelArgSVMPointer {{{
 * \brief Mock for clSetKernelArgSVMPointer OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelArgSVMPointer
  : public T::Base_clSetKernelArgSVMPointer,
    public T::Dummy_CallArgs<cl_kernel, cl_uint, const void*>
{
  cl_int _err;
  cl_int clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelArgSVMPointer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelArgSVMPointer(cl_int err);
};
#endif
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
/** // doc: Dummy_clSetKernelExecInfo {{{
 * \brief Mock for clSetKernelExecInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Dummy_clSetKernelExecInfo
  : public T::Base_clSetKernelExecInfo,
    public T::Dummy_CallArgs<cl_kernel, cl_kernel_exec_info, size_t, const void*>
{
  cl_int _err;
  cl_int clSetKernelExecInfo(cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void* arg_value);
public:
  /** // doc: Dummy_clSetKernelExecInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param err Error code to be returned by the mock
   */ // }}}
  Dummy_clSetKernelExecInfo(cl_int err);
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
#if CLXX_OPENCL_ALLOWED(clCreateSubDevices)
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
#if CLXX_OPENCL_ALLOWED(clRetainDevice)
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
#if CLXX_OPENCL_ALLOWED(clReleaseDevice)
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
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueue)
cl_command_queue Dummy_clCreateCommandQueue::
clCreateCommandQueue(cl_context context, cl_device_id device,
                     cl_command_queue_properties properties,
                     cl_int* errcode_ret)
{
  call_with(context, device, properties, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_queue;
}
Dummy_clCreateCommandQueue::
Dummy_clCreateCommandQueue(cl_command_queue queue, cl_int err)
  : _queue(queue), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateCommandQueueWithProperties)
cl_command_queue Dummy_clCreateCommandQueueWithProperties::
clCreateCommandQueueWithProperties(cl_context context, cl_device_id device,
                                   const cl_queue_properties* properties,
                                   cl_int* errcode_ret)
{
  call_with(context, device, properties, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_queue;
}
Dummy_clCreateCommandQueueWithProperties::
Dummy_clCreateCommandQueueWithProperties(cl_command_queue queue, cl_int err)
  : _queue(queue), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainCommandQueue::
clRetainCommandQueue(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clRetainCommandQueue::
Dummy_clRetainCommandQueue(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseCommandQueue::
clReleaseCommandQueue(cl_command_queue command_queue)
{
  call_with(command_queue);
  return _err;
}
Dummy_clReleaseCommandQueue::
Dummy_clReleaseCommandQueue(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetCommandQueueInfo::
clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  call_with(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value_size_ret) {
    *param_value_size_ret = _param_value_size_ret;
  }
  if(param_value && _param_value) {
    std::memcpy(param_value, _param_value, std::min(param_value_size, _param_value_size_ret));
  }
  return _err;
}
Dummy_clGetCommandQueueInfo::
Dummy_clGetCommandQueueInfo(cl_int err, void* pv, size_t pvs)
  : _err(err), _param_value(pv), _param_value_size_ret(pvs)
{
}
/* ------------------------------------------------------------------------- */
cl_program Dummy_clCreateProgramWithSource::
clCreateProgramWithSource(cl_context context,
                          cl_uint count,
                          const char** strings,
                          const size_t* lengths,
                          cl_int* errcode_ret)
{
  call_with(context, count, strings, lengths, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithSource::
Dummy_clCreateProgramWithSource(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_program Dummy_clCreateProgramWithBinary::
clCreateProgramWithBinary(cl_context context,
                          cl_uint num_devices,
                          const cl_device_id* device_list,
                          const size_t* lengths,
                          const unsigned char** binaries,
                          cl_int* binary_status,
                          cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithBinary::
Dummy_clCreateProgramWithBinary(cl_program program, cl_int err)
  : _program(program), _err(err)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clCreateProgramWithBuiltInKernels)
cl_program Dummy_clCreateProgramWithBuiltInKernels::
clCreateProgramWithBuiltInKernels(cl_context context,
                                  cl_uint num_devices,
                                  const cl_device_id* device_list,
                                  const char* kernel_names,
                                  cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, kernel_names, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clCreateProgramWithBuiltInKernels::
Dummy_clCreateProgramWithBuiltInKernels(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainProgram::
clRetainProgram(cl_program program)
{
  call_with(program);
  return _err;
}
Dummy_clRetainProgram::
Dummy_clRetainProgram(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseProgram::
clReleaseProgram(cl_program program)
{
  call_with(program);
  return _err;
}
Dummy_clReleaseProgram::
Dummy_clReleaseProgram(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clBuildProgram::
clBuildProgram(cl_program program,
               cl_uint num_devices,
               const cl_device_id* device_list,
               const char* options,
               void (CL_CALLBACK* pfn_notify)(cl_program, void*),
               void* user_data)
{
  call_with(program, num_devices,device_list, options, pfn_notify, user_data);
  return _err;
}
Dummy_clBuildProgram::
Dummy_clBuildProgram(cl_int err)
  :_err(err)
{
}
#if CLXX_OPENCL_ALLOWED(clCompileProgram)
/* ------------------------------------------------------------------------- */
cl_int Dummy_clCompileProgram::
clCompileProgram(cl_program program,
                 cl_uint num_devices,
                 const cl_device_id* device_list,
                 const char* options,
                 cl_uint num_input_headers,
                 const cl_program* input_headers,
                 const char** header_include_names,
                 void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                 void* user_data)
{
  call_with(program, num_devices, device_list, options, num_input_headers,
            input_headers, header_include_names, pfn_notify, user_data);
  return _err;
}
Dummy_clCompileProgram::
Dummy_clCompileProgram(cl_int err)
  :_err(err)
{
}
#endif
#if CLXX_OPENCL_ALLOWED(clLinkProgram)
/* ------------------------------------------------------------------------- */
cl_program Dummy_clLinkProgram::
clLinkProgram(cl_context context,
              cl_uint num_devices,
              const cl_device_id* device_list,
              const char* options,
              cl_uint num_input_programs,
              const cl_program* input_programs,
              void (CL_CALLBACK* pfn_notify)(cl_program, void*),
              void* user_data,
              cl_int* errcode_ret)
{
  call_with(context, num_devices, device_list, options, num_input_programs,
            input_programs, pfn_notify, user_data, errcode_ret);
  if(errcode_ret)
    *errcode_ret = _err;
  return _program;
}
Dummy_clLinkProgram::
Dummy_clLinkProgram(cl_program program, cl_int err)
  :_program(program), _err(err)
{
}
#endif
#if CLXX_OPENCL_ALLOWED(clUnloadPlatformCompiler)
/* ------------------------------------------------------------------------- */
cl_int Dummy_clUnloadPlatformCompiler::
clUnloadPlatformCompiler(cl_platform_id platform)
{
  call_with(platform);
  return _err;
}
Dummy_clUnloadPlatformCompiler::
Dummy_clUnloadPlatformCompiler(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetProgramInfo::
clGetProgramInfo(cl_program program, cl_program_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(program, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}
Dummy_clGetProgramInfo::
Dummy_clGetProgramInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetProgramBuildInfo::
clGetProgramBuildInfo(cl_program program, cl_device_id device,
                      cl_program_build_info param_name, size_t param_value_size,
                      void* param_value, size_t* param_value_size_ret)
{
  call_with(program, device, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}
Dummy_clGetProgramBuildInfo::
Dummy_clGetProgramBuildInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_kernel Dummy_clCreateKernel::
clCreateKernel(cl_program program, const char* kernel_name, cl_int* errcode_ret)
{
  call_with(program, kernel_name, errcode_ret);
  if(errcode_ret)
    {
      *errcode_ret = _err;
    }
  return this->_kern;
}
Dummy_clCreateKernel::
Dummy_clCreateKernel(cl_kernel kern, cl_int err)
  : _kern(kern), _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clCreateKernelsInProgram::
clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel* kernels,
                         cl_uint* num_kernels_ret)
{
  call_with(program, num_kernels, kernels, num_kernels_ret);
  if(_kernels && kernels && _num_kernels_ret)
    {
      std::memcpy(kernels, _kernels, std::min(*_num_kernels_ret, num_kernels) * sizeof(cl_kernel));
    }
  if(_num_kernels_ret && num_kernels_ret)
    {
      *num_kernels_ret = *_num_kernels_ret;
    }
  return _err;
}
Dummy_clCreateKernelsInProgram::
Dummy_clCreateKernelsInProgram(cl_int err, cl_kernel* kernels, cl_uint* num_kernels_ret)
  : _err(err), _kernels(kernels), _num_kernels_ret(num_kernels_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetKernelInfo::
clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  call_with(kernel, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}
Dummy_clGetKernelInfo::
Dummy_clGetKernelInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
cl_int Dummy_clGetKernelArgInfo::
clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name,
                   size_t param_value_size, void* param_value,
                   size_t* param_value_size_ret)
{
  call_with(kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}
Dummy_clGetKernelArgInfo::
Dummy_clGetKernelArgInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
#endif
/* ------------------------------------------------------------------------- */
cl_int Dummy_clGetKernelWorkGroupInfo::
clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret)
{
  call_with(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
  if(param_value && _param_value && _param_value_size_ret)
    {
      std::memcpy(param_value, _param_value, std::min(*_param_value_size_ret, param_value_size));
    }
  if(_param_value_size_ret && param_value_size_ret)
    {
      *param_value_size_ret = *_param_value_size_ret;
    }
  return _err;
}
Dummy_clGetKernelWorkGroupInfo::
Dummy_clGetKernelWorkGroupInfo(cl_int err, void* param_value, size_t* param_value_size_ret)
  : _err(err), _param_value(param_value), _param_value_size_ret(param_value_size_ret)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clRetainKernel::
clRetainKernel(cl_kernel kernel)
{
  call_with(kernel);
  return _err;
}
Dummy_clRetainKernel::
Dummy_clRetainKernel(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clReleaseKernel::
clReleaseKernel(cl_kernel kernel)
{
  call_with(kernel);
  return _err;
}
Dummy_clReleaseKernel::
Dummy_clReleaseKernel(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
cl_int Dummy_clSetKernelArg::
clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value)
{
  call_with(kernel, arg_index, arg_size, arg_value);
  return _err;
}
Dummy_clSetKernelArg::
Dummy_clSetKernelArg(cl_int err)
  : _err(err)
{
}
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
cl_int Dummy_clSetKernelArgSVMPointer::
clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value)
{
  call_with(kernel, arg_index, arg_value);
  return _err;
}
Dummy_clSetKernelArgSVMPointer::
Dummy_clSetKernelArgSVMPointer(cl_int err)
  : _err(err)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
cl_int Dummy_clSetKernelExecInfo::
clSetKernelExecInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, const void* param_value)
{
  call_with(kernel, param_name, param_value_size, param_value);
  return _err;
}
Dummy_clSetKernelExecInfo::
Dummy_clSetKernelExecInfo(cl_int err)
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
