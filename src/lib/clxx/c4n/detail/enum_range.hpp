// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/enum_range.hpp

/** // doc: clxx/c4n/detail/enum_range.hpp {{{
 * \file clxx/c4n/detail/enum_range.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED
#define CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED

#include <clxx/c4n/detail/integer_range.hpp>
#include <type_traits>

namespace clxx { namespace detail {

/** // doc: enum_range {{{
 * \todo Write documentation for #enum_range
 *
 * \tparam EnumT
 * \tparam IntT
 * \tparam SizeT
 * \tparam DiffT
 *
 */ // }}}
template < typename EnumT
         , typename IntT = typename ::std::underlying_type<EnumT>::type
         , typename SizeT = size_t
         , typename DiffT = ptrdiff_t >
class enum_range
  : public integer_range<IntT, SizeT, DiffT>
{
  using Base = integer_range<IntT, SizeT, DiffT>;
public:
  /** // doc: enum_type {{{
   * \todo Write documentation
   */ // }}}
  typedef EnumT enum_type;
  /** // doc: underlying_type {{{
   * \todo Write documentation
   */ // }}}
  typedef IntT underlying_type;
public:
  using Base::Base;
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range(enum_type stop) noexcept
    : Base(static_cast<underlying_type>(stop))
  { }
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range(enum_type start, enum_type stop) noexcept
    : Base(static_cast<underlying_type>(start), static_cast<underlying_type>(stop))
  { }
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range(enum_type start, enum_type stop, DiffT step) noexcept
    : Base(static_cast<underlying_type>(start), static_cast<underlying_type>(stop), step)
  { }
  /** // doc: includes() {{{
   * \todo Write documentation
   */ // }}}
  constexpr bool includes(enum_type x) const noexcept
  { return this->Base::includes(static_cast<underlying_type>(x)); }
};

} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
