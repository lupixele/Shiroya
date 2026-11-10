# Unit 5: Agile Design, Refactoring, CI/CD & Version Control — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 5](questions.md#unit-v--agile-design-refactoring-cicd--version-control)

---

## Part A: 2-Mark Short Questions

### 2M-1. Meaning of Agile Software Design

#### Definition
**Agile Software Design** is an evolutionary, iterative approach to system architecture. Instead of heavy upfront design (BDUF), the architecture is kept simple (YAGNI/KISS), modular, and clean, adapting continuously to emerging requirements through regular refactoring and automated testing.

---

### 2M-2. Agile Design Practices

#### Two Core Practices
1. **Simple Design (YAGNI / KISS):** Building only the architecture necessary to satisfy current user stories without speculative over-engineering.
2. **Continuous Refactoring:** Relentlessly cleaning up code structure, removing duplication, and improving cohesion without changing external behavior.

---

### 2M-3. Purpose of Single Responsibility Principle (SRP)

#### Purpose
**SRP** states that a class should have one, and only one, reason to change. Its purpose is to achieve high cohesion and isolate changes so that modifying one feature does not inadvertently break unrelated functionality.

---

### 2M-4. Summary of Open Closed Principle (OCP)

#### Summary
**OCP** states: *"Software entities (classes, modules, functions) should be open for extension, but closed for modification."* New behavior is added by creating new subclasses or implementing interfaces, without modifying existing, tested code.

---

### 2M-5. Purpose of Liskov Substitution Principle (LSP)

#### Purpose
**LSP** asserts that subclasses must be substitutable for their base classes without altering the correctness of the program. It prevents broken abstractions and invalid inheritance hierarchies.

---

### 2M-6. Key Idea of Interface Segregation Principle (ISP)

