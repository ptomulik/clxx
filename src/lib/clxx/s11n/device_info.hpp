// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/device_info.hpp

/** // doc: clxx/s11n/device_info.hpp {{{
 * \file clxx/s11n/device_info.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_S11N_DEVICE_INFO_HPP_INCLUDED
#define CLXX_S11N_DEVICE_INFO_HPP_INCLUDED

#include <clxx/device_info.hpp>
#include <boost/serialization/version.hpp>

BOOST_CLASS_VERSION( clxx::device_info
                   , clxx::device_info::class_version )

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
void serialize(Archive& ar, clxx::device_info& obj, const unsigned int ver);
/** @} */
} /* namespace serialization */
} /* namespace boost */

#endif /* CLXX_S11N_DEVICE_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
