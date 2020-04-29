# SOLID Design Principles

Part 3 of a summary of *Clean Architecture* by Robert C. Martin.

## Single Responsibility

Each component has only one reason to change.

Many misunderstand this to mean that a component should only do one thing. In fact, it would be more accurate to say that a component should *only be accountable to one stakeholder group*.

If the method for calculating pay is in the `Employee` class, then both HR and finance could have a reason to change it. This is bad design because changes made by one team could affect the other without their knowledge.

## Open-Closed

This principle states that components should be *open for extension but closed for modification*.

For example, if you have a plug socket, you want it to be easy to design a new device to fit with that socket, but you don't want modify the socket itself.

To implement this principle, partition the system into components and arrange them in a dependency hierarchy. Then ensure that, if `Socket` should be protected from changes in `Device`, then `Device` should depend on `Socket` and not the other way around. The component containing the business logic should be at the highest level of privilege, because it should not depend on the design.

This usually involves a lot of interfaces, but it's worth it.

## Liskov Substitution

If you're performing an operation on many objects, they should all be substitutable.

You don't want to change your process depending on what type of input it's receiving. Better to make the inputs inherit or implement a class/interface, and have the process rely on the properties and methods of that class/interface.

## Interface Segregation

Components should not depend on functionality they don't use.

So if `A` depends on only half of `B`'s functionality, it's better to extract that functionality out to an interface and have `A` depend on the interface. That way, if `B` changes in a way that doesn't affect `A`, then `A` doesn't have to be recompiled.

This matters more when the codebase is large because recompilation is costly and you want your releases to be small.

Code written in dynamically typed languages is often more tightly coupled that the same code written in a statically typed language for this reason - that there is no costly recompilation involved.

## Dependency Inversion

This principle is traditionally stated as:

1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
2. Abstractions should not depend on details. Details should depend on abstractions.

At its most extreme, this means that all dependencies are via interfaces. In pracice, we abstract away the *volatile* dependencies.

Another way to see the principle is that the flow of dependency is in the opposite direction to the flow of control.

A few rules of thumb:

* Design interfaces carefully and be reluctant to change them, because a lot depends on them.
* Don't refer to volatile concrete classes, or override them. Obeying this rule often means using an abstract factory.
* Don't derive from volatile concrete classes; inheritance is a strong dependency.
