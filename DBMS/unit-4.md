# UNIT 4 — Normalization, Transactions & Concurrency

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. Normalization, 1NF & 2NF

> **Question:** Explain the purpose of Normalization and discuss 1NF, 2NF with suitable examples.

---

### Definition
**Normalization** is a systematic database design technique that decomposes relations, using **functional dependencies**, to **minimise redundancy** and eliminate **insertion, update and deletion anomalies**, while keeping the decomposition **lossless**.

### Purpose of Normalization
1. **Reduce redundancy:** the same fact (for example a course name) is stored only once instead of being repeated in every row.
2. **Remove anomalies:**
   - *Insertion anomaly* — a new course cannot be recorded until some student enrols in it.
   - *Deletion anomaly* — deleting the last enrolment of a course also erases the course details.
   - *Update anomaly* — changing a student's name requires editing many rows; missing one leaves inconsistent data.
3. **Improve integrity:** since each fact lives in one place, constraints are easy to enforce.
4. **Logical clarity:** each table represents one entity or one relationship.

### First Normal Form (1NF)
A relation is in 1NF if every attribute contains only **atomic (indivisible) values** and there are no **repeating groups** or multi-valued cells. Composite attributes are split into separate columns, and multi-valued attributes are moved into separate rows or a separate table.

```
Not in 1NF                    1NF
+--------+-----------+        +--------+-------+
| RollNo | Phones    |        | RollNo | Phone |
| 1      | 98, 97    |  --->  | 1      | 98    |
+--------+-----------+        | 1      | 97    |
                              +--------+-------+
```

### Second Normal Form (2NF)
A relation is in 2NF if it is in 1NF and **every non-prime attribute is fully functionally dependent on the entire candidate key**, i.e. there is no **partial dependency**. This matters only when the key is **composite**; a 1NF relation with a single-attribute key is automatically in 2NF. The cure is to move each partially dependent attribute, together with its determinant, into a new relation.

### Example
`STUD_COURSE(RollNo, CID, SName, CName, Grade)` with key (RollNo, CID):

| RollNo | CID | SName | CName | Grade |
|---|---|---|---|---|
| 1 | C1 | Ravi | DBMS | A |
| 1 | C2 | Ravi | OS | B |
| 2 | C1 | Sita | DBMS | A |

Dependencies: `RollNo → SName` and `CID → CName` are **partial dependencies** (they depend on only part of the key), while `(RollNo, CID) → Grade` is full. "Ravi" and "DBMS" repeat, causing the anomalies above.

**Decomposition into 2NF:**
- `STUDENT(RollNo, SName)` → (1, Ravi), (2, Sita)
- `COURSE(CID, CName)` → (C1, DBMS), (C2, OS)
- `ENROLL(RollNo, CID, Grade)` → (1, C1, A), (1, C2, B), (2, C1, A)

Ravi's name is now stored once, a new course can be inserted into `COURSE` alone, and joining the three tables on RollNo and CID reproduces the original table, so the decomposition is lossless.

### Comparison
| Parameter | 1NF | 2NF |
|---|---|---|
| Requirement | Atomic values | 1NF + no partial dependency |
| Problem removed | Multi-valued / repeating groups | Dependency on part of composite key |
| Applies to | Every relation | Relations with composite keys |
| Technique | Split cells / new rows | Decompose on the partial key |
| Redundancy left | High | Reduced; transitive dependency remains |

---

## 2. 4NF & 5NF

> **Question:** Explain 4NF, and 5NF with suitable examples.

---

### Definition
- A relation is in **Fourth Normal Form (4NF)** if it is in **BCNF** and, for every non-trivial **multivalued dependency (MVD)** `X ↠ Y`, **X is a superkey**.
- A relation is in **Fifth Normal Form (5NF)**, also called **Project-Join Normal Form (PJNF)**, if every non-trivial **join dependency** is implied by the candidate keys; it cannot be decomposed further into smaller relations without loss unless the decomposition is dictated by keys.

### Multivalued Dependency
`X ↠ Y` means that for a given value of X, the set of Y values is independent of the other attributes Z. This forces a **cross product** of Y and Z values for each X, creating many redundant tuples. An MVD is *trivial* if Y ⊆ X or X ∪ Y = R. 4NF removes non-trivial MVDs whose left side is not a superkey by splitting R into R1(X, Y) and R2(X, Z).

### 4NF Example
`CTB(Course, Teacher, Book)` where the teachers and the books of a course are independent:

| Course | Teacher | Book |
|---|---|---|
| DBMS | Rao | Korth |
| DBMS | Rao | Elmasri |
| DBMS | Sharma | Korth |
| DBMS | Sharma | Elmasri |

Here `Course ↠ Teacher` and `Course ↠ Book`. Adding a third book needs one new row per teacher, and forgetting one causes inconsistency.

```
CTB(Course, Teacher, Book)
        |
   +----+-----------------+
   v                      v
CT(Course, Teacher)   CB(Course, Book)
```
`CT` = {(DBMS, Rao), (DBMS, Sharma)} and `CB` = {(DBMS, Korth), (DBMS, Elmasri)}. Joining on Course restores all four rows (lossless), and a new book is now a single row.

### Join Dependency and 5NF
A **join dependency** `*(R1, R2, …, Rn)` states that R equals the natural join of its projections on R1…Rn. Every MVD is a join dependency with n = 2. 5NF deals with relations that can be rebuilt losslessly only from **three or more** projections, arising from a cyclic business rule.

**Example:** `SPC(Agent, Company, Product)` with the rule "if an agent represents a company, the company makes a product, and the agent sells that product, then the agent sells that company's product":

| Agent | Company | Product |
|---|---|---|
| A1 | X | P1 |
| A1 | X | P2 |
| A1 | Y | P1 |
| A2 | X | P1 |

Project into `AC(Agent, Company)`, `CP(Company, Product)` and `AP(Agent, Product)`. Joining all three returns exactly the original four tuples, while joining only two produces spurious tuples. So the relation is decomposed into these three tables for 5NF.

### Comparison
| Parameter | 4NF | 5NF |
|---|---|---|
| Prerequisite | BCNF | 4NF |
| Dependency handled | Multivalued dependency | Join dependency |
| Decomposition | Binary (2 tables) | n-ary (3 or more tables) |
| Cause | Two independent multi-valued facts | Cyclic constraint among attributes |
| Condition | Left side of MVD is a superkey | JD implied by candidate keys |
| Frequency in practice | Common | Rare |

---

## 3. Functional Dependency & Types of Dependencies

> **Question:** Explain Functional Dependency and different types of dependencies with examples.

---

### Definition
A **functional dependency (FD)** `X → Y` holds on a relation R if, for any two tuples t1 and t2, **t1[X] = t2[X] implies t1[Y] = t2[Y]**. X is the **determinant** and Y is the **dependent**. For example, `RollNo → SName`: knowing the roll number fixes the student's name. FDs are semantic integrity constraints and form the basis of all normalization.

### Types of Dependencies
1. **Trivial FD:** `X → Y` where Y ⊆ X (e.g., `(RollNo, SName) → RollNo`). It is always true and conveys no information. If Y ⊄ X it is **non-trivial**.
2. **Full functional dependency:** Y depends on X and on no proper subset of X, e.g., `(RollNo, CID) → Grade`.
3. **Partial dependency:** a non-prime attribute depends on only part of a composite key, e.g., `(RollNo, CID) → SName` where `RollNo → SName`. It violates 2NF.
4. **Transitive dependency:** `X → Y` and `Y → Z`, with Y not a key, imply `X → Z`, e.g., `EmpID → DeptNo → DName`. It violates 3NF.
5. **Multivalued dependency:** `X ↠ Y`, where Y values are independent of the remaining attributes. It violates 4NF.
6. **Join dependency:** the relation equals the join of its projections. It violates 5NF.

```
Full:        (RollNo, CID) ----> Grade
Partial:     (RollNo, CID) ..-> SName     (really RollNo -> SName)
Transitive:  RollNo ---> DeptNo ---> DeptName
```

### Armstrong's Axioms and Closure
- **Reflexivity:** if Y ⊆ X then X → Y.
- **Augmentation:** if X → Y then XZ → YZ.
- **Transitivity:** if X → Y and Y → Z then X → Z.

These axioms are **sound and complete** and yield derived rules (union, decomposition, pseudo-transitivity). The **closure X⁺** is the set of all attributes functionally determined by X; if X⁺ contains every attribute of R, X is a **superkey**.

**Closure trace:** for F = {A → B, B → C}: A⁺ = {A}; using A → B gives {A, B}; using B → C gives {A, B, C}. Hence A → C holds.

### Example
`EMP(EmpID, EName, DeptNo, DName, ProjID, Hours)` with key (EmpID, ProjID):
- `EmpID → EName, DeptNo` is a partial dependency.
- `DeptNo → DName` together with `EmpID → DeptNo` gives the transitive dependency `EmpID → DName`.
- `(EmpID, ProjID) → Hours` is a full dependency.

