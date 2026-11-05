# UNIT 4 — Normalization, Transactions & Concurrency

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

## Q1. Normalization, 1NF and 2NF

> **Question:** Explain the purpose of Normalization and discuss 1NF, 2NF with suitable examples.

---

### Definition and Purpose of Normalization

**Normalization** is the process of organizing data in relational tables to reduce unnecessary data redundancy and prevent insertion, update, and deletion anomalies. It divides large tables into smaller related tables and connects them using keys. The objective is to store each fact in an appropriate place while maintaining data consistency.

### Problems in an Unnormalized Table

Consider the following table:

| Student_ID | Student_Name | Courses |
|---|---|---|
| 101 | Arun | DBMS, Java |
| 102 | Bina | Python, DBMS |

The `Courses` column contains multiple values in a single cell. This makes searching, updating, and maintaining the data difficult.

The main anomalies are:

1. **Insertion anomaly:** A course cannot be stored easily until a student enrolls in it, if course information is kept only in the student-enrollment table.
2. **Update anomaly:** If a student's name or course details are repeated in many rows, every copy must be updated. Missing one copy creates inconsistent data.
3. **Deletion anomaly:** Deleting the last student enrolled in a course may also remove the only stored information about that course.

### First Normal Form (1NF)

A relation is in **First Normal Form (1NF)** when every attribute contains a single, atomic value and there are no repeating groups or multivalued cells. Each row must be identifiable, and each cell must hold one value from its attribute's domain.

The unnormalized table can be converted into 1NF by storing one course per row:

| Student_ID | Student_Name | Course |
|---|---|---|
| 101 | Arun | DBMS |
| 101 | Arun | Java |
| 102 | Bina | Python |
| 102 | Bina | DBMS |

The composite key is `(Student_ID, Course)` because a student can enroll in several courses.

**1NF conversion:**

```text
UNNORMALIZED                         1NF
+----------------------+             +-------------------------------+
| ID | Name | Courses  |             | ID  | Name | Course            |
+----------------------+   ----->    +-------------------------------+
|101 | Arun | DBMS,Java|             |101  | Arun | DBMS              |
|102 | Bina | Python...|             |101  | Arun | Java              |
+----------------------+             |102  | Bina | Python            |
                                     |102  | Bina | DBMS              |
                                     +-------------------------------+
```

### Second Normal Form (2NF)

A relation is in **Second Normal Form (2NF)** when:

1. It is already in 1NF.
2. Every non-prime attribute is fully functionally dependent on the whole of every candidate key. In simple terms, no non-key attribute should depend on only a part of a composite candidate key.

A **partial dependency** occurs when a non-key attribute depends on only part of a composite key.

Consider this 1NF relation:

`ENROLLMENT(Student_ID, Course_ID, Student_Name, Course_Name, Grade)`

The candidate key is `(Student_ID, Course_ID)`. Its functional dependencies include:

```text
(Student_ID, Course_ID) -> Grade
Student_ID               -> Student_Name
Course_ID                -> Course_Name
```

`Student_Name` depends only on `Student_ID`, and `Course_Name` depends only on `Course_ID`. These are partial dependencies, so the relation violates 2NF.

### Conversion into 2NF

Decompose the relation into three tables:

**STUDENT**

| Student_ID (PK) | Student_Name |
|---|---|
| 101 | Arun |
| 102 | Bina |

**COURSE**

| Course_ID (PK) | Course_Name |
|---|---|
| C01 | DBMS |
| C02 | Java |

**ENROLLMENT**

| Student_ID (PK, FK) | Course_ID (PK, FK) | Grade |
|---|---|---|
| 101 | C01 | A |
| 101 | C02 | B |
| 102 | C01 | A |

```text
             +------------------+
             |     STUDENT      |
             | Student_ID (PK)  |
             | Student_Name     |
             +--------+---------+
                      |
                      | 1
                      | N
             +--------+---------+       +------------------+
             |    ENROLLMENT    |   N   |      COURSE      |
             | Student_ID (FK)  |-------| Course_ID (PK)   |
             | Course_ID (FK)   |   1   | Course_Name      |
             | Grade            |       +------------------+
             +------------------+
```

Now, student details are stored only in `STUDENT`, course details only in `COURSE`, and enrollment-specific information in `ENROLLMENT`. The non-key attributes depend on the complete key of their respective relations.

### Difference Between 1NF and 2NF

| Parameter | 1NF | 2NF |
|---|---|---|
| Main rule | Values must be atomic | Must satisfy 1NF and eliminate partial dependencies |
| Repeating groups | Not allowed | Not allowed because 1NF is required |
| Partial dependency | May exist | Not allowed for non-prime attributes |
| Composite key | Not required | Relevant when a candidate key is composite |
| Main objective | Remove multivalued cells | Ensure full dependency on the whole candidate key |
| Redundancy | May remain | Reduced by removing partial dependencies |

### Advantages of Normalization

1. It reduces duplicate data and saves storage space.
2. It prevents insertion, update, and deletion anomalies.
3. It improves consistency and integrity of stored information.
4. It makes the database structure easier to maintain.

## Q2. Fourth and Fifth Normal Forms

> **Question:** Explain 4NF, and 5NF with suitable examples.

---

### Introduction

