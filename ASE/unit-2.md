# Unit 2: Agile Fundamentals, Manifesto & Project Management — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 2](questions.md#unit-ii--agile-fundamentals-manifesto--project-management)

---

## Part A: 2-Mark Short Questions

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

## Part B: 8-Mark Questions

### 1. Theories of Agile Management

**Q1. Describe the major theories of Agile Management and their relevance to Agile Software Development. (8M)**

#### 1. Overview of Agile Management Theories
Agile Management transitions organizations from mechanistic, bureaucratic command-and-control hierarchies to organic, adaptive ecosystems. It draws heavily upon modern organizational science, sociology, and complexity theory.

#### 2. Four Foundational Management Theories

```
┌────────────────────────────────────────────────────────────────────────┐
│                      THEORIES OF AGILE MANAGEMENT                      │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. Complex         │ 2. Empirical       │ 3. Theory Y & Servant        │
│    Adaptive        │    Process Control │    Leadership (Human         │
│    Systems (CAS)   │    (Inspection &   │    Relations School)         │
│                    │     Adaptation)    │                              │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

1. **Complex Adaptive Systems (CAS) Theory:**
   - *Core Premise:* Software development is not a predictable assembly line; it is a complex adaptive system composed of independent, interacting agents (developers, users, systems).
   - *Relevance to Agile:* Instead of rigid central planning, managers establish lightweight governing boundaries (simple rules) and allow self-organization and emergent design to solve technical challenges.
2. **Empirical Process Control Theory:**
   - *Core Premise:* Traditional management relies on *defined* processes (assuming identical inputs yield identical outputs). In contrast, empirical process control acknowledges uncertainty and relies on three pillars:
     - **Transparency:** All work, progress, and blockers are visible to all stakeholders (e.g., Kanban boards, burn-down charts).
     - **Inspection:** Frequent reviews of artifacts and processes (e.g., Sprint Reviews, Retrospectives).
     - **Adaptation:** Immediate correction if an inspection reveals deviation outside acceptable limits.
3. **Human Relations School & Theory Y (Douglas McGregor):**
   - *Core Premise:* Theory X assumes workers are lazy and need coercion; Theory Y assumes workers are intrinsically motivated, creative, and seek responsibility.
   - *Relevance to Agile:* Agile managers reject micro-management. They empower cross-functional teams, trust their technical judgment, and provide required environments and resources.
4. **Lean Management & Flow Theory (Womack & Jones):**
   - *Core Premise:* Focuses on eliminating non-value-adding waste (*Muda*), such as partially done work, handoffs, task switching, and defects, while optimizing flow efficiency.

---

### 2. Traditional vs. Agile Software Development Models

**Q2. Differentiate between Traditional and Agile Software Development Models with respect to planning, requirements, development, testing, and delivery. (8M)**

#### 1. Core Paradigm Shift
- **Traditional (Plan-Driven / Predictive):** Assumes the problem domain and solution can be completely analyzed, documented, and frozen before execution starts.
- **Agile (Value-Driven / Adaptive):** Assumes requirements change unpredictably; software evolves through iterative learning and frequent stakeholder feedback.

#### 2. Detailed Dimension-by-Dimension Comparison

| Dimension | Traditional Model (e.g., Waterfall) | Agile Model (e.g., Scrum / XP) |
|---|---|---|
| **1. Planning** | **Upfront & Comprehensive:** Detailed Gantt charts, resource plans, and budgets fixed for the entire multi-month project lifecycle. | **Adaptive & Rolling-Wave:** High-level release roadmap; detailed task planning happens only for the upcoming 1–4 week iteration. |
| **2. Requirements** | **Static & Document-Centric:** Captured exhaustively in a formal SRS document; signed off early; modifications require formal Change Control Boards. | **Dynamic & User-Centric:** Expressed as concise user stories prioritized in a living Product Backlog; details elaborated just-in-time. |
| **3. Development** | **Sequential & Siloed:** Distinct phases separated by handoffs (Analysts $\to$ Architects $\to$ Coders $\to$ Testers). | **Concurrent & Cross-Functional:** One multi-disciplinary team designs, codes, tests, and refactors together in continuous cycles. |
| **4. Testing** | **Late Phase Activity:** Testing occurs in a dedicated phase after all coding is finished. High risk of discovering critical architectural defects late. | **Continuous & Integrated:** Testing begins on day one (TDD, automated regression, daily builds). Whole team owns quality. |
| **5. Delivery** | **Monolithic \"Big Bang\":** Single deployment at project conclusion. Customer sees and verifies software after months/years. | **Iterative & Incremental:** Production-ready, working software increments delivered at the end of every 2–4 week iteration. |

#### 3. Summary Workflow Comparison
- **Traditional:** `Plan ──► Specify (SRS) ──► Design ──► Code ──► Test ──► Deploy (Single End Delivery)`
- **Agile:** `[Plan ──► Build ──► Test ──► Deploy Increment 1] ──► [Repeat for Increments 2, 3, ... N]`

---

### 3. Four Values of the Agile Manifesto

**Q3. Discuss the four values of the Agile Manifesto and illustrate each value with a suitable example. (8M)**

#### 1. Background
In February 2001, 17 software practitioners authored the **Agile Manifesto** to restore agility, human teamwork, and engineering pragmatism to software development:
> *"While there is value in the items on the right, we value the items on the left more."*

```
   ┌───────────────────────────────────────────┬───────────────────────────────────────────┐
   │          WE VALUE MORE (LEFT)             │         OVER ITEMS ON RIGHT               │
   ├───────────────────────────────────────────┼───────────────────────────────────────────┤
   │ 1. Individuals and Interactions           │ Processes and Tools                       │
   │ 2. Working Software                       │ Comprehensive Documentation               │
   │ 3. Customer Collaboration                 │ Contract Negotiation                      │
   │ 4. Responding to Change                   │ Following a Plan                          │
   └───────────────────────────────────────────┴───────────────────────────────────────────┘
