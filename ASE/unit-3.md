# Unit 3: Agile Process Models & Requirements Engineering — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 3](questions.md#unit-iii--agile-process-models--requirements-engineering)

---

## Part A: 2-Mark Short Questions

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

## Part B: 8-Mark Questions

### 1. Scrum Framework: Lifecycle, Roles, Artifacts, Practices

**Q1. Explain the Scrum framework with reference to its lifecycle, roles, work products, and practices. (8M)**

#### 1. Definition & Core Philosophy
**Scrum** is a lightweight, iterative Agile framework designed to develop complex products adaptively. Work is structured into fixed-length iterations called **Sprints** (typically 1 to 4 weeks), delivering a potentially releasable **Increment** at each cycle.

#### 2. Three Major Roles
1. **Product Owner (PO):** Represents stakeholders and customers. Manages and prioritizes the Product Backlog, defines acceptance criteria, and decides when to release increments.
2. **Scrum Master (SM):** A servant-leader. Facilitates Scrum events, eliminates impediments (blockers), coaches the team on Agile values, and protects the team from external distractions.
3. **Development Team:** Cross-functional group of 3–9 specialists (programmers, testers, UI designers) who are self-organizing and mutually accountable for turning backlog items into working software.

#### 3. Three Core Work Products (Artifacts)
1. **Product Backlog:** A living, ordered list of all desired features, technical requirements, and bug fixes.
2. **Sprint Backlog:** The subset of Product Backlog items selected for the active Sprint, combined with the team's tactical delivery plan.
3. **Increment:** The sum of all completed, thoroughly tested backlog items delivered during a Sprint, meeting the team's formal **Definition of Done (DoD)**.

#### 4. Five Key Events (Practices & Ceremonies)
1. **Sprint:** The foundational time-boxed container (1–4 weeks) encompassing all execution activities.
2. **Sprint Planning:** Meeting where the team and PO agree on the Sprint Goal and select items for the Sprint Backlog.
3. **Daily Scrum:** 15-minute daily standup to inspect progress and synchronize tasks:
   - What did I accomplish yesterday?
   - What will I work on today?
   - Are there any impediments blocking my progress?
4. **Sprint Review:** End-of-sprint demo showcasing working software to stakeholders for inspection and feedback.
5. **Sprint Retrospective:** Dedicated team reflection examining process successes, bottlenecks, and committing to actionable improvements for the next Sprint.

#### 5. Scrum Workflow Flowchart
```
Product Backlog ──► Sprint Planning ──► Sprint Backlog ──► [ SPRINT (1–4 Weeks) ]
       ▲                                                           │
       │                                                 Daily Scrum (Every 24h)
       │                                                           ▼
Sprint Retrospective ◄── Sprint Review ◄───────────────── Working Product Increment
```

---

### 2. Extreme Programming (XP): Lifecycle, Roles, Artifacts, Practices

**Q2. Demonstrate the lifecycle, roles, work products, and practices of Extreme Programming (XP). (8M)**

#### 1. Concept & Philosophy
Created by **Kent Beck**, **Extreme Programming (XP)** is an Agile methodology centered on **disciplined software engineering practices**. XP takes recognized best practices (testing, code review, simplicity) and pushes them to \"extreme\" levels (e.g., if code review is good, we review code continuously via Pair Programming).

#### 2. The XP Lifecycle Phases

```
Exploration ──► Planning ──► Iterations to Release ──► Productionizing ──► Maintenance ──► Death
 (User Stories)  (Game)        (TDD, Pair Prog, CI)     (Extra Testing)   (Continuous)     (Retire)
```

