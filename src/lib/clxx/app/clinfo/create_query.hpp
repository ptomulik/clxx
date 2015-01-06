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

// clxx/app/clinfo/build_platform_query.hpp

/** // doc: clxx/app/clinfo/build_platform_query.hpp {{{
 * \file clxx/app/clinfo/build_platform_query.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED
#define CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED

#include <clxx/platform_query.hpp>
#include <clxx/device_query.hpp>
#include <clxx/app/options/options_map.hpp>

namespace clxx { namespace app { namespace clinfo {

/** // {{{
 * \todo Write documentation
 */ // }}}
clxx::platform_query
create_platform_query(clxx::app::options::options_map const& optmap);
clxx::device_query
create_device_query(clxx::app::options::options_map const& optmap);

} } } // end namespace clxx::app::clinfo

#endif /* CLXX_APP_CLINFO_CREATE_QUERY_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
