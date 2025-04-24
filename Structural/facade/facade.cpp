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

class Day {
  private:
    Computer& m_computer;
    Meetings& m_meet;
    ExitBuilding& m_build;
  public:
    Day(Computer& computer, Meetings& meet, ExitBuilding& build)
      : m_computer{ computer }
      , m_meet{ meet }
      , m_build{ build }
    {}

    void startDay() {
      m_computer.turnOn();
      m_computer.logIn();
      m_computer.checkingForMeetings();

      m_meet.walk();
      m_meet.talk();
      m_meet.exit();

      m_build.walkingOut();
    }
};

int main() {
  Computer computer;
  Meetings meet;
  ExitBuilding exit;

  Day day(computer, meet, exit);

  day.startDay();
  return 0;
}