1. **Exploration (a few weeks):** Customers write user stories on index cards; developers experiment with architectural spikes and technology options.
2. **Planning (Planning Game):** Customers prioritize stories by business value; developers estimate effort. Together they schedule the first release (typically 2–3 months).
3. **Iterations to Release (1–3 weeks each):** Developers implement stories using core engineering practices. At iteration end, customer acceptance tests verify completion.
4. **Productionizing:** Final end-to-end performance tuning, operational readiness checks, and production certification.
5. **Maintenance:** Normal production operations where new features and patches continue to be developed incrementally.
6. **Death:** The system reaches the end of its life cycle when no new customer stories exist or migration to a successor system occurs.

#### 3. Roles and Work Products
- **Roles:** Customer (writes stories/tests), Programmer (estimates, codes, tests), Coach (guides XP practices), Tracker (monitors velocity/metrics).
- **Work Products:** User Story Cards, Acceptance Test Suites, Unit Tests, Working Source Code, Architectural Spikes.

#### 4. The 12 Core XP Practices
- **Planning:** 1. The Planning Game, 2. Small Releases, 3. Customer on Site.
- **Designing:** 4. Simple Design (YAGNI), 5. System Metaphor, 6. Refactoring.
- **Coding:** 7. Pair Programming, 8. Collective Code Ownership, 9. Coding Standards.
- **Testing & Integrating:** 10. Test-Driven Development (TDD), 11. Continuous Integration (CI).
- **Team Cadence:** 12. Sustainable Pace (40-hour work week).

---

### 3. Crystal vs. Feature Driven Development (FDD)

**Q3. Differentiate Crystal and Feature Driven Development (FDD) based on their major characteristics and development practices. (8M)**

#### 1. Core Principles
- **Crystal (Alistair Cockburn):** A human-powered, adaptive methodology. It recognizes that team size, communication proximity, and project criticality dictate process weight.
- **Feature Driven Development (Jeff De Luca / Peter Coad):** A pragmatic, client-centric, 5-step process organized around delivering small, tangible, client-valued software features.

#### 2. Comparative Analysis Table

| Basis | Crystal Methodologies | Feature Driven Development (FDD) |
|---|---|---|
| **Primary Philosophy** | People, talent, skills, and communication over strict processes | Architecture-driven, feature-based progress and milestone tracking |
| **Team Organization** | Categorized by colors based on team size & criticality (Clear, Yellow, Orange, Red) | Organized around **Chief Programmer Teams** and **Class Owners** |
| **Iteration Focus** | Cyclic delivery of working software increments (2–6 weeks) | Short feature iterations; each feature completed in **2 to 10 days** |
| **Requirements Format** | Use cases, lightweight stories, direct osmotic communication | Formal hierarchical **Feature List** (Major Feature $\to$ Feature Activity $\to$ Feature) |
| **Modeling & Design** | Minimal, emergent design; focus on reflective self-tuning | Upfront object-oriented **Domain Object Modeling** with domain experts |
| **Code Ownership** | Collective code ownership; osmotic communication | **Individual Class Ownership** (only class owner can modify that file) |
| **Verification** | Automated regression, frequent demos, side-by-side testing | **Design & Code Inspections**, unit testing, milestone progress tracking |

#### 3. FDD 5-Step Process Workflow
```
Develop Overall Model ──► Build Feature List ──► Plan by Feature ──► Design by Feature ──► Build by Feature
    (Domain Walkthrough)      (Granular Items)     (Ownership & Milestones) (Class Design)    (Code & Inspect)
```

---

### 4. Adaptive Software Development (ASD): Lifecycle and Principles

**Q4. Illustrate the lifecycle and major principles of Adaptive Software Development (ASD). (8M)**

#### 1. Concept & Philosophy
Proposed by **Jim Highsmith**, **Adaptive Software Development (ASD)** was created for projects characterized by **extreme requirements volatility, high uncertainty, and rapid technology change**. ASD rejects the classical deterministic assumption that complex software can be fully pre-planned.

#### 2. The ASD Dynamic Learning Cycle

```
   ┌─────────────────────────────────────────────────────────────┐
   │                                                             │
   ▼                                                             │
SPECULATE ──────────────────► COLLABORATE ──────────────────► LEARN
(Mission-Driven Planning)     (Concurrent Engineering)        (Quality & Feedback)
```

