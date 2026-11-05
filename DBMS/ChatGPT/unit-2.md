# UNIT 2 — Relational Model, Relational Algebra & SQL

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

## Q1. Relational Model and Its Components

> **Question:** Explain the Relational Model and its components with examples.

---

### Definition

The **Relational Model** is a database model in which data is organized into **relations (tables)**. Each relation consists of rows called **tuples** and columns called **attributes**. Every attribute has a defined domain, and relationships between tables are represented using keys, especially primary keys and foreign keys.

The model was introduced by **E. F. Codd**. It provides a simple tabular way to represent data and supports operations such as retrieving, inserting, updating, and deleting records using relational algebra and SQL.

### Components of the Relational Model

Consider the following relations for a college database.

**STUDENT**

| Student_ID | Name | Department | Age |
|---:|---|---|---:|
| 101 | Arun | CSE | 20 |
| 102 | Bina | ECE | 19 |
| 103 | Charan | CSE | 21 |

**COURSE**

| Course_ID | Course_Name |
|---|---|
| C01 | DBMS |
| C02 | Python |

**ENROLLMENT**

| Student_ID | Course_ID | Grade |
|---:|---|---|
| 101 | C01 | A |
| 101 | C02 | B |
| 102 | C01 | A |

1. **Relation:** A relation is a table containing data about one type of object or association. `STUDENT`, `COURSE`, and `ENROLLMENT` are relations. A relation is identified by its name and its set of attributes.

2. **Tuple:** A tuple is a single row in a relation. For example, `(101, Arun, CSE, 20)` is one tuple in the `STUDENT` relation. Each tuple represents one record.

3. **Attribute:** An attribute is a named column in a relation. `Student_ID`, `Name`, `Department`, and `Age` are attributes of `STUDENT`. Each attribute describes a property of the records.

4. **Domain:** A domain is the set of valid values that an attribute can contain. For example, the domain of `Age` may be positive integers within an allowed range, while the domain of `Grade` may be `{A, B, C, D, F}`. Domains help maintain valid and consistent data.

5. **Relation Schema:** A relation schema describes the structure of a relation, including its name and attributes. It is commonly written as:

   ```text
   STUDENT(Student_ID, Name, Department, Age)
   ```

   The schema describes the design, not the actual records.

6. **Relation Instance:** A relation instance is the set of tuples stored in a relation at a particular point in time. The rows currently present in the `STUDENT` table form its current instance. The instance changes when records are inserted, updated, or deleted.

7. **Degree and Cardinality:** The **degree** of a relation is the number of attributes (columns), while its **cardinality** is the number of tuples (rows). The `STUDENT` relation above has degree 4 and cardinality 3.

8. **Keys:** Keys identify tuples and establish relationships between relations. In `STUDENT`, `Student_ID` can be the primary key. In `ENROLLMENT`, `(Student_ID, Course_ID)` can form a composite primary key. `Student_ID` in `ENROLLMENT` is also a foreign key referencing `STUDENT`.

### Integrity Constraints

Integrity constraints are rules that keep relational data valid and consistent.

- **Domain constraint:** An attribute value must belong to its defined domain. For example, `Age` must contain a valid integer value.
- **Key constraint:** A candidate key must uniquely identify each tuple. Two students cannot have the same `Student_ID`.
- **Entity integrity:** A primary key cannot contain `NULL`, because every row must be identifiable.
- **Referential integrity:** A foreign-key value must refer to an existing key value in the referenced relation, or be `NULL` when the schema permits it. For example, every `Student_ID` in `ENROLLMENT` must refer to a student in `STUDENT`.

### Properties of a Relation

1. Each relation has a unique name within the database.
2. Each attribute has a unique name within its relation.
3. Each cell contains a single value from the attribute's domain in the classical relational model.
4. Duplicate tuples are not allowed in a mathematical relation.
5. The order of rows has no logical significance.
6. The order of columns has no logical significance, although each column is identified by its name.
7. Values in a column belong to the same domain.

In practical SQL tables, duplicate rows can occur unless constraints prevent them, and a query result is not automatically sorted. `DISTINCT` can be used when duplicate elimination is required.

### Example SQL Representation

```sql
CREATE TABLE STUDENT (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(40) NOT NULL,
    Department VARCHAR(20),
    Age        INT CHECK (Age >= 16)
);

CREATE TABLE ENROLLMENT (
    Student_ID INT,
    Course_ID  VARCHAR(10),
    Grade      CHAR(1),
    PRIMARY KEY (Student_ID, Course_ID),
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID)
);
```

### Advantages of the Relational Model

- **Simplicity:** Tables make data easy to understand and represent.
- **Reduced redundancy:** Related information can be stored in separate relations and connected through keys.
- **Data integrity:** Keys and constraints help prevent invalid records and relationships.
- **Data retrieval:** Relational algebra and SQL provide powerful ways to query data.
- **Data independence:** Users work with logical tables without needing to know the physical storage details.

### Conclusion

The Relational Model represents a database as a collection of related tables. Its components—relations, tuples, attributes, domains, schemas, instances, and keys—provide a structured way to store data. Integrity constraints maintain correctness, while SQL enables users to manipulate and retrieve the data.

## Q2. Types of Keys in the Relational Model

> **Question:** Explain different types of keys in the Relational Model with suitable examples.

---

### Definition

