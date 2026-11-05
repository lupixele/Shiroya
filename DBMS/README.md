# Database Management Systems (2501IT05) — Study Hub & Exam Notes

*(Common to CSE, IT, AIML & CSE (DS) — Aditya University)*

Comprehensive, high-clarity exam preparation notes, unit-wise master question banks, and complete worked answers covering all 5 Units (47 Section B questions and 30 Section A compulsory questions).

---

## Examination Blueprint & Course Overview

- **Subject:** Database Management Systems (`2501IT05`)
- **Exam Date:** Friday, 06-11-2026 (End-Sem)
- **Exam Format:** 100 Marks (3 Hours)
  - **Section A (Compulsory):** 10 Qs × 2M = **20 Marks** (2 Qs from each Unit) → [`2-marks.md`](2-marks.md)
  - **Section B (Internal Choice):** 5 Units × 16M (two 8M Qs per unit) = **80 Marks** → [`unit-1.md`](unit-1.md) to [`unit-5.md`](unit-5.md)
- **Master Questions Index:** [`questions.md`](questions.md) (Complete index with direct links to all answers)

---

## Repository Index & Unit Navigation

| Section / Unit | Title | Questions Count | Answers Document | Syllabus & Topics Covered |
| :---: | :--- | :---: | :--- | :--- |
| **Index** | **Master Questions Index** | 47 Qs (8M) + 30 Qs (2M) | [`questions.md`](questions.md) | Full semester question directory with direct answer anchors |
| **Section A** | **2-Marks Short Answers** | 30 Qs | [`2-marks.md`](2-marks.md) | Compulsory 20M Section A (All 5 Units) |
| **Unit 1** | Database Concepts & Architecture | 10 Qs | [`unit-1.md`](unit-1.md) | Three-Schema, DBMS Architecture, DBA, Models, Parallel/Distributed, NoSQL, Client-Server |
| **Unit 2** | Relational Model, Algebra & SQL | 8 Qs | [`unit-2.md`](unit-2.md) | Relational Model, Keys, Relational Algebra, DDL, DML, SQL Functions, GROUP BY/HAVING, NULLs |
| **Unit 3** | ER Model, Constraints, Joins & Views | 10 Qs | [`unit-3.md`](unit-3.md) | ER Diagrams, Attributes, EER (Spec/Gen/Agg), Constraints, Subqueries, Joins, Views, Set Ops |
| **Unit 4** | Normalization & Transactions | 10 Qs | [`unit-4.md`](unit-4.md) | 1NF–5NF, Functional Dependencies, 3NF vs BCNF, Decompositions, ACID, States, Serializability, Recovery |
| **Unit 5** | Indexing, Optimization & Recovery | 9 Qs | [`unit-5.md`](unit-5.md) | B+ Trees, Primary/Secondary/Clustered/Hash Indexing, Tuning, Query Optimization, CBO, Backup/Recovery |
| **LAB** | Oracle 10g SQL Practicals | Lab Queries | [`LAB/`](LAB/) | Oracle 10g Lab Internal SQL queries, table schemas, and test suites |
| **Raw** | Source Documents & Notes | Reference Archives | [`raw/`](raw/) | University question banks, syllabus circulars, and reference materials |

---

## Unit-by-Unit Question Directory

