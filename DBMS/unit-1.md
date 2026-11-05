# UNIT 1 — Database System Concepts & Architecture

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. Three-Schema Architecture

> **Question:** Explain the Three-Schema Architecture and discuss its role in achieving data independence.

---

### Definition

The **Three-Schema Architecture** (also called the **ANSI-SPARC architecture**) is a framework that separates a database into three levels of description so that user applications are isolated from the physical details of storage. Its goal is to support multiple user views, a single integrated logical design, and **data independence**.

### The Three Levels

1. **External Level (View Level):** Describes the part of the database relevant to a particular user or group. Each user group has its own **external schema** (a view). Different users may see different subsets, and the same data may be presented differently (e.g., a student sees only their marks; an accountant sees only fee records).
2. **Conceptual Level (Logical Level):** Describes the structure of the *whole* database for the entire community of users: entities, attributes, relationships, data types, and integrity constraints. There is only **one conceptual schema**, and it hides physical storage details.
3. **Internal Level (Physical Level):** Describes how data is actually stored on disk: file organization, record layout, indexes, access paths, compression, and data placement. There is one **internal schema**.

### Architecture Diagram

```
   User 1 (Student)        User 2 (Faculty)        User 3 (Accountant)
         |                        |                         |
    +----v-----+             +----v-----+              +----v-----+
    |  View 1  |             |  View 2  |              |  View 3  |   EXTERNAL LEVEL
    +----+-----+             +----+-----+              +----+-----+   (Multiple User Views)
         \________________________|________________________/
                                  |
                      +-----------v------------+
                      |    Conceptual Schema   |                      CONCEPTUAL LEVEL
                      | (Tables, Keys, Checks) |                      (Single Logical Schema)
                      +-----------+------------+
                                  |
                      +-----------v------------+
                      |     Internal Schema    |                      INTERNAL LEVEL
                      | (Files, Blocks, B+Tree)|                      (Physical Storage Schema)
                      +-----------+------------+
                                  |
                            [ Disk / OS ]
```

### Role in Achieving Data Independence

**Data independence** is the capacity to change the database schema at one level without forcing modifications to schemas or applications at higher levels. The Three-Schema Architecture provides two types of data independence:

1. **Physical Data Independence:**
   - **Definition:** The ability to modify the internal (physical) schema without having to change the conceptual schema or application programs.
   - **Examples:** Adding or removing a secondary B+ tree index, switching from heap files to sorted files, or moving database files to SSDs.
   - **Benefit:** Storage optimizations and performance tuning do not break existing tables, queries, or application software.

2. **Logical Data Independence:**
   - **Definition:** The ability to alter the conceptual (logical) schema without requiring changes to external schemas (views) or existing application programs.
   - **Examples:** Adding a new column (such as `email` or `phone_number` to `STUDENT`), creating a new table, or splitting an existing table into two.
   - **Benefit:** The database can expand to support new requirements without breaking existing user reports or requiring code rewrites.
   - *Note:* Logical data independence is generally harder to achieve than physical independence because user queries depend directly on table structures and column names.

### Key Advantages

- **Role-Based Security:** Restricts users to only the data they need to see.
- **Ease of Maintenance:** Storage upgrades and schema evolution do not break existing applications.
- **Simplified Programming:** Developers write queries against clear logical tables rather than managing raw disk blocks and pointers.

---

## 2. DBMS Architecture

> **Question:** Describe the architecture of DBMS with a neat diagram and explain the functions of each component.

---

### Overview

A **DBMS architecture** describes the internal modules of a database system and how a user's request travels through them to reach the stored data. The system is organized into three main parts: the **Query Processor**, the **Storage Manager**, and the **Disk Storage**.

### Diagram