A **key** is an attribute or a set of attributes used to identify tuples uniquely in a relation or to establish a relationship between relations. Keys help avoid duplicate records and maintain entity and referential integrity.

Consider the following relations:

```text
STUDENT(Student_ID, Aadhaar_No, Name, Email, Department)
COURSE(Course_ID, Course_Name)
ENROLLMENT(Student_ID, Course_ID, Semester, Grade)
```

Assume `Student_ID`, `Aadhaar_No`, and `Email` are each unique for every student. The following key types can be identified.

### Types of Keys

1. **Super Key:** A super key is any attribute or combination of attributes that uniquely identifies each tuple in a relation. It may contain extra attributes that are not necessary for unique identification.

   Examples in `STUDENT` include `{Student_ID}`, `{Student_ID, Name}`, and `{Email, Department}`. All are super keys if the stated unique attributes identify each student.

2. **Candidate Key:** A candidate key is a **minimal super key**. It uniquely identifies each tuple, and no attribute can be removed from it without losing uniqueness.

   Examples: `Student_ID`, `Aadhaar_No`, and `Email` are candidate keys under the assumptions above. Each can independently identify one student.

3. **Primary Key:** A primary key is the candidate key selected to identify tuples in the relation. It must be unique and cannot contain `NULL` values.

   Example: `Student_ID` may be chosen as the primary key of `STUDENT`.

4. **Alternate Key:** Candidate keys that are not selected as the primary key are called alternate keys.

   Example: If `Student_ID` is the primary key, then `Aadhaar_No` and `Email` are alternate keys.

5. **Foreign Key:** A foreign key is an attribute or group of attributes in one relation that refers to a candidate key—commonly the primary key—of another relation. It maintains referential integrity.

   Example: `Student_ID` in `ENROLLMENT` references `Student_ID` in `STUDENT`. An enrollment cannot refer to a student who does not exist, subject to the defined foreign-key rules.

6. **Composite Key (Compound Key):** A composite key consists of two or more attributes that together uniquely identify a tuple. The individual attributes may not be unique by themselves.

   Example: In `ENROLLMENT`, `(Student_ID, Course_ID)` can be the primary key because a student may enroll in many courses and a course may have many students, but the same student-course pair should occur only once. If repeated attempts are stored, another attribute such as `Attempt_No` may also be required.

7. **Unique Key:** A `UNIQUE` constraint ensures that values in a column or combination of columns do not repeat. It is commonly used to enforce candidate-key-like uniqueness for alternate identifiers such as email addresses. The treatment of `NULL` under `UNIQUE` can vary between DBMS products.

8. **Natural Key:** A natural key is an attribute that has a real-world meaning and can identify an entity, such as an officially assigned registration number.

9. **Surrogate Key:** A surrogate key is an artificial identifier created by the database or application, usually without business meaning. For example, an automatically generated `Student_ID` can be used instead of a long natural identifier. It is generally stable and convenient for relationships.

### Key Relationship

```text
                 SUPER KEY
                     |
             Minimal Super Keys
                     |
               CANDIDATE KEYS
                /          \
       Selected candidate   Other candidates
              |                  |
         PRIMARY KEY        ALTERNATE KEYS
```

A foreign key serves a different purpose: it connects a child relation to a referenced relation rather than necessarily identifying a tuple in the child relation by itself.

### SQL Example

```sql
CREATE TABLE STUDENT (
    Student_ID INT PRIMARY KEY,
    Aadhaar_No CHAR(12) UNIQUE,
    Name       VARCHAR(40) NOT NULL,
    Email      VARCHAR(80) UNIQUE
);

CREATE TABLE COURSE (
    Course_ID   VARCHAR(10) PRIMARY KEY,
    Course_Name VARCHAR(50) NOT NULL
);

CREATE TABLE ENROLLMENT (
    Student_ID INT,
    Course_ID  VARCHAR(10),
    Semester   VARCHAR(10),
    Grade      CHAR(1),
    PRIMARY KEY (Student_ID, Course_ID),
    FOREIGN KEY (Student_ID) REFERENCES STUDENT(Student_ID),
    FOREIGN KEY (Course_ID) REFERENCES COURSE(Course_ID)
);
```

In this example, `Student_ID` is the primary key of `STUDENT`, `Aadhaar_No` and `Email` are unique alternate identifiers, and `(Student_ID, Course_ID)` is a composite primary key of `ENROLLMENT`. The two foreign keys connect enrollment records to valid students and courses.

### Difference Between Primary, Candidate, Super, and Foreign Keys

| Parameter | Super Key | Candidate Key | Primary Key | Foreign Key |
|---|---|---|---|---|
| Meaning | Any attribute set that uniquely identifies a row | Minimal super key | Candidate key selected as the main identifier | Attribute set referencing a key in another relation |
| Uniqueness | Yes | Yes | Yes | Not necessarily |
| Minimality | Not required | Required | Required because it is a candidate key | Not required |
| NULL values | Depends on the attributes and constraints | A candidate key must identify every tuple | Not allowed | May be allowed unless restricted |
| Main purpose | Unique identification | Provide possible identifiers | Identify each row in the relation | Connect related relations |

### Importance of Keys

- Keys prevent duplicate identification of records.
- Primary keys provide a reliable identity for each row.
- Foreign keys prevent invalid references between related tables.
- Candidate and alternate keys allow more than one valid unique identifier.
- Composite keys identify records whose uniqueness depends on multiple attributes.

