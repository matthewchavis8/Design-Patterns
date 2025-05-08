#include <iostream>
#include <string_view>

class Logger {
  public:
      void log(std::string_view message) { std::cout << "[Log] " << message << '\n'; }
};

int main() {
  Logger log;
  log.log("Hello Matt!");
  return 0;
}