```

#### 2. Detailed Explanation & Real-World Examples

1. **Individuals and Interactions over Processes and Tools:**
   - *Meaning:* People and communication solve complex engineering problems, not fancy project management software or rigid standard operating procedures.
   - *Example:* Instead of filing a Jira ticket and waiting days for an email reply across functional silos, a developer and tester hold a 5-minute whiteboarding session to resolve an API contract ambiguity immediately.
2. **Working Software over Comprehensive Documentation:**
   - *Meaning:* A working, executable program is the only true measure of progress. Hundreds of pages of unverified specifications do not provide user value.
   - *Example:* Instead of spending 3 months drafting a 300-page SRS for an online banking checkout, the team builds a working, secured payment gateway prototype in 2 weeks and demos it live to stakeholders.
3. **Customer Collaboration over Contract Negotiation:**
   - *Meaning:* Building great software requires a collaborative partnership where the customer actively steers development, rather than an adversarial legal relationship based on static contracts.
   - *Example:* When market research reveals users prefer OTP authentication over passwords, the Product Owner and developers collaborate to modify the feature immediately, without invoking penalty clauses or renegotiating contracts.
4. **Responding to Change over Following a Plan:**
   - *Meaning:* Plans must adapt as new information, technologies, and market requirements emerge. Blindly adhering to an obsolete initial plan leads to project failure.
   - *Example:* When government tax laws change mid-sprint, the team re-prioritizes the Product Backlog and adjusts the current sprint increment to comply with legal regulations.

---

### 4. Principles of the Agile Manifesto

**Q4. Analyze the principles of the Agile Manifesto and their contribution to iterative and customer-focused development. (8M)**

#### 1. Overview
The Agile Manifesto defines **12 fundamental principles** that translate its four core values into actionable operational practices.

#### 2. Categorization & Analysis of the 12 Principles

```
                              12 AGILE PRINCIPLES
        ┌──────────────────────────────┼──────────────────────────────┐
        │                              │                              │