### Conclusion

Keys are essential components of the Relational Model. Super keys and candidate keys provide unique identification, a primary key is the selected candidate key, alternate keys preserve other unique choices, and foreign keys connect related tables. Composite, natural, and surrogate keys support different database design requirements.

## Q3. Relational Algebra and Its Fundamental Operations

> **Question:** Explain Relational Algebra and discuss its fundamental operations.

---

### Definition

**Relational Algebra** is a procedural query language used in the Relational Model. It takes one or more relations as input and produces a new relation as output. It provides the mathematical foundation for many relational database operations and helps explain how a DBMS processes queries.

### Example Relations

Assume the following schemas:

```text
STUDENT(Student_ID, Name, Department, Age)
COURSE(Course_ID, Course_Name, Department)
ENROLLMENT(Student_ID, Course_ID, Grade)
```

The fundamental operations are selection, projection, union, set difference, Cartesian product, and rename.

### Fundamental Operations

1. **Selection (σ):** Selection retrieves tuples that satisfy a specified condition. It is a row-filtering operation.

   **Syntax:**

   ```text
   σ condition (Relation)
   ```

   **Example:** Select students belonging to the CSE department.

   ```text
   σ Department = 'CSE' (STUDENT)
   ```

   Only rows whose `Department` value is `CSE` are returned.

2. **Projection (π):** Projection retrieves only the required attributes (columns) from a relation. In classical relational algebra, duplicate result tuples are eliminated.

   **Syntax:**

   ```text
   π attribute1, attribute2 (Relation)
   ```

   **Example:** Display student names and departments.

   ```text
   π Name, Department (STUDENT)
   ```

3. **Union (∪):** Union combines tuples from two union-compatible relations. Two relations are union-compatible when they have the same number of attributes and the corresponding attributes have compatible domains.

   **Syntax:**

   ```text
   Relation1 ∪ Relation2
   ```

   **Example:** If `CSE_STUDENT` and `ECE_STUDENT` have the same structure, their union gives all tuples present in either relation.

   ```text
   CSE_STUDENT ∪ ECE_STUDENT
   ```

   Duplicate tuples are eliminated because relations use set semantics.

4. **Set Difference (−):** Set difference returns tuples that belong to the first relation but not to the second. Both relations must be union-compatible.

   **Syntax:**

   ```text
   Relation1 − Relation2
   ```

   **Example:** If `ALL_STUDENTS` and `PLACED_STUDENTS` have the same structure, then:

   ```text
   ALL_STUDENTS − PLACED_STUDENTS
   ```

   returns students who are not included in `PLACED_STUDENTS`.

5. **Cartesian Product (×):** Cartesian product combines every tuple of the first relation with every tuple of the second relation. If the first relation has `m` tuples and the second has `n` tuples, the result contains `m × n` tuple combinations.

   **Syntax:**

   ```text
   Relation1 × Relation2
   ```

   **Example:**

   ```text
   STUDENT × COURSE
   ```

   If `STUDENT` has 3 rows and `COURSE` has 2 rows, the result has 6 combinations. Attribute names may need qualification when both relations contain attributes with the same name.

6. **Rename (ρ):** Rename changes the name of a relation or its attributes. It is useful when the same relation is used more than once or when a clearer name is required.

   **Syntax and example:**

   ```text
   ρ S (STUDENT)
   ```

   This creates a renamed relation reference `S` for the `STUDENT` relation. Rename can also be used to assign new attribute names.

### Derived Operations

The following operations can be expressed using the fundamental operations but are commonly used for convenience.

1. **Intersection (∩):** Returns tuples common to both union-compatible relations.

   ```text
   CSE_STUDENT ∩ SCHOLARSHIP_STUDENT
   ```

2. **Join (⋈):** Combines related tuples from two relations based on a join condition. A join can be expressed using Cartesian product followed by selection.

   ```text
   STUDENT ⋈ STUDENT.Student_ID = ENROLLMENT.Student_ID ENROLLMENT
   ```

   A natural join automatically matches attributes with the same name and compatible domains, such as `Student_ID` in `STUDENT` and `ENROLLMENT`.

3. **Division (÷):** Used for queries involving the idea of “for all.” For example, it can find students who are enrolled in **all** required courses.

   If `ENROLLMENT(Student_ID, Course_ID)` and `REQUIRED(Course_ID)` are given, then:

   ```text
   ENROLLMENT ÷ REQUIRED
   ```

   returns the `Student_ID` values associated with every course in `REQUIRED`.

### Relational Algebra Expression Example

**Question:** Find the names of students enrolled in the DBMS course.

First, join `STUDENT` with `ENROLLMENT` using `Student_ID`, then join with `COURSE` using `Course_ID`, select the DBMS course, and project the student names.

```text
π Name (
    σ Course_Name = 'DBMS' (
        STUDENT ⋈ ENROLLMENT ⋈ COURSE
    )
)
```

The expression can also be written with explicit join conditions if the relations contain attributes with overlapping names.

### Summary of Fundamental Operations

