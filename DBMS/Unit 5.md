# UNIT 5 — Indexing ($B^+$ Trees, Primary/Secondary/Clustered, Hashing), Query Optimization & Backup/Recovery

---

## 1. Explain $B^+$ Tree and discuss search, insertion, and deletion algorithms with neat diagrams.

### Definition & Key Properties
A **$B^+$ Tree** is a balanced multi-level dynamic search tree used for database indexing:
1. **All Data Records in Leaves:** Internal nodes store **only search keys and child pointers** (routing keys). All actual data record pointers reside strictly in the **leaf nodes**.
2. **Sequential Leaf Linking:** All leaf nodes are linked together sequentially as a linked list for fast range queries.
3. **Balanced Height:** All leaf nodes appear at the **same depth**.
4. **Time Complexity:** Search, insertion, and deletion all run in **$O(\log_p N)$** disk block accesses.

---

### Structure of $B^+$ Tree (Order $p = 4$)

![B+ Tree Structure](figures/unit5_q1_bplus_tree.png)

---

### 1. Search Algorithm
1. Start at the root node.
2. At each internal node, compare search key $k$ with keys $K_1, K_2, \dots$:
   - If $k < K_1$, follow child pointer $P_0$.
   - If $K_i \le k < K_{i+1}$, follow pointer $P_i$.
   - If $k \ge K_m$, follow rightmost pointer $P_m$.
3. Repeat down to the leaf node.
4. Scan the leaf node for key $k$: return record pointer if found, else report **Not Found**.
- **Trace (Search for `25`):** Root `[20 | 40]` $\rightarrow$ $20 \le 25 < 40 \implies$ follow middle pointer to leaf `[20 | 25 | 30 | 35]` $\rightarrow$ locate `25`.

---

### 2. Insertion Algorithm
1. Traverse to the correct leaf node $L$ for key $k$.
2. Insert $k$ into leaf $L$ in sorted order.
3. **No Overflow:** If $L$ has space ($\le p - 1$ keys), insertion is complete.
4. **Leaf Overflow ($p$ keys):**
   - Split leaf $L$ into two halves: left leaf gets first $\lceil p/2 \rceil$ keys; right leaf gets remaining keys.
   - **Copy the smallest key of the right leaf UP** to the parent internal node, and update sibling pointers.
5. If an internal node overflows, split the internal node and **push (move) the middle key UP** to its parent.
- **Trace (Insert `28` into full leaf `[20 | 25 | 30 | 35]`):**
  - Leaf splits into `[20 | 25]` and `[28 | 30 | 35]`.
  - First key of right leaf (`28`) is **copied up** to the parent.

---

### 3. Deletion Algorithm
1. Locate leaf node $L$ containing key $k$ and remove $k$.
2. **No Underflow:** If $L$ has at least $\lceil (p-1)/2 \rceil$ keys, stop.
3. **Underflow (Borrow / Redistribution):** If a sibling leaf has extra keys, borrow a key from the sibling and update the separator key in the parent.
4. **Underflow (Merge / Coalesce):** If neither sibling can spare a key, merge $L$ with its sibling and delete the separator key from the parent.
- **Trace (Delete `45` from `[40 | 45 | 50]`):** Leaf becomes `[40 | 50]`. Occupancy is $\ge 2$, so no underflow occurs.

---

### Advantages of $B^+$ Tree
1. High fan-out keeps tree height very small (typically 3–4 levels).
2. Linked leaf nodes allow fast range queries (`WHERE Marks BETWEEN 40 AND 80`) without tree re-traversal.
3. Predictable $O(\log N)$ performance for all operations.

---

## 2. Explain Primary, Secondary, and Clustered Indexes with suitable examples.

An **Index** is an access structure $( \text{Search-Key}, \text{Pointer} )$ that avoids expensive Full Table Scans.

![Indexing Types](figures/unit5_q2_indexing_types.png)

---

### 1. Primary Index (Sparse Index)
- **Built on:** The **ordering Primary Key** of a sorted data file.
- **Type:** **Sparse Index** — stores **one index entry per disk block** (pointing to the *Block Anchor*, the first record of each block).
- **Example:** Data file is physically sorted by `Roll_No` (PK):
  - Index: `Key 1` $\rightarrow$ Block 1; `Key 3` $\rightarrow$ Block 2.

### 2. Secondary Index (Dense Index)
- **Built on:** A **non-ordering attribute** (candidate key or non-key) where the physical data file is **not sorted** on this attribute.
- **Type:** **Dense Index** — must store an entry for **every record** in the table (since matching rows are scattered across random blocks). Multiple secondary indexes are allowed per table.
- **Example:** Secondary index on `Department` for an `EMPLOYEE` table ordered by `Emp_ID`:
  - Index: `CSE` $\rightarrow$ `101, 103`; `ECE` $\rightarrow$ `102`; `IT` $\rightarrow$ `104`.

