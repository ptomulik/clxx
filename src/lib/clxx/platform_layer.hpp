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

// clxx/platform_layer.hpp

/** // doc: clxx/platform_layer.hpp {{{
 * \file clxx/platform_layer.hpp
 * \todo Write documentation
 */ // }}}
#ifndef CLXX_PLATFORM_LAYER_HPP_INCLUDED
#define CLXX_PLATFORM_LAYER_HPP_INCLUDED

#include <clxx/platforms.hpp>
#include <clxx/devices.hpp>

#include <clxx/platform_layer_info.hpp>
#include <clxx/platform_query.hpp>
#include <clxx/device_query.hpp>

#include <set>
#include <map>
#include <vector>

namespace clxx {

/** // doc: class platform_layer {{{
 * \ingroup Clxx_Cl_platform
 * \todo Write documentation
 */ // }}}
class platform_layer
{
public:
  typedef std::vector<cl_platform_id> platform_ids;
  typedef std::vector<cl_device_id> device_ids;
  typedef std::map<cl_device_id, cl_platform_id> device_platform_map;
  typedef std::map<cl_platform_id, device_ids > platform_devices_map;
public:
  /** // doc: platform_layer() {{{
   * \todo Write documentation
   */ // }}}
  platform_layer();
  /** // doc: ~platform_layer() {{{
   * \todo Write documentation for class platform_layer
   */ // }}}
  virtual ~platform_layer();
  /** // doc: get_platforms() {{{
   * \todo Write documentation
   */ // }}}
  platforms get_platforms() const;
  /** // doc: get_devices() {{{
   * \todo Write documentation
   */ // }}}
  devices get_devices() const;
  /** // doc: get_devices(platform const&) {{{
   * \todo Write documentation
   */ // }}}
  devices get_devices(platform const&) const;
  /** // doc: get_platform(device const&) {{{
   * \todo Write documentation
   */ // }}}
  platform get_platform(device const&) const;
private:
  void _init();
  void _insert(cl_platform_id id);
  void _insert(cl_platform_id platform_id, cl_device_id id);
  void _insert(cl_platform_id platform_id, device_ids const& ids);
  platform_ids _platform_ids;
  device_ids _device_ids;
  device_platform_map _device_platform_map;
  platform_devices_map _platform_devices_map;
};

/** // doc: query_platform_layer_info(layer,pquery,dquery) {{{
 * \todo Write documentation
 */ // }}}
platform_layer_info
query_platform_layer_info(
    platform_layer const& layer = platform_layer(),
    platform_query const& pquery = platform_query(),
    device_query const& dquery = device_query()
);

} // end namespace clxx

#endif /* CLXX_PLATFORM_LAYER_HPP_INCLUDED */
// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
