#pragma once

// pqrs::osx::launch_services v1.1

// (C) Copyright Takayama Fumihiko 2022.
// Distributed under the Boost Software License, Version 1.0.
// (See https://www.boost.org/LICENSE_1_0.txt)

#include "launch_services/status.hpp"
#include <pqrs/cf/cf_ptr.hpp>
#include <pqrs/cf/string.hpp>

namespace pqrs::osx::launch_services {

[[nodiscard]] inline status register_application(const std::string& path, bool update = true) noexcept {
  if (auto cf_path = pqrs::cf::make_cf_string(path)) {
    if (auto url = pqrs::cf::adopt_cf_ptr(CFURLCreateWithFileSystemPath(nullptr,
                                                                        *cf_path,
                                                                        kCFURLPOSIXPathStyle,
                                                                        true))) {
      return LSRegisterURL(*url, update);
    }
  }

  return kLSUnknownErr;
}

} // namespace pqrs::osx::launch_services
