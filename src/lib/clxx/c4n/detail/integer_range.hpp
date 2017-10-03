// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/detail/integer_range.hpp

/** // doc: clxx/c4n/detail/integer_range.hpp {{{
 * \file clxx/c4n/detail/integer_range.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_C4N_DETAIL_INTEGER_RANGE_HPP_INCLUDED
#define CLXX_C4N_DETAIL_INTEGER_RANGE_HPP_INCLUDED

#include <type_traits>
#include <cstdlib>

namespace clxx { namespace detail {

template < typename IntT
         , typename DiffT = ptrdiff_t >
class integer_range_iterator
{
  IntT _value;
  DiffT _step;
public:
  typedef IntT value_type;
  typedef DiffT difference_type;
  typedef integer_range_iterator iterator;
public:
  constexpr integer_range_iterator(value_type value, difference_type step) noexcept
    : _value(value), _step(step)
  { }
  constexpr value_type
  value() const noexcept
  {
    return this->_value;
  }
  constexpr difference_type
  step() const noexcept
  {
    return this->_step;
  }
  iterator&
  operator++() noexcept
  {
    this->_value += this->_step;
    return *this;
  }
  iterator&
  operator--() noexcept
  {
    this->_value -= this->_step;
    return *this;
  }
  iterator
  operator++(int) noexcept
  {
    iterator it(*this);
    this->_value += this->_step;
    return it;
  }
  iterator
  operator--(int) noexcept
  {
    iterator it(*this);
    this->_value -= this->_step;
    return it;
  }
  iterator&
  operator+=(difference_type d) noexcept
  {
    this->_value += d * this->_step;
    return *this;
  }
  iterator&
  operator-=(difference_type d) noexcept
  {
    this->_value -= d * this->_step;
    return *this;
  }
  constexpr iterator
  operator+(difference_type d) const noexcept
  { return iterator(this->_value + d * this->_step, this->_step); }
  constexpr iterator
  operator-(difference_type d) const noexcept
  { return iterator(this->_value - d * this->_step, this->_step); }
  constexpr value_type
  operator* () const noexcept
  { return this->_value; }
  constexpr value_type
  operator [](difference_type i) const noexcept
  { return this->_value + i * this->_step; }
  constexpr bool
  operator==(iterator rhs) const noexcept
  { return this->_value == rhs._value; }
  constexpr bool
  operator!=(iterator rhs) const noexcept
  { return this->_value != rhs._value; }
  constexpr bool
  operator<(iterator rhs) noexcept
  {
    return (this->_step < 0) ?
      this->_value > rhs._value :
      this->_value < rhs._value ;
  }
  constexpr bool
  operator>(iterator rhs) noexcept
  {
    return (this->_step < 0) ?
      this->_value < rhs._value :
      this->_value > rhs._value ;
  }
  constexpr bool
  operator<=(iterator rhs) noexcept
  {
    return (this->_step < 0) ?
      this->_value >= rhs._value :
      this->_value <= rhs._value ;
  }
  constexpr bool
  operator>=(iterator rhs) noexcept
  {
    return (this->_step < 0) ?
      this->_value <= rhs._value :
      this->_value >= rhs._value ;
  }
};

/** // doc: integer_range {{{
 * \todo Write documentation for #integer_range
 *
 * \tparam EnumT
 * \tparam IntT
 * \tparam SizeT
 * \tparam DiffT
 *
 */ // }}}
template <  typename IntT
          , typename SizeT = size_t
          , typename DiffT = ptrdiff_t >
class integer_range
{
  IntT  _begin;
  IntT  _end;
  DiffT _step;
public:
  /** // doc: value_type {{{
   *  \todo Write documentation for value_type
   */ // }}}
  typedef IntT value_type;
  /** // doc: size_type {{{
   *  \todo Write documentation for size_type
   */ // }}}
  typedef SizeT size_type;
  /** // doc: difference_type {{{
   *  \todo Write documentation for difference_type
   */ // }}}
  typedef DiffT difference_type;
  /** // doc: iterator {{{
   *  \todo Write documentation for integer_range::iterator
   */ // }}}
  typedef integer_range_iterator<IntT, DiffT> iterator;
public:
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range() noexcept
    : _begin(0), _end(0), _step(1)
  { }
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range(value_type begin, value_type end) noexcept
    : _begin(begin), _end(end), _step((end >= begin) ? 1 : -1)
  { }
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range(value_type begin, value_type end, difference_type step) noexcept
    : _begin(begin), _end(end), _step(step)
  { }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  constexpr iterator begin() const noexcept
  { return iterator(this->_begin, this->_step); }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  constexpr iterator end() const noexcept
  { return iterator(this->_end, this->_step); }
  /** // doc: low() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type low() const noexcept
  { return this->_begin <= this->_end ? this->_begin : this->_end; }
  /** // doc: high() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type high() const noexcept
  { return this->_begin >= this->_end ? this->_begin : this->_end; }
   /** // doc: step() {{{
   * \todo Write documentation
   */ // }}}
  constexpr difference_type step() const noexcept
  { return this->_step; }
  /** // doc: size() {{{
   * \todo Write documentation
   */ // }}}
  constexpr size_type size() const noexcept
  { return this->high() - this->low(); }
  /** // doc: includes() {{{
   * \todo Write documentation
   */ // }}}
  constexpr bool includes(value_type x) const noexcept
  { return (x >= this->low()) && (x < this->high()); }
};

template <typename T, typename IntT, typename DiffT>
constexpr integer_range_iterator<IntT, DiffT>
operator+ (T d, integer_range_iterator<IntT, DiffT> const& it) noexcept
{
  return it + d;
}

} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_INTEGER_RANGE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
