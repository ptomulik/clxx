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

// clxx/io/types.hpp

/** // doc: clxx/io/types.hpp {{{
 * @file clxx/io/types.hpp
 * @todo Write documentation
 */ // }}}
#ifndef CLXX_IO_TYPES_HPP_INCLUDED
#define CLXX_IO_TYPES_HPP_INCLUDED

#include <clxx/types.hpp>
#include <iosfwd>

/** // doc: operator << (os, status_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::status_t x);
/** // doc: operator << (os, platform_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::platform_info_t x);
/** // doc: operator << (os, device_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_type_t x);
/** // doc: operator << (os, device_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_info_t x);
/** // doc: operator << (os, device_fp_config_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_fp_config_t x);
/** // doc: operator << (os, device_mem_cache_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_mem_cache_type_t x);
/** // doc: operator << (os, device_local_mem_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_local_mem_type_t x);
/** // doc: operator << (os, device_exec_capabilities_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_exec_capabilities_t x);
/** // doc: operator << (os, command_queue_properties_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_properties_t x);
/** // doc: operator << (os, context_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_info_t x);
/** // doc: operator << (os, context_properties_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::context_properties_t x);
#if CL_VERSION_1_2
/** // doc: operator << (os, device_partition_property_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_partition_property_t x);
#endif
#if CL_VERSION_1_2
/** // doc: operator << (os, device_affinity_domain_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::device_affinity_domain_t x);
#endif
/** // doc: operator << (os, command_queue_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_queue_info_t x);
/** // doc: operator << (os, mem_flags_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_flags_t x);
#if CL_VERSION_1_2
/** // doc: operator << (os, mem_migration_flags_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_migration_flags_t x);
#endif
/** // doc: operator << (os, channel_order_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_order_t x);
/** // doc: operator << (os, channel_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::channel_type_t x);
/** // doc: operator << (os, mem_object_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_object_type_t x);
/** // doc: operator << (os, mem_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::mem_info_t x);
/** // doc: operator << (os, image_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::image_info_t x);
/** // doc: operator << (os, addressing_mode_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::addressing_mode_t x);
/** // doc: operator << (os, filter_mode_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::filter_mode_t x);
/** // doc: operator << (os, sampler_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::sampler_info_t x);
/** // doc: operator << (os, map_flags_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::map_flags_t x);
/** // doc: operator << (os, program_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_info_t x);
/** // doc: operator << (os, program_build_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_build_info_t x);
#if CL_VERSION_1_2
/** // doc: operator << (os, program_binary_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::program_binary_type_t x);
#endif
/** // doc: operator << (os, build_status_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::build_status_t x);
/** // doc: operator << (os, kernel_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_info_t x);
#if CL_VERSION_1_2
/** // doc: operator << (os, kernel_arg_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_info_t x);
#endif
#if CL_VERSION_1_2
/** // doc: operator << (os, kernel_arg_address_qualifier_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_address_qualifier_t x);
#endif
#if CL_VERSION_1_2
/** // doc: operator << (os, kernel_arg_access_qualifier_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_access_qualifier_t x);
#endif
#if CL_VERSION_1_2
/** // doc: operator << (os, kernel_arg_type_qualifier_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_arg_type_qualifier_t x);
#endif
/** // doc: operator << (os, kernel_work_group_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::kernel_work_group_info_t x);
/** // doc: operator << (os, event_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::event_info_t x);
/** // doc: operator << (os, command_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_type_t x);
/** // doc: operator << (os, command_exec_status_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::command_exec_status_t x);
#if CL_VERSION_1_1
/** // doc: operator << (os, buffer_create_type_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::buffer_create_type_t x);
#endif
/** // doc: operator << (os, profiling_info_t) {{{ 
 * \todo Write documentation
 */ // }}}
template <typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator<< (std::basic_ostream<_CharT, _Traits>& os, clxx::profiling_info_t x);

#endif /* CLXX_IO_TYPES_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
