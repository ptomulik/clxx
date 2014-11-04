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

/** // doc: clxx/s11n/platform_layer_info.cpp {{{
 * \file clxx/s11n/platform_layer_info.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/s11n/platform_layer_info_impl.hpp>
#include <clxx/info/platform_info.hpp>
#include <clxx/info/device_info.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

//
// Instantiations:
//
namespace boost {
namespace serialization {

template void serialize(boost::archive::text_iarchive&, clxx::platform_layer_info&, const unsigned int);
template void serialize(boost::archive::xml_iarchive&, clxx::platform_layer_info&, const unsigned int);
template void serialize(boost::archive::binary_iarchive&, clxx::platform_layer_info&, const unsigned int);

template void serialize(boost::archive::text_oarchive&, clxx::platform_layer_info&, const unsigned int);
template void serialize(boost::archive::xml_oarchive&, clxx::platform_layer_info&, const unsigned int);
template void serialize(boost::archive::binary_oarchive&, clxx::platform_layer_info&, const unsigned int);

} /* namespace serialization */
} /* namespace boost */


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
