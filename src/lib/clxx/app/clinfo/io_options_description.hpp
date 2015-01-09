// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/io_options_description.hpp

/** // doc: clxx/app/clinfo/io_options_description.hpp {{{
 * \file clxx/app/clinfo/io_options_description.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED
#define CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED

#include <clxx/app/options/options_description.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class io_options_description {{{
 * \todo Write documentation
 */ // }}}
class io_options_description
  : public clxx::app::options::options_description
{
  /** // doc: _init_options_descrition() {{{
   * \todo Write documentation
   */ // }}}
  void _init_options_description( ) ;
public:
  /** // doc: ~io_options_description() {{{
   * \todo Write documentation
   */ // }}}
  virtual ~io_options_description();
  /** // {{{
   * \todo Write documetation
   */ // }}}
  io_options_description( unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
  /** // {{{
   * \todo Write documetation
   */ // }}}
  io_options_description( const std::string & caption
        , unsigned line_length = m_default_line_length
        , unsigned min_description_length = m_default_line_length/2);
};

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_io_OPTIONS_DESCRIPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
