# Preface

Part 1 of a summary of *Clean Architecture* by Robert C. Martin.

## The goal of software architecture

The goal of software architecture is to *minimise the human resources required to build and maintain a system.*

The measure of design quality is the *effort required to meet customer needs*. If that effort is low and stays low, the design is good.

People give two excuses for not employing good architecture:
1. "We can refactor later, let's just get it to market" - this is a fallacy because the market pressure never subsides
2. "It's faster not to bother" - this is certainly wrong in the long term, and some experiments suggest it might be wrong even when writing something as small as a single class

## A tale of two values

Software provides *two* types of value to stakeholders:
1. Behaviour - satisfying requirements
2. Architecture - keeping software "soft" so that stakeholders can change their requirements

If engineers neglect the second value, eventually the cost of implementing a feature exceeds its benefit and the system becomes obsolete.

It usually falls to the engineers to assert the importance of architecture over the urgency of features.
