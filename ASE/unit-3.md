# Unit 3 — Answers

[⬅ Back to Questions](questions.md#unit-3)

---

### 1. Describe the SCRUM framework and identify its major components

**Scrum** is an Agile framework that builds a product in short, fixed-length cycles called **Sprints** (1-4 weeks). Each Sprint delivers a working increment.

- **Roles:**
  - **Product Owner** manages the Product Backlog and sets priorities.
  - **Scrum Master** coaches the team and removes obstacles.
  - **Development Team** is self-organising and builds the product.
- **Artifacts:** **Product Backlog** (all wanted features), **Sprint Backlog** (items chosen for the Sprint), **Increment** (working output).
- **Events:** **Sprint Planning**, **Daily Scrum** (15 min), **Sprint Review**, **Sprint Retrospective**.

```
Product Backlog → Sprint Planning → Sprint Backlog
      ↑                                  ↓
 Retrospective ← Review ← Increment ← Sprint (Daily Scrum)
```

[⬆ Back to top](#unit-3--answers)

---

### 2. Illustrate the lifecycle of Extreme Programming

**XP** is an Agile method focused on engineering practices, with very short iterations and constant customer feedback.

- **Exploration:** customer writes **user stories**; team tries out tools and technology.
- **Planning:** stories are estimated and prioritised; the **release plan** is made.
- **Iterations to Release:** each iteration of 1-3 weeks delivers working code with **tests**.
- **Productionizing:** extra testing and tuning before release.
- **Maintenance:** new features, bug fixes, support.
- **Death:** no more stories left, or system is retired.

```
Exploration → Planning → Iterations to Release → Productionizing → Maintenance → Death
                              ↑___ feedback loop ___|
```

[⬆ Back to top](#unit-3--answers)

---

### 3. Summarize the lifecycle phases of Adaptive Software Development

**ASD** (by Jim Highsmith) is built for complex, changing projects. It replaces "plan-build" with "speculate-collaborate-learn".

- **Speculate:** plan loosely, since the outcome is uncertain. Set the mission and cycles.
- **Collaborate:** developers, customers and stakeholders work together to build the product.
- **Learn:** review each cycle through **customer focus group reviews**, technical reviews and post-mortems. Use the lessons in the next cycle.

```
Speculate → Collaborate → Learn
    ↑______________________|
```

Key ideas: **change is expected**, and feedback drives each cycle.

[⬆ Back to top](#unit-3--answers)

---

### 4. Differentiate between traditional requirements elicitation and Agile requirements elicitation

| Basis | Traditional | Agile |
|---|---|---|
| **Timing** | Done fully at the start | Continuous, throughout the project |
| **Format** | Detailed SRS document | **User stories**, backlog |
| **Customer role** | Involved at start and end | On-site, daily collaboration |
| **Change** | Resisted, needs formal change control | Welcomed at any stage |
| **Communication** | Documents, formal sign-off | Face-to-face conversation |
| **Delivery** | One big release | Small, frequent increments |

[⬆ Back to top](#unit-3--answers)

---

### 5. Analyze the challenges involved in managing changing requirements in Agile projects

Change is welcome in Agile, but it still creates problems.

- **Scope creep:** constant additions can push the project past time and budget.
- **Unclear priorities:** many new requests make it hard to decide what comes first.
- **Customer availability:** frequent changes need an active customer, who may be busy.
- **Weak documentation:** less written detail makes it hard to track why changes were made.
- **Rework and technical debt:** poor design makes each change costly and risky.
- **Contract and cost issues:** fixed-price contracts do not fit evolving scope.

[⬆ Back to top](#unit-3--answers)

---

### 6. Compare the roles and practices of SCRUM and Extreme Programming

| Basis | SCRUM | XP |
|---|---|---|
| **Focus** | Project management | Engineering practices |
| **Roles** | Product Owner, Scrum Master, Team | Customer, Programmer, Coach, Tester, Tracker |
| **Iteration** | Sprint, 1-4 weeks, fixed | 1-2 weeks, may change |
| **Practices** | Daily Scrum, Review, Retrospective | **Pair programming, TDD**, refactoring, CI |
| **Change in sprint** | Not allowed once started | Allowed if priorities change |
| **Requirements** | Product Backlog | User stories |

Both are Agile, iterative and customer-focused, and are often used together.

[⬆ Back to top](#unit-3--answers)

---

### 7. How does Agile accommodate changing customer requirements?

Agile is designed to treat change as normal.

- **Short iterations:** a change is absorbed in the next cycle, within weeks.
- **Product Backlog:** items can be added, removed or reprioritised any time.
- **Customer collaboration:** continuous feedback shows what is needed.
- **Working software every iteration:** customers see results early and correct course.
- **Sprint Review and Retrospective:** adjust both product and process regularly.
- **Technical practices:** **refactoring, automated tests and CI** keep changes safe and cheap.

[⬆ Back to top](#unit-3--answers)

---

### 8. List the major practices followed in Extreme Programming (XP)

1. **Planning Game:** customer and team plan the release together.
2. **Small Releases:** deliver working software often.
3. **Pair Programming:** two programmers share one machine.
4. **Test-Driven Development:** write tests before code.
5. **Refactoring:** improve code without changing behaviour.
6. **Continuous Integration:** merge and build many times a day.
7. **Simple Design:** build only what is needed now.
8. **Collective Code Ownership:** anyone can change any code.
9. **Coding Standards:** uniform style across the team.
10. **Sustainable Pace:** no long overtime.
11. **On-site Customer:** customer available to the team.

[⬆ Back to top](#unit-3--answers)

---

## Last-minute revision: Unit 3
- **Scrum:** 3 roles, 3 artifacts, 4 events, fixed Sprint.
- **XP lifecycle:** Exploration → Planning → Iterations → Productionizing → Maintenance → Death.
- **ASD:** Speculate → Collaborate → Learn.
- **Agile elicitation** is continuous, uses user stories, and welcomes change.
- **Scrum = management; XP = engineering practices.**
