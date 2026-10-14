# Unit 4 — Answers

> **Questions File:** [`questions.md` — Unit 4](questions.md#unit-4)

---

### 1. Identify the steps involved in performing risk-based testing

**Definition:** **Risk-based testing (RBT)** is a testing approach where test effort is decided by **risk**. The features most likely to fail, and most damaging if they fail, are tested **first and deepest**. It is useful in Agile because time in each Sprint is short and everything cannot be tested equally.

**Risk = Probability of failure × Impact of failure**

**Steps involved:**

1. **Identify risks**
   - List what can go wrong: new or complex features, changed code, critical business functions, areas with past defects, third-party integration.
   - Use brainstorming with developers, testers and the Product Owner.

2. **Analyse and assess risks**
   - Rate each risk for **probability** (how likely to fail) and **impact** (how bad the damage is).
   - Use simple scales: High / Medium / Low.

3. **Prioritise risks**
   - Rank items using the risk score. Example matrix:

| | Low Impact | High Impact |
|---|---|---|
| **High Probability** | Medium | **Critical** |
| **Low Probability** | Low | Medium |

4. **Plan the testing**
   - Choose test types and techniques for each risk level.
   - **High risk:** more tests, early testing, automation, exploratory testing.
   - **Low risk:** light or minimal testing.

5. **Design and execute tests**
   - Write test cases and run **high-risk tests first**.
   - Log defects and report their severity.

6. **Mitigate risks**
   - Fix defects, add extra checks or change the design where risks remain high.

7. **Monitor, review and update**
   - Risks change every Sprint. Re-check the list in each iteration and adjust the test plan.

**Benefits:** best use of limited time, serious defects found early, clear communication of quality status to stakeholders.

---

### 2. Describe the role of scenarios in Agile testing

**Definition:** A **scenario** is a short, realistic description of **how a user will use the system to reach a goal**. In Agile, scenarios are often written in **Given–When–Then** format. They connect user stories with test cases.

**Format:**
- **Given** – the starting condition.
- **When** – the action done by the user.
- **Then** – the expected result.

**Example (Online shopping):**
- *Given* the user has added a product to the cart,
- *When* the user clicks "Place Order" with valid payment details,
- *Then* the system shows an order confirmation and sends an email.

**Role of scenarios in Agile testing:**

1. **Understanding requirements:** scenarios explain a user story with a concrete example, so everyone understands the need in the same way.
2. **Basis for acceptance tests:** each scenario becomes an **acceptance test** that proves a story is "done".
3. **Better communication:** customers, developers and testers can all read the plain-language scenarios, which reduces misunderstanding.
4. **Early defect detection:** missing or unclear requirements are found while writing scenarios, before coding starts.
5. **User-focused testing:** tests follow real user journeys, not just technical functions.
6. **Coverage of cases:** scenarios include **normal flow, alternate flow and error flow**, giving wide coverage.
7. **Supports automation and BDD:** tools such as **Cucumber** and **SpecFlow** can run scenarios directly as automated tests.
8. **Living documentation:** scenarios stay up to date with the product and serve as light documentation.

**Conclusion:** Scenarios turn requirements into testable examples, which improves clarity, quality and teamwork in Agile projects.

---

### 3. What is exploratory testing? Mention its advantages in Agile projects

**Definition:** **Exploratory testing** is an approach where the tester **learns the software, designs tests and executes them at the same time**, without detailed pre-written test scripts. The tester uses experience, creativity and intuition to explore the application and find defects.

**How it is done:**
- Testers are given a **test charter** (a short mission, e.g. "Explore the payment page for invalid inputs").
- Testing is done in **time-boxed sessions** (for example 60 to 90 minutes).
- Testers take **notes** of what they tried and what they found.
- A short **debrief** shares the results with the team.

**Advantages in Agile projects:**

1. **Fast start:** needs little preparation or documentation, so it fits short Sprints.
2. **Finds hidden defects:** discovers unexpected bugs that scripted tests miss.
3. **Quick feedback:** defects are reported to developers immediately.
4. **Adapts to change:** testers can change direction instantly when requirements or code change.
5. **Uses tester skill:** takes advantage of knowledge, curiosity and domain understanding.
6. **Saves effort:** less time spent writing and maintaining test scripts.
7. **Improves learning:** testers understand the product better with each session.
8. **Complements automation:** automation covers repetitive regression, while exploratory testing covers new and risky areas.

**Limitations (brief):** results depend on tester skill, and it is harder to measure coverage. These are reduced by using charters and session notes.

**Conclusion:** Exploratory testing gives flexible, quick and creative testing that suits the fast pace of Agile.

---

### 4. Explain any four tools/frameworks used for TDD and state their purpose

**TDD (Test-Driven Development)** needs a testing framework to write and run tests quickly. Four well-known tools are:

**1. JUnit (Java)**
- A **unit testing framework** for Java.
- Purpose: write and run repeatable tests for methods and classes.
- Uses annotations such as `@Test`, `@BeforeEach` and assertions like `assertEquals()`.
- Easily runs inside IDEs and CI tools.

**2. NUnit (.NET / C#)**
- A **unit testing framework** for .NET languages.
- Purpose: test C# classes and methods with attributes such as `[Test]` and `[SetUp]`.
- Supports parameterised tests and detailed test reports.

**3. pytest (Python)**
- A simple and powerful **testing framework** for Python.
- Purpose: write short test functions using plain `assert` statements.
- Offers fixtures, automatic test discovery and many plug-ins.

**4. Mockito (Java)**
- A **mocking framework**.
- Purpose: create **fake (mock) objects** of dependencies such as a database or web service, so a class can be tested **in isolation**.
- Allows checking that a method was called with the right values.

**Summary table:**

| Tool | Language | Main purpose |
|---|---|---|
| **JUnit** | Java | Unit tests |
| **NUnit** | C# / .NET | Unit tests |
| **pytest** | Python | Simple, flexible unit tests |
| **Mockito** | Java | Mock objects for isolation |

**Other tools (extra):** **Selenium** for web UI testing, **Cucumber** for behaviour-driven tests, **Jest** for JavaScript.

**Conclusion:** These tools make the Red-Green-Refactor cycle fast, automatic and reliable.

---

### 5. Differentiate between Agile testing and traditional software testing

**Agile testing** is testing done continuously as part of the Agile team. **Traditional testing** is done as a separate phase after development (as in the Waterfall model).

| Basis | Agile Testing | Traditional Testing |
|---|---|---|
| **When testing starts** | From the **first day**, along with development | **After coding** is complete |
| **Process** | **Continuous** and iterative | Separate **phase** in sequence |
| **Team structure** | Testers are **part of the development team** | **Separate testing team** |
| **Requirements** | Accepts **changing** requirements | Needs **fixed** requirements |
| **Feedback** | **Quick and frequent** | Slow and late |
| **Documentation** | **Light**: scenarios, checklists | **Heavy**: test plans, test cases, reports |
| **Customer role** | Customer takes part in testing and acceptance | Customer involved only at the end |
| **Automation** | Strongly encouraged (regression, unit tests) | Often mostly manual |
| **Defect cost** | **Low**, defects found early | **High**, defects found late |
| **Responsibility** | **Whole team** owns quality | Only testers own quality |
| **Delivery** | Small working increments | Single big release |

**Explanation:**
- In Agile, a tester works with developers in every Sprint, tests each story as soon as it is ready and gives immediate feedback.
- In traditional testing, testers wait until the full product is built. Defects found at that point are expensive to fix.

**Conclusion:** Agile testing is early, collaborative and flexible, while traditional testing is late, formal and document-driven.

---

### 6. Which types of tests are most suitable for automation in Agile projects?

**Principle:** Automate tests that are **repeated often, stable, time-consuming and easy to script**. Because Agile releases frequently, automation gives fast and reliable feedback.

**Tests suitable for automation:**

1. **Unit tests**
   - Test a single method or class.
   - Fast, run on every build; written by developers (JUnit, NUnit, pytest).

2. **Regression tests**
   - Repeated every iteration to ensure new changes do not break old features.
   - Best candidate for automation.

3. **Smoke / sanity tests**
   - Quick check after each build to confirm that main functions work.

4. **Integration and API tests**
   - Check that modules, services and databases work together.
   - More stable and faster than UI tests (e.g. Postman, REST-assured).

5. **Acceptance tests (BDD)**
   - Key business scenarios written in Given-When-Then and run automatically (Cucumber, FitNesse).

6. **Data-driven tests**
   - Same test repeated with many input sets.

7. **Performance and load tests**
   - Simulating many users is not practical by hand (JMeter).

8. **Cross-browser / cross-platform tests**
   - Same test run on many browsers or devices (Selenium).

**Test automation pyramid:**
```
        /\        UI tests (few, slow)
       /--\
      /    \      Integration / API tests (some)
     /------\
    /        \    Unit tests (many, fast)
   /__________\
```

**Not suitable for automation:** exploratory testing, usability testing, one-time tests and tests for rapidly changing features. Keep these **manual**.

**Conclusion:** Automating unit, regression, API and acceptance tests saves time and supports continuous delivery in Agile.

---

### 7. How are user stories converted into acceptance tests?

**User story:** a short requirement written from the user's view: *"As a <role>, I want <feature> so that <benefit>."*

**Acceptance test:** a test that checks whether the story is **complete and meets the customer's expectations**.

**Steps to convert a user story into acceptance tests:**

1. **Understand the story**
   - Example: *"As a registered user, I want to reset my password so that I can log in if I forget it."*

2. **Discuss with the Product Owner/customer**
   - Clarify doubts, limits and business rules (e.g. link expires in 24 hours).

3. **Define acceptance criteria**
   - Clear pass/fail conditions:
     - A reset link is sent to the registered email.
     - Link expires after 24 hours.
     - New password must be at least 8 characters.

4. **Write scenarios in Given–When–Then form**
   - *Given* the user is registered, *When* they request a reset, *Then* an email with a link is sent.

5. **Add variations**
   - **Positive** case (valid email), **negative** case (unknown email), **boundary** case (link at 24 hours).

6. **Review and agree**
   - Customer, developer and tester confirm that these tests define "done".

7. **Automate and run**
   - Automate with **Cucumber, FitNesse or Selenium** and run them in every build.

8. **Use as Definition of Done**
   - The story is accepted only when all its acceptance tests pass.

**Flow:**
```
User Story → Acceptance Criteria → Scenarios (Given-When-Then) → Automated Acceptance Tests → Story "Done"
```

**Conclusion:** Acceptance tests turn a short story into clear, testable conditions that confirm the customer's need is met.

---

### 8. Describe the Red-Green-Refactor cycle of TDD

**Definition:** **Test-Driven Development (TDD)** is a technique where the developer writes a **test before writing the code**. The work is done in very short cycles called **Red–Green–Refactor**.

**The three phases:**

1. **RED – Write a failing test**
   - Write a small test for one new behaviour.
   - Run it. It **fails** (shows red) because the code does not exist yet.
   - This confirms the test is working and the feature is really missing.

2. **GREEN – Make the test pass**
   - Write the **simplest and quickest code** that makes the test pass.
   - Do not worry about perfect design at this stage.
   - Run all tests. They turn **green**.

3. **REFACTOR – Clean the code**
   - Improve the code: remove duplication, rename, simplify structure.
   - Run the tests again. They must **stay green**, which proves the behaviour did not change.

**Diagram:**
```
        ┌──────────► RED ──────────┐
        │     (write failing test)  │
        │                           ▼
   REFACTOR ◄────────────────── GREEN
 (clean the code)         (make the test pass)
```

**Small example:** Feature: add two numbers.
- Red: test `add(2,3) == 5` fails (no function).
- Green: write `add(a,b){ return a+b; }` – test passes.
- Refactor: improve naming or structure if needed.
- Repeat for the next behaviour.

**Benefits:**
- Fewer bugs and high test coverage.
- A safety net for future changes.
- Simple, clean, well-designed code.
- Developers think about requirements before coding.
- Gives confidence while refactoring.

**Conclusion:** Red-Green-Refactor builds quality into the code from the start and is a key practice of Agile and XP.

---

## Last-minute revision: Unit 4
- **Risk-based testing:** Risk = Probability × Impact; identify → assess → prioritise → plan → execute → mitigate → review.
- **Scenarios** use Given-When-Then and become acceptance tests; **exploratory testing** = learn + design + execute together, using charters.
- **TDD tools:** JUnit (Java), NUnit (.NET), pytest (Python), Mockito (mocks).
- **Automate:** unit, regression, smoke, API, acceptance, data-driven, performance. Keep exploratory and usability manual.
- **Red** (failing test) → **Green** (simplest code passes) → **Refactor** (clean, tests stay green).
