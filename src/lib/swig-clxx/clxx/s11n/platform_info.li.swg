// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/s11n/platform_info.li.swg {{{
 * \file clxx/s11n/platform_info.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/s11n/platform_info.hpp>
#include <clxx/s11n/boost_archives.hpp>
#include <clxx/s11n/shared_ptr.hpp>
%}

%include <clxx/s11n/platform_info.hpp>
%import <clxx/s11n/boost_archives.swg>
%import <clxx/common/shared_ptr.swg>
CLXX_EXTEND_BOOST_ARCHIVES(clxx::platform_info);
CLXX_EXTEND_BOOST_ARCHIVES(CLXX_SHARED_PTR(clxx::platform_info));

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
