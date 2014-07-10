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

// clxx/s11n/platform_layer_info.hpp

/** // doc: clxx/s11n/platform_layer_info.hpp {{{
 * \file clxx/s11n/platform_layer_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED

#include <clxx/s11n/platform_layer_info.hpp>
#include <clxx/s11n/platform_info.hpp>
#include <clxx/s11n/device_info.hpp>
#include <clxx/s11n/shared_ptr.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
template<class Archive>
void _serialize(Archive& ar, platform_layer_info& obj, const unsigned int)
{
  using boost::serialization::make_nvp;
  ar & make_nvp("bimap", obj._bimap);
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

namespace boost {
namespace serialization {

/* ------------------------------------------------------------------------ */
template <class Archive>
void serialize(Archive& ar, clxx::platform_layer_info& obj, const unsigned int ver)
{
  clxx::_serialize(ar, obj, ver);
}
/* ------------------------------------------------------------------------ */

} /* namespace boost */
} /* namespace serialization */

#endif /* CLXX_S11N_PLATFORM_LAYER_INFO_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
