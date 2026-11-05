# UNIT 3 — ER Model, Constraints, Joins, Subqueries & Views

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. The ER Model

> **Question:** Explain the ER Model with neat diagrams.

---

### Definition

The **Entity-Relationship (ER) Model**, proposed by **Peter Chen (1976)**, is a high-level **conceptual data model** that describes the real world as a collection of **entities**, their **attributes**, and the **relationships** among them. The result is drawn as an **ER diagram**, which is later converted to a relational schema.

### Core Components

1. **Entity:** A real-world object that is distinguishable from others (e.g., a student, a book).
   - **Entity set:** Collection of entities of the same type (all students).
   - **Strong entity:** Has its own primary key. Drawn as a rectangle.
   - **Weak entity:** Cannot be identified without an owner (strong) entity. Drawn as a double rectangle.
2. **Attribute:** A property of an entity or relationship. Drawn as an ellipse; the key attribute is underlined.
3. **Relationship:** An association among entities. Drawn as a diamond.
4. **Cardinality ratio:** 1:1, 1:N, N:1, M:N.
5. **Participation:** **Total** (every entity must participate; double line) or **partial** (single line).

### Notation

| Symbol | Meaning |
|---|---|
| Rectangle | Entity set |
| Double rectangle | Weak entity set |
| Ellipse | Attribute |
| Underlined ellipse | Key attribute |
| Double ellipse | Multivalued attribute |
| Dashed ellipse | Derived attribute |
| Diamond | Relationship set |
| Double diamond | Identifying relationship (for weak entity) |
| Line | Links entities to relationships and attributes |

### Diagram: Student–Course

```
   (roll_no)   (name)                      (course_id)  (title)
        \       /                               \        /
        +---------+      <  ENROLLS  >       +----------+
        | STUDENT |=========<>===============| COURSE   |
        +---------+  M                    N  +----------+
              |                  |
           (dept)             (grade)
```

Here `STUDENT` and `COURSE` are entities, `ENROLLS` is an M:N relationship with its own attribute `grade`, and the double line shows total participation of `STUDENT`.

### Steps to Build an ER Diagram

1. Identify the entities.
2. Identify attributes and choose keys.
3. Identify relationships between entities.
4. Determine cardinality and participation.
5. Draw the diagram and refine it.

### Advantages

- Easy for non-technical users to understand.
- Independent of any DBMS.
- Maps directly to relational tables.

---

## 2. Attributes and Relationships in the ER Model

> **Question:** Explain different types of attributes and relationships in the ER Model.

---

### Types of Attributes

| Type | Description | Example |
|---|---|---|
| **Simple (Atomic)** | Cannot be divided further | `roll_no`, `age` |
| **Composite** | Made of sub-parts | `name` = (`first_name`, `last_name`); `address` = (`street`, `city`, `pin`) |
| **Single-valued** | One value per entity | `dob` |
| **Multivalued** | Several values per entity | `phone_numbers`, `skills` |
| **Derived** | Computed from other attributes | `age` derived from `dob` |
| **Key** | Uniquely identifies an entity | `roll_no` |
| **Null-valued** | May be unknown or not applicable | `middle_name` |

### Types of Relationships

**By degree (number of participating entity sets):**

- **Unary (recursive):** One entity set relates to itself. Example: `EMPLOYEE` *manages* `EMPLOYEE`.
- **Binary:** Two entity sets. Example: `STUDENT` *enrolls in* `COURSE`. This is the most common.
- **Ternary:** Three entity sets. Example: `SUPPLIER` *supplies* `PART` to `PROJECT`.

**By cardinality:**

| Cardinality | Meaning | Example |
|---|---|---|
| **One-to-One (1:1)** | One entity relates to at most one other | `PERSON` – `PASSPORT` |
| **One-to-Many (1:N)** | One entity relates to many | `DEPARTMENT` – `EMPLOYEE` |
| **Many-to-One (N:1)** | Many entities relate to one | `EMPLOYEE` – `DEPARTMENT` |
| **Many-to-Many (M:N)** | Many relate to many | `STUDENT` – `COURSE` |

