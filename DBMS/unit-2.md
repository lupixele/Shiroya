# UNIT 2 — Relational Model, Relational Algebra & SQL

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. The Relational Model and Its Components

> **Question:** Explain the Relational Model and its components with examples.

---

### Definition

The **Relational Model**, proposed by **E.F. Codd (1970)**, represents data as a collection of **relations**. Each relation is a two-dimensional **table** of rows and columns. It is based on set theory and predicate logic, and is the basis for SQL and most modern DBMSs.

### Components

| Term | Meaning | Example |
|---|---|---|
| **Relation** | A table with a name | `STUDENT` |
| **Tuple** | A row; one record | `(101, 'Ravi', 'CSE', 8.5)` |
| **Attribute** | A column; a named property | `roll_no`, `name`, `dept`, `cgpa` |
| **Domain** | Set of allowed values for an attribute | `cgpa` ∈ [0.0, 10.0] |
| **Degree** | Number of attributes | 4 for `STUDENT` below |
| **Cardinality** | Number of tuples | 3 for `STUDENT` below |
| **Relation Schema** | Name plus attribute list | `STUDENT(roll_no, name, dept, cgpa)` |
| **Relation Instance** | Set of tuples at a given time | The data currently in the table |
| **Key** | Attribute(s) uniquely identifying a tuple | `roll_no` |

### Example

```
STUDENT
+---------+--------+------+------+
| roll_no | name   | dept | cgpa |
+---------+--------+------+------+
| 101     | Ravi   | CSE  | 8.5  |
| 102     | Sita   | ECE  | 9.1  |
| 103     | Arjun  | CSE  | 7.8  |
+---------+--------+------+------+
 Degree = 4, Cardinality = 3
```

### Properties of a Relation

1. Each relation has a **unique name** within the database.
2. Each attribute name is unique within a relation.
3. Values are **atomic** (single-valued); no multi-valued or composite entries.
4. All values in a column come from the same domain.
5. **No duplicate tuples** (a relation is a set).
6. The order of tuples and the order of attributes are insignificant.

### Relational Constraints

- **Domain constraints:** Values must belong to the attribute's domain.
- **Key constraints:** Every relation has at least one key that uniquely identifies tuples.
- **Entity integrity:** Primary key attributes cannot be `NULL`.
- **Referential integrity:** A foreign key must match a primary key value in the referenced relation, or be `NULL`.

---

## 2. Types of Keys

> **Question:** Explain different types of keys in the Relational Model with suitable examples.

---

### Definition

A **key** is an attribute or a set of attributes that uniquely identifies a tuple in a relation. Keys enforce uniqueness and establish relationships between tables.

Consider the following relations for all examples:

```
STUDENT(roll_no, email, aadhaar, name, dept_id)
DEPARTMENT(dept_id, dept_name)
```

### Types of Keys

1. **Super Key:** Any set of attributes that uniquely identifies a tuple. It may contain extra, unnecessary attributes.
   *Examples:* `{roll_no}`, `{roll_no, name}`, `{email, name}`, `{aadhaar}`.

2. **Candidate Key:** A **minimal** super key; no proper subset is itself a super key. A relation can have several.
   *Examples:* `{roll_no}`, `{email}`, `{aadhaar}`. (`{roll_no, name}` is not a candidate key, since `roll_no` alone suffices.)

3. **Primary Key (PK):** The candidate key chosen by the designer to identify tuples. It must be **unique and NOT NULL**, and there is only one per table.
   *Example:* `roll_no`.

4. **Alternate Key:** Candidate keys that were **not** chosen as the primary key.
   *Examples:* `email`, `aadhaar`.

5. **Composite Key:** A key made of two or more attributes together.
   *Example:* In `ENROLLMENT(roll_no, course_id, grade)`, the key is `(roll_no, course_id)`.

6. **Foreign Key (FK):** An attribute in one relation that refers to the primary key of another relation, creating a link between them and enforcing referential integrity.
   *Example:* `STUDENT.dept_id` references `DEPARTMENT.dept_id`.

7. **Unique Key:** Ensures values are unique, but unlike a primary key, it allows `NULL` (the number of NULLs allowed depends on the DBMS) and a table may have several.
   *Example:* `email`.

8. **Surrogate Key:** An artificial, system-generated key (such as an auto-increment ID) with no business meaning, used when no suitable natural key exists.

### Relationship Between Keys

