# UNIT 4 — Normalization, Functional Dependencies, Transactions, Serializability & Recovery

---

## 1. Explain the purpose of Normalization and discuss 1NF, 2NF with suitable examples.

### 1. Purpose of Normalization
**Normalization** is the systematic process of organizing data in a relational database (by decomposing large, poorly structured tables into smaller, well-structured related tables) to **minimize data redundancy** and **eliminate data modification anomalies** (Insertion, Deletion, and Update anomalies).

#### Main Objectives / Advantages of Normalization
1. **Eliminate Duplicate Data:** Reduces storage overhead by storing each fact only once.
2. **Prevent Update, Insertion, and Deletion Anomalies:**
   - *Insertion Anomaly:* Inability to insert a new fact without having data for another unrelated entity.
   - *Deletion Anomaly:* Deleting a record unintentionally erases vital information about another entity.
   - *Update Anomaly:* Updating a repeated value in one row but forgetting to update all duplicate copies, leading to inconsistency.
3. **Improve Data Consistency & Integrity:** Ensures accurate and reliable query results.
4. **Simplify Database Maintenance:** Makes the schema cleaner and easier to evolve.

---

### 2. First Normal Form (1NF)
- **Definition:** A relation (table) is in **First Normal Form (1NF)** if and only if:
  1. Every attribute contains only **atomic (indivisible, single) values**.
  2. There are **no repeating groups** or multi-valued attributes in any cell.
  3. Each record (row) is uniquely identifiable.

#### Worked Example of 1NF
Consider a `Student` table where the `Subjects` column stores multiple comma-separated values in a single cell (**Not in 1NF**):

**`Student` Table (Unnormalized — Violates 1NF):**

| `RollNo` | `Name` | `Dept` | `Subjects` (Multi-Valued) |
| :---: | :--- | :---: | :--- |
| `101` | Ravi | CSE | `DS, DBMS` |
| `102` | Sita | ECE | `OS, CN` |
| `103` | Hari | ME | `FEA, CAD` |

**Conversion to 1NF:** Split the multi-valued `Subjects` attribute into separate atomic rows so every cell holds a single value:

**`Student_1NF` Table (In 1NF):**

| `RollNo` | `Name` | `Dept` | `Subject` (Atomic) |
| :---: | :--- | :---: | :---: |
| `101` | Ravi | CSE | `DS` |
| `101` | Ravi | CSE | `DBMS` |
| `102` | Sita | ECE | `OS` |
| `102` | Sita | ECE | `CN` |
| `103` | Hari | ME | `FEA` |
| `103` | Hari | ME | `CAD` |

---

### 3. Second Normal Form (2NF)
- **Definition:** A relation is in **Second Normal Form (2NF)** if and only if:
  1. It is already in **1NF**, and
  2. **No non-prime (non-key) attribute is partially dependent** on any proper subset of a composite candidate key.
- In other words, every non-key attribute must be **fully functionally dependent** on the **entire** primary key.

#### Worked Example 1 (`STUDENT_COURSE` Relation)
Consider the relation:
$$\text{STUDENT\_COURSE}(\underline{\text{Student\_ID}}, \underline{\text{Course\_ID}}, \text{Student\_Name}, \text{Course\_Name}, \text{Marks})$$
- **Composite Primary Key:** $(\text{Student\_ID}, \text{Course\_ID})$
- **Functional Dependencies:**
  - $(\text{Student\_ID}, \text{Course\_ID}) \rightarrow \text{Marks}$ *(Full functional dependency)*
  - $\text{Student\_ID} \rightarrow \text{Student\_Name}$ *(**Partial Dependency** — depends only on part of the key!)*
  - $\text{Course\_ID} \rightarrow \text{Course\_Name}$ *(**Partial Dependency** — depends only on part of the key!)*
- Because partial dependencies exist, `STUDENT_COURSE` is **not in 2NF**.
- **Conversion to 2NF:** Decompose into three relations to remove all partial dependencies:
  1. $\text{STUDENT}(\underline{\text{Student\_ID}}, \text{Student\_Name})$
  2. $\text{COURSE}(\underline{\text{Course\_ID}}, \text{Course\_Name})$
  3. $\text{STUDENT\_COURSE}(\underline{\text{Student\_ID}}, \underline{\text{Course\_ID}}, \text{Marks})$

#### Worked Example 2 (`Orders` Table with Data)
Consider an `Orders` table with composite key $(\text{OrderID}, \text{ProductID})$:

**`Orders` (Not in 2NF):**

| `OrderID` (PK) | `ProductID` (PK) | `ProductName` | `UnitPrice` | `Quantity` | `Total` |
| :---: | :---: | :--- | :---: | :---: | :---: |
| `O001` | `P01` | Laptop | `50000` | `2` | `100000` |
| `O001` | `P02` | Mouse | `500` | `1` | `500` |
| `O002` | `P03` | Keyboard | `1500` | `1` | `1500` |

- Here, `ProductName` and `UnitPrice` depend **only on `ProductID`**, not on the whole key $(\text{OrderID}, \text{ProductID})$.
- **Conversion to 2NF:** Split into two tables:

**1. `Orders_2NF` Table:**

| `OrderID` (PK) | `ProductID` (PK/FK) | `Quantity` | `Total` |
| :---: | :---: | :---: | :---: |
| `O001` | `P01` | `2` | `100000` |
| `O001` | `P02` | `1` | `500` |
| `O002` | `P03` | `1` | `1500` |

**2. `Product_2NF` Table:**

| `ProductID` (PK) | `ProductName` | `UnitPrice` |
| :---: | :--- | :---: |
| `P01` | Laptop | `50000` |
| `P02` | Mouse | `500` |
| `P03` | Keyboard | `1500` |

**Conclusion:** Normalization systematically refines database tables: **1NF** eliminates repeating groups and ensures atomic values, while **2NF** eliminates partial dependencies on composite keys.

---

## 2. Explain 4NF, and 5NF with suitable examples.

### Introduction
**Fourth Normal Form (4NF)** and **Fifth Normal Form (5NF / Project-Join Normal Form)** are advanced levels of database normalization designed to eliminate redundancy caused by **Multi-Valued Dependencies (MVDs)** and **Join Dependencies (JDs)** respectively.

---

### 1. Fourth Normal Form (4NF)
- **Definition:** A relation $R$ is in **4NF** if and only if:
  1. It is already in **BCNF** (and 3NF), and
  2. It contains **no non-trivial Multi-Valued Dependencies (MVDs)**.
- **What is a Multi-Valued Dependency ($X \twoheadrightarrow Y$)?**
  - A multi-valued dependency $X \twoheadrightarrow Y$ occurs when a single key $X$ determines **two or more independent multi-valued attributes** $Y$ and $Z$ in the same table, forcing the table to store every Cartesian combination of $Y$ and $Z$ values.
- **Purpose of 4NF:**
  - Removes independent multi-valued facts from the same relation.
  - Prevents combinatorial tuple explosion and update anomalies.