```
 Naive users     App programmers     Sophisticated users      DBA
     |                  |                    |                  |
 Application        Application          Query tools        Admin tools
  interfaces        programs (host+DML)  (SQL editor)       (DDL / schema)
     |                  |                    |                  |
     v                  v                    v                  v
+--------------------------------------------------------------------+
|                         QUERY PROCESSOR                            |
|  +--------------+  +--------------+  +-------------------------+   |
|  | DDL          |  | DML          |  | Query Evaluation Engine |   |
|  | Interpreter  |  | Compiler     |  | (+ Query Optimizer)     |   |
|  +--------------+  +--------------+  +-------------------------+   |
+----------------------------------+---------------------------------+
                                   |
+----------------------------------v---------------------------------+
|                         STORAGE MANAGER                            |
|  +-------------------+ +-------------------+ +-----------------+   |
|  | Authorization &   | | Transaction       | | File Manager    |   |
|  | Integrity Manager | | Manager           | |                 |   |
|  +-------------------+ +-------------------+ +-----------------+   |
|                        +-----------------------------------+       |
|                        |          Buffer Manager           |       |
|                        +-----------------------------------+       |
+----------------------------------+---------------------------------+
                                   |
+----------------------------------v---------------------------------+
|                          DISK STORAGE                              |
|   [ Data Files ]   [ Indices ]   [ Data Dictionary / Catalog ]     |
+--------------------------------------------------------------------+
```

### Functions of Each Component

**A. Query Processor**

- **DDL Interpreter:** Interprets schema definition statements (`CREATE`, `ALTER`) and records the definitions in the data dictionary.
- **DML Compiler:** Translates DML statements (such as `SELECT`) into a low-level plan of evaluation that the engine understands. It also invokes the query optimizer.
- **Query Optimizer:** Chooses the cheapest execution plan among many equivalent plans.
- **Query Evaluation Engine:** Executes the low-level instructions produced by the DML compiler.

**B. Storage Manager** (the interface between stored data and queries)

- **Authorization and Integrity Manager:** Checks user permissions and enforces integrity constraints.
- **Transaction Manager:** Ensures the database remains consistent despite failures and that concurrent transactions execute without conflict (ACID).
- **File Manager:** Manages allocation of disk space and the data structures used to represent information on disk.
- **Buffer Manager:** Fetches data from disk into main memory and decides which pages to cache or replace.

**C. Disk Storage**

- **Data files:** The actual database contents.
- **Indices:** Structures that give fast access to records.
- **Data dictionary:** Metadata about tables, columns, constraints, and users.

### Example Flow

For `SELECT name FROM STUDENT WHERE roll_no = 101;` the DML compiler parses and translates the query, the optimizer picks an index scan, the evaluation engine runs the plan, the buffer manager brings the needed page into memory via the file manager, and the result is returned to the user.

---

## 3. Database Users and the Role of the DBA

> **Question:** Explain different types of database users and discuss the responsibilities of the Database Administrator (DBA).

---

### Types of Database Users

1. **Naive (Parametric) Users:** Interact through pre-written application interfaces such as forms and menus, without writing queries. Examples: bank tellers, railway reservation clerks, online shoppers.
2. **Application Programmers:** Write application programs in languages such as Java, Python, or C++ with embedded SQL or APIs (JDBC/ODBC) to build the interfaces used by naive users.
3. **Sophisticated (Casual) Users:** Interact directly using a query language such as SQL, or analytical tools, without writing programs. Examples: data analysts and scientists.
4. **Specialized Users:** Write specialized database applications that do not fit the traditional data-processing framework, such as CAD systems, GIS, and knowledge-base systems.
5. **Database Administrator (DBA):** The person with central control over the DBMS and the data.

### Responsibilities of the DBA

| Responsibility | Description |
|---|---|
| **Schema definition** | Creates the original database schema using DDL |
| **Storage structure and access method definition** | Chooses file organization, indexes, and access paths |
| **Schema and physical organization modification** | Alters the schema or storage when requirements change |
| **Granting authorization** | Decides who may access which data; maintains roles and privileges |
| **Security and integrity enforcement** | Implements constraints, encryption, and auditing |
| **Backup and recovery** | Schedules backups and restores the database after failures |
| **Performance monitoring and tuning** | Monitors response time, adds indexes, and tunes queries |
| **Routine maintenance** | Ensures free disk space, upgrades software, and manages capacity |
| **User liaison** | Works with developers and users to gather requirements and resolve issues |

---

## 4. Comparison of Data Models

