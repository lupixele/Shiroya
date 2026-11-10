# Unit 5: Agile Design, Refactoring, CI/CD & Version Control — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 5](questions.md#unit-v--agile-design-refactoring-cicd--version-control)

---

## Q1. Describe Agile Design Practices and discuss their contribution to maintainable and scalable software.

### 1. Introduction

**Agile Software Design** is an approach to designing software in a flexible and iterative way. The design is improved continuously as requirements change and new information becomes available.

Agile design aims to keep software simple, understandable, testable and easy to modify.

### 2. Important Agile Design Practices

**1. Simple Design**
- Build the simplest design that satisfies the current requirements.
- Avoid unnecessary features and complexity.
- Simple designs are easier to understand and maintain.

**2. Refactoring**
- Improve the internal structure of existing code without changing its external behavior.
- Remove duplication and improve readability.
- Refactoring helps the software remain clean as it evolves.

**3. Continuous Integration**
- Integrate code changes frequently into a shared project.
- Run automated builds and tests to identify problems early.
- This reduces integration difficulties.

**4. Test-Driven Development (TDD)**
- Write a test before implementing the required behavior.
- Write code to pass the test and then refactor.
- TDD helps developers create testable and reliable code.

**5. Pair Programming**
- Two developers work together on the same task.
- One writes code while the other reviews and thinks ahead.
- It encourages knowledge sharing and can identify mistakes early.

**6. Collective Code Ownership**
- Team members can improve any part of the code.
- Knowledge is shared rather than limited to one developer.
- It helps the team maintain the complete system.

**7. Coding Standards**
- Team members follow common coding rules.
- Consistent code is easier to read and maintain.
- It improves collaboration.

### 3. Contribution to maintainability

Maintainability means how easily software can be corrected, improved or modified.

Agile design supports maintainability by:
- Keeping code simple and understandable.
- Reducing duplication through refactoring.
- Using coding standards for consistency.
- Using automated tests to make changes safer.
- Sharing code knowledge across the team.

### 4. Contribution to scalability

Scalability means the ability of a system to handle increased users, data or workload by adding or improving resources.

Agile design can support scalability by:
- Keeping modules clearly organized.
- Reducing unnecessary dependencies.
- Using simple and flexible architecture.
- Testing changes frequently.
- Improving the design as system needs grow.

### 5. Example

In an online shopping application, separate modules can be used for users, products, cart and payments. When the number of users grows, the team can improve the relevant modules without redesigning the entire application.

### 6. Conclusion

Agile design practices such as simple design, refactoring, TDD, continuous integration and coding standards help create software that is easier to maintain and extend as requirements and workload grow.

**Memory trick: S--R--C--T--P--C--C = "Simple Refactoring Creates Testable, Pair-Coded, Consistent Code."**
- Simple Design
- Refactoring
- Continuous Integration
- TDD
- Pair Programming
- Collective Code Ownership
- Coding Standards

---

## Q2. Illustrate the Single Responsibility Principle (SRP) and Open Closed Principle (OCP) with suitable examples.

### 1. Introduction

The **SOLID principles** are five object-oriented design principles that help create understandable, flexible and maintainable software. Two important principles are Single Responsibility Principle (SRP) and Open Closed Principle (OCP).

### 2. Single Responsibility Principle (SRP)

**Definition:** A class should have only one responsibility or one reason to change.

**Explanation:**
- A class should focus on one main task.
- Different responsibilities should be placed in separate classes.
- This reduces complexity and makes code easier to maintain.
- Changes in one responsibility are less likely to affect unrelated functionality.

**Example:** Consider a student management application.

A poorly designed `Student` class may:
- Store student details.
- Calculate fees.
- Generate reports.
- Send email notifications.

This class has too many responsibilities.

A better design separates them:
- `Student`: stores student information.
- `FeeCalculator`: calculates fees.
- `ReportGenerator`: generates reports.
- `EmailService`: sends email notifications.