Customer Focus & Delivery      Teamwork & Culture           Engineering Excellence
 (P1, P2, P3, P7)               (P4, P5, P6, P11, P12)       (P8, P9, P10)
```

1. **Customer Focus & Value Delivery:**
   - *Principle 1 (Customer Satisfaction):* Highest priority is to satisfy the customer through early and continuous delivery of valuable software.
   - *Principle 2 (Welcome Change):* Welcome changing requirements, even late in development. Agile harnesses change for the customer's competitive advantage.
   - *Principle 3 (Frequent Delivery):* Deliver working software frequently (weeks rather than months).
   - *Principle 7 (Primary Metric):* Working software is the primary measure of project progress.
2. **Human Collaboration & Team Dynamics:**
   - *Principle 4 (Daily Collaboration):* Business people and developers must work together daily throughout the project.
   - *Principle 5 (Motivated Individuals):* Build projects around motivated individuals. Give them the environment, support, and trust to get the job done.
   - *Principle 6 (Face-to-Face Conversation):* The most efficient and effective method of conveying information is face-to-face conversation.
   - *Principle 11 (Self-Organizing Teams):* The best architectures, requirements, and designs emerge from self-organizing teams.
   - *Principle 12 (Reflect & Adjust):* At regular intervals, the team reflects on how to become more effective, then tunes and adjusts its behavior accordingly.
3. **Engineering Rigor & Sustainable Flow:**
   - *Principle 8 (Sustainable Pace):* Agile processes promote sustainable development. Sponsors, developers, and users should maintain a constant pace indefinitely.
   - *Principle 9 (Technical Excellence):* Continuous attention to technical excellence and good design enhances agility.
   - *Principle 10 (Simplicity):* Simplicity—the art of maximizing the amount of work not done—is essential.

#### 3. Contribution to Iterative & Customer-Focused Development
- Short delivery loops eliminate the risk of building unneeded features.
- Daily business interaction ensures that developed features directly solve live business problems.

---

### 5. Classification of Major Agile Methods

**Q5. Classify the major Agile methods and compare their key characteristics. (8M)**

#### 1. Classification Taxonomy
Agile methods can be classified into two complementary categories:
1. **Management / Workflow Frameworks:** Focus on team cadence, backlog organization, ceremonies, and flow (e.g., Scrum, Kanban, Lean).
2. **Technical / Engineering Methodologies:** Focus on code design, automated verification, programming practices, and refactoring (e.g., Extreme Programming, TDD, FDD).

#### 2. Overview of the 5 Major Methods
1. **Scrum:** Lightweight framework structured around 3 roles (Product Owner, Scrum Master, Developers), 3 artifacts (Product Backlog, Sprint Backlog, Increment), and 5 events (Sprint, Planning, Daily Standup, Review, Retrospective).
2. **Extreme Programming (XP):** Engineering-focused method created by Kent Beck. Prescribes technical practices: Test-Driven Development (TDD), Pair Programming, Continuous Integration, Refactoring, and Small Releases.
3. **Crystal Methodologies (Alistair Cockburn):** People-centric family of methods color-coded by team size and system criticality (Crystal Clear, Yellow, Orange, Red). Emphasizes human communication over technical constraints.
4. **Feature Driven Development (FDD):** Client-centric method developed by Jeff De Luca. Focuses on short, feature-based iterations across 5 core steps (Develop model $\to$ Build feature list $\to$ Plan by feature $\to$ Design by feature $\to$ Build by feature).
5. **Adaptive Software Development (ASD):** Jim Highsmith's method for complex, unpredictable systems. Replaces plan-build with the learning cycle: **Speculate $\to$ Collaborate $\to$ Learn**.

#### 3. Cross-Method Comparison Table

| Method | Primary Focus | Iteration Length | Key Practices / Artifacts | Ideal Context |
|---|---|---|---|---|
| **Scrum** | Project & Sprint management | 1–4 weeks (fixed) | Backlogs, Sprints, Daily Scrum, Reviews | General product development with evolving needs |
| **XP** | Software engineering craft | 1–2 weeks | Pair Programming, TDD, CI, Refactoring | High technical risk, changing specs, quality-critical code |
| **Crystal** | Human communication & safety | 2–6 weeks | Co-location, frequent delivery, reflective improvement | Tailored by team size (Clear for 1–6 people, Orange for 40+) |
| **FDD** | Feature-by-feature progress | 2 days to 2 weeks | Object modeling, feature lists, chief programmer teams | Larger teams building domain-driven, corporate applications |
| **ASD** | Continuous learning under change | Time-boxed cycles | Speculate $\to$ Collaborate $\to$ Learn, customer focus groups | Highly volatile, exploratory research and development |

---

### 6. Agile Project Management: Team Interactions, Roles, Responsibilities

**Q6. Demonstrate how Agile Project Management supports team interactions, roles, and responsibilities. (8M)**

#### 1. The Agile Project Management Paradigm
Agile Project Management (APM) replaces hierarchical management with a collaborative, servant-leadership model that maximizes team autonomy, transparency, and fast decision-making.

```
       STAKEHOLDERS / CUSTOMERS
                  │
                  ▼
         [ Product Owner ]  ◄── (Prioritizes Value & Backlog)
                  │
                  ▼
         [ Development Team ] ◄── (Cross-Functional, Self-Organizing: Builds Increment)
                  ▲
                  │
         [ Scrum Master / Coach ] ◄── (Servant Leader: Protects Team, Clears Obstacles)
