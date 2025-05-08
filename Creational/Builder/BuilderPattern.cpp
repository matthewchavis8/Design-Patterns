#include <iostream>
#include <string_view>

class House {
  public:
      int walls;
      std::string_view roof;
      std::string_view door;
      int windows;
      std::string_view garage;
      std::string_view garden;
      std::string_view pool;

      House() 
      : walls{ 0 }
      , windows{ 0 }
      {}

      void display() const {
        std::cout << "House: " << walls << '\n'
        << roof << " roof, " << '\n'
        << door << " door," << '\n'
        << windows << " windows" << '\n';
        if (!garage.empty()) 
          std::cout << ", garage: " << garage << '\n';
        
        if (!garden.empty()) 
          std::cout << ", garden: " << garden << '\n';
        
        if (!pool.empty()) 
          std::cout << ", pool: " << pool << '\n';

        std::cout << '\n';
      }
};

class HouseBuilder {
  private:  
    House m_house;
  public:
    HouseBuilder& buildWalls (int cnt) {
      m_house.walls = cnt;
      return *this;
    }

    HouseBuilder& buildRoof (std::string_view type) {
      m_house.roof = type;
      return *this;
    }
    HouseBuilder& addDoor (std::string_view type) {
      m_house.door = type;
      return *this;
    }
    HouseBuilder& addWindows (int cnt) {
      m_house.windows = cnt;
      return *this;
    }
    HouseBuilder& addGarage (std::string_view description) {
      m_house.garage = description;
      return *this;
    }
    HouseBuilder& addPool (std::string_view description) {
      m_house.pool = description;
      return *this;
    }
    HouseBuilder& addGarden (std::string_view description) {
      m_house.garden = description;
      return *this;
    }

    House createHouse() { return m_house; }
};

class Director {
  public:
  House constructSimpleHouse (HouseBuilder& builder) {
    return builder.buildWalls(4)
                  .buildRoof("shingle")
                  .addDoor("wooden")
                  .addWindows(4)
                  .createHouse();
  }
  House constructLuxuryHouse (HouseBuilder& builder) {
    return builder.buildWalls(4)
                  .buildRoof("Title")
                  .addDoor("reinforced")
                  .addWindows(8)
                  .addGarage("two-car")
                  .addGarden("large")
                  .addPool("infinity")
                  .createHouse();
  }
};

int main() {
  HouseBuilder builder;
  Director director;

  House simpleHouse = director.constructSimpleHouse(builder);
  House luxuryHouse = director.constructLuxuryHouse(builder);
  
  simpleHouse.display();
  luxuryHouse.display();
}
