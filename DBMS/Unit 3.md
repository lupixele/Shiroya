# UNIT 3 — Entity-Relationship Model, Constraints, Subqueries, Joins & Views

---

## 1. Explain the ER Model with neat diagrams.

### Introduction
The **Entity–Relationship (ER) Model** is a high-level conceptual data model used to design the logical structure of a database. Proposed by Peter Chen, it represents real-world objects (**entities**), their properties (**attributes**), and the associations among them (**relationships**) in a clear graphical blueprint before creating relational tables in a DBMS.

### Main Components of the ER Model
1. **Entity:** A real-world object, person, place, or concept that is distinguishable from other objects.
   - **Strong Entity:** Has its own primary key and does not depend on any other entity for existence (e.g., `STUDENT`, `COURSE`, `EMPLOYEE`).
   - **Weak Entity:** Does not have sufficient attributes to form a primary key on its own and depends on a strong (identifying) owner entity (e.g., `DEPENDENT` of an `EMPLOYEE`).
2. **Attribute:** A property or characteristic that describes an entity or a relationship (e.g., `Student` has `Roll_No`, `Name`, `Age`, `Phone_No`).
3. **Relationship:** An association among two or more entities (e.g., `STUDENT` *enrolls in* / *takes* `COURSE`).

### Symbols / Notations Used in the ER Model

| Symbol / Shape | Graphical Representation | Meaning in ER Model |
| :--- | :--- | :--- |
| **Rectangle** | `[ ENTITY ]` | Entity Set (Strong Entity) |
| **Double Rectangle** | `[[ WEAK ENTITY ]]` | Weak Entity Set |
| **Ellipse (Oval)** | `( Attribute )` | Simple / Single-Valued Attribute |
| **Underlined Ellipse** | `( `<u>`Key_Attribute`</u>` )` | Key Attribute (Primary Key) |
| **Double Ellipse** | `(( Multivalued ))` | Multivalued Attribute (e.g., `Phone_No`) |
| **Dashed Ellipse** | `(- - Derived - -)` | Derived Attribute (e.g., `Age` from `DOB`) |
| **Diamond** | `<> Relationship <>` | Relationship Set |
| **Double Diamond** | `<< Identifying >>` | Identifying Relationship for a Weak Entity |
| **Line** | `───────` | Links attributes to entities and entities to relationships |

### Neat ER Diagram

![Entity-Relationship Model Diagram](figures/unit3_q1_er_model.png)

### Explanation of the Diagram
- **`STUDENT`** and **`COURSE`** are strong entity sets represented by rectangles.
- **`Roll_No`** (underlined) is the key attribute uniquely identifying each student; **`Name`** and **`DOB`** are simple attributes; **`Phone_No`** (double oval) is a multivalued attribute; **`Age`** (dashed oval) is a derived attribute computed from `DOB`.
- **`Course_ID`** (underlined) uniquely identifies each course, along with **`Course_Name`**, **`Duration`**, and **`Credits`**.
- **`ENROLLS`** (or **`TAKES`**) is the diamond relationship connecting `STUDENT` and `COURSE`. An `M : N` cardinality indicates that many students can enroll in many courses (or `1 : M` if one student takes multiple courses).

### Advantages of the ER Model
1. **Simple and Visual:** Easy for both database designers and non-technical stakeholders to understand.
2. **Conceptual Clarity:** Clearly separates entities, attributes, and relationships before physical implementation.
3. **Easy Conversion:** Translates directly into relational tables, primary keys, and foreign keys.
4. **Reduces Design Errors:** Identifies redundancy and cardinality constraints early in database design.

**Conclusion:** Thus, the ER Model serves as an essential conceptual tool to represent the structure of a database in a simple and graphical form before creating tables in DBMS.

---

## 2. Explain different types of attributes and relationships in the ER Model.

In the Entity–Relationship (ER) model, **attributes** describe the properties of an entity or relationship, and **relationships** represent associations between two or more entities.

### 1. Types of Attributes in the ER Model

| Attribute Type | Definition & Notation | Example & Diagrammatic Representation |
| :--- | :--- | :--- |
| **(i) Simple (Atomic) Attribute** | An attribute that cannot be divided further into smaller sub-parts. Represented by a single oval. | `Age`, `Gender`, `Roll_No`<br>`( Age ) ─── [ Student ]` |
| **(ii) Composite Attribute** | An attribute that can be divided into smaller meaningful sub-attributes. Represented by an oval branching into sub-ovals. | `Name` $\rightarrow$ (`First_Name`, `Middle_Name`, `Last_Name`)<br>`Address` $\rightarrow$ (`Street`, `City`, `State`, `Pincode`) |
| **(iii) Single-Valued Attribute** | An attribute that holds only a single atomic value for each entity instance. Represented by a standard oval. | `Date_of_Birth`, `Roll_Number`<br>`( Date_of_Birth ) ─── [ Student ]` |
| **(iv) Multi-Valued Attribute** | An attribute that can have more than one value for a single entity instance. Represented by a **double oval**. | `Phone_Number`, `Email`, `Skills`<br>`(( Phone_Number )) ─── [ Student ]` |
| **(v) Derived Attribute** | An attribute whose value is dynamically calculated/derived from another stored attribute. Represented by a **dashed oval**. | `Age` (derived from `Date_of_Birth`)<br>`(- - Age - -) ─── [ Student ]` |
| **(vi) Key Attribute** | An attribute (or set of attributes) that uniquely identifies each entity in an entity set. Represented by an oval with **underlined text**. | `Student_ID`, `Roll_No`, `Employee_ID`<br>`(`<u>`Student_ID`</u>`) ─── [ Student ]` |

```text
Composite Attribute Hierarchy Example:
                 ( Address )
                /   |    \    \
        (Street) (City) (State) (Pincode)
```

---

### 2. Types of Relationships (Mapping Cardinalities)

