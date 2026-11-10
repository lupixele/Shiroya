# Agile Software Engineering (ASE) — 2-Marks Short Answers (All Units)

> **Course Code:** 2501IT07 | **Program:** B.Tech — III Semester (CSE, IT, AIML, CSE-DS) | Aditya University  
> **Exam Coverage:** Section A (Compulsory 10 × 2M = 20 Marks)  
> **Source:** Aditya University Official Question Bank & Mid Examination Evaluation Key  
> **Questions Index:** [questions.md](questions.md)

---

---

## Unit I — Software Process & Classical Life Cycle Models

### 2M-1. Meaning of Software Engineering

#### Definition
**Software Engineering** is a systematic, disciplined, and quantifiable approach to the development, operation, and maintenance of software. It applies engineering principles to produce reliable, efficient, and cost-effective software that satisfies user requirements.

#### Key Objectives
- Deliver high-quality, defect-free software on schedule and within budget.
- Facilitate long-term maintainability, adaptability, and scalability.

---

### 2M-2. Major Activities of a Software Process

#### Four Fundamental Activities
1. **Software Specification:** Defining what the software must do and its operational constraints.
2. **Software Design & Implementation:** Structuring the architecture and producing executable code.
3. **Software Validation:** Testing and verifying that the software conforms to requirements.
4. **Software Evolution:** Modifying software post-delivery to satisfy changing customer needs and fix bugs.

---

### 2M-3. Activities in Software Engineering Practice

#### Core Engineering Activities
1. **Communication (Requirements Gathering):** Interacting with stakeholders to understand business problems and collect functional needs.
2. **Modeling (Analysis & Design):** Creating architectural blueprints, data models, and algorithms prior to implementation.

---

### 2M-4. Two Common Software Myths

