// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/mem.cpp {{{
 * \file clxx/mem.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/mem.hpp>
#include <clxx/context.hpp>
//#include <clxx/functions.hpp>
//#include <clxx/exceptions.hpp>
#include <clxx/clobj_impl.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
mem::
mem(context const& ctx, mem_flags_t flags, size_t size, void* host_ptr)
  :Base((cl_mem)NULL) // because it's read by _set_handle()
{
  this->_set_handle(create_buffer(ctx.get_valid_handle(), flags, size, host_ptr), false, false);
}
/* ----------------------------------------------------------------------- */
mem_object_type_t mem::
get_type() const
{
  return _get_pod_info<mem_object_type_t>(*this, mem_info_t::type);
}
/* ----------------------------------------------------------------------- */
mem_flags_t mem::
get_flags() const
{
  return _get_pod_info<mem_flags_t>(*this, mem_info_t::flags);
}
/* ----------------------------------------------------------------------- */
size_t mem::
get_size() const
{
  return _get_pod_info<size_t>(*this, mem_info_t::size);
}
/* ----------------------------------------------------------------------- */
void* mem::
get_host_ptr() const
{
  return _get_pod_info<void*>(*this, mem_info_t::host_ptr);
}
/* ----------------------------------------------------------------------- */
cl_uint mem::
get_map_count() const
{
  return _get_pod_info<cl_uint>(*this, mem_info_t::map_count);
}
/* ----------------------------------------------------------------------- */
cl_uint mem::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, mem_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
context mem::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, mem_info_t::context));
}
/* ----------------------------------------------------------------------- */
mem mem::
get_associated_memobject() const
{
  return mem(_get_pod_info<cl_mem>(*this, mem_info_t::associated_memobject));
}
/* ----------------------------------------------------------------------- */
size_t mem::
get_offset() const
{
  return _get_pod_info<size_t>(*this, mem_info_t::offset);
}
/* ----------------------------------------------------------------------- */
#if CLXX_CL_H_VERSION_2_0
cl_bool mem::
get_uses_svm_pointer() const
{
  return _get_pod_info<cl_bool>(*this, mem_info_t::uses_svm_pointer);
}
#endif
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
