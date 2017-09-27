// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/b3c/program_fcn.cpp {{{
 * \file clxx/b3c/program_fcn.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/b3c/program_fcn.hpp>
#include <clxx/b3c/program.hpp>
#include <clxx/b3c/programs.hpp>
#include <clxx/b3c/context.hpp>
#include <clxx/b5d/functions.hpp>
#include <clxx/b3c/detail/obj2cl.hpp>
#include <clxx/c4n/exceptions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
void
build_program(clxx::program const& program,
              std::string const& options)
{
  build_program(
      program.chk_get(),
      0ul,
      NULL,
      options.data(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(clxx::program const& program,
              clxx::devices const& devices,
              std::string const& options)
{
  build_program(
      program.chk_get(),
      devices.size(),
      detail::obj2cl(devices),
      options.data(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(clxx::program const& program,
              std::string const& options,
              clxx::program_observer& observer)
{
  build_program(
      program.chk_get(),
      0ul,
      NULL,
      options.data(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
void
build_program(clxx::program const& program,
              clxx::devices const& devices,
              std::string const& options,
              clxx::program_observer& observer)
{
  build_program(
      program.chk_get(),
      devices.size(),
      detail::obj2cl(devices),
      options.data(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
#if CLXX_B5D_PROVIDES(compile_program)
/* ------------------------------------------------------------------------ */
static boost::shared_array<char const*>
_cstrings(program_sources const& sources)
{
  typedef boost::shared_array<char const*> array;
  array a(new char const*[sources.size()]);
  auto op =  [](program_source const& b) -> char const* { return b.data(); };
  std::transform(sources.begin(), sources.end(), a.get(), op);
  return a;
}
/* ----------------------------------------------------------------------- */
void
compile_program(clxx::program const& program,
                std::string const& options,
                clxx::programs const& input_headers,
                std::vector<std::string> const& header_include_names)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      program.chk_get(),
      0ul,
      NULL,
      options.data(),
      input_headers.size(),
      detail::obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(clxx::program const& program,
                std::string const& options,
                clxx::programs const& input_headers,
                std::vector<std::string> const& header_include_names,
                clxx::program_observer& observer)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      program.chk_get(),
      0ul,
      NULL,
      options.data(),
      input_headers.size(),
      detail::obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(clxx::program const& program,
                clxx::devices const& devices,
                std::string const& options,
                clxx::programs const& input_headers,
                std::vector<std::string> const& header_include_names)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      program.chk_get(),
      devices.size(),
      detail::obj2cl(devices),
      options.data(),
      input_headers.size(),
      detail::obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      NULL,
      NULL
  );
}
/* ----------------------------------------------------------------------- */
void
compile_program(clxx::program const& program,
                clxx::devices const& devices,
                std::string const& options,
                clxx::programs const& input_headers,
                std::vector<std::string> const& header_include_names,
                clxx::program_observer& observer)
{
  if(input_headers.size() != header_include_names.size())
    throw invalid_argument_error();

  compile_program(
      program.chk_get(),
      devices.size(),
      detail::obj2cl(devices),
      options.data(),
      input_headers.size(),
      detail::obj2cl(input_headers),
      _cstrings(header_include_names).get(),
      observer.fcn_ptr(),
      observer.fcn_arg()
  );
}
/* ----------------------------------------------------------------------- */
#endif // CLXX_B5D_PROVIDES(compile_program)
#if CLXX_B5D_PROVIDES(link_program)
/* ----------------------------------------------------------------------- */
program
link_program(clxx::context const& context,
             clxx::devices const& device_list,
             std::string const& options,
             clxx::programs const& input_programs)
{
  return clxx::program(
    link_program(
      context.chk_get(),
      device_list.size(),
      detail::obj2cl(device_list),
      options.data(),
      input_programs.size(),
      detail::obj2cl(input_programs),
      nullptr,
      nullptr
    )
  );
}
/* ----------------------------------------------------------------------- */
program
link_program(clxx::context const& context,
             clxx::devices const& device_list,
             std::string const& options,
             clxx::programs const& input_programs,
             clxx::program_observer& observer)
{
  return clxx::program(
    link_program(
      context.chk_get(),
      device_list.size(),
      detail::obj2cl(device_list),
      options.data(),
      input_programs.size(),
      detail::obj2cl(input_programs),
      observer.fcn_ptr(),
      observer.fcn_arg()
    )
  );
}
#endif // CLXX_B5D_PROVIDES(link_program)
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
