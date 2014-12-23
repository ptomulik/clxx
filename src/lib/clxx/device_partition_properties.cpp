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
/** // doc: clxx/device_partition_properties.cpp {{{
 * \file clxx/device_partition_properties.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/device_partition_properties.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
size_t
device_partition_properties_array_size(const device_partition_properties& props)
{
  typedef device_partition_properties::const_iterator iter;
  size_t size = 1; // one entry for trailing zero
  for(iter p = props.begin(); p != props.end(); size += p->size(), ++p) {}
  return size;
}
/* ----------------------------------------------------------------------- */
size_t
device_partition_properties_fill_array(const device_partition_properties& props,
                              cl_device_partition_property* array,
                              size_t size)
{
  typedef device_partition_properties::const_iterator iter;

  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = device_partition_properties_array_size(props);
  if(size < count)
    throw not_enough_space_error();

  for(iter p = props.begin(); p != props.end(); ++p)
    {
      array += p->write(array);
    }
  *array = (cl_device_partition_property)0ul;

  return count;
}
/* ----------------------------------------------------------------------- */
size_t
device_partition_properties_parse_array(device_partition_properties& props,
                               const cl_device_partition_property* array)
{
  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = 0;
  device_partition_property prop;
  for(;array[count] != (cl_device_partition_property)0; count+=prop.size())
    {
      prop.read(array + count);
      props.push_back(prop);
    }
  return count;
}
/* ----------------------------------------------------------------------- */
device_partition_properties
operator& (device_partition_property const& left, device_partition_property const& right)
{
  device_partition_properties cp;
  cp.push_back(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
device_partition_properties
operator& (device_partition_properties const& left, device_partition_property const& right)
{
  device_partition_properties cp(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
device_partition_properties
operator& (device_partition_property const& left, device_partition_properties const& right)
{
  device_partition_properties cp;
  cp.push_back(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
device_partition_properties
operator& (device_partition_properties const& left, device_partition_properties const& right)
{
  device_partition_properties cp(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: