#include <iostream>
#include <memory>

class Animal {
  public:
      virtual void speak() = 0;

      virtual ~Animal() {}
};


class Dog : public Animal {
  public:
      void speak() override {
        std::cout << "Hey I am a dog" << 'n';
      }
};



class Cat : public Animal {
  public:
      void speak() override {
        std::cout << "Hey I am a Cat" << 'n';
      }
};

class AnimalFactory {
  public:
      virtual std::unique_ptr<Animal> createAnimal() = 0;
      virtual ~AnimalFactory() {}
};

class DogFactory : public AnimalFactory {
  public:
      std::unique_ptr<Animal> createAnimal() override { return std::make_unique<Dog>(); }
};

class CatFactory : public AnimalFactory {
  public:
      std::unique_ptr<Animal> createAnimal() override { return std::make_unique<Cat>(); }
};

int main() {
  auto factory = std::make_unique<DogFactory>();
  
  auto dog = factory->createAnimal();
  dog->speak();

  return 0;
}
