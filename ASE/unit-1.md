# Unit 1: Software Process & Classical Life Cycle Models — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 1](questions.md#unit-i--software-process--classical-life-cycle-models)

---

## 1. Software Process and Software Engineering Practice

**Q1. Describe the Software Process and Software Engineering Practice. Discuss the major activities involved in a software process. (8M)**

### 1. Software Process vs. Software Engineering Practice
- **Software Process:** A set of organized activities and steps followed to develop, deliver, and maintain a software system. It provides a structured framework to convert user requirements into a high-quality working software product.
- **Software Engineering Practice:** The technical methods, principles, and disciplined craft applied across the process (e.g., communication, modeling, algorithmic design, test construction, code refactoring).

### 2. Four Major Activities in a Software Process (Sommerville & Classical Syllabus)
1. **Software Specification:** In this stage, the requirements, operational constraints, and needs of the users are identified, analyzed, and clearly defined (producing the SRS).
2. **Software Design and Implementation:** The software architecture, database schemas, and modular components are designed based on requirements, and executable source code is developed.
3. **Software Validation:** The developed software is systematically tested and reviewed to verify that it functions correctly, is defect-free, and meets customer expectations.
4. **Software Evolution:** Following deployment, the software is updated, maintained, and enhanced to fix defects, adapt to new operating environments, and satisfy changing user needs.

### 3. Generic Framework Activities of a Software Process (Pressman Syllabus)
Every software process model also incorporates five generic engineering framework activities:

```
Communication ──► Planning ──► Modeling ──► Construction ──► Deployment
(Inception)       (Estimation) (Analysis/Design) (Code & Test)  (Release/Feedback)
```

1. **Communication:** Involves heavy collaboration with stakeholders. Developers perform requirements elicitation to identify business goals, project scope, and user needs.
2. **Planning:** Defines the software engineering roadmap. Encompasses task identification, risk assessment, resource allocation, effort estimation, and delivery milestone scheduling.
3. **Modeling:** Creation of architectural models, domain entity diagrams, and data flows to conceptualize how the system satisfies requirements before physical implementation.
4. **Construction:** Combines code generation (programming in standard languages) and comprehensive verification (unit, integration, and functional testing).
5. **Deployment:** The software increment is delivered to the customer for operational evaluation, acceptance testing, and continuous feedback.

### 4. Umbrella Activities
Operating continuously across all framework activities are **Umbrella Activities**:
- **Software Project Tracking and Control:** Comparing actual progress against scheduled baselines.
- **Risk Management:** Assessing and mitigating technical, schedule, and cost hazards.
- **Software Quality Assurance (SQA):** Conducting formal reviews and inspections.
- **Software Configuration Management (SCM):** Managing version control, change requests, and release baselines.
- **Work Product Preparation & Documentation:** Generating SRS, technical manuals, and user guides.

---

## 2. Phased Development Life Cycle

**Q2. Illustrate the Phased Development Life Cycle with its major phases and suitable examples. (8M)**

### 1. Concept & Rationale
The **Phased Development Life Cycle** decomposes complex software engineering endeavors into discrete, manageable stages. Rather than building the entire system in one monolithic effort, the project proceeds through verified checkpoints where each stage must produce tangible artifacts reviewed against quality standards.

### 2. Major Phases & Activities

```
┌─────────────────────┐    ┌─────────────────────┐    ┌─────────────────────┐
│ 1. Feasibility &   │ ──►│ 2. Requirements     │ ──►│ 3. Architecture &   │
│    Project Initiation│    │    Engineering      │    │    System Design    │
└─────────────────────┘    └─────────────────────┘    └─────────────────────┘
                                                                 │
┌─────────────────────┐    ┌─────────────────────┐               ▼
│ 6. Maintenance &    │ ◄──│ 5. System Testing   │ ◄──┌─────────────────────┐
│    Operations       │    │    & Verification   │    │ 4. Implementation   │
└─────────────────────┘    └─────────────────────┘    │    (Coding)         │
                                                      └─────────────────────┘
```

1. **Feasibility Study & Inception:** Evaluates technical viability, economic feasibility (cost-benefit analysis), and legal constraints.
2. **Requirements Analysis & Specification:** Stakeholders define detailed functional and non-functional requirements. Result: Signed **Software Requirements Specification (SRS)**.
3. **Architectural & Detailed Design:** System architects partition the system into modules, define database schemas (ER diagrams), and specify API contracts.
4. **Coding & Module Testing:** Programmers implement the design using selected tech stacks, conducting unit tests to verify logic at class and function levels.
5. **System Integration & Testing:** Assembled modules undergo functional, performance, regression, and user acceptance testing (UAT).
6. **Deployment & Maintenance:** System goes live; maintenance addresses corrective (bug fixes), adaptive (platform upgrades), and perfective (feature expansion) changes.

### 3. Real-World Walkthrough: E-Commerce Storefront
- *Phase 1:* Assess cloud server costs and checkout gateway compliance.
- *Phase 2:* Specify user stories: Cart operations, Payment gateways, Inventory sync.
- *Phase 3:* Design microservices (User Service, Catalog Service, Order Service) with PostgreSQL schemas.
- *Phase 4:* Implement REST endpoints in Java/Node.js with automated JUnit tests.
- *Phase 5:* Run integration tests simulating 10,000 concurrent shopping checkouts.
- *Phase 6:* Deploy to AWS; perform daily monitoring and security patch updates.

---

## 3. Waterfall Model: Phases, Advantages, Limitations

**Q3. Analyze the Waterfall Model with respect to its phases, advantages, limitations, and suitable applications. (8M)**

### 1. Concept
Proposed by Winston Royce, the **Waterfall Model** (Classic Life Cycle) is a linear-sequential software process. It mandates that each phase must be fully completed, verified, and signed off before the next phase begins, with zero overlapping.

```
[Requirements] ──► [System Design] ──► [Implementation] ──► [Testing] ──► [Deployment & Maintenance]
```

### 2. Detailed Phase Breakdown
1. **Requirements Analysis:** All potential requirements are captured upfront and documented in a formal SRS document.
2. **System Design:** Hardware requirements, system architecture, database schema, and high-level module hierarchies are established.
3. **Implementation:** Code is developed in small units, tested individually (unit testing), and integrated.
4. **Integration & System Testing:** The entire integrated suite is verified against the SRS to confirm functional completeness.
5. **Operations & Maintenance:** The system is installed at the customer environment; post-release defects are patched.

### 3. Advantages & Limitations

| Aspect | Advantages | Limitations |
|---|---|---|
| **Structure** | Highly disciplined, clear stage gates and deliverables | Inflexible; cannot accommodate changing requirements mid-project |
| **Management** | Simple to track progress, milestones, and project budget | High risk; working software is delivered only at the very end |
| **Documentation** | Extensive documentation at each phase aids auditability | Heavy documentation overhead slows delivery speed |
| **Defect Cost** | Early requirements defects caught before design are cheap | Defects found during testing require catastrophic, expensive rework |

### 4. Suitable Applications
- Safety-critical or defense systems where requirements are strictly regulated and legally frozen (e.g., flight control firmware).
- Migration projects where an existing, well-understood system is rewritten in a modern language without changing functionality.

---

## 4. Spiral Model and Risk Analysis

**Q4. Examine the Spiral Model and discuss how risk analysis influences its different iterations. (8M)**

### 1. Concept
Designed by Barry Boehm, the **Spiral Model** combines the iterative nature of prototyping with the controlled, systematic aspects of the Waterfall model. It introduces **explicit risk assessment** at every turn of the spiral.

### 2. The Four Quadrants of the Spiral Cycle

```
                       Determine Objectives,
                       Alternatives & Constraints
                                 │
                 Quadrant 1      │      Quadrant 2
                                 │
           ──────────────────────┼──────────────────────
                                 │
                 Quadrant 4      │      Quadrant 3
                                 │
                       Plan Next Phase     Develop & Verify
                                           Next-Level Product
```

1. **Quadrant 1 (Determine Objectives):** Identifies iteration goals, performance constraints, and alternative implementation approaches.
2. **Quadrant 2 (Identify & Resolve Risks):** Detailed technical, operational, and financial risk evaluation. Prototypes, simulations, and benchmark tests are built to resolve uncertainties.
3. **Quadrant 3 (Development & Verification):** Produces the next-level software increment using standard design, coding, and testing practices.
4. **Quadrant 4 (Review & Plan):** Customer evaluates the deliverable; the team reviews progress and plans the next spiral circuit.

