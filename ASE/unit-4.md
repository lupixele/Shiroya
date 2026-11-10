# Unit 4: Agile Testing & Test-Driven Development (TDD) — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 4](questions.md#unit-iv--agile-testing--test-driven-development-tdd)

---

## 1. Agile Software Development Lifecycle and Testing Impact

**Q1. Explain the Agile Software Development lifecycle and its impact on software testing activities. (8M)**

### 1. Introduction

**Agile Software Development** is an iterative and incremental approach in which software is developed in small cycles. Each cycle delivers a working part of the product. Testing is performed continuously during development instead of waiting until the end.

### 2. Agile Software Development lifecycle

**1. Requirements**
- Requirements are collected from customers and stakeholders.
- They are written as user stories and acceptance criteria.
- Requirements can be updated when new needs are identified.

**2. Planning**
- The team selects high-priority requirements for an iteration or Sprint.
- Tasks, responsibilities and goals are decided.
- Testing activities are planned along with development.

**3. Design**
- The team prepares a simple design for the selected features.
- Testers and developers discuss expected behavior and possible risks.
- The design can be improved as feedback is received.

**4. Development**
- Developers write code for the selected features.
- Unit tests and other automated checks may be written while coding.
- Developers and testers communicate regularly.

**5. Testing**
- The developed features are tested during the iteration.
- Defects are identified and corrected quickly.
- Integration, acceptance and regression testing are performed as appropriate.

**6. Review and feedback**
- Working software is demonstrated to customers or stakeholders.
- Feedback is collected and requirements may be updated.

**7. Release and maintenance**
- A tested increment is delivered.
- The team monitors the software and fixes problems.
- New improvements are planned for later iterations.

### 3. Impact of the Agile lifecycle on testing
- **Testing starts early:** Testers participate from requirements and design stages.
- **Testing is continuous:** Each iteration includes testing activities.
- **Frequent feedback:** Defects and misunderstandings can be found earlier.
- **Changing requirements:** Test cases may need to be updated when requirements change.
- **Automation:** Repeated tests can be automated to provide quick feedback.
- **Regression testing:** Existing features are retested after changes.
- **Team responsibility:** Developers, testers and stakeholders work together for quality.

### 4. Example

For a student attendance application:
- In one iteration, the team develops student login and attendance entry.
- Testers check login, attendance saving and invalid inputs during the same iteration.
- Faculty review the working feature and suggest changes.
- The team updates the feature and reruns relevant regression tests.

### 5. Conclusion

The Agile lifecycle makes testing a continuous activity. Early testing, collaboration, automation and repeated feedback help the team identify defects sooner and maintain software quality during every iteration.

**Memory trick: R--P--D--D--T--F--R = "Requirements, Plan, Design, Develop, Test, Feedback, Release."**

For the impact remember **E--C--F--A--R--T**: Early testing, Continuous testing, Feedback, Automation, Regression, Team responsibility.

---

## 2. Test-Driven Development (TDD) Cycle and Example

**Q2. Describe the Test-Driven Development (TDD) cycle using a suitable example. (8M)**

### 1. Introduction

**Test-Driven Development (TDD)** is a software development technique in which developers write a test before writing the actual program code. They then write code to pass the test and improve the code while keeping the tests passing.

### 2. Three steps in the TDD cycle

**1. Red -- Write a failing test**
- Write a small test for the required behavior before implementing it.
- Run the test.
- It fails because the required code is not yet available or complete.

**2. Green -- Write code to pass the test**
- Write the minimum code needed to make the test pass.
- Run the test again.
- Confirm that the expected behavior works.

**3. Refactor -- Improve the code**
- Clean and improve the internal structure of the code.
- Remove duplication and improve readability.
- Run the tests again to ensure behavior has not changed.

The cycle repeats for each small requirement.

### 3. TDD cycle diagram

``` text
       RED
  Write a failing test
         ↓
       GREEN
  Write code to pass
         ↓
      REFACTOR
  Improve the code
         ↓
   Repeat the cycle
```

### 4. Example: Addition function

Suppose a developer needs a function that adds two numbers.

**Step 1 -- Red:** Write a test expecting `add(2, 3)` to return `5`. Run it; it fails because the function is not implemented.

**Step 2 -- Green:** Write a simple function that returns the sum of the two numbers. Run the test; it passes.

**Step 3 -- Refactor:** Improve the code's naming or structure if necessary, then run the test again to confirm it still passes.

