// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** \defgroup clxx_b5d libclxx_b5d
 * @{ */

/**
 * \defgroup clxx_b5d_functions Functional interface to OpenCL
 *
 * \brief Thin wrappers around OpenCL functions
 *
 * The functions documented in this module provide thin wrappers around OpenCL
 * functions. Their purpose is to:
 *   - introduce \ref clxx_common_exceptions "our exceptions" &mdash; the new
 *     functions throw appropriate \ref clxx_common_exceptions "exceptions" instead of
 *     returning OpenCL error codes,
 *   - introduce \ref clxx_common_types "clxx enumerative types" &mdash; whenever
 *     appropriate, the new functions accept strongly typed enums defined in
 *     \ref clxx/common/types.hpp, instead of the OpenCL's \c CL_* constants,
 *   - introduce cxxtest mocks &mdash; this is used internally for unit
 *     testing.
 */

/** @} */

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