#### Worked Example of 4NF (`STUDENT_SKILL_HOBBY`)
Consider a relation `STUDENT_SKILL_HOBBY(Student_ID, Skill, Hobby)` where a student can have multiple **skills** and multiple **hobbies**, and a student's skills are completely **independent** of their hobbies ($\text{Student\_ID} \twoheadrightarrow \text{Skill}$ and $\text{Student\_ID} \twoheadrightarrow \text{Hobby}$):

**`STUDENT_SKILL_HOBBY` (Not in 4NF — Contains MVDs):**

| `Student_ID` | `StudentName` | `Skill` | `Hobby` |
| :---: | :--- | :--- | :--- |
| `101` | Ravi | Python | Cricket |
| `101` | Ravi | Python | Music |
| `101` | Ravi | Java | Cricket |
| `101` | Ravi | Java | Music |
| `102` | Sita | C++ | Reading |

- Notice that because `Skill` and `Hobby` are independent multi-valued attributes of `Student_ID`, every skill of `101` must be paired with every hobby of `101`, causing massive redundancy.
- **Decomposition into 4NF:** Separate the independent multi-valued attributes into distinct tables:

**1. `STUDENT_SKILL` (In 4NF):**

| `Student_ID` | `Skill` |
| :---: | :--- |
| `101` | Python |
| `101` | Java |
| `102` | C++ |

**2. `STUDENT_HOBBY` (In 4NF):**

| `Student_ID` | `Hobby` |
| :---: | :--- |
| `101` | Cricket |
| `101` | Music |
| `102` | Reading |

*(And `STUDENT(Student_ID, StudentName)` if `StudentName` is included.)* Now all non-trivial MVDs are eliminated, and the relations are in **4NF**.

---

### 2. Fifth Normal Form (5NF / Project-Join Normal Form — PJNF)
- **Definition:** A relation $R$ is in **5NF** if and only if:
  1. It is already in **4NF**, and
  2. It has **no non-trivial Join Dependencies (JDs)** that are not implied by the candidate keys of $R$.
- **What is a Join Dependency?**
  - A relation $R$ has a join dependency $*(R_1, R_2, \dots, R_n)$ if $R$ cannot be lossless-decomposed into two tables without spurious tuples, **but can be reconstructed losslessly by joining three or more smaller projections** $R_1 \bowtie R_2 \bowtie \dots \bowtie R_n$.
- **Purpose of 5NF:**
  - Removes redundancy caused by 3-way (cyclic) many-to-many-to-many relationships.
  - Ensures a table cannot be decomposed any further without losing information.

#### Worked Example 1 (`SUPPLIER_PART_PROJECT`)
Consider the ternary relation:
$$\text{SUPPLIER\_PART\_PROJECT}(\text{Supplier}, \text{Part}, \text{Project})$$
Suppose a business constraint states that if Supplier $S$ supplies Part $P$, Supplier $S$ supplies to Project $J$, and Project $J$ uses Part $P$, then $S$ necessarily supplies $P$ to $J$.
- **Decomposition into 5NF:** We decompose into three binary relations:
  1. $\text{SUPPLIER\_PART}(\underline{\text{Supplier}}, \underline{\text{Part}})$
  2. $\text{SUPPLIER\_PROJECT}(\underline{\text{Supplier}}, \underline{\text{Project}})$
  3. $\text{PART\_PROJECT}(\underline{\text{Part}}, \underline{\text{Project}})$
- Joining all three relations $\text{SUPPLIER\_PART} \bowtie \text{SUPPLIER\_PROJECT} \bowtie \text{PART\_PROJECT}$ reconstructs the original relation exactly without spurious tuples.

#### Worked Example 2 (`Project_Employee` Table)
**`Project_Employee` (Not in 5NF):**

| `ProjectID` | `ProjectName` | `EmpID` | `EmpName` |
| :---: | :--- | :---: | :--- |
| `P1` | Website | `E1` | Ravi |
| `P1` | Website | `E2` | Sita |
| `P2` | Mobile | `E2` | Sita |
| `P2` | Mobile | `E3` | Hari |

- **Decomposition into 5NF (Three Tables):**
  1. **`Project` (`ProjectID`, `ProjectName`):** `(P1, Website)`, `(P2, Mobile)`
  2. **`Employee` (`EmpID`, `EmpName`):** `(E1, Ravi)`, `(E2, Sita)`, `(E3, Hari)`
  3. **`Project_Emp_Map` (`ProjectID`, `EmpID`):** `(P1, E1)`, `(P1, E2)`, `(P2, E2)`, `(P2, E3)`

**Conclusion:** **4NF** eliminates redundancy caused by independent multi-valued dependencies (MVDs), while **5NF** eliminates redundancy caused by join dependencies (JDs), representing the highest practical normal forms in relational database design.

---

## 3. Explain Functional Dependency and different types of dependencies with examples.

### 1. Functional Dependency (FD)
- **Definition:** A **Functional Dependency (FD)** is a constraint between two sets of attributes $X$ and $Y$ in a relation $R$. We say that attribute set $Y$ is **functionally dependent** on attribute set $X$ — denoted as:
  $$X \rightarrow Y$$
  if and only if **each value of $X$ in $R$ is associated with policies/exactly one value of $Y$**.
- **Terminology:**
  - $X$ (left-hand side) is called the **Determinant**.
  - $Y$ (right-hand side) is called the **Dependent**.
- **Formal Rule:** For any two tuples $t_1, t_2 \in R$, if $t_1[X] = t_2[X]$, then it must hold that $t_1[Y] = t_2[Y]$.

#### Example of Functional Dependency
Consider relation `STUDENT(Roll_No, Name, Dept_ID, Dept_Name)`:

| `Roll_No` | `Name` | `Dept_ID` | `Dept_Name` |
| :---: | :--- | :---: | :---: |
| `101` | Ravi | `D1` | CSE |
| `102` | Sita | `D2` | ECE |
| `103` | Hari | `D3` | ME |

- $\text{Roll\_No} \rightarrow \text{Name}, \text{Dept\_ID}$ *(Each roll number uniquely determines one student name and department ID.)*
- $\text{Dept\_ID} \rightarrow \text{Dept\_Name}$ *(Each department ID uniquely determines one department name.)*

---

### 2. Types of Functional Dependencies

#### (1) Trivial Functional Dependency
- **Definition:** A functional dependency $X \rightarrow Y$ is called **trivial** if $Y$ is a subset of $X$ ($Y \subseteq X$). It always holds in every relation and provides no new constraint.
- **Examples:**
  - $\{\text{Roll\_No}, \text{Name}\} \rightarrow \text{Name}$
  - $\{\text{A}, \text{B}\} \rightarrow \text{A}$

#### (2) Non-Trivial Functional Dependency
- **Definition:** A functional dependency $X \rightarrow Y$ is called **non-trivial** if $Y$ is **not** a subset of $X$ ($Y \not\subseteq X$).
- **Examples:**
  - $\text{Roll\_No} \rightarrow \text{Name}$
  - $\{\text{Roll\_No}, \text{Name}\} \rightarrow \{\text{Name}, \text{Dept\_ID}\}$ *(Semi-trivial, since `Dept_ID` is not in the determinant)*

