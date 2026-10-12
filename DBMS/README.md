# Database Management Systems (2501IT05) — Study Hub & Exam Notes

*(Common to CSE, IT, AIML & CSE (DS) — Aditya University)*

Detailed exam-ready questions, worked answers, SQL implementations, and dark-mode diagrams organized by unit.

---

## Map / Contents

| File | Contents |
|---|---|
| [`Important Questions.md`](Important%20Questions.md) | Complete Unit-I to Unit-V Important Questions (IE-1 & IE-2) with direct section mapping |
| [`Unit 3.md`](Unit%203.md) | **Worked Exam Answers:** ER Model, Attributes & Relationships, Specialization/Generalization/Aggregation/Inheritance, Library ER Diagram, SQL Constraints (`PK`, `FK`, `UNIQUE`, `NOT NULL`, `CHECK`), Integrity Constraints, Nested & Correlated Subqueries, SQL Joins, Views (Updatable & Non-Updatable), and Relational Set Operations |
| [`Unit 4.md`](Unit%204.md) | **Worked Exam Answers:** Purpose of Normalization, 1NF & 2NF, 4NF & 5NF, Functional Dependencies & Types, 3NF vs. BCNF, Lossless Join & Dependency Preservation, Transaction Management & ACID Properties, Transaction States Diagram, Conflict vs. View Serializability, Precedence Graphs, Recoverability & Recovery Algorithms, and Concurrent Execution |
| [`Unit 5.md`](Unit%205.md) | **Worked Exam Answers:** $B^+$ Tree Search/Insertion/Deletion Algorithms & Split Traces, Primary/Secondary/Clustered Indexes, Tree vs. Hash Indexing, Hash-Based Indexing & Collision Chaining, Query Optimization Algorithms & Heuristic Tree Transformations, and Database Backup & Recovery Techniques |
| [`Database Design Challenge.md`](Database%20Design%20Challenge.md) | 20 Challenge Domains, 5-Mark Assessment Rubric, and 2 Complete Worked Case Studies with Dark-Mode ER Diagrams (University Academic Management & Mobile Service Center System) |
| [`LAB/`](LAB/) | Oracle 10g Lab Internal SQL queries, table setups, independent test suites, and answers |
| [`raw/`](raw/) | Original question papers, handwritten lecture notes, design challenge docx, and student presentation PPT |

---

## Question-to-Answer Mapping

### UNIT-I (Reference Notes in [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf))

| Q# | Topic | Reference Resource |
| :---: | :--- | :--- |
| **Q1** | Three-Schema Architecture & Data Independence | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q2** | DBMS Architecture & Component Functions | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q3** | Types of Database Users & DBA Responsibilities | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q4** | Comparison of Relational, ER, Object-Oriented, and Semi-Structured Models | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q5** | Steps Involved in Database Design | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q6** | Parallel Databases vs. Distributed Databases | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |
| **Q7** | Client-Server Architecture in DBMS | [`raw/UNIT - 1.pdf`](raw/UNIT%20-%201.pdf) |

---

### UNIT-II (Reference Notes in [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf))

| Q# | Topic | Reference Resource |
| :---: | :--- | :--- |
| **Q1** | Relational Model & Components with Examples | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |
| **Q2** | Types of Keys in Relational Model (Super, Candidate, Primary, Alternate, Foreign) | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |
| **Q3** | DDL Commands with Syntax & Examples (`CREATE`, `ALTER`, `DROP`, `TRUNCATE`) | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |
| **Q4** | DML Commands with Syntax & Examples (`INSERT`, `UPDATE`, `DELETE`, `SELECT`) | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |
| **Q5** | SQL Built-in Functions (String, Numeric, Date/Time) | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |
| **Q6** | Aggregate Functions with `GROUP BY` and `HAVING` Clauses | [`raw/DBMS_Q4_Aggregate_Functions_Expanded.pdf`](raw/DBMS_Q4_Aggregate_Functions_Expanded.pdf) |
| **Q7** | Importance and Handling of `NULL` Values in SQL | [`raw/UNIT 2.pdf`](raw/UNIT%202.pdf) |

---

### UNIT-III (Worked Answers in [`Unit 3.md`](Unit%203.md))

