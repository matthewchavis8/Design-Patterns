
# Creational Design Patterns

Creational design patterns focus on **how objects are created**. Instead of instantiating objects directly using constructors, these patterns provide flexible and reusable object creation mechanisms. This helps ensure your code is decoupled from specific classes, making it easier to manage, extend, and test.

---

### **Abstract Factory**

**Provides an interface for creating families of related or dependent objects without specifying their concrete classes.** Useful when the **system needs to be independent** of how its objects are created.

### **Builder**

**Separates the construction of a complex object from its representation, allowing the same construction process to create different representations.** Ideal when objects **require numerous configuration steps**.

### **Factory**

Defines an **interface for creating an object but allows subclasses or methods to alter the type of object that will be created**. This promotes loose coupling by eliminating the need to bind application-specific classes into your code.

### **Prototype**

**Creates new objects by copying an existing object, known as the prototype**. This is particularly **useful when the cost of creating a new instance is expensive or complex**.

### **Singleton**

Ensures that **a class has only one instance and provides a global point of access to it**. Commonly **used for managing shared resources like configuration settings or a logging service**.
