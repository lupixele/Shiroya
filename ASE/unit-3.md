# Unit 3: Agile Process Models & Requirements Engineering — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 3](questions.md#unit-iii--agile-process-models--requirements-engineering)

---

## 1. Scrum Framework: Lifecycle, Roles, Artifacts, Practices

**Q1. Explain the Scrum framework with reference to its lifecycle, roles, work products, and practices. (8M)**

### 1. Introduction

**Scrum** is an Agile framework used to develop and deliver software in
small, manageable increments. Work is organized into fixed-length
iterations called **Sprints**. Scrum encourages teamwork, transparency,
inspection and adaptation.

### 2. Scrum lifecycle

**1. Product Backlog creation** - The Product Owner collects and lists
the features, requirements and improvements needed in the product. -
This ordered list is called the Product Backlog.

**2. Sprint Planning** - The Scrum Team selects items from the Product
Backlog for the upcoming Sprint. - A Sprint Goal is defined. - The team
plans how the selected work can be completed.

**3. Sprint execution** - The Developers work on the selected items. -
They design, code and test the features. - The work is organized to
achieve the Sprint Goal.

**4. Daily Scrum** - Developers meet briefly every day to inspect
progress. - They coordinate their work and identify obstacles. - The
Sprint plan is adjusted when needed.

**5. Sprint Review** - The team presents the completed work to
stakeholders. - Feedback is collected and the Product Backlog may be
updated.

**6. Sprint Retrospective** - The team reviews how the Sprint went. - It
identifies improvements for the next Sprint.

**7. Next Sprint** - The cycle repeats until the product goal is
achieved.

### 3. Scrum roles

**1. Product Owner** - Responsible for maximizing product value. -
Manages and orders the Product Backlog. - Communicates product needs and
priorities.

**2. Scrum Master** - Helps everyone understand and follow Scrum. -
Supports the team and helps remove impediments. - Encourages effective
Scrum practices.

**3. Developers** - Create a usable product Increment during each
Sprint. - Plan and perform the work needed to meet the Sprint Goal. -
Maintain quality and adapt their plan daily.

### 4. Scrum work products (artifacts)

**1. Product Backlog** - An ordered list of work needed to improve the
product. - It contains features, fixes and other product requirements.

**2. Sprint Backlog** - Contains the Sprint Goal, selected Product
Backlog items and the plan for delivering them. - It is the Developers'
plan for the Sprint.

**3. Increment** - The usable, completed product work produced during a
Sprint. - It must meet the agreed quality criteria, commonly expressed
through the Definition of Done.

### 5. Scrum practices / events

-   **Sprint:** A fixed-length period in which work is completed.
-   **Sprint Planning:** Decides what and how much work to do.
-   **Daily Scrum:** Checks progress and coordinates work.
-   **Sprint Review:** Inspects the result and gathers feedback.
-   **Sprint Retrospective:** Identifies ways to improve.

### 6. Example

For a library application: - Product Backlog: login, book search, issue
and return, fine calculation. - Sprint 1: develop login. - Sprint 2:
develop book search. - Sprint 3: develop issue and return. - At each
Sprint Review, librarians provide feedback.

### 7. Conclusion

Scrum provides a structured but flexible way to develop software through
Sprints. Its roles, work products and events help teams collaborate,
inspect progress and continuously improve.

**Memory trick: L--R--A--P = "Lifecycle, Roles, Artifacts,
Practices."** - Lifecycle: Backlog → Planning → Sprint → Daily Scrum →
Review → Retrospective. - Roles: **P--S--D** = Product Owner, Scrum
Master, Developers. - Artifacts: **P--S--I** = Product Backlog, Sprint
Backlog, Increment.

---

## 2. Extreme Programming (XP): Lifecycle, Roles, Artifacts, Practices

**Q2. Demonstrate the lifecycle, roles, work products, and practices of Extreme Programming (XP). (8M)**

### 1. Introduction

**Extreme Programming (XP)** is an Agile software development method
that focuses on high-quality software, frequent releases, close customer
involvement and strong engineering practices. It is especially useful
when requirements change frequently.

### 2. XP lifecycle

**1. Planning** - Customers describe requirements as user stories. -
Developers estimate the effort needed. - The customer prioritizes the
stories for a release or iteration.

**2. Design** - Developers create a simple design for the required
features. - They avoid unnecessary complexity. - Design is improved as
the system evolves.

**3. Coding** - Developers write code using agreed coding standards. -
Pair programming may be used. - Code is integrated frequently.