A **relationship** shows how entities from one entity set are associated with entities from another entity set. Based on **cardinality ratios**, relationships are classified into:

#### (a) One-to-One ($1 : 1$) Relationship
- **Definition:** One entity instance in entity set $A$ is associated with **at most one** entity instance in entity set $B$, and vice versa.
- **Example:** One `Person` has one `Passport`, and each `Passport` belongs to only one `Person`.

```text
[ Person ] ──── 1 ──── < Has > ──── 1 ──── [ Passport ]
```

#### (b) One-to-Many ($1 : N$ or $1 : M$) Relationship
- **Definition:** One entity instance in entity set $A$ can be associated with **many** entity instances in entity set $B$, but each entity in $B$ is associated with **at most one** entity in $A$.
- **Example:** One `Department` employs many `Employees`, but each `Employee` belongs to one `Department`.

```text
[ Department ] ──── 1 ──── < Has > ──── N ──── [ Employee ]
```

#### (c) Many-to-One ($M : 1$) Relationship
- **Definition:** Many entities in entity set $A$ are associated with a single entity in entity set $B$, while each entity in $A$ relates to at most one entity in $B$.
- **Example:** Many `Books` are published by one `Publisher`.

```text
[ Book ] ──── M ──── < Published_By > ──── 1 ──── [ Publisher ]
```

#### (d) Many-to-Many ($M : N$) Relationship
- **Definition:** Many entity instances in entity set $A$ can be associated with many entity instances in entity set $B$, and vice versa.
- **Example:** A `Student` can enroll in many `Courses`, and a `Course` can have many `Students`.

```text
[ Student ] ──── M ──── < Enrolls > ──── N ──── [ Course ]
```

**Conclusion:** Attributes describe the characteristics of entities, and relationships define the structural connections and cardinality rules between entities, enabling accurate real-world database modeling.

---

## 3. Explain Specialization, Generalization, Aggregation and Inheritance with examples.

**Specialization, Generalization, Aggregation, and Inheritance** are core modeling concepts of the **Enhanced Entity–Relationship (EER) Model**. They allow database designers to express superclass/subclass hierarchies and higher-level relationships cleanly.

![EER Concepts: Specialization, Generalization, Inheritance and Aggregation](figures/unit3_q3_eer_concepts.png)

### 1. Specialization (Top-Down Approach)
- **Definition:** Specialization is a **top-down** design process in which a single higher-level entity (superclass) is divided into two or more lower-level sub-entities (subclasses) based on distinguishing characteristics or roles.
- **Key Property:** Sub-entities inherit all common attributes of the parent entity while adding their own specific attributes.
- **Examples:**
  1. `EMPLOYEE` is specialized into `MANAGER`, `ENGINEER`, and `CLERK`.
  2. `PERSON` (with `ID`, `Name`, `Age`) is specialized into `STUDENT` (`RollNo`, `Course`) and `EMPLOYEE` (`EmpID`, `Dept`).

```text
                    [ PERSON ] (ID, Name, Age)
                         |
                       /ISA\
                      /     \
  [ STUDENT ] (RollNo, Course)   [ EMPLOYEE ] (EmpID, Dept)
```

### 2. Generalization (Bottom-Up Approach)
- **Definition:** Generalization is a **bottom-up** design process in which two or more lower-level entities with common attributes are combined to form a single higher-level generalized entity (superclass).
- **Key Property:** It is the exact reverse of specialization and reduces redundancy when multiple entity sets share common attributes.
- **Examples:**
  1. `CAR` and `TRUCK` share common vehicle attributes (`Vehicle_No`, `Price`, `Model`) and are generalized into `VEHICLE`.
  2. `STUDENT` and `EMPLOYEE` are combined upward into `PERSON`.

```text
     [ CAR ]           [ TRUCK ]
          \             /
           \   /ISA\   /
            [ VEHICLE ]
```

### 3. Aggregation
- **Definition:** Standard ER modeling cannot connect a relationship directly to another relationship. **Aggregation** is an abstraction process in which a **relationship set along with its participating entity sets** is treated as a single higher-level entity set so it can participate in another relationship.
- **Examples:**
  1. An `EMPLOYEE` `WORKS_ON` a `PROJECT`. When a `MANAGER` `MONITORS` this specific work assignment (rather than just the employee or the project alone), the entire `(EMPLOYEE — WORKS_ON — PROJECT)` block is enclosed in an aggregation box and linked to `MONITORS`.
  2. A `STUDENT` `TAKES` a `COURSE`, and that enrollment is `ENROLLED_IN` a `SEMESTER` (`SemID`, `Year`).

### 4. Attribute & Relationship Inheritance
- **Definition:** Inheritance is an EER mechanism whereby a lower-level subclass entity ( connected via an `ISA` triangle) automatically inherits **all attributes and relationships** of its higher-level superclass entity, while also defining its own specialized attributes and relationships.
- **Example:** If superclass `STUDENT` has attributes `Roll_No` and `Name`, the subclass `PG_STUDENT` (`ISA` `STUDENT`) automatically inherits `Roll_No` and `Name` and adds its own specialized attribute `Thesis_Topic`.

### Quick Summary Comparison

| Concept | Direction / Mechanism | Purpose | Example |
| :--- | :--- | :--- | :--- |
| **Specialization** | Top-Down ($\downarrow$) | Splits a general entity into specific sub-entities | `EMPLOYEE` $\rightarrow$ `MANAGER`, `ENGINEER`, `CLERK` |
| **Generalization** | Bottom-Up ($\uparrow$) | Merges similar entities into a common superclass | `CAR` + `TRUCK` $\rightarrow$ `VEHICLE` |
| **Aggregation** | Abstraction Box | Treats a relationship + entities as one higher-level entity | `(EMPLOYEE WORKS_ON PROJECT)` $\rightarrow$ `MONITORS` $\rightarrow$ `MANAGER` |
| **Inheritance** | Superclass $\rightarrow$ Subclass | Subclass reuses attributes & relationships of superclass | `PG_STUDENT` inherits `Roll_No`, `Name` from `STUDENT` |

