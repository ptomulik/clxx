// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/common/clerror.li.swg {{{
 * \file clxx/common/clerror.li.swg
 * \todo Write documentation
 */ // }}}

%{
#include <clxx/common/clerror.hpp>
%}
%include <clxx/common/clerror.hpp>

// instantiate commonly used specializations of clxx::exception_base
%template(exception_base_logic_clerror) clxx::exception_base<clxx::clerror,std::logic_error>;

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
