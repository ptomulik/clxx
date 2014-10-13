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

// clxx/s11n/platform_info.hpp

/** // doc: clxx/s11n/platform_info.hpp {{{
 * \file clxx/s11n/platform_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_INFO_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_INFO_HPP_INCLUDED

#include <clxx/info/platform_info.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::platform_info
                   , clxx::platform_info::class_version )
#ifdef DOXYGEN
;
#endif

namespace boost {
namespace serialization {
/**
 * \ingroup clxx_s11n
 * @{
 */
/** // doc: serialize(ar,obj,ver) {{{
 * \todo Write documentation
 */ // }}}
template<class Archive>
void serialize(Archive& ar, clxx::platform_info& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_PLATFORM_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