#### Key Idea
**ISP** states that clients should not be forced to depend on methods they do not use. It promotes splitting large, monolithic (\"fat\") interfaces into smaller, role-specific interfaces.

---

### 2M-7. Purpose of Dependency Inversion Principle (DIP)

#### Purpose
**DIP** states:
1. High-level modules should not depend on low-level modules; both should depend on abstractions.
2. Abstractions should not depend on details; details should depend on abstractions.  
It decouples business logic from concrete technical implementations (e.g., databases, web services).

---

### 2M-8. Five SOLID Principles

#### The SOLID Acronym
1. **S:** Single Responsibility Principle (SRP)
2. **O:** Open-Closed Principle (OCP)
3. **L:** Liskov Substitution Principle (LSP)
4. **I:** Interface Segregation Principle (ISP)
5. **D:** Dependency Inversion Principle (DIP)

---

### 2M-9. Meaning of Refactoring

#### Definition
**Refactoring** is the disciplined process of restructuring existing computer code—improving its internal design, readability, and maintainability—without altering its external observable behavior.

---

### 2M-10. Reasons for Performing Refactoring

#### Two Key Reasons
1. **Reduce Technical Debt:** Cleaning up rushed, messy, or duplicate code prevents design decay over time.
2. **Improve Malleability & Readability:** Clean, well-structured code allows developers to add new sprint features quickly and safely.

---

### 2M-11. Refactoring Techniques

#### Two Common Techniques
1. **Extract Method:** Moving a cohesive code fragment from a bloated method into a new, well-named method.
2. **Rename Symbol:** Changing cryptic variable, class, or method names into meaningful, self-descriptive identifiers.

---

### 2M-12. Purpose of Continuous Integration (CI)

#### Purpose
**Continuous Integration (CI)** is an Agile practice where developers merge their code changes into a shared central repository multiple times a day. Every commit triggers an automated build and test pipeline to detect integration errors immediately.

---

### 2M-13. Examples of Automated Build Tools

#### Two Primary Tools
1. **Maven / Gradle:** Industry-standard Java build and dependency management tools automating compilation, packaging, and testing.
2. **npm / yarn:** Package managers and build scripts for JavaScript/Node.js ecosystems.

---

### 2M-14. Purpose of Version Control

#### Purpose
A **Version Control System (VCS)** tracks and records every historical modification made to source code files, enabling multi-developer collaboration, non-destructive branching, and instant rollback of defective changes.

---

### 2M-15. Benefits of Version Control

#### Two Key Benefits
1. **Parallel Feature Development:** Branching allows multiple developers to build separate sprint stories concurrently without overwriting code.
2. **Traceability & Auditability:** Every commit logs *who* changed *what*, *when*, and *why*, simplifying debugging and accountability.

---

### 2M-16. Role of Continuous Integration in Agile

#### Role & Importance
CI eliminates \"integration hell\" at the end of sprints. By building and testing code on every push, CI guarantees the team maintains a permanently stable, potentially releasable product increment.

---

### 2M-17. Refactoring Contribution to Maintainability

#### Contribution
Refactoring simplifies control flow, eliminates code duplication (DRY), and enforces modularity. This drastically reduces the cognitive load required for future engineers to comprehend and modify the codebase.

---

### 2M-18. Maintainability vs. Scalability

#### Comparison Table
| Basis | Maintainability | Scalability |
|---|---|---|
| **Definition** | The ease with which software can be understood, corrected, and adapted | The ability of a system to handle increased workloads or traffic by adding resources |
| **Focus** | Code health, modularity, and internal architecture | Performance, concurrency, throughput, and hardware efficiency |

---

### 2M-19. Benefits of SOLID Principles in Agile Design

#### Two Key Benefits
1. **Decoupled Architecture:** Modifications to one feature do not ripple unexpectedly through the rest of the application.
2. **Effortless Extensibility:** New user stories can be added as new classes/modules without modifying existing, tested production code.

---

### 2M-20. Combining Version Control with Continuous Integration

#### Two Major Advantages
1. **Automated Quality Gates:** Pull requests cannot be merged into `main` unless automated CI test builds pass 100%.
2. **Instant Feedback on Broken Commits:** Developers are alerted to integration conflicts seconds after pushing, keeping the shared repository healthy.

---

## Part B: 8-Mark Questions

### 1. Agile Design Practices for Maintainable and Scalable Software

**Q1. Describe Agile Design Practices and discuss their contribution to maintainable and scalable software. (8M)**

#### 1. Agile Design Overview
Traditional software engineering favored **Big Design Up Front (BDUF)**, producing massive architectural documents before writing code. In contrast, **Agile Software Design** advocates **Evolutionary Architecture**: designing just enough to satisfy current requirements, backed by rigorous engineering practices that keep the codebase easy to change.

```
┌────────────────────────────────────────────────────────────────────────┐
│                      CORE AGILE DESIGN PRACTICES                       │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. Simple Design   │ 2. Continuous      │ 3. SOLID & Clean Code        │
│    (YAGNI & KISS)  │    Refactoring     │    Principles                │
├────────────────────┼────────────────────┼──────────────────────────────┤
│ 4. Test-Driven     │ 5. Continuous      │ Outcome: Highly Maintainable │
│    Design (TDD)    │    Integration     │ & Scalable Architecture      │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

#### 2. Key Agile Design Practices
1. **Simple Design (Kent Beck's 4 Rules):**
   - Runs all tests.
   - Contains no duplicate code (DRY - Don't Repeat Yourself).
   - Expresses the intent of the programmer (clean naming and structure).
   - Minimizes the number of classes and methods (KISS & YAGNI - You Aren't Gonna Need It).
2. **Continuous Refactoring:**
   - Regularly reviewing and improving internal structure without altering external behavior. Eliminates code smells before they degrade into crippling technical debt.
3. **Encapsulation & Low Coupling, High Cohesion:**
   - Modules perform a single well-defined task and interact across narrow, abstract interfaces.
4. **Pattern-Oriented Emergence:**
   - Design patterns (Strategy, Factory, Observer) are not forced upfront; they are introduced through refactoring when complexity justifies them.

#### 3. Contribution to Maintainability and Scalability
- **Maintainability:** Modular, self-documenting code with isolated responsibilities makes bug fixing and feature enhancement rapid and low-risk.
- **Scalability:** Loose coupling and stateless component design allow services to be scaled horizontally across cloud instances without architectural rewrites.

---

### 2. Single Responsibility Principle (SRP) and Open Closed Principle (OCP)

**Q2. Illustrate the Single Responsibility Principle (SRP) and Open Closed Principle (OCP) with suitable examples. (8M)**

#### 1. Single Responsibility Principle (SRP)
- **Definition:** *A class should have one, and only one, reason to change.* A class must represent a single, cohesive business concept.

##### Code Example: Violating SRP (Bad Design)
```java
public class Invoice {
    public double calculateTotal() { /* calculate bill */ return 100.0; }
    public void printInvoice() { /* printing layout logic */ }
    public void saveToDatabase() { /* SQL persistence logic */ }
}
```
*Problem:* `Invoice` changes if tax calculation changes, if printing format changes, or if database schema changes (3 separate reasons to change).

##### Code Example: Adhering to SRP (Good Design)
```java
public class Invoice {
    public double calculateTotal() { return 100.0; } // Core domain logic only
}
public class InvoicePrinter {
    public void print(Invoice invoice) { /* Presentation logic */ }
}
public class InvoiceRepository {
    public void save(Invoice invoice) { /* Database persistence logic */ }
}
```

---

#### 2. Open-Closed Principle (OCP)
- **Definition:** *Software entities should be open for extension, but closed for modification.* Add new behavior by writing new code, not modifying existing, tested code.

##### Code Example: Violating OCP (Bad Design)
```java
public class AreaCalculator {
    public double calculateArea(Object shape) {
        if (shape instanceof Circle) {
            Circle c = (Circle) shape;
            return Math.PI * c.radius * c.radius;
        } else if (shape instanceof Rectangle) {
            Rectangle r = (Rectangle) shape;
            return r.width * r.height;
        }
        // Adding Triangle forces us to MODIFY this tested method!
        return 0;
    }
}
```

##### Code Example: Adhering to OCP (Good Design)
```java
public interface Shape {
    double calculateArea();
}

public class Circle implements Shape {
    private double radius;
    public double calculateArea() { return Math.PI * radius * radius; }
}

public class Rectangle implements Shape {
    private double width, height;
    public double calculateArea() { return width * height; }
}

public class Triangle implements Shape { // Added without touching existing classes!
    private double base, height;
    public double calculateArea() { return 0.5 * base * height; }
}

public class AreaCalculator {
    public double calculateArea(Shape shape) {
        return shape.calculateArea(); // Completely closed for modification!
    }
}
```

---

### 3. Liskov Substitution Principle (LSP) and Interface Segregation Principle (ISP)

**Q3. Demonstrate the Liskov Substitution Principle (LSP) and Interface Segregation Principle (ISP) using suitable examples. (8M)**

#### 1. Liskov Substitution Principle (LSP)
- **Definition (Barbara Liskov):** *Objects of a superclass should be replaceable with objects of a subclass without affecting the correctness of the program.*

##### Classic Violation: The Rectangle and Square Problem
```java
public class Rectangle {
    protected int width, height;
    public void setWidth(int w) { this.width = w; }
    public void setHeight(int h) { this.height = h; }
    public int getArea() { return width * height; }
}

public class Square extends Rectangle {
    @Override
    public void setWidth(int w) { this.width = w; this.height = w; }
    @Override
    public void setHeight(int h) { this.width = h; this.height = h; }
}
```
*The Flaw:* A client writing `rect.setWidth(5); rect.setHeight(4);` expects area = 20. If a `Square` instance is passed, area becomes 16! `Square` violates the expected behavioral invariants of `Rectangle`.

##### Solution Adhering to LSP
Do not use inheritance where behavioral invariants differ. Have both implement a common `Shape` interface:
```java
public interface Shape { int getArea(); }
public class Rectangle implements Shape { /* independent width/height */ }
public class Square implements Shape { /* single side */ }
```

---

#### 2. Interface Segregation Principle (ISP)
- **Definition:** *Clients should not be forced to depend on interfaces they do not use.* Break fat interfaces into cohesive, client-specific interfaces.

##### Code Example: Violating ISP (Fat Interface)
```java
public interface Worker {
    void code();
    void test();
    void manageProject();
}

public class Developer implements Worker {
    public void code() { /* coding */ }
    public void test() { /* testing */ }
    public void manageProject() { throw new UnsupportedOperationException(); } // Forced!
}
```

##### Code Example: Adhering to ISP (Segregated Interfaces)
```java
public interface Codeable { void code(); }
public interface Testable { void test(); }
public interface Manageable { void manageProject(); }

public class Developer implements Codeable, Testable {
    public void code() { /* write code */ }
    public void test() { /* write unit tests */ }
}

public class ProjectManager implements Manageable {
    public void manageProject() { /* track milestones */ }
}
```

---

### 4. Dependency Inversion Principle (DIP) in Agile Design

**Q4. Discuss the Dependency Inversion Principle (DIP) and its significance in Agile software design. (8M)**

#### 1. Concept & Formal Definition
Formulated by Robert C. Martin, **DIP** inverts traditional top-down procedural architecture:
1. **High-level modules should not depend on low-level modules. Both should depend on abstractions.**
2. **Abstractions should not depend on details. Details (concrete implementations) should depend on abstractions.**

```
TRADITIONAL COUPLING (Rigid):
[ High-Level Business Logic ] ─────────► [ Low-Level MySQL Database ]

DEPENDENCY INVERSION (Agile & Decoupled):
[ High-Level Business Logic ] ─────────► [ <<Interface>> NotificationService ]
                                                          ▲
                                                          │ (implements)
[ EmailService / SMSService ] ────────────────────────────┘
```

#### 2. Code Walkthrough: Notification System

##### Bad Design (Direct Coupling)
```java
public class EmailService {
    public void sendEmail(String msg) { /* SMTP sending */ }
}
public class OrderNotification {
    private EmailService emailer = new EmailService(); // Direct hardcoded dependency!
    public void notifyCustomer(String msg) {
        emailer.sendEmail(msg); // Cannot switch to SMS or WhatsApp without editing!
    }
}
```

##### Good Design (Dependency Inversion with Injection)
```java
// 1. Abstraction
public interface MessageService {
    void sendMessage(String message);
}

// 2. Low-level concrete implementations
public class EmailService implements MessageService {
    public void sendMessage(String msg) { /* SMTP email */ }
}
public class SMSService implements MessageService {
    public void sendMessage(String msg) { /* SMS gateway */ }
}

// 3. High-level module depends ONLY on abstraction
public class OrderNotification {
    private final MessageService messageService;

    // Dependency is injected via constructor
    public OrderNotification(MessageService messageService) {
        this.messageService = messageService;
    }
    public void notifyCustomer(String msg) {
        messageService.sendMessage(msg);
    }
}
```

#### 3. Significance in Agile Design
- **Mocking and TDD Isolation:** High-level business classes can be unit-tested in complete isolation by injecting mock interfaces without hitting live databases or network APIs.
- **Pluggable Architecture:** Changing third-party payment gateways (Stripe $\to$ PayPal) requires zero edits to core order processing logic.

---

### 5. Five SOLID Principles: Synthesis and Analysis

**Q5. Analyze the five SOLID principles and their contribution to maintainable and scalable software systems. (8M)**

#### 1. Synthesis of the SOLID Principles
The **SOLID** principles, compiled by Robert C. Martin (Uncle Bob), provide the foundational design rules for building robust, maintainable, and agile object-oriented architectures.

```
┌───┬───────────────────────────────────┬────────────────────────────────────────────────────────┐
│   │ Principle                         │ Core Architectural Rule                                │
├───┼───────────────────────────────────┼────────────────────────────────────────────────────────┤
│ S │ Single Responsibility (SRP)       │ One class, one clear job, one reason to change.        │
│ O │ Open-Closed (OCP)                 │ Open for extension, closed for modification.           │
│ L │ Liskov Substitution (LSP)         │ Subtypes must be seamlessly substitutable for base.    │
│ I │ Interface Segregation (ISP)       │ Many small, role-specific interfaces over one fat.     │
│ D │ Dependency Inversion (DIP)        │ Depend on abstractions (interfaces), not concretions.  │
└───┴───────────────────────────────────┴────────────────────────────────────────────────────────┘
```

#### 2. Comprehensive Impact Analysis on Software Engineering

1. **Combating Architectural Smells:**
   - *Rigidity:* Code is hard to change because a single edit cascades across dozens of modules (eliminated by **DIP** and **SRP**).
   - *Fragility:* Code breaks in unexpected places when an edit is made (eliminated by **OCP** and **LSP**).
   - *Viscosity:* Doing the wrong thing is easier than doing the right thing (combated by **ISP** and clean abstractions).
2. **Contribution to Maintainability:**
   - Reduces the cost of bug fixing. When classes follow SRP and DIP, defects are confined to a single class and do not pollute the system.
   - Makes code readable and self-documenting; new developers navigate small, single-purpose classes effortlessly.
3. **Contribution to Scalability:**
   - Decoupled interfaces enable modular development across distributed engineering teams.
   - Microservice decomposition: SOLID classes map directly to clean, independent microservice boundaries that scale horizontally across cloud clusters.

---

### 6. Need and Significance of Refactoring and Techniques

**Q6. Examine the need and significance of Refactoring and illustrate suitable refactoring techniques. (8M)**

#### 1. Definition & Core Need for Refactoring
**Refactoring** is the systematic process of improving the internal design and quality of existing code without modifying its external behavior. As software evolves across agile iterations, new features and rapid deadlines inevitably introduce code smells, design rot, and technical debt. Refactoring continuously repays this debt.

#### 2. Significance in Agile Development (6 Core Points from Raw Notes)
1. **Removes Code Smells:** Eliminates duplicated code, long bloated methods, and oversized \"God classes\".
2. **Reduces Technical Debt:** Repays architectural debt accumulated due to rushed sprint deadlines.
3. **Improves Maintainability & Comprehension:** Makes code clean, logical, and easy for new team members to understand.
4. **Supports Changing Requirements:** Prepares the codebase so new sprint stories can be added with minimal friction.
5. **Enforces Design Principles:** Applies principles like SOLID, DRY, and KISS continuously.
6. **Makes Future Changes Safe:** Paired with unit tests, refactoring ensures future enhancements do not introduce silent regression bugs.

#### 3. Four Core Refactoring Techniques with Code Walkthroughs

##### 1. Extract Method
- *Problem:* A single 80-line method performs calculation, logging, and database operations.
- *Solution:* Extract cohesive chunks into small, well-named helper methods.
```java
// BEFORE:
public void printOwing() {
    printBanner();
    // print details
    System.out.println("name: " + name);
    System.out.println("amount: " + getOutstanding());
}

// AFTER:
public void printOwing() {
    printBanner();
    printDetails(getOutstanding());
}
private void printDetails(double outstanding) {
    System.out.println("name: " + name);
    System.out.println("amount: " + outstanding);
}
```

##### 2. Replace Magic Number with Named Constant
```java
// BEFORE: double total = price + (price * 0.18);
// AFTER:
public static final double GST_TAX_RATE = 0.18;
double total = price + (price * GST_TAX_RATE);
```

##### 3. Rename Method / Variable
- Changing cryptic identifiers (`int d;`, `void proc()`) to self-explanatory names (`int daysSinceLastLogin;`, `void processOrderPayment()`).

##### 4. Move Method / Field
- Moving a method or attribute to the class that uses it most frequently to eliminate *Feature Envy* and reduce coupling.

---

### 7. Continuous Integration, Automated Build Tools, and Version Control

**Q7. Evaluate the role of Continuous Integration, Automated Build Tools, and Version Control in Agile software development. (8M)**

#### 1. The Agile DevOps Triad
Modern Agile engineering relies on the seamless convergence of **Version Control**, **Automated Build Tools**, and **Continuous Integration** to enable rapid, defect-free software delivery.

```
┌─────────────────┐       ┌─────────────────┐       ┌─────────────────┐
│ Version Control │ ────► │ Build Automation│ ────► │ Continuous      │ ────► Automated Build Report
│ (Git Branches)  │ Push  │ (Maven / Gradle)│ Trigs │ Integration     │       & Deployable Artifact
└─────────────────┘       └─────────────────┘       │ (CI Server)     │
                                                    └─────────────────┘
```

#### 2. Detailed Role of Each Component
1. **Version Control System (Git):**
   - *Role:* Manages code history and distributed collaboration.
   - *Agile Practices:* Feature branching (`feature/user-auth`), Pull Requests with peer code review, atomic commits, and release tagging (`v1.4-sprint-3`).
2. **Automated Build Tools (Maven, Gradle, npm):**
   - *Role:* Automates mechanical development tasks into repeatable, headless commands.
   - *Activities:* Compiles source files, resolves transitive library dependencies, runs unit test suites, and packages compiled code into executable JARs/containers.
3. **Continuous Integration Server (Jenkins, GitHub Actions, GitLab CI):**
   - *Role:* Orchestrates the automated pipeline triggered on every `git push`.
   - *Workflow:* Pulls latest branch $\to$ Executes build tool $\to$ Runs unit/integration tests $\to$ Runs code quality scanners (SonarQube) $\to$ Reports build status to developers.

#### 3. Seven Steps in a Typical CI Pipeline (From Raw Notes)
1. **Code Commit:** Developer commits small changes and pushes to the shared Git repository.
2. **Automated Build:** CI server triggers immediately and compiles the source code into binary form.
3. **Automated Testing:** Unit, integration, and regression test suites execute automatically.
4. **Static Code Analysis:** Linters and scanners (SonarQube) check code quality and potential security flaws.
5. **Package Creation:** A deployable, versioned software artifact (JAR, Docker container) is created.
6. **Deploy to Staging:** Artifact is automatically deployed to a test/staging environment for verification.
7. **Production Release:** Validated, signed-off software is ready for continuous delivery to end users.

#### 4. Seven Major Benefits of Continuous Integration (From Raw Notes)
1. **Detects integration problems early:** Identifies merge conflicts within minutes instead of weeks.
2. **Finds defects and regressions quickly:** Tests immediately flag broken code before it spreads.
3. **Provides fast feedback to developers:** Engineers know within minutes if their push was successful.
4. **Reduces integration conflicts:** Frequent, small merges eliminate agonizing \"merge day\" marathons.
5. **Keeps the software continuously releasable:** The `main` branch remains permanently stable and releasable.
6. **Supports frequent and low-risk delivery:** Small batches reduce the operational hazard of production deployments.
7. **Makes software quality transparent:** Build dashboards give the entire team visibility into test coverage and build health.

---

### 8. Refactoring Strategy for E-Commerce Backend

**Q8. Develop a refactoring strategy for an E-Commerce backend using Agile design principles, SOLID principles, Continuous Integration, and Version Control. (8M)**

#### 1. Context & Legacy Architecture Smells
An online retail platform experiences severe slowdowns and bugs. The backend has a massive 2,000-line \"God Class\" `OrderProcessor` containing order validation, tax calculations, inventory updates, MySQL database calls, and credit card processing.

#### 2. Refactoring Strategy Blueprint

```
┌────────────────────────────────────────────────────────────────────────┐
│               E-COMMERCE BACKEND REFACTORING ROADMAP                   │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. Git Safety Net  │ 2. Characterization│ 3. SOLID & Pattern           │
│    Branching       │    Unit Tests      │    Decomposition             │
├────────────────────┼────────────────────┼──────────────────────────────┤
│ 4. CI Automated    │ 5. Safe Canary     │ Expected Outcome:            │
│    Verification    │    Pull Request    │ Highly Cohesive, Decoupled   │
│    (Zero Downtime) │    Merge to Main   │ Microservice Architecture    │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

#### 3. Step-by-Step Refactoring Execution

1. **Step 1: Version Control Isolation:**
   - Create a dedicated Git branch: `git checkout -b refactor/order-processor-decoupling`.
   - Ensure the current baseline is tagged and reproducible.
2. **Step 2: Establish a Characterization Testing Safety Net:**
   - *Rule:* Never refactor without automated tests!
   - Write comprehensive integration tests (JUnit 5 + Mockito) capturing current inputs and expected outputs of `OrderProcessor`. Confirm all tests pass green.
3. **Step 3: Decompose the God Class using SRP and OCP:**
   - **Extract Validation:** Move input checks to `OrderValidator`.
   - **Extract Pricing & Tax:** Move pricing logic to `PricingCalculator`.
   - **Extract Payment (DIP & OCP):**
     - Define abstraction `PaymentGateway` with `processPayment(double amount)`.
     - Implement concrete adapters `StripeGateway` and `PayPalGateway`.
   - **Extract Persistence:** Move SQL queries to `OrderRepository`.
4. **Step 4: Continuous Integration Pipeline Verification:**
   - Push small, atomic commits to Git.
   - GitHub Actions runs the automated test suite on every push.
   - SonarQube measures reduced cyclomatic complexity and zero duplicate code.
5. **Step 5: Code Review & Production Merge:**
   - Open a Pull Request demonstrating identical behavior and 92% test coverage.
   - Merge into `main` and deploy via CI/CD with zero customer downtime.
