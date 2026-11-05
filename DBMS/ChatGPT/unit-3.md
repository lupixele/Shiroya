# UNIT 3 — ER Model, Constraints, Joins, Subqueries & Views

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

## Q1. Entity–Relationship (ER) Model

> **Question:** Explain the ER Model with neat diagrams.

---

### Definition

The **Entity–Relationship (ER) Model** is a high-level conceptual data model used to represent the structure of a database. It describes real-world objects as **entities**, their properties as **attributes**, and the associations between entities as **relationships**. An ER diagram provides a visual representation of these elements before the database is converted into relational tables.

The ER model is mainly used during the conceptual design stage of database development. It helps database designers understand the data requirements and communicate the design clearly with users.

### Basic Components of the ER Model

1. **Entity:** An entity is a distinguishable real-world object or concept about which data is stored. Examples include a student, course, employee, or department. An entity type is represented by a rectangle.

2. **Entity Set:** An entity set is a collection of similar entities. For example, all students in a college form the `STUDENT` entity set.

3. **Attribute:** An attribute describes a property of an entity or relationship. For a `STUDENT`, attributes may include `Student_ID`, `Name`, `Age`, and `Email`. An attribute is represented by an oval.

4. **Relationship:** A relationship represents an association between two or more entities. For example, a student **ENROLLS_IN** a course. A relationship is represented by a diamond.

5. **Key Attribute:** A key attribute uniquely identifies each entity in an entity set. For example, `Student_ID` uniquely identifies a student. It is conventionally shown with an underline in an ER diagram.

### Example ER Diagram

A college database contains students and courses. A student can enroll in many courses, and a course can have many students.

```text
       (Student_ID)                         (Course_ID)
            |                                    |
        +---------+       +-------------+    +---------+
        | STUDENT |-------| ENROLLS_IN  |----| COURSE  |
        +---------+  M:N  +-------------+    +---------+
            |                                    |
         (Name)                              (Title)
```

Here, `STUDENT` and `COURSE` are entity types. `ENROLLS_IN` is the relationship, and `M:N` indicates a many-to-many relationship. A student may enroll in multiple courses, and each course may contain multiple students.

### Types of Relationships Based on Cardinality

1. **One-to-One (1:1):** One entity of set A is associated with at most one entity of set B, and vice versa. Example: one person is assigned one passport, and each passport belongs to one person.

   ```text
   +--------+       1 : 1       +----------+
   | PERSON |-------------------| PASSPORT |
   +--------+                   +----------+
   ```

2. **One-to-Many (1:N):** One entity in set A can be associated with many entities in set B, but each entity in B is associated with one entity in A. Example: one department employs many employees.

   ```text
   +------------+      1 : N      +----------+
   | DEPARTMENT |-----------------| EMPLOYEE |
   +------------+                 +----------+
   ```

3. **Many-to-One (N:1):** Many entities in set A are associated with one entity in set B. Example: many employees work in one department. This is the reverse direction of a one-to-many relationship.

4. **Many-to-Many (M:N):** Many entities in set A can be associated with many entities in set B. Example: students enroll in many courses, and each course has many students.

### Types of Participation Constraints

- **Total participation:** Every entity in an entity set must participate in the relationship. It is conventionally represented by a double line. For example, if every employee must belong to a department, `EMPLOYEE` has total participation in `WORKS_FOR`.
- **Partial participation:** Only some entities are required to participate in the relationship. It is represented by a single line. For example, not every employee may manage a department.

### Strong and Weak Entities

- **Strong entity:** An entity that has its own primary key and can be identified independently. It is represented by a single rectangle. `STUDENT(Student_ID, Name)` is an example.
- **Weak entity:** An entity that cannot be uniquely identified by its own attributes alone. It depends on an owner entity and is identified using its **partial key** together with the owner's key. It is represented by a double rectangle. Its identifying relationship is represented by a double diamond.

For example, a dependent may be identified by `(Employee_ID, Dependent_Name)` because `Dependent_Name` alone may not be unique.

```text
+------------+       <<HAS>>       ++-----------++
| EMPLOYEE   |=====================|| DEPENDENT ||
+------------+                     ++-----------++
  Employee_ID                         Dependent_Name
  (Primary Key)                       (Partial Key)
```

### Advantages of the ER Model

1. It provides a simple visual representation of database requirements.
2. It helps identify entities, attributes, keys, and relationships before implementation.
3. It makes cardinality and participation rules clear.
4. It helps designers detect missing or incorrect relationships.
5. It can be converted into a relational database schema.

### Conversion of ER Model into Relational Tables

A basic conversion follows these rules:

- Each strong entity generally becomes a table, and its key becomes the primary key.
- A one-to-many relationship is usually implemented by placing the primary key of the one-side entity as a foreign key in the many-side table.
- A many-to-many relationship is implemented using a separate junction table containing foreign keys to both entities.
- A multivalued attribute is generally converted into a separate table.

For the student-course example:

```sql
CREATE TABLE Student (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(60) NOT NULL
);

CREATE TABLE Course (
    Course_ID INT PRIMARY KEY,
    Title     VARCHAR(80) NOT NULL
);

CREATE TABLE Enrollment (
    Student_ID INT,
    Course_ID  INT,
    Enroll_Date DATE,
    PRIMARY KEY (Student_ID, Course_ID),
    FOREIGN KEY (Student_ID) REFERENCES Student(Student_ID),
    FOREIGN KEY (Course_ID) REFERENCES Course(Course_ID)
);
```

The `ENROLLMENT` table resolves the many-to-many relationship between students and courses.

## Q2. Attributes and Relationships in the ER Model

> **Question:** Explain different types of attributes and relationships in the ER Model.

---

### Introduction

In the **ER model**, attributes describe the properties of entities or relationships, while relationships describe associations among entities. Attributes help define what information is stored, and relationship types explain how entity sets are connected.

### Types of Attributes

1. **Simple (Atomic) Attribute:** An attribute that cannot be divided into smaller meaningful parts. Examples include `Age`, `Gender`, and `Salary`.

2. **Composite Attribute:** An attribute that can be divided into smaller sub-attributes. For example, `Address` can be divided into `Street`, `City`, `State`, and `PIN_Code`. Similarly, `Name` may be divided into `First_Name` and `Last_Name`.

   ```text
                     (Address)
                    /    |    \
             (Street) (City) (PIN_Code)
   ```

3. **Single-Valued Attribute:** An attribute that has only one value for each entity at a particular time. For example, a student has one current date of birth.

4. **Multi-Valued Attribute:** An attribute that can have multiple values for one entity. For example, an employee may have multiple phone numbers. It is conventionally represented by a double oval.

   ```text
          +----------+
          | EMPLOYEE |
          +----------+
                |
          ((Phone_No))
   ```

5. **Stored Attribute:** An attribute whose value is stored directly in the database. For example, `Date_of_Birth` is stored in the `STUDENT` table.

6. **Derived Attribute:** An attribute whose value can be calculated from another attribute. For example, `Age` can be derived from `Date_of_Birth`. It is conventionally represented by a dashed oval. Derived values are often calculated when needed rather than stored permanently.

   ```text
      (Date_of_Birth) ---- +---------+
                           | STUDENT |
      (Age - - - - - - -)  +---------+
         Derived
   ```

7. **Key Attribute:** An attribute whose value uniquely identifies an entity. For example, `Student_ID` uniquely identifies each student. It is represented by an underlined attribute name.

8. **Null or Optional Attribute:** An attribute that may have no value for some entities. For example, `Middle_Name` may be absent for some students. In a relational implementation, the column may allow `NULL`.

9. **Complex Attribute:** An attribute formed by combining composite and multivalued characteristics. For example, an employee can have multiple addresses, and each address can contain street, city, and PIN code.

### Types of Relationships Based on Degree

The **degree of a relationship** is the number of entity types participating in that relationship.

1. **Unary (Recursive) Relationship:** An entity type is related to itself. Example: an employee supervises another employee.

   ```text
             +----------+
             | EMPLOYEE |
             +----------+
                 ^  |
                 |  |
             SUPERVISES
             (recursive)
   ```

2. **Binary Relationship:** A relationship between two entity types. Example: a student enrolls in a course. Binary relationships are the most common.

   ```text
   +---------+      +-----------+      +--------+
   | STUDENT |------| ENROLLS   |------| COURSE |
   +---------+      +-----------+      +--------+
   ```

3. **Ternary Relationship:** A relationship among three entity types. Example: a supplier supplies a part to a project. The association is represented by one ternary relationship because the complete fact involves all three entities together.

   ```text
                 +-----------+
                 |  SUPPLIER |
                 +-----------+
                       \
                        \
                     +----------+
   +--------+---------| SUPPLIES |---------+---------+
   | PART   |         +----------+         | PROJECT |
   +--------+                              +---------+
   ```

4. **N-ary Relationship:** A relationship involving more than three entity types. For example, a single transaction may associate a supplier, part, project, warehouse, and delivery date.

### Types of Relationships Based on Cardinality

| Relationship | Meaning | Example |
|---|---|---|
| One-to-One (1:1) | Each entity is related to at most one entity on the other side. | Person — Passport |
| One-to-Many (1:N) | One entity can be related to many entities. | Department — Employees |
| Many-to-One (N:1) | Many entities are related to one entity. | Employees — Department |
| Many-to-Many (M:N) | Many entities on both sides can be related. | Students — Courses |

### Participation Constraints

- **Total participation** means every entity in the participating entity set must take part in at least one relationship instance. It is shown using a double line.
- **Partial participation** means participation is optional for some entities. It is shown using a single line.

For example, if every `EMPLOYEE` must work for a `DEPARTMENT`, employee participation in `WORKS_FOR` is total. If a department may temporarily have no employees, department participation may be partial.

### Difference Between Attributes and Relationships

| Attribute | Relationship |
|---|---|
| Describes a property of an entity or relationship. | Describes an association among entities. |
| Usually represented by an oval. | Usually represented by a diamond. |
| Example: `Student_Name`. | Example: `ENROLLS_IN`. |
| Has a value from a domain. | Connects participating entity instances. |
| May be simple, composite, multivalued, or derived. | May be unary, binary, ternary, or n-ary. |
| Example belongs to one student entity. | Example connects students and courses. |

### Example

Consider a `STUDENT` entity with the following attributes:

```text
STUDENT
  Student_ID       Key, simple
  Name             Composite (First_Name, Last_Name)
  Phone_No         Multivalued
  Date_of_Birth    Stored
  Age              Derived from Date_of_Birth
```

A student **ENROLLS_IN** a course. This is a binary many-to-many relationship because one student may enroll in multiple courses and one course may have multiple students.

## Q3. Specialization, Generalization, Aggregation and Inheritance

> **Question:** Explain Specialization, Generalization, Aggregation, and Inheritance with examples.

---

### Introduction

The **Enhanced Entity–Relationship (EER) model** extends the basic ER model to represent more complex real-world structures. It includes concepts such as specialization, generalization, inheritance, and aggregation. These concepts help represent subclasses, common properties, and relationships among relationships.

### 1. Specialization

**Specialization** is a top-down process in which a higher-level entity type (superclass) is divided into lower-level entity types (subclasses) based on distinguishing characteristics.

For example, an `EMPLOYEE` entity can be specialized into `MANAGER` and `ENGINEER`. Each subclass has the common attributes of `EMPLOYEE` and may have its own specific attributes.

```text
                 +------------+
                 |  EMPLOYEE  |
                 | Emp_ID     |
                 | Name       |
                 | Salary     |
                 +------------+
                       |
                      (d)
                     /   \
          +----------+   +----------+
          | MANAGER  |   | ENGINEER |
          | Bonus    |   | Skill    |
          +----------+   +----------+
```

Here, `MANAGER` and `ENGINEER` are subclasses of `EMPLOYEE`. The letter `d` indicates a disjoint specialization: an employee can belong to only one of the subclasses in this example.

**Constraints in specialization:**

- **Disjoint constraint:** An entity can belong to at most one subclass in the specialization. It is often marked with `d`.
- **Overlapping constraint:** An entity may belong to more than one subclass. It is often marked with `o`.
- **Total specialization:** Every superclass entity must belong to at least one subclass. It is shown with a double line from the superclass to the specialization circle.
- **Partial specialization:** Some superclass entities may belong to none of the subclasses. It is shown with a single line.

### 2. Generalization

**Generalization** is a bottom-up process in which two or more lower-level entity types are combined into a common higher-level entity type because they share common properties.

For example, `CAR` and `BIKE` can be generalized into a common superclass called `VEHICLE`.

```text
          +---------+                 +---------+
          |   CAR   |                 |  BIKE   |
          | Seats   |                 | Type    |
          +---------+                 +---------+
                \                       /
                 \                     /
                      (ISA)
                         |
                  +--------------+
                  |   VEHICLE    |
                  | Vehicle_ID   |
                  | Brand        |
                  +--------------+
```

The common attributes such as `Vehicle_ID` and `Brand` are placed in `VEHICLE`, while specific attributes remain in their respective subclasses.