### Summary
| Type | Condition | Normal form violated |
|---|---|---|
| Trivial | Y ⊆ X | None |
| Full | No subset of X determines Y | — |
| Partial | Part of key determines Y | 2NF |
| Transitive | Non-key → non-key | 3NF |
| Multivalued | X ↠ Y independent of Z | 4NF |

---

## 4. 3NF vs BCNF

> **Question:** Compare 3NF and BCNF with suitable examples.

---

### Definition
- A relation R is in **Third Normal Form (3NF)** if for every non-trivial FD `X → A`, either **X is a superkey** or **A is a prime attribute** (part of some candidate key).
- A relation R is in **Boyce–Codd Normal Form (BCNF)** if for every non-trivial FD `X → Y`, **X is a superkey**.

Every BCNF relation is in 3NF, but not every 3NF relation is in BCNF.

```
1NF ⊃ 2NF ⊃ 3NF ⊃ BCNF ⊃ 4NF ⊃ 5NF
```

### Explanation
3NF removes transitive dependencies of non-prime attributes on the key. BCNF closes the loophole that 3NF leaves: a **non-superkey determinant that determines a prime attribute**. This occurs when a relation has **overlapping composite candidate keys**. 3NF decomposition can always be made both **lossless and dependency preserving**, whereas BCNF decomposition is always lossless but may **lose dependencies**.

### Example
`TEACH(Student, Course, Teacher)` with FDs `(Student, Course) → Teacher` and `Teacher → Course` (each teacher teaches exactly one course). Candidate keys: (Student, Course) and (Student, Teacher).

| Student | Course | Teacher |
|---|---|---|
| S1 | DBMS | Rao |
| S2 | DBMS | Rao |
| S3 | OS | Das |

- **3NF check:** in `Teacher → Course`, Course is a prime attribute, so 3NF is satisfied.
- **BCNF check:** Teacher is not a superkey, so BCNF is violated; the pair "Rao–DBMS" is stored repeatedly.

**BCNF decomposition:** `TC(Teacher, Course)` and `ST(Student, Teacher)`. Redundancy disappears and the join is lossless because Teacher is a key of `TC`. However, `(Student, Course) → Teacher` cannot be checked within one table any more, so the dependency is not preserved. In such cases a designer may deliberately stop at 3NF.

### Comparison
| Parameter | 3NF | BCNF |
|---|---|---|
| Condition | X is superkey OR A is prime | X must be a superkey |
| Strictness | Weaker | Stronger |
| Redundancy | Small residual possible | Almost none (FD-based) |
| Lossless join | Always achievable | Always achievable |
| Dependency preservation | Always achievable | Not always |
| Overlapping candidate keys | Not fully handled | Handled |
| Relationship | Superset | Subset of 3NF |

---

## 5. Lossless Join & Dependency Preserving Decomposition

> **Question:** Explain Lossless Join and Dependency Preserving Decomposition.

---

### Definition
Decomposition replaces a relation R by smaller relations R1, R2, …, Rn. A good decomposition must satisfy two properties.
- **Lossless-join:** `R1 ⋈ R2 ⋈ … ⋈ Rn = R` for every legal instance, so no information is lost and no spurious tuples appear.
- **Dependency preserving:** `(F1 ∪ F2 ∪ … ∪ Fn)⁺ = F⁺`, where Fi is the set of FDs of F that involve only attributes of Ri, so every FD can be enforced without joining tables.

```
        R(A,B,C)
        /      \
  R1(A,B)    R2(B,C)        common attribute B is the "glue"
```

### Lossless-Join Test
For a binary decomposition of R into R1 and R2, it is lossless **if and only if** `R1 ∩ R2 → R1` or `R1 ∩ R2 → R2` is in F⁺; that is, the common attributes form a superkey of at least one component. A **lossy** decomposition gives **spurious tuples** on joining. For more than two relations the **tableau (chase) algorithm** is used.

### Dependency-Preservation Test
Project F onto each Ri, take the union of these projected sets, and check (using attribute closure) whether it implies every FD of F. If an FD can only be verified by joining tables, it is lost and constraint checking becomes expensive.

### Examples
**Lossless and preserving:** `R(EmpID, DeptNo, DName)` with F = {EmpID → DeptNo, DeptNo → DName}. Split into R1(EmpID, DeptNo) and R2(DeptNo, DName). The common attribute DeptNo is a key of R2, so the join is lossless. F1 = {EmpID → DeptNo}, F2 = {DeptNo → DName}; their union implies EmpID → DName by transitivity, so all dependencies are preserved.

