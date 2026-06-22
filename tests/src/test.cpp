#include <boost/ut.hpp>
#include <pqrs/osx/launch_services.hpp>

int main() {
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace std::literals::string_literals;

  "status"_test = [] {
    pqrs::osx::launch_services::status no_error(noErr);
    expect(no_error.get() == noErr);
    expect(no_error.no_error());
    expect(static_cast<bool>(no_error));
    expect(no_error.to_string() == "noErr"s);

    pqrs::osx::launch_services::status unknown(-1);
    expect(unknown.get() == -1);
    expect(!unknown.no_error());
    expect(!static_cast<bool>(unknown));
    expect(unknown.to_string() == "Unknown OSStatus (-1)"s);
  };

  "register_application"_test = [] {
    expect(pqrs::osx::launch_services::register_application("/System/Applications/TextEdit.app").to_string() == "noErr"s);
  };

  return 0;
}
