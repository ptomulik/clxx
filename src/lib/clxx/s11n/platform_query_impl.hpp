// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/s11n/platform_query.hpp

/** // doc: clxx/s11n/platform_query.hpp {{{
 * \file clxx/s11n/platform_query.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_S11N_PLATFORM_QUERY_IMPL_HPP_INCLUDED
#define CLXX_S11N_PLATFORM_QUERY_IMPL_HPP_INCLUDED

#include <clxx/s11n/platform_query.hpp>
#include <boost/serialization/serialization.hpp>
#include <boost/serialization/utility.hpp>

namespace clxx {

/* ------------------------------------------------------------------------ */
template<class Archive>
static void _serialize(Archive& ar, platform_query& obj, const unsigned int)
{
  using boost::serialization::make_nvp;
  ar  & make_nvp("id", obj._id)
      & make_nvp("profile", obj._profile)
      & make_nvp("version", obj._version)
      & make_nvp("name", obj._name)
      & make_nvp("vendor", obj._vendor)
      & make_nvp("extensions", obj._extensions);
}
/* ------------------------------------------------------------------------ */

} // end namespace clxx

namespace boost {
namespace serialization {

/* ------------------------------------------------------------------------ */
template <class Archive>
void serialize(Archive& ar, clxx::platform_query& obj, const unsigned int ver)
{
  clxx::_serialize(ar, obj, ver);
}
/* ------------------------------------------------------------------------ */

} /* namespace boost */
} /* namespace serialization */

#endif /* CLXX_S11N_PLATFORM_QUERY_IMPL_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
