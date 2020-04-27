# Summary of Clean Architecture
Clean Architecture by Robert C. Martin

## Preface

The goal of software architecture is to *minimise the human resources required to build and maintain a system.*

The measure of design quality is the *effort required to meet customer needs*. If that effort is low and stays low, the design is good.

People give two excuses for not employing good architecture:
1. "We can refactor later, let's just get it to market" - this is a fallacy because the market pressure never subsides
2. "It's faster not to bother" - this is certainly wrong in the long term, and some experiments suggest it might be wrong even when writing something as small as a single class

### A tale of two values

Software provides *two* types of value to stakeholders:
1. Behaviour - satisfying requirements
2. Architecture - keeping software "soft" so that stakeholders can change their requirements

If engineers neglect the second value, eventually the cost of implementing a feature exceeds its benefit and the system becomes obsolete.

It usually falls to the engineers to assert the importance of architecture over the urgency of features.

## Programming paradigms

### Object-oriented programming (OOP)

OOP is traditionally defined as programming that uses encapsulation, inheritance and polymorphism. However:
* Encapsulation already existed before OOP - see `struct` in C
* Inheritance already existed, albeit via casting

So polymorphism is really the defining trait of OOP. It existed before, but only via dangerous function pointers that were easy to forget to implement. (Polymorphism is the ability of classes to behave like their base classes, and is assisted by features like virtual methods).

In summary, OOP is *the ability, through polymorphism, to control every dependency in the system*. This is done via the use of a plugin architecture and dependency inversion, so that modules can be developed and deployed independently.

## Design principles (SOLID)

### Single responsibility

Each component has only one reason to change. 

Many misunderstand this to mean that a component should only do one thing. In fact, it would be more accurate to say that a component should *only be accountable to one stakeholder group*.

If the method for calculating pay is in the `Employee` class, then both HR and finance could have a reason to change it. This is bad design because changes made by one team could affect the other without their knowledge.

### Open-closed

This principle states that components should be *open for extension but closed for modification*.

For example, if you have a plug socket, you want it to be easy to design a new device to fit with that socket, but you don't want modify the socket itself.

To implement this principle, partition the system into components and arrange them in a dependency hierarchy. Then ensure that, if `Socket` should be protected from changes in `Device`, then `Device` should depend on `Socket` and not the other way around. The component containing the business logic should be at the highest level of privilege, because it should not depend on the design.

This usually involves a lot of interfaces, but it's worth it.

### Liskov substitution

If you're performing an operation on many objects, they should all be substitutable.

You don't want to change your process depending on what type of input it's receiving. Better to make the inputs inherit or implement a class/interface, and have the process rely on the properties and methods of that class/interface.

### Interface segregation

Components should not depend on functionality they don't use.

So if `A` depends on only half of `B`'s functionality, it's better to extract that functionality out to an interface and have `A` depend on the interface. That way, if `B` changes in a way that doesn't affect `A`, then `A` doesn't have to be recompiled.

This matters more when the codebase is large because recompilation is costly and you want your releases to be small.

Code written in dynamically typed languages is often more tightly coupled that the same code written in a statically typed language for this reason - that there is no costly recompilation involved.

### Dependency inversion

This principle is traditionally stated as:

1. High-level modules should not depend on low-level modules. Both should depend on abstractions.
2. Abstractions should not depend on details. Details should depend on abstractions.

At its most extreme, this means that all dependencies are via interfaces. In pracice, we abstract away the *volatile* dependencies.

Another way to see the principle is that the flow of dependency is in the opposite direction to the flow of control.

A few rules of thumb:
- Design interfaces carefully and be reluctant to change them, because a lot depends on them.
- Don't refer to volatile concrete classes, or override them. Obeying this rule often means using an abstract factory.
- Don't derive from volatile concrete classes; inheritance is a strong dependency.

## Component principles

A component is a self-contained deployable unit like a DLL or JAR file.

### Component cohesion

Cohesion is about deciding which classes belong in which components. There are three principles of component cohesion:

#### Re-use/release equivalence principle (REP)

Classes and modules grouped into a component should be releasable together.

If your changes span classes in different components with different release cycles, your system will become difficult to re-use and update.

#### Common closure principle (CCP)

Components should consist of classes that change at the same times, for the same reasons.

This principle makes the system easier to maintain. It is analogous to the Single Responsibility Principle, but for components.

#### Common reuse principle (CRP)

Don't force a component to depend on things it doesn't need. This is analogous to the Interface Segregation Principle, but for components.

Two corollaries:
1. If two modules are not tightly coupled, they shouldn't be in the same component.
2. Don't depend on components which contain a lot of classes you're not going to use.

This principle stops a system from generating too many releases.

#### Tension diagram

The three principles are on the three corners of a triangle. They often conflict, and good architecture is about putting the emphasis in the right area for the team's current needs. For example, the REP groups classes for maximum reuse, which is not a concern in the early stages of a project, but becomes vital for a large project with a controlled release system.

For the other two principles:
- Neglecting the CCP leads to small changes affecting many components, making the system hard to maintain
- Neglecting the CRP results in too many unneeded releases
