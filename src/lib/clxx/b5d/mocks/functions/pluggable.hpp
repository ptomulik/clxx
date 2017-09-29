// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/mocks/cl/pluggable.hpp

/** // doc: clxx/b5d/mocks/cl/pluggable.hpp {{{
 * \file clxx/b5d/mocks/cl/pluggable.hpp
 *
 * This file implements OpenCL mocks emulating several pluggable cases, such as
 * memory allocation errors.
 *
 * The implementation is created only when the \c CXXTEST_MOCK_TEST_SOURCE_FILE
 * constant is defined,
 *
 */ // }}}
#ifndef CLXX_B5D_MOCKS_FUNCTIONS_PLUGGABLE_HPP_INCLUDED
#define CLXX_B5D_MOCKS_FUNCTIONS_PLUGGABLE_HPP_INCLUDED

/* Mock class declarations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE) || defined(CXXTEST_FLAGS) \
  || defined(CXXTEST_RUNNING) || defined(DOXYGEN)

#include <tuple>
#include <vector>
#include <cstring>

namespace T {
/** // doc: Pluggable_CallArgs {{{
 * \brief Helper class for OpenCL mocks
 *
 * This class shall be used as a base for other mock classes (\c T::Pluggable_clXxx).
 * It allows to record and check calls to a mock function. An instantiation
 * of this template serves a single mock prototype.
 *
 * The typical usage is to spawn an instance of \ref T::Pluggable_CallArgs
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
 * class Pluggable_clGetPlatformIDs
 *   : public T::Base_clGetPlatformIDs,
 *     public T::Pluggable_CallArgs<cl_uint, cl_platform_id*, cl_uint*>
 * {
 *    // ...
 * };
 * // ...
 * cl_int Pluggable_clGetPlatformIDs::
 * clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
 *                  cl_uint* num_platforms)
 * {
 *   call_with(num_entries, platforms, num_platforms);
 *   return _err;
 * }
 * \endcode
 *
 * Note, that each time the Pluggable_clGetPlatformIDs::clGetPlatformIDs() is
 * invoked, the call gets recorded by the Pluggable_clGetPlatformIDs object. It
 * may be later verified by a unit-test code how many times and with what
 * argument values the mock has been invoked.
 */ // }}}
template<class... Args>
class Pluggable_CallArgs
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

/** // doc: Pluggable_Function {{{
 * \todo Write documentation for Pluggable_Function
 */ // }}}
template<class>
class Pluggable_Function;

template<class RetT, class... Args>
class Pluggable_Function<RetT(*)(Args...)>
  : public T::Pluggable_CallArgs<Args...>
{
public:
  /** // doc: function_pointer_t {{{
   * \brief Type of pointer to the underlying function
   */ // }}}
  typedef RetT (*function_pointer_t)(Args...);
  /** // doc: function_value_t {{{
   * \brief Type of the underlying function's return value
   */ // }}}
  typedef RetT function_value_t;
protected:
  /** // doc: _fptr {{{
   * \brief Function pointer stored by user
   */ // }}}
  function_pointer_t _fptr;
  /** // doc: call_with(args) {{{
   * \brief Record a call to the mock
   *
   * This should be invoked from within derived class each time the mock is
   * invoked.
   *
   * \param args The arguments used in the invocation being recorded
   */ // }}}
  inline RetT call_function(Args... args)
  {
    this->call_with(args...);
    return _fptr(args...);
  }
public:
  Pluggable_Function(function_pointer_t fptr)
    : _fptr(fptr)
  { }
};

#if CLXX_B5D_OPENCL_PROVIDES(clBuildProgram)
/** // doc: Pluggable_clBuildProgram {{{
 * \brief Default mock for clBuildProgram OpenCL function.
 */ // }}}
