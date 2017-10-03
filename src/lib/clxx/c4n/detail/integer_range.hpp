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
class integer_iterator
{
  IntT _value;
  DiffT _step;
public:
  typedef IntT value_type;
  typedef DiffT difference_type;
  typedef integer_iterator iterator;
public:
  constexpr integer_iterator(value_type value, difference_type step) noexcept
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
    this->_value += this->step();
    return *this;
  }
  iterator&
  operator--() noexcept
  {
    this->_value -= this->step();
    return *this;
  }
  iterator
  operator++(int) noexcept
  {
    iterator it(*this);
    this->_value += this->step();
    return it;
  }
  iterator
  operator--(int) noexcept
  {
    iterator it(*this);
    this->_value -= this->step();
    return it;
  }
  iterator&
  operator+=(difference_type d) noexcept
  {
    this->_value += d * this->step();
    return *this;
  }
  iterator&
  operator-=(difference_type d) noexcept
  {
    this->_value -= d * this->step();
    return *this;
  }
  constexpr iterator
  operator+(difference_type d) const noexcept
  { return iterator(this->value() + d * this->step(), this->step()); }
  constexpr iterator
  operator-(difference_type d) const noexcept
  { return iterator(this->value() - d * this->step(), this->step()); }
  constexpr difference_type
  operator-(iterator const& rhs) const noexcept
  {
    return ( (  static_cast<difference_type>(this->value())
              - static_cast<difference_type>(rhs.value()) )
            +(  static_cast<difference_type>(this->value())
              - static_cast<difference_type>(rhs.value()) ) % rhs.step()
           ) / rhs.step();
  }
  constexpr value_type
  operator* () const noexcept
  { return this->value(); }
  constexpr value_type
  operator [](difference_type i) const noexcept
  { return this->value() + i * this->step(); }
  constexpr bool
  operator==(iterator rhs) const noexcept
  { return this->value() == rhs.value(); }
  constexpr bool
  operator!=(iterator rhs) const noexcept
  { return this->value() != rhs.value(); }
  constexpr bool
  operator<(iterator rhs) noexcept
  {
    return ((this->step() < 0) == (rhs.step() < 0)) ?
      ( (this->step() >= 0) ?
        this->value() < rhs.value():
        this->value() > rhs.value() )
      : false ;
  }
  constexpr bool
  operator>(iterator rhs) noexcept
  {
    return ((this->step() < 0) == (rhs.step() < 0)) ?
      ( (this->step() >= 0) ?
        this->value() > rhs.value():
        this->value() < rhs.value() )
      : false ;
  }
  constexpr bool
  operator<=(iterator rhs) noexcept
  {
    return ((this->step() < 0) == (rhs.step() < 0)) ?
      ( (this->step() >= 0) ?
        this->value() <= rhs.value():
        this->value() >= rhs.value() )
      : false ;
  }
  constexpr bool
  operator>=(iterator rhs) noexcept
  {
    return ((this->step() < 0) == (rhs.step() < 0)) ?
      ( (this->step() >= 0) ?
        this->value() >= rhs.value():
        this->value() <= rhs.value() )
      : false ;
  }
};

namespace std {
template < typename IntT, typename DiffT >
constexpr DiffT
distance(clxx::detail::integer_iterator<IntT, DiffT> const& first,
         clxx::detail::integer_iterator<IntT, DiffT> const& last) noexcept
{
  return last - first;
}
} // end namespace std

template <typename T, typename IntT, typename DiffT>
constexpr integer_iterator<IntT, DiffT>
operator+ (T d, integer_iterator<IntT, DiffT> const& it) noexcept
{
  return it + d;
}

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
  IntT  _start;
  IntT  _stop;
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
  typedef integer_iterator<IntT, DiffT> iterator;
public:
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range() noexcept
    : _start(0), _stop(0), _step(1)
  { }
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range(value_type stop) noexcept
    : _start(0), _stop(stop), _step((stop >= 0)? 1 : -1)
  { }
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range(value_type start, value_type stop) noexcept
    : _start(start), _stop(stop), _step((stop >= start) ? 1 : -1)
  { }
  /** // doc: integer_range() {{{
   * \todo Write documentation
   */ // }}}
  constexpr integer_range(value_type start, value_type stop, difference_type step) noexcept
    : _start(start), _stop(stop), _step(step)
  { }
  /** // doc: start() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type start() const noexcept
  { return this->_start; }
  /** // doc: stop() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type stop() const noexcept
  { return this->_stop; }
   /** // doc: step() {{{
   * \todo Write documentation
   */ // }}}
  constexpr difference_type step() const noexcept
  { return this->_step; }
  /** // doc: low() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type low() const noexcept
  { return this->start() <= this->stop() ? this->start() : this->stop(); }
  /** // doc: high() {{{
   * \todo Write documentation
   */ // }}}
  constexpr value_type high() const noexcept
  { return this->start() >= this->stop() ? this->start() : this->stop(); }
  /** // doc: begin() {{{
   * \todo Write documentation
   */ // }}}
  constexpr iterator begin() const noexcept
  { return iterator(this->start(), this->step()); }
  /** // doc: end() {{{
   * \todo Write documentation
   */ // }}}
  constexpr iterator end() const noexcept
  {
    return iterator(
        this->stop() + (static_cast<difference_type>(this->stop())
                      - static_cast<difference_type>(this->start()))
          % this->step(),
        this->step()
    );
  }
  /** // doc: includes() {{{
   * \todo Write documentation
   */ // }}}
  constexpr bool includes(value_type x) const noexcept
  {
    return (x >= this->low()) && (x <= this->high()) && (x != this->stop()) &&
           (( static_cast<difference_type>(x) -
              static_cast<difference_type>(this->start()) ) % this->step() == 0);
  }
  /** // doc: size() {{{
   * \todo Write documentation
   */ // }}}
  constexpr size_type size() const noexcept
  { return (this->end() - this->begin()); }
};

} } // end namespace clxx::detail

#endif /* CLXX_C4N_DETAIL_INTEGER_RANGE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