**Lossy:** split `R(Name, City, Product)` into R1(Name, City) and R2(City, Product). City is a key of neither table, so two customers in the same city produce false (Name, Product) pairs after the join.

**Dependency lost:** R(A, B, C) with F = {AB → C, C → B}; the BCNF decomposition (A, C), (C, B) cannot verify AB → C within a single table.

### Comparison
| Property | Lossless Join | Dependency Preserving |
|---|---|---|
| Purpose | Retain information | Retain constraints |
| Test | R1 ∩ R2 is a key of R1 or R2 | (F1 ∪ F2)⁺ = F⁺ |
| Failure effect | Spurious tuples | FD checks need joins |
| Mandatory? | Yes, always | Desirable |
| Guaranteed in 3NF synthesis | Yes | Yes |
| Guaranteed in BCNF | Yes | No |

---

## 6. Transaction Management & ACID Properties

> **Question:** Explain Transaction Management and ACID properties with examples.

---

### Definition
A **transaction** is a logical unit of work made of one or more database operations that moves the database from one **consistent state** to another. **Transaction management** is the DBMS function, performed by the **concurrency-control** and **recovery** components, that ensures transactions satisfy the **ACID** properties. Basic operations are `BEGIN`, `READ(X)`, `WRITE(X)`, `COMMIT` and `ROLLBACK`.

```
 App --> [ Transaction Manager ] --> [ Concurrency Control ] --> Database
                 |                       (Isolation)
                 +--> [ Recovery Manager ] --> Log
                          (Atomicity, Durability)
```

### ACID Properties
1. **Atomicity — "all or nothing".** Either every operation of the transaction is reflected in the database or none is. If a failure occurs midway, the partial effects are rolled back using the log. *Responsible:* recovery manager.
2. **Consistency.** A transaction executed alone on a consistent database leaves it consistent: all integrity constraints (keys, foreign keys, balance totals) continue to hold. *Responsible:* the application programmer and the DBMS constraint checker.
3. **Isolation.** Concurrent transactions must not interfere; the outcome must be equivalent to running them one after another, and intermediate states are invisible to others. *Responsible:* concurrency-control manager (locking, timestamps).
4. **Durability.** Once a transaction commits, its changes persist even after crashes, ensured by **write-ahead logging** and forcing log records to disk. *Responsible:* recovery manager.

### Example
Transfer ₹500 from account A (₹1000) to account B (₹2000):
```
T1: READ(A); A = A - 500; WRITE(A);
    READ(B); B = B + 500; WRITE(B); COMMIT;
```
```sql
START TRANSACTION;
UPDATE ACCOUNT SET bal = bal - 500 WHERE acc = 'A';
UPDATE ACCOUNT SET bal = bal + 500 WHERE acc = 'B';
COMMIT;
```
- **Consistency:** A becomes 500 and B 2500; the total remains 3000.
- **Atomicity:** if the system crashes after `WRITE(A)` but before `WRITE(B)`, recovery restores A to 1000.
- **Isolation:** another transaction cannot see the intermediate state (500, 2000) because of locks.
- **Durability:** after COMMIT, a crash still leaves A = 500 and B = 2500 (redo from the log).

### Summary
| Property | Guarantee | Mechanism | Violation example |
|---|---|---|---|
| Atomicity | All or none | Undo log, rollback | Debit done, credit lost |
| Consistency | Valid state → valid state | Integrity constraints | Total balance changes |
| Isolation | No interference | Locks / MVCC | Lost update |
| Durability | Commit is permanent | WAL, redo | Committed data lost after crash |

---

## 7. Transaction States

> **Question:** Explain Transaction States with a neat state transition diagram.

---

### Definition
During its life a transaction passes through well-defined states: **Active, Partially Committed, Committed, Failed and Aborted**. The DBMS tracks the state so that, after a failure, it knows whether to keep or undo the transaction's work.

### State Transition Diagram
```
              last stmt             log flushed
   +--------+ executed +-----------+ ----------> +-----------+
   | ACTIVE | -------> | PARTIALLY |             | COMMITTED |
   +--------+          | COMMITTED | ----------> +-----------+
      |                +-----------+
      | error             | error
      v                   v
   +--------+  rollback +---------+
   | FAILED | --------> | ABORTED |  --> restart / kill
   +--------+           +---------+
```