> **Question:** Compare the Relational, ER, Object-Oriented, and Semi-Structured data models.

---

### Definition

A **data model** is a collection of concepts used to describe the structure of a database: its data, relationships, semantics, and constraints. Different models suit different purposes.

### Overview of Each Model

- **Relational Model:** Organizes data as **tables (relations)** of rows and columns. Relationships are expressed using keys. Example: `STUDENT(roll_no, name, dept_id)`.
- **Entity-Relationship (ER) Model:** A **conceptual** model that represents the real world as **entities, attributes, and relationships**, drawn as ER diagrams. It is used at the design stage and is later mapped to relational tables.
- **Object-Oriented Model:** Stores data as **objects** that encapsulate both **data (attributes) and behavior (methods)**, with support for classes, inheritance, and complex types.
- **Semi-Structured Model:** Data is self-describing and does not follow a rigid schema; the structure is carried within the data itself using tags or key-value nesting. Examples: **XML** and **JSON**.

### Comparison

| Parameter | Relational | ER | Object-Oriented | Semi-Structured |
|---|---|---|---|---|
| **Basic structure** | Tables of rows and columns | Entities, attributes, relationships | Objects and classes | Trees or graphs of tagged data |
| **Level** | Logical / implementation | Conceptual / design | Logical / implementation | Logical / implementation |
| **Schema** | Fixed, predefined | Defined by diagram | Defined by class definitions | Flexible, schema-less or loose |
| **Relationships** | Foreign keys and joins | Explicit relationship sets | Object references and inheritance | Nesting or references |
| **Query language** | SQL | None (design tool only) | OQL / object APIs | XQuery, JSONPath, document APIs |
| **Data types** | Simple atomic types | Attribute domains | Complex, user-defined types | Mixed and nested |
| **Typical use** | Banking, ERP, enterprise systems | Database design | CAD, multimedia, engineering | Web data, APIs, configuration |

### Example (Same Fact in Three Forms)

- **Relational:** `STUDENT(101, 'Ravi', 'CSE')`
- **Object-Oriented:** `class Student { int roll; String name; String dept; void enroll(); }`
- **Semi-structured (JSON):** `{ "roll": 101, "name": "Ravi", "dept": "CSE", "skills": ["SQL", "Python"] }`

---

## 5. Steps in Database Design

> **Question:** Explain the steps involved in database design with a suitable example.

---

### Definition

**Database design** is the process of creating a structure that accurately stores an organization's data while minimizing redundancy and supporting required queries. It proceeds in well-defined phases.

### Steps

1. **Requirements Analysis:** Collect and document what data must be stored, who uses it, and what operations are needed, by interviewing users and studying existing documents.
2. **Conceptual Design:** Build a high-level model, usually an **ER diagram**, identifying entities, attributes, keys, and relationships, independent of any DBMS.
3. **Logical Design:** Convert the ER model into a **relational schema** (tables, columns, primary and foreign keys) for the chosen DBMS.
4. **Schema Refinement (Normalization):** Analyze functional dependencies and decompose tables to remove redundancy and anomalies (1NF, 2NF, 3NF, BCNF).
5. **Physical Design:** Decide file organization, indexes, partitioning, and storage parameters for performance.
6. **Security Design and Implementation:** Define users, roles, privileges; then create the database, load data, test, and tune.

### Flow Diagram

```
Requirements Analysis
        |
        v
Conceptual Design (ER Diagram)
        |
        v
Logical Design (Relational Schema)
        |
        v
Schema Refinement (Normalization)
        |
        v
Physical Design (Indexes, Storage)
        |
        v
Implementation, Security & Tuning
```

### Example: University Database

- **Requirements:** Track students, courses, and enrollments with grades.
- **Conceptual design:** Entities `STUDENT(roll_no, name)` and `COURSE(course_id, title, credits)`; many-to-many relationship `ENROLLS(grade)`.
- **Logical design:**
  - `STUDENT(roll_no PK, name)`
  - `COURSE(course_id PK, title, credits)`
  - `ENROLLMENT(roll_no FK, course_id FK, grade)` with composite primary key `(roll_no, course_id)`.
