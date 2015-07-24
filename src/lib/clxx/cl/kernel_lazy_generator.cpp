// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/cl/kernel_lazy_generator.cpp {{{
 * \file clxx/cl/kernel_lazy_generator.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/cl/kernel_lazy_generator.hpp>

namespace clxx {
/* ----------------------------------------------------------------------- */
clxx::kernel kernel_lazy_generator::
get_kernel(clxx::program const& program, std::string const& name) const
{
  std::lock_guard<std::mutex> lock(this->_kernels_mutex);
  memoized_kernels_t::iterator it{ _kernels.find(program) };
  
  if(it != _kernels.end())
    {
      kernel_map_t::const_iterator it2{ it->second.find(name) };
      if(it2 != it->second.end())
        return it2->second;
      return it->second[name] = clxx::kernel{program, name};
    }
  return _kernels[program][name] = clxx::kernel{program, name};
}
/* ----------------------------------------------------------------------- */
void kernel_lazy_generator::
memoize_kernels(clxx::program const& program, std::string const& names) const
{
  for(size_t start = 0ul, end = names.find(';');
      start < names.size();
      start = end+1, end = names.find(';', start))
    {
      std::string name = names.substr(start, end - start);
      if(!name.empty())
        this->get_kernel(program, name);
      // we do this because std::string::npos + 1 == 0
      if(end == std::string::npos)
        break;
    }
}
/* ----------------------------------------------------------------------- */
void kernel_lazy_generator::
memoize_kernels(clxx::program const& program) const
{
  this->memoize_kernels(program, program.get_kernel_names());
}
/* ----------------------------------------------------------------------- */
size_t kernel_lazy_generator::
discard_memoized_kernel(clxx::program const& program, std::string const& name) const
{
  std::lock_guard<std::mutex> lock(this->_kernels_mutex);
  memoized_kernels_t::iterator it{ _kernels.find(program) };
  if(it == _kernels.end())
    return 0;
  return it->second.erase(name);
}
/* ----------------------------------------------------------------------- */
size_t kernel_lazy_generator::
discard_memoized_kernels(clxx::program const& program) const
{
  std::lock_guard<std::mutex> lock(this->_kernels_mutex);
  memoized_kernels_t::iterator it{ _kernels.find(program) };
  if(it == _kernels.end())
    return 0;
  size_t n = it->second.size();
  _kernels.erase(program);
  return n;
}
/* ----------------------------------------------------------------------- */
void kernel_lazy_generator::
discard_memoized_kernels() const
{
  std::lock_guard<std::mutex> lock(this->_kernels_mutex);
  _kernels.clear();
}
/* ----------------------------------------------------------------------- */
} // end namespace clxx
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