| Q# | Topic | Answer Section |
| :---: | :--- | :--- |
| **Q1** | ER Model: Components, Symbols, and Diagrams | [`Unit 3.md` — §1](Unit%203.md#1-explain-the-er-model-with-neat-diagrams) |
| **Q2** | Types of Attributes & Relationships in ER Model | [`Unit 3.md` — §2](Unit%203.md#2-explain-different-types-of-attributes-and-relationships-in-the-er-model) |
| **Q3** | Specialization, Generalization, Aggregation, and Inheritance | [`Unit 3.md` — §3](Unit%203.md#3-explain-specialization-generalization-aggregation-and-inheritance-with-examples) |
| **Q4** | ER Diagram: Library, Hospital, and Banking Systems | [`Unit 3.md` — §4](Unit%203.md#4-draw-an-er-diagram-for-a-libraryhospitalbanking-system) |
| **Q5** | SQL Constraints (`PRIMARY KEY`, `FOREIGN KEY`, `UNIQUE`, `NOT NULL`, `CHECK`) | [`Unit 3.md` — §5](Unit%203.md#5-explain-the-implementation-of-primary-key-foreign-key-unique-not-null-and-check-constraints-in-sql-with-suitable-examples) |
| **Q6** | Integrity Constraints (Entity, Referential, Domain Integrity) | [`Unit 3.md` — §6](Unit%203.md#6-what-are-integrity-constraints-explain-entity-integrity-referential-integrity-and-domain-integrity-constraints-with-suitable-sql-examples) |
| **Q7** | Nested vs. Correlated Subqueries with Execution Flow & SQL Examples | [`Unit 3.md` — §7](Unit%203.md#7-explain-nested-and-correlated-subqueries-with-examples) |
| **Q8** | SQL Joins (`INNER`, `LEFT`, `RIGHT`, `FULL OUTER`, `CROSS`, `SELF JOIN`) | [`Unit 3.md` — §8](Unit%203.md#8-explain-different-types-of-sql-joins-with-suitable-examples) |
| **Q9** | SQL Views: Updatable vs. Non-Updatable Views & Materialized Views | [`Unit 3.md` — §9](Unit%203.md#9-explain-sql-views-differentiate-updatable-and-non-updatable-views-with-examples) |
| **Q10** | Relational Set Operations (`UNION`, `INTERSECT`, `MINUS`, `CROSS JOIN`, `COMPLEMENT`) | [`Unit 3.md` — §10](Unit%203.md#10-explain-relational-set-operations-with-suitable-examples) |

---

### UNIT-IV (Worked Answers in [`Unit 4.md`](Unit%204.md))

| Q# | Topic | Answer Section |
| :---: | :--- | :--- |
| **Q1** | Purpose of Normalization & 1NF, 2NF Decompositions | [`Unit 4.md` — §1](Unit%204.md#1-explain-the-purpose-of-normalization-and-discuss-1nf-2nf-with-suitable-examples) |
| **Q2** | 4NF (Multi-Valued Dependencies) and 5NF (Join Dependencies) | [`Unit 4.md` — §2](Unit%204.md#2-explain-4nf-and-5nf-with-suitable-examples) |
| **Q3** | Functional Dependencies & Types (Trivial, Non-Trivial, Full, Partial, Transitive) | [`Unit 4.md` — §3](Unit%204.md#3-explain-functional-dependency-and-different-types-of-dependencies-with-examples) |
| **Q4** | Comparison of 3NF and BCNF with Worked Decomposition Traces | [`Unit 4.md` — §4](Unit%204.md#4-compare-3nf-and-bcnf-with-suitable-examples) |
| **Q5** | Lossless Join and Dependency Preserving Decomposition | [`Unit 4.md` — §5](Unit%204.md#5-explain-lossless-join-and-dependency-preserving-decomposition) |
| **Q6** | Transaction Management & ACID Properties with Bank Transfer Walkthrough | [`Unit 4.md` — §6](Unit%204.md#6-explain-transaction-management-and-acid-properties-with-examples) |
| **Q7** | Transaction States with State Transition Diagram | [`Unit 4.md` — §7](Unit%204.md#7-explain-transaction-states-with-a-neat-state-transition-diagram) |
| **Q8** | Conflict Serializability vs. View Serializability & Precedence Graphs | [`Unit 4.md` — §8](Unit%204.md#8-discuss-conflict-serializability-and-view-serializability-with-suitable-examples) |
| **Q9** | Recoverability Types & Recovery Algorithms (WAL, Deferred/Immediate, Checkpoints) | [`Unit 4.md` — §9](Unit%204.md#9-explain-recoverability-and-recovery-algorithms-in-dbms) |
| **Q10** | Concurrent Execution Benefits & Serializable Schedules | [`Unit 4.md` — §10](Unit%204.md#10-explain-concurrent-execution-and-serializability-with-examples) |

---

### UNIT-5 (Worked Answers in [`Unit 5.md`](Unit%205.md))

| Q# | Topic | Answer Section |
| :---: | :--- | :--- |
| **Q1** | $B^+$ Tree Structure & Search, Insertion, Deletion Algorithms | [`Unit 5.md` — §1](Unit%205.md#1-explain-b-tree-and-discuss-search-insertion-and-deletion-algorithms-with-neat-diagrams) |
| **Q2** | Primary, Secondary, and Clustered Indexes Block Mapping | [`Unit 5.md` — §2](Unit%205.md#2-explain-primary-secondary-and-clustered-indexes-with-suitable-examples) |
| **Q3** | Comparison of Tree-Based Indexing and Hash-Based Indexing | [`Unit 5.md` — §3](Unit%205.md#3-compare-tree-based-indexing-and-hash-based-indexing) |
| **Q4** | Hash-Based Indexing: Working, Modulo Example & Collision Chaining | [`Unit 5.md` — §4](Unit%205.md#4-explain-hash-based-indexing) |
| **Q5** | Query Optimization: Heuristic Tree Transformations, CBO, DP & Greedy Join | [`Unit 5.md` — §5](Unit%205.md#5-what-is-query-optimization-explain-the-various-query-optimization-algorithms-in-detail-with-suitable-examples) |
| **Q6** | Database Backup (Full, Incremental, Differential) & Recovery Techniques | [`Unit 5.md` — §6](Unit%205.md#6-what-is-database-backup-and-recovery-explain-the-various-backup-and-recovery-techniques-in-detail-with-suitable-examples) |

---

## Figures Directory

All diagrams are rendered in **dark mode** (`#0d1117` background) to match dark theme study environments:

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
- [`figures/ddc_university_er_dark.png`](figures/ddc_university_er_dark.png) — University Academic Management System ER model
- [`figures/ddc_mobile_service_er.png`](figures/ddc_mobile_service_er.png) — Mobile Service Center System ER model
