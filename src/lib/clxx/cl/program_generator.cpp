// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator.cpp {{{
 * \file clxx/cl/program_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_generator.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
program_generator::
~program_generator()
{
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_namespace() const
{
  return "";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_full_name() const
{
  return program_namespace() + "::" + program_name();
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_file_suffix() const
{
  return ".cl";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_dir() const
{
  return "";
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_file() const
{
  return program_name() + program_file_suffix();
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
program_path() const
{
  std::string path(this->program_dir());
  if(!path.empty())
    if(path.back() != '/')
      path.push_back('/');
  path.append(this->program_file());
  return path;
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
line_directive(size_t line) const
{
  return "#line " + std::to_string(line) + " \"" + this->program_path() + "\"";
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
get_program(clxx::context const& context) const
{
  std::string src;
  this->generate_program_source(src, context);
  return clxx::program(context, clxx::program_sources{ src });
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

namespace clxx {
/* ----------------------------------------------------------------------- */
void
generate_and_build_program(clxx::program& program,
                           clxx::program_generator const& program_generator,
                           clxx::command_queue const& command_queue,
                           std::string const& build_options)
{
  clxx::context context{ command_queue.get_context() };
  clxx::device device{ command_queue.get_device() };

  program = program_generator.get_program(context);
  build_program(program, clxx::devices{ device }, build_options);
}
/* ----------------------------------------------------------------------- */
void
generate_and_lazy_build_program(clxx::program& program,
                                clxx::program_generator const& program_generator,
                                clxx::command_queue const& command_queue,
                                std::string const& build_options)
{
  clxx::context context{ command_queue.get_context() };
  clxx::device device{ command_queue.get_device() };

  program = program_generator.get_program(context);

  build_status_t status = program.get_build_status(device);
  // FIXME: thread-safety issue?: we may end-up with two threads trying to
  // build same program for same device. Some thoughts:
  //
  //  - OpenCL calls, including clBuildProgram(), claim to be thread-safe,
  //    but the double invocation of clBuildProgram() from distinct threads may
  //    yield unnecessary computational overhead,
  //  - one thread may start to use cl_program, while it's being built for the
  //    second time by another thread; while the program is being built,
  //    colliding calls to OpenCL API by other threads shall be maintained
  //    appropriately by the thread-safe OpenCL implementation, however
  //  - the problem appears, for example, then two thread call this function
  //    concurrently with all the parameters being same, but with different 
  //    build_options; the result will be surprising for one or more threads,
  //  - the last issue, however, would not be solved by any thread
  //    synchronization mechanisms here.
  //
  // Anyway, it's an interesting question: what happens if we call
  // clBuildProgram() on an already built program (for which the build status
  // is initially CL_BUILD_STATUS_SUCCESS).
  switch(status)
    {
      case build_status_t::none:
      case build_status_t::error:
        build_program(program, clxx::devices{ device }, build_options);
        break;
      default:
        break;
    }
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