### 3. How Risk Analysis Influences Iterations
- **Early Loops (Inception & Proof-of-Concept):** Evaluate technical feasibility risks (e.g., can the database handle 50,000 transactions/sec?). A throwaway prototype is built in Quadrant 2 to settle architectural risks before writing production code.
- **Middle Loops (Architecture & Core Features):** Assess integration, interface, and vendor dependency risks.
- **Late Loops (Production Release):** Focus on scalability, security vulnerabilities, and deployment reliability risks.
- **Decision to Terminate:** If a spiral loop reveals an insurmountable risk (e.g., severe budget overrun or obsolete technology), the project can be aborted early before sinking capital.

---

## 5. Evolutionary Model vs. Waterfall Model

**Q5. Compare the Evolutionary Model with the Waterfall Model with respect to handling changing requirements and software delivery. (8M)**

### 1. Architectural Philosophy
- **Waterfall Model:** Prescriptive, linear-sequential, assuming requirements are static and fully discoverable upfront.
- **Evolutionary Model:** Iterative, incremental, acknowledging that complex software requirements evolve as stakeholders interact with early versions.

### 2. Detailed Comparative Analysis

| Feature | Waterfall Model | Evolutionary Model |
|---|---|---|
| **Requirement Handling** | Frozen at the start; change requires formal, bureaucratic change control boards | Welcomes evolving requirements; feedback from iteration $N$ shapes iteration $N+1$ |
| **Software Delivery** | Monolithic "Big Bang" delivery at the project conclusion | Rapid delivery of functional increments (Core version $\to$ Enhanced versions) |
| **Customer Involvement** | High at the beginning (SRS sign-off) and end (UAT); absent during development | Continuous; customer validates every working increment |
| **Risk of Failure** | High; misunderstandings discovered late during integration or testing | Low; architectural and usability flaws identified and fixed early |
| **Documentation vs. Code** | Heavy emphasis on exhaustive specifications before coding begins | Working code takes precedence, supported by concise design specs |
| **Cost of Change** | Exponentially high if changes occur during late testing or coding | Moderate to low, as increments are small and modularly decoupled |

### 3. Delivery Workflow Comparison
- **Waterfall:** `Requirements (3 mos) ──► Design (3 mos) ──► Code (4 mos) ──► Test (2 mos) ──► Value Realized (Month 12)`
- **Evolutionary:** `Increment 1 (Month 2, Core Features) ──► Increment 2 (Month 4, Extra Features) ──► Increment 3 (Month 6, Final System)`

---

## 6. Software Project Management: Planning and Estimation

**Q6. Demonstrate the major activities involved in Software Project Management, including project planning and estimation. (8M)**

### 1. Software Project Management (SPM) Overview
Software Project Management ensures that engineering teams successfully execute projects within triple constraints: **Scope, Time, and Cost**, while maintaining high quality.

### 2. Major SPM Activities
```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│ Project Planning│ ──►│ Effort & Cost   │ ──►│ Risk Management │ ──►│ Project Tracking│
│ & WBS Scoping   │    │ Estimation      │    │ & Mitigation    │    │ & Control       │
└─────────────────┘    └─────────────────┘    └─────────────────┘    └─────────────────┘
```

1. **Project Planning & WBS Decomposition:**
   - Defines project boundaries, deliverables, and milestones.
   - Uses a **Work Breakdown Structure (WBS)** to decompose large modules into tasks with clear owners and dependencies.
2. **Effort and Cost Estimation:**
   - Calculates the person-months (PM) and calendar duration required.
   - **Empirical Models (COCOMO II):** Uses formulas based on Source Lines of Code (KSLOC) or Function Points (FP):
     $$\text{Effort} = a \times (\text{KSLOC})^b \quad [\text{Person-Months}]$$
   - **Analogy & Delphi Estimation:** Expert consensus estimating based on historical project data.
3. **Scheduling & Milestone Tracking:**
   - Utilizes **Gantt Charts** and **Critical Path Method (CPM) / PERT** to identify task dependencies, slack time, and bottlenecks.
4. **Risk Management:**
   - Systematic process: Identify risks $\to$ Assess probability & impact $\to$ Formulate mitigation strategies $\to$ Monitor triggers.
5. **Project Monitoring and Quality Control:**
   - Earned Value Analysis (EVA) compares planned budget/schedule against actual work completed.

---

## 7. Relationship Among Requirements, Design, Testing, Quality, and Reliability