| Operation | Symbol | Purpose | Result |
|---|---|---|---|
| Selection | σ | Filters rows using a condition | Selected tuples |
| Projection | π | Selects required columns | Selected attributes |
| Union | ∪ | Combines two union-compatible relations | Tuples in either relation |
| Set Difference | − | Finds tuples in the first relation but not the second | Remaining tuples of first relation |
| Cartesian Product | × | Combines every row of one relation with every row of another | All row combinations |
| Rename | ρ | Renames a relation or its attributes | Renamed relation |

### Importance of Relational Algebra

- It gives a formal foundation for relational query processing.
- It represents queries as a sequence of well-defined operations.
- It helps a DBMS transform and optimize queries.
- It supports reasoning about the correctness of query expressions.
- Its operations form the basis for understanding SQL queries.

### Conclusion

Relational Algebra is a formal language for manipulating relations. Its six fundamental operations—selection, projection, union, set difference, Cartesian product, and rename—can be combined to express complex queries. Derived operations such as join, intersection, and division make relational queries more convenient.

## Q4. DDL Commands with Syntax and Examples

> **Question:** Explain DDL commands with syntax and examples.

---

### Definition

**Data Definition Language (DDL)** is a category of SQL commands used to define, create, modify, and remove database structures. DDL mainly works on schema objects such as databases, tables, and other database objects rather than directly manipulating individual table records.

### Main DDL Commands

#### 1. CREATE

The `CREATE` command is used to create a new database object, such as a database or table.

**Syntax:**

```sql
CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    ...
);
```

**Example:**

```sql
CREATE TABLE STUDENT (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(40) NOT NULL,
    Department VARCHAR(20),
    Age        INT CHECK (Age >= 16)
);
```

This creates a table named `STUDENT` with four columns. It also defines a primary key, a `NOT NULL` constraint, and a `CHECK` constraint.

#### 2. ALTER

The `ALTER` command modifies the structure of an existing table. Depending on the DBMS, it can add, modify, or remove columns and constraints.

**Add a column:**

```sql
ALTER TABLE STUDENT
ADD Email VARCHAR(80);
```

**Drop a column:**

```sql
ALTER TABLE STUDENT
DROP COLUMN Email;
```

**Add a constraint:**

```sql
ALTER TABLE STUDENT
ADD CONSTRAINT uq_student_email UNIQUE (Email);
```

The exact syntax for changing a column's data type or renaming a column differs among DBMS products.

#### 3. DROP

The `DROP` command permanently removes a database object, including its definition and the data stored in it.

**Syntax:**

```sql
DROP TABLE table_name;
```

**Example:**

```sql
DROP TABLE STUDENT;
```

This removes the `STUDENT` table. It cannot be queried afterward unless it is created again and its data is restored or reinserted. Dependencies such as foreign keys may prevent a table from being dropped unless they are handled first.

#### 4. TRUNCATE

The `TRUNCATE` command removes all rows from a table while keeping the table structure available for future use.

**Syntax:**

```sql
TRUNCATE TABLE table_name;
```

**Example:**

```sql
TRUNCATE TABLE STUDENT;
```

This removes all records from `STUDENT`, but the table and its column definitions remain. Features such as rollback behavior, identity-counter reset, and foreign-key restrictions vary by DBMS.

#### 5. RENAME

The `RENAME` operation changes the name of an existing database object. Its exact syntax is DBMS-specific.

**Example syntax used by some DBMS products:**

```sql
ALTER TABLE STUDENT
RENAME TO STUDENT_DETAILS;
```

After renaming, the table is referred to as `STUDENT_DETAILS`. Other systems may provide a separate `RENAME TABLE` statement or a different form of `ALTER TABLE`.

### Difference Between DROP, TRUNCATE, and DELETE

| Parameter | DROP | TRUNCATE | DELETE |
|---|---|---|---|
| SQL category | DDL | Commonly classified as DDL | DML |
| Effect | Removes the table object | Removes all rows | Removes selected rows or all rows |
| Table structure | Removed | Retained | Retained |
| WHERE condition | Not applicable | Not supported in the usual command form | Supported |
| Can remove selected rows | No | No | Yes |
| Typical use | Remove an unwanted table | Empty a table quickly | Remove specific records |

The transaction and logging behavior of `TRUNCATE` and `DROP` depends on the DBMS. `DELETE` is generally used when row-level filtering or row-level trigger behavior is required.

### Advantages of DDL

- It creates the structures needed to store database information.
- It allows the schema to evolve as application requirements change.
- It defines constraints that help maintain data integrity.
- It allows unwanted database objects to be removed.
- It separates database structure definition from record manipulation.

### Conclusion

DDL commands define and manage the structure of a database. `CREATE` builds objects, `ALTER` changes their structure, `DROP` removes objects, `TRUNCATE` empties a table while retaining its structure, and `RENAME` changes an object's name. These commands are essential for database schema management.

## Q5. DML Commands with Syntax and Examples

> **Question:** Explain DML commands with syntax and examples.

---

### Definition

**Data Manipulation Language (DML)** is the part of SQL used to retrieve and manipulate the data stored in database tables. The main data-changing DML commands are `INSERT`, `UPDATE`, and `DELETE`. `SELECT` is used to retrieve data and is often classified separately as **Data Query Language (DQL)**, although some introductory classifications include it under DML.

Consider the following table:

```text
STUDENT(Student_ID, Name, Department, Age)
```

### Main DML Commands

#### 1. INSERT

The `INSERT` command adds new rows to a table.

