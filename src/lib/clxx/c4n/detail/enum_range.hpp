// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/enum_range.hpp

/** // doc: clxx/c4n/detail/enum_range.hpp {{{
 * \file clxx/c4n/detail/enum_range.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED
#define CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED

#include <type_traits>
#include <cstdlib>

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
         , typename IntT = typename std::underlying_type<EnumT>::type
         , typename SizeT = typename std::make_unsigned<IntT>::type
         , typename DiffT = typename std::make_signed<IntT>::type >
class enum_range
{
  IntT _begin;
  IntT _end;
public:
  /** // doc: enum_type {{{
   *  \todo Write documentation for enum_type
   */ // }}}
  typedef EnumT enum_type;
  /** // doc: enum_type {{{
   *  \todo Write documentation for underlying_type
   */ // }}}
  typedef IntT underlying_type;
  /** // doc: enum_type {{{
   *  \todo Write documentation for size_type
   */ // }}}
  typedef SizeT size_type;
  /** // doc: enum_type {{{
   *  \todo Write documentation for difference_type
   */ // }}}
  typedef DiffT difference_type;
public:
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range() noexcept
    : _begin(0), _end(0)
  { }
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range(enum_type begin, enum_type end) noexcept
    : _begin(static_cast<underlying_type>(begin)),
      _end(static_cast<underlying_type>(end))
  { }
  /** // doc: enum_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr enum_range(underlying_type begin, underlying_type end) noexcept
    : _begin(begin), _end(end)
  { }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  constexpr underlying_type begin() const noexcept
  { return this->_begin; }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  constexpr underlying_type end() const noexcept
  { return this->_end; }
  /** // doc: low() {{{
   * \todo Write documentation
   */ // }}}
  constexpr underlying_type low() const noexcept
  { return std::min(this->begin(), this->end()); }
  /** // doc: high() {{{
   * \todo Write documentation
   */ // }}}
  constexpr underlying_type high() const noexcept
  { return std::max(this->begin(), this->end()); }
  /** // doc: size() {{{
   * \todo Write documentation
   */ // }}}
  constexpr size_type size() const noexcept
  { return this->high() - this->low(); }
  /** // doc: includes() {{{
   * \todo Write documentation
   */ // }}}
  constexpr bool includes(enum_type x) const noexcept
  { return this->includes(static_cast<underlying_type>(x)); }
  /** // doc: includes() {{{
   * \todo Write documentation
   */ // }}}
  constexpr bool includes(underlying_type x) const noexcept
  { return (x >= this->low()) && (x < this->high()); }
};

} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_ENUM_RANGE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
