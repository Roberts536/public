# V. Architecture

Part 5 of a summary of *Clean Architecture* by Robert C. Martin.

## 15. What is Architecture?

Architecture has little to do with a system's behaviour. Systems can work fine with good or bad architecture.

Good architecture facilitates the development, deployment, operation and maintenance of a software system. It does this in order to leave as many options open as possible, for as long as possible. It minimises the lifetime cost of the system and maximises programmer productivity.

### Development

The right architecture depends on the team size. Architectural decisions could hinder a small team, but become essential when many teams work on the same system. In the absence of a deliberate architectural decision, the architecture will gravitate towards one component per team. This is unlikely to be the best decision in the long term.

### Deployment

A system with good architecture is easy to deploy with a single action. Programmers gravitate towards an architecture which is easy to develop, not necessarily one which is easy to deploy. Early attention to architecture can prevent this problem.

### Operation

Operation is less important financially (it's cheap to throw more hardware at the problem). However good architecture makes the operational needs of the system more obvious by privileging business logic over detail.

### Maintenance

The most costly aspect of a software system. Good architecture minimises both the time spent working out how to add a new feature and the risk of breaking the system when making the change.

### Keeping options open

A software system consists of *policy* and *details*. Good architecture recognises the importance of policy, and tries to decouple the details from the policy as much as possible. Doing so allows us to *delay implementation decisions* so that we can make them later with better information. This applies even if you think the decision has already been made.

*A good architect maximises the number of decisions not made.*

## 16-22 To do

## 23 Presenters and Humble Objects

The *Humble Object Pattern* consists of stripping out the hard-to-test elements of a class into a separate module, called the Humble object.

For example, a GUI screen is hard to test, but the rest of the logic might be easier to test. So we separate the GUI into two modules: the *Presenter* and the *View*.
