// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/detail/clerror_stdexcept.t.h

/** // doc: clxx/b5d/detail/clerror_stdexcept.t.h {{{
 * \file clxx/b5d/detail/clerror_stdexcept.t.h
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_DETAIL_CLERROR_STDEXCEPT_T_H_INCLUDED
#define CLXX_B5D_DETAIL_CLERROR_STDEXCEPT_T_H_INCLUDED

#include <cxxtest/TestSuite.h>
#include <clxx/b5d/detail/clerror_stdexcept.hpp>
#include <type_traits>

namespace clxx { namespace detail { class clerror_stdexcept_test_suite; } }

/** // doc: class clxx::detail::clerror_stdexcept_test_suite {{{
 * \todo Write documentation
 */ // }}}
class clxx::detail::clerror_stdexcept_test_suite : public CxxTest::TestSuite
{
public:
  /** // doc: test__clerror_stdexcept() {{{
   * \todo Write documentation
   */ // }}}
  void test__clerror_stdexcept( )
  {
    static_assert(std::is_same<clerror_stdexcept<status_t::device_not_found>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::device_not_available>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::compiler_not_available>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::mem_object_allocation_failure>::type, std::bad_alloc>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::out_of_resources>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::out_of_host_memory>::type, std::bad_alloc>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::profiling_info_not_available>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::mem_copy_overlap>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::image_format_mismatch>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::image_format_not_supported>::type, std::exception>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::build_program_failure>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::map_failure>::type, std::runtime_error>::value, "");
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    static_assert(std::is_same<clerror_stdexcept<status_t::misaligned_sub_buffer_offset>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::exec_status_error_for_events_in_wait_list>::type, std::invalid_argument>::value, "");
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    static_assert(std::is_same<clerror_stdexcept<status_t::compile_program_failure>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::linker_not_available>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::link_program_failure>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::device_partition_failed>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::kernel_arg_info_not_available>::type, std::runtime_error>::value, "");
#endif
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_value>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_device_type>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_platform>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_device>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_context>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_queue_properties>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_command_queue>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_host_ptr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_mem_object>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_image_format_descriptor>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_image_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_sampler>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_binary>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_build_options>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_program>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_program_executable>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_kernel_name>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_kernel_definition>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_kernel>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_arg_index>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_arg_value>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_arg_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_kernel_args>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_work_dimension>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_work_group_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_work_item_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_global_offset>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_event_wait_list>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_event>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_operation>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_gl_object>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_buffer_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_mip_level>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_global_work_size>::type, std::invalid_argument>::value, "");
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_1
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_property>::type, std::invalid_argument>::value, "");
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_1_2
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_image_descriptor>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_compiler_options>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_linker_options>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_device_partition_count>::type, std::invalid_argument>::value, "");
#endif
#if CLXX_B5D_OPENCL_CL_H_VERSION_2_0
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_pipe_size>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_device_queue>::type, std::invalid_argument>::value, "");
#endif
#if cl_khr_icd
    static_assert(std::is_same<clerror_stdexcept<status_t::platform_not_found_khr>::type, std::runtime_error>::value, "");
#endif
#if cl_ext_device_fission
    static_assert(std::is_same<clerror_stdexcept<status_t::device_partition_failed_ext>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_partition_count_ext>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_partition_name_ext>::type, std::invalid_argument>::value, "");
#endif
#if cl_khr_gl_sharing
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_gl_sharegroup_reference_khr>::type, std::invalid_argument>::value, "");
#endif
#if cl_khr_dx9_media_sharing
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_dx9_media_adapter_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_dx9_media_surface_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::dx9_media_surface_already_acquired_khr>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::dx9_media_surface_not_acquired_khr>::type, std::runtime_error>::value, "");
#endif
#if cl_khr_d3d10_sharing
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_d3d10_device_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_d3d10_resource_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::d3d10_resource_already_acquired_khr>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::d3d10_resource_not_acquired_khr>::type, std::runtime_error>::value, "");
#endif
#if cl_khr_d3d11_sharing
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_d3d11_device_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::invalid_d3d11_resource_khr>::type, std::invalid_argument>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::d3d11_resource_already_acquired_khr>::type, std::runtime_error>::value, "");
    static_assert(std::is_same<clerror_stdexcept<status_t::d3d11_resource_not_acquired_khr>::type, std::runtime_error>::value, "");
#endif
    TS_ASSERT(true);
  }
};

#endif /* CLXX_B5D_DETAIL_CLERROR_STDEXCEPT_T_H_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
