
# Creational Design Patterns

Creational design patterns focus on **how objects are created**. Rather than instantiating objects directly, these patterns provide flexible and reusable approaches to object creation, promoting clean architecture and decoupled design.


## Patterns

### 🔹 Abstract Factory

- **Goal:** Create families of related objects without specifying their concrete classes.
- **Use case:** When you want to ensure a group of products work together and construction logic should be abstracted.


### 🔹 Builder

- **Goal:** Construct complex objects step-by-step.
- **Use case:** When objects require many configuration steps or need to support different representations.


### 🔹 Factory

- **Goal:** Define an interface for object creation, letting subclasses decide which class to instantiate.
 **Use case:** When object creation should be decoupled from the main logic that uses it.

### 🔹 Prototype

- **Goal:** Create new objects by cloning existing ones.
- **Use case:** When creating a new object is costly or when instances should be copied rather than built from scratch.


### 🔹 Singleton

- **Goal:** Ensure a class has only one instance and provide a global point of access to it.
- **Use case:** When a single shared resource (e.g., logger or config) must be consistently accessed throughout the system.

