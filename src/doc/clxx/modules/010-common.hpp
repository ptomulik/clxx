// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/**
 * \defgroup clxx_common libclxx_common
 *
 * \brief This module documents contents of \ref clxx_common package
 *
 * The package contains entities that do not directly fit to any other package
 * of the clxx project. You'll find here \ref clxx_types "enumerative types"
 * used across the project, definition of \ref clxx_exceptions "exception classes",
 * and some other specific \ref clxx_util "utilities".
 *
 * \par Linking
 *
 * The libclxx_common is header-only library.
 *
 * @{ */

/**
 * \defgroup clxx_types Types
 *
 * \brief This module documents enumerative types defined by \ref clxx_common
 *        package and functions that provide basic operations on them
 */

/**
 * \defgroup clxx_exceptions Exceptions
 *
 * \brief This module introduces clxx exceptions provided by \ref clxx_common
 *        package
 *
 * <h4>User's view</h4>
 *
 * %Clxx uses exceptions to report errors. A hierarchy of exception classes is
 * developed to represent all errors which may occur in %clxx. This hierarchy
 * may be easily extended when new exceptions are needed.
 *
 * From user's view, the exceptions are categorized as follows:
 * - #clxx::exception - base class for all clxx exceptions
 *   - #clxx::clerror - base class for exceptions originating from OpenCL errors
 *     - #clxx::clerror_no - particular OpenCL errors (template class with OpenCL error code as parameter)
 *     - #clxx::unexpected_clerror - OpenCL error not expected by clxx,
 *   - #clxx::uninitialized_platform_error - a non-OpenCL exception ,
 *   - ... - other exceptions, originating from other source than OpenCL.
 *
 * When handling exception, the user may wish to catch all %clxx exceptions
 * (and ignore others):
 * \code
 *   try {
 *     // ...
 *   } catch(clxx::exception const& e) {
 *     // ...
 *   }
 * \endcode
 * or (s)he may wish to handle only exceptions that fall to a predefined
 * \e category in %clxx &mdash; for example exceptions raised due to OpenCL
 * errors (error codes returned from OpenCL functions converted to exceptions)
 * \code
 *   try {
 *     // ...
 *   } catch (clxx::clerror const& e) {
 *     // ...
 *   }
 * \endcode
 * When necessary, an exception might be tracked down up to a particular error
 * code:
 * \code
 *   try {
 *     // ...
 *   } catch (clxx::clerror_no<clxx::status_t::device_not_found> const& e) {
 *     // ...
 *   }
 * \endcode
 *
 * Each %clxx exception has one of the standard exceptions as its base class,
 * for example \c std::exception, \c std::runtime_error or \c std::logic_error.
 * The following code
 * \code
 *   try {
 *    ...
 *   } catch (const std::exception& e) {
 *     // clxx exceptions also caught here ...
 *   }
 * \endcode
 * will, thus, catch all exceptions including %clxx exceptions.
 *
 * When handling %clxx exception, the standard interface is available via
 * the method \ref clxx::exception::clxx2std() "clxx2std()".
 * \code
 * try {
 *   // ...
 * } catch (clxx::exception const& e) {
 *   std::cout << e.clxx2std().what() << std::endl;
 * }
 * \endcode
 *
 * <h4>Developer's view</h4>
 *
 * Developers should derive new exceptions from clxx::exception_base. It takes
 * a base exception class as the first template argument. The clxx::exception
 * is the first candidate to be put here,
 * \code
 * struct fooerror1
 *   : public clxx::exception_base<clxx::exception, std::exception>
 *   {
 *     // ...
 *   };
 * \endcode
 * but you may also introduce a subclass of clxx::exception to create a new
 * \e category of clxx exceptions
 * \code
 * struct fooerror
 *   : public clxx::exception
 *   {
 *     // ...
 *   };
 * struct fooerror1
 *   : public clxx::exception_base<fooerror, std::exception>
 *   {
 *     // ...
 *   };
 * \endcode
 *
 * Whenever a new \e category has to be implemented, a new base class for the
 * \e category should be defined (a "branch base"). For example, a base
 * for errors returned by OpenCL functions is the clxx::clerror class. The
 * category class should be derived from clxx::exception.
 *
 * For quick start we'll follow the \ref clxx/common/exception3.cpp example. In this
 * example we create a custom exception without a category. Include followig
 * headers
 * \snippet clxx/common/exception3.cpp Includes
 *
 * Next, define within the clxx namespace the new exception class:
 * \snippet clxx/common/exception3.cpp ExceptionDefinition
 *
 * That's all, we can test our new exception with the following program
 * \snippet clxx/common/exception3.cpp Test
 *
 * The output from above program will be the following
 * \verbatim
   user@host:$ ./build/examples/clxx/exception3
   A. caught clxx::exception3: exception3
   B. caught clxx::exception: exception3
   C. caught std::runtime_error: exception3
   D. caught std::exception: exception3
   E. caught clxx::exception3: exception3
   \endverbatim
 *
 * This complete example should give basic understanding about %clxx
 * exceptions. More information about exceptions may be inferred from file
 * and class documentation.
 *
 * \see clxx/common/exception.hpp
 * \see clxx/common/exception_base.hpp
 * \see clxx/common/clerror.hpp
 * \see clxx/common/clerror_base.hpp
 * \see clxx/common/clerror_no.hpp
 * \see clxx/common/exceptions.hpp
 * \see clxx::exception,
 * \see clxx::exception_base,
 * \see clxx::clerror,
 * \see clxx::clerror_base,
 * \see clxx::clerror_no.
 */


/**
 * \defgroup clxx_util Utilities
 *
 * \brief This module documents utility functions and meta-functions provided
 *        by \ref clxx_common package
 * @{
 */
/** \defgroup clxx_util_enum2str Enum to String Conversions
 */
/** \defgroup clxx_util_sha1 SHA-1 Utilities
 */
/** \defgroup clxx_util_current_instance Current Instance
 *
 * This module documents the \ref clxx_util_current_instance "Current Instance"
 * utility. The concept of \ref clxx_util_current_instance "Current Instance"
 * refers to a distinguished instance of a given type with a single point of
 * access in an program. The \ref clxx_util_current_instance "Current Instance"
 * implementation is actually a smart thread-local reference, which at given
 * time points to one of the following:
 *
 * - a static instance, shared between threads, or
 * - a thread_local instance individual to the current thread, or
 * - a user-provided instance (which may be static, thread_local, auto or
 *   whatever makes sense).
 *
 * The static and thread_local instance are managed internally by the
 * \ref clxx::detail::current_instance "detail::current_instance<>" template.
 * The user instance is any suitable instance provided by the user.
 *
 * The template class \ref clxx::detail::current_instance "detail::current_instance<>"
 * may be used to implement current instances of different kinds. See
 * the \ref clxx::detail::current_instance "class reference" for details.
 *
 * Which is the current instance for a given instantiation of
 * \ref clxx::detail::current_instance "detail::current_instance<>" template is
 * determined at runtime and may be changed by user at any time.
 */
 /** \defgroup clxx_util_memoized_function Memoized Function
  */
/** @} */
/** @} */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
