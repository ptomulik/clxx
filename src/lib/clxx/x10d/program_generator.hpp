// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

// clxx/x10d/program_generator.hpp

/** // doc: clxx/x10d/program_generator.hpp {{{
 * \file clxx/x10d/program_generator.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_X10D_PROGRAM_GENERATOR_HPP_INCLUDED
#define CLXX_X10D_PROGRAM_GENERATOR_HPP_INCLUDED

#include <clxx/x10d/program_generator_fwd.hpp>
#include <clxx/cl/program_fwd.hpp>
#include <clxx/cl/context_fwd.hpp>
#include <clxx/cl/command_queue_fwd.hpp>
#include <clxx/x10d/program_with_source_ctor.hpp>
#include <clxx/common/shared_ptr.hpp>
#include <string>

namespace clxx {
/** // doc: program_generator {{{
 * \ingroup clxx_x10d
 * \brief Abstract base class for OpenCL program generators
 *
 * A program generator object (an instance of program generator class derived
 * from \ref clxx::program_generator "program_generator") generates program
 * source which is then used to create an OpenCL program object. The program is
 * created for an OpenCL \c context given as an argument to generator. The
 * programs created by program generators are NOT assumed to be automatically
 * compiled/built (generators are not responsible for building their generated
 * programs). As such, they MAY require to be built for one or more devices in
 * the \c context before the actual use. Whether the returned programs are
 * already built or not, depends on the program constructor used by the
 * \ref clxx::program_generator "program_generator" object.
 *
 * A program constructor is a C++11 callable object of type
 * \ref clxx::program_with_source_ctor "program_with_source_ctor"
 * (we have a typedef for it, see \ref clxx::program_generator::program_ctor_t "program_ctor_t").
 * The program constructor is pluggable, so each instanace of
 * \ref clxx::program_generator "program_generator" may use its own program
 * constructor. The program constructor may add features to the program
 * generator, such as automatic offline program caching.
 *
 * If not explicitly provided, the \ref clxx::program_generator "program_generator"
 * uses the default program constructor returned by \ref clxx::current_program_with_source_ctor::get()
 * "current_program_with_source_ctor::get()".
 *
 * A program generator class (derived from \ref clxx::program_generator
 * "program_generator") \b MUST implement following virtual methods:
 *
 * - \ref generate_program_source(std::string&, clxx::context const&) const,
 * - \ref program_path(clxx::context const&) const.
 *
 * It also \b MAY overwrite the following virtual methods:
 *
 * - \ref line_directive(clxx::context const&, size_t) const,
 * - \ref get_program(clxx::context const&) const.
 *
 * \par Example
 *
 * Usage example for the \ref clxx::program_generator "program_generator":
 *
 * \snippet clxx/x10d/program_generator1.cpp Program
 */ // }}}
class program_generator
{
public:
  /** // doc: program_ctor_t {{{
   * \brief Type of the pluggable program constructor
   */ // }}}
  typedef clxx::program_with_source_ctor program_ctor_t;
private:
  shared_ptr<program_ctor_t> _program_ctor;
protected:
  /** // doc: create_program() {{{
   * \brief Converts source code to \ref clxx::program "program" object
   *
   * This function uses program constructor (\c program_ctor) plugged-in with
   * #set_program_ctor() or with \ref program_generator(shared_ptr<program_ctor_t> const&)
   * or (if local program_ctor is absent) the thread-current program
   * constructor returned by \ref clxx::current_program_with_source_ctor::get()
   * "current_program_with_source_ctor::get()".
   */ // }}}
  clxx::program create_program(clxx::context const& context, std::string const& src) const;
public:
  /** // doc: program_generator() {{{
   * \brief Default constructor
   */ // }}}
  program_generator();
  /** // doc: program_generator() {{{
   * \brief Constructor with pluggable program constructor
   *
   * \param program_ctor
   *    The program
   */ // }}}
  program_generator(shared_ptr<program_ctor_t> const& program_ctor);
  /** // doc: ~program_generator() {{{
   * \brief Destructor
   */ // }}}
  virtual ~program_generator();
  /** // doc: set_program_ctor() {{{
   * \brief Use new program constructor
   */ // }}}
  void set_program_ctor(shared_ptr<program_ctor_t> const& ctor);
  /** // doc: get_program_ctor() {{{
   * \brief Return program constructor bound to this instance
   *
   * This may return \c nullptr if the program_ctor was not set
   */ // }}}
  shared_ptr<program_ctor_t> get_program_ctor() const;
  /** // doc: generate_program_source(std::string&) {{{
   * \brief Generate program source
   *
   * The \p context may be used by generator to select particular
   * implementation of the program being generated (this enables possible
   * device-dependent optimizations).
   *
   * \param str
   *    The implementation should append its program source to this string,
   * \param context
   *    Specifies the OpenCL contex for which the program is generated.
   */ // }}}
  virtual void generate_program_source(std::string& str, clxx::context const& context) const = 0;
  /** // doc: program_path() {{{
   * \brief Returns the virtual path of the generated program
   *
   * Program path identifies the generated program source. The string returned
   * by #program_path() shall follow syntax of file-system path names. The
   * string returned by #program_path() does not have to point to actual file.
   * #program_path() is used by the #line_directive() method to generate line
   * control stamps in the generated source code. The #program_path() should
   * thus return strings that can be correctly parsed by OpenCL C99 compiler.
   *
   * \param context
   *    A valid \ref clxx::context "context" for which the program is generated
   * \returns program path as c++ string
   */ // }}}
  virtual std::string program_path(clxx::context const& context) const = 0;
  /** // doc: line_directive() {{{
   * \brief Returns a line directive
   *
   * This function shall generate a single line of code of the form
   *
   * \code
   *  #line linenum "program/path"
   * \endcode
   *
   * The \e linenum in the above snippet is the line number as provided in
   * \p linenum parameter, whereas the \e "program/path" is a string
   * returned by the #program_path() method.
   *
   * \param context
   *    A valid \ref clxx::context "context" for which the program is generated
   * \param linenum
   *    Line number, starting from \c 1 for the first line.
   *
   * \returns
   *    The generated line directive as a c++ string
   *
   * \note Inserting the line directive at the beginning of each program source
   *       is a recommended practice. This shall help with identifying
   *       generated programs that have compilation problems. Example:
   * \code
   *  void my_program_generator::
   *  generate_program_source(std::string& src, clxx::context const& context) const
   *  {
   *    // The very first line should be:
   *    src.append(this->line_directive(1)); src.append("\n");
   *    // ...
   *  }
   * \endcode
   */ // }}}
  virtual std::string line_directive(clxx::context const& context, size_t linenum) const;
  /** // doc: get_program() {{{
   * \brief Get the program created for \p context
   *
   * The default implementation invokes the #generate_program_source() for
   * the provided \p context, and returns new instance of \ref clxx::program
   * created from the source generated by #generate_program_source(). It uses
   * #create_program() method to create program from the source code.
   *
   * \param context
   *    A valid OpenCL \ref clxx::context "context"
   */ // }}}
  virtual clxx::program get_program(clxx::context const& context) const;
};
} // end namespace clxx

namespace clxx {
/** // doc: program_generator_ptr {{{
 * \ingroup clxx_x10d
 * \brief Shared pointer to \ref clxx::program_generator "program_generator" object
 *
 * This is used by containers, for example by the generator map in \ref clxx::runtime.
 */ // }}}
typedef shared_ptr<program_generator> program_generator_ptr;
} // end namespace clxx

#endif /* CLXX_X10D_PROGRAM_GENERATOR_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
