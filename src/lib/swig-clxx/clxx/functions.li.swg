// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/functions.li.swg {{{
 * \file clxx/functions.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/functions.hpp>
%}

%include <clxx/exception_support.swg>

%throws_clerror(clxx::get_platform_ids(cl_uint, cl_platform_id *, cl_uint *));
%throws_clerror(clxx::get_platform_info(cl_platform_id, platform_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::get_device_ids(cl_platform_id, device_type_t, cl_uint, cl_device_id *, cl_uint *));
%throws_clerror(clxx::get_device_info(cl_device_id, device_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::create_context(const cl_context_properties *, cl_uint, const cl_device_id *, void(*)(const char *, const void *,size_t, void *), void *));
%throws_clerror(clxx::create_context_from_type(const cl_context_properties *, device_type_t, void(*)(const char *, const void *, size_t, void *), void *));
%throws_clerror(clxx::retain_context(cl_context));
%throws_clerror(clxx::release_context(cl_context));
%throws_clerror(clxx::get_context_info(cl_context, context_info_t, size_t, void *, size_t *));
%throws_clerror(clxx::create_sub_devices(cl_device_id, const cl_device_partition_property *, cl_uint, cl_device_id *, cl_uint *));
%throws_clerror(clxx::retain_device(cl_device_id));
%throws_clerror(clxx::release_device(cl_device_id));

%include <clxx/functions.hpp>


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
