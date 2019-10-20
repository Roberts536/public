# SOLID Notes
Notes to help me remember what the SOLID principles are, when they apply and why we would want to use them.

## Dependency Inversion
*The Dependency Inversion Principle states that:*
- *High-level modules should not depend on low-level modules; both should depend on abstractions.*
- *Abstractions should not depend on details. Details should depend on abstractions.*

**Example:** Suppose we have a module of a website which wants to get a customer's name from their ID. Customer 
names and IDs are stored in a variety of databases depending on the user's country, whether they signed up via
email of social media, or whether they have a registered account or have made a 'guest' account. Each of these
ways of getting a user's name are implemented differently. Instead of writing if/else statements for these many
cases, we write an interface `ICustomerDataAccess` which has a method `getCustomerName()`, and use a Factory to
pass in the right type of object. The module now only requires that the object in question has a 
`getCustomerName()` method, and doesn't have to concern itself with any further details.

This way, both the Factory and the module itself depends on the `ICustomerDataAccess` interface, but the module
no longer depends directly on either the factory or the `DataAccess` object that implements the interface.
