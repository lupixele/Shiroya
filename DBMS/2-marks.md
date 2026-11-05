# Database Management Systems (2501IT05) — 2-Marks Notes

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section A (2-Mark Compulsory Questions — All 5 Units)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## UNIT I — Database System Concepts & Architecture

### Q1. Define a Database Management System.

A **Database Management System (DBMS)** is software that allows users to **define, create, store, retrieve, update and manage** data in a database while providing security, integrity and concurrent access.

- It acts as an interface between the users/applications and the physical database.
- Examples: MySQL, Oracle, PostgreSQL, SQL Server.

### Q2. List any four advantages of DBMS over traditional file systems.

- **Reduced data redundancy and inconsistency:** Data is stored centrally, so duplicate copies are minimized.
- **Data independence:** Application programs are not affected by changes in storage structure or file format.
- **Data integrity and security:** Integrity constraints and access control (authorization) protect the data.
- **Concurrent access and crash recovery:** Multiple users can work simultaneously, and the DBMS restores data after failures.

### Q3. List the three levels of data abstraction.

- **Physical (Internal) level:** Describes *how* data is actually stored on disk (files, indexes, blocks).
- **Logical (Conceptual) level:** Describes *what* data is stored and the relationships among them (tables, attributes, constraints).
- **View (External) level:** Describes only the part of the database relevant to a particular user, hiding the rest.

### Q4. Define data independence.

**Data independence** is the ability to **modify the schema at one level of the database without having to change the schema at the next higher level.**

- **Physical data independence:** Changing the physical schema (e.g., adding an index) does not affect the logical schema.
- **Logical data independence:** Changing the logical schema (e.g., adding a column) does not affect external views or application programs.

### Q5. Define a spatial database.

A **spatial database** is a database optimized to store and query **spatial (geometric) data** such as points, lines, polygons and maps, along with their locations and relationships.

- It supports spatial data types and operations such as *distance*, *overlap* and *within*, using spatial indexes like R-trees.
- Example: GIS applications, Google Maps — `SELECT * FROM CITY WHERE ST_Distance(location, :p) < 10;` (PostGIS).

### Q6. Define a temporal database.

A **temporal database** stores data along with its **time dimension**, so that both the current and the past (or future) states of data can be recorded and queried.

- **Valid time:** When a fact is true in the real world.
- **Transaction time:** When the fact was recorded in the database.
- Example: Storing an employee's salary history with `start_date` and `end_date` for each salary value.

---

## UNIT II — Relational Model, Relational Algebra & SQL

### Q1. Define the relational model.

The **relational model** represents data as a collection of **relations (tables)**, where each relation consists of **rows (tuples)** and **columns (attributes)**, and relationships are expressed through common attribute values (keys).

- Proposed by **E. F. Codd (1970)**; it is based on set theory and predicate logic.
- Example: `STUDENT(RollNo, Name, Dept, CGPA)` is a relation with each row a student tuple.

### Q2. Define a primary key.

A **primary key** is a **minimal set of attributes** chosen from the candidate keys that **uniquely identifies each tuple** in a relation.

- It cannot contain **NULL** values and must be unique.
- A relation has only one primary key.
- Example: `RollNo` in `STUDENT(RollNo, Name, Dept)`.

### Q3. Define a candidate key.

A **candidate key** is a **minimal super key**, i.e., an attribute (or set of attributes) that uniquely identifies tuples and from which no attribute can be removed without losing uniqueness.

- A relation can have several candidate keys; one is chosen as the primary key and the others are called alternate keys.
- Example: In `STUDENT(RollNo, Email, Name)`, both `RollNo` and `Email` are candidate keys.

### Q4. List the fundamental operations of relational algebra.

- **Select (σ):** Chooses tuples satisfying a condition — `σ Dept='CSE'(STUDENT)`.
- **Project (π):** Chooses specified attributes (columns) — `π Name, Dept(STUDENT)`.
- **Union (∪):** Tuples present in either of two compatible relations.
- **Set difference (−):** Tuples in the first relation but not in the second.
- **Cartesian product (×):** Combines every tuple of one relation with every tuple of another.
- **Rename (ρ):** Renames a relation or its attributes.

### Q5. List the DML commands.

**Data Manipulation Language (DML)** commands are used to retrieve and modify data stored in tables:

- **SELECT:** Retrieves data from one or more tables.
- **INSERT:** Adds new rows — `INSERT INTO STUDENT VALUES (1,'Ravi','CSE');`
- **UPDATE:** Modifies existing rows — `UPDATE STUDENT SET Dept='IT' WHERE RollNo=1;`
- **DELETE:** Removes rows — `DELETE FROM STUDENT WHERE RollNo=1;`

### Q6. State the difference between the WHERE and HAVING clauses.

| Basis | WHERE | HAVING |
|---|---|---|
| Purpose | Filters **individual rows** | Filters **groups** produced by GROUP BY |
| Execution time | Applied **before** grouping | Applied **after** grouping |
| Aggregate functions | Cannot be used directly | Can be used (`COUNT`, `SUM`, `AVG`, etc.) |
| Example | `WHERE Salary > 20000` | `HAVING AVG(Salary) > 20000` |

---

## UNIT III — ER Model, Views, Integrity & Subqueries

### Q1. List the different types of attributes in ER Model.

- **Simple (atomic) attribute:** Cannot be divided further — e.g., `Age`.
- **Composite attribute:** Can be divided into sub-parts — e.g., `Name` → `FirstName`, `LastName`.
- **Single-valued attribute:** Holds one value per entity — e.g., `RollNo`.
- **Multivalued attribute:** Can hold multiple values — e.g., `PhoneNumbers`.
- **Derived attribute:** Value is computed from other attributes — e.g., `Age` from `DOB`.
- **Key attribute:** Uniquely identifies an entity — e.g., `EmpID`.

### Q2. Define an ER diagram.

An **Entity-Relationship (ER) diagram** is a **graphical representation of the logical structure of a database**, showing the **entities, their attributes and the relationships** among them.

- **Rectangle** = entity, **Ellipse** = attribute, **Diamond** = relationship, **Lines** = connections.
- Example: `STUDENT —(enrolls)— COURSE` with cardinality M:N.

### Q3. Define an updatable view.

An **updatable view** is a view through which **INSERT, UPDATE and DELETE** operations can be performed, and the changes are reflected in the underlying base table.

- It is normally defined on a **single table**, without `DISTINCT`, `GROUP BY`, aggregate functions or set operations, and it includes the primary key of the base table.
- Example: `CREATE VIEW CSE_STUDENTS AS SELECT RollNo, Name FROM STUDENT WHERE Dept='CSE';`

### Q4. State the difference between specialization and generalization.

| Basis | Specialization | Generalization |
|---|---|---|
| Approach | **Top-down** | **Bottom-up** |
| Process | Divides a higher-level entity into lower-level sub-entities based on distinguishing features | Combines lower-level entities with common features into a higher-level entity |
| Result | Creates subclasses | Creates a superclass |
| Example | `EMPLOYEE` → `MANAGER`, `ENGINEER` | `CAR`, `TRUCK` → `VEHICLE` |

### Q5. Define referential integrity.

**Referential integrity** is a constraint ensuring that a **foreign key value in one relation must either be NULL or match an existing primary key value** in the referenced relation.

- It prevents "dangling" references to non-existent tuples.
- Example: `EMP.DeptNo` must exist in `DEPT.DeptNo`.

```sql
FOREIGN KEY (DeptNo) REFERENCES DEPT(DeptNo)
```

### Q6. Define a correlated subquery.

A **correlated subquery** is a nested subquery that **refers to columns of the outer query** and is therefore **executed once for each row** processed by the outer query.

- It cannot be evaluated independently of the outer query.
- Example: Employees earning more than the average of their own department:

```sql
SELECT E1.Name FROM EMP E1
WHERE E1.Salary > (SELECT AVG(E2.Salary) FROM EMP E2
                   WHERE E2.DeptNo = E1.DeptNo);
```

---

## UNIT IV — Normalization, Keys & Transaction Management

### Q1. Define normalization.

**Normalization** is the process of **organizing relations to minimize data redundancy and eliminate insertion, update and deletion anomalies** by decomposing them into smaller, well-structured relations based on functional dependencies.

- Progressive normal forms: **1NF, 2NF, 3NF, BCNF**, and so on.
- Example: Splitting `STUDENT(RollNo, Name, DeptNo, DeptName)` into `STUDENT(RollNo, Name, DeptNo)` and `DEPT(DeptNo, DeptName)`.

### Q2. Define functional dependency.

