// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/b5d/config.hpp

/** // doc: clxx/b5d/config.hpp {{{
 * \file clxx/b5d/config.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_B5D_CONFIG_HPP_INCLUDED
#define CLXX_B5D_CONFIG_HPP_INCLUDED

#include <clxx/b5d/config_params.hpp>
#include <clxx/b5d/config_cl_fcn.hpp>

#if defined(_WIN32)
# define CLXX_B5D_API_ENTRY
# define CLXX_B5D_API_CALL  __stdcall
# define CLXX_B5D_CALLBACK  __stdcall
#else
# define CLXX_B5D_API_ENTRY
# define CLXX_B5D_API_CALL
# define CLXX_B5D_CALLBACK
#endif

#define CLXX_B5D_OPENCL_PROVIDES(sym) \
    CLXX_B5D_OPENCL_DECLARES_ ## sym

#define CLXX_B5D_PROVIDES(sym) CLXX_B5D_PROVIDES_ ## sym

#ifdef __APPLE__
# error Apple is not supported yet
#else
# ifdef __GNUC__
#   define CLXX_B5D_DEPRECATION_PREFIX
#   define CLXX_B5D_DEPRECATION_SUFFIX __attribute__((deprecated))
# elif defined(_WIN32)
#   define CLXX_B5D_DEPRECATION_PREFIX _declspec(deprecated)
#   define CLXX_B5D_DEPRECATION_SUFFIX
# else
#   define CLXX_B5D_DEPRECATION_PREFIX
#   define CLXX_B5D_DEPRECATION_SUFFIX
# endif
#endif

#define CLXX_B5D_PREFIX_DEPRECATED(f) CLXX_B5D_PREFIX_DEPRECATED_ ## f
#define CLXX_B5D_SUFFIX_DEPRECATED(f) CLXX_B5D_SUFFIX_DEPRECATED_ ## f
#define CLXX_B5D_API_PREFIX(f) CLXX_B5D_API_ENTRY CLXX_B5D_PREFIX_DEPRECATED(f)
#define CLXX_B5D_API_SUFFIX(f) CLXX_B5D_SUFFIX_DEPRECATED(f)

#endif /* CLXX_B5D_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
