# Unit 4: Agile Testing & Test-Driven Development (TDD) — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 4](questions.md#unit-iv--agile-testing--test-driven-development-tdd)

---

## Part A: 2-Mark Short Questions

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

## Part B: 8-Mark Questions

### 1. Agile Software Development Lifecycle and Testing Impact

**Q1. Explain the Agile Software Development lifecycle and its impact on software testing activities. (8M)**

#### 1. Agile Development Lifecycle Overview
In Agile, software is built in short, time-boxed iterations (Sprints) delivering a working, tested product increment every 1 to 4 weeks. This rapid rhythm fundamentally transforms testing from a late-stage gatekeeper into an active, continuous quality partner.

```
                  AGILE TESTING LIFECYCLE IN A SPRINT
┌────────────────────────────────────────────────────────────────────────┐
│ Sprint Planning: Define Acceptance Criteria & Given-When-Then Scenarios│
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌───────────────────────────────────┴────────────────────────────────────┐
│ Daily Development: TDD (Red-Green-Refactor) + Automated Unit Tests     │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌───────────────────────────────────┴────────────────────────────────────┐
│ Continuous Integration: Automated API & Regression Runs on Every Build │
└───────────────────────────────────┬────────────────────────────────────┘
                                    │
                                    ▼
┌───────────────────────────────────┴────────────────────────────────────┐
│ Sprint Review & Deployment: User Acceptance Validation (Story "Done")  │
└────────────────────────────────────────────────────────────────────────┘
```

#### 2. Key Impacts on Software Testing Activities
1. **Shift-Left Testing:** Testers participate in Sprint Planning and backlog grooming, clarifying ambiguous acceptance criteria *before* coding begins. Defect prevention replaces late defect detection.
2. **Continuous & Integrated Testing:** Testing occurs daily in lockstep with feature construction. Waiting until code-freeze is abolished.
3. **The Whole-Team Approach to Quality:** Developers write automated unit and integration tests; testers focus on exploratory, edge-case, and automated acceptance testing; the entire team is accountable for delivery quality.
4. **Automation Dependency:** Because regression tests must be executed multiple times a day across every git push, test automation becomes an absolute necessity rather than an optional luxury.
5. **Living Specifications:** Automated acceptance tests (BDD scenarios) act as verified, up-to-date documentation describing system behavior.

---

### 2. Test-Driven Development (TDD) Cycle and Example

**Q2. Describe the Test-Driven Development (TDD) cycle using a suitable example. (8M)**

#### 1. Concept & Philosophy
**Test-Driven Development (TDD)** is an iterative programming discipline formulated by Kent Beck. The fundamental rule of TDD is: **You are not allowed to write any production code unless you first have a failing automated test.**

#### 2. The Red-Green-Refactor Lifecycle Flowchart
```
         ┌───────────────────► RED ───────────────────┐
         │              (Write Failing Test)           │
         │                                            ▼
     REFACTOR ◄───────────────────────────────────── GREEN
 (Clean Code Structure)                         (Make Test Pass)
```

1. **Phase 1: RED (Write a failing test):**
   - Write an automated unit test for a single, small piece of desired behavior.
   - Run the test suite: it **fails** (red) either due to compilation error or assertion failure, proving the feature is missing and the test works.
2. **Phase 2: GREEN (Make the test pass):**
   - Write the simplest, quickest code necessary to pass the test.
   - Do not worry about elegant design at this step; run all tests until they turn **green**.
3. **Phase 3: REFACTOR (Improve code structure):**
   - Clean up code: remove duplication, rename variables, extract methods, improve modularity.
   - Re-run test suite: tests must **stay green**, proving that refactoring preserved original behavior.

#### 3. Concrete Code Walkthrough: String Calculator (Add Numbers)
- **Step 1 (RED):** Write test for empty string returning `0`:
  ```java
  @Test
  void shouldReturnZeroForEmptyString() {
      StringCalculator calc = new StringCalculator();
      assertEquals(0, calc.add("")); // Fails: class/method doesn't exist
  }
  ```
- **Step 2 (GREEN):** Implement minimal code to pass:
  ```java
  public class StringCalculator {
      public int add(String numbers) {
          if (numbers.isEmpty()) return 0;
          return -1;
      }
  } // Passes! Green!
  ```
- **Step 3 (RED):** Add test for single number:
  ```java
  @Test
  void shouldReturnNumberItself() {
      assertEquals(5, new StringCalculator().add("5")); // Fails!
  }
  ```
- **Step 4 (GREEN):** Update implementation:
  ```java
  public int add(String numbers) {
      if (numbers.isEmpty()) return 0;
      return Integer.parseInt(numbers); // Passes!
  }
  ```
- **Step 5 (REFACTOR):** Extract string parsing helpers and clean formatting while keeping all existing tests green.

---

### 3. xUnit Framework and TDD Tools in Agile

**Q3. Discuss the role of the xUnit framework and TDD tools in Agile software development. (8M)**

#### 1. Architecture of the xUnit Family
The **xUnit** architecture (originated by Kent Beck as SUnit for Smalltalk, popularized as JUnit) provides a common conceptual model implemented across nearly all programming languages:

```
┌────────────────────────────────────────────────────────────────────────┐
│                        xUNIT CORE ARCHITECTURE                         │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ Test Runners       │ Test Cases &       │ Assertions & Matchers        │
│ (Discovers & runs) │ Fixtures (Setup /  │ (assertEquals, assertTrue,   │
│                    │  Teardown)         │  assertThrows)               │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

#### 2. Key TDD Tools & Frameworks (From Syllabus & Raw Notes)

| Tool | Language | Primary Purpose & Key Features |
|---|---|---|
| **1. JUnit** | Java | One of the most widely used Java unit-testing frameworks; uses annotations like `@Test` and `@BeforeEach`. |
| **2. NUnit** | .NET / C# | Unit-testing framework for .NET (C#, VB.NET); closely modelled on JUnit; integrates directly with Visual Studio. |
| **3. PyUnit / unittest** | Python | Standard testing framework included directly within Python; used to create and run automated unit tests. |
| **4. Jest** | JavaScript / TypeScript | Modern testing framework providing an integrated test runner, rich assertion library, and built-in mocking support. |

*Additional Supporting Tools:*
- **Mockito:** Popular Java mocking library used alongside JUnit to simulate external dependencies (e.g., databases, web services) for isolated testing.
- **RSpec:** Behavior-driven development (BDD) testing tool for Ruby.

#### 3. Six Common xUnit Concepts
1. **Test Case:** Tests one specific unit of behavior or single logical condition.
2. **Test Fixture:** Fixed baseline state and test data used to execute repeatable tests.
3. **setUp() / tearDown():** Methods executed before and after each test case to prepare environment and clean up resources.
4. **Assertions:** Statements (e.g., `assertEquals()`, `assertTrue()`) that compare actual runtime results against expected outcomes.
5. **Test Suite:** A structured collection of related test cases executed together.
6. **Test Runner:** The execution engine that discovers tests, runs them, and displays pass/fail reports.

#### 4. Strategic Role of xUnit & TDD Tools in Agile
1. **Enables Continuous Integration:** xUnit tests run headless in CI/CD pipelines (GitHub Actions, Jenkins), automatically validating code health on every commit.
2. **Living Safety Net for Refactoring:** Developers can boldly refactor legacy code because thousands of automated unit tests run in seconds to detect broken dependencies.
3. **Self-Documenting Code:** Unit test methods with clear naming conventions document class behavior better than static comments.

---

### 4. Testing User Stories Using Acceptance Tests and Scenarios

**Q4. Illustrate the process of testing user stories using acceptance tests and scenarios with a suitable example. (8M)**

#### 1. The Requirement-to-Test Pipeline
User stories capture what the user wants; acceptance tests establish the concrete boundary conditions under which the story is accepted as \"done\".

```
User Story ──► Acceptance Criteria ──► Scenarios (Given-When-Then) ──► Automated BDD Tests ──► Verified "Done"
```

#### 2. The Given–When–Then (Gherkin) Scenario Format
- **GIVEN:** The initial system context and preconditions.
- **WHEN:** The user action or event that triggers behavior.
- **THEN:** The expected observable outcome and state changes.

#### 3. Concrete Example: Online Banking Fund Transfer
- **User Story:**
  > **As an** authenticated account holder,  
  > **I want to** transfer money to another account,  
  > **So that** I can pay my bills electronically.

- **Scenario 1: Successful Transfer (Happy Path)**
  - *Given* User \"Alice\" has a checking account with a balance of \$500,
  - *And* User \"Bob\" has a valid target account number,
  - *When* Alice transfers \$200 to Bob,
  - *Then* Alice's account balance should become \$300,
  - *And* Bob's account balance should increase by \$200,
  - *And* a transaction receipt with a unique confirmation ID should be displayed.

- **Scenario 2: Insufficient Funds (Negative Path)**
  - *Given* Alice has a balance of \$50,
  - *When* Alice attempts to transfer \$100 to Bob,
  - *Then* the transaction must be declined,
  - *And* Alice's balance must remain \$50,
  - *And* an error message \"Insufficient funds for transfer\" must be displayed.

#### 4. Automation via Behavior-Driven Development (BDD)
Scenarios written in plain language are automated directly using tools such as **Cucumber** or **SpecFlow**, binding each English step to executable test code.

---

### 5. Managing Testing Cycle Plan in Agile

**Q5. Develop a plan for managing the testing cycle in an Agile software project. (8M)**

#### 1. Agile Test Management Strategy
Unlike traditional test plans that produce static 100-page documents, an Agile Testing Plan is an active, iterative roadmap embedded into every Sprint.

#### 2. Phased Testing Cycle in a 2-Week Sprint

```
WEEK 1: Days 1–3                   WEEK 1: Days 4–5 & WEEK 2: Days 6–8     WEEK 2: Days 9–10
┌───────────────────────────────┐  ┌────────────────────────────────────┐  ┌───────────────────────────────┐
│ Elicitation & Shift-Left:     │  │ Concurrent Execution:              │  │ Hardening & Acceptance:       │
│ • Review acceptance criteria  │─►│ • TDD unit testing                 │─►│ • Full regression suite runs  │
│ • Write BDD Given-When-Then   │  │ • Exploratory testing on stories   │  │ • Product Owner demo (UAT)    │
│ • Set up test data & mocks    │  │ • Automated API & integration tests│  │ • Retrospective & test metrics│
└───────────────────────────────┘  └────────────────────────────────────┘  └───────────────────────────────┘
```

#### 3. Core Components of the Agile Testing Plan
1. **Test Scope & Definition of Done (DoD):**
   - A story is not \"done\" until unit tests pass with $\ge 85\%$ coverage, all acceptance scenarios pass, and regression tests run green in CI.
2. **Environment & Test Data Management:**
   - Isolated staging environments and automated mock servers ensuring reproducible test runs.
3. **Defect Management Protocol:**
   - Defects found during the active Sprint are fixed immediately by developers (zero-bug policy) without logging formal Jira tickets.
   - Out-of-sprint bugs are logged to the Product Backlog for PO prioritization.
4. **Test Reporting & Metrics:**
   - Automated CI build reports, pass/fail trends, automated test execution duration, and Sprint burndown charts visible on the team's radiator.

---

### 6. Exploratory Testing vs. Risk-Based Testing

**Q6. Differentiate Exploratory Testing and Risk-Based Testing with respect to objectives, approach, and application. (8M)**

#### 1. Core Principles
- **Exploratory Testing (Cem Kaner / James Bach):** Human-centric testing that emphasizes simultaneous learning, test design, and execution.
- **Risk-Based Testing:** Analytical, structured testing where effort and execution sequence are dictated by potential business and technical failure hazards.

#### 2. Detailed Comparative Matrix

| Basis | Exploratory Testing | Risk-Based Testing |
|---|---|---|
| **Primary Objective** | Discover unpredicted, subtle defects and usability flaws that scripted tests miss. | Optimize limited sprint testing time by focusing strictly on high-impact, high-probability failure points. |
| **Approach** | Intuitive, heuristic-driven; uses **Test Charters** and time-boxed sessions (SBTM). | Quantitative and analytical; calculates: $\text{Risk} = \text{Probability} \times \text{Impact}$. |
| **Planning & Documentation** | Light; short charter mission statement, session notes, and debriefing records. | Structured; produces Risk Assessment Matrices and prioritized test suites. |
| **Execution Timing** | Throughout the sprint as new features become testable; ideal for rapid change. | Early in the sprint during backlog grooming to classify stories into High/Med/Low risk. |
| **Skill Dependency** | Heavily dependent on tester creativity, domain knowledge, and technical curiosity. | Dependent on collaborative risk brainstorming among PO, architect, and QA leads. |
| **Ideal Application** | New user interfaces, complex user journeys, edge-case validation. | Core payment gateways, authentication systems, medical/safety firmware. |

#### 3. Risk Assessment Matrix Table (RBT Tool)
| Probability \ Impact | Low Impact | High Impact |
|---|---|---|
| **High Probability** | Medium Risk (Moderate Testing) | **Critical Risk (Intensive Testing First)** |
| **Low Probability** | Low Risk (Light / Minimal Testing) | Medium Risk (Automated Smoke Testing) |

---

### 7. Regression Testing and Test Automation in Agile

**Q7. Analyze the role of Regression Testing and Test Automation in maintaining software quality during Agile iterations. (8M)**

#### 1. The Agile Regression Challenge
In Agile, code is modified, extended, and refactored every single day. Without systematic regression testing, new feature additions will frequently and silently break existing functionality.

#### 2. The Test Automation Pyramid (Mike Cohn)

```
             /\
            /  \       UI / End-to-End Tests (10%)  ── [Few, Slow, Fragile]
           /----\
          /      \     API / Service Tests   (20%)  ── [Fast, Stable]
         /--------\
        /          \   Unit Tests            (70%)  ── [Massive, Sub-second, Robust]
       /____________\
```

1. **Unit Testing Layer (Base):** Fast, isolated tests written in JUnit/pytest. Runs thousands of checks in seconds on developer machines before commit.
2. **Service / API Testing Layer (Middle):** Validates business logic, database queries, and microservice integration without UI latency.
3. **UI / End-to-End Testing Layer (Top):** Validates complete user journeys via Selenium/Cypress. Kept lean to prevent high maintenance costs.

#### 3. Strategic Role in Agile Quality Maintenance
1. **Safety Net for Continuous Refactoring:** Automated regression suites guarantee that restructuring code to eliminate technical debt does not alter external behavior.
2. **Enables Continuous Integration & Continuous Delivery (CI/CD):** Every git push automatically runs the regression suite; bad builds are rejected within minutes.
3. **Reduces Quality Costs:** Finding a regression bug immediately on day 3 of a sprint costs 10x less than finding it during customer deployment.
4. **Frees Human Testers for Exploratory Testing:** Eliminates the drudgery of executing hundreds of repetitive manual checklists every sprint.

---

### 8. TDD-Based Testing Strategy for Healthcare Application

**Q8. Design a TDD-based testing strategy for a healthcare application covering user stories, acceptance tests, regression testing, automation, and testing tools. (8M)**

#### 1. System Overview & Criticality
A **Healthcare Patient Vitals & Medication Management System** tracks patient heart rate, blood pressure, and automated drug dosage administration. Defects can lead to medical malpractice or loss of life; hence, testing must be exhaustive, automated, and strictly verified.

#### 2. Architecture of the Testing Strategy

```
┌────────────────────────────────────────────────────────────────────────┐
│               HEALTHCARE APPLICATION TESTING ARCHITECTURE              │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. User Stories &  │ 2. TDD Unit Test   │ 3. Automated API &           │
│    BDD Acceptance  │    Layer           │    Integration Layer         │
│    Criteria        │    (JUnit/Mockito) │    (REST-Assured/DBUnit)     │
├────────────────────┼────────────────────┼──────────────────────────────┤
│ 4. CI Regression   │ 5. Automated E2E & │ Expected Outcome:            │
│    Pipeline        │    Exploratory QA  │ Zero-Defect Medication       │
│    (GitHub Actions)│    (Playwright)    │ Safety Certification         │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

#### 3. Execution Plan Breakdown

1. **User Story & Acceptance Criteria (BDD Specification):**
   - *Story:* \"As a registered physician, I want to prescribe pediatric antibiotic dosage based on patient weight, so that the patient receives a safe, therapeutic quantity.\"
   - *Acceptance Scenario:*
     - *Given* patient age is 5 years and weight is 18 kg,
     - *When* physician selects Amoxicillin (recommended: 20 mg/kg/day),
     - *Then* system calculates maximum daily dosage as 360 mg,
     - *And* flags an alert if entered dosage exceeds 400 mg.
2. **TDD Implementation (Red-Green-Refactor):**
   - Write failing unit test `testDosageCalculationForPediatricPatient()` in JUnit 5.
   - Implement `DosageCalculator` class to pass test.
   - Refactor dosage rules into clean domain policy classes.
3. **Mocking & Integration Testing:**
   - Use **Mockito** to mock external pharmacy inventory and hospital EHR database connections, ensuring dosage logic is verified in complete isolation.
4. **Automated Regression Pipeline (CI/CD):**
   - GitHub Actions runs full 500+ unit test suite on every commit; build fails if any test fails.
   - Automated nightly runs verify end-to-end patient record synchronization.
5. **Tools Stack:**
   - *Unit & Mocks:* JUnit 5, Mockito.
   - *BDD Acceptance:* Cucumber with Gherkin.
   - *API Verification:* REST-Assured.
   - *E2E Browser Validation:* Playwright.