**Insert values into all columns:**

```sql
INSERT INTO STUDENT (Student_ID, Name, Department, Age)
VALUES (101, 'Arun', 'CSE', 20);
```

**Insert multiple rows:**

```sql
INSERT INTO STUDENT (Student_ID, Name, Department, Age)
VALUES
    (102, 'Bina', 'ECE', 19),
    (103, 'Charan', 'CSE', 21);
```

Column names should be specified when possible because this makes the statement clear and avoids depending on the table's physical column order. Values must satisfy the table's data types and constraints.

#### 2. UPDATE

The `UPDATE` command modifies existing rows in a table. The `SET` clause specifies the new values, and the `WHERE` clause identifies which rows should be changed.

**Syntax:**

```sql
UPDATE table_name
SET column_name = value
WHERE condition;
```

**Example:**

```sql
UPDATE STUDENT
SET Department = 'IT'
WHERE Student_ID = 101;
```

This changes the department of the student whose ID is 101.

**Important:** If the `WHERE` clause is omitted, every row in the table is updated.

```sql
UPDATE STUDENT
SET Department = 'CSE';
```

The above statement changes the department of all students to `CSE`.

#### 3. DELETE

The `DELETE` command removes rows from a table. The `WHERE` clause determines which rows are deleted.

**Syntax:**

```sql
DELETE FROM table_name
WHERE condition;
```

**Example:**

```sql
DELETE FROM STUDENT
WHERE Student_ID = 103;
```

This removes the student record whose ID is 103.

**Important:** If the `WHERE` clause is omitted, all rows are deleted, but the table structure remains.

```sql
DELETE FROM STUDENT;
```

#### 4. SELECT (Data Retrieval)

The `SELECT` command retrieves data from one or more tables. It is commonly taught alongside DML commands, but is also classified separately as DQL.

**Syntax:**

```sql
SELECT column1, column2
FROM table_name
WHERE condition;
```

**Example:**

```sql
SELECT Name, Age
FROM STUDENT
WHERE Department = 'CSE';
```

This displays the names and ages of students belonging to the CSE department without changing the stored data.

### Summary of DML and Retrieval Commands

| Command | Purpose | Example |
|---|---|---|
| INSERT | Adds new rows | `INSERT INTO STUDENT (...) VALUES (...);` |
| UPDATE | Modifies existing rows | `UPDATE STUDENT SET Age = 21 WHERE Student_ID = 101;` |
| DELETE | Removes rows | `DELETE FROM STUDENT WHERE Student_ID = 101;` |
| SELECT (DQL) | Retrieves rows and columns | `SELECT * FROM STUDENT;` |

### Difference Between DDL and DML

| Parameter | DDL | DML |
|---|---|---|
| Full form | Data Definition Language | Data Manipulation Language |
| Main purpose | Defines or changes database structure | Manipulates stored records |
| Operates on | Schema objects such as tables | Rows stored in tables |
| Common commands | `CREATE`, `ALTER`, `DROP`, `TRUNCATE` | `INSERT`, `UPDATE`, `DELETE` |
| Example | `CREATE TABLE STUDENT (...);` | `INSERT INTO STUDENT ...;` |

### Importance of DML

- It allows new records to be stored in database tables.
- It enables existing information to be corrected or updated.
- It removes records that are no longer required.
- It retrieves the information needed by users and applications through SQL queries.
- It works with transaction control to help maintain reliable changes to data.

### Conclusion

DML commands manipulate the records stored in database tables. `INSERT` adds rows, `UPDATE` modifies rows, and `DELETE` removes rows. `SELECT`, often classified as DQL, retrieves the required data. Together, these commands support the everyday operations performed on a relational database.

## Q6. SQL Functions with Examples

> **Question:** Explain SQL functions with suitable examples.

---

### Definition

**SQL functions** are built-in operations that accept input values, perform a calculation or transformation, and return a result. They are used to process text, numbers, dates, and groups of rows. SQL functions reduce the need to perform common calculations outside the database.

SQL functions are mainly classified into **single-row (scalar) functions** and **aggregate (group) functions**.

### 1. Single-Row (Scalar) Functions

A single-row function operates on a value from one row and returns one result for that row. It can be used in clauses such as `SELECT`, `WHERE`, and `ORDER BY`, depending on the function and DBMS.

#### A. Character or String Functions

These functions manipulate character data.

| Function | Purpose | Example | Result |
|---|---|---|---|
| `UPPER()` | Converts text to uppercase | `UPPER('aditya')` | `ADITYA` |
| `LOWER()` | Converts text to lowercase | `LOWER('DBMS')` | `dbms` |
| `LENGTH()` | Returns the length of a string | `LENGTH('SQL')` | `3` in common systems |
| `CONCAT()` | Joins strings | `CONCAT('Data', 'Base')` | `DataBase` |
| `TRIM()` | Removes leading and trailing spaces | `TRIM('  SQL  ')` | `SQL` |

`LENGTH()` and concatenation syntax can differ across DBMS products. For example, some systems use `LEN()` or the `||` operator for concatenation.

**Example:**

```sql
SELECT UPPER(Name) AS Upper_Name
FROM STUDENT;
```

This displays each student's name in uppercase without changing the stored value.

#### B. Numeric Functions

Numeric functions perform mathematical operations on numeric values.

