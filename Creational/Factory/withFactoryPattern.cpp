#include <iostream>
#include <string_view>
#include <memory>

class Animal {
  public:
      virtual void speak() = 0;
      virtual ~Animal() {}
};

class Cat : public Animal {
  public:
    void speak() override { std::cout << "Hey I am a cat meow meow!" << '\n'; }
};

class Dog : public Animal {
  public:
    void speak() override { std::cout << "Hey I am a dog bark bark!" << '\n'; }
};

class Factory {
  public:
      std::unique_ptr<Animal> createAnimal(std::string_view animal) {
        if (animal == "Cat") 
          return std::make_unique<Cat>();
        else if (animal == "Dog") 
          return std::make_unique<Dog>();

        return nullptr;
      }

      ~Factory() {}
};

int main() {
  Factory factory;
  std::unique_ptr<Animal> animal = factory.createAnimal("Cat");

  animal->speak();

  return 0;
}