**By participation:**

- **Total:** Every entity in the set must take part (every employee must belong to a department).
- **Partial:** Some entities may not take part (not every employee manages a project).

### Diagrams

```
1:1    PERSON |1-----<HAS>-----1| PASSPORT
1:N    DEPARTMENT |1---<WORKS_FOR>---N| EMPLOYEE
M:N    STUDENT |M---<ENROLLS>---N| COURSE
Unary  EMPLOYEE (supervisor) |1---<MANAGES>---N| EMPLOYEE (subordinate)
```

### Weak Entity and Identifying Relationship

A **weak entity** such as `DEPENDENT` of an `EMPLOYEE` has only a **partial key** (e.g., `dep_name`) and is identified by combining it with the owner's primary key. It is linked through an **identifying relationship** (double diamond) and always has total participation.

---

## 3. Specialization, Generalization, Aggregation and Inheritance

> **Question:** Explain Specialization, Generalization, Aggregation, and Inheritance with examples.

---

These are features of the **Extended ER (EER) Model**.

### Specialization (Top-Down)

**Specialization** is the process of defining **subclasses** of an entity set based on distinguishing characteristics. A higher-level entity is divided into more specific lower-level entities.

*Example:* `EMPLOYEE` specializes into `ENGINEER`, `MANAGER`, and `SECRETARY`, where `ENGINEER` has `specialization` and `MANAGER` has `bonus`.

### Generalization (Bottom-Up)

**Generalization** is the reverse: several entity sets with common attributes are combined into a single higher-level **superclass**.

*Example:* `CAR` and `TRUCK` share `reg_no`, `model`, and `price`, so they are generalized into `VEHICLE`.

```
            +-----------+                      +-----------+
            |  VEHICLE  |                      | EMPLOYEE  |
            +-----+-----+                      +-----+-----+
                  |                                  |
                 (ISA)                             (ISA)
              /       \                          /    |     \
        +-----+--+  +--+-----+         +--------+  +--+----+ +-----------+
        |  CAR   |  | TRUCK  |         |ENGINEER|  |MANAGER| | SECRETARY |
        +--------+  +--------+         +--------+  +-------+ +-----------+
```

Reading downwards is specialization; reading upwards is generalization.

### Constraints on Specialization

- **Disjoint (d):** An entity belongs to at most one subclass.
- **Overlapping (o):** An entity can belong to several subclasses.
- **Total:** Every superclass entity must belong to some subclass.
- **Partial:** An entity need not belong to any subclass.

### Inheritance

**Inheritance** means that a subclass automatically receives all attributes and relationships of its superclass, besides having its own. Each subclass `ENGINEER` inherits `emp_id`, `name`, and `salary` from `EMPLOYEE`, and adds `specialization`. This avoids repetition and models an **"is-a"** relationship. When a subclass has more than one superclass, it is called **multiple inheritance**.

### Aggregation

**Aggregation** treats a **relationship set as a higher-level entity**, so that it can participate in another relationship. It is used when a relationship needs to be related to a third entity.

*Example:* Employees **work on** projects (`WORKS_ON`). Some of these assignments need **machinery**, so the whole `WORKS_ON` relationship is aggregated and linked to `MACHINE` through `USES`.

```
 EMPLOYEE ----<WORKS_ON>---- PROJECT
    \________________________/
              |  (aggregation box)
           <USES>
              |
           MACHINE
```

### Summary

| Concept | Direction | Purpose |
|---|---|---|
| Specialization | Top-down | Define subgroups with extra attributes |
| Generalization | Bottom-up | Merge common features into a superclass |
| Inheritance | Superclass → subclass | Reuse attributes and relationships |
| Aggregation | Relationship → entity | Relate a relationship to another entity |

---

## 4. ER Diagrams: Library, Hospital and Banking Systems

> **Question:** Draw an ER diagram for a Library/Hospital/Banking System.

---

### A. Library Management System