| Function | Purpose | Example | Result |
|---|---|---|---:|
| `ABS()` | Returns the absolute value | `ABS(-15)` | 15 |
| `ROUND()` | Rounds a number | `ROUND(12.567, 2)` | 12.57 |
| `CEIL()` / `CEILING()` | Rounds upward to an integer | `CEIL(4.2)` | 5 |
| `FLOOR()` | Rounds downward to an integer | `FLOOR(4.8)` | 4 |
| `MOD()` | Returns the remainder | `MOD(10, 3)` | 1 |

**Example:**

```sql
SELECT ROUND(Percentage, 2) AS Rounded_Percentage
FROM RESULTS;
```

This returns the percentage rounded to two decimal places.

#### C. Date and Time Functions

Date and time functions return or manipulate date and time values.

| Function | Purpose | Example |
|---|---|---|
| `CURRENT_DATE` | Returns the current date | `SELECT CURRENT_DATE;` |
| `CURRENT_TIME` | Returns the current time | `SELECT CURRENT_TIME;` |
| `CURRENT_TIMESTAMP` | Returns the current date and time | `SELECT CURRENT_TIMESTAMP;` |

Date arithmetic and formatting functions vary considerably between DBMS products. For example, extracting a year or adding days to a date may use different syntax in MySQL, PostgreSQL, Oracle, and SQL Server.

#### D. Conversion Functions

Conversion functions change a value from one data type to another.

**Example using `CAST`:**

```sql
SELECT CAST('250' AS INTEGER) AS Number_Value;
```

This converts the character value `'250'` into an integer where the conversion is valid.

#### E. NULL-Handling Functions

These functions help process `NULL` values.

- **`COALESCE(value1, value2, ...)`:** Returns the first non-`NULL` expression.

  ```sql
  SELECT Name, COALESCE(Email, 'Not Provided') AS Email_Display
  FROM STUDENT;
  ```

- **`NULLIF(value1, value2)`:** Returns `NULL` when the two expressions are equal; otherwise, it returns the first expression.

  ```sql
  SELECT NULLIF(10, 10) AS Result;
  ```

  The result is `NULL`. These functions are especially useful when handling optional values and avoiding invalid calculations.

### 2. Aggregate Functions

An **aggregate function** performs a calculation over a set of rows and returns one result for the entire set or for each group.

Consider the table `EMPLOYEE(Emp_ID, Name, Department, Salary)`.

| Emp_ID | Name | Department | Salary |
|---:|---|---|---:|
| 1 | Arun | CSE | 40000 |
| 2 | Bina | CSE | 50000 |
| 3 | Charan | ECE | 45000 |
| 4 | Divya | ECE | 55000 |

| Function | Purpose | Example |
|---|---|---|
| `COUNT()` | Counts rows or non-NULL values | `COUNT(*)` |
| `SUM()` | Calculates the total | `SUM(Salary)` |
| `AVG()` | Calculates the average | `AVG(Salary)` |
| `MIN()` | Finds the minimum value | `MIN(Salary)` |
| `MAX()` | Finds the maximum value | `MAX(Salary)` |

**Example:**

```sql
SELECT
    COUNT(*) AS Employee_Count,
    SUM(Salary) AS Total_Salary,
    AVG(Salary) AS Average_Salary,
    MIN(Salary) AS Minimum_Salary,
    MAX(Salary) AS Maximum_Salary
FROM EMPLOYEE;
```

This query returns one row containing the overall statistics for the employee table.

### Difference Between Single-Row and Aggregate Functions

| Parameter | Single-Row Function | Aggregate Function |
|---|---|---|
| Input | A value from an individual row | A set or group of rows |
| Output | One result per input row | One result per set or group |
| Main use | Transform or calculate individual values | Summarize multiple records |
| Examples | `UPPER()`, `ROUND()`, `LENGTH()` | `COUNT()`, `SUM()`, `AVG()` |
| Common use | Formatting names or calculating row values | Finding totals, averages, minimums, and maximums |

### Important Points About Aggregate Functions

1. Most aggregate functions ignore `NULL` values in the target expression.
2. `COUNT(*)` counts rows, including rows containing `NULL` in some columns.
3. `COUNT(column_name)` counts only rows where that column is not `NULL`.
4. `COUNT(DISTINCT column_name)` counts distinct non-`NULL` values in that column.
5. Aggregate functions can be applied to the complete table or separately to groups using `GROUP BY`.

### Conclusion

SQL functions perform useful operations directly inside database queries. Single-row functions process individual values, while aggregate functions summarize multiple rows. String, numeric, date, conversion, and NULL-handling functions make SQL queries more flexible and reduce the need for external calculations.

## Q7. GROUP BY and HAVING Clauses with Aggregate Functions

> **Question:** Explain the GROUP BY and HAVING clauses in SQL. Discuss how they are used with aggregate functions with suitable examples.

---

### Introduction

The `GROUP BY` and `HAVING` clauses are used to summarize table records. **GROUP BY** divides rows into groups based on one or more columns, while **HAVING** filters those groups using a condition. They are commonly used with aggregate functions such as `COUNT()`, `SUM()`, `AVG()`, `MIN()`, and `MAX()`.

Consider the following `EMPLOYEE` table:

| Emp_ID | Name | Department | Salary |
|---:|---|---|---:|
| 1 | Arun | CSE | 40000 |
| 2 | Bina | CSE | 50000 |
| 3 | Charan | ECE | 45000 |
| 4 | Divya | ECE | 55000 |
| 5 | Esha | IT | 35000 |

### 1. GROUP BY Clause

The `GROUP BY` clause combines rows that have the same value in one or more specified columns. Aggregate functions can then calculate a result for each group.

**Syntax:**

```sql
SELECT column_name, aggregate_function(column_name)
FROM table_name
GROUP BY column_name;
```

**Example: Find the total salary in each department.**

```sql
SELECT Department, SUM(Salary) AS Total_Salary
FROM EMPLOYEE
GROUP BY Department;
```

**Result:**

| Department | Total_Salary |
|---|---:|
| CSE | 90000 |
| ECE | 100000 |
| IT | 35000 |

The DBMS groups employees by department and calculates the salary total for each department.

### 2. HAVING Clause

The `HAVING` clause filters the groups formed by `GROUP BY`. It is generally used with aggregate functions because it applies a condition to the summarized result.

**Syntax:**

```sql
SELECT column_name, aggregate_function(column_name)
FROM table_name
GROUP BY column_name
HAVING aggregate_condition;
```

**Example: Display departments whose total salary is greater than 50,000.**

```sql
SELECT Department, SUM(Salary) AS Total_Salary
FROM EMPLOYEE
GROUP BY Department
HAVING SUM(Salary) > 50000;
```

**Result:**

| Department | Total_Salary |
|---|---:|
| CSE | 90000 |
| ECE | 100000 |

The IT department is excluded because its total salary is only 35,000.

### 3. Using WHERE and HAVING Together

`WHERE` filters individual rows **before grouping**, while `HAVING` filters completed groups **after grouping**.

**Example: Consider only employees earning more than 40,000, then show departments having at least two such employees.**

```sql
SELECT Department, COUNT(*) AS Employee_Count
FROM EMPLOYEE
WHERE Salary > 40000
GROUP BY Department
HAVING COUNT(*) >= 2;
```

The `WHERE` clause first removes employees whose salary is 40,000 or less. The remaining rows are grouped by department. Finally, `HAVING` keeps only groups containing at least two employees.

### 4. Other Aggregate Examples with GROUP BY

**Count employees in each department:**

```sql
SELECT Department, COUNT(*) AS Employee_Count
FROM EMPLOYEE
GROUP BY Department;
```

**Find the average salary in each department:**

```sql
SELECT Department, AVG(Salary) AS Average_Salary
FROM EMPLOYEE
GROUP BY Department;
```

**Find the highest salary in each department:**

```sql
SELECT Department, MAX(Salary) AS Highest_Salary
FROM EMPLOYEE
GROUP BY Department;
```

### Logical Processing Order

A simplified logical processing order for a grouped `SELECT` query is:

```text
FROM
  |
  v
WHERE       -- filters individual rows
  |
  v
GROUP BY    -- forms groups
  |
  v
HAVING      -- filters groups
  |
  v
SELECT      -- produces selected expressions
  |
  v
ORDER BY    -- sorts the final result
```

This is the logical order used to understand query evaluation; it does not necessarily describe the physical execution plan chosen by the optimizer.

### Difference Between WHERE and HAVING

| Parameter | WHERE | HAVING |
|---|---|---|
| Purpose | Filters individual rows | Filters groups of rows |
| Processing stage | Before grouping | After grouping |
| Used with aggregate results | Cannot normally filter an aggregate result directly | Commonly used with aggregate functions |
| Requires GROUP BY | No | Often used with `GROUP BY`, but can also be used on an aggregate query without grouping |
| Example | `WHERE Salary > 40000` | `HAVING AVG(Salary) > 40000` |
| Effect | Determines which rows enter groups | Determines which groups appear in the result |

### Rules for GROUP BY and HAVING

1. Every selected column that is not inside an aggregate function generally must appear in the `GROUP BY` clause, according to standard SQL grouping rules.
2. Aggregate functions such as `SUM()` and `AVG()` are commonly used in the `SELECT` and `HAVING` clauses.
3. `WHERE` is used for row-level conditions; `HAVING` is used for group-level conditions.
4. More than one column can be specified in `GROUP BY` to create groups based on combinations of values.
5. `ORDER BY` can be used after grouping to sort the final summarized rows.

### Conclusion

`GROUP BY` divides table rows into groups and allows aggregate functions to calculate summaries for each group. `HAVING` filters those grouped results, while `WHERE` filters rows before grouping. Together, these clauses are useful for reports such as department-wise salary totals, employee counts, and average marks.

## Q8. NULL Values and Methods of Handling NULL Values

> **Question:** Explain NULL values and methods of handling NULL values.

---

### Definition

In SQL, **NULL** represents the absence of a known or applicable value. It may indicate that a value is unknown, missing, or not applicable. `NULL` is different from zero, an empty string, or a blank space.

For example, a student's phone number may be `NULL` if it has not been provided. The database does not treat that missing value as the number zero.

### Characteristics of NULL Values

1. `NULL` represents missing, unknown, or inapplicable information.
2. `NULL` is not equal to zero or an empty string.
3. A comparison such as `NULL = NULL` does not evaluate to `TRUE`; it evaluates to `UNKNOWN`.
4. Arithmetic expressions involving `NULL` generally produce `NULL`.
5. SQL uses three-valued logic—`TRUE`, `FALSE`, and `UNKNOWN`—to evaluate conditions involving `NULL`.
6. Aggregate functions such as `SUM()` and `AVG()` generally ignore `NULL` values in the expression being aggregated.

