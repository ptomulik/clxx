// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/compiler_config.hpp

/** // doc: clxx/c4n/compiler_config.hpp {{{
 * \file clxx/c4n/compiler_config.hpp
 * \brief Configuration and preprocessor macros used across clxx project
 */ // }}}
#ifndef CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED
#define CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED

#include <clxx/config.h>

#if defined(__clang__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("clang diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("clang diagnostic pop")
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
# define CLXX_DISABLE_COMMENT_WARNING _Pragma("clang diagnostic ignored \"-Wcomment\"")
# define CLXX_DISABLE_IGNORED_ATTRIBUTES_WARNING
#elif defined(__GNUC__)
# define CLXX_DIAGNOSTIC_PUSH _Pragma("GCC diagnostic push")
# define CLXX_DIAGNOSTIC_POP _Pragma("GCC diagnostic pop")
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
# define CLXX_DISABLE_COMMENT_WARNING _Pragma("GCC diagnostic ignored \"-Wcomment\"")
# define CLXX_DISABLE_IGNORED_ATTRIBUTES_WARNING _Pragma("GCC diagnostic ignored \"-Wignored-attributes\"")
#elif defined(_MSC_VER)
# define CLXX_DIAGNOSTIC_PUSH __pragma(warning( push ))
# define CLXX_DIAGNOSTIC_POP __pragma(warning( pop ))
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING __pragma(warning( disable : 4996 ))
# define CLXX_DISABLE_COMMENT_WARNING
# define CLXX_DISABLE_IGNORED_ATTRIBUTES_WARNING
#elif defined(SWIG) || defined(DOXYGEN)
/** // doc: CLXX_DIAGNOSTIC_PUSH {{{
 * \brief Push the configuration of compiler diagnostics
 *
 * This usually is defined as an appropriate \c pragma directive which pushes
 * settings such as warning verbosity, enabled/disabled compiler diagnostics
 * etc., such that they can be later restored.
 *
 * For example, if GCC is used, then it's defined as _Pragma("GCC diagnostic push")
 */ // }}}
# define CLXX_DIAGNOSTIC_PUSH
/** // doc: CLXX_DIAGNOSTIC_POP {{{
 * \brief Pop the configuration of compiler diagnostics
 *
 * This usually is defined as an appropriate \c pragma directive which restores
 * settings such as warning verbosity, enabled/disabled compiler diagnostics
 * etc., previously pushed with \ref CLXX_DIAGNOSTIC_PUSH.
 *
 * For example, if GCC is used, then it's defined as _Pragma("GCC diagnostic pop")
 */ // }}}
# define CLXX_DIAGNOSTIC_POP
/** // doc: CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING {{{
 * \brief Disable "deprecated declaration"
 *
 * This disables warnings normally triggered by a compiler when a deprecated
 * function or other compound is used in code. For example, in gcc a function
 * with <tt>__attribute((deprecated))__</tt> would yield such warning (\c
 * -Wdeprecated-declaration), and it may be disabled with
 *  CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING (which, in this case, equals to
 *  _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")).
 */ // }}}
# define CLXX_DISABLE_DEPRECATED_DECLARATION_WARNING
/** // doc: CLXX_DISABLE_COMMENT_WARNING {{{
 * \brief Disable warnings about ill formed C/C++ comments
 *
 * For example, on GCC this resolves to _Pragma("GCC diagnostic ignored \"-Wcomment\"")).
 */ // }}}
# define CLXX_DISABLE_COMMENT_WARNING
/** // doc: CLXX_DISABLE_IGNORED_ATTRIBUTES_WARNING {{{
 * \brief Disable warnings about ignored attributes
 *
 * For example, on GCC this resolves to _Pragma("GCC diagnostic ignored \"-Wignored-attributes\"")).
 */ // }}}
# define CLXX_DISABLE_IGNORED_ATTRIBUTES_WARNING
#endif

#if defined(_WIN32)
# define CLXX_WINDOWS_API
#else
# define CLXX_POSIX_API
#endif

#endif /* CLXX_C4N_COMPILER_CONFIG_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