```
Super Keys
 └── Candidate Keys (minimal super keys)
        ├── Primary Key   (chosen one)
        └── Alternate Keys (the rest)
```

### SQL Example

```sql
CREATE TABLE DEPARTMENT (
    dept_id   INT PRIMARY KEY,
    dept_name VARCHAR(30) NOT NULL
);

CREATE TABLE STUDENT (
    roll_no INT PRIMARY KEY,
    email   VARCHAR(50) UNIQUE,
    aadhaar CHAR(12)    UNIQUE,
    name    VARCHAR(40),
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES DEPARTMENT(dept_id)
);
```

---

## 3. Relational Algebra

> **Question:** Explain Relational Algebra and discuss its fundamental operations.

---

### Definition

**Relational Algebra** is a **procedural query language** consisting of a set of operations that take one or two relations as input and produce a new relation as output. It forms the theoretical foundation of SQL and query optimization.

Sample relations used below:

```
STUDENT                         ENROLL
+------+-------+------+         +------+--------+
| roll | name  | dept |         | roll | course |
+------+-------+------+         +------+--------+
| 101  | Ravi  | CSE  |         | 101  | DBMS   |
| 102  | Sita  | ECE  |         | 103  | DBMS   |
| 103  | Arjun | CSE  |         | 102  | OS     |
+------+-------+------+         +------+--------+
```

### Fundamental Operations

**1. Selection (σ):** Selects tuples satisfying a condition (horizontal filter).
`σ dept='CSE' (STUDENT)` → rows 101 Ravi and 103 Arjun.

**2. Projection (π):** Selects specified attributes (vertical filter) and removes duplicates.
`π name, dept (STUDENT)` → only the `name` and `dept` columns.

**3. Union (∪):** All tuples in R or S (or both), duplicates removed. Requires **union-compatible** relations (same number and domains of attributes).
`π roll (STUDENT) ∪ π roll (ENROLL)`

**4. Set Difference (−):** Tuples in R but not in S.
`π roll (STUDENT) − π roll (ENROLL)` → students not enrolled in any course.

**5. Cartesian Product (×):** Combines every tuple of R with every tuple of S. If R has *m* tuples and S has *n*, the result has *m × n* tuples.
`STUDENT × ENROLL` → 3 × 3 = 9 tuples.

**6. Rename (ρ):** Renames a relation or its attributes.
`ρ S(roll_no, sname, d) (STUDENT)`

### Derived (Additional) Operations

- **Intersection (∩):** Tuples common to both. `R ∩ S = R − (R − S)`.
- **Join (⋈):** A Cartesian product followed by selection on a condition.
  - *Theta join:* `R ⋈θ S` with any condition.
  - *Equi-join:* condition uses only equality.
  - *Natural join:* equi-join on all common attributes, with duplicate columns removed.
  `STUDENT ⋈ ENROLL` → (101, Ravi, CSE, DBMS), (102, Sita, ECE, OS), (103, Arjun, CSE, DBMS).
- **Division (÷):** Finds tuples in R associated with *all* tuples of S. Example: students who are enrolled in **all** courses listed in a relation `COURSES`.
- **Assignment (←):** Stores a result in a temporary relation: `CSE_STUD ← σ dept='CSE' (STUDENT)`.
- **Aggregate (𝒢):** Applies functions such as SUM and AVG: `𝒢 count(roll) (STUDENT)`.

### Composite Query Example

Names of students enrolled in DBMS:

```
π name ( σ course='DBMS' ( STUDENT ⋈ ENROLL ) )
```

### Summary Table

| Operation | Symbol | Type |
|---|---|---|
| Selection | σ | Unary |
| Projection | π | Unary |
| Rename | ρ | Unary |
| Union | ∪ | Binary |
| Set difference | − | Binary |
| Cartesian product | × | Binary |
| Intersection, Join, Division | ∩, ⋈, ÷ | Binary (derived) |

---

## 4. DDL Commands

> **Question:** Explain DDL commands with syntax and examples.

---

### Definition

**Data Definition Language (DDL)** consists of SQL commands used to **define, modify, and remove the structure (schema)** of database objects such as tables, views, and indexes. DDL statements are typically **auto-committed** and cannot be rolled back in most systems.

### Commands

**1. `CREATE`** — Creates a new database object.

```sql
CREATE TABLE STUDENT (
    roll_no INT PRIMARY KEY,
    name    VARCHAR(40) NOT NULL,
    dept    VARCHAR(10),
    cgpa    DECIMAL(3,1) CHECK (cgpa BETWEEN 0 AND 10)
);
```

