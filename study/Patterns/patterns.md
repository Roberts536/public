# Notes on Design Patterns
This is a cheat sheet that helps me remember the definitions for design patterns, the key points behind each, and why you'd actually want to use them - i.e. what benefit they bring over just 'going at it' and coding what comes to mind.

## Factory Pattern
*In the Factory Pattern:*
- *We create an object without exposing the creation logic to the client.*
- *We refer to the newly created object using a common interface.*

We use this when we have a constructor which might be hard to use or opaque to read. The factory allows us to create an object using a simple method which has only the necessary parameters. More complex elements of construction (such as dependency injection) are handled inside the logic of the factory.

All of the objects that can be created by the factory should implement a common interface. For example, if a `ShapeFactory` can create `Square`, `Circle` and `Rectangle` objects, then all three of these classes should implement a common interface `Shape`.
