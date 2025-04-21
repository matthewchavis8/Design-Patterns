#include <iostream>
#include <string_view>

class Shape {
  private:
    int m_height{};
    int m_width{};
    int m_sides{};
    std::string_view m_name{};
    std::string_view m_color{};
  public:
    Shape(int height, int width, int sides, std::string_view name, std::string_view color)
      : m_height{ height }
      , m_width{ width }
      , m_sides{ sides }
      , m_name{ name }
      , m_color{ color }
    {}

    void print() {
      std::cout << "Shape name: " << m_name << '\n'
        << "Shape's height: " << m_height << '\n'
        << "Shape's width: " << m_width << '\n'
        << "Shape's sides: " << m_sides << '\n'
        << "Shape's color: " << m_color << '\n'
        << '\n';
    }
};

class RedCircle : public Shape {
  public: 
    RedCircle()
    : Shape(100, 50, 0, "Circle", "Red")
    {}
};

class BlueCirlce : public Shape {
  public: 
    BlueCirlce()
    : Shape(100, 50, 0, "Circle", "Blue")
    {}
};

int main() {
  RedCircle circle;
  BlueCirlce cirlce2;
  circle.print();
  cirlce2.print();

}
