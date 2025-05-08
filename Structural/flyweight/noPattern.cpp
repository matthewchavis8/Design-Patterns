#include <iostream>
#include <string_view>
#include <vector>

enum TreeType {
  Oak,
  Birchwood,
  Redwood,
  Magnolia
};

class Tree {
  private:
    int m_x {};
    int m_y {};
    TreeType m_type{};
  
  public:
    Tree(int x, int y, TreeType type)
    : m_x{ x }
    , m_y{ y }
    , m_type{ type }
    {}

    void display() const {
      auto printTreeType = [&]() {
        switch (m_type) {
          case 0:
            std::cout << "Oak";
            break;
          case 1:
            std::cout << "Birchwood";
            break;
          case 2: 
            std::cout << "Redwood";
            break;
          case 3: 
            std::cout << "Magnolia";
            break;
          default:
            std::cout << "Unknown";
        }
      };

      std::cout 
        << "The type of tree is: ";
      printTreeType();

      std::cout << '\n' << "The x coordinate is: " << m_x << '\n'
      << "The y coordinate is: " << m_y << '\n' << '\n';
    }
};

int main() {
  std::vector<Tree> forest;

  for (int i{}; i < 1000; ++i) {
    forest.push_back( {i, i, TreeType::Redwood} ); 
  }

  for (int i{1000}; i < 2000; ++i) {
    forest.push_back( {i, i, TreeType::Magnolia} ); 
  }

  for (const auto& tree : forest) 
    tree.display();
  return 0; 
}
