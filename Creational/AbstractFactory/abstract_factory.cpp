#include <iostream> 
#include <memory>


// Animal Base Class
class Animal {
  public:
      virtual void speak() = 0;
      virtual ~Animal() {}
};

// Products of our 4 legs
class Dog : public Animal {
  public:
    void speak() override { std::cout << "This Dog is barking" << '\n'; }
};

class Cat : public Animal {
  public:
      void speak() override { std::cout << "This Cat is meowing" << '\n'; }
};

// Products with 2 legs
class Rabbit : public Animal {
  public:
      void speak() override { std::cout << "This Rabbit is meeping" << '\n'; }
};

class Duck : public Animal {
  public:
      void speak() override { std::cout << "This Duck is quacking" << '\n'; }
};

class Animal_Factory {
  public:
      virtual std::unique_ptr<Animal> createAnimal(const std::string& type) = 0;
      virtual ~Animal_Factory() {} 
};

class TwoLegAnimalFactory : public Animal_Factory {
  public:
    std::unique_ptr<Animal> createAnimal(const std::string &type) override {
      if (type == "Rabbit")
        return std::make_unique<Rabbit>();
      else if (type == "Duck")
        return std::make_unique<Duck>();
      else {
        std::cerr << "Type does not exist" << '\n';
        return nullptr;
      }
    }
};

class FourLegAnimalFactory : public Animal_Factory {
  public:
    std::unique_ptr<Animal> createAnimal(const std::string &type) override {
        if (type == "Dog")
          return std::make_unique<Dog>();
        else if (type == "Cat")
          return std::make_unique<Cat>();
        else {
          std::cerr << "Type does not exist" << '\n';
          return nullptr;
        }
      }
};

void runTwoLegFactory(const std::string& type) {
    auto factory = std::make_unique<TwoLegAnimalFactory>();
    auto animal = factory->createAnimal(type);
    
    animal->speak();
}

void runFourLegFactory(const std::string& type) {
  auto factory = std::make_unique<FourLegAnimalFactory>();
  auto animal = factory->createAnimal(type);

  animal->speak();
}

int main() {
  runTwoLegFactory("Rabbit");
  runFourLegFactory("Dog");
  return 0;
}
