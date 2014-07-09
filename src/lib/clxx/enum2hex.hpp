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

// clxx/to_string.hpp

/** // doc: clxx/to_string.hpp {{{
 * \file clxx/to_string.hpp
 * \brief Conversions of several types of data to string
 *
 * This header implements overloaded std::to_string for several types defined
 * in clxx.
 */ // }}}
#ifndef CLXX_ENUM2HEX_HPP_INCLUDED
#define CLXX_ENUM2HEX_HPP_INCLUDED

#include <string>
#include <type_traits>

#include <tml/string.hpp>
#include <tml/num_to_string.hpp>
#include <tml/join.hpp>
#include <tml/c_str.hpp>
#include <tml/sequence.hpp>

namespace clxx { namespace detail {

template<typename T>
  struct enum_hex_fmt_prec
    : tml::join<
        tml::string<'.'>
      , typename tml::num_to_string_c<std::size_t,sizeof(T)*2>::type
      >
  { };

template<typename T>
  struct enum_hex_fmt_argt
  {
    typedef typename tml::string<> type;
  };

template<>
  struct enum_hex_fmt_argt<signed char>
  { typedef typename tml::string<'h','h'> type; };
template<>
  struct enum_hex_fmt_argt<signed short>
  { typedef typename tml::string<'h'> type; };
template<>
  struct enum_hex_fmt_argt<signed long>
  { typedef typename tml::string<'l'> type; };
template<>
  struct enum_hex_fmt_argt<signed long long>
  { typedef typename tml::string<'l','l'> type; };
template<>
  struct enum_hex_fmt_argt<size_t>
  { typedef typename tml::string<'z'> type; };

template<typename T>
  struct enum_hex_fmt
    : tml::join<
        typename tml::join<
          tml::string<'%','#'>
        , typename enum_hex_fmt_prec<T>::type
        >::type
      , typename tml::join<
          typename enum_hex_fmt_argt<T>::type
        , tml::string<'x'>
        >::type
      >
  { };

} } // end namespace clxx::detail

namespace clxx {

/** // doc: enum2hex(x) {{{
 * \todo Write documentation
 */ // }}}
template<typename E>
std::string enum2hex(E x)
{
  typedef typename std::underlying_type<E>::type T;
  constexpr size_t size = 5 + 2 * sizeof(T);
  T t = static_cast<T>(x);
  char buf[size];
  typedef typename detail::enum_hex_fmt<T>::type fmt;
  std::snprintf(buf, size, tml::c_str<fmt>::value, static_cast<T>(x));
  return std::string(buf);
}

} // end namespace clxx
#endif /* CLXX_ENUM2HEX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
