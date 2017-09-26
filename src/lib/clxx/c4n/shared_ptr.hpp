// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/shared_ptr.hpp

/** // doc: clxx/c4n/shared_ptr.hpp {{{
 * \file clxx/c4n/shared_ptr.hpp
 * \brief Declares the \ref clxx::shared_ptr
 */ // }}}
#ifndef CLXX_C4N_SHARED_PTR_HPP_INCLUDED
#define CLXX_C4N_SHARED_PTR_HPP_INCLUDED

#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
namespace clxx {
/** // doc: shared_ptr {{{
 * \brief Shared pointer
 *
 * Currently \c boost::shared_ptr is used.
 */ // }}}
template <typename T> using shared_ptr = boost::shared_ptr<T>;
/** // doc: make_shared() {{{
 * \brief Currently its an alias to \c boost::make_shared() is used.
 */ // }}}
using boost::make_shared;
} // end namespace clxx
#endif /* CLXX_C4N_SHARED_PTR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
