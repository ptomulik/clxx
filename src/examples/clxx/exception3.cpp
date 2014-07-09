/*
 * @COPYRIGHT@
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE
 */

/** // doc: clxx/exception3.cpp {{{
 * \file clxx/exception3.cpp
 * \todo Write documentation
 */ // }}}
/** // doc: \example exception3.cpp {{{
 * \example exception3.cpp
 * This example illustrates the basic technique for extending the hierarchy of
 * clxx exceptions. We define new exception class named \c exception3 based
 * on std::runtime_error. Instead of deriving directly from clxx::exception
 * we use the clxx::exception_base template.
 */ // }}}

// [Includes]
#include <clxx/exception_base.hpp>
// [Includes]

// [ExceptionDefinition]
namespace clxx {
/// \brief Example exception
struct exception3
  : public clxx::exception_base<clxx::exception, std::runtime_error>
  {
    /// \brief Base class
    typedef clxx::exception_base<clxx::exception, std::runtime_error> Base;
    /// \brief Default constructor
    exception3() noexcept : Base("exception3") { }
  };
} /* namespace clxx { */
// [ExceptionDefinition]

// [Test]
#include <iostream>
/// \brief Main function
int main()
{
  // [CatchClxxException1]
  try {
    throw clxx::exception3();
  } catch(clxx::exception3 const& e) {
    std::cout << "A. caught clxx::exception3: " << e.what() << std::endl;
  }
  // [CatchClxxException1]
  // [CatchClxxException]
  try {
    throw clxx::exception3();
  } catch(clxx::exception const& e) {
    std::cout << "B. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  }
  // [CatchClxxException]

  // [CatchStdRuntimeError]
  try {
    throw clxx::exception3();
  } catch(std::runtime_error const& e) {
    std::cout << "C. caught std::runtime_error: " << e.what() << std::endl;
  }
  // [CatchStdRuntimeError]
  
  // [CatchStdException]
  try {
    throw clxx::exception3();
  } catch(std::exception const& e) {
    std::cout << "D. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchStdException]
  
  // [CatchHierarchy]
  try {
    throw clxx::exception3();
  } catch(clxx::exception3 const& e) {
    std::cout << "E. caught clxx::exception3: " << e.what() << std::endl;
  } catch(clxx::exception const& e) {
    std::cout << "E. caught clxx::exception: " << e.clxx2std().what() << std::endl;
  } catch(std::runtime_error const& e) {
    std::cout << "E. caught std::runtime_error: " << e.what() << std::endl;
  } catch(std::exception const& e) {
    std::cout << "E. caught std::exception: " << e.what() << std::endl;
  }
  // [CatchHierarchy]

  return 0;
}
// [Test]

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
