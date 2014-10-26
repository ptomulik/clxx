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

/** // doc: clxx/types_mod.i {{{
 * \file clxx/types_mod.i
 * \todo Write documentation
 */ // }}}

%module (package="clxx_") types_mod
%feature("autodoc","3");

// All the following lines are a part of the enum class workaround.
%rename(status_t) clxx::status_t_;
%rename(platform_info_t) clxx::platform_info_t_;
%rename(device_type_t) clxx::device_type_t_;
%rename(device_info_t) clxx::device_info_t_;
%rename(device_fp_config_t) clxx::device_fp_config_t_;
%rename(device_mem_cache_type_t) clxx::device_mem_cache_type_t_;
%rename(device_local_mem_type_t) clxx::device_local_mem_type_t_;
%rename(device_exec_capabilities_t) clxx::device_exec_capabilities_t_;
%rename(command_queue_properties_t) clxx::command_queue_properties_t_;
%rename(context_info_t) clxx::context_info_t_;
%rename(context_properties_t) clxx::context_properties_t_;
%rename(device_partition_property_t) clxx::device_partition_property_t_;
%rename(device_affinity_domain_t) clxx::device_affinity_domain_t_;
%rename(command_queue_info_t) clxx::command_queue_info_t_;
%rename(mem_flags_t) clxx::mem_flags_t_;
%rename(mem_migration_flags_t) clxx::mem_migration_flags_t_;
%rename(channel_order_t) clxx::channel_order_t_;
%rename(channel_type_t) clxx::channel_type_t_;
%rename(mem_object_type_t) clxx::mem_object_type_t_;
%rename(mem_info_t) clxx::mem_info_t_;
%rename(image_info_t) clxx::image_info_t_;
%rename(addressing_mode_t) clxx::addressing_mode_t_;
%rename(filter_mode_t) clxx::filter_mode_t_;
%rename(sampler_info_t) clxx::sampler_info_t_;
%rename(map_flags_t) clxx::map_flags_t_;
%rename(program_info_t) clxx::program_info_t_;
%rename(program_build_info_t) clxx::program_build_info_t_;
%rename(program_binary_type_t) clxx::program_binary_type_t_;
%rename(build_status_t) clxx::build_status_t_;
%rename(kernel_info_t) clxx::kernel_info_t_;
%rename(kernel_arg_info_t) clxx::kernel_arg_info_t_;
%rename(kernel_arg_address_qualifier_t) clxx::kernel_arg_address_qualifier_t_;
%rename(kernel_arg_access_qualifier_t) clxx::kernel_arg_access_qualifier_t_;
%rename(kernel_arg_type_qualifier_t) clxx::kernel_arg_type_qualifier_t_;
%rename(kernel_work_group_info_t) clxx::kernel_work_group_info_t_;
%rename(event_info_t) clxx::event_info_t_;
%rename(command_type_t) clxx::command_type_t_;
%rename(command_exec_status_t) clxx::command_exec_status_t_;
%rename(buffer_create_type_t) clxx::buffer_create_type_t_;
%rename(profiling_info_t) clxx::profiling_info_t_;

//%rename(value) clxx::status_t_::operator enum_type;
//%rename(value) clxx::platform_info_t_::operator enum_type;
//%rename(value) clxx::device_type_t_::operator enum_type;
//%rename(value) clxx::device_info_t_::operator enum_type;
//%rename(value) clxx::device_fp_config_t_::operator enum_type;
//%rename(value) clxx::device_mem_cache_type_t_::operator enum_type;
//%rename(value) clxx::device_local_mem_type_t_::operator enum_type;
//%rename(value) clxx::device_exec_capabilities_t_::operator enum_type;
//%rename(value) clxx::command_queue_properties_t_::operator enum_type;
//%rename(value) clxx::context_info_t_::operator enum_type;
//%rename(value) clxx::context_properties_t_::operator enum_type;
//%rename(value) clxx::device_partition_property_t_::operator enum_type;
//%rename(value) clxx::device_affinity_domain_t_::operator enum_type;
//%rename(value) clxx::command_queue_info_t_::operator enum_type;
//%rename(value) clxx::mem_flags_t_::operator enum_type;
//%rename(value) clxx::mem_migration_flags_t_::operator enum_type;
//%rename(value) clxx::channel_order_t_::operator enum_type;
//%rename(value) clxx::channel_type_t_::operator enum_type;
//%rename(value) clxx::mem_object_type_t_::operator enum_type;
//%rename(value) clxx::mem_info_t_::operator enum_type;
//%rename(value) clxx::image_info_t_::operator enum_type;
//%rename(value) clxx::addressing_mode_t_::operator enum_type;
//%rename(value) clxx::filter_mode_t_::operator enum_type;
//%rename(value) clxx::sampler_info_t_::operator enum_type;
//%rename(value) clxx::map_flags_t_::operator enum_type;
//%rename(value) clxx::program_info_t_::operator enum_type;
//%rename(value) clxx::program_build_info_t_::operator enum_type;
//%rename(value) clxx::program_binary_type_t_::operator enum_type;
//%rename(value) clxx::build_status_t_::operator enum_type;
//%rename(value) clxx::kernel_info_t_::operator enum_type;
//%rename(value) clxx::kernel_arg_info_t_::operator enum_type;
//%rename(value) clxx::kernel_arg_address_qualifier_t_::operator enum_type;
//%rename(value) clxx::kernel_arg_access_qualifier_t_::operator enum_type;
//%rename(value) clxx::kernel_arg_type_qualifier_t_::operator enum_type;
//%rename(value) clxx::kernel_work_group_info_t_::operator enum_type;
//%rename(value) clxx::event_info_t_::operator enum_type;
//%rename(value) clxx::command_type_t_::operator enum_type;
//%rename(value) clxx::command_exec_status_t_::operator enum_type;
//%rename(value) clxx::buffer_create_type_t_::operator enum_type;
//%rename(value) clxx::profiling_info_t_::operator enum_type;

#define CLXX_SWIG_NO_CLASS_ENUM_BOOLVAL 1
#define CLXX_SWIG_NO_CLASS_ENUM_INTVAL 1
#define CLXX_SWIG_NO_CLASS_ENUM_BITOPS 1
#define CLXX_SWIG_NO_CLASS_ENUM_CMPOPS 1

%include <clxx/types_mod.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