Each class now has a focused responsibility.

### 3. Open Closed Principle (OCP)

**Definition:** Software entities such as classes and modules should be open for extension but closed for modification.

**Explanation:**
- New functionality should be added without repeatedly changing existing tested code.
- Use suitable abstractions, interfaces or polymorphism.
- This reduces the risk of breaking existing features.
- It makes the system easier to extend.

**Example:** Consider a payment system that supports different payment methods.

Instead of modifying one large payment class whenever a new method is added:
- Define a common `Payment` interface.
- Create `UPIPayment` and
`CardPayment` classes implementing it.
- Add `WalletPayment` as another
implementation when needed.

The new payment type extends the system without changing the existing
payment implementations.

### 4. Difference between SRP and OCP

| Basis | SRP | OCP |
|---|---|---|
| **Full form** | Single Responsibility Principle | Open Closed Principle |
| **Main idea** | One responsibility per class | Extend behavior without modifying existing code |
| **Focus** | Separation of responsibilities | Safe extension |
| **Benefit** | Easier maintenance | Easier addition of features |
| **Example** | Separate fee calculation from student details | Add a new payment class through a common interface |

### 5. Advantages
- Reduces code complexity.
- Improves readability and maintainability.
- Makes testing easier.
- Reduces the effect of changes.
- Supports future extension.

### 6. Conclusion

SRP ensures that each class has one clear responsibility. OCP allows new
behavior to be added with minimal changes to existing code. Both
principles improve software design and maintainability.

**Memory trick:**
- **SRP = Single Job.**
- **OCP = Open to Extension,
Closed to Modification.**

---

## Q3. Demonstrate the Liskov Substitution Principle (LSP) and Interface Segregation Principle (ISP) using suitable examples.

### 1. Introduction

Liskov Substitution Principle (LSP) and Interface Segregation Principle
(ISP) are two of the five SOLID principles. They help create flexible
object-oriented software and reduce unexpected behavior.

### 2. Liskov Substitution Principle (LSP)

**Definition:** Objects of a child class should be usable wherever
objects of the parent class are expected without changing the
correctness of the program.

**Explanation:**
- A child class should correctly follow the behavior
promised by its parent class.
- It should not unexpectedly break
operations that work with the parent class.
- Inheritance should
represent a valid behavioral relationship.

**Example:** Suppose a system has a `Bird` class with a `fly()`
operation. A `Sparrow` can fly, but a `Penguin` cannot. Making `Penguin`
inherit from a class that requires every bird to fly may violate LSP.

A better design can use a general `Bird` type and a separate `Flyable`
capability for birds that can fly. Then a Sparrow can implement
`Flyable`, while a Penguin does not have to.

### 3. Interface Segregation Principle (ISP)

**Definition:** Clients should not be forced to depend on methods they do not use.

**Explanation:**
- Avoid creating one large interface with unrelated methods.
- Divide large interfaces into smaller, focused interfaces.
- Classes should implement only the operations they need.
- This reduces unnecessary dependencies.

**Example:** Suppose a college system has one large `Worker` interface with:
- `teach()`
- `manageFees()`
- `maintainLibrary()`

A teacher may not manage fees or maintain the library. Instead, create separate interfaces:
- `Teacher` with `teach()`
- `FeeManager` with
`manageFees()`
- `Librarian` with `maintainLibrary()`

Each class implements only the relevant interface.

### 4. Difference between LSP and ISP

| Basis | LSP | ISP |
|---|---|---|
| **Full form** | Liskov Substitution Principle | Interface Segregation Principle |
| **Main idea** | Child objects should safely replace parent objects | Clients should not depend on unused methods |
| **Focus** | Correct inheritance behavior | Small, focused interfaces |
| **Benefit** | Prevents unexpected behavior | Reduces unnecessary dependencies |
| **Example** | Penguin should not be forced to fly | Separate Teacher and Librarian interfaces |