**Fourth Normal Form (4NF)** and **Fifth Normal Form (5NF)** are higher levels of database normalization. 4NF deals mainly with unwanted **multivalued dependencies**, while 5NF deals with redundancy caused by certain **join dependencies**.

### Fourth Normal Form (4NF)

A relation is in **Fourth Normal Form (4NF)** if:

1. It is in BCNF.
2. It has no non-trivial multivalued dependency unless the determinant is a superkey.

A **multivalued dependency (MVD)**, written as `X ->> Y`, exists when a value of X determines a set of Y values independently of the remaining attributes in the relation.

### Example of 4NF Violation

Suppose a student can have several hobbies and can know several languages. Hobbies and languages are independent of each other.

`STUDENT_INFO(Student, Hobby, Language)`

| Student | Hobby | Language |
|---|---|---|
| Arun | Chess | English |
| Arun | Chess | Telugu |
| Arun | Music | English |
| Arun | Music | Telugu |

The relation contains two independent multivalued dependencies:

```text
Student ->> Hobby
Student ->> Language
```

For one student, every hobby is combined with every language. This creates repeated combinations. Since `Student` is not a superkey of the combined relation, it violates 4NF.

### Conversion into 4NF

Decompose the relation into:

**STUDENT_HOBBY(Student, Hobby)**

| Student | Hobby |
|---|---|
| Arun | Chess |
| Arun | Music |

**STUDENT_LANGUAGE(Student, Language)**

| Student | Language |
|---|---|
| Arun | English |
| Arun | Telugu |

```text
STUDENT_INFO(Student, Hobby, Language)
                  |
                  | Decompose using independent MVDs
            +-----+------+
            |            |
            v            v
+------------------+  +----------------------+
| STUDENT_HOBBY    |  | STUDENT_LANGUAGE     |
| Student, Hobby   |  | Student, Language    |
+------------------+  +----------------------+
```

The hobbies and languages are now stored separately. Their combinations can be generated when needed by joining the two relations on `Student`.

### Fifth Normal Form (5NF)

A relation is in **Fifth Normal Form (5NF)**, also called **Project-Join Normal Form (PJNF)**, if every non-trivial join dependency is implied by the candidate keys of the relation. A relation in 5NF cannot be further decomposed into smaller relations without losing information, except where the decomposition is required by its keys and join dependencies.

A **join dependency (JD)** states that a relation can be reconstructed exactly by joining two or more of its projections.

### Example of 5NF

Consider a relation:

`SUPPLIER_PART_PROJECT(Supplier, Part, Project)`

It records which supplier supplies which part for which project. Suppose the business rules establish that this three-way information is completely determined by these independent pairwise relationships:

- Supplier and Part (`SP`): which parts a supplier can supply.
- Supplier and Project (`SJ`): which projects a supplier serves.
- Part and Project (`PJ`): which parts are required by a project.

The ternary relation has the join dependency:

```text
*(SP, SJ, PJ)
```

It can therefore be decomposed into:

```text
SP(Supplier, Part)
SJ(Supplier, Project)
PJ(Part, Project)
```

The original relation is reconstructed by joining these three relations on their common attributes:

```sql
SELECT SP.Supplier, SP.Part, SJ.Project
FROM SP
JOIN SJ ON SP.Supplier = SJ.Supplier
JOIN PJ ON SP.Part = PJ.Part
       AND SJ.Project = PJ.Project;
```

This decomposition is valid only when the stated business rule guarantees that the join produces exactly the original tuples. Without that rule, joining the projections may create **spurious tuples**, so the decomposition would not be lossless.

### Difference Between 4NF and 5NF

| Parameter | 4NF | 5NF |
|---|---|---|
| Full name | Fourth Normal Form | Fifth Normal Form / PJNF |
| Main concern | Multivalued dependency | Join dependency |
| Requirement | BCNF and no non-trivial MVD with a non-superkey determinant | Every non-trivial JD must be implied by candidate keys |
| Redundancy removed | Repetition caused by independent multivalued facts | Redundancy caused by complex join relationships |
| Decomposition | Separates independent multivalued attributes | Splits a relation into smaller relations that can be losslessly joined |
| Typical example | Student, hobby, language | Supplier, part, project |

### Advantages

1. 4NF removes unnecessary combinations caused by independent multivalued attributes.
2. 5NF removes redundancy that remains due to complex join dependencies.
3. Both forms improve consistency and reduce anomalies in highly structured databases.

## Q3. Functional Dependency and Types of Dependencies

> **Question:** Explain Functional Dependency and different types of dependencies with examples.

---

### Definition

A **Functional Dependency (FD)** is a relationship between attributes in a relation. An FD `X -> Y` means that if two rows have the same value for attribute set X, they must also have the same value for attribute set Y. Here, X is called the **determinant**, and Y is the **dependent attribute set**.

For example, in `STUDENT(Student_ID, Name, Department)`, if each student ID identifies exactly one student, then:

```text
Student_ID -> Name, Department
```

### Types of Functional Dependencies

#### 1. Trivial Functional Dependency

An FD `X -> Y` is **trivial** if Y is a subset of X. It is always true by the definition of set inclusion.

Example:

```text
(Student_ID, Name) -> Name
```

#### 2. Non-Trivial Functional Dependency

