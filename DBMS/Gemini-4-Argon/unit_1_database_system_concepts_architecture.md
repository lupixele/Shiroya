# UNIT 1 — Database System Concepts & Architecture

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. Three-Schema Architecture & Data Independence
> **Question:** Explain the Three-Schema Architecture and discuss its role in achieving data independence.

---

### Definition
The **Three-Schema Architecture** (proposed by ANSI/SPARC) is a database design framework that separates user applications from the physical database by dividing the system into three distinct schema levels. A **database schema** is the formal description of the database structure, whereas a **database state** (or instance) is the actual data stored at a specific moment in time.

### Diagram: Three-Schema Architecture
```text
      [ End Users / Application Views ]
        |             |             |
  +-----------+ +-----------+ +-----------+
  | External  | | External  | | External  |   <-- External Level
  |  View A   | |  View B   | |  View C   |       (Individual User Views)
  +-----------+ +-----------+ +-----------+
        \             |             /
         \   External / Conceptual /
          \        Mapping        /
           v          v          v
      +-------------------------------+
      |       Conceptual Schema       |       <-- Conceptual Level
      |  (Logical Community Structure)|           (Entities, Data Types,
      +-------------------------------+            Relationships, Constraints)
                      |
             Conceptual / Internal
                   Mapping
                      v
      +-------------------------------+
      |        Internal Schema        |       <-- Internal Level
      |   (Physical Storage Details)  |           (Files, Indexes, Blocks)
      +-------------------------------+
                      |
                      v
             ( Stored Database )              <-- Physical Disk Storage
```

### The Three Schema Levels
1. **External Level (View Level):** This highest level includes a number of external schemas or user views. Each external schema describes only the subset of the database relevant to a particular user group while hiding the remaining database details.
2. **Conceptual Level (Logical Level):** This middle level has a conceptual schema that describes the global logical structure of the entire database for the whole community of users. It specifies entities, data types, relationships, user operations, and constraints while hiding physical storage details.
3. **Internal Level (Physical Level):** This lowest level has an internal schema that describes how data is physically stored on disk. It defines file organizations, record layouts, byte offsets, compression, indexes, and access paths.

### Mappings and Role in Achieving Data Independence
The DBMS translates requests and results between the three levels using **schema mappings**, which directly enable **Data Independence**—the capacity to modify the schema at one level of a database system without having to change the schema at the next higher level.

* **Logical Data Independence:** It is the capacity to change the conceptual schema without having to change external schemas or rewrite application programs.
  * **Modifications Supported:** Expanding the database by adding a new attribute (such as `Email` to a `STUDENT` table), adding a new entity, or splitting/merging existing relations.
  * **Role of Mapping:** Only the **External/Conceptual Mapping** and view definitions need to be updated by the DBA so existing external views continue to see the exact same virtual table structure.
* **Physical Data Independence:** It is the capacity to change the internal schema without having to alter the conceptual schema (or external schemas).
  * **Modifications Supported:** Moving data files to a new storage drive, creating or dropping a B+ Tree index, or switching file organization from sequential heap files to hashing.
  * **Role of Mapping:** The DBMS updates only the **Conceptual/Internal Mapping** while logical queries, views, and table definitions remain completely unaffected.

### Example
Consider a university database with a conceptual relation `STUDENT(RollNo, Name, DeptID, CGPA)`:
* **Internal Level:** Records are stored in fixed-length binary blocks sorted by `RollNo` with a B+ Tree index on `DeptID`.
* **Conceptual Level:** Defines the table structure `STUDENT(RollNo, Name, DeptID, CGPA)` and `DEPARTMENT(DeptID, DeptName)`.
* **External Level:** Library staff only need student identification and department details, hiding sensitive academic grades via a SQL View:

```sql
CREATE VIEW Library_Student_View AS
SELECT RollNo, Name, DeptID
FROM STUDENT;
```

---

## 2. DBMS Architecture & Component Functions
> **Question:** Describe the architecture of DBMS with a neat diagram and explain the functions of each component.

---

### Definition
The **DBMS Architecture** is a modular software framework that acts as an interface between database users and physical disk storage. It is divided into two primary operational subsystems—the **Query Processor** and the **Storage Manager**—which coordinate with main memory buffers and disk structures to execute queries and transactions safely.