**Entities and attributes**

- `MEMBER` (**member_id**, name, address, phone, join_date)
- `BOOK` (**isbn**, title, author, publisher, price)
- `COPY` (**copy_no**, status) — weak entity of `BOOK`
- `LIBRARIAN` (**staff_id**, name)

**Relationships**

- `BORROWS` between `MEMBER` and `COPY` (M:N) with attributes `issue_date`, `due_date`, `return_date`.
- `HAS` between `BOOK` and `COPY` (1:N; identifying).
- `ISSUES` between `LIBRARIAN` and `BORROWS` (1:N).

```
 (member_id)(name)(phone)                          (isbn)(title)(author)
        \    |    /                                      \   |   /
       +----------+   M   <BORROWS>   N   +--------+  1  <HAS>  N  +========+
       |  MEMBER  |--------<issue_date,---|  COPY  |--------------=|  BOOK  |
       +----------+         due_date>      +--------+              +========+
                                              |
                                          (copy_no)(status)

       +-----------+  1   <ISSUES>   N   to BORROWS
       | LIBRARIAN |
       +-----------+
```

**Relational mapping**

```
MEMBER(member_id PK, name, address, phone, join_date)
BOOK(isbn PK, title, author, publisher, price)
COPY(isbn FK, copy_no, status)                    PK = (isbn, copy_no)
BORROWS(member_id FK, isbn FK, copy_no FK, issue_date, due_date, return_date)
```

### B. Hospital Management System

- **Entities:** `PATIENT(patient_id, name, dob, address)`, `DOCTOR(doc_id, name, specialization)`, `DEPARTMENT(dept_id, dept_name)`, `APPOINTMENT`, `ROOM(room_no, type)`.
- **Relationships:**
  - `DOCTOR` **works in** `DEPARTMENT` (N:1).
  - `PATIENT` **consults** `DOCTOR` (M:N) with attributes `date`, `diagnosis`.
  - `PATIENT` **admitted to** `ROOM` (N:1).

```
 PATIENT |M--<CONSULTS(date,diagnosis)>--N| DOCTOR |N--<WORKS_IN>--1| DEPARTMENT
    |N
 <ADMITTED_TO>
    |1
  ROOM
```

### C. Banking System

- **Entities:** `CUSTOMER(cust_id, name, address)`, `ACCOUNT(acc_no, type, balance)`, `BRANCH(branch_id, name, city)`, `LOAN(loan_no, amount)`, `TRANSACTION(txn_id, date, amount)` (weak entity of `ACCOUNT`).
- **Relationships:**
  - `CUSTOMER` **holds** `ACCOUNT` (M:N).
  - `ACCOUNT` **maintained at** `BRANCH` (N:1).
  - `CUSTOMER` **takes** `LOAN` (1:N); `LOAN` **sanctioned by** `BRANCH`.

```
 CUSTOMER |M--<HOLDS>--N| ACCOUNT |N--<MAINTAINED_AT>--1| BRANCH
    |1                       |1
 <TAKES>                 <HAS>
    |N                       |N
  LOAN                  TRANSACTION (weak)
```

---

## 5. SQL Constraints (PK, FK, UNIQUE, NOT NULL, CHECK)

> **Question:** Explain the implementation of Primary Key, Foreign Key, UNIQUE, NOT NULL, and CHECK constraints in SQL with suitable examples.

---

### Definition

**Constraints** are rules enforced by the DBMS on table columns to maintain accuracy and integrity of the data. They can be defined at **column level** or **table level**, during `CREATE TABLE` or later with `ALTER TABLE`.

### 1. PRIMARY KEY

Uniquely identifies each row; it enforces **UNIQUE + NOT NULL**. A table can have only one primary key, which may be composite.

```sql
CREATE TABLE DEPARTMENT (
    dept_id   INT PRIMARY KEY,
    dept_name VARCHAR(30)
);

-- Composite key
CREATE TABLE ENROLLMENT (
    roll_no   INT,
    course_id INT,
    grade     CHAR(2),
    PRIMARY KEY (roll_no, course_id)
);
```