An FD is **non-trivial** if Y is not a subset of X.

Example:

```text
Student_ID -> Name
```

It is completely non-trivial when X and Y have no attributes in common.

#### 3. Full Functional Dependency

An attribute is **fully functionally dependent** on a composite determinant if it depends on the entire determinant and not on any proper subset of it.

Example:

```text
(Student_ID, Course_ID) -> Grade
```

If neither `Student_ID -> Grade` nor `Course_ID -> Grade` is valid, then `Grade` depends fully on the composite key.

#### 4. Partial Functional Dependency

A **partial dependency** occurs when a non-prime attribute depends on only a part of a composite candidate key.

Example, in `ENROLLMENT(Student_ID, Course_ID, Student_Name, Grade)`:

```text
(Student_ID, Course_ID) -> Grade
Student_ID               -> Student_Name
```

The key is `(Student_ID, Course_ID)`, but `Student_Name` depends only on `Student_ID`. This is a partial dependency and violates 2NF.

#### 5. Transitive Functional Dependency

A **transitive dependency** occurs when an attribute depends on a key through another non-key attribute.

Example:

```text
Student_ID -> Department_ID
Department_ID -> Department_Name
Therefore, Student_ID -> Department_Name
```

The department name is indirectly determined by the student ID through the department ID. This type of dependency can cause redundancy and is addressed when designing relations for 3NF.

### Other Important Dependencies

#### 6. Multivalued Dependency (MVD)

A **multivalued dependency** `X ->> Y` exists when, for one value of X, multiple Y values are associated independently of the remaining attributes.

Example:

```text
Student ->> Hobby
Student ->> Language
```

A student may have several hobbies and several languages, and the two sets may be independent. MVDs are handled by 4NF.

#### 7. Join Dependency (JD)

A **join dependency** exists when a relation can be reconstructed exactly by joining multiple projections of that relation. It is written as `*(R1, R2, ..., Rn)`.

Example: a supplier-part-project relation may be decomposed into supplier-part, supplier-project, and part-project relations when the business rules guarantee that their join reconstructs the original relation. Join dependencies are addressed by 5NF.

### Summary of Dependencies

| Dependency | Meaning | Example | Related normal form |
|---|---|---|---|
| Trivial | Dependent attributes are part of the determinant | `(A, B) -> A` | FD property |
| Non-trivial | Dependent attributes are not contained in determinant | `A -> B` | FD property |
| Full | Depends on the complete composite determinant | `(Student_ID, Course_ID) -> Grade` | 2NF |
| Partial | Depends on only part of a composite key | `Student_ID -> Student_Name` | Removed in 2NF |
| Transitive | Depends through another attribute | `ID -> Dept_ID -> Dept_Name` | Addressed by 3NF |
| Multivalued | Independent set of values for a determinant | `Student ->> Hobby` | 4NF |
| Join | Relation reconstructed from multiple projections | `*(SP, SJ, PJ)` | 5NF |

### Importance of Functional Dependencies

1. FDs help identify candidate keys and determine the structure of relations.
2. They reveal partial and transitive dependencies that cause redundancy.
3. They guide decomposition into higher normal forms.
4. They help ensure that decomposed tables preserve the intended relationships among attributes.

## Q4. Third Normal Form (3NF) and Boyce-Codd Normal Form (BCNF)

> **Question:** Compare 3NF and BCNF with suitable examples.

---

### Third Normal Form (3NF)

A relation is in **Third Normal Form (3NF)** if:

1. It is in 2NF.
2. For every non-trivial functional dependency `X -> A`, at least one of the following is true:
   - X is a superkey, or
   - A is a prime attribute, meaning it belongs to at least one candidate key.

3NF removes transitive dependencies of non-prime attributes on candidate keys.

### Boyce-Codd Normal Form (BCNF)

A relation is in **Boyce-Codd Normal Form (BCNF)** if, for every non-trivial functional dependency `X -> Y`, X must be a **superkey**.

BCNF is stricter than 3NF because it does not provide the prime-attribute exception allowed by 3NF.

### Example: A Relation in 3NF but Not BCNF

Consider:

`CLASS(Student, Course, Instructor)`

Assume each instructor teaches only one course, while a student may study multiple courses. The functional dependencies are:

```text
(Student, Course) -> Instructor
Instructor         -> Course
```

The candidate keys are:

```text
(Student, Course)
(Student, Instructor)
```

All three attributes are prime because each belongs to at least one candidate key.

Consider the dependency:

```text
Instructor -> Course
```

`Instructor` is not a superkey because multiple students can have the same instructor. However, `Course` is a prime attribute. Therefore, this dependency satisfies the 3NF condition but violates the BCNF condition.

### Decomposition into BCNF

Decompose the relation into:

```text
INSTRUCTOR_COURSE(Instructor, Course)
STUDENT_INSTRUCTOR(Student, Instructor)
```

In `INSTRUCTOR_COURSE`, `Instructor` is the key. In `STUDENT_INSTRUCTOR`, the combination `(Student, Instructor)` identifies a row. This decomposition removes the BCNF violation caused by `Instructor -> Course`.

### Comparison Between 3NF and BCNF

