#include <iostream>

class Cat {
  public:
      void speak() { std::cout << "Hey I am a cat meow meow!" << '\n'; }
      ~Cat() {}
};


class Dog {
  public:
      void speak() { std::cout << "Hey I am a dog ruff ruff!" << '\n'; }
      ~Dog() {}
};

/**
 * Issue with this is that as you can see everyhting is hard coded
 * If I want to create a object I have to hard code the creation of a new animal
 * Hence factories are a thing where we encapsulate the process of creating 
 * a new object to a factory so we separate things from producers and products
 * in thsi case Cat and Dog will become a product and we create a producer Factory 
 * that is in charge of creating our objects no hard coding
 * 
 * */

int main() {
  Cat cat;
  Dog dog;
  
  cat.speak();
  dog.speak();

  return 0;
}