### Difference Between Specialization and Generalization

| Specialization | Generalization |
|---|---|
| Top-down approach. | Bottom-up approach. |
| Divides one superclass into subclasses. | Combines multiple entity types into a superclass. |
| Based on distinguishing characteristics. | Based on common characteristics. |
| Example: `EMPLOYEE` into `MANAGER` and `ENGINEER`. | Example: `CAR` and `BIKE` into `VEHICLE`. |
| Creates more specific entity types. | Creates a more general entity type. |

### 3. Inheritance

**Inheritance** is the property by which a subclass receives the attributes and relationships of its superclass. The subclass can also define its own additional attributes.

For example, if `EMPLOYEE` contains `Emp_ID`, `Name`, and `Salary`, then `MANAGER` inherits all these attributes and may add `Department_Managed` or `Bonus`.

```text
             EMPLOYEE
        (Emp_ID, Name, Salary)
                 |
             inherits
                 |
              MANAGER
        (Department_Managed)

MANAGER contains:
Emp_ID, Name, Salary, Department_Managed
```

Inheritance avoids repeating common attributes in every subclass and supports a clear hierarchy of entity types.

### 4. Aggregation

**Aggregation** is an abstraction in which a relationship set, together with its participating entity sets, is treated as a higher-level entity so that it can participate in another relationship.

It is useful when a relationship itself must be related to another entity.

Example: an employee **WORKS_ON** a project, and a manager **MONITORS** that work assignment. The manager monitors the employee's assignment to a particular project, not merely the employee or project independently.

```text
+----------+       +----------+       +---------+
| EMPLOYEE |-------| WORKS_ON |-------| PROJECT |
+----------+       +----------+       +---------+
                         |
                  [Aggregation]
                         |
                    +---------+
                    | MANAGER |
                    +---------+
                         |
                      MONITORS
```

The `WORKS_ON` relationship between `EMPLOYEE` and `PROJECT` is treated as an abstract higher-level unit. `MANAGER` is related to that unit through `MONITORS`.

### Comparison of the Four Concepts

| Concept | Meaning | Direction / Purpose | Example |
|---|---|---|---|
| Specialization | Divides a superclass into subclasses. | Top-down. | Employee → Manager, Engineer |
| Generalization | Combines similar entity types into a superclass. | Bottom-up. | Car, Bike → Vehicle |
| Inheritance | Subclass receives superclass attributes and relationships. | Property of an ISA hierarchy. | Manager inherits Employee attributes |
| Aggregation | Treats a relationship and its entities as a higher-level unit. | Relationship abstraction. | Manager monitors an employee's project assignment |

### Advantages

1. These concepts represent complex real-world data more accurately than a basic ER model.
2. Inheritance reduces duplication of common attributes.
3. Specialization and generalization improve database organization.
4. Aggregation represents relationships that involve other relationships.
5. EER diagrams make complex database requirements easier to understand.

## Q4. ER Diagram for a Library Management System

> **Question:** Draw an ER diagram for a Library/Hospital/Banking System.

---

### Introduction

An **ER diagram** represents the entities, attributes, keys, and relationships of a database system. The following design describes a **Library Management System** that stores book details, physical book copies, members, and borrowing transactions.

### Entities and Attributes

1. **MEMBER:** Stores library member details. `Member_ID` is the primary key. Other attributes include `Name`, `Email`, and `Phone`.
2. **BOOK:** Stores bibliographic details of a book. `Book_ID` is the primary key. Other attributes include `Title`, `ISBN`, `Publisher`, and `Category`.
3. **BOOK_COPY:** Represents each physical copy of a book. `Copy_ID` is the primary key, while `Book_ID` identifies the book to which the copy belongs. `Status` indicates whether the copy is available, issued, or under maintenance.
4. **AUTHOR:** Stores author details. `Author_ID` is the primary key, and `Author_Name` stores the author's name.
5. **LOAN:** Stores each book-issue transaction. `Loan_ID` is the primary key. It also stores `Member_ID`, `Copy_ID`, `Issue_Date`, `Due_Date`, and `Return_Date`.

### ER Diagram

```text
 +-------------+          M       1       +----------+
 |   MEMBER    |---------------------------|   LOAN   |
 +-------------+          BORROWS          +----------+
 | PK Member_ID|                           | PK Loan_ID|
 | Name        |                           | Issue_Date|
 | Email       |                           | Due_Date  |
 | Phone       |                           | Return_Date|
 +-------------+                           +----------+
                                                  |
                                                  | N
                                                  | BORROWS
                                                  | 1
                                            +-------------+
                                            |  BOOK_COPY  |
                                            +-------------+
                                            | PK Copy_ID  |
                                            | FK Book_ID  |
                                            | Status      |
                                            +-------------+
                                                  |
                                                  | N
                                               BELONGS_TO
                                                  | 1
                                            +-------------+
                                            |    BOOK     |
                                            +-------------+
                                            | PK Book_ID  |
                                            | Title       |
                                            | ISBN        |
                                            | Publisher   |
                                            | Category    |
                                            +-------------+
                                                  |
                                                  | M
                                                WRITTEN_BY
                                                  | N
                                            +-------------+
                                            |   AUTHOR    |
                                            +-------------+
                                            | PK Author_ID|
                                            | Author_Name |
                                            +-------------+
```

**Note:** `BOOK` and `AUTHOR` have a many-to-many relationship in this design. A book can have multiple authors, and an author can write multiple books. A junction entity `BOOK_AUTHOR` is used when converting this relationship into relational tables.

### Relationships and Cardinalities

1. **MEMBER — LOAN (1:N):** One member can have many loan records over time, but each loan belongs to exactly one member.
2. **BOOK_COPY — LOAN (1:N over time):** One physical copy can appear in multiple loan records over time, but each loan record refers to one copy. A business rule must ensure that the same copy is not issued to two members at the same time.
3. **BOOK — BOOK_COPY (1:N):** One book title can have many physical copies, but each copy belongs to one book title.
4. **BOOK — AUTHOR (M:N):** One book may be written by multiple authors, and one author may write multiple books.

### Relational Tables Generated from the ER Diagram