**2. `ALTER`** — Modifies the structure of an existing object.

```sql
ALTER TABLE STUDENT ADD email VARCHAR(50);            -- add a column
ALTER TABLE STUDENT MODIFY name VARCHAR(60);          -- change a column (Oracle/MySQL)
ALTER TABLE STUDENT DROP COLUMN email;                -- remove a column
ALTER TABLE STUDENT ADD CONSTRAINT uq_name UNIQUE (name);
```

**3. `DROP`** — Permanently deletes the object, including its data and structure.

```sql
DROP TABLE STUDENT;
```

**4. `TRUNCATE`** — Removes **all rows** quickly but keeps the table structure. It cannot use a `WHERE` clause.

```sql
TRUNCATE TABLE STUDENT;
```

**5. `RENAME`** — Changes the name of an object.

```sql
RENAME TABLE STUDENT TO STUDENTS;       -- MySQL
ALTER TABLE STUDENT RENAME TO STUDENTS; -- standard / PostgreSQL
```

### Difference Between `DROP`, `TRUNCATE`, and `DELETE`

| Parameter | `DROP` | `TRUNCATE` | `DELETE` |
|---|---|---|---|
| **Category** | DDL | DDL | DML |
| **Removes** | Table structure and data | All rows only | Selected or all rows |
| **`WHERE` clause** | Not applicable | Not allowed | Allowed |
| **Rollback** | Not possible | Generally not possible | Possible |
| **Speed** | Fast | Fast | Slower (row by row) |

---

## 5. DML Commands

> **Question:** Explain DML commands with syntax and examples.

---

### Definition

**Data Manipulation Language (DML)** consists of SQL commands used to **retrieve, insert, modify, and delete data** stored in tables. Unlike DDL, DML changes can be **rolled back** until committed.

Sample table: `STUDENT(roll_no, name, dept, cgpa)`.

### Commands

**1. `INSERT`** — Adds new rows.

```sql
INSERT INTO STUDENT (roll_no, name, dept, cgpa)
VALUES (101, 'Ravi', 'CSE', 8.5);

INSERT INTO STUDENT VALUES (102, 'Sita', 'ECE', 9.1);          -- all columns in order

INSERT INTO TOPPERS SELECT * FROM STUDENT WHERE cgpa > 9;       -- from a query
```

**2. `SELECT`** — Retrieves data.

```sql
SELECT * FROM STUDENT;
SELECT name, cgpa FROM STUDENT WHERE dept = 'CSE' ORDER BY cgpa DESC;
SELECT DISTINCT dept FROM STUDENT;
SELECT name FROM STUDENT WHERE name LIKE 'R%' AND cgpa BETWEEN 7 AND 9;
```

Basic syntax:

```sql
SELECT [DISTINCT] column_list
FROM   table_name
[WHERE condition]
[GROUP BY columns]
[HAVING group_condition]
[ORDER BY columns [ASC|DESC]];
```

**3. `UPDATE`** — Modifies existing rows.

```sql
UPDATE STUDENT SET cgpa = 9.0 WHERE roll_no = 103;
UPDATE STUDENT SET cgpa = cgpa + 0.2 WHERE dept = 'CSE';
```

Omitting `WHERE` updates **all** rows.

**4. `DELETE`** — Removes rows.

```sql
DELETE FROM STUDENT WHERE roll_no = 102;
DELETE FROM STUDENT;                  -- deletes all rows, keeps structure
```

### Related Transaction Control

Because DML changes are not permanent until committed, they are controlled with `COMMIT` (save), `ROLLBACK` (undo), and `SAVEPOINT` (partial rollback).

---

## 6. SQL Functions

> **Question:** Explain SQL functions with suitable examples.

---

### Definition

**SQL functions** are built-in routines that take input values and return a result. They are used in `SELECT`, `WHERE`, and other clauses to compute and transform data. They fall into two main groups: **aggregate** functions and **scalar (single-row)** functions.

### A. Aggregate Functions

These operate on a **set of rows** and return a **single value**. They ignore `NULL` values (except `COUNT(*)`).

| Function | Purpose | Example |
|---|---|---|
| `COUNT()` | Number of rows | `SELECT COUNT(*) FROM STUDENT;` |
| `SUM()` | Total | `SELECT SUM(salary) FROM EMP;` |
| `AVG()` | Average | `SELECT AVG(cgpa) FROM STUDENT;` |
| `MAX()` | Largest value | `SELECT MAX(cgpa) FROM STUDENT;` |
| `MIN()` | Smallest value | `SELECT MIN(cgpa) FROM STUDENT;` |