**Conclusion:** Specialization and generalization organize entities into hierarchies, aggregation models relationships among relationships, and inheritance promotes attribute reuse across the EER model.

---

## 4. Draw an ER diagram for a Library/Hospital/Banking System.

### Case Study 1: ER Diagram for a Library Management System (Primary)

An ER diagram for a **Library Management System** models books, library members, librarians/publishers, and book borrowing/reservation transactions.

#### Main Entities and Attributes
1. **`BOOK`:** `Book_ID` (Primary Key), `Title`, `Author`, `Publisher`, `Price` (or `Genre`, `Status`).
2. **`MEMBER`:** `Member_ID` (Primary Key), `Name`, `Department`, `Phone_No`, `Email`, `Address`.
3. **`LIBRARIAN`:** `Librarian_ID` (Primary Key), `Name`.
4. **`PUBLISHER` *(Optional Extended Entity)*:** `Publisher_ID` (Primary Key), `Name`, `Address`, `Phone`.
5. **`ISSUES` / `BORROWS` *(Relationship Attributes)*:** `Issue_Date`, `Return_Date`.
6. **`RESERVATION` *(Optional Weak/Associative Entity)*:** `Reservation_ID` (PK), `Date`, `Status`.

#### Neat ER Diagram

![Library Management System ER Diagram](figures/unit3_q4_library_er.png)

#### Explanation of Relationships and Cardinalities
1. **`MEMBER` — `ISSUES` (`BORROWS`) — `BOOK` ($M : N$ or $1 : M$):**
   - A library member can borrow/issue multiple books, and over time a book can be issued to multiple members ($M : N$).
   - The relationship `ISSUES` records the transaction attributes **`Issue_Date`** and **`Return_Date`**.
2. **`LIBRARIAN` — `MANAGES` — `BOOK` ($1 : N$):**
   - One librarian manages/catalogs many books in the library.
3. **`PUBLISHER` — `PUBLISHED_BY` — `BOOK` ($1 : M$):**
   - One publisher publishes many books, while each book edition is published by one publisher.
4. **`MEMBER` — `RESERVES` — `RESERVATION` — `FOR` — `BOOK`:**
   - A member can place reservations for books that are currently checked out.

#### Relational Schema Mapping
- `MEMBER` (`<u>Member_ID</u>`, `Name`, `Department`, `Phone_No`)
- `LIBRARIAN` (`<u>Librarian_ID</u>`, `Name`)
- `BOOK` (`<u>Book_ID</u>`, `Title`, `Author`, `Publisher`, `Price`, `Librarian_ID (FK)`)
- `BOOK_ISSUE` (`<u>Member_ID (FK)</u>`, `<u>Book_ID (FK)</u>`, `<u>Issue_Date</u>`, `Return_Date`)

---

### Case Study 2: Hospital Management System (Alternative Exam Option)

- **Entities & Attributes:**
  1. **`PATIENT`:** `<u>Patient_ID</u>`, `Name`, `Age`, `Gender`, `Phone`, `Address`
  2. **`DOCTOR`:** `<u>Doctor_ID</u>`, `Name`, `Specialization`, `Phone`, `Department`
  3. **`APPOINTMENT` (or `TREATMENT`):** `<u>Appt_ID</u>`, `Appt_Date`, `Diagnosis`, `Patient_ID (FK)`, `Doctor_ID (FK)`
  4. **`WARD` / `ROOM`:** `<u>Room_No</u>`, `Ward_Type`, `Charges_Per_Day`
  5. **`BILL`:** `<u>Bill_ID</u>`, `Patient_ID (FK)`, `Total_Amount`, `Payment_Status`

```text
(Patient_ID)  (Name)                            (Doctor_ID)  (Specialization)
     \         /                                      \            /
     [ PATIENT ] ──── M ──── < TREATS / CONSULTS > ──── N ──── [ DOCTOR ]
          |                                      \
          1                                   (Diagnosis, Date)
          |
   < ADMITTED_IN > ──── N:1 ──── [ WARD / ROOM ] (Room_No, Type)
```

---

### Case Study 3: Banking Management System (Alternative Exam Option)

- **Entities & Attributes:**
  1. **`CUSTOMER`:** `<u>Customer_ID</u>`, `Name`, `Phone`, `Email`, `Address`
  2. **`BRANCH`:** `<u>Branch_ID</u>`, `Branch_Name`, `IFSC_Code`, `City`
  3. **`ACCOUNT`:** `<u>Account_No</u>`, `Account_Type` (`Savings`/`Current`), `Balance`, `Branch_ID (FK)`
  4. **`LOAN`:** `<u>Loan_ID</u>`, `Loan_Type`, `Amount`, `Interest_Rate`, `Branch_ID (FK)`

```text
[ CUSTOMER ] (Customer_ID, Name, Phone)
   |      \
   | (M:N) \ (M:N)
< DEPOSITS >  < BORROWS >
   |              \
[ ACCOUNT ]      [ LOAN ]
(Account_No,     (Loan_ID, Amount)
 Balance)           /
   \               /
    N             N
     \           /
    < MAINTAINS / OFFERS > (1 : N)
           |
       [ BRANCH ] (Branch_ID, Branch_Name, City)
```

> **Note:** For two more complete ER & Relational Schema case studies (**University Academic Management System** and **Mobile Service Center System**), see [`Database Design Challenge.md`](Database%20Design%20Challenge.md).

---

## 5. Explain the implementation of Primary Key, Foreign Key, UNIQUE, NOT NULL, and CHECK constraints in SQL with suitable examples.

### Introduction
**SQL Constraints** are rules enforced on table columns to maintain the accuracy, validity, consistency, and integrity of data stored in a relational database. Constraints can be specified at the **column level** or **table level** during `CREATE TABLE` or added later via `ALTER TABLE`.

