// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b5d/detail/enum2name.cpp {{{
 * \file clxx/b5d/detail/enum2name.cpp
 * \todo Write documentation for clxx/b5d/detail/enum2name.cpp
 */ // }}}
#include <clxx/b5d/detail/enum2name.hpp>
#include <type_traits>
#include <cstdlib>


namespace clxx { namespace detail {

#if 0
static const char* _error_names_00[] = {
  "success",                                    //   0
  "device_not_found",                           //  -1
  "device_not_available",                       //  -2
  "compiler_not_available",                     //  -3
  "mem_object_allocation_failure",              //  -4
  "out_of_resources",                           //  -5
  "out_of_host_memory",                         //  -6
  "profiling_info_not_available",               //  -7
  "mem_copy_overlap",                           //  -8
  "image_format_mismatch",                      //  -9
  "image_format_not_supported",                 // -11
  "build_program_failure",                      // -12
  "map_failure"                                 // -13
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
  ,
  "misaligned_sub_buffer_offset",               // -14
  "exec_status_error_for_events_in_wait_list"   // -15
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  ,
  "compile_program_failure",                    // -16
  "linker_not_available",                       // -17
  "link_program_failure",                       // -18
  "device_partition_failed",                    // -19
  "kernel_arg_info_not_available"               // -20
#endif
};

static constexpr cl_int _error_names_00_beg = 0;
static constexpr cl_int _error_names_00_end =
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  -21
#elif CLXX_B5D_OPENCL_CL_H_VERSION_1_1
  -16
#else
  -14
#endif
;
#endif

#if 0
static const char* _error_names_30[] = {
  "invalid_value",                              // -30
  "invalid_device_type",                        // -31
  "invalid_platform",                           // -32
  "invalid_device",                             // -33
  "invalid_context",                            // -34
  "invalid_queue_properties",                   // -35
  "invalid_command_queue",                      // -36
  "invalid_host_ptr",                           // -37
  "invalid_mem_object",                         // -38
  "invalid_image_format_descriptor",            // -39
  "invalid_image_size",                         // -40
  "invalid_sampler",                            // -41
  "invalid_binary",                             // -42
  "invalid_build_options",                      // -43
  "invalid_program",                            // -44
  "invalid_program_executable",                 // -45
  "invalid_kernel_name",                        // -46
  "invalid_kernel_definition",                  // -47
  "invalid_kernel",                             // -48
  "invalid_arg_index",                          // -49
  "invalid_arg_value",                          // -50
  "invalid_arg_size",                           // -51
  "invalid_kernel_args",                        // -52
  "invalid_work_dimension",                     // -53
  "invalid_work_group_size",                    // -54
  "invalid_work_item_size",                     // -55
  "invalid_global_offset",                      // -56
  "invalid_event_wait_list",                    // -57
  "invalid_event",                              // -58
  "invalid_operation",                          // -59
  "invalid_gl_object",                          // -60
  "invalid_buffer_size",                        // -61
  "invalid_mip_level",                          // -62
  "invalid_global_work_size"                    // -63
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
  ,
  "invalid_property"                            // -64
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  ,
  "invalid_image_descriptor",                   // -65
  "invalid_compiler_options",                   // -66
  "invalid_linker_options",                     // -67
  "invalid_device_partition_count"              // -68
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_0
  ,
  "invalid_pipe_size",                          // -69
  "invalid_device_queue"                        // -70
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_2
  ,
  "invalid_spec_id",                            // -71
  "max_size_restriction_exceeded"               // -72
#endif
};

static constexpr cl_int _error_names_30_beg = -30;
static constexpr cl_int _error_names_30_end =
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_2
  -73
#elif CLXX_B5D_OPENCL_CL_H_VERSION_2_0
  -71
#elif CLXX_B5D_OPENCL_CL_H_VERSION_1_2
  -69
#elif CLXX_B5D_OPENCL_CL_H_VERSION_1_1
  -65
#else
  -64
#endif
;
#endif

#if 0
static const char* error_strings_30[] = {
#if cl_khr_icd
  "platform_not_found_khr",
#endif
#if cl_ext_device_fission
  "device_partition_failed_ext",
  "invalid_partition_count_ext",
  "invalid_partition_name_ext",
#endif
#if cl_khr_gl_sharing
  "invalid_gl_sharegroup_reference_khr",
#endif
#if cl_khr_dx9_media_sharing
  "invalid_dx9_media_adapter_khr",
  "invalid_dx9_media_surface_khr",
  "dx9_media_surface_already_acquired_khr",
  "dx9_media_surface_not_acquired_khr",
#endif
#if cl_khr_d3d10_sharing
  "invalid_d3d10_device_khr",
  "invalid_d3d10_resource_khr",
  "d3d10_resource_already_acquired_khr",
  "d3d10_resource_not_acquired_khr",
#endif
#if cl_khr_d3d11_sharing
  "invalid_d3d11_device_khr",
  "invalid_d3d11_resource_khr",
  "d3d11_resource_already_acquired_khr",
  "d3d11_resource_not_acquired_khr",
#endif
};
#endif

const char* enum2name(status_t x, const char* dflt) noexcept
{
  (void)x;
  return dflt;
}


} } // end namespace clxx::detail


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
