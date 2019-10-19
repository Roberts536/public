# Notes on Design Patterns
This is a cheat sheet that helps me remember the definitions for design patterns, the key points behind each, and why you'd actually want to use them - i.e. what benefit they bring over just 'going at it' and coding what comes to mind.

## Factory Pattern
*In the Factory Pattern:*
- *We create an object without exposing the creation logic to the client.*
- *We refer to the newly created object using a common interface.*

We use this when we have a constructor which might be hard to use or opaque to read. The factory allows us to create an object using a simple method which has only the necessary parameters. More complex elements of construction (such as dependency injection) are handled inside the logic of the factory.

All of the objects that can be created by the factory should implement a common interface. For example, if a `ShapeFactory` can create `Square`, `Circle` and `Rectangle` objects, then all three of these classes should implement a common interface `Shape`.

## Abstract Factory Pattern
*The Abstract Factory Pattern provides interfaces for creating families of related or dependent objects without specifying their concrete classes.*

Remember that the purpose of a factory is to create objects of a common family, hiding the complex parts of construction in the factory body. But what if there are many ways to create an object of a certain type?

For example, suppose we have a website and we are interested in making new user accounts. A user can create an account via email, via Facebook or via Twitter. Each of those techniques have different construction logic that we'd want to hide away in separate factories; however all three methods are *still creating the same type of object*, namely a user account.

In this case we would write the following:
- An `AbstractFactory` class which specified an abstract `createUser` method.
- Three extensions of this class called `EmailAccountFactory`, `FacebookAccountFactory`, and `TwitterAccountFactory`, each with its own `createUser` method.
- A `User` interface. Any class produced by any of the factories must implement the `User` interface.

Important points to note:
- Each of these factories would behave like a normal factory. So the `EmailAccountFactory` might create a `GmailUser` and a `HotmailUser`, whereas the `FacebookAccountFactory` might create `PopularUser` and `UnpopularUser` objects (depending on the number of the user's Facebook friends).
- Objects might implement different interfaces depending on which factory they came from.
- However *all* the objects produced by any of the factories implement the `User` interface. This guarantees that the client can rely on the `User` interface for any object produced by an `AbstractFactory`.

### Why not just use the Factory Method Pattern?
It would be possible just to make a `UserFactory` object and have many different cases within it. However the construction logic for email and Facebook accounts could be vastly different; creating a Facebook account could require many lines of code to the Facebook API, for example. And creating a `PopularUser` and `UnpopularUser` from a Facebook account would have a lot in common, but be much different from the process for creating different email users. So separating the construction logic into *different* factories much better reflects the logic of your program.
