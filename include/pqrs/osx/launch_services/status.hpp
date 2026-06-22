#pragma once

// (C) Copyright Takayama Fumihiko 2022.
// Distributed under the Boost Software License, Version 1.0.
// (See https://www.boost.org/LICENSE_1_0.txt)

#include <CoreServices/CoreServices.h>
#include <ostream>
#include <string>

namespace pqrs::osx::launch_services {

class status final {
public:
  status(OSStatus s) noexcept : status_(s) {
  }

  [[nodiscard]] OSStatus get() const noexcept {
    return status_;
  }

  [[nodiscard]] std::string to_string() const {
#define PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(OSSTATUS) \
  case OSSTATUS:                                              \
    return #OSSTATUS;

    switch (status_) {
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(noErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSAppInTrashErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSUnknownErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSNotAnApplicationErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSDataUnavailableErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSApplicationNotFoundErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSDataErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSLaunchInProgressErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSServerCommunicationErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSCannotSetInfoErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSIncompatibleSystemVersionErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSNoLaunchPermissionErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSNoExecutableErr);
      PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING(kLSMultipleSessionsNotSupportedErr);
    }

#undef PQRS_OSX_LAUNCH_SERVICES_OSSTATUS_TO_STRING

    return std::string("Unknown OSStatus (") + std::to_string(status_) + ")";
  }

  [[nodiscard]] bool no_error() const noexcept {
    return status_ == noErr;
  }

  [[nodiscard]] operator bool() const noexcept {
    return no_error();
  }

private:
  OSStatus status_;
};

inline std::ostream& operator<<(std::ostream& stream, const status& value) {
  return stream << value.to_string();
}

} // namespace pqrs::osx::launch_services