#### (3) Completely Non-Trivial Functional Dependency
- **Definition:** A functional dependency $X \rightarrow Y$ is **completely non-trivial** if $X$ and $Y$ have **no attributes in common** ($X \cap Y = \emptyset$).
- **Example:** $\text{Roll\_No} \rightarrow \text{Dept\_ID}$

#### (4) Full (Complete) Functional Dependency
- **Definition:** A functional dependency $X \rightarrow Y$ is a **full functional dependency** if $Y$ depends on the **entire composite set $X$** and does **not** depend on any proper subset $X' \subset X$.
- **Example:** In $\text{ENROLL}(\underline{\text{Student\_ID}}, \underline{\text{Course\_ID}}, \text{Marks})$:
  - $(\text{Student\_ID}, \text{Course\_ID}) \rightarrow \text{Marks}$ is a **full FD** because neither $\text{Student\_ID} \rightarrow \text{Marks}$ nor $\text{Course\_ID} \rightarrow \text{Marks}$ holds alone.

#### (5) Partial Functional Dependency
- **Definition:** A functional dependency $X \rightarrow Y$ is a **partial dependency** if a non-prime attribute $Y$ is functionally determined by a **proper subset** of a composite candidate key $X$. *(Eliminated in 2NF.)*
- **Example:** In $\text{ENROLL}(\underline{\text{Student\_ID}}, \underline{\text{Course\_ID}}, \text{Student\_Name}, \text{Course\_Name})$:
  - $\text{Student\_ID} \rightarrow \text{Student\_Name}$ and $\text{Course\_ID} \rightarrow \text{Course\_Name}$ are **partial dependencies**.

#### (6) Transitive Functional Dependency
- **Definition:** Given three attributes (or attribute sets) $X, Y, Z$ where $Y$ is a non-prime attribute (and $Y \nrightarrow X$), if $X \rightarrow Y$ and $Y \rightarrow Z$, then $X \rightarrow Z$ holds indirectly through $Y$ and is called a **transitive dependency**. *(Eliminated in 3NF.)*
- **Example:** In `STUDENT(Roll_No, Name, Dept_ID, Dept_Name)`:
  - $\text{Roll\_No} \rightarrow \text{Dept\_ID}$ and $\text{Dept\_ID} \rightarrow \text{Dept\_Name} \implies \text{Roll\_No} \rightarrow \text{Dept\_Name}$ is a **transitive dependency**.

---

### 3. Other Higher-Order Dependencies in Relational Databases

#### (7) Multivalued Dependency (MVD) ($X \twoheadrightarrow Y$)
- **Definition:** Occurs when one attribute $X$ determines a set of multiple independent values of attribute $Y$, independent of another multi-valued attribute $Z$ in the same relation. *(Eliminated in 4NF.)*
- **Example:** $\text{Student\_ID} \twoheadrightarrow \text{Skill}$ and $\text{Student\_ID} \twoheadrightarrow \text{Hobby}$.

#### (8) Join Dependency (JD) ($*(R_1, R_2, \dots, R_n)$)
- **Definition:** Holds on a relation $R$ if $R$ can be losslessly reconstructed by taking the natural join of its projections $R_1, R_2, \dots, R_n$: $R = R_1 \bowtie R_2 \bowtie \dots \bowtie R_n$. *(Eliminated in 5NF.)*
- **Example:** $R(\text{Supplier}, \text{Part}, \text{Project})$ decomposed into $R_1(\text{Supplier}, \text{Part})$, $R_2(\text{Supplier}, \text{Project})$, and $R_3(\text{Part}, \text{Project})$.

### Importance of Functional Dependencies
1. **Identifies Keys:** Used via attribute closure ($X^+$) to find Super Keys, Candidate Keys, and Primary Keys.
2. **Drives Normalization:** Forms the formal basis for 2NF, 3NF, and BCNF decomposition rules.
3. **Eliminates Redundancy:** Helps detect and remove partial and transitive dependencies.

**Conclusion:** Functional dependencies and higher-order dependencies (MVD, JD) provide the mathematical foundation for schema analysis, key identification, and lossless normalization.

---

## 4. Compare 3NF and BCNF with suitable examples.

### 1. Introduction
**Third Normal Form (3NF)** and **Boyce–Codd Normal Form (BCNF / 3.5NF)** are normalization levels used to remove redundancy and anomalies caused by functional dependencies. **BCNF is a stricter, stronger version of 3NF.**

---

### 2. Third Normal Form (3NF)
- **Definition:** A relation $R$ is in **3NF** if:
  1. It is already in **2NF**, and
  2. **No non-prime (non-key) attribute is transitively dependent** on any candidate key.
- **Formal Rule:** For every non-trivial functional dependency $X \rightarrow A$ in $R$, **at least one** of the following must hold:
  1. $X$ is a **Super Key** of $R$, **OR**
  2. $A$ is a **Prime Attribute** (i.e., $A$ is part of some candidate key of $R$).

#### Worked Example of Converting to 3NF
Consider `Student(StudentID, StudentName, DeptID, DepartmentName)`:
- **Primary Key:** `StudentID`
- **FDs:** $\text{StudentID} \rightarrow \text{StudentName}, \text{DeptID}$ and $\text{DeptID} \rightarrow \text{DepartmentName}$ (Transitive dependency!).

**`Student` (In 2NF, Not in 3NF):**

| `StudentID` (PK) | `StudentName` | `DeptID` | `DepartmentName` |
| :---: | :--- | :---: | :---: |
| `101` | Ravi | `D1` | CSE |
| `102` | Sita | `D2` | ECE |
| `103` | Hari | `D3` | ME |

**3NF Decomposition:** Split into two relations to remove the transitive dependency:
1. **`Student_3NF` (`<u>StudentID</u>`, `StudentName`, `DeptID`)**
2. **`Department_3NF` (`<u>DeptID</u>`, `DepartmentName`)**

---

### 3. Boyce–Codd Normal Form (BCNF)
- **Definition:** A relation $R$ is in **BCNF** if and only if for **every non-trivial functional dependency $X \rightarrow A$**, the determinant **$X$ is a Super Key** of $R$.
- Notice that BCNF drops the second exception of 3NF ("or $A$ is a prime attribute"). Even if $A$ is a prime attribute, its determinant $X$ **must still be a super key**.

#### Worked Example 1: Relation in 3NF but NOT in BCNF (`R(Student, Course, Instructor)`)
Consider a relation $R(\text{Student}, \text{Course}, \text{Instructor})$ with the following rules:
1. Each `(Student, Course)` pair has a single `Instructor`:
   $$(\text{Student}, \text{Course}) \rightarrow \text{Instructor}$$
2. Each `Instructor` teaches only one `Course`:
   $$\text{Instructor} \rightarrow \text{Course}$$