---

### 1. `PRIMARY KEY` Constraint
- **Definition:** Uniquely identifies each record (row) in a database table.
- **Rules:**
  - Does **not** allow duplicate values.
  - Cannot contain `NULL` values (`UNIQUE + NOT NULL`).
  - A table can have **only one** primary key (which may consist of a single column or a composite of multiple columns).
- **SQL Example:**

```sql
CREATE TABLE Students (
    Student_ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT
);
```

| `Student_ID` (PK) | `Name` | `Age` |
| :---: | :--- | :---: |
| `101` | Ravi | `20` |
| `102` | Sita | `21` |

---

### 2. `FOREIGN KEY` Constraint
- **Definition:** Creates a parent–child relationship between two tables by referencing the `PRIMARY KEY` (or `UNIQUE` key) of another table.
- **Rules:**
  - Enforces **referential integrity** — prevents inserting a foreign key value that does not exist in the parent table (prevents orphan records).
- **SQL Example:**

```sql
CREATE TABLE Department (
    Dept_ID INT PRIMARY KEY,
    Dept_Name VARCHAR(50)
);

CREATE TABLE Employee (
    Emp_ID INT PRIMARY KEY,
    Emp_Name VARCHAR(50),
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
);
```

*(Alternative `Orders` example referencing `Students(Student_ID)`)*:
```sql
CREATE TABLE Orders (
    Order_ID INT PRIMARY KEY,
    Student_ID INT,
    Order_Date DATE,
    FOREIGN KEY (Student_ID) REFERENCES Students(Student_ID)
);
```

| `Order_ID` (PK) | `Student_ID` (FK) | `Order_Date` |
| :---: | :---: | :---: |
| `1` | `101` | `2025-06-01` |
| `2` | `102` | `2025-06-02` |

---

### 3. `UNIQUE` Constraint
- **Definition:** Ensures that all non-null values in a column (or group of columns) are distinct.
- **Rules:**
  - Duplicate values are rejected.
  - Unlike `PRIMARY KEY`, a table can have **multiple** `UNIQUE` columns, and `UNIQUE` allows `NULL` values.
- **SQL Example:**

```sql
CREATE TABLE Employees (
    Emp_ID INT PRIMARY KEY,
    Email VARCHAR(100) UNIQUE,
    Name VARCHAR(50)
);
```

| `Emp_ID` (PK) | `Email` (UNIQUE) | `Name` |
| :---: | :--- | :--- |
| `1` | `ravi@gmail.com` | Ravi |
| `2` | `sita@gmail.com` | Sita |

---

### 4. `NOT NULL` Constraint
- **Definition:** Ensures that a column cannot store a `NULL` (empty/unknown) value.
- **Rules:** Every `INSERT` or `UPDATE` must provide a mandatory valid value for that column.
- **SQL Example:**

```sql
CREATE TABLE Products (
    Product_ID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Price DECIMAL(10, 2) NOT NULL
);
```

| `Product_ID` (PK) | `Name` (NOT NULL) | `Price` (NOT NULL) |
| :---: | :--- | :---: |
| `1` | Laptop | `50000.00` |
| `2` | Mouse | `1200.00` |

---

### 5. `CHECK` Constraint
- **Definition:** Restricts the domain/range of values that can be placed in a column by evaluating a Boolean condition.
- **Rules:** If the condition evaluates to `FALSE` for an inserted or updated value, the DBMS rejects the operation.
- **SQL Example:**

```sql
CREATE TABLE Employees_Check (
    Emp_ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT CHECK (Age >= 18),
    Price DECIMAL(8, 2) CHECK (Price > 0)
);
```

| `Emp_ID` (PK) | `Name` | `Age` (`>= 18`) |
| :---: | :--- | :---: |
| `1` | Ravi | `22` |
| `2` | Sita | `25` |

### Summary Comparison of SQL Constraints

| Constraint | Prevents Duplicates? | Allows `NULL`? | Max per Table | Main Purpose |
| :--- | :---: | :---: | :---: | :--- |
| **`PRIMARY KEY`** | Yes | No | 1 | Uniquely identifies every row |
| **`FOREIGN KEY`** | No (unless also unique) | Yes | Unlimited | Links child table to parent table |
| **`UNIQUE`** | Yes | Yes | Unlimited | Ensures distinct non-key values (e.g., `Email`) |
| **`NOT NULL`** | No | No | Unlimited | Enforces mandatory field entry |
| **`CHECK`** | No | Yes (unless restricted) | Unlimited | Validates custom boolean rules (e.g., `Age >= 18`) |

**Conclusion:** SQL constraints enforce automatic data validation at the schema level: `PRIMARY KEY` identifies records uniquely, `FOREIGN KEY` preserves table relationships, `UNIQUE` prevents duplicates, `NOT NULL` avoids missing values, and `CHECK` enforces custom domain conditions.

---

## 6. What are integrity constraints? Explain Entity Integrity, Referential Integrity, and Domain Integrity constraints with suitable SQL examples.

### Introduction
**Integrity Constraints** are a set of rules and conditions used in a relational database to maintain the **accuracy, validity, completeness, and consistency** of data. They prevent invalid, contradictory, or meaningless data from being entered or stored in tables during `INSERT`, `UPDATE`, and `DELETE` operations.

The three fundamental types of integrity constraints in the Relational Model are:
1. **Entity Integrity Constraint**
2. **Referential Integrity Constraint**
3. **Domain Integrity Constraint**

---

### 1. Entity Integrity Constraint
- **Rule:** States that every relation (table) must have a **Primary Key**, and **no attribute participating in the Primary Key can be `NULL` or duplicated**.
- **Why it is required:** If a primary key were allowed to be `NULL`, we could not uniquely identify or distinguish between tuples containing `NULL`, violating the fundamental definition of a relation.
- **SQL Implementation:** Enforced using the `PRIMARY KEY` constraint.