### 5. Advantages of TDD
- Finds defects early.
- Clarifies expected behavior before coding.
- Encourages small and simple code changes.
- Provides tests that can be reused during regression testing.
- Makes refactoring safer.
- Improves confidence in the code.

### 6. Conclusion

TDD follows the Red--Green--Refactor cycle. Writing tests before code helps developers understand the expected behavior, detect errors early and maintain code quality.

**Memory trick: R--G--R = "Red, Green, Refactor."**
- Red = Test fails.
- Green = Code passes.
- Refactor = Improve code.

Remember: **Test first → Make it pass → Clean it.**
- --

## 3. xUnit Framework and TDD Tools in Agile

**Q3. Discuss the role of the xUnit framework and TDD tools in Agile software development. (8M)**

### 1. Introduction

An **xUnit framework** is a family of unit-testing frameworks used to write and execute automated tests. Examples include JUnit for Java, NUnit for .NET and pytest for Python (pytest is commonly used for Python testing, though it is not named with the xUnit prefix).

TDD tools help developers write tests, run them frequently and receive quick feedback during development.

### 2. Role of xUnit frameworks

**1. Writing test cases**
- Developers create tests for individual functions or units.
- Each test checks a particular expected behavior.

**2. Running tests automatically**
- The framework executes test cases.
- It reports whether tests pass or fail.

**3. Assertions**
- Assertions compare actual results with expected results.
- Example: Check whether a function returns 5 for the input 2 and 3.

**4. Test organization**
- Tests can be grouped into test classes or suites.
- This makes large test collections easier to manage.

**5. Regression support**
- Existing tests can be rerun after code changes.
- This helps detect whether previously working features have broken.

**6. Integration with development tools**
- Test frameworks can be used with IDEs and Continuous Integration systems.
- Tests can run automatically when code is changed or committed.

### 3. Examples of TDD / testing tools
- **JUnit:** Unit-testing framework for Java.
- **NUnit:** Unit-testing framework for .NET.
- **pytest:** Testing framework widely used with Python.
- **GoogleTest:** C++ testing framework.
- **TestNG:** Testing framework for Java.

### 4. Role of tools in TDD
- Help write tests before implementation.
- Execute tests quickly after code changes.
- Show failures so developers can correct defects.
- Support repeated testing during refactoring.
- Reduce manual effort in checking basic functionality.
- Provide confidence when integrating code.

### 5. Example

A developer writes a Python function to calculate a student's total marks. A test checks whether the total of 70 and 80 is 150. The test framework runs the test and reports the result. When the function is changed, the same test can be run again.

### 6. Conclusion

xUnit frameworks and TDD tools support Agile development by automating unit tests, providing quick feedback and helping detect defects early. They make continuous testing and safe refactoring easier.

**Memory trick: W--R--A--O--I = "Write, Run, Assert, Organize, Integrate."**
- Write test cases.
- Run tests automatically.
- Use assertions.
- Organize test suites.
- Integrate with development tools.

Tools recall: **J--N--P--G--T** = JUnit, NUnit, pytest, GoogleTest, TestNG.

---

## 4. Testing User Stories Using Acceptance Tests and Scenarios

**Q4. Illustrate the process of testing user stories using acceptance tests and scenarios with a suitable example. (8M)**

### 1. Introduction

A **user story** is a short description of a feature from the user's point of view. Acceptance testing checks whether the developed feature satisfies the conditions agreed with the customer.

An **acceptance scenario** describes a particular situation and the expected result used to verify a user story.

### 2. Process of testing a user story

**1. Understand the user story**
- Read the story and identify the user's goal.
- Clarify unclear requirements with the customer or Product Owner.

**2. Define acceptance criteria**
- Write clear conditions that must be satisfied.
- Criteria should be understandable and testable.

**3. Create acceptance scenarios**
- Identify normal, alternative and error situations.
- Describe the input or action and the expected result.

**4. Prepare test data**
- Select suitable valid and invalid data.
- Prepare the required test environment.

**5. Execute acceptance tests**
- Perform the steps in each scenario.
- Compare actual results with expected results.

**6. Record defects**
- Report failed tests with steps and evidence.
- Developers correct the defects.

**7. Retest and accept**
- Run the tests again after fixes.
- Confirm that the acceptance criteria are satisfied.

### 3. Example: Student login user story

**User story:** "As a student, I want to log in using my college ID and password so that I can access my student account."

**Acceptance criteria:**
- A registered student can log in with valid details.
- An incorrect password should not allow login.
- Required fields should not be left empty.
- A suitable error message should be displayed for invalid details.

