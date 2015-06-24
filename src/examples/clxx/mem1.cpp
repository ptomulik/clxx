// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/mem1.cpp {{{
 * \file clxx/mem1.cpp
 * \brief Usage example for \ref clxx::mem class
 */ // }}}
/** // doc: mem1.cpp {{{
 * \example clxx/mem1.cpp
 * \brief Usage example for \ref clxx::mem class
 */ // }}}

// [Program]
#include <clxx/platforms.hpp>
#include <clxx/mem.hpp>
#include <clxx/context.hpp>
#include <clxx/io/types.hpp>
#include <iostream>

#define ARRAY_ELEMENTS 16
int main() 
{
  clxx::platforms platforms(clxx::get_platforms());
  clxx::context   context(clxx::make_context_properties(platforms[0]),
                          clxx::device_type_t::all);
  float           array[ARRAY_ELEMENTS];
  clxx::mem       buffer(context, clxx::mem_flags_t::read_write, sizeof(array), array);

  std::cout << "buffer.get_type():            " << buffer.get_type() << std::endl;
  std::cout << "buffer.get_flags():           " << buffer.get_flags() << std::endl;
  std::cout << "buffer.get_size():            " << buffer.get_size() << std::endl;
  std::cout << "buffer.get_map_count():       " << buffer.get_map_count() << std::endl;
  std::cout << "buffer.get_reference_count(): " << buffer.get_reference_count() << std::endl;
  return 0;
}
// [Program]

/* [Output]
buffer.get_type():            buffer
buffer.get_flags():           read_write
buffer.get_size():            64
buffer.get_map_count():       0
buffer.get_reference_count(): 1
   [Output] */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
