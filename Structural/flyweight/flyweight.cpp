#include <iostream>
#include <memory>
#include <string_view>
#include <unordered_map>
#include <utility>
#include <vector>

enum TreeType {
  Oak,
  Birchwood,
  Redwood,
  Magnolia
};

class TreeKind {
  private:
    TreeType m_type;
    std::string_view m_name;

  public:
    TreeKind(TreeType type, std::string_view name)
      : m_type{ type }
      , m_name{ name }
      {}
    void display(int x, int y) const {
      std::cout 
        << "The type of tree is: " << m_name << '\n'
        << "The x coordinate is: " << x << '\n'
        << "The y coordinate is: " << y << '\n' << '\n';
    }
};

class TreeFactory {
  private:
    static std::unordered_map<TreeType, std::shared_ptr<TreeKind>> m_treeTypes;
  public:
    static std::shared_ptr<TreeKind> getTreeType(TreeType type) {
      auto it = m_treeTypes.find(type);

      if (it != m_treeTypes.end())
          return it->second;

      std::string_view name{ "" };

      switch (type) {
        case TreeType::Magnolia:     name = "Magnolia"; break;
        case TreeType::Birchwood:    name = "Magnolia"; break;
        case TreeType::Oak:          name = "Oak";      break;
        case TreeType::Redwood:      name = "Redwood";  break;
        default:                     name = "Unknown";  break;
      }

      auto treeType = std::make_shared<TreeKind>(type, name);
      m_treeTypes[type] = treeType;
      
      return treeType;
    }
};

class Tree {
  private:
    int m_x {};
    int m_y {};
    std::shared_ptr<TreeKind> m_kind;
  
  public:
    Tree(int x, int y, std::shared_ptr<TreeKind> type)
    : m_x{ x }
    , m_y{ y }
    , m_kind{ std::move(type) }
    {}

    void display() const {
      m_kind->display(m_x, m_y);
    }

};
int main() {
  std::vector<Tree> forest;
  
  auto redwoodType = TreeFactory::getTreeType(TreeType::Redwood);
  auto magnoliaType = TreeFactory::getTreeType(TreeType::Magnolia);

  for (int i{}; i < 1000; ++i) 
    forest.emplace_back( i, i, redwoodType ); 

  for (int i{1000}; i < 2000; ++i) 
    forest.emplace_back( i, i, magnoliaType ); 
  
  for (const auto& tree : forest) 
    tree.display();

  return 0; 
}