### Unit 1 — Database System Concepts & Architecture
*Worked Answers:* [`unit-1.md`](unit-1.md) · *Section A (2M):* [`2-marks.md`](2-marks.md#unit-i-database-system-concepts-architecture)

1. [Three-Schema Architecture](unit-1.md#1-three-schema-architecture) — ANSI-SPARC architecture, external/conceptual/internal levels, data independence.
2. [DBMS Architecture](unit-1.md#2-dbms-architecture) — Detailed architectural diagram, query processor, storage manager, buffer manager.
3. [Database Users & Role of DBA](unit-1.md#3-database-users-and-the-role-of-the-dba) — Naive, application, sophisticated, specialized users; DBA roles & privileges.
4. [Comparison of Data Models](unit-1.md#4-comparison-of-data-models) — Relational, ER, Object-Oriented, and Semi-Structured (XML/JSON) data models.
5. [Steps in Database Design](unit-1.md#5-steps-in-database-design) — Requirements collection, conceptual design, logical design, physical design with University example.
6. [Parallel & Distributed Databases](unit-1.md#6-parallel-and-distributed-databases) — Shared-memory/disk/nothing architectures vs distributed autonomy, fragmentation & replication.
7. [NoSQL Databases](unit-1.md#7-nosql-databases) — Document, Key-Value, Columnar, Graph models; CAP theorem, comparison with RDBMS.
8. [Database System Environment & Client-Server Architecture](unit-1.md#8-database-system-environment-and-client-server-architecture) — Centralized, 2-Tier, and 3-Tier architectures.
9. [Levels of Data Abstraction & Data Independence](unit-1.md#9-levels-of-data-abstraction-and-data-independence) — Physical, Logical, View levels; Logical vs Physical data independence.
10. [Applications, Need & Purpose of DBMS; DBMS vs File System](unit-1.md#10-applications-need-and-purpose-of-dbms-dbms-vs-file-system) — Limitations of file systems; 8 core advantages of DBMS.

---

### Unit 2 — Relational Model, Relational Algebra & SQL
*Worked Answers:* [`unit-2.md`](unit-2.md) · *Section A (2M):* [`2-marks.md`](2-marks.md#unit-ii-relational-model-relational-algebra-sql)

1. [The Relational Model & Components](unit-2.md#1-the-relational-model-and-its-components) — Relations, attributes, tuples, domains, schemas, instances, degree, and cardinality.
2. [Types of Keys](unit-2.md#2-types-of-keys) — Super key, Candidate key, Primary key, Alternate key, Foreign key, Composite key, Surrogate key.
3. [Relational Algebra](unit-2.md#3-relational-algebra) — Fundamental operations (Select $\sigma$, Project $\pi$, Union $\cup$, Set Difference $-$, Cartesian Product $\times$, Rename $\rho$).
4. [DDL Commands](unit-2.md#4-ddl-commands) — `CREATE`, `ALTER`, `DROP`, `TRUNCATE`, `RENAME` with syntax and examples.
5. [DML Commands](unit-2.md#5-dml-commands) — `INSERT`, `UPDATE`, `DELETE`, `SELECT` with syntax and examples.
6. [SQL Functions](unit-2.md#6-sql-functions) — Scalar functions (String, Numeric, Date) and Aggregate functions (`COUNT`, `SUM`, `AVG`, `MIN`, `MAX`).
7. [GROUP BY & HAVING Clauses](unit-2.md#7-group-by-and-having-clauses) — Grouping rows, filtering groups, syntax, order of execution, `WHERE` vs `HAVING`.
8. [NULL Values & Handling NULLs](unit-2.md#8-null-values-and-handling-nulls) — Three-valued logic (3VL), `IS NULL`, `IS NOT NULL`, `NVL()`, `COALESCE()`.

---

### Unit 3 — ER Model, Constraints, Joins, Subqueries & Views
*Worked Answers:* [`unit-3.md`](unit-3.md) · *Section A (2M):* [`2-marks.md`](2-marks.md#unit-iii-er-model-constraints-joins-subqueries-views)

1. [The ER Model](unit-3.md#1-the-er-model) — Conceptual modeling, entities (strong/weak), attributes, relationships, standard ER notations table.
2. [Attributes & Relationships in ER Model](unit-3.md#2-attributes-and-relationships-in-the-er-model) — Simple/Composite, Single/Multivalued, Stored/Derived; Cardinality ratios ($1:1, 1:N, M:N$).
3. [Specialization, Generalization, Aggregation & Inheritance](unit-3.md#3-specialization-generalization-aggregation-and-inheritance) — Enhanced ER (EER) concepts, attribute/relationship inheritance.
4. [ER Diagrams: Library, Hospital & Banking Systems](unit-3.md#4-er-diagrams-library-hospital-and-banking-systems) — Detailed entity, relationship, and cardinality diagrams for all three systems.
5. [SQL Constraints (PK, FK, UNIQUE, NOT NULL, CHECK)](unit-3.md#5-sql-constraints-pk-fk-unique-not-null-check) — Table-level and column-level definitions with sample DDL.
6. [Integrity Constraints](unit-3.md#6-integrity-constraints) — Domain integrity, Entity integrity, Referential integrity with foreign key cascade options.
7. [Nested & Correlated Subqueries](unit-3.md#7-nested-and-correlated-subqueries) — Single-row, multi-row (`IN`, `ANY`, `ALL`), correlated subqueries with `EXISTS` and execution comparison.
8. [SQL Joins](unit-3.md#8-sql-joins) — `INNER JOIN`, `LEFT OUTER JOIN`, `RIGHT OUTER JOIN`, `FULL OUTER JOIN`, `CROSS JOIN`, `SELF JOIN`.
9. [SQL Views](unit-3.md#9-sql-views) — Creation, benefits, Updatable vs Non-Updatable views, `WITH CHECK OPTION`.
10. [Relational Set Operations](unit-3.md#10-relational-set-operations) — `UNION`, `UNION ALL`, `INTERSECT`, `MINUS` / `EXCEPT` with union compatibility rules.

---

### Unit 4 — Normalization, Transactions & Concurrency
*Worked Answers:* [`unit-4.md`](unit-4.md) · *Section A (2M):* [`2-marks.md`](2-marks.md#unit-iv-normalization-transactions-concurrency)

1. [Normalization, 1NF & 2NF](unit-4.md#1-normalization-1nf-2nf) — Insertion, Deletion, Update anomalies; First Normal Form (atomicity); Second Normal Form (partial dependency removal).
2. [4NF & 5NF](unit-4.md#2-4nf-5nf) — Multi-valued dependencies ($X \twoheadrightarrow Y$) and Fourth Normal Form; Join dependencies and Fifth Normal Form (PJNF).
3. [Functional Dependency & Types](unit-4.md#3-functional-dependency-types-of-dependencies) — Trivial, Non-trivial, Full, Partial, Transitive dependencies; Armstrong axioms.
4. [3NF vs BCNF](unit-4.md#4-3nf-vs-bcnf) — Third Normal Form (transitive dependency removal), Boyce-Codd Normal Form, detailed comparison table.
5. [Lossless Join & Dependency Preserving Decomposition](unit-4.md#5-lossless-join-dependency-preserving-decomposition) — Testing lossless join ($R_1 \cap R_2 \rightarrow R_1 \text{ or } R_2$), dependency preservation check.
6. [Transaction Management & ACID Properties](unit-4.md#6-transaction-management-acid-properties) — Atomicity, Consistency, Isolation, Durability with banking transfer examples.
7. [Transaction States](unit-4.md#7-transaction-states) — Active, Partially Committed, Committed, Failed, Aborted state transition diagram.
8. [Concurrent Execution & Serializability](unit-4.md#8-concurrent-execution-serializability) — Concurrency advantages; Dirty Read, Lost Update, Unrepeatable Read anomalies.
9. [Conflict & View Serializability](unit-4.md#9-conflict-view-serializability) — Conflicting operations, Precedence (Serialization) Graph, topological sort, View equivalence.
10. [Recoverability & Recovery Algorithms](unit-4.md#10-recoverability-recovery-algorithms) — Recoverable vs Cascadeless schedules; Write-Ahead Logging (WAL), Checkpoints, Deferred vs Immediate database modification.

---

### Unit 5 — Indexing, Query Optimization & Backup/Recovery
*Worked Answers:* [`unit-5.md`](unit-5.md) · *Section A (2M):* [`2-marks.md`](2-marks.md#unit-v-indexing-query-optimization-backuprecovery)

1. [B+ Tree](unit-5.md#1-b-tree) — Multi-level balanced index tree structure, search, insertion with leaf/internal split traces, deletion algorithm.
2. [Primary, Secondary & Clustered Indexes](unit-5.md#2-primary-secondary-clustered-indexes) — Ordered indexing, sparse vs dense index records, comparison table.
3. [Tree-Based vs Hash-Based Indexing](unit-5.md#3-tree-based-vs-hash-based-indexing) — Range queries vs exact-match lookups, space complexity, operational trade-offs.
4. [File Organization & Indexing](unit-5.md#4-file-organization-indexing) — Heap files, Sequential files, Hashed files; single-level vs multi-level indexing.
5. [Hash-Based Indexing](unit-5.md#5-hash-based-indexing) — Hash functions, bucket allocation, collision resolution via chaining, Static vs Dynamic (Extendible) hashing.
6. [Database Tuning Techniques](unit-5.md#6-database-tuning-techniques) — Schema tuning (denormalization), index tuning, query rewriting, buffer pool optimization.
7. [Query Optimization](unit-5.md#7-query-optimization) — Query processing pipeline, relational algebra equivalence rules, heuristic query optimization trees.
8. [Cost-Based Query Optimization](unit-5.md#8-cost-based-query-optimization) — Cost components (Disk I/O, CPU, memory), catalog statistics, selectivity estimation, execution plan evaluation.
9. [Database Backup & Recovery](unit-5.md#9-database-backup-recovery) — Full, Incremental, Differential backups; ARIES recovery algorithm (Analysis, Redo, Undo phases).

---

## Dark-Mode Visual Assets

Key conceptual diagrams located in [`figures/`](figures/):

- [`figures/unit3_q1_er_model.png`](figures/unit3_q1_er_model.png) — ER Model: Student–Enrolls–Course diagram & notations
- [`figures/unit3_q3_eer_concepts.png`](figures/unit3_q3_eer_concepts.png) — Specialization, Generalization, Inheritance, and Aggregation
- [`figures/unit3_q4_library_er.png`](figures/unit3_q4_library_er.png) — Library Management System ER diagram
- [`figures/unit3_q8_sql_joins.png`](figures/unit3_q8_sql_joins.png) — Venn diagrams for INNER, LEFT, RIGHT, FULL OUTER, and CROSS JOINs
- [`figures/unit4_q7_transaction_states.png`](figures/unit4_q7_transaction_states.png) — Transaction State Transition diagram
- [`figures/unit4_q9_precedence_graphs.png`](figures/unit4_q9_precedence_graphs.png) — Conflict vs. View Serializability precedence graphs
- [`figures/unit5_q1_bplus_tree.png`](figures/unit5_q1_bplus_tree.png) — $B^+$ Tree order-4 structure, overflow split, and deletion
- [`figures/unit5_q2_indexing_types.png`](figures/unit5_q2_indexing_types.png) — Primary (Sparse), Secondary (Dense), and Clustered indexing block mappings
- [`figures/unit5_q4_hash_indexing.png`](figures/unit5_q4_hash_indexing.png) — Hash-based indexing bucket mapping and overflow chaining
- [`figures/unit5_q5_query_optimization.png`](figures/unit5_q5_query_optimization.png) — Query optimization heuristic relational algebra tree transformation
