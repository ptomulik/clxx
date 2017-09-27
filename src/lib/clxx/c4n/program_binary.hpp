// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/c4n/program_binary.hpp

/** // doc: clxx/c4n/program_binary.hpp {{{
 * \file clxx/c4n/program_binary.hpp
 * \brief Declares the \ref clxx::program_binary "program_binary" type
 */ // }}}
#ifndef CLXX_C4N_PROGRAM_BINARY_HPP_INCLUDED
#define CLXX_C4N_PROGRAM_BINARY_HPP_INCLUDED

#include <vector>

namespace clxx {
/** // doc: program_binary {{{
 * \ingroup clxx_cl_program_objects
 * \brief A type used to represent OpenCL program binary
 */ // }}}
typedef std::vector<unsigned char> program_binary;
} // end namespace clxx

#endif /* CLXX_C4N_PROGRAM_BINARY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4: