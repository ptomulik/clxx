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

/** // doc: clxx/context.cpp {{{
 * \file clxx/context.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/context.hpp>
#include <clxx/functions.hpp>
#include <clxx/exceptions.hpp>
#include <vector>

namespace clxx {

/* ------------------------------------------------------------------------ */
template<typename T> static T
_get_pod_info(context const& ctx, context_info_t name)
{
  T value;
  ctx.get_info(name,sizeof(value),&value,NULL);
  return value;
}
/* ------------------------------------------------------------------------ */
template<typename T> static std::vector<T>
_get_vec_info(context const& ctx, context_info_t name)
{
  size_t size;
  ctx.get_info(name,0,NULL,&size);
  std::vector<T> values(size/sizeof(T));
  ctx.get_info(name,values.size()*sizeof(T),&values.front(),NULL);
  return values;
}
/* ------------------------------------------------------------------------ */
void context::
_set_id(cl_context ctx, bool retain_new, bool release_old)
{
  if(ctx != this->_ctx) // Avoid unintended deletion by clReleaseContext()
    {
      if(release_old)
        {
          release_context(this->get_valid_ctx());
        }
      this->_ctx = ctx;
      if(retain_new)
        {
          retain_context(this->_ctx);
        }
    }
}
/* ------------------------------------------------------------------------ */
context::
context(cl_context ctx)
{
  this->_set_id(ctx, true, false);
}
/* ------------------------------------------------------------------------ */
context::
context(context_properties const& props, devices const& devs,
        void(*pfn_notify)(const char*, const void*, size_t, void*),
        void* user_data)
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  const size_t devs_n = devs.size();
  std::vector<cl_device_id> dev_ids(devs_n);
  for(size_t i = 0; i < devs_n; dev_ids[i] = devs[i].id(), ++i) { }
  cl_context ctx = create_context(&props_v.front(), devs_n, &dev_ids.front(),
                                  pfn_notify, user_data);
  this->_set_id(ctx, false, false);
}
/* ------------------------------------------------------------------------ */
context::
context(const context_properties& props,
        device_type_t dev_type,
        void(*pfn_notify)(const char*, const void*, size_t, void*),
        void* user_data)
{
  const size_t props_n = context_properties_array_size(props);
  std::vector<cl_context_properties> props_v(props_n);
  context_properties_fill_array(props, &props_v.front(), props_n);
  cl_context ctx = create_context_from_type(&props_v.front(), dev_type,
                                            pfn_notify, user_data);
  this->_set_id(ctx, false, false);
}
/* ------------------------------------------------------------------------ */
context::
context(const context& rhs)
{
  this->_set_id(rhs.get_valid_ctx(), true, false);
}
/* ------------------------------------------------------------------------ */
context::
~context() noexcept
{
  if(this->is_initialized())
    {
      try { this->_set_id(NULL, false, true); }
      catch(clerror_no<status_t::invalid_context> const& ){ }
      // NOTE: _set_id() also throws uninitialized_context_error but it
      // shouldn't happen here (we have checked, that context is initialized);
      // if it happens anyway, then there is a bug somewhere.
    }
}
/* ------------------------------------------------------------------------ */
void context::
get_info(context_info_t name, size_t value_size, void* value,
         size_t* value_size_ret) const
{
  get_context_info(this->get_valid_ctx(), name, value_size, value, value_size_ret);
}
/* ------------------------------------------------------------------------ */
cl_context context::
ctx() const noexcept
{
  return this->_ctx;
}
/* ------------------------------------------------------------------------ */
cl_context context::
get_valid_ctx() const
{
  if(!this->is_initialized())
    {
      throw uninitialized_context_error();
    }
  return this->_ctx;
}
/* ------------------------------------------------------------------------ */
context& context::
operator=(context const& rhs)
{
  this->assign(rhs);
  return *this;
}
/* ------------------------------------------------------------------------ */
bool context::
operator == (context const& rhs) const noexcept
{
  return this->_ctx == rhs._ctx;
}
/* ------------------------------------------------------------------------ */
bool context::
operator != (context const& rhs) const noexcept
{
  return ! (*this == rhs);
}
/* ------------------------------------------------------------------------ */
void context::
assign(context const& rhs)
{
  if(&rhs != this)
    {
      this->_set_id(rhs.get_valid_ctx(), true, true);
    }
}
/* ------------------------------------------------------------------------ */
cl_uint context::
get_reference_count() const
{
  return _get_pod_info<cl_uint>(*this, context_info_t::reference_count);
}
/* ------------------------------------------------------------------------ */
cl_uint context::
get_num_devices() const
{
  return _get_pod_info<cl_uint>(*this, context_info_t::num_devices);
}
/* ------------------------------------------------------------------------ */
devices context::
get_devices() const
{
  typedef cl_device_id T;
  std::vector<T> devs(_get_vec_info<T>(*this, context_info_t::devices));
  return devices(devs.begin(), devs.end());
}
/* ------------------------------------------------------------------------ */
context_properties context::
get_properties() const
{
  typedef cl_context_properties T;
  std::vector<T> cl_props(_get_vec_info<T>(*this, context_info_t::properties));
  context_properties props;
  context_properties_parse_array(props, &cl_props.front());
  return props;
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