- **Candidate Key:** $(\text{Student}, \text{Course})$ (or $(\text{Student}, \text{Instructor})$).
- **Prime Attributes:** `Student`, `Course`.
- **Why it is in 3NF:** In $\text{Instructor} \rightarrow \text{Course}$, the RHS (`Course`) is a **prime attribute** (part of the candidate key $(\text{Student}, \text{Course})$). Thus 3NF allows it!
- **Why it violates BCNF:** In $\text{Instructor} \rightarrow \text{Course}$, the determinant **`Instructor` is NOT a super key**!

| `Student` | `Course` | `Instructor` |
| :--- | :---: | :--- |
| Ratan | DBMS | Rao |
| Vivek | DBMS | Rao |
| Lochan | Python | Kumar |

- **BCNF Decomposition:** Decompose $R$ using $\text{Instructor} \rightarrow \text{Course}$ into two BCNF relations:
  1. $\text{INSTRUCTOR\_COURSE}(\underline{\text{Instructor}}, \text{Course})$
  2. $\text{STUDENT\_INSTRUCTOR}(\underline{\text{Student}}, \underline{\text{Instructor}})$

#### Worked Example 2 (`Course` Table)
Consider `Course(CourseID, CourseName, InstructorID, InstructorName)` where $\text{CourseID} \rightarrow \text{CourseName}, \text{InstructorID}$ and $\text{InstructorID} \rightarrow \text{InstructorName}$ (`InstructorID` is not a candidate key):
- Decompose into:
  1. **`Course_BCNF` (`<u>CourseID</u>`, `CourseName`, `InstructorID`)**
  2. **`Instructor_BCNF` (`<u>InstructorID</u>`, `InstructorName`)**

---

### 4. Detailed Comparison Between 3NF and BCNF

| Point of Comparison | Third Normal Form (3NF) | Boyce–Codd Normal Form (BCNF) |
| :--- | :--- | :--- |
| **1. Formal Condition (for non-trivial $X \rightarrow A$)** | Either $X$ is a **Super Key**, **OR** $A$ is a **Prime Attribute**. | $X$ **must always be a Super Key** (no exception for prime attributes). |
| **2. Strictness** | Less strict than BCNF. | Strictly stronger than 3NF (*Every BCNF relation is in 3NF, but not every 3NF relation is in BCNF*). |
| **3. Focus** | Removes transitive dependencies of **non-prime** attributes on candidate keys. | Removes **all** functional dependencies where the determinant is not a super key. |
| **4. Redundancy & Anomalies** | Some redundancy and update anomalies may still remain when candidate keys overlap. | Zero redundancy from functional dependencies; eliminates all FD-based anomalies. |
| **5. Lossless Join** | Always guarantees a **lossless-join** decomposition. | Always guarantees a **lossless-join** decomposition. |
| **6. Dependency Preservation** | **Always** possible to achieve a dependency-preserving decomposition into 3NF. | **May NOT always preserve** all functional dependencies (e.g., $(\text{Student}, \text{Course}) \rightarrow \text{Instructor}$ spans both tables after BCNF split). |

**Conclusion:** 3NF is easier to achieve and always preserves functional dependencies, whereas BCNF is a stricter normal form that eliminates all FD-related redundancy, sometimes at the expense of dependency preservation.

---

## 5. Explain Lossless Join and Dependency Preserving Decomposition.

When a relation $R$ is decomposed into two or more smaller relations $R_1, R_2, \dots, R_n$ during normalization, the decomposition must satisfy two critical correctness properties:
1. **Lossless-Join (Non-Additive Join) Property**
2. **Dependency Preservation Property**

---

### 1. Lossless Join Decomposition
- **Definition:** A decomposition of a relation $R$ into $R_1$ and $R_2$ is called a **Lossless Join Decomposition** if the original relation $R$ can be **recovered exactly** by taking the **natural join** ($\bowtie$) of the decomposed relations, without generating any extraneous (**spurious**) tuples:
  $$\pi_{R_1}(R) \bowtie \pi_{R_2}(R) = R$$
- **Formal Condition for Binary Lossless Join:**
  A decomposition of $R$ into $R_1$ and $R_2$ is lossless if and only if the **common attributes ($R_1 \cap R_2$) form a Super Key of either $R_1$ or $R_2$** (under the closure of $F$):
  $$(R_1 \cap R_2) \rightarrow R_1 \quad \text{OR} \quad (R_1 \cap R_2) \rightarrow R_2$$

#### Why it is Important
- Prevents **loss of information** and prevents the creation of **spurious (false) tuples** when tables are joined back together in queries.

#### Worked Example (`EMPLOYEE` Relation)
Consider relation:
$$\text{EMPLOYEE}(\text{Emp\_ID}, \text{Emp\_Name}, \text{Dept\_ID}, \text{Dept\_Name})$$
with Functional Dependencies:
1. $\text{Emp\_ID} \rightarrow \text{Emp\_Name}, \text{Dept\_ID}$
2. $\text{Dept\_ID} \rightarrow \text{Dept\_Name}$

Suppose we decompose `EMPLOYEE` into:
- $R_1(\text{Emp\_ID}, \text{Emp\_Name}, \text{Dept\_ID})$
- $R_2(\text{Dept\_ID}, \text{Dept\_Name})$

**Check Lossless Condition:**
- Common attribute: $R_1 \cap R_2 = \{\text{Dept\_ID}\}$.
- Since $\text{Dept\_ID} \rightarrow \text{Dept\_Name}$, the common attribute `Dept_ID` is the **Primary Key (Super Key) of $R_2$** ($R_1 \cap R_2 \rightarrow R_2$).
- Therefore, the decomposition is **Lossless**!

**Table Verification:**

**$R_1(\text{Emp\_ID}, \text{Emp\_Name}, \text{Dept\_ID})$:**

| `Emp_ID` | `Emp_Name` | `Dept_ID` |
| :---: | :--- | :---: |
| `1` | Ratan | `D1` |
| `2` | Vivek | `D2` |

**$R_2(\text{Dept\_ID}, \text{Dept\_Name})$:**

| `Dept_ID` | `Dept_Name` |
| :---: | :---: |
| `D1` | CSE |
| `D2` | ECE |

$$\implies R_1 \bowtie R_2 \text{ yields the exact original } \text{EMPLOYEE} \text{ relation with zero spurious tuples.}$$

---

### 2. Dependency Preserving Decomposition
- **Definition:** A decomposition of a relation $R$ (with functional dependency set $F$) into $R_1, R_2, \dots, R_n$ (with projected FD sets $F_1, F_2, \dots, F_n$) is **Dependency Preserving** if the closure of the union of the individual local dependencies equals the closure of the original dependencies $F$:
  $$(F_1 \cup F_2 \cup \dots \cup F_n)^+ = F^+$$
- **In Simple Words:** Every functional dependency in $R$ can be enforced and verified by checking **only a single decomposed table individually**, without having to join multiple tables at runtime.

#### Why it is Important
- Maintains all integrity constraints of the original schema.
- Avoids expensive multi-table `JOIN` operations on every `INSERT` or `UPDATE` just to verify a functional dependency.

#### Worked Example
In the `EMPLOYEE` decomposition above:
- In $R_1(\text{Emp\_ID}, \text{Emp\_Name}, \text{Dept\_ID})$, we can directly check and enforce $\text{Emp\_ID} \rightarrow \text{Emp\_Name}, \text{Dept\_ID}$.
- In $R_2(\text{Dept\_ID}, \text{Dept\_Name})$, we can directly check and enforce $\text{Dept\_ID} \rightarrow \text{Dept\_Name}$.
- Similarly, if $R(A, B, C)$ with $F = \{A \rightarrow B, B \rightarrow C\}$ is decomposed into $R_1(A, B)$ and $R_2(B, C)$, $F_1 = \{A \rightarrow B\}$ and $F_2 = \{B \rightarrow C\}$, and $(F_1 \cup F_2)^+ = F^+$ (since $A \rightarrow C$ follows by transitivity). Hence, it is **Dependency Preserving**!

---

### 3. Comparison: Lossless Join vs. Dependency Preserving Decomposition

| Feature | Lossless Join Decomposition | Dependency Preserving Decomposition |
| :--- | :--- | :--- |
| **1. Core Meaning** | Original relation $R$ can be reconstructed **exactly** by natural joining the decomposed relations. | All functional dependencies $F$ of $R$ are preserved within the individual decomposed relations. |
| **2. Primary Focus** | Data correctness — **zero spurious tuples** and no information loss. | Constraint enforcement efficiency — **easy FD checking**. |
| **3. Is a `JOIN` Needed?** | Uses `JOIN` to reconstruct the original relation $R$. | Ensures `JOIN` is **not needed** to validate functional dependencies. |
| **4. Mathematical Test** | $(R_1 \cap R_2) \rightarrow R_1$ or $(R_1 \cap R_2) \rightarrow R_2$. | $(F_1 \cup F_2 \cup \dots \cup F_n)^+ = F^+$. |
| **5. Requirement in Design** | **Mandatory** (non-negotiable in all decompositions up to 5NF). | **Highly desirable** (always achievable up to 3NF; occasionally sacrificed in BCNF). |

**Conclusion:** An ideal relational decomposition should be both **lossless join** (guaranteeing zero data loss or spurious tuples) and **dependency preserving** (allowing all constraints to be checked locally without joins).

---

## 6. Explain Transaction Management and ACID properties with examples.

### 1. Transaction and Transaction Management
- **What is a Transaction?**
  - A **Transaction** is a single **logical unit of work** in a database that consists of one or more database access operations (such as `READ`, `WRITE`, `INSERT`, `UPDATE`, or `DELETE`).
  - Either **all** operations within the transaction succeed completely, or **none** of them take effect.
- **What is Transaction Management?**
  - **Transaction Management** is the DBMS subsystem responsible for coordinating the execution of transactions so that the database remains **consistent, accurate, and reliable**, even in the presence of **concurrent multi-user access** and **system crashes/failures**.

#### Main Activities / Operations in Transaction Management
1. **`BEGIN TRANSACTION`:** Marks the start of a new transaction.
2. **`READ(X)` / `WRITE(X)`:** Reads a data item $X$ from disk/buffer or writes an updated value to $X$.
3. **`COMMIT`:** Signals successful completion of the transaction and makes all changes **permanent** in the database.
4. **`ROLLBACK` (`ABORT`):** Undoes all changes made by the transaction if an error or failure occurs, restoring the database to its state prior to `BEGIN`.
5. **Concurrency Control & Recovery Management:** Manages interleaved execution among multiple users and restores consistency after crashes.

#### Bank Fund Transfer Example ($\text{Transfer } ₹1000 \text{ from Account } A \text{ to Account } B$)
```text
Transaction T (Transfer ₹1000 from A to B):
1. read(A)
2. A = A - 1000       // Deduct ₹1000 from Account A
3. write(A)
4. read(B)
5. B = B + 1000       // Add ₹1000 to Account B
6. write(B)
7. COMMIT
```

---

### 2. ACID Properties of a Transaction
To guarantee data integrity and reliability, every DBMS transaction must satisfy four fundamental properties known by the acronym **ACID**:

#### 1. Atomicity ("All-or-Nothing" Property)
- **Definition:** A transaction is treated as a single, **indivisible (atomic) unit of execution**. Either **all** of its operations are executed completely, or **none** of them are executed at all. No partial changes are ever left behind.
- **Example:** In the bank transfer of $₹1000$ from Account $A$ to Account $B$, if $₹1000$ is debited from $A$ (`write(A)`) and a system crash occurs before it is credited to $B$, **Atomicity** ensures the debit from $A$ is rolled back so money is not lost.

#### 2. Consistency (Correctness Preservation)
- **Definition:** A transaction must transform the database from **one valid (consistent) state to another valid state**, preserving all defined database integrity constraints, business rules, and invariants.
- **Example:** Suppose initially $A = ₹3000$ and $B = ₹2000$, so the total sum is $A + B = ₹5000$. After transferring $₹1000$ ($A = ₹2000, B = ₹3000$), the total sum $A + B$ must still equal **$₹5000$**, and no account balance rule (such as $\text{Balance} \ge 0$) is violated.

#### 3. Isolation (Concurrency Independence)
- **Definition:** Although multiple transactions may execute **concurrently**, the execution of one transaction must be **isolated** from the intermediate, uncommitted states of other concurrently running transactions. The final effect must be equivalent to some **serial** (one-after-another) execution.
- **Example:** While Transaction $T_1$ is transferring $₹1000$ from $A$ to $B$ (after debiting $A$ but before crediting $B$), another concurrent Transaction $T_2$ calculating $A + B$ must **not** read the intermediate state where $₹1000$ appears missing.

#### 4. Durability (Permanence)
- **Definition:** Once a transaction has successfully completed and executed **`COMMIT`**, its changes to the database are **permanent** and must never be lost — even if a power outage, operating system crash, or hardware failure occurs immediately afterward.
- **Example:** Once the bank displays *"Transfer of ₹1000 Successful"* (`COMMIT`), the updated balances ($A = ₹2000, B = ₹3000$) remain permanently saved in non-volatile storage even if the server crashes one millisecond later.

---

### 3. SQL Transaction Example
```sql
BEGIN TRANSACTION;

UPDATE Account SET Balance = Balance - 1000 WHERE Acc_No = 101;
UPDATE Account SET Balance = Balance + 1000 WHERE Acc_No = 102;

-- If both statements succeed without error:
COMMIT;

-- If any error occurs before COMMIT:
-- ROLLBACK;
```

**Conclusion:** Transaction management coordinates atomic logical units of work, and the **ACID properties** (*Atomicity, Consistency, Isolation, Durability*) guarantee that database operations remain reliable, accurate, and crash-safe.

---

## 7. Explain Transaction States with a neat state transition diagram.

### 1. Introduction
During its execution lifecycle from start (`BEGIN`) to completion, a transaction in a DBMS passes through a well-defined sequence of **Transaction States**. Tracking these states enables the DBMS to manage commits, handle runtime errors, and perform crash recovery accurately.

---