1. **Speculate (Planning):**
   - Traditional \"plan\" implies certainty; ASD uses **speculate** because outcomes cannot be definitively known in advance.
   - The team defines a broad **project mission statement**, establishes fixed time-boxed cycles, and outlines milestones while explicitly expecting change.
2. **Collaborate (Engineering):**
   - High-uncertainty projects cannot be solved by isolated individuals. Developers, testers, and customers work in high-trust, cross-functional collaboration.
   - Features are developed concurrently in short, overlapping iterations.
3. **Learn (Quality Review):**
   - At the conclusion of every cycle, the team evaluates results across three distinct learning dimensions:
     - *Customer Focus Group Review:* Users test working increments and provide feedback.
     - *Technical Review:* Architects inspect code quality, modularity, and test coverage.
     - *Post-Mortem / Retrospective:* The team analyzes process efficiency and lessons learned.
   - Insights directly feed into the next Speculate phase.

#### 3. Major Principles of ASD
- **Mission-Driven:** Focuses on clear organizational business goals rather than rigid task checklists.
- **Feature-Based:** Progress is measured through completed, working user features.
- **Time-Boxed:** Cycles have immutable deadlines, forcing prioritization.
- **Risk-Driven:** Complex, high-risk features are tackled in early iterations.
- **Change-Friendly:** Change is not viewed as a disruptive defect; it is treated as an opportunity to learn.

---

### 5. Comparison of Scrum, Crystal, FDD, ASD, and XP

**Q5. Compare Scrum, Crystal, FDD, ASD, and XP with respect to lifecycle, roles, work products, and practices. (8M)**

#### Comprehensive Cross-Method Comparative Matrix

| Method | Lifecycle Structure | Defined Roles | Primary Work Products | Signature Practices |
|---|---|---|---|---|
| **Scrum** | Sprints of 1–4 weeks (fixed time-box) | Product Owner, Scrum Master, Development Team | Product Backlog, Sprint Backlog, Potentially Shippable Increment | Daily Scrum, Sprint Planning, Review, Retrospective, Sprint Backlog grooming |
| **Extreme Programming (XP)** | Exploration $\to$ Planning $\to$ Iterations (1–3 wks) $\to$ Production $\to$ Maintenance | Customer, Programmer, Coach, Tracker, Manager | User Story Cards, Acceptance Tests, Automated Unit Tests, Spikes | Pair Programming, Test-Driven Development (TDD), Refactoring, Continuous Integration |
| **Crystal** | Cyclic releases (2–6 weeks), frequent delivery | Sponsor, Lead Designer, Programmer, User (tailored by color) | Working Software Increment, Use Cases, Reflection Notes | Osmotic Communication, Co-location, Reflective Improvement, Personal Safety |
| **Feature Driven Development (FDD)** | 5-step process: Model $\to$ List $\to$ Plan $\to$ Design $\to$ Build (2–10 days/feature) | Project Manager, Chief Architect, Chief Programmer, Class Owner | Domain Object Model, Feature List, Work Packages | Individual Class Ownership, Feature Teams, Formal Design/Code Inspections |
| **Adaptive Software Development (ASD)** | Iterative learning cycle: Speculate $\to$ Collaborate $\to$ Learn | Project Manager, Technical Lead, Customer Focus Group | Project Mission Statement, Time-box Plan, Working Features | Customer Focus Groups, JAD sessions, Technical Reviews, Collaborative Post-mortems |

---

### 6. Impact of Agile on Requirements Engineering and Practices

**Q6. Analyze the impact of Agile processes on Requirements Engineering and identify important Agile RE practices. (8M)**

#### 1. The Agile Paradigm Shift in Requirements Engineering
Traditional Requirements Engineering (RE) operates under the assumption that all requirements can be elicited, analyzed, and documented in a comprehensive SRS before construction begins. In contrast, **Agile Requirements Engineering (ARE)** treats requirements as an evolving, interactive conversation.