### 3. Clustered (Clustering) Index (Sparse Index)
- **Built on:** An **ordering non-key attribute** (clustering field) where records with the same value are physically grouped together on disk.
- **Type:** **Sparse Index** — stores **one index entry per distinct value** pointing to the first block containing that value.
- **Constraint:** At most **one** clustered/primary index per table (data can only be physically sorted one way).
- **Example:** `EMPLOYEE` records physically sorted and grouped by `Department`:
  - Index: `CSE` $\rightarrow$ First CSE block; `ECE` $\rightarrow$ First ECE block.

---

### Comparison: Primary vs. Secondary vs. Clustered Index

| Feature | Primary Index | Secondary Index | Clustered Index |
| :--- | :--- | :--- | :--- |
| **Ordering of Data File** | Sorted on Primary Key | **Not sorted** on index key | Sorted/grouped on non-key field |
| **Key Uniqueness** | **Unique** (Primary Key) | Unique or Non-Unique | **Non-Unique** (duplicate values grouped) |
| **Index Density** | **Sparse** (1 entry per block) | **Dense** (1 entry per record) | **Sparse** (1 entry per distinct value) |
| **Max per Table** | At most **1** | **Multiple** allowed | At most **1** |
| **Main Use** | Fast lookup & range scan on PK | Fast search on non-PK fields | Grouped retrieval by category |

---

## 3. Compare Tree-Based Indexing and Hash-Based Indexing.

### 1. Overview
- **Tree-Based Indexing ($B^+$ Tree):** Organizes search keys in a height-balanced search tree with keys stored in **sorted order**. Supports both exact-match and range queries.
- **Hash-Based Indexing:** Uses a hash function $h(k)$ to map keys directly to disk bucket addresses. Designed strictly for **$O(1)$ exact-match lookups**.

---

### 2. Comparison Table

| Point of Comparison | Tree-Based Indexing ($B^+$ Tree) | Hash-Based Indexing |
| :--- | :--- | :--- |
| **1. Underlying Structure** | Balanced multi-way search tree | Array of hash buckets + hash function $h(k)$ |
| **2. Key Ordering** | Keys stored in **sorted order** | Keys are **not sorted** (randomly scattered) |
| **3. Best Suited For** | **Range queries** and exact matches | Strictly **exact-match equality queries** (`=`) |
| **4. Range Query Cost** | **Efficient** via linked leaf nodes | **Inefficient** (requires scanning all buckets) |
| **5. Search Time** | $O(\log_p N)$ disk I/Os | **$O(1)$** average disk I/O |
| **6. Ordered Operations** | Directly supports `ORDER BY`, `MIN`, `MAX` | Does **not** support ordered traversal |
| **7. Handling Growth** | Dynamic node splitting (self-balancing) | Static has overflow chains; Dynamic uses directory split |

---

## 4. Explain Hash-Based Indexing.

### Definition & Working
**Hash-Based Indexing** uses a hash function $h(k)$ to compute the bucket address directly from the search key $k$:
1. User provides search key $k$ (`WHERE ID = 25`).
2. DBMS computes bucket address $B = h(k)$ (e.g., $k \bmod 5$).
3. The disk manager reads Bucket $B$ directly in **$O(1)$ constant time**.
4. The record pointer is retrieved.

![Hash Indexing](figures/unit5_q4_hash_indexing.png)

---

### Worked Example: $h(k) = k \bmod 5$
Insert keys **`20, 12, 27, 34`** into 5 buckets (`0` to `4`):
- $\text{Key } 20 \implies 20 \bmod 5 = 0 \longrightarrow \text{Bucket 0}$
- $\text{Key } 12 \implies 12 \bmod 5 = 2 \longrightarrow \text{Bucket 2}$
- $\text{Key } 27 \implies 27 \bmod 5 = 2 \longrightarrow \text{Bucket 2 (Collision with 12!)}$
- $\text{Key } 34 \implies 34 \bmod 5 = 4 \longrightarrow \text{Bucket 4}$

Because keys `12` and `27` both map to Bucket 2, a **collision** occurs and key `27` is stored in an **Overflow Bucket** linked to Bucket 2.

---

### Collision Handling Methods
1. **Overflow Chaining (Closed Addressing):** Links an overflow disk block to the primary bucket. This is the **standard method in DBMS**.
2. **Open Addressing:** Probes for the next available slot (Linear Probing, Quadratic Probing).

### Static vs. Dynamic Hashing
- **Static Hashing:** Number of primary buckets is fixed. As data grows, long overflow chains degrade performance.
- **Dynamic Hashing (Extendible / Linear Hashing):** Number of buckets grows and shrinks dynamically by splitting buckets and doubling a directory, avoiding long overflow chains.

---

## 5. What is Query Optimization? Explain the various Query Optimization Algorithms in detail with suitable examples.

### Definition
**Query Optimization** is the process of selecting the most efficient **Query Execution Plan (QEP)** to evaluate an SQL query with the **minimum cost** (disk I/O accesses, CPU time, and memory usage).

