#include <iostream> 

class Animal {
  public:
      virtual void speak() = 0;
      virtual ~Animal() {}
};

class Dog : public Animal {
  public:
    void speak() override { std::cout << "This Dog is barking" << '\n'; }
};

class Cat : public Animal {
  public:
      void speak() override { std::cout << "This Cat is meowing" << '\n'; }
};


class Rabbit : public Animal {
  public:
      void speak() override { std::cout << "This Rabbit is meeping" << '\n'; }
};

class Duck : public Animal {
  public:
      void speak() override { std::cout << "This Duck is quacking" << '\n'; }
};

int main() {
  Animal* dog = new Dog();
  Animal* cat = new Cat();

  dog->speak();
  cat->speak();

  delete dog;
  delete cat;

  return 0;
}
