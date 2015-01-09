// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/main.hpp

/** // doc: clxx/app/main.hpp {{{
 * \file clxx/app/main.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_MAIN_HPP_INCLUDED
#define CLXX_APP_MAIN_HPP_INCLUDED

namespace clxx { namespace app {

/** // doc: class main {{{
 * \todo Write documentation
 */ // }}}
class main
{
public:
  /** // doc: ~main() {{{
   * \todo Write documentation for class main
   */ // }}}
  virtual ~main();
  /** // doc: main() {{{
   * \todo Write documentation
   */ // }}}
  main();
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual void init(int argc, char const* argv[]) = 0;
  /** // doc: run() {{{
   * \todo Write documentation
   */ // }}}
  virtual int run( ) = 0;
};

} } // end namespace clxx::app

#endif /* CLXX_APP_MAIN_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
