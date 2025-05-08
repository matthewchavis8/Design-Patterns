# Structural Design Patterns

Structural design patterns focus on **how classes and objects are composed to form larger structures**. These patterns help ensure that components work well together, maintain flexibility, and are easier to extend or refactor without rewriting major parts of the system.

---

## Patterns

### Adapter

* **Goal:** Allow incompatible interfaces to work together by wrapping one class with an interface expected by the client.
* **Use case:** When you need to integrate a class with an interface it wasn’t designed to work with.

### Bridge

* **Goal:** Separate an object’s abstraction from its implementation so the two can vary independently.
* **Use case:** When you want to avoid a permanent binding between an abstraction and its implementation.


### Composite

* **Goal:** Treat individual objects and compositions of objects uniformly.
* **Use case:** When dealing with tree structures like file systems, GUI hierarchies, or nested objects.


### Decorator

* **Goal:** Add responsibilities to objects dynamically without altering their structure.
* **Use case:** When you need flexible and reusable alternatives to subclassing for extending behavior.


### Facade

* **Goal:** Provide a simplified interface to a complex subsystem.
* **Use case:** When you want to hide the complexities of a system and provide a cleaner API to clients.


### Flyweight

* **Goal:** Minimize memory usage by sharing common parts of state between multiple objects.
* **Use case:** When many objects share identical data, such as characters in a text editor or game sprites.
