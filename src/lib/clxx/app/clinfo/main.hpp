// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/clinfo/main.hpp

/** // doc: clxx/app/clinfo/main.hpp {{{
 * \file clxx/app/clinfo/main.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_MAIN_HPP_INCLUDED
#define CLXX_APP_CLINFO_MAIN_HPP_INCLUDED

#include <clxx/app/main.hpp>
#include <clxx/app/clinfo/options_description.hpp>
#include <clxx/app/options/options_map.hpp>
#include <string>
#include <vector>

namespace clxx { namespace app { namespace clinfo {

/** // doc: class main {{{
 * \todo Write documentation
 */ // }}}
class main
  : public clxx::app::main
{
public:
  /** // doc: options_map {{{
   * \todo Write documentation
   */ // }}}
  typedef clxx::app::options::options_map options_map;
public:
  /** // doc: ~main() {{{
   * \todo Write documentation for class main
   */ // }}}
  virtual ~main();
  /** // doc: main() {{{
   * \todo Write documentation
   */ // }}}
  main();
  /** // doc: main(argc, argv) {{{
   * \todo Write documentation
   */ // }}}
  main(int argc, char const* argv[]);
  /** // doc: init(argc, argv) {{{
   * \todo Write documentation
   */ // }}}
  virtual void init(int argc, char const* argv[]) ;
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual int run( ) ;
  /** // doc: get_options_description() {{{
   * \todo Write documentation
   */ // }}}
  inline options_description const& get_options_description() const
  {
    return this->_options_description;
  }
  /** // doc: get_options_map() {{{
   * \todo Write documentation
   */ // }}}
  inline options_map const& get_options_map() const
  {
    return this->_options_map;
  }
private:
  void _init_main( );
private:
  options_description _options_description;
  options_map _options_map;
};

/** // doc: run(argc, argv) {{{
 * \todo Write documentation
 */ // }}}
int run(int argc, char const* argv[]);

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
