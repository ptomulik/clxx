// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

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