### 5. Advantages
- Improves flexibility.
- Reduces unnecessary dependencies.
- Makes code easier to test.
- Avoids incorrect inheritance behavior.
- Supports maintainable software.

### 6. Conclusion

LSP ensures that child classes behave correctly when substituted for
parent classes. ISP encourages smaller and focused interfaces. Both
principles help create reliable and flexible software.

**Memory trick:**
- **LSP = Legitimate Substitution.**
- **ISP =
Interfaces Should be Particular / Small.**

---

## Q4. Discuss the Dependency Inversion Principle (DIP) and its significance in Agile software design.

### 1. Introduction

The **Dependency Inversion Principle (DIP)** is one of the five SOLID
principles. It states that high-level modules should not depend directly
on low-level modules. Both should depend on abstractions.

Abstractions should not depend on details; details should depend on
abstractions.

### 2. Explanation
- High-level modules contain important business logic.
- Low-level modules perform specific technical tasks such as database
    access or sending notifications.
- Direct dependency makes the high-level code difficult to change.
- DIP introduces an interface or abstraction between them.
- Both modules depend on that abstraction instead of depending
    directly on each other.

### 3. Example: Notification system

**Without DIP:**
- An `OrderService` directly creates and uses an
`EmailService`.
- If the company wants to use SMS instead, the order service must be modified.
- This creates tight coupling.

**With DIP:**
- Create a common `Notification` interface.
- `EmailNotification` implements the interface.
- `SMSNotification` also implements the interface.
- `OrderService` depends on the `Notification` abstraction.
- The required notification implementation can be supplied without changing the business logic.

### 4. Simple diagram

``` text
Without DIP:

OrderService ───────→ EmailService
                 Direct dependency

With DIP:

OrderService ───────→ Notification Interface
                              ↑
                    ┌─────────┴─────────┐
                    ↓                   ↓
              Email Service       SMS Service
```

### 5. Significance in Agile Software Design
- **Flexibility:** Implementations can be changed more easily.
- **Maintainability:** Business logic is separated from technical details.
- **Testability:** Mock or substitute implementations can be used during testing.
- **Extensibility:** New services can be added through the same abstraction.
- **Reduced coupling:** Changes in a low-level component have less effect on high-level code.
- **Supports changing requirements:** Teams can adapt the system without rewriting major business logic.

### 6. Conclusion

DIP reduces direct dependencies between high-level and low-level modules by using abstractions. It supports flexible, testable and maintainable software, which is valuable in Agile projects where requirements may change.

**Memory trick: H--L--A = "High and Low depend on Abstraction."**
- High-level modules.
- Low-level modules.
- Abstraction connects them.

Remember: **Depend on interfaces, not concrete details.**
---
## Q5. Analyze the five SOLID principles and their contribution to maintainable and scalable software systems.

### 1. Introduction

**SOLID** is a set of five object-oriented design principles. They help developers create software that is easier to understand, test, maintain and extend.

### 2. Five SOLID principles

**1. S -- Single Responsibility Principle (SRP)**
- A class should have one responsibility or one reason to change.
- Separate unrelated tasks into different classes.
- Example: Keep student details and fee calculation in separate classes.

**2. O -- Open Closed Principle (OCP)**
- Software entities should be open for extension but closed for modification.
- Add new behavior without repeatedly changing existing tested code.
- Example: Add a new payment method through a common payment interface.

**3. L -- Liskov Substitution Principle (LSP)**
- Child objects should be usable wherever parent objects are expected without breaking correctness.
- Child classes must respect the behavior promised by the parent.
- Example: Do not require a Penguin object to perform a flying operation.

**4. I -- Interface Segregation Principle (ISP)**
- Clients should not be forced to depend on methods they do not use.
- Create smaller and focused interfaces.
- Example: Separate teaching and library-maintenance interfaces.

