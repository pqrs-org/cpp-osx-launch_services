#include <iostream>
#include <pqrs/osx/launch_services.hpp>

int main(void) {
  std::cout << "TextEdit: " << pqrs::osx::launch_services::register_application("/System/Applications/TextEdit.app") << std::endl;
  std::cout << "NotFound: " << pqrs::osx::launch_services::register_application("/Applications/NotFound.app") << std::endl;

  return 0;
}