### 2. States of a Transaction
1. **Active State:**
   - The **initial state** of every transaction when it begins execution.
   - The transaction stays in the **Active** state while its `READ` and `WRITE` operations are actively executing in main memory buffers.
2. **Partially Committed State:**
   - The transaction enters this state immediately after its **final statement has been executed**.
   - At this point, the modified data values may still reside in volatile main memory buffers and have not yet been permanently flushed to disk.
3. **Committed State:**
   - The transaction enters the **Committed** state once all its updates and log records have been permanently written (flushed) to stable storage (`COMMIT` succeeds).
   - Once committed, a transaction can **never** be rolled back.
4. **Failed State:**
   - A transaction enters the **Failed** state from either the *Active* or *Partially Committed* state when the system discovers that normal execution can no longer proceed (e.g., due to a hardware/software crash, division by zero, integrity constraint violation, deadlock, or explicit user abort).
5. **Aborted State:**
   - After entering the *Failed* state, the Recovery Manager **rolls back (undoes)** all changes made by the transaction, restoring the database to the consistent state it was in before the transaction started. Once rollback is complete, the transaction is in the **Aborted** state.
6. **Terminated (End) State:**
   - The transaction leaves the system and releases all held locks/resources after completing either **Committed** or **Aborted**.

---

### 3. Neat State Transition Diagram

![Transaction State Transition Diagram](figures/unit4_q7_transaction_states.png)

---

### 4. Explanation of State Transitions
1. **$\text{Begin} \rightarrow \text{Active}$:** When a transaction starts (`BEGIN TRANSACTION`), it enters the **Active** state and executes its read/write instructions.
2. **$\text{Active} \rightarrow \text{Partially Committed}$:** Once the very last instruction of the transaction executes without error, it transitions to **Partially Committed**.
3. **$\text{Partially Committed} \rightarrow \text{Committed}$:** After the DBMS flushes log records to disk and completes the `COMMIT` protocol, the transaction moves to **Committed**.
4. **$\text{Active / Partially Committed} \rightarrow \text{Failed}$:** If any runtime error, user abort, or power/system crash occurs before commit completes, the transaction transitions immediately to **Failed**.
5. **$\text{Failed} \rightarrow \text{Aborted}$:** The DBMS executes a `ROLLBACK` to undo all partial writes made by the transaction and moves it to **Aborted**.
6. **From $\text{Aborted}$ (Two Possible Actions):**
   - **Restart the Transaction:** If the failure was caused by an external transient event (such as a deadlock victim selection or temporary hardware glitch), the DBMS automatically restarts it as a new transaction ($\text{Aborted} \rightarrow \text{Active}$).
   - **Kill / Terminate the Transaction:** If the failure was caused by internal logic errors or bad user input (e.g., insufficient balance), the transaction is killed ($\text{Aborted} \rightarrow \text{Terminated}$).
7. **$\text{Committed / Aborted} \rightarrow \text{Terminated}$:** Finally, the transaction ends and its resources are reclaimed.

#### Real-World Bank Transfer Trace
Consider transferring $₹1000$ from Account $A$ to Account $B$:
- While deducting $₹1000$ from $A$ and adding $₹1000$ to $B$, the transaction is **Active**.
- After the final `UPDATE` statement finishes in memory, it is **Partially Committed**.
- Once the commit log is written to disk, it becomes **Committed** $\rightarrow$ **Terminated**.
- If a power failure occurs before the commit log is flushed, it transitions to **Failed**, rolls back to **Aborted**, and then **Terminated**.

**Conclusion:** The transaction state transition diagram models the complete lifecycle of a database transaction, ensuring that every transaction ends cleanly in either a permanently **Committed** or fully rolled-back **Aborted** state.

---

## 8. Discuss conflict serializability and view serializability with suitable examples.

### Introduction: What is Serializability?
When multiple transactions execute **concurrently** (interleaved in time), their schedule $S$ is correct and preserves database consistency if and only if it is **Serializable** — meaning the final outcome of the concurrent schedule $S$ is **equivalent to some serial schedule** (where transactions execute one after another without any interleaving, e.g., $T_1 \rightarrow T_2$ or $T_2 \rightarrow T_1$).

There are two principal forms of serializability:
1. **Conflict Serializability**
2. **View Serializability**

---

### 1. Conflict Serializability
- **Definition:** A schedule $S$ is **Conflict Serializable** if it is **conflict equivalent** to some serial schedule — that is, $S$ can be transformed into a serial schedule by a series of swaps of **non-conflicting** adjacent instructions.
- **When Do Two Operations Conflict?**
  Two operations $I_i$ and $I_j$ conflict if and only if **all three conditions** hold simultaneously:
  1. They belong to **different transactions** ($T_i \neq T_j$).
  2. They access the **same data item** $X$.
  3. **At least one** of the two operations is a **`WRITE(X)`** operation.
- **Three Conflicting Operation Pairs on Data Item $X$:**
  1. **Read–Write ($\text{RW}$ Conflict):** $R_i(X)$ followed by $W_j(X)$
  2. **Write–Read ($\text{WR}$ Conflict):** $W_i(X)$ followed by $R_j(X)$
  3. **Write–Write ($\text{WW}$ Conflict):** $W_i(X)$ followed by $W_j(X)$
  *(Note: $R_i(X)$ and $R_j(X)$ do **not** conflict because reading does not modify $X$.)*

#### Testing Conflict Serializability Using a Precedence (Serialization) Graph
1. Draw a directed graph $G = (V, E)$ where each vertex $T_i \in V$ represents a participating transaction.
2. Add a directed edge **$T_i \rightarrow T_j$** whenever an operation in $T_i$ **conflicts with and executes before** an operation in $T_j$ on the same data item.
3. **Decision Rule:**
   - Schedule $S$ is **Conflict Serializable if and only if its Precedence Graph has NO cycle (is a DAG)**.
   - The equivalent serial order is obtained by **Topological Sorting** of the precedence graph.

#### Worked Example 1 (Schedule $S_1$)
Consider schedule $S_1$ with two transactions $T_1$ and $T_2$ operating on data items $A$ and $B$:

| Step | $T_1$ | $T_2$ |
| :---: | :---: | :---: |
| `1` | $R_1(A)$ | — |
| `2` | $W_1(A)$ | — |
| `3` | — | $R_2(A)$ |
| `4` | — | $W_2(A)$ |
| `5` | $R_1(B)$ | — |
| `6` | $W_1(B)$ | — |
| `7` | — | $R_2(B)$ |
| `8` | — | $W_2(B)$ |

- **Conflicts on $A$:** $W_1(A)$ precedes $R_2(A)$ and $W_2(A) \implies$ Edge **$T_1 \rightarrow T_2$**.
- **Conflicts on $B$:** $W_1(B)$ precedes $R_2(B)$ and $W_2(B) \implies$ Edge **$T_1 \rightarrow T_2$**.
- Since the Precedence Graph ($T_1 \rightarrow T_2$) has **no cycle**, $S_1$ is **Conflict Serializable** and is equivalent to the serial schedule **$T_1 \rightarrow T_2$**.

