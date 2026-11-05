# UNIT 5 — Indexing, Query Optimization & Backup/Recovery

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

---

## 1. B+ Tree

> **Question:** Explain B+ Tree and discuss search, insertion, and deletion algorithms with neat diagrams.

---

### Definition
A **B+ tree of order n** is a **balanced multi-way search tree** used as a disk-based index. All leaves lie at the **same depth**; **internal nodes store only keys and child pointers** (acting as a guide); **leaf nodes store all keys with record pointers** and are linked by **sibling pointers**. Every node except the root is at least half full. Because nodes are large disk blocks with high fan-out, the tree is very shallow, so a record is located in a few block reads.

```
                      [ 30 | 60 ]                  <- root (internal)
                     /     |     \
          [10|20]  ->  [30|40|50]  ->  [60|70|80]   <- leaves (linked)
            |             |               |
        record ptrs   record ptrs     record ptrs
```

### Properties
- An internal node has between ⌈n/2⌉ and n children (the root has at least 2) and one key fewer than its children.
- A leaf holds between ⌈(n−1)/2⌉ and n−1 keys.
- Height ≈ log of N to the base ⌈n/2⌉, so search cost is height + 1 block reads.
- The linked leaf level makes **range queries** and ordered scans efficient.

### Search Algorithm
1. Start at the root.
2. In each internal node, follow the pointer whose key range contains the search key K (K smaller than the first key → leftmost child; between Ki and Ki+1 → child i+1).
3. Repeat until a leaf is reached and scan it for K.
4. For a range query, locate the lower bound in a leaf and follow sibling pointers until the upper bound is passed.

### Insertion Algorithm
1. Search for the leaf in which K belongs.
2. If the leaf has space, insert K in sorted order.
3. If the leaf **overflows**, **split** it into two nodes and **copy up** the smallest key of the right node into the parent.
4. If the parent overflows, split it and **push up** the middle key (it is moved, not copied).
5. If the root splits, a new root is created and the tree grows by one level. The tree thus grows at the root, which keeps all leaves at the same depth.

### Deletion Algorithm
1. Locate the leaf and delete K.
2. If the leaf still has the minimum number of keys, stop (update the parent separator if the smallest key changed).
3. On **underflow**, first try **redistribution**: borrow a key from an adjacent sibling with spare keys and update the parent key.
4. If no sibling can lend, **merge** with a sibling and delete the separator key from the parent.
5. Merging can propagate upward; if the root is left with a single child, the tree height decreases.

### Example (order 4: max 3 keys, min 2 keys per leaf)
Insert 10, 20, 30 → leaf `[10|20|30]`. Insert 40 → overflow, split into `[10|20]` and `[30|40]`; copy 30 up.
```
        [30]
       /    \
  [10|20] -> [30|40]
```
Insert 50 → `[30|40|50]`. Insert 60 → overflow, split into `[30|40]` and `[50|60]`; copy 50 up.
```
          [30 | 50]
         /    |     \
  [10|20] -> [30|40] -> [50|60]
```
**Search 40:** at the root 40 ≥ 30 and < 50, so go to the middle leaf and find 40.

**Delete 40:** the middle leaf becomes `[30]`, which underflows (minimum is 2). Neither sibling has a spare key, so merge `[30]` with `[50|60]` into `[30|50|60]` and remove separator 50 from the root.
```
        [30]
       /    \
  [10|20] -> [30|50|60]
```

### Comparison with B Tree
| Parameter | B Tree | B+ Tree |
|---|---|---|
| Data pointers | In all nodes | Only in leaves |
| Key repetition | Each key once | Leaf keys repeated in internal nodes |
| Range queries | Slow (tree traversal) | Fast (linked leaves) |
| Internal fan-out | Lower | Higher |
| Search path | Variable depth | Always to a leaf (uniform) |
| Usage | Rare | Standard DBMS index |

---

## 2. Primary, Secondary & Clustered Indexes

> **Question:** Explain Primary, Secondary, and Clustered Indexes with suitable examples.

---

### Definition
An **index** is an auxiliary structure of (search key, pointer) entries that lets the DBMS locate records without scanning the whole file, just like the index of a book. Indexes are **dense** (an entry for every record/search-key value) or **sparse** (entries for only some values, requiring a sorted data file).

