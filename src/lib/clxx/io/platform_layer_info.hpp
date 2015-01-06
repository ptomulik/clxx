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

// clxx/io/platform_layer_info.hpp

/** // doc: clxx/io/platform_layer_info.hpp {{{
 * @file clxx/io/platform_layer_info.hpp
 * @todo Write documentation
 */ // }}}
#ifndef CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED
#define CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED

#include <clxx/platform_layer_info.hpp>
#include <iosfwd>

namespace clxx { namespace io {

/**
 * \ingroup clxx_io
 * @{
 */
/** // doc: write(os, info, pre) {{{
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 * \param ind   Indentation level.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info, int ind);
/** // doc: write(os, info) {{{
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template <class Ostream> Ostream&
write(Ostream& os, clxx::platform_layer_info const& info);
/** @} */

} } // end namespace clxx::io

/** // doc: os << info {{{
 * \ingroup clxx_io
 * \brief Write out clxx::platform_layer_info object to a stream
 *
 * \param os    Output stream.
 * \param info  Info object to be written out to the stream.
 *
 * \returns     Modified output stream \b os.
 */ // }}}
template<typename _CharT, typename _Traits>
std::basic_ostream<_CharT, _Traits>&
operator << ( std::basic_ostream<_CharT, _Traits>& os
            , clxx::platform_layer_info const& info);

#endif /* CLXX_IO_PLATFORM_LAYER_INFO_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