**4. Testing** - Developers write and run unit tests. - Acceptance tests
check whether the features meet customer needs. - Defects are corrected
quickly.

**5. Release** - A small, working version is delivered to the
customer. - Feedback is collected for the next iteration.

The cycle repeats with updated user stories and priorities.

### 3. XP roles

Typical responsibilities in an XP team include:

-   **Customer:** Defines and prioritizes user stories and clarifies
    requirements.
-   **Programmers / Developers:** Design, code, test and integrate the
    software.
-   **Tester:** Helps create and run acceptance tests and provides
    quality feedback.
-   **Coach:** Guides the team in applying XP practices.
-   **Tracker:** Helps monitor progress and estimates.
-   **Manager:** Supports the team and provides resources.

*Role names and arrangements can vary between XP teams.*

### 4. XP work products

-   **User stories:** Short descriptions of features from the user's
    point of view.
-   **Release plan:** A plan showing which stories are expected in a
    release.
-   **Iteration plan:** Stories and tasks selected for a particular
    iteration.
-   **Source code:** The implemented software.
-   **Test cases:** Unit and acceptance tests used to check behavior.
-   **Working release:** The usable software delivered to the customer.

### 5. Important XP practices

**1. Pair programming:** Two developers work together at one
workstation; one writes code while the other reviews and thinks ahead.

**2. Test-Driven Development (TDD):** Write a test first, write code to
pass it, and then improve the code.

**3. Continuous Integration:** Integrate and test code frequently.

**4. Refactoring:** Improve the internal structure of code without
changing its external behavior.

**5. Small releases:** Deliver working software frequently.

**6. Simple design:** Use the simplest design that meets current
requirements.

**7. Collective code ownership:** Team members can improve any part of
the code.

**8. Coding standards:** Follow common coding rules to keep code
consistent.

### 6. Example

For an online shopping system: - Customer writes a story: "As a
customer, I want to add a product to my cart." - Developers estimate and
select it. - A test is written first. - Developers implement the cart
feature, integrate the code and run tests. - The feature is released and
customer feedback is collected.

### 7. Conclusion

XP combines short development cycles with disciplined engineering
practices. Its focus on testing, pair programming, continuous
integration and small releases helps produce high-quality software that
can adapt to changing requirements.

**Memory trick: P--D--C--T--R = "Plan, Design, Code, Test, Release."**

For practices remember **P--T--C--R--S**: - Pair programming -
Test-Driven Development - Continuous Integration - Refactoring - Small
releases

---

## 3. Crystal vs. Feature Driven Development (FDD)

**Q3. Differentiate Crystal and Feature Driven Development (FDD) based on their major characteristics and development practices. (8M)**

### 1. Introduction

Crystal and Feature Driven Development (FDD) are Agile software
development methods. Both support iterative development, but they focus
on different aspects.

-   **Crystal** emphasizes people, communication and adapting the
    process to the project.
-   **FDD** emphasizes planning, designing and building software feature
    by feature.

### 2. Crystal methodology

-   Crystal is a family of methods suited to different team sizes and
    project criticality.
-   It emphasizes people, communication and interaction.
-   It encourages frequent delivery of working software.
-   It supports reflection and continuous improvement.
-   Its process can be adjusted according to project needs.

### 3. Feature Driven Development (FDD)

FDD is an Agile method in which development is organized around small,
client-valued features.

Major FDD activities are:

**1. Develop an overall model** - Understand the project domain. -
Create a high-level model of the system.

**2. Build a feature list** - Divide the system into small features. -
Features should provide value to the customer.

**3. Plan by feature** - Prioritize and assign responsibility for
features. - Prepare a development plan.

**4. Design by feature** - Design the selected feature in detail. -
Review the design before implementation.

**5. Build by feature** - Code, test and complete the feature. -
Integrate it into the system.

### 4. Comparison

  -----------------------------------------------------------------------
  Basis                   Crystal                 FDD
  ----------------------- ----------------------- -----------------------
  Main focus              People and              Customer-valued
                          communication           features

  Approach                Adapts process to team  Organizes work around
                          and project needs       defined features

  Planning                Flexible and            Feature-based planning
                          context-dependent       

  Development             Frequent delivery and   Design and build by
                          reflection              feature

  Team                    Emphasizes              Uses defined feature
                          communication and       responsibilities and
                          teamwork                domain expertise

  Documentation / work    Keeps useful            Uses domain model,
  products                information appropriate feature list and
                          to the project          feature plans

  Best suited for         Different project       Projects that can be
                          sizes, depending on the divided into clear
                          Crystal method          features
  -----------------------------------------------------------------------