| Parameter | 3NF | BCNF |
|---|---|---|
| Full form | Third Normal Form | Boyce-Codd Normal Form |
| Main condition | For each non-trivial FD, determinant is a superkey or dependent attribute is prime | For every non-trivial FD, determinant must be a superkey |
| Strictness | Less strict | Stricter than 3NF |
| Prime attribute exception | Allowed | Not allowed |
| Redundancy | Removes many, but not all FD-based redundancies | Removes more FD-based redundancy |
| Dependency preservation | A 3NF decomposition can be designed to preserve dependencies | BCNF decomposition may not preserve all dependencies |
| Relationship | Every BCNF relation is in 3NF | Not every 3NF relation is in BCNF |

### Conclusion

BCNF is stronger than 3NF because every determinant of a non-trivial functional dependency must be a superkey. 3NF is sometimes preferred when preserving all functional dependencies is important, while BCNF provides a stronger reduction of redundancy.

## Q5. Lossless Join and Dependency-Preserving Decomposition

> **Question:** Explain Lossless Join and Dependency Preserving Decomposition.

---

### Decomposition

**Decomposition** is the process of splitting a relation into two or more smaller relations to reduce redundancy and achieve normalization. A good decomposition should ideally satisfy two important properties: **lossless join** and **dependency preservation**.

### 1. Lossless Join Decomposition

A decomposition is **lossless** if joining the decomposed relations reconstructs exactly the original relation, without losing valid tuples or generating extra (spurious) tuples.

For a binary decomposition of relation R into R1 and R2, the decomposition is lossless with respect to a set of functional dependencies F if at least one of the following holds:

```text
(R1 ∩ R2) -> R1
or
(R1 ∩ R2) -> R2
```

In other words, the common attributes must functionally determine all attributes of at least one of the decomposed relations.

### Lossless Decomposition Example

Consider:

`EMPLOYEE(Emp_ID, Dept_ID, Dept_Name)`

with the functional dependencies:

```text
Emp_ID  -> Dept_ID
Dept_ID -> Dept_Name
```

Decompose it into:

```text
EMPLOYEE_DEPT(Emp_ID, Dept_ID)
DEPARTMENT(Dept_ID, Dept_Name)
```

The common attribute is `Dept_ID`. Since `Dept_ID -> Dept_Name`, the common attribute determines all attributes of `DEPARTMENT`. Therefore, the decomposition is lossless.

```text
EMPLOYEE(Emp_ID, Dept_ID, Dept_Name)
                  |
                  | Decompose
             +----+----+
             |         |
             v         v
+------------------+  +----------------------+
| EMPLOYEE_DEPT    |  | DEPARTMENT           |
| Emp_ID, Dept_ID  |  | Dept_ID, Dept_Name   |
+------------------+  +----------------------+
             \         /
              \ JOIN  /
               \     /
                v   v
       EMPLOYEE(Emp_ID, Dept_ID, Dept_Name)
```

### Lossy Decomposition Example

Consider a relation `R(A, B, C)` with these tuples:

| A | B | C |
|---|---|---|
| a1 | b1 | c1 |
| a1 | b2 | c2 |

Decompose it into `R1(A, B)` and `R2(A, C)`:

**R1(A, B)**

| A | B |
|---|---|
| a1 | b1 |
| a1 | b2 |

**R2(A, C)**

| A | C |
|---|---|
| a1 | c1 |
| a1 | c2 |

Joining on A produces four combinations, including `(a1, b1, c2)` and `(a1, b2, c1)`, which were not present in the original relation. These are **spurious tuples**, so the decomposition is lossy.

### 2. Dependency-Preserving Decomposition

A decomposition is **dependency preserving** if all the original functional dependencies can be enforced by checking the decomposed relations individually, without having to join them again.

If F is the original set of functional dependencies and F1, F2, ..., Fn are the dependencies projected onto the decomposed relations, the decomposition is dependency preserving when:

```text
(F1 union F2 union ... union Fn)+ = F+
```

Here, `+` represents the functional dependencies implied by a set of dependencies.

### Dependency-Preserving Example

Consider:

`R(A, B, C)` with:

```text
A -> B
B -> C
```

Decompose it into:

```text
R1(A, B)
R2(B, C)
```

The dependency `A -> B` can be checked in `R1`, and `B -> C` can be checked in `R2`. Therefore, both original dependencies are preserved without joining the relations.

### Lossless Join vs Dependency Preservation

| Parameter | Lossless Join | Dependency Preservation |
|---|---|---|
| Meaning | Original relation can be reconstructed exactly | Original dependencies can be checked in decomposed tables |
| Main purpose | Prevents information loss and spurious tuples | Preserves integrity constraints efficiently |
| Concern | Correctness of joining decomposed relations | Enforcement of functional dependencies |
| Test | Common attributes determine all attributes of at least one component in a binary decomposition | Union of projected dependencies implies all original dependencies |
| Requires a join? | Joining is used to reconstruct the original relation | Dependency checks should not require joining tables |
| Importance | Ensures data reconstruction is correct | Ensures constraints remain enforceable |

### Conclusion

A good decomposition should be both lossless and dependency preserving whenever possible. Lossless join protects the original information, while dependency preservation ensures that functional dependencies can still be enforced efficiently.

## Q6. Transaction Management and ACID Properties

> **Question:** Explain Transaction Management and ACID properties with examples.

---

### Definition of a Transaction

