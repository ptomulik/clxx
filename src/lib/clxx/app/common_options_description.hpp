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

// clxx/app/common_options_description.hpp

/** // doc: clxx/app/common_options_description.hpp {{{
 * \file clxx/app/common_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app {
/** // doc: class common_options_description {{{
 * \todo Write documentation
 */ // }}}
class common_options_description
  : public options::options_description
{
protected:
  /** // _init_app_common_options() {{{
   * \todo Write documentation
   *
   * Called from default constructor.
   */ // }}}
  void _init_options_description();
public:
  /** // doc: ~common_options_description() {{{
   * \todo Write documentation
   */ // }}}
  ~common_options_description();
  /** // doc: common_options_description(...) {{{
   * \todo Write documentation
   */ // }}}
  common_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: common_options_description(...) {{{
   * \todo Write documentation
   */ // }}}
  common_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} } // end namespace clxx::app

#endif /* CLXX_APP_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