```sql
CREATE TABLE Student (
    Roll_No INT PRIMARY KEY,
    Name VARCHAR(50),
    Age INT
);
```

| `Roll_No` (PK — Unique & Not Null) | `Name` | `Age` |
| :---: | :--- | :---: |
| `101` | Ravi | `20` |
| `102` | Sita | `21` |

*(Inserting `(NULL, 'Hari', 20)` or `(101, 'Hari', 20)` is rejected by Entity Integrity.)*

---

### 2. Referential Integrity Constraint
- **Rule:** Specified between two related tables (a **referencing/child** table and a **referenced/parent** table). It states that any **Foreign Key** value in the child table must either:
  1. Match an existing **Primary Key** value in the referenced parent table, **or**
  2. Be wholly `NULL` (if the foreign key column allows `NULL`s).
- **Why it is required:** Prevents **orphan records** (e.g., an employee assigned to a non-existent department `Dept_ID = 999`, or an order placed by a non-existent student).
- **SQL Implementation:** Enforced using the `FOREIGN KEY ... REFERENCES` clause (with optional `ON DELETE CASCADE` or `ON DELETE SET NULL`).

```sql
CREATE TABLE Department (
    Dept_ID INT PRIMARY KEY,
    Dept_Name VARCHAR(50)
);

CREATE TABLE Employee (
    Emp_ID INT PRIMARY KEY,
    Emp_Name VARCHAR(50),
    Dept_ID INT,
    FOREIGN KEY (Dept_ID) REFERENCES Department(Dept_ID)
);
```

**Parent Table (`Student`):**

| `Student_ID` (PK) | `Name` |
| :---: | :--- |
| `101` | Ravi |
| `102` | Sita |

**Child Table (`Orders`):**

| `Order_ID` (PK) | `Student_ID` (FK $\rightarrow$ `Student`) |
| :---: | :---: |
| `1` | `101` (Valid — exists in `Student`) |
| `2` | `102` (Valid — exists in `Student`) |

---

### 3. Domain Integrity Constraint
- **Rule:** Specifies that the value of every attribute in a tuple must be an **atomic value** drawn from its defined **domain** (data type, length, format, nullability, and permissible range).
- **Why it is required:** Prevents nonsensical values (such as storing text in a salary column, negative ages, or invalid gender codes).
- **SQL Implementation:** Enforced using **Data Types** (`INT`, `VARCHAR`, `DATE`, `DECIMAL`), **`NOT NULL`**, **`DEFAULT`**, and **`CHECK`** constraints.

```sql
CREATE TABLE Person (
    Person_ID INT PRIMARY KEY,
    Name VARCHAR(50) NOT NULL,
    Age INT CHECK (Age BETWEEN 18 AND 60),
    Gender VARCHAR(10) CHECK (Gender IN ('Male', 'Female'))
);
```

| `Person_ID` | `Name` | `Age` (`18..60`) | `Gender` |
| :---: | :--- | :---: | :---: |
| `1` | Ravi | `22` | `Male` |
| `2` | Sita | `25` | `Female` |

### Summary Table

| Integrity Type | Target Element | Core Rule | SQL Mechanism |
| :--- | :--- | :--- | :--- |
| **Entity Integrity** | Primary Key of a table | Primary Key must be **unique** and **`NOT NULL`** | `PRIMARY KEY` |
| **Referential Integrity** | Foreign Key between tables | Foreign Key must match an existing parent PK or be `NULL` | `FOREIGN KEY ... REFERENCES` |
| **Domain Integrity** | Individual column values | Values must obey data type, range, and format rules | Data types, `CHECK`, `NOT NULL` |

**Conclusion:** Integrity constraints safeguard data quality and correctness: Entity Integrity uniquely identifies tuples, Referential Integrity maintains valid cross-table relationships, and Domain Integrity enforces permissible attribute values.

---

## 7. Explain Nested and Correlated Subqueries with examples.

### Introduction
A **Subquery** (or **Inner Query**) is a `SELECT` query embedded inside another SQL query (the **Outer Query**), usually within the `WHERE`, `HAVING`, or `FROM` clause and enclosed in parentheses `(...)`. Subqueries are primarily classified into:
1. **Nested (Independent) Subqueries**
2. **Correlated Subqueries**

---

### 1. Nested Subquery (Non-Correlated / Independent Subquery)
- **Definition:** A nested subquery is completely **independent** of the outer query.
- **Execution Flow (Bottom-Up):**
  1. The **inner query** executes **first, only once**.
  2. Its output (a single value or a list of values) is passed to the **outer query**.
  3. The outer query executes using the result returned by the inner query.

#### Example 1 (Highest Marks)
Find the name of the student who has scored the highest marks:
```sql
SELECT Name
FROM Student
WHERE Marks = (SELECT MAX(Marks) FROM Student);
```
- **Explanation:** The inner query `(SELECT MAX(Marks) FROM Student)` runs first and returns a single value (e.g., `90`). The outer query then selects the student(s) whose `Marks = 90`.

#### Example 2 (Above Average Marks in Maths)
Find the names of students who scored more than the average marks in `'Maths'`:

| `StudentID` | `Name` | `Marks` | `Subject` |
| :---: | :--- | :---: | :--- |
| `1` | Ravi | `90` | Maths |
| `2` | Sita | `70` | Maths |
| `3` | Hari | `85` | Science |
| `4` | Anu | `60` | Maths |

```sql
SELECT Name
FROM Students
WHERE Marks > (
    SELECT AVG(Marks)
    FROM Students
    WHERE Subject = 'Maths'
);
```
- **Explanation:** Inner query computes `AVG(Marks)` for Maths $= (90 + 70 + 60)/3 = 73.33$. Outer query returns `Ravi` (`90`) and `Hari` (`85`).

---

