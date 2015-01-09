// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/app/options/exceptions/unknown_option.hpp

/** // doc: clxx/app/options/exceptions/unknown_option.hpp {{{
 * \file clxx/app/options/exceptions/unknown_option.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED
#define CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED

#include <clxx/app/options/exception.hpp>
#include <clxx/exception_base.hpp>
#include <boost/program_options/errors.hpp>

namespace clxx {
template<>
struct std_except_ctor_arg< boost::program_options::unknown_option>
  { typedef boost::program_options::unknown_option type; };
} // end namespace clxx

namespace clxx { namespace app { namespace options {

class unknown_option_error
  : public clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::unknown_option
    >
{
  typedef clxx::exception_base<
      clxx::app::options::exception
    , boost::program_options::unknown_option
    > base_;
public:
  unknown_option_error(boost::program_options::unknown_option const& e)
    : base_(e)
  { }
};

} } } // end namespace clxx::app::options

#endif /* CLXX_APP_OPTIONS_EXCEPTIONS_UNKNOWN_OPTION_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