### Three-Valued Logic

A condition involving `NULL` may produce `UNKNOWN` rather than `TRUE` or `FALSE`.

For example:

```sql
SELECT *
FROM STUDENT
WHERE Email = NULL;
```

This is incorrect for checking missing email values because the comparison produces `UNKNOWN`. The `WHERE` clause returns only rows for which the condition is `TRUE`, so rows with a `NULL` email are not selected.

The correct form is:

```sql
SELECT *
FROM STUDENT
WHERE Email IS NULL;
```

To find rows where a value is present:

```sql
SELECT *
FROM STUDENT
WHERE Email IS NOT NULL;
```

### Methods of Handling NULL Values

#### 1. IS NULL and IS NOT NULL

These operators check whether a column contains a `NULL` value.

```sql
SELECT Name
FROM STUDENT
WHERE Email IS NULL;
```

This returns students whose email address has not been stored.

```sql
SELECT Name
FROM STUDENT
WHERE Email IS NOT NULL;
```

This returns students with a known email value.

#### 2. COALESCE()

`COALESCE()` returns the first non-`NULL` expression from the supplied list. It is useful for displaying a default value when a column is missing.

**Syntax:**

```sql
COALESCE(expression1, expression2, ...)
```

**Example:**

```sql
SELECT Name,
       COALESCE(Email, 'Not Provided') AS Email_Status
FROM STUDENT;
```

If `Email` is `NULL`, the query displays `Not Provided`. Otherwise, it displays the actual email address. This changes the query result, not the stored table value.

#### 3. NULLIF()

`NULLIF(expression1, expression2)` returns `NULL` when the two expressions are equal; otherwise, it returns the first expression. It can help avoid division by zero.

**Example:**

```sql
SELECT Total_Marks / NULLIF(Subjects, 0) AS Average_Marks
FROM RESULT_SUMMARY;
```

If `Subjects` is zero, `NULLIF(Subjects, 0)` returns `NULL`, so the expression does not attempt division by zero. The final result for that row becomes `NULL`.

#### 4. CASE Expression

The `CASE` expression applies conditional logic and can replace `NULL` with a display value.

```sql
SELECT Name,
       CASE
           WHEN Email IS NULL THEN 'Email Missing'
           ELSE Email
       END AS Email_Status
FROM STUDENT;
```

This displays a message when the email value is missing.

#### 5. Default Values and NOT NULL Constraints

A suitable default can be assigned when a new record is inserted, and `NOT NULL` can be used when a value is mandatory.

```sql
CREATE TABLE STUDENT (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(40) NOT NULL,
    City       VARCHAR(30) DEFAULT 'Not Specified'
);
```

Here, `Name` must be supplied. If `City` is omitted during insertion, the defined default is used. An explicitly supplied `NULL` does not necessarily invoke the default; behavior depends on how the `INSERT` statement is written and the DBMS rules.

#### 6. Aggregate Functions and NULL

Aggregate functions handle `NULL` values in specific ways.

| Expression | Treatment of NULL |
|---|---|
| `COUNT(*)` | Counts all rows |
| `COUNT(Email)` | Counts rows where `Email` is not `NULL` |
| `COUNT(DISTINCT Email)` | Counts distinct non-`NULL` email values |
| `SUM(Salary)` | Ignores `NULL` salary values |
| `AVG(Salary)` | Calculates the average using non-`NULL` salary values |
| `MIN(Salary)` / `MAX(Salary)` | Ignores `NULL` values when finding the minimum or maximum |

**Example:**

```sql
SELECT COUNT(*) AS Total_Students,
       COUNT(Email) AS Students_With_Email
FROM STUDENT;
```

The two counts may differ because `COUNT(*)` includes every row, while `COUNT(Email)` excludes rows where `Email` is `NULL`.

### Problems Caused by NULL Values

- Comparisons involving `NULL` can produce `UNKNOWN`, which may affect filtering conditions.
- Arithmetic calculations can return `NULL` when an operand is `NULL`.
- Aggregate results may be affected because many aggregate functions ignore missing values.
- A missing value may have different meanings, such as unknown or not applicable, which can make interpretation difficult.
- Conditions using `NOT IN` can behave unexpectedly if the subquery result contains `NULL`; `NOT EXISTS` is often a safer alternative for such queries.

### Best Practices

1. Use `NOT NULL` for attributes that must always contain a value.
2. Use `IS NULL` and `IS NOT NULL` to test missing values; do not use `= NULL` or `<> NULL`.
3. Use `COALESCE()` when a suitable replacement value is required in query output or calculations.
4. Do not replace missing values with zero unless zero has the correct meaning for that attribute.
5. Consider how aggregate functions treat `NULL` before interpreting totals, averages, and counts.
6. Choose default values only when they represent a meaningful business rule.

### Conclusion

`NULL` represents missing, unknown, or inapplicable information in SQL. Since it is different from zero or an empty string, it requires special handling. Operators such as `IS NULL`, functions such as `COALESCE()` and `NULLIF()`, `CASE` expressions, constraints, and careful use of aggregate functions help process `NULL` values correctly.
