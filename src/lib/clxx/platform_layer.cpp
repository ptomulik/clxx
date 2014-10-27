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

// clxx/platform_layer.cpp

/** // doc: clxx/platform_layer.cpp {{{
 * @file clxx/platform_layer.cpp
 * @todo Write documentation
 */ // }}}
#include <clxx/platform_layer.hpp>
#include <clxx/platform.hpp>
#include <clxx/device.hpp>
#include <clxx/cl/mock.hpp>
#include <algorithm>

namespace clxx {

platform_layer::
platform_layer()
{
  _init();
}

platform_layer::
~platform_layer()
{
}

platforms platform_layer::
get_platforms() const
{
  return platforms(this->_platform_ids.begin(), this->_platform_ids.end());
}

devices platform_layer::
get_devices() const
{
  return devices(this->_device_ids.begin(), this->_device_ids.end());
}

devices platform_layer::
get_devices(platform const& p) const
{
  typedef platform_devices_map::const_iterator map_iterator;
  map_iterator found = this->_platform_devices_map.find(p.id());
  if(found == this->_platform_devices_map.end())
    // FIXME: throw an exception (platform with no devices)???
    return devices();
  return devices(found->second.begin(), found->second.end());
}

platform platform_layer::
get_platform(device const& d) const
{
  typedef std::map<cl_device_id,cl_platform_id>::const_iterator iterator;
  iterator found = this->_device_platform_map.find(d.id());
  // FIXME: assert device in _device_platform_map ?
  //if(found == this->_device_platform_map.end())
  //  throw ???;
  return platform(found->second);
}

void platform_layer::
_insert(cl_platform_id id)
{
  if(this->_platform_devices_map.count(id) == 0)
    {
      this->_platform_ids.push_back(id);
      this->_platform_devices_map.insert(std::make_pair(id, device_ids()));
    }
}

void platform_layer::
_insert(cl_platform_id platform_id, cl_device_id id)
{
  if(this->_device_platform_map.count(id) == 0)
    {
      this->_device_ids.push_back(id);
      this->_device_platform_map.insert(std::make_pair(id, platform_id));
      this->_insert(platform_id);
      this->_platform_devices_map[platform_id].push_back(id);
    }
}

void platform_layer::
_insert(cl_platform_id platform_id, device_ids const& ids)
{
  typedef device_ids::const_iterator iterator;
  iterator end(ids.end());
  for(iterator cur(ids.begin()); cur != end; ++cur)
    this->_insert(platform_id, *cur);
}

void platform_layer::
_init()
{
  typedef std::vector<cl_platform_id>::const_iterator iterator;
  std::vector<cl_platform_id> platform_ids(get_platform_ids());
  iterator end( platform_ids.end() );
  for(iterator cur( platform_ids.begin() ); cur != end; ++cur)
    this->_insert(*cur, get_device_ids(*cur));
}

platform_layer_info
query_platform_layer_info(platform_layer const& layer,
                          platform_query const& pquery,
                          device_query const& dquery)
{
  platforms plats(layer.get_platforms());
  platforms::const_iterator pend(plats.end());
  platforms::const_iterator pcur(plats.begin());

  platform_layer_info info;

  for(;pcur != pend; ++pcur)
    {
      platform_info_ptr pinfo(
          new platform_info(
            query_platform_info(*pcur, pquery)
          )
      );
      devices devs(layer.get_devices(*pcur));
      devices::const_iterator dend(devs.end());
      devices::const_iterator dcur(devs.begin());
      for(;dcur != dend; ++dcur)
        {
          info.push_back(
            device_info_ptr(
              new device_info(
                query_device_info(*dcur, dquery)
              )
            ),
            pinfo
          );
        }
    }
  return info;
}

} // end namespace clxx

// vim: set expandtab tabstop=2 shiftwidth=2:
// vim: set foldmethod=marker foldcolumn=4:
