// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/config.hpp

/** // doc: clxx/c4n/config.hpp {{{
 * \file clxx/c4n/config.hpp
 * \brief Configuration and preprocessor macros used across clxx project
 */ // }}}
#ifndef CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED
#define CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED

#include <clxx/c4n/config_params.hpp>
#include <clxx/c4n/compiler_config.hpp>

#if defined(_WIN32)
# define CLXX_WINDOWS_API
#else
# define CLXX_POSIX_API
#endif

#endif /* CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