**5. D -- Dependency Inversion Principle (DIP)**
- High-level and low-level modules should depend on abstractions.
- Avoid direct dependence on specific implementations.
- Example: An order service depends on a notification interface rather than directly on email.

### 3. Contribution to maintainability
- SRP reduces class complexity.
- OCP makes new features safer to add.
- LSP prevents incorrect behavior in inheritance.
- ISP avoids unnecessary dependencies.
- DIP separates business logic from implementation details.

### 4. Contribution to scalability and extensibility
- Modular code is easier to extend.
- New features can be added with fewer changes.
- Independent components can be improved separately.
- Better separation of responsibilities supports growing systems.
- Testing and maintenance become more manageable.

*Note: SOLID supports extensible and maintainable design; it does not automatically guarantee that a system can handle increased traffic or workload. Runtime scalability also depends on architecture, infrastructure and performance design.*

### 5. Example: E-commerce application
- SRP: Separate product, order and payment responsibilities.
- OCP: Add new payment methods through an abstraction.
- LSP: Ensure specialized payment implementations follow the expected payment behavior.
- ISP: Keep customer, seller and delivery interfaces focused.
- DIP: Make order processing depend on payment and notification abstractions.

### 6. Conclusion

The five SOLID principles provide guidelines for building modular, flexible and maintainable object-oriented software. They reduce the impact of changes and make it easier to extend systems as requirements grow.

**Memory trick: SOLID = S--O--L--I--D.**
- S = Single Responsibility
- O = Open Closed
- L = Liskov Substitution
- I = Interface Segregation
- D = Dependency Inversion

One-line recall: **One job, extend safely, substitute correctly, small interfaces, depend on abstractions.**

---

## Q6. Examine the need and significance of Refactoring and illustrate suitable refactoring techniques.

### 1. Introduction

**Refactoring** is the process of improving the internal structure of existing code without changing its external behavior. It makes code cleaner, simpler and easier to maintain.

### 2. Need for Refactoring
- Removes duplicated code.
- Improves code readability.
- Reduces unnecessary complexity.
- Makes future changes easier.
- Improves the structure of classes and methods.
- Helps developers understand and maintain the system.
- Makes code easier to test.

### 3. Significance of Refactoring
- **Maintainability:** Clean code is easier to correct and update.
- **Readability:** Clear names and smaller methods help developers understand the code.
- **Reduced duplication:** Common logic can be reused.
- **Safer changes:** Good structure makes modifications easier to manage.
- **Better design:** Refactoring gradually improves the internal architecture.

### 4. Refactoring techniques

**1. Extract Method**
- Move a group of statements into a separate method.
- Gives the method a meaningful name.
- Example: Move repeated fee calculation statements into `calculateFee()`.

**2. Rename Variable / Method**
- Replace unclear names with meaningful names.
- Example: Rename `x` to `totalMarks`.

**3. Extract Class**
- Move related data and behavior into a new class.
- Example: Move payment-related code out of an order class into
`PaymentService`.

**4. Remove Duplicate Code**
- Identify repeated code and place common
logic in one method or module.
- This avoids maintaining the same logic
in multiple places.

**5. Replace Magic Number with Constant**
- Replace unexplained numeric
values with named constants.
- Example: Replace `0.18` with `GST_RATE`.

**6. Simplify Conditional Expressions**
- Make complicated conditions
easier to read.
- Use clear methods or simpler logical expressions.

### 5. Example

Suppose an application contains the same tax calculation in three
different methods. During refactoring, the developer extracts the
calculation into one `calculateTax()` method. All three places use the
common method. The output remains the same, but the code becomes easier
to maintain.

### 6. Important point

Refactoring should be supported by tests. Run relevant tests before and
after refactoring to confirm that external behavior remains unchanged.

### 7. Conclusion

Refactoring improves the internal structure of software without changing
its behavior. Techniques such as Extract Method, Rename, Extract Class
and removing duplicate code help improve readability and
maintainability.

