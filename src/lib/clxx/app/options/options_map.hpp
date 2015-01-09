// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/options_map.hpp

/** // doc: clxx/app/options/options_map.hpp {{{
 * \file clxx/app/options/options_map.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED
#define CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED

#include <boost/program_options/variables_map.hpp>

namespace clxx { namespace app { namespace options {
/** // doc: options_map {{{
 * \todo write documentation
 */ // }}}
class options_map
  : public boost::program_options::variables_map
{
public:
  /** // doc: ~options_map() {{{
   * \todo write documentation
   */ // }}}
  virtual ~options_map();
  /** // doc: options_map() {{{
   * \todo write documentation
   */ // }}}
  options_map();
};
} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_OPTIONS_MAP_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