### Explanation of States
1. **Active:** the initial state; the transaction is executing its read and write operations. Changes exist only in memory buffers.
2. **Partially Committed:** the final statement has been executed, but the changes may not yet be on disk. The system must still force the log to stable storage; a failure here (e.g., disk error) leads to Failed.
3. **Committed:** the commit record is safely on disk, so the changes are **durable** and cannot be undone.
4. **Failed:** normal execution can no longer proceed because of a logical error, deadlock, constraint violation or system crash.
5. **Aborted:** all effects have been **rolled back** and the database restored to the state before the transaction began. The system may then **restart** the transaction (after hardware or deadlock failures) or **kill** it (if the program itself is erroneous).

The **commit point** separates states where rollback is possible from the state where it is not.

### Transition Table
| State | Entered when | Next states |
|---|---|---|
| Active | Transaction starts | Partially committed, Failed |
| Partially committed | Last statement executed | Committed, Failed |
| Committed | Log flushed to disk | Terminated |
| Failed | An error occurs | Aborted |
| Aborted | Rollback complete | Restart or kill |

### Example
In a funds transfer, `BEGIN` puts T in **Active**; after both writes it becomes **Partially Committed**; once the log is forced and `COMMIT` is written it is **Committed**. If instead B's account is found frozen during the second write, T becomes **Failed**, A's debit is undone from the log, T becomes **Aborted**, and the user is informed (kill) or the transaction is retried later (restart).

---

## 8. Concurrent Execution & Serializability

> **Question:** Explain Concurrent Execution and Serializability with examples.

---

### Definition
**Concurrent execution** means the operations of several transactions are interleaved by the DBMS. A **schedule** is the chronological order in which their operations execute. A schedule is **serializable** if its effect is **equivalent to that of some serial schedule** of the same transactions.

### Need for Concurrency
Concurrent execution gives higher **throughput**, better **CPU and disk utilisation** and shorter **average response time**, since short transactions need not wait behind long ones.

### Problems Caused by Uncontrolled Concurrency
1. **Lost update (W–W):** two transactions read the same value and both write, so one update overwrites the other.
2. **Dirty read (W–R):** T2 reads a value written by uncommitted T1, which later rolls back.
3. **Non-repeatable read (R–W):** T1 reads X twice and gets different values because T2 modified it in between.
4. **Phantom read:** a repeated range query returns new rows inserted by another transaction.

### Serial and Serializable Schedules
```
Serial (T1 then T2)       Interleaved (non-serial)
T1: R(A) W(A)             T1: R(A)       W(A)
T2:            R(A) W(A)  T2:      R(A)       W(A)   <- lost update
```
With n transactions there are n! serial schedules and all are correct. A non-serial schedule is correct only if it is serializable. Two kinds of equivalence are used: **conflict** and **view**. Concurrency-control protocols such as two-phase locking and timestamp ordering enforce serializability.

### Example
Let A = 100, T1: A = A − 10, T2: A = A − 20. The correct final value is 70.
- **Bad schedule:** T1 reads 100; T2 reads 100; T1 writes 90; T2 writes 80. Final A = 80 and T1's update is lost.
- **Serializable schedule:** T1 reads 100 and writes 90; then T2 reads 90 and writes 70. This equals the serial order T1 → T2.

Locking fixes the first schedule: T2 must wait for T1's exclusive lock on A, forcing a serial-equivalent order.

| Schedule type | Interleaving | Correct? |
|---|---|---|
| Serial | None | Always |
| Serializable | Yes | Yes |
| Non-serializable | Yes | No |

---

## 9. Conflict & View Serializability

> **Question:** Discuss conflict serializability and view serializability with suitable examples.

---

### Definition
Two operations **conflict** if they belong to different transactions, access the same data item and at least one is a write (R–W, W–R, W–W; R–R never conflicts).
- A schedule is **conflict serializable** if it can be turned into a serial schedule by **swapping adjacent non-conflicting operations**.
- A schedule is **view serializable** if it is **view equivalent** to a serial schedule.

### Conflict Serializability — Precedence Graph Test
1. Create one node per transaction.
2. Add an edge Ti → Tj whenever an operation of Ti conflicts with a later operation of Tj.
3. If the graph is **acyclic**, the schedule is conflict serializable, and a **topological order** gives the equivalent serial schedule. A **cycle** means it is not.

```
 T1 ------> T2         acyclic  => conflict serializable
 T1 <=====> T2         cycle    => NOT conflict serializable
```