![Conflict vs View Serializability Precedence Graphs](figures/unit4_q9_precedence_graphs.png)

---

### 2. View Serializability
- **Definition:** A schedule $S$ is **View Serializable** if it is **view equivalent** to some serial schedule $S_{\text{serial}}$.
- **Three Conditions for View Equivalence (For Every Data Item $X$):**
  1. **Initial Read:** If transaction $T_i$ reads the initial value of $X$ in schedule $S$, then $T_i$ must also read the initial value of $X$ in $S_{\text{serial}}$.
  2. **Updated Read (Read-From Relation):** If $T_i$ reads a value of $X$ written by $T_j$ in schedule $S$, then $T_i$ must also read the value of $X$ written by $T_j$ in $S_{\text{serial}}$.
  3. **Final Write:** The transaction that performs the **final `WRITE(X)`** in schedule $S$ must also perform the **final `WRITE(X)`** in $S_{\text{serial}}$.

#### Worked Example 2 (Schedule $S_2$ — View Serializable but NOT Conflict Serializable)
Consider schedule $S_2$ with **blind writes** (writes without prior reads):

| Step | $T_1$ | $T_2$ |
| :---: | :---: | :---: |
| `1` | $W_1(X)$ | — |
| `2` | — | $W_2(X)$ |
| `3` | $W_1(X)$ | — |

- **Conflict Serializability Test:**
  - Step 1 ($W_1(X)$) before Step 2 ($W_2(X)$) $\implies$ Edge $T_1 \rightarrow T_2$.
  - Step 2 ($W_2(X)$) before Step 3 ($W_1(X)$) $\implies$ Edge $T_2 \rightarrow T_1$.
  - The precedence graph has a **cycle ($T_1 \leftrightarrows T_2$)**, so $S_2$ is **NOT Conflict Serializable**.
- **View Serializability Test:**
  - Compare $S_2$ with the serial schedule **$T_2 \rightarrow T_1$** ($W_2(X)$ followed by $W_1(X)$):
    1. Neither schedule has any `READ(X)` operations (Conditions 1 & 2 are satisfied vacuously).
    2. In both $S_2$ and $T_2 \rightarrow T_1$, the **final write on $X$** is performed by **$T_1$**.
  - Therefore, $S_2$ is **View Equivalent** to $T_2 \rightarrow T_1$, so $S_2$ **IS View Serializable**!

---

### 3. Comparison: Conflict Serializability vs. View Serializability

| Point of Comparison | Conflict Serializability | View Serializability |
| :--- | :--- | :--- |
| **1. Core Basis** | Based on **conflict equivalence** (preserving order of conflicting RW, WR, WW pairs). | Based on **view equivalence** (preserving initial reads, read-from dependencies, and final writes). |
| **2. Testing Method & Cost** | Easy and fast ($O(V + E)$ polynomial time) using a **Precedence Graph** cycle check. | **NP-Complete** (expensive to test in general; requires checking polygraphs). |
| **3. Strictness / Coverage** | **More restrictive** (sufficient condition for serializability). | **Less restrictive / broader** (necessary and sufficient condition for view equivalence). |
| **4. Subset Relationship** | **Every conflict serializable schedule is view serializable.** | **Not every view serializable schedule is conflict serializable** (those with *blind writes* can be view serializable without being conflict serializable). |
| **5. Practical Use in DBMS** | Used by almost all practical concurrency control protocols (2PL, Timestamp Ordering). | Rarely tested directly at runtime due to high computational cost. |

**Conclusion:** Conflict serializability and view serializability are the two key correctness criteria for concurrent transaction schedules. Conflict serializability is efficiently verified via precedence graphs, while view serializability is more general and additionally admits valid schedules containing blind writes.

---

## 9. Explain Recoverability and Recovery Algorithms in DBMS.

### Introduction
**Recoverability** and **Recovery Algorithms** ensure that a database can always be restored to a **correct and consistent state** after a transaction abort, system crash, power outage, or disk failure, preserving **Atomicity** and **Durability**.

---

### 1. Recoverability of Schedules
- **Definition of a Recoverable Schedule:**
  A concurrent schedule $S$ is **Recoverable** if no transaction $T_j$ commits until **all transactions $T_i$ that have written a data item read by $T_j$ (a dirty read) have already committed**.
  $$\text{If } T_j \text{ reads } X \text{ written by } T_i \text{ } (W_i(X) < R_j(X)), \text{ then } \text{Commit}(T_i) < \text{Commit}(T_j).$$

#### Why Recoverability is Important
- Suppose $T_1$ writes a new value to $X$, and $T_2$ reads that uncommitted value of $X$ and **commits immediately** before $T_1$. If $T_1$ subsequently fails and aborts, $T_2$ has already committed based on an invalid, non-existent value (**dirty read**), violating **Durability** (since committed $T_2$ cannot be undone).

#### Example of Recoverable vs. Non-Recoverable Schedule