**Acceptance scenarios:**

| Scenario | Test Input / Action | Expected Result |
|---|---|---|
| **Valid login** | Enter correct ID and password | Student dashboard opens |
| **Invalid password** | Enter correct ID and wrong password | Login is rejected and error is shown |
| **Empty fields** | Submit without ID or password | Validation message appears |
| **Unknown ID** | Enter an unregistered ID | Login is rejected |

### 4. Acceptance test vs acceptance scenario

| Acceptance Test | Acceptance Scenario |
|---|---|
| A test used to check whether a story meets its acceptance criteria | A specific situation or example to be checked |
| May contain several steps and checks | Describes one particular case and expected behavior |
| Verifies the feature as a whole or against criteria | Helps define one path through the feature |

### 5. Importance
- Confirms that the feature meets customer expectations.
- Makes requirements clearer.
- Reduces misunderstanding between developers and customers.
- Finds missing or incorrect behavior.
- Provides a basis for deciding whether a story is accepted.

### 6. Conclusion

User stories are tested by defining acceptance criteria, creating scenarios, preparing test data, executing tests and confirming the results. This ensures that delivered features meet user needs.

**Memory trick: U--C--S--D--E--R--A = "Understand, Criteria, Scenarios, Data, Execute, Record, Accept."**

---

## 5. Managing Testing Cycle Plan in Agile

**Q5. Develop a plan for managing the testing cycle in an Agile software project. (8M)**

### 1. Introduction

The **Agile testing cycle** is a continuous process of planning, designing, executing and reviewing tests during every development iteration. Testing is performed alongside coding to identify defects early and maintain software quality.

### 2. Testing cycle activities

**1. Requirement analysis**
- Understand user stories and acceptance criteria.
- Identify expected behavior and possible risks.
- Clarify requirements with stakeholders.

**2. Test planning**
- Decide what needs to be tested in the iteration.
- Select testing methods, tools and resources.
- Estimate testing effort and schedule.

**3. Test design**
- Prepare test cases and scenarios.
- Select valid, invalid and boundary test data.
- Define expected results.

**4. Test environment preparation**
- Set up the required hardware, software and test data.
- Ensure the environment is suitable for testing.

**5. Test execution**
- Execute unit, integration, functional and acceptance tests as appropriate.
- Compare actual and expected results.
- Run automated tests where suitable.

**6. Defect reporting and fixing**
- Record defects with clear steps and evidence.
- Assign defects to the appropriate team members.
- Correct the defects and retest.

**7. Regression testing**
- Rerun relevant existing tests after changes.
- Check that previously working features still work.

**8. Review and improvement**
- Review test results and quality.
- Discuss testing problems during the retrospective.
- Improve the testing approach in the next iteration.

### 3. Example: Online shopping application

During a Sprint for the shopping cart:
- Analyze the cart user story.
- Plan tests for adding, removing and changing quantities.
- Prepare test cases and sample products.
- Execute functional tests.
- Report and fix any defects.
- Rerun cart tests and related checkout regression tests.
- Review the results before the Sprint is completed.

### 4. Benefits
- Defects are found earlier.
- Testing remains aligned with changing requirements.
- Frequent feedback improves product quality.
- Automation reduces repeated manual work.
- Regression testing protects existing features.
- The team can improve testing after every iteration.

### 5. Conclusion

An Agile testing plan includes requirement analysis, planning, test design, environment setup, execution, defect fixing, regression testing and review. Repeating these activities in every iteration helps maintain quality.

**Memory trick: R--P--D--E--F--R--R = "Requirements, Plan, Design, Environment, Execute, Fix, Recheck."**

---

## 6. Exploratory Testing vs. Risk-Based Testing

**Q6. Differentiate Exploratory Testing and Risk-Based Testing with respect to objectives, approach, and application. (8M)**

### 1. Introduction

**Exploratory Testing** and **Risk-Based Testing** are testing approaches used to find defects, but they have different focuses.
- Exploratory Testing uses learning, test design and execution together.
- Risk-Based Testing gives priority to areas that have the greatest risk of failure or impact.

### 2. Exploratory Testing
- Testers explore the application to understand its behavior.
- Test design and test execution happen together.
- Testers use their knowledge and observations to discover unexpected defects.
- It is useful when requirements are incomplete or when new areas need investigation.

**Example:** A tester explores a shopping application by trying different product searches, cart actions and unusual input combinations to discover unexpected problems.