### 5. Example

For a college management system: - **Crystal:** The team chooses
communication practices and process details according to its size and
project needs. - **FDD:** The team creates features such as student
registration, attendance entry, marks entry and report generation, then
plans and builds each feature.

### 6. Conclusion

Crystal focuses on people, communication and adapting the process,
whereas FDD focuses on developing software through small,
customer-valued features. The choice depends on project needs and the
way work can be organized.

**Memory trick: Crystal = PEOPLE; FDD = FEATURES.**

For FDD's five activities remember **M--L--P--D--B = "Model, List, Plan,
Design, Build."**

---

## 4. Adaptive Software Development (ASD): Lifecycle and Principles

**Q4. Illustrate the lifecycle and major principles of Adaptive Software Development (ASD). (8M)**

### 1. Introduction

**Adaptive Software Development (ASD)** is an Agile approach designed
for projects with uncertainty and frequently changing requirements. It
emphasizes continuous learning, collaboration and adaptation instead of
depending on a fixed plan.

### 2. ASD lifecycle

ASD has three main phases:

**1. Speculate** - Set the project mission and objectives. - Identify
requirements and possible risks. - Prepare a flexible plan for the next
development cycle. - The plan is treated as something that can change as
the team learns.

**2. Collaborate** - Team members work together to develop the
product. - Developers, customers and other stakeholders share
information. - The team communicates, solves problems and makes
decisions collectively. - Working software is developed through
collaboration.

**3. Learn** - Review the completed work. - Collect customer and team
feedback. - Test the product and identify mistakes. - Apply lessons
learned to the next cycle.

The three phases repeat until the required product is developed.

### 3. Major principles of ASD

**1. Mission-driven** - Development is guided by a clear project
mission. - The mission gives direction even when details change.

**2. Feature-based** - Work is organized around useful product
features. - Features provide visible value to users.

**3. Iterative development** - Software is developed in repeated
cycles. - Each cycle produces progress and learning.

**4. Time-boxed cycles** - Work is planned within a fixed time period. -
Time limits encourage focus and regular delivery.

**5. Risk-driven** - Important uncertainties and risks receive
attention. - The team adapts plans according to risks.

**6. Change-tolerant** - Changes are accepted as part of development. -
Plans are adjusted when new information appears.

**7. Continuous learning** - The team learns from testing, feedback and
experience. - Lessons are applied to later cycles.

### 4. Example

For a new mobile banking application: - **Speculate:** Identify the
mission and plan login and account-view features. - **Collaborate:**
Developers, testers and banking representatives work together. -
**Learn:** Users review the features; the team identifies improvements
and plans the next cycle for transactions.

### 5. Advantages

-   Handles uncertain and changing requirements.
-   Encourages teamwork and customer involvement.
-   Supports continuous feedback and learning.
-   Helps identify risks during development.
-   Promotes regular progress.

### 6. Limitations

-   Requires active collaboration.
-   Exact cost and schedule may be difficult to predict.
-   Teams need experience in adapting plans.
-   It may be difficult where strict fixed requirements are mandatory.

### 7. Conclusion

ASD uses the repeating cycle of Speculate, Collaborate and Learn. It is
useful for complex projects where requirements and conditions may change
during development.

**Memory trick: S--C--L = "Speculate, Collaborate, Learn."**

Remember the meaning: - Speculate = **Plan flexibly** - Collaborate =
**Work together** - Learn = **Review and improve**

---

## 5. Comparison of Scrum, Crystal, FDD, ASD, and XP

**Q5. Compare Scrum, Crystal, FDD, ASD, and XP with respect to lifecycle, roles, work products, and practices. (8M)**

### 1. Introduction

Scrum, Crystal, Feature Driven Development (FDD), Adaptive Software
Development (ASD) and Extreme Programming (XP) are Agile methods. They
share iterative development and collaboration, but differ in their
lifecycle, responsibilities, work products and practices.

