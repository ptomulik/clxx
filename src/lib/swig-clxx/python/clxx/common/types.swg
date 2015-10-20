// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: python/clxx/common/types.swg {{{
 * \file python/clxx/common/types.swg
 * \brief Python specific implementation of clxx/common/types.swg
 */ // }}}

// Rename some symbols
%rename(_global) clxx::device_local_mem_type_t::global;
%rename(_global) clxx::kernel_arg_address_qualifier_t::global;

%include <enums.swg>

// // Upstream swig's implementation of enum class is limited under Python.
// // Enum types are undistinguishable -- all enums are simply converted to
// // 'int'. The consequence is that method overloading doesn't work. The other
// // problem may be an integer overflow (consider enum class foo : bigint {}),
// // but I have no solution to this.
// %ignore clxx::boolval(addressing_mode_t);
// %ignore clxx::boolval(buffer_create_type_t);
// %ignore clxx::boolval(build_status_t);
// %ignore clxx::boolval(channel_order_t);
// %ignore clxx::boolval(channel_type_t);
// %ignore clxx::boolval(command_exec_status_t);
// %ignore clxx::boolval(command_queue_info_t);
// %ignore clxx::boolval(command_queue_properties_t);
// %ignore clxx::boolval(command_type_t);
// %ignore clxx::boolval(context_info_t);
// %ignore clxx::boolval(context_properties_t);
// %ignore clxx::boolval(device_affinity_domain_t);
// %ignore clxx::boolval(device_exec_capabilities_t);
// %ignore clxx::boolval(device_fp_config_t);
// %ignore clxx::boolval(device_info_t);
// %ignore clxx::boolval(device_local_mem_type_t);
// %ignore clxx::boolval(device_mem_cache_type_t);
// %ignore clxx::boolval(device_partition_property_t);
// %ignore clxx::boolval(device_type_t);
// %ignore clxx::boolval(event_info_t);
// %ignore clxx::boolval(filter_mode_t);
// %ignore clxx::boolval(image_info_t);
// %ignore clxx::boolval(kernel_arg_access_qualifier_t);
// %ignore clxx::boolval(kernel_arg_address_qualifier_t);
// %ignore clxx::boolval(kernel_arg_info_t);
// %ignore clxx::boolval(kernel_arg_type_qualifier_t);
// %ignore clxx::boolval(kernel_exec_info_t);
// %ignore clxx::boolval(kernel_info_t);
// %ignore clxx::boolval(kernel_work_group_info_t);
// %ignore clxx::boolval(map_flags_t);
// %ignore clxx::boolval(mem_flags_t);
// %ignore clxx::boolval(mem_info_t);
// %ignore clxx::boolval(mem_migration_flags_t);
// %ignore clxx::boolval(mem_object_type_t);
// %ignore clxx::boolval(platform_info_t);
// %ignore clxx::boolval(profiling_info_t);
// %ignore clxx::boolval(program_binary_type_t);
// %ignore clxx::boolval(program_build_info_t);
// %ignore clxx::boolval(program_info_t);
// %ignore clxx::boolval(sampler_info_t);
// %ignore clxx::intval(addressing_mode_t);
// %ignore clxx::intval(buffer_create_type_t);
// %ignore clxx::intval(build_status_t);
// %ignore clxx::intval(channel_order_t);
// %ignore clxx::intval(channel_type_t);
// %ignore clxx::intval(command_exec_status_t);
// %ignore clxx::intval(command_queue_info_t);
// %ignore clxx::intval(command_queue_properties_t);
// %ignore clxx::intval(command_type_t);
// %ignore clxx::intval(context_info_t);
// %ignore clxx::intval(context_properties_t);
// %ignore clxx::intval(device_affinity_domain_t);
// %ignore clxx::intval(device_exec_capabilities_t);
// %ignore clxx::intval(device_fp_config_t);
// %ignore clxx::intval(device_info_t);
// %ignore clxx::intval(device_local_mem_type_t);
// %ignore clxx::intval(device_mem_cache_type_t);
// %ignore clxx::intval(device_partition_property_t);
// %ignore clxx::intval(device_type_t);
// %ignore clxx::intval(event_info_t);
// %ignore clxx::intval(filter_mode_t);
// %ignore clxx::intval(image_info_t);
// %ignore clxx::intval(kernel_arg_access_qualifier_t);
// %ignore clxx::intval(kernel_arg_address_qualifier_t);
// %ignore clxx::intval(kernel_arg_info_t);
// %ignore clxx::intval(kernel_arg_type_qualifier_t);
// %ignore clxx::intval(kernel_exec_info_t);
// %ignore clxx::intval(kernel_info_t);
// %ignore clxx::intval(kernel_work_group_info_t);
// %ignore clxx::intval(map_flags_t);
// %ignore clxx::intval(mem_flags_t);
// %ignore clxx::intval(mem_info_t);
// %ignore clxx::intval(mem_migration_flags_t);
// %ignore clxx::intval(mem_object_type_t);
// %ignore clxx::intval(platform_info_t);
// %ignore clxx::intval(profiling_info_t);
// %ignore clxx::intval(program_binary_type_t);
// %ignore clxx::intval(program_build_info_t);
// %ignore clxx::intval(program_info_t);
// %ignore clxx::intval(sampler_info_t);
// %ignore clxx::is_error(build_status_t);
// %ignore clxx::is_error(command_exec_status_t);
// %ignore clxx::is_success(build_status_t);
// %ignore clxx::is_success(command_exec_status_t);
// %ignore clxx::operator !=(command_exec_status_t,status_t);
// %ignore clxx::operator &(command_queue_properties_t,command_queue_properties_t);
// %ignore clxx::operator &(device_affinity_domain_t,device_affinity_domain_t);
// %ignore clxx::operator &(device_exec_capabilities_t,device_exec_capabilities_t);
// %ignore clxx::operator &(device_fp_config_t,device_fp_config_t);
// %ignore clxx::operator &(kernel_arg_type_qualifier_t,kernel_arg_type_qualifier_t);
// %ignore clxx::operator &(map_flags_t,map_flags_t);
// %ignore clxx::operator &(mem_flags_t,mem_flags_t);
// %ignore clxx::operator &(mem_migration_flags_t,mem_migration_flags_t);
// %ignore clxx::operator &(program_binary_type_t,program_binary_type_t);
// %ignore clxx::operator <(command_exec_status_t,status_t);
// %ignore clxx::operator <=(command_exec_status_t,status_t);
// %ignore clxx::operator ==(command_exec_status_t,status_t);
// %ignore clxx::operator >(command_exec_status_t,status_t);
// %ignore clxx::operator >=(command_exec_status_t,status_t);
// %ignore clxx::operator ^(command_queue_properties_t,command_queue_properties_t);
// %ignore clxx::operator ^(device_affinity_domain_t,device_affinity_domain_t);
// %ignore clxx::operator ^(device_exec_capabilities_t,device_exec_capabilities_t);
// %ignore clxx::operator ^(device_fp_config_t,device_fp_config_t);
// %ignore clxx::operator ^(kernel_arg_type_qualifier_t,kernel_arg_type_qualifier_t);
// %ignore clxx::operator ^(map_flags_t,map_flags_t);
// %ignore clxx::operator ^(mem_flags_t,mem_flags_t);
// %ignore clxx::operator ^(mem_migration_flags_t,mem_migration_flags_t);
// %ignore clxx::operator ^(program_binary_type_t,program_binary_type_t);
// %ignore clxx::operator |(command_queue_properties_t,command_queue_properties_t);
// %ignore clxx::operator |(device_affinity_domain_t,device_affinity_domain_t);
// %ignore clxx::operator |(device_exec_capabilities_t,device_exec_capabilities_t);
// %ignore clxx::operator |(device_fp_config_t,device_fp_config_t);
// %ignore clxx::operator |(kernel_arg_type_qualifier_t,kernel_arg_type_qualifier_t);
// %ignore clxx::operator |(map_flags_t,map_flags_t);
// %ignore clxx::operator |(mem_flags_t,mem_flags_t);
// %ignore clxx::operator |(mem_migration_flags_t,mem_migration_flags_t);
// %ignore clxx::operator |(program_binary_type_t,program_binary_type_t);
// %ignore clxx::operator ~(command_queue_properties_t);
// %ignore clxx::operator ~(device_affinity_domain_t);
// %ignore clxx::operator ~(device_exec_capabilities_t);
// %ignore clxx::operator ~(device_fp_config_t);
// %ignore clxx::operator ~(kernel_arg_type_qualifier_t);
// %ignore clxx::operator ~(map_flags_t);
// %ignore clxx::operator ~(mem_flags_t);
// %ignore clxx::operator ~(mem_migration_flags_t);
// %ignore clxx::operator ~(program_binary_type_t);

%include <clxx/common/types.li.swg>

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