A **functional dependency (FD)** `X → Y` between two sets of attributes means that **each value of X determines exactly one value of Y**; i.e., if two tuples agree on X, they must agree on Y.

- `X` is the **determinant**, `Y` is the **dependent**.
- Example: `RollNo → Name, Dept` in the `STUDENT` relation.

### Q3. Define a surrogate key.

A **surrogate key** is an **artificial, system-generated key** (usually an auto-incremented integer) that uniquely identifies each row and has **no business meaning**.

- It is used when no suitable natural key exists, or when natural keys are large or likely to change.
- Example: `OrderID INT AUTO_INCREMENT PRIMARY KEY` in `ORDERS`.

### Q4. Define conflict serializability.

A schedule is **conflict serializable** if it can be **transformed into a serial schedule by swapping adjacent non-conflicting operations**, i.e., it is **conflict equivalent** to some serial schedule.

- Two operations **conflict** if they belong to different transactions, access the same data item, and at least one is a **write** (R-W, W-R, W-W).
- It is tested using a **precedence graph**: the schedule is conflict serializable if and only if the graph has **no cycle**.

### Q5. List the ACID properties of a transaction.

- **Atomicity:** A transaction is executed completely or not at all ("all or nothing").
- **Consistency:** A transaction takes the database from one consistent state to another.
- **Isolation:** Concurrent transactions do not interfere; each appears to run alone.
- **Durability:** Once committed, the changes persist even after a system failure.

### Q6. Define concurrent execution.

**Concurrent execution** is the **interleaved execution of multiple transactions at the same time** on a database, with operations from different transactions overlapping.

- **Advantages:** Better throughput, higher resource utilization and reduced waiting time.
- **Problem:** Without control it may cause lost updates, dirty reads and inconsistency, so **concurrency control protocols** (e.g., locking, timestamp ordering) are used.

---

## UNIT V — Indexing, Hashing & Query Optimization

### Q1. List the characteristics of a B+ Tree.

- It is a **balanced, multi-level** tree; all leaf nodes are at the **same level**.
- **Internal nodes store only keys** (as guides); **all data pointers/records are stored in leaf nodes**.
- **Leaf nodes are linked** in a sequential list, enabling efficient **range queries**.
- Every node (except the root) is at least **half full**, which ensures good space utilization.
- Search, insertion and deletion take **O(log n)** time.

### Q2. Define a cluster index.

A **cluster (clustered) index** is an index in which the **physical order of the data records in the file matches the order of the index key**; the data rows themselves are stored in the sorted order of the key.

- A table can have **only one** clustered index.
- It is very efficient for **range searches**.
- Example: Records of `EMP` stored physically sorted by `EmpID`.

### Q3. State the difference between primary and secondary indexes.

| Basis | Primary Index | Secondary Index |
|---|---|---|
| Indexing field | Built on the **ordering key field** of the file (usually the primary key) | Built on a **non-ordering** field (key or non-key) |
| Data file order | File is **sorted** on the indexed field | File is **not sorted** on the indexed field |
| Index entries | Usually **sparse** (one entry per block) | Must be **dense** (one entry per record/value) |
| Number per file | Only **one** | **Many** can exist |

### Q4. Define a B+ Tree.

A **B+ Tree** is a **balanced, multi-way search tree** used for indexing, in which **all records (or record pointers) are stored in the leaf nodes**, internal nodes hold only search keys, and the leaf nodes are **linked together** for sequential access.

- Order *m*: each node holds at most *m − 1* keys and *m* child pointers.
- Widely used in database indexes (e.g., MySQL InnoDB, Oracle).

### Q5. Define hash-based indexing.

**Hash-based indexing** uses a **hash function h(K)** that maps a search key directly to the **bucket (disk block) address** where the corresponding record or pointer is stored.

- It gives **constant-time (O(1)) average** access for **equality searches** (`WHERE EmpID = 101`).
- It is **not suitable for range queries**, as hashing does not preserve key order.
- Types: **Static hashing** and **dynamic hashing** (extendible, linear).

### Q6. Define query optimization.

**Query optimization** is the process by which the DBMS **selects the most efficient execution plan** for a query from the many possible equivalent plans, in order to minimize **cost** (disk I/O, CPU time and memory).

- **Heuristic optimization:** Applies rules such as *perform selections and projections early* and reorder joins.
- **Cost-based optimization:** Estimates the cost of each plan using statistics (table sizes, indexes) and picks the cheapest.