### 2. Comparison

  --------------------------------------------------------------------------------------
  Method         Lifecycle       Roles / people     Main work products  Key practices
                                 focus                                  
  -------------- --------------- ------------------ ------------------- ----------------
  Scrum          Repeated        Product Owner,     Product Backlog,    Sprint Planning,
                 Sprints         Scrum Master,      Sprint Backlog,     Daily Scrum,
                                 Developers         Increment           Review,
                                                                        Retrospective

  Crystal        Adapted to      Emphasizes team    Useful project      Frequent
                 project context communication and  information and     delivery,
                 with frequent   interaction        working software    communication,
                 delivery                                               reflection

  FDD            Five            Domain experts,    Overall model,      Model, list,
                 feature-based   developers and     feature list,       plan, design and
                 activities      feature            feature plan and    build by feature
                                 responsibilities   completed features  

  ASD            Speculate,      Collaborative team Iteration plans and Adaptation,
                 Collaborate,    and stakeholders   working product     time-boxing,
                 Learn                              increments          risk focus and
                                                                        learning

  XP             Planning,       Customer and       User stories,       Pair
                 design, coding, development team,  release/iteration   programming,
                 testing and     with supporting    plans, code and     TDD,
                 release cycles  roles such as      tests               refactoring, CI
                                 coach and tester                       and small
                                                                        releases
  --------------------------------------------------------------------------------------

### 3. Explanation of each method

**Scrum** - Uses fixed-length Sprints. - Defines clear
accountabilities. - Tracks work through backlogs. - Uses regular Scrum
events to inspect and adapt.

**Crystal** - Adapts its process to the project and team. - Focuses on
communication and people. - Encourages frequent delivery and reflection.

**FDD** - Organizes work around small features. - Uses a domain model
and feature list. - Designs and builds features in a planned sequence.

**ASD** - Uses Speculate, Collaborate and Learn. - Accepts uncertainty
and changing requirements. - Encourages learning and adaptation.

**XP** - Focuses on technical excellence. - Uses TDD, pair programming
and continuous integration. - Delivers small releases frequently.

### 4. Example

For an online shopping system: - Scrum can organize work into Sprints. -
Crystal can adapt team communication to the project. - FDD can plan
features such as search, cart and payment. - ASD can adapt the plan
based on user learning. - XP can use automated tests and pair
programming while building features.

### 5. Conclusion

Each Agile method provides a different way to organize development.
Scrum emphasizes Sprint management, Crystal emphasizes people, FDD
emphasizes features, ASD emphasizes adaptation and XP emphasizes
engineering practices. The method should be selected according to
project requirements and team needs.

**Memory trick: S--C--F--A--X** - Scrum = **Sprints** - Crystal =
**Communication** - FDD = **Features** - ASD = **Adaptation** - XP =
**eXtreme engineering practices**

For the comparison headings remember **L--R--W--P = Lifecycle, Roles,
Work products, Practices.**

---

## 6. Impact of Agile on Requirements Engineering and Practices

**Q6. Analyze the impact of Agile processes on Requirements Engineering and identify important Agile RE practices. (8M)**

### 1. Introduction

**Requirements Engineering (RE)** is the process of identifying,
analyzing, documenting, validating and managing the requirements of a
software system.

In traditional development, requirements may be defined in detail at the
beginning. In Agile development, requirements are handled continuously
and can be updated as customer needs change.

### 2. Impact of Agile processes on Requirements Engineering

**1. Changing requirements are accepted** - Agile accepts that
requirements may change during development. - New needs can be added to
the backlog and prioritized.

**2. Continuous customer involvement** - Customers and stakeholders
communicate with the team regularly. - Their feedback helps clarify
requirements.

**3. Incremental requirements development** - Requirements are developed
and refined in small parts. - The team focuses on the features needed
for upcoming iterations.

**4. Less emphasis on large upfront specifications** - Agile avoids
trying to finalize every detail before development. - It documents
enough information to support current work.

**5. Continuous validation** - Working software is reviewed by
customers. - Feedback helps confirm whether the requirements are
understood correctly.

**6. Better prioritization** - High-value and important requirements are
developed first. - Lower-priority requirements can be scheduled later.

### 3. Important Agile Requirements Engineering practices

**1. User Stories** - Requirements are written from the user's point of
view. - Example: "As a student, I want to view my attendance so that I
can track my attendance percentage."

**2. Product Backlog** - A prioritized list of features, requirements,
improvements and fixes. - It is updated as needs change.

**3. Customer Collaboration** - Customers explain their needs and
provide feedback. - Developers clarify unclear requirements directly.

**4. Requirements Prioritization** - Requirements are ordered according
to business value, urgency, risk and dependencies.

**5. Acceptance Criteria** - Conditions that a feature must satisfy to
be accepted. - They help developers and testers understand what success
means.