### Diagram: Overall DBMS Architecture
```text
 +-------------------------------------------------------------------+
 | Naive Users   Application Programmers   Sophisticated Users   DBA |
 +------+-------------------+----------------------+--------------+--+
        |                   |                      |              |
   [App Interfaces]   [App Programs]         [Query Tools]   [Admin Tools]
        |                   |                      |              |
 =======+===================+======================+==============+===
 |                        QUERY PROCESSOR                            |
 |                                                                   |
 |  +-----------------------+           +-------------------------+  |
 |  |     DML Compiler      |           |     DDL Interpreter     |  |
 |  +-----------+-----------+           +------------+------------+  |
 |              |                                    |               |
 |              v                                    |               |
 |  +-----------------------+                        |               |
 |  |   Query Evaluation    |                        |               |
 |  |        Engine         |                        |               |
 |  +-----------+-----------+                        |               |
 ===============|====================================|===============+
 |              |          STORAGE MANAGER           |               |
 |              v                                    |               |
 |  +-----------------------+  +------------------+  |               |
 |  |  Buffer Manager       |  | Transaction Mgr  |  |               |
 |  +-----------------------+  +------------------+  |               |
 |  |  File Manager         |  | Auth & Integrity |  |               |
 |  +-----------+-----------+  +--------+---------+  |               |
 ===============|=======================|============|===============+
                |                       |            |
                v                       v            v
 +-------------------------------------------------------------------+
 |                        DISK STORAGE                               |
 |   [ Data Files ]    [ Data Dictionary ]    [ Indices ]    [Log]   |
 +-------------------------------------------------------------------+
```

### 1. Query Processor Components
The **Query Processor** accepts high-level declarative SQL statements from users and translates them into low-level file system execution plans.

* **DDL Interpreter:** Interprets Data Definition Language statements (such as `CREATE`, `ALTER`, and `DROP`) and records the schema definitions inside the system catalog (Data Dictionary).
* **DML Compiler:** Parses Data Manipulation Language statements (`SELECT`, `INSERT`, `UPDATE`, `DELETE`) and translates them into an evaluation plan consisting of low-level relational algebra instructions.
* **Query Optimizer:** Examines multiple candidate evaluation plans using system catalog statistics and selects the most cost-efficient execution plan to minimize disk I/O and CPU time.
* **Query Evaluation Engine:** Executes the low-level instructions generated by the DML compiler and optimizer by requesting pages from the Storage Manager.

### 2. Storage Manager Components
The **Storage Manager** is the program module that provides the interface between the low-level data stored on disk and the application programs and queries submitted to the system.

* **Authorization and Integrity Manager:** Tests for the satisfaction of integrity constraints (such as `PRIMARY KEY` and `FOREIGN KEY` rules) and verifies the authority of users to access or modify data.
* **Transaction Manager:** Ensures that the database remains in a consistent (correct) state despite system failures and ensures that concurrent transaction executions proceed without conflicting with one another.
* **File Manager:** Manages the allocation of space on disk storage and maintains the underlying data structures used to represent information stored on disk.
* **Buffer Manager:** Responsible for fetching data blocks from disk storage into main memory (RAM) and deciding what data to cache in memory to speed up processing.

### 3. Disk Storage Structures
The Storage Manager implements several physical data structures on disk:

* **Data Files:** Store the actual database relations and user tuples.
* **Data Dictionary (System Catalog):** Stores metadata about the structure of the database, in particular the schema of tables, constraints, views, and user permissions.
* **Indices:** Provide fast access paths (such as B+ Trees or hash indexes) to locate data items holding particular values without scanning entire data files.
* **Statistical Data and Logs:** Store data distribution metrics used by the query optimizer alongside write-ahead logs (`WAL`) required for crash recovery.

---

## 3. Database Users & DBA Responsibilities
> **Question:** Explain different types of database users and discuss the responsibilities of the Database Administrator (DBA).

---

### Definition
People who work with a database environment are categorized into **Database Users**, who interact with the system to retrieve or modify information, and **Database Administrators (DBAs)**, who maintain central control over both the data and the programs that access that data.

### Diagram: Database User Hierarchy
```text
                    +-------------------------------+
                    |      DBMS Software System     |
                    +---------------+---------------+
                                    |
        +------------------+--------+--------+------------------+
        |                  |                 |                  |
        v                  v                 v                  v
+---------------+  +---------------+ +---------------+  +---------------+
|  Naive Users  |  |  Application  | | Sophisticated |  |  Specialized  |
| (Forms/ATMs)  |  |  Programmers  | | Users (SQL)   |  | Users (CAD)   |
+---------------+  +---------------+ +---------------+  +---------------+
```

### Types of Database Users
1. **Naive Users (Parametric End Users):** Unsophisticated users who interact with the system by invoking one of the application programs that have been written previously. They operate through simple form interfaces or mobile apps without writing SQL.
   * **Example:** A bank teller performing a deposit or a student checking semester results via a web portal.