```
Traditional RE: Elicitation ──► Specification (SRS) ──► Validation ──► [Requirements Frozen]
Agile RE:       Living Backlog ──► JIT User Story Elaboration ──► Code & Test ──► Continuous Feedback
```

#### 2. Key Impacts of Agile on RE
1. **Dynamic & Evolving Scope:** Requirements are prioritized by business value and remain open to modification throughout the project.
2. **Just-In-Time (JIT) Elaboration:** Requirements details are not written months ahead; they are detailed immediately before the iteration in which they are built.
3. **From Sign-Off Documents to Shared Understanding:** Eliminates misunderstandings caused by reading dense legalistic SRS documents; relies on direct verbal discussions supported by acceptance tests.
4. **Executable Requirements:** Acceptance criteria are automated using Behavior-Driven Development (BDD), turning requirements into living regression suites.

#### 3. Core Agile Requirements Engineering Practices
- **User Stories & 3 C's Framework:**
  - *Card:* Brief story statement representing requirement intent.
  - *Conversation:* Continuous dialogue between developers and customer to unpack details.
  - *Confirmation:* Objective acceptance criteria defining when the story is "done".
- **INVEST Criteria for High-Quality Stories:**
  - **I**ndependent, **N**egotiable, **V**aluable, **E**stimable, **S**mall, **T**estable.
- **Product Backlog Refinement (Grooming):** Regular sessions where the PO and team split large stories (Epics) into small stories and estimate story points.
- **Acceptance Criteria & BDD Scenarios:** Defining expected behaviors using standard Given-When-Then syntax.

#### 4. Challenges in Managing Changing Requirements (From Raw Notes)
1. **Scope Creep:** Customers continuously add new features without adjusting the project schedule or budget.
2. **Thrashing (Wasted Effort):** Frequent mid-iteration changes prevent programmers from finishing tasks, destroying team momentum.
3. **Requirements Churn:** Rapidly changing specifications create confusion, rework, and inconsistent system state.
4. **Technical Debt:** Rushed implementation of late changes without proper refactoring degrades code quality.

---

### 7. Requirements Elicitation Techniques in Agile

**Q7. Demonstrate suitable Requirements Elicitation techniques for an Agile development environment. (8M)**

#### 1. Agile Elicitation Principles
Agile requirements elicitation prioritizes collaborative, fast, and visual techniques that minimize document overhead while maximizing customer interaction.

#### 2. How Agile Accommodates Changing Customer Requirements (8 Mechanisms)
1. **Living Product Backlog:** The backlog is constantly updated; new requirements are added, modified, or removed anytime by the PO.
2. **Continuous Customer Feedback:** Direct, regular interaction ensures direction is corrected early before costly errors spread.
3. **Short Iterations (Sprints):** 1 to 4 week cycles mean a new requirement can be incorporated into the next iteration with minimal delay.
4. **Backlog Reprioritization:** Features are dynamically re-ranked so the team always works on the highest business value items.
5. **Just-in-Time (JIT) Requirements:** Details are written only when a story is ready to be built, avoiding wasted effort on changing specs.
6. **Sprint Reviews:** Working software is demonstrated at the end of every sprint, eliciting real customer feedback.
7. **Frequent Small Releases:** Delivers usable increments frequently, validating true market requirements.
8. **Protected Current Sprint:** Changes are not introduced into an active Sprint, preventing thrashing while welcoming change in the next backlog grooming.

#### 3. Four Primary Agile Elicitation Techniques