- **Refinement:** Check that no table stores repeated course titles inside enrollment records; the schema is already in 3NF.
- **Physical design:** Create an index on `ENROLLMENT(course_id)` to speed up per-course queries.

---

## 6. Parallel and Distributed Databases

> **Question:** Discuss Parallel Databases and Distributed Databases. Compare their architectures and applications.

---

### Parallel Databases

A **parallel database** uses multiple processors and disks working simultaneously inside a single system (or tightly coupled cluster) to improve **throughput** and **response time**. Performance is measured by **speed-up** (same job, more hardware, less time) and **scale-up** (bigger job, more hardware, same time).

**Architectures:**

```
Shared Memory          Shared Disk            Shared Nothing
 P  P  P  P             P    P    P           P--M--D   P--M--D   P--M--D
  \  \ /  /             |    |    |             |          |          |
 [  Memory  ]          M    M    M            [------ Network ------]
      |                 \   |   /
 [ Disks ]              [ Disks ]

Hierarchical: a combination of the above (clusters of shared-memory nodes
connected in a shared-nothing fashion).
```

- **Shared memory:** All processors share common memory and disks. Fast communication, but limited scalability.
- **Shared disk:** Processors have private memory but share all disks. Offers fault tolerance, but disk contention can occur.
- **Shared nothing:** Each node has its own processor, memory, and disk. Highly scalable and widely used.
- **Hierarchical:** Combines the above.

### Distributed Databases

A **distributed database** stores data across multiple **geographically separated sites** connected by a network. Each site is an independent computer with its own DBMS, yet users see a single logical database.

**Key concepts:**

- **Fragmentation:** Splitting a table into pieces (horizontal, vertical, mixed) stored at different sites.
- **Replication:** Keeping copies of data at multiple sites for availability and speed.
- **Transparency:** Location, replication, and fragmentation are hidden from users.
- **Types:** *Homogeneous* (same DBMS at every site) and *heterogeneous* (different DBMSs).

```
   Site A (Hyderabad)        Site B (Chennai)        Site C (Delhi)
   +---------------+         +---------------+       +---------------+
   |  Local DBMS   |<------->|  Local DBMS   |<----->|  Local DBMS   |
   |  Fragment 1   |  Wide   |  Fragment 2   | Area  |  Fragment 3   |
   +---------------+ Network +---------------+       +---------------+
```

### Comparison

| Parameter | Parallel Database | Distributed Database |
|---|---|---|
| **Location** | Single site or tightly coupled cluster | Multiple geographically separate sites |
| **Main goal** | Performance (speed-up, scale-up) | Data sharing, availability, local autonomy |
| **Interconnect** | High-speed local bus or LAN | Slower WAN / internet |
| **Data placement** | Partitioned for balanced parallel processing | Placed near where data is used |
| **Communication cost** | Low | High |
| **Autonomy** | None (one controlled system) | Sites can be autonomous |
| **Failure impact** | Whole system often affected | Other sites continue working |
| **Complexity** | Moderate | High (replication, distributed transactions, 2PC) |

### Applications

- **Parallel:** Data warehousing, large analytical queries, scientific computing, decision support.
- **Distributed:** Banking networks, airline reservation, multinational ERP, e-commerce with regional servers.

---

## 7. NoSQL Databases

> **Question:** Explain NoSQL databases and compare them with Relational databases.

---

### Definition

**NoSQL** ("Not Only SQL") databases are non-relational systems designed for **large-scale, distributed, flexible-schema** data. They sacrifice some relational features (rigid schema, full joins, strict ACID) to gain **horizontal scalability, high availability, and speed** for big data and real-time web applications.

### Characteristics

- Schema-less or flexible schema.
- **Horizontal scaling** by adding more commodity servers (sharding).
- Built-in replication for availability.
- Follow the **BASE** model (Basically Available, Soft state, Eventual consistency) and often the **CAP** trade-off (a distributed system can guarantee only two of Consistency, Availability, Partition tolerance).

### Types of NoSQL Databases