### 2. FOREIGN KEY

Links a column to the primary (or unique) key of another table, enforcing **referential integrity**. Referential actions control what happens when the parent row changes.

```sql
CREATE TABLE STUDENT (
    roll_no INT PRIMARY KEY,
    name    VARCHAR(40),
    dept_id INT,
    CONSTRAINT fk_dept FOREIGN KEY (dept_id)
        REFERENCES DEPARTMENT(dept_id)
        ON DELETE CASCADE
        ON UPDATE CASCADE
);
```

Options: `CASCADE`, `SET NULL`, `SET DEFAULT`, `RESTRICT` / `NO ACTION`.

### 3. UNIQUE

Ensures all values in a column (or combination) are different. A table may have **many** unique constraints, and NULLs are normally allowed.

```sql
ALTER TABLE STUDENT ADD email VARCHAR(50) UNIQUE;
-- table level, composite
CONSTRAINT uq_stu UNIQUE (name, dept_id)
```

### 4. NOT NULL

Prohibits NULL values in a column. It is only defined at column level.

```sql
CREATE TABLE EMP (
    emp_id INT PRIMARY KEY,
    name   VARCHAR(40) NOT NULL
);
```

### 5. CHECK

Restricts values to those satisfying a condition.

```sql
CREATE TABLE EMP (
    emp_id INT PRIMARY KEY,
    age    INT CHECK (age >= 18),
    salary DECIMAL(10,2),
    gender CHAR(1),
    CONSTRAINT chk_sal CHECK (salary > 0),
    CONSTRAINT chk_g   CHECK (gender IN ('M','F','O'))
);
```

### Adding and Dropping Constraints Later

```sql
ALTER TABLE EMP ADD CONSTRAINT chk_age CHECK (age <= 65);
ALTER TABLE EMP DROP CONSTRAINT chk_age;      -- Oracle / PostgreSQL / SQL Server
```

### Summary

| Constraint | Duplicates | NULL allowed | Per table |
|---|---|---|---|
| PRIMARY KEY | No | No | One |
| FOREIGN KEY | Yes | Yes | Many |
| UNIQUE | No | Yes | Many |
| NOT NULL | Yes | No | Per column |
| CHECK | Yes | Yes (condition unknown passes) | Many |

---

## 6. Integrity Constraints

> **Question:** What are integrity constraints? Explain Entity Integrity, Referential Integrity, and Domain Integrity constraints with suitable SQL examples.

---

### Definition

**Integrity constraints** are rules that ensure the data in a database remains **accurate, valid, and consistent** whenever it is inserted, updated, or deleted. The DBMS rejects any operation that violates them.

### 1. Entity Integrity

**Rule:** No primary key attribute of a tuple may be `NULL`, and primary key values must be unique. This guarantees each row is identifiable.

```sql
CREATE TABLE STUDENT (
    roll_no INT PRIMARY KEY,
    name    VARCHAR(40)
);

INSERT INTO STUDENT VALUES (101, 'Ravi');
INSERT INTO STUDENT VALUES (101, 'Sita');   -- rejected: duplicate key
INSERT INTO STUDENT VALUES (NULL, 'Arjun'); -- rejected: NULL primary key
```

### 2. Referential Integrity

**Rule:** A foreign key value must either match an existing primary key value in the referenced table, or be `NULL`. This prevents "orphan" records.

```sql
CREATE TABLE DEPARTMENT (dept_id INT PRIMARY KEY, dept_name VARCHAR(30));

CREATE TABLE EMP (
    emp_id  INT PRIMARY KEY,
    name    VARCHAR(40),
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES DEPARTMENT(dept_id) ON DELETE SET NULL
);

INSERT INTO EMP VALUES (1, 'Ravi', 99);   -- rejected if dept 99 does not exist
DELETE FROM DEPARTMENT WHERE dept_id = 10; -- dependent EMP.dept_id becomes NULL
```

