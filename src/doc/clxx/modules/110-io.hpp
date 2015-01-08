/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE
 */
/**
 * \defgroup clxx_io I/O module
 *
 * This module implements several I/O routines which stream out %clxx objects
 * to output streams in a user-readable form. They may be used for simple
 * diagnostics, debugging or user-interface implementation.
 *
 * The implemented functions cover all the %clxx enum classes defined in
 * clxx/types.hpp and some of the object classes, such as clxx::platform_info.
 * For convenience, we have specialized the "shift" operator (\c <<) for these
 * types and these specializations work with most standard streams. In
 * addition, there are also specialized functions named clxx::io::write which
 * accept additional parameters to tune the output layout (indentation etc.).
 *
 * \par Linking
 *
 * Programs using functions described in this module shall be linked against
 * \c libclxx_io library (\c -lclxx_io).
 *
 */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
