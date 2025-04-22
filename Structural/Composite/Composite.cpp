
#include <algorithm>
#include <memory>
#include <string_view>
#include <utility>
#include <vector>
#include <iostream>

struct OrderItem {
  virtual double getPrice() const = 0;

  virtual ~OrderItem() = default;
};

struct Product : OrderItem {
  std::string_view m_name;
  double m_price;

  Product(std::string_view name, double price)
    : m_name{ name }
    , m_price{ price }
  {}

  double getPrice() const override {
    return m_price;
  }
};

struct Box : OrderItem {
  double packagingCost;

  std::vector<std::unique_ptr<OrderItem>> items;
  
  Box(double cost) : packagingCost(cost) {}
  
  void add(std::unique_ptr<OrderItem> item) {
    items.push_back(std::move(item));
  }

  double getPrice() const override {
    double sum = packagingCost;

    for (auto& pack : items)
      sum += pack->getPrice();

    return sum;
  }
};

int main() {
  std::vector<std::unique_ptr<OrderItem>> order;
  
  // Loose product
  order.push_back(std::make_unique<Product>("Pen", 1.50));

  // Bix Box
  auto bigBox = std::make_unique<Box>(2.00);
  bigBox->add(std::make_unique<Product>("Book", 10.00));
  order.push_back(std::move(bigBox));

  double total{};

  for (const auto& item : order)
    total += item->getPrice();

  std::cout << "Order total: $" << total << '\n';

  return 0;
}
