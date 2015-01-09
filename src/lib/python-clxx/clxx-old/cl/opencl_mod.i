// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/opencl_mod.i {{{
 * \file clxx/cl/opencl_mod.i
 * \todo Write documentation
 */ // }}}

%module(package="clxx_.cl") opencl_mod
%feature("autodoc","3");
%include <clxx/cl/opencl_mod.swg>
%pythoncode %{

# Attempt to load wrapper for a most recent available OpenCL version. This is
# best we can do. The other option would be to find actual version of the
# OpenCL API, but for that we had to query platform info. This initializes
# OpenCL platform which usually takes few seconds. We can't wait so long to
# just get a version number. Here we recognize enemy with fire and take first
# succesfull shot as a result.
CLXX_OPENCL_VERSION = None
if (CLXX_OPENCL_VERSION is None) and (CLXX_OPENCL_CL_H_VERSION_2_0 == 1):
  try:
    from clxx_.cl.opencl2_0 import *
    CLXX_OPENCL_VERSION = "2.0"
  except ImportError:
    pass

if (CLXX_OPENCL_VERSION is None) and (CLXX_OPENCL_CL_H_VERSION_1_2 == 1):
  try:
    from clxx_.cl.opencl1_2 import *
    CLXX_OPENCL_VERSION = "1.2"
  except ImportError:
    pass

if (CLXX_OPENCL_VERSION is None) and (CLXX_OPENCL_CL_H_VERSION_1_1 == 1):
  try:
    from clxx_.cl.opencl1_1 import *
    CLXX_OPENCL_VERSION = "1.1"
  except ImportError:
    pass

if (CLXX_OPENCL_VERSION is None) and (CLXX_OPENCL_CL_H_VERSION_1_0 == 1):
  from clxx_.cl.opencl1_1 import *
  CLXX_OPENCL_VERSION = "1.0"

%}

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
