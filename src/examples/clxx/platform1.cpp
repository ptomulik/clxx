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

/** // doc: clxx/platform1.cpp {{{
 * \file clxx/platform1.cpp
 * \todo Write file documentation
 */ // }}}
/** // doc: platform1.cpp {{{
 * \example platform1.cpp
 * This example demonstrates, how OpenCL Platfrom Layer may be accessed from
 * local machine. We get and display some info about platforms and devices
 * available locally. We use clxx::platform_layer and clxx::platform_layer_info
 * for this purpose.
 */ // }}}
// [Program]
// [DumpPlatform]
#include <clxx/platform.hpp>
#include <iostream>
/// \brief Dump platform information to stdout. Functor.
class dump_platform
  {
    /// \internal
    int count;
  public:
    /// \brief Default constructor
    dump_platform() : count(0) { }
    /// \brief Core operator
    void operator()(clxx::platform const& p)
    {
      std::cout << "Platform " << count << ":" << std::endl;
      std::cout << "  Id ........ : " << p.id() << std::endl;
      std::cout << "  Name ...... : " << p.get_name() << std::endl;
      std::cout << "  Vendor .... : " << p.get_vendor() << std::endl;
      std::cout << "  Version ... : " << p.get_version() << std::endl;
      ++count;
    }
  };
// [DumpPlatform]

// [Main]
#include <clxx/platforms.hpp>
#include <algorithm>
/// \brief Main function
int main(int, char const*[])
{
  try {
    clxx::platforms ps(clxx::get_platforms());
    std::for_each(ps.begin(), ps.end(), dump_platform());
  } catch (std::exception const& e) {
    std::cerr << "Exception caught: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Main]
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
