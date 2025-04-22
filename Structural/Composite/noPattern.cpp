#include <string_view>
#include <vector>
#include <iostream>

struct Product {
  std::string_view m_name{};
  double m_price{};

  Product(std::string_view name, double price)
    : m_name{ name } 
    , m_price{ price }
  {}
};

struct Box {
  std::vector<Product> products{};
  std::vector<Box>     boxes{};
  double               packagingCost{};
};

double calculateBoxPrice(const Box& box) {
  double total = box.packagingCost;

  for (const auto& product : box.products)
    total += product.m_price;
  
  for (const auto& box : box.boxes)
    total += calculateBoxPrice(box);

  return total;
}

double calculateOrderPrice(
  const std::vector<Product>& looseProducts,
  const std::vector<Box>&     packedBoxes
) {
  double total = 0;

  for (const auto& product : looseProducts)
    total += product.m_price;
  
  for (const auto& box : packedBoxes)
    total += calculateBoxPrice(box);

  return total;
}

int main() {
  Product mario("mario", 5.65);
  Product luigi("luigi", 3.75);
  Product yoishi("mario", 6.87);
  
  Box box;
  box.products.push_back(mario);
  box.products.push_back(luigi);
  box.products.push_back(yoishi);
  
  std::vector<Product> looseProducts;
  std::vector<Box>     packedBoxes{ box };

  double total = calculateOrderPrice(looseProducts, packedBoxes);

  std::cout << "Order Total: $" << total << '\n';
  return 0;
}
