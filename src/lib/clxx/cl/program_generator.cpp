// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_generator.cpp {{{
 * \file clxx/cl/program_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_generator.hpp>
#include <clxx/cl/program.hpp>
#include <clxx/cl/context.hpp>
#include <clxx/cl/command_queue.hpp>
#include <clxx/cl/program_with_source_ctor.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
thread_local shared_ptr<program_generator::program_ctor_t> program_generator::
_default_program_ctor = make_shared<program_generator::program_ctor_t>();
/* ----------------------------------------------------------------------- */
shared_ptr<program_generator::program_ctor_t> program_generator::
get_default_program_ctor()
{
  return _default_program_ctor;
}
/* ----------------------------------------------------------------------- */
void program_generator::
set_default_program_ctor(shared_ptr<program_ctor_t> const& ctor)
{
  _default_program_ctor = ctor;
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
create_program(clxx::context const& context, std::string const& src) const
{
  return _program_ctor ? (*_program_ctor)(context, { src })
                       : (*_default_program_ctor)(context, { src });
}
/* ----------------------------------------------------------------------- */
program_generator::
program_generator()
  : _program_ctor(nullptr)
{
}
/* ----------------------------------------------------------------------- */
program_generator::
program_generator(shared_ptr<program_ctor_t> const& program_ctor)
  : _program_ctor(program_ctor)
{
}
/* ----------------------------------------------------------------------- */
program_generator::
~program_generator()
{
}
/* ----------------------------------------------------------------------- */
void program_generator::
set_program_ctor(shared_ptr<program_ctor_t> const& ctor)
{
  _program_ctor = ctor;
}
/* ----------------------------------------------------------------------- */
shared_ptr<program_generator::program_ctor_t> program_generator::
get_program_ctor() const
{
  return _program_ctor;
}
/* ----------------------------------------------------------------------- */
std::string program_generator::
line_directive(clxx::context const& context, size_t line) const
{
  return "#line " + std::to_string(line) + " \"" + this->program_path(context) + "\"";
}
/* ----------------------------------------------------------------------- */
clxx::program program_generator::
get_program(clxx::context const& context) const
{
  std::string src;
  this->generate_program_source(src, context);
  return this->create_program(context, src);
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
