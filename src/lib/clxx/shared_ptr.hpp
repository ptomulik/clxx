// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/shared_ptr.hpp

/** // doc: clxx/shared_ptr.hpp {{{
 * \file clxx/shared_ptr.hpp
 * \brief Declares the \ref clxx::shared_ptr
 */ // }}}
#ifndef CLXX_SHARED_PTR_HPP_INCLUDED
#define CLXX_SHARED_PTR_HPP_INCLUDED

#include <boost/shared_ptr.hpp>
namespace clxx {
/** // doc: shared_ptr {{{
 * \brief Shared pointer
 *
 * Currently \c boost::shared_ptr is used.
 */ // }}}
template <typename T> using shared_ptr = boost::shared_ptr<T>;
} // end namespace clxx
#endif /* CLXX_SHARED_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
