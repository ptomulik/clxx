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

// clxx/app/options/rethrow.hpp

/** // doc: clxx/app/options/rethrow.hpp {{{
 * \file clxx/app/options/rethrow.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED
#define CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED

#include <clxx/app/options/exceptions.hpp>

/** // doc: CLXX_APP_OPTIONS_RETHROW {{{
 * \todo Write documentation
 */ // }}}
#define CLXX_APP_OPTIONS_RETHROW(__ex,__as) \
  catch(boost::program_options::__ex const& e) { \
    throw clxx::app::options::__as(e); \
  }

/** // doc: CLXX_APP_OPTIONS_RETHROW_ALL {{{
 * \todo Write documentation
 */ // }}}
#define CLXX_APP_OPTIONS_RETHROW_ALL() \
  CLXX_APP_OPTIONS_RETHROW(too_many_positional_options_error, too_many_positional_options_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_command_line_style, invalid_command_line_style_error) \
  CLXX_APP_OPTIONS_RETHROW(reading_file, reading_options_file_error) \
  CLXX_APP_OPTIONS_RETHROW(multiple_values, multiple_option_values_error) \
  CLXX_APP_OPTIONS_RETHROW(multiple_occurrences, multiple_option_occurrences_error) \
  CLXX_APP_OPTIONS_RETHROW(required_option, required_option_error) \
  CLXX_APP_OPTIONS_RETHROW(unknown_option, unknown_option_error) \
  CLXX_APP_OPTIONS_RETHROW(ambiguous_option, ambiguous_option_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_config_file_syntax, invalid_config_file_syntax_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_command_line_syntax, invalid_command_line_syntax_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_option_value, invalid_option_value_error) \
  CLXX_APP_OPTIONS_RETHROW(invalid_bool_value, invalid_bool_option_value_error)

#endif /* CLXX_APP_OPTIONS_RETHROW_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
