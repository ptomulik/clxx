/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */

/** // doc: clxx/platform3.cpp {{{
 * \file clxx/platform3.cpp
 * \todo Write file documentation
 */ // }}}
/** // doc: platform3.cpp {{{
 * \example platform3.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally.
 */ // }}}
// [Program]
// [Includes]
#include <clxx/cl/platform_layer.hpp>
#include <clxx/io/platform_layer_info.hpp>
#include <iostream>
// [Includes]

int main(int, char const*[])
{
  using namespace std;
  using namespace clxx;
  try {
    // [CreatePlatformLayer]
    platform_layer pl;
    // [CreatePlatformLayer]
    // [CreatePlatformLayerInfo]
    platform_layer_info info(query_platform_layer_info(pl));
    // [CreatePlatformLayerInfo]
    // [DumpPlatformLayerInfo]
    io::write(cout, info, 2);
    // [DumpPlatformLayerInfo]
  } catch (std::exception const& e) {
    std::cerr << "Exception cautht: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