### 2. Correlated Subquery
- **Definition:** A correlated subquery **depends on the outer query** for its parameter values (it references one or more columns of the outer table in its `WHERE` clause).
- **Execution Flow (Row-by-Row / Top-Down):**
  1. The outer query fetches a candidate row.
  2. The inner query executes **once for that specific outer row**, using the outer row's column value.
  3. The outer query evaluates the condition and repeats the process for **every row** of the outer table.

#### Example 1 (Salary Greater Than Department Average)
Find employees whose salary is greater than the average salary of **their own department**:
```sql
SELECT E1.Emp_Name, E1.Salary, E1.Dept_ID
FROM Employee E1
WHERE E1.Salary > (
    SELECT AVG(E2.Salary)
    FROM Employee E2
    WHERE E2.Dept_ID = E1.Dept_ID
);
```
- **Explanation:** For each employee `E1` in the outer query, the inner query calculates the average salary of department `E1.Dept_ID`. If `E1.Salary` exceeds that department's average, the row is included in the result.

#### Example 2 (Coworkers in Same Department)
Find the names of employees who work in the same department as `'Ravi'`:

| `EmpID` | `Name` | `DepartmentID` |
| :---: | :--- | :---: |
| `1` | Ravi | `10` |
| `2` | Sita | `10` |
| `3` | Hari | `20` |
| `4` | Anu | `30` |

```sql
SELECT Name
FROM Employee e1
WHERE DepartmentID = (
    SELECT DepartmentID
    FROM Employee e2
    WHERE e2.Name = 'Ravi'
      AND e2.DepartmentID = e1.DepartmentID
);
```

---

### Differences Between Nested and Correlated Subqueries

