#include <iostream>

class Computer {
  public:
    void turnOn() const { std::cout << "Turning on computer\n"; }
    void logIn() const { std::cout << "Logging into computer\n"; }
    void checkingForMeetings() const { std::cout << "Checking for meetings\n"; }
};

class Meetings {
  public:
    void walk() { std::cout << "Walking into my meeting\n"; }
    void talk() { std::cout << "I am talking in my meeting\n"; }
    void exit() { std::cout << "I am exiting my meeting\n"; }
};

class ExitBuilding {
  public:

    void walkingOut() { std::cout << "I am walking out the building\n"; }
};

int main() {
  Computer computer;
  Meetings meet;
  ExitBuilding exit;

  computer.turnOn();
  computer.logIn();
  computer.checkingForMeetings();

  meet.walk();
  meet.talk();
  meet.exit();

  exit.walkingOut();
  return 0;
}
