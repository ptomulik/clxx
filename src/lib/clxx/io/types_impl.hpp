// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/io/types_impl.hpp

#ifndef CLXX_IO_TYPES_IMPL
#define CLXX_IO_TYPES_IMPL

/** // doc: clxx/io/types_impl.hpp {{{
 * \file clxx/io/types_impl.hpp
 * \brief Implements I/O routines for types defined in clxx/common/types.hpp
 */ // }}}
#include <clxx/io/types.hpp>
#include <clxx/util/to_string.hpp>

template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::status_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::platform_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_fp_config_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_mem_cache_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_local_mem_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_exec_capabilities_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_properties_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_properties_t x)
{
  os << std::to_string(x);
  return os;
}
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_partition_property_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_affinity_domain_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_flags_t x)
{
  os << std::to_string(x);
  return os;
}
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_migration_flags_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_order_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_object_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::image_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::addressing_mode_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::filter_mode_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::sampler_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::map_flags_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_build_info_t x)
{
  os << std::to_string(x);
  return os;
}
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_binary_type_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::build_status_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_info_t x)
{
  os << std::to_string(x);
  return os;
}
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_info_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_address_qualifier_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_access_qualifier_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
#if CLXX_CL_H_VERSION_1_2
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_type_qualifier_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_work_group_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::event_info_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_type_t x)
{
  os << std::to_string(x);
  return os;
}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_exec_status_t x)
{
  os << std::to_string(x);
  return os;
}
#if CLXX_CL_H_VERSION_1_1
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::buffer_create_type_t x)
{
  os << std::to_string(x);
  return os;
}
#endif
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::profiling_info_t x)
{
  os << std::to_string(x);
  return os;
}

#endif /* CLXX_IO_TYPES_IMPL */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