```
┌────────────────────────────────────────────────────────────────────────┐
│                 AGILE REQUIREMENTS ELICITATION SUITE                   │
├────────────────────┬────────────────────┬──────────────────────────────┤
│ 1. User Story      │ 2. Collaborative   │ 3. Rapid UI/UX               │
│    Writing         │    Workshops & JAD │    Prototyping &             │
│    Workshops       │    Sessions        │    Wireframing               │
├────────────────────┼────────────────────┼──────────────────────────────┤
│ 4. Story Mapping   │ 5. Customer On-    │ Outcome: High-Yield, Clean,  │
│    (Jeff Patton)   │    Site Demos      │ Testable User Stories        │
└────────────────────┴────────────────────┴──────────────────────────────┘
```

1. **User Story Writing Workshops:**
   - Cross-functional team (PO, developers, testers, actual users) holds structured brainstorming sessions.
   - Participants write story cards on physical sticky notes or virtual boards using role-based templates (*"As a... I want... So that..."*).
2. **User Story Mapping (Jeff Patton Technique):**
   - Visual arrangement of the user's journey along a horizontal timeline (the "backbone"), such as *Browse $\to$ Select $\to$ Cart $\to$ Checkout*.
   - Vertical slices decompose steps into prioritized features, clearly identifying Minimum Viable Product (MVP) release boundaries.
3. **Interactive Prototyping & Wireframing:**
   - Building clickable mockups (using Figma or lightweight HTML) to elicit feedback on user experience before building database backends.
4. **Direct Customer Interviews & On-Site Interaction:**
   - XP style on-site customer or daily PO access. Developers ask targeted questions directly rather than sending emails across management layers.
5. **Behavior-Driven Given-When-Then Workshops:**
   - Defining edge cases and scenarios collaboratively:
     - *Given* a customer with \$50 balance,
     - *When* they attempt to purchase a \$75 item,
     - *Then* the transaction is declined with an "Insufficient Funds" alert.

---

### 8. Agile Requirements Engineering for Healthcare Project

**Q8. Develop an Agile Requirements Engineering approach for a healthcare software project with frequently changing requirements. (8M)**

#### 1. Project Context & Challenges
A **Hospital Patient Management & Telemedicine System** must navigate strict regulatory compliance (HIPAA, NABH), evolving physician clinical workflows, patient privacy rules, and shifting medical insurance billing codes.

#### 2. Architectural Agile RE Strategy

```
Stakeholders (Doctors, Nurses, Patients, Insurers)
                       │
                       ▼
          [ Collaborative RE Workshops ]
                       │
                       ▼
       Living Product Backlog (Prioritized)
          ├── Release 1: Patient Registration & Telehealth Consultation
          ├── Release 2: E-Prescription & Pharmacy Integration
          └── Release 3: Insurance Claims & Diagnostic Lab Reports
                       │
                       ▼
   Sprint Delivery ──► Clinical Feedback ──► Backlog Refinement
```

#### 3. Step-by-Step Implementation Approach

1. **Role Identification & Persona Modeling:**
   - Define concrete clinical personas: *Dr. Sharma (Cardiologist)*, *Staff Nurse Mary*, *Patient (Elderly/Remote)*, *Billing Auditor*.
2. **Backlog Structuring with Epics and INVEST Stories:**
   - *Epic:* Telemedicine Video Consultation.
   - *INVEST Story:*
     > **As a** registered patient,  
     > **I want to** schedule a 15-minute video consultation with my assigned doctor,  
     > **So that** I can receive medical advice without traveling to the hospital.
3. **Clinical Acceptance Criteria (Given-When-Then):**
   - *Given* patient has confirmed appointment slot and valid payment,
   - *When* consultation time arrives,
   - *Then* system generates an encrypted, HIPAA-compliant video room link accessible with one click.
4. **Regulatory & Compliance Spikes:**
   - When medical insurance protocols or encryption rules shift, conduct short technical research \"Spikes\" (1–2 days) to define compliance criteria before story commitment.
5. **Bi-Weekly Clinical Review & Feedback Loop:**
   - Involve actual physicians and hospital administrators in Sprint Reviews to test working software on medical tablets, refining subsequent sprint priorities.