A **transaction** is a logical unit of work in a database that consists of one or more operations such as reading, inserting, updating, or deleting data. A transaction must be completed as a whole or rolled back if it fails.

For example, transferring ₹500 from Account A to Account B requires two updates: subtract ₹500 from A and add ₹500 to B. Both operations must succeed together.

### Transaction Management

**Transaction management** is the process of controlling transaction execution to maintain database correctness, consistency, and reliability. The transaction manager coordinates operations such as starting a transaction, committing successful work, and rolling back failed work.

A typical transaction follows this sequence:

```text
       BEGIN TRANSACTION
              |
              v
        Execute operations
              |
        +-----+------+
        |            |
      Success      Failure
        |            |
        v            v
      COMMIT      ROLLBACK
        |            |
        v            v
   Changes saved  Changes undone
```

### ACID Properties

ACID represents the four essential properties of reliable transaction processing.

#### 1. Atomicity

**Atomicity** means that all operations in a transaction are performed completely or none of them are performed. If one operation fails, the DBMS rolls back the changes already made by that transaction.

Example: In a bank transfer, if money is deducted from Account A but the credit to Account B fails, the deduction must be undone.

#### 2. Consistency

**Consistency** means that a transaction moves the database from one valid state to another while satisfying all defined constraints, rules, and integrity conditions.

Example: If the bank database requires an account balance to be non-negative, a transaction must not leave an account with an invalid negative balance.

#### 3. Isolation

**Isolation** means that concurrent transactions should not interfere in a way that produces an incorrect result. Each transaction should behave as though it is executing in an appropriate isolated order, according to the selected isolation level.

Example: While one transaction transfers money between two accounts, another transaction should not observe a partially completed transfer.

#### 4. Durability

**Durability** means that once a transaction has committed, its changes remain permanent even if a power failure or system crash occurs immediately afterward. The DBMS uses logs and other recovery mechanisms to maintain committed changes.

Example: After a bank transfer is committed, the updated balances must remain stored even if the database server restarts.

### Bank Transfer Example

Assume Account A has ₹2,000 and Account B has ₹1,000. Transfer ₹500 from A to B.

```sql
START TRANSACTION;

UPDATE Account
SET Balance = Balance - 500
WHERE Account_ID = 'A';

UPDATE Account
SET Balance = Balance + 500
WHERE Account_ID = 'B';

COMMIT;
```

After a successful transaction:

| Account | Before | After |
|---|---:|---:|
| A | ₹2,000 | ₹1,500 |
| B | ₹1,000 | ₹1,500 |
| Total | ₹3,000 | ₹3,000 |

If an operation fails before the transaction commits, the DBMS can execute `ROLLBACK` to undo the incomplete transfer. The exact transaction-control syntax can vary between database systems.

### ACID Summary

| Property | Meaning | Prevents or guarantees |
|---|---|---|
| Atomicity | All operations succeed or none do | Partial transactions |
| Consistency | Constraints remain satisfied | Invalid database states |
| Isolation | Concurrent transactions do not interfere improperly | Incorrect interference between transactions |
| Durability | Committed changes survive failures | Loss of committed data |

### Importance of Transaction Management

1. It protects data from incomplete or failed operations.
2. It helps maintain database consistency during concurrent access.
3. It supports recovery after transaction or system failures.
4. It ensures that committed changes are permanent.

## Q7. Transaction States

> **Question:** Explain Transaction States with a neat state transition diagram.

---

### Introduction

A transaction passes through different **transaction states** during its execution. These states describe whether the transaction is executing, has completed its operations, has committed successfully, or has failed and requires rollback.

### Transaction States

#### 1. Active State

A transaction is in the **active state** while it is executing its read and write operations. It remains active until its final statement has been executed or an error occurs.

#### 2. Partially Committed State

A transaction enters the **partially committed state** after executing its final statement but before the DBMS has guaranteed that the commit is safely recorded. A failure can still prevent the transaction from becoming committed.

#### 3. Committed State

A transaction enters the **committed state** after it has completed successfully and the DBMS has made its commit durable. Its changes are considered permanent.

#### 4. Failed State

A transaction enters the **failed state** when it cannot continue because of an error, system crash, deadlock victim selection, or another failure condition.

#### 5. Aborted State

A transaction enters the **aborted state** after the DBMS has rolled back its effects and restored the database to the state required before that transaction's changes.

After aborting, the transaction may be restarted or terminated.

#### 6. Terminated State

A transaction reaches the **terminated state** when it leaves the transaction system after committing or aborting. It releases the resources that it no longer needs.

### Transaction State Transition Diagram

```text
                   +------------------+
                   |      ACTIVE      |
                   +------------------+
                     |              |
       Last statement|              | Error / failure
                     v              v
          +------------------+  +------------------+
          | PARTIALLY        |  |      FAILED      |
          | COMMITTED        |  +------------------+
          +------------------+           |
              |       |                  | Rollback
              |       | Failure          v
              |       +---------->+------------------+
              |                  |      ABORTED     |
       Commit |                  +------------------+
              v                    |              |
      +------------------+         | Restart      | Stop
      |    COMMITTED     |         v              v
      +------------------+      ACTIVE      +------------------+
              |                             |   TERMINATED     |
              v                             +------------------+
      +------------------+
      |   TERMINATED     |
      +------------------+
```

