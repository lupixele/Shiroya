# Unit 3 — Answers

> **Questions File:** [`questions.md` — Unit 3](questions.md#unit-3)

---

## 1. Describe the SCRUM framework and identify its major components

### Definition & Overview
**Scrum** is a lightweight **Agile framework** used to build complex products step by step. Work is done in short, fixed-length cycles called **Sprints** (usually 1 to 4 weeks). At the end of every Sprint the team delivers a **working, usable increment** of the product.

### Main Characteristics
- **Iterative and incremental:** the product grows a little in every Sprint.
- **Time-boxed:** every Sprint and every meeting has a fixed time limit.
- **Self-organising team:** the team decides *how* to do the work, nobody dictates it.
- **Empirical:** decisions are based on what is observed (transparency, inspection, adaptation).

### Major Components of Scrum

#### Roles
1. **Product Owner (PO):** represents the customer. Owns and orders the **Product Backlog**, decides what is built first, and accepts or rejects the work.
2. **Scrum Master (SM):** a servant-leader. Explains Scrum to everyone, protects the team from disturbance and **removes obstacles**. Does not act as a boss.
3. **Development Team:** 3 to 9 members. Cross-functional (developers, testers, designers). They turn backlog items into a working product.

#### Artifacts
1. **Product Backlog:** ordered list of everything the product may need (features, fixes, ideas).
2. **Sprint Backlog:** items selected for the current Sprint plus the plan to finish them.
3. **Increment:** the sum of all finished items; must be in a usable condition.

#### Events (Ceremonies)
1. **Sprint Planning:** team decides what to build in the Sprint and how.
2. **Daily Scrum:** 15-minute daily meeting. What did I do yesterday? What will I do today? Any blocks?
3. **Sprint Review:** team shows the increment to stakeholders and collects feedback.
4. **Sprint Retrospective:** team discusses what went well, what did not, and how to improve the next Sprint.

### Scrum Workflow Flowchart
```
Product Backlog → Sprint Planning → Sprint Backlog → SPRINT (1-4 wks)
       ↑                                                   │
       │                                         Daily Scrum (every day)
       │                                                   ↓
  Retrospective ← Sprint Review ←────────────── Working Increment
```

### Conclusion
Scrum gives a clear structure of roles, artifacts and events that helps teams deliver value quickly and adapt to change.

---

## 2. Illustrate the lifecycle of Extreme Programming

### Definition & Philosophy
**Extreme Programming (XP)** is an Agile method created by **Kent Beck**. It focuses on **good engineering practices**, very short iterations, constant customer feedback and high-quality code. The word "extreme" means that good practices (like testing and reviewing) are taken to the extreme level.

### Lifecycle Phases
1. **Exploration phase**
   - The customer writes the **user stories** (features they want) on cards.
   - The team learns the tools, technology and practices to be used.
   - Duration: a few weeks.
2. **Planning phase**
   - The team **estimates** the effort for each story.
   - The customer sets **priorities**.
   - Using the **Planning Game**, both agree on the contents of the first small release (usually 2 to 3 months or less).
3. **Iterations to Release phase**
   - The release is divided into many **iterations of 1 to 3 weeks**.
   - In each iteration the team builds the chosen stories using **pair programming, TDD, refactoring and continuous integration**.
   - At the end, the customer runs **acceptance tests** and gives feedback.
4. **Productionizing phase**
   - Extra testing, performance tuning and checking before the software goes live.
   - New ideas are noted but kept for later.
5. **Maintenance phase**
   - The software is in use, and the team keeps adding features, fixing bugs and giving support.
   - New iterations may continue in parallel.
6. **Death phase**
   - The customer has no more stories left, or the system is retired.
   - Final documentation is written.

### Lifecycle Flowchart
```
Exploration → Planning → Iterations to Release → Productionizing → Maintenance → Death
                               ↑_____ customer feedback ____|
                           (each iteration = 1 to 3 weeks)
```

### Core XP Values
The 5 values that guide the lifecycle are **Communication, Simplicity, Feedback, Courage, and Respect**.

### Conclusion
XP's lifecycle is short, test-driven and customer-centred, so it suits projects where requirements change often.

---

## 3. Summarize the lifecycle phases of Adaptive Software Development

### Definition & Overview
**Adaptive Software Development (ASD)** was proposed by **Jim Highsmith**. It is made for **complex projects with high change and uncertainty**. The traditional "plan → build" idea is replaced by a learning cycle: **Speculate → Collaborate → Learn**.

### Phase 1: Speculate (Planning)
- "Plan" is replaced by "speculate" because the results cannot be fully known in advance.
- The team defines the **project mission**, sets the schedule and breaks work into **time-boxed cycles**.
- Plans are loose and **expected to change** as the team learns.

### Phase 2: Collaborate (Engineering)
- Developers, customers, testers and managers work **together** on the product.
- Teamwork, trust and communication are the key.
- Features are built in **short, iterative cycles**. Concurrent (parallel) work is encouraged.

### Phase 3: Learn (Review)
- At the end of each cycle the team **checks quality and learns** what went right or wrong. Review has three parts:
  - **Customer focus group review:** customers see and comment on the working product.
  - **Technical review:** code and design are checked for quality.
  - **Post-mortem (project review):** team discusses what to improve in the next cycle.
- What is learnt is fed back into the next speculate phase.

### ASD Learning Cycle Flowchart
```
   ┌──────────── (next cycle) ────────────┐
   ↓                                      │
SPECULATE  →  COLLABORATE  →  LEARN ──────┘
(plan loosely) (build together) (review & improve)
```

### Key Characteristics
- **Mission-driven** and **feature-based**.
- **Iterative** and **time-boxed**.
- **Risk-driven** (risky parts are tackled early).
- **Change-tolerant:** change is seen as a chance to learn.

### Conclusion
ASD gives a flexible, learning-based way of developing software where each cycle improves the next.

---

## 4. Differentiate between traditional requirements elicitation and Agile requirements elicitation

### Overview
**Requirements elicitation** means collecting and understanding what the customer needs from the software. Traditional methods (like Waterfall) and Agile methods do this very differently.

### Comparison Table

| Basis | Traditional Elicitation | Agile Elicitation |
|---|---|---|
| **Timing** | Done completely **at the start** before design begins | **Continuous**, throughout the project |
| **Requirement format** | Long, detailed **SRS document** | Short **user stories** and Product Backlog |
| **Customer involvement** | Mainly at the **start and end** | **Daily** collaboration, on-site customer |
| **Handling change** | Changes are **resisted**; need a formal change request | Changes are **welcomed** at any stage |
| **Communication** | Written documents, formal meetings and sign-off | **Face-to-face** talks, frequent discussion |
| **Techniques used** | Interviews, questionnaires, surveys, document study | Workshops, story writing, prototypes, demos |
| **Delivery** | One big release at the end | Small **frequent increments** |
| **Feedback** | Late (after the product is built) | Early and regular (every iteration) |
| **Risk** | High: wrong requirements found late | Low: wrong requirements found early |

### Core Differences Explained
- In the **traditional** approach, all requirements are frozen first. If the customer's need changes later, the cost of change is very high.
- In the **Agile** approach, only a rough idea is needed at the start. Details are discussed just before each iteration, so the product stays close to what the customer really wants.

### Conclusion
Traditional elicitation is plan-driven and document-heavy, while Agile elicitation is people-driven, flexible and continuous.

---

## 5. Analyze the challenges involved in managing changing requirements in Agile projects

### Overview
Agile welcomes change, but handling constant change is not easy.

### Major Challenges
1. **Scope creep:** the customer keeps adding new features. Without control the project grows beyond the planned time and budget.
2. **Setting priorities:** many change requests arrive together. It is hard to decide what is most valuable and what should wait.
3. **Customer availability:** Agile needs an active customer for feedback. If the customer is busy or unclear, wrong decisions are made.
4. **Less documentation:** Agile keeps documents light. Later it becomes difficult to track **why** a change was made or what the old requirement was.
5. **Rework and technical debt:** frequent change can break existing code. If the design is poor and not refactored, each change becomes costly.
6. **Fixed contracts and budgets:** fixed-price, fixed-scope contracts do not fit well with changing requirements.
7. **Estimation and planning difficulty:** when requirements move, estimates, release dates and velocity become unreliable.
8. **Team stress and focus:** changes in the middle of a Sprint disturb the team and reduce productivity.
9. **Large and distributed teams:** communicating each change to everyone is harder when the team is big or spread across locations.

### Agile Mitigation Strategies
- Keep one **prioritised Product Backlog** managed by the Product Owner.
- Accept changes only **between Sprints** (in Scrum).
- Use **refactoring, automated tests and CI** to make change safe.
- Hold regular **reviews** with the customer.

### Conclusion
Agile makes change possible, but it needs strong discipline, good communication and technical practices to manage it well.

---

## 6. Compare the roles and practices of SCRUM and Extreme Programming

### Overview
Both **Scrum** and **XP** are Agile methods. They are iterative, customer-focused and welcome change, but they differ in focus and detail.

### Roles and Practices Comparison Table

| Basis | SCRUM | Extreme Programming (XP) |
|---|---|---|
| **Main focus** | **Project management** and team organisation | **Engineering / coding practices** |
| **Iteration name & length** | **Sprint**, 1 to 4 weeks, fixed | **Iteration**, usually 1 to 2 weeks |
| **Roles** | Product Owner, Scrum Master, Development Team | Customer, Programmer, Coach, Tester, Tracker, Manager |
| **Change during iteration** | **Not allowed** once the Sprint starts | **Allowed** if the team agrees and priorities change |
| **Requirements** | **Product Backlog** items | **User stories** on cards |
| **Meetings / events** | Sprint Planning, Daily Scrum, Review, Retrospective | Planning Game, Daily stand-up |
| **Technical practices** | Not prescribed | **Pair programming, TDD, refactoring, CI, simple design** |
| **Prioritisation** | By the Product Owner | By the customer |
| **Team style** | Self-organising team | Team works closely, collective code ownership |
| **Testing** | Left to the team | Strongly built-in (test-first) |

### Key Similarities
- Both are **iterative and incremental**.
- Both deliver **working software** frequently.
- Both give high value to **customer collaboration** and **feedback**.
- Both support **self-organising teams** and welcome changing requirements.

### Combining Scrum and XP
Many teams combine them: **Scrum** to manage the project and **XP practices** to build the code.

### Conclusion
Scrum tells *how to manage* the work, while XP tells *how to write* the code.

---

## 7. How does Agile accommodate changing customer requirements?

### Core Philosophy
Agile is built on the belief that **change is normal and useful**. The Agile Manifesto says: *"Respond to change over following a plan."*

### 8 Key Agile Mechanisms
1. **Short iterations:** work is delivered in 1 to 4 week cycles, so a new requirement can be added in the **next iteration** without much delay.
2. **Flexible Product Backlog:** the backlog is a living list. Items can be **added, removed, changed or re-ordered** at any time by the Product Owner.
3. **Continuous customer involvement:** the customer is part of the team, gives daily feedback and corrects direction early.
4. **Working software in every iteration:** the customer **sees and tests** the product early, so wrong or changed needs are spotted quickly.
5. **Just-in-time requirements:** details are written only when a story is about to be built, so little effort is wasted if it changes.
6. **Regular reviews and retrospectives:** the Sprint Review improves the product and the Retrospective improves the process.
7. **Technical practices:** **refactoring, automated testing, continuous integration and simple design** keep the code easy to change.
8. **Self-organising teams:** the team can adjust its plan quickly without waiting for approval.

### Change Feedback Cycle Flowchart
```
Customer feedback → New / changed story → Backlog re-prioritised
        ↑                                          ↓
  Working increment ← Built in next iteration ←────┘
```

### Conclusion
By combining short cycles, constant feedback and strong technical practices, Agile turns changing requirements into a chance to deliver a better product.

---

## 8. List the major practices followed in Extreme Programming (XP)

### Overview
XP has about 12 core practices designed to improve code quality, customer satisfaction, and team communication.

### The 12 Core Practices

#### Planning Practices
1. **Planning Game:** customer decides scope and priority; programmers give estimates.
2. **Small Releases:** put a simple working system into use quickly and update often.
3. **On-site Customer:** a real customer sits with the team to answer questions.

#### Design Practices
4. **Simple Design:** build only what is needed now; no extra features.
5. **Metaphor:** a shared story or naming idea that explains how the system works.
6. **Refactoring:** keep improving the code structure without changing behaviour.

#### Coding Practices
7. **Pair Programming:** two programmers work at one computer; one types, one reviews.
8. **Collective Code Ownership:** any member can improve any part of the code.
9. **Coding Standards:** the whole team follows the same style and naming.

#### Testing & Integration Practices
10. **Test-Driven Development (TDD):** write the test first, then the code.
11. **Continuous Integration:** merge and build the code many times a day.

#### Team Practice
12. **Sustainable Pace (40-hour week):** avoid overtime so the team stays fresh and produces good quality.

### Benefits & Takeaways
Better quality, fewer bugs, quick feedback, shared knowledge and the ability to handle change.

---

## Last-minute revision: Unit 3
- **Scrum:** 3 roles (PO, SM, Team), 3 artifacts (Product Backlog, Sprint Backlog, Increment), 4 events (Planning, Daily Scrum, Review, Retrospective).
- **XP lifecycle:** Exploration → Planning → Iterations to Release → Productionizing → Maintenance → Death.
- **ASD:** Speculate → Collaborate → Learn (change is expected, review in 3 ways).
- **Agile elicitation** is continuous, uses user stories, face-to-face talks and welcomes change.
- **Scrum = management framework; XP = engineering practices;** many teams use both together.