### 3. Domain Integrity

**Rule:** Every value in a column must belong to that column's **domain**: the allowed data type, format, range, and default.

```sql
CREATE TABLE EMP (
    emp_id INT PRIMARY KEY,
    age    INT          CHECK (age BETWEEN 18 AND 65),
    gender CHAR(1)      CHECK (gender IN ('M','F','O')),
    status VARCHAR(10)  DEFAULT 'ACTIVE' NOT NULL,
    salary DECIMAL(8,2) CHECK (salary > 0)
);

INSERT INTO EMP (emp_id, age, gender, salary) VALUES (1, 15, 'M', 20000); -- rejected: age
```

Domain integrity is enforced using **data types, `NOT NULL`, `DEFAULT`, and `CHECK`**.

### Other Types (Brief)

- **Key constraint:** Every relation has at least one candidate key.
- **User-defined (semantic) integrity:** Business rules enforced via triggers or assertions (for example, a withdrawal cannot exceed the balance).

### Comparison

| Integrity | Applies to | Prevents | Enforced by |
|---|---|---|---|
| Entity | Primary key | Duplicate or NULL keys | `PRIMARY KEY` |
| Referential | Foreign key | Orphan or invalid references | `FOREIGN KEY` |
| Domain | Any column | Invalid values | Data type, `CHECK`, `NOT NULL`, `DEFAULT` |

---

## 7. Nested and Correlated Subqueries

> **Question:** Explain Nested and Correlated Subqueries with examples.

---

### Definition

A **subquery** is a `SELECT` statement written inside another SQL statement (in `WHERE`, `FROM`, `HAVING`, or `SELECT`). The inner query provides values for the outer query.

Sample tables:

```
EMP(emp_id, name, dept_id, salary)     DEPT(dept_id, dept_name, location)
```

### Nested (Non-Correlated) Subquery

The inner query is **independent**: it runs **once**, and its result is used by the outer query.

**Single-row subquery** (uses `=, >, <`):

```sql
SELECT name, salary FROM EMP
WHERE  salary > (SELECT AVG(salary) FROM EMP);
```

**Multiple-row subquery** (uses `IN, ANY, ALL`):

```sql
SELECT name FROM EMP
WHERE  dept_id IN (SELECT dept_id FROM DEPT WHERE location = 'Hyderabad');

SELECT name FROM EMP
WHERE  salary > ALL (SELECT salary FROM EMP WHERE dept_id = 10);
```

**Execution order:** inner query → result → outer query.

### Correlated Subquery

The inner query **refers to a column of the outer query**, so it is evaluated **once for every row** processed by the outer query.

**Example 1:** Employees earning more than the average of **their own** department.

```sql
SELECT e.name, e.salary, e.dept_id
FROM   EMP e
WHERE  e.salary > (SELECT AVG(salary)
                   FROM   EMP
                   WHERE  dept_id = e.dept_id);
```

**Example 2:** Departments that have at least one employee, using `EXISTS`.

```sql
SELECT d.dept_name
FROM   DEPT d
WHERE  EXISTS (SELECT 1 FROM EMP e WHERE e.dept_id = d.dept_id);
```

Use `NOT EXISTS` to find departments with no employees.

### Execution of a Correlated Subquery

```
For each row r of the outer table:
    1. Pass r.dept_id into the inner query
    2. Evaluate the inner query
    3. Test the outer condition; keep or discard r
```

### Comparison

| Parameter | Nested (Non-correlated) | Correlated |
|---|---|---|
| **Dependency** | Independent of outer query | Depends on outer query's values |
| **Execution** | Inner runs once | Inner runs once per outer row |
| **Speed** | Generally faster | Generally slower |
| **Can run alone** | Yes | No |
| **Typical operators** | `IN`, `ANY`, `ALL`, `=` | `EXISTS`, `NOT EXISTS`, comparisons |

---

## 8. SQL Joins

> **Question:** Explain different types of SQL Joins with suitable examples.

---

### Definition