```

#### 2. Core Roles & Clear Responsibilities
1. **Product Owner (PO):**
   - *Role:* Voice of the customer and business value maximizer.
   - *Responsibilities:* Manages and grooms the Product Backlog, prioritizes user stories by business value, sets acceptance criteria, and accepts/rejects completed work increments.
2. **Scrum Master / Agile Coach:**
   - *Role:* Servant-leader and process champion.
   - *Responsibilities:* Shields developers from external interruptions, eliminates workflow blockers (impediments), coaches the team on Agile values, and facilitates ceremonies without acting as a commanding boss.
3. **Cross-Functional Development Team:**
   - *Role:* Self-organizing execution unit (developers, QA testers, UI/UX designers, database engineers).
   - *Responsibilities:* Collaboratively estimates effort (story points), commits to sprint scope, decides *how* to implement technical features, and delivers a potentially shippable increment.

#### 3. Agile Team Interaction Mechanisms
- **Daily Stand-Up (15 mins):** Synchronizes activities, promotes peer accountability, and uncovers dependencies.
- **Sprint Planning:** PO and Developers collaboratively negotiate the sprint goal and scope.
- **Sprint Review:** Developers showcase live, working software to stakeholders to capture real user feedback.
- **Sprint Retrospective:** Dedicated team meeting analyzing process bottlenecks and committing to continuous self-improvement.

---

### 7. Ethics, Agility in Design & Testing, and Agile Documentation

**Q7. Examine the importance of ethics, agility in design and testing, and Agile documentation within an Agile team. (8M)**

#### 1. Ethics in Agile Teams
Because Agile relies heavily on self-organization, autonomy, and transparency rather than micromanagement, high ethical standards are vital:
- **Intellectual Honesty:** Truthfully disclosing technical debt, security flaws, and missed estimates early instead of hiding them under pressure.
- **Mutual Respect & Psychological Safety:** Encouraging blameless retrospectives where team members can discuss failures openly without fear of reprisal.
- **Customer Data Privacy:** Upholding ethical data protection standards when handling sensitive user records during development and testing.

#### 2. Agility in Software Design
- **Evolutionary Architecture:** Eliminates Big Design Up Front (BDUF). Teams build simple, clean designs that satisfy current user stories, relying on automated test suites and refactoring to evolve the architecture gracefully.
- **Adherence to Clean Code & SOLID:** Ensures classes and modules exhibit low coupling and high cohesion, making code modification rapid and safe.

#### 3. Agility in Software Testing
- **Continuous & Integrated:** Testing is not an afterthought phase; testers collaborate with developers from day one.
- **Shift-Left Testing & Automation:** Utilizing Test-Driven Development (TDD) and Behavior-Driven Development (BDD) to validate specifications before and during coding.
- **Whole-Team Quality Ownership:** Quality is the collective responsibility of the entire team, not solely the QA department.

#### 4. Agile Documentation
- **\"Just-Enough, Just-In-Time\":** Documentation is treated as a supporting asset, not the final goal. Teams write concise architectural blueprints and API specs only when necessary.
- **Living Documentation:** Automated acceptance tests (e.g., Cucumber scenarios) and clean, self-documenting code serve as verified, permanently up-to-date documentation.

---

### 8. Agile Implementation Plan for Retail Software Migration

**Q8. Design an Agile implementation plan for a retail software company migrating from Waterfall to Agile, covering Agile values, project management, team interaction, testing, and documentation. (8M)**

#### 1. Organizational Context & Problem Statement
*RetailCorp* operates a legacy point-of-sale (POS) and inventory system built using the Waterfall model. Releases take 9–12 months, customer feature requests stall in change control queues, and late testing uncovers severe defects. Management seeks to transition to an Agile Scrum framework.

#### 2. Five-Pillar Migration Plan

```
┌────────────────────────────────────────────────────────────────────────┐
│               RETAILCORP AGILE TRANSITION BLUEPRINT                    │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. Agile Values &  │ 2. Project         │ 3. Team Interaction          │
│    Cultural Shift  │    Management      │    & Cadence                 │
├────────────────────┼────────────────────┼──────────────────────────────┤
│ 4. Agile Testing & │ 5. Agile           │ Expected Outcome:            │
│    Engineering     │    Documentation   │ 2-Week Bi-Weekly Releases    │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