### 3. Risk-Based Testing
- Testing is prioritized according to the likelihood and impact of failure.
- High-risk features receive more testing effort.
- Risk assessment helps decide what to test first and how deeply.
- It is useful when time and testing resources are limited.

**Example:** In a banking application, money transfers and login security may receive higher testing priority because failures can have serious consequences.

### 4. Comparison

| Basis | Exploratory Testing | Risk-Based Testing |
|---|---|---|
| **Main objective** | Discover unexpected defects and learn the application | Reduce the chance and impact of important failures |
| **Approach** | Tester explores and designs tests while executing them | Tests are prioritized using risk analysis |
| **Test cases** | May be created and adjusted during exploration | Focus is based on identified risks and priorities |
| **Focus** | Behavior, usability and unexpected situations | High-risk features and failure impact |
| **Best application** | New, changing or poorly understood features | Critical features and projects with limited testing time |
| **Tester role** | Uses observation, creativity and experience | Assesses risk and allocates testing effort |

### 5. Using both together

A team can combine the two approaches. Risk analysis can identify a high-risk payment feature, and exploratory testing can then be used to investigate unusual payment behavior.

### 6. Conclusion

Exploratory Testing focuses on discovering defects through active exploration, whereas Risk-Based Testing focuses on prioritizing tests according to risk. Both approaches help improve software quality.

**Memory trick: Exploratory = EXPLORE; Risk-Based = PRIORITIZE.**

Remember comparison headings: **Objective -- Approach -- Focus -- Application.**

---

## 7. Regression Testing and Test Automation in Agile

**Q7. Analyze the role of Regression Testing and Test Automation in maintaining software quality during Agile iterations. (8M)**

### 1. Introduction

In Agile development, software is updated frequently through short iterations. A change made to one feature may affect another feature.
**Regression Testing** and **Test Automation** help ensure that new changes do not damage existing functionality.

### 2. Regression Testing

Regression Testing is the process of rerunning previously executed tests after software changes to check whether existing features still work correctly.

**Role of Regression Testing:**
- Detects defects introduced by new changes.
- Checks that previously working features remain functional.
- Helps maintain software stability.
- Supports frequent releases.
- Provides confidence when code is modified or refactored.

**Example:** After changing the shopping cart, test adding products, removing products and proceeding to checkout to make sure these existing functions still work.

### 3. Test Automation

Test Automation uses tools or scripts to execute tests automatically and compare actual results with expected results.

**Role of Test Automation:**
- Runs repeated tests quickly.
- Reduces manual effort for routine checks.
- Provides faster feedback to developers.
- Supports continuous integration.
- Makes it easier to run large regression test suites.
- Helps teams test frequently during short iterations.

Examples of automation tools include Selenium, JUnit, pytest and Cypress.

### 4. Relationship between Regression Testing and Automation
- Regression testing defines **what needs to be checked again** after a change.
- Test automation helps execute many of those checks **quickly and repeatedly**.
- Automated regression suites can run after code changes or during a build.
- Failed tests alert the team to possible defects.

### 5. Example: E-commerce application

A developer changes the payment feature.
- Automated regression tests check login, product selection, cart and checkout.
- If the cart or checkout test fails, the team investigates the problem.
- After fixing the defect, the tests are run again before release.

### 6. Advantages
- Maintains existing functionality.
- Detects defects introduced by changes.
- Reduces repeated manual testing.
- Provides faster feedback.
- Supports continuous integration and frequent releases.
- Improves confidence in software quality.

### 7. Limitations / care needed
- Automated tests need maintenance when the application changes.
- Not every test is suitable for automation.
- Poorly designed tests may produce unreliable results.
- Human exploratory testing is still valuable.

### 8. Conclusion

Regression Testing checks whether existing features still work after changes. Test Automation makes repeated testing faster and more consistent. Together, they help Agile teams maintain quality during frequent iterations.

**Memory trick: C--D--F--S = "Changes, Detect, Fast, Stable."**
- Changes can affect old features.
- Detect defects with regression tests.
- Fast execution through automation.
- Stable software through repeated checks.

---

## 8. TDD-Based Testing Strategy for Healthcare Application

**Q8. Design a TDD-based testing strategy for a healthcare application covering user stories, acceptance tests, regression testing, automation, and testing tools. (8M)**

### 1. Introduction

A healthcare application may manage patient registration, appointments, medical records and prescriptions. A TDD-based strategy helps developers write tests before implementation and continuously verify that important features work correctly.