### View Serializability
Schedules S and S′ are **view equivalent** if: (i) a transaction that reads the initial value of Q in S does so in S′; (ii) if Ti reads a value written by Tj in S, it does so in S′; (iii) the transaction performing the final write of Q is the same in both. View serializability is more general than conflict serializability because it accepts schedules with **blind writes** (writes without a prior read). Testing it is **NP-complete**, so real systems use conflict serializability.

### Examples
**S1:** `R1(A) W1(A) R2(A) W2(A) R1(B) W1(B) R2(B) W2(B)` — every conflict (on A and on B) gives edge T1 → T2. No cycle, so it is conflict serializable and equivalent to T1, T2.

**S2:** `R1(A) R2(A) W1(A) W2(A)` — R1(A) before W2(A) gives T1 → T2, and R2(A) before W1(A) gives T2 → T1. A cycle exists, so S2 is not conflict serializable.

**View-only schedule:** `R1(A) W2(A) W1(A) W3(A)` — the precedence graph has a cycle (T1 → T2 and T2 → T1), so it is not conflict serializable. However, it is view equivalent to the serial schedule T1, T2, T3: T1 reads the initial A and T3 performs the final write, so it is view serializable.

### Comparison
| Aspect | Conflict Serializability | View Serializability |
|---|---|---|
| Basis | Order of conflicting operations | Reads-from and final writes |
| Test | Precedence graph (polynomial time) | NP-complete |
| Generality | Stricter | More general |
| Relation | Implies view serializability | Not always conflict serializable |
| Blind writes | Cannot accommodate | Can accept |
| Practical use | Widely used | Rarely used |

---

## 10. Recoverability & Recovery Algorithms

> **Question:** Explain Recoverability and Recovery Algorithms in DBMS.

---

### Definition
A schedule is **recoverable** if, whenever Tj reads data written by Ti, **Ti commits before Tj commits**. **Recovery** is the process of restoring the database to the latest consistent state after a failure, guaranteeing **atomicity and durability**, using the log, checkpoints, shadow paging or ARIES.

### Recoverability
```
Strict ⊂ Cascadeless (ACA) ⊂ Recoverable ⊂ All schedules
```
- **Non-recoverable schedule:** Tj reads Ti's write and commits first; if Ti later aborts, Tj cannot be undone, violating atomicity.
- **Recoverable schedule:** a reader commits only after the writer it depends on has committed.
- **Cascading rollback:** abort of Ti forces the abort of every transaction that read its data, wasting work.
- **Cascadeless schedule:** a transaction may read only values written by **committed** transactions.
- **Strict schedule:** a transaction neither reads nor overwrites an item written by an uncommitted transaction; this simplifies undo (strict two-phase locking produces strict schedules).

**Example:** `W1(A) R2(A) W2(B) C2 A1` is non-recoverable because T2 committed after reading T1's uncommitted A, and T1 then aborted. Delaying C2 until T1 commits makes it recoverable.

### Recovery Algorithms
1. **Deferred update (NO-UNDO/REDO):** updates are recorded in the log and applied to the database only after commit. After a crash, committed transactions are **redone**; uncommitted ones are ignored.
2. **Immediate update (UNDO/REDO):** the database may be changed before commit, but only after the log record is written (**write-ahead logging**). After a crash, uncommitted transactions are **undone** and committed ones **redone**.
3. **Checkpointing:** the system periodically flushes buffers and writes a `<checkpoint>` record so recovery scans the log only from the latest checkpoint.
4. **Shadow paging:** a *current page table* and an untouched *shadow page table* are kept; commit atomically switches the pointer, and abort simply discards the current table. No log is needed, but pages become fragmented.
5. **ARIES:** uses WAL with a *steal/no-force* buffer policy and three phases — **Analysis** (find dirty pages and active transactions), **Redo** (repeat history), **Undo** (roll back loser transactions, writing compensation log records).

### Log Recovery Example
```
<T1,start> <T1,A,100,90> <T1,commit> <T2,start> <T2,B,5,7>  CRASH
```
- T1 has a commit record → **REDO**: set A = 90.
- T2 has no commit record → **UNDO**: restore B = 5.

The database ends with A = 90 and B = 5, a consistent state.

### Comparison of Techniques
| Technique | Undo | Redo | Key idea |
|---|---|---|---|
| Deferred update | No | Yes | Write to DB only after commit |
| Immediate update | Yes | Yes | Log before data (WAL) |
| Shadow paging | No | No | Page-table pointer switch |
| ARIES | Yes | Yes | Analysis–Redo–Undo using LSNs |