2. **Application Programmers:** Computer professionals who write application programs and user interfaces using host programming languages (Java, Python, C#) that communicate with the DBMS via APIs like JDBC or ODBC.
   * **Example:** A software developer writing the course registration module for a university ERP system.
3. **Sophisticated Users (Data Analysts):** Engineers, scientists, and business analysts who interact with the system without writing custom programs. Instead, they form their requests directly in a database query language (`SQL`) or use OLAP data analysis tools.
   * **Example:** A financial analyst executing complex `GROUP BY` and `JOIN` queries to audit departmental spending.
4. **Specialized Users:** Sophisticated users who write specialized database applications that do not fit into the traditional data-processing framework.
   * **Example:** Users building Computer-Aided Design (CAD) systems, Geographic Information Systems (GIS), or expert knowledge-base systems.

### Responsibilities of the Database Administrator (DBA)
The **Database Administrator (DBA)** is the person or team with central control over the database system. The primary functions and responsibilities of a DBA include:

* **Schema Definition:** The DBA creates the original database schema by executing a set of Data Definition Language (DDL) statements.
* **Storage Structure and Access-Method Definition:** The DBA defines physical file organizations, tablespaces, and primary/secondary indexes to optimize disk I/O performance.
* **Schema and Physical-Organization Modification:** The DBA carries out changes to the schema and physical organization to reflect the changing needs of the organization or to alter physical storage for better performance.
* **Granting of Authorization for Data Access:** By granting different types of authorization (`GRANT` and `REVOKE`), the DBA regulates which parts of the database various users can access.
* **Routine Maintenance:** The DBA performs essential operational tasks including:
  * Periodically backing up the database onto remote servers or tapes to prevent data loss.
  * Ensuring that enough free disk space is available for normal operations and upgrading disk space as required.
  * Monitoring jobs running on the database and ensuring that performance is not degraded by expensive user tasks.
* **Crash Recovery:** In the event of hardware failure, power outage, or software corruption, the DBA restores the database to a consistent state using backup snapshots and transaction logs.

### Example: DBA Authorization Commands
```sql
-- Granting read and insert privileges on STUDENT table to faculty role
GRANT SELECT, INSERT ON STUDENT TO 'faculty_user'@'localhost';

-- Revoking delete privileges from the same user
REVOKE DELETE ON STUDENT FROM 'faculty_user'@'localhost';
```

---

## 4. Comparison of Data Models
> **Question:** Compare the Relational, ER, Object-Oriented, and Semi-Structured data models.

---

### Definition
A **Data Model** is a collection of conceptual tools for describing data, data relationships, data semantics, and consistency constraints. A data model provides a way to describe the design of a database at the physical, logical, and view levels.

### Overview of the Four Data Models
1. **Relational Data Model:** Uses a collection of two-dimensional tables (called **relations**) to represent both data and the relationships among those data. Each table has multiple columns (**attributes**) with unique names, and each row is a **tuple**.
2. **Entity-Relationship (ER) Data Model:** Uses a collection of basic objects, called **entities**, and **relationships** among these objects. An entity is a real-world object distinguishable from other objects, widely used in conceptual database design.
3. **Object-Oriented Data Model:** Extends the ER model with notions of **encapsulation**, **methods** (functions), and **object identity**. It combines features of object-oriented programming with relational database principles.
4. **Semi-Structured Data Model:** Permits the specification of data where individual data items of the same type may have different sets of attributes. Self-describing formats like **XML** and **JSON** are widely used to represent semi-structured data.

### Structural Representation Examples
```text
1. RELATIONAL MODEL (Table: STUDENT)
+--------+--------+--------+
| RollNo | Name   | Dept   |
+--------+--------+--------+
| 101    | Arjun  | CSE    |
+--------+--------+--------+

2. ER MODEL
[ STUDENT ] ----< ( Enrolled_In ) >---- [ COURSE ]

3. OBJECT-ORIENTED MODEL
Class Student {
  int RollNo;
  string Name;
  float calculateCGPA();
}

4. SEMI-STRUCTURED MODEL (JSON)
{ "RollNo": 101, "Name": "Arjun", "Skills": ["SQL", "Python"] }
```

### Comparison Table
| Parameter | Relational Model | ER Model | Object-Oriented Model | Semi-Structured Model |
| :--- | :--- | :--- | :--- | :--- |
| **Level of Abstraction** | Logical / Representational | Conceptual / High-Level | Logical / Object-Level | Physical / Flexible Logical |
| **Basic Building Block** | Relation (Table), Tuple, Attribute | Entity, Attribute, Relationship | Object, Class, Method | Tree Node / Key-Value Document |
| **Schema Flexibility** | Strictly predefined, rigid schema | Fixed conceptual blueprint | Fixed class hierarchy | Schema-less or self-describing |
| **Relationship Representation** | Foreign Keys matching Primary Keys | Diamond relationship links | Object Identifiers (OIDs) / Pointers | Nested hierarchy elements |
| **Query Language** | Structured Query Language (`SQL`) | None (Graphical design tool) | Object Query Language (`OQL`) | `XPath`, `XQuery`, `JSONPath` |
| **Data Encapsulation** | Data only (No methods stored in row) | Data attributes only | Encapsulates data and methods | Data attributes and nested arrays |
| **Primary Application** | Banking, ERP, and OLTP systems | Initial conceptual DB design | CAD, multimedia, and GIS | Web APIs, NoSQL, and IoT logs |

---

## 5. Steps in Database Design
> **Question:** Explain the steps involved in database design with a suitable example.

---

### Definition
**Database Design** is the structured engineering process of determining the logical and physical organization of a database to satisfy the information and processing requirements of an organization while eliminating data redundancy and anomalies.

### Diagram: Database Design Phases
```text
  [ 1. Requirements Collection & Analysis ]
                      |
                      v
  [ 2. Conceptual Database Design (ER Model) ]
                      |
                      v
  [ 3. Logical Database Design (Relational Mapping) ]
                      |
                      v
  [ 4. Schema Refinement (Normalization) ]
                      |
                      v
  [ 5. Physical Database Design (Indexes/Files) ]
                      |
                      v
  [ 6. Application & Security Design ]
```

### Phases of Database Design
1. **Requirements Collection and Analysis:** Database designers interview prospective users to understand and document their data requirements, functional requirements (user-defined operations/transactions), and business constraints.
2. **Conceptual Database Design:** The information gathered in the requirements phase is used to develop a high-level description of the data using the **Entity-Relationship (ER) Model**. It focuses on defining entities, attributes, relationships, and cardinalities independent of any physical DBMS.
3. **Logical Database Design (Data Model Mapping):** The conceptual ER schema is translated into the implementation data model of the chosen commercial DBMS—most commonly mapping entities and relationships into **Relational Schemas** (tables, primary keys, and foreign keys).
4. **Schema Refinement (Normalization):** The relational schemas produced in the logical design phase are analyzed for potential problems such as data redundancy and update/insertion/deletion anomalies using **Functional Dependencies** and normal forms (`1NF`, `2NF`, `3NF`, `BCNF`).
5. **Physical Database Design:** Designers consider typical query workloads and specify internal storage structures, file organizations (heap, sequential, hashed), partitioning, and **B+ Tree indexes** to guarantee high performance.
6. **Application and Security Design:** Software modules that interact with the database are designed, and role-based access rules, views, and encryption policies are configured to enforce data security.

### Suitable Example: University Course Management System
* **Step 1 (Requirements Analysis):** The university needs to store details of students, courses, and departments. Each department has a unique name and building, and offers multiple courses.
* **Step 2 (Conceptual ER Design):** Identify two main entities: `COURSE(CourseID, Title)` and `DEPARTMENT(DeptName, Building)` connected by a $N:1$ relationship `OFFERED_BY`.
* **Step 3 (Logical Mapping):** Suppose an initial unrefined mapping combines them into a single table:
  * `COURSE_DEPT(CourseID, Title, DeptName, Building)`
* **Step 4 (Schema Refinement / Normalization):** In `COURSE_DEPT`, the functional dependency $\text{DeptName} \rightarrow \text{Building}$ causes redundancy because `Building` is repeated for every course offered by the same department. Decompose into two `3NF` relations:
  * `DEPARTMENT(DeptName PK, Building)`
  * `COURSE(CourseID PK, Title, DeptName FK)`
* **Step 5 (Physical Design):** Implement the tables in SQL and add a secondary index on `DeptName` for fast join performance:

```sql
CREATE TABLE DEPARTMENT (
    DeptName VARCHAR(50) PRIMARY KEY,
    Building VARCHAR(50) NOT NULL
);

CREATE TABLE COURSE (
    CourseID INT PRIMARY KEY,
    Title VARCHAR(100) NOT NULL,
    DeptName VARCHAR(50),
    FOREIGN KEY (DeptName) REFERENCES DEPARTMENT(DeptName)
);

CREATE INDEX idx_course_dept ON COURSE(DeptName);
```

* **Step 6 (Security Design):** Create views and grant `SELECT` access to students while restricting `INSERT` and `UPDATE` rights to the Academic Dean role.

---

## 6. Parallel vs. Distributed Databases
> **Question:** Discuss Parallel Databases and Distributed Databases. Compare their architectures and applications.

---

### Definition
* **Parallel Database System:** A database system that seeks to improve processing and I/O performance through parallelization of various operations (such as loading data, building indexes, and evaluating queries) across multiple tightly coupled CPUs and disks within a single facility.
* **Distributed Database System (DDBS):** A database system in which the database is stored across several computers (sites) at different geographic locations that communicate with one another over a network (LAN or WAN) and do not share main memory or disks.

### 1. Parallel Database Architectures
```text
SHARED-MEMORY            SHARED-DISK              SHARED-NOTHING
[CPU] [CPU] [CPU]       [CPU]   [CPU]   [CPU]    [CPU]    [CPU]    [CPU]
  |     |     |          |       |       |        |        |        |
 [Shared Memory]        [RAM]   [RAM]   [RAM]    [RAM]    [RAM]    [RAM]
        |                 \       |       /        |        |        |
  [Shared Disks]           [Shared Disks]        [Disk]   [Disk]   [Disk]
                                                   \========|========/
                                                    High-Speed Network
```

* **Shared-Memory Architecture:** All processors share a common main memory and common disk array over a high-speed bus. It provides extremely fast communication between processors, but is not scalable beyond 32 or 64 processors because the memory bus becomes a bottleneck.
* **Shared-Disk Architecture:** All processors have their own private memory, but share a common set of disks over an interconnection network. If one processor fails, the others can still access all data on the shared disks.
* **Shared-Nothing Architecture:** Each node consists of a processor, its own private main memory, and its own local disk storage. Nodes communicate strictly via high-speed message passing. It can easily scale to thousands of nodes.
* **Key Performance Metrics:**
  * **Speedup:** Running a given task in less time by increasing the degree of parallelism ($\text{Speedup} = \frac{T_{\text{small}}}{T_{\text{large}}}$).
  * **Scaleup:** Ability to process larger tasks in the same amount of time by providing more resources ($\text{Scaleup} = \frac{T_{\text{small\_system\_small\_task}}}{T_{\text{large\_system\_large\_task}}}$).

### 2. Distributed Database Architectures
```text
             [ Global Communication Network (WAN/Internet) ]
              /                     |                     \
             v                      v                      v
     +---------------+      +---------------+      +---------------+
     |  Site 1 (HYD) |      |  Site 2 (BLR) |      |  Site 3 (DEL) |
     |  [Local DBMS] |      |  [Local DBMS] |      |  [Local DBMS] |
     |  (Local DB)   |      |  (Local DB)   |      |  (Local DB)   |
     +---------------+      +---------------+      +---------------+
```

* **Homogeneous Distributed Database:** All sites have identical database management system software, are aware of one another, and agree to cooperate in processing user requests under a unified global schema.
* **Heterogeneous Distributed Database:** Different sites may use different schemas and different DBMS software (e.g., Oracle at Site 1 and PostgreSQL at Site 2), requiring middleware translation layers.
* **Distributed Data Storage Methods:**
  * **Replication:** The system maintains multiple identical copies of a relation across different sites to increase availability and parallel read speed.
  * **Fragmentation:** A relation is partitioned into several fragments—either **horizontally** (splitting rows by branch) or **vertically** (splitting columns)—and stored at different sites.

### Comparison Table
| Parameter | Parallel Database | Distributed Database |
| :--- | :--- | :--- |
| **Geographic Location** | Nodes are located in a single room/rack | Sites are geographically separated across cities |
| **Interconnection Network** | High-speed local system bus or switch | Wide Area Network (WAN) or public internet |
| **Communication Speed** | Extremely high bandwidth, microsecond latency | Lower bandwidth, higher network latency |
| **Primary Objective** | High query throughput, speedup, and scaleup | Local autonomy, data sharing, high availability |
| **Impact of Single Node Failure** | May stall query execution across the cluster | Remaining geographic sites continue operating |
| **Administration** | Managed centrally by a single DBA team | Local site DBAs plus a global DBA |
| **Applications** | Data warehousing, OLAP, scientific analytics | Multi-branch banking, global airline reservations |

---

## 7. NoSQL Databases vs. Relational Databases
> **Question:** Explain NoSQL databases and compare them with Relational databases.

---

### Definition
**NoSQL ("Not Only SQL") Databases** are a class of non-relational database management systems designed to store, retrieve, and manage massive volumes of unstructured and semi-structured data with flexible schemas, horizontal scalability across commodity clusters, and high availability.

### Core Characteristics of NoSQL Databases
* **Schema-less / Dynamic Schema:** Records can be inserted without predefined table structures, and each record can hold different attributes.
* **Horizontal Scalability (Scale-Out):** Capacity is increased by adding more commodity servers to a distributed cluster (sharding) rather than upgrading to a single expensive mainframe.
* **BASE Consistency Model:** Instead of strict ACID transactions, NoSQL systems frequently follow the **BASE** model:
  * **Basically Available:** The database guarantees availability even during partial node failures.
  * **Soft State:** Replica states may change over time without direct user input due to background synchronization.
  * **Eventual Consistency:** All replicas across the cluster eventually converge to the same state once updates cease.

### Four Major Types of NoSQL Databases
```text
1. KEY-VALUE STORE               2. DOCUMENT STORE (JSON)
+----------+--------------+      {
| Key      | Value        |        "_id": "S101",
+----------+--------------+        "name": "Kiran",
| user:101 | "{cart:[5]}" |        "courses": ["DBMS", "OS"]
+----------+--------------+      }

3. COLUMN-FAMILY                 4. GRAPH DATABASE
[RowKey: 101]                    (User: Kiran) ---[FOLLOWS]---> (User: Ravi)
  |-- Profile: {Name:Kiran}
  |-- Grades:  {DBMS:92}
```

1. **Key-Value Stores:** The simplest NoSQL model where every item is stored as a unique key paired with an arbitrary value blob.
   * *Examples:* Redis, Amazon DynamoDB. *Use Case:* User session caching, shopping carts.
2. **Document Databases:** Store data as self-describing documents (in JSON, BSON, or XML formats) grouped into collections. Documents can contain nested objects and arrays.
   * *Examples:* MongoDB, CouchDB. *Use Case:* Product catalogs, content management systems.
3. **Column-Family (Wide-Column) Stores:** Store data tables by column families rather than by rows, enabling ultra-fast aggregation and write throughput across distributed clusters.
   * *Examples:* Apache Cassandra, HBase. *Use Case:* IoT sensor telemetry, time-series logs.
4. **Graph Databases:** Represent data as a network of **nodes** (entities) and **edges** (relationships with properties), optimizing multi-hop relationship traversal.
   * *Examples:* Neo4j, Amazon Neptune. *Use Case:* Social networks, recommendation engines, fraud detection.

### Comparison Table
| Parameter | Relational Databases (RDBMS) | NoSQL Databases |
| :--- | :--- | :--- |
| **Data Storage Model** | Structured tables with rows and columns | Key-Value, Document, Column-Family, Graph |
| **Schema Rigidity** | Strict, predefined static schema required | Dynamic, flexible, schema-less |
| **Scalability Strategy** | Vertical scaling (Scale-Up CPU/RAM on one server) | Horizontal scaling (Scale-Out across server nodes) |
| **Transaction Guarantee** | Strict **ACID** properties (Atomicity, Consistency, etc.) | **BASE** properties (Eventual consistency) |
| **Data Relationships** | Normalized across tables and combined via `JOIN` | Denormalized via nested documents or graph edges |
| **Query Language** | Standardized declarative SQL | Vendor-specific APIs, JSON queries, Cypher |
| **Ideal Workload** | Banking ledgers, ERP, complex transactional joins | Big Data, real-time web apps, IoT, social graphs |

---

## 8. Database System Environment & Client-Server Architecture
> **Question:** Explain the Database System Environment and Client-Server Architecture with neat diagrams.

---

### Definition
A **Database System Environment** comprises the DBMS software, underlying hardware, operating system, stored database, system catalog, utilities, and user interfaces. Modern enterprise environments deploy the DBMS using **Client-Server Architectures** that divide workload responsibilities between front-end client machines and back-end server machines.

### 1. Database System Environment & Utilities
In addition to the core DBMS compiler and storage modules, a complete database environment includes system utilities that help the DBA manage the system:
* **Loading Utility:** Loads existing data files (such as flat text files or sequential CSV files) directly into the database structure.
* **Backup Utility:** Creates a backup copy of the database by dumping the entire database state onto tape or cloud storage to protect against catastrophic disk failure.
* **Database Storage Reorganization Utility:** Reorganizes a set of database files into different file organizations and reclaims fragmented space to improve performance.
* **Performance Monitoring Utility:** Monitors database usage, buffer hit ratios, and lock waits, providing statistical reports to the DBA.

### Diagram: Two-Tier vs. Three-Tier Client-Server Architecture
```text
   TWO-TIER ARCHITECTURE                 THREE-TIER ARCHITECTURE

  +-----------------------+             +-----------------------+
  |      Client Tier      |             |      Client Tier      |
  | (GUI + Business Logic)|             | (Web Browser / Mobile)|
  +-----------+-----------+             +-----------+-----------+
              |                                     |
              | ODBC / JDBC                         | HTTP / REST / HTTPS
              | (SQL Requests)                      v
              |                         +-----------------------+
              |                         |   Application Tier    |
              |                         | (Business Logic / API)|
              |                         +-----------+-----------+
              |                                     |
              v                                     | Connection Pool (JDBC)
  +-----------------------+                         v
  +-----------------------+             +-----------------------+
  |     Database Tier     |             |     Database Tier     |
  |     (DBMS Server)     |             |     (DBMS Server)     |
  +-----------------------+             +-----------------------+
```

### 2. Two-Tier Client-Server Architecture
In a **Two-Tier Architecture**, the application is partitioned into two components: the **Client** and the **Database Server**.
* **Working Mechanism:** User interface programs and application business logic run on the client side. When data access is required, the client program establishes a direct network connection to the DBMS server using **ODBC** (Open Database Connectivity) or **JDBC** (Java Database Connectivity) APIs.
* **Execution:** The client sends SQL statements to the server, and the server executes the query and ships the resulting tuples back to the client.
* **Limitations:** Poor scalability when the number of clients exceeds a few hundred (due to connection exhaustion) and security vulnerabilities because clients connect directly to the database server.

### 3. Three-Tier Client-Server Architecture
In a **Three-Tier Architecture**, an intermediate layer called the **Application Server (or Web Server)** is added between the client and the database server.
1. **Presentation Tier (Client):** The client machine contains only the graphical user interface (such as a web browser or mobile app) and handles user input/output without storing business rules or direct DB credentials.
2. **Application Tier (Middle Tier):** Houses the business logic, validates client requests, manages security authentication, and maintains a pool of persistent connections to the database.
3. **Database Tier (Data Server):** Runs the DBMS software to execute SQL transactions and manage physical storage, completely isolated from direct external user traffic by a firewall.

### Comparison Table
| Parameter | Two-Tier Architecture | Three-Tier Architecture |
| :--- | :--- | :--- |
| **Number of Layers** | Two (Client and Database Server) | Three (Client, App Server, Database Server) |
| **Business Logic Location** | Resides on the Client workstation | Resides on the central Application Server |
| **Security** | Lower (Direct network path from client to DB) | High (DB server is hidden behind App Server) |
| **Scalability** | Limited due to direct per-client DB connections | High scalability via middle-tier connection pooling |
| **Software Maintenance** | Difficult (Updates must be installed on all clients) | Easy (Business logic updated centrally on App Server) |
| **Typical Example** | Desktop LAN billing software | E-commerce portals, net banking, university ERP |

---

## 9. Levels of Data Abstraction & Data Independence
> **Question:** Explain the levels of data abstraction and discuss logical and physical data independence.

---

### Definition
A major purpose of a database system is to provide users with an abstract view of the data. That is, the system hides certain technical details of how the data are physically stored and maintained on hardware disks. This hiding of complexity through layered representations is called **Data Abstraction**.

### Diagram: Three Levels of Data Abstraction
```text
      +-------------------+   +-------------------+   +-------------------+
      |      View 1       |   |      View 2       |   |     View ... n    |
      | (Registrar View)  |   |  (Student View)   |   |  (Accounts View)  |
      +---------+---------+   +---------+---------+   +---------+---------+
                \                       |                       /
                 +----------------------+----------------------+
                                        |
                                        v
                   +-----------------------------------------+
                   |              LOGICAL LEVEL              |
                   |  Tables, Columns, Data Types, Keys      |
                   +--------------------+--------------------+
                                        |
                                        v
                   +-----------------------------------------+
                   |             PHYSICAL LEVEL              |
                   |  Byte Offsets, Disk Blocks, B+ Trees    |
                   +-----------------------------------------+
```

### The Three Levels of Data Abstraction
1. **Physical Level (Lowest Level):** The lowest level of abstraction describes **how** the data are actually stored on physical storage media. The physical level describes complex low-level data structures in detail, such as byte offsets, disk block allocations, index pointers, and file organizations (heap, sequential, or hashing).
2. **Logical Level (Middle Level):** The next-higher level of abstraction describes **what** data are stored in the database, and what relationships exist among those data. The logical level describes the entire database in terms of a small number of relatively simple structures (such as relational tables, columns, data types, and foreign keys). Database administrators (`DBAs`) primarily work at this level.
3. **View Level (Highest Level):** The highest level of abstraction describes **only part** of the entire database. Even though the logical level uses simpler structures, complexity remains because of the variety of information stored in a large enterprise database. Many users do not need all this information; instead, they access tailored views that simplify interaction and hide confidential attributes.

### Example Illustrating the Three Levels
Consider an `EMP` relation storing employee details:
```sql
CREATE TABLE EMP (
    EmpID INT PRIMARY KEY,
    EmpName VARCHAR(50),
    Dept VARCHAR(30),
    Salary DECIMAL(10, 2)
);
```
* **Physical Level:** Describes `EMP` as a consecutive block of bytes stored on disk cylinder 120 with a B+ Tree index built on `EmpID`.
* **Logical Level:** Defines the table structure with four fields (`EmpID`, `EmpName`, `Dept`, `Salary`) and their domain constraints.
* **View Level:** A payroll clerk sees all four columns, whereas an office receptionist accesses a view displaying only `(EmpID, EmpName, Dept)`, hiding the sensitive `Salary` attribute.

### Logical and Physical Data Independence
**Data Independence** is the ability to modify a schema definition in one level without affecting a schema definition in the next higher level.

* **Physical Data Independence:**
  * **Definition:** The ability to modify the physical schema (Physical Level) without requiring any rewrite of the logical schema or application programs.
  * **Examples of Changes:** Switching from a sequential file to a B+ Tree index, partitioning a file across two SSDs, or compressing disk blocks to improve I/O speed.
  * **Complexity:** Relatively easy to achieve because the DBMS storage manager isolates physical file pointers from SQL queries.
* **Logical Data Independence:**
  * **Definition:** The ability to modify the logical schema (Logical Level) without causing existing external views or application programs to be rewritten.
  * **Examples of Changes:** Adding a new column `BloodGroup` to the `EMP` table or adding a new `PROJECT` table to the database.
  * **Complexity:** Harder to achieve than physical data independence because application programs are heavily dependent on the logical structure of the data they access.

---

## 10. Purpose of DBMS vs. File Processing System
> **Question:** Discuss the applications, need, and purpose of DBMS. Compare DBMS with the traditional file processing system.

---

### Definition
A **Database Management System (DBMS)** is a collection of interrelated data and a set of programs to access and manage those data in a convenient and efficient manner. Prior to the invention of DBMS software, organizations stored data in **Traditional File Processing Systems** managed directly by the host operating system.

### Major Applications of DBMS
* **Banking and Finance:** Storing customer information, account balances, loan schedules, and daily ATM/UPI banking transactions.
* **Airlines:** Managing flight schedules, fare pricing, and real-time seat reservations across geographically distributed terminals.
* **Universities:** Maintaining student enrollments, course registrations, faculty allocations, and academic grades.
* **E-Commerce and Retail:** Tracking product catalogs, real-time warehouse stock levels, customer orders, and payment gateways.
* **Telecommunications:** Keeping records of millions of calls made, generating monthly bills, and maintaining balances on prepaid calling cards.

### Need and Purpose of DBMS (Drawbacks of File Processing System)
Keeping organizational information in a traditional file-processing system has seven major disadvantages, which explain the fundamental need and purpose of a DBMS:

1. **Data Redundancy and Inconsistency:** Since different programmers create different files over time, the same information may be duplicated in several files (e.g., a student's address stored in both `Hostel.dat` and `Accounts.txt`). This redundancy leads to higher storage costs and **data inconsistency** when an update is applied to one file but not the others.
2. **Difficulty in Accessing Data:** Conventional file-processing environments do not allow needed data to be retrieved in a convenient and efficient manner. Every new ad-hoc query requires a programmer to write a brand-new procedural application program.
3. **Data Isolation:** Because data are scattered in various files, and files may be in different formats (CSV, binary, fixed-width), writing new application programs to retrieve the appropriate combined data is difficult.
4. **Integrity Problems:** The data values stored in the database must satisfy certain types of consistency constraints (e.g., $\text{Balance} \ge 0$). In a file system, constraints are buried inside procedural code across multiple programs rather than being enforced centrally.
5. **Atomicity Problems:** A computer system is subject to mid-operation crashes. In a fund transfer of Rs. 1,000 from Account A to Account B, a crash during file writing can leave Rs. 1,000 deducted from A without being credited to B. A DBMS ensures **atomicity** (all-or-nothing execution).
6. **Concurrent-Access Anomalies:** When multiple users update the same file simultaneously without coordination, race conditions can overwrite updates and leave the file in an incorrect state. A DBMS coordinates concurrent access using locking protocols.
7. **Security Problems:** Not every user of the database system should be able to access all the data. Operating system file permissions only secure entire files, whereas a DBMS enforces fine-grained security at the table, column, and row levels.

### Architecture Contrast Diagram
```text
TRADITIONAL FILE SYSTEM                   DBMS APPROACH
[App A] ---> [Accounts.dat]               [App A] \
[App B] ---> [Library.csv]                [App B] --> [ DBMS Engine ] --> (Central DB)
[App C] ---> [Hostel.txt]                 [App C] /
(Duplicated data, isolated files)         (Single repository, unified control)
```

### Comparison Table
| Parameter | Traditional File Processing System | Database Management System (DBMS) |
| :--- | :--- | :--- |
| **Data Redundancy** | High data duplication across independent files | Minimal redundancy controlled via normalization |
| **Data Consistency** | Prone to update anomalies and inconsistent copies | High consistency enforced via central constraints |
| **Data Independence** | None (Changing file structure breaks code) | Provides both Logical and Physical independence |
| **Data Access / Querying** | Requires writing custom procedural programs (C/COBOL) | Fast, ad-hoc retrieval using declarative `SQL` |
| **Atomicity & Recovery** | No automatic crash recovery; partial writes corrupt files | Guaranteed atomicity and automated log recovery |
| **Concurrency Control** | Concurrent writes cause race condition anomalies | Managed safely via ACID transaction locking |
| **Security Granularity** | Coarse OS file-level read/write permissions | Fine-grained views and role-based access (`GRANT`) |