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

/** // doc: clxx/unit.cpp {{{
 * \file clxx/unit.cpp
 * \todo Write documentation
 */ // }}}
/** // doc: io1.cpp {{{
 * \example io1.cpp
 * This example demonstrates usage of I/O functions with CLXX types.
 */ // }}}
// [Program]
#include <clxx/io/types.hpp>
#include <clxx/types.hpp>
#include <iostream>
// [Main]
/// \brief Main function
int main(int, char const*[])
{
  // [OutputStatusT]
  clxx::status_t err = clxx::status_t::device_not_found;
  std::cout << "1. Error code: " << err << std::endl;
  // [OutputStatusT]
  return EXIT_SUCCESS;
}
// [Main]
// [Program]



// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
