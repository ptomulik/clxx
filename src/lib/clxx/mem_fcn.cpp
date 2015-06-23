// @COPYRIGHT@
// Licensed under MIT license (LICENSE.txt)

/** // doc: clxx/mem_fcn.cpp {{{
 * \file clxx/mem_fcn.cpp
 * \todo Write documentation
 */ // }}}
#include <clxx/mem_fcn.hpp>
#include <clxx/functions.hpp>
#include <boost/shared_array.hpp>

namespace clxx {
/* ------------------------------------------------------------------------ */
template<typename T, class X>
static boost::shared_array<T>
_identifiers_impl(X const& x)
{
  typedef boost::shared_array<T> array;
  array a(new T[x.size()]);
  auto op =  [](typename X::const_reference d) -> T { return d.id(); };
  std::transform(x.begin(), x.end(), a.get(), op);
  return a;
}
/* ------------------------------------------------------------------------ */
static boost::shared_array<cl_event>
_identifiers(events const& x)
{
  return _identifiers_impl<cl_event, events>(x);
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr,
                    clxx::events const& event_wait_list)
{
  cl_event _event;
  enqueue_read_buffer(command_queue.get_valid_id(),
                      buffer.get_valid_id(),
                      static_cast<cl_bool>(blocking_read),
                      offset,
                      size,
                      ptr,
                      static_cast<cl_uint>(event_wait_list.size()),
                      _identifiers(event_wait_list).get(),
                      &_event);
  return clxx::event(_event);
  // release_event(_event) ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_read_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& buffer,
                    bool blocking_read,
                    size_t offset,
                    size_t size,
                    void* ptr)
{
  cl_event _event;
  enqueue_read_buffer(command_queue.get_valid_id(),
                      buffer.get_valid_id(),
                      static_cast<cl_bool>(blocking_read),
                      offset,
                      size,
                      ptr,
                      0,
                      nullptr,
                      &_event);
  return clxx::event(_event);
  // release_event(_event) ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr,
                     clxx::events const& event_wait_list)
{
  cl_event _event;
  enqueue_write_buffer(command_queue.get_valid_id(),
                       buffer.get_valid_id(),
                       static_cast<cl_bool>(blocking_write),
                       offset,
                       size,
                       ptr,
                       static_cast<cl_uint>(event_wait_list.size()),
                       _identifiers(event_wait_list).get(),
                       &_event);
  return clxx::event(_event);
  // release_event(_event) ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_write_buffer(clxx::command_queue const& command_queue,
                     clxx::mem const& buffer,
                     bool blocking_write,
                     size_t offset,
                     size_t size,
                     const void* ptr)
{
  cl_event _event;
  enqueue_write_buffer(command_queue.get_valid_id(),
                       buffer.get_valid_id(),
                       static_cast<cl_bool>(blocking_write),
                       offset,
                       size,
                       ptr,
                       0,
                       nullptr,
                       &_event);
  return clxx::event(_event);
  // release_event(_event); ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size,
                    clxx::events const& event_wait_list)
{
  cl_event _event;
  enqueue_copy_buffer(command_queue.get_valid_id(),
                      src_buffer.get_valid_id(),
                      dst_buffer.get_valid_id(),
                      src_offset,
                      dst_offset,
                      size,
                      static_cast<cl_uint>(event_wait_list.size()),
                      _identifiers(event_wait_list).get(),
                      &_event);
  return clxx::event(_event);
  // release_event(_event); ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_copy_buffer(clxx::command_queue const& command_queue,
                    clxx::mem const& src_buffer,
                    clxx::mem const& dst_buffer,
                    size_t src_offset,
                    size_t dst_offset,
                    size_t size)
{
  cl_event _event;
  enqueue_copy_buffer(command_queue.get_valid_id(),
                      src_buffer.get_valid_id(),
                      dst_buffer.get_valid_id(),
                      src_offset,
                      dst_offset,
                      size,
                      0,
                      nullptr,
                      &_event);
  return clxx::event(_event);
  // release_event(_event); ???
}
/* ------------------------------------------------------------------------ */
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::events const& event_wait_list,
                   clxx::event& event)
{
  cl_event _event;
  void* result = enqueue_map_buffer(command_queue.get_valid_id(),
                                    buffer.get_valid_id(),
                                    static_cast<cl_bool>(blocking_map),
                                    map_flags,
                                    offset,
                                    size,
                                    static_cast<cl_uint>(event_wait_list.size()),
                                    _identifiers(event_wait_list).get(),
                                    &_event);
  event = clxx::event(_event);
  // release_event(_event); ???
  return result;
}
/* ------------------------------------------------------------------------ */
void*
enqueue_map_buffer(clxx::command_queue const& command_queue,
                   clxx::mem const& buffer,
                   bool blocking_map,
                   map_flags_t map_flags,
                   size_t offset,
                   size_t size,
                   clxx::event& event)
{
  cl_event _event;
  void* result = enqueue_map_buffer(command_queue.get_valid_id(),
                                    buffer.get_valid_id(),
                                    static_cast<cl_bool>(blocking_map),
                                    map_flags,
                                    offset,
                                    size,
                                    0,
                                    nullptr,
                                    &_event);
  event = clxx::event(_event);
  // release_event(_event); ???
  return result;
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr,
                         clxx::events const& event_wait_list)
{
  cl_event _event;
  enqueue_unmap_mem_object(command_queue.get_valid_id(),
                           memobj.get_valid_id(),
                           mapped_ptr,
                           static_cast<cl_uint>(event_wait_list.size()),
                           _identifiers(event_wait_list).get(),
                           &_event);
  return clxx::event(_event);
  // release_event(_event) ???
}
/* ------------------------------------------------------------------------ */
clxx::event
enqueue_unmap_mem_object(clxx::command_queue const& command_queue,
                         clxx::mem const& memobj,
                         void* mapped_ptr)
{
  cl_event _event;
  enqueue_unmap_mem_object(command_queue.get_valid_id(),
                           memobj.get_valid_id(),
                           mapped_ptr,
                           0,
                           nullptr,
                           &_event);
  return clxx::event(_event);
}
/* ------------------------------------------------------------------------ */
} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