#### Myths & Realities
1. **Myth 1 (Resource Myth):** *"If we get behind schedule, we can add more programmers and catch up."*  
   - **Reality:** Adding manpower to a late software project makes it later (Brook's Law), due to communication overhead and ramp-up time.
2. **Myth 2 (Requirements Myth):** *"A general statement of objectives is enough to begin coding; details can be resolved later."*  
   - **Reality:** Ambiguous requirements lead to massive architectural rework and costly failures.

---

### 2M-5. Purpose of a Software Life Cycle Model

#### Purpose
A **Software Life Cycle Model (SDLC)** provides a structured, predictable framework defining the sequence of phases, milestones, deliverables, and quality gates from project inception through retirement. It ensures development consistency, risk management, and resource governance.

---

### 2M-6. Major Categories of Software Processes

#### Primary Categories
1. **Prescriptive (Plan-Driven) Processes:** Linear or sequential workflows with heavy upfront documentation (e.g., Waterfall, V-Model).
2. **Evolutionary / Iterative Processes:** Progressive refinement with working releases at each stage (e.g., Prototyping, Spiral).
3. **Agile Processes:** Lightweight, adaptive, people-driven workflows emphasizing rapid delivery and flexibility (e.g., Scrum, XP).

---

### 2M-7. Phased Development Life Cycle

#### Summary
The **Phased Development Life Cycle** breaks system construction into discrete sequential or overlapping phases (Analysis, Design, Coding, Testing, Deployment). Each phase produces verifiable artifacts (e.g., SRS, design documents) reviewed against predefined exit criteria before advancing.

---

### 2M-8. Major Phases of the Waterfall Model

#### Five Sequential Phases
1. **Requirements Analysis & Specification:** Gathering and documenting complete system requirements in an SRS.
2. **System & Software Design:** Establishing system architecture, data structures, and interfaces.
3. **Implementation & Unit Testing:** Writing program code and testing individual modules.
4. **Integration & System Testing:** Combining units and verifying overall functional correctness.
5. **Deployment & Maintenance:** Releasing software to production and providing ongoing support.

---

### 2M-9. Primary Objective of the Spiral Model

#### Primary Objective
The primary objective of the **Spiral Model** is **explicit, proactive risk management**. It iteratively evaluates technical, operational, and financial risks at every spiral loop before committing resources to design, coding, or deployment.

---

### 2M-10. Characteristics of the Evolutionary Model

#### Two Key Characteristics
1. **Iterative & Incremental Delivery:** The system is released in a sequence of usable versions with increasing functionality.
2. **High Tolerance for Change:** User feedback from each deployed increment drives the requirements and design of subsequent versions.

---

### 2M-11. Purpose of Software Project Management

#### Purpose
**Software Project Management (SPM)** plans, monitors, and controls personnel, resources, schedules, and risks to ensure software is delivered on time, within budget, and meeting specified quality standards.

---

### 2M-12. Major Activities in Project Planning

#### Two Key Activities
1. **Scope Definition & Work Breakdown Structure (WBS):** Decomposing the project into manageable tasks and milestones.
2. **Resource & Schedule Estimation:** Estimating required effort, allocating team roles, and building dependency Gantt charts.

---

### 2M-13. Purpose of Software Estimation

#### Purpose
**Software Estimation** forecasts the effort (person-months), calendar duration (months), and financial cost required to build a system. It provides management with realistic benchmarks for budgeting, team sizing, and contract bidding.

---

### 2M-14. Requirements-Gathering Activities

#### Two Key Activities
1. **Stakeholder Interviews & Brainstorming:** Conducting direct question-and-answer sessions with domain users and clients.
2. **Document Analysis & Existing System Observation:** Studying business forms, operational logs, and existing workflows to identify functional gaps.

---

### 2M-15. Purpose of Software Design

#### Purpose
The purpose of **Software Design** is to translate requirements into an architectural blueprint that guides implementation. It defines software components, interfaces, data models, and control flows to ensure modularity, low coupling, and high cohesion.

---

### 2M-16. Objectives of Software Testing

#### Two Key Objectives
1. **Defect Identification:** Uncovering discrepancies between actual program behavior and specified requirements.
2. **Quality Verification & Confidence:** Ensuring the system meets performance, security, and reliability standards prior to production release.

---

### 2M-17. Characteristics of Software Quality

#### Two Key Characteristics
1. **Correctness & Reliability:** Performing required functions accurately under specified operational conditions.
2. **Maintainability & Modularity:** Permitting effortless defect correction, enhancement, and adaptation to new environments.

---

### 2M-18. Factors Influencing Software Reliability

#### Two Key Factors
1. **Defect Density & Test Coverage:** The frequency of residual coding/design faults remaining after system verification.
2. **Operational Environment & Input Validation:** How gracefully the software handles unexpected inputs, high loads, and hardware faults.

---

### 2M-19. Waterfall vs. Spiral Models

#### Comparison Table
| Feature | Waterfall Model | Spiral Model |
|---|---|---|
| **Risk Management** | Reactive (no formal risk analysis) | Proactive (risk analysis in every cycle) |
| **Approach & Feedback** | Rigid, linear sequential; late feedback | Cyclic, evolutionary; early feedback per loop |

---

### 2M-20. Student Management System Case Study

#### Purpose
A **Student Management System (SMS)** serves as an academic case study because it encapsulates clear functional boundaries (admissions, attendance, grade book, fee payment), diverse user roles (admin, faculty, student), and straightforward database transactions, making it ideal for demonstrating the full SDLC lifecycle.

---

---

## Unit II — Agile Fundamentals, Manifesto & Project Management

### 2M-1. Meaning of Agile Software Development

#### Definition
**Agile Software Development** is an iterative, incremental, and people-centric software engineering approach. It focuses on delivering working software in short, time-boxed cycles (1–4 weeks), collaborating closely with customers, and rapidly adapting to changing requirements.

---

### 2M-2. Principles of Agile Management

#### Two Core Principles
1. **Self-Organizing & Empowered Teams:** Decision-making authority is delegated to the cross-functional team rather than being micro-managed top-down.
2. **Empirical Process Control:** Decisions are grounded in real-time observation, transparency, continuous inspection, and immediate adaptation.

---

### 2M-3. Characteristics of Traditional Software Model

#### Two Key Characteristics
1. **Plan-Driven & Linear:** Comprehensive requirements and detailed project schedules are frozen upfront before design and coding commence.
2. **Heavy Documentation & Stage Gates:** Progress is measured via extensive written deliverables (SRS, design docs) with formal sign-off gates.

---

### 2M-4. Characteristics of Agile Model

#### Two Key Characteristics
1. **Iterative Increments & Continuous Delivery:** Working, tested software increments are released to users at the end of every short iteration.
2. **Welcome Changing Requirements:** Changes are embraced at any stage of development to harness competitive advantage for the customer.

---

### 2M-5. Four Values of the Agile Manifesto

#### The 4 Core Values
1. **Individuals and interactions** over processes and tools.
2. **Working software** over comprehensive documentation.
3. **Customer collaboration** over contract negotiation.
4. **Responding to change** over following a plan.

---

### 2M-6. Purpose of the Agile Manifesto

#### Purpose
Created in 2001 by 17 software leaders in Snowbird, Utah, the **Agile Manifesto** was formulated to challenge bureaucratic, heavyweight, plan-driven methodologies. It establishes a shared philosophy emphasizing human collaboration, rapid feedback, and high responsiveness to change.

---

### 2M-7. Principles of the Agile Manifesto

#### Two Key Principles
1. **Highest Priority:** Satisfy the customer through early and continuous delivery of valuable software.
2. **Frequent Delivery:** Deliver working software frequently, from a couple of weeks to a couple of months, with a preference for shorter timescales.

---

### 2M-8. Purpose of Agile Project Management

#### Purpose
**Agile Project Management (APM)** provides a flexible, value-driven framework to coordinate cross-functional teams, facilitate rapid delivery cycles, eliminate workflow impediments, and ensure alignment between stakeholder goals and developer output.

---

### 2M-9. Agile Team Interaction

#### Two Important Aspects
1. **Daily Face-to-Face Standups:** A brief daily check-in (15 mins) where members share completed work, daily plans, and blockers.
2. **Co-located / Osmotic Communication:** Team members work in close physical or virtual proximity, enabling passive learning and rapid problem resolution.

---

### 2M-10. Ethical Practices in Agile Teams

#### Two Ethical Practices
1. **Honesty & Transparency in Reporting:** Truthfully reporting task progress, technical debt, and estimates without hiding delays or defects.
2. **Respect & Psychological Safety:** Respecting diverse viewpoints during retrospectives and constructive code reviews without personal blame.

---

### 2M-11. Agility in Design

#### Summary
**Agility in Design** rejects heavy upfront over-engineering in favor of simple, evolutionary architecture. Systems are designed to satisfy only current user stories (YAGNI/KISS), utilizing continuous refactoring and design patterns to keep the code malleable for future changes.

---

### 2M-12. Agility in Testing

#### Summary
**Agility in Testing** integrates testing as a continuous, collaborative activity performed alongside development from day one (e.g., TDD, automated unit/regression suites), ensuring the entire team shares responsibility for quality.

---

### 2M-13. Characteristics of Agile Documentation

#### Two Key Characteristics
1. **\"Just-Enough\" & Lean:** Documentation is created only when it delivers tangible business or maintenance value, avoiding speculative manuals.
2. **Living & Executable:** Automated test suites, acceptance scenarios (BDD), and clean code serve as living, verified system documentation.

---

### 2M-14. Agile Drivers

#### Two Major Drivers
1. **Rapid Market Volatility & Competitor Pressure:** Business conditions shift quickly, demanding accelerated time-to-market.
2. **Evolving & Uncertain User Requirements:** Modern digital users cannot fully articulate needs until they interact with working prototypes.

---

### 2M-15. Agile Capabilities

#### Two Core Capabilities
1. **Responsiveness (Flexibility):** The organizational capacity to pivot architectural or functional priorities without destabilizing operations.
2. **Fast Cycle Time (Speed):** The technical ability to build, test, and deploy production-grade software increments within weeks.

---

### 2M-16. Agile Values

#### Two Practical Values
1. **Simplicity:** Maximizing the amount of work *not* done to focus strictly on delivering immediate business value.
2. **Direct Collaboration:** Prioritizing rich, verbal dialogue between engineers and business stakeholders over written memos.

---

### 2M-17. Traditional vs. Agile Models

#### Comparison Table
| Feature | Traditional Model | Agile Model |
|---|---|---|
| **Delivery Model** | Monolithic release at the end | Frequent working increments (every 1–4 weeks) |
| **Change Tolerance** | Rigid, changes resisted via Change Request Forms | Welcomes change at any stage for customer advantage |

---

### 2M-18. Classification of Agile Methods

#### Two Broad Categories
1. **Management & Workflow Focused:** Provide project management, cadence, and ceremonies (e.g., Scrum, Kanban, Lean).
2. **Engineering & Technical Practice Focused:** Prescribe coding standards, testing, and architecture discipline (e.g., Extreme Programming (XP), TDD).

---

### 2M-19. Benefits of Agile Software Development

#### Two Key Benefits
1. **Accelerated Time-to-Market:** High-priority features are deployed to end-users in weeks rather than months or years.
2. **Higher Software Quality & Lower Defect Cost:** Continuous testing and automated integration identify errors immediately.

---

### 2M-20. Importance of Customer Collaboration

#### Importance
Continuous customer collaboration ensures the engineering team builds the *right* product. Direct feedback prevents costly architectural misunderstandings and aligns feature development with genuine business ROI.

---

---

## Unit III — Agile Process Models & Requirements Engineering

### 2M-1. Primary Purpose of Scrum

#### Primary Purpose
The primary purpose of **Scrum** is to provide a lightweight framework that enables cross-functional teams to deliver usable, high-value software increments in short, time-boxed iterations (Sprints) while inspecting and adapting to changing requirements.

---

### 2M-2. Major Roles in Scrum

#### Three Core Roles
1. **Product Owner (PO):** Defines features, prioritizes the Product Backlog, and represents customer value.
2. **Scrum Master (SM):** Acts as a servant-leader, removes blockers, and ensures Scrum practices are followed.
3. **Development Team:** Self-organizing, cross-functional professionals who turn backlog items into working increments.

---

### 2M-3. Purpose of a Sprint

#### Purpose
A **Sprint** is a fixed time-box (typically 1 to 4 weeks) during which a specific set of backlog items are designed, coded, tested, and integrated into a usable, potentially releasable product increment.

---

### 2M-4. Contents of a Product Backlog

#### Core Contents
The **Product Backlog** contains an ordered list of all known product requirements, including:
- Functional features (expressed as user stories).
- Non-functional requirements (performance, security).
- Technical debt, infrastructure enhancements, and bug fixes.

---

### 2M-5. Product Backlog vs. Sprint Backlog

#### Comparison Table
| Feature | Product Backlog | Sprint Backlog |
|---|---|---|
| **Scope** | Entire product roadmap (long-term) | Items chosen for the current Sprint only |
| **Ownership & Change** | Managed and reprioritized solely by Product Owner | Owned by Development Team; frozen during Sprint |

---

### 2M-6. Key Characteristic of Crystal Methodology

#### Key Characteristic
**People-Centric Criticality & Color Coding:** Crystal (developed by Alistair Cockburn) asserts that different projects require different methodologies based on **team size** and **system criticality** (risk to comfort, money, or human life), categorizing methods by colors (Clear, Yellow, Orange, Red).

---

### 2M-7. Feature Driven Development (FDD)

#### Summary
**Feature Driven Development (FDD)** is an iterative, client-centric Agile method organized around delivering tangible, small, client-valued **features** (e.g., \"Calculate shipping fee\") within 2-week cycles, driven by object-oriented domain modeling and chief programmer teams.

---

### 2M-8. Basic Idea of Adaptive Software Development (ASD)

#### Core Idea
Developed by Jim Highsmith, **ASD** replaces traditional \"predictable planning\" with continuous learning under extreme uncertainty, governed by the dynamic three-phase cycle: **Speculate $\to$ Collaborate $\to$ Learn**.

---

### 2M-9. Practices of Extreme Programming (XP)

#### Two Core Practices
1. **Pair Programming:** Two developers collaborate at one workstation; one writes code while the other reviews in real time.
2. **Test-Driven Development (TDD):** Writing automated unit tests *before* writing the functional production code.

---

### 2M-10. Characteristics of Agile Processes

#### Two Key Characteristics
1. **Time-Boxed Iterations:** Work is structured into short, predictable release rhythms (1–4 weeks).
2. **Continuous Feedback Loops:** Daily standups, end-of-iteration customer reviews, and automated builds ensure fast error detection.

---

### 2M-11. Purpose of Agile Requirements Engineering

#### Purpose
The purpose of **Agile Requirements Engineering (ARE)** is to elicit, refine, and prioritize business requirements iteratively and just-in-time, avoiding speculative documentation and allowing software to evolve alongside real customer needs.

---

### 2M-12. Impact of Agile on Requirements Engineering

#### Two Key Impacts
1. **Elimination of Monolithic SRS:** Replaces rigid, 300-page upfront requirements documents with lightweight, living user stories.
2. **Continuous Collaboration:** Shifts requirements from a formal sign-off transaction to daily verbal dialogues between developers and clients.

---

### 2M-13. Meaning of Requirements Elicitation

#### Definition
**Requirements Elicitation** is the process of discovering, surfacing, collecting, and elaborating the needs, constraints, and operational goals of users and stakeholders for a target software system.

---

### 2M-14. Causes of Unstable Requirements

#### Two Major Causes
1. **Dynamic Market & Business Conditions:** Changing competitive landscape, emerging consumer trends, and regulatory law shifts.
2. **Tacit & Unclear User Knowledge:** Stakeholders often cannot articulate what they truly need until they see and interact with an executable prototype.

---

### 2M-15. Agile Practices for Managing Changing Requirements

#### Two Key Practices
1. **Single Prioritized Product Backlog:** All new requests enter a central queue re-ranked by the Product Owner by business value.
2. **Sprint Commitment Boundary:** Once a Sprint begins, new scope is not injected into the active Sprint; new requirements wait for the next Sprint planning.

---

### 2M-16. Meaning of a User Story

#### Definition
A **User Story** is a brief, plain-language description of a software capability written from an end-user's perspective:  
`"As a <role>, I want <goal/feature> so that <benefit>."`

---

### 2M-17. Benefits of Incremental Development

#### Two Key Benefits
1. **Early Realization of Business Value:** High-priority features reach production and generate revenue months ahead of monolithic releases.
2. **Lower Technical Risk:** Integration bugs and architectural flaws are surfaced early and fixed in small codebases.

---

### 2M-18. Scrum vs. XP

#### Comparison Table
| Feature | Scrum | Extreme Programming (XP) |
|---|---|---|
| **Primary Focus** | Management and workflow framework | Software engineering and coding practices |
| **Change During Iteration** | Scope frozen once Sprint begins | Changes allowed if team agrees and swaps equal effort |

---

### 2M-19. Agile Requirements Engineering Practices

#### Two Key Practices
1. **Just-In-Time (JIT) Story Elaboration:** Deferring detailed specifications until the iteration in which the story is scheduled to be coded.
2. **Customer Acceptance Demos:** Validating user story completion through working software demonstrations during Sprint Reviews.

---

### 2M-20. Importance of Requirements Elicitation in Agile

#### Importance
Continuous elicitation prevents the team from building obsolete features. Regular interaction ensures that developer effort is concentrated strictly on high-impact, revenue-generating functionality.

---

---

## Unit IV — Agile Testing & Test-Driven Development (TDD)

### 2M-1. Meaning of Agile Testing

#### Definition
**Agile Testing** is continuous, collaborative software testing that occurs throughout the entire software lifecycle from day one. Rather than treating testing as a separate downstream phase, cross-functional teams test small increments continuously to provide immediate quality feedback.

---

### 2M-2. Effects of Agile Lifecycle on Testing

#### Two Key Effects
1. **Shift-Left Testing:** Testing activities begin at sprint inception alongside user story elaboration rather than waiting for finished code.
2. **Whole-Team Quality Ownership:** Quality is no longer solely the responsibility of a separate QA silo; developers, testers, and product owners collectively ensure defect prevention.

---

### 2M-3. Purpose of Test-Driven Development (TDD)

#### Purpose
The primary purpose of **TDD** is to design clean, modular software with high test coverage by writing an automated test *before* implementing the actual production code, ensuring every line of code is justified by a failing test.

---

### 2M-4. Three Basic Steps in TDD Cycle

#### The Red-Green-Refactor Cycle
1. **RED:** Write a small automated unit test that fails (since the code does not exist yet).
2. **GREEN:** Write the minimal amount of simple code required to make the test pass.
3. **REFACTOR:** Clean and restructure the code to eliminate duplication while keeping all tests passing.

---

### 2M-5. Purpose of an xUnit Framework

#### Purpose
An **xUnit framework** (e.g., JUnit, NUnit, pytest) provides a standardized, automated architecture to define test suites, execute assertions, manage setup/teardown fixtures, and generate pass/fail test reports.

---

### 2M-6. Tools and Frameworks Used for TDD

#### Two Primary Tools
1. **JUnit (Java):** Industry-standard unit testing framework utilizing `@Test` annotations and assertion libraries.
2. **Mockito (Java):** Mocking framework used to simulate dependencies (databases, external APIs) to test classes in complete isolation.

---

### 2M-7. User Story in Agile Testing

#### Role & Meaning
In Agile testing, a **User Story** defines the functional scope and boundary of a testable requirement from an end-user's viewpoint, serving as the direct baseline for writing acceptance criteria and test scenarios.

---

### 2M-8. Definition of an Acceptance Test

#### Definition
An **Acceptance Test** is a formal, verifiable test that evaluates whether a user story fulfills business specifications and satisfies the customer's predefined **Definition of Done (DoD)** before it is accepted into the product release.

---

### 2M-9. Acceptance Test vs. Acceptance Scenario

#### Comparison Table
| Feature | Acceptance Test | Acceptance Scenario |
|---|---|---|
| **Form** | Formal verification check (automated or manual) | Concrete contextual example of system use |
| **Syntax** | Test script or assertion verifying expected outcome | Structured plain language (e.g., Given–When–Then) |

---

### 2M-10. Major Stages in a Testing Cycle

#### Four Key Stages
1. **Test Planning & Elicitation:** Defining test charters and acceptance criteria from stories.
2. **Test Design & Implementation:** Writing automated unit/integration tests and manual charters.
3. **Test Execution & Reporting:** Running regression suites, logging defects, and evaluating build health.
4. **Test Closure & Retrospective:** Reviewing defect metrics and identifying testing process improvements.

---

### 2M-11. Purpose of Exploratory Testing

#### Purpose
**Exploratory Testing** simultaneously combines test design, execution, and learning. It leverages human intuition, experience, and critical thinking to uncover edge-case defects that pre-scripted automated tests fail to anticipate.

---

### 2M-12. Concept of Risk-Based Testing

#### Concept & Formula
**Risk-Based Testing (RBT)** prioritizes testing effort based on the potential consequence of failure. High-risk modules (critical financial calculations, auth systems) are tested first and deepest:
$$\text{Risk Score} = \text{Probability of Failure} \times \text{Impact of Failure}$$

---

### 2M-13. Purpose of Regression Testing

#### Purpose
**Regression Testing** re-runs existing test suites against an updated codebase to confirm that recent code changes, bug fixes, or refactoring have not broken previously functional features.

---

### 2M-14. Benefits of Test Automation

#### Two Key Benefits
1. **Rapid, Repeatable Feedback:** Automated suites execute on every build in minutes, instantly alerting developers to regression bugs.
2. **Cost-Effective Scalability:** Eliminates repetitive, error-prone manual testing, freeing testers for high-value exploratory and usability testing.

---

### 2M-15. Tools Supporting an Agile Tester

#### Two Supporting Tools
1. **Selenium / Playwright:** Browser automation tools for executing end-to-end web acceptance tests.
2. **Postman / REST-Assured:** API testing tools for validating RESTful endpoints and microservice integration.

---

### 2M-16. Importance of Continuous Testing

#### Importance
Continuous testing integrates automated test execution into the Continuous Integration (CI) pipeline, ensuring code quality is inspected on every commit and preventing \"big-bang\" testing bottlenecks at the end of the sprint.

---

### 2M-17. TDD in Agile Software Development

#### Two Key Connections
1. **Living Architectural Safety Net:** TDD produces comprehensive regression test suites that enable safe refactoring as requirements change.
2. **Immediate Developer Feedback:** Developers catch logic errors seconds after typing code, dramatically accelerating iteration velocity.

---

### 2M-18. Manual Testing vs. Automated Testing

#### Comparison Table
| Basis | Manual Testing | Automated Testing |
|---|---|---|
| **Execution** | Human tester interacts with the application | Automated scripts execute tests via framework |
| **Best Used For** | Exploratory, usability, and ad-hoc testing | Repetitive regression, unit, and performance testing |

---

### 2M-19. Purposes of Testing a User Story

#### Two Key Purposes
1. **Verification of Acceptance Criteria:** Ensuring the implemented feature matches the exact behavior agreed upon with the Product Owner.
2. **Boundary & Negative Flow Validation:** Proving the system handles invalid inputs and error conditions gracefully without crashing.

---

### 2M-20. Advantages of Regression Testing in Agile

#### Two Key Advantages
1. **Safe Rapid Delivery:** Guarantees that continuous code changes in bi-weekly sprints do not introduce silent regressions into production.
2. **Preserves System Stability:** Protects core business features as technical debt is actively refactored across iterations.

---

---

## Unit V — Agile Design, Refactoring, CI/CD & Version Control

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