### B. Scalar Functions

These operate on **each row** and return one value per row.

**1. String functions**

```sql
SELECT UPPER('dbms');                  -- DBMS
SELECT LOWER('SQL');                   -- sql
SELECT LENGTH('Aditya');               -- 6
SELECT SUBSTR('DATABASE', 1, 4);       -- DATA
SELECT CONCAT('Data', 'base');         -- Database
SELECT TRIM('  hi  ');                 -- hi
SELECT REPLACE('Hello', 'l', 'p');     -- Heppo
```

**2. Numeric functions**

```sql
SELECT ABS(-15);          -- 15
SELECT ROUND(45.678, 1);  -- 45.7
SELECT CEIL(4.2);         -- 5
SELECT FLOOR(4.8);        -- 4
SELECT MOD(10, 3);        -- 1
SELECT POWER(2, 3);       -- 8
SELECT SQRT(49);          -- 7
```

**3. Date functions** (names vary by DBMS)

```sql
SELECT CURRENT_DATE;
SELECT EXTRACT(YEAR FROM order_date) FROM ORDERS;
SELECT DATEDIFF(end_date, start_date) FROM PROJECT;   -- MySQL
SELECT ADD_MONTHS(hire_date, 6) FROM EMP;              -- Oracle
```

**4. Conversion functions**

```sql
SELECT CAST('123' AS INT);
SELECT TO_CHAR(hire_date, 'DD-MM-YYYY') FROM EMP;      -- Oracle
```

**5. NULL-handling and conditional functions**

```sql
SELECT COALESCE(phone, 'N/A') FROM STUDENT;
SELECT CASE WHEN cgpa >= 9 THEN 'Distinction'
            WHEN cgpa >= 7 THEN 'First Class'
            ELSE 'Pass' END AS grade
FROM STUDENT;
```

### Aggregate vs Scalar

| Parameter | Aggregate Functions | Scalar Functions |
|---|---|---|
| **Input** | Group of rows | Single row value |
| **Output** | One value per group | One value per row |
| **NULL handling** | Ignored (mostly) | Depends on function |
| **Used with `GROUP BY`** | Yes | No |
| **Examples** | `SUM`, `AVG`, `COUNT` | `UPPER`, `ROUND`, `SUBSTR` |

---

## 7. GROUP BY and HAVING Clauses

> **Question:** Explain the GROUP BY and HAVING clauses in SQL. Discuss how they are used with aggregate functions with suitable examples.

---

### GROUP BY

The **`GROUP BY`** clause arranges rows that share the same value in specified columns into **groups**, so that an aggregate function can be applied to each group separately and return one result per group.

**Syntax:**

```sql
SELECT column, aggregate_function(column)
FROM   table
[WHERE condition]
GROUP BY column;
```

**Rule:** Every non-aggregated column in the `SELECT` list must appear in the `GROUP BY` clause.

### HAVING

The **`HAVING`** clause filters **groups** after they have been formed, typically using a condition on an aggregate function. `WHERE` cannot use aggregates, so `HAVING` fills that role.

**Syntax:**

```sql
SELECT column, aggregate_function(column)
FROM   table
GROUP BY column
HAVING aggregate_condition;
```

### Example Data

```
EMP
+-------+--------+--------+
| emp_id| dept   | salary |
+-------+--------+--------+
| 1     | IT     | 50000  |
| 2     | IT     | 60000  |
| 3     | HR     | 40000  |
| 4     | HR     | 45000  |
| 5     | SALES  | 30000  |
+-------+--------+--------+
```

**Example 1: GROUP BY with aggregates**

```sql
SELECT dept, COUNT(*) AS emp_count, AVG(salary) AS avg_sal
FROM   EMP
GROUP BY dept;
```

```
+-------+-----------+---------+
| dept  | emp_count | avg_sal |
+-------+-----------+---------+
| IT    | 2         | 55000   |
| HR    | 2         | 42500   |
| SALES | 1         | 30000   |
+-------+-----------+---------+
```

**Example 2: HAVING to filter groups**

```sql
SELECT dept, AVG(salary) AS avg_sal
FROM   EMP
GROUP BY dept
HAVING AVG(salary) > 40000;
```

Result: `IT` (55000) and `HR` (42500).

