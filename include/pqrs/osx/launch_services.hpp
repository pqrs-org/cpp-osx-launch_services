#pragma once

// pqrs::osx::launch_services v1.1

// (C) Copyright Takayama Fumihiko 2022.
// Distributed under the Boost Software License, Version 1.0.
// (See https://www.boost.org/LICENSE_1_0.txt)

#include "launch_services/status.hpp"
#include <pqrs/cf/string.hpp>

namespace pqrs {
namespace osx {
namespace launch_services {

inline status register_application(const std::string& path, bool update = true) {
  if (auto cf_path = pqrs::cf::make_cf_string(path)) {
    if (auto url = CFURLCreateWithFileSystemPath(nullptr,
                                                 *cf_path,
                                                 kCFURLPOSIXPathStyle,
                                                 true)) {
      auto s = LSRegisterURL(url, update);
      CFRelease(url);

      return s;
    }
  }

  return kLSUnknownErr;
}

} // namespace launch_services
} // namespace osx
} // namespace pqrs