**Q7. Analyze the relationship among requirements gathering, software design, software testing, software quality, and reliability. (8M)**

### 1. The Interdependent Quality Chain
Software engineering is an integrated pipeline where each activity directly governs the integrity of subsequent phases. Deficiencies in upstream phases amplify downstream failure rates.

```
Requirements Gathering ──► Software Design ──► Implementation ──► Software Testing
         │                       │                                       │
         ▼                       ▼                                       ▼
  Defines What Quality    Architects Quality                      Verifies Quality
       Is Expected             Into the Code                           & Integrity
         │                       │                                       │
         └───────────────────────┴───────────────────────────────────────┘
                                     │
                                     ▼
                    [Software Quality & High Reliability]
```

### 2. Detailed Phase Interactions & The Requirements Process

1. **Requirements Gathering (The Foundation):**
   - Involves 5 key activities: *Identifying Stakeholders*, *Collecting Requirements* (interviews/surveys), *Analyzing Requirements* (resolving conflicts), *Documenting Requirements* (SRS), and *Validating Requirements* (confirming user needs).
   - Requirements specify *what* the system must do (functional) and *how well* it must behave (non-functional). Incomplete requirements produce fundamentally flawed architectures.
2. **Requirements Gathering $\to$ Software Design:**
   - Design translates specifications into modular components, database schemas, and algorithms. High cohesion and low coupling are engineered here to ensure maintainability.
3. **Design $\to$ Software Testing:**
   - Architecture directly determines testing strategies: component interfaces guide Integration Testing; functional specifications guide Black-Box System Testing.
4. **Testing $\to$ Quality & Reliability:**
   - Testing measures conformance to requirements and identifies latent defects before delivery. High test coverage directly reduces runtime defect density.
5. **Software Quality vs. Software Reliability:**
   - **Quality:** Degree to which software meets user expectations, standard benchmarks, and functional/non-functional requirements (correctness, efficiency, maintainability).
   - **Reliability:** Probability that software performs its intended functions without failure over a specified time in a specified environment (measured by MTBF — Mean Time Between Failures).

### 3. Core Synthesis & Joint Impact (Mid-1 Key Points)
1. **Testing** finds and eliminates defects before the software is delivered to end-users.
2. **Quality** ensures the software meets user expectations and provides satisfactory, secure performance.
3. **Reliability** ensures the software operates consistently without frequent crashes or unexpected downtime.
4. **Together**, thorough requirements, clean design, and rigorous testing reduce maintenance costs, improve user trust, and increase overall software lifespan.

---

## 8. Lifecycle Model for Student Management System

**Q8. Design a suitable software life-cycle model for a Student Management System (SMS). Justify the selected model and specify the major development activities. (8M)**

### 1. System Overview & Problem Scope
A **Student Management System (SMS)** manages core university operations: Student Admissions, Course Registration, Daily Attendance, Grade Book & Examination Results, and Fee Payment.

### 2. Selected Model: Incremental / Evolutionary Model
- **Justification for Incremental Model:**
  - University operations follow calendar milestones; modules can be deployed sequentially when needed (e.g., Admissions must go live in June, Attendance in August, Examination grading in December).
  - Low organizational disruption: Faculty and administrative staff learn modules incrementally.
  - Reduced risk: Core database tables are tested in early increments before deploying complex financial fee modules.

### 3. Increment Breakdown & Schedule

```
Increment 1: Core Database & Student Admission Module ──► (Deployed Month 2)
Increment 2: Course Registration & Attendance Tracking  ──► (Deployed Month 4)
Increment 3: Marks Entry, GPA Calculation & Transcripts ──► (Deployed Month 6)
Increment 4: Online Fee Payment & Payment Gateway Sync  ──► (Deployed Month 8)
```

### 4. Major Development Activities per Increment
1. **Requirements Specification:** Interviewing university registrars, department heads, and students to define role-based access controls (RBAC) and schema fields.
2. **System Architecture & Database Design:** Building normalized relational schemas (Students, Courses, Enrollments, Grades, Fees) with secure API contracts.
3. **Module Coding:** Developing web interfaces and RESTful backends (e.g., React + Spring Boot/FastAPI + PostgreSQL).
4. **Rigorous Verification:** Role-permission testing, load testing for exam result publication day, and security audits on student financial data.
5. **Deployment & Stakeholder Training:** Live pilot release per department, accompanied by user manuals and feedback collection.
