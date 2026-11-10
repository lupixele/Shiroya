# Unit 1: Software Process & Classical Life Cycle Models — Worked Exam Answers

> **Questions File:** [`questions.md` — Unit 1](questions.md#unit-i--software-process--classical-life-cycle-models)

---

## 1. Software Process and Software Engineering Practice

> **Question:** Describe the Software Process and Software Engineering Practice. Discuss the major activities involved in a software process.

### 1. Introduction

**Software Engineering** is a systematic, disciplined and measurable approach to the development, operation and maintenance of software. It applies engineering principles to produce reliable, efficient and quality software within the planned time and budget.

A **software process** is a set of related activities followed to develop and maintain a software product. It provides an organized way to convert user needs into working software.

### 2. Software Process

A software process defines:
- What activities must be performed.
- Who is responsible for each activity.
- What inputs and outputs are required.
- How the work is planned, monitored and controlled.
- How the quality of the software is checked.

### 3. Major activities of a software process

**1. Communication / Requirements gathering**
- Developers communicate with customers and users.
- They understand the problem, goals, needs and limitations.
- Requirements are collected, analyzed and documented.
- Example: For a college management system, collect requirements for student registration, attendance and marks.

**2. Planning**
- The project scope and objectives are identified.
- Time, cost, people and other resources are estimated.
- Tasks, milestones and schedules are prepared.
- Risks that may affect the project are identified.

**3. Modeling**
- The requirements are converted into a design or model.
- The system architecture, database, interfaces and components are planned.
- Diagrams such as use-case, class, flow and data-flow diagrams may be prepared.
- Modeling helps developers understand how the system should work before coding.

**4. Construction**
- Developers write the program code based on the design.
- The code is compiled and errors are corrected.
- Unit and integration testing are performed to identify defects.
- The software is built into a working product.

**5. Deployment**
- The completed software is delivered or installed for users.
- Users are trained and feedback is collected.
- Errors or improvement requests are recorded.
- Updates and maintenance may follow.

### 4. Software Engineering Practice

Software engineering practice means applying systematic methods and technical principles while developing software. It includes understanding the problem, planning, designing, coding, testing and maintaining the product.

Important practice activities include:
- Understanding the problem and requirements.
- Planning the development work.
- Designing a suitable solution.
- Developing and testing the software.
- Delivering the product and collecting feedback.

### 5. Importance
- Improves software quality and reliability.
- Helps control project cost and schedule.
- Reduces development risks and errors.
- Makes teamwork and communication easier.
- Supports maintenance and future changes.

### 6. Conclusion

A software process gives a clear structure for software development. Software engineering practice applies suitable methods at every stage to produce useful, reliable and maintainable software.

**Memory trick: C--P--M--C--D = "Cool People Make Code Daily"**
- **C** — Communication
- **P** — Planning
- **M** — Modeling
- **C** — Construction
- **D** — Deployment

Remember the flow: **Ask → Plan → Design → Build → Deliver.**
---
## 2. Phased Development Life Cycle

> **Question:** Illustrate the Phased Development Life Cycle with its major phases and suitable examples.

### 1. Introduction

The **Phased Development Life Cycle** is a software development approach in which the complete system is divided into smaller phases or increments. Each phase develops and delivers a usable part of the software. The system grows step by step until all required features are completed.

### 2. Major phases

**1. Requirements analysis**
- Identify the purpose and scope of the software.
- Collect requirements from users.
- Separate essential features from optional features.
- Example: For a library system, identify login, book search, issue and return requirements.

**2. Planning**
- Divide the project into manageable phases.
- Estimate time, cost and resources for each phase.
- Decide which features should be developed first.
- Prepare a schedule for each increment.

**3. Design**
- Design the overall system architecture.
- Plan the database, user interface and modules.
- Decide how the different phases will connect.
- Example: Design student, book and transaction tables for a library system.

**4. Development / Implementation**
- Code the features selected for the current phase.
- Build one working part of the system.
- Keep the design suitable for adding later features.

**5. Testing**
- Test the developed features to find errors.
- Check whether each feature meets its requirements.
- Test whether new features work with previously completed parts.

**6. Deployment and feedback**
- Release the completed phase to users.
- Collect feedback about usability and missing features.
- Use the feedback to plan the next phase.

**7. Maintenance and further development**
- Correct defects and improve existing features.
- Add the remaining features in later phases.
- Continue until the complete system is delivered.

### 3. Example: Library Management System

The system can be developed in the following increments:

| Phase / Increment | Features Delivered |
|:---:|---|
| **Increment 1** | User login and student registration |
| **Increment 2** | Book search and book details |
| **Increment 3** | Book issue and return |
| **Increment 4** | Fine calculation and payment records |
| **Increment 5** | Reports and recommendations |

After each increment, the working features are tested and may be given to users. Feedback is used to improve later increments.

### 4. Advantages
- Working software is delivered early.
- The project is easier to manage in smaller parts.
- User feedback can be included in later phases.
- Problems can be identified earlier.
- Changing requirements can be handled more easily than in a single final delivery.

### 5. Limitations
- Good planning is needed to divide the system into phases.
- Integration between phases can be difficult.
- The overall architecture must support future additions.
- Repeated testing and integration may require extra effort.

### 6. Conclusion

The Phased Development Life Cycle develops software through planned, manageable increments. It allows users to receive useful features early and helps the development team improve the system gradually.

**Memory trick: R--P--D--D--T--D--M = "Really Prepared Developers Test, Deliver, Maintain"**
- Requirements, Planning, Design, Development, Testing, Deployment, Maintenance.

For the example, remember **Library = Login → Search → Issue/Return → Fine → Reports.**

---

## 3. Waterfall Model: Phases, Advantages, Limitations

> **Question:** Analyze the Waterfall Model with respect to its phases, advantages, limitations, and suitable applications.

### 1. Introduction

The **Waterfall Model** is a traditional software development life-cycle model in which development moves through a sequence of phases. Each phase is generally completed before the next phase begins. The output of one phase becomes the input to the next phase.

### 2. Phases of the Waterfall Model

**1. Requirement analysis**
- Collect and document all customer requirements.
- Understand what the system must do.
- Prepare a requirement specification.

**2. System design**
- Convert requirements into a technical design.
- Plan system architecture, database, modules and interfaces.
- Decide how the software will be implemented.

**3. Implementation / Coding**
- Developers write code according to the design.
- The system may be divided into smaller modules.
- Each module is developed and checked.

**4. Integration and testing**
- Combine the developed modules.
- Test the complete system to identify defects.
- Verify that the software satisfies the requirements.

**5. Deployment**
- Install and release the software to users.
- Provide necessary instructions or training.

**6. Maintenance**
- Correct errors found after delivery.
- Adapt the software to changes in its environment.
- Improve performance or add necessary updates.

### 3. Simple flow diagram

``` text
Requirements
     ↓
System Design
     ↓
Implementation
     ↓
Integration & Testing
     ↓
Deployment
     ↓
Maintenance
```

### 4. Advantages
- Simple and easy to understand.
- Phases and deliverables are clearly defined.
- Easy to plan and monitor when requirements are stable.
- Documentation is produced at each stage.
- Suitable for projects with clear and fixed requirements.

### 5. Limitations
- Difficult to accommodate changing requirements after a phase is completed.
- Working software is usually available late in the project.
- Testing occurs after implementation, so defects may be discovered late.
- Returning to an earlier phase can be costly.
- Users may not see the complete working product until late.

### 6. Suitable applications

The Waterfall Model is suitable when:
- Requirements are clear, complete and unlikely to change.
- The project uses familiar technology.
- The project is small or has a well-defined scope.
- Strong documentation and formal approvals are required.

**Example:** A simple payroll system with fixed rules and clearly documented requirements may use the Waterfall Model.

### 7. Conclusion

The Waterfall Model follows a linear sequence of development phases. It is easy to manage when requirements are stable, but it is less suitable for projects where requirements change frequently.

**Memory trick: R--D--I--T--D--M = "Requirements Design, Implement, Test, Deliver, Maintain."**

For the exam, remember the four parts of analysis: **Phases + Advantages + Limitations + Applications.**

---

## 4. Spiral Model and Risk Analysis

> **Question:** Examine the Spiral Model and discuss how risk analysis influences its different iterations.

### 1. Introduction

The **Spiral Model** is a risk-driven software development model that combines iterative development with systematic risk analysis. The project is developed through repeated cycles called spirals. Each cycle produces progress and helps plan the next cycle.

It is especially useful for large, complex and high-risk projects.

### 2. Four major activities in each spiral

**1. Determine objectives, alternatives and constraints**
- Identify the goals of the current iteration.
- List possible approaches to achieve those goals.
- Identify limitations such as cost, time and technology.

**2. Identify and analyze risks**
- Identify possible problems that may affect the project.
- Estimate their probability and impact.
- Evaluate alternatives and prepare ways to reduce risks.
- A prototype or experiment may be developed to understand uncertain requirements or technology.

**3. Develop and verify the next-level product**
- Design and implement the selected solution.
- Test the developed part.
- Verify that the iteration meets its objectives.

**4. Plan the next iteration**
- Review the results with stakeholders.
- Decide whether to continue, change direction or stop.
- Prepare objectives and plans for the next spiral.

### 3. How risk analysis influences iterations

Risk analysis is the central feature of the Spiral Model.
- **High technical risk:** A prototype or technical experiment may be developed before full implementation.
- **Unclear requirements:** The team may build a prototype and obtain user feedback.
- **Budget risk:** Cost estimates are reviewed before committing to the next iteration.
- **Schedule risk:** Difficult tasks and dependencies are examined to reduce delays.
- **Security or safety risk:** Important risks are studied and tested early.

Each iteration is planned according to the risks discovered in the previous cycle. Therefore, the development path can change when new risks or information appear.

### 4. Example: Online Banking System
- First spiral: Identify user needs and risks related to login.
- Second spiral: Prototype secure authentication and test it.
- Third spiral: Develop account and transaction features while analyzing transaction risks.
- Fourth spiral: Test security, reliability and performance before wider release.

### 5. Advantages
- Risks are identified and handled early.
- Suitable for large and complex projects.
- Supports changing requirements.
- Users can provide feedback during development.
- Prototypes help clarify uncertain requirements.

### 6. Limitations
- Risk analysis requires skilled people.
- The model can be expensive and time-consuming.
- It may be difficult to manage many iterations.
- It is not ideal for small, low-risk projects.

### 7. Conclusion

The Spiral Model develops software through repeated cycles, with risk analysis guiding every iteration. It is useful when the project has high uncertainty, complex requirements or major risks.

**Memory trick: O--R--D--P = "Our Risks Decide Progress."**
- **O** — Objectives
- **R** — Risk analysis
- **D** — Development and verification
- **P** — Planning the next iteration

Key phrase to remember: **Spiral = Iteration + Risk Analysis.**
---
## 5. Evolutionary Model vs. Waterfall Model

> **Question:** Compare the Evolutionary Model with the Waterfall Model with respect to handling changing requirements and software delivery.

### 1. Introduction

The **Waterfall Model** follows a sequential process in which one phase is completed before the next begins. The **Evolutionary Model** develops software through repeated versions, improving the product using feedback and changing requirements.

### 2. Evolutionary Model
- A basic version of the software is developed first.
- Users evaluate the version and provide feedback.
- Requirements and features are improved in later versions.
- The process continues until the software meets user needs.

### 3. Comparison

---
| Basis | Waterfall Model | Evolutionary Model |
|---|---|---|
| **Development** | Sequential phases | Repeated versions or iterations |
| **Requirements** | Expected to be clear early | Can change during development |
| **User feedback** | Usually limited after initial requirements | Collected throughout development |
| **Delivery** | Usually delivered after major phases are completed | Early and repeated versions can be delivered |
| **Changes** | Changes can be costly | Changes can be included in later versions |
| **Testing** | Often concentrated after implementation | Testing is repeated as the product evolves |
| **Flexibility** | Less flexible | More flexible |
| **Risk** | Some problems may appear late | Feedback can reveal problems earlier |

### 4. Example

**Waterfall -- Payroll System:**
- Salary rules and requirements are collected first.
- Design, coding and testing are completed in sequence.
- The system is delivered after the planned development phases.

**Evolutionary -- Online Shopping Application:**
- First version: User registration and login.
- Second version: Product search and product details.
- Third version: Shopping cart and ordering.
- Fourth version: Payment and order tracking.
- User feedback is used to improve each version.

### 5. Advantages of the Evolutionary Model
- Supports changing requirements.
- Provides working software earlier.
- Encourages regular user feedback.
- Helps improve the product gradually.
- Important features can be prioritized.

### 6. Limitations of the Evolutionary Model
- Overall cost and completion time may be difficult to predict.
- Frequent changes may affect the system structure.
- Continuous customer involvement is needed.
- Without proper design, the software may become difficult to maintain.

### 7. Conclusion

The Waterfall Model is suitable when requirements are stable and clearly defined. The Evolutionary Model is more suitable when requirements are uncertain or likely to change because it develops the product through repeated versions and feedback.

**Memory trick: Waterfall = FIXED; Evolutionary = FLEXIBLE.**

Remember these five comparison words: **Development, Requirements, Feedback, Delivery, Changes.**

---

## 6. Software Project Management: Planning and Estimation

> **Question:** Demonstrate the major activities involved in Software Project Management, including project planning and estimation.

### 1. Introduction

**Software Project Management (SPM)** is the process of planning, organizing, monitoring and controlling software development activities to complete a project within the expected time, budget and quality.

A software project manager coordinates people, resources, tasks and risks to achieve project objectives.

### 2. Major activities of Software Project Management

**1. Project planning**
- Define the project objectives and scope.
- Identify the tasks required to complete the project.
- Decide the project schedule and milestones.
- Assign responsibilities to team members.
- Identify resources and possible risks.

**2. Project estimation** Estimation predicts the effort, time, cost and resources needed.

It includes:
- **Effort estimation:** Estimate the amount of work or person-hours/person-months required.
- **Time estimation:** Estimate how long the project will take.
- **Cost estimation:** Estimate expenses such as salaries, software and equipment.
- **Resource estimation:** Estimate the number of people and tools required.

Common estimation approaches include expert judgment, analogy with previous projects and size-based estimation techniques.

**3. Resource management**
- Select suitable team members.
- Assign tasks based on skills.
- Arrange hardware, software and other resources.
- Ensure resources are used effectively.

**4. Risk management**
- Identify possible risks such as technical problems, staff shortages and delays.
- Analyze their probability and impact.
- Prepare plans to avoid or reduce risks.
- Monitor risks throughout the project.

**5. Scheduling and task allocation**
- Divide the project into smaller tasks.
- Set start dates, end dates and milestones.
- Identify task dependencies.
- Allocate work to team members.

**6. Monitoring and control**
- Compare actual progress with the project plan.
- Track time, cost, quality and completed work.
- Identify delays or problems.
- Take corrective action when necessary.

**7. Quality management and communication**
- Set quality standards and review work.
- Coordinate communication among team members and customers.
- Share progress reports and important decisions.
- Ensure that the final product meets requirements.

### 3. Example: Student Management System

For an SMS project:
- Planning: Decide to develop registration, attendance and marks modules.
- Estimation: Estimate the developers, time and cost needed.
- Scheduling: Assign dates for each module.
- Risk management: Plan for database failure or changing requirements.
- Monitoring: Check weekly progress and correct delays.
- Quality management: Test each module before release.

### 4. Importance
- Helps complete projects on time.
- Controls cost and resource usage.
- Reduces project risks.
- Improves teamwork and communication.
- Helps deliver quality software.

### 5. Conclusion

Software Project Management ensures that software development is properly planned, estimated, organized and monitored. Project planning and estimation are essential for completing the project successfully.

**Memory trick: P--E--R--R--S--M--Q = "Plan Estimates, Resources, Risks, Schedule, Monitor Quality."**
- Planning
- Estimation
- Resource management
- Risk management
- Scheduling
- Monitoring
- Quality and communication

For estimation, remember **E--T--C--R: Effort, Time, Cost, Resources.**
---
## 7. Relationship Among Requirements, Design, Testing, Quality, and Reliability

> **Question:** Analyze the relationship among requirements gathering, software design, software testing, software quality, and reliability.

### 1. Introduction

Requirements gathering, software design, testing, quality and reliability are connected activities in software engineering. Each activity supports the next one and contributes to the development of a successful software product.

### 2. Requirements gathering
- It is the process of collecting user needs and expectations.
- Developers communicate with customers and users.
- Functional and non-functional requirements are identified.
- Requirements form the basis for design and testing.

**Example:** In a Student Management System, requirements may include student registration, attendance, marks and report generation.

### 3. Software design
- Design converts requirements into a technical plan.
- It defines system architecture, database structure, modules and interfaces.
- A good design helps developers implement the correct features.
- Design should consider performance, security, maintainability and reliability.

**Example:** Design separate modules for student details, attendance and examination records.

### 4. Software testing
- Testing checks whether the developed software works correctly.
- It identifies defects and verifies that requirements are satisfied.
- Unit testing checks individual modules.
- Integration testing checks communication between modules.
- System and acceptance testing check the complete system and user needs.

**Example:** Test whether attendance is correctly saved and displayed for the selected student.

### 5. Software quality

Software quality is the degree to which software satisfies stated and implied requirements.

Important quality characteristics include:
- Correctness and functionality.
- Usability.
- Efficiency and performance.
- Maintainability.
- Security and reliability.

Quality is influenced by good requirements, good design, disciplined coding and effective testing.

### 6. Software reliability

Software reliability is the ability of software to perform its required functions without failure for a specified period under specified conditions.

Factors influencing reliability include:
- Correct and complete requirements.
- Good system design.
- Fewer coding defects.
- Effective testing.
- Proper error handling and maintenance.

### 7. Relationship among the five concepts

``` text
Requirements Gathering
          ↓
     Software Design
          ↓
   Coding / Development
          ↓
    Software Testing
          ↓
   Software Quality
          ↓
  Reliable Software
```

The relationship is continuous:
- Correct requirements help create a suitable design.
- Good design makes implementation easier and reduces defects.
- Testing detects defects and checks whether requirements are met.
- Quality activities ensure that the software meets expected standards.
- Reliability is improved when defects and failure causes are reduced.

If requirements are incomplete, the design may be incorrect. If the design is poor, testing may reveal many defects. If testing is insufficient, low-quality and unreliable software may be delivered.

### 8. Conclusion

Requirements gathering, design, testing, quality and reliability are interdependent. Careful work at every stage helps produce software that satisfies users and operates correctly and consistently.

**Memory trick: R--D--T--Q--R = "Requirements Design, Testing, Quality, Reliability."**

Remember the connection: **Know what is needed → Plan how to build it → Check it → Ensure quality → Improve reliability.**

---

## 8. Lifecycle Model for Student Management System

> **Question:** Design a suitable software life-cycle model for a Student Management System (SMS). Justify the selected model and specify the major development activities.

### 1. Introduction

A **Student Management System (SMS)** is software used by an educational institution to manage student information and academic activities. It may include student registration, attendance, marks, fees and report generation.

A suitable life-cycle model should support development in manageable stages and allow feedback from users such as students, faculty and administrators.

### 2. Selected model: Phased Development / Incremental approach

The Phased Development Life Cycle is suitable for an SMS because the system can be divided into modules and delivered in increments. Each increment provides a working set of features, and later increments add more functionality.

### 3. Justification for selecting the model
- The SMS contains several independent but connected modules.
- Basic features can be delivered before advanced features.
- Faculty and administrators can provide feedback after each release.
- Errors can be identified and corrected during development.
- New requirements can be considered in later increments.
- The project can be divided into smaller tasks, making it easier to manage.

### 4. Major development activities

**1. Requirements gathering** Meet students, faculty and administrators to identify requirements.

Possible functional requirements:
- Student registration and profile management.
- Attendance management.
- Marks and examination records.
- Fee details.
- Report generation.

Possible non-functional requirements:
- Security and privacy.
- Easy-to-use interface.
- Reliable data storage.
- Good performance.

**2. Planning**
- Define the project scope and objectives.
- Divide the system into increments.
- Estimate time, cost and resources.
- Assign tasks and prepare a schedule.

**3. System design**
- Design the overall architecture.
- Design the database tables and relationships.
- Prepare user interfaces.
- Define modules and access permissions.

**4. Development in increments**

| Increment | Module / Features |
|:---:|---|
| **1** | Login and user management |
| **2** | Student registration and profile |
| **3** | Attendance management |
| **4** | Marks and examination management |
| **5** | Fee management and reports |

**5. Testing**
- Unit test each module.
- Integration test connected modules.
- System test the complete SMS.
- Acceptance test with faculty or administrators.
- Perform regression testing after changes.

**6. Deployment**
- Install the system in the institution.
- Create user accounts and configure access.
- Import required student data.
- Train users and release the system.

**7. Maintenance**
- Correct errors reported by users.
- Improve performance and security.
- Update features according to institutional needs.
- Back up and protect student records.

### 5. Simple life-cycle diagram

``` text
Requirements and Planning
          ↓
     Overall Design
          ↓
  Increment 1: Login
          ↓
  Increment 2: Student Details
          ↓
  Increment 3: Attendance
          ↓
  Increment 4: Marks
          ↓
  Increment 5: Fees and Reports
          ↓
 Testing, Deployment and Maintenance
```

Each increment should be designed, developed and tested before or as it is integrated with the existing system.

### 6. Conclusion

The Phased Development Life Cycle is a suitable choice for a Student Management System because it supports modular development, early delivery, regular feedback and gradual improvement. It helps the institution receive useful features while the remaining modules are being developed.

**Memory trick: SMS = L--S--A--M--F--R**
- **L** — Login
- **S** — Student details
- **A** — Attendance
- **M** — Marks
- **F** — Fees
- **R** — Reports

For the model justification, remember **M--F--E--T**:
- **M** — Modular system
- **F** — Feedback after increments
- **E** — Early delivery
- **T** — Testing in stages

---
## Quick Revision — Unit 1

### Eight questions in one line

| Q.No. | Main Topic | Memory Trick |
|:---:|---|---|
| **1** | Software Process and Practice | C–P–M–C–D |
| **2** | Phased Development Life Cycle | R–P–D–D–T–D–M |
| **3** | Waterfall Model | R–D–I–T–D–M |
| **4** | Spiral Model | O–R–D–P |
| **5** | Evolutionary vs Waterfall | Fixed vs Flexible |
| **6** | Software Project Management | P–E–R–R–S–M–Q |
| **7** | Requirements to Reliability | R–D–T–Q–R |
| **8** | Student Management System | L–S–A–M–F–R |

### Important diagrams to practise

1.  Software process: Communication → Planning → Modeling → Construction → Deployment.
2.  Phased development: show successive increments and feedback.
3.  Waterfall: draw the six phases in a vertical sequence.
4.  Spiral: draw a spiral with objectives, risk analysis, development and planning.
5.  SMS: show the increments from login to reports.

### Exam-writing strategy for 8 marks
- Start with a clear definition and introduction.
- Use numbered headings for phases, activities, advantages and limitations.
- Explain each point in 2--3 meaningful sentences.
- Add a neat diagram for life-cycle model questions.
- Add a relevant example wherever asked.
- End with a short conclusion.
- Use the memory trick to recall the headings, not as a replacement for the explanation.

**Revision tip:** First learn the definition and headings. Then close the notes and try to reproduce the headings from memory. Finally, explain each heading in your own simple words.

---
