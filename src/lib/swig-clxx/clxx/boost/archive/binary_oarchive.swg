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

/** // doc: clxx/boost/archive/binary_oarchive.swg {{{
 * \file clxx/boost/archive/binary_oarchive.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/std/iostream_mod.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <clxx/info/device_info.hpp>
#include <boost/serialization/shared_ptr.hpp>
%}

%import <clxx/std/iostream_mod.i>
%include <clxx/boost/archive/detail/interface_oarchive.swg>

namespace boost {
namespace archive {
class binary_oarchive;
%template(interface_oarchive_T_binary_oarchive) detail::interface_oarchive<binary_oarchive>;
class binary_oarchive
  : public detail::interface_oarchive<binary_oarchive>
  {
  public:
    binary_oarchive(std::ostream &os, unsigned int flags = 0);
    binary_oarchive(std::streambuf &bsb, unsigned int flags = 0);
   ~binary_oarchive();
  };
} /* namespace archive */
} /* namespace boost */


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
