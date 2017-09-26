// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/i2o/platform_info_ptrs.hpp

/** // doc: clxx/i2o/platform_info_ptrs.hpp {{{
 * \file clxx/i2o/platform_info_ptrs.hpp
 * \brief Defines \ref clxx::platform_info_ptrs "platform_info_ptrs"
 */ // }}}
#ifndef CLXX_I2O_PLATFORM_INFO_PTRS_HPP_INCLUDED
#define CLXX_I2O_PLATFORM_INFO_PTRS_HPP_INCLUDED

#include <clxx/i2o/platform_info_ptr.hpp>
#include <vector>

namespace clxx {
/** // doc: platform_info_ptrs {{{
 * \brief Sequence of (shared) pointers to \ref clxx::platform_info "platform_info" objects
 */ // }}}
typedef std::vector<clxx::platform_info_ptr> platform_info_ptrs;
/** // doc: const_platform_info_ptrs {{{
 * \brief Sequence of (shared) pointers to const \ref clxx::platform_info "platform_info" objects
 */ // }}}
typedef std::vector<clxx::const_platform_info_ptr> const_platform_info_ptrs;
} // end namespace clxx

#endif /* CLXX_I2O_PLATFORM_INFO_PTRS_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
