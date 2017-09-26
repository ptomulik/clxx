// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/cl_functions.hpp

/** // doc: clxx/b5d/cl_functions.hpp {{{
 * \file clxx/b5d/cl_functions.hpp
 * \brief Bare C++ wrappers around OpenCL functions.
 */ // }}}
#ifndef CLXX_B5D_CL_FUNCTIONS_HPP_INCLUDED
#define CLXX_B5D_CL_FUNCTIONS_HPP_INCLUDED

#include <clxx/b5d/cl_types.hpp>
#include <clxx/b5d/cl_config.hpp>

namespace clxx {

/** \ingroup clxx_b5d_functions
 *  @{ */
#if CLXX_B5D_PROVIDES(build_program)
/** // doc: build_program(...) {{{
 * \brief Builds (compiles and links) a program executable from the program
 *    source or binary
 *
 * This function is a wrapper around \c clBuildProgram(). The call to this
 * function has same effect as
 *  - \c clBuildProgram(program, num_devices, device_list, options, pfn_notify, user_data)
 *
 * The main difference between \ref build_program() and
 * \c clBuildProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * Builds (compiles & links) a program executable from the program source or
 * binary for all the devices or a specific device(s) in the OpenCL context
 * associated with program. OpenCL allows program executables to be built
 * using the source or the binary. \ref build_program() must be called for
 * program created using either create_program_with_source() or
 * create_program_with_binary() to build the program executable for one or
 * more devices associated with \p program. If \p program is created with
 * create_program_with_binary(), then the program binary must be an executable
 * binary (not a compiled binary or library).
 *
 * The executable binary can be queried using get_program_info(program,
 * program_info_t::binaries, ...) and can be specified to
 * create_program_with_binary() to create a new program object.
 *
 * \par Compiler Options
 *
 * See [clBuildProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clBuildProgram.html).
 *
 * \param program
 *    The program object.
 * \param num_devices
 *    The number of devices listed in \p device_list.
 * \param device_list
 *    A pointer to a list of devices associated with program. If device_list is
 *    \c NULL value, the program executable is built for all devices associated
 *    with program for which a source or binary has been loaded. If device_list
 *    is a non-NULL value, the program executable is built for devices
 *    specified in this list for which a source or binary has been loaded.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    build options to be used for building the program executable. The list of
 *    supported options is described in the OpenCL standard.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \p pfn_notify is not \c NULL, build_program() does
 *    not need to wait for the build to complete and can return immediately
 *    once the build operation can begin. The build operation can begin if the
 *    context, program whose sources are being compiled and linked, list of
 *    devices and build options specified are all valid and appropriate host
 *    and device resources needed to perform the build are available. If
 *    \p pfn_notify is \c NULL, build_program() does not return until the build
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \p pfn_notify is called. \p user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clBuildProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clBuildProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clBuildProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_binary>
 *    When \c clBuildProgram() returns CL_INVALID_BINARY.
 * \throw clerror_no<status_t::invalid_build_options>
 *    When \c clBuildProgram() returns CL_INVALID_BUILD_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clBuildProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::compiler_not_available>
 *    When \c clBuildProgram() returns CL_COMPILER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::build_program_failure>
 *    When \c clBuildProgram() returns CL_BUILD_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clBuildProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clBuildProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clBuildProgram() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clBuildProgram.html">clBuildProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(build_program) void CLXX_B5D_API_CALL
build_program(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data
) CLXX_B5D_API_SUFFIX(build_program);
#endif
#if CLXX_B5D_PROVIDES(clone_kernel)
/** // doc: clone_kernel() {{{
 * \brief Make a shallow copy of the kernel object.
 *
 * This function is a wrapper around \c clCloneKernel(). The call to this
 * function has same effect as
 * - \c clCloneKernel(source_kernel, &errcode_ret),
 * with \c errcode_ret being defined internally in #clone_kernel().
 *
 * The main difference between #clone_kernel() and \c clCloneKernel() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param source_kernel A valid cl_kernel object that will be copied.
 *        source_kernel will not be modified in any way by this function
 * \returns A handle to the cloned kernel object
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clCloneKernel() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCloneKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCloneKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCloneKernel() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clCloneKernel.html">clCloneKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(clone_kernel) cl_kernel CLXX_B5D_API_CALL
clone_kernel(
    cl_kernel source_kernel
) CLXX_B5D_API_SUFFIX(clone_kernel);
#endif
#if CLXX_B5D_PROVIDES(compile_program)
/** // doc: compile_program(...) {{{
 * \brief Compiles a program’s source for all the devices or a specific
 *    device(s) in the OpenCL context associated with program.
 *
 * This function is a wrapper around \c clCompileProgram(). The call to this
 * function has same effect as
 *  - \c clCompileProgram(program, num_devices, device_list, options, num_input_headers, input_headers, header_include_names, pfn_notify, user_data)
 *
 * The main difference between \ref compile_program() and
 * \c clCompileProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * Compiles a program’s source for all the devices or a specific device(s) in
 * the OpenCL context associated with \p program. The pre-processor runs before
 * the program sources are compiled. The compiled binary is built for all
 * devices associated with \p program or the list of devices specified. The
 * compiled binary can be queried using get_program_info(program,
 * program_info_t::binaries, ...) and can be specified to
 * create_program_with_binary() to create a new program object.
 *
 * \par Compiler Options
 *
 * See [clCompileProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCompileProgram.html).
 *
 * \param program
 *    The program object that is the compilation target.
 * \param num_devices
 *    The number of devices listed in \p device_list.
 * \param device_list
 *    A pointer to a list of devices associated with program. If \p device_list
 *    is a \c NULL value, the compile is performed for all devices associated
 *    with program. If device_list is a non-NULL value, the compile is
 *    performed for devices specified in this list.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    compilation options to be used for building the program executable.
 * \param num_input_headers
 *    Specifies the number of programs that describe headers in the array
 *    referenced by \p input_headers.
 * \param input_headers
 *    An array of program embedded headers created with
 *    create_program_with_source().
 * \param header_include_names
 *    An array that has a one to one correspondence with \p input_headers. Each
 *    entry in \p header_include_names specifies the include name used by
 *    source in program that comes from an embedded header. The corresponding
 *    entry in \p input_headers identifies the program object which contains
 *    the header source to be used. The embedded headers are first searched
 *    before the headers in the list of directories specified by the -I compile
 *    option. If multiple entries in \p header_include_names refer to the same
 *    header name, the first one encountered will be used.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \p pfn_notify is not \c NULL, compile_program() does
 *    not need to wait for the compile to complete and can return immediately
 *    once the compile operation can begin. The compile operation can begin if the
 *    context, program whose sources are being compiled and linked, list of
 *    devices and compile options specified are all valid and appropriate host
 *    and device resources needed to perform the compile are available. If
 *    \p pfn_notify is \c NULL, compile_program() does not return until the compile
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \p pfn_notify is called. \p user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCompileProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCompileProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCompileProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_compiler_options>
 *    When \c clCompileProgram() returns CL_COMPILER_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCompileProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::compiler_not_available>
 *    When \c clCompileProgram() returns CL_COMPILER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::compile_program_failure>
 *    When \c clCompileProgram() returns CL_COMPILE_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCompileProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCompileProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCompileProgram() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCompileProgram.html">clCompileProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(compile_program) void CLXX_B5D_API_CALL
compile_program(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data
) CLXX_B5D_API_SUFFIX(compile_program);
#endif
#if CLXX_B5D_PROVIDES(create_buffer)
/** // doc: create_buffer() {{{
 * \brief Creates a buffer object
 *
 * This is a wrapper for \c clCreateBuffer(). The call to \ref
 * create_buffer() has same effect as a call to
 *    - \c clCreateBuffer(context, static_cast<cl_mem_flags>(flags), size, host_ptr, &errcode)
 *
 * with \c errcode being internally defined by #create_buffer().
 *
 * The main difference between create_buffer() and \c clCreateBuffer() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context used to create the buffer object.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information such
 *    as the memory arena that should be used to allocate the buffer object and
 *    how it will be used. See the documentation of #mem_flags_t for defined
 *    bit values.
 * \param size
 *    The size in bytes of the buffer memory object to be allocated.
 * \param host_ptr
 *    A pointer to the buffer data that may already be allocated by the
 *    application. The size of the buffer that \p host_ptr points to must be
 *    greater than or equal to the size bytes.
 *
 * \returns The newly created OpenCL memory object
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_buffer_size>
 *    When \c clCreateBuffer() returns \c CL_INVALID_BUFFER_SIZE.
 * \throw clerror_no<status_t::invalid_host_ptr>
 *    When \c clCreateBuffer() returns \c CL_INVALID_HOST_PTR.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clCreateBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateBuffer.html">clCreateBuffer()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_buffer) cl_mem CLXX_B5D_API_CALL
create_buffer(
    cl_context context,
    mem_flags_t flags,
    size_t size,
    void* host_ptr
) CLXX_B5D_API_SUFFIX(create_buffer);
#endif
#if CLXX_B5D_PROVIDES(create_command_queue)
/** // doc: create_command_queue(...) {{{
 * \brief Create a command-queue on a specific device
 *
 * This is a wrapper around \c clCreateCommandQueue(). The call to this function has
 * same effect as call to
 *   - \c clCreateCommandQueue(context,device,static_cast<cl_command_queue_properties>(properties),errcode_ret)
 *
 * with \p errcode_ret being defined internaly in the create_command_queue().
 *
 * The main difference between clxx::create_command_queue() and
 * \c clCreateCommandQueue() is that it throws %clxx exceptions
 * instead of returning OpenCL error codes and accepts
 * \ref clxx::command_queue_properties_t "command_queue_properties_t"
 * instead of \c cl_command_queue_properties as the \p properties argument.
 *
 * OpenCL objects such as memory, program and kernel objects are created using
 * a context. Operations on these objects are performed using a command-queue.
 * The command-queue can be used to queue a set of operations (referred to as
 * commands) in order. Having multiple command-queues allows applications to
 * queue multiple independent commands without requiring synchronization. Note
 * that this should work as long as these objects are not being shared. Sharing
 * of objects across multiple command-queues will require the application to
 * perform appropriate synchronization. For more informations see the
 * <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueue.html">documentation of the clCreateCommandQueue()</a>.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param device
 *    Must be a device associated with \p context. It can either be in the list
 *    of devices specified when \p context is created using
 *    \ref clxx::create_context() "create_context()" or have the same device
 *    type as the device type specified when the context is created using
 *    \ref clxx::create_context_from_type() "create_context_from_type()".
 * \param properties
 *    Specifies a list of properties for the command-queue. This is a
 *    bit-field. For bits definitions see documentation of
 *    \ref clxx::command_queue_properties_t "command_queue_properties_t".
 *
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_queue_properties>
 *    When \c clCreateCommandQueue() returns error \c CL_INVALID_QUEUE_PROPERTIES
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateCommandQueue() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateCommandQueue() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateCommandQueue() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueue.html">clCreateCommandQueue()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_command_queue) cl_command_queue CLXX_B5D_API_CALL
create_command_queue(
    cl_context context,
    cl_device_id device,
    command_queue_properties_t properties
) CLXX_B5D_API_SUFFIX(create_command_queue);
#endif
#if CLXX_B5D_PROVIDES(create_command_queue_with_properties)
/** // doc: create_command_queue_with_properties(...) {{{
 * \brief Create a host or device command-queue on a specific device
 *
 * This is a wrapper around \c clCreateCommandQueueWithProperties(). The call
 * to this function has same effect as call to
 *   - \c clCreateCommandQueueWithProperties(context,device,properties,errcode_ret)
 *
 * with \p errcode_ret being defined internaly in the
 * create_command_queue_with_properties().
 *
 * The main difference between clxx::create_command_queue_with_properties() and
 * \c clCreateCommandQueueWithProperties() is that it throws %clxx exceptions
 * instead of returning OpenCL error codes.
 *
 * OpenCL objects such as memory, program and kernel objects are created using
 * a context. Operations on these objects are performed using a command-queue.
 * The command-queue can be used to queue a set of operations (referred to as
 * commands) in order. Having multiple command-queues allows applications to
 * queue multiple independent commands without requiring synchronization. Note
 * that this should work as long as these objects are not being shared. Sharing
 * of objects across multiple command-queues will require the application to
 * perform appropriate synchronization. For more informations see the
 * <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueueWithProperties.html">documentation of the clCreateCommandQueueWithProperties()</a>.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param device
 *    Must be a device associated with \p context. It can either be in the list
 *    of devices specified when \p context is created using
 *    \ref clxx::create_context() "create_context()" or have the same device
 *    type as the device type specified when the context is created using
 *    \ref clxx::create_context_from_type() "create_context_from_type()".
 * \param properties
 *    Specifies a list of properties for the command-queue and their
 *    corresponding values. Each property name is immediately followed by the
 *    corresponding desired value. This list is terminated with 0. The list of
 *    supported properties is defined in the OpenCL standard. If a supported
 *    property and its value is not specified in \p properties, its default
 *    value will be used. \p properties can be \c NULL in which case the
 *    default values for supported command-queue properties will be used.
 *
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_queue_properties>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_INVALID_QUEUE_PROPERTIES
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateCommandQueueWithProperties() returns error \c CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateCommandQueueWithProperties() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateCommandQueueWithProperties.html">clCreateCommandQueueWithProperties()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_command_queue_with_properties) cl_command_queue CLXX_B5D_API_CALL
create_command_queue_with_properties(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties
) CLXX_B5D_API_SUFFIX(create_command_queue_with_properties);
#endif
#if CLXX_B5D_PROVIDES(create_context)
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
 *    desired value. The list is terminated with \c 0. \p properties can be
 *    NULL in which case the platform that is selected is
 *    implementation-defined. The list of supported propertes is described in
 *    the OpenCL standard.
 * \param num_devices
 *    The number of devices specified in \p devices argument.
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
 *    \p pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \p pfn_notify is called.
 *    \p user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \p pfn_notify callback.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateContext.html">clCreateContext()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_context) cl_context CLXX_B5D_API_CALL
create_context(
    const cl_context_properties* properties,
    cl_uint num_devices, const cl_device_id* devices,
    void(CL_CALLBACK *pfn_notify)(const char* errinfo,
                                  const void* private_info,
                                  size_t cb, void* user_data),
    void* user_data
) CLXX_B5D_API_SUFFIX(create_context);
#endif
#if CLXX_B5D_PROVIDES(create_context_from_type)
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
 *    desired value. The list is terminated with \c 0. \p properties can be
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
 *    \p pfn_notify is \c NULL, no callback function is registered. The
 *    parameters to this callback function are:
 *      - *errinfo* is a pointer to an error string.
 *      - *private_info*  and *cb* represent a pointer to binary data that is
 *        returned by the OpenCL implementation that can be used to log
 *        additional information helpful in debugging the error.
 *      - *user_data* is a pointer to user supplied data.
 * \param user_data
 *    Passed as the *user_data* argument when \p pfn_notify is called.
 *    \p user_data can be \c NULL.
 *
 * \note there are a number of cases where error notifications need to be
 *    delivered due to an error that occurs outside a context. Such
 *    notification may not be delivered through the \p pfn_notify callback.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateContextFromType.html">clCreateContextFromType()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_context_from_type) cl_context CLXX_B5D_API_CALL
create_context_from_type(
    const cl_context_properties* properties,
    device_type_t device_type,
    void(CL_CALLBACK *pfn_notify)(const char* errinfo,
                                  const void* private_info,
                                  size_t cb,
                                  void* user_data),
    void* user_data
) CLXX_B5D_API_SUFFIX(create_context_from_type);
#endif
#if CLXX_B5D_PROVIDES(create_image)
/** // doc: create_image() {{{
 * \brief Creates a 1D image, 1D image buffer, 1D image array, 2D image, 2D
 *        image array or 3D image object
 *
 * This is a wrapper for \c clCreateImage(). The call to
 * #create_image() has same effect as a call to
 *    - \c clCreateImage(context, static_cast<cl_mem_flags>(flags), image_format, image_desc, host_ptr, &errcode)
 *
 * with \c errcode being defined internally by #create_image().
 *
 * The main difference between #create_image() and \c clCreateImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context on which the image object is to be created.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information
 *    about the image memory object being created. See the documentation
 *    of #mem_flags_t for the list of predefined bit values.
 * \param image_format
 *    A pointer to a structure that describes format properties of the image to
 *    be allocated.
 *    See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/cl_image_format.html">cl_image_format</a>
 *    for a detailed description of the image format descriptor.
 * \param image_desc
 *    A pointer to a structure that describes type and dimensions of the image
 *    to be allocated. See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/cl_image_desc.html">imageDescriptor</a> for more information
 * \param host_ptr
 *    A pointer to the image data that may already be allocated by the
 *    application.
 *
 * \returns A handle to the newly created OpenCL image object
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_image_format_descriptor>
 *    When \c clCreateImage() returns \c CL_INVALID_IMAGE_FORMAT_DESCRIPTOR.
 * \throw clerror_no<status_t::invalid_image_descriptor>
 *    When \c clCreateImage() returns \c CL_INVALID_IMAGE_DESCRIPTOR.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clCreateImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::invalid_host_ptr>
 *    When \c clCreateImage() returns \c CL_INVALID_HOST_PTR.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clCreateImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clCreateImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateImage.html">clCreateImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_image) cl_mem CLXX_B5D_API_CALL
create_image(
    cl_context context,
    mem_flags_t flags,
    const cl_image_format *image_format,
    const cl_image_desc *image_desc,
    void *host_ptr
) CLXX_B5D_API_SUFFIX(create_image);
#endif
#if CLXX_B5D_PROVIDES(create_image_2d)
/** // doc: create_image_2d() {{{
 * \brief Creates a 2D image object.
 *
 *
 * This is a wrapper for \c clCreateImage2D(). The call to
 * #create_image_2d() has same effect as a call to
 *    - \c clCreateImage2D(context, static_cast<cl_mem_flags>(flags), image_format, image_width, image_height, image_row_pitch, host_ptr, &errcode)
 *
 * with \c errcode being defined internally by #create_image_2d().
 *
 * The main difference between #create_image_2d() and \c clCreateImage2D()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context on which the image object is to be created.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information
 *    about the image memory object being created. See the documentation
 *    of #mem_flags_t for the list of predefined bit values.
 * \param image_format
 *    A pointer to a structure that describes format properties of the image to
 *    be allocated.
 *    See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/cl_image_format.html">cl_image_format</a>
 *    for a detailed description of the image format descriptor.
 * \param image_width
 *    The width of the image in pixels. Must be a value greater than or equal to 1.
 * \param image_height
 *    The height of the image in pixels. Must be value greater than or equal to 1.
 * \param image_row_pitch
 *    The scan-line pitch in bytes. This must be 0 if host_ptr is NULL and can
 *    be either 0 or greater than or equal to image_width * size of element in
 *    bytes if host_ptr is not NULL. If host_ptr is not NULL and
 *    image_row_pitch is equal to 0, image_row_pitch is calculated as
 *    image_width * size of element in bytes. If image_row_pitch is not 0, it
 *    must be a multiple of the image element size in bytes.
 * \param host_ptr
 *    A pointer to the image data that may already be allocated by the
 *    application.
 *
 * \returns A handle to the newly created OpenCL image object
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateImage2D() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateImage2D() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_image_format_descriptor>
 *    When \c clCreateImage2D() returns \c CL_INVALID_IMAGE_FORMAT_DESCRIPTOR.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clCreateImage2D() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::invalid_host_ptr>
 *    When \c clCreateImage2D() returns \c CL_INVALID_HOST_PTR.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clCreateImage2D() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clCreateImage2D() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateImage2D() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateImage2D() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateImage2D() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateImage2D() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clCreateImage2D.html">clCreateImage2D()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_image_2d) cl_mem CLXX_B5D_API_CALL
create_image_2d(
    cl_context context,
    mem_flags_t flags,
    const cl_image_format *image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void *host_ptr
) CLXX_B5D_API_SUFFIX(create_image_2d);
#endif
#if CLXX_B5D_PROVIDES(create_image_3d)
/** // doc: create_image_3d() {{{
 * \brief Creates a 3D image object.
 *
 *
 * This is a wrapper for \c clCreateImage3D(). The call to
 * #create_image_3d() has same effect as a call to
 *    - \c clCreateImage3D(context, static_cast<cl_mem_flags>(flags), image_format, image_width, image_height, image_row_pitch, host_ptr, &errcode)
 *
 * with \c errcode being defined internally by #create_image_3d().
 *
 * The main difference between #create_image_3d() and \c clCreateImage3D()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context on which the image object is to be created.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information
 *    about the image memory object being created. See the documentation
 *    of #mem_flags_t for the list of predefined bit values.
 * \param image_format
 *    A pointer to a structure that describes format properties of the image to
 *    be allocated.
 *    See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/cl_image_format.html">cl_image_format</a>
 *    for a detailed description of the image format descriptor.
 * \param image_width
 *    The width of the image in pixels. Must be a value greater than or equal to 1.
 * \param image_height
 *    The height of the image in pixels. Must be value greater than or equal to 1.
 * \param image_depth
 *    The depth of the image in pixels. Must be a value greater than 1.
 * \param image_row_pitch
 *    The scan-line pitch in bytes. This must be 0 if host_ptr is NULL and can
 *    be either 0 or greater than or equal to image_width * size of element in
 *    bytes if host_ptr is not NULL. If host_ptr is not NULL and
 *    image_row_pitch is equal to 0, image_row_pitch is calculated as
 *    image_width * size of element in bytes. If image_row_pitch is not 0, it
 *    must be a multiple of the image element size in bytes.
 * \param image_slice_pitch
 *    The size in bytes of each 2D slice in the 3D image. This must be 0 if
 *    host_ptr is NULL and can be either 0 or greater than or equal to
 *    image_row_pitch * image_height if host_ptr is not NULL. If host_ptr is
 *    not NULL and image_slice_pitch equal to 0, image_slice_pitch is
 *    calculated as image_row_pitch * image_height. If image_slice_pitch is not
 *    0, it must be a multiple of the image_row_pitch.
 * \param host_ptr
 *    A pointer to the image data that may already be allocated by the
 *    application.
 *
 * \returns A handle to the newly created OpenCL image object
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateImage3D() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateImage3D() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_image_format_descriptor>
 *    When \c clCreateImage3D() returns \c CL_INVALID_IMAGE_FORMAT_DESCRIPTOR.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clCreateImage3D() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::invalid_host_ptr>
 *    When \c clCreateImage3D() returns \c CL_INVALID_HOST_PTR.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clCreateImage3D() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clCreateImage3D() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateImage3D() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateImage3D() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateImage3D() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateImage3D() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clCreateImage3D.html">clCreateImage3D()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_image_3d) cl_mem CLXX_B5D_API_CALL
create_image_3d(
    cl_context context,
    mem_flags_t flags,
    const cl_image_format *image_format,
    size_t image_width,
    size_t image_height,
    size_t image_depth,
    size_t image_row_pitch,
    size_t image_slice_pitch,
    void *host_ptr
) CLXX_B5D_API_SUFFIX(create_image_3d);
#endif
#if CLXX_B5D_PROVIDES(create_kernel)
/** // doc: create_kernel() {{{
 * \brief Creates OpenCL kernel
 *
 * This function is a wrapper around \c clCreateKernel(). The call to this
 * function has same effect as
 * - \c clCreateKernel(program, kernel_name, &errcode_ret),
 * with \c errcode_ret being defined internally in #create_kernel().
 *
 * The main difference between #create_kernel() and \c clCreateKernel() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * A kernel is a function declared in a program. A kernel is identified by the
 * \c __kernel qualifier applied to any function in a program. A kernel object
 * encapsulates the specific \c __kernel function declared in a program and the
 * argument values to be used when executing this \c __kernel function.
 *
 * \param program A program object with a successfully built executable.
 * \param kernel_name A function name in the program declared with the __kernel qualifier.
 * \returns A handle to the newly created kernel object
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCreateKernel() returns CL_INVALID_PROGRAM
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clCreateKernel() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_kernel_name>
 *    When \c clCreateKernel() returns CL_INVALID_KERNEL_NAME
 * \throw clerror_no<status_t::invalid_kernel_definition>
 *    When \c clCreateKernel() returns CL_INVALID_KERNEL_DEFINITION
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateKernel() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateKernel() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clCreateKernel.html">clCreateKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_kernel) cl_kernel CLXX_B5D_API_CALL
create_kernel(
    cl_program program,
    const char* kernel_name
) CLXX_B5D_API_SUFFIX(create_kernel);
#endif
#if CLXX_B5D_PROVIDES(create_kernels_in_program)
/** // doc: create_kernels_in_program() {{{
 * \brief Create kernel objects for all kernel functions in \em program
 *
 * This function is a wrapper around \c clCreateKernelsInProgram(). The call to
 * this function has same effect as
 * - \c clCreateKernelsInProgram(program, num_kernels, kernels, num_kernels_ret).
 *
 * The main difference between #create_kernels_in_program() and
 * \c clCreateKernelsInProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param program
 *    A program object with a successfully built executable.
 * \param num_kernels
 *    The size of memory pointed to by \em kernels specified as the number of
 *    \c cl_kernel entries.
 * \param kernels
 *    The buffer where the kernel objects for kernels in program will be
 *    returned. If kernels is \c NULL, it is ignored. If kernels is not \c NULL,
 *    \em num_kernels must be greater than or equal to the number of kernels in
 *    program.
 * \param num_kernels_ret
 *    The number of kernels in program. If \em num_kernels_ret is \c NULL, it
 *    is ignored.
 *
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_PROGRAM
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateKernelsInProgram() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateKernelsInProgram() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateKernelsInProgram() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateKernelsInProgram() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateKernelsInProgram.html">clCreateKernelsInProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_kernels_in_program) void CLXX_B5D_API_CALL
create_kernels_in_program(
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret
) CLXX_B5D_API_SUFFIX(create_kernels_in_program);
#endif
#if CLXX_B5D_PROVIDES(create_pipe)
/** // doc: create_pipe() {{{
 * \brief Creates a pipe object.
 *
 * This is a wrapper for \c clCreatePipe(). The call to
 * #create_pipe() has same effect as a call to
 *    - \c clCreatePipe(context, static_cast<cl_mem_flags>(flags), pipe_packet_size, pipe_max_packets, properties, &errcode)
 *
 * with \c errcode being defined internally by #create_pipe().
 *
 * The main difference between #create_pipe() and \c clCreatePipe()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context used to create the pipe object.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information such
 *    as the memory arena that should be used to allocate the pipe object and
 *    how it will be used.
 * \param pipe_packet_size
 *    Size in bytes of a pipe packet.
 * \param pipe_max_packets
 *    Specifies the pipe capacity by specifying the maximum number of packets
 *    the pipe can hold.
 * \param properties
 *    A list of properties for the pipe and their corresponding values. Each
 *    property name is immediately followed by the corresponding desired value.
 *    The list is terminated with 0. In OpenCL 2.0, properties must be NULL.
 *
 * \returns A handle to the newly created OpenCL image object
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreatePipe() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreatePipe() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_pipe_size>
 *    When \c clCreatePipe() returns \c CL_INVALID_PIPE_SIZE.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clCreatePipe() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreatePipe() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreatePipe() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreatePipe() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clCreatePipe.html">clCreatePipe()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_pipe) cl_mem CLXX_B5D_API_CALL
create_pipe(
    cl_context context,
    mem_flags_t flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties
) CLXX_B5D_API_SUFFIX(create_pipe);
#endif
#if CLXX_B5D_PROVIDES(create_program_with_binary)
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
 *    The number of devices listed in \p device_list.
 *    The devices associated with the program object will be the list of
 *    devices specified by \p device_list. The list of devices specified by
 *    \p device_list must be devices associated with context.
 * \param device_list
 *    A pointer to a list of devices that are in \p context. \p device_list
 *    must be a non-NULL value. The binaries are loaded for devices specified
 *    in this list.
 * \param lengths
 *    Lengths of the \p binaries arrays. For each \c i \p lengths[i] defines
 *    length of \p binaries[i] array.
 * \param binaries
 *    An array of pointers to program binaries to be loaded for devices
 *    specified by \p device_list. For each device given by \p device_list[i],
 *    the pointer to the program binary for that device is given by
 *    \p binaries[i] and the length of this corresponding binary is given by
 *    \p lengths[i]. \p lengths[i] cannot be zero and \p binaries[i] cannot be
 *    a NULL pointer. The program binaries specified by binaries contain the
 *    bits that describe one of the following:
 *      - a program executable to be run on the device(s) associated with \p context.
 *      - a compiled program for \p device(s) associated with context.
 *      - a library of compiled programs for \p device(s) associated with context.
 *    The program binary can consist of either or both of device-specific code
 *    and/or implementation-specific intermediate representation (IR) which
 *    will be converted to the device-specific code.
 * \param binary_status
 *    Returns whether the program binary for each device specified in
 *    device_list was loaded successfully or not. It is an array of
 *    \p num_devices entries and returns \c CL_SUCCESS in \p binary_status[i]
 *    if binary was successfully loaded for device specified by \p device_list[i];
 *    otherwise returns CL_INVALID_VALUE if \p lengths[i] is zero or if
 *    \p binaries[i] is a \c NULL value or \c CL_INVALID_BINARY in
 *    \p binary_status[i] if program binary is not a valid binary for the
 *    specified device. If \p binary_status is \c NULL, it is ignored.
 *
 * \returns
 *    A valid non-zero program object if the program object is created
 *    successfully (otherwise it throws an exception).
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_binary>
 *    When \c clCreateProgramWithBinary() returns CL_INVALID_BINARY.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithBinary() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithBinary() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithBinary() returns other error code.
 *
 * \note This function throws <tt>clerror_no<status_t::invalid_binary></tt>
 *    if any of the provided binaries is invalid. Before raising the exception,
 *    the array pointed to by \p binary_status gets filled with error
 *    information. To ensure that storage for \p binary_status is maintained
 *    properly and does not go out of scope when exception is caught or
 *    propagated, the following (or similar) code pattern should be used
 *    \code
 *      cl_int binary_status[SIZE]; // the array declared in the outer scope
 *      cl_program program = NULL;
 *      try {
 *        program = create_program_with_binary( ..., binary_status);
 *      } catch(clerror_no<status_t::invalid_binary> const& e) {
 *        // scan binary_status to find out which binary caused the problem ...
 *      }
 *    \endcode
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithBinary.html">clCreateProgramWithBinary()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_program_with_binary) cl_program CLXX_B5D_API_CALL
create_program_with_binary(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status
) CLXX_B5D_API_SUFFIX(create_program_with_binary);
#endif
#if CLXX_B5D_PROVIDES(create_program_with_built_in_kernels)
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
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \p device_list.
 * \param device_list
 *    A pointer to a list of devices that are in \p context. \p device_list
 *    must be a non-NULL value. The built-in kernels are loaded for devices
 *    specified in this list. The devices associated with the program object
 *    will be the list of devices specified by \p device_list. The list of
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithBuiltInKernels.html">clCreateProgramWithBuiltInKernels()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_program_with_built_in_kernels) cl_program CLXX_B5D_API_CALL
create_program_with_built_in_kernels(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names
) CLXX_B5D_API_SUFFIX(create_program_with_built_in_kernels);
#endif
#if CLXX_B5D_PROVIDES(create_program_with_il)
/** // doc: create_program_with_il(...) {{{
 * \brief Creates a program object for a context, and loads the IL into the
 *        program object.
 *
 * This function is a wrapper around \c clCreateProgramWithIL().
 * The call to this function has same effect as
 *  - \c clCreateProgramWithIL(context, il, length, &errcode_ret)
 *
 * with \c errcode_ret defined internally in create_program_with_il().
 *
 * The main difference between \ref create_program_with_il() and
 * \c clCreateProgramWithIL() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param il
 *    A pointer to a \p length-byte block of memory containing SPIR-V or an
 *    implementation-defined intermediate language.
 * \param length
 *    Length, in bytes, of the \p il buffer.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateProgramWithIL() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateProgramWithIL() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateProgramWithIL() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateProgramWithIL() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateProgramWithIL() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithIL.html">clCreateProgramWithIL()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_program_with_il) cl_program CLXX_B5D_API_CALL
create_program_with_il(
    cl_context context,
    const void* il,
    size_t length
) CLXX_B5D_API_SUFFIX(create_program_with_il);
#endif
#if CLXX_B5D_PROVIDES(create_program_with_source)
/** // doc: create_program_with_source(...) {{{
 * \brief Creates a program object for a context, and loads the source
 *    code specified by the text strings in the \p strings array into the program
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
 * code specified by the text strings in the \p strings array into the program
 * object. The devices associated with the program object are the devices
 * associated with \p context. The source code specified by \p strings is
 * either an OpenCL C program source, header or implementation-defined source
 * for custom devices that support an online compiler.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param count
 *    Number of elements in \p strings and \p lengths.
 * \param strings
 *    An array of \p count pointers to optionally null-terminated character
 *    strings that make up the source code.
 * \param lengths
 *    An array with the number of chars in each string (the string length). I
 *    an element in lengths i zero, its accompanuing string is null-terminated.
 *    If \p lengths is NULL, all strings in the \p strings argument are
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateProgramWithSource.html">clCreateProgramWithSource()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_program_with_source) cl_program CLXX_B5D_API_CALL
create_program_with_source(
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths
) CLXX_B5D_API_SUFFIX(create_program_with_source);
#endif
#if CLXX_B5D_PROVIDES(create_sampler)
/** // doc: create_sampler() {{{
 * \brief Creates a sampler object
 *
 * This is a wrapper for \c clCreateSampler(). The call to
 * #create_sampler() has same effect as a call to
 *    - \c clCreateSampler(context, normalized_coords, static_cast<cl_addressing_mode>(addressing_mode), static_cast<cl_filter_mode>(filter_mode), &errcode)
 *
 * with \c errcode being internally defined by #create_sampler().
 *
 * The main difference between #create_sampler() and \c clCreateSampler()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param normalized_coords
 *    Determines if the image coordinates specified are normalized (if
 *    \p normalized_coords is \c CL_TRUE) or not (if \p normalized_coords is
 *    \c CL_FALSE).
 * \param addressing_mode
 *    Specifies how out-of-range image coordinates are handled when reading
 *    from an image. See documentation of
 *    \ref clxx::addressing_mode_t "addressing_mode_t"
 *    for the list of possible values.
 * \param filter_mode
 *    Specifies the type of filter that must be applied when reading an image.
 *    See documentation of \ref clxx::filter_mode_t "filter_mode_t" for the
 *    list of possible values.
 *
 * \returns The newly created sampler
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateSampler() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateSampler() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateSampler() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateSampler() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateSampler() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateSampler() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSampler.html">clCreateSampler()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_sampler) cl_sampler CLXX_B5D_API_CALL
create_sampler(
    cl_context context,
    cl_bool normalized_coords,
    addressing_mode_t addressing_mode,
    filter_mode_t filter_mode
) CLXX_B5D_API_SUFFIX(create_sampler);
#endif
#if CLXX_B5D_PROVIDES(create_sampler_with_properties)
/** // doc: create_sampler_with_properties() {{{
 * \brief Creates a sampler object
 *
 * This is a wrapper for \c clCreateSamplerWithProperties(). The call to
 * #create_sampler_with_properties() has same effect as a call to
 *    - \c clCreateSamplerWithProperties(context, sampler_properties, &errcode)
 *
 * with \c errcode being internally defined by #create_sampler_with_properties().
 *
 * The main difference between #create_sampler_with_properties() and \c clCreateSamplerWithProperties()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param sampler_properties
 *    Specifies a list of sampler property names and their corresponding
 *    values. Each sampler property name is immediately followed by the
 *    corresponding desired value. The list is terminated with 0. The list of
 *    supported properties is described in the OpenCL documentation of
 *    <a href="https://www.khronos.org/registry/OpenCL/sdk/2.0/docs/man/xhtml/clCreateSamplerWithProperties.html">clCreateSamplerWithProperties</a>.
 *    If a supported property and its value is not specified in
 *    sampler_properties, its default value will be used. sampler_properties
 *    can be NULL in which case the default values for supported sampler
 *    properties will be used.
 *
 * \returns The newly created sampler
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateSamplerWithProperties() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateSamplerWithProperties() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clCreateSamplerWithProperties() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateSamplerWithProperties() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateSamplerWithProperties() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateSamplerWithProperties() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSamplerWithProperties.html">clCreateSamplerWithProperties()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_sampler_with_properties) cl_sampler CLXX_B5D_API_CALL
create_sampler_with_properties(
    cl_context context,
    const cl_sampler_properties* sampler_properties
) CLXX_B5D_API_SUFFIX(create_sampler_with_properties);
#endif
#if CLXX_B5D_PROVIDES(create_sub_buffer)
/** // doc: create_sub_buffer() {{{
 * \brief Creates a buffer object (referred to as a sub-buffer object) from an
 *        existing buffer object
 *
 * This is a wrapper for \c clCreateSubBuffer(). The call to
 * #create_sub_buffer() has same effect as a call to
 *    - \c clCreateSubBuffer(buffer, static_cast<cl_mem_flags>(flags), static_cast<cl_buffer_create_type>(buffer_create_type), buffer_create_info, &errcode)
 *
 * with \c errcode being internally defined by #create_sub_buffer().
 *
 * The main difference between #create_sub_buffer() and \c clCreateSubBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param buffer
 *    A valid OpenCL memory object. Cannot be a sub-buffer object.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information
 *    about the image memory object being created. See the documentation of
 *    #mem_flags_t for defined bit values.
 * \param buffer_create_type
 *    The type of buffer object to be created. See documentation of
 *    #buffer_create_type_t for possible values.
 * \param buffer_create_info
 *    A pointer to the \c _cl_buffer_region structure, which defines the offset
 *    and size in bytes in \p buffer. For details consult the
 *    <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSubBuffer.html">clCreateSubBuffer()</a>
 *    documentation.
 *
 * \returns The newly created OpenCL sub buffer
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clCreateSubBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clCreateSubBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateSubBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateSubBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clCreateSubBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSubBuffer.html">clCreateSubBuffer()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_sub_buffer) cl_mem CLXX_B5D_API_CALL
create_sub_buffer(
    cl_mem buffer,
    mem_flags_t flags,
    buffer_create_type_t buffer_create_type,
    const void* buffer_create_info
) CLXX_B5D_API_SUFFIX(create_sub_buffer);
#endif
#if CLXX_B5D_PROVIDES(create_sub_devices)
/** // doc: create_sub_devices(...) {{{
 * \brief Creates an array of sub-devices that each reference
 *    a non-intersecting set of compute units within \p in_device.
 *
 * This function is a wrapper around \c clCreateSubDevices(). The main
 * difference between \ref create_sub_devices() and \c clCreateSubDevices() is
 * that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param in_device
 *    The device to be partitioned
 * \param properties
 *    Specifies how \p in_device is to be partition described by a partition
 *    name and its corresponding value. Each partition name is immediately
 *    followed by the corresponding desired value. The list is terminated with
 *    0. The list of supported partitioning schemes is described by the OpenCL
 *    standard (ver. 1.2 and later), see documentation for
 *    \c clCreateSubDevices().
 * \param num_devices
 *    Size of memory pointed to by **out_devices&& specified as the number of
 *    \c cl_device_id entries.
 * \param out_devices
 *    The buffer where OpenCL sub-devices will be returned. If \p out_devices
 *    is \c NULL, this argument is ignored. If \p out_devices is not \c NULL,
 *    \p num_devices must be greater than or equal to the number of
 *    sub-devices than \p in_device may be partitioned into according to the
 *    partitioning scheme specified in \p properties.
 * \param num_devices_ret
 *    Returns the number of sub-devices that device may be partitioned into
 *    according to the partitioning scheme specified in \p properties. If
 *    \p num_devices_reg is \c NULL, it is ignored.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateSubDevices.html">clCreateSubDevices()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_sub_devices) void CLXX_B5D_API_CALL
create_sub_devices(
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint *num_devices_ret
) CLXX_B5D_API_SUFFIX(create_sub_devices);
#endif
#if CLXX_B5D_PROVIDES(create_user_event)
/** // doc: create_user_event() {{{
 * \brief Creates an OpenCL user event object
 *
 * This function is a wrapper around \c clCreateUserEvent(). The call to this
 * function has same effect as
 * - \c clCreateUserEvent(context, &errcode_ret),
 * with \c errcode_ret being defined internally in #create_user_event().
 *
 * The main difference between #create_user_event() and \c clCreateUserEvent() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * User events allow applications to enqueue commands that wait on a user event
 * to finish before the command is executed by the device
 *
 * \param context A valid OpenCL context
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clCreateUserEvent() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clCreateUserEvent() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clCreateUserEvent() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clCreateUserEvent() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clCreateUserEvent.html">clCreateUserEvent()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(create_user_event) cl_event CLXX_B5D_API_CALL
create_user_event(
    cl_context context
) CLXX_B5D_API_SUFFIX(create_user_event);
#endif
#if CLXX_B5D_PROVIDES(enqueue_barrier)
/** // doc: enqueue_barrier() {{{
 * \brief A synchronization point that enqueues a barrier operation.
 *
 * This is a wrapper for \c clEnqueueBarrier(). The call to
 * #enqueue_barrier() has same effect as a call to
 *    - \c clEnqueueBarrier(command_queue)
 *
 * The main difference between #enqueue_barrier() and \c clEnqueueBarrier()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueBarrier() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueBarrier() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueBarrier() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueBarrier() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clEnqueueBarrier.html">clEnqueueBarrier()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_barrier) void CLXX_B5D_API_CALL
enqueue_barrier(
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(enqueue_barrier);
#endif
#if CLXX_B5D_PROVIDES(enqueue_barrier_with_wait_list)
/** // doc: enqueue_barrier_with_wait_list() {{{
 * \brief A synchronization point that enqueues a barrier operation.
 *
 * This is a wrapper for \c clEnqueueBarrierWithWaitList(). The call to
 * #enqueue_barrier_with_wait_list() has same effect as a call to
 *    - \c clEnqueueBarrierWithWaitList(command_queue)
 *
 * The main difference between #enqueue_barrier_with_wait_list() and \c clEnqueueBarrierWithWaitList()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command queue.
 * \param num_events_in_wait_list
 *    Number of events in \p events_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed.
 *
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 *
 *    If \p event_wait_list is NULL, then this particular command waits until
 *    all previous enqueued commands to command_queue have completed.
 * \param event
 *    Returns an event object that identifies this particular command. Event
 *    objects are unique and can be used to identify this barrier command later
 *    on. \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the \p event argument should not refer to an element of
 *    the \p event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueBarrierWithWaitList() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueBarrierWithWaitList() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueBarrierWithWaitList() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueBarrierWithWaitList() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueBarrierWithWaitList() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueBarrierWithWaitList() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueBarrierWithWaitList.html">clEnqueueBarrierWithWaitList()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_barrier_with_wait_list) void CLXX_B5D_API_CALL
enqueue_barrier_with_wait_list(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_barrier_with_wait_list);
#endif
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer)
/** // doc: enqueue_copy_buffer() {{{
 * \brief Enqueues a command to copy from one buffer object to another
 *
 * This is a wrapper for \c clEnqueueCopyBuffer(). The call to
 * #enqueue_copy_buffer() has same effect as a call to
 *    - \c clEnqueueCopyBuffer(command_queue, src_buffer, dst_buffer, src_offset, dst_offset, size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_copy_buffer() and \c clEnqueueCopyBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued. The
 *    OpenCL context associated with \p command_queue, \p src_buffer, and
 *    \p dst_buffer must be the same.
 * \param src_buffer
 *    Source buffer, where the data is to be copied from.
 * \param dst_buffer
 *    Destination buffer, where the data is to be copied into.
 * \param src_offset
 *    The offset where to begin copying data from \p src_buffer.
 * \param dst_offset
 *    The offset where to begin copying data into \p dst_buffer.
 * \param size
 *    Refers to the size in bytes to copy.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete.The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular copy command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueCopyBuffer() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_copy_overlap>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MEM_COPY_OVERLAP.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueCopyBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueCopyBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueCopyBuffer() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueCopyBuffer.html">clEnqueueCopyBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_copy_buffer) void CLXX_B5D_API_CALL
enqueue_copy_buffer(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_copy_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer_rect)
/** // doc: enqueue_copy_buffer_rect() {{{
 * \brief Enqueues a command to copy a 2D or 3D rectangular region from a
 *        buffer object to another buffer object.
 *
 * This is a wrapper for \c clEnqueueCopyBufferRect(). The call to
 * #enqueue_copy_buffer_rect() has same effect as a call to
 *    - \c clEnqueueCopyBufferRect(command_queue, src_buffer, dst_buffer, src_origin, dst_origin, region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_copy_buffer_rect() and \c clEnqueueCopyBufferRect()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    The host command-queue in which the copy command will be queued. The
 *    OpenCL context associated with \p command_queue, \p src_buffer, and
 *    \p dst_buffer must be the same.
 * \param src_buffer
 *    Source buffer, where the data is to be copied from.
 * \param dst_buffer
 *    Destination buffer, where the data is to be copied into.
 * \param src_origin
 *    The (x, y, z) offset in the memory region associated with \p src_buffer.
 *    For a 2D rectangle region, the \c z value given by \p src_origin[2]
 *    should be \c 0. The offset in bytes is computed as \p src_origin[2] *
 *    \p src_slice_pitch + \p src_origin[1] * \p src_row_pitch + \p src_origin[0].
 * \param dst_origin
 *    The (x, y, z) offset in the memory region associated with \p dst_buffer.
 *    For a 2D rectangle region, the \c z value given by \p dst_origin[2]
 *    should be \c 0. The offset in bytes is computed as \p dst_origin[2] *
 *    \p dst_slice_pitch + \p dst_origin[1] * \p dst_row_pitch + dst_origin[0].
 * \param region
 *    The (width in bytes, height in rows, depth in slices) in bytes of the 2D
 *    or 3D rectangle being copied. For a 2D rectangle, the depth value given
 *    by \p region[2] should be \c 1. The values in region cannot be \c 0.
 * \param src_row_pitch
 *    The length of each row in bytes to be used for the memory region
 *    associated with \p src_buffer. If \p src_row_pitch is \c 0,
 *    \p src_row_pitch is computed as \p region[0].
 * \param src_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    associated with \p src_buffer. If \p src_slice_pitch is \c 0,
 *    \p src_slice_pitch is computed as \p region[1] * \p src_row_pitch.
 * \param dst_row_pitch
 *    The length of each row in bytes to be used for the memory region
 *    associated with \p dst_buffer. If \p dst_row_pitch is \c 0,
 *    \p dst_row_pitch is computed as \p region[0].
 * \param dst_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    associated with \p dst_buffer. If \p dst_slice_pitch is \c 0,
 *    \p dst_slice_pitch is computed as \p region[1] * \p dst_row_pitch.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete.The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular copy command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::mem_copy_overlap>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_MEM_COPY_OVERLAP.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueCopyBufferRect() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueCopyBufferRect() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueCopyBufferRect.html">clEnqueueCopyBufferRect()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_copy_buffer_rect) void CLXX_B5D_API_CALL
enqueue_copy_buffer_rect(
    cl_command_queue command_queue,
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
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_copy_buffer_rect);
#endif
#if CLXX_B5D_PROVIDES(enqueue_copy_buffer_to_image)
/** // doc: enqueue_copy_buffer_to_image() {{{
 * \brief Enqueues a command to copy an image object to a buffer object
 *
 * This is a wrapper for \c clEnqueueCopyBufferToImage(). The call to
 * #enqueue_copy_buffer_to_image() has same effect as a call to
 *    - \c clEnqueueCopyBufferToImage(command_queue, src_buffer, dst_image, src_offset, dst_origin, region, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_copy_buffer_to_image() and \c clEnqueueCopyBufferToImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Must be a valid host command-queue. The OpenCL context associated with
 *    \p command_queue, \p src_buffer, and \p dst_image must be the same.
 * \param src_buffer
 *    A valid buffer object.
 * \param dst_image
 *    A valid image object.
 * \param src_offset
 *    The offset where to begin copying data from \p src_buffer
 * \param dst_origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D or 3D image, the (x,
 *    y) offset and the image index in the 2D image array or the (x) offset and
 *    the image index in the 1D image array. If \p dst_image is a 2D image
 *    object, \p dst_origin[2] must be 0. If \p dst_image is a 1D image or 1D
 *    image buffer object, \p dst_origin[1] and \p dst_origin[2] must be 0. If
 *    \p dst_image is a 1D image array object, \p dst_origin[2] must be 0. If
 *    \p dst_image is a 1D image array object, \p dst_origin[1] describes the
 *    image index in the 1D image array. If \p dst_image is a 2D image array
 *    object, \p dst_origin[2] describes the image index in the 2D image array.
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p dst_image
 *    is a 2D image object, \p region[2] must be 1. If \p dst_image is a 1D
 *    image or 1D image buffer object, \p region[1] and \p region[2] must be 1.
 *    If \p dst_image is a 1D image array object, \p region[2] must be 1. The
 *    values in region cannot be 0.
 *    The size in bytes of the region to be copied from \p src_buffer referred
 *    to as \e src_cb is computed as width * height * depth * bytes/image_element
 *    if \p dst_image is a 3D image object, is computed as width * height * bytes/image_element
 *    if \p dst_image is a 2D image, is computed as width height * arraysize * bytes/image_element
 *    if \p dst_image is a 2D image array object, is computed as width * bytes/image_element
 *    if \p dst_image is a 1D image or 1D image buffer object and is computed
 *    as width * arraysize * bytes/image_element if \p dst_image is a 1D image
 *    array object.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular copy command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueCopyBufferToImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueCopyBufferToImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueCopyBufferToImage.html">clEnqueueCopyBufferToImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_copy_buffer_to_image) void CLXX_B5D_API_CALL
enqueue_copy_buffer_to_image(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_copy_buffer_to_image);
#endif
#if CLXX_B5D_PROVIDES(enqueue_copy_image)
/** // doc: enqueue_copy_image() {{{
 * \brief Enqueues a command to copy image objects
 *
 * This is a wrapper for \c clEnqueueCopyImage(). The call to
 * #enqueue_copy_image() has same effect as a call to
 *    - \c clEnqueueCopyImage(command_queue, src_image, dst_image, src_origin, dst_origin, region, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_copy_image() and \c clEnqueueCopyImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Refers to the host command-queue in which the copy command will be
 *    queued. The OpenCL context associated with \p command_queue, \p src_image
 *    and \p dst_image must be the same.
 * \param src_image
 * \param dst_image
 *    Can be 1D, 2D, 3D image or a 1D, 2D image array objects. It is possible
 *    to copy subregions between any combinations of source and destination
 *    types, provided that the dimensions of the subregions are the same e.g.,
 *    one can copy a rectangular region from a 2D image to a slice of a 3D
 *    image.
 * \param src_origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D or 3D image, the (x,
 *    y) offset and the image index in the 2D image array or the (x) offset and
 *    the image index in the 1D image array. If \p src_image is a 2D image
 *    object, \p src_origin[2] must be 0. If \p src_image is a 1D image object,
 *    \p src_origin[1] and \p src_origin[2] must be 0. If src_image is a 1D
 *    image array object, \p src_origin[2] must be 0. If \p src_image is a 1D
 *    image array object, \p src_origin[1] describes the image index in the 1D
 *    image array. If \p src_image is a 2D image array object, \p src_origin[2]
 *    describes the image index in the 2D image array.
 * \param dst_origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D or 3D image, the (x,
 *    y) offset and the image index in the 2D image array or the (x) offset and
 *    the image index in the 1D image array. If \p dst_image is a 2D image
 *    object, \p dst_origin[2] must be 0. If \p dst_image is a 1D image or 1D
 *    image buffer object, \p dst_origin[1] and \p dst_origin[2] must be 0. If
 *    \p dst_image is a 1D image array object, \p dst_origin[2] must be 0. If
 *    \p dst_image is a 1D image array object, \p dst_origin[1] describes the
 *    image index in the 1D image array. If \p dst_image is a 2D image array
 *    object, \p dst_origin[2] describes the image index in the 2D image array.
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p src_image
 *    or \p dst_image is a 2D image object, \p region[2] must be 1. If
 *    \p src_image or \p dst_image is a 1D image or 1D image buffer object,
 *    \p region[1] and \p region[2] must be 1. If \p src_image or dst_image is
 *    a 1D image array object, \p region[2] must be 1. The values in region
 *    cannot be 0.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular copy command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::image_format_mismatch>
 *    When \c clEnqueueCopyImage() returns \c CL_IMAGE_FORMAT_MISMATCH.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueCopyImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueCopyImage() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueCopyImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueCopyImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueCopyImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueCopyImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw clerror_no<status_t::mem_copy_overlap>
 *    When \c clEnqueueCopyImage() returns \c CL_MEM_COPY_OVERLAP.
 * \throw unexpected_clerror
 *    When \c clEnqueueCopyImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueCopyImage.html">clEnqueueCopyImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_copy_image) void CLXX_B5D_API_CALL
enqueue_copy_image(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_copy_image);
#endif
#if CLXX_B5D_PROVIDES(enqueue_copy_image_to_buffer)
/** // doc: enqueue_copy_image_to_buffer() {{{
 * \brief Enqueues a command to copy an image object to a buffer object
 *
 * This is a wrapper for \c clEnqueueFillBuffer(). The call to
 * #enqueue_copy_image_to_buffer() has same effect as a call to
 *    - \c clEnqueueFillBuffer(command_queue, src_image, dst_buffer, src_origin, region, dst_offset, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_copy_image_to_buffer() and \c clEnqueueFillBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Must be a valid host command-queue. The OpenCL context associated with
 *    \p command_queue, \p src_image, and \p dst_buffer must be the same.
 * \param src_image
 *    A valid image object.
 * \param dst_buffer
 *    A valid buffer object.
 * \param src_origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D or 3D image, the (x,
 *    y) offset and the image index in the 2D image array or the (x) offset and
 *    the image index in the 1D image array. If \p src_image is a 2D image
 *    object, \p src_origin[2] must be 0. If \p src_image is a 1D image or 1D
 *    image buffer object, \p src_origin[1] and \p src_origin[2] must be 0. If
 *    \p src_image is a 1D image array object, \p src_origin[2] must be 0. If
 *    \p src_image is a 1D image array object, \p src_origin[1] describes the
 *    image index in the 1D image array. If \p src_image is a 2D image array
 *    object, \p src_origin[2] describes the image index in the 2D image array.
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p src_image
 *    is a 2D image object, \p region[2] must be 1. If \p src_image is a 1D
 *    image or 1D image buffer object, \p region[1] and \p region[2] must be 1.
 *    If \p src_image is a 1D image array object, \p region[2] must be 1. The
 *    values in region cannot be 0.
 * \param dst_offset
 *    Refers to the offset where to begin copying data into \p dst_buffer. The
 *    size in bytes of the region to be copied referred to as \e dst_cb is
 *    computed as width * height * depth * bytes/image element if \p src_image
 *    is a 3D image object, is computed as width * height * bytes/image element
 *    if \p src_image is a 2D image, is computed as width * height * arraysize
 *    * bytes/image element if \p src_image is a 2D image array object, is
 *    computed as width * bytes/image element if \p src_image is a 1D image or
 *    1D image buffer object and is computed as width * arraysize * bytes/image
 *    element if \p src_image is a 1D image array object.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular copy command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueFillBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueFillBuffer() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueFillBuffer() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueFillBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueFillBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueFillBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueFillBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueFillBuffer.html">clEnqueueFillBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_copy_image_to_buffer) void CLXX_B5D_API_CALL
enqueue_copy_image_to_buffer(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_copy_image_to_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_fill_buffer)
/** // doc: enqueue_fill_buffer() {{{
 * \brief Enqueues a command to fill a buffer object with a pattern of a given
 *        pattern size
 *
 * This is a wrapper for \c clEnqueueFillBuffer(). The call to
 * #enqueue_fill_buffer() has same effect as a call to
 *    - \c clEnqueueFillBuffer(command_queue, buffer, pattern, pattern_size, offset, size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_fill_buffer() and \c clEnqueueFillBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Refers to the host command-queue in which the fill command will be
 *    queued. The OpenCL context associated with \p command_queue and \p buffer
 *    must be the same.
 * \param buffer
 *    A valid buffer object.
 * \param pattern
 *    A pointer to the data pattern of size \p pattern_size in bytes. pattern
 *    will be used to fill a region in buffer starting at \p offset and is
 *    \p size bytes in size. The data pattern must be a scalar or vector
 *    integer or floating-point data type. For example, if \p buffer is to be
 *    filled with a pattern of \c float4 values, then \p pattern will be a
 *    pointer to a \c cl_float4 value and \p pattern_size will be
 *    <tt>sizeof(cl_float4)</tt>. The maximum value of \p pattern_size is the
 *    size of the largest integer or floating-point vector data type supported
 *    by the OpenCL device. The memory associated with \p pattern can be reused
 *    or freed after the function returns.
 * \param offset
 *    The location in bytes of the region being filled in \p buffer and must be
 *    a multiple of \p pattern_size.
 * \param size
 *    The size in bytes of region being filled in \p buffer and must be a
 *    multiple of \p pattern_size.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    Together with \p num_events_in_wait_list specify events that need to
 *    complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization points. The
 *    context associated with events in \p event_wait_list and \p command_queue
 *    must be the same. The memory associated with \p event_wait_list can be
 *    reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete.
 *    \ref clxx::enqueue_barrier_with_wait_list "enqueue_barrier_with_wait_list"
 *    can be used instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueFillBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueFillBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueFillBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueFillBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueFillBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueFillBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueFillBuffer.html">clEnqueueFillBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_fill_buffer) void CLXX_B5D_API_CALL
enqueue_fill_buffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_fill_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_fill_image)
/** // doc: enqueue_fill_image() {{{
 * \brief Enqueues a command to fill an image object with a specified color.
 *
 * This is a wrapper for \c clEnqueueFillImage(). The call to
 * #enqueue_fill_image() has same effect as a call to
 *    - \c clEnqueueFillImage(command_queue, image, fill_color, origin, region, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_fill_image() and \c clEnqueueFillImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Refers to the host command-queue in which the fill command will be
 *    queued. The OpenCL context associated with \p command_queue and \p image
 *    must be the same.
 * \param image
 *    A valid image object.
 * \param fill_color
 *    The color used to fill the image. The fill color is a single floating
 *    point value if the channel order is cl_chanel_order_t::depth. Otherwise,
 *    the fill color is a four component RGBA floating-point color value if the
 *    image channel data type is not an unnormalized signed or unsigned integer
 *    type, is a four component signed integer value if the image channel data
 *    type is an unnormalized signed integer type and is a four component
 *    unsigned integer value if the image channel data type is an unnormalized
 *    unsigned integer type. The fill color will be converted to the
 *    appropriate image channel format and order associated with image as
 *    described in OpenCL standard.
 * \param origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D, or 3D image, the
 *    (x, y) offset and the image index in the image array or the (x) offset
 *    and the image index in the 1D image array. If \p image is a 2D image
 *    object, \p origin[2] must be \c 0. If \p image is a 1D image or 1D image
 *    buffer object, \p origin[1] and \p origin[2] must be \c 0. If \p image is
 *    a 1D image array object, \p origin[2] must be \c 0. If \p image is a 1D
 *    image array object, \p origin[1] describes the image index in the 1D
 *    image array. If \p image is a 2D image array object, \p origin[2]
 *    describes the image index in the 2D image array.
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p image is a
 *    2D image object, \p region[2] must be \c 1. If \p image is a 1D image or
 *    1D image buffer object, \p region[1] and \p region[2] must be \c 1. If
 *    \p image is a 1D image array object, \p region[2] must be \c 1. The
 *    values in region cannot be \c 0.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    Together with \p num_events_in_wait_list specify events that need to
 *    complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization points. The
 *    context associated with events in \p event_wait_list and \p command_queue
 *    must be the same. The memory associated with \p event_wait_list can be
 *    reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete.
 *    \ref clxx::enqueue_barrier_with_wait_list "enqueue_barrier_with_wait_list"
 *    can be used instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueFillImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueFillImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueFillImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueFillImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueFillImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueFillImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueFillImage.html">clEnqueueFillImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_fill_image) void CLXX_B5D_API_CALL
enqueue_fill_image(
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_fill_image);
#endif
#if CLXX_B5D_PROVIDES(enqueue_map_buffer)
/** // doc: enqueue_map_buffer() {{{
 * \brief Enqueues a command to map a region of the buffer object given by
 *        \p buffer into the host address space and returns a pointer to this
 *        mapped region.
 *
 * This is a wrapper for \c clEnqueueMapBuffer(). The call to
 * #enqueue_map_buffer() has same effect as a call to
 *    - \c clEnqueueMapBuffer(command_queue, buffer, blocking_map, static_cast<cl_map_flags>(map_flags), offset, size, num_events_in_wait_list, event_wait_list, event, &errcode)
 *
 * with \c errcode being defined internally by #enqueue_map_buffer().
 *
 * The main difference between #enqueue_map_buffer() and \c clEnqueueMapBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param buffer
 *    The buffer object to be mapped.
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 *    If \p blocking_map is \c CL_TRUE, #enqueue_map_buffer() does not return
 *    until the specified region in buffer is mapped into the host address
 *    space and the application can access the contents of the mapped region
 *    using the pointer returned by enqueue_map_buffer().
 *    If \p blocking_map is \c CL_FALSE i.e. map operation is non-blocking, the
 *    pointer to the mapped region returned by enqueue_map_buffer() cannot be
 *    used until the map command has completed. The \p event argument returns
 *    an event object which can be used to query the execution status of the
 *    map command. When the map command is completed, the application can
 *    access the contents of the mapped region using the pointer returned by
 *    enqueue_map_buffer().
 * \param map_flags
 *    A bit-field with mapping options. See the documentation of #map_flags_t
 *    for the predefined bit values.
 * \param offset
 *    The offset in bytes of the region in the buffer object that is being
 *    mapped.
 * \param size
 *    The size in bytes of the region in the buffer object that is being
 *    mapped.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular map command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \returns A pointer to mapped buffer.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::map_failure>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MAP_FAILURE.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueCopyBuffer() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueCopyBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueCopyBuffer() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueCopyBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueCopyBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueCopyBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueCopyBuffer.html">clEnqueueCopyBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_map_buffer) void* CLXX_B5D_API_CALL
enqueue_map_buffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_map,
    map_flags_t map_flags,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_map_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_map_image)
/** // doc: enqueue_map_image() {{{
 * \brief Enqueues a command to map a region of an image object into the host
 *        address space and returns a pointer to this mapped region
 *
 * This is a wrapper for \c clEnqueueMapImage(). The call to
 * #enqueue_map_image() has same effect as a call to
 *    - \c clEnqueueMapImage(command_queue, image, blocking_map, static_cast<cl_map_flags>(map_flags), origin, region, image_row_pitch, image_slice_pitch, num_events_in_wait_list, event_wait_list, event, &errcode)
 *
 * with \c errcode being internally defined by #enqueue_map_image().
 *
 * The main difference between #enqueue_map_image() and \c clEnqueueMapImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param image
 *    A valid image object. The OpenCL context associated with \p command_queue
 *    and \p image must be the same.
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 *    If \p blocking_map is \c CL_TRUE, #enqueue_map_image() does not return
 *    until the specified region in image is mapped into the host address space
 *    and the application can access the contents of the mapped region using
 *    the pointer returned by #enqueue_map_image().
 *    If \p blocking_map is \c CL_FALSE i.e. map operation is non-blocking, the
 *    pointer to the mapped region returned by #enqueue_map_image() cannot be
 *    used until the map command has completed. The \p event argument returns
 *    an event object which can be used to query the execution status of the
 *    map command. When the map command is completed, the application can
 *    access the contents of the mapped region using the pointer returned by
 *    #enqueue_map_image()
 * \param map_flags
 *    A bit-field with map options. See the documentation of #map_flags_t
 *    for the list of predefined bit values.
 * \param origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D or 3D image, the (x,
 *    y) offset and the image index in the 2D image array or the (x) offset and
 *    the image index in the 1D image array. If \p image is a 2D image object,
 *    \p origin[2] must be 0. If \p image is a 1D image or 1D image buffer
 *    object, \p origin[1] and \p origin[2] must be 0. If \p image is a 1D
 *    image array object, \p origin[2] must be 0. If image is a 1D image array
 *    object, \p origin[1] describes the image index in the 1D image array. If
 *    \p image is a 2D image array object, \p origin[2] describes the image
 *    index in the 2D image array.
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p image is a
 *    2D image object, \p region[2] must be 1. If \p image is a 1D image or 1D
 *    image buffer object, \p region[1] and \p region[2] must be 1. If image is
 *    a 1D image array object, \p region[2] must be 1. The values in region
 *    cannot be 0.
 * \param image_row_pitch
 *    Returns the scan-line pitch in bytes for the mapped region. This must be
 *    a non-NULL value.
 * \param image_slice_pitch
 *    Returns the size in bytes of each 2D slice of a 3D image or the size of
 *    each 1D or 2D image in a 1D or 2D image array for the mapped region. For
 *    a 1D and 2D image, zero is returned if this argument is not \c NULL. For
 *    a 3D image, 1D, and 2D image array, \p image_slice_pitch must be a
 *    non-NULL value.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular map command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \returns A pointer to mapped buffer.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueMapImage() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::map_failure>
 *    When \c clEnqueueMapImage() returns \c CL_MAP_FAILURE.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueMapImage() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueMapImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueMapImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueMapImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueMapImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueMapImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueMapImage.html">clEnqueueMapImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_map_image) void* CLXX_B5D_API_CALL
enqueue_map_image(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_map,
    map_flags_t map_flags,
    const size_t* origin,
    const size_t* region,
    size_t* image_row_pitch,
    size_t* image_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_map_image);
#endif
#if CLXX_B5D_PROVIDES(enqueue_marker)
/** // doc: enqueue_marker() {{{
 * \brief Enqueues a marker command.
 *
 * This is a wrapper for \c clEnqueueMarker(). The call to
 * #enqueue_marker() has same effect as a call to
 *    - \c clEnqueueMarker(command_queue, &errcode)
 *
 * with \c errcode being internally defined by #enqueue_marker().
 *
 * The main difference between #enqueue_marker() and \c clEnqueueMarker()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * Enqueues a marker command to \p command_queue. The marker command is not
 * completed until all commands enqueued before it have completed. The marker
 * command returns an event which can be waited on, i.e. this event can be
 * waited on to ensure that all commands which have been queued before the
 * marker command have been completed.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param event
 *    Returns an event object that identifies this particular mark command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueMarker() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueMarker() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueMarker() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueMarker() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueMarker() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clEnqueueMarker.html">clEnqueueMarker()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_marker) void CLXX_B5D_API_CALL
enqueue_marker(
    cl_command_queue command_queue,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_marker);
#endif
#if CLXX_B5D_PROVIDES(enqueue_marker_with_wait_list)
/** // doc: enqueue_marker_with_wait_list() {{{
 * \brief Enqueues a marker command which waits for either a list of events to
 *        complete, or all previously enqueued commands to complete.
 *
 * This is a wrapper for \c clEnqueueMarkerWithWaitList(). The call to
 * #enqueue_marker_with_wait_list() has same effect as a call to
 *    - \c clEnqueueMarkerWithWaitList(command_queue, &errcode)
 *
 * with \c errcode being internally defined by #enqueue_marker_with_wait_list().
 *
 * The main difference between #enqueue_marker_with_wait_list() and \c clEnqueueMarkerWithWaitList()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * Enqueues a marker command which waits for either a list of events to
 * complete, or if the list is empty it waits for all commands previously
 * enqueued in \p command_queue to complete before it completes. This command
 * returns an event which can be waited on, i.e. this event can be waited on to
 * insure that all events either in the \p event_wait_list or all previously
 * enqueued commands, queued before this command to \p command_queue, have
 * completed.
 *
 * \param command_queue
 *    A valid host command-queue.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specifies events that need to complete before this particular command can
 *    be executed.
 *
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be
 *    \c 0. If \p event_wait_list is not \c NULL, the list of events pointed to
 *    by \p event_wait_list must be valid and \p num_events_in_wait_list must
 *    be greater than \c 0. The events specified in \p event_wait_list act as
 *    synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 *
 *    If \p event_wait_list is \c NULL, then this particular command waits
 *    until all previous enqueued commands to \p command_queue have completed.
 * \param event
 *    Returns an event object that identifies this particular command. Event
 *    objects are unique and can be used to identify this marker command later
 *    on. \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the \p event argument should not refer to an element of
 *    the \p event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueMarkerWithWaitList() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueMarkerWithWaitList() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueMarkerWithWaitList() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueMarkerWithWaitList() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueMarkerWithWaitList() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueMarkerWithWaitList() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueMarkerWithWaitList.html">clEnqueueMarkerWithWaitList()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_marker_with_wait_list) void CLXX_B5D_API_CALL
enqueue_marker_with_wait_list(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_marker_with_wait_list);
#endif
#if CLXX_B5D_PROVIDES(enqueue_migrate_mem_objects)
/** // doc: enqueue_migrate_mem_objects() {{{
 * \brief Enqueues a command to indicate which device a set of memory objects
 *        should be associated with
 *
 * This is a wrapper for \c clEnqueueMigrateMemObjects(). The call to
 * #enqueue_migrate_mem_objects() has same effect as a call to
 *    - \c clEnqueueMigrateMemObjects(command_queue, num_mem_objects, mem_objects, static_cast<cl_mem_migration_flags>(flags), num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_migrate_mem_objects() and \c clEnqueueMigrateMemObjects()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue. The specified set of memory objects in
 *    \p mem_objects will be migrated to the OpenCL device associated with
 *    \p command_queue or to the host if the mem_migration_flags_t::mem_object_host
 *    has been specified in \p flags.
 * \param num_mem_objects
 *    The number of memory objects specified in \p mem_objects.
 * \param mem_objects
 *    A pointer to a list of memory objects.
 * \param flags
 *    A bit-field that is used to specify migration options. See the
 *    documentation of #mem_migration_flags_t for the list of predefined bit
 *    values.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueMigrateMemObjects() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueMigrateMemObjects() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueMigrateMemObjects.html">clEnqueueMigrateMemObjects()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_migrate_mem_objects) void CLXX_B5D_API_CALL
enqueue_migrate_mem_objects(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    mem_migration_flags_t flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_migrate_mem_objects);
#endif
#if CLXX_B5D_PROVIDES(enqueue_native_kernel)
/** // doc: enqueue_native_kernel() {{{
 * \brief Enqueues a command to execute a native C/C++ function
 *
 * Enqueues a command to execute a native C/C++ function not compiled using the
 * OpenCL compiler.
 *
 * This function is a wrapper around \c clEnqueueNativeKernel(). The call to this
 * function has same effect as
 *  - \c clEnqueueNativeKernel(command_queue, user_func, args, cb_args, num_mem_objects, mem_list, args_mem_loc, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between \ref enqueue_native_kernel() and
 * \c clEnqueueNativeKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue. A native user function can only be executed
 *    on a command-queue created on a device that has \c CL_EXEC_NATIVE_KERNEL
 *    capability set in \c CL_DEVICE_EXECUTION_CAPABILITIES as specified in the
 *    table of OpenCL Device Queries for \c clGetDeviceInfo.
 * \param user_func
 *    A pointer to a host-callable user function.
 * \param args
 *    A pointer to the args list that \em user_func should be called with.
 * \param cb_args
 *    The size in bytes of the \em args list that args points to.
 * \param num_mem_objects
 *    The number of buffer objects that are passed in \em args.
 * \param mem_list
 *    A list of valid buffer objects, if \em num_mem_objects > 0. The buffer
 *    object values specified in \em mem_list are memory object handles
 *    (\c cl_mem values) returned by #create_buffer() or \c NULL.
 * \param args_mem_loc
 *    A pointer to appropriate locations that \em args points to where memory
 *    object handles (\c cl_mem values) are stored. Before the user function is
 *    executed, the memory object handles are replaced by pointers to global
 *    memory.
 * \param num_events_in_wait_list
 *    Number of events in \em event_wait_list
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \em event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \em event_wait_list is
 *    \c NULL, \em num_events_in_wait_list must be \c 0. If \em event_wait_list
 *    is not \c NULL, the list of events pointed to by \em event_wait_list must
 *    be valid and \em num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \em event_wait_list act as synchronization points.
 *    The context associated with events in \em event_wait_list and
 *    \em %command_queue must be the same. The memory associated with
 *    \em event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular kernel execution
 *    instance. Event objects are unique and can be used to identify a
 *    particular kernel execution instance later on. If event is \c NULL, no
 *    event will be created for this kernel execution instance and therefore it
 *    will not be possible for the application to query or queue a wait for
 *    this particular kernel execution instance. If the \em event_wait_list and
 *    the event arguments are not \c NULL, the event argument should not refer
 *    to an element of the \em event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_MEM_OBJECT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueNativeKernel returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueNativeKernel returns CL_MEM_OBJECT_ALLOCATION_FAILURE
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueNativeKernel returns CL_INVALID_EVENT_WAIT_LIST
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueNativeKernel returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clEnqueueNativeKernel returns other error code
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNativeKernel.html">clEnqueueNativeKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_native_kernel) void CLXX_B5D_API_CALL
enqueue_native_kernel(
    cl_command_queue command_queue,
    void (CL_CALLBACK* user_func)(void*),
    void* args,
    size_t cb_args,
    cl_uint num_mem_objects,
    const cl_mem* mem_list,
    const void** args_mem_loc,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_native_kernel);
#endif
#if CLXX_B5D_PROVIDES(enqueue_ndrange_kernel)
/** // doc: enqueue_ndrange_kernel() {{{
 * \brief Enqueues a command to execute a kernel on a device
 *
 * This function is a wrapper around \c clEnqueueNDRangeKernel(). The call to this
 * function has same effect as
 *  - \c clEnqueueNDRangeKernel(command_queue, kernel, work_dim, global_work_offset, global_work_size, local_work_size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between \ref enqueue_ndrange_kernel() and
 * \c clEnqueueNDRangeKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue. The kernel will be queued for execution on
 *    the device associated with \em %command_queue.
 * \param kernel
 *    A valid kernel object. The OpenCL context associated with \em kernel and
 *    \em %command_queue must be the same.
 * \param work_dim
 *    The number of dimensions used to specify the global work-items and
 *    work-items in the work-group. \em work_dim must be greater than zero and
 *    less than or equal to \c CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS.
 * \param global_work_offset
 *    \em global_work_offset can be used to specify an array of work_dim
 *    unsigned values that describe the offset used to calculate the global ID
 *    of a work-item. If \em global_work_offset is \c NULL, the global IDs
 *    start at offset <tt>(0, 0, ... 0)</tt>.
 * \param global_work_size
 *    Points to an array of \em work_dim unsigned values that describe the
 *    number of global work-items in work_dim dimensions that will execute the
 *    kernel function. The total number of global work-items is computed as
 *    <tt>global_work_size[0] *...* global_work_size[work_dim - 1]</tt>.
 * \param local_work_size
 *    Points to an array of \em work_dim unsigned values that describe the
 *    number of work-items that make up a work-group (also referred to as the
 *    size of the work-group) that will execute the kernel specified by kernel.
 *    See <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNDRangeKernel.html">clEnqueueNDRangeKernel()</a>
 *    for more details.
 * \param num_events_in_wait_list
 *    Number of events in \em event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \em event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If event_wait_list is
 *    \c NULL, \em num_events_in_wait_list must be \c 0. If event_wait_list is
 *    not \c NULL, the list of events pointed to by \em event_wait_list must be
 *    valid and \em num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \em event_wait_list act as synchronization points.
 *    The context associated with events in \em event_wait_list and
 *    \em %command_queue must be the same. The memory associated with
 *    \em event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular kernel execution
 *    instance. Event objects are unique and can be used to identify a
 *    particular kernel execution instance later on. If event is \c NULL, no
 *    event will be created for this kernel execution instance and therefore it
 *    will not be possible for the application to query or queue a wait for
 *    this particular kernel execution instance. If the event_wait_list and the
 *    event arguments are not \c NULL, the event argument should not refer to
 *    an element of the \em event_wait_list array.
 *
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_PROGRAM_EXECUTABLE
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::invalid_kenel>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::invalid_context>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_kernel_args>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_KERNEL_ARGS
 * \throw clerror_no<status_t::invalid_work_dimension>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_DIMENSION
 * \throw clerror_no<status_t::invalid_global_work_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_GLOBAL_WORK_SIZE
 * \throw clerror_no<status_t::invalid_global_offset>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_GLOBAL_OFFSET
 * \throw clerror_no<status_t::invalid_work_group_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_GROUP_SIZE
 * \throw clerror_no<status_t::invalid_work_item_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_WORK_ITEM_SIZE
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When the \c clEnqueueNDRangeKernel() returns CL_MISALIGNED_SUB_BUFFER_OFFSET
 * \throw clerror_no<status_t::invalid_image_size>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_IMAGE_SIZE
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When the \c clEnqueueNDRangeKernel() returns CL_IMAGE_FORMAT_NOT_SUPPORTED
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clEnqueueNDRangeKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When the \c clEnqueueNDRangeKernel() returns CL_MEM_OBJECT_ALLOCATION_FAILURE
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_EVENT_WAIT_LIST
 * \throw clerror_no<status_t::invalid_operation>
 *    When the \c clEnqueueNDRangeKernel() returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clEnqueueNDRangeKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When other error code is returned
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueNDRangeKernel.html">clEnqueueNDRangeKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_ndrange_kernel) void CLXX_B5D_API_CALL
enqueue_ndrange_kernel(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_ndrange_kernel);
#endif
#if CLXX_B5D_PROVIDES(enqueue_read_buffer)
/** // doc: enqueue_read_buffer() {{{
 * \brief Enqueue commands to read from a buffer object to host memory
 *
 * This is a wrapper for \c clEnqueueReadBuffer(). The call to
 * #enqueue_read_buffer() has same effect as a call to
 *    - \c clEnqueueReadBuffer(command_queue, buffer, blocking_read, offset, size, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_read_buffer() and \c clEnqueueReadBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Is a valid host command-queue in which the read command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    context.
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_read
 *    Indicates if the read operations are blocking or non-blocking.
 *    If \p blocking_read is \c CL_TRUE i.e. the read command is blocking,
 *    #enqueue_read_buffer() does not return until the buffer data has been
 *    read and copied into memory pointed to by \p ptr.
 *    If \p blocking_read is \c CL_FALSE i.e. the read command is non-blocking,
 *    #enqueue_read_buffer() queues a non-blocking read command and returns.
 *    The contents of the buffer that \p ptr points to cannot be used until the
 *    read command has completed. The \p event argument returns an event object
 *    which can be used to query the execution status of the read command. When
 *    the read command has completed, the contents of the buffer that \p ptr
 *    points to can be used by the application.
 * \param offset
 *    The offset in bytes in the buffer object to read from.
 * \param size
 *    The size in bytes of data being read.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read into.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueReadBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueReadBuffer() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueReadBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueReadBuffer() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueReadBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueReadBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueReadBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueReadBuffer.html">clEnqueueReadBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_read_buffer) void CLXX_B5D_API_CALL
enqueue_read_buffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_read_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_read_buffer_rect)
/** // doc: enqueue_read_buffer_rect() {{{
 * \brief Enqueue command to read from a 2D or 3D rectangular region from a
 *        buffer object to host memory.
 *
 * This is a wrapper for \c clEnqueueReadBufferRect(). The call to
 * #enqueue_read_buffer_rect() has same effect as a call to
 *    - \c clEnqueueReadBufferRect(command_queue, buffer, blocking_read, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_read_buffer_rect() and \c clEnqueueReadBufferRect()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Is a valid host command-queue in which the read command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL context.
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_read
 *    Indicates if the read operations are \e blocking or \e non-blocking.
 *    If \p blocking_read is \c CL_TRUE i.e. the read command is blocking,
 *    #enqueue_read_buffer_rect() does not return until the buffer data has been
 *    read and copied into memory pointed to by \p ptr.
 *    If \p blocking_read is \c CL_FALSE i.e. the read command is non-blocking,
 *    #enqueue_read_buffer_rect() queues a non-blocking read command and returns.
 *    The contents of the buffer that \p ptr points to cannot be used until the
 *    read command has completed. The \p event argument returns an event object
 *    which can be used to query the execution status of the read command. When
 *    the read command has completed, the contents of the buffer that \p ptr
 *    points to can be used by the application.
 * \param buffer_origin
 *    The (x, y, z) offset in the memory region associated with \p buffer. For
 *    a 2D rectangle region, the \c z value given by \p buffer_origin[2] should
 *    be \c 0. The offset in bytes is computed as \p buffer_origin[2] *
 *    \p buffer_slice_pitch + \p buffer_origin[1] * \p buffer_row_pitch +
 *    \p buffer_origin[0].
 * \param host_origin
 *    The (x, y, z) offset in the memory region pointed to by \p ptr. For a 2D
 *    rectangle region, the \c z value given by \p host_origin[2] should be
 *    \c 0. The offset in bytes is computed as \p host_origin[2] *
 *    \p host_slice_pitch + \p host_origin[1] * \p host_row_pitch +
 *    \p host_origin[0].
 * \param region
 *    The (width in bytes, height in rows, depth in slices) of the 2D or 3D
 *    rectangle being read or written. For a 2D rectangle copy, the depth value
 *    given by \p region[2] should be \c 1. The values in \p region cannot be
 *    \c 0.
 * \param buffer_row_pitch
 *    The length of each row in bytes to be used for the memory region
 *    associated with \p buffer. If \p buffer_row_pitch is \c 0,
 *    \p buffer_row_pitch is computed as \p region[0].
 * \param buffer_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    associated with \p buffer. If \p buffer_slice_pitch is \c 0,
 *    \p buffer_slice_pitch is computed as \p region[1] * \p buffer_row_pitch.
 * \param host_row_pitch
 *    The length of each row in bytes to be used for the memory region pointed
 *    to by \p ptr. If \p host_row_pitch is \c 0, \p host_row_pitch is computed
 *    as \p region[0].
 * \param host_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    pointed to by \p ptr. If \p host_slice_pitch is \c 0, \p host_slice_pitch
 *    is computed as \p region[1] * \p host_row_pitch.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be read into.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be valid
 *    and \p num_events_in_wait_list must be greater than \c 0.  The events
 *    specified in \p event_wait_list act as synchronization points. The
 *    context associated with events in \p event_wait_list and \p command_queue
 *    must be the same. The memory associated with \p event_wait_list can be
 *    reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueReadBufferRect() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueReadBufferRect() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueReadBufferRect() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueReadBufferRect() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueReadBufferRect() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueReadBufferRect() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueReadBufferRect() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueReadBufferRect.html">clEnqueueReadBufferRect()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_read_buffer_rect) void CLXX_B5D_API_CALL
enqueue_read_buffer_rect(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_read_buffer_rect);
#endif
#if CLXX_B5D_PROVIDES(enqueue_read_image)
/** // doc: enqueue_read_image() {{{
 * \brief Enqueue commands to read from an image or image array object to host memory.
 *
 * This is a wrapper for \c clEnqueueReadImage(). The call to
 * #enqueue_read_image() has same effect as a call to
 *    - \c clEnqueueReadImage(command_queue, image, blocking_read, origin, region, row_pitch, slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_read_image() and \c clEnqueueReadImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 *
 * \param command_queue
 *    Refers to the host command-queue in which the read command will be
 *    queued. \p command_queue and \p image must be created with the same
 *    OpenCL context.
 * \param image
 *    Refers to a valid image or image array object.
 * \param blocking_read
 *    Indicates if the read operations are blocking or non-blocking.
 *    If \p blocking_read is \c CL_TRUE i.e. the read command is blocking,
 *    #enqueue_read_image() does not return until the buffer data has been read
 *    and copied into memory pointed to by \p ptr.
 *    If \p blocking_read is \c CL_FALSE i.e. map operation is non-blocking,
 *    #enqueue_read_image() queues a non-blocking read command and returns. The
 *    contents of the buffer that \p ptr points to cannot be used until the
 *    read command has completed. The \p event argument returns an event object
 *    which can be used to query the execution status of the read command. When
 *    the read command has completed, the contents of the buffer that \p ptr
 *    points to can be used by the application
 * \param origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D, or 3D image, the
 *    (x, y) offset and the image index in the \p image array or the (x) offset
 *    and the image index in the 1D \p image array. If \p image is a 2D image
 *    object, \p origin[2] must be 0. If \p image is a 1D image or 1D image
 *    buffer object, \p origin[1] and \p origin[2] must be 0. If \p image is a
 *    1D image array object, \p origin[2] must be 0. If image is a 1D image
 *    array object, \p origin[1] describes the image index in the 1D image
 *    array. If \p image is a 2D image array object, \p origin[2] describes the
 *    image index in the 2D image array
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p image is a
 *    2D image object, \p region[2] must be 1. If \p image is a 1D image or 1D
 *    image buffer object, \p region[1] and \p region[2] must be 1. If \p image
 *    is a 1D image array object, \p region[2] must be 1. The values in region
 *    cannot be 0.
 * \param row_pitch
 *    The length of each row in bytes. This value must be greater than or equal
 *    to the element size in bytes * width. If \p row_pitch is set to 0, the
 *    appropriate row pitch is calculated based on the size of each element in
 *    bytes multiplied by width.
 * \param slice_pitch
 *    Size in bytes of the 2D slice of the 3D region of a 3D image or each
 *    image of a 1D or 2D image array being read. This must be 0 if \p image is
 *    a 1D or 2D image. Otherwise this value must be greater than or equal to
 *    \p row_pitch * \c height. If \p slice_pitch is set to 0, the appropriate
 *    slice pitch is calculated based on the \p row_pitch * \c height.
 * \param ptr
 *    The pointer to a buffer in host memory where image data is to be read
 *    from.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular read command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueReadImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueReadImage() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueReadImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueReadImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueReadImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueReadImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueReadImage() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueReadImage.html">clEnqueueReadImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_read_image) void CLXX_B5D_API_CALL
enqueue_read_image(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_read,
    const size_t* origin,
    const size_t* region,
    size_t row_pitch,
    size_t slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_read_image);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_free)
/** // doc: enqueue_svm_free() {{{
 * \brief Enqueues a command to free the shared virtual memory allocated using
 *        #svm_alloc() or a shared system memory pointer
 *
 * This is a wrapper for \c clEnqueueSVMFree(). The call to
 * #enqueue_svm_free() has same effect as a call to
 *    - \c clEnqueueSVMFree(command_queue, num_svm_pointers, svm_pointers, pfn_free_func, user_data, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_free() and \c clEnqueueSVMFree()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue.
 * \param num_svm_pointers
 *    Number of elements in \p svm_pointers array.
 * \param svm_pointers
 *    Specifiy shared virtual memory pointers to be freed. Each pointer in
 *    \p svm_pointers that was allocated using #svm_alloc() must have been
 *    allocated from the same context from which \p command_queue was created.
 *    The memory associated with \p svm_pointers can be reused or freed after
 *    the function returns.
 * \param pfn_free_func
 *    Specifies the callback function to be called to free the SVM pointers.
 *    \p pfn_free_func takes four arguments: \p queue which is the command
 *    queue in which #enqueue_svm_free() was enqueued, the count and list of
 *    SVM pointers to free and \p user_data which is a pointer to user
 *    specified data. If \p pfn_free_func is \c NULL, all pointers specified in
 *    \p svm_pointers must be allocated using #svm_alloc() (or \c clSVMAlloc)
 *    and the OpenCL implementation will free these SVM pointers.
 *    \p pfn_free_func must be a valid callback function if any SVM pointer to
 *    be freed is a shared system memory pointer i.e. not allocated using
 *    #svm_alloc (\c clSVMAlloc). If \p pfn_free_func is a valid callback
 *    function, the OpenCL implementation will call \p pfn_free_func to free
 *    all the SVM pointers specified in \p svm_pointers.
 * \param user_data
 *    Will be passed as the \p user_data argument when \p pfn_free_func is
 *    called. \p user_data can be \c NULL.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before #enqueue_svm_free() can be
 *    executed. If \p event_wait_list is \c NULL, then #enqueue_svm_free() does
 *    not wait on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events *    specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMFree() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMFree() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMFree() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMFree() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMFree() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMFree() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMFree.html">clEnqueueSVMFree()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_free) void CLXX_B5D_API_CALL
enqueue_svm_free(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue,
                                      cl_uint num_svm_pointers,
                                      void *svm_pointers[],
                                      void *user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_free);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_map)
/** // doc: enqueue_svm_map() {{{
 * \brief Enqueues a command that will allow the host to update a region of a
 *        SVM buffer
 *
 * This is a wrapper for \c clEnqueueSVMMap(). The call to
 * #enqueue_svm_map() has same effect as a call to
 *    - \c clEnqueueSVMMap(command_queue, blocking_map, static_cast<cl_map_flags>(map_flags), svm_ptr, size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_map() and \c clEnqueueSVMMap()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes
 * and uses enums instead of OpenCL constants.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param blocking_map
 *    Indicates if the map operation is blocking or non-blocking.
 *
 *    If \p blocking_map is \c CL_TRUE, #enqueue_svm_map() does not return
 *    until the application can access the contents of the SVM region specified
 *    by \p svm_ptr and size on the host.
 *
 *    If \p blocking_map is \c CL_FALSE i.e. map operation is non-blocking, the
 *    region specified by \p svm_ptr and \p size cannot be used until the map
 *    command has completed. The event argument returns an event object which
 *    can be used to query the execution status of the map command. When the
 *    map command is completed, the application can access the contents of the
 *    region specified by \p svm_ptr and \p size.
 * \param map_flags
 *    A bitfield with the values defined in the documentation of #map_flags_t.
 * \param svm_ptr
 *    A pointer to a memory region that will be updated by the host. If
 *    \p svm_ptr is allocated using #svm_alloc (\c clSVMAlloc) then it must be
 *    allocated from the same context from which \p command_queue was created.
 *    Otherwise the behavior is undefined.
 * \param size
 *    Size in bytes of the memory region pointed to by \p svm_ptr that will be
 *    updated by the host.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \p event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. #enqueue_barrier_with_wait_list() can be used
 *    instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMMap() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueSVMMap() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMMap() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMMap() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueSVMMap() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMMap() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMMap() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMMap() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMMap.html">clEnqueueSVMMap()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_map) void CLXX_B5D_API_CALL
enqueue_svm_map(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    map_flags_t map_flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_map);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_mem_fill)
/** // doc: enqueue_svm_mem_fill() {{{
 * \brief Enqueues a command to fill a region in memory with a pattern of a
 *        given pattern size
 *
 * This is a wrapper for \c clEnqueueSVMMemFill(). The call to
 * #enqueue_svm_mem_fill() has same effect as a call to
 *    - \c clEnqueueSVMMemFill(command_queue, svm_ptr, pattern, pattern_size, size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_mem_fill() and \c clEnqueueSVMMemFill()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Refers to the host command-queue in which the fill command will be
 *    queued. The OpenCL context associated with \p command_queue and SVM
 *    pointer referred to by \p svm_ptr must be the same.
 * \param svm_ptr
 *    A pointer to a memory region that will be filled with \p pattern. It must
 *    be aligned to \p pattern_size bytes. If \p svm_ptr is allocated using
 *    #svm_alloc (\c clSVMAlloc) then it must be allocated from the same
 *    context from which \p command_queue was created. Otherwise the behavior
 *    is undefined.
 * \param pattern
 *    A pointer to the data pattern of size \p pattern_size in bytes.
 *    \p pattern will be used to fill a region in buffer starting at \p svm_ptr
 *    and is \p size bytes in size. The data pattern must be a scalar or vector
 *    integer or floating-point data type. For example, if region pointed to by
 *    \p svm_ptr is to be filled with a pattern of \c float4 values, then
 *    pattern will be a pointer to a \c cl_float4 value and \p pattern_size
 *    will be \c sizeof(cl_float4). The maximum value of \p pattern_size is the
 *    size of the largest integer or floating-point vector data type supported
 *    by the OpenCL device. The memory associated with \p pattern can be reused
 *    or freed after the function returns.
 * \param pattern_size
 *    Size in bytes of the data pointed to by \p pattern.
 * \param size
 *    The size in bytes of region being filled starting with \p svm_ptr and
 *    must be a multiple of \p pattern_size.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \p event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \p event_wait_list is
 *    \c NULL, \p num_events_in_wait_list must be \c 0. If \p event_wait_list
 *    is not \c NULL, the list of events pointed to by \p event_wait_list must
 *    be valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. #enqueue_barrier_with_wait_list() can be used
 *    instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMMemFill() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueSVMMemFill() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMMemFill() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMMemFill() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMMemFill() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMMemFill() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMMemFill() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMMemFill.html">clEnqueueSVMMemFill()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_mem_fill) void CLXX_B5D_API_CALL
enqueue_svm_mem_fill(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_mem_fill);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_memcpy)
/** // doc: enqueue_svm_memcpy() {{{
 * \brief Enqueues a command to do a memcpy operation
 *
 * This is a wrapper for \c clEnqueueSVMMemcpy(). The call to
 * #enqueue_svm_memcpy() has same effect as a call to
 *    - \c clEnqueueSVMMemcpy(command_queue, blocking_copy, dst_ptr, src_ptr, size, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_memcpy() and \c clEnqueueSVMMemcpy()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Refers to the host command-queue in which the read / write command will
 *    be queued. If either \p dst_ptr or \p src_ptr is allocated using
 *    #svm_alloc (\c clSVMAlloc) then the OpenCL context allocated against must
 *    match that of \p command_queue.
 * \param blocking_copy
 *    Indicates if the copy operation is blocking or non-blocking.
 *
 *    If \p blocking_copy is \c CL_TRUE i.e. the copy command is blocking,
 *    #enqueue_svm_memcpy (\c clEnqueueSVMMemcpy) does not return until the
 *    buffer data has been copied into memory pointed to by \p dst_ptr.
 *
 *    If \p blocking_copy is \c CL_FALSE i.e. the copy command is non-blocking,
 *    #enqueue_svm_memcpy (\c clEnqueueSVMMemcpy) queues a non-blocking copy
 *    command and returns. The contents of the buffer that \p dst_ptr point to
 *    cannot be used until the copy command has completed. The event argument
 *    returns an event object which can be used to query the execution status
 *    of the read command. When the copy command has completed, the contents of
 *    the buffer that \p dst_ptr points to can be used by the application.
 * \param dst_ptr
 *    The pointer to a host or SVM memory allocation where data is copied to.
 * \param src_ptr
 *     The pointer to a memory region where data is copied from.
 *
 *     If the memory allocation(s) containing \p dst_ptr and/or \p src_ptr are
 *     allocated using #svm_alloc (\c clSVMAlloc) and either is not allocated
 *     from the same context from which command_queue was created the behavior
 *     is undefined.
 * \param size
 *    The size in bytes of data being copied.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \p event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \p event_wait_list is
 *    \c NULL, \p num_events_in_wait_list must be \c 0. If \p event_wait_list
 *    is not \c NULL, the list of events pointed to by \p event_wait_list must
 *    be valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. #enqueue_barrier_with_wait_list() can be used
 *    instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueSVMMap() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_copy_overlap>
 *    When \c clEnqueueSVMMap() returns \c CL_MEM_COPY_OVERLAP.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMMemcpy() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMMemcpy() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMMemcpy.html">clEnqueueSVMMemcpy()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_memcpy) void CLXX_B5D_API_CALL
enqueue_svm_memcpy(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_memcpy);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_migrate_mem)
/** // doc: enqueue_svm_migrate_mem() {{{
 * \brief Enqueues a command to do a migrate_mem operation
 *
 * This is a wrapper for \c clEnqueueSVMMigrateMem(). The call to
 * #enqueue_svm_migrate_mem() has same effect as a call to
 *    - \c clEnqueueSVMMigrateMem(command_queue, num_svm_pointers, svm_pointers, sizes, static_cast<cl_mem_migration_flags>(flags), num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_migrate_mem() and \c clEnqueueSVMMigrateMem()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command queue. The specified set of allocation ranges will
 *    be migrated to the OpenCL device associated with \p command_queue.
 * \param num_svm_pointers
 *    The number of pointers in the specified \p svm_pointers array, and the
 *    number of sizes in the sizes array, if sizes is not \c NULL.
 * \param svm_pointers
 *    A pointer to an array of pointers. Each pointer in this array must be
 *    within an allocation produced by a call to #svm_alloc (\c clSVMAlloc).
 * \param sizes
 *    An array of sizes. The pair \p svm_pointers[i] and \p sizes[i] together
 *    define the starting address and number of bytes in a range to be
 *    migrated. \p sizes may be NULL indicating that every allocation
 *    containing any \p svm_pointer[i] is to be migrated. Also, if \p sizes[i]
 *    is zero, then the entire allocation containing \p svm_pointer[i] is
 *    migrated.
 * \param flags
 *    A bit-field that is used to specify migration options. See documentation
 *    of #mem_migration_flags_t for possible values.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \p event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \p event_wait_list is
 *    \c NULL, \p num_events_in_wait_list must be \c 0. If \p event_wait_list
 *    is not \c NULL, the list of events pointed to by \p event_wait_list must
 *    be valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. #enqueue_barrier_with_wait_list() can be used
 *    instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMMigrateMem() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMMigrateMem() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMMigrateMem.html">clEnqueueSVMMigrateMem()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_migrate_mem) void CLXX_B5D_API_CALL
enqueue_svm_migrate_mem(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void **svm_pointers,
    const size_t *sizes,
    mem_migration_flags_t flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_migrate_mem);
#endif
#if CLXX_B5D_PROVIDES(enqueue_svm_unmap)
/** // doc: enqueue_svm_unmap() {{{
 * \brief Enqueues a command to indicate that the host has completed updating
 *        the region given by \p svm_ptr and which was specified in a previous
 *        call to #enqueue_svm_map (\c clEnqueueSVMMap)
 *
 * This is a wrapper for \c clEnqueueSVMUnmap(). The call to
 * #enqueue_svm_unmap() has same effect as a call to
 *    - \c clEnqueueSVMUnmap(command_queue, svm_ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_svm_unmap() and \c clEnqueueSVMUnmap()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes
 * and uses enums instead of OpenCL constants.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param svm_ptr
 *    A pointer that was specified in a previous call to #enqueue_svm_map
 *    (\c clEnqueueSVMMap). If \p svm_ptr is allocated using #svm_alloc
 *    (\c clSVMAlloc) then it must be allocated from the same context from
 *    which \p command_queue was created. Otherwise the behavior is undefined.
 * \param num_events_in_wait_list
 *    Number of elements in \p event_wait_list.
 * \param event_wait_list
 *    Specify events that need to complete before this particular command can
 *    be executed. If \p event_wait_list is \c NULL, then this particular
 *    command does not wait on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization
 *    points. The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular command and can
 *    be used to query or queue a wait for this particular command to complete.
 *    \p event can be \c NULL in which case it will not be possible for the
 *    application to query the status of this command or queue a wait for this
 *    command to complete. #enqueue_barrier_with_wait_list() can be used
 *    instead. If the \p event_wait_list and the \p event arguments
 *    are not \c NULL, the event argument should not refer to an element of the
 *    \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueSVMUnmap() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueSVMUnmap() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueSVMUnmap() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueSVMUnmap() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueSVMUnmap() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueSVMUnmap() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueSVMUnmap() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueSVMUnmap.html">clEnqueueSVMUnmap()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_svm_unmap) void CLXX_B5D_API_CALL
enqueue_svm_unmap(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_svm_unmap);
#endif
#if CLXX_B5D_PROVIDES(enqueue_task)
/** // doc: enqueue_task() {{{
 * \brief Enqueues a command to execute a kernel on a device.
 *
 * This is a wrapper for \c clEnqueueTask(). The call to
 * #enqueue_task() has same effect as a call to
 *    - \c clEnqueueTask(command_queue, kernel, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_task() and \c clEnqueueTask()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 *
 * \param command_queue
 *    A valid command-queue. The kernel will be queued for execution on the
 *    device associated with \p command_queue.
 * \param image
 *    A valid kernel object. The OpenCL context associated with \p kernel and
 *    \p command_queue must be the same.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and num_\p events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization points.
 *    The context associated with events in \p event_wait_list and
 *    \p command_queue must be the same. The memory associated with
 *    \p event_wait_list can be reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular kernel execution
 *    instance. Event objects are unique and can be used to identify a
 *    particular kernel execution instance later on. If \p event is \c NULL, no
 *    event will be created for this kernel execution instance and therefore it
 *    will not be possible for the application to query or queue a wait for
 *    this particular kernel execution instance.
 *
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clEnqueueTask() returns \c CL_INVALID_PROGRAM_EXECUTABLE.
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueTask() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clEnqueueTask() returns \c CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueTask() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_kernel_args>
 *    When \c clEnqueueTask() returns \c CL_INVALID_KERNEL_ARGS.
 * \throw clerror_no<status_t::invalid_work_group_size>
 *    When \c clEnqueueTask() returns \c CL_INVALID_WORK_GROUP_SIZE.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueTask() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueTask() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::invalid_image_format_descriptor>
 *    When \c clEnqueueTask() returns \c CL_INVALID_IMAGE_FORMAT_DESCRIPTOR.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueTask() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueTask() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueTask() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueTask() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueTask() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.2/docs/man/xhtml/clEnqueueTask.html">clEnqueueTask()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_task) void CLXX_B5D_API_CALL
enqueue_task(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_task);
#endif
#if CLXX_B5D_PROVIDES(enqueue_unmap_mem_object)
/** // doc: enqueue_unmap_mem_object() {{{
 * \brief Enqueues a command to unmap a previously mapped region of a memory object
 *
 * This is a wrapper for \c clEnqueueUnmapMemObject(). The call to
 * #enqueue_unmap_mem_object() has same effect as a call to
 *    - \c clEnqueueUnmapMemObject(command_queue, memobj, mapped_ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_unmap_mem_object() and \c clEnqueueUnmapMemObject()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Must be a valid host command-queue.
 * \param memobj
 *    A valid memory (buffer or image) object. The OpenCL context associated
 *    with \p command_queue and \p memobj must be the same.
 * \param mapped_ptr
 *    The host address returned by a previous call to #enqueue_map_buffer() or
 *    #enqueue_map_image() for \p memobj.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular unmap command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueUnmapMemObject() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueUnmapMemObject() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueUnmapMemObject.html">clEnqueueUnmapMemObject()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_unmap_mem_object) void CLXX_B5D_API_CALL
enqueue_unmap_mem_object(
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_unmap_mem_object);
#endif
#if CLXX_B5D_PROVIDES(enqueue_wait_for_events)
/** // doc: enqueue_wait_for_events() {{{
 * \brief Enqueues a wait for a specific event or a list of events to complete
 *        before any future commands queued in the command-queue are executed.
 *
 * This is a wrapper for \c clEnqueueWaitForEvents(). The call to
 * #enqueue_wait_for_events() has same effect as a call to
 *    - \c clEnqueueWaitForEvents(command_queue, num_events, event_list)
 *
 * The main difference between #enqueue_wait_for_events() and \c clEnqueueWaitForEvents()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    A valid host command-queue.
 * \param num_events
 *    Specifies the number of events givent by \p event_list.
 * \param event_list
 *    Events specified in \p event_list act as synchronization points. The
 *    context associated with events in \p event_list and \p command_queue must
 *    be the same. Each event in \p event_list must be a valid event object
 *    returned by a previous call to on of the following functions:
 *
 *    - #enqueue_ndrange_kernel(),
 *    - #enqueue_task(),
 *    - #enqueue_native_kernel(),
 *    - #enqueue_read_image(),
 *    - #enqueue_write_image(),
 *    - #enqueue_map_image(),
 *    - #enqueue_read_buffer(),
 *    - #enqueue_write_buffer(),
 *    - #enqueue_map_buffer(),
 *    - #enqueue_unmap_mem_object(),
 *    - #enqueue_read_buffer_rect(),
 *    - #enqueue_write_buffer_rect(),
 *    - #enqueue_copy_buffer(),
 *    - #enqueue_copy_image(),
 *    - #enqueue_copy_buffer_rect(),
 *    - #enqueue_copy_buffer_to_image(),
 *    - #enqueue_copy_image_to_buffer(),
 *    - #enqueue_marker().
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueWaitForEvents() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueWaitForEvents() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueWaitForEvents() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clEnqueueWaitForEvents() returns \c CL_INVALID_EVENT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueWaitForEvents() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueWaitForEvents() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueWaitForEvents() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clEnqueueWaitForEvents.html">clEnqueueWaitForEvents()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_wait_for_events) void CLXX_B5D_API_CALL
enqueue_wait_for_events(
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list
) CLXX_B5D_API_SUFFIX(enqueue_wait_for_events);
#endif
#if CLXX_B5D_PROVIDES(enqueue_write_buffer)
/** // doc: enqueue_write_buffer() {{{
 * \brief Enqueue commands to write to a buffer object from host memory
 *
 * This is a wrapper for \c clEnqueueWriteBuffer(). The call to
 * #enqueue_write_buffer() has same effect as a call to
 *    - \c clEnqueueWriteBuffer(command_queue, buffer, blocking_write, offset, size, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_write_buffer() and \c clEnqueueWriteBuffer()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Is a valid host command-queue in which the write command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    context.
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 *    If \p blocking_write is \c CL_TRUE, the OpenCL implementation copies the
 *    data referred to by \p ptr and enqueues the write operation in the
 *    command-queue. The memory pointed to by \p ptr can be reused by the
 *    application after the #enqueue_write_buffer() call returns.
 *    If \p blocking_write is \c CL_FALSE, the OpenCL implementation will use
 *    \p ptr to perform a nonblocking write. As the write is non-blocking the
 *    implementation can return immediately. The memory pointed to by ptr
 *    cannot be reused by the application after the call returns. The event
 *    argument returns an \p event object which can be used to query the
 *    execution status of the write command. When the write command has
 *    completed, the memory pointed to by \p ptr can then be reused by the
 *    application.
 * \param offset
 *    The offset in bytes in the buffer object to write to.
 * \param size
 *    The size in bytes of data being written.
 * \param ptr
 *    The pointer to buffer in host memory where data is to be write from.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueWriteBuffer() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueWriteBuffer() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueWriteBuffer() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueWriteBuffer() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueWriteBuffer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueWriteBuffer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueWriteBuffer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueWriteBuffer.html">clEnqueueWriteBuffer()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_write_buffer) void CLXX_B5D_API_CALL
enqueue_write_buffer(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_write_buffer);
#endif
#if CLXX_B5D_PROVIDES(enqueue_write_buffer_rect)
/** // doc: enqueue_write_buffer_rect() {{{
 * \brief Enqueue command to write a 2D or 3D rectangular region to a buffer
 *        object from host memory.
 *
 * This is a wrapper for \c clEnqueueWriteBufferRect(). The call to
 * #enqueue_write_buffer_rect() has same effect as a call to
 *    - \c clEnqueueWriteBufferRect(command_queue, buffer, blocking_write, buffer_origin, host_origin, region, buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_write_buffer_rect() and \c clEnqueueWriteBufferRect()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    Is a valid host command-queue in which the write command will be queued.
 *    \p command_queue and \p buffer must be created with the same OpenCL
 *    context.
 * \param buffer
 *    Refers to a valid buffer object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 *    If \p blocking_write is \c CL_TRUE, the OpenCL implementation copies the
 *    data referred to by \p ptr and enqueues the write operation in the
 *    command-queue. The memory pointed to by \p ptr can be reused by the
 *    application after the #enqueue_write_buffer_rect() call returns.
 *    If \p blocking_write is \c CL_FALSE, the OpenCL implementation will use
 *    \p ptr to perform a nonblocking write. As the write is non-blocking the
 *    implementation can return immediately. The memory pointed to by ptr
 *    cannot be reused by the application after the call returns. The event
 *    argument returns an \p event object which can be used to query the
 *    execution status of the write command. When the write command has
 *    completed, the memory pointed to by \p ptr can then be reused by the
 *    application.
 * \param buffer_origin
 *    The (x, y, z) offset in the memory region associated with buffer. For a
 *    2D rectangle region, the \c z value given by \p buffer_origin[2] should
 *    be \c 0. The offset in bytes is computed as \p buffer_origin[2] *
 *    \p buffer_slice_pitch + \p buffer_origin[1] * \p buffer_row_pitch +
 *    \p buffer_origin[0].
 * \param host_origin
 *    The (x, y, z) offset in the memory region pointed to by ptr. For a 2D
 *    rectangle region, the z value given by \p host_origin[2] should be \c 0.
 *    The offset in bytes is computed as \p host_origin[2] *
 *    \p host_slice_pitch + \p host_origin[1] * \p host_row_pitch +
 *    \p host_origin[0].
 * \param region
 *    The (width in bytes, height in rows, depth in slices) of the 2D or 3D
 *    rectangle being read or written. For a 2D rectangle copy, the depth value
 *    given by \p region[2] should be \c 1. The values in region cannot be
 *    \c 0.
 * \param buffer_row_pitch
 *    The length of each row in bytes to be used for the memory region
 *    associated with buffer. If \p buffer_row_pitch is \c 0,
 *    \p buffer_row_pitch is computed as \p region[0].
 * \param buffer_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    associated with buffer. If \p buffer_slice_pitch is \c 0,
 *    \p buffer_slice_pitch is computed as \p region[1] * \p buffer_row_pitch.
 * \param host_row_pitch
 *    The length of each row in bytes to be used for the memory region pointed
 *    to by \p ptr. If \p host_row_pitch is \c 0, \p host_row_pitch is computed
 *    as \p region[0].
 * \param host_slice_pitch
 *    The length of each 2D slice in bytes to be used for the memory region
 *    pointed to by \p ptr. If \p host_slice_pitch is \c 0, \p host_slice_pitch
 *    is computed as \p region[1] * \p host_row_pitch.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. If \p event_wait_list is \c NULL,
 *    \p num_events_in_wait_list must be \c 0. If \p event_wait_list is not
 *    \c NULL, the list of events pointed to by \p event_wait_list must be
 *    valid and \p num_events_in_wait_list must be greater than \c 0. The
 *    events specified in \p event_wait_list act as synchronization points. The
 *    context associated with events in \p event_wait_list and \p command_queue
 *    must be the same. The memory associated with \p event_wait_list can be
 *    reused or freed after the function returns.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array.
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::misaligned_sub_buffer_offset>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_MISALIGNED_SUB_BUFFER_OFFSET.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueWriteBufferRect() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueWriteBufferRect() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clEnqueueWriteBufferRect.html">clEnqueueWriteBufferRect()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_write_buffer_rect) void CLXX_B5D_API_CALL
enqueue_write_buffer_rect(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_write_buffer_rect);
#endif
#if CLXX_B5D_PROVIDES(enqueue_write_image)
/** // doc: enqueue_write_image() {{{
 * \brief Enqueue commands to write to an image or image array object from host memory.
 *
 * This is a wrapper for \c clEnqueueWriteImage(). The call to
 * #enqueue_write_image() has same effect as a call to
 *    - \c clEnqueueWriteImage(command_queue, image, blocking_write, origin, region, input_row_pitch, input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event)
 *
 * The main difference between #enqueue_write_image() and \c clEnqueueWriteImage()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 *
 * \param command_queue
 *    Refers to the host command-queue in which the write command will be
 *    queued. \p command_queue and \p image must be created with the same
 *    OpenCL context.
 * \param image
 *    Refers to a valid image or image array object.
 * \param blocking_write
 *    Indicates if the write operations are blocking or non-blocking.
 *    If \p blocking_write is \c CL_TRUE the OpenCL implementation copies the
 *    data referred to by \p ptr and enqueues the write command in the
 *    command-queue. The memory pointed to by \p ptr can be reused by the
 *    application after the #enqueue_write_image() call returns.
 *    If \p blocking_write is \c CL_FALSE the OpenCL implementation will use
 *    \p ptr to perform a nonblocking write. As the write is non-blocking the
 *    implementation can return immediately. The memory pointed to by \p ptr
 *    cannot be reused by the application after the call returns. The event
 *    argument returns an event object which can be used to query the
 *    execution status of the write command. When the write command has
 *    completed, the memory pointed to by \p ptr can then be reused by the
 *    application.
 * \param origin
 *    Defines the (x, y, z) offset in pixels in the 1D, 2D, or 3D image, the
 *    (x, y) offset and the image index in the \p image array or the (x) offset
 *    and the image index in the 1D \p image array. If \p image is a 2D image
 *    object, \p origin[2] must be 0. If \p image is a 1D image or 1D image
 *    buffer object, \p origin[1] and \p origin[2] must be 0. If \p image is a
 *    1D image array object, \p origin[2] must be 0. If image is a 1D image
 *    array object, \p origin[1] describes the image index in the 1D image
 *    array. If \p image is a 2D image array object, \p origin[2] describes the
 *    image index in the 2D image array
 * \param region
 *    Defines the (width, height, depth) in pixels of the 1D, 2D or 3D
 *    rectangle, the (width, height) in pixels of the 2D rectangle and the
 *    number of images of a 2D image array or the (width) in pixels of the 1D
 *    rectangle and the number of images of a 1D image array. If \p image is a
 *    2D image object, \p region[2] must be 1. If \p image is a 1D image or 1D
 *    image buffer object, \p region[1] and \p region[2] must be 1. If \p image
 *    is a 1D image array object, \p region[2] must be 1. The values in region
 *    cannot be 0.
 * \param input_row_pitch
 *    The length of each row in bytes. This value must be greater than or equal
 *    to the element size in bytes * width. If \p input_row_pitch is set to 0, the
 *    appropriate row pitch is calculated based on the size of each element in
 *    bytes multiplied by width.
 * \param input_slice_pitch
 *    Size in bytes of the 2D slice of the 3D region of a 3D image or each
 *    image of a 1D or 2D image array being write. This must be 0 if \p image is
 *    a 1D or 2D image. Otherwise this value must be greater than or equal to
 *    \p input_row_pitch * \c height. If \p input_slice_pitch is set to 0, the appropriate
 *    slice pitch is calculated based on the \p input_row_pitch * \c height.
 * \param ptr
 *    The pointer to a buffer in host memory where image data is to be write
 *    from.
 * \param num_events_in_wait_list
 *    Number of events in the \p event_wait_list.
 *    If \p event_wait_list is \c NULL, \p num_events_in_wait_list must be 0.
 *    If \p event_wait_list is not \c NULL, the list of events pointed to by
 *    \p event_wait_list must be valid and \p num_events_in_wait_list must be
 *    greater than \c 0.
 * \param event_wait_list
 *    \p event_wait_list and \p num_events_in_wait_list specify events that
 *    need to complete before this particular command can be executed. If
 *    \p event_wait_list is \c NULL, then this particular command does not wait
 *    on any event to complete. The events specified in \p event_wait_list act
 *    as synchronization points. The context associated with events in
 *    \p event_wait_list and \p command_queue must be the same. The memory
 *    associated with \p event_wait_list can be reused or freed after the
 *    function returns.
 * \param event
 *    Returns an event object that identifies this particular write command and
 *    can be used to query or queue a wait for this particular command to
 *    complete.\p event can be \c NULL in which case it will not be possible
 *    for the application to query the status of this command or queue a wait
 *    for this command to complete. If the \p event_wait_list and the \p event
 *    arguments are not \c NULL, the event argument should not refer to an
 *    element of the \p event_wait_list array
 *
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_event_wait_list>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_EVENT_WAIT_LIST.
 * \throw clerror_no<status_t::invalid_image_size>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_IMAGE_SIZE.
 * \throw clerror_no<status_t::image_format_not_supported>
 *    When \c clEnqueueWriteImage() returns \c CL_IMAGE_FORMAT_NOT_SUPPORTED.
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clEnqueueWriteImage() returns \c CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST.
 * \throw clerror_no<status_t::mem_object_allocation_failure>
 *    When \c clEnqueueWriteImage() returns \c CL_MEM_OBJECT_ALLOCATION_FAILURE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clEnqueueWriteImage() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clEnqueueWriteImage() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clEnqueueWriteImage() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clEnqueueWriteImage() returns other error code.
 *
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clEnqueueWriteImage.html">clEnqueueWriteImage()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(enqueue_write_image) void CLXX_B5D_API_CALL
enqueue_write_image(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_write,
    const size_t* origin,
    const size_t* region,
    size_t input_row_pitch,
    size_t input_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event
) CLXX_B5D_API_SUFFIX(enqueue_write_image);
#endif
#if CLXX_B5D_PROVIDES(finish)
/** // doc: finish() {{{
 * \brief Blocks until all previously queued OpenCL commands in a command-queue
 *        are issued to the associated device and have completed
 *
 * This function is a wrapper around \c clFinish(). The call to this function
 * has same effect as
 * - \c clFinish(command_queue)
 *
 * The main difference between #finish() and \c clFinish() is that it throws
 * %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    The command queue whose commands are to be finished.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clFinish() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clFinish() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clFinish() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clFinish() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clFinish.html">clFinish()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(finish) void CLXX_B5D_API_CALL
finish(
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(finish);
#endif
#if CLXX_B5D_PROVIDES(flush)
/** // doc: flush() {{{
 * \brief Issues all previously queued OpenCL commands in a command-queue to
 *        the device associated with the command-queue
 *
 * This function is a wrapper around \c clFlush(). The call to this function
 * has same effect as
 * - \c clFlush(command_queue)
 *
 * The main difference between #flush() and \c clFlush() is that it throws
 * %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param command_queue
 *    The command queue whose commands are to be issued.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clFlush() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clFlush() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clFlush() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clFlush() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clFlush.html">clFlush()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(flush) void CLXX_B5D_API_CALL
flush(
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(flush);
#endif
#if CLXX_B5D_PROVIDES(get_command_queue_info)
/** // doc: get_command_queue_info(...) {{{
 * \brief Query information about a command-queue.
 *
 * This is a wrapper for \c clGetCommandQueueInfo(). The call to \ref
 * get_command_queue_info() has same effect as a call to
 *    - \c clGetCommandQueueInfo(command_queue,static_cast<cl_command_queue_info>(param_name),param_value_size,param_value,param_value_size_ret)
 *
 *  The main difference between get_command_queue_info() and
 *  \c clGetCommandQueueInfo() is that it throws %clxx exceptions instead of
 *  returning OpenCL error codes.
 *
 * \param command_queue
 *    Specifies the OpenCl command-queue being queried.
 * \param param_name
 *    An enumeration constant that specifies the information to query. See
 *    \ref command_queue_info_t.
 * \param param_value_size
 *    Specifies the size in bytes of memory pointed to by \p param_value. This
 *    size must be grater than or equal to the size of return type for
 *    \p param_name as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \p param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    \p param_value. If \p param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clGetCommandQueueInfo() returns \c CL_INVALID_COMMAND_QUEUE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetCommandQueueInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetCommandQueueInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetCommandQueueInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetCommandQueueInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetCommandQueueInfo.html">clGetCommandQueueInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_command_queue_info) void CLXX_B5D_API_CALL
get_command_queue_info(
    cl_command_queue command_queue,
    command_queue_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_command_queue_info);
#endif
#if CLXX_B5D_PROVIDES(get_context_info)
/** // doc: get_context_info(...) {{{
 * \brief Query information about a context.
 *
 * This is a wrapper for \c clGetContextInfo(). The call to \ref
 * get_context_info() has same effect as a call to
 *    - \c clGetContextInfo(context,static_cast<cl_context_info>(param_name),param_value_size,param_value,param_value_size_ret)
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
 *    Specifies the size in bytes of memory pointed to by \p param_value. This
 *    size must be grater than or equal to the size of return type for
 *    \p param_name as described in the OpenCL standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. if *param_value* is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by
 *    \p param_value. If \p param_value_size_ret is \c NULL, it is ignored.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetContextInfo.html">clGetContextInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_context_info) void CLXX_B5D_API_CALL
get_context_info(
    cl_context context,
    context_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_context_info);
#endif
#if CLXX_B5D_PROVIDES(get_device_and_host_timer)
/** // doc: get_device_and_host_timer(...) {{{
 * \brief Returns a reasonably synchronized pair of timestamps from the device
 * timer and the host timer as seen by device.
 *
 * This is a wrapper for \c clGetDeviceAndHostTimer(). The call to \ref
 * get_device_and_host_timer() has same effect as a call to
 *    - \c clGetDeviceAndHostTimer(device, device_timestamp, host_timestamp)
 *
 *  The main difference between get_device_and_host_timer() and \c clGetDeviceAndHostTimer() is
 *  that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param device
 *    A device returned by #get_device_ids().
 * \param device_timestamp
 *    Will be updated with the value of the current timer in nanoseconds. The
 *    resolution of the timer is the same as the device profiling timer
 *    returned by #get_device_info() and the #device_info_t::profiling_timer_resolution
 *    query.
 * \param host_timestamp
 *    Will be updated with the value of the current timer in nanoseconds at the
 *    closest possible point in time to that at which device_timer was
 *    returned. The resolution of the timer may be queried via
 *    #get_platform_info() and the flag
 *    #platform_info_t::host_timer_resolution query.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetDeviceAndHostTimer() returns \c CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetDeviceAndHostTimer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetDeviceAndHostTimer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetDeviceAndHostTimer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetDeviceAndHostTimer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clGetDeviceAndHostTimer.html">clGetDeviceAndHostTimer()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_device_and_host_timer) void CLXX_B5D_API_CALL
get_device_and_host_timer(
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp
) CLXX_B5D_API_SUFFIX(get_device_and_host_timer);
#endif
#if CLXX_B5D_PROVIDES(get_device_ids)
/** // doc: get_device_ids() {{{
 * \brief Retrieve device identifiers of locally available OpenCL devices.
 *
 * This function is a C++ wrapper for \c clGetDeviceIDs(). The main difference
 * between clxx::get_device_ids() and \c clGetDeviceIDs() is that it throws
 * exceptions instead of returning error codes.
 *
 * \param platform
 *        Refers to the platform ID returned by clxx::get_platform_ids() or can
 *        be \c NULL. If \p platform is \c NULL, the behavior is
 *        implementation-defined.
 * \param device_type
 *        A bitfield that identifies the type of OpenCL device. The
 *        \p device_type can be used to query specific OpenCL devices or all
 *        OpenCL devices available. The valid values for \p device_type are
 *        specified by clxx::device_type_t.
 * \param num_entries
 *        The number of \c cl_device_id entries that can be added to
 *        \p devices. If \p devices is not \c NULL, the \p num_entries must be
 *        greater than zero.
 * \param devices
 *        A list of OpenCL devices found. The \c cl_device_id values returned
 *        in \p devices can be used to identify a specific OpenCL device. If
 *        \p devices argument is \c NULL, this argument is ignored. The number
 *        of OpenCL devices returned is the minimum of the value specified by
 *        \p num_entries or the number of OpenCL devices whose type matches
 *        \p device_type.
 * \param num_devices
 *        Returns the number of OpenCL devices available. If \c num_devices is
 *        \c NULL, this argument is ignored.
 *
 * \return The number of available OpenCL devices
 *
 * \throw clerror_no<status_t::invalid_platform>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_PLATFORM,
 * \throw clerror_no<status_t::invalid_device_type>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_DEVICE_TYPE,
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetDeviceIDs() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_resources>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_RESOURCES,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetDeviceIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetDeviceIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetDeviceIDs()
 * implementation is not standard conformant, its version is not supported by
 * %clxx, or when get_platform_ids() has a bug.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetDeviceIDs.html">clGetDeviceIDs()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_device_ids) void CLXX_B5D_API_CALL
get_device_ids(
    cl_platform_id platform,
    device_type_t device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices
) CLXX_B5D_API_SUFFIX(get_device_ids);
#endif
#if CLXX_B5D_PROVIDES(get_device_info)
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
 *    Returns the actual size in bytes of data being queried by
 *    \c param_value. If \c param_value_size_ret is \c NULL, it is ignored
 *
 * \throw  clxx::clerror_no<clxx::status_t::invalid_device>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_DEVICE,
 * \throw  clxx::clerror_no<clxx::status_t::invalid_value>
 *    when \c clGetDeviceInfo() returns \c CL_INVALID_VALUE,
 * \throw  clxx::clerror_no<clxx::status_t::out_of_resources>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_RESOURCES,
 * \throw  clxx::clerror_no<clxx::status_t::out_of_host_memory>
 *    when \c clGetDeviceInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw  clxx::unexpected_clerror
 *    when \c clGetDeviceInfo() returns any other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetDeviceInfo.html">clGetDeviceInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_device_info) void CLXX_B5D_API_CALL
get_device_info(
    cl_device_id device,
    device_info_t name,
    size_t value_size,
    void* value,
    size_t* value_size_ret
) CLXX_B5D_API_SUFFIX(get_device_info);
#endif
#if CLXX_B5D_PROVIDES(get_event_info)
/** // doc: get_event_info() {{{
 * \brief Returns information about the event object
 *
 * This function is a wrapper around \c clGetEventInfo(). The call to
 * this function has same effect as
 * - \c clGetEventInfo(event, static_cast<cl_event_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_event_info() and
 * \c clGetEventInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    Specifies the event object being queried.
 * \param param_name
 *    Specifies the information to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetEventInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clGetEventInfo() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetEventInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetEventInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetEventInfo.html">clGetEventInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_event_info) void CLXX_B5D_API_CALL
get_event_info(
    cl_event event,
    event_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_event_info);
#endif
#if CLXX_B5D_PROVIDES(get_event_profiling_info)
/** // doc: get_event_profiling_info() {{{
 * \brief Returns profiling information for the command associated with event
 *        if profiling is enabled
 *
 * This function is a wrapper around \c clGetEventProfilingInfo(). The call to
 * this function has same effect as
 * - \c clGetEventProfilingInfo(event, static_cast<cl_profiling_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_event_profiling_info() and
 * \c clGetEventProfilingInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    Specifies the event object.
 * \param param_name
 *    Specifies the profiling data to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::profiling_info_not_available>
 *    When the \c clGetEventProfilingInfo() returns CL_PROFILING_INFO_NOT_AVAILABLE
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetEventProfilingInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clGetEventProfilingInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetEventProfilingInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetEventProfilingInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetEventProfilingInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetEventProfilingInfo.html">clGetEventProfilingInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_event_profiling_info) void CLXX_B5D_API_CALL
get_event_profiling_info(
    cl_event event,
    profiling_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_event_profiling_info);
#endif
#if CLXX_B5D_PROVIDES(get_extension_function_address)
/** // doc: get_extension_function_address() {{{
 * \brief Returns the address of the extension function named by \p funcname.
 *
 * This function is a wrapper around \c clGetExtensionFunctionAddress(). The call to
 * this function has same effect as
 * - \c clGetExtensionFunctionAddress(funcname)
 *
 * \param funcname
 *    Name of an extension function.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clGetExtensionFunctionAddress.html">clGetExtensionFunctionAddress()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_extension_function_address) void* CLXX_B5D_API_CALL
get_extension_function_address(
    const char* funcname
) CLXX_B5D_API_SUFFIX(get_extension_function_address);
#endif
#if CLXX_B5D_PROVIDES(get_extension_function_address_for_platform)
/** // doc: get_extension_function_address_for_platform() {{{
 * \brief Returns the address of the extension function named by \p funcname
 *        for a given \p platform
 *
 * This function is a wrapper around \c clGetExtensionFunctionAddressForPlatform(). The call to
 * this function has same effect as
 * - \c clGetExtensionFunctionAddressForPlatform(platform, funcname)
 *
 * \param funcname
 *    Name of an extension function.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clGetExtensionFunctionAddressForPlatform.html">clGetExtensionFunctionAddressForPlatform()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_extension_function_address_for_platform) void* CLXX_B5D_API_CALL
get_extension_function_address_for_platform(
    cl_platform_id platform,
    const char* funcname
) CLXX_B5D_API_SUFFIX(get_extension_function_address_for_platform);
#endif
#if CLXX_B5D_PROVIDES(get_host_timer)
/** // doc: get_host_timer(...) {{{
 * \brief Return the current value of the host clock as seen by device.
 *
 * This is a wrapper for \c clGetHostTimer(). The call to \ref
 * get_host_timer() has same effect as a call to
 *    - \c clGetHostTimer(device, host_timestamp)
 *
 *  The main difference between get_host_timer() and \c clGetHostTimer() is
 *  that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param device
 *    A device returned by #get_device_ids().
 * \param host_timestamp
 *    Will be updated with the value of the current timer in nanoseconds.
 *    The resolution of the timer may be queried via
 *    #get_platform_info() and the flag
 *    #platform_info_t::host_timer_resolution query.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetHostTimer() returns \c CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetHostTimer() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetHostTimer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetHostTimer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetHostTimer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clGetHostTimer.html">clGetHostTimer()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_host_timer) void CLXX_B5D_API_CALL
get_host_timer(
    cl_device_id device,
    cl_ulong* host_timestamp
) CLXX_B5D_API_SUFFIX(get_host_timer);
#endif
#if CLXX_B5D_PROVIDES(get_image_info)
/** // doc: get_image_info() {{{
 * \brief Get information specific to an image object created with #create_image()
 *
 * This is a wrapper for \c clGetImageInfo(). The call to
 * #get_image_info() has same effect as a call to
 *    - \c clGetImageInfo(image, static_cast<cl_image_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between #get_image_info() and \c clGetImageInfo()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param image
 *    Specifies the image object being queried.
 * \param param_name
 *    Specifies the information to query. See the documentation of
 *    #image_info_t for the list of predefined names.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \p param_value.
 *    This size must be >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \p param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by \p param_value.
 *    If \p param_value_size_ret is \c NULL, it is ignored
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clGetImageInfo() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetImageInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetImageInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetImageInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetImageInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetImageInfo.html">clGetImageInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_image_info) void CLXX_B5D_API_CALL
get_image_info(
    cl_mem image,
    image_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_image_info);
#endif
#if CLXX_B5D_PROVIDES(get_kernel_arg_info)
/** // doc: get_kernel_arg_info() {{{
 * \brief Returns information about the arguments of a kernel.
 *
 * This function is a wrapper around \c clGetKernelArgInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelArgInfo(kernel, arg_index, static_cast<cl_kernel_arg_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_arg_info() and
 * \c clGetKernelArgInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param param_name
 *    Specifies the argument information to query. The list of supported \em
 *    param_name types and the information returned in \em param_value by
 *    get_kernel_arg_info is described in the OpenCL standard.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be > size of return type as described in the OpenCL
 *    standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::arg_info_not_available>
 *    When \c clGetKernelArgInfo() returns CL_ARG_INFO_NOT_AVAILABLE.
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clGetKernelArgInfo() returns CL_INVALID_KERNEL.
 * \throw unexpected_clerror
 *    When \c clGetKernelArgInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelArgInfo.html">clGetKernelArgInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_kernel_arg_info) void CLXX_B5D_API_CALL
get_kernel_arg_info(
    cl_kernel kernel,
    cl_uint arg_index,
    kernel_arg_info_t param_name,
    size_t param_value_size, void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_kernel_arg_info);
#endif
#if CLXX_B5D_PROVIDES(get_kernel_info)
/** // doc: get_kernel_info() {{{
 * \brief Returns information about the kernel object
 *
 * This function is a wrapper around \c clGetKernelInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelInfo(kernel, static_cast<cl_kernel_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_info() and
 * \c clGetKernelInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param param_name
 *    Specifies the information to query.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    The actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clGetKernelInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_kernel>
 *    When the \c clGetKernelInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clGetKernelInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clGetKernelInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetKernelInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelInfo.html">clGetKernelInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_kernel_info) void CLXX_B5D_API_CALL
get_kernel_info(
    cl_kernel kernel,
    kernel_info_t param_name,
    size_t param_value_size, void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_kernel_info);
#endif
#if CLXX_B5D_PROVIDES(get_kernel_sub_group_info)
/** // doc: get_kernel_sub_group_info() {{{
 * \brief Returns information about the kernel object
 *
 * This function is a wrapper around \c clGetKernelSubGroupInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelSubGroupInfo(kernel, device, static_cast<cl_kernel_sub_group_info>(param_name), input_value_size, input_value, param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_sub_group_info() and
 * \c clGetKernelSubGroupInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param device
 *    Identifies a specific device in the list of devices associated with
 *    \p kernel. The list of devices is the list of devices in the OpenCL
 *    context that is associated with kernel. If the list of devices associated
 *    with kernel is a single device, \p device can be a \c NULL value.
 * \param param_name
 *    Specifies the information to query. The list of supported \p param_name
 *    types is documented in \ref clxx::kernel_sub_group_info_t. The
 *    information returned in \p param_value is described in the OpenCL
 *    standard.
 * \param input_value_size
 *    Specifies the size in bytes of memory pointed to by input_value. This
 *    size must be == size of input type as described in OpenCL documentation
 *    for [clGetKernelSubGroupInfo()](https://www.khronos.org/registry/OpenCL/sdk/2.1/docs/man/xhtml/clGetKernelSubGroupInfo.html)
 * \param input_value
 *    A pointer to memory where the appropriate parameterization of the query
 *    is passed from. If \p input_value is \c NULL, it is ignored.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \p param_value.
 *    This size must be \c >= size of return type as described in the OpenCL
 *    documentation for [clGetKernelSubGroupInfo()](https://www.khronos.org/registry/OpenCL/sdk/2.1/docs/man/xhtml/clGetKernelSubGroupInfo.html).
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \p param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to \p param_value. If
 *    \p param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetKernelSubGroupInfo() returns CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetKernelSubGroupInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clGetKernelSubGroupInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetKernelSubGroupInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetKernelSubGroupInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetKernelSubGroupInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clGetKernelSubGroupInfo.html">clGetKernelSubGroupInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_kernel_sub_group_info) void CLXX_B5D_API_CALL
get_kernel_sub_group_info(
    cl_kernel kernel,
    cl_device_id device,
    kernel_sub_group_info_t param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_kernel_sub_group_info);
#endif
#if CLXX_B5D_PROVIDES(get_kernel_work_group_info)
/** // doc: get_kernel_work_group_info() {{{
 * \brief Returns information about the kernel object that may be specific to a device.
 *
 * This function is a wrapper around \c clGetKernelWorkGroupInfo(). The call to
 * this function has same effect as
 * - \c clGetKernelWorkGroupInfo(kernel, device, static_cast<cl_kernel_work_group_info>(param_name), param_value_size, param_value, param_value_size_ret).
 *
 * The main difference between #get_kernel_work_group_info() and
 * \c clGetKernelWorkGroupInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param device
 *    Identifies a specific device in the list of devices associated with
 *    kernel. The list of devices is the list of devices in the OpenCL context
 *    that is associated with kernel. If the list of devices associated with
 *    kernel is a single device, \em device can be a \c NULL value.
 * \param param_name
 *    Specifies the information to query. The list of supported \em param_name
 *    types is documented in \ref clxx::kernel_work_group_info_t. The
 *    information returned in \em param_value is described in the OpenCL
 *    standard.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \em param_value.
 *    This size must be \c >= size of return type as described in the OpenCL
 *    standard.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \em param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to \em param_value. If
 *    \em param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clGetKernelWorkGroupInfo() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetKernelWorkGroupInfo() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetKernelWorkGroupInfo() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clGetKernelWorkGroupInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetKernelWorkGroupInfo.html">clGetKernelWorkGroupInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_kernel_work_group_info) void CLXX_B5D_API_CALL
get_kernel_work_group_info(
    cl_kernel kernel,
    cl_device_id device,
    kernel_work_group_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_kernel_work_group_info);
#endif
#if CLXX_B5D_PROVIDES(get_mem_object_info)
/** // doc: get_mem_object_info() {{{
 * \brief Get information that is common to all memory objects (buffer and
 *        image objects).
 *
 * This is a wrapper for \c clGetMemObjectInfo(). The call to
 * #get_mem_object_info() has same effect as a call to
 *    - \c clGetMemObjectInfo(memobj, static_cast<cl_mem_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between #get_mem_object_info() and \c clGetMemObjectInfo()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param memobj
 *    Specifies the memory object being queried.
 * \param param_name
 *    Specifies the information to query. See the documentation of
 *    #mem_info_t for the list of predefined names.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \p param_value.
 *    This size must be >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \p param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by \p param_value.
 *    If \p param_value_size_ret is \c NULL, it is ignored
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clGetMemObjectInfo() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetMemObjectInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetMemObjectInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetMemObjectInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetMemObjectInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetMemObjectInfo.html">clGetMemObjectInfo()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_mem_object_info) void CLXX_B5D_API_CALL
get_mem_object_info(
    cl_mem memobj,
    mem_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_mem_object_info);
#endif
#if CLXX_B5D_PROVIDES(get_pipe_info)
/** // doc: get_pipe_info() {{{
 * \brief Get information specific to a pipe object created with #create_pipe
 *
 * This is a wrapper for \c clGetPipeInfo(). The call to
 * #get_pipe_info() has same effect as a call to
 *    - \c clGetPipeInfo(pipe, static_cast<cl_pipe_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between #get_pipe_info() and \c clGetPipeInfo()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param pipe
 *    Specifies the pipe being queried.
 * \param param_name
 *    Specifies the information to query. See the documentation of
 *    #pipe_info_t for the list of predefined names.
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by \p param_value.
 *    This size must be >= size of return type.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If \p param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data being queried by \p param_value.
 *    If \p param_value_size_ret is \c NULL, it is ignored
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clGetPipeInfo() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetPipeInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetPipeInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetPipeInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetPipeInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clGetPipeInfo.html">clGetPipeInfo()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_pipe_info) void CLXX_B5D_API_CALL
get_pipe_info(
    cl_mem pipe,
    pipe_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_pipe_info);
#endif
#if CLXX_B5D_PROVIDES(get_platform_ids)
/** // {{{ doc: get_platform_ids(...)
 * \brief Retrieve platform identifiers of locally available OpenCL platforms.
 *
 * This function is a C++ wrapper for \c clGetPlatformIDs().
 *
 * \param num_entries
 *    The number of \c cl_platform_id entries that can be added to
 *    \p platforms. If \p platforms is not \c NULL, the \p num_entries must be
 *    greater than zero
 * \param platforms
 *    Returns a list of OpenCL platforms found. The \c cl_platform_id values
 *    returned in \p platforms can be used to identify a specific OpenCL
 *    platform. If platforms argument is \c NULL, this argument is ignored. The
 *    number ofOpenCL platforms returned is the mininum of the value specified
 *    by \p num_entries or the number of OpenCL platforms available
 * \param num_platforms
 *    Returns the number of OpenCL platforms available. If \p num_platforms is
 *    \c NULL, this argument is ignored
 * \return void
 *
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformIDs() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformIDs() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetPlatformIDs() returns other error code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformIDs()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_ids() has a bug.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetPlatformIDs.html">clGetPlatformIDs()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_platform_ids) void CLXX_B5D_API_CALL
get_platform_ids(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms
) CLXX_B5D_API_SUFFIX(get_platform_ids);
#endif
#if CLXX_B5D_PROVIDES(get_platform_info)
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
 * \throw clerror_no<status_t::invalid_platform>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_PLATFORM,
 * \throw clerror_no<status_t::invalid_value>
 *         when \c clGetPlatformInfo() returns \c CL_INVALID_VALUE,
 * \throw clerror_no<status_t::out_of_host_memory>
 *         when \c clGetPlatformInfo() returns \c CL_OUT_OF_HOST_MEMORY,
 * \throw unexpected_clerror
 *         when \c clGetPlatformInfo() returns other status code.
 *
 * The unexpected_clerror is thrown only when the \c clGetPlatformInfo()
 * implementation is not standard conformant, its version is not supported by
 * CLXX, or when get_platform_info() has a bug.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetPlatformInfo.html">clGetPlatformInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_platform_info) void CLXX_B5D_API_CALL
get_platform_info(
    cl_platform_id platform,
    platform_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_platform_info);
#endif
#if CLXX_B5D_PROVIDES(get_program_build_info)
/** // doc: get_program_build_info {{{
 * \brief Returns build information for each device in the program object.
 *
 * This function is a wrapper around \c clGetProgramBuildInfo(). The call to this
 * function has same effect as
 *  - \c clGetProgramBuildInfo(program, device, static_cast<cl_program_build_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between \ref get_program_build_info() and
 * \c clGetProgramBuildInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes and accepts \ref clxx::program_build_info_t
 * "program_build_info_t" instead of \c cl_program_build_info as \p param_name.
 *
 * A program binary (compiled binary, library binary or executable binary)
 * built for a parent device can be used by all its sub-devices. If a program
 * binary has not been built for a sub-device, the program binary associated
 * with the parent device will be used.
 *
 * A program binary for a device specified with create_program_with_binary() or
 * queried using get_program_info() can be used as the binary for the
 * associated root device, and all sub-devices created from the root-level
 * device or sub-devices thereof.
 *
 * \param program
 *    Specifies the program object being queried.
 * \param device
 *    Specifies the device for which build information is being queried.
 *    \p device must be a valid device associated with \p program.
 * \param param_name
 *    Specifies the information to query. The list of supported \p param_name
 *    types is documented in \ref clxx::program_build_info_t "program_build_info_t".
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by param_value.
 *    This size must be >= size of return type as described in the table above.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to param_value. If
 *    \p param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clGetProgramBuildInfo() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetProgramBuildInfo() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetProgramBuildInfo() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetProgramBuildInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetProgramBuildInfo.html">clGetProgramBuildInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_program_build_info) void CLXX_B5D_API_CALL
get_program_build_info(
    cl_program program,
    cl_device_id device,
    program_build_info_t param_name,
    size_t param_value_size, void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_program_build_info);
#endif
#if CLXX_B5D_PROVIDES(get_program_info)
/** // doc: get_program_info {{{
 * \brief Returns information about the program object.
 *
 * This function is a wrapper around \c clGetProgramInfo(). The call to this
 * function has same effect as
 *  - \c clGetProgramInfo(program, static_cast<cl_program_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between \ref get_program_info() and
 * \c clGetProgramInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes and accepts \ref clxx::program_info_t
 * "program_info_t" instead of \c cl_program_info as \p param_name.
 *
 * \param program
 *    Specifies the program object being queried.
 * \param param_name
 *    Specifies the information to query. The list of supported \p param_name
 *    types is documented in \ref clxx::program_info_t "program_info_t".
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by param_value.
 *    This size must be >= size of return type as described in the table above.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to param_value. If
 *    \p param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetProgramInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clGetProgramInfo() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_program_executable>
 *    When \c clGetProgramInfo() returns CL_INVALID_PROGRAM_EXECUTABLE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetProgramInfo() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetProgramInfo() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetProgramInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetProgramInfo.html">clGetProgramInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_program_info) void CLXX_B5D_API_CALL
get_program_info(
    cl_program program,
    program_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_program_info);
#endif
#if CLXX_B5D_PROVIDES(get_sampler_info)
/** // doc: get_sampler_info {{{
 * \brief Returns information about the sampler object.
 *
 * This function is a wrapper around \c clGetSamplerInfo(). The call to this
 * function has same effect as
 *  - \c clGetSamplerInfo(sampler, static_cast<cl_sampler_info>(param_name), param_value_size, param_value, param_value_size_ret)
 *
 * The main difference between \ref get_sampler_info() and
 * \c clGetSamplerInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes and accepts \ref clxx::sampler_info_t
 * "sampler_info_t" instead of \c cl_sampler_info as \p param_name.
 *
 * \param sampler
 *    Specifies the sampler object being queried.
 * \param param_name
 *    Specifies the information to query. The list of supported \p param_name
 *    types is documented in \ref clxx::sampler_info_t "sampler_info_t".
 * \param param_value_size
 *    Used to specify the size in bytes of memory pointed to by param_value.
 *    This size must be >= size of return type as described in the table above.
 * \param param_value
 *    A pointer to memory where the appropriate result being queried is
 *    returned. If param_value is \c NULL, it is ignored.
 * \param param_value_size_ret
 *    Returns the actual size in bytes of data copied to param_value. If
 *    \p param_value_size_ret is \c NULL, it is ignored.
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetSamplerInfo() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_sampler>
 *    When \c clGetSamplerInfo() returns CL_INVALID_SAMPLER.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetSamplerInfo() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetSamplerInfo() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetSamplerInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clGetSamplerInfo.html">clGetSamplerInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_sampler_info) void CLXX_B5D_API_CALL
get_sampler_info(
    cl_sampler sampler,
    sampler_info_t param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret
) CLXX_B5D_API_SUFFIX(get_sampler_info);
#endif
#if CLXX_B5D_PROVIDES(get_supported_image_formats)
/** // doc: get_supported_image_formats() {{{
 * \brief Get the list of image formats supported by an OpenCL implementation
 *
 * This is a wrapper for \c clGetSupportedImageFormats(). The call to
 * #get_supported_image_formats() has same effect as a call to
 *    - \c clGetSupportedImageFormats(context, static_cast<cl_mem_flags>(flags), static_cast<cl_mem_object_type>(image_type), num_entries, image_formats, num_image_formats)
 *
 * The main difference between #get_supported_image_formats() and \c clGetSupportedImageFormats()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param context
 *    A valid OpenCL context on which the image object(s) will be created.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information
 *    about the image memory object being queried. See the documentation of
 *    #mem_flags_t for a list of predefined bit values.
 * \param image_type
 *    Describes the image type. See the documentation of #mem_object_type_t
 *    for a list of predefined values.
 * \param num_entries
 *    Specifies the number of entries that can be returned in the memory
 *    location given by \p image_formats.
 * \param image_formats
 *    A pointer to a memory location where the list of supported image formats
 *    are returned. Each entry describes a \c cl_image_format structure
 *    supported by the OpenCL implementation. If \p image_formats is \c NULL,
 *    it is ignored.
 * \param num_image_formats
 *    The actual number of supported image formats for a specific context and
 *    values specified by \p flags. If \p num_image_formats is \c NULL, it is
 *    ignored.
 *
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clGetSupportedImageFormats() returns \c CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clGetSupportedImageFormats() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clGetSupportedImageFormats() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clGetSupportedImageFormats() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clGetSupportedImageFormats() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clGetSupportedImageFormats.html">clGetSupportedImageFormats()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(get_supported_image_formats) void CLXX_B5D_API_CALL
get_supported_image_formats(
    cl_context context,
    mem_flags_t flags,
    mem_object_type_t image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats
) CLXX_B5D_API_SUFFIX(get_supported_image_formats);
#endif
#if CLXX_B5D_PROVIDES(link_program)
/** // doc: link_program(...) {{{
 * \brief Links a set of compiled program objects and libraries for all the
 *    devices or a specific device(s) in the OpenCL context and creates an
 *    executable.
 *
 * This function is a wrapper around \c clLinkProgram(). The call to this
 * function has same effect as
 *  - \c clLinkProgram(context, num_devices, device_list, options, num_input_programs, input_programs, pfn_notify, user_data, &errcode_ret)
 * with \p errcode_ret being defined internally in link_program().
 *
 *
 * The main difference between \ref link_program() and
 * \c clLinkProgram() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 *  link_program() creates a new program object which contains this executable.
 *  The executable binary can be queried using get_program_info(program,
 *  program_info_t::binaries, ...) and can be specified to
 *  create_program_with_binary() to create a new program object.
 *
 *  The devices associated with the returned program object will be the list of
 *  devices specified by \p device_list or if \p device_list is \c NULL it will
 *  be the list of devices associated with \p context.
 *
 *  The linking operation can begin if the context, list of devices, input
 *  programs and linker options specified are all valid and appropriate host
 *  and device resources needed to perform the link are available. If the
 *  linking operation can begin, link_program() returns a valid non-zero
 *  program object.
 *
 * \b Linker Options
 *
 * See [clLinkProgram()](https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clLinkProgram.html).
 *
 * \param context
 *    Must be a valid OpenCL context.
 * \param num_devices
 *    The number of devices listed in \p device_list.
 * \param device_list
 *    A pointer to a list of devices that are in context. If device_list is a
 *    NULL value, the link is performed for all devices associated with context
 *    for which a compiled object is available. If device_list is a non-NULL
 *    value, the compile is performed for devices specified in this list for
 *    which a source has been loaded.
 * \param options
 *    A pointer to a null-terminated string of characters that describes the
 *    link options to be used for building the program executable.
 * \param num_input_programs
 *    Specifies the number of programs in array referenced by \p input_programs.
 * \param input_programs
 *    An array of program objects that are compiled binaries or libraries that
 *    are to be linked to create the program executable. For each device in
 *    \p device_list or if device_list is \c NULL the list of devices
 *    associated with \p context, the following cases occur:
 *      - All programs specified by \p input_programs contain a compiled binary
 *        or library for the device. In this case, a link is performed to
 *        generate a program executable for this device.
 *      - None of the programs contain a compiled binary or library for that
 *        device. In this case, no link is performed and there will be no
 *        program executable generated for this device.
 *      - All other cases will throw clerror_no<status_t::invalid_operation>.
 * \param pfn_notify
 *    A function pointer to a notification routine. The notification routine is
 *    a callback function that an application can register and which will be
 *    called when the program executable has been built (successfully or
 *    unsuccessfully). If \p pfn_notify is not \c NULL, link_program() does
 *    not need to wait for the link to complete and can return immediately
 *    once the link operation can begin. The link operation can begin if the
 *    context, program whose sources are being linkd and linked, list of
 *    devices and link options specified are all valid and appropriate host
 *    and device resources needed to perform the link are available. If
 *    \p pfn_notify is \c NULL, link_program() does not return until the link
 *    has completed. This callback function may be called asynchronously by the
 *    OpenCL implementation. It is the application’s responsibility to ensure
 *    that the callback function is thread-safe.
 * \param user_data
 *    Passed as an argument when \p pfn_notify is called. \p user_data can be
 *    \c NULL.
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clLinkProgram() returns CL_INVALID_CONTEXT.
 * \throw clerror_no<status_t::invalid_program>
 *    When \c clLinkProgram() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clLinkProgram() returns CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_device>
 *    When \c clLinkProgram() returns CL_INVALID_DEVICE.
 * \throw clerror_no<status_t::invalid_linker_options>
 *    When \c clLinkProgram() returns CL_LINKER_OPTIONS.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clLinkProgram() returns CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::linker_not_available>
 *    When \c clLinkProgram() returns CL_LINKER_NOT_AVAILABLE.
 * \throw clerror_no<status_t::link_program_failure>
 *    When \c clLinkProgram() returns CL_LINK_PROGRAM_FAILURE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clLinkProgram() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clLinkProgram() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clLinkProgram() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clLinkProgram.html">clLinkProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(link_program) cl_program CLXX_B5D_API_CALL
link_program(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data
) CLXX_B5D_API_SUFFIX(link_program);
#endif
#if CLXX_B5D_PROVIDES(release_command_queue)
/** // doc: release_command_queue(...) {{{
 * \brief Decrement the \p command_queue reference count
 *
 * This is a wrapper around \c clReleaseCommandQueue(). The call to this
 * function has same effect as call to
 *  - \c clReleaseCommandQueue(command_queue)
 *
 * The difference between \ref release_command_queue() and
 * \c clReleaseCommandQueue() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    The OpenCL command-queue to release.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clReleaseCommandQueue() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseCommandQueue() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseCommandQueue() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clReleaseCommandQueue() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseCommandQueue.html">clReleaseCommandQueue()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_command_queue) void CLXX_B5D_API_CALL
release_command_queue(
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(release_command_queue);
#endif
#if CLXX_B5D_PROVIDES(release_context)
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseContext.html">clReleaseContext()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_context) void CLXX_B5D_API_CALL
release_context(
    cl_context context
) CLXX_B5D_API_SUFFIX(release_context);
#endif
#if CLXX_B5D_PROVIDES(release_device)
/** // doc: release_device(...) {{{
 * \brief Decrements the \p devices reference count
 *
 * This function is a wrapper around \c clReleaseDevice(). The call to this
 * function has same effect as
 *  - \c clReleaseDevice(device)
 *
 * The main difference between \ref release_device() and
 * \c clReleaseDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function decrements the \p device reference count if \p device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \p device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \p device reference count remains unchanged.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseDevice.html">clReleaseDevice()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_device) void CLXX_B5D_API_CALL
release_device(
    cl_device_id device
) CLXX_B5D_API_SUFFIX(release_device);
#endif
#if CLXX_B5D_PROVIDES(release_event)
/** // doc: release_event() {{{
 * \brief Decrements the \p event reference count
 *
 * This function is a wrapper around \c clReleaseEvent(). The call to this
 * function has same effect as
 *  - \c clReleaseEvent(event)
 *
 * The main difference between \ref release_event() and
 * \c clReleaseEvent() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The event object is deleted once the number of instances that are
 *       retained to event become zero and the event object is no longer
 *       needed by any enqueued commands that use event.
 *
 * \param event
 *    The event to be released
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clReleaseEvent() returns CL_INVALID_EVENT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseEvent() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseEvent() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseEvent() returns other error code.
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseEvent.html">clReleaseEvent()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_event) void CLXX_B5D_API_CALL
release_event(
    cl_event event
) CLXX_B5D_API_SUFFIX(release_event);
#endif
#if CLXX_B5D_PROVIDES(release_kernel)
/** // doc: release_kernel() {{{
 * \brief Decrements the \p kernel reference count
 *
 * This function is a wrapper around \c clReleaseKernel(). The call to this
 * function has same effect as
 *  - \c clReleaseKernel(kernel)
 *
 * The main difference between \ref release_kernel() and
 * \c clReleaseKernel() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The kernel object is deleted once the number of instances that are
 *       retained to kernel become zero and the kernel object is no longer
 *       needed by any enqueued commands that use kernel.
 *
 * \param kernel
 *    The kernel to be released
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clReleaseKernel() returns CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseKernel() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseKernel() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseKernel() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseKernel.html">clReleaseKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_kernel) void CLXX_B5D_API_CALL
release_kernel(
    cl_kernel kernel
) CLXX_B5D_API_SUFFIX(release_kernel);
#endif
#if CLXX_B5D_PROVIDES(release_mem_object)
/** // doc: release_mem_object() {{{
 * \brief Decrements the memory object reference count
 *
 * This is a wrapper for \c clReleaseMemObject(). The call to
 * #release_mem_object() has same effect as a call to
 *    - \c clReleaseMemObject(memobj)
 *
 * The main difference between #release_mem_object() and \c clReleaseMemObject()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param memobj
 *    A valid memory object
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clReleaseMemObject() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseMemObject() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseMemObject() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseMemObject() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseMemObject.html">clReleaseMemObject()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_mem_object) void CLXX_B5D_API_CALL
release_mem_object(
    cl_mem memobj
) CLXX_B5D_API_SUFFIX(release_mem_object);
#endif
#if CLXX_B5D_PROVIDES(release_program)
/** // doc: release_program(...) {{{
 * \brief Decrements the \p program reference count
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseProgram.html">clReleaseProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_program) void CLXX_B5D_API_CALL
release_program(
    cl_program program
) CLXX_B5D_API_SUFFIX(release_program);
#endif
#if CLXX_B5D_PROVIDES(release_sampler)
/** // doc: release_sampler(...) {{{
 * \brief Decrements the \p sampler reference count
 *
 * This function is a wrapper around \c clReleaseSampler(). The call to this
 * function has same effect as
 *  - \c clReleaseSampler(sampler)
 *
 * The main difference between \ref release_sampler() and
 * \c clReleaseSampler() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note The sampler object is deleted after the reference count becomes zero
 * and commands queued for execution on a command-queue(s) that use sampler
 * have finished.
 *
 * \note Using this function to release a reference that was not obtained by
 * creating the object or by calling #retain_sampler() causes undefined
 * behavior.
 *
 * \param sampler
 *    The sampler to be released
 *
 * \throw clerror_no<status_t::invalid_sampler>
 *    When \c clReleaseSampler() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clReleaseSampler() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clReleaseSampler() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clReleaseSampler() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clReleaseSampler.html">clReleaseSampler()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(release_sampler) void CLXX_B5D_API_CALL
release_sampler(
    cl_sampler sampler
) CLXX_B5D_API_SUFFIX(release_sampler);
#endif
#if CLXX_B5D_PROVIDES(retain_command_queue)
/** // doc: retain_command_queue(...) {{{
 * \brief Increment the \p command_queue reference count
 *
 * This is a wrapper around \c clRetainCommandQueue(). The call to this
 * function has same effect as call to
 *  - \c clRetainCommandQueue(command_queue)
 *
 * The difference between \ref retain_command_queue() and
 * \c clRetainCommandQueue() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    The OpenCL command-queue to retain.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When \c clRetainCommandQueue() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainCommandQueue() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainCommandQueue() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpeced_clerror
 *    When \c clRetainCommandQueue() returns other error code.
 *
 * \note \ref create_command_queue() performs an implicit retain.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainCommandQueue.html">clRetainCommandQueue()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_command_queue) void CLXX_B5D_API_CALL
retain_command_queue(
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(retain_command_queue);
#endif
#if CLXX_B5D_PROVIDES(retain_context)
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainContext.html">clRetainContext()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_context) void CLXX_B5D_API_CALL
retain_context(
    cl_context context
) CLXX_B5D_API_SUFFIX(retain_context);
#endif
#if CLXX_B5D_PROVIDES(retain_device)
/** // doc: retain_device(...) {{{
 * \brief Increments the \p devices reference count
 *
 * This function is a wrapper around \c clRetainDevice(). The call to this
 * function has same effect as
 *  - \c clRetainDevice(device)
 *
 * The main difference between \ref retain_device() and
 * \c clRetainDevice() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * The function increments the \p device reference count if \p device is a
 * valid sub-device created by call to \ref create_sub_devices() or
 * \c clCreateSubDevices(). If \p device is a root level device i.e.
 * a \c cl_device_id returned by \ref get_device_ids() or \c clGetDeviceIDs(),
 * the \p device reference count remains unchanged.
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainDevice.html">clRetainDevice()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_device) void CLXX_B5D_API_CALL
retain_device(
    cl_device_id device
) CLXX_B5D_API_SUFFIX(retain_device);
#endif
#if CLXX_B5D_PROVIDES(retain_event)
/** // doc: retain_event() {{{
 * \brief Increments the event object reference count.
 *
 * This function is a wrapper around \c clRetainEvent(). The call to this
 * function has same effect as
 *  - \c clRetainEvent(event)
 *
 * The main difference between #retain_event() and \c clRetainEvent() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \note create_user_event() performs an implicit retain.
 *
 * \param event
 *    The event to be retained
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clRetainEvent() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainEvent() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainEvent() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clRetainEvent() returns other error code.
 *
 *  \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainEvent.html">clRetainEvent()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_event) void CLXX_B5D_API_CALL
retain_event(
    cl_event event
) CLXX_B5D_API_SUFFIX(retain_event);
#endif
#if CLXX_B5D_PROVIDES(retain_kernel)
/** // doc: retain_kernel() {{{
 * \brief Increments the kernel object reference count.
 *
 * This function is a wrapper around \c clRetainKernel(). The call to this
 * function has same effect as
 *  - \c clRetainKernel(kernel)
 *
 * The main difference between #retain_kernel() and \c clRetainKernel() is that
 * it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \note create_kernel() and create_kernels_in_program() do an implicit retain.
 *
 * \param kernel
 *    The kernel to be retained
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clRetainKernel() returns CL_INVALID_KERNEL
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainKernel() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainKernel() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clRetainKernel() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainKernel.html">clRetainKernel()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_kernel) void CLXX_B5D_API_CALL
retain_kernel(
    cl_kernel kernel
) CLXX_B5D_API_SUFFIX(retain_kernel);
#endif
#if CLXX_B5D_PROVIDES(retain_mem_object)
/** // doc: retain_mem_object() {{{
 * \brief Increments the memory object reference count
 *
 * This is a wrapper for \c clRetainMemObject(). The call to
 * #retain_mem_object() has same effect as a call to
 *    - \c clRetainMemObject(memobj)
 *
 * The main difference between #retain_mem_object() and \c clRetainMemObject()
 * is that it throws %clxx exceptions instead of returning OpenCL error codes.
 *
 * \param memobj
 *    A valid memory object
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clRetainMemObject() returns \c CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainMemObject() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainMemObject() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainMemObject() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainMemObject.html">clRetainMemObject()</a>
 *
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_mem_object) void CLXX_B5D_API_CALL
retain_mem_object(
    cl_mem memobj
) CLXX_B5D_API_SUFFIX(retain_mem_object);
#endif
#if CLXX_B5D_PROVIDES(retain_program)
/** // doc: retain_program(...) {{{
 * \brief Increments the \p program reference count
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
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clRetainProgram.html">clRetainProgram()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_program) void CLXX_B5D_API_CALL
retain_program(
    cl_program program
) CLXX_B5D_API_SUFFIX(retain_program);
#endif
#if CLXX_B5D_PROVIDES(retain_sampler)
/** // doc: retain_sampler(...) {{{
 * \brief Increments the \p sampler reference count
 *
 * This function is a wrapper around \c clRetainSampler(). The call to this
 * function has same effect as
 *  - \c clRetainSampler(sampler)
 *
 * The main difference between \ref retain_sampler() and
 * \c clRetainSampler() is that it throws %clxx exceptions instead of returning
 * OpenCL error codes.
 *
 * \note #create_sampler() and #create_sampler_with_properties()
 * do an implicit retain. The same applies to \c clCreateSampler()
 * and \c clCreateSamplerWithProperties() functions.
 *
 * \param sampler
 *    The sampler to be retained
 *
 * \throw clerror_no<status_t::invalid_sampler>
 *    When \c clRetainSampler() returns CL_INVALID_PROGRAM.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clRetainSampler() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clRetainSampler() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clRetainSampler() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clRetainSampler.html">clRetainSampler()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(retain_sampler) void CLXX_B5D_API_CALL
retain_sampler(
    cl_sampler sampler
) CLXX_B5D_API_SUFFIX(retain_sampler);
#endif
#if CLXX_B5D_PROVIDES(set_command_queue_property)
/** // doc: set_command_queue_property() {{{
 * \brief Enable or disable the properties of a command-queue
 *
 * This function is a wrapper around \c clSetCommandQueueProperty(). The call to
 * this function has same effect as
 * - \c clSetCommandQueueProperty(command_queue, static_cast<cl_command_queue_properties>(properties), enable, old_properties)
 *
 * The main difference between #set_command_queue_property() and
 * \c clSetCommandQueueProperty() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param command_queue
 *    Specifies the command-queue being queried.
 * \param properties
 *    Specifies the new command-queue properties to be applied to
 *    \p command_queue. Only command-queue properties specified for
 *    #create_command_queue() can be set in properties; otherwise the value
 *    specified in properties is considered to be not valid.
 * \param enable
 *    Determines whether the values specified by properties are enabled (if
 *    \p enable is \c CL_TRUE) or disabled (if \p enable is \c CL_FALSE) for
 *    the command-queue. The allowed property values are the same as those
 *    specified for #create_command_queue().
 * \param old_properties
 *     Returns the command-queue properties before they were changed by
 *     #set_command_queue_property(). If \p old_properties is \c NULL, it is
 *     ignored.
 *
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clSetCommandQueueProperty() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clSetCommandQueueProperty() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_queue_properties>
 *    When the \c clSetCommandQueueProperty() returns CL_INVALID_QUEUE_PROPERTIES
 * \throw unexpected_clerror
 *    When \c clSetCommandQueueProperty() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.0/docs/man/xhtml/clSetCommandQueueProperty.html">clSetCommandQueueProperty()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_command_queue_property) void CLXX_B5D_API_CALL
set_command_queue_property(
    cl_command_queue command_queue,
    command_queue_properties_t properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties
) CLXX_B5D_API_SUFFIX(set_command_queue_property);
#endif
#if CLXX_B5D_PROVIDES(set_default_device_command_queue)
/** // doc: set_default_device_command_queue() {{{
 * \brief Replaces the default command queue on the device.
 *
 * This function is a wrapper around \c clSetDefaultDeviceCommandQueue(). The call to
 * this function has same effect as
 * - \c clSetDefaultDeviceCommandQueue(context, device, command_queue)
 *
 * The main difference between #set_default_device_command_queue() and
 * \c clSetDefaultDeviceCommandQueue() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param context
 * \param device
 * \param command_queue
 *
 * \throw clerror_no<status_t::invalid_context>
 *    When the \c clSetDefaultDeviceCommandQueue() returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_device>
 *    When the \c clSetDefaultDeviceCommandQueue() returns CL_INVALID_DEVICE
 * \throw clerror_no<status_t::invalid_command_queue>
 *    When the \c clSetDefaultDeviceCommandQueue() returns CL_INVALID_COMMAND_QUEUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clSetDefaultDeviceCommandQueue() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clSetDefaultDeviceCommandQueue() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clSetDefaultDeviceCommandQueue() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clSetDefaultDeviceCommandQueue.html">clSetDefaultDeviceCommandQueue()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_default_device_command_queue) void CLXX_B5D_API_CALL
set_default_device_command_queue(
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue
) CLXX_B5D_API_SUFFIX(set_default_device_command_queue);
#endif
#if CLXX_B5D_PROVIDES(set_event_callback)
/** // doc: set_event_callback() {{{
 * \brief Registers a user callback function for a specific command execution status
 *
 * This function is a wrapper around \c clSetEventCallback(). The call to
 * this function has same effect as
 * - \c clSetEventCallback(event, command_exec_callback_type, pfn_event_notify, user_data)
 *
 * The main difference between #set_event_callback() and
 * \c clSetEventCallback() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    A valid event object
 * \param command_exec_callback_type
 *    Specifies the command execution status for which the callback is
 *    registered. The command execution callback values for which a callback
 *    can be registered are \c CL_SUBMITTED, \c CL_RUNNING, or \c CL_COMPLETE.
 * \param pfn_event_notify
 *    The event callback function that can be registered by the application.
 *    This callback function may be called asynchronously by the OpenCL
 *    implementation. It is the application's responsibility to ensure that the
 *    callback function is thread-safe.
 * \param user_data
 *    Will be passed as the user_data argument when \p pfn_notify is called.
 *    \p user_data can be \c NULL.
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When the \c clSetEventCallback() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clSetEventCallback() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clSetEventCallback() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clSetEventCallback() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clSetEventCallback() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetEventCallback.html">clSetEventCallback()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_event_callback) void CLXX_B5D_API_CALL
set_event_callback(
    cl_event event,
    cl_int command_exec_callback_type,
    void(CL_CALLBACK* pfn_event_notify)(cl_event, cl_int, void*),
    void* user_data
) CLXX_B5D_API_SUFFIX(set_event_callback);
#endif
#if CLXX_B5D_PROVIDES(set_kernel_arg)
/** // doc: set_kernel_arg() {{{
 * \brief Used to set the argument value for a specific argument of a kernel
 *
 * This function is a wrapper around \c clSetKernelArg(). The call to this
 * function has same effect as
 *  - \c clSetKernelArg(kernel, arg_index, arg_size, arg_value)
 *
 * The main difference between \ref set_kernel_arg() and
 * \c clSetKernelArg() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    A valid kernel object.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param arg_size
 *    Specifies the size of the argument value. If the argument is a memory
 *    object, the size is the size of the memory object. For arguments declared
 *    with the local qualifier, the size specified will be the size in bytes of
 *    the buffer that must be allocated for the local argument. If the argument
 *    is of type \c sampler_t, the \em arg_size value must be equal to
 *    <tt>sizeof(cl_sampler)</tt>. If the argument is of type \c queue_t, the
 *    \em arg_size value must be equal to <tt>sizeof(cl_command_queue)</tt>.
 *    For all other arguments, the size will be the size of argument type.
 * \param arg_value
 *    A pointer to data that should be used as the argument value for argument
 *    specified by \em arg_index. The argument data pointed to by \em arg_value
 *    is copied and the \em arg_value pointer can therefore be reused by the
 *    application after #set_kernel_arg() returns. The argument value specified
 *    is the value used by all API calls that enqueue kernel
 *    (#enqueue_ndrange_kernel()) until the argument value is changed by a
 *    call to #set_kernel_arg() for kernel.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArg.html">clSetKernelArg()</a>
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelArg() returns CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_arg_value>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_VALUE.
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When \c clSetKernelArg() returns CL_INVALID_MEM_OBJECT.
 * \throw clerror_no<status_t::invalid_sampler>
 *    When \c clSetKernelArg() returns CL_INVALID_SAMPLER.
 * \throw clerror_no<status_t::invalid_device_queue>
 *    When \c clSetKernelArg() returns CL_INVALID_DEVICE_QUEUE.
 * \throw clerror_no<status_t::invalid_arg_size>
 *    When \c clSetKernelArg() returns CL_INVALID_ARG_SIZE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelArg() returns CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelArg() returns CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelArg() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArg.html">clSetKernelArg()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_kernel_arg) void CLXX_B5D_API_CALL
set_kernel_arg(
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value
) CLXX_B5D_API_SUFFIX(set_kernel_arg);
#endif
#if CLXX_B5D_PROVIDES(set_kernel_arg_svm_pointer)
/** // doc: set_kernel_arg_svm_pointer() {{{
 * \brief Used to set a SVM pointer as the argument value for a specific
 *        argument of a kernel
 *
 * This function is a wrapper around \c clSetKernelArgSVMPointer(). The call to this
 * function has same effect as
 *  - \c clSetKernelArgSVMPointer(kernel, arg_index, arg_value)
 *
 * The main difference between \ref set_kernel_arg_svm_pointer() and
 * \c clSetKernelArgSVMPointer() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    A valid kernel object.
 * \param arg_index
 *    The argument index. Arguments to the kernel are referred by indices that
 *    go from \c 0 for the leftmost argument to <tt>n - 1</tt>, where \c n is
 *    the total number of arguments declared by a kernel.
 * \param arg_value
 *    A pointer to the SVM pointer that should be used as the argument value
 *    for argument specified by \em arg_index. The SVM pointer specified is the
 *    value used by all API calls that enqueue kernel (#enqueue_ndrange_kernel())
 *    until the argument value is changed by a call to set_kernel_arg_svm_pointer()
 *    for kernel. The SVM pointer can only be used for arguments that are
 *    declared to be a pointer to global or constant memory. The SVM pointer
 *    value must be aligned according to the argument's type. For example, if
 *    the argument is declared to be global <tt>float4 *p</tt>, the SVM pointer
 *    value passed for \c p must be at a minimum aligned to a \c float4. The
 *    SVM pointer value specified as the argument value can be the pointer
 *    returned by clSVMAlloc or can be a pointer + offset into the SVM region.
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_arg_index>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_ARG_INDEX.
 * \throw clerror_no<status_t::invalid_arg_value>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_INVALID_ARG_VALUE.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelArgSVMPointer() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelArgSVMPointer() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelArgSVMPointer.html">clSetKernelArgSVMPointer()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_kernel_arg_svm_pointer) void CLXX_B5D_API_CALL
set_kernel_arg_svm_pointer(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value
) CLXX_B5D_API_SUFFIX(set_kernel_arg_svm_pointer);
#endif
#if CLXX_B5D_PROVIDES(set_kernel_exec_info)
/** // doc: set_kernel_exec_info() {{{
 * \brief Used to pass additional information other than argument values to a kernel
 *
 * This function is a wrapper around \c clSetKernelExecInfo(). The call to this
 * function has same effect as
 *  - \c clSetKernelExecInfo(kernel, param_name, param_value_size, param_value)
 *
 * The main difference between \ref set_kernel_exec_info() and
 * \c clSetKernelExecInfo() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param kernel
 *    Specifies the kernel object being queried.
 * \param param_name
 *    Specifies the information to be passed to kernel. The list of supported
 *    \em param_name types may be found in the documentation of
 *    \ref clxx::kernel_exec_info_t "kernel_exec_info_t". The corresponding
 *    values passed in \em param_value are described in the OpenCL standard.
 * \param param_value_size
 *    Specifies the size in bytes of the memory pointed to by \em param_value.
 * \param param_value
 *    A pointer to memory where the appropriate values determined by
 *    \em param_name are specified.
 *
 * \throw clerror_no<status_t::invalid_kernel>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_KERNEL.
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_VALUE.
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clSetKernelExecInfo() returns \c CL_INVALID_OPERATION.
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetKernelExecInfo() returns \c CL_OUT_OF_RESOURCES.
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetKernelExecInfo() returns \c CL_OUT_OF_HOST_MEMORY.
 * \throw unexpected_clerror
 *    When \c clSetKernelExecInfo() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetKernelExecInfo.html">clSetKernelExecInfo()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_kernel_exec_info) void CLXX_B5D_API_CALL
set_kernel_exec_info(
    cl_kernel kernel,
    kernel_exec_info_t param_name,
    size_t param_value_size,
    const void* param_value
) CLXX_B5D_API_SUFFIX(set_kernel_exec_info);
#endif
#if CLXX_B5D_PROVIDES(set_mem_object_destructor_callback)
/** // doc: set_mem_object_destructor_callback() {{{
 * \brief Registers a user callback function with a memory object.
 *
 * This function is a wrapper around \c clSetMemObjectDestructorCallback(). The call to
 * this function has same effect as
 * - \c clSetMemObjectDestructorCallback(memobj, pfn_notify, user_data)
 *
 * The main difference between #set_mem_object_destructor_callback() and
 * \c clSetMemObjectDestructorCallback() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param memobj
 *    A valid memory object.
 * \param pfn_notify
 *     The callback function that can be registered by the application. This
 *     callback function may be called asynchronously by the OpenCL
 *     implementation. It is the application's responsibility to ensure that
 *     the callback function is thread-safe. The parameters to this callback
 *     function are:
 *         - \p memobj: the memory object being deleted. When the user callback
 *           is called by the implementation, this memory object is no longer
 *            valid. memobj is only provided for reference purposes.
 *         - \p user_data: a pointer to user supplied data
 * \param user_data
 *    Will be passed as the \p user_data argument when \p pfn_notify is called.
 *    \p user_data can be \c NULL.
 *
 * \throw clerror_no<status_t::invalid_mem_object>
 *    When the \c clSetMemObjectDestructorCallback() returns CL_INVALID_MEM_OBJECT
 * \throw clerror_no<status_t::invalid_value>
 *    When the \c clSetMemObjectDestructorCallback() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::out_of_resources>
 *    When the \c clSetMemObjectDestructorCallback() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When the \c clSetMemObjectDestructorCallback() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clSetMemObjectDestructorCallback() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetMemObjectDestructorCallback.html">clSetMemObjectDestructorCallback()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_mem_object_destructor_callback) void CLXX_B5D_API_CALL
set_mem_object_destructor_callback(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem, void*),
    void* user_data
) CLXX_B5D_API_SUFFIX(set_mem_object_destructor_callback);
#endif
#if CLXX_B5D_PROVIDES(set_user_event_status)
/** // doc: set_user_event_status() {{{
 * \brief Sets the execution status of a user event object
 *
 * This function is a wrapper around \c clSetUserEventStatus(). The call to this
 * function has same effect as
 * - \c clSetUserEventStatus(event, execution_status),
 *
 * The main difference between #set_user_event_status() and
 * \c clSetUserEventStatus() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param event
 *    A user event object created using #create_user_event.
 * \param execution_status
 *    Specifies the new execution status to be set and can be \c CL_COMPLETE or
 *    a negative integer value to indicate an error. A negative integer value
 *    causes all enqueued commands that wait on this user event to be
 *    terminated. #set_user_event_status() can only be called once to change the
 *    execution status of event.
 *
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clSetUserEventStatus() returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clSetUserEventStatus() returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_operation>
 *    When \c clSetUserEventStatus() returns CL_INVALID_OPERATION
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clSetUserEventStatus() returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clSetUserEventStatus() returns CL_OUT_OF_HOST_MEMORY
 * \throw unexpected_clerror
 *    When \c clSetUserEventStatus() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clSetUserEventStatus.html">clSetUserEventStatus()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(set_user_event_status) void CLXX_B5D_API_CALL
set_user_event_status(
    cl_event event,
    cl_int execution_status
) CLXX_B5D_API_SUFFIX(set_user_event_status);
#endif
#if CLXX_B5D_PROVIDES(svm_alloc)
/** // doc: svm_alloc(...) {{{
 * \brief Allocates a shared virtual memory (SVM) buffer that can be shared by
 *        the host and all devices in an OpenCL context that support shared
 *        virtual memory
 *
 * This function is a wrapper around \c clSVMAlloc(). The call to
 * this function has same effect as
 *  - \c clSVMAlloc(context, static_cast<cl_svm_mem_flags>(flags), size, alignment)
 *
 * The main difference between \ref svm_alloc() and
 * \c clSVMAlloc() is that it uses %clxx enum instead of OpenCL constant
 * to represent flags.
 *
 * \param context
 *    A valid OpenCL context used to create the SVM buffer.
 * \param flags
 *    A bit-field that is used to specify allocation and usage information. The
 *    possible flag values may be found in the documentation of
 *    #svm_mem_flags_t.
 * \param size
 *    The size in bytes of the SVM buffer to be allocated.
 * \param alignment
 *    The minimum alignment in bytes that is required for the newly created
 *    buffer’s memory region. It must be a power of two up to the largest data
 *    type supported by the OpenCL device. For the full profile, the largest
 *    data type is \c long16. For the embedded profile, it is \c long16 if the
 *    device supports 64-bit integers; otherwise it is \c int16. If alignment
 *    is \c 0, a default alignment will be used that is equal to the size of
 *    largest data type supported by the OpenCL implementation.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clSVMAlloc.html">clSVMAlloc()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(svm_alloc) void* CLXX_B5D_API_CALL
svm_alloc(
    cl_context context,
    svm_mem_flags_t flags,
    size_t size,
    cl_uint alignment
) CLXX_B5D_API_SUFFIX(svm_alloc);
#endif
#if CLXX_B5D_PROVIDES(svm_free)
/** // doc: svm_free(...) {{{
 * \brief Frees a shared virtual memory buffer allocated using #svm_alloc
 *        (\c clSVMAlloc)
 *
 * This function is a wrapper around \c clSVMFree(). The call to
 * this function has same effect as
 *  - \c clSVMFree(context, svm_pointer)
 *
 * There is actually no  difference between \ref svm_free() and
 * \c clSVMFree(), the function is introduced only for consistency with the
 * rest of the API.
 *
 * \param context
 *    A valid OpenCL context used to create the SVM buffer.
 * \param svm_pointer
 *    Must be the value returned by a call to #svm_alloc (\c clSVMAlloc). If a
 *    \c NULL pointer is passed in \p svm_pointer, no action occurs.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.1/docs/man/xhtml/clSVMFree.html">clSVMFree()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(svm_free) void CLXX_B5D_API_CALL
svm_free(
    cl_context context,
    void* svm_pointer
) CLXX_B5D_API_SUFFIX(svm_free);
#endif
#if CLXX_B5D_PROVIDES(unload_compiler)
/** // doc: unload_compiler(...) {{{
 * \brief Allows the implementation to release the resources allocated by the
 *        OpenCL compiler
 *
 * This function is a wrapper around \c clUnloadCompiler(). The call to
 * this function has same effect as
 *  - \c clUnloadCompiler()
 *
 * The main difference between \ref unload_compiler() and
 * \c clUnloadCompiler() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \note This is a hint from the application and does not guarantee that the
 * compiler will not be used in the future or that the compiler will actually
 * be unloaded by the implementation. Calls to #build_program (or
 * \c clBuildProgram) after \c #unload_compiler will reload the compiler, if
 * necessary, to build the appropriate program executable.
 *
 * \throw unexpected_clerror
 *    When \c clUnloadCompiler() returns an error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/1.1/docs/man/xhtml/clUnloadCompiler.html">clUnloadCompiler()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(unload_compiler) void CLXX_B5D_API_CALL
unload_compiler(
) CLXX_B5D_API_SUFFIX(unload_compiler);
#endif
#if CLXX_B5D_PROVIDES(unload_platform_compiler)
/** // doc: unload_platform_compiler(...) {{{
 * \brief Allows the implementation to release the resources allocated by the
 *    OpenCL compiler for \p platform.
 *
 * This function is a wrapper around \c clUnloadPlatformCompiler(). The call to
 * this function has same effect as
 *  - \c clUnloadPlatformCompiler(platform)
 *
 * The main difference between \ref unload_platform_compiler() and
 * \c clUnloadPlatformCompiler() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * This is a hint from the application and does not guarantee that the compiler
 * will not be used in the future or that the compiler will actually be
 * unloaded by the implementation. Calls to build_program(), compile_program(),
 * or link_program() after unload_platform_compiler() will reload the compiler,
 * if necessary, to build the appropriate program executable.
 *
 * \param platform
 *    The platform whose compiler may be unloaded
 *
 * \throw clerror_no<status_t::invalid_platform>
 *    When \c clUnloadPlatformCompiler() returns CL_INVALID_PLATFORM.
 * \throw unexpected_clerror
 *    When \c clUnloadPlatformCompiler() returns other error code.
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clUnloadPlatformCompiler.html">clUnloadPlatformCompiler()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(unload_platform_compiler) void CLXX_B5D_API_CALL
unload_platform_compiler(
    cl_platform_id platform
) CLXX_B5D_API_SUFFIX(unload_platform_compiler);
#endif
#if CLXX_B5D_PROVIDES(wait_for_events)
/** // doc: wait_for_events() {{{
 * \brief Waits on the host thread for commands identified by event objects to complete
 *
 * This function is a wrapper around \c clWaitForEvents(). The call to this
 * function has same effect as
 * - \c clWaitForEvents(num_events, event_list),
 *
 * The main difference between #set_user_event_status() and
 * \c clWaitForEvents() is that it throws %clxx exceptions instead of
 * returning OpenCL error codes.
 *
 * \param num_events
 *    Number of events in \p event_list
 * \param event_list
 *    The events specified in \p event_list act as synchronization points
 *
 * \throw clerror_no<status_t::invalid_value>
 *    When \c clWaitForEvents returns CL_INVALID_VALUE
 * \throw clerror_no<status_t::invalid_context>
 *    When \c clWaitForEvents returns CL_INVALID_CONTEXT
 * \throw clerror_no<status_t::invalid_event>
 *    When \c clWaitForEvents returns CL_INVALID_EVENT
 * \throw clerror_no<status_t::exec_status_error_for_events_in_wait_list>
 *    When \c clWaitForEvents returns CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST
 * \throw clerror_no<status_t::out_of_resources>
 *    When \c clWaitForEvents returns CL_OUT_OF_RESOURCES
 * \throw clerror_no<status_t::out_of_host_memory>
 *    When \c clWaitForEvents returns CL_OUT_OF_HOST_MEMORY
 *
 * \sa <a href="https://www.khronos.org/registry/cl/sdk/2.0/docs/man/xhtml/clWaitForEvents.html">clWaitForEvents()</a>
 */ // }}}
extern CLXX_B5D_API_PREFIX(wait_for_events) void CLXX_B5D_API_CALL
wait_for_events(
    cl_uint num_events,
    const cl_event* event_list
) CLXX_B5D_API_SUFFIX(wait_for_events);
#endif
/** @} */
} // end namespace clxx

#endif /* CLXX_B5D_CL_FUNCTIONS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
