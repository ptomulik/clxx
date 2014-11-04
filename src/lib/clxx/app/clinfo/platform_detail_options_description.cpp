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

// clxx/app/clinfo/platform_detail_options_description.cpp

/** // doc: clxx/app/clinfo/platform_detail_options_description.cpp {{{
 * \file clxx/app/clinfo/platform_detail_options_description.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/app/clinfo/platform_detail_options_description.hpp>
#include <clxx/app/options/option_value.hpp>
#include <vector>
#include <string>

namespace clxx { namespace app { namespace clinfo {

platform_detail_options_description::
platform_detail_options_description( unsigned line_length
                                   , unsigned min_description_length )
  : clxx::app::options::options_description("Platform Detail Options"
                                            , line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
platform_detail_options_description::
platform_detail_options_description( const std::string & caption
                                   , unsigned line_length
                                   , unsigned min_description_length )
  : clxx::app::options::options_description( caption, line_length
                                            , min_description_length )
{
  this->_init_options_description();
}
platform_detail_options_description::
~platform_detail_options_description()
{
}
void platform_detail_options_description::
_init_options_description()
{
  using clxx::app::options::value;
  using std::vector;
  using std::string;
  this->add_options()
    ("platform-profile"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    , "query for platform profile?")
    ("platform-version"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    , "query for platform version?")
    ("platform-name"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    , "query for platform name?")
    ("platform-vendor"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    , "query for platform vendor?")
    ("platform-extensions"
    , value<bool>()->value_name("yes/no")->implicit_value(true,"yes")
    , "query for platform extensions?")
  ;
}

} } } // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
