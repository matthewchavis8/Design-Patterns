
#include <iostream>
#include <memory>
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

    std::unique_ptr<Monster> copy() {
      return std::make_unique<Monster>(*this);
    }
};

int main (int argc, char *argv[]) {
  Monster orcPrototype("Orc", 100, "Club");

  auto orc1 = orcPrototype.copy();
  auto orc2 = orcPrototype.copy();
  auto orc3 = orcPrototype.copy();

  orc1->print();
  orc2->print();
  orc3->print();


  return 0;
}