A transaction may fail while active or partially committed. After rollback, it becomes aborted. A committed or aborted transaction eventually terminates. An aborted transaction may be restarted as a new execution if the system or application chooses to retry it.

### State Transitions Explained

| Transition | Explanation |
|---|---|
| Active → Partially Committed | The final operation of the transaction has executed |
| Active → Failed | An error or failure prevents further execution |
| Partially Committed → Committed | The commit is successfully recorded and made durable |
| Partially Committed → Failed | A failure occurs before commit is made durable |
| Failed → Aborted | The DBMS rolls back the transaction's effects |
| Aborted → Active | The transaction is restarted |
| Aborted → Terminated | The transaction is not restarted |
| Committed → Terminated | The completed transaction leaves the system |

### Example

Consider a transaction that transfers ₹500 from Account A to Account B:

1. It enters the **Active** state when it starts and performs the debit and credit operations.
2. After its final statement, it enters the **Partially Committed** state.
3. When the commit record is safely stored, it enters the **Committed** state.
4. If an error occurs before commit, it enters the **Failed** state instead. After rollback, it becomes **Aborted**.
5. It is then restarted or moved to the **Terminated** state.

### Importance of Transaction States

1. They help the DBMS track the progress of each transaction.
2. They distinguish successful completion from incomplete or failed execution.
3. They help recovery mechanisms identify transactions that must be undone or retained.
4. They support correct transaction scheduling and resource management.

## Q8. Concurrent Execution and Serializability

> **Question:** Explain Concurrent Execution and Serializability with examples.

---

### Concurrent Execution

**Concurrent execution** means that operations from multiple transactions are performed in an interleaved order. The DBMS allows transactions to make progress during overlapping time periods instead of completing one transaction before starting another.

For example, while one transaction reads an account balance, another transaction may perform an update on a different account. Concurrency improves system utilization and response time, but it must be controlled to prevent incorrect results.

### Serial Schedule

A **serial schedule** executes one transaction completely before the next transaction begins. There is no interleaving of operations.

For transactions T1 and T2:

```text
Serial Schedule:
T1: R(A) -> W(A) -> COMMIT
T2:                         R(B) -> W(B) -> COMMIT
```

All operations of T1 occur before operations of T2.

### Non-Serial Schedule

A **non-serial schedule** interleaves the operations of multiple transactions.

```text
Non-Serial Schedule:
T1: R(A) -------- W(A) -------- COMMIT
T2:       R(B) -------- W(B) -------- COMMIT
```

This can improve resource utilization. However, an arbitrary non-serial schedule may produce incorrect or inconsistent results.

### Problems Caused by Uncontrolled Concurrency

1. **Lost update:** Two transactions update the same data item, and one update overwrites the other.
2. **Dirty read:** A transaction reads a value written by another transaction that has not yet committed. If the writer rolls back, the reader has used an invalid value.
3. **Unrepeatable read:** A transaction reads the same row twice and gets different values because another committed transaction modified it between the reads.
4. **Incorrect summary:** An aggregate operation reads some values before another transaction updates them and other values after the update, producing an inconsistent result.

### Serializability

**Serializability** is the correctness criterion used to determine whether a concurrent schedule produces a result equivalent to some serial execution of the same transactions.

A schedule is **serializable** if its effect on the database is equivalent to the effect of a serial schedule. Serializability allows concurrency without sacrificing the correctness of transaction execution.

The two main forms are:

1. **Conflict serializability:** Based on the order of conflicting operations.
2. **View serializability:** Based on the reads-from relationships and final writes of transactions.

### Example of a Serializable Concurrent Schedule

Consider two transactions:

```text
T1: R(A), W(A)
T2: R(A), W(A)
```

A concurrent schedule is:

```text
S: R1(A), W1(A), R2(A), W2(A)
```

The conflicting operations on A occur with T1 before T2. The schedule is equivalent to the serial order `T1 -> T2`, so it is serializable.

### Example of a Non-Serializable Schedule

Consider:

```text
S: R1(A), W1(A), R2(A), W2(A), R2(B), W2(B), R1(B), W1(B)
```

For data item A, T1's write occurs before T2's read and write, giving the precedence edge `T1 -> T2`. For data item B, T2's write occurs before T1's read and write, giving `T2 -> T1`.

The precedence graph contains a cycle:

```text
       +------+
       |  T1  | -----> +------+
       +------+       |  T2  |
          ^           +------+
          |              |
          +--------------+
```

Because the graph is cyclic, the schedule is not conflict serializable. In this example, the transactions perform incompatible interleavings on A and B.

### Advantages of Concurrent Execution

1. It improves CPU and I/O resource utilization.
2. It allows multiple users to access the database at the same time.
3. It can increase transaction throughput.
4. It reduces waiting time when one transaction is waiting for input/output.

### Role of Serializability

Serializability provides a formal way to check whether concurrent execution preserves the correctness of a serial execution. DBMS concurrency-control methods such as locking and timestamp ordering are used to produce safe schedules.

## Q9. Conflict Serializability and View Serializability

> **Question:** Discuss conflict serializability and view serializability with suitable examples.

---

### Introduction