### Steps in Query Processing
$$\text{SQL Query} \longrightarrow \text{Parser (Relational Algebra Tree)} \longrightarrow \text{Optimizer (Plan Generation \& Costing)} \longrightarrow \text{Execution Engine}$$

![Query Optimization](figures/unit5_q5_query_optimization.png)

---

### Query Optimization Algorithms & Techniques

#### 1. Heuristic (Rule-Based) Optimization
Applies fixed equivalence transformation rules to the query tree without calculating detailed numeric costs:
- **Rule 1: Push Selections ($\sigma$) Down:** Filter rows before joins to reduce intermediate table size early.
- **Rule 2: Push Projections ($\pi$) Down:** Eliminate unused columns early to reduce tuple width.
- **Rule 3: Replace Cartesian Product ($\times$) with Join ($\bowtie$):**
  $$\sigma_{R.A = S.A}(R \times S) \equiv R \bowtie_{R.A = S.A} S$$
- **Example:** Filtering `Dept = 'CSE'` and `Marks > 80` **before** performing the join between `STUDENT` and `DEPARTMENT`.

#### 2. Cost-Based Optimization (CBO)
- Uses **system catalog statistics** (number of tuples $n_r$, block count $b_r$, distinct values $V(A,r)$, index height) to estimate the disk I/O cost of candidate execution plans and selects the cheapest plan.
- **Example:** Chooses a $B^+$ Tree Index Scan when selectivity is high ($< 5\%$ rows), but chooses a Sequential Table Scan when matching $> 50\%$ rows.

#### 3. Dynamic Programming Join Ordering (System-R)
- Finds the globally optimal join order for $R_1 \bowtie R_2 \bowtie \dots \bowtie R_n$ bottom-up.
- Evaluates best 2-table joins, then 3-table joins, saving optimal sub-plans (typically using left-deep trees to enable pipelining).

#### 4. Greedy Optimization
- For queries with many joins ($> 10$ tables) where dynamic programming is too slow, it greedily selects the pair of tables that produces the smallest immediate intermediate result at each step.

#### 5. Semantic Query Optimization
- Uses schema integrity constraints (`CHECK`, `NOT NULL`, foreign keys) to simplify or eliminate redundant query clauses.
- **Example:** If `CHECK (Age >= 18)` is enforced, the clause `WHERE Age > 15` is eliminated as always true.

---

## 6. What is Database Backup and Recovery? Explain the various Backup and Recovery Techniques in detail with suitable examples.

### Definitions
- **Database Backup:** Creating duplicate copies of data and log files on separate storage media to protect against data loss.
- **Database Recovery:** Restoring the database to a correct and consistent state after a crash or failure.

---

### 1. Types of Backup Techniques

| Backup Type | What is Copied? | Backup Speed | Storage Space | Restore Speed |
| :--- | :--- | :---: | :---: | :---: |
| **Full Backup** | The entire database | Slowest | Highest | **Fastest** (1 file needed) |
| **Incremental Backup** | Changes since the **most recent backup of any type** | **Fastest** | **Lowest** | Slowest (Full + all Incrementals) |
| **Differential Backup** | Cumulative changes since the **last Full backup** | Moderate | Moderate | **Fast** (Full + latest Differential) |
| **Mirror Backup** | Real-time continuous replica (hot standby) | Continuous | High ($2\times$) | **Instant failover** |

- **Weekly Schedule Example:**
  - *Sunday:* Full Backup.
  - *Monday, Tuesday:* Incremental backups copy only daily changes.
  - *Wednesday:* Differential backup copies all changes since Sunday.

---

### 2. Recovery Techniques in DBMS
1. **Log-Based Recovery (Write-Ahead Logging — WAL):**
   - Updates are recorded in a log on disk before modifying the database.
   - **`UNDO(Ti)`:** Rolls back incomplete transactions (restores old values).
   - **`REDO(Ti)`:** Re-applies committed transactions (writes new values).
2. **Deferred Update (No-Undo / Redo):**
   - Disk writes are deferred until `COMMIT`. If a crash occurs before commit, nothing was written to disk $\implies$ **No `UNDO` required**, only `REDO`.
3. **Immediate Update (Undo / Redo):**
   - Allows disk updates while the transaction is active. Requires both **`UNDO`** and **`REDO`** during recovery.
4. **Checkpointing:**
   - Periodically flushes memory buffers and writes a `<CHECKPOINT>` record to the log, reducing recovery time by scanning only from the latest checkpoint.
5. **Shadow Paging:**
   - Maintains a **Current Page Table** (copy-on-write) and a **Shadow Page Table** (original). On crash, simply revert to the shadow table $\implies$ No log undo/redo needed.

---

### Comparison: Backup vs. Recovery

| Feature | Database Backup | Database Recovery |
| :--- | :--- | :--- |
| **Meaning** | Copying data for safety | Restoring database to consistent state |
| **Nature** | **Proactive** (scheduled regularly) | **Reactive** (performed after failure) |
| **Output** | Archive files (`.bak`, snapshots) | An active, consistent database |