**Memory trick: E--R--C--D--M--S = "Extract, Rename, Class, Duplicate,
Magic number, Simplify."**
- Extract Method
- Rename
- Extract Class
- Remove Duplicate Code
- Replace Magic Number
- Simplify Conditions

---

## Q7. Evaluate the role of Continuous Integration, Automated Build Tools, and Version Control in Agile software development.

### 1. Introduction

Agile teams make frequent changes to software. **Continuous Integration
(CI)**, automated build tools and version control help developers
combine code safely, build the application and track changes.

### 2. Continuous Integration (CI)

Continuous Integration is the practice of frequently integrating code
changes into a shared repository and automatically building and testing
the application.

**Role of CI:**
- Integrates code changes frequently.
- Runs automated
builds and tests.
- Detects integration problems early.
- Gives quick
feedback to developers.
- Reduces the risk of large integration problems
near release time.

### 3. Automated Build Tools

Automated build tools perform tasks such as compiling source code,
managing dependencies, running tests and packaging the application.

**Examples:**
- **Maven:** Build and dependency management tool commonly
used with Java.
- **Gradle:** Build automation tool used for Java,
Android and other projects.
- **Ant:** Java build automation tool.
- **MSBuild:** Build platform used in Microsoft development environments.

**Role:**
- Automates repeated build tasks.
- Reduces manual errors.
- Makes builds more consistent.
- Supports automated testing and
packaging.

### 4. Version Control

Version Control is a system that records changes to source code and
allows developers to manage different versions of a project.

**Examples:**
- Git.
- Subversion (SVN).

**Role:**
- Tracks changes made to code.
- Allows developers to
collaborate.
- Supports branches for separate features or fixes.
- Helps
merge changes.
- Allows earlier versions to be recovered when needed.

### 5. How they work together

``` text Developer writes code ↓ Code is committed to Version Control ↓ Continuous Integration detects changes ↓ Automated Build Tool builds the project ↓ Automated Tests are executed ↓ Results are reported to the team
```

### 6. Benefits in Agile development
- Supports frequent integration.
- Finds defects earlier.
- Reduces manual work.
- Improves team collaboration.
- Provides consistent builds.
- Helps deliver working software frequently.
- Makes changes easier to track and manage.

### 7. Conclusion

Continuous Integration, automated build tools and version control work
together to support reliable and frequent software delivery. They help
Agile teams manage code changes, automate builds and tests, and identify
problems early.

**Memory trick: C--B--V = "Code, Build, Version."**
- CI = Integrate and
test code.
- Build tools = Build and package software.
- Version control
= Track and manage changes.

---

## Q8. Develop a refactoring strategy for an E-Commerce backend using Agile design principles, SOLID principles, Continuous Integration, and Version Control.

### 1. Introduction

An **E-Commerce backend** manages important functions such as customer
accounts, product information, shopping carts, orders, payments and
notifications.

As the application grows, its code may become duplicated, complex and
difficult to maintain. A refactoring strategy improves the internal
structure without changing the existing external behavior.

### 2. Step 1: Analyze the existing backend
- Review the current code and architecture.
- Identify duplicated code and large classes.
- Find tightly coupled modules.
- Identify areas with frequent defects or difficult changes.
- Record the current behavior using tests before making changes.

### 3. Step 2: Apply Agile design practices
- Use simple design and avoid unnecessary complexity.
- Refactor code in small, manageable steps.
- Use TDD or automated tests where suitable.
- Integrate changes frequently.
- Review code with team members.
- Improve the design continuously based on feedback.

### 4. Step 3: Apply SOLID principles

**SRP -- Single Responsibility Principle**
- Separate product, cart,
order and payment responsibilities into focused classes or modules.

**OCP -- Open Closed Principle**
- Add new payment methods through a
common payment abstraction instead of repeatedly modifying existing
payment logic.

**LSP -- Liskov Substitution Principle**
- Ensure specialized
implementations can replace their parent abstraction without breaking
expected behavior.