class Pluggable_clBuildProgram
  : public T::Base_clBuildProgram,
    public T::Pluggable_Function<cl_int (*) ( cl_program,
                                              cl_uint,
                                              const cl_device_id*,
                                              const char*,
                                              void (CL_CALLBACK*)(cl_program, void*),
                                              void* )>
{
  cl_int clBuildProgram(cl_program program,
                        cl_uint num_devices,
                        const cl_device_id* device_list,
                        const char* options,
                        void (CL_CALLBACK* pfn_notify)(cl_program, void*),
                        void* user_data);
public:
  /** // doc: Pluggable_clBuildProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clBuildProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCloneKernel)
/** // doc: Pluggable_clCloneKernel {{{
 * \brief Default mock for clCloneKernel OpenCL function.
 */ // }}}
class Pluggable_clCloneKernel
  : public T::Base_clCloneKernel,
    public T::Pluggable_Function<cl_kernel(*)(cl_kernel,cl_int*)>
{
  cl_kernel clCloneKernel(cl_kernel source_kernel, cl_int* errcode_ret);
public:
  /** // doc: Pluggable_clCloneKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCloneKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCompileProgram)
/** // doc: Pluggable_clCompileProgram {{{
 * \brief Default mock for clCompileProgram OpenCL function.
 */ // }}}
class Pluggable_clCompileProgram
  : public T::Base_clCompileProgram,
    public T::Pluggable_Function<cl_int (*) ( cl_program,
                                              cl_uint,
                                              const cl_device_id*,
                                              const char*,
                                              cl_uint,
                                              const cl_program*,
                                              const char**,
                                              void (CL_CALLBACK*)(cl_program, void*),
                                              void* )>
{
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
  /** // doc: Pluggable_clCompileProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCompileProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateBuffer)
/** // doc: Pluggable_clCreateBuffer {{{
 * \brief Default mock for clCreateBuffer OpenCL function.
 */ // }}}
class Pluggable_clCreateBuffer
  : public T::Base_clCreateBuffer,
    public T::Pluggable_Function<cl_mem (*) ( cl_context,
                                              cl_mem_flags,
                                              size_t,
                                              void*,
                                              cl_int* )>
{
  cl_mem clCreateBuffer( cl_context context, cl_mem_flags flags,
                         size_t size, void* host_ptr, cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueue)
/** // doc: Pluggable_clCreateCommandQueue {{{
 * \brief Default mock for clCreateCommandQueue OpenCL function.
 */ // }}}
class Pluggable_clCreateCommandQueue
  : public T::Base_clCreateCommandQueue,
    public T::Pluggable_Function<cl_command_queue (*) ( cl_context,
                                                        cl_device_id,
                                                        cl_command_queue_properties,
                                                        cl_int* )>
{
  cl_command_queue clCreateCommandQueue(
      cl_context context,
      cl_device_id device,
      cl_command_queue_properties properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Pluggable_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateCommandQueue(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueueWithProperties)
/** // doc: Pluggable_clCreateCommandQueueWithProperties {{{
 * \brief Default mock for clCreateCommandQueueWithProperties OpenCL function.
 */ // }}}
class Pluggable_clCreateCommandQueueWithProperties
  : public T::Base_clCreateCommandQueueWithProperties,
    public T::Pluggable_Function<cl_command_queue (*) ( cl_context,
                                                        cl_device_id,
                                                        const cl_queue_properties*,
                                                        cl_int* )>
{
  cl_command_queue clCreateCommandQueueWithProperties(
      cl_context context,
      cl_device_id device,
      const cl_queue_properties* properties,
      cl_int* errcode_ret
  );
public:
  /** // doc: Pluggable_clCreateCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateCommandQueueWithProperties(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateContext)
/** // doc: Pluggable_clCreateContext {{{
 * \brief Default mock for clCreateContext OpenCL function.
 */ // }}}
class Pluggable_clCreateContext
  : public T::Base_clCreateContext,
    public T::Pluggable_Function<cl_context (*) ( const cl_context_properties*,
                                                  cl_uint,
                                                  const cl_device_id*,
                                                  void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                                                  void*,
                                                  cl_int* )>
{
  cl_context clCreateContext(
      const cl_context_properties* properties, cl_uint num_devices,
      const cl_device_id* devices,
      void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  /** // doc: Pluggable_clCreateContext() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateContext(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateContextFromType)
/** // doc: Pluggable_clCreateContextFromType {{{
 * \brief Default mock for clCreateContextFromType OpenCL function.
 */ // }}}
class Pluggable_clCreateContextFromType
  : public T::Base_clCreateContextFromType,
    public T::Pluggable_Function<cl_context (*) ( const cl_context_properties*,
                                                  const cl_device_type,
                                                  void(CL_CALLBACK*)(const char*,const void*, size_t, void*),
                                                  void*,
                                                  cl_int* )>
{
  cl_context clCreateContextFromType(
      const cl_context_properties* properties,
      cl_device_type device_type,
      void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
      void* user_data,
      cl_int* errcode_ret
  );
public:
  /** // doc: Pluggable_clCreateContextFromType() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateContextFromType(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage)
/** // doc: Pluggable_clCreateImage {{{
 * \brief Default mock for clCreateImage OpenCL function.
 */ // }}}
class Pluggable_clCreateImage
  : public T::Base_clCreateImage,
    public T::Pluggable_Function<cl_mem (*) ( cl_context,
                                              cl_mem_flags,
                                              const cl_image_format*,
                                              const cl_image_desc*,
                                              void*,
                                              cl_int* )>
{
  cl_mem clCreateImage( cl_context context, cl_mem_flags flags,
                        const cl_image_format* image_format,
                        const cl_image_desc* image_desc, void* host_ptr,
                        cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage2D)
/** // doc: Pluggable_clCreateImage2D {{{
 * \brief Default mock for clCreateImage2D OpenCL function.
 */ // }}}
class Pluggable_clCreateImage2D
  : public T::Base_clCreateImage2D,
    public T::Pluggable_Function<cl_mem (*) ( cl_context,
                                              cl_mem_flags,
                                              const cl_image_format*,
                                              size_t,
                                              size_t,
                                              size_t,
                                              void*,
                                              cl_int* )>
{
  cl_mem clCreateImage2D( cl_context context, cl_mem_flags flags,
                        const cl_image_format* image_format,
                        size_t image_width, size_t image_height,
                        size_t image_row_pitch, void* host_ptr,
                        cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateImage2D() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateImage2D(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage3D)
/** // doc: Pluggable_clCreateImage3D {{{
 * \brief Default mock for clCreateImage3D OpenCL function.
 */ // }}}
class Pluggable_clCreateImage3D
  : public T::Base_clCreateImage3D,
    public T::Pluggable_Function<cl_mem (*) ( cl_context,
                                              cl_mem_flags,
                                              const cl_image_format*,
                                              size_t,
                                              size_t,
                                              size_t,
                                              size_t,
                                              size_t,
                                              void*,
                                              cl_int* )>
{
  cl_mem clCreateImage3D( cl_context context, cl_mem_flags flags,
                          const cl_image_format* image_format,
                          size_t image_width, size_t image_height,
                          size_t image_depth, size_t image_row_pitch,
                          size_t image_slice_pitch, void* host_ptr,
                          cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateImage3D() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateImage3D(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernel)
/** // doc: Pluggable_clCreateKernel {{{
 * \brief Default mock for clCreateKernel OpenCL function.
 */ // }}}
class Pluggable_clCreateKernel
  : public T::Base_clCreateKernel,
    public T::Pluggable_Function<cl_kernel (*) ( cl_program,
                                                 const char*,
                                                 cl_int* )>
{
  cl_kernel clCreateKernel(
      cl_program program,
      const char* kernel_name,
      cl_int* errcode_ret
  );
public:
  /** // doc: Pluggable_clCreateKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernelsInProgram)
/** // doc: Pluggable_clCreateKernelsInProgram {{{
 * \brief Default mock for clCreateKernelsInProgram OpenCL function.
 */ // }}}
class Pluggable_clCreateKernelsInProgram
  : public T::Base_clCreateKernelsInProgram,
    public T::Pluggable_Function<cl_int (*) ( cl_program,
                                              cl_uint,
                                              cl_kernel*,
                                              cl_uint* )>
{
  cl_int clCreateKernelsInProgram(
      cl_program program,
      cl_uint num_kernels,
      cl_kernel* kernels,
      cl_uint* num_kernels_ret
  );
public:
  /** // doc: Pluggable_clCreateKernelsInProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateKernelsInProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreatePipe)
/** // doc: Pluggable_clCreatePipe {{{
 * \brief Default mock for clCreatePipe OpenCL function.
 */ // }}}
class Pluggable_clCreatePipe
  : public T::Base_clCreatePipe,
    public T::Pluggable_Function<cl_mem (*) ( cl_context,
                                              cl_mem_flags,
                                              cl_uint,
                                              cl_uint,
                                              const cl_pipe_properties*,
                                              cl_int* )>
{
  cl_mem clCreatePipe( cl_context context, cl_mem_flags flags,
                       cl_uint pipe_packet_size, cl_uint pipe_max_packets,
                       const cl_pipe_properties* properties,
                       cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreatePipe() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreatePipe(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBinary)
/** // doc: Pluggable_clCreateProgramWithBinary {{{
 * \brief Default mock for clCreateProgramWithBinary OpenCL function.
 */ // }}}
class Pluggable_clCreateProgramWithBinary
  : public T::Base_clCreateProgramWithBinary,
    public T::Pluggable_Function<cl_program (*) ( cl_context,
                                                  cl_uint,
                                                  const cl_device_id*,
                                                  const size_t*,
                                                  const unsigned char**,
                                                  cl_int*,
                                                  cl_int* )>
{
  cl_program clCreateProgramWithBinary(cl_context context,
                                       cl_uint num_devices,
                                       const cl_device_id* device_list,
                                       const size_t* lengths,
                                       const unsigned char** binaries,
                                       cl_int* binary_status,
                                       cl_int* errcode_ret);
public:
  /** // doc: Pluggable_clCreateProgramWithBinary() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateProgramWithBinary(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBuiltInKernels)
/** // doc: Pluggable_clCreateProgramWithBuiltInKernels {{{
 * \brief Default mock for clCreateProgramWithBuiltInKernels OpenCL function.
 */ // }}}
class Pluggable_clCreateProgramWithBuiltInKernels
  : public T::Base_clCreateProgramWithBuiltInKernels,
    public T::Pluggable_Function<cl_program (*) ( cl_context,
                                                  cl_uint,
                                                  const cl_device_id*,
                                                  const char*,
                                                  cl_int* )>
{
  cl_program clCreateProgramWithBuiltInKernels(cl_context context,
                                               cl_uint num_devices,
                                               const cl_device_id* device_list,
                                               const char* kernel_names,
                                               cl_int* errcode_ret);
public:
  /** // doc: Pluggable_clCreateProgramWithBuiltInKernels() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateProgramWithBuiltInKernels(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithIL)
/** // doc: Pluggable_clCreateProgramWithIL {{{
 * \brief Default mock for clCreateProgramWithIL OpenCL function.
 */ // }}}
class Pluggable_clCreateProgramWithIL
  : public T::Base_clCreateProgramWithIL,
    public T::Pluggable_Function<cl_program (*) ( cl_context,
                                                  const void*,
                                                  size_t,
                                                  cl_int* )>
{
  cl_program clCreateProgramWithIL(cl_context context,
                                   const void* il,
                                   size_t length,
                                   cl_int* errcode_ret);
public:
  /** // doc: Pluggable_clCreateProgramWithIL() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateProgramWithIL(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithSource)
/** // doc: Pluggable_clCreateProgramWithSource {{{
 * \brief Default mock for clCreateProgramWithSource OpenCL function.
 */ // }}}
class Pluggable_clCreateProgramWithSource
  : public T::Base_clCreateProgramWithSource,
    public T::Pluggable_Function<cl_program (*) ( cl_context,
                                                  cl_uint,
                                                  const char**,
                                                  const size_t*,
                                                  cl_int* )>
{
  cl_program clCreateProgramWithSource(cl_context context,
                                       cl_uint count,
                                       const char** strings,
                                       const size_t* lengths,
                                       cl_int* errcode_ret);
public:
  /** // doc: Pluggable_clCreateProgramWithSource() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateProgramWithSource(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSampler)
/** // doc: Pluggable_clCreateSampler {{{
 * \brief Default mock for clCreateSampler OpenCL function.
 */ // }}}
class Pluggable_clCreateSampler
  : public T::Base_clCreateSampler,
    public T::Pluggable_Function<cl_sampler (*) ( cl_context,
                                                  cl_bool,
                                                  cl_addressing_mode,
                                                  cl_filter_mode,
                                                  cl_int* )>
{
  cl_sampler clCreateSampler( cl_context context, cl_bool normalized_coords,
                              cl_addressing_mode addressing_mode, cl_filter_mode
                              filter_mode, cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateSampler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateSampler(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSamplerWithProperties)
/** // doc: Pluggable_clCreateSamplerWithProperties {{{
 * \brief Default mock for clCreateSamplerWithProperties OpenCL function.
 */ // }}}
class Pluggable_clCreateSamplerWithProperties
  : public T::Base_clCreateSamplerWithProperties,
    public T::Pluggable_Function<cl_sampler (*) ( cl_context,
                                                  const cl_sampler_properties*,
                                                  cl_int* )>
{
  cl_sampler clCreateSamplerWithProperties( cl_context context,
                                            const cl_sampler_properties* sampler_properties,
                                            cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateSamplerWithProperties() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateSamplerWithProperties(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubBuffer)
/** // doc: Pluggable_clCreateSubBuffer {{{
 * \brief Default mock for clCreateSubBuffer OpenCL function.
 */ // }}}
class Pluggable_clCreateSubBuffer
  : public T::Base_clCreateSubBuffer,
    public T::Pluggable_Function<cl_mem (*) ( cl_mem,
                                              cl_mem_flags,
                                              cl_buffer_create_type,
                                              const void*,
                                              cl_int* )>
{
  cl_mem clCreateSubBuffer( cl_mem buffer, cl_mem_flags flags,
                            cl_buffer_create_type buffer_create_type,
                            const void* buffer_create_info,
                            cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateSubBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateSubBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
/** // doc: Pluggable_clCreateSubDevices {{{
 * \brief Default mock for clCreateSubDevices OpenCL function.
 */ // }}}
class Pluggable_clCreateSubDevices
  : public T::Base_clCreateSubDevices,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id,
                                              const cl_device_partition_property*,
                                              cl_uint,
                                              cl_device_id*,
                                              cl_uint* )>
{
  cl_int clCreateSubDevices(cl_device_id in_device,
                            const cl_device_partition_property* properties,
                            cl_uint num_devices,
                            cl_device_id* out_devices,
                            cl_uint* num_devices_ret);
public:
  /** // doc: Pluggable_clCreateSubDevices() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateSubDevices(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clCreateUserEvent)
/** // doc: Pluggable_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom event handle predefined by user.
 */ // }}}
class Pluggable_clCreateUserEvent
  : public T::Base_clCreateUserEvent,
    public T::Pluggable_Function<cl_event (*) ( cl_context,
                                                cl_int* )>
{
  cl_event clCreateUserEvent( cl_context context, cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clCreateUserEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clCreateUserEvent(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrier)
/** // doc: Pluggable_clEnqueueBarrier {{{
 * \brief Default mock for clEnqueueBarrier OpenCL function.
 */ // }}}
class Pluggable_clEnqueueBarrier
  : public T::Base_clEnqueueBarrier,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue )>
{
  cl_int clEnqueueBarrier( cl_command_queue command_queue );
public:
  /** // doc: Pluggable_clEnqueueBarrier() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueBarrier(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrierWithWaitList)
/** // doc: Pluggable_clEnqueueBarrierWithWaitList {{{
 * \brief Default mock for clEnqueueBarrierWithWaitList OpenCL function.
 */ // }}}
class Pluggable_clEnqueueBarrierWithWaitList
  : public T::Base_clEnqueueBarrierWithWaitList,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueBarrierWithWaitList( cl_command_queue command_queue,
                                       cl_uint num_events_in_wait_list,
                                       const cl_event* event_wait_list,
                                       cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueBarrierWithWaitList() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueBarrierWithWaitList(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBuffer)
/** // doc: Pluggable_clEnqueueCopyBuffer {{{
 * \brief Default mock for clEnqueueCopyBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueCopyBuffer
  : public T::Base_clEnqueueCopyBuffer,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_mem,
                                              size_t,
                                              size_t,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueCopyBuffer( cl_command_queue command_queue,
                              cl_mem src_buffer, cl_mem dst_buffer,
                              size_t src_offset, size_t dst_offset,
                              size_t size, cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueCopyBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueCopyBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferRect)
/** // doc: Pluggable_clEnqueueCopyBuffer {{{
 * \brief Default mock for clEnqueueCopyBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueCopyBufferRect
  : public T::Base_clEnqueueCopyBufferRect,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_mem,
                                              const size_t*,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              size_t,
                                              size_t,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueCopyBufferRect( cl_command_queue command_queue,
                                  cl_mem src_buffer,
                                  cl_mem dst_buffer,
                                  const size_t* src_origin,
                                  const size_t* dst_origin,
                                  const size_t* region,
                                  size_t src_row_pitch,
                                  size_t src_slice_pitch,
                                  size_t dst_row_pitch,
                                  size_t dst_slice_pitch,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event* event_wait_list,
                                  cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueCopyBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueCopyBufferRect(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferToImage)
/** // doc: Pluggable_clEnqueueCopyBufferToImage {{{
 * \brief Default mock for clEnqueueCopyBufferToImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueCopyBufferToImage
  : public T::Base_clEnqueueCopyBufferToImage,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_mem,
                                              size_t,
                                              const size_t*,
                                              const size_t*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueCopyBufferToImage( cl_command_queue command_queue,
                                     cl_mem src_buffer,
                                     cl_mem dst_image,
                                     size_t src_offset,
                                     const size_t* dst_origin,
                                     const size_t* region,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueCopyBufferToImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueCopyBufferToImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImage)
/** // doc: Pluggable_clEnqueueCopyImage {{{
 * \brief Default mock for clEnqueueCopyImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueCopyImage
  : public T::Base_clEnqueueCopyImage,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_mem,
                                              const size_t*,
                                              const size_t*,
                                              const size_t*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueCopyImage( cl_command_queue command_queue, cl_mem src_image,
                             cl_mem dst_image, const size_t* src_origin,
                             const size_t* dst_origin, const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueCopyImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueCopyImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImageToBuffer)
/** // doc: Pluggable_clEnqueueCopyImageToBuffer {{{
 * \brief Default mock for clEnqueueCopyImageToBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueCopyImageToBuffer
  : public T::Base_clEnqueueCopyImageToBuffer,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_mem,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueCopyImageToBuffer( cl_command_queue command_queue,
                                     cl_mem src_image,
                                     cl_mem dst_buffer,
                                     const size_t* src_origin,
                                     const size_t* region,
                                     size_t dst_offset,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueCopyImageToBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueCopyImageToBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillBuffer)
/** // doc: Pluggable_clEnqueueFillBuffer {{{
 * \brief Default mock for clEnqueueFillBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueFillBuffer
  : public T::Base_clEnqueueFillBuffer,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              const void *,
                                              size_t,
                                              size_t,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueFillBuffer( cl_command_queue command_queue, cl_mem buffer,
                              const void *pattern, size_t pattern_size,
                              size_t offset, size_t size,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueFillBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueFillBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillImage)
/** // doc: Pluggable_clEnqueueFillImage {{{
 * \brief Default mock for clEnqueueFillImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueFillImage
  : public T::Base_clEnqueueFillImage,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              const void*,
                                              const size_t*,
                                              const size_t*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueFillImage( cl_command_queue command_queue,
                             cl_mem image,
                             const void *fill_color,
                             const size_t* origin,
                             const size_t* region,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueFillImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueFillImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapBuffer)
/** // doc: Pluggable_clEnqueueMapBuffer {{{
 * \brief Default mock for clEnqueueMapBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueMapBuffer
  : public T::Base_clEnqueueMapBuffer,
    public T::Pluggable_Function<void* (*) ( cl_command_queue,
                                             cl_mem,
                                             cl_bool,
                                             cl_map_flags,
                                             size_t,
                                             size_t,
                                             cl_uint,
                                             const cl_event*,
                                             cl_event*,
                                             cl_int* )>
{
  void* clEnqueueMapBuffer( cl_command_queue command_queue, cl_mem buffer,
                            cl_bool blocking_map, cl_map_flags map_flags,
                            size_t offset, size_t size,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event, cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clEnqueueMapBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueMapBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapImage)
/** // doc: Pluggable_clEnqueueMapImage {{{
 * \brief Default mock for clEnqueueMapImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueMapImage
  : public T::Base_clEnqueueMapImage,
    public T::Pluggable_Function<void* (*) ( cl_command_queue,
                                             cl_mem,
                                             cl_bool,
                                             cl_map_flags,
                                             const size_t*,
                                             const size_t*,
                                             size_t*,
                                             size_t*,
                                             cl_uint,
                                             const cl_event*,
                                             cl_event*,
                                             cl_int* )>
{
  void* clEnqueueMapImage( cl_command_queue command_queue,
                           cl_mem image,
                           cl_bool blocking_map,
                           cl_map_flags map_flags,
                           const size_t* origin,
                           const size_t* region,
                           size_t* image_row_pitch,
                           size_t* image_slice_pitch,
                           cl_uint num_events_in_wait_list,
                           const cl_event* event_wait_list,
                           cl_event* event,
                           cl_int* errcode_ret );
public:
  /** // doc: Pluggable_clEnqueueMapImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueMapImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarker)
/** // doc: Pluggable_clEnqueueMarker {{{
 * \brief Default mock for clEnqueueMarker OpenCL function.
 */ // }}}
class Pluggable_clEnqueueMarker
  : public T::Base_clEnqueueMarker,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_event* )>
{
  cl_int clEnqueueMarker( cl_command_queue command_queue,
                          cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueMarker() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueMarker(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarkerWithWaitList)
/** // doc: Pluggable_clEnqueueMarkerWithWaitList {{{
 * \brief Default mock for clEnqueueMarkerWithWaitList OpenCL function.
 */ // }}}
class Pluggable_clEnqueueMarkerWithWaitList
  : public T::Base_clEnqueueMarkerWithWaitList,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueMarkerWithWaitList( cl_command_queue command_queue,
                                      cl_uint num_events_in_wait_list,
                                      const cl_event* event_wait_list,
                                      cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueMarkerWithWaitList() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueMarkerWithWaitList(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMigrateMemObjects)
/** // doc: Pluggable_clEnqueueMigrateMemObjects {{{
 * \brief Default mock for clEnqueueMigrateMemObjects OpenCL function.
 */ // }}}
class Pluggable_clEnqueueMigrateMemObjects
  : public T::Base_clEnqueueMigrateMemObjects,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              const cl_mem*,
                                              cl_mem_migration_flags,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueMigrateMemObjects( cl_command_queue command_queue,
                                     cl_uint num_mem_objects,
                                     const cl_mem* mem_objects,
                                     cl_mem_migration_flags flags,
                                     cl_uint num_events_in_wait_list,
                                     const cl_event* event_wait_list,
                                     cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueMigrateMemObjects() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueMigrateMemObjects(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNativeKernel)
/** // doc: Pluggable_clEnqueueNativeKernel {{{
 * \brief Mock for clEnqueueNativeKernel OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clEnqueueNativeKernel
  : public T::Base_clEnqueueNativeKernel,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              void (CL_CALLBACK*)(void*),
                                              void*,
                                              size_t,
                                              cl_uint,
                                              const cl_mem*,
                                              const void**,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueNativeKernel( cl_command_queue command_queue,
                                void (CL_CALLBACK* user_func)(void*),
                                void* args,
                                size_t cb_args,
                                cl_uint num_mem_objects,
                                const cl_mem* mem_list,
                                const void** args_mem_loc,
                                cl_uint num_events_in_wait_list,
                                const cl_event* event_wait_list,
                                cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueNativeKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueNativeKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNDRangeKernel)
/** // doc: Pluggable_clEnqueueNDRangeKernel {{{
 * \brief Mock for clEnqueueNDRangeKernel OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clEnqueueNDRangeKernel
  : public T::Base_clEnqueueNDRangeKernel,
    public T::Pluggable_Function< cl_int (*) ( cl_command_queue,
                                               cl_kernel,
                                               cl_uint,
                                               const size_t*,
                                               const size_t*,
                                               const size_t*,
                                               cl_uint,
                                               const cl_event*,
                                               cl_event* )>
{
  cl_int clEnqueueNDRangeKernel( cl_command_queue command_queue,
                                 cl_kernel kernel,
                                 cl_uint work_dim,
                                 const size_t* global_work_offset,
                                 const size_t* global_work_size,
                                 const size_t* local_work_size,
                                 cl_uint num_events_in_wait_list,
                                 const cl_event* event_wait_list,
                                 cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueNDRangeKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueNDRangeKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBuffer)
/** // doc: Pluggable_clEnqueueReadBuffer {{{
 * \brief Default mock for clEnqueueReadBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueReadBuffer
  : public T::Base_clEnqueueReadBuffer,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              size_t,
                                              size_t,
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueReadBuffer( cl_command_queue command_queue,
                              cl_mem buffer, cl_bool blocking_read,
                              size_t offset, size_t size, void* ptr,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueReadBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueReadBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBufferRect)
/** // doc: Pluggable_clEnqueueReadBufferRect {{{
 * \brief Default mock for clEnqueueReadBufferRect OpenCL function.
 */ // }}}
class Pluggable_clEnqueueReadBufferRect
  : public T::Base_clEnqueueReadBufferRect,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              const size_t*,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              size_t,
                                              size_t,
                                              size_t,
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueReadBufferRect( cl_command_queue command_queue,
                                  cl_mem buffer, cl_bool blocking_read,
                                  const size_t* buffer_origin,
                                  const size_t* host_origin,
                                  const size_t* region,
                                  size_t buffer_row_pitch,
                                  size_t buffer_splice_pitch,
                                  size_t host_row_pitch,
                                  size_t host_slice_pitch,
                                  void* ptr,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event* event_wait_list,
                                  cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueReadBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueReadBufferRect(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadImage)
/** // doc: Pluggable_clEnqueueReadImage {{{
 * \brief Default mock for clEnqueueReadImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueReadImage
  : public T::Base_clEnqueueReadImage,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              size_t,
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueReadImage( cl_command_queue command_queue,
                             cl_mem image,
                             cl_bool blocking_read,
                             const size_t* origin,
                             const size_t* region,
                             size_t row_pitch,
                             size_t slice_pitch,
                             void* ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueReadImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueReadImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMFree)
/** // doc: Pluggable_clEnqueueSVMFree {{{
 * \brief Default mock for clEnqueueSVMFree OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMFree
  : public T::Base_clEnqueueSVMFree,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              void*,
                                              void(CL_CALLBACK*)(cl_command_queue, cl_uint, void**, void*),
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMFree(cl_command_queue command_queue,
                          cl_uint num_svm_pointers, void* svm_pointers[],
                          void(CL_CALLBACK* pfn_free_func)(cl_command_queue, cl_uint, void*[], void*),
                          void* user_data, cl_uint num_events_in_wait_list,
                          const cl_event* event_wait_list, cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueSVMFree() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMFree(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMap)
/** // doc: Pluggable_clEnqueueSVMMap {{{
 * \brief Default mock for clEnqueueSVMMap OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMMap
  : public T::Base_clEnqueueSVMMap,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_bool,
                                              cl_map_flags,
                                              void*,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMMap(cl_command_queue command_queue, cl_bool blocking_map,
                         cl_map_flags map_flags, void* svm_ptr, size_t size,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list, cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueSVMMap() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMMap(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemFill)
/** // doc: Pluggable_clEnqueueSVMMemFill {{{
 * \brief Default mock for clEnqueueSVMMemFill OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMMemFill
  : public T::Base_clEnqueueSVMMemFill,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              void*,
                                              const void*,
                                              size_t,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMMemFill(cl_command_queue command_queue, void* svm_ptr,
                             const void* pattern, size_t pattern_size,
                             size_t size, cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list, cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueSVMMemFill() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMMemFill(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemcpy)
/** // doc: Pluggable_clEnqueueSVMMemcpy {{{
 * \brief Default mock for clEnqueueSVMMemcpy OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMMemcpy
  : public T::Base_clEnqueueSVMMemcpy,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_bool,
                                              void*,
                                              const void*,
                                              size_t,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMMemcpy(cl_command_queue command_queue,
                            cl_bool blocking_copy, void* dst_ptr,
                            const void* src_ptr, size_t size,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list, cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueSVMMemcpy() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMMemcpy(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMigrateMem)
/** // doc: Pluggable_clEnqueueSVMMigrateMem {{{
 * \brief Default mock for clEnqueueSVMMigrateMem OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMMigrateMem
  : public T::Base_clEnqueueSVMMigrateMem,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              const void**,
                                              const size_t*,
                                              cl_mem_migration_flags,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMMigrateMem(cl_command_queue command_queue,
                                cl_uint num_svm_pointers,
                                const void** svm_pointers, const size_t* sizes,
                                cl_mem_migration_flags flags,
                                cl_uint num_events_in_wait_list,
                                const cl_event* event_wait_list,
                                cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueSVMMigrateMem() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMMigrateMem(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMUnmap)
/** // doc: Pluggable_clEnqueueSVMUnmap {{{
 * \brief Default mock for clEnqueueSVMUnmap OpenCL function.
 */ // }}}
class Pluggable_clEnqueueSVMUnmap
  : public T::Base_clEnqueueSVMUnmap,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueSVMUnmap(cl_command_queue command_queue, void* svm_ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list, cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueSVMUnmap() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueSVMUnmap(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueTask)
/** // doc: Pluggable_clEnqueueTask {{{
 * \brief Default mock for clEnqueueTask OpenCL function.
 */ // }}}
class Pluggable_clEnqueueTask
  : public T::Base_clEnqueueTask,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_kernel,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueTask( cl_command_queue command_queue,
                        cl_kernel kernel,
                        cl_uint num_events_in_wait_list,
                        const cl_event* event_wait_list,
                        cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueTask() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueTask(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueUnmapMemObject)
/** // doc: Pluggable_clEnqueueUnmapMemObject {{{
 * \brief Default mock for clEnqueueUnmapMemObject OpenCL function.
 */ // }}}
class Pluggable_clEnqueueUnmapMemObject
  : public T::Base_clEnqueueUnmapMemObject,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueUnmapMemObject( cl_command_queue command_queue,
                                  cl_mem memobj,
                                  void* mapped_ptr,
                                  cl_uint num_events_in_wait_list,
                                  const cl_event* event_wait_list,
                                  cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueUnmapMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueUnmapMemObject(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWaitForEvents)
/** // doc: Pluggable_clEnqueueWaitForEvents {{{
 * \brief Default mock for clEnqueueWaitForEvents OpenCL function.
 */ // }}}
class Pluggable_clEnqueueWaitForEvents
  : public T::Base_clEnqueueWaitForEvents,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_uint,
                                              const cl_event* )>
{
  cl_int clEnqueueWaitForEvents( cl_command_queue command_queue,
                                 cl_uint num_events_,
                                 const cl_event* event_list );
public:
  /** // doc: Pluggable_clEnqueueWaitForEvents() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueWaitForEvents(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBuffer)
/** // doc: Pluggable_clEnqueueWriteBuffer {{{
 * \brief Default mock for clEnqueueWriteBuffer OpenCL function.
 */ // }}}
class Pluggable_clEnqueueWriteBuffer
  : public T::Base_clEnqueueWriteBuffer,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              size_t,
                                              size_t,
                                              const void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueWriteBuffer( cl_command_queue command_queue,
                               cl_mem buffer, cl_bool blocking_read,
                               size_t offset, size_t size, const void* ptr,
                               cl_uint num_events_in_wait_list,
                               const cl_event* event_wait_list,
                               cl_event* event);
public:
  /** // doc: Pluggable_clEnqueueWriteBuffer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueWriteBuffer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBufferRect)
/** // doc: Pluggable_clEnqueueWriteBufferRect {{{
 * \brief Default mock for clEnqueueWriteBufferRect OpenCL function.
 */ // }}}
class Pluggable_clEnqueueWriteBufferRect
  : public T::Base_clEnqueueWriteBufferRect,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              const size_t*,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              size_t,
                                              size_t,
                                              size_t,
                                              const void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueWriteBufferRect( cl_command_queue command_queue,
                                      cl_mem buffer, cl_bool blocking_read,
                                      const size_t* buffer_origin,
                                      const size_t* host_origin,
                                      const size_t* region,
                                      size_t buffer_row_pitch,
                                      size_t buffer_splice_pitch,
                                      size_t host_row_pitch,
                                      size_t host_slice_pitch,
                                      const void* ptr,
                                      cl_uint num_events_in_wait_list,
                                      const cl_event* event_wait_list,
                                      cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueWriteBufferRect() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueWriteBufferRect(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteImage)
/** // doc: Pluggable_clEnqueueWriteImage {{{
 * \brief Default mock for clEnqueueWriteImage OpenCL function.
 */ // }}}
class Pluggable_clEnqueueWriteImage
  : public T::Base_clEnqueueWriteImage,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_mem,
                                              cl_bool,
                                              const size_t*,
                                              const size_t*,
                                              size_t,
                                              size_t,
                                              const void*,
                                              cl_uint,
                                              const cl_event*,
                                              cl_event* )>
{
  cl_int clEnqueueWriteImage( cl_command_queue command_queue,
                              cl_mem image,
                              cl_bool blocking_read,
                              const size_t* origin,
                              const size_t* region,
                              size_t input_row_pitch,
                              size_t input_slice_pitch,
                              const void* ptr,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event );
public:
  /** // doc: Pluggable_clEnqueueWriteImage() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clEnqueueWriteImage(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clFinish)
/** // doc: Pluggable_clFinish {{{
 * \brief Default mock for clFinish OpenCL function.
 */ // }}}
class Pluggable_clFinish
  : public T::Base_clFinish,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue )>
{
  cl_int clFinish(cl_command_queue);
public:
  /** // doc: Pluggable_clFinish() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clFinish(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clFlush)
/** // doc: Pluggable_clFlush {{{
 * \brief Default mock for clFlush OpenCL function.
 */ // }}}
class Pluggable_clFlush
  : public T::Base_clFlush,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue )>
{
  cl_int clFlush(cl_command_queue);
public:
  /** // doc: Pluggable_clFlush() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clFlush(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetCommandQueueInfo)
/** // doc: Pluggable_clGetCommandQueueInfo {{{
 * \brief Default mock for clGetCommandQueueInfo OpenCL function.
 */ // }}}
class Pluggable_clGetCommandQueueInfo
  : public T::Base_clGetCommandQueueInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_command_queue_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetCommandQueueInfo(cl_command_queue command_queue,
                               cl_command_queue_info param_name,
                               size_t param_value_size, void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetCommandQueueInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetCommandQueueInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetContextInfo)
/** // doc: Pluggable_clGetContextInfo {{{
 * \brief Default mock for clGetContextInfo OpenCL function.
 */ // }}}
class Pluggable_clGetContextInfo
  : public T::Base_clGetContextInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_context,
                                              cl_context_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetContextInfo(cl_context context, cl_context_info param_name,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetContextInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetContextInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceAndHostTimer)
/** // doc: Pluggable_clGetDeviceAndHostTimer {{{
 * \brief Default mock for clGetDeviceAndHostTimer OpenCL function.
 */ // }}}
class Pluggable_clGetDeviceAndHostTimer
  : public T::Base_clGetDeviceAndHostTimer,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id,
                                              cl_ulong*,
                                              cl_ulong* )>
{
  cl_int clGetDeviceAndHostTimer(cl_device_id device, cl_ulong* device_timestamp,
                                 cl_ulong* host_timestamp);
public:
  /** // doc: Pluggable_clGetDeviceAndHostTimer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetDeviceAndHostTimer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceIDs)
/** // doc: Pluggable_clGetDeviceIDs {{{
 * \brief Mock for clGetDeviceIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Pluggable_clGetDeviceIDs
  : public T::Base_clGetDeviceIDs,
    public T::Pluggable_Function<cl_int (*) ( cl_platform_id,
                                              cl_device_type,
                                              cl_uint,
                                              cl_device_id*,
                                              cl_uint*  )>
{
  cl_int clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
                        cl_uint num_entries, cl_device_id* devices,
                        cl_uint* num_devices);
public:
  /** // doc: Pluggable_clGetDeviceIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   *        \p devices array is stored
   */ // }}}
  Pluggable_clGetDeviceIDs(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceInfo)
/** // doc: Pluggable_clGetDeviceInfo {{{
 * \brief Mock for clGetDeviceInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetDeviceInfo
  : public T::Base_clGetDeviceInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id,
                                              cl_device_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetDeviceInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetDeviceInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetEventInfo)
/** // doc: Pluggable_clGetEventInfo {{{
 * \brief Mock for clGetEventInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetEventInfo
  : public T::Base_clGetEventInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_event,
                                              cl_event_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetEventInfo(cl_event event, cl_event_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetEventInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetEventInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetEventProfilingInfo)
/** // doc: Pluggable_clGetEventProfilingInfo {{{
 * \brief Mock for clGetEventProfilingInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetEventProfilingInfo
  : public T::Base_clGetEventProfilingInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_event,
                                              cl_profiling_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetEventProfilingInfo(cl_event kernel, cl_profiling_info param_name,
                                 size_t param_value_size, void* param_value,
                                 size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetEventProfilingInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetEventProfilingInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddress)
/** // doc: Pluggable_clGetExtensionFunctionAddress {{{
 * \brief Mock for clGetExtensionFunctionAddress OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetExtensionFunctionAddress
  : public T::Base_clGetExtensionFunctionAddress,
    public T::Pluggable_Function<void* (*) ( const char* )>
{
  void* clGetExtensionFunctionAddress(const char* funcname);
public:
  /** // doc: Pluggable_clGetExtensionFunctionAddress() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetExtensionFunctionAddress(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddressForPlatform)
/** // doc: Pluggable_clGetExtensionFunctionAddressForPlatform {{{
 * \brief Mock for clGetExtensionFunctionAddressForPlatform OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetExtensionFunctionAddressForPlatform
  : public T::Base_clGetExtensionFunctionAddressForPlatform,
    public T::Pluggable_Function<void* (*) ( cl_platform_id,
                                             const char* )>
{
  void* clGetExtensionFunctionAddressForPlatform(cl_platform_id platform,
                                                 const char* funcname);
public:
  /** // doc: Pluggable_clGetExtensionFunctionAddressForPlatform() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetExtensionFunctionAddressForPlatform(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetHostTimer)
/** // doc: Pluggable_clGetHostTimer {{{
 * \brief Default mock for clGetHostTimer OpenCL function.
 */ // }}}
class Pluggable_clGetHostTimer
  : public T::Base_clGetHostTimer,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id,
                                              cl_ulong* )>
{
  cl_int clGetHostTimer(cl_device_id device, cl_ulong* host_timestamp);
public:
  /** // doc: Pluggable_clGetHostTimer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetHostTimer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetImageInfo)
/** // doc: Pluggable_clGetImageInfo {{{
 * \brief Mock for clGetImageInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetImageInfo
  : public T::Base_clGetImageInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_mem,
                                              cl_image_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetImageInfo(cl_mem image, cl_image_info param_name,
                        size_t param_value_size, void* param_value,
                        size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetImageInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetImageInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
/** // doc: Pluggable_clGetKernelArgInfo {{{
 * \brief Mock for clGetKernelArgInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetKernelArgInfo
  : public T::Base_clGetKernelArgInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_uint,
                                              cl_kernel_arg_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index,
                            cl_kernel_arg_info param_name,
                            size_t param_value_size, void* param_value,
                            size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetKernelArgInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetKernelArgInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelInfo)
/** // doc: Pluggable_clGetKernelInfo {{{
 * \brief Mock for clGetKernelInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetKernelInfo
  : public T::Base_clGetKernelInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_kernel_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetKernelInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetKernelInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelWorkGroupInfo)
/** // doc: Pluggable_clGetKernelWorkGroupInfo {{{
 * \brief Mock for clGetKernelWorkGroupInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetKernelWorkGroupInfo
  : public T::Base_clGetKernelWorkGroupInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_device_id,
                                              cl_kernel_work_group_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device,
                                  cl_kernel_work_group_info param_name,
                                  size_t param_value_size, void* param_value,
                                  size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetKernelWorkGroupInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetKernelWorkGroupInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelSubGroupInfo)
/** // doc: Pluggable_clGetKernelSubGroupInfo {{{
 * \brief Mock for clGetKernelSubGroupInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetKernelSubGroupInfo
  : public T::Base_clGetKernelSubGroupInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_device_id,
                                              cl_kernel_sub_group_info,
                                              size_t,
                                              const void*,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetKernelSubGroupInfo(cl_kernel kernel, cl_device_id device,
                                  cl_kernel_sub_group_info param_name,
                                  size_t input_value_size, const void* input_value,
                                  size_t param_value_size, void* param_value,
                                  size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetKernelSubGroupInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetKernelSubGroupInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetMemObjectInfo)
/** // doc: Pluggable_clGetMemObjectInfo {{{
 * \brief Mock for clGetMemObjectInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetMemObjectInfo
  : public T::Base_clGetMemObjectInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_mem,
                                              cl_mem_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetMemObjectInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetMemObjectInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetPipeInfo)
/** // doc: Pluggable_clGetPipeInfo {{{
 * \brief Mock for clGetPipeInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetPipeInfo
  : public T::Base_clGetPipeInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_mem,
                                              cl_pipe_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetPipeInfo(cl_mem pipe, cl_pipe_info param_name,
                       size_t param_value_size, void* param_value,
                       size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetPipeInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetPipeInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformIDs)
/** // doc: Pluggable_clGetPlatformIDs {{{
 * \brief Mock for clGetPlatformIDs OpenCL function.
 *
 * When queried for the size of a string data being returned, the mock returns
 * a negative value. It's intended to cause the std::bad_alloc to be raised in
 * a calling code.
 */ // }}}
class Pluggable_clGetPlatformIDs
  : public T::Base_clGetPlatformIDs,
    public T::Pluggable_Function<cl_int (*) ( cl_uint,
                                              cl_platform_id*,
                                              cl_uint* )>
{
  cl_int clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                          cl_uint* num_platforms);
public:
  /** // doc: Pluggable_clGetPlatformIDs() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   *        platforms array is stored
   */ // }}}
  Pluggable_clGetPlatformIDs(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformInfo)
/** // doc: Pluggable_clGetPlatformInfo {{{
 * \brief Mock for clGetPlatformInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetPlatformInfo
  : public T::Base_clGetPlatformInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_platform_id,
                                              cl_platform_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetPlatformInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetPlatformInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramBuildInfo)
/** // doc: Pluggable_clGetProgramBuildInfo {{{
 * \brief Mock for clGetProgramBuildInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetProgramBuildInfo
  : public T::Base_clGetProgramBuildInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_program,
                                              cl_device_id,
                                              cl_program_build_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetProgramBuildInfo(cl_program program,
                               cl_device_id device,
                               cl_program_build_info param_name,
                               size_t param_value_size,
                               void* param_value,
                               size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetProgramBuildInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetProgramBuildInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramInfo)
/** // doc: Pluggable_clGetProgramInfo {{{
 * \brief Mock for clGetProgramInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetProgramInfo
  : public T::Base_clGetProgramInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_program,
                                              cl_program_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int clGetProgramInfo(cl_program program, cl_program_info param_name,
                           size_t param_value_size, void* param_value,
                           size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetProgramInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetProgramInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetSamplerInfo)
/** // doc: Pluggable_clGetSamplerInfo {{{
 * \brief Mock for clGetSamplerInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clGetSamplerInfo
  : public T::Base_clGetSamplerInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_sampler,
                                              cl_sampler_info,
                                              size_t,
                                              void*,
                                              size_t* )>
{
  cl_int _err;
  cl_int clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name,
                          size_t param_value_size, void* param_value,
                          size_t* param_value_size_ret);
public:
  /** // doc: Pluggable_clGetSamplerInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetSamplerInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clGetSupportedImageFormats)
/** // doc: Pluggable_clGetSupportedImageFormats {{{
 * \brief Default mock for clGetSupportedImageFormats OpenCL function.
 */ // }}}
class Pluggable_clGetSupportedImageFormats
  : public T::Base_clGetSupportedImageFormats,
    public T::Pluggable_Function<cl_int (*) ( cl_context,
                                              cl_mem_flags,
                                              cl_mem_object_type,
                                              cl_uint,
                                              cl_image_format*,
                                              cl_uint* )>
{
  cl_int clGetSupportedImageFormats( cl_context context, cl_mem_flags flags,
                                     cl_mem_object_type image_type,
                                     cl_uint num_entries,
                                     cl_image_format* image_formats,
                                     cl_uint* num_image_formats);
public:
  /** // doc: Pluggable_clGetSupportedImageFormats() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clGetSupportedImageFormats(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clLinkProgram)
/** // doc: Pluggable_clLinkProgram {{{
 * \brief Default mock for clLinkProgram OpenCL function.
 */ // }}}
class Pluggable_clLinkProgram
  : public T::Base_clLinkProgram,
    public T::Pluggable_Function<cl_program (*) ( cl_context,
                                                  cl_uint,
                                                  const cl_device_id*,
                                                  const char*,
                                                  cl_uint,
                                                  const cl_program*,
                                                  void (CL_CALLBACK*)(cl_program, void*),
                                                  void*,
                                                  cl_int* )>
{
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
  /** // doc: Pluggable_clLinkProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clLinkProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseCommandQueue)
/** // doc: Pluggable_clReleaseCommandQueue {{{
 * \brief Default mock for clReleaseCommandQueue OpenCL function.
 */ // }}}
class Pluggable_clReleaseCommandQueue
  : public T::Base_clReleaseCommandQueue,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue )>
{
  cl_int clReleaseCommandQueue(cl_command_queue);
public:
  /** // doc: Pluggable_clReleaseCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseCommandQueue(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseContext)
/** // doc: Pluggable_clReleaseContext {{{
 * \brief Default mock for clReleaseContext OpenCL function.
 */ // }}}
class Pluggable_clReleaseContext
  : public T::Base_clReleaseContext,
    public T::Pluggable_Function<cl_int (*) ( cl_context )>
{
  cl_int clReleaseContext(cl_context);
public:
  /** // doc: Pluggable_clReleaseContext() {{{
   * \brief Constructor
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseContext(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
/** // doc: Pluggable_clReleaseDevice {{{
 * \brief Default mock for clReleaseDevice OpenCL function.
 */ // }}}
class Pluggable_clReleaseDevice
  : public T::Base_clReleaseDevice,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id )>
{
  cl_int clReleaseDevice(cl_device_id device);
public:
  /** // doc: Pluggable_clReleaseDevice() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseDevice(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseEvent)
/** // doc: Pluggable_clReleaseEvent {{{
 * \brief Default mock for clReleaseEvent OpenCL function.
 */ // }}}
class Pluggable_clReleaseEvent
  : public T::Base_clReleaseEvent,
    public T::Pluggable_Function<cl_int (*) ( cl_event )>
{
  cl_int clReleaseEvent(cl_event);
public:
  /** // doc: Pluggable_clReleaseEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseEvent(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseKernel)
/** // doc: Pluggable_clReleaseKernel {{{
 * \brief Default mock for clReleaseKernel OpenCL function.
 */ // }}}
class Pluggable_clReleaseKernel
  : public T::Base_clReleaseKernel,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel )>
{
  cl_int clReleaseKernel(cl_kernel kernel);
public:
  /** // doc: Pluggable_clReleaseKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseMemObject)
/** // doc: Pluggable_clReleaseMemObject {{{
 * \brief Default mock for clReleaseMemObject OpenCL function.
 */ // }}}
class Pluggable_clReleaseMemObject
  : public T::Base_clReleaseMemObject,
    public T::Pluggable_Function<cl_int (*) ( cl_mem )>
{
  cl_int clReleaseMemObject(cl_mem memobj);
public:
  /** // doc: Pluggable_clReleaseMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseMemObject(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseProgram)
/** // doc: Pluggable_clReleaseProgram {{{
 * \brief Default mock for clReleaseProgram OpenCL function.
 */ // }}}
class Pluggable_clReleaseProgram
  : public T::Base_clReleaseProgram,
    public T::Pluggable_Function<cl_int (*) ( cl_program )>
{
  cl_int clReleaseProgram(cl_program program);
public:
  /** // doc: Pluggable_clReleaseProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseSampler)
/** // doc: Pluggable_clReleaseSampler {{{
 * \brief Default mock for clReleaseSampler OpenCL function.
 */ // }}}
class Pluggable_clReleaseSampler
  : public T::Base_clReleaseSampler,
    public T::Pluggable_Function<cl_int (*) ( cl_sampler )>
{
  cl_int clReleaseSampler(cl_sampler sampler);
public:
  /** // doc: Pluggable_clReleaseSampler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clReleaseSampler(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainCommandQueue)
/** // doc: Pluggable_clRetainCommandQueue {{{
 * \brief Default mock for clRetainCommandQueue OpenCL function.
 */ // }}}
class Pluggable_clRetainCommandQueue
  : public T::Base_clRetainCommandQueue,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue )>
{
  cl_int clRetainCommandQueue(cl_command_queue);
public:
  /** // doc: Pluggable_clRetainCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainCommandQueue(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainContext)
/** // doc: Pluggable_clRetainContext {{{
 * \brief Default mock for clRetainContext OpenCL function.
 */ // }}}
class Pluggable_clRetainContext
  : public T::Base_clRetainContext,
    public T::Pluggable_Function<cl_int (*) ( cl_context )>
{
  cl_int clRetainContext(cl_context);
public:
  /** // doc: Pluggable_clRetainContext() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainContext(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
/** // doc: Pluggable_clRetainDevice {{{
 * \brief Default mock for clRetainDevice OpenCL function.
 */ // }}}
class Pluggable_clRetainDevice
  : public T::Base_clRetainDevice,
    public T::Pluggable_Function<cl_int (*) ( cl_device_id )>
{
  cl_int clRetainDevice(cl_device_id device);
public:
  /** // doc: Pluggable_clRetainDevice() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainDevice(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainEvent)
/** // doc: Pluggable_clRetainEvent {{{
 * \brief Default mock for clRetainEvent OpenCL function.
 */ // }}}
class Pluggable_clRetainEvent
  : public T::Base_clRetainEvent,
    public T::Pluggable_Function<cl_int (*) ( cl_event )>
{
  cl_int clRetainEvent(cl_event);
public:
  /** // doc: Pluggable_clRetainEvent() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainEvent(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainKernel)
/** // doc: Pluggable_clRetainKernel {{{
 * \brief Default mock for clRetainKernel OpenCL function.
 */ // }}}
class Pluggable_clRetainKernel
  : public T::Base_clRetainKernel,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel )>
{
  cl_int clRetainKernel(cl_kernel kernel);
public:
  /** // doc: Pluggable_clRetainKernel() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainKernel(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainMemObject)
/** // doc: Pluggable_clRetainMemObject {{{
 * \brief Default mock for clRetainMemObject OpenCL function.
 */ // }}}
class Pluggable_clRetainMemObject
  : public T::Base_clRetainMemObject,
    public T::Pluggable_Function<cl_int (*) ( cl_mem )>
{
  cl_int clRetainMemObject(cl_mem memobj);
public:
  /** // doc: Pluggable_clRetainMemObject() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainMemObject(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainProgram)
/** // doc: Pluggable_clRetainProgram {{{
 * \brief Default mock for clRetainProgram OpenCL function.
 */ // }}}
class Pluggable_clRetainProgram
  : public T::Base_clRetainProgram,
    public T::Pluggable_Function<cl_int (*) ( cl_program )>
{
  cl_int clRetainProgram(cl_program program);
public:
  /** // doc: Pluggable_clRetainProgram() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainProgram(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clRetainSampler)
/** // doc: Pluggable_clRetainSampler {{{
 * \brief Default mock for clRetainSampler OpenCL function.
 */ // }}}
class Pluggable_clRetainSampler
  : public T::Base_clRetainSampler,
    public T::Pluggable_Function<cl_int (*) ( cl_sampler )>
{
  cl_int clRetainSampler(cl_sampler sampler);
public:
  /** // doc: Pluggable_clRetainSampler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clRetainSampler(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetCommandQueueProperty)
/** // doc: Pluggable_clSetCommandQueueProperty {{{
 * \brief Mock for clSetCommandQueueProperty OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetCommandQueueProperty
  : public T::Base_clSetCommandQueueProperty,
    public T::Pluggable_Function<cl_int (*) ( cl_command_queue,
                                              cl_command_queue_properties,
                                              cl_bool,
                                              cl_command_queue_properties* )>
{
  cl_int clSetCommandQueueProperty(cl_command_queue command_queue,
                                      cl_command_queue_properties properties,
                                      cl_bool enable,
                                      cl_command_queue_properties* old_properties);
public:
  /** // doc: Pluggable_clSetCommandQueueProperty() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetCommandQueueProperty(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetDefaultDeviceCommandQueue)
/** // doc: Pluggable_clSetDefaultDeviceCommandQueue {{{
 * \brief Mock for clSetDefaultDeviceCommandQueue OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetDefaultDeviceCommandQueue
  : public T::Base_clSetDefaultDeviceCommandQueue,
    public T::Pluggable_Function<cl_int (*) ( cl_context,
                                              cl_device_id,
                                              cl_command_queue )>
{
  cl_int clSetDefaultDeviceCommandQueue(cl_context context, cl_device_id device,
                                        cl_command_queue command_queue);
public:
  /** // doc: Pluggable_clSetDefaultDeviceCommandQueue() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetDefaultDeviceCommandQueue(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetEventCallback)
/** // doc: Pluggable_clSetEventCallback {{{
 * \brief Mock for clSetEventCallback OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetEventCallback
  : public T::Base_clSetEventCallback,
    public T::Pluggable_Function<cl_int (*) ( cl_event,
                                              cl_int,
                                              void(CL_CALLBACK*)(cl_event, cl_int, void*),
                                              void* )>
{
  cl_int clSetEventCallback(cl_event event, cl_int command_exec_callback_type,
                            void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
                            void* user_data);
public:
  /** // doc: Pluggable_clSetEventCallback() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetEventCallback(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArg)
/** // doc: Pluggable_clSetKernelArg {{{
 * \brief Mock for clSetKernelArg OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetKernelArg
  : public T::Base_clSetKernelArg,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_uint,
                                              size_t,
                                              const void* )>
{
  cl_int clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size,
                        const void* arg_value);
public:
  /** // doc: Pluggable_clSetKernelArg() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetKernelArg(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArgSVMPointer)
/** // doc: Pluggable_clSetKernelArgSVMPointer {{{
 * \brief Mock for clSetKernelArgSVMPointer OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetKernelArgSVMPointer
  : public T::Base_clSetKernelArgSVMPointer,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_uint,
                                              const void* )>
{
  cl_int clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value);
public:
  /** // doc: Pluggable_clSetKernelArgSVMPointer() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetKernelArgSVMPointer(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelExecInfo)
/** // doc: Pluggable_clSetKernelExecInfo {{{
 * \brief Mock for clSetKernelExecInfo OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetKernelExecInfo
  : public T::Base_clSetKernelExecInfo,
    public T::Pluggable_Function<cl_int (*) ( cl_kernel,
                                              cl_kernel_exec_info,
                                              size_t,
                                              const void* )>
{
  cl_int clSetKernelExecInfo(cl_kernel kernel, cl_kernel_exec_info param_name, size_t param_value_size, const void* arg_value);
public:
  /** // doc: Pluggable_clSetKernelExecInfo() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetKernelExecInfo(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetMemObjectDestructorCallback)
/** // doc: Pluggable_clSetMemObjectDestructorCallback {{{
 * \brief Mock for clSetMemObjectDestructorCallback OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetMemObjectDestructorCallback
  : public T::Base_clSetMemObjectDestructorCallback,
    public T::Pluggable_Function<cl_int (*) ( cl_mem,
                                              void(CL_CALLBACK*)(cl_mem, void*),
                                              void* )>
{
  cl_int clSetMemObjectDestructorCallback(cl_mem memobj,
                                          void(CL_CALLBACK* pfn_notify)(cl_mem, void*),
                                          void* user_data);
public:
  /** // doc: Pluggable_clSetMemObjectDestructorCallback() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetMemObjectDestructorCallback(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSetUserEventStatus)
/** // doc: Pluggable_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSetUserEventStatus
  : public T::Base_clSetUserEventStatus,
    public T::Pluggable_Function<cl_int (*) ( cl_event,
                                              cl_int )>
{
  cl_int clSetUserEventStatus( cl_event event , cl_int execution_status );
public:
  /** // doc: Pluggable_clSetUserEventStatus() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSetUserEventStatus(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSVMAlloc)
/** // doc: Pluggable_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSVMAlloc
  : public T::Base_clSVMAlloc,
    public T::Pluggable_Function<void* (*) ( cl_context,
                                             cl_svm_mem_flags,
                                             size_t,
                                             cl_uint )>
{
  void* clSVMAlloc(cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment);
public:
  /** // doc: Pluggable_clSVMAlloc() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSVMAlloc(function_poitner_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clSVMFree)
/** // doc: Pluggable_clCreateUserEvent {{{
 * \brief Mock for clCreateUserEvent OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clSVMFree
  : public T::Base_clSVMFree,
    public T::Pluggable_Function<void (*) ( cl_context,
                                            void* )>
{
  void clSVMFree(cl_context context, void* svm_pointer);
public:
  /** // doc: Pluggable_clSVMFree() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clSVMFree(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clUnloadCompiler)
/** // doc: Pluggable_clUnloadCompiler {{{
 * \brief Default mock for clUnloadCompiler OpenCL function.
 */ // }}}
class Pluggable_clUnloadCompiler
  : public T::Base_clUnloadCompiler,
    public T::Pluggable_Function<cl_int (*)()>
{
  cl_int clUnloadCompiler();
public:
  /** // doc: Pluggable_clUnloadCompiler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clUnloadCompiler(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clUnloadPlatformCompiler)
/** // doc: Pluggable_clUnloadPlatformCompiler {{{
 * \brief Default mock for clUnloadPlatformCompiler OpenCL function.
 */ // }}}
class Pluggable_clUnloadPlatformCompiler
  : public T::Base_clUnloadPlatformCompiler,
    public T::Pluggable_Function<cl_int (*) ( cl_platform_id )>
{
  cl_int clUnloadPlatformCompiler(cl_platform_id);
public:
  /** // doc: Pluggable_clUnloadPlatformCompiler() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clUnloadPlatformCompiler(function_pointer_t fptr);
};
#endif
#if CLXX_B5D_OPENCL_PROVIDES(clWaitForEvents)
/** // doc: Pluggable_clWaitForEvents {{{
 * \brief Mock for clWaitForEvents OpenCL function.
 *
 * Does nothing except it returns a custom code defined by user.
 */ // }}}
class Pluggable_clWaitForEvents
  : public T::Base_clWaitForEvents,
    public T::Pluggable_Function<cl_int (*) ( cl_uint,
                                              const cl_event* )>
{
  cl_int clWaitForEvents(cl_uint num_events, const cl_event* event_list);
public:
  /** // doc: Pluggable_clWaitForEvents() {{{
   * \brief Constructor, initializes the mock object.
   *
   * \param fptr Function to be plugged-in
   */ // }}}
  Pluggable_clWaitForEvents(function_pointer_t fptr);
};
#endif
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE || ... */

/* Mock class implementations */
#if defined(CXXTEST_MOCK_TEST_SOURCE_FILE)
namespace T {
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clBuildProgram)
cl_int Pluggable_clBuildProgram::
clBuildProgram(cl_program program,
               cl_uint num_devices,
               const cl_device_id* device_list,
               const char* options,
               void (CL_CALLBACK* pfn_notify)(cl_program, void*),
               void* user_data)
{
  return call_function(program, num_devices,device_list, options, pfn_notify, user_data);
}
Pluggable_clBuildProgram::
Pluggable_clBuildProgram(function_pointer_t fptr)
  : Base_clBuildProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCloneKernel)
cl_kernel Pluggable_clCloneKernel::
clCloneKernel(cl_kernel source_kernel, cl_int* errcode_ret)
{
  return call_function(source_kernel, errcode_ret);
}
Pluggable_clCloneKernel::
Pluggable_clCloneKernel(function_pointer_t fptr)
  : Base_clCloneKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCompileProgram)
cl_int Pluggable_clCompileProgram::
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
  return call_function(program, num_devices, device_list, options,
                       num_input_headers, input_headers, header_include_names,
                       pfn_notify, user_data);
}
Pluggable_clCompileProgram::
Pluggable_clCompileProgram(function_pointer_t fptr)
  : Base_clCompileProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateBuffer)
cl_mem Pluggable_clCreateBuffer::
clCreateBuffer( cl_context context, cl_mem_flags flags, size_t size,
                void* host_ptr, cl_int* errcode_ret )
{
  return call_function(context, flags, size, host_ptr, errcode_ret);
}
Pluggable_clCreateBuffer::
Pluggable_clCreateBuffer(function_pointer_t fptr)
  : Base_clCreateBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueue)
cl_command_queue Pluggable_clCreateCommandQueue::
clCreateCommandQueue(cl_context context, cl_device_id device,
                     cl_command_queue_properties properties,
                     cl_int* errcode_ret)
{
  return call_function(context, device, properties, errcode_ret);
}
Pluggable_clCreateCommandQueue::
Pluggable_clCreateCommandQueue(function_pointer_t fptr)
  : Base_clCreateCommandQueue(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateCommandQueueWithProperties)
cl_command_queue Pluggable_clCreateCommandQueueWithProperties::
clCreateCommandQueueWithProperties(cl_context context, cl_device_id device,
                                   const cl_queue_properties* properties,
                                   cl_int* errcode_ret)
{
  return call_function(context, device, properties, errcode_ret);
}
Pluggable_clCreateCommandQueueWithProperties::
Pluggable_clCreateCommandQueueWithProperties(function_pointer_t fptr)
  : Base_clCreateCommandQueueWithProperties(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateContext)
cl_context Pluggable_clCreateContext::
clCreateContext(const cl_context_properties* properties,
                cl_uint num_devices,
                const cl_device_id* devices,
                void(CL_CALLBACK* pfn_notify)(const char*,const void*, size_t, void*),
                void* user_data,
                cl_int* errcode_ret)
{
  return call_function(properties, num_devices, devices, pfn_notify, user_data, errcode_ret);
}
Pluggable_clCreateContext::
Pluggable_clCreateContext(function_pointer_t fptr)
  : Base_clCreateContext(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateContextFromType)
cl_context Pluggable_clCreateContextFromType::
clCreateContextFromType(const cl_context_properties* properties,
                        cl_device_type device_type,
                        void(CL_CALLBACK* pfn_notify)(const char*, const void*, size_t, void*),
                        void* user_data,
                        cl_int* errcode_ret)
{
  return call_function(properties, device_type, pfn_notify, user_data, errcode_ret);
}
Pluggable_clCreateContextFromType::
Pluggable_clCreateContextFromType(function_pointer_t fptr)
  : Base_clCreateContextFromType(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage)
cl_mem Pluggable_clCreateImage::
clCreateImage( cl_context context, cl_mem_flags flags,
               const cl_image_format* image_format,
               const cl_image_desc* image_desc, void* host_ptr,
               cl_int* errcode_ret )
{
  return call_function( context, flags, image_format, image_desc, host_ptr, errcode_ret );
}
Pluggable_clCreateImage::
Pluggable_clCreateImage(function_pointer_t fptr)
  : Base_clCreateImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage2D)
cl_mem Pluggable_clCreateImage2D::
clCreateImage2D( cl_context context, cl_mem_flags flags,
               const cl_image_format* image_format,
               size_t image_width, size_t image_height, size_t image_row_pitch,
               void* host_ptr, cl_int* errcode_ret )
{
  return call_function( context, flags, image_format, image_width, image_height,
             image_row_pitch, host_ptr, errcode_ret );
}
Pluggable_clCreateImage2D::
Pluggable_clCreateImage2D(function_pointer_t fptr)
  : Base_clCreateImage2D(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateImage3D)
cl_mem Pluggable_clCreateImage3D::
clCreateImage3D( cl_context context, cl_mem_flags flags,
               const cl_image_format* image_format,
               size_t image_width, size_t image_height, size_t image_depth,
               size_t image_row_pitch, size_t image_slice_pitch,
               void* host_ptr, cl_int* errcode_ret )
{
  return call_function( context, flags, image_format, image_width, image_height,
             image_depth, image_row_pitch, image_slice_pitch, host_ptr,
             errcode_ret );
}
Pluggable_clCreateImage3D::
Pluggable_clCreateImage3D(function_pointer_t fptr)
  : Base_clCreateImage3D(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernel)
cl_kernel Pluggable_clCreateKernel::
clCreateKernel(cl_program program, const char* kernel_name, cl_int* errcode_ret)
{
  return call_function(program, kernel_name, errcode_ret);
}
Pluggable_clCreateKernel::
Pluggable_clCreateKernel(function_pointer_t fptr)
  : Base_clCreateKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateKernelsInProgram)
cl_int Pluggable_clCreateKernelsInProgram::
clCreateKernelsInProgram(cl_program program, cl_uint num_kernels, cl_kernel* kernels,
                         cl_uint* num_kernels_ret)
{
  return call_function(program, num_kernels, kernels, num_kernels_ret);
}
Pluggable_clCreateKernelsInProgram::
Pluggable_clCreateKernelsInProgram(function_pointer_t fptr)
  : Base_clCreateKernelsInProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreatePipe)
cl_mem Pluggable_clCreatePipe::
clCreatePipe( cl_context context, cl_mem_flags flags,
              cl_uint pipe_packet_size, cl_uint pipe_max_packets,
              const cl_pipe_properties* properties, cl_int* errcode_ret )
{
  return call_function( context, flags, pipe_packet_size, pipe_max_packets, properties,
             errcode_ret );
}
Pluggable_clCreatePipe::
Pluggable_clCreatePipe(function_pointer_t fptr)
  : Base_clCreatePipe(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBinary)
cl_program Pluggable_clCreateProgramWithBinary::
clCreateProgramWithBinary(cl_context context,
                          cl_uint num_devices,
                          const cl_device_id* device_list,
                          const size_t* lengths,
                          const unsigned char** binaries,
                          cl_int* binary_status,
                          cl_int* errcode_ret)
{
  return call_function(context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
}
Pluggable_clCreateProgramWithBinary::
Pluggable_clCreateProgramWithBinary(function_pointer_t fptr)
  : Base_clCreateProgramWithBinary(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithBuiltInKernels)
cl_program Pluggable_clCreateProgramWithBuiltInKernels::
clCreateProgramWithBuiltInKernels(cl_context context,
                                  cl_uint num_devices,
                                  const cl_device_id* device_list,
                                  const char* kernel_names,
                                  cl_int* errcode_ret)
{
  return call_function(context, num_devices, device_list, kernel_names, errcode_ret);
}
Pluggable_clCreateProgramWithBuiltInKernels::
Pluggable_clCreateProgramWithBuiltInKernels(function_pointer_t fptr)
  : Base_clCreateProgramWithBuiltInKernels(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithIL)
cl_program Pluggable_clCreateProgramWithIL::
clCreateProgramWithIL(cl_context context,
                      const void* il,
                      size_t length,
                      cl_int* errcode_ret)
{
  return call_function(context, il, length, errcode_ret);
}
Pluggable_clCreateProgramWithIL::
Pluggable_clCreateProgramWithIL(function_pointer_t fptr)
  : Base_clCreateProgramWithIL(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateProgramWithSource)
cl_program Pluggable_clCreateProgramWithSource::
clCreateProgramWithSource(cl_context context,
                          cl_uint count,
                          const char** strings,
                          const size_t* lengths,
                          cl_int* errcode_ret)
{
  return call_function(context, count, strings, lengths, errcode_ret);
}
Pluggable_clCreateProgramWithSource::
Pluggable_clCreateProgramWithSource(function_pointer_t fptr)
  : Base_clCreateProgramWithSource(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSampler)
cl_sampler Pluggable_clCreateSampler::
clCreateSampler( cl_context context, cl_bool normalized_coords,
                 cl_addressing_mode addressing_mode, cl_filter_mode filter_mode,
                 cl_int* errcode_ret )
{
  return call_function(context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
}
Pluggable_clCreateSampler::
Pluggable_clCreateSampler(function_pointer_t fptr)
  : Base_clCreateSampler(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSamplerWithProperties)
cl_sampler Pluggable_clCreateSamplerWithProperties::
clCreateSamplerWithProperties( cl_context context,
                               const cl_sampler_properties* sampler_properties,
                               cl_int* errcode_ret )
{
  return call_function(context, sampler_properties, errcode_ret);
}
Pluggable_clCreateSamplerWithProperties::
Pluggable_clCreateSamplerWithProperties(function_pointer_t fptr)
  : Base_clCreateSamplerWithProperties(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubBuffer)
cl_mem Pluggable_clCreateSubBuffer::
clCreateSubBuffer( cl_mem buffer, cl_mem_flags flags,
                   cl_buffer_create_type buffer_create_type,
                   const void* buffer_create_info, cl_int* errcode_ret )
{
  return call_function(buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
}
Pluggable_clCreateSubBuffer::
Pluggable_clCreateSubBuffer(function_pointer_t fptr)
  : Base_clCreateSubBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateSubDevices)
cl_int Pluggable_clCreateSubDevices::
clCreateSubDevices(cl_device_id in_device,
                   const cl_device_partition_property* properties,
                   cl_uint num_devices,
                   cl_device_id* out_devices,
                   cl_uint* num_devices_ret)
{
  return call_function(in_device, properties, num_devices, out_devices, num_devices_ret);
}
Pluggable_clCreateSubDevices::
Pluggable_clCreateSubDevices(function_pointer_t fptr)
  : Base_clCreateSubDevices(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clCreateUserEvent)
cl_event Pluggable_clCreateUserEvent::
clCreateUserEvent(cl_context context, cl_int* errcode_ret )
{
  return call_function(context, errcode_ret);
}
Pluggable_clCreateUserEvent::
Pluggable_clCreateUserEvent(function_pointer_t fptr)
  : Base_clCreateUserEvent(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrier)
cl_int Pluggable_clEnqueueBarrier::
clEnqueueBarrier( cl_command_queue command_queue )
{
  return call_function( command_queue );
}
Pluggable_clEnqueueBarrier::
Pluggable_clEnqueueBarrier(function_pointer_t fptr)
  : Base_clEnqueueBarrier(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueBarrierWithWaitList)
cl_int Pluggable_clEnqueueBarrierWithWaitList::
clEnqueueBarrierWithWaitList( cl_command_queue command_queue,
                              cl_uint num_events_in_wait_list,
                              const cl_event* event_wait_list,
                              cl_event* event )
{
  return call_function( command_queue, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueBarrierWithWaitList::
Pluggable_clEnqueueBarrierWithWaitList(function_pointer_t fptr)
  : Base_clEnqueueBarrierWithWaitList(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBuffer)
cl_int Pluggable_clEnqueueCopyBuffer::
clEnqueueCopyBuffer( cl_command_queue command_queue,
                     cl_mem src_buffer, cl_mem dst_buffer,
                     size_t src_offset, size_t dst_offset,
                     size_t size, cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event )
{
  return call_function( command_queue, src_buffer, dst_buffer, src_offset, dst_offset,
             size, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueCopyBuffer::
Pluggable_clEnqueueCopyBuffer(function_pointer_t fptr)
  : Base_clEnqueueCopyBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferRect)
cl_int Pluggable_clEnqueueCopyBufferRect::
clEnqueueCopyBufferRect( cl_command_queue command_queue,
                         cl_mem src_buffer,
                         cl_mem dst_buffer,
                         const size_t* src_origin,
                         const size_t* dst_origin,
                         const size_t* region,
                         size_t src_row_pitch,
                         size_t src_slice_pitch,
                         size_t dst_row_pitch,
                         size_t dst_slice_pitch,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event )
{
  return call_function( command_queue, src_buffer, dst_buffer, src_origin, dst_origin,
             region, src_row_pitch, src_slice_pitch, dst_row_pitch,
             dst_slice_pitch, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueCopyBufferRect::
Pluggable_clEnqueueCopyBufferRect(function_pointer_t fptr)
  : Base_clEnqueueCopyBufferRect(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyBufferToImage)
cl_int Pluggable_clEnqueueCopyBufferToImage::
clEnqueueCopyBufferToImage( cl_command_queue command_queue,
                            cl_mem src_buffer,
                            cl_mem dst_image,
                            size_t src_offset,
                            const size_t* dst_origin,
                            const size_t* region,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  return call_function( command_queue, src_buffer, dst_image, src_offset, dst_origin,
             region, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueCopyBufferToImage::
Pluggable_clEnqueueCopyBufferToImage(function_pointer_t fptr)
  : Base_clEnqueueCopyBufferToImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImage)
cl_int Pluggable_clEnqueueCopyImage::
clEnqueueCopyImage( cl_command_queue command_queue, cl_mem src_image,
                    cl_mem dst_image, const size_t* src_origin,
                    const size_t* dst_origin, const size_t* region,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  return call_function( command_queue, src_image, dst_image, src_origin, dst_origin,
             region, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueCopyImage::
Pluggable_clEnqueueCopyImage(function_pointer_t fptr)
  : Base_clEnqueueCopyImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueCopyImageToBuffer)
cl_int Pluggable_clEnqueueCopyImageToBuffer::
clEnqueueCopyImageToBuffer( cl_command_queue command_queue,
                            cl_mem src_image,
                            cl_mem dst_buffer,
                            const size_t* src_origin,
                            const size_t* region,
                            size_t dst_offset,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  return call_function( command_queue, src_image, dst_buffer, src_origin, region,
             dst_offset, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueCopyImageToBuffer::
Pluggable_clEnqueueCopyImageToBuffer(function_pointer_t fptr)
  : Base_clEnqueueCopyImageToBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillBuffer)
cl_int Pluggable_clEnqueueFillBuffer::
clEnqueueFillBuffer( cl_command_queue command_queue, cl_mem buffer,
                     const void *pattern, size_t pattern_size,
                     size_t offset, size_t size,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event )
{
  return call_function( command_queue, buffer, pattern, pattern_size, offset, size,
             num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueFillBuffer::
Pluggable_clEnqueueFillBuffer(function_pointer_t fptr)
  : Base_clEnqueueFillBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueFillImage)
cl_int Pluggable_clEnqueueFillImage::
clEnqueueFillImage( cl_command_queue command_queue,
                    cl_mem image,
                    const void *fill_color,
                    const size_t* origin,
                    const size_t* region,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event)
{
  return call_function( command_queue, image, fill_color, origin, region,
             num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueFillImage::
Pluggable_clEnqueueFillImage(function_pointer_t fptr)
  : Base_clEnqueueFillImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapBuffer)
void* Pluggable_clEnqueueMapBuffer::
clEnqueueMapBuffer( cl_command_queue command_queue, cl_mem buffer,
                    cl_bool blocking_map, cl_map_flags map_flags,
                    size_t offset, size_t size,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event, cl_int* errcode_ret )
{
  return call_function( command_queue, buffer, blocking_map, map_flags, offset, size,
             num_events_in_wait_list, event_wait_list, event, errcode_ret );
}
Pluggable_clEnqueueMapBuffer::
Pluggable_clEnqueueMapBuffer(function_pointer_t fptr)
  : Base_clEnqueueMapBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMapImage)
void* Pluggable_clEnqueueMapImage::
clEnqueueMapImage( cl_command_queue command_queue,
                   cl_mem image,
                   cl_bool blocking_map,
                   cl_map_flags map_flags,
                   const size_t* origin,
                   const size_t* region,
                   size_t* image_row_pitch,
                   size_t* image_slice_pitch,
                   cl_uint num_events_in_wait_list,
                   const cl_event* event_wait_list,
                   cl_event* event,
                   cl_int* errcode_ret )
{
  return call_function( command_queue, image, blocking_map, map_flags, origin, region,
             image_row_pitch, image_slice_pitch, num_events_in_wait_list,
             event_wait_list, event, errcode_ret );
}
Pluggable_clEnqueueMapImage::
Pluggable_clEnqueueMapImage(function_pointer_t fptr)
  : Base_clEnqueueMapImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarker)
cl_int Pluggable_clEnqueueMarker::
clEnqueueMarker( cl_command_queue command_queue,
                 cl_event* event )
{
  return call_function( command_queue, event );
}
Pluggable_clEnqueueMarker::
Pluggable_clEnqueueMarker(function_pointer_t fptr)
  : Base_clEnqueueMarker(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMarkerWithWaitList)
cl_int Pluggable_clEnqueueMarkerWithWaitList::
clEnqueueMarkerWithWaitList( cl_command_queue command_queue,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event )
{
  return call_function( command_queue, num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueMarkerWithWaitList::
Pluggable_clEnqueueMarkerWithWaitList(function_pointer_t fptr)
  : Base_clEnqueueMarkerWithWaitList(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueMigrateMemObjects)
cl_int Pluggable_clEnqueueMigrateMemObjects::
clEnqueueMigrateMemObjects( cl_command_queue command_queue,
                            cl_uint num_mem_objects,
                            const cl_mem* mem_objects,
                            cl_mem_migration_flags flags,
                            cl_uint num_events_in_wait_list,
                            const cl_event* event_wait_list,
                            cl_event* event )
{
  return call_function( command_queue, num_mem_objects, mem_objects, flags,
             num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueMigrateMemObjects::
Pluggable_clEnqueueMigrateMemObjects(function_pointer_t fptr)
  : Base_clEnqueueMigrateMemObjects(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNativeKernel)
cl_int Pluggable_clEnqueueNativeKernel::
clEnqueueNativeKernel( cl_command_queue command_queue,
                       void (CL_CALLBACK* user_func)(void*),
                       void* args,
                       size_t cb_args,
                       cl_uint num_mem_objects,
                       const cl_mem* mem_list,
                       const void** args_mem_loc,
                       cl_uint num_events_in_wait_list,
                       const cl_event* event_wait_list,
                       cl_event* event )
{
  return call_function( command_queue, user_func, args, cb_args, num_mem_objects,
             mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list,
             event );
}
Pluggable_clEnqueueNativeKernel::
Pluggable_clEnqueueNativeKernel(function_pointer_t fptr)
  : Base_clEnqueueNativeKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueNDRangeKernel)
cl_int Pluggable_clEnqueueNDRangeKernel::
clEnqueueNDRangeKernel( cl_command_queue command_queue,
                        cl_kernel kernel,
                        cl_uint work_dim,
                        const size_t* global_work_offset,
                        const size_t* global_work_size,
                        const size_t* local_work_size,
                        cl_uint num_events_in_wait_list,
                        const cl_event* event_wait_list,
                        cl_event* event)
{
  return call_function(command_queue, kernel, work_dim, global_work_offset,
            global_work_size, local_work_size, num_events_in_wait_list,
            event_wait_list, event);
}
Pluggable_clEnqueueNDRangeKernel::
Pluggable_clEnqueueNDRangeKernel(function_pointer_t fptr)
  : Base_clEnqueueNDRangeKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBuffer)
cl_int Pluggable_clEnqueueReadBuffer::
clEnqueueReadBuffer( cl_command_queue command_queue,
                     cl_mem buffer, cl_bool blocking_read,
                     size_t offset, size_t size, void* ptr,
                     cl_uint num_events_in_wait_list,
                     const cl_event* event_wait_list,
                     cl_event* event)
{
  return call_function( command_queue, buffer, blocking_read, offset, size, ptr,
             num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueReadBuffer::
Pluggable_clEnqueueReadBuffer(function_pointer_t fptr)
  : Base_clEnqueueReadBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadBufferRect)
cl_int Pluggable_clEnqueueReadBufferRect::
clEnqueueReadBufferRect( cl_command_queue command_queue,
                         cl_mem buffer, cl_bool blocking_read,
                         const size_t* buffer_origin,
                         const size_t* host_origin,
                         const size_t* region,
                         size_t buffer_row_pitch,
                         size_t buffer_splice_pitch,
                         size_t host_row_pitch,
                         size_t host_slice_pitch,
                         void* ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event )
{
  return call_function( command_queue, buffer, blocking_read, buffer_origin, host_origin,
             region, buffer_row_pitch, buffer_splice_pitch, host_row_pitch,
             host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event);
}
Pluggable_clEnqueueReadBufferRect::
Pluggable_clEnqueueReadBufferRect(function_pointer_t fptr)
  : Base_clEnqueueReadBufferRect(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueReadImage)
cl_int Pluggable_clEnqueueReadImage::
clEnqueueReadImage( cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_read,
                    const size_t* origin,
                    const size_t* region,
                    size_t row_pitch,
                    size_t slice_pitch,
                    void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  return call_function( command_queue, image, blocking_read, origin, region, row_pitch,
             slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event );
}
Pluggable_clEnqueueReadImage::
Pluggable_clEnqueueReadImage(function_pointer_t fptr)
  : Base_clEnqueueReadImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMFree)
cl_int Pluggable_clEnqueueSVMFree::
clEnqueueSVMFree(cl_command_queue command_queue,
                 cl_uint num_svm_pointers, void* svm_pointers[],
                 void(CL_CALLBACK* pfn_free_func)(cl_command_queue,
                                                  cl_uint,
                                                  void*[],
                                                  void*),
                 void* user_data, cl_uint num_events_in_wait_list,
                 const cl_event* event_wait_list, cl_event* event)
{
  return call_function(command_queue, num_svm_pointers, svm_pointers, pfn_free_func,
            user_data, num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueSVMFree::
Pluggable_clEnqueueSVMFree(function_pointer_t fptr)
  : Base_clEnqueueSVMFree(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMap)
cl_int Pluggable_clEnqueueSVMMap::
clEnqueueSVMMap(cl_command_queue command_queue, cl_bool blocking_map,
                cl_map_flags map_flags, void* svm_ptr, size_t size,
                cl_uint num_events_in_wait_list,
                const cl_event* event_wait_list, cl_event* event )
{
  return call_function(command_queue, blocking_map, map_flags, svm_ptr, size,
            num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueSVMMap::
Pluggable_clEnqueueSVMMap(function_pointer_t fptr)
  : Base_clEnqueueSVMMap(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemFill)
cl_int Pluggable_clEnqueueSVMMemFill::
clEnqueueSVMMemFill(cl_command_queue command_queue, void* svm_ptr,
                    const void* pattern, size_t pattern_size, size_t size,
                    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
                    cl_event* event)
{
  return call_function(command_queue, svm_ptr, pattern, pattern_size, size,
            num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueSVMMemFill::
Pluggable_clEnqueueSVMMemFill(function_pointer_t fptr)
  : Base_clEnqueueSVMMemFill(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMemcpy)
cl_int Pluggable_clEnqueueSVMMemcpy::
clEnqueueSVMMemcpy(cl_command_queue command_queue, cl_bool blocking_copy,
                   void* dst_ptr, const void* src_ptr, size_t size,
                    cl_uint num_events_in_wait_list, const cl_event* event_wait_list,
                    cl_event* event)
{
  return call_function(command_queue, blocking_copy, dst_ptr, src_ptr, size,
            num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueSVMMemcpy::
Pluggable_clEnqueueSVMMemcpy(function_pointer_t fptr)
  : Base_clEnqueueSVMMemcpy(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMMigrateMem)
cl_int Pluggable_clEnqueueSVMMigrateMem::
clEnqueueSVMMigrateMem(cl_command_queue command_queue,
                       cl_uint num_svm_pointers,
                       const void** svm_pointers, const size_t* sizes,
                       cl_mem_migration_flags flags,
                       cl_uint num_events_in_wait_list,
                       const cl_event* event_wait_list,
                       cl_event* event)
{
  return call_function(command_queue, num_svm_pointers, svm_pointers, sizes, flags,
            num_events_in_wait_list, event_wait_list, event);
}
Pluggable_clEnqueueSVMMigrateMem::
Pluggable_clEnqueueSVMMigrateMem(function_pointer_t fptr)
  : Base_clEnqueueSVMMigrateMem(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueSVMUnmap)
cl_int Pluggable_clEnqueueSVMUnmap::
clEnqueueSVMUnmap(cl_command_queue command_queue, void* svm_ptr,
                  cl_uint num_events_in_wait_list,
                  const cl_event* event_wait_list, cl_event* event )
{
  return call_function(command_queue, svm_ptr, num_events_in_wait_list, event_wait_list,
            event);
}
Pluggable_clEnqueueSVMUnmap::
Pluggable_clEnqueueSVMUnmap(function_pointer_t fptr)
  : Base_clEnqueueSVMUnmap(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueTask)
cl_int Pluggable_clEnqueueTask::
clEnqueueTask( cl_command_queue command_queue,
               cl_kernel kernel,
               cl_uint num_events_in_wait_list,
               const cl_event* event_wait_list,
               cl_event* event )
{
  return call_function( command_queue, kernel, num_events_in_wait_list,
             event_wait_list, event );
}
Pluggable_clEnqueueTask::
Pluggable_clEnqueueTask(function_pointer_t fptr)
  : Base_clEnqueueTask(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueUnmapMemObject)
cl_int Pluggable_clEnqueueUnmapMemObject::
clEnqueueUnmapMemObject( cl_command_queue command_queue,
                         cl_mem memobj,
                         void* mapped_ptr,
                         cl_uint num_events_in_wait_list,
                         const cl_event* event_wait_list,
                         cl_event* event )
{
  return call_function( command_queue, memobj, mapped_ptr, num_events_in_wait_list,
             event_wait_list, event );
}
Pluggable_clEnqueueUnmapMemObject::
Pluggable_clEnqueueUnmapMemObject(function_pointer_t fptr)
  : Base_clEnqueueUnmapMemObject(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWaitForEvents)
cl_int Pluggable_clEnqueueWaitForEvents::
clEnqueueWaitForEvents( cl_command_queue command_queue,
                        cl_uint num_events,
                        const cl_event* event_list )
{
  return call_function( command_queue, num_events, event_list );
}
Pluggable_clEnqueueWaitForEvents::
Pluggable_clEnqueueWaitForEvents(function_pointer_t fptr)
  : Base_clEnqueueWaitForEvents(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBuffer)
cl_int Pluggable_clEnqueueWriteBuffer::
clEnqueueWriteBuffer( cl_command_queue command_queue,
                      cl_mem buffer, cl_bool blocking_write,
                      size_t offset, size_t size, const void* ptr,
                      cl_uint num_events_in_wait_list,
                      const cl_event* event_wait_list,
                      cl_event* event )
{
  return call_function( command_queue, buffer, blocking_write, offset, size, ptr,
             num_events_in_wait_list, event_wait_list, event );
}
Pluggable_clEnqueueWriteBuffer::
Pluggable_clEnqueueWriteBuffer(function_pointer_t fptr)
  : Base_clEnqueueWriteBuffer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteBufferRect)
cl_int Pluggable_clEnqueueWriteBufferRect::
clEnqueueWriteBufferRect( cl_command_queue command_queue,
                             cl_mem buffer, cl_bool blocking_read,
                             const size_t* buffer_origin,
                             const size_t* host_origin,
                             const size_t* region,
                             size_t buffer_row_pitch,
                             size_t buffer_splice_pitch,
                             size_t host_row_pitch,
                             size_t host_slice_pitch,
                             const void* ptr,
                             cl_uint num_events_in_wait_list,
                             const cl_event* event_wait_list,
                             cl_event* event )
{
  return call_function( command_queue, buffer, blocking_read, buffer_origin, host_origin,
             region, buffer_row_pitch, buffer_splice_pitch, host_row_pitch,
             host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list,
             event);
}
Pluggable_clEnqueueWriteBufferRect::
Pluggable_clEnqueueWriteBufferRect(function_pointer_t fptr)
  : Base_clEnqueueWriteBufferRect(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clEnqueueWriteImage)
cl_int Pluggable_clEnqueueWriteImage::
clEnqueueWriteImage( cl_command_queue command_queue,
                    cl_mem image,
                    cl_bool blocking_read,
                    const size_t* origin,
                    const size_t* region,
                    size_t input_row_pitch,
                    size_t input_slice_pitch,
                    const void* ptr,
                    cl_uint num_events_in_wait_list,
                    const cl_event* event_wait_list,
                    cl_event* event )
{
  return call_function( command_queue, image, blocking_read, origin, region,
             input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list,
             event_wait_list, event );
}
Pluggable_clEnqueueWriteImage::
Pluggable_clEnqueueWriteImage(function_pointer_t fptr)
  : Base_clEnqueueWriteImage(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clFinish)
cl_int Pluggable_clFinish::
clFinish(cl_command_queue command_queue)
{
  return call_function(command_queue);
}
Pluggable_clFinish::
Pluggable_clFinish(function_pointer_t fptr)
  : Base_clFinish(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clFlush)
cl_int Pluggable_clFlush::
clFlush(cl_command_queue command_queue)
{
  return call_function(command_queue);
}
Pluggable_clFlush::
Pluggable_clFlush(function_pointer_t fptr)
  : Base_clFlush(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetCommandQueueInfo)
cl_int Pluggable_clGetCommandQueueInfo::
clGetCommandQueueInfo(cl_command_queue command_queue, cl_command_queue_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  return call_function(command_queue, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetCommandQueueInfo::
Pluggable_clGetCommandQueueInfo(function_pointer_t fptr)
  : Base_clGetCommandQueueInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetContextInfo)
cl_int Pluggable_clGetContextInfo::
clGetContextInfo(cl_context context, cl_context_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  return call_function(context, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetContextInfo::
Pluggable_clGetContextInfo(function_pointer_t fptr)
  : Base_clGetContextInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceAndHostTimer)
cl_int Pluggable_clGetDeviceAndHostTimer::
clGetDeviceAndHostTimer(cl_device_id device, cl_ulong* device_timestamp,
                        cl_ulong* host_timestamp)
{
  return call_function(device, device_timestamp, host_timestamp);
}
Pluggable_clGetDeviceAndHostTimer::
Pluggable_clGetDeviceAndHostTimer(function_pointer_t fptr)
  : Base_clGetDeviceAndHostTimer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceIDs)
cl_int Pluggable_clGetDeviceIDs::
clGetDeviceIDs(cl_platform_id platform, cl_device_type device_type,
               cl_uint num_entries, cl_device_id* devices,
               cl_uint* num_devices)
{
  return call_function(platform, device_type, num_entries, devices, num_devices);
}
Pluggable_clGetDeviceIDs::
Pluggable_clGetDeviceIDs(function_pointer_t fptr)
  : Base_clGetDeviceIDs(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetDeviceInfo)
cl_int Pluggable_clGetDeviceInfo::
clGetDeviceInfo(cl_device_id device, cl_device_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  return call_function(device, param_name, param_value_size, param_value, param_value_size_ret);
}

Pluggable_clGetDeviceInfo::
Pluggable_clGetDeviceInfo(function_pointer_t fptr)
  : Base_clGetDeviceInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetEventInfo)
cl_int Pluggable_clGetEventInfo::
clGetEventInfo(cl_event event, cl_event_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  return call_function(event, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetEventInfo::
Pluggable_clGetEventInfo(function_pointer_t fptr)
  : Base_clGetEventInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetEventProfilingInfo)
cl_int Pluggable_clGetEventProfilingInfo::
clGetEventProfilingInfo(cl_event event, cl_profiling_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  return call_function(event, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetEventProfilingInfo::
Pluggable_clGetEventProfilingInfo(function_pointer_t fptr)
  : Base_clGetEventProfilingInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddress)
void* Pluggable_clGetExtensionFunctionAddress::
clGetExtensionFunctionAddress(const char* funcname)
{
  return call_function(funcname);
}
Pluggable_clGetExtensionFunctionAddress::
Pluggable_clGetExtensionFunctionAddress(function_pointer_t fptr)
  : Base_clGetExtensionFunctionAddress(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetExtensionFunctionAddressForPlatform)
void* Pluggable_clGetExtensionFunctionAddressForPlatform::
clGetExtensionFunctionAddressForPlatform(cl_platform_id platform, const char* funcname)
{
  return call_function(platform, funcname);
}
Pluggable_clGetExtensionFunctionAddressForPlatform::
Pluggable_clGetExtensionFunctionAddressForPlatform(function_pointer_t fptr)
  : Base_clGetExtensionFunctionAddressForPlatform(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetHostTimer)
cl_int Pluggable_clGetHostTimer::
clGetHostTimer(cl_device_id device, cl_ulong* host_timestamp)
{
  return call_function(device, host_timestamp);
}
Pluggable_clGetHostTimer::
Pluggable_clGetHostTimer(function_pointer_t fptr)
  : Base_clGetHostTimer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetImageInfo)
cl_int Pluggable_clGetImageInfo::
clGetImageInfo(cl_mem image, cl_image_info param_name,
               size_t param_value_size, void* param_value,
               size_t* param_value_size_ret)
{
  return call_function(image, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetImageInfo::
Pluggable_clGetImageInfo(function_pointer_t fptr)
  : Base_clGetImageInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelArgInfo)
cl_int Pluggable_clGetKernelArgInfo::
clGetKernelArgInfo(cl_kernel kernel, cl_uint arg_index, cl_kernel_arg_info param_name,
                   size_t param_value_size, void* param_value,
                   size_t* param_value_size_ret)
{
  return call_function(kernel, arg_index, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetKernelArgInfo::
Pluggable_clGetKernelArgInfo(function_pointer_t fptr)
  : Base_clGetKernelArgInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelInfo)
cl_int Pluggable_clGetKernelInfo::
clGetKernelInfo(cl_kernel kernel, cl_kernel_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  return call_function(kernel, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetKernelInfo::
Pluggable_clGetKernelInfo(function_pointer_t fptr)
  : Base_clGetKernelInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelWorkGroupInfo)
cl_int Pluggable_clGetKernelWorkGroupInfo::
clGetKernelWorkGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret)
{
  return call_function(kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetKernelWorkGroupInfo::
Pluggable_clGetKernelWorkGroupInfo(function_pointer_t fptr)
  : Base_clGetKernelWorkGroupInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetKernelSubGroupInfo)
cl_int Pluggable_clGetKernelSubGroupInfo::
clGetKernelSubGroupInfo(cl_kernel kernel, cl_device_id device, cl_kernel_work_group_info param_name,
                         size_t input_value_size, const void* input_value,
                         size_t param_value_size, void* param_value,
                         size_t* param_value_size_ret)
{
  return call_function(kernel, device, param_name, input_value_size, input_value, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetKernelSubGroupInfo::
Pluggable_clGetKernelSubGroupInfo(function_pointer_t fptr)
  : Base_clGetKernelSubGroupInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetMemObjectInfo)
cl_int Pluggable_clGetMemObjectInfo::
clGetMemObjectInfo(cl_mem memobj, cl_mem_info param_name,
                   size_t param_value_size, void* param_value,
                   size_t* param_value_size_ret)
{
  return call_function(memobj, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetMemObjectInfo::
Pluggable_clGetMemObjectInfo(function_pointer_t fptr)
  : Base_clGetMemObjectInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetPipeInfo)
cl_int Pluggable_clGetPipeInfo::
clGetPipeInfo(cl_mem pipe, cl_pipe_info param_name,
              size_t param_value_size, void* param_value,
              size_t* param_value_size_ret)
{
  return call_function(pipe, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetPipeInfo::
Pluggable_clGetPipeInfo(function_pointer_t fptr)
  : Base_clGetPipeInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformIDs)
cl_int Pluggable_clGetPlatformIDs::
clGetPlatformIDs(cl_uint num_entries, cl_platform_id* platforms,
                 cl_uint* num_platforms)
{
  return call_function(num_entries, platforms, num_platforms);
}
Pluggable_clGetPlatformIDs::
Pluggable_clGetPlatformIDs(function_pointer_t fptr)
  : Base_clGetPlatformIDs(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetPlatformInfo)
cl_int Pluggable_clGetPlatformInfo::
clGetPlatformInfo(cl_platform_id platform, cl_platform_info param_name,
                  size_t param_value_size, void* param_value,
                  size_t* param_value_size_ret)
{
  return call_function(platform, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetPlatformInfo::
Pluggable_clGetPlatformInfo(function_pointer_t fptr)
  : Base_clGetPlatformInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramBuildInfo)
cl_int Pluggable_clGetProgramBuildInfo::
clGetProgramBuildInfo(cl_program program, cl_device_id device,
                      cl_program_build_info param_name, size_t param_value_size,
                      void* param_value, size_t* param_value_size_ret)
{
  return call_function(program, device, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetProgramBuildInfo::
Pluggable_clGetProgramBuildInfo(function_pointer_t fptr)
  : Base_clGetProgramBuildInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetProgramInfo)
cl_int Pluggable_clGetProgramInfo::
clGetProgramInfo(cl_program program, cl_program_info param_name,
                size_t param_value_size, void* param_value,
                size_t* param_value_size_ret)
{
  return call_function(program, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetProgramInfo::
Pluggable_clGetProgramInfo(function_pointer_t fptr)
  : Base_clGetProgramInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetSamplerInfo)
cl_int Pluggable_clGetSamplerInfo::
clGetSamplerInfo(cl_sampler sampler, cl_sampler_info param_name,
                 size_t param_value_size, void* param_value,
                 size_t* param_value_size_ret)
{
  return call_function(sampler, param_name, param_value_size, param_value, param_value_size_ret);
}
Pluggable_clGetSamplerInfo::
Pluggable_clGetSamplerInfo(function_pointer_t fptr)
  : Base_clGetSamplerInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clGetSupportedImageFormats)
cl_int Pluggable_clGetSupportedImageFormats::
clGetSupportedImageFormats( cl_context context, cl_mem_flags flags,
                            cl_mem_object_type image_type,
                            cl_uint num_entries,
                            cl_image_format* image_formats,
                            cl_uint* num_image_formats)
{
  return call_function( context, flags, image_type, num_entries, image_formats, num_image_formats);
}
Pluggable_clGetSupportedImageFormats::
Pluggable_clGetSupportedImageFormats(function_pointer_t fptr)
  : Base_clGetSupportedImageFormats(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clLinkProgram)
cl_program Pluggable_clLinkProgram::
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
  return call_function(context, num_devices, device_list, options, num_input_programs,
            input_programs, pfn_notify, user_data, errcode_ret);
}
Pluggable_clLinkProgram::
Pluggable_clLinkProgram(function_pointer_t fptr)
  : Base_clLinkProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseCommandQueue)
cl_int Pluggable_clReleaseCommandQueue::
clReleaseCommandQueue(cl_command_queue command_queue)
{
  return call_function(command_queue);
}
Pluggable_clReleaseCommandQueue::
Pluggable_clReleaseCommandQueue(function_pointer_t fptr)
  : Base_clReleaseCommandQueue(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseContext)
cl_int Pluggable_clReleaseContext::
clReleaseContext(cl_context context)
{
  return call_function(context);
}
Pluggable_clReleaseContext::
Pluggable_clReleaseContext(function_pointer_t fptr)
  : Base_clReleaseContext(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseDevice)
cl_int Pluggable_clReleaseDevice::
clReleaseDevice(cl_device_id device)
{
  return call_function(device);
}
Pluggable_clReleaseDevice::
Pluggable_clReleaseDevice(function_pointer_t fptr)
  : Base_clReleaseDevice(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseEvent)
cl_int Pluggable_clReleaseEvent::
clReleaseEvent(cl_event event)
{
  return call_function(event);
}
Pluggable_clReleaseEvent::
Pluggable_clReleaseEvent(function_pointer_t fptr)
  : Base_clReleaseEvent(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseKernel)
cl_int Pluggable_clReleaseKernel::
clReleaseKernel(cl_kernel kernel)
{
  return call_function(kernel);
}
Pluggable_clReleaseKernel::
Pluggable_clReleaseKernel(function_pointer_t fptr)
  : Base_clReleaseKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseMemObject)
cl_int Pluggable_clReleaseMemObject::
clReleaseMemObject(cl_mem memobj)
{
  return call_function(memobj);
}
Pluggable_clReleaseMemObject::
Pluggable_clReleaseMemObject(function_pointer_t fptr)
  : Base_clReleaseMemObject(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseProgram)
cl_int Pluggable_clReleaseProgram::
clReleaseProgram(cl_program program)
{
  return call_function(program);
}
Pluggable_clReleaseProgram::
Pluggable_clReleaseProgram(function_pointer_t fptr)
  : Base_clReleaseProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clReleaseSampler)
cl_int Pluggable_clReleaseSampler::
clReleaseSampler(cl_sampler sampler)
{
  return call_function(sampler);
}
Pluggable_clReleaseSampler::
Pluggable_clReleaseSampler(function_pointer_t fptr)
  : Base_clReleaseSampler(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainCommandQueue)
cl_int Pluggable_clRetainCommandQueue::
clRetainCommandQueue(cl_command_queue command_queue)
{
  return call_function(command_queue);
}
Pluggable_clRetainCommandQueue::
Pluggable_clRetainCommandQueue(function_pointer_t fptr)
  : Base_clRetainCommandQueue(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainContext)
cl_int Pluggable_clRetainContext::
clRetainContext(cl_context context)
{
  return call_function(context);
}
Pluggable_clRetainContext::
Pluggable_clRetainContext(function_pointer_t fptr)
  : Base_clRetainContext(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainDevice)
cl_int Pluggable_clRetainDevice::
clRetainDevice(cl_device_id device)
{
  return call_function(device);
}
Pluggable_clRetainDevice::
Pluggable_clRetainDevice(function_pointer_t fptr)
  : Base_clRetainDevice(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainEvent)
cl_int Pluggable_clRetainEvent::
clRetainEvent(cl_event event)
{
  return call_function(event);
}
Pluggable_clRetainEvent::
Pluggable_clRetainEvent(function_pointer_t fptr)
  : Base_clRetainEvent(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainKernel)
cl_int Pluggable_clRetainKernel::
clRetainKernel(cl_kernel kernel)
{
  return call_function(kernel);
}
Pluggable_clRetainKernel::
Pluggable_clRetainKernel(function_pointer_t fptr)
  : Base_clRetainKernel(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainMemObject)
cl_int Pluggable_clRetainMemObject::
clRetainMemObject(cl_mem memobj)
{
  return call_function(memobj);
}
Pluggable_clRetainMemObject::
Pluggable_clRetainMemObject(function_pointer_t fptr)
  : Base_clRetainMemObject(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainProgram)
cl_int Pluggable_clRetainProgram::
clRetainProgram(cl_program program)
{
  return call_function(program);
}
Pluggable_clRetainProgram::
Pluggable_clRetainProgram(function_pointer_t fptr)
  : Base_clRetainProgram(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clRetainSampler)
cl_int Pluggable_clRetainSampler::
clRetainSampler(cl_sampler sampler)
{
  return call_function(sampler);
}
Pluggable_clRetainSampler::
Pluggable_clRetainSampler(function_pointer_t fptr)
  : Base_clRetainSampler(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetCommandQueueProperty)
cl_int Pluggable_clSetCommandQueueProperty::
clSetCommandQueueProperty(cl_command_queue command_queue,
                          cl_command_queue_properties properties,
                          cl_bool enable,
                          cl_command_queue_properties* old_properties)
{
  return call_function(command_queue, properties, enable, old_properties);
}
Pluggable_clSetCommandQueueProperty::
Pluggable_clSetCommandQueueProperty(function_pointer_t fptr)
  : Base_clSetCommandQueueProperty(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetDefaultDeviceCommandQueue)
cl_int Pluggable_clSetDefaultDeviceCommandQueue::
clSetDefaultDeviceCommandQueue(cl_context context, cl_device_id device,
                               cl_command_queue command_queue)
{
  return call_function(context, device, command_queue);
}
Pluggable_clSetDefaultDeviceCommandQueue::
Pluggable_clSetDefaultDeviceCommandQueue(function_pointer_t fptr)
  : Base_clSetDefaultDeviceCommandQueue(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetEventCallback)
cl_int Pluggable_clSetEventCallback::
clSetEventCallback(cl_event event, cl_int command_exec_callback_type,
                   void(CL_CALLBACK *pfn_event_notify)(cl_event, cl_int, void*),
                   void* user_data)
{
  return call_function(event, command_exec_callback_type, pfn_event_notify, user_data);
}
Pluggable_clSetEventCallback::
Pluggable_clSetEventCallback(function_pointer_t fptr)
  : Base_clSetEventCallback(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArg)
cl_int Pluggable_clSetKernelArg::
clSetKernelArg(cl_kernel kernel, cl_uint arg_index, size_t arg_size, const void* arg_value)
{
  return call_function(kernel, arg_index, arg_size, arg_value);
}
Pluggable_clSetKernelArg::
Pluggable_clSetKernelArg(function_pointer_t fptr)
  : Base_clSetKernelArg(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelArgSVMPointer)
cl_int Pluggable_clSetKernelArgSVMPointer::
clSetKernelArgSVMPointer(cl_kernel kernel, cl_uint arg_index, const void* arg_value)
{
  return call_function(kernel, arg_index, arg_value);
}
Pluggable_clSetKernelArgSVMPointer::
Pluggable_clSetKernelArgSVMPointer(function_pointer_t fptr)
  : Base_clSetKernelArgSVMPointer(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetKernelExecInfo)
cl_int Pluggable_clSetKernelExecInfo::
clSetKernelExecInfo(cl_kernel kernel, cl_kernel_info param_name, size_t param_value_size, const void* param_value)
{
  return call_function(kernel, param_name, param_value_size, param_value);
}
Pluggable_clSetKernelExecInfo::
Pluggable_clSetKernelExecInfo(function_pointer_t fptr)
  : Base_clSetKernelExecInfo(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetMemObjectDestructorCallback)
cl_int Pluggable_clSetMemObjectDestructorCallback::
clSetMemObjectDestructorCallback(cl_mem memobj,
                                 void(CL_CALLBACK* pfn_notify)(cl_mem, void*),
                                 void* user_data)
{
  return call_function(memobj, pfn_notify, user_data);
}
Pluggable_clSetMemObjectDestructorCallback::
Pluggable_clSetMemObjectDestructorCallback(function_pointer_t fptr)
  : Base_clSetMemObjectDestructorCallback(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSetUserEventStatus)
cl_int Pluggable_clSetUserEventStatus::
clSetUserEventStatus( cl_event event , cl_int execution_status )
{
  return call_function(event, execution_status);
}
Pluggable_clSetUserEventStatus::
Pluggable_clSetUserEventStatus(function_pointer_t fptr)
  : Base_clSetUserEventStatus(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSVMAlloc)
void* Pluggable_clSVMAlloc::
clSVMAlloc(cl_context context, cl_svm_mem_flags flags, size_t size, cl_uint alignment)
{
  return call_function(context, flags, size, alignment);
}
Pluggable_clSVMAlloc::
Pluggable_clSVMAlloc(function_pointer_t fptr)
  : Base_clSVMAlloc(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clSVMFree)
void Pluggable_clSVMFree::
clSVMFree(cl_context context, void* svm_pointer)
{
  return call_function(context, svm_pointer);
}
Pluggable_clSVMFree::
Pluggable_clSVMFree(function_pointer_t fptr)
  : Base_clSVMFree(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clUnloadCompiler)
cl_int Pluggable_clUnloadCompiler::
clUnloadCompiler()
{
  return call_function();
}
Pluggable_clUnloadCompiler::
Pluggable_clUnloadCompiler(function_pointer_t fptr)
  : Base_clUnloadCompiler(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clUnloadPlatformCompiler)
cl_int Pluggable_clUnloadPlatformCompiler::
clUnloadPlatformCompiler(cl_platform_id platform)
{
  return call_function(platform);
}
Pluggable_clUnloadPlatformCompiler::
Pluggable_clUnloadPlatformCompiler(function_pointer_t fptr)
  : Base_clUnloadPlatformCompiler(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
#if CLXX_B5D_OPENCL_PROVIDES(clWaitForEvents)
cl_int Pluggable_clWaitForEvents::
clWaitForEvents(cl_uint num_events, const cl_event* event_list)
{
  return call_function(num_events, event_list);
}
Pluggable_clWaitForEvents::
Pluggable_clWaitForEvents(function_pointer_t fptr)
  : Base_clWaitForEvents(), Pluggable_Function(fptr)
{
}
#endif
/* ------------------------------------------------------------------------- */
} // end namespace T
#endif /* CXXTEST_MOCK_TEST_SOURCE_FILE */

#endif /* CLXX_B5D_MOCKS_FUNCTIONS_PLUGGABLE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