| Recoverable Schedule (Valid) | Non-Recoverable Schedule (Invalid) |
| :--- | :--- |
| 1. $T_1: \text{Write}(X)$ | 1. $T_1: \text{Write}(X)$ |
| 2. $T_2: \text{Read}(X)$ *(reads $T_1$'s value)* | 2. $T_2: \text{Read}(X)$ *(dirty read from $T_1$)* |
| 3. $T_1: \text{Commit}$ *($T_1$ commits first)* | 3. $T_2: \text{Commit}$ *($T_2$ commits before $T_1$!)* |
| 4. $T_2: \text{Commit}$ *($T_2$ commits after $T_1$)* | 4. $T_1: \text{Abort}$ *(Inconsistency! Committed $T_2$ read aborted data)* |

#### Hierarchy of Recoverable Schedule Types
1. **Recoverable Schedule:** Dependent transaction $T_j$ commits only **after** the writing transaction $T_i$ commits. *(May still suffer from cascading rollbacks.)*
2. **Cascadeless Schedule (Avoids Cascading Aborts — ACA):** A transaction $T_j$ is allowed to **read** a data item $X$ written by $T_i$ **only after $T_i$ has committed**. Prevents a single abort from forcing a chain of rollbacks.
3. **Strict Schedule:** Neither **reading nor writing** a data item $X$ modified by $T_i$ is allowed until $T_i$ has **committed or aborted**. Strict schedules are the easiest to recover using before-images.

---

### 2. Recovery Algorithms in DBMS

Recovery algorithms restore the database to a consistent state after a failure by preserving **Atomicity** (undoing uncommitted transactions) and **Durability** (redoing committed transactions).

#### (1) Log-Based Recovery & Write-Ahead Logging (WAL)
- The DBMS maintains a sequential **System Log** on stable storage recording every action of every transaction:
  - `<Ti, START>`
  - `<Ti, X, old_value, new_value>` (Update log record)
  - `<Ti, COMMIT>` or `<Ti, ABORT>`
- **Write-Ahead Logging (WAL) Rule:** Log records must be flushed to stable storage **before** the corresponding data page is written to disk and before a transaction is considered committed.
- Uses two recovery operations:
  - **`UNDO(Ti)`:** Restores all data items updated by incomplete/aborted transaction $T_i$ to their **`old_value`** (backward scan).
  - **`REDO(Ti)`:** Sets all data items updated by committed transaction $T_i$ to their **`new_value`** (forward scan).

#### (2) Deferred Database Modification (No-Undo / Redo Algorithm)
- **Working:** All `WRITE` operations of a transaction are recorded **only in the log** and local buffers during execution; **actual database disk writes are deferred (postponed) until the transaction reaches `Partially Committed` / `COMMIT`**.
- **Recovery Action after Crash:**
  - **No `UNDO` is ever required** because uncommitted transactions never modified the database on disk!
  - **`REDO(Ti)`** is performed for any transaction that has both `<Ti, START>` and `<Ti, COMMIT>` in the log.

#### (3) Immediate Database Modification (Undo / Redo Algorithm)
- **Working:** Database modifications can be written to the disk **while the transaction is still in the Active state** (before `COMMIT`), provided the WAL log record is written first.
- **Recovery Action after Crash:**
  - **`UNDO(Ti)`** is performed for all transactions that have `<Ti, START>` in the log **without** a `<Ti, COMMIT>` record.
  - **`REDO(Ti)`** is performed for all transactions that have **both** `<Ti, START>` and `<Ti, COMMIT>` in the log.

#### (4) Checkpointing (Checkpoint Recovery)
- Scanning the entire log from the beginning of time during crash recovery is too slow.
- **Working:** Periodically, the DBMS flushes all modified buffer blocks and log records to disk and writes a `<CHECKPOINT L>` record to the log (where $L$ is the list of transactions active at that moment).
- **Benefit:** During recovery, the DBMS only needs to scan back to the **most recent `<CHECKPOINT>`**, drastically reducing recovery time.

#### (5) Shadow Paging (Non-Log Recovery Technique)
- **Working:** The DBMS maintains two page tables during a transaction's lifetime:
  1. **Shadow Page Table:** Points to the unmodified original disk pages prior to the transaction (never changed during execution).
  2. **Current Page Table:** Points to newly allocated disk pages whenever a write occurs (**Copy-on-Write**).
- **Commit / Abort:** To **commit**, the pointer to the Current Page Table atomically replaces the Shadow Page Table pointer. If a **crash/abort** occurs, the Current Page Table is simply discarded and the Shadow Page Table is already consistent — requiring **neither `UNDO` nor `REDO`**!

---

### 3. Step-by-Step Recovery Procedure After a Crash
1. **Locate Point of Failure:** Scan the log backward to find the most recent `<CHECKPOINT>`.
2. **Build `UNDO-LIST` and `REDO-LIST`:**
   - Transactions with `<Ti, COMMIT>` go into `REDO-LIST`.
   - Incomplete transactions (no `<Ti, COMMIT>`) go into `UNDO-LIST`.
3. **Analysis / REDO Phase (Forward Pass):** Re-apply (`REDO`) updates of all committed transactions.
4. **UNDO Phase (Backward Pass):** Roll back (`UNDO`) all incomplete transactions in reverse chronological order.
5. **Resume Normal Operation:** Database is now in a consistent state.

**Conclusion:** Recoverability ensures transactions commit in a safe dependency order, while recovery algorithms (*Log-Based WAL, Deferred Update, Immediate Update, Checkpointing, and Shadow Paging*) guarantee database consistency after any failure.

---

## 10. Explain Concurrent Execution and Serializability with examples.

### 1. Concurrent Execution of Transactions
- **Definition:** **Concurrent Execution** means executing multiple transactions **simultaneously** in a multi-user database system by **interleaving (mixing)** their elementary `READ` and `WRITE` operations in time (e.g., while one transaction waits for disk I/O, the CPU executes another transaction).

#### Why Concurrent Execution is Important (Advantages)
1. **Increased System Throughput:** More transactions are completed per unit of time because CPU and Disk I/O operate in parallel.
2. **Reduced Average Waiting & Response Time:** Short transactions do not have to wait behind a long-running batch transaction.
3. **Better Resource Utilization:** Keeps both the CPU and I/O subsystem busy simultaneously.

#### Worked Example of Concurrent Execution
Consider two concurrent banking transactions $T_1$ and $T_2$:
- **$T_1$:** Transfers $₹100$ from Account $A$ to Account $B$.
- **$T_2$:** Checks the balance of Account $A$.

| Transaction $T_1$ (Transfer $₹100$ from $A$ to $B$) | Transaction $T_2$ (Check balance of $A$) |
| :--- | :--- |
| `1. read(A)` | `1. read(A)` |
| `2. A = A - 100` | `2. print(A)` |
| `3. write(A)` | `3. if (A >= 0) print("Sufficient")` |
| `4. read(B)` | `   else print("Insufficient")` |
| `5. B = B + 100` | |
| `6. write(B)` | |

When the DBMS interleaves instructions from $T_1$ and $T_2$, the resulting chronological sequence of operations is called a **Schedule**.

---

### 2. Potential Concurrency Problems (If Uncontrolled)
If concurrent transactions interleave without proper concurrency control, three classic anomalies occur:
1. **Lost Update Problem (Write–Write Conflict):** Two transactions read the same old balance and both write back their updates, causing one transaction's update to overwrite the other's.
2. **Dirty Read Problem (Write–Read Conflict):** Transaction $T_2$ reads an uncommitted modified value written by $T_1$, and $T_1$ later rolls back.
3. **Unrepeatable Read / Inconsistent Retrieval (Read–Write Conflict):** Transaction $T_1$ reads data item $X$ twice and gets two different values because $T_2$ modified and committed $X$ in between.

---

### 3. Serializability
- **Definition:** A concurrent schedule $S$ of $n$ transactions is called **Serializable** if its net effect on the database is **identical to the effect of some Serial Schedule** (executing the $n$ transactions strictly one after another with zero interleaving).
- **Main Types of Serializability:**
  1. **Conflict Serializability**
  2. **View Serializability**

#### Worked Example of a Serializable Concurrent Schedule
Suppose initial value $X = 50$, and two transactions execute:
- **$T_1$:** `read(X); X = X + 10; write(X);`
- **$T_2$:** `read(X); X = X - 5; write(X);`

**Valid Interleaved Schedule $S$:**
1. $T_1: \text{read}(X)$ *(reads $50$)*
2. $T_1: X = X + 10 \rightarrow \text{write}(X)$ *(writes $60$)*
3. $T_2: \text{read}(X)$ *(reads $60$)*
4. $T_2: X = X - 5 \rightarrow \text{write}(X)$ *(writes $55$)*

- The final value of $X = 55$ is **identical** to the serial execution order **$T_1 \rightarrow T_2$**. Hence, schedule $S$ is **Serializable** and maintains complete database consistency.

**Conclusion:** Concurrent execution maximizes throughput and minimizes response time, while **serializability** serves as the golden correctness criterion ensuring that interleaved execution never corrupts database consistency.