```sql
CREATE TABLE Member (
    Member_ID INT PRIMARY KEY,
    Name      VARCHAR(80) NOT NULL,
    Email     VARCHAR(120) UNIQUE,
    Phone     VARCHAR(20)
);

CREATE TABLE Book (
    Book_ID   INT PRIMARY KEY,
    Title     VARCHAR(150) NOT NULL,
    ISBN      VARCHAR(20) UNIQUE,
    Publisher VARCHAR(100),
    Category  VARCHAR(50)
);

CREATE TABLE Author (
    Author_ID   INT PRIMARY KEY,
    Author_Name VARCHAR(100) NOT NULL
);

CREATE TABLE Book_Author (
    Book_ID   INT,
    Author_ID INT,
    PRIMARY KEY (Book_ID, Author_ID),
    FOREIGN KEY (Book_ID) REFERENCES Book(Book_ID),
    FOREIGN KEY (Author_ID) REFERENCES Author(Author_ID)
);

CREATE TABLE Book_Copy (
    Copy_ID INT PRIMARY KEY,
    Book_ID INT NOT NULL,
    Status  VARCHAR(20) NOT NULL
        CHECK (Status IN ('AVAILABLE', 'ISSUED', 'MAINTENANCE')),
    FOREIGN KEY (Book_ID) REFERENCES Book(Book_ID)
);

CREATE TABLE Loan (
    Loan_ID    INT PRIMARY KEY,
    Member_ID  INT NOT NULL,
    Copy_ID    INT NOT NULL,
    Issue_Date DATE NOT NULL,
    Due_Date   DATE NOT NULL,
    Return_Date DATE,
    FOREIGN KEY (Member_ID) REFERENCES Member(Member_ID),
    FOREIGN KEY (Copy_ID) REFERENCES Book_Copy(Copy_ID),
    CHECK (Due_Date >= Issue_Date),
    CHECK (Return_Date IS NULL OR Return_Date >= Issue_Date)
);
```

### Working of the System

1. The librarian enters book details into the `BOOK` table and author details into the `AUTHOR` table.
2. Each physical copy is stored separately in `BOOK_COPY` and linked to its book through `Book_ID`.
3. A member is registered in the `MEMBER` table.
4. When a member borrows a copy, a row is inserted into `LOAN` with the member, copy, issue date, and due date.
5. When the copy is returned, `Return_Date` is updated and the copy's status is changed to `AVAILABLE`.

### Conclusion

The ER model gives a clear conceptual design of the library database. It identifies the main entities, their attributes, primary keys, and relationships. The design can be converted into relational tables using primary keys, foreign keys, and a junction table for the many-to-many relationship.

## Q5. SQL Implementation of Primary Key, Foreign Key, UNIQUE, NOT NULL and CHECK Constraints

> **Question:** Explain the implementation of Primary Key, Foreign Key, UNIQUE, NOT NULL, and CHECK constraints in SQL with suitable examples.

---

### Definition

**SQL constraints** are rules applied to table columns or combinations of columns to restrict the data that can be inserted or updated. They help maintain the accuracy, validity, and consistency of database records.

### 1. PRIMARY KEY Constraint

A **PRIMARY KEY** uniquely identifies every row in a table. It does not allow duplicate values or `NULL` values. A table can have only one primary-key constraint, but that key may contain multiple columns (a composite primary key).

```sql
CREATE TABLE Student (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(60)
);
```

Here, `Student_ID` uniquely identifies each student. Two rows cannot have the same `Student_ID`, and it cannot be `NULL`.

A composite primary key can be defined as follows:

```sql
CREATE TABLE Enrollment (
    Student_ID INT,
    Course_ID  INT,
    PRIMARY KEY (Student_ID, Course_ID)
);
```

The combination of `Student_ID` and `Course_ID` must be unique.

### 2. FOREIGN KEY Constraint

A **FOREIGN KEY** establishes a relationship between two tables. It ensures that a value in the child table matches an existing referenced key in the parent table, subject to the nullability rules of the foreign-key column.

```sql
CREATE TABLE Department (
    Dept_ID   INT PRIMARY KEY,
    Dept_Name VARCHAR(60) NOT NULL
);

CREATE TABLE Employee (
    Emp_ID  INT PRIMARY KEY,
    Name    VARCHAR(60) NOT NULL,
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
);
```

The `Dept_ID` column in `EMPLOYEE` is a foreign key referencing `Department(Dept_ID)`. An employee cannot be assigned a department ID that does not exist in the `DEPARTMENT` table. Since `Dept_ID` is nullable here, `NULL` is allowed unless `NOT NULL` is also specified.

### 3. UNIQUE Constraint

A **UNIQUE** constraint ensures that the values in a column or combination of columns do not repeat. It is commonly used for values such as email addresses or registration numbers.

```sql
CREATE TABLE User_Account (
    User_ID INT PRIMARY KEY,
    Email   VARCHAR(120) UNIQUE
);
```

Two users cannot have the same non-`NULL` email value. The treatment of multiple `NULL` values in a `UNIQUE` constraint can vary by DBMS, so it should not be assumed to be identical in every database system.

### 4. NOT NULL Constraint

A **NOT NULL** constraint prevents a column from storing a `NULL` value. It is used when a value is compulsory for every row.

```sql
CREATE TABLE Student_Details (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(60) NOT NULL,
    Email      VARCHAR(120)
);
```

Every student must have a name, while the email value is optional in this example.

### 5. CHECK Constraint

A **CHECK** constraint restricts values according to a condition. The condition must evaluate to `TRUE` or `UNKNOWN` for the row to pass; a separate `NOT NULL` constraint is needed when `NULL` must also be rejected.

```sql
CREATE TABLE Employee_Salary (
    Emp_ID INT PRIMARY KEY,
    Name   VARCHAR(60) NOT NULL,
    Age    INT CHECK (Age >= 18),
    Salary DECIMAL(10, 2) CHECK (Salary > 0)
);
```

Here, age must be at least 18 when provided, and salary must be positive when provided. To make both values compulsory, define the columns as `Age INT NOT NULL CHECK (Age >= 18)` and `Salary DECIMAL(10,2) NOT NULL CHECK (Salary > 0)`.

### Adding Constraints Using ALTER TABLE

Constraints can also be added after table creation.

```sql
ALTER TABLE Student
ADD CONSTRAINT uq_student_email UNIQUE (Email);

ALTER TABLE Employee
ADD CONSTRAINT fk_employee_dept
FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID);

ALTER TABLE Employee
ADD CONSTRAINT chk_emp_age CHECK (Age >= 18);
```

The exact syntax and support for altering or validating existing constraints can vary between DBMS products.

### Comparison of Constraints

