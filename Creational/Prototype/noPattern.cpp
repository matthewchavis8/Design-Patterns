#include <iostream>
#include <string_view>

class Monster {
  private:
    std::string_view m_name;
    int m_health;
    std::string_view m_weapon;
  public:
    Monster(std::string_view name, int health, std::string_view weapon)
      : m_name{ name }
      , m_health{ health }
      , m_weapon{ weapon }
      {}
    const void print() const {
      std::cout << "Monster: " << m_name << '\n'
        << "Health: " << m_health << '\n'
        << "weapon: " << m_weapon << '\n'
        << '\n';
    }
};

int main (int argc, char *argv[]) {
  Monster orc("Orc", 100, "club");
  Monster orc1("Orc", 100, "Bat");
  Monster orc2("Orc", 100, "gun");

  orc.print();
  orc1.print();
  orc2.print();


  return 0;
}