| Type | Structure | Example Systems | Use Case |
|---|---|---|---|
| **Key-Value** | Key mapped to an opaque value | Redis, DynamoDB | Caching, sessions |
| **Document** | JSON/BSON documents | MongoDB, CouchDB | Content management, catalogs |
| **Column-Family** | Columns grouped into families | Cassandra, HBase | Time-series, analytics |
| **Graph** | Nodes and edges | Neo4j | Social networks, recommendations |

**Document example (MongoDB):**

```json
{ "_id": 101, "name": "Ravi", "dept": "CSE", "courses": ["DBMS", "OS"] }
```

### Comparison with Relational Databases

| Parameter | Relational (RDBMS) | NoSQL |
|---|---|---|
| **Data model** | Tables with rows and columns | Key-value, document, column, graph |
| **Schema** | Fixed, predefined | Dynamic, flexible |
| **Query language** | SQL | Varies by database (API-based or query languages) |
| **Scalability** | Vertical (stronger server) | Horizontal (more servers) |
| **Consistency model** | ACID | BASE (eventual consistency) |
| **Joins** | Strong support | Limited or absent |
| **Best for** | Structured data, complex queries, transactions | Big data, unstructured data, high-velocity workloads |
| **Examples** | MySQL, Oracle, PostgreSQL | MongoDB, Redis, Cassandra, Neo4j |

---

## 8. Database System Environment and Client-Server Architecture

> **Question:** Explain the Database System Environment and Client-Server Architecture with neat diagrams.

---

### Database System Environment

A **database system environment** consists of all the components required to build, run, and use a database:

1. **Hardware:** Servers, storage devices, and network equipment.
2. **Software:** The DBMS, operating system, and application programs and tools.
3. **Data:** The operational data and its **metadata** stored in the data dictionary.
4. **Procedures:** Instructions and rules for using and managing the database (backup, login, recovery).
5. **People (Users):** End users, application programmers, and the DBA.

```
 +-----------------------------------------------------------+
 |                 DATABASE SYSTEM ENVIRONMENT               |
 |   People  -->  Application Programs / Query Tools         |
 |                          |                                |
 |                        DBMS Software                      |
 |                          |                                |
 |      Hardware (Server, Disks)  <-->  Data + Metadata      |
 +-----------------------------------------------------------+
```

### Client-Server Architecture

In this architecture, processing is divided between **clients** (which request services) and **servers** (which provide services) connected through a network.

**Two-Tier Architecture:** The client application connects directly to the database server (using ODBC/JDBC). The user interface and application logic run on the client; the DBMS runs on the server.

```
 +----------+        +----------+        +---------------+
 | Client 1 |---+    |          |        |               |
 +----------+   +--->| Network  |------->| Database      |
 +----------+   |    |          |        | Server (DBMS) |
 | Client 2 |---+    +----------+        +---------------+
 +----------+
```

**Three-Tier Architecture:** Adds a middle **application server** that holds the business logic. The client only handles presentation.

```
 +----------------+     +--------------------+     +-----------------+
 | Client         |     | Application Server |     | Database Server |
 | (Browser/App)  |<--->| (Business Logic)   |<--->| (DBMS + Data)   |
 | Presentation   |     | Middle Tier        |     | Data Tier       |
 +----------------+     +--------------------+     +-----------------+
```

### Comparison of Two-Tier and Three-Tier

| Parameter | Two-Tier | Three-Tier |
|---|---|---|
| **Layers** | Client and DB server | Client, application server, DB server |
| **Business logic** | On the client | On the application server |
| **Scalability** | Limited | High |
| **Security** | Client has direct DB access | Database hidden behind the middle tier |
| **Typical use** | Small desktop applications | Web applications and large enterprises |

---

## 9. Levels of Data Abstraction and Data Independence

> **Question:** Explain the levels of data abstraction and discuss logical and physical data independence.

---