| Constraint | Purpose | Allows duplicate values? | Allows NULL? |
|---|---|---|---|
| PRIMARY KEY | Uniquely identifies each row. | No. | No. |
| FOREIGN KEY | Maintains a valid reference to another table. | Yes, unless other constraints prevent it. | Yes, if the column is nullable. |
| UNIQUE | Prevents duplicate values in the constrained column(s). | No for non-NULL values. | DBMS-dependent behavior. |
| NOT NULL | Requires a value in a column. | Yes. | No. |
| CHECK | Requires a condition to be satisfied. | Depends on the condition. | `NULL` may pass unless `NOT NULL` is also used. |

### Conclusion

SQL constraints enforce rules directly in the database. Primary keys identify records, foreign keys connect tables, UNIQUE prevents repeated values, NOT NULL requires compulsory data, and CHECK validates values against conditions.

## Q6. Integrity Constraints in DBMS

> **Question:** What are integrity constraints? Explain Entity Integrity, Referential Integrity, and Domain Integrity constraints with suitable SQL examples.

---

### Definition

**Integrity constraints** are rules applied to a database to ensure that stored data remains accurate, valid, and consistent. They prevent invalid records and maintain correct relationships between tables.

The three important types are **entity integrity**, **referential integrity**, and **domain integrity**.

### 1. Entity Integrity Constraint

**Entity integrity** states that the primary-key value of a relation must be unique and must never be `NULL`. Every row must be identifiable by its primary key.

Example:

```sql
CREATE TABLE Student (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(60) NOT NULL
);
```

The following operations are invalid:

```sql
INSERT INTO Student VALUES (101, 'Arun');
INSERT INTO Student VALUES (101, 'Bina'); -- Duplicate primary key
INSERT INTO Student VALUES (NULL, 'Charan'); -- NULL primary key
```

The first statement succeeds if the table is empty. The second fails because `Student_ID = 101` already exists, and the third fails because a primary key cannot be `NULL`.

### 2. Referential Integrity Constraint

**Referential integrity** ensures that a foreign-key value in a child table refers to an existing candidate or primary key value in the parent table, or is `NULL` when the foreign-key column permits it.

Example:

```sql
CREATE TABLE Department (
    Dept_ID   INT PRIMARY KEY,
    Dept_Name VARCHAR(60) NOT NULL
);

CREATE TABLE Employee (
    Emp_ID  INT PRIMARY KEY,
    Name    VARCHAR(60) NOT NULL,
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
);
```

Valid insertion:

```sql
INSERT INTO Department VALUES (10, 'CSE');
INSERT INTO Employee VALUES (1, 'Anil', 10);
```

Invalid insertion:

```sql
INSERT INTO Employee VALUES (2, 'Bala', 99);
```

The second employee insertion is rejected because department `99` does not exist in the parent table.

### Referential Actions

When a referenced parent row is updated or deleted, the database can apply a referential action. Common options include:

- **RESTRICT / NO ACTION:** Prevents a parent row from being deleted or changed when dependent child rows exist. The precise timing of enforcement may differ by DBMS.
- **CASCADE:** Automatically deletes or updates matching child rows when the referenced parent key is deleted or updated.
- **SET NULL:** Sets the child foreign-key column to `NULL` when the referenced parent row is deleted or updated. The child column must allow `NULL`.
- **SET DEFAULT:** Sets the child foreign-key column to its declared default value, where supported and valid.

Example:

```sql
CREATE TABLE Employee (
    Emp_ID  INT PRIMARY KEY,
    Name    VARCHAR(60) NOT NULL,
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
        ON DELETE SET NULL
        ON UPDATE CASCADE
);
```

### 3. Domain Integrity Constraint

**Domain integrity** ensures that each attribute contains values from its permitted domain. A domain includes the data type, size, range, format, and allowed set of values for a column.

Example:

```sql
CREATE TABLE Student_Result (
    Student_ID INT PRIMARY KEY,
    Name       VARCHAR(60) NOT NULL,
    Age        INT CHECK (Age BETWEEN 16 AND 30),
    Marks      DECIMAL(5, 2) CHECK (Marks BETWEEN 0 AND 100),
    Grade      CHAR(1) CHECK (Grade IN ('A', 'B', 'C', 'D', 'F'))
);
```

Here:

- `Age` must be between 16 and 30 when supplied.
- `Marks` must be between 0 and 100 when supplied.
- `Grade` must be one of the specified letters when supplied.
- `NOT NULL` is used for attributes that must contain a value.

A `CHECK` condition does not by itself reject `NULL`, because SQL uses three-valued logic. Add `NOT NULL` when missing values are not permitted.

### Comparison of Integrity Constraints

| Constraint | Main Rule | Common SQL Implementation | Example Violation |
|---|---|---|---|
| Entity Integrity | Primary key must be unique and non-NULL. | `PRIMARY KEY` | Duplicate or NULL student ID |
| Referential Integrity | Foreign key must reference a valid parent key or be NULL if allowed. | `FOREIGN KEY` | Employee refers to a non-existing department |
| Domain Integrity | Attribute values must satisfy their defined domain. | Data type, `NOT NULL`, `CHECK`, `DEFAULT` | Marks equal to 120 when range is 0–100 |

### Importance of Integrity Constraints

1. They prevent invalid data from entering the database.
2. They maintain consistency between related tables.
3. They reduce data-entry and application errors.
4. They make business rules enforceable at the database level.
5. They improve the reliability of queries and reports.

## Q7. Nested and Correlated Subqueries

> **Question:** Explain Nested and Correlated Subqueries with examples.

---

### Definition of a Subquery

A **subquery** is a query written inside another SQL query. The inner query is placed within parentheses and is used to provide a value or set of rows to the outer query. Subqueries can be used with `SELECT`, `INSERT`, `UPDATE`, and `DELETE` statements.

Consider the following tables:

**EMPLOYEE**

| Emp_ID | Name | Dept_ID | Salary |
|---:|---|---:|---:|
| 1 | Arun | 10 | 50000 |
| 2 | Bina | 20 | 65000 |
| 3 | Charan | 10 | 70000 |
| 4 | Divya | 30 | 45000 |

**DEPARTMENT**

| Dept_ID | Dept_Name |
|---:|---|
| 10 | CSE |
| 20 | ECE |
| 30 | MECH |

### 1. Nested (Non-Correlated) Subquery

A **nested subquery** is a query placed inside another query. In a non-correlated subquery, the inner query does not depend on the outer query. It can be evaluated independently, and its result is then used by the outer query.

Example: Display employees who work in the CSE department.

```sql
SELECT Name
FROM Employee
WHERE Dept_ID = (
    SELECT Dept_ID
    FROM Department
    WHERE Dept_Name = 'CSE'
);
```

**Working:**

1. The inner query finds the department ID for `CSE`.
2. The inner query returns `10`.
3. The outer query selects employees whose `Dept_ID` is `10`.