**Example 3: WHERE and HAVING together**

```sql
SELECT dept, SUM(salary)
FROM   EMP
WHERE  salary > 35000          -- filters rows BEFORE grouping
GROUP BY dept
HAVING SUM(salary) > 90000;    -- filters groups AFTER grouping
```

### Order of Execution

```
FROM -> WHERE -> GROUP BY -> HAVING -> SELECT -> ORDER BY
```

### Difference Between WHERE and HAVING

| Parameter | `WHERE` | `HAVING` |
|---|---|---|
| **Filters** | Individual rows | Groups of rows |
| **Applied** | Before grouping | After grouping |
| **Aggregate functions** | Not allowed | Allowed |
| **Requires `GROUP BY`** | No | Normally used with it |
| **Performance** | Reduces rows early | Works on grouped result |

---

## 8. NULL Values and Handling NULLs

> **Question:** Explain NULL values and methods of handling NULL values.

---

### Definition

A **NULL** represents a **missing, unknown, or inapplicable** value. It is **not** the same as zero or an empty string. For example, a student's `phone` is NULL if it has not been provided.

### Behavior of NULL

1. **Arithmetic:** Any arithmetic with NULL yields NULL. `5 + NULL = NULL`.
2. **Comparison:** `NULL = NULL` is neither true nor false; it evaluates to **UNKNOWN**. Therefore `= NULL` and `<> NULL` never work; use `IS NULL` and `IS NOT NULL`.
3. **Aggregates:** `SUM`, `AVG`, `MIN`, `MAX`, and `COUNT(column)` ignore NULLs. `COUNT(*)` counts all rows.
4. **Constraints:** `PRIMARY KEY` cannot be NULL. `NOT NULL` forbids it.
5. **Sorting and grouping:** NULLs group together in `GROUP BY` and sort first or last depending on the DBMS.

### Three-Valued Logic

SQL uses **TRUE, FALSE, and UNKNOWN**. A `WHERE` clause returns a row only if the condition is TRUE.

| A | B | A AND B | A OR B |
|---|---|---|---|
| TRUE | UNKNOWN | UNKNOWN | TRUE |
| FALSE | UNKNOWN | FALSE | UNKNOWN |
| UNKNOWN | UNKNOWN | UNKNOWN | UNKNOWN |

`NOT UNKNOWN` is `UNKNOWN`.

### Methods of Handling NULLs

Sample table: `STUDENT(roll_no, name, phone, cgpa)` where some `phone` values are NULL.

**1. `IS NULL` / `IS NOT NULL`**

```sql
SELECT name FROM STUDENT WHERE phone IS NULL;
SELECT name FROM STUDENT WHERE phone IS NOT NULL;
```

**2. `COALESCE()`** — Returns the first non-NULL argument (standard SQL).

```sql
SELECT name, COALESCE(phone, 'Not Available') FROM STUDENT;
```

**3. `NVL()` / `IFNULL()` / `ISNULL()`** — DBMS-specific two-argument versions (Oracle `NVL`, MySQL `IFNULL`, SQL Server `ISNULL`).

```sql
SELECT NVL(cgpa, 0) FROM STUDENT;       -- Oracle
SELECT IFNULL(cgpa, 0) FROM STUDENT;    -- MySQL
```

**4. `NULLIF(a, b)`** — Returns NULL if `a = b`, otherwise `a`. Useful to avoid divide-by-zero.

```sql
SELECT total / NULLIF(count_items, 0) FROM ORDERS;
```

**5. `CASE` expression**

```sql
SELECT name,
       CASE WHEN phone IS NULL THEN 'No phone' ELSE phone END AS contact
FROM STUDENT;
```

**6. Preventing NULLs with constraints or defaults**

```sql
CREATE TABLE STUDENT (
    roll_no INT PRIMARY KEY,
    name    VARCHAR(40) NOT NULL,
    cgpa    DECIMAL(3,1) DEFAULT 0
);
```

**7. Outer joins** produce NULLs for unmatched rows; they are handled with `IS NULL` to find non-matching records.

```sql
SELECT s.name
FROM   STUDENT s LEFT JOIN ENROLL e ON s.roll_no = e.roll_no
WHERE  e.roll_no IS NULL;               -- students with no enrollment
```

### Common Pitfall

```sql
SELECT * FROM STUDENT WHERE phone = NULL;   -- wrong: returns no rows
SELECT * FROM STUDENT WHERE phone IS NULL;  -- correct
```
