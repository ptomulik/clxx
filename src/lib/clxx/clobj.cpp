// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/clobj.cpp {{{
 * \file clxx/clobj.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/clobj.hpp>
#include <clxx/clobj_impl.hpp>

namespace clxx {
template class clobj<cl_command_queue>;
template class clobj<cl_context>;
template class clobj<cl_device_id>;
template class clobj<cl_event>;
template class clobj<cl_kernel>;
template class clobj<cl_mem>;
template class clobj<cl_platform_id>;
template class clobj<cl_program>;
#if 0
template class clobj<cl_sampler>;
#endif

static_assert(
    sizeof(clobj<cl_command_queue>) == sizeof(cl_command_queue),
    "sizeof(clobj<cl_command_queue>) differs from sizeof(cl_command_queue)"
);
static_assert(
    sizeof(clobj<cl_context>) == sizeof(cl_context),
    "sizeof(clobj<cl_context>) differs from sizeof(cl_context)"
);
static_assert(
    sizeof(clobj<cl_device_id>) == sizeof(cl_device_id),
    "sizeof(clobj<cl_device_id>) differs from sizeof(cl_device_id)"
);
static_assert(
    sizeof(clobj<cl_event>) == sizeof(cl_event),
    "sizeof(clobj<cl_event>) differs from sizeof(cl_event)"
);
static_assert(
    sizeof(clobj<cl_kernel>) == sizeof(cl_kernel),
    "sizeof(clobj<cl_kernel>) differs from sizeof(cl_kernel)"
);
static_assert(
    sizeof(clobj<cl_mem>) == sizeof(cl_mem),
    "sizeof(clobj<cl_mem>) differs from sizeof(cl_mem)"
);
static_assert(
    sizeof(clobj<cl_platform_id>) == sizeof(cl_platform_id),
    "sizeof(clobj<cl_platform_id>) differs from sizeof(cl_platform_id)"
);
static_assert(
    sizeof(clobj<cl_program>) == sizeof(cl_program),
    "sizeof(clobj<cl_program>) differs from sizeof(cl_program)"
);
#if 0
static_assert(
    sizeof(clobj<cl_sampler>) == sizeof(cl_sampler),
    "sizeof(clobj<cl_sampler>) differs from sizeof(cl_sampler)"
);
#endif
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