Because healthcare software handles sensitive information, security, privacy and correctness must receive special attention.

### 2. Step 1: Identify user stories

Collect requirements from doctors, nurses, patients and administrators.

Examples:
- "As a patient, I want to book an appointment so that I can consult a doctor."
- "As a doctor, I want to view a patient's medical history so that I can make informed decisions."
- "As a nurse, I want to update patient details so that records remain current."

### 3. Step 2: Define acceptance criteria and tests

Write clear conditions for each user story.

Example: Appointment booking:
- Patient can select an available doctor.
- Patient can select an available time slot.
- Booking confirmation is displayed.
- The same time slot cannot be booked twice.

Prepare acceptance tests for valid booking, unavailable slots, missing information and invalid inputs.

### 4. Step 3: Apply the TDD cycle

For each small behavior:

**Red**
- Write a test first.
- Run it and confirm that it fails.

**Green**
- Write the minimum code needed to pass the test.
- Run the test again.

**Refactor**
- Improve the code without changing its behavior.
- Rerun tests to confirm that they still pass.

Repeat the cycle for the required features.

### 5. Step 4: Perform acceptance testing
- Test complete user workflows.
- Check whether acceptance criteria are satisfied.
- Involve suitable healthcare stakeholders in reviewing features.
- Record defects and retest after fixes.

### 6. Step 5: Perform regression testing
- Rerun existing tests after every important change.
- Check that appointment booking, patient records and login still work.
- Include regression tests for important security and access-control behavior.

### 7. Step 6: Use test automation
- Automate repeatable unit and integration tests.
- Run automated tests during continuous integration.
- Execute suitable end-to-end tests for important workflows.
- Keep tests updated when requirements change.

### 8. Step 7: Select testing tools

Examples:
- **JUnit:** Unit testing for Java.
- **pytest:** Testing for Python.
- **Selenium:** Browser-based application testing.
- **Cypress:** Web application testing.
- **Jenkins:** Can automate build and test pipelines.

Choose tools according to the application's programming language and technology.

### 9. Step 8: Protect healthcare data and quality
- Apply role-based access controls.
- Protect sensitive patient information.
- Test authorization and access restrictions.
- Maintain appropriate audit logs.
- Validate important data carefully.
- Follow applicable healthcare and data-protection requirements.

### 10. Conclusion

A TDD-based healthcare testing strategy combines user stories, acceptance criteria, Red--Green--Refactor, acceptance testing, regression testing, automation and suitable tools. Continuous testing and careful protection of patient data help maintain reliable and secure software.

**Memory trick: U--A--T--A--R--A--T--S = "User stories, Acceptance, TDD, Acceptance tests, Regression, Automation, Tools, Security."**

------------------------------------------------------------------------

## Quick Revision — Unit 4

### Eight questions in one line

| Q.No. | Main Topic | Memory Trick |
|:---:|---|---|
| **1** | Agile lifecycle and testing | R–P–D–D–T–F–R |
| **2** | TDD cycle | R–G–R |
| **3** | xUnit and TDD tools | W–R–A–O–I |
| **4** | User stories and acceptance testing | U–C–S–D–E–R–A |
| **5** | Agile testing cycle | R–P–D–E–F–R–R |
| **6** | Exploratory vs Risk-Based Testing | Explore vs Prioritize |
| **7** | Regression Testing and Automation | C–D–F–S |
| **8** | Healthcare TDD strategy | U–A–T–A–R–A–T–S |

### Important diagrams / tables to practise

1.  Agile lifecycle with testing at every stage.
2.  TDD Red → Green → Refactor cycle.
3.  User story with acceptance criteria and scenarios.
4.  Agile testing cycle from requirement analysis to review.
5.  Exploratory Testing vs Risk-Based Testing comparison table.
6.  Regression Testing and Test Automation relationship.
7.  Healthcare TDD testing strategy steps.

### Exam-writing strategy for 8 marks
- Start with a definition and short introduction.
- For lifecycle or process questions, explain the stages in order.
- Draw the Red--Green--Refactor diagram for TDD.
- For comparison questions, use a table.
- Include a practical example and test scenarios where asked.
- Explain how testing supports quality, not just the names of tools.
- End with a short conclusion.

**Revision tip:** Learn Q2 first because the TDD cycle is short and important. Then study Q3, Q4 and Q8, which use TDD, tools, user stories and acceptance tests. Finish with Q1, Q5, Q6 and Q7.

---