**Output:**

| Name |
|---|
| Arun |
| Charan |

A subquery can return a single value, multiple values, or a table of rows. The outer operator must match the result type. For example, use `=` for a scalar result and `IN` when the subquery may return multiple values.

Example using `IN`: display employees who belong to departments located in a selected group.

```sql
SELECT Name
FROM Employee
WHERE Dept_ID IN (
    SELECT Dept_ID
    FROM Department
    WHERE Dept_Name IN ('CSE', 'ECE')
);
```

### 2. Correlated Subquery

A **correlated subquery** is an inner query that refers to a column from the outer query. Therefore, it depends on the current row being processed by the outer query. Conceptually, the correlated condition is evaluated for each candidate outer row, although a DBMS optimizer may transform it into a more efficient execution plan.

Example: Display employees whose salary is greater than the average salary of their own department.

```sql
SELECT E1.Name, E1.Salary, E1.Dept_ID
FROM Employee E1
WHERE E1.Salary > (
    SELECT AVG(E2.Salary)
    FROM Employee E2
    WHERE E2.Dept_ID = E1.Dept_ID
);
```

**Working:**

1. The outer query selects an employee row using alias `E1`.
2. The inner query calculates the average salary for the department of that employee.
3. The condition compares the employee's salary with that department's average.
4. The employee is displayed if the salary is greater than the department average.

For the sample data, the average salary of department `10` is `60000`, department `20` is `65000`, and department `30` is `45000`. `Charan` is selected because his salary is `70000`, greater than the average of department `10`.

**Output:**

| Name | Salary | Dept_ID |
|---|---:|---:|
| Charan | 70000 | 10 |

### EXISTS and NOT EXISTS with Correlated Subqueries

`EXISTS` checks whether the subquery returns at least one row. `NOT EXISTS` checks whether it returns no rows.

Example: Display departments that have at least one employee.

```sql
SELECT D.Dept_ID, D.Dept_Name
FROM Department D
WHERE EXISTS (
    SELECT 1
    FROM Employee E
    WHERE E.Dept_ID = D.Dept_ID
);
```

The condition `E.Dept_ID = D.Dept_ID` refers to the outer query, so the subquery is correlated.

Example: Display departments that have no employees.

```sql
SELECT D.Dept_ID, D.Dept_Name
FROM Department D
WHERE NOT EXISTS (
    SELECT 1
    FROM Employee E
    WHERE E.Dept_ID = D.Dept_ID
);
```

### Difference Between Nested and Correlated Subqueries

| Nested (Non-Correlated) Subquery | Correlated Subquery |
|---|---|
| Inner query does not refer to the outer query. | Inner query refers to an outer-query column. |
| Can be executed independently. | Depends on the current outer row. |
| Conceptually evaluated before its result is used by the outer query. | Conceptually evaluated for each outer row. |
| Does not require an outer-table alias inside the inner query. | Usually uses an outer-table alias to refer to the current row. |
| Example: find employees in the department returned by another query. | Example: find employees earning more than their department average. |

### Advantages of Subqueries

1. They divide complex queries into smaller logical parts.
2. They can compare values with calculated results such as averages and maximums.
3. They support membership checks using `IN` and existence checks using `EXISTS`.
4. Correlated subqueries can express row-dependent conditions.

## Q8. Types of SQL Joins

> **Question:** Explain different types of SQL Joins with suitable examples.

---

### Definition

A **JOIN** is an SQL operation used to combine rows from two or more tables based on a related column or a specified condition. Joins are useful because relational databases store related information in separate tables to reduce redundancy and maintain consistency.

Consider the following tables:

**EMPLOYEE**

| Emp_ID | Name | Dept_ID |
|---:|---|---:|
| 1 | Arun | 10 |
| 2 | Bina | 20 |
| 3 | Charan | 10 |
| 4 | Divya | NULL |

**DEPARTMENT**

| Dept_ID | Dept_Name |
|---:|---|
| 10 | CSE |
| 20 | ECE |
| 30 | MECH |

### 1. INNER JOIN

An **INNER JOIN** returns only the rows that satisfy the join condition in both tables. Rows without a matching record are excluded.

```sql
SELECT E.Emp_ID, E.Name, D.Dept_Name
FROM Employee E
INNER JOIN Department D
    ON E.Dept_ID = D.Dept_ID;
```

**Output:**

| Emp_ID | Name | Dept_Name |
|---:|---|---|
| 1 | Arun | CSE |
| 2 | Bina | ECE |
| 3 | Charan | CSE |

Divya is not included because her `Dept_ID` is `NULL`, and department `30` is not included because no employee matches it.

### 2. LEFT OUTER JOIN (LEFT JOIN)

A **LEFT JOIN** returns all rows from the left table and matching rows from the right table. If no match exists, the right-table columns contain `NULL`.

```sql
SELECT E.Emp_ID, E.Name, D.Dept_Name
FROM Employee E
LEFT JOIN Department D
    ON E.Dept_ID = D.Dept_ID;
```

**Output:**

| Emp_ID | Name | Dept_Name |
|---:|---|---|
| 1 | Arun | CSE |
| 2 | Bina | ECE |
| 3 | Charan | CSE |
| 4 | Divya | NULL |

All employees are returned, including Divya, who has no matching department.

### 3. RIGHT OUTER JOIN (RIGHT JOIN)

A **RIGHT JOIN** returns all rows from the right table and matching rows from the left table. If no match exists, the left-table columns contain `NULL`.

```sql
SELECT E.Emp_ID, E.Name, D.Dept_Name
FROM Employee E
RIGHT JOIN Department D
    ON E.Dept_ID = D.Dept_ID;
```

**Output:**

| Emp_ID | Name | Dept_Name |
|---:|---|---|
| 1 | Arun | CSE |
| 3 | Charan | CSE |
| 2 | Bina | ECE |
| NULL | NULL | MECH |

All departments are returned, including MECH, which has no matching employee.

### 4. FULL OUTER JOIN

A **FULL OUTER JOIN** returns all matching rows and all non-matching rows from both tables. Missing columns on either side are filled with `NULL`.

```sql
SELECT E.Emp_ID, E.Name, D.Dept_Name
FROM Employee E
FULL OUTER JOIN Department D
    ON E.Dept_ID = D.Dept_ID;
```

**Output:**

| Emp_ID | Name | Dept_Name |
|---:|---|---|
| 1 | Arun | CSE |
| 2 | Bina | ECE |
| 3 | Charan | CSE |
| 4 | Divya | NULL |
| NULL | NULL | MECH |

