// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/current_instance1.cpp {{{
 * \file clxx/common/current_instance1.cpp
 * \brief Usage example for \ref clxx::detail::current_example
 */ // }}}
/** // doc: clxx/common/current_instance1.cpp {{{
 * \example clxx/common/current_instance1.cpp
 * \brief Usage example for \ref clxx::detail::current_example
 */ // }}}

// [Program]
#include <clxx/common/detail/current_instance.hpp>
#include <iostream>

// [CurrentPathClass]
/** // doc: current_path {{{
 * \brief Example of "Current Instance" class
 */ // }}}
class current_path
  : public clxx::detail::current_instance< current_path, std::string >
{
public:
  /// Default value for static-singleton instance
  static std::string default_static_instance() { return "/static/path"; }
  /// Default value for thread-singleton instance
  static std::string default_thread_instance() { return "/thread/path"; }
};
// [CurrentPathClass]

// [LoadProgramFcn]
void load_program(std::string const& name, std::string const& path = current_path::get())
{
  std::cout << "loading: \"" << path << "/" << name << "\"" << std::endl;
}
// [LoadProgramFcn]

/// Main function
int main() 
{
  load_program("1.cl");

  // [BindThreadInstance]
  current_path::bind_thread_instance();
  // [BindThreadInstance]
  load_program("2.cl");
  
  // [BindUserInstance]
  std::string path("/local/path");
  current_path::bind_custom_instance(path);
  // [BindUserInstance]
  load_program("3.cl");

  current_path::get() = "/local/path/modified";
  load_program("4.cl");

  // [BindStaticInstance]
  current_path::bind_static_instance();
  // [BindStaticInstance]
  current_path::get() = "/static/path/modified";
  load_program("5.cl");

  return 0;
}
// [Program]

/* [Output]
loading: "/static/path/1.cl"
loading: "/thread/path/2.cl"
loading: "/local/path/3.cl"
loading: "/local/path/modified/4.cl"
loading: "/static/path/modified/5.cl"
   [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