**6. Backlog Refinement** - The team reviews, clarifies, estimates and
divides backlog items into manageable work.

**7. Prototyping** - A simple model or sample interface is created to
clarify uncertain requirements. - Users provide feedback before full
development.

### 4. Example

For a college attendance application: - A student story is created to
view attendance. - Acceptance criteria define the information to
display. - The story is prioritized in the Product Backlog. - Developers
implement it in a Sprint. - Faculty and students review the feature and
suggest changes.

### 5. Advantages

-   Requirements remain closer to customer needs.
-   Changes can be handled more easily.
-   Misunderstandings can be identified earlier.
-   Important features receive priority.
-   Regular feedback improves the product.

### 6. Conclusion

Agile changes Requirements Engineering from a mostly upfront activity
into a continuous process. User stories, backlogs, prioritization,
acceptance criteria and customer collaboration help teams manage
changing requirements.

**Memory trick: C--I--V--P = "Customers Involve, Validate,
Prioritize."** - Impact: Changing needs, continuous involvement,
incremental refinement, validation and prioritization.

For practices remember **S--B--C--P--A--R--P**: - Stories - Backlog -
Collaboration - Prioritization - Acceptance criteria - Refinement -
Prototyping

---

## 7. Requirements Elicitation Techniques in Agile

**Q7. Demonstrate suitable Requirements Elicitation techniques for an Agile development environment. (8M)**

### 1. Introduction

**Requirements Elicitation** is the process of collecting information
about users' needs, expectations and problems. In Agile development,
elicitation is continuous because requirements can change as users
review working software and provide feedback.

### 2. Requirements Elicitation techniques

**1. Interviews** - Developers ask users and stakeholders questions. -
Interviews help understand needs, problems and expectations. - Example:
Interview faculty to understand attendance entry requirements.

**2. Workshops** - Users, developers and stakeholders meet to discuss
requirements. - Different viewpoints are collected and clarified. -
Example: Conduct a workshop with students, faculty and administrators to
plan a student portal.

**3. Observation** - Developers observe users performing their daily
tasks. - This helps identify actual workflows and hidden problems. -
Example: Observe how a librarian issues and returns books.

**4. Questionnaires / Surveys** - Questions are distributed to many
users. - Responses help identify common needs and preferences. -
Example: Ask students which features they need in a college application.

**5. Brainstorming** - Team members and stakeholders suggest ideas. -
Ideas are discussed and grouped. - This is useful for discovering
possible features and solutions.

**6. Prototyping** - A sample screen or simple working model is
created. - Users examine it and give feedback. - Example: Create a
sample attendance dashboard before developing the full application.

**7. User Stories** - Requirements are written as short descriptions
from the user's perspective. - Example: "As a student, I want to
download my marksheet so that I can keep a record of my results."

### 3. Applying elicitation in Agile

1.  Identify the stakeholders.
2.  Select suitable elicitation techniques.
3.  Collect and clarify requirements.
4.  Convert requirements into user stories.
5.  Define acceptance criteria.
6.  Prioritize the stories in the Product Backlog.
7.  Review and update requirements using feedback during iterations.

### 4. Importance

-   Helps understand real user needs.
-   Reduces misunderstanding.
-   Encourages customer participation.
-   Identifies missing requirements.
-   Supports changing requirements.
-   Helps prioritize useful features.

### 5. Conclusion

Agile teams use interviews, workshops, observation, surveys,
brainstorming, prototyping and user stories to collect requirements.
Using several suitable techniques helps the team understand users and
build the right software.

**Memory trick: I--W--O--Q--B--P--U = "Interviews, Workshops, Observe,
Question, Brainstorm, Prototype, User stories."**

Short recall: **Ask → Discuss → Observe → Survey → Create → Show → Write
stories.**

---

## 8. Agile Requirements Engineering for Healthcare Project

**Q8. Develop an Agile Requirements Engineering approach for a healthcare software project with frequently changing requirements. (8M)**

### 1. Introduction

Healthcare software may manage patient registration, appointments,
medical records, prescriptions and reports. Requirements may change due
to user feedback, workflow needs, security concerns and policy changes.

An Agile Requirements Engineering approach helps the team manage these
changes while keeping patient safety, privacy and software quality
important.

### 2. Step 1: Identify stakeholders

Identify the people who will use or influence the system: - Doctors. -
Nurses. - Receptionists. - Patients. - Hospital administrators. - IT and
security teams.

