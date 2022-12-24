#include <boost/ut.hpp>
#include <pqrs/osx/launch_services.hpp>

int main(void) {
  using namespace boost::ut;
  using namespace boost::ut::literals;
  using namespace std::literals::string_literals;

  "register_application"_test = [] {
    expect(pqrs::osx::launch_services::register_application("/System/Applications/TextEdit.app").to_string() == "noErr");
  };

  return 0;
}
