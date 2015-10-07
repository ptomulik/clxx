// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/auto_bind1.cpp {{{
 * \file clxx/common/auto_bind1.cpp
 * \brief Usage example for \ref clxx::auto_bind
 */ // }}}
/** // doc: clxx/common/auto_bind1.cpp {{{
 * \example clxx/common/auto_bind1.cpp
 * \brief Usage example for \ref clxx::auto_bind
 */ // }}}

// [Program]
#include <clxx/common/auto_bind.hpp>
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
  // [ExampleCore]
  std::string path1("/local/path1");
  std::string path2("/local/path2");

  load_program("1.cl");

  { 
    // bind path1, the bind will be reverted at the end of current scope
    clxx::auto_bind<current_path> ab1(path1);
    load_program("2.cl");

    {
      // bind path2, the bind will be reverted at the end of current scope
      clxx::auto_bind<current_path> ab2(path2);
      load_program("3.cl");
    }

    load_program("4.cl");
  }

  load_program("5.cl");
  // [ExampleCore]

  return 0;
}
// [Program]

/* [Output]
loading: "/static/path/1.cl"
loading: "/local/path1/2.cl"
loading: "/local/path2/3.cl"
loading: "/local/path1/4.cl"
loading: "/static/path/5.cl"
   [Output] */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