#### 3. Detailed Execution Blueprint

1. **Pillar 1: Cultural Alignment & Agile Values:**
   - Conduct workshop training on the 4 Agile Manifesto values.
   - Shift organizational mindset from *\"following rigid contracts\"* to *\"delivering frequent retail customer value\"*.
2. **Pillar 2: Project Management Transformation:**
   - Form cross-functional teams of 7–8 members (frontend, backend, QA, retail domain analyst), breaking functional silos.
   - Appoint senior retail business analysts as **Product Owners** to manage a prioritized Product Backlog.
   - Appoint experienced coaches as **Scrum Masters** to remove blockers and protect team focus.
3. **Pillar 3: Team Interaction & Cadence Setup:**
   - Establish standard **2-week Sprint cycles**.
   - Enforce mandatory ceremonies:
     - *Sprint Planning:* Every second Monday (commit to retail stories, e.g., \"Scan barcode & apply discount\").
     - *Daily Scrum:* 15-minute morning standup.
     - *Sprint Review:* Live demo to retail store managers every alternate Friday.
     - *Retrospective:* Team process improvement sessions.
4. **Pillar 4: Testing & Automation Strategy:**
   - Introduce **Continuous Integration (CI)** using GitHub Actions/Jenkins.
   - Implement **Test-Driven Development (TDD)** for critical pricing and discount logic.
   - Build an automated regression test suite using Selenium/Playwright to verify POS checkout flows on every build.
5. **Pillar 5: Lean Documentation Strategy:**
   - Replace 400-page SRS documents with living Jira backlogs and user stories with clear Given-When-Then acceptance criteria.
   - Auto-generate API documentation using Swagger/OpenAPI.
