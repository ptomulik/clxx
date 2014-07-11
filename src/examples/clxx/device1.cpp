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
#include <clxx/cl/platforms.hpp>
#include <clxx/cl/devices.hpp>
#include <algorithm>

// [DumpDevice]
#include <clxx/cl/device.hpp>
#include <iostream>
/// \brief Dump OpenCL device info to stdout. Functor.
class dump_device
{
  /// \internal
  int count;
public:
  /// \brief Default constructor
  dump_device() : count(0) { }
  /// \brief Core operator
  void operator ()(clxx::device const& d)
  {
    std::cout << "  Device " << count << ":" << std::endl;
    std::cout << "    Id ........ : " << d.id() << std::endl;
    std::cout << "    Name ...... : " << d.get_name() << std::endl;
    std::cout << "    Vendor .... : " << d.get_vendor() << std::endl;
    std::cout << "    Version: .. : " << d.get_version() << std::endl;
    ++count;
  }
};
// [DumpDevice]

// [DumpPlatform]
/// \brief Dump OpenCL platform info to stdout. Functor.
class dump_platform
{
  /// \internal
  int count;
public:
  /// \brief Default constructor
  dump_platform() : count(0) { }
  /// \brief Core operator
  void operator () (clxx::platform const& p)
  {
    std::cout << "Platform " << count << ":" << std::endl;
    std::cout << "  Id .......... : " << p.id() << std::endl;
    std::cout << "  Name ........ : " << p.get_name() << std::endl;
    std::cout << "  Profile ..... : " << p.get_profile() << std::endl;
    std::cout << "  Version ..... : " << p.get_version() << std::endl;
    std::cout << "  Extensions .. : " << p.get_extensions() << std::endl;

    clxx::devices ds(clxx::get_devices(p));
    std::for_each(ds.begin(), ds.end(), dump_device());
    std::cout << std::endl;

    ++count;
  }
};
// [DumpPlatform]

// [Main]
#include <algorithm>
/// \brief Main function
int main(int, char const*[])
{
  using clxx::get_platforms;
  try {
    clxx::platforms ps(clxx::get_platforms());
    std::for_each(ps.begin(), ps.end(), dump_platform());
  } catch (std::exception const& e) {
    std::cerr << "Exception cautht: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
// [Main]
// [Program]
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
