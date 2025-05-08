#include <iostream>
#include <string_view>

class Logger {
  private:
    Logger() {}
    // Disables the copy constructor
    Logger(const Logger&) = delete;
    // Disabels copying over from another instance
    Logger& operator=(const Logger&) = delete; 
  public:
    void log(std::string_view msg) { std::cout << "[Log] " << msg << '\n'; }

    static Logger& getInstance() {
      static Logger instance;
      return instance;
    }
};

int main() {
  Logger::getInstance().log("Hello world!");

  // Logger log = Logger::getInstance();

  return 0;
}
