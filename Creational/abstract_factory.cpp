#include <iostream> 

class Animal {
  public:
      virtual void speak() = 0;
      virtual ~Animal() {}
};

class Two_Leg_Animals : public Animal {
  public:
      virtual ~Two_Leg_Animals() {}
};

class Four_Leg_Animals : public Animal {
  public:
      virtual ~Four_Leg_Animals() {}
};

class Dog : public Four_Leg_Animals {
  public:
    void speak() override { std::cout << "This Dog is barking" << '\n'; }
};

class Cat : public Four_Leg_Animals {
  public:
      void speak() override { std::cout << "This Cat is meowing" << '\n'; }
};

class Rabbit : public Two_Leg_Animals {
  public:
      void speak() override { std::cout << "This Rabbit is meeping" << '\n'; }
};

class Duck : public Two_Leg_Animals {
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
