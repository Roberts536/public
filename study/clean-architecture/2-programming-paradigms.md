# Programming paradigms

Part 2 of a summary of *Clean Architecture* by Robert C. Martin.

## Object-oriented programming (OOP)

OOP is traditionally defined as programming that uses encapsulation, inheritance and polymorphism. However:

* Encapsulation already existed before OOP - see `struct` in C
* Inheritance already existed, albeit via casting

So polymorphism is really the defining trait of OOP. It existed before, but only via dangerous function pointers that were easy to forget to implement. (Polymorphism is the ability of classes to behave like their base classes, and is assisted by features like virtual methods).

In summary, OOP is *the ability, through polymorphism, to control every dependency in the system*. This is done via the use of a plugin architecture and dependency inversion, so that modules can be developed and deployed independently.
