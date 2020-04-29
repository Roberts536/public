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
