// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/s11n/device_query.cpp {{{
 * \file clxx/s11n/device_query.cpp
 * \brief Instantiates boost::serialization::serialize functions for
 *        \ref clxx::device_query "device_query" objects
 */ // }}}
#include <clxx/s11n/device_query_impl.hpp>
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
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template void serialize(boost::archive::text_iarchive&, clxx::device_query&, const unsigned int);
template void serialize(boost::archive::xml_iarchive&, clxx::device_query&, const unsigned int);
template void serialize(boost::archive::binary_iarchive&, clxx::device_query&, const unsigned int);

template void serialize(boost::archive::text_oarchive&, clxx::device_query&, const unsigned int);
template void serialize(boost::archive::xml_oarchive&, clxx::device_query&, const unsigned int);
template void serialize(boost::archive::binary_oarchive&, clxx::device_query&, const unsigned int);
/** \endcond */
} /* namespace serialization */
} /* namespace boost */


// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
