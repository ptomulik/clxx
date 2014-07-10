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

// clxx/app/options/exceptions/invalid_command_line_syntax.hpp

/** // doc: clxx/app/options/exceptions/invalid_command_line_syntax.hpp {{{
 * \file clxx/app/options/exceptions/invalid_command_line_syntax.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
template<>
struct std_except_ctor_arg< boost::program_options::invalid_command_line_syntax >
  { typedef boost::program_options::invalid_command_line_syntax type; };
} /* namespace clxx */

namespace clxx { namespace app { namespace options {

class invalid_command_line_syntax_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_command_line_syntax
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_command_line_syntax
    > base_;
public:
  invalid_command_line_syntax_error(boost::program_options::invalid_command_line_syntax const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_COMMAND_LINE_SYNTAX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
