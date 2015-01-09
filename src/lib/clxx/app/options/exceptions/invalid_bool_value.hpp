// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/invalid_bool_value.hpp

/** // doc: clxx/app/options/exceptions/invalid_bool_value.hpp {{{
 * \file clxx/app/options/exceptions/invalid_bool_value.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_BOOL_VALUE_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_BOOL_VALUE_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
/** \cond SHOW_TEMPLATE_SPECIALIZATIONS */
template<>
struct std_except_ctor_arg< boost::program_options::invalid_bool_value>
  { typedef boost::program_options::invalid_bool_value type; };
/** \endcond */
} /* namespace clxx */

namespace clxx { namespace app { namespace options {
/** // doc: invalid_bool_option_value_error {{{
 * \todo Write documentation
 */ // }}}
class invalid_bool_option_value_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_bool_value
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::invalid_bool_value
    > base_;
public:
  /** // doc: invalid_bool_option_value_error(boost::program_options::invalid_bool_value const&) {{{
   * \todo Write documentation
   */ // }}}
  invalid_bool_option_value_error(boost::program_options::invalid_bool_value const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_INVALID_BOOL_VALUE_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
