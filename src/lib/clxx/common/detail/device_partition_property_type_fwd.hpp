// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/device_partition_property_type_fwd.hpp

/** // doc: clxx/common/detail/device_partition_property_type_fwd.hpp {{{
 * \file clxx/common/detail/device_partition_property_type_fwd.hpp
 * \brief Forward-declaration of \ref clxx::device_partition_property_type
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_DEVICE_PARTITION_PROPERTY_TYPE_FWD_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_DEVICE_PARTITION_PROPERTY_TYPE_FWD_HPP_INCLUDED

#include <clxx/common/types.hpp>

namespace clxx { namespace detail {
#if CLXX_CL_H_VERSION_1_2
template <device_partition_property_t Name>
  struct device_partition_property_type;
#endif
} } // end namespace clxx::detail

#endif /* CLXX_COMMON_DETAIL_DEVICE_PARTITION_PROPERTY_TYPE_FWD_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
