// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/platform_detail_options_description.hpp

/** // doc: clxx/app/clinfo/platform_detail_options_description.hpp {{{
 * \file clxx/app/clinfo/platform_detail_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class platform_detail_options_description {{{
 * \todo Write documentation
 */ // }}}
class platform_detail_options_description
  : public clxx::app::options::options_description
{
private:
  void _init_options_description();
public:
  /** // doc: ~platform_detail_options_description() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~platform_detail_options_description();
  /** // {{{
   * \todo Write documetation
   */ // }}}
  platform_detail_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \todo Write documetation
   */ // }}}
  platform_detail_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx

#endif /* CLXX_APP_CLINFO_PLATFORM_DETAIL_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
