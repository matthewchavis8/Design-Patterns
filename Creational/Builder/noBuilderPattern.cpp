#include <iostream>
#include <string_view>
using  std::cout;


class House {
  private:  
    int m_walls;
    std::string_view m_roof;
    std::string_view m_door;
    int m_windows;
    std::string_view m_garage;
    std::string_view m_garden;
    std::string_view m_pool;
  
  public: 
    House(int walls, std::string_view roof, std::string_view door, int windows, 
      std::string_view garage = "", std::string_view garden = "", std::string_view pool =     "")
    : m_walls { walls }
    , m_roof { roof }
    , m_door { door }
    , m_windows { windows }
    , m_garage { garage }
    , m_garden { garden }
    , m_pool { pool }
    {}

    void display() const {
      cout << "House: " << m_walls << " \nwalls, " << m_roof << " \nroof, "
             << m_door << " \ndoor, " << m_windows << " \nwindows";
        
        if (!m_garage.empty()) 
          cout << "\n, garage: " << m_garage;
        if (!m_garden.empty()) 
          cout << "\n, garden: " << m_garden;
        if (!m_pool.empty()) 
          cout << "\n, pool: " << m_pool;
        cout << '\n' << '\n';
    }
};

int main() {
    House simpleHouse(4, "shingle", "wooden", 4);
    
    House luxuryHouse(4, "tile", "reinforced", 8, "two-car", "large", "infinity");
    
    simpleHouse.display();
    luxuryHouse.display(); 

    return 0;
}
