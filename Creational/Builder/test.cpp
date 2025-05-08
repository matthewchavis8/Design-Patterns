
#include <iostream>
#include <string_view>
class Chair {
  private:
      int m_legs;
      std::string_view m_armRest;
      std::string_view m_color;
      std::string_view m_type;
  public:
      Chair() : m_legs{ 0 } {}

      void setLegs(int num) { m_legs = num; }

      void setArmRest(std::string_view armRest) { m_armRest = armRest; }

      void setColor(std::string_view color) { m_color = color; }

      void setType(std::string_view type) { m_type = type; }

      const void print() const {
        std::cout << "The chair has " << m_legs << '\n'
        << "The armRest is " << m_armRest << '\n'
        << "The chair's color is " << m_color << '\n'
        << "The chair's type is " << m_type << '\n';
      }
};

class ChairBuilder {
  private:
      Chair m_chair;
  public:
      ChairBuilder& createLegs(int num) {
        m_chair.setLegs(num);
        return *this;
      }

      ChairBuilder& createColor(std::string_view color) {
        m_chair.setColor(color);
        return *this;
      }

      ChairBuilder& createArmRest(std::string_view armRest) {
        m_chair.setArmRest(armRest);
        return *this;
      }
      
      ChairBuilder& createType(std::string_view type) {
        m_chair.setType(type);
        return *this;
      }

      Chair createChair() { return m_chair; }
};

class Director {
  public:
      Chair createSimpleChair(ChairBuilder& builder) {
        return builder
          .createColor("Red")
          .createArmRest("simle arm rest")
          .createLegs(4)
          .createType("Wood")
          .createChair();
      }
      Chair createLuxuryChair(ChairBuilder& builder) {
        return builder
          .createColor("Red")
          .createArmRest("simle arm rest")
          .createLegs(4)
          .createType("metal")
          .createChair();
      }
};

int main() {
  ChairBuilder builder;
  Director director;

  Chair simpleChair = director.createSimpleChair(builder);
  Chair luxuryChair = director.createLuxuryChair(builder);
  
  simpleChair.print();
  luxuryChair.print();
  return 0;
}