| Feature | Nested (Independent) Subquery | Correlated Subquery |
| :--- | :--- | :--- |
| **Dependency** | Inner query is completely **independent** of the outer query. | Inner query **depends on** column values from the outer query. |
| **Execution Order** | Bottom-Up: Inner query runs **first** $\rightarrow$ Outer query runs second. | Top-Down / Synchronized: Outer row fetched $\rightarrow$ Inner query evaluated. |
| **Number of Executions** | Inner query executes **only once**. | Inner query executes **repeatedly ($N$ times)**, once for each outer row. |
| **Performance** | Faster and more efficient ($O(1)$ inner evaluation). | Slower on large tables due to repeated per-row evaluation. |
| **Typical Use Case** | Global aggregates (`MAX`, `AVG`) or static set membership (`IN`, `NOT IN`). | Row-by-row group comparisons (e.g., comparing with own department's average) or `EXISTS`. |

**Conclusion:** Both nested and correlated subqueries enable powerful multi-step data retrieval in SQL. Nested subqueries evaluate a standalone condition once, whereas correlated subqueries dynamically evaluate conditions relative to each row of the outer query.

---

## 8. Explain different types of SQL Joins with suitable examples.

### Introduction
An **SQL Join** is used to combine rows from two or more tables in a single query based on a related column (typically a Primary Key–Foreign Key relationship) between them.

The main types of SQL Joins are:
1. **`INNER JOIN`**
2. **`LEFT JOIN` (`LEFT OUTER JOIN`)**
3. **`RIGHT JOIN` (`RIGHT OUTER JOIN`)**
4. **`FULL JOIN` (`FULL OUTER JOIN`)**
5. **`CROSS JOIN`**
6. **`SELF JOIN`**

![SQL Joins Venn Diagrams](figures/unit3_q8_sql_joins.png)

---

### Sample Input Tables Used for Examples

**`Employee` Table:**

| `EmpID` | `EmpName` | `DeptID` | `ManagerID` |
| :---: | :--- | :---: | :---: |
| `1` | Ratan | `10` | `NULL` |
| `2` | Vivek | `20` | `1` |
| `3` | Lochan | `10` | `1` |
| `4` | Teja | `40` | `2` |

**`Department` Table:**

| `DeptID` | `DeptName` |
| :---: | :--- |
| `10` | CSE |
| `20` | IT |
| `30` | AIML |

---

### 1. `INNER JOIN`
- **Definition:** Returns **only the rows that have matching values** in both tables. Unmatched rows from either table are excluded.
- **SQL Query:**
```sql
SELECT E.EmpID, E.EmpName, D.DeptName
FROM Employee E
INNER JOIN Department D
    ON E.DeptID = D.DeptID;
```
- **Result (`DeptID = 40` in `Employee` and `DeptID = 30` in `Department` are excluded):**

| `EmpID` | `EmpName` | `DeptName` |
| :---: | :--- | :--- |
| `1` | Ratan | CSE |
| `2` | Vivek | IT |
| `3` | Lochan | CSE |

---

### 2. `LEFT JOIN` (`LEFT OUTER JOIN`)
- **Definition:** Returns **all rows from the left table (`Employee`)** and the matching rows from the right table (`Department`). If no match is found in the right table, `NULL` is returned for right-table columns.
- **SQL Query:**
```sql
SELECT E.EmpID, E.EmpName, D.DeptName
FROM Employee E
LEFT OUTER JOIN Department D
    ON E.DeptID = D.DeptID;
```
- **Result:**

| `EmpID` | `EmpName` | `DeptName` |
| :---: | :--- | :--- |
| `1` | Ratan | CSE |
| `2` | Vivek | IT |
| `3` | Lochan | CSE |
| `4` | Teja | `NULL` |

---

### 3. `RIGHT JOIN` (`RIGHT OUTER JOIN`)
- **Definition:** Returns **all rows from the right table (`Department`)** and the matching rows from the left table (`Employee`). If no match is found in the left table, `NULL` is returned for left-table columns.
- **SQL Query:**
```sql
SELECT E.EmpID, E.EmpName, D.DeptName
FROM Employee E
RIGHT OUTER JOIN Department D
    ON E.DeptID = D.DeptID;
```
- **Result:**

| `EmpID` | `EmpName` | `DeptName` |
| :---: | :--- | :--- |
| `1` | Ratan | CSE |
| `2` | Vivek | IT |
| `3` | Lochan | CSE |
| `NULL` | `NULL` | AIML |

---

### 4. `FULL JOIN` (`FULL OUTER JOIN`)
- **Definition:** Returns **all rows when there is a match in either the left or the right table**. Unmatched rows from both tables are included, with `NULL` filling in the missing side's columns.
- **SQL Query:**
```sql
SELECT E.EmpID, E.EmpName, D.DeptName
FROM Employee E
FULL OUTER JOIN Department D
    ON E.DeptID = D.DeptID;
```
- **Result:**

| `EmpID` | `EmpName` | `DeptName` |
| :---: | :--- | :--- |
| `1` | Ratan | CSE |
| `2` | Vivek | IT |
| `3` | Lochan | CSE |
| `4` | Teja | `NULL` |
| `NULL` | `NULL` | AIML |

---

### 5. `CROSS JOIN` (Cartesian Join)
- **Definition:** Returns the **Cartesian product** (all possible $m \times n$ combinations of rows) from both tables. No `ON` join condition is specified.
- **SQL Query:**
```sql
SELECT E.EmpName, D.DeptName
FROM Employee E
CROSS JOIN Department D;
```
- **Result (First 4 of $4 \times 3 = 12$ combinations):**

| `EmpName` | `DeptName` |
| :--- | :--- |
| Ratan | CSE |
| Ratan | IT |
| Ratan | AIML |
| Vivek | CSE |
| *... (all combinations)* | *...* |

---

### 6. `SELF JOIN`
- **Definition:** A regular join in which **a table is joined with itself** using table aliases. It is widely used for querying hierarchical relationships (such as `Employee` $\rightarrow$ `Manager`) stored within the same table.
- **SQL Query:**
```sql
SELECT A.EmpName AS Employee, B.EmpName AS Manager
FROM Employee A
LEFT JOIN Employee B
    ON A.ManagerID = B.EmpID;
```
- **Result:**

| `Employee` | `Manager` |
| :--- | :--- |
| Ratan | `NULL` |
| Vivek | Ratan |
| Lochan | Ratan |
| Teja | Vivek |

**Conclusion:** Different types of SQL joins allow flexible retrieval of relational data across multiple tables depending on whether unmatched rows from the left, right, or both tables need to be preserved.

---

## 9. Explain SQL Views. Differentiate updatable and non-updatable views with examples.

### 1. SQL Views
- **Definition:** A **View** is a **virtual table** in SQL whose contents are defined by a stored `SELECT` query. Unlike a base table, a standard view does not physically store data on disk (except in the case of a *Materialized View*); instead, it dynamically computes data from one or more underlying base tables whenever queried.
- **Advantages of Views:**
  1. **Security:** Hides sensitive columns (like `Salary` or `Password`) by exposing only selected columns/rows to users.
  2. **Query Simplification:** Encapsulates complex multi-table joins into a simple virtual table name.
  3. **Reusability & Logical Data Independence:** Shields applications from changes in underlying base table schemas.

#### Basic Syntax & Example
```sql
-- Create a virtual view showing only student names and marks
CREATE VIEW StudentView AS
SELECT Name, Marks
FROM Students;

-- Query the view just like a regular table
SELECT * FROM StudentView;
```

---

### 2. Updatable Views
- **Definition:** An **updatable view** is a view through which we can perform `INSERT`, `UPDATE`, and `DELETE` data modification statements, and those changes are automatically propagated to the underlying base table.
- **Conditions for a View to be Updatable:**
  1. Defined over a **single base table** (no complex `JOIN`s).
  2. Includes the **Primary Key** and all `NOT NULL` columns (without default values) of the base table.
  3. Does **not** contain `GROUP BY`, `HAVING`, `DISTINCT`, aggregate functions (`SUM`, `AVG`, `COUNT`, `MIN`, `MAX`), or set operations (`UNION`, `INTERSECT`).

#### Example of an Updatable View
```sql
CREATE VIEW Emp_View AS
SELECT EmpID, EmpName, DeptID
FROM Employee;

-- Valid DML operations through the updatable view:
INSERT INTO Emp_View VALUES (4, 'Rithvik', 30);

UPDATE Emp_View
SET DeptID = 20
WHERE EmpID = 1;

DELETE FROM Emp_View
WHERE EmpID = 3;
```

| `EmpID` | `EmpName` | `DeptID` |
| :---: | :--- | :---: |
| `1` | Ratan | `10` $\rightarrow$ `20` |
| `2` | Vivek | `20` |
| `4` | Rithvik | `30` *(Inserted)* |

---

### 3. Non-Updatable Views (Read-Only Views)
- **Definition:** A **non-updatable view** is a view that can **only be used for reading (`SELECT`) data** and does not allow `INSERT`, `UPDATE`, or `DELETE` operations because the DBMS cannot unambiguously map a modification back to a single base table row.
- **Causes:** Created using multiple tables (`JOIN`), `GROUP BY`, `HAVING`, `DISTINCT`, aggregate functions, or `UNION`.

#### Example of a Non-Updatable View
```sql
CREATE VIEW Emp_Dept_View AS
SELECT E.EmpID, E.EmpName, D.DeptName
FROM Employee E
JOIN Department D
    ON E.DeptID = D.DeptID;

-- Attempting to modify this joined view fails:
INSERT INTO Emp_Dept_View VALUES (5, 'Teja', 'DS');
-- Error: ORA-01732: data manipulation operation not legal on this view
```

---

### 4. Comparison: Updatable View vs. Non-Updatable View

| Aspect / Feature | Updatable View | Non-Updatable View |
| :--- | :--- | :--- |
| **1. Definition** | Allows `INSERT`, `UPDATE`, and `DELETE` operations on underlying data. | Does **not** allow `INSERT`, `UPDATE`, or `DELETE` operations (Read-Only). |
| **2. Source Tables** | Derived from a **single base table**. | Often derived from **multiple joined tables** (`JOIN`, `UNION`). |
| **3. Clauses Allowed** | Simple `SELECT ... WHERE` over base columns. | Uses `GROUP BY`, `HAVING`, `DISTINCT`, or aggregate functions (`AVG`, `SUM`). |
| **4. Primary Key Requirement** | Must include the base table's **unique/primary key** to identify rows. | Not required; rows may represent aggregated groups. |
| **5. Main Purpose** | Row-level security and simplified data manipulation. | Complex reporting, summaries, and read-only data presentation. |

---

### 5. Bonus Note: Standard View vs. Materialized View (Lab Reference)
- **Standard View (`CREATE VIEW`):** Stores only the SQL query definition; recomputes the result every time it is queried.
- **Materialized View (`CREATE MATERIALIZED VIEW`):** Physically stores the precomputed query result on disk for fast access to expensive aggregate/join queries, and is refreshed when needed (e.g., `EXEC DBMS_MVIEW.REFRESH('MV_Department_Salary');` in Oracle).

**Conclusion:** SQL views simplify data access and strengthen security. Updatable views allow direct modification of a single underlying table, while non-updatable views provide read-only access to joined or aggregated data.

---

## 10. Explain Relational Set Operations with suitable examples.

### Introduction
**Relational Set Operations** combine or compare the tuple sets of two relations and produce a new relation as their result.
- **Union Compatibility Requirement:** For binary set operations (`UNION`, `INTERSECTION`, `DIFFERENCE`), the two input relations $R$ and $S$ must be **union-compatible**:
  1. Both relations must have the **same number of attributes (degree/arity)**.
  2. Corresponding attributes must have **compatible data types (domains)**.

The five core relational set operations are:
1. **`UNION` ($R \cup S$)**
2. **`INTERSECTION` ($R \cap S$)**
3. **`SET DIFFERENCE` ($R - S$)**
4. **`CARTESIAN PRODUCT` ($R \times S$)**
5. **`COMPLEMENT` ($R^c$)**

---

### 1. UNION ($R \cup S$)
- **Definition:** The union of two relations $R$ and $S$ returns all tuples that appear in **either $R$, or $S$, or both**, automatically eliminating duplicate tuples (`UNION ALL` in SQL retains duplicates).
- **SQL Equivalent:** `SELECT * FROM R UNION SELECT * FROM S;`

**Relation $R$ (`Employee_Branch1`):**

| `Eid` | `Name` | `Dept` |
| :---: | :--- | :--- |
| `101` | Ravi | CSE |
| `102` | Sita | ECE |

**Relation $S$ (`Employee_Branch2`):**

| `Eid` | `Name` | `Dept` |
| :---: | :--- | :--- |
| `103` | Hari | ME |
| `102` | Sita | ECE |

**Result of $R \cup S$:**

| `Eid` | `Name` | `Dept` |
| :---: | :--- | :--- |
| `101` | Ravi | CSE |
| `102` | Sita | ECE |
| `103` | Hari | ME |

---

### 2. INTERSECTION ($R \cap S$)
- **Definition:** The intersection of two relations $R$ and $S$ returns **only the tuples that are common to both** $R$ and $S$.
- **SQL Equivalent:** `SELECT * FROM R INTERSECT SELECT * FROM S;`

**Result of $R \cap S$ (using $R$ and $S$ above):**

| `Eid` | `Name` | `Dept` |
| :---: | :--- | :--- |
| `102` | Sita | ECE |

---

### 3. SET DIFFERENCE ($R - S$)
- **Definition:** The difference of two relations $R - S$ returns all tuples that are **present in relation $R$ but NOT present in relation $S$**. Note that $R - S \neq S - R$.
- **SQL Equivalent:** `SELECT * FROM R MINUS SELECT * FROM S;` (Oracle) or `EXCEPT` (PostgreSQL / SQL Server).

**Result of $R - S$ (using $R$ and $S$ above):**

| `Eid` | `Name` | `Dept` |
| :---: | :--- | :--- |
| `101` | Ravi | CSE |

---

### 4. CARTESIAN PRODUCT ($R \times S$)
- **Definition:** Combines **every tuple of relation $R$ with every tuple of relation $S$**. If $R$ has $m$ tuples and $p$ attributes, and $S$ has $n$ tuples and $q$ attributes, then $R \times S$ contains $m \times n$ tuples and $p + q$ attributes.
- **SQL Equivalent:** `SELECT * FROM R CROSS JOIN S;`

**Relation $R$ (`Student`):**

| `Sid` | `Name` |
| :---: | :--- |
| `1` | Ajay |
| `2` | Balu |

**Relation $S$ (`Course`):**

| `Cid` | `Cname` |
| :---: | :--- |
| `C1` | DBMS |
| `C2` | Python |

**Result of $R \times S$:**

| `Sid` | `Name` | `Cid` | `Cname` |
| :---: | :--- | :---: | :--- |
| `1` | Ajay | `C1` | DBMS |
| `1` | Ajay | `C2` | Python |
| `2` | Balu | `C1` | DBMS |
| `2` | Balu | `C2` | Python |

---

### 5. COMPLEMENT ($R^c$)
- **Definition:** The complement of a relation $R$ (denoted $R^c$ or $U - R$) contains all tuples from the **Universal Set $U$** (all possible valid tuples over the domain) that are **not present in $R$**.
- **Example:**
  - Universal Set $U = \{1, 2, 3, 4, 5\}$
  - Relation $R = \{1, 2, 3\}$
  - Complement $R^c = U - R = \{4, 5\}$

**Conclusion:** Relational set operations form the mathematical foundation of relational algebra and SQL set queries (`UNION`, `INTERSECT`, `MINUS`/`EXCEPT`, and `CROSS JOIN`).
