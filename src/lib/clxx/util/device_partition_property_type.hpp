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

// clxx/util/device_partition_property_type.hpp

/** // doc: clxx/util/device_partition_property_type.hpp {{{
 * \file clxx/util/device_partition_property_type.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED
#define CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED

#include <clxx/types.hpp>
#include <clxx/util/device_partition_property_type_fwd.hpp>
#include <vector>

namespace clxx {

/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template <>
  struct device_partition_property_type<device_partition_property_t::equally>
  {
    typedef unsigned int type;
  };
template <>
  struct device_partition_property_type<device_partition_property_t::by_counts>
  {
    typedef std::vector<unsigned int> const& type;
  };
#if CL_VERSION_1_2
template <>
  struct device_partition_property_type<device_partition_property_t::by_affinity_domain>
  {
    typedef device_affinity_domain_t type;
  };
#endif
/** \endcond */

} // end namespace clxx

#endif /* CLXX_UTIL_DEVICE_PARTITION_PROPERTY_TYPE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