**ISP -- Interface Segregation Principle**
- Create focused interfaces
for payment, notification and inventory operations rather than one large
interface.

**DIP -- Dependency Inversion Principle**
- Make high-level order logic
depend on abstractions for payment, inventory and notifications.

### 5. Step 4: Use refactoring techniques
- Extract large methods into smaller methods.
- Rename unclear variables and methods.
- Extract separate classes for payment and order logic.
- Remove duplicated code.
- Simplify complex conditional statements.
- Replace magic numbers with named constants.

### 6. Step 5: Use Version Control
- Store the project in a Git repository.
- Create a separate branch for each refactoring task.
- Commit small and meaningful changes.
- Review changes before merging.
- Keep the main branch in a stable condition.
- Use version history to identify or reverse problematic changes.

### 7. Step 6: Implement Continuous Integration
- Configure an automated build process.
- Run unit and integration tests after changes.
- Run relevant regression tests.
- Report build or test failures to developers.
- Fix failures before merging or releasing changes.

### 8. Step 7: Review and measure improvement
- Compare code duplication and complexity before and after
    refactoring.
- Check whether tests pass.
- Review maintainability and defect reports.
- Collect team feedback.
- Plan the next small improvement.

### 9. Example

Suppose the E-Commerce backend has one large class that handles orders,
payments and email notifications.
- Separate these responsibilities into
focused modules.
- Introduce payment and notification interfaces.
- Write tests to verify existing behavior.
- Refactor in a separate Git
branch.
- Use CI to build the project and run tests.
- Merge the change
after successful review.

### 10. Conclusion

A successful E-Commerce backend refactoring strategy uses small
improvements, Agile design practices, SOLID principles, version control
and Continuous Integration. These practices improve code structure,
reduce unnecessary dependencies and make the backend easier to maintain
and extend.

**Memory trick: A--S--R--V--C--M = "Analyze, SOLID, Refactor, Version,
CI, Measure."**
- Analyze existing code.
- Apply SOLID.
- Refactor in
small steps.
- Use Version Control.
- Run Continuous Integration.
- Measure improvements.

---
## Quick Revision — Unit 5

### Eight questions in one line

| Q.No. | Main Topic | Memory Trick |
|:---:|---|---|
| **1** | Agile Design Practices | S–R–C–T–P–C–C |
| **2** | SRP and OCP | Single Job; Extend safely |
| **3** | LSP and ISP | Substitute correctly; Small interfaces |
| **4** | Dependency Inversion Principle | H–L–A |
| **5** | Five SOLID principles | S–O–L–I–D |
| **6** | Refactoring | E–R–C–D–M–S |
| **7** | CI, Build Tools and Version Control | C–B–V |
| **8** | E-Commerce backend refactoring strategy | A–S–R–V–C–M |

### Important diagrams / tables to practise

1.  Five SOLID principles and their meanings.
2.  SRP example: separate Student, FeeCalculator, ReportGenerator and
    EmailService.
3.  OCP payment example using a common interface.
4.  LSP example: Bird and Flyable capability.
5.  DIP diagram: high-level and low-level modules depending on an
    abstraction.
6.  Refactoring techniques with examples.
7.  CI workflow: Commit → Build → Test → Report.
8.  E-Commerce refactoring strategy steps.

### Exam-writing strategy for 8 marks
- Begin with the definition of the principle or concept.
- Explain each principle separately and give a small example.
- For comparison questions, use a table.
- For refactoring questions, explain the need, significance and
    techniques.
- For CI questions, explain the role of all three: CI, build tools and
    version control.
- For the E-Commerce scenario, show the strategy step by step and
    connect it to SOLID and CI.
- End with a short conclusion.

**Revision tip:** Learn Q2, Q3 and Q5 together because they cover all
five SOLID principles. Then study Q4 and Q6, followed by Q7 and Q8.
Practise the DIP and CI diagrams.

---