Each stakeholder may have different requirements.

### 3. Step 2: Elicit requirements

Use suitable techniques: - Interviews with doctors and nurses. -
Workshops with administrators. - Observation of hospital workflows. -
Surveys for patients. - Prototypes of appointment and patient-record
screens.

### 4. Step 3: Write user stories

Convert requirements into user stories.

Examples: - "As a patient, I want to book an appointment so that I can
consult a doctor." - "As a doctor, I want to view a patient's medical
history so that I can make informed decisions." - "As a nurse, I want to
update vital signs so that patient records remain current."

### 5. Step 4: Define acceptance criteria

Write clear conditions for each story.

Example: Patient appointment booking: - The patient can select an
available doctor. - The patient can select an available time slot. - The
system confirms the booking. - The system prevents double booking.

For healthcare data, access should be controlled and actions should be
handled safely.

### 6. Step 5: Create and prioritize the Product Backlog

-   Add user stories, defects and improvements to the backlog.
-   Prioritize essential and safety-related features.
-   Consider business value, risk, urgency and dependencies.
-   Reorder items when new information becomes available.

### 7. Step 6: Plan and develop in iterations

Example iteration plan:

  Iteration   Features
  ----------- -----------------------------
  1           Secure login and user roles
  2           Patient registration
  3           Appointment booking
  4           Medical history and records
  5           Prescription and reports

At the start of each iteration, the team selects and clarifies the
highest-priority work.

### 8. Step 7: Continuous validation and feedback

-   Demonstrate working features to doctors and other stakeholders.
-   Collect feedback.
-   Check acceptance criteria.
-   Update user stories and backlog items.
-   Reassess risks when requirements change.

### 9. Step 8: Security, privacy and quality

-   Restrict access according to user roles.
-   Protect patient information.
-   Maintain appropriate audit records.
-   Test important workflows carefully.
-   Perform regression testing after changes.
-   Follow applicable healthcare and data-protection requirements.

### 10. Conclusion

An Agile Requirements Engineering approach for healthcare uses
stakeholder involvement, elicitation, user stories, acceptance criteria,
backlog prioritization and iterative validation. Frequent feedback helps
manage changing requirements, while careful attention to privacy,
security and patient safety protects the quality of the system.

**Memory trick: S--E--U--A--B--I--F--S = "Stakeholders Elicit User
needs, Accept, Backlog, Iterate, Feedback, Secure."** - Stakeholders -
Elicitation - User stories - Acceptance criteria - Backlog
prioritization - Iterations - Feedback - Security and safety

------------------------------------------------------------------------

# Quick Revision -- Unit 3

## Eight questions in one line

  Q.No.   Main topic                                 Memory trick
  ------- ------------------------------------------ ------------------------
  1       Scrum framework                            L--R--A--P
  2       Extreme Programming                        P--D--C--T--R
  3       Crystal vs FDD                             People vs Features
  4       Adaptive Software Development              S--C--L
  5       Compare Scrum, Crystal, FDD, ASD and XP    S--C--F--A--X
  6       Agile impact on Requirements Engineering   C--I--V--P
  7       Requirements Elicitation techniques        I--W--O--Q--B--P--U
  8       Healthcare Agile RE approach               S--E--U--A--B--I--F--S

## Important diagrams / tables to practise

1.  Scrum lifecycle: Product Backlog → Sprint Planning → Sprint → Daily
    Scrum → Review → Retrospective.
2.  Scrum roles: Product Owner, Scrum Master and Developers.
3.  XP lifecycle: Planning → Design → Coding → Testing → Release.
4.  FDD five activities: Model → Feature List → Plan → Design → Build.
5.  ASD cycle: Speculate → Collaborate → Learn.
6.  Comparison table of Scrum, Crystal, FDD, ASD and XP.
7.  Requirements Elicitation techniques.
8.  Healthcare project iteration table.

## Exam-writing strategy for 8 marks

-   Start with a definition and introduction.
-   Use headings that match the question: lifecycle, roles, work
    products and practices.
-   For comparison questions, use a table.
-   Add a practical example, preferably from a college, library,
    shopping or healthcare system.
-   For scenario questions, explain the steps in the order the team
    would perform them.
-   End with a short conclusion.
-   Use memory tricks to recall headings, then write the full
    explanation.

**Revision tip:** Study Q1 and Q2 first (Scrum and XP), then Q3--Q5
(other Agile methods and comparison), and finally Q6--Q8 (Requirements
Engineering).

---
