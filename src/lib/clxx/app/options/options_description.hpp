// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/options_description.hpp

/** // doc: clxx/app/options/options_description.hpp {{{
 * \file clxx/app/options/options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <boost/program_options/options_description.hpp>

namespace clxx { namespace app { namespace options {
/** // doc: options_description {{{
 * \todo Write documentation
 */ // }}}
class options_description
  : public boost::program_options::options_description
{
public:
  /** // doc: option_description {{{
   * \todo write documentation
   */ // }}}
  typedef boost::program_options::option_description option_description;
public:
  /** // doc: ~options_description() {{{
   * \todo write documentation
   */ // }}}
  ~options_description();
  /** // doc: options_description(...) {{{
   * \todo write documentation
   */ // }}}
  options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // doc: options_description(...) {{{
   * \todo write documentation
   */ // }}}
  options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
