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

// clxx/app/clinfo/options_description.cpp

/** // doc: clxx/app/clinfo/options_description.cpp {{{
 * \file clxx/app/clinfo/options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clinfo/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

options_description::
options_description( unsigned line_length, unsigned min_description_length )
  : clxx::app::options::options_description( line_length
                                            , min_description_length)
  , _common_options("Common Options",line_length,min_description_length)
  , _platform_general_options(line_length,min_description_length)
  , _platform_detail_options(line_length,min_description_length)
  , _device_general_options(line_length,min_description_length)
  , _device_detail_options(line_length,min_description_length)
  , _io_options(line_length,min_description_length)
{ // {{{
  this->_init_options_description();
} // }}}
options_description::
options_description( const std::string & caption, unsigned line_length
                   , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                   , min_description_length)
  , _common_options(line_length,min_description_length)
  , _platform_general_options(line_length,min_description_length)
  , _platform_detail_options(line_length,min_description_length)
  , _device_general_options(line_length,min_description_length)
  , _device_detail_options(line_length,min_description_length)
  , _io_options(line_length,min_description_length)
{ // {{{
  this->_init_options_description();
} // }}}
options_description::
~options_description()
{ // {{{
} // }}}
void options_description::
_init_options_description()
{ // {{{
  this->add(this->common_options());
  this->add(this->platform_general_options());
  this->add(this->platform_detail_options());
  this->add(this->device_general_options());
  this->add(this->device_detail_options());
  this->add(this->io_options());
} // }}}

} } } // end namespace clxx::app::clinfo

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