**Serializability** checks whether a concurrent schedule is equivalent to a serial schedule. Two important types are **conflict serializability** and **view serializability**. Both are used to reason about the correctness of concurrent transaction schedules, but they use different equivalence conditions.

### Conflicting Operations

Two operations conflict when all three conditions are satisfied:

1. They belong to different transactions.
2. They operate on the same data item.
3. At least one of the operations is a write.

The conflicting pairs are:

| Operation 1 | Operation 2 | Conflict? |
|---|---|---|
| Read(A) | Read(A) | No |
| Read(A) | Write(A) | Yes |
| Write(A) | Read(A) | Yes |
| Write(A) | Write(A) | Yes |
| Read(A) | Write(B) | No, different data items |

### 1. Conflict Serializability

A schedule is **conflict serializable** if it is conflict equivalent to a serial schedule. Two schedules are conflict equivalent when the relative order of every pair of conflicting operations is the same in both schedules.

#### Precedence Graph Method

A **precedence graph** (or serialization graph) is used to test conflict serializability.

Steps:

1. Create one node for each transaction.
2. For every pair of conflicting operations belonging to different transactions, add a directed edge from the transaction whose operation occurs first to the transaction whose operation occurs later.
3. Check the graph for cycles.
4. If the graph is acyclic, the schedule is conflict serializable. A topological ordering of the graph gives an equivalent serial order.
5. If the graph contains a cycle, the schedule is not conflict serializable.

#### Example: Conflict-Serializable Schedule

```text
S: R1(A), W1(A), R2(A), W2(A)
```

The write `W1(A)` occurs before `R2(A)` and `W2(A)`. The graph contains the edge `T1 -> T2`.

```text
+------+       +------+
|  T1  | ----> |  T2  |
+------+       +------+
```

There is no cycle. Therefore, the schedule is conflict serializable and is equivalent to the serial order `T1 -> T2`.

#### Example: Not Conflict Serializable

```text
S: R1(A), W1(A), R2(A), W2(A),
   R2(B), W2(B), R1(B), W1(B)
```

The conflicts on A create `T1 -> T2`. The conflicts on B create `T2 -> T1`. The graph has a cycle, so the schedule is not conflict serializable.

### 2. View Serializability

A schedule is **view serializable** if it is view equivalent to some serial schedule. Two schedules are view equivalent when they preserve all three conditions:

1. **Initial read:** If a transaction reads the initial value of a data item in one schedule, it must also read the initial value in the other schedule.
2. **Reads-from relationship:** If a transaction reads a value written by another transaction, it must read the value written by the same transaction in the other schedule.
3. **Final write:** The transaction that performs the final write on each data item must be the same in both schedules.

#### Example: View Serializable but Not Conflict Serializable

Consider the schedule:

```text
S: W1(A), W2(A), W1(A)
```

All three operations are writes. There are no read operations, so the initial-read and reads-from conditions are not applicable. The final write on A is performed by T1.

This schedule is view equivalent to the serial schedule:

```text
T2 -> T1
```

The final write on A is still performed by T1. Therefore, the schedule is view serializable.

However, the conflicting writes produce these precedence edges:

```text
W1(A) before W2(A)  => T1 -> T2
W2(A) before W1(A)  => T2 -> T1
```

The graph contains a cycle, so the schedule is not conflict serializable. This example is possible because the transactions perform **blind writes**, meaning they write a data item without first reading it.

### Comparison Between Conflict and View Serializability

| Parameter | Conflict Serializability | View Serializability |
|---|---|---|
| Basis | Order of conflicting operations | Initial reads, reads-from relationships, and final writes |
| Equivalence | Conflict equivalence | View equivalence |
| Test method | Precedence graph | Check view-equivalence conditions against a serial schedule |
| Cycle test | Acyclic graph means conflict serializable | A cycle in a conflict graph does not by itself rule out view serializability |
| Blind writes | Some view-serializable schedules with blind writes are rejected | Can accept certain schedules containing blind writes |
| Complexity | Easier to test | More difficult to test in general |
| Relationship | Every conflict-serializable schedule is view serializable | A view-serializable schedule need not be conflict serializable |

### Relationship Between the Two

```text
Conflict Serializable  is a subset of  View Serializable
```

Every conflict-serializable schedule is view serializable, but the reverse is not always true. The blind-write example demonstrates a schedule that is view serializable but not conflict serializable.

## Q10. Recoverability and Recovery Algorithms

> **Question:** Explain Recoverability and Recovery Algorithms in DBMS.

---

### Recoverability

**Recoverability** is a property of a transaction schedule that ensures committed transactions do not depend on values written by transactions that later abort. It protects the database from retaining results that were based on invalid or uncommitted data.

Suppose transaction T1 writes a value of A, and transaction T2 reads that value. If T1 later aborts, T2 has read data that is no longer valid. The order in which these transactions commit determines whether the schedule is recoverable.

### Recoverable Schedule

A schedule is **recoverable** if, whenever transaction Tj reads a value written by transaction Ti, Tj commits only after Ti has committed.

Example:

```text
T1: W(A) -------- COMMIT
T2:       R(A) -------- COMMIT
```

T2 reads the value written by T1 and commits only after T1 commits. Therefore, the schedule is recoverable.

### Unrecoverable Schedule

