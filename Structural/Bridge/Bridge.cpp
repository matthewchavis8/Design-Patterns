
#include <iostream>
#include <string_view>


struct Color {
  public:
    virtual ~Color() = default;
    virtual std::string_view name() const = 0;
};

struct Red : public Color { std::string_view name() const override { return "Red"; }};

struct Blue : public Color { std::string_view name() const override { return "Blue"; }};

struct Yellow : public Color { std::string_view name() const override { return "Yellow"; }};

struct Green : public Color { std::string_view name() const override { return "Green"; }};


class Shape {
  private:
    int m_height{};
    int m_width{};
    int m_sides{};
    std::string_view m_name{};
    Color& m_color; 
  
  public:
    Shape(int height, int width, int sides, std::string_view name, Color& color)
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
        << "Shape's color: " << m_color.name() << '\n'
        << '\n';
    }
};

class Circle : public Shape {
  public:
    Circle(int size, Color& c) 
      : Shape(size, size, 0, "Circle", c)
      {}
};

int main() {
  Red red;
  Blue blue;

  Circle c1(100, red);
  Circle c2(100, blue);

  c1.print();
  c2.print();
}
