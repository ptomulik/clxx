// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/clobj_impl.hpp

/** // doc: clxx/clobj_impl.hpp {{{
 * \file clxx/clobj_impl.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_CLOBJ_IMPL_HPP_INCLUDED
#define CLXX_CLOBJ_IMPL_HPP_INCLUDED

#include <clxx/clobj.hpp>
#include <clxx/clobj_fcn.hpp>
#include <vector>
#include <string>
#include <memory>

namespace clxx {
/* ----------------------------------------------------------------------- */
template< typename Handle > std::string
_get_str_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  size_t size;
  obj.get_info(name, 0, NULL, &size);

  std::unique_ptr<char[]> str(new char[size]);
  obj.get_info(name, size, str.get(), &size);
  return std::string(str.get());
}

/* ----------------------------------------------------------------------- */
template<typename T, typename Handle> T
_get_pod_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  T value;
  obj.get_info(name, sizeof(value), &value, NULL);
  return value;
}

/* ----------------------------------------------------------------------- */
template<typename T, typename Handle> std::vector<T>
_get_vec_info(clobj<Handle> const& obj, typename clobj<Handle>::info_t name)
{
  size_t size;
  obj.get_info(name, 0, NULL, &size);
  std::vector<T> values(size/sizeof(T));
  obj.get_info(name, values.size() * sizeof(T), &values.front(), NULL);
  return values;
}
} // end namespace clxx

namespace clxx {
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
_set_handle(handle_t h, bool retain_new, bool release_old)
{
  if(h != this->_handle) // Avoid unintended deletion by release_clobj()
    {
      if(release_old && this->is_initialized())
        {
          release_clobj(this->_handle);
        }
      this->_handle = h;
      if(retain_new)
        {
          retain_clobj(this->_handle);
        }
    }
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj() noexcept
  :_handle((handle_t)NULL)
{
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj(handle_t h)
  :_handle((handle_t)NULL) // because it's read by _set_handle
{
  this->_set_handle(h, true, false);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
clobj(clobj const& other)
  :_handle((handle_t)NULL) // because it's read by _set_handle
{
  this->_set_handle(other.handle(), true, false);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>::
~clobj()
{
  if(this->is_initialized())
    {
      try { this->_set_handle((handle_t)NULL, false, true); }
      catch(clerror_no<invalid_clobj_error<Handle>::value> const&) { }
    }
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
is_initialized() const noexcept
{
  return this->handle() != (handle_t)NULL;
}
/* ----------------------------------------------------------------------- */
template< typename Handle>
Handle clobj<Handle>::
handle() const noexcept
{
  return this->_handle;
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
Handle clobj<Handle>::
get_valid_handle() const
{
  if(!this->is_initialized())
    throw typename uninitialized_clobj_error<Handle>::type();
  return this->_handle;
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
get_info(info_t name, size_t value_size, void* value, size_t* value_size_ret) const
{
  get_clobj_info(this->get_valid_handle(), name, value_size, value, value_size_ret);
}
/* ----------------------------------------------------------------------- */
template< typename Handle >
clobj<Handle>& clobj<Handle>::
operator=(clobj const& rhs)
{ this->assign(rhs); return *this; }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator == (clobj const& rhs) const noexcept
{ return this->handle() == rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator != (clobj const& rhs) const noexcept
{ return this->handle() != rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator < (clobj const& rhs) const noexcept
{ return this->handle() < rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator > (clobj const& rhs) const noexcept
{ return this->handle() > rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator <= (clobj const& rhs) const noexcept
{ return this->handle() <= rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
bool clobj<Handle>::
operator >= (clobj const& rhs) const noexcept
{ return this->handle() >= rhs.handle(); }
/* ----------------------------------------------------------------------- */
template< typename Handle >
void clobj<Handle>::
assign(clobj const& rhs)
{
  if(&rhs != this)
    this->_set_handle(rhs.get_valid_handle(), true, true);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

#endif /* CLXX_CLOBJ_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