A schedule is **unrecoverable** if a transaction commits after reading an uncommitted value written by another transaction, and the writer later aborts.

Example:

```text
T1: W(A) -------- ABORT
T2:       R(A) ---- COMMIT
```

T2 commits using a value written by T1 before T1 commits. When T1 aborts, T2 has already committed based on invalid data. This schedule is unrecoverable.

### Cascading Rollback

A **cascading rollback** occurs when the failure of one transaction forces other transactions to roll back because they read values written by the failed transaction.

Example:

```text
T1: W(A) -------- ABORT
T2:       R(A) -------- ABORT
T3:             R(A) -------- ABORT
```

If T2 and T3 depend on the uncommitted value written by T1, aborting T1 may force T2 and T3 to abort as well.

### Cascadeless Schedule

A schedule is **cascadeless** if a transaction reads a data item only after the transaction that last wrote that item has committed. This prevents dirty reads and avoids cascading rollbacks.

Example:

```text
T1: W(A) ---- COMMIT
T2:                  R(A) ---- COMMIT
```

T2 reads A only after T1 commits.

### Strict Schedule

A schedule is **strict** if, after a transaction writes a data item, no other transaction can read or write that item until the writing transaction commits or aborts. Strict schedules prevent dirty reads and dirty writes, making recovery simpler.

### Relationship Between Schedule Types

```text
Strict  =>  Cascadeless  =>  Recoverable
```

Every strict schedule is cascadeless, and every cascadeless schedule is recoverable. The reverse implications are not guaranteed.

### Recovery Algorithms in DBMS

A **recovery algorithm** restores the database to a correct state after transaction failures, system crashes, or other interruptions. It uses information such as transaction logs, checkpoints, and copies of database pages.

#### 1. Log-Based Recovery

A **log** is a record of transaction activities maintained by the DBMS. A log entry may record the transaction ID, data item, old value, and new value.

Example log records:

```text
<START T1>
<T1, A, 1000, 800>
<T1, B, 500, 700>
<COMMIT T1>
```

The records show that T1 changed A from 1000 to 800 and B from 500 to 700 before committing.

**Write-Ahead Logging (WAL):** The log record describing a change must be written to stable storage before the corresponding changed database page is written to disk. This ensures that the DBMS has enough information to recover from a crash.

Two common log-based approaches are:

- **Deferred database modification:** Database changes are postponed until the transaction commits. After a crash, the DBMS can redo committed transactions; uncommitted changes have not been applied to the database pages.
- **Immediate database modification:** Database pages may be updated before a transaction commits. The log stores the old and new values, allowing the DBMS to undo uncommitted transactions and redo committed transactions when necessary.

#### 2. Checkpoint-Based Recovery

A **checkpoint** is a recovery marker created periodically by the DBMS. It records a known recovery position and may ensure that relevant log records and modified pages are safely handled.

During recovery, the DBMS can use the most recent suitable checkpoint to reduce how much of the log it must examine. It then performs the necessary undo and redo operations for transactions around that checkpoint.

```text
Log timeline:
START T1 ---- UPDATE T1 ---- CHECKPOINT ---- START T2 ---- COMMIT T2 ---- CRASH
                                ^
                       Recovery reference point
```

A checkpoint reduces recovery work, but it does not replace logging.

#### 3. Shadow Paging

**Shadow paging** is a recovery technique that maintains two page tables:

- The **shadow page table** points to the database pages representing the last committed state.
- The **current page table** points to pages being modified by the active transaction.

Updates are written to new pages rather than overwriting the original pages. On commit, the DBMS atomically switches the database pointer to the current page table. If a failure occurs before commit, the shadow page table remains available and the incomplete updates can be discarded.

```text
Before commit:
+-------------------+       +-------------------+
| Shadow Page Table |       | Current Page Table|
| Previous state    |       | Modified state    |
+-------------------+       +-------------------+
          |                           |
          v                           v
   Original pages               New pages

Commit: switch the database pointer to Current Page Table.
Failure before commit: retain Shadow Page Table.
```

### Undo and Redo Operations

- **UNDO** reverses the effects of an uncommitted transaction using the old values stored in the log.
- **REDO** reapplies the effects of a committed transaction using the new values stored in the log, when those changes are not yet reflected on disk.

Example:

```text
Log: <T1, A, old_value=100, new_value=150>

UNDO T1  -> restore A to 100
REDO T1  -> set A to 150
```

### Comparison of Recovery Techniques

| Technique | Main idea | Recovery action | Main advantage |
|---|---|---|---|
| Deferred log-based recovery | Apply database updates after commit | Redo committed transactions if needed | Uncommitted updates are not written to database pages |
| Immediate log-based recovery | Pages may be updated before commit; log stores old and new values | Undo uncommitted and redo committed transactions as required | Supports flexible buffer management |
| Checkpointing | Periodically records a recovery position | Start recovery from a suitable checkpoint and process later log records | Reduces recovery time |
| Shadow paging | Maintain shadow and current page tables | Keep shadow table on failure; switch to current table on commit | Does not require undo/redo logging for page updates in the basic method |

### Importance of Recovery

1. It protects committed data from being lost after failures.
2. It removes incomplete effects of transactions that did not commit.
3. It restores database consistency after system crashes.
4. It reduces downtime and supports reliable transaction processing.