### Primary Index
Built on the **ordering key field** (usually the primary key) of a data file that is **physically sorted** on that field. It has one entry per **data block** (the key of the block's first record, the *block anchor*), so it is **sparse** and compact. Binary search on the index finds the correct block. A file can have **only one** primary index.

### Clustered Index
Built on a **non-key ordering field** (e.g., DeptNo) of a sorted file. Records with the same value are stored **together**, so range and group queries read only a few adjacent blocks. The index has one entry per distinct value pointing to the first block with that value. Since the file can be sorted in only one way, there is **only one** clustering index per file.

### Secondary Index
Built on a **non-ordering field** (e.g., Name, Email) of a file that is not sorted on it. It must be **dense**, with an entry for every record (or one entry per value pointing to a bucket of record pointers). A file can have **many** secondary indexes. Lookups are fast, but range scans touch scattered blocks and every insert or delete must update all indexes.

```
PRIMARY (sparse)             SECONDARY (dense)
Index   Data blocks          Index(Name)   Data file (unsorted by Name)
[101] -> 101,102,103         [Asha] -----> record 7
[104] -> 104,105,106         [Ravi] -----> record 2
[107] -> 107,108,109         [Sita] -----> record 5
```

### Example
`STUDENT(RollNo, Name, Dept)` is stored sorted on RollNo with 3 records per block.
- **Primary index lookup** of RollNo = 105: binary search on entries 101, 104, 107 finds the largest entry ≤ 105, which is 104 → block B2 → scan the block. This costs one index access plus one data block.
- **Secondary index lookup** of Name = 'Ravi' jumps directly to record 2 even though the file is not sorted by Name.

```sql
CREATE INDEX idx_name ON STUDENT(Name);               -- secondary index
CREATE CLUSTERED INDEX idx_dept ON STUDENT(Dept);     -- clustered index (SQL Server)
```

### Comparison
| Parameter | Primary | Clustered | Secondary |
|---|---|---|---|
| Search field | Ordering key | Ordering non-key | Non-ordering field |
| Data file sorted? | Yes | Yes | No |
| Density | Sparse | Sparse | Dense |
| Number per file | One | One | Many |
| Range queries | Excellent | Excellent | Poor |
| Update cost | Moderate | Moderate | High |
| Example field | RollNo | DeptNo | Name |

---

## 3. Tree-Based vs Hash-Based Indexing

> **Question:** Compare Tree-Based Indexing and Hash-Based Indexing.

---

### Definition
- **Tree-based indexing** (ISAM, B tree, B+ tree) keeps search keys in **sorted order** within a balanced hierarchy of nodes.
- **Hash-based indexing** applies a **hash function h(K)** to the search key to compute the **bucket** where the record or its pointer is stored.

```
Tree:  root -> internal -> leaf -> record        (about log N block reads)
Hash:  key --h(K)--> bucket -> [records]         (about 1 block read)
```

### Explanation
Tree indexes support **equality, range, prefix and ordered** retrieval, and they provide sorted output for `ORDER BY` for free. Their cost is O(log N) block reads, and they remain balanced under inserts and deletes through node splitting and merging. Hash indexes find a record in about **one bucket access** for **equality** searches, but because the hash function scatters neighbouring keys into unrelated buckets, they cannot handle range queries. Static hashing also suffers from overflow chains as data grows, and a poor hash function causes skew.

### Example
Table `EMP(EmpID, Salary)`:
- `SELECT * FROM EMP WHERE EmpID = 4521;` — a hash index reaches the bucket in about one I/O, whereas a B+ tree needs about three.
- `SELECT * FROM EMP WHERE Salary BETWEEN 30000 AND 50000;` — a B+ tree locates 30000 and follows leaf links; a hash index is useless, since 30001 and 30002 fall in unrelated buckets, forcing a full scan.

### Comparison
| Parameter | Tree-Based (B+ Tree) | Hash-Based |
|---|---|---|
| Lookup cost | O(log N) | O(1) on average |
| Equality search | Good | Best |
| Range search | Excellent | Not supported |
| Sorted output | Yes | No |
| Dynamic growth | Handled by split/merge | Needs overflow chains or rehashing |
| Space utilisation | Nodes at least half full | Depends on bucket load |
| Typical use | General purpose, range queries | Exact-match lookups, hash joins |

---

## 4. File Organization & Indexing

> **Question:** Discuss File Organization and Indexing.

---

### Definition
**File organization** is the way records of a file are arranged in disk blocks; it decides how records are inserted, searched and deleted. **Indexing** adds **access paths** (search key + pointer) on top of a file organization to reduce disk I/O.

```
Heap:    [r5][r1][r9][r2] ...       (insertion order)
Sorted:  [r1][r2][r5][r9] ...       (ordered by key)
Hashed:  h(key) -> bucket -> [records]
Indexed: Index [key|ptr] ---------> Data file
```

### File Organizations
1. **Heap (pile) file:** records are appended at the end. Insertion is very fast, but search needs a full scan; suited to bulk loading.
2. **Sequential (sorted) file:** records are ordered on a key, so binary search and range queries are efficient. Insertion is costly because records must be kept in order (usually an overflow area is used).
3. **Hash file:** the hash of the key selects the block. Equality search is very fast; there is no ordering.
4. **Clustered file:** records of related tables (e.g., `DEPT` and `EMP`) are stored together to speed up joins.
5. **Indexed sequential (ISAM):** a sorted file combined with an index.

### Indexing
Index types include **single-level** and **multi-level** indexes (an index on the index, leading to B+ trees), **dense** and **sparse** indexes, and **primary, secondary and clustered** indexes. Indexes make reads faster but add **storage cost and slower inserts, updates and deletes**, so only columns used in `WHERE`, `JOIN` and `ORDER BY` should be indexed.

### Example
`STUDENT` has 10,000 records, 10 per block, giving 1000 blocks.
- Heap file search: up to 1000 block reads.
- Sorted file with binary search: about log₂ 1000 ≈ 10 reads.
- B+ tree index with fan-out 100: about 2 index reads + 1 data read = 3 reads.
- Hash file: about 1–2 reads.

```sql
CREATE INDEX idx_roll ON STUDENT(RollNo);
```

### Comparison
| Organization | Insert | Equality search | Range search | Best suited for |
|---|---|---|---|---|
| Heap | Fast | Slow | Slow | Bulk loading |
| Sorted | Slow | Fast (binary search) | Fast | Range scans |
| Hashed | Fast | Fastest | Slow | Exact match |
| Indexed | Moderate | Fast | Fast | General purpose |

---

## 5. Hash-Based Indexing

> **Question:** Explain Hash-Based Indexing.

---

### Definition
**Hash-based indexing** organises records into **buckets** (one or more disk blocks), where the bucket for a search key K is computed by a **hash function h(K)**. It is ideal for **equality** searches. The main forms are **static hashing**, **extendible hashing** and **linear hashing**.

```
 h(K) = K mod 4
 [0] -> 8, 12
 [1] -> 5, 9 -> (overflow) 13
 [2] -> 6
 [3] -> 7, 11
```

### Static Hashing
The number of buckets M is **fixed** and the bucket is h(K) = K mod M. When a bucket is full, extra records go to an **overflow chain**. If the file grows a lot, long chains degrade performance; if it shrinks, space is wasted. Changing M needs a complete rehash of the file.

### Extendible Hashing
A **directory** of 2^d pointers (d = **global depth**) is indexed by the first d bits of h(K); each bucket has a **local depth**. When a bucket overflows:
- if its local depth < global depth, the bucket is simply split and its entries redistributed;
- if local depth = global depth, the **directory is doubled** (d becomes d+1) and then the bucket is split.

A lookup needs at most two I/Os (directory + bucket) and there are no long overflow chains.

### Linear Hashing
Buckets are added **one at a time** in round-robin order using a **split pointer**, with no directory. A family of hash functions h_i(K) = K mod (2^i · N) is used. It grows gradually and smoothly with the data.

### Example
Static hashing with M = 4 and bucket capacity 2; insert 5, 9, 13, 6, 7, 8:
- 5 mod 4 = 1 → B1; 9 mod 4 = 1 → B1 (now full); 13 mod 4 = 1 → B1 is full, so an **overflow block** is attached.
- 6 → B2; 7 → B3; 8 → B0.

**Search 13:** h(13) = 1 → B1 → not in the primary block → follow the overflow pointer → found.

**Extendible hashing:** with global depth 1 and buckets 0 and 1, an overflow in bucket 1 (local depth 1 = global depth) doubles the directory to depth 2 (00, 01, 10, 11) and splits bucket 1 into buckets 10 and 11, while entries 00 and 01 continue to share bucket 0.

### Limitations
Hash indexes do not support range queries or ordering, and a poorly chosen hash function causes skewed buckets.

### Comparison
| Feature | Static | Extendible | Linear |
|---|---|---|---|
| Number of buckets | Fixed | Grows via directory | Grows via split pointer |
| Overflow handling | Overflow chains | Rare | Temporary chains |
| Directory | None | Yes | None |
| Reorganisation | Full rehash | Split one bucket | Split next bucket |

---

## 6. Database Tuning Techniques

> **Question:** Evaluate various database tuning techniques for improving database performance.

---

### Definition
**Database tuning** is the process of adjusting the **physical design, queries and configuration** of a database system to improve **throughput and response time** for a given workload. It is iterative: monitor the workload, find the bottleneck, apply one change, measure, and repeat.

```
Monitor workload -> Find bottleneck -> Apply tuning -> Measure -> repeat
Layers: Query | Schema | Index | DBMS configuration | OS / Hardware
```

### Tuning Techniques
1. **Index tuning:** create indexes on columns used in `WHERE`, `JOIN` and `ORDER BY`; use composite and covering indexes; remove unused or duplicate indexes because they slow writes. Choose B+ trees for range queries and hash indexes for equality.
2. **Query tuning:** avoid `SELECT *`; do not apply functions to indexed columns (for example `YEAR(date) = 2025` prevents index use); prefer joins or `EXISTS` over inefficient subqueries; push selections early; read the plan with `EXPLAIN`.
3. **Schema tuning:** normalise to remove redundancy, but selectively **denormalise** heavily read tables to avoid costly joins; **partition** large tables horizontally or vertically; choose compact data types.
4. **Transaction and concurrency tuning:** keep transactions short, use row-level locking, access items in a consistent order to avoid deadlocks, and use a lower isolation level where safe.
5. **Memory and configuration tuning:** enlarge the **buffer pool**, set suitable sort/work memory, use connection pooling and keep optimizer **statistics** up to date.
6. **Hardware and storage tuning:** use SSDs, RAID, a separate disk for the log, more RAM and parallel processing; use **caching** and **materialised views** for repeated aggregations.

### Example
Slow query on 10 million rows:
```sql
SELECT * FROM ORDERS WHERE YEAR(OrderDate) = 2025;
```
The function on `OrderDate` blocks the index, causing a full table scan. After tuning:
```sql
CREATE INDEX idx_orderdate ON ORDERS(OrderDate);
SELECT OrderID, Amount FROM ORDERS
WHERE OrderDate >= '2025-01-01' AND OrderDate < '2026-01-01';
```
`EXPLAIN` now shows an index range scan, reading only the needed columns and the matching range.

### Trade-offs
| Technique | Benefit | Cost / Risk |
|---|---|---|
| Indexing | Faster reads | Slower writes, extra space |
| Denormalisation | Fewer joins | Redundancy, anomalies |
| Partitioning | Smaller scans | Added complexity |
| Buffer / caching | Fewer disk I/Os | More memory |
| Short transactions | Less lock contention | Application redesign |

---

## 7. Query Optimization

> **Question:** What is Query Optimization? Explain the various Query Optimization Algorithms in detail with suitable examples.

---

### Definition
**Query optimization** is the process by which the DBMS chooses the **most efficient execution plan** for a query from many **equivalent** relational-algebra expressions and access methods, so as to minimise cost (mainly disk I/O and CPU time) without changing the result.

```
SQL -> Parser -> Relational Algebra Tree -> OPTIMIZER -> Execution Plan -> Executor
                                 (heuristic rules + cost model + statistics)
```

### Heuristic (Rule-Based) Optimization
The query is converted to a **query tree** and transformation rules that nearly always lower cost are applied:
1. **Perform selections early** (push σ down) to shrink the inputs of later operations.
2. **Perform projections early** to discard unneeded attributes.
3. **Break conjunctive selections** `σ(c1 ∧ c2)` into a cascade of single selections.
4. **Replace Cartesian product followed by a selection with a join.**
5. **Reorder joins** so that the most restrictive joins (smallest results) execute first.
6. Use the **commutativity and associativity** of ⋈, ∪ and ∩.

### Cost-Based Optimization
Several candidate plans are generated and the one with the lowest estimated cost, computed from catalog statistics, is chosen (detailed in the next question).

### Join-Order Algorithms
- **Dynamic programming (System R):** finds the best plan for each subset of relations, considering left-deep join trees only.
- **Greedy:** repeatedly picks the cheapest next join.
- **Randomised / genetic:** used when the number of joins is large.

### Algorithms for Individual Operators
- **Selection:** linear scan, binary search on a sorted file, or index scan.
- **Join:** **nested-loop**, **block nested-loop**, **index nested-loop**, **sort-merge** and **hash join**; the choice depends on relation sizes, sort order and available indexes.

### Example
```sql
SELECT Name FROM STUDENT S, ENROLL E
WHERE S.RollNo = E.RollNo AND E.CID = 'C1';
```
- **Initial tree:** π_Name( σ_{S.RollNo=E.RollNo ∧ CID='C1'}( STUDENT × ENROLL ) ).
- **Step 1:** push `σ_{CID='C1'}` onto ENROLL, reducing (say) 100,000 rows to about 500.
- **Step 2:** replace the product plus join condition with a join.
- **Step 3:** project early, keeping only RollNo from ENROLL and (RollNo, Name) from STUDENT.
- **Final plan:** π_Name( STUDENT ⋈_{RollNo} π_{RollNo}(σ_{CID='C1'}(ENROLL)) ) using an index nested-loop join on `STUDENT.RollNo`.

The join now handles about 500 rows instead of forming 100,000 × |STUDENT| combinations.

### Comparison
| Strategy | Basis | Advantage | Disadvantage |
|---|---|---|---|
| Heuristic | Fixed rules | Fast and simple | May miss the best plan |
| Cost-based | Statistics | Better plans | Costly to compute |
| Dynamic programming | Subsets of relations | Optimal left-deep plan | Exponential time |
| Greedy / randomised | Heuristics | Scales to many joins | No optimality guarantee |

---

## 8. Cost-Based Query Optimization

> **Question:** What is Cost-Based Query Optimization? Explain its working process, cost estimation techniques, and execution plan selection with a suitable example.

---

### Definition
**Cost-Based Optimization (CBO)** generates multiple candidate **execution plans** for a query, **estimates the cost** of each using **catalog statistics** and a **cost model** (disk I/O, CPU and communication), and selects the plan with the **lowest estimated cost**.

```
Query -> Plan Generator (P1, P2, P3 ...)
              |
        Cost Estimator <-- Catalog statistics (n_r, b_r, V(A,r), indexes, histograms)
              |
        Choose minimum-cost plan -> Executor
```

### Working Process
1. Parse the query and convert it to relational algebra.
2. Apply heuristic transformations to obtain logically equivalent expressions.
3. For each expression, enumerate physical alternatives (scan method, join algorithm, join order).
4. Estimate the size and cost of every operator bottom-up.
5. Choose the cheapest complete plan, using **dynamic programming** to avoid exponential search.
6. Execute the plan (and optionally cache it).

### Cost Factors in CBO

The total cost of an execution plan is computed based on:
1. **Disk I/O Cost (Primary Factor):** Number of disk blocks transferred to and from secondary storage.
2. **CPU Cost:** Processing cycles spent evaluating predicates, sorting, and hashing records in memory.
3. **Memory / Buffer Cost:** Amount of RAM required for hash tables, sorting runs, or intermediate buffers.

### Catalog Statistics Used

The DBMS catalog (data dictionary) maintains statistical metadata used by the cost estimator:
- $n_r$: Total number of tuples (records) in relation $r$.
- $b_r$: Total number of disk blocks occupied by relation $r$.
- $V(A, r)$: Number of distinct values for attribute $A$ in relation $r$ (used to estimate selectivity).
- **Index Metadata:** Heights of B+ trees, clustering status, and value histograms.

### Plan Evaluation & Access Paths

For any query, the optimizer compares physical evaluation alternatives:
- **Table Access:** Choosing between a **Full Table Scan** (efficient when retrieving a large fraction of rows) vs an **Index Scan** (efficient when selecting few specific records).
- **Join Algorithm:** Selecting between **Nested-Loop Join** (ideal for small inputs or with an index), **Sort-Merge Join** (ideal when tables are already sorted on the join key), and **Hash Join** (efficient for large, unindexed relations).
- **Join Ordering:** Arranging joins so the most selective tables are evaluated first, minimizing the size of intermediate results.

### Practical Example

Consider the query:
```sql
SELECT * FROM EMP E, DEPT D 
WHERE E.DNo = D.DNo AND D.Loc = 'Hyderabad';
```

- **Candidate Plan A (Naive Plan):** Performs a full table scan on both `EMP` and `DEPT`, computes a full Cartesian product, and checks conditions row-by-row. Extremely slow with massive disk I/O.
- **Candidate Plan B (Optimized Cost Plan):**
  1. Filters `DEPT` on `Loc = 'Hyderabad'` first (reduces search to only matching department records).
  2. Uses an index on `EMP.DNo` to look up only relevant employees directly, avoiding a full table scan of `EMP`.
- **Optimizer Decision:** The CBO calculates the estimated block transfers for both plans and automatically dispatches **Plan B**.

### Heuristic vs Cost-Based Optimization

| Feature | Heuristic (Rule-Based) Optimization | Cost-Based Optimization (CBO) |
|---|---|---|
| **Decision Basis** | Fixed transformation rules (e.g., push $\sigma$ down) | Mathematical cost estimation using catalog statistics |
| **Catalog Reliance** | Does not require statistics | Heavily relies on accurate catalog statistics |
| **Optimization Time** | Very fast (constant rule checks) | Higher (evaluates multiple candidate plans) |
| **Plan Quality** | Reasonable, but may miss the optimal execution path | Selects the most optimal physical access plan |
| **System Adoption** | Early relational systems | All modern DBMS engines (Oracle, PostgreSQL, MySQL) |

---

## 9. Database Backup & Recovery

> **Question:** What is Database Backup and Recovery? Explain the various Backup and Recovery Techniques in detail with suitable examples.

---

### Definition
**Database backup** is the process of making copies of the data and logs so that they can be used if the original is lost or damaged. **Database recovery** is restoring the database to a **correct, consistent state** after a failure, preserving the **atomicity and durability** of transactions.

### Types of Failure
- **Transaction failure:** logical error or deadlock affecting a single transaction.
- **System crash:** power or OS failure; memory contents are lost but the disk survives.
- **Media failure:** disk crash or corruption; stored data is lost.
- **Disaster:** fire, flood or theft of the whole site.

### Backup Techniques
- **Full backup:** a complete copy of the database; simple and fast to restore but large and slow to take.
- **Incremental backup:** only data changed since the *last backup of any kind*; small and quick, but restoring needs the full backup plus all increments in order.
- **Differential backup:** data changed since the *last full backup*; restoring needs the full backup plus only the latest differential.
- **Hot (online) vs cold (offline) backup:** taken while the database is running or shut down.
- **Logical vs physical backup:** an SQL export/dump versus copies of the data files.
- **Archive logs, replication, mirroring, RAID and standby servers** protect against media failure and disasters.

```
Sun: FULL -- Mon: INCR -- Tue: INCR -- Wed: INCR -- Thu: CRASH
Restore: FULL + INCR(Mon, Tue, Wed) + replay archived log (roll forward)
```

### Recovery Techniques
1. **Log-based recovery with write-ahead logging (WAL):** every update is first recorded as `<T, X, old, new>`. *Deferred update* needs only redo; *immediate update* needs both undo and redo.
2. **Checkpointing:** periodic flush of buffers and a checkpoint record, so recovery scans the log only from the last checkpoint.
3. **Shadow paging:** a shadow page table is kept untouched while updates go to a current table; commit switches the pointer, so no undo or redo is needed.
4. **ARIES:** WAL-based algorithm with Analysis, Redo and Undo phases.
5. **Media recovery:** restore the latest full backup, apply incremental or differential backups, then **roll forward** the archived logs to the failure point (**point-in-time recovery**).

### Examples
**Crash recovery.** Log:
`<T1,start> <T1,A,50,60> <T1,commit> <checkpoint> <T2,start> <T2,B,10,20> <T3,start> <T3,C,5,8> <T3,commit> CRASH`
- T1 committed before the checkpoint, so its changes are already on disk.
- T2 has no commit record → **UNDO**: restore B = 10.
- T3 committed after the checkpoint → **REDO**: set C = 8.

**Media recovery.** A full backup is taken on Sunday and incrementals on Monday to Wednesday; the disk fails on Thursday. Restore the Sunday full backup, apply the Monday, Tuesday and Wednesday increments, then roll forward the archived logs to the time of failure. No committed work is lost.

```sql
BACKUP DATABASE College TO DISK = 'full.bak';
BACKUP DATABASE College TO DISK = 'diff.bak' WITH DIFFERENTIAL;
RESTORE DATABASE College FROM DISK = 'full.bak' WITH NORECOVERY;
```

### Comparison of Backup Types
| Backup type | Size | Backup speed | Restore speed |
|---|---|---|---|
| Full | Large | Slow | Fast |
| Incremental | Small | Fast | Slow |
| Differential | Medium | Medium | Medium |
