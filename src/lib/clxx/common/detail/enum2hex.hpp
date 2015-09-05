// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/enum2hex.hpp

/** // doc: clxx/common/detail/enum2hex.hpp {{{
 * \file clxx/common/detail/enum2hex.hpp
 * \brief Provides #enum2hex() function
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_ENUM2HEX_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_ENUM2HEX_HPP_INCLUDED

#include <string>
#include <type_traits>
#include <cmath>
#include <cstdio>

namespace clxx { namespace detail {
/** \addtogroup clxx_util_enum2str
 * @{ */
/** // doc: enum_hex_fmt_prec {{{
 * \brief Generates the \em precision part of the formating string for integers
 *
 * Helper template used by \ref clxx::detail::enum_hex_fmt "enum_hex_fmt".
 * It's responsible for generating the <tt>[.precision]</tt> part of the format
 * specifier that is generated by \ref clxx::detail::enum_hex_fmt "enum_hex_fmt".
 *
 * For a given integer type T, the function returns a compile-time string
 * starting with dot "." and followed by the minimum number of hexadecimal
 * digits to be written by \c printf (and cousins) when printing a value of
 * type \c T as a hexadecimal number.
 *
 * \tparam T must be an integral type
 */ // }}}
template<typename T>
  struct enum_hex_fmt_prec
  {
    /** doc: apply() {{{
     * \brief The generator
     */ // }}}
    static void
    apply(char*& s)
    {
      constexpr const int n = sizeof(T) * 2;
      static_assert(n < 100, "");
      if(n > 10)
        *s++ = '0' + n/10;
      *s++ = '0' + n%10;
    }
  };

/** // doc: enum_hex_fmt_len {{{
 * \brief Generates the \em type part of the formating string for integers
 *
 * Helper template used by \ref clxx::detail::enum_hex_fmt "enum_hex_fmt".
 * It's responsible for generating the type specifier part of the format
 * specifier that is generated by \ref clxx::detail::enum_hex_fmt
 * "enum_hex_fmt" (for example \c 'h' for <tt>signed char</tt> or <tt>signed
 * short</tt> and \c 'l' for <tt>signed long</tt>).
 *
 * \tparam T must be an integral type
 */ // }}}
template<typename T>
  struct enum_hex_fmt_len
  {
    /** doc: apply() {{{
     * \brief The generator
     */ // }}}
    static void apply(char*&) {} 
  };
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
  struct enum_hex_fmt_len<signed char>
  { static void apply(char*& s) { *s++ = 'h'; *s++ = 'h'; } };
template<>
  struct enum_hex_fmt_len<signed short>
  { static void apply(char*& s) { *s++ = 'h'; } };
template<>
  struct enum_hex_fmt_len<signed long>
  { static void apply(char*& s) { *s++ = 'l'; } };
template<>
  struct enum_hex_fmt_len<signed long long>
  { static void apply(char*& s) { *s++ = 'l'; *s++ = 'l'; } };
template<>
  struct enum_hex_fmt_len<size_t>
  { static void apply(char*& s) { *s++ = 'z'; } };
/** \endcond */

/** // doc: enum_hex_fmt {{{
 * \brief Generate formatting string for integers
 *
 * Helper template used by #enum2hex().
 *
 * Generates a formating string for use with \c printf and similar functions to
 * represent integers of different type in hexadecimal form. The string has
 * form <tt>"0x%.PSx"</tt> or <tt>"-0x%.PSx"</tt>, where \c P stands for
 * precision specifier and \c S is type specifier (\c x is a verbatim character
 * in the formatting string). The two specifiers \c P and \c S are determined
 * automatically for given integer type \p T.
 *
 * For example,
 * \code
 *    char buf[16];
 *    char* s;
 *    detail::enum_hex_fmt<signed short>::apply(s = buf);
 * \endcode
 * would write <tt>"0x%.4hx"</tt> to \c buf.
 *
 * The construction and interpretation of the formatting strings is explained
 * in the <a href="http://www.cplusplus.com/reference/cstdio/printf/">C++
 * reference page for printf</a>.
 *
 * \tparam T must be an integer type,
 */ // }}}
template< typename T >
struct enum_hex_fmt
{
  /** doc: apply() {{{
   * \brief The generator
   */ // }}}
  static void
  apply(char* s)
  {
    *s++ = '0';
    *s++ = 'x';
    *s++ = '%';
    *s++ = '.';
    enum_hex_fmt_prec<T>::apply(s);
    enum_hex_fmt_len<T>::apply(s);
    *s++ = 'x';
    *s = '\0';
  }
};
/** @} */
} } // end namespace clxx::detail

namespace clxx { namespace detail {
/** \addtogroup clxx_util_enum2str
 * @{ */
/** // doc: enum2hex(x) {{{
 * \brief Convert enum value to a string in hexadecimal representation
 *
 * Clxx defines a number of enum classes to represent certain features, error
 * codes and so on. Most of their values may be represented in human readable
 * form by functions such as #enum2cstr() of #enum2name(). It may happen,
 * however, that some of the values are not handled by these functions (for
 * example, they are not implemented yet). For such cases the #enum2hex()
 * function is used as a fallback.
 *
 * \param x the value to be converted, must be a value of enum type
 * \returns string which represents numerical value of \p x in hexadecimal form
 */ // }}}
template<typename E>
std::string enum2hex(E x)
{
  typedef typename std::underlying_type<E>::type T;
  constexpr size_t buf_size = 5 + 2 * sizeof(T);
  constexpr size_t fmt_size = 16;
  T t = static_cast<T>(x);
  char buf[buf_size];
  char fmt[fmt_size];
  if (t < 0)
    {
      *fmt = '-';
      detail::enum_hex_fmt<T>::apply(fmt+1);
      t = -t;
    }
  else
    {
      detail::enum_hex_fmt<T>::apply(fmt);
    }
#if CLXX_NO_STD_SNPRINTF
  std::sprintf(buf, fmt, t);
#else
  std::snprintf(buf, buf_size, fmt, t);
#endif
  return std::string(buf);
}
/** @} */
} } // end namespace clxx::detail
#endif /* CLXX_COMMON_DETAIL_ENUM2HEX_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
