# Unit 4 — Answers

[⬅ Back to Questions](questions.md#unit-4)

---

### 1. Identify the steps involved in performing risk-based testing

**Risk-based testing** decides what to test first by looking at the risk of failure.

1. **Identify risks:** list areas that could fail (complex, new, critical features).
2. **Assess risks:** rate each by **probability** and **impact**.
3. **Prioritise:** rank by risk level, high to low.
4. **Plan tests:** assign more effort and deeper tests to high-risk areas.
5. **Execute tests:** test high-risk items first.
6. **Monitor and review:** update risks as new information and defects appear.

[⬆ Back to top](#unit-4--answers)

---

### 2. Describe the role of scenarios in Agile testing

A **scenario** is a short story of how a user uses the system, usually written as Given-When-Then.

- **Real-life focus:** tests are based on actual user behaviour.
- **Shared understanding:** customers, developers and testers all read the same scenario.
- **Test case source:** each scenario becomes an **acceptance test**.
- **Early defect detection:** gaps in requirements show up while writing scenarios.
- **Supports automation:** tools like **Cucumber** run scenarios directly.

Example: *Given* a valid login, *When* the user clicks Login, *Then* the dashboard opens.

[⬆ Back to top](#unit-4--answers)

---

### 3. What is exploratory testing? Mention its advantages in Agile projects

**Exploratory testing** is simultaneous learning, test design and execution. The tester explores the software without fixed scripts, using skill and intuition.

**Advantages:**
- Finds bugs that scripted tests miss.
- Needs little preparation, so it suits short sprints.
- Gives fast feedback to developers.
- Adapts quickly when requirements change.
- Uses the tester's creativity and domain knowledge.
- Complements automated regression testing.

[⬆ Back to top](#unit-4--answers)

---

### 4. Explain any four tools/frameworks used for TDD and state their purpose

1. **JUnit:** unit testing framework for Java.
2. **NUnit:** unit testing framework for .NET.
3. **pytest:** simple testing framework for Python.
4. **Mockito:** creates mock objects to isolate the unit under test.

(Alternatives: **Selenium** for web UI tests, **Cucumber** for behaviour-driven tests.)

[⬆ Back to top](#unit-4--answers)

---

### 5. Differentiate between Agile testing and traditional software testing

| Basis | Agile Testing | Traditional Testing |
|---|---|---|
| **Timing** | Continuous, from day one | After development is complete |
| **Team** | Testers work inside the team | Separate testing team |
| **Approach** | Iterative, small increments | Sequential, one big phase |
| **Feedback** | Fast and frequent | Slow, late |
| **Documentation** | Light, scenario-based | Heavy test plans and cases |
| **Change** | Welcomed | Hard to handle |

[⬆ Back to top](#unit-4--answers)

---

### 6. Which types of tests are most suitable for automation in Agile projects?

Automate tests that are **repetitive, stable and frequent**.

- **Unit tests:** fast, written by developers, run on every build.
- **Regression tests:** repeated every iteration to protect old features.
- **Smoke / build verification tests:** quick checks after each build.
- **Integration and API tests:** verify components work together.
- **Acceptance tests:** automate key scenarios (e.g. with Cucumber).
- **Performance / data-driven tests:** repeated with large inputs.

Keep **exploratory and usability testing** manual.

[⬆ Back to top](#unit-4--answers)

---

### 7. How are user stories converted into acceptance tests?

A user story says what the user wants. An acceptance test checks whether it is done.

1. **Read the story:** "As a user, I want to reset my password so that I can regain access."
2. **Define acceptance criteria:** clear pass/fail conditions.
3. **Write scenarios** in Given-When-Then form.
4. **Add cases:** positive, negative and boundary examples.
5. **Agree with the customer** (Product Owner) that these show "done".
6. **Automate** with tools like Cucumber or FitNesse and run every iteration.

[⬆ Back to top](#unit-4--answers)

---

### 8. Describe the Red-Green-Refactor cycle of TDD

**TDD** means writing the test before the code. It runs in a short loop:

- **Red:** write a small test for a new feature. It **fails** since no code exists.
- **Green:** write the **simplest code** to make the test pass.
- **Refactor:** clean up the code and remove duplication. Keep the tests green.

```
   RED (failing test)
     ↑            ↓
REFACTOR  ←  GREEN (test passes)
```

Benefits: fewer bugs, a safety net for change, and cleaner design.

[⬆ Back to top](#unit-4--answers)

---

## Last-minute revision: Unit 4
- **Risk-based testing:** identify → assess → prioritise → plan → execute → review.
- **Exploratory testing:** simultaneous learning, design and execution; finds hidden bugs.
- **TDD tools:** JUnit, NUnit, pytest, Mockito.
- **Automate:** unit, regression, smoke, API tests.
- **Red** (fail) → **Green** (pass) → **Refactor** (clean).
