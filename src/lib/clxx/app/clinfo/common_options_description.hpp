// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/common_options_description.hpp

/** // doc: clxx/app/clinfo/common_options_description.hpp {{{
 * \file clxx/app/clinfo/common_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/common_options_description.hpp>

namespace clxx { namespace app { namespace clinfo {
/** // doc: class common_options_description {{{
 * \todo Write documentation
 */ // }}}
class common_options_description
  : public clxx::app::common_options_description
{
  /** // doc: common_options_description::_init_options_description() {{{
   * \todo Write documentation
   */ // }}}
  void _init_options_description( ) ;
public:
  /** // doc: common_options_description::~common_options_description() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~common_options_description();
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
} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_COMMON_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
