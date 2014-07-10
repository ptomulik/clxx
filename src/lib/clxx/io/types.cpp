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

// clxx/io/types.cpp

/** // doc: clxx/io/types.cpp {{{
 * @file clxx/io/types.cpp
 * @todo Write documentation
 */ // }}}
#include <ostream>
#include <string>

template<typename _Traits>
static std::basic_ostream<wchar_t, _Traits>&
operator << ( std::basic_ostream<wchar_t, _Traits>& os
            , std::string const& s)
{
  return os << s.c_str();
}

#include <clxx/io/types_impl.hpp>

//
// Instantiations for char
//
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::status_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::platform_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_fp_config_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_mem_cache_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_local_mem_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_exec_capabilities_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_queue_properties_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::context_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::context_properties_t);
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_partition_property_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::device_affinity_domain_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_queue_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_flags_t);
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_migration_flags_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::channel_order_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::channel_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_object_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::mem_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::image_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::addressing_mode_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::filter_mode_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::sampler_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::map_flags_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_build_info_t);
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::program_binary_type_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::build_status_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_info_t);
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_info_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_address_qualifier_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_access_qualifier_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_arg_type_qualifier_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::kernel_work_group_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::event_info_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_type_t);
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::command_exec_status_t);
#if CL_VERSION_1_1
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::buffer_create_type_t);
#endif
template std::basic_ostream<char>&
operator<< (std::basic_ostream<char>&, clxx::profiling_info_t);

//
// Instantiations for wchar_t
//
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::status_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::platform_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_fp_config_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_mem_cache_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_local_mem_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_exec_capabilities_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_queue_properties_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::context_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::context_properties_t);
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_partition_property_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::device_affinity_domain_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_queue_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_flags_t);
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_migration_flags_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::channel_order_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::channel_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_object_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::mem_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::image_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::addressing_mode_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::filter_mode_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::sampler_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::map_flags_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_build_info_t);
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::program_binary_type_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::build_status_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_info_t);
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_info_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_address_qualifier_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_access_qualifier_t);
#endif
#if CL_VERSION_1_2
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_arg_type_qualifier_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::kernel_work_group_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::event_info_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_type_t);
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::command_exec_status_t);
#if CL_VERSION_1_1
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::buffer_create_type_t);
#endif
template std::basic_ostream<wchar_t>&
operator<< (std::basic_ostream<wchar_t>&, clxx::profiling_info_t);

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