The result includes unmatched employees and unmatched departments. `FULL OUTER JOIN` is supported by PostgreSQL and several other DBMS products; some systems require an alternative using `LEFT JOIN`, `RIGHT JOIN`, and `UNION`.

### 5. CROSS JOIN

A **CROSS JOIN** returns the Cartesian product of two tables. Every row of the first table is combined with every row of the second table. If the first table has `m` rows and the second has `n` rows, the result has `m × n` rows.

```sql
SELECT E.Name, D.Dept_Name
FROM Employee E
CROSS JOIN Department D;
```

With four employees and three departments, the result contains `4 × 3 = 12` rows.

### 6. SELF JOIN

A **SELF JOIN** joins a table with itself. It is useful for representing relationships between rows of the same table, such as employees and their managers.

Example table:

**EMPLOYEE**

| Emp_ID | Name | Manager_ID |
|---:|---|---:|
| 1 | Arun | NULL |
| 2 | Bina | 1 |
| 3 | Charan | 1 |
| 4 | Divya | 2 |

```sql
SELECT E.Name AS Employee,
       M.Name AS Manager
FROM Employee E
LEFT JOIN Employee M
    ON E.Manager_ID = M.Emp_ID;
```

**Output:**

| Employee | Manager |
|---|---|
| Arun | NULL |
| Bina | Arun |
| Charan | Arun |
| Divya | Bina |

The table is given two aliases: `E` for the employee and `M` for the manager.

### 7. EQUI JOIN and NON-EQUI JOIN

- **Equi join:** A join in which the matching condition uses the equality operator (`=`). The earlier employee-department join is an equi join.
- **Non-equi join:** A join in which the condition uses operators such as `<`, `>`, or `BETWEEN` rather than equality.

Example of a non-equi join:

```sql
SELECT E.Name, G.Grade
FROM Employee E
JOIN Salary_Grade G
    ON E.Salary BETWEEN G.Min_Salary AND G.Max_Salary;
```

This query matches an employee's salary with a salary range. `Salary_Grade` is assumed to contain `Min_Salary`, `Max_Salary`, and `Grade` columns.

### Comparison of SQL Joins

| Join Type | Rows Returned | Unmatched Rows |
|---|---|---|
| INNER JOIN | Only matching rows. | Excluded from both sides. |
| LEFT JOIN | All left rows and matching right rows. | Unmatched left rows included with right-side `NULL`s. |
| RIGHT JOIN | All right rows and matching left rows. | Unmatched right rows included with left-side `NULL`s. |
| FULL OUTER JOIN | All rows from both sides. | Unmatched rows from both sides included. |
| CROSS JOIN | Every possible row combination. | No matching condition is required. |
| SELF JOIN | Rows from the same table matched using aliases. | Depends on the join type used. |

### Conclusion

Joins combine related data stored in different tables. INNER JOIN retrieves matching records, outer joins retain unmatched rows, CROSS JOIN generates combinations, and SELF JOIN compares rows within the same table.

## Q9. SQL Views and Updatable / Non-Updatable Views

> **Question:** Explain SQL Views. Differentiate between updatable and non-updatable views.

---

### Definition

A **view** is a virtual table created from the result of an SQL query. It does not normally store the query result as an independent table; instead, it stores the query definition and retrieves data from the underlying base tables when accessed. A view can present selected columns and rows while hiding unnecessary details.

### Creating a View

Consider a table named `Employee` containing `Emp_ID`, `Name`, `Dept_ID`, and `Salary`.

```sql
CREATE VIEW Employee_Public AS
SELECT Emp_ID, Name, Dept_ID
FROM Employee;
```

The view contains only the selected columns. Users querying `Employee_Public` do not see the `Salary` column through this view.

```sql
SELECT *
FROM Employee_Public;
```

### Types of Views

1. **Simple View:** Created using one base table and usually contains no aggregate functions or grouping. Simple views are often updatable, subject to the DBMS rules.

   ```sql
   CREATE VIEW CSE_Employees AS
   SELECT Emp_ID, Name, Dept_ID
   FROM Employee
   WHERE Dept_ID = 10;
   ```

2. **Complex View:** Created using multiple tables, joins, aggregate functions, or grouping. Such views are generally not directly updatable in many DBMS products.

   ```sql
   CREATE VIEW Department_Summary AS
   SELECT Dept_ID, COUNT(*) AS Employee_Count,
          AVG(Salary) AS Average_Salary
   FROM Employee
   GROUP BY Dept_ID;
   ```

3. **Materialized View:** A view-like database object that physically stores the result of its query. It may need to be refreshed when underlying data changes. Availability and refresh behavior depend on the DBMS.

### Updatable View

An **updatable view** allows certain `INSERT`, `UPDATE`, or `DELETE` operations to be performed through the view. These changes affect the underlying base table.

Example:

```sql
CREATE VIEW Employee_Basic AS
SELECT Emp_ID, Name, Dept_ID
FROM Employee;

UPDATE Employee_Basic
SET Dept_ID = 20
WHERE Emp_ID = 1;
```

If the view is updatable, this operation changes the corresponding row in the base `EMPLOYEE` table.

A view is more likely to be updatable when it is based on a single table and does not contain features such as `GROUP BY`, aggregate functions, `DISTINCT`, or set operations. Exact rules vary by DBMS. When a view includes a `WHERE` clause, a `WITH CHECK OPTION` can prevent modifications through the view from creating rows that no longer satisfy the view condition.

```sql
CREATE VIEW CSE_Employees AS
SELECT Emp_ID, Name, Dept_ID
FROM Employee
WHERE Dept_ID = 10
WITH CHECK OPTION;
```

With the check option, an update through this view cannot change a visible employee's department to a value other than `10` if that would make the row disappear from the view.

### Non-Updatable View

A **non-updatable view** does not allow direct data modification through the view, usually because its query combines, groups, or summarizes data in a way that cannot be mapped unambiguously to individual base-table rows.

Example:

```sql
CREATE VIEW Department_Summary AS
SELECT Dept_ID,
       COUNT(*) AS Employee_Count,
       AVG(Salary) AS Average_Salary
FROM Employee
GROUP BY Dept_ID;
```

The result contains one summary row per department. Updating `Average_Salary` would not identify which individual employee salaries should be changed. Therefore, this kind of view is generally not directly updatable.

### Difference Between Updatable and Non-Updatable Views

