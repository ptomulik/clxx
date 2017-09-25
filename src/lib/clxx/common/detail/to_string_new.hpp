// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/common/detail/to_string_new.hpp

/** // doc: clxx/common/detail/to_string_new.hpp {{{
 * \file clxx/common/detail/to_string_new.hpp
 * \brief Conversions of several types of data to string
 *
 * This header implements overloaded std::to_string for several types defined
 * in clxx.
 */ // }}}
#ifndef CLXX_COMMON_DETAIL_TO_STRING_NEW_HPP_INCLUDED
#define CLXX_COMMON_DETAIL_TO_STRING_NEW_HPP_INCLUDED

#include <clxx/common/config.hpp>
#include <clxx/common/detail/enum2hex.hpp>
#include <string>
#include <type_traits>
#if CLXX_NO_STD_TO_STRING_NEW
# include <limits>
#endif

namespace clxx{ namespace detail {
template<int N, typename T>
inline std::string
to_string_impl(T val, const char* fmt)
{
  char buf[N+1];
  std::sprintf(buf, fmt, val);
  return std::string(buf);
}
} } // end namespace clxx::detail

namespace clxx {
#if CLXX_NO_STD_TO_STRING_NEW
/** // doc: to_string(int) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(int val)
{ return detail::to_string_impl<4*sizeof(int)>(val, "%d"); }
/** // doc: to_string(long) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(long val)
{ return detail::to_string_impl<4*sizeof(long)>(val, "%ld"); }
/** // doc: to_string(long long) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(long long val)
{ return detail::to_string_impl<4*sizeof(long long)>(val, "%lld"); }
/** // doc: to_string(unsigned) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(unsigned val)
{ return detail::to_string_impl<4*sizeof(unsigned)>(val, "%u"); }
/** // doc: to_string(unsigned long) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(unsigned long val)
{ return detail::to_string_impl<4*sizeof(unsigned long)>(val, "%lu"); }
/** // doc: to_string(unsigned long long) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(unsigned long long val)
{ return detail::to_string_impl<4*sizeof(unsigned long long)>(val, "%llu"); }
/** // doc: to_string(float) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(float val)
{
  constexpr int n = std::numeric_limits<float>::max_exponent10 + 20;
  return detail::to_string_impl<n>(val, "%f");
}
/** // doc: to_string(double) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(double val)
{
  constexpr int n = std::numeric_limits<double>::max_exponent10 + 20;
  return detail::to_string_impl<n>(val, "%f");
}
/** // doc: to_string(long double) {{{
 * \todo Write documentation
 */ // }}}
inline std::string to_string(long double val)
{
  constexpr int n = std::numeric_limits<long double>::max_exponent10 + 20;
  return detail::to_string_impl<n>(val, "%f");
}
#else
using std::to_string;
#endif
} // end namespace clxx

namespace clxx {
/** \ingroup clxx_common_util_enum2str clxx_common_detail
 * @{ */
/** // doc: enum_to_name_of_hex {{{
 * \brief Convert an enum value to its string representation
 *
 * For most values of enums defined in <tt>clxx/common/types.hpp</tt> it returns a
 * string representation of enum value (name of enum). For the values not
 * recognized by the library, however, it returns a string representation
 * of a hexadecimal value of the enum.
 *
 * \param x The value to be converted
 * \returns String representation of the value \em x
 */ // }}}
template<typename E>
std::string enum_to_name_or_hex(E x)
{
  char const* name = clxx::detail::enum2name(x);
  return name ? std::string(name) : detail::enum2hex(x);
}
/** // doc: enum_to_name_of_hex {{{
 * \brief Convert an enum value to string interpreting it as a bitmask
 *
 * Generates a string composed of or'ed values of enum-bits that are present
 * in the provided value \em x.
 *
 * \param x The value to be converted
 * \param end Final value of a moving bit when the function stops scanning for
 *            active bits in the bit-field \em x
 * \returns The string representation of the bits contained in \em x
 *
 * \par Example
 *
 * The invocation:
 *
 * \code
 *  s = enum_bitmask_to_string(device_type_t::cpu | device_type_t::gpu);
 * \endcode
 *
 * shall return string <tt>"cpu | gpu"</tt>
 */ // }}}
template<typename E>
std::string enum_bitmask_to_string(E x, typename std::underlying_type<E>::type end = 0)
{
  typedef typename std::underlying_type<E>::type T;
  T const t = static_cast<T>(x);
  if(t == static_cast<T>(0))
    {
      return enum_to_name_or_hex(x);
    }
  else
    {
      std::string result;
      std::string sep;
      for (T bit = 1; bit != end; bit <<= 1)
        {
          if(t & bit)
            {
              result += (sep + enum_to_name_or_hex(static_cast<E>(bit)));
              sep = " | ";
            }
        }
      return result;
    }
}
/** @} */
} // end namespace clxx

#endif /* CLXX_COMMON_DETAIL_TO_STRING_NEW_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
