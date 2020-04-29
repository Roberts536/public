# Component Principles

Part 4 of a summary of *Clean Architecture* by Robert C. Martin.

## Component Cohesion

A component is a self-contained deployable unit like a DLL or JAR file.

Cohesion is about deciding which classes belong in which components. There are three principles of component cohesion:

### Re-use/Release Equivalence Principle (REP)

Classes and modules grouped into a component should be releasable together.

If your changes span classes in different components with different release cycles, your system will become difficult to re-use and update.

### Common Closure Principle (CCP)

Components should consist of classes that change at the same times, for the same reasons.

This principle makes the system easier to maintain. It is analogous to the Single Responsibility Principle, but for components.

### Common Reuse Principle (CRP)

Don't force a component to depend on things it doesn't need. This is analogous to the Interface Segregation Principle, but for components.

Two corollaries:

1. If two modules are not tightly coupled, they shouldn't be in the same component.
2. Don't depend on components which contain a lot of classes you're not going to use.

This principle stops a system from generating too many releases.

### Tension Diagram

The three principles are on the three corners of a triangle. They often conflict, and good architecture is about putting the emphasis in the right area for the team's current needs. For example, the REP groups classes for maximum reuse, which is not a concern in the early stages of a project, but becomes vital for a large project with a controlled release system.

For the other two principles:

- Neglecting the CCP leads to small changes affecting many components, making the system hard to maintain
- Neglecting the CRP results in too many unneeded releases

## Component Coupling

### The Acyclic Dependencies Principle (ADP)

*Allow no cycles in the component dependency graph.*

This principle arose to solve the *morning after syndrome*: when you work all day, get your code working, then come back the next morning to find it's stopped working because someone else stayed later than you.

This problem becomes greater as the size of the project increases.

Deal with the problem by:

- Divide the system into components, and assign each component to one team
- Developers release components when they like, and other teams adopt them when they like
- Draw the dependency diagram as a directed acyclic graph. Then:
  - Follow the arrows back to find affected components for testing
  - Start at the leaves and work backwards when building and testing the whole system

If you find yourself including many libraries and components to write a simple test, you may have a cycle in your graph.

If you have a cycle:

1. Use the Dependency Inversion Principle (DIP): include an interface in the dependent module, and depend on the interface instead of the second component. Or,
2. Create a new component for both of the original components to depend on.

#### Top-down Design

There are a few corollaries to looking at component graphs in this way:

- You cannot design the structure from the top down. It evolves as the system grows.
- Components don't represent functionality. They are a map of *buildability* and *maintainability*.
- The overriding concern of this practice is to isolate volatility.

### The Stable Dependencies Principle (SDP)

*Components should only depend on others which are more stable than themselves.*

We expect volatile components to change. It follows that we should make them easy to change.

However, if a difficult-to-change component depends on a volatile component, the volatile component also becomes difficult to change.

First, we must define stability. Many things make a class stable - size, complexity, clarity, etc. Here we will talk about *positional* stability.

When many components depend on a component, that component becomes more positionally stable - it is harder to change. When a component depends on other components, it is positionally unstable. The *stability metric* is the percentage of all the dependencies which are incoming.

### The Stable Abstractions Principle (SAP)

*A component should be as abstract as it is stable.*
