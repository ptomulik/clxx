// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/kernel.cpp {{{
 * \file clxx/kernel.cpp
 * \brief Implements the \ref clxx::kernel "kernel" class
 */ // }}}
#include <clxx/kernel.hpp>
#include <clxx/program.hpp>
#include <clxx/context.hpp>
#include <clxx/device.hpp>
#include <clxx/util/obj2cl.hpp>
#include <clxx/clobj_impl.hpp>
#include <memory>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_arg_pod_info(kernel const& p, cl_uint arg_index, kernel_arg_info_t name)
{
  T value;
  p.get_arg_info(arg_index, name, sizeof(value), &value, NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
static std::string
_get_arg_str_info(kernel const& p, cl_uint arg_index, kernel_arg_info_t name)
{
  size_t size;
  p.get_arg_info(arg_index, name, 0, NULL, &size);

  std::unique_ptr<char[]> str(new char[size]);
  // FIXME: is(str == nullptr) { throw clxx::bad_alloc() }
  p.get_arg_info(arg_index, name, size, str.get(), &size);
  return std::string(str.get());
}
/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_work_group_pod_info(kernel const& p, device const& dev, kernel_work_group_info_t name)
{
  T value;
  p.get_work_group_info(dev, name, sizeof(value), &value, NULL);
  return value;
}
/* ----------------------------------------------------------------------- */
kernel::
kernel(program const& prog, std::string const& name)
  :Base((cl_kernel)NULL) // because it's readby _set_handle()
{
  cl_kernel id = create_kernel(prog.get_valid_handle(), name.data());
  // create_kernel() performs implicit retain, so we
  // don't have to retain it again here (thus 2 x false below)
  this->_set_handle(id, false, false);
}
/* ----------------------------------------------------------------------- */
cl_uint kernel::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, kernel_info_t::reference_count);
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_function_name() const
{
  return _get_str_info(*this, kernel_info_t::function_name);
}
/* ----------------------------------------------------------------------- */
cl_uint kernel::
get_num_args() const
{
  return _get_pod_info<cl_uint>(*this, kernel_info_t::num_args);
}
/* ----------------------------------------------------------------------- */
context kernel::
get_context() const
{
  return context(_get_pod_info<cl_context>(*this, kernel_info_t::context));
}
/* ----------------------------------------------------------------------- */
program kernel::
get_program() const
{
  return program(_get_pod_info<cl_program>(*this, kernel_info_t::program));
}
#if CLXX_CL_H_VERSION_1_2
/* ----------------------------------------------------------------------- */
std::string kernel::
get_attributes() const
{
  return _get_str_info(*this, kernel_info_t::attributes);
}
#endif
#if CLXX_OPENCL_ALLOWED(clGetKernelArgInfo)
/* ----------------------------------------------------------------------- */
void kernel::
get_arg_info(cl_uint arg_index, kernel_arg_info_t name, size_t value_size,
             void* value, size_t* value_size_ret) const
{
  get_kernel_arg_info(this->get_valid_handle(),
                      arg_index,
                      name,
                      value_size,
                      value,
                      value_size_ret);
}
/* ----------------------------------------------------------------------- */
kernel_arg_address_qualifier_t kernel::
get_arg_address_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_address_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::address_qualifier
         );
}
/* ----------------------------------------------------------------------- */
kernel_arg_access_qualifier_t kernel::
get_arg_access_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_access_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::access_qualifier
         );
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_arg_type_name(cl_uint arg_index) const
{
  return _get_arg_str_info(*this, arg_index, kernel_arg_info_t::type_name);
}
/* ----------------------------------------------------------------------- */
kernel_arg_type_qualifier_t kernel::
get_arg_type_qualifier(cl_uint arg_index) const
{
  return _get_arg_pod_info<kernel_arg_type_qualifier_t>(
            *this,
            arg_index,
            kernel_arg_info_t::type_qualifier
         );
}
/* ----------------------------------------------------------------------- */
std::string kernel::
get_arg_name(cl_uint arg_index) const
{
  return _get_arg_str_info(*this, arg_index, kernel_arg_info_t::name);
}
/* ----------------------------------------------------------------------- */
#endif
void kernel::
get_work_group_info(device const& dev, kernel_work_group_info_t name,
                    size_t value_size, void* value, size_t* value_size_ret) const
{
  // note: NULL is allowed for device ID, see clGetKernelWorkGroupInfo()
  get_kernel_work_group_info(
      this->get_valid_handle(),
      dev.handle(),
      name,
      value_size,
      value,
      value_size_ret
  );
}
/* ----------------------------------------------------------------------- */
size_t kernel::
get_work_group_size(device const& dev) const
{
  return _get_work_group_pod_info<size_t>(
            *this,
            dev,
            kernel_work_group_info_t::work_group_size
         );
}
/* ----------------------------------------------------------------------- */
void kernel::
get_compile_work_group_size(size_t* result, device const& dev) const
{
  get_work_group_info(dev, kernel_work_group_info_t::compile_work_group_size,
                      3*sizeof(size_t), result, nullptr);
}
/* ----------------------------------------------------------------------- */
cl_ulong kernel::
get_local_mem_size(device const& dev) const
{
  return _get_work_group_pod_info<cl_ulong>(*this, dev,
            kernel_work_group_info_t::local_mem_size
         );
}
#if CLXX_CL_H_VERSION_1_1
/* ----------------------------------------------------------------------- */
size_t kernel::
get_preferred_work_group_size_multiple(device const& dev) const
{
  return _get_work_group_pod_info<size_t>(*this, dev,
            kernel_work_group_info_t::preferred_work_group_size_multiple
         );
}
/* ----------------------------------------------------------------------- */
cl_ulong kernel::
get_private_mem_size(device const& dev) const
{
  return _get_work_group_pod_info<cl_ulong>(*this, dev,
            kernel_work_group_info_t::private_mem_size
         );
}
#endif
#if CLXX_CL_H_VERSION_1_2
/* ----------------------------------------------------------------------- */
void kernel::
get_global_work_size(size_t* result, device const& dev) const
{
  get_work_group_info(dev, kernel_work_group_info_t::global_work_size,
                      3*sizeof(size_t), result, nullptr);
}
#endif
/* ----------------------------------------------------------------------- */
void kernel::
set_arg(cl_uint arg_index, size_t size, const void* arg_value) const
{
  set_kernel_arg(this->get_valid_handle(), arg_index, size, arg_value);
}
/* ----------------------------------------------------------------------- */
void kernel::
set_arg(cl_uint arg_index, clxx::mem const& mem) const
{
  set_kernel_arg(this->get_valid_handle(), arg_index, sizeof(cl_mem), obj2cl(&mem));
}
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelArgSVMPointer)
void kernel::
set_arg_svm_pointer(cl_uint arg_index, const void* arg_value) const
{
  set_kernel_arg_svm_pointer(this->get_valid_handle(), arg_index, arg_value);
}
#endif
/* ----------------------------------------------------------------------- */
#if CLXX_OPENCL_ALLOWED(clSetKernelExecInfo)
void kernel::
set_exec_info(kernel_exec_info_t name, size_t value_size, const void* value) const
{
  set_kernel_exec_info(
      this->get_valid_handle(),
      name,
      value_size,
      value
  );
}
#endif
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