| Updatable View | Non-Updatable View |
|---|---|
| Allows supported modifications through the view. | Does not allow direct modifications through the view. |
| Usually based on a single base table. | Often based on joins, grouping, or set operations. |
| Usually has a direct mapping to base-table rows. | A row or value may not map clearly to individual base rows. |
| Commonly avoids aggregate functions and `GROUP BY`. | May contain aggregate functions or `GROUP BY`. |
| Example: view showing employee names and departments. | Example: view showing average salary by department. |

### Advantages of Views

1. **Security:** Sensitive columns can be hidden from specific users.
2. **Simplicity:** Complex queries can be stored and reused as views.
3. **Logical data independence:** Users can work with a stable view even when the underlying schema is reorganized in ways that preserve the view's interface.
4. **Customized presentation:** Different users can access different representations of the same base data.
5. **Reusability:** Frequently used query logic can be centralized.

### Dropping a View

```sql
DROP VIEW Employee_Public;
```

Dropping a view removes its definition. It does not normally delete the underlying base-table records.

## Q10. Relational Set Operations

> **Question:** Explain Relational Set Operations with suitable examples.

---

### Definition

**Relational set operations** are operations used to combine or compare the tuples of two relations. The main set operations are **UNION**, **INTERSECTION**, **SET DIFFERENCE**, and **CARTESIAN PRODUCT**. In relational algebra, these operations are used to construct new relations from existing relations.

For UNION, INTERSECTION, and SET DIFFERENCE, the two relations must be **union-compatible**: they must have the same number of attributes, and corresponding attributes must have compatible domains (and matching positions or corresponding types, depending on the relational notation).

Consider the following relations:

**CSE_STUDENT**

| Student_ID | Name |
|---:|---|
| 101 | Arun |
| 102 | Bina |
| 103 | Charan |

**SPORTS_STUDENT**

| Student_ID | Name |
|---:|---|
| 102 | Bina |
| 103 | Charan |
| 104 | Divya |

### 1. UNION (∪)

The **UNION** operation returns all distinct tuples that are present in either relation or in both relations. Both relations must be union-compatible.

Relational algebra notation:

```text
CSE_STUDENT ∪ SPORTS_STUDENT
```

SQL:

```sql
SELECT Student_ID, Name FROM CSE_Student
UNION
SELECT Student_ID, Name FROM Sports_Student;
```

**Output:**

| Student_ID | Name |
|---:|---|
| 101 | Arun |
| 102 | Bina |
| 103 | Charan |
| 104 | Divya |

`UNION` removes duplicate result rows. `UNION ALL` retains duplicates and is therefore not the same as mathematical set union.

### 2. INTERSECTION (∩)

The **INTERSECTION** operation returns only the tuples that are common to both relations. Both relations must be union-compatible.

Relational algebra notation:

```text
CSE_STUDENT ∩ SPORTS_STUDENT
```

SQL:

```sql
SELECT Student_ID, Name FROM CSE_Student
INTERSECT
SELECT Student_ID, Name FROM Sports_Student;
```

**Output:**

| Student_ID | Name |
|---:|---|
| 102 | Bina |
| 103 | Charan |

Only Bina and Charan appear in both relations. `INTERSECT` is supported by PostgreSQL and several other DBMS products; in systems without it, the same result can be expressed using an inner join or `EXISTS`.

### 3. SET DIFFERENCE (−)

The **SET DIFFERENCE** operation returns tuples that are present in the first relation but absent from the second relation. The operation is not commutative: `A − B` is generally different from `B − A`.

Relational algebra notation:

```text
CSE_STUDENT − SPORTS_STUDENT
```

SQL:

```sql
SELECT Student_ID, Name FROM CSE_Student
EXCEPT
SELECT Student_ID, Name FROM Sports_Student;
```

**Output:**

| Student_ID | Name |
|---:|---|
| 101 | Arun |

`EXCEPT` is used by PostgreSQL and several other DBMS products. Oracle uses `MINUS` for this operation. In systems without either operator, it can be expressed with `NOT EXISTS` or an appropriate anti-join.

### 4. CARTESIAN PRODUCT (×)

The **Cartesian product** combines every tuple of the first relation with every tuple of the second relation. If relation A has `m` tuples and relation B has `n` tuples, the product contains `m × n` tuples.

Relational algebra notation:

```text
CSE_STUDENT × COURSE
```

SQL:

```sql
SELECT S.Student_ID, S.Name, C.Course_ID, C.Course_Name
FROM CSE_Student S
CROSS JOIN Course C;
```

If `CSE_STUDENT` has 3 rows and `COURSE` has 2 rows, the result contains `3 × 2 = 6` rows.

### 5. RENAME (ρ)

The **RENAME** operation changes the name of a relation or its attributes in relational algebra. It is useful when the same relation is used more than once or when an expression needs a clearer name.

Notation:

```text
ρ STUDENT_INFO(Student_ID, Student_Name)(STUDENT)
```

This gives the relation a new name `STUDENT_INFO` and uses the indicated attribute names. In SQL, aliases can be used to rename a table or columns in a query:

```sql
SELECT Student_ID AS ID, Name AS Student_Name
FROM Student;
```

### Summary of Set Operations

| Operation | Symbol | Purpose | Condition |
|---|---|---|---|
| Union | `∪` | Tuples present in either relation. | Union-compatible relations. |
| Intersection | `∩` | Tuples common to both relations. | Union-compatible relations. |
| Set Difference | `−` | Tuples in the first relation but not the second. | Union-compatible relations. |
| Cartesian Product | `×` | Every combination of tuples from two relations. | No union-compatibility requirement; attribute names may need renaming. |
| Rename | `ρ` | Renames a relation or its attributes. | Used to clarify or distinguish expressions. |

### Important Properties

1. **Union is commutative:** `A ∪ B = B ∪ A`.
2. **Intersection is commutative:** `A ∩ B = B ∩ A`.
3. **Union and intersection are associative:** `(A ∪ B) ∪ C = A ∪ (B ∪ C)` and `(A ∩ B) ∩ C = A ∩ (B ∩ C)`.
4. **Difference is not commutative:** `A − B` is not generally equal to `B − A`.
5. **Cartesian product cardinality:** If A contains `m` tuples and B contains `n` tuples, `A × B` contains `m × n` tuples.
6. In classical relational algebra, relations are sets, so duplicate tuples are eliminated. SQL uses bag (multiset) behavior in many query results unless `DISTINCT` or a set operator such as `UNION` is used.

### Conclusion

Relational set operations allow relations to be combined, compared, and renamed. UNION finds all tuples, INTERSECTION finds common tuples, SET DIFFERENCE finds tuples unique to the first relation, and CARTESIAN PRODUCT generates all possible tuple combinations.