> 💡 **Syllabus Note:** This question is the direct equivalent of **[Question 1: Three-Schema Architecture](#1-three-schema-architecture)**. In semester exams, whether phrased as "Three-Schema Architecture" or "Levels of Data Abstraction", the valuation rubric expects the exact same 3-level hierarchy and data independence explanation.

### Definition of Data Abstraction

**Data abstraction** is the technique of hiding complex internal storage details from users, exposing only the structure and data relevant to their role. A DBMS implements abstraction through three levels:

```
   +-------------------------------------------------------+
   |   VIEW LEVEL (Highest)                                |
   |   Custom user views (e.g., student view, clerk view)  |
   +---------------------------+---------------------------+
                               |
   +---------------------------v---------------------------+
   |   LOGICAL LEVEL (Conceptual)                          |
   |   Tables, entities, relationships, and constraints    |
   +---------------------------+---------------------------+
                               |
   +---------------------------v---------------------------+
   |   PHYSICAL LEVEL (Lowest)                             |
   |   Data blocks, file organization, B+ trees, disk      |
   +-------------------------------------------------------+
```

### The Three Levels

1. **Physical Level (Lowest Level):** Describes *how* data is stored physically on disk (e.g., blocks, record layouts, secondary indexes, hashing). Managed by DBAs and storage engines.
2. **Logical Level (Conceptual Level):** Describes *what* data is stored and the relationships among entities (e.g., table definitions, data types, integrity checks). Hides raw hardware details.
3. **View Level (Highest Level):** Describes only a specific subset of the database for individual user groups to simplify interaction and enforce role-based security.

### Data Independence Summary

Data independence is the capability to modify the schema at one level without breaking the schema or programs at higher levels:

| Parameter | Physical Data Independence | Logical Data Independence |
|---|---|---|
| **Level Affected** | Between Physical and Logical levels | Between Logical and View levels |
| **Example Change** | Adding a B+ tree index, moving to SSD storage | Adding a new column `email` or splitting a table |
| **Impact on Users** | Zero impact on queries or application code | Views and existing queries remain unaffected |
| **Ease of Achievement** | High (natively supported by DBMS) | Moderate to difficult (queries depend on table schema) |

*(For full worked diagrams and detailed explanations, refer to [Question 1](#1-three-schema-architecture).)*

---

## 10. Applications, Need and Purpose of DBMS; DBMS vs File System

> **Question:** Discuss the applications, need, and purpose of DBMS. Compare DBMS with the traditional file processing system.

---

### Definition

A **Database Management System (DBMS)** is software that allows users to define, create, maintain, and control access to a database, which is an organized collection of related data.

### Need and Purpose

Traditional file systems suffer from several problems that a DBMS is designed to solve:

1. **Data redundancy and inconsistency:** The same data is duplicated across files, and copies may disagree. A DBMS centralizes data.
2. **Difficulty in accessing data:** Each new query needs a new program. A DBMS provides SQL for ad-hoc queries.
3. **Data isolation:** Data is scattered in different formats across files. A DBMS gives a uniform structure.
4. **Integrity problems:** Constraints are buried inside application code. A DBMS enforces them declaratively.
5. **Atomicity problems:** Failures leave partial updates. A DBMS provides transactions and recovery.
6. **Concurrent access anomalies:** Simultaneous updates can corrupt data. A DBMS uses concurrency control.
7. **Security problems:** File systems offer coarse access control. A DBMS offers fine-grained privileges.

### Applications of DBMS

- **Banking:** Accounts, transactions, loans.
- **Airlines and railways:** Reservations and schedules.
- **Universities:** Registration, results, fee records.
- **E-commerce:** Products, orders, payments.
- **Healthcare:** Patient records and billing.
- **Telecommunications:** Call records and billing.
- **Social media:** Profiles, posts, connections.
- **Manufacturing and retail:** Inventory and supply chain.

### Comparison: DBMS vs File Processing System

| Parameter | File Processing System | DBMS |
|---|---|---|
| **Data redundancy** | High | Controlled and minimal |
| **Data consistency** | Hard to maintain | Maintained through constraints |
| **Data independence** | None; programs depend on file format | Provided (logical and physical) |
| **Data sharing** | Difficult | Easy and controlled |
| **Security** | Limited | Strong, role-based |
| **Concurrency** | Not supported properly | Supported via locking and scheduling |
| **Backup and recovery** | Manual | Automatic mechanisms |
| **Querying** | Requires custom programs | Standard query language (SQL) |
| **Cost** | Low initial cost | Higher initial cost, lower long-term cost |