A **join** combines rows from two or more tables based on a related column, usually a primary key–foreign key pair.

Sample tables:

```
EMP                               DEPT
+--------+-------+---------+      +---------+-----------+
| emp_id | name  | dept_id |      | dept_id | dept_name |
+--------+-------+---------+      +---------+-----------+
| 1      | Ravi  | 10      |      | 10      | IT        |
| 2      | Sita  | 20      |      | 20      | HR        |
| 3      | Arjun | NULL    |      | 30      | SALES     |
+--------+-------+---------+      +---------+-----------+
```

### 1. INNER JOIN

Returns only rows with **matching** values in both tables.

```sql
SELECT e.name, d.dept_name
FROM   EMP e INNER JOIN DEPT d ON e.dept_id = d.dept_id;
```

Result: (Ravi, IT), (Sita, HR).

### 2. LEFT (OUTER) JOIN

All rows from the left table, plus matches from the right; unmatched right columns are `NULL`.

```sql
SELECT e.name, d.dept_name
FROM   EMP e LEFT JOIN DEPT d ON e.dept_id = d.dept_id;
```

Result: (Ravi, IT), (Sita, HR), (Arjun, NULL).

### 3. RIGHT (OUTER) JOIN

All rows from the right table, plus matches from the left.

```sql
SELECT e.name, d.dept_name
FROM   EMP e RIGHT JOIN DEPT d ON e.dept_id = d.dept_id;
```

Result: (Ravi, IT), (Sita, HR), (NULL, SALES).

### 4. FULL (OUTER) JOIN

All rows from both tables, with `NULL` where there is no match.

```sql
SELECT e.name, d.dept_name
FROM   EMP e FULL OUTER JOIN DEPT d ON e.dept_id = d.dept_id;
```

Result: (Ravi, IT), (Sita, HR), (Arjun, NULL), (NULL, SALES). MySQL lacks `FULL JOIN`; use `LEFT JOIN UNION RIGHT JOIN`.

### 5. CROSS JOIN

Cartesian product: every row of one table with every row of the other (3 × 3 = 9 rows).

```sql
SELECT e.name, d.dept_name FROM EMP e CROSS JOIN DEPT d;
```

### 6. NATURAL JOIN

Automatically joins on all columns with the same name and shows the common column once.

```sql
SELECT * FROM EMP NATURAL JOIN DEPT;
```

### 7. SELF JOIN

A table joined with itself using aliases. Used for hierarchical data.

```sql
SELECT e.name AS employee, m.name AS manager
FROM   EMP e JOIN EMP m ON e.manager_id = m.emp_id;
```

### Join Types at a Glance

```
INNER      :  A ∩ B
LEFT       :  all of A  + matching B
RIGHT      :  all of B  + matching A
FULL       :  A ∪ B
CROSS      :  A × B
```

---

## 9. SQL Views

> **Question:** Explain SQL Views. Differentiate between updatable and non-updatable views.

---

### Definition

A **view** is a **virtual table** defined by a stored `SELECT` query. It does not store data itself (except materialized views); data is fetched from the underlying **base tables** whenever the view is queried.

### Creating, Using and Dropping

```sql
CREATE VIEW cse_students AS
SELECT roll_no, name, cgpa
FROM   STUDENT
WHERE  dept = 'CSE';

SELECT * FROM cse_students WHERE cgpa > 8;

CREATE OR REPLACE VIEW cse_students AS ...;   -- modify
DROP VIEW cse_students;
```

### Advantages

1. **Security:** Expose only selected rows or columns (hide `salary`).
2. **Simplicity:** Hide complex joins and calculations behind a name.
3. **Logical data independence:** Applications are unaffected by changes to base tables.
4. **Consistency:** The same query logic is reused everywhere.

### Updatable Views

A view is **updatable** when `INSERT`, `UPDATE`, and `DELETE` through it are translated to the single base table. This requires each view row to map to exactly one base-table row. Typically the view:

- is based on **one table**;
- contains **no** `DISTINCT`, aggregate functions, `GROUP BY`, `HAVING`, `UNION`, or subquery in `SELECT`;
- includes all `NOT NULL` columns of the base table without defaults (for inserts).

```sql
CREATE VIEW cse_students AS
SELECT roll_no, name, cgpa FROM STUDENT WHERE dept = 'CSE';

UPDATE cse_students SET cgpa = 9.0 WHERE roll_no = 101;   -- works
```

`WITH CHECK OPTION` prevents changes that would make a row disappear from the view.

```sql
CREATE VIEW cse_students AS
SELECT * FROM STUDENT WHERE dept = 'CSE' WITH CHECK OPTION;
```

### Non-Updatable (Read-Only) Views

Views that use aggregates, `GROUP BY`, `DISTINCT`, set operators, or multi-table joins (in most systems) cannot be updated reliably because a view row does not map to a single base row.

```sql
CREATE VIEW dept_avg AS
SELECT dept, AVG(cgpa) AS avg_cgpa FROM STUDENT GROUP BY dept;

UPDATE dept_avg SET avg_cgpa = 9 WHERE dept = 'CSE';   -- error
```

### Comparison

| Parameter | Updatable View | Non-Updatable View |
|---|---|---|
| **Base tables** | Usually a single table | Often multiple tables |
| **Aggregates / GROUP BY** | Not present | Present |
| **DISTINCT / UNION** | Not present | Present |
| **DML allowed** | INSERT, UPDATE, DELETE | SELECT only |
| **Row mapping** | One view row ↔ one base row | No one-to-one mapping |
| **Example** | `SELECT roll_no, name FROM STUDENT` | `SELECT dept, AVG(cgpa) ... GROUP BY dept` |

---

## 10. Relational Set Operations

> **Question:** Explain Relational Set Operations with suitable examples.

---

### Definition

**Set operations** combine the results of two or more `SELECT` queries into one result. The queries must be **union-compatible**: same number of columns, and compatible data types in corresponding positions.

Sample tables:

```
CSE_STUDENTS(name)          ECE_STUDENTS(name)
+-------+                   +-------+
| Ravi  |                   | Sita  |
| Sita  |                   | Arjun |
| Meena |                   | Meena |
+-------+                   +-------+
```

### 1. UNION

Combines rows from both queries and **removes duplicates**. `UNION ALL` keeps duplicates.

```sql
SELECT name FROM CSE_STUDENTS
UNION
SELECT name FROM ECE_STUDENTS;
```

Result: Ravi, Sita, Meena, Arjun.

### 2. INTERSECT

Returns only rows present in **both** results.

```sql
SELECT name FROM CSE_STUDENTS
INTERSECT
SELECT name FROM ECE_STUDENTS;
```

Result: Sita, Meena.

### 3. EXCEPT / MINUS

Returns rows from the first query that are **not** in the second. `EXCEPT` is standard SQL (PostgreSQL, SQL Server); `MINUS` is Oracle.

```sql
SELECT name FROM CSE_STUDENTS
EXCEPT
SELECT name FROM ECE_STUDENTS;
```

Result: Ravi.

### Venn Representation

```
 UNION        INTERSECT      EXCEPT (A - B)
 [A  B ]      [   A∩B  ]     [ A only ]
 all shaded   overlap only   left minus overlap
```

### Relational Algebra Equivalents

| SQL | Algebra |
|---|---|
| `UNION` | R ∪ S |
| `INTERSECT` | R ∩ S |
| `EXCEPT / MINUS` | R − S |

### Rules

1. The number and order of columns must match.
2. Corresponding columns must have compatible types.
3. Column names come from the first query.
4. `ORDER BY` is placed once, at the end of the final query.
5. Duplicates are removed unless `ALL` is used.

### Set Operations vs Joins

| Parameter | Set Operations | Joins |
|---|---|---|
| **Combines** | Rows (vertically) | Columns (horizontally) |
| **Requirement** | Union-compatible queries | A join condition |
| **Output width** | Same as inputs | Sum of the columns |
