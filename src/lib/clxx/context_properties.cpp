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
/** // doc: clxx/context_properties.cpp {{{
 * \file clxx/context_properties.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/context_properties.hpp>
#include <clxx/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
size_t
context_properties_array_size(const context_properties& props)
{
  typedef context_properties::const_iterator iter;
  size_t size = 1; // one entry for trailing zero
  for(iter p = props.begin(); p != props.end(); size += p->size(), ++p) {}
  return size;
}
/* ----------------------------------------------------------------------- */
size_t
context_properties_fill_array(const context_properties& props,
                              cl_context_properties* array,
                              size_t size)
{
  typedef context_properties::const_iterator iter;

  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = context_properties_array_size(props);
  if(size < count)
    throw not_enough_space_error();

  for(iter p = props.begin(); p != props.end(); ++p)
    {
      p->write(array);
      array += p->size();
    }
  *array = (cl_context_properties)0ul;

  return count;
}
/* ----------------------------------------------------------------------- */
size_t
context_properties_parse_array(context_properties& props,
                               const cl_context_properties* array)
{
  if(array == nullptr)
    throw invalid_argument_error();

  size_t count = 0;
  for(;array[count] != (cl_context_properties)0; count+=2)
    {
      props.push_back(context_property(array[count],array[count+1]));
    }
  return count;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_property const& left, context_property const& right)
{
  context_properties cp;
  cp.push_back(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_properties const& left, context_property const& right)
{
  context_properties cp(left);
  cp.push_back(right);
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_property const& left, context_properties const& right)
{
  context_properties cp;
  cp.push_back(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
context_properties
operator& (context_properties const& left, context_properties const& right)
{
  context_properties cp(left);
  cp.insert(cp.end(),right.begin(),right.end());
  return cp;
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
