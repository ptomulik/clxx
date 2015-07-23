// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/program_lazy_generator.cpp {{{
 * \file clxx/cl/program_lazy_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/program_lazy_generator.hpp>
#include <clxx/common/exceptions.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_program(clxx::context const& context) const
{
  // To be thread-safe we have to protect mutable member(s)
  // _programs_mutex is automatically released when lock goes out of scope
  std::lock_guard<std::mutex> lock(this->_programs_mutex);

  memoized_programs_t::const_iterator it{ this->_programs.find(context) }; 

  if(it != _programs.cend())
    return it->second;

  return _programs[context] = this->program_generator::get_program(context);
}
/* ----------------------------------------------------------------------- */
clxx::program program_lazy_generator::
get_memoized_program(clxx::context const& context) const
{
  // To be thread-safe we have to protect mutable member(s)
  // _programs_mutex is automatically released when lock goes out of scope
  std::lock_guard<std::mutex> lock(this->_programs_mutex);

  memoized_programs_t::const_iterator it{ this->_programs.find(context) }; 

  if(it == _programs.cend())
    throw invalid_key_error("memoized program not found");

  return it->second;
}
/* ----------------------------------------------------------------------- */
size_t program_lazy_generator::
discard_memoized_program(clxx::context const& context) const
{
  // To be thread-safe we have to protect mutable member(s)
  // _programs_mutex is automatically released when lock goes out of scope
  std::lock_guard<std::mutex> lock(this->_programs_mutex);
  return _programs.erase(context);
}
/* ----------------------------------------------------------------------- */
void program_lazy_generator::
discard_memoized_programs() const
{
  // To be thread-safe we have to protect mutable member(s)
  // _programs_mutex is automatically released when lock goes out of scope
  std::lock_guard<std::mutex> lock(this->_programs_mutex);
  _programs.clear();
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
