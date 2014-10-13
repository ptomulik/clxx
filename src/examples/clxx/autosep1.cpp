/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

/** // doc: clxx/autosep1.cpp {{{
 * \file clxx/autosep1.cpp
 * \todo Write documentation
 */ // }}}
/** // example {{{
 * \example autosep1.cpp
 * This example demonstrates how one may use the clxx::io::autosep_ object
 * to format sequences when printing them to a stream.
 */ // }}}
// [Program]
#include <clxx/io/autosep.hpp>
#include <iostream>
/// Main function
int main(int, char**)
{
  clxx::io::autosep_<const char*> as(", ");
  std::cout << "tab[] = {";
  for(int i = 1; i <= 3; ++i) {
    std::cout << as << i;
  }
  std::cout << "}" << std::endl;
  return EXIT_SUCCESS;
}
// [Program]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
