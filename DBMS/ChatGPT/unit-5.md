# UNIT 5 — Indexing, Query Optimization & Backup/Recovery

> **Course Code:** `2501IT05` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section B (8-Mark Long Questions — Official Question Bank)  
> **Master Questions Index:** [`questions.md`](questions.md) · [`Important Questions.md`](Important%20Questions.md)

## Q1. B+ Tree and Its Operations

> **Question:** Explain B+ Tree and discuss search, insertion, and deletion algorithms with neat diagrams.

---

### Definition

A **B+ Tree** is a balanced multi-level search tree used by DBMSs to index records stored on disk. It keeps search keys in sorted order. Internal nodes guide the search, while leaf nodes contain all search-key entries and pointers to records or data blocks. The leaf nodes are linked sequentially, which makes range queries and ordered traversal efficient.

All leaf nodes are at the same level. Therefore, the tree remains balanced and a search takes approximately the same number of disk accesses regardless of the key being searched.

### Structure and Properties

For a B+ Tree of order `m`:

1. An internal node can have at most `m` child pointers and at most `m - 1` search keys.
2. Except for the root, an internal node normally has at least `ceil(m/2)` children.
3. A leaf can contain at most `m - 1` search-key entries. Except for special root cases, it must satisfy the minimum occupancy rule defined for the implementation.
4. All leaf nodes appear at the same depth.
5. Internal-node keys act as separators; actual data entries are stored at the leaf level.
6. Leaf nodes are connected using next-leaf pointers to support sequential and range access.

### Neat Diagram

Example B+ Tree:

```text
                       [ 30 | 50 ]
                      /     |     \
                     /      |      \
             [10 | 20] [30 | 40] [50 | 60 | 70]
                 <-------- leaf links -------->
```

The root contains separator keys `30` and `50`. A key smaller than `30` is searched in the first leaf; a key from `30` up to but not including `50` is searched in the second leaf; and a key greater than or equal to `50` is searched in the third leaf.

### Search Operation

To search for a key `K`:

1. Start at the root node.
2. Compare `K` with the separator keys in the current internal node.
3. Follow the child pointer whose key range contains `K`.
4. Repeat until a leaf node is reached.
5. Search the leaf entries. If the key is present, follow its record pointer; otherwise, report that the key is not present.

**Example:** To search for `60` in the diagram, compare it with `30` and `50`. Since `60` is greater than or equal to `50`, follow the rightmost pointer and find `60` in the final leaf.

```text
Root [30 | 50]
       |
       +---- 60 >= 50 ----> Leaf [50 | 60 | 70] ----> FOUND
```

The search cost is proportional to the height of the tree. Since a B+ Tree has a high branching factor, its height is usually small even for a large number of records.

### Insertion Operation

To insert a new key:

1. Search for the correct leaf node where the key belongs.
2. Insert the key in sorted order in that leaf.
3. If the leaf has space, stop.
4. If the leaf overflows, split it into two leaf nodes and distribute the entries between them.
5. Copy the first key of the new right leaf into the parent as a separator. The key remains in the leaf as well.
6. If the parent overflows, split the internal node and propagate a separator to its parent.
7. If the root splits, create a new root. The height of the tree increases by one.

**Example — inserting `40` into a leaf containing `[10 | 20 | 30]`:**

Assume the maximum number of keys in a leaf is three. Inserting `40` causes an overflow.

```text
Before insertion:

                  [10 | 20 | 30]

After inserting 40 (overflow):

             [10 | 20 | 30 | 40]

After splitting:

                    [ 30 ]
                   /      \
           [10 | 20]      [30 | 40]
                 <------->
                 leaf link
```

The separator `30` is copied into the parent. The actual key `30` is still stored in the right leaf.

### Deletion Operation

To delete a key:

1. Search for the key in the appropriate leaf node.
2. Remove the key from the leaf.
3. If the leaf still has the required minimum number of entries, update a separator key if necessary and stop.
4. If the leaf underflows, first try to **redistribute** an entry from an adjacent sibling that has more than the minimum number of entries. Update the parent separator.
5. If redistribution is not possible, **merge** the underflowing leaf with an adjacent sibling and remove the corresponding separator from the parent.
6. If the parent underflows, apply redistribution or merging to internal nodes as well.
7. If the root is left with only one child, make that child the new root. The tree height decreases by one.

**Example — deleting `50` after the right leaf contains `[50 | 70]`:**

The leaf becomes `[70]`, which is below the minimum occupancy of two entries in this example. If its left sibling `[30 | 40]` cannot lend an entry, merge the two leaves and remove separator `50` from the root.

```text
Before deletion:

                   [30 | 50]
                  /    |    \
             [10|20] [30|40] [50|70]

After deleting 50 and merging:

                    [ 30 ]
                   /      \
              [10 | 20] [30 | 40 | 70]
```

### Advantages and Applications

- The tree remains balanced, providing predictable search performance.
- A high branching factor reduces the number of disk I/O operations.
- Linked leaf nodes make range searches and ordered retrieval efficient.
- Insertions and deletions can be handled without rebuilding the entire index.
- B+ Trees are widely used for database indexes and file-system indexes.

---

## Q2. Primary, Secondary and Clustered Indexes

> **Question:** Explain Primary, Secondary, and Clustered Indexes with suitable examples.

---

### Definition of Indexing

An **index** is an auxiliary data structure that stores search-key values along with pointers to records or disk blocks. It helps the DBMS locate required records without scanning the entire table. An index improves retrieval speed, but it requires additional storage and must be maintained when records are inserted, deleted, or updated.

### 1. Primary Index

A **primary index** is an index built on the primary key of a data file that is physically stored in the order of that key. In the traditional file-organization definition, a primary index is often **sparse**: it contains one index entry for each data block, usually storing the first key value in that block and a pointer to the block.

Example: Suppose `STUDENT` records are stored in ascending order of `Student_ID`.

**Data file**

| Block | Student_ID values |
|---|---|
| B1 | 101, 102, 103 |
| B2 | 104, 105, 106 |
| B3 | 107, 108, 109 |

**Primary index**

| First Student_ID | Block pointer |
|---|---|
| 101 | B1 |
| 104 | B2 |
| 107 | B3 |

To find student `105`, the DBMS locates the index entry `104`, accesses block `B2`, and searches within that block.

### 2. Secondary Index

A **secondary index** is created on an attribute that does not determine the physical ordering of the data file. It provides an additional access path. A secondary index is generally **dense**, meaning it has an entry for every search-key value or record. When duplicate values exist, an index entry can point to a list or bucket of record pointers.

Example: The `STUDENT` file is physically ordered by `Student_ID`, but users frequently search by `Department`.

| Department value | Record pointers |
|---|---|
| CSE | R1, R3, R5 |
| ECE | R2, R4 |

The secondary index on `Department` helps retrieve all CSE students without scanning every student record.

### 3. Clustered Index

A **clustered index** determines or closely follows the physical order in which records are stored. Records with the same or nearby indexed values are stored together. It is useful when queries retrieve groups or ranges of records having similar values.

In the traditional indexing classification, a **clustering index** is built on an ordered, non-key field. There may be one index entry for each distinct value, pointing to the first block containing records with that value.

Example: Suppose `EMPLOYEE` records are stored grouped by `Department_ID`.

```text
Data file ordered by Department_ID

+------------------------------+
| Department 10: E1, E2, E3     |
| Department 20: E4, E5         |
| Department 30: E6, E7, E8     |
+------------------------------+

Clustering index

+----------------+-------------+
| Department_ID  | Block       |
+----------------+-------------+
| 10             | B1          |
| 20             | B2          |
| 30             | B3          |
+----------------+-------------+
```

A query that retrieves all employees from department `20` can access the relevant group of records efficiently.

### Comparison

| Parameter | Primary Index | Secondary Index | Clustered / Clustering Index |
|---|---|---|---|
| Search field | Primary key | Non-ordering search field | Field used to group or order records |
| Physical order | Data file is ordered by the primary key | Does not determine file order | Records are grouped according to the indexed field |
| Uniqueness | Search key is unique | May contain duplicate values | Often uses a non-key field with duplicate values |
| Density | Often sparse in the traditional definition | Generally dense | Often sparse, with an entry per distinct value or group |
| Main use | Fast lookup by primary key | Additional lookup paths | Retrieval of groups and ranges |
| Storage | Index entries and block pointers | Entries or pointer lists for values/records | Entries pointing to groups of records |

### SQL Example

```sql
CREATE TABLE Student (
    Student_ID INT PRIMARY KEY,
    Student_Name VARCHAR(50),
    Department VARCHAR(20)
);

-- Additional access path on Department
CREATE INDEX idx_student_department
ON Student(Department);
```

The `PRIMARY KEY` declaration creates a primary-key constraint and usually an associated index, depending on the DBMS. The explicit `CREATE INDEX` statement creates an additional index. SQL systems differ in how they implement physical clustering; creating an ordinary index does not necessarily rearrange table rows physically.

### Advantages and Limitations

Indexes reduce record lookup time and can speed up joins, sorting, and filtering. However, they consume disk space and increase the cost of insert, update, and delete operations because the DBMS must maintain the index. The appropriate index depends on the table's physical organization and the queries performed most frequently.

---

## Q3. Tree-Based Indexing vs Hash-Based Indexing

> **Question:** Compare Tree-Based Indexing and Hash-Based Indexing.

---

### Tree-Based Indexing

**Tree-based indexing** stores keys in a hierarchical, ordered structure. DBMSs commonly use B+ Trees. Internal nodes contain separator keys and child pointers, while leaf nodes contain key entries and record pointers. The tree is balanced, so search, insertion, and deletion have logarithmic height-based cost.

Tree indexes support equality searches as well as range conditions such as `BETWEEN`, `<`, `>`, and ordered retrieval.

### Hash-Based Indexing

**Hash-based indexing** applies a hash function to a search key to determine the bucket in which its record pointer should be stored. The hash function maps a large key space to a limited set of bucket addresses. Collisions are handled using techniques such as overflow buckets or chaining.

Hash indexes are especially useful for equality conditions such as `Student_ID = 105`. They do not naturally maintain key order, so range queries are generally inefficient.

### Comparison Table

| Parameter | Tree-Based Indexing | Hash-Based Indexing |
|---|---|---|
| Data organization | Hierarchical and sorted | Records assigned to buckets using a hash function |
| Typical structure | B+ Tree | Hash table with buckets |
| Equality search | Efficient | Usually very efficient when the hash function distributes keys well |
| Range search | Efficient because keys are ordered | Inefficient because bucket order does not represent key order |
| Sequential access | Supports ordered traversal | Does not naturally support sorted traversal |
| Insert and delete | Requires node splits, redistribution, or merging when necessary | May require collision handling, overflow handling, or bucket splitting |
| Main applications | Range queries, sorting, equality lookup, ordered scans | Exact-match lookup and equality joins |

### Example

Assume a table `STUDENT(Student_ID, Student_Name)`.

**Tree index:**

```text
                  [30 | 50]
                 /    |    \
            [10,20] [30,40] [50,60]
```

A query such as the following can use the ordering of the tree:

```sql
SELECT *
FROM Student
WHERE Student_ID BETWEEN 30 AND 50;
```

**Hash index:**

Suppose the hash function is `h(k) = k MOD 5`.

| Student_ID | Hash calculation | Bucket |
|---:|---:|---:|
| 101 | 101 MOD 5 = 1 | B1 |
| 102 | 102 MOD 5 = 2 | B2 |
| 107 | 107 MOD 5 = 2 | B2 |

Both `102` and `107` map to bucket `B2`; this is a collision. The hash structure must store both entries using an overflow or collision-resolution method.

### When to Use Each Index

- Use a **B+ Tree index** when queries frequently perform range searches, sorting, prefix/range scans, or equality searches.
- Use a **hash index** when the workload mainly performs exact equality lookups and the DBMS provides an appropriate hash-index implementation.

### Conclusion

Tree-based indexing is more flexible because it supports both equality and range operations. Hash-based indexing is designed mainly for exact-match operations and can provide very fast bucket access, but it does not preserve key order. The workload and DBMS implementation determine which index is appropriate.

---

## Q4. File Organization and Indexing

> **Question:** Discuss File Organization and Indexing.

---

### File Organization

**File organization** is the method used to arrange records physically in a database file. It determines how records are stored, accessed, inserted, deleted, and updated. A suitable file organization reduces disk I/O and improves query performance.

### Types of File Organization

#### 1. Heap File Organization

In a **heap file**, records are stored wherever free space is available; they are not maintained in any particular order.

```text
HEAP FILE
+------------------------------+
| R7 | R2 | R9 | R1 | R5 | R3  |
+------------------------------+
```

- Insertion is simple because a new record can be placed in an available location.
- Searching without an index may require a linear scan.
- It is suitable for tables that receive frequent insertions and do not require ordered retrieval.

#### 2. Sequential or Sorted File Organization

In **sequential organization**, records are stored in sorted order based on a search key.

```text
SORTED FILE (Student_ID)
+--------------------------------+
| 101 | 104 | 108 | 112 | 119     |
+--------------------------------+
```

- Sequential scans and range queries are efficient.
- Searching can use binary search when the storage structure supports it.
- Insertions and deletions may be expensive because order must be maintained, sometimes using overflow areas.

#### 3. Hash File Organization

In **hash file organization**, a hash function maps a record's search key to a bucket.

```text
          h(Student_ID)
                |
        +-------+-------+
        |               |
      Bucket 0       Bucket 1 ...
        |               |
      Records         Records
```

- Exact-match retrieval is efficient when keys are distributed well.
- Collisions may create overflow buckets or chains.
- It is not suitable for retrieving records in sorted order or for ordinary range scans.

#### 4. Clustered File Organization

In a **clustered organization**, records that are related by a clustering key or relationship are stored physically close to one another. This can reduce disk accesses when a query retrieves a group of related records. For example, employee records belonging to the same department may be stored together.

### Indexing

**Indexing** creates an auxiliary structure containing search-key values and pointers to records or data blocks. Rather than scanning every record, the DBMS searches the index and follows the pointer to the required data.

Common index structures include:

1. **Ordered indexes:** Store key values in sorted order. B+ Trees are a common example.
2. **Hash indexes:** Use a hash function to map keys to buckets.
3. **Primary indexes:** Built on the ordering primary key of a sorted data file.
4. **Secondary indexes:** Provide additional access paths on non-ordering attributes.
5. **Clustered indexes:** Arrange or group records according to an indexed field.

### Difference Between File Organization and Indexing

| Parameter | File Organization | Indexing |
|---|---|---|
| Meaning | Defines the physical arrangement of records | Defines an auxiliary path for locating records |
| Purpose | Controls how records are stored | Reduces the work required to find records |
| Structures | Heap, sorted, hash, clustered files | B+ Tree, hash index, primary and secondary indexes |
| Storage | Organizes the main data file | Requires additional index storage |
| Update impact | May require moving or reorganizing records | Index entries must be maintained when indexed values or records change |
| Use | Determines overall storage and access pattern | Speeds up selected search and retrieval operations |

### Example

Consider the following table:

```sql
CREATE TABLE Employee (
    Emp_ID INT PRIMARY KEY,
    Emp_Name VARCHAR(50),
    Department_ID INT,
    Salary DECIMAL(10,2)
);

CREATE INDEX idx_emp_department
ON Employee(Department_ID);
```

The DBMS chooses a file organization for storing the `Employee` rows. The index on `Department_ID` gives it an additional access path for queries such as:

```sql
SELECT *
FROM Employee
WHERE Department_ID = 10;
```

The optimizer decides whether using the index is cheaper than scanning the table. An index is not automatically beneficial for every query.

### Conclusion

File organization determines where and how records are stored, whereas indexing provides additional structures for locating records efficiently. Both must be selected according to the database workload, query patterns, and update frequency.

---

## Q5. Hash-Based Indexing

> **Question:** Explain Hash-Based Indexing.

---

### Definition

**Hash-based indexing** is an indexing technique in which a hash function converts a search-key value into a bucket address. The bucket stores the key and a pointer to the corresponding record or data block. It is mainly used for fast equality searches.

### Components

1. **Search key:** The attribute used to locate a record, such as `Student_ID`.
2. **Hash function:** A function that maps a key to a bucket number.
3. **Bucket:** A storage area that contains one or more index entries or record pointers.
4. **Collision:** A situation in which two different keys map to the same bucket.
5. **Overflow area:** Extra storage used when the target bucket cannot hold another entry.

### Working of Hash Indexing

The basic process is:

```text
        Search key K
              |
              v
        Hash function h(K)
              |
              v
        Bucket address
              |
              v
       Search bucket entries
              |
        +-----+------+
        |            |
      Found       Not found
        |            |
        v            v
   Record pointer  Report absence
```

### Example Using a Hash Function

Assume five buckets numbered `0` to `4`, and the hash function is:

\[
h(k) = k \bmod 5
\]

Insert the keys `12`, `22`, `17`, `31`, and `44`.

| Key | Calculation | Bucket |
|---:|---:|---:|
| 12 | 12 MOD 5 = 2 | B2 |
| 22 | 22 MOD 5 = 2 | B2 |
| 17 | 17 MOD 5 = 2 | B2 |
| 31 | 31 MOD 5 = 1 | B1 |
| 44 | 44 MOD 5 = 4 | B4 |

The resulting buckets can be represented as:

```text
B0 : Empty
B1 : 31
B2 : 12 -> 22 -> 17
B3 : Empty
B4 : 44
```

Keys `12`, `22`, and `17` all map to bucket `B2`. This is a **collision**. In this example, chaining is used to store multiple entries in the same bucket chain.

### Searching for a Key

To search for key `22`:

1. Calculate `h(22) = 22 MOD 5 = 2`.
2. Access bucket `B2` directly.
3. Examine the entries in that bucket or its overflow chain.
4. Find `22` and follow its record pointer.

Only the entries in the selected bucket need to be examined, rather than every record in the file.

### Collision Handling Techniques

**1. Separate Chaining / Overflow Chaining**  
All entries that map to the same bucket are stored in a linked chain or overflow pages. It is simple, but a long chain increases search time.

**2. Open Addressing**  
When the target location is occupied, the algorithm probes other positions according to a probing sequence. Common methods include linear probing, quadratic probing, and double hashing. The exact method depends on the hash-table implementation.

**3. Bucket Splitting**  
In dynamic hashing methods, a full bucket can be split so that entries are distributed among additional buckets.

### Static and Dynamic Hashing

| Parameter | Static Hashing | Dynamic Hashing |
|---|---|---|
| Number of buckets | Fixed initially | Can grow or change as records increase |
| Overflow | May create overflow chains | Uses bucket splitting or directory changes to reduce overflow |
| Flexibility | Less flexible for changing file size | Adapts better to changing data size |
| Complexity | Simpler to implement | More complex to manage |
| Example | Fixed bucket array | Extendible hashing and linear hashing |

**Extendible hashing** uses a directory of pointers to buckets and a global-depth value. When a bucket overflows, it may split; the directory may also double if more hash bits are needed. **Linear hashing** splits buckets progressively without requiring the entire directory to double at once.

### Advantages

- Provides fast access for exact equality searches.
- A well-designed hash function distributes keys across buckets.
- It is useful for equality lookups and some equality-join operations.

### Limitations

- It does not preserve the sorted order of keys.
- Range queries such as `BETWEEN`, `<`, and `>` are not efficient through a hash index.
- Poor hash functions can create long overflow chains.
- Insertions and deletions may require overflow management or bucket restructuring.

### Conclusion

Hash-based indexing maps search keys directly to buckets and is effective for exact-match searches. Its performance depends on the hash function, bucket capacity, and collision-handling method.

---

## Q6. Database Tuning Techniques

> **Question:** Evaluate various database tuning techniques for improving database performance.

---

### Definition

**Database tuning** is the process of adjusting database queries, indexes, schema design, configuration, and system resources to improve performance. Its main objectives are to reduce response time, minimize disk I/O, use memory efficiently, and support more concurrent users without sacrificing correctness.

### Database Tuning Techniques

#### 1. Query Optimization

Queries should be written so that the DBMS processes only the required rows and columns. Avoid retrieving unnecessary data with `SELECT *` when only a few columns are required. Apply selective conditions early and use appropriate joins.

```sql
-- Less efficient when only two columns are needed
SELECT * FROM Employee WHERE Department_ID = 10;

-- Retrieves only the required columns
SELECT Emp_ID, Emp_Name
FROM Employee
WHERE Department_ID = 10;
```

The DBMS query optimizer can choose a better execution plan when useful statistics and indexes are available.

#### 2. Proper Indexing

Create indexes on columns frequently used in `WHERE`, `JOIN`, `ORDER BY`, or `GROUP BY` conditions, provided the expected read benefit justifies the maintenance cost.

```sql
CREATE INDEX idx_employee_dept
ON Employee(Department_ID);
```

Avoid creating unnecessary indexes. Too many indexes increase storage usage and slow down insert, update, and delete operations.

#### 3. Schema Design and Normalization

A well-designed schema reduces redundant data and prevents update anomalies. Normalization improves consistency by separating facts into related tables. However, a read-heavy workload may sometimes benefit from carefully controlled denormalization, such as storing a frequently used summary, provided consistency is maintained.

#### 4. Efficient Joins

Join tables using appropriate key columns and make sure the optimizer has useful statistics. Indexes on join columns may reduce lookup work. Avoid joining tables unnecessarily and filter rows before a large join when the query semantics allow it.

```sql
SELECT E.Emp_Name, D.Department_Name
FROM Employee E
JOIN Department D
  ON E.Department_ID = D.Department_ID
WHERE D.Department_ID = 10;
```

#### 5. Memory and Buffer Management

The DBMS uses memory buffers to cache frequently accessed data pages. An appropriate buffer-pool size can reduce repeated disk reads. Memory must be balanced with the requirements of the operating system and other database operations.

#### 6. Partitioning Large Tables

**Partitioning** divides a large table into smaller logical or physical parts based on a partition key, such as date or region. Queries that filter on the partition key may access only relevant partitions. Partitioning also helps with maintenance of very large tables.

Example: An `ORDERS` table can be partitioned by order year so a query for recent orders need not scan every historical partition, when partition pruning is supported and applicable.

#### 7. Statistics and Execution-Plan Analysis

The optimizer relies on statistics such as row counts, distinct values, and value distributions to estimate the cost of execution plans. Keep statistics current and inspect execution plans to identify full table scans, expensive joins, and inefficient access paths.

```sql
EXPLAIN
SELECT *
FROM Employee
WHERE Department_ID = 10;
```

The exact `EXPLAIN` syntax and output vary between DBMS products.

#### 8. Caching and Connection Management

Frequently reused results may be cached at the application or database layer when the data's freshness requirements permit it. Connection pooling reuses existing database connections instead of repeatedly creating and closing them, reducing connection overhead.

#### 9. Hardware and Storage Optimization

Adequate RAM, fast storage, suitable CPU capacity, and properly configured storage can reduce bottlenecks. Workloads involving many random reads may benefit from low-latency storage. Monitor CPU, memory, disk I/O, and network utilization before upgrading hardware.

#### 10. Regular Maintenance

Perform suitable maintenance tasks, such as updating statistics, checking index health, monitoring storage growth, and removing obsolete data according to retention rules. The correct maintenance commands depend on the DBMS.

### Summary Table

| Technique | Main purpose | Expected benefit |
|---|---|---|
| Query optimization | Reduce unnecessary processing | Lower query execution time |
| Indexing | Avoid repeated full scans | Faster data retrieval |
| Normalized schema | Reduce redundancy and anomalies | Better data consistency |
| Efficient joins | Reduce join processing work | Faster multi-table queries |
| Buffer management | Cache frequently used pages | Fewer disk reads |
| Partitioning | Divide very large tables | Less data scanned for suitable queries |
| Statistics and plan analysis | Improve cost estimates and identify bottlenecks | Better execution-plan selection |
| Caching and pooling | Reuse data and connections | Less repeated computation and connection overhead |
| Hardware optimization | Remove resource bottlenecks | Better overall throughput |

### Conclusion

Database performance cannot be improved by one technique alone. Effective tuning begins by measuring the workload, identifying the bottleneck, applying an appropriate change, and measuring again. The best solution balances read performance, update cost, storage, and data consistency.

---

## Q7. Query Optimization Algorithms

> **Question:** What is Query Optimization? Explain the various Query Optimization Algorithms in detail with suitable examples.

---

### Definition

**Query optimization** is the process of selecting an efficient execution plan for an SQL query. A query can often be executed in several logically equivalent ways. The optimizer examines alternative plans and tries to choose one that minimizes estimated execution cost, such as disk I/O, CPU time, memory use, and response time.

### Query Processing Stages

```text
       SQL Query
           |
           v
   Parsing and Validation
           |
           v
   Relational Algebra Form
           |
           v
     Query Optimizer
           |
           v
   Physical Execution Plan
           |
           v
     Query Execution
           |
           v
         Result
```

### 1. Heuristic or Rule-Based Optimization

**Heuristic optimization** applies transformation rules that usually reduce the amount of data processed. These rules are applied using relational algebra equivalences, without necessarily estimating the exact execution cost of every alternative.

Important heuristic rules include:

1. **Perform selections early:** Apply restrictive `WHERE` conditions near the relevant table so fewer rows move to later operations.
2. **Perform projections early:** Retrieve only the columns required by later operations, while retaining columns needed for joins and conditions.
3. **Replace Cartesian product followed by selection with a join:** A join avoids generating irrelevant combinations of rows.
4. **Reorder joins:** Join smaller or more selective intermediate results first, when the transformation preserves query semantics.
5. **Combine cascaded selections:** Multiple conditions on the same relation can be combined into one selection condition.
6. **Remove unnecessary operations:** Eliminate redundant projections or conditions when equivalence rules prove that they do not affect the result.

**Example:** Consider the query:

```sql
SELECT S.Student_Name
FROM Student S
JOIN Enrollment E
  ON S.Student_ID = E.Student_ID
WHERE S.Department = 'CSE';
```

A logical plan can first join the complete `Student` and `Enrollment` relations and then filter the result. A better heuristic plan pushes the department selection down to `Student` first:

```text
Less efficient logical order:

        Project Student_Name
                 |
          Select Department='CSE'
                 |
          Join Student, Enrollment

Optimized logical order:

        Project Student_Name
                 |
                 Join
               /     \
      Select CSE     Enrollment
           |
        Student
```

The optimized plan reduces the number of student rows that participate in the join.

### 2. Cost-Based Optimization

**Cost-based optimization** generates alternative execution plans, estimates the cost of each using database statistics and cost formulas, and chooses a low-cost plan.

The optimizer may compare:

- Table scan and index scan access paths.
- Different join orders.
- Nested-loop, sort-merge, and hash join algorithms.
- Different sorting and grouping strategies.

A simplified process is:

```text
     Query and Database Statistics
                  |
                  v
       Generate Candidate Plans
                  |
                  v
         Estimate Each Cost
                  |
                  v
          Compare Costs
                  |
                  v
       Select Lowest-Cost Plan
                  |
                  v
          Execute the Plan
```

### 3. Dynamic Programming for Join Ordering

For queries that join several relations, the optimizer may use **dynamic programming** to find a low-cost join order.

1. Estimate the best access path for each individual relation.
2. Estimate the best way to join each pair of relations.
3. Store the best known plan and cost for each relation subset.
4. Build plans for larger subsets using previously computed smaller subsets.
5. Select the lowest-cost plan for the complete query.

This avoids evaluating every possible join order independently. System R-style optimization is a well-known example of cost-based dynamic programming for join-order and access-path selection.

### 4. Join Algorithms Considered by an Optimizer

| Join algorithm | Working principle | Suitable situation |
|---|---|---|
| Nested-loop join | For each row of one relation, search matching rows in the other relation | Small outer relation or indexed lookup on the inner relation |
| Block nested-loop join | Processes blocks of outer rows to reduce repeated scans of the inner relation | Relations where a block of the outer relation fits in memory |
| Sort-merge join | Sorts both inputs on join keys and then scans them in order | Inputs are already sorted or sorting cost is acceptable; useful for ordered output |
| Hash join | Builds a hash table on one input and probes it using the other input's join key | Equi-joins where sufficient memory is available for the build phase |

### 5. Semantic Query Optimization

**Semantic optimization** uses information about the meaning of the data, such as integrity constraints, keys, and known relationships, to simplify a query. For example, a condition that contradicts a declared constraint may allow the DBMS to determine that the query returns no rows. The exact extent of semantic optimization depends on the DBMS.

### Conclusion

Query optimization improves query performance by transforming logical expressions and selecting efficient physical operations. Heuristic rules reduce unnecessary work, while cost-based algorithms compare alternative plans using statistics and estimated resource costs.

---

## Q8. Cost-Based Query Optimization

> **Question:** What is Cost-Based Query Optimization? Explain its working process, cost estimation techniques, and execution plan selection with a suitable example.

---

### Definition

**Cost-based query optimization** is a query optimization method in which the DBMS estimates the resource cost of different execution plans and selects the plan with the lowest estimated cost. The optimizer commonly considers disk page I/O, CPU operations, memory usage, and sometimes communication cost in distributed systems.

The estimates are based on database statistics, such as the number of rows, number of disk pages, number of distinct values, data distribution, and available indexes.

### Working Process

1. **Parse the query:** Check SQL syntax, table names, and column names.
2. **Generate a logical plan:** Represent the query using relational algebra operations such as selection, projection, and join.
3. **Generate alternatives:** Consider different access paths, join orders, and join algorithms.
4. **Collect statistics:** Use table size, page count, value distribution, index height, and selectivity estimates.
5. **Estimate costs:** Calculate the expected I/O, CPU, memory, and other relevant costs for each plan.
6. **Compare plans:** Choose the plan with the lowest estimated total cost.
7. **Execute:** Run the selected physical execution plan.

### Important Cost Estimation Techniques

#### 1. Table and Page Statistics

Let:

- `T(R)` = number of tuples (rows) in relation `R`.
- `B(R)` = number of disk pages occupied by relation `R`.
- `V(R,A)` = number of distinct values of attribute `A` in relation `R`.
- `M` = number of available buffer pages.

These statistics help estimate how much data must be read and how many rows an operation may produce.

#### 2. Selectivity Estimation

**Selectivity** is the fraction of rows expected to satisfy a condition. For example, if 1,000 out of 10,000 rows satisfy a condition, the estimated selectivity is:

\[
\text{Selectivity} = \frac{1000}{10000} = 0.1
\]

The estimated output contains about 10% of the original rows. Under a simplifying uniform-distribution assumption, the estimated number of rows satisfying `A = value` may be approximated by:

\[
\frac{T(R)}{V(R,A)}
\]

This estimate can be inaccurate when values are skewed or correlated; DBMSs may use histograms and other statistics to improve it.

#### 3. Disk I/O Cost

Disk I/O is often a major component of query cost because reading pages from storage can be expensive. A full table scan of relation `R` requires reading approximately `B(R)` pages, ignoring caching and other implementation details.

#### 4. Index Cost

An index can reduce the number of data pages read for a selective condition. The optimizer considers index height, the number of matching entries, and whether data records are stored close together. An index is not always cheaper than a table scan, especially when a large fraction of the table is required.

#### 5. Join Cost Estimation

For a simple **block nested-loop join**, if `R` is the outer relation and `S` is the inner relation, a common page-I/O estimate is:

\[
B(R) + \left\lceil \frac{B(R)}{M-2} \right\rceil \times B(S)
\]

This assumes that approximately `M - 2` buffer pages can be used for blocks of the outer relation, with the remaining buffers used for the inner scan and output. Actual costs depend on the DBMS and buffer-management details.

A hash join or sort-merge join has different cost components, including reading inputs, building/probing hash structures, or sorting runs.

### Worked Example — Choosing a Join Order

Consider two relations:

**STUDENT**

- Number of pages: `B(Student) = 100`
- Number of rows: `10,000`

**ENROLLMENT**

- Number of pages: `B(Enrollment) = 500`
- Number of rows: `50,000`

Suppose the query first filters `STUDENT` to 1,000 rows occupying 10 pages. The DBMS has `M = 12` buffer pages and uses block nested-loop join. Compare the two possible outer relations.

**Plan A: Filtered STUDENT is the outer relation**

\[
\begin{aligned}
Cost_A &= 10 + \left\lceil \frac{10}{12-2} \right\rceil \times 500 \\
       &= 10 + 1 \times 500 \\
       &= 510\text{ page I/Os}
\end{aligned}
\]

**Plan B: ENROLLMENT is the outer relation**

\[
\begin{aligned}
Cost_B &= 500 + \left\lceil \frac{500}{12-2} \right\rceil \times 10 \\
       &= 500 + 50 \times 10 \\
       &= 1000\text{ page I/Os}
\end{aligned}
\]

| Plan | Outer relation | Estimated cost |
|---|---|---:|
| A | Filtered STUDENT (10 pages) | 510 page I/Os |
| B | ENROLLMENT (500 pages) | 1,000 page I/Os |

Under these assumptions, Plan A has the lower estimated I/O cost. Therefore, the optimizer prefers to filter the smaller `STUDENT` input first and use it as the outer relation for this block nested-loop join.

### Execution Plan Selection

The DBMS compares the estimated costs of the candidate plans. The plan with the lowest estimated cost is selected, subject to correctness and optimizer rules. The chosen plan may use an index scan, table scan, a particular join order, and one or more join algorithms.

An execution plan can be inspected using a command such as:

```sql
EXPLAIN
SELECT S.Student_Name, E.Course_ID
FROM Student S
JOIN Enrollment E
  ON S.Student_ID = E.Student_ID
WHERE S.Department = 'CSE';
```

The exact command and detail shown by `EXPLAIN` vary by DBMS. Actual runtime can differ from estimated cost when statistics are stale, data is skewed, cache conditions change, or resource availability differs.

### Advantages and Limitations

- It selects plans based on estimated resource consumption rather than relying only on fixed rules.
- It can compare different indexes, join orders, and join algorithms.
- It depends on accurate statistics and reasonable cost models.
- Estimation errors can cause the optimizer to select a plan that performs poorly in practice.

### Conclusion

Cost-based optimization estimates the resource requirements of alternative execution plans and selects a low-cost plan. Table statistics, selectivity, index information, and join-cost formulas are important inputs to this decision.

---

## Q9. Database Backup and Recovery Techniques

> **Question:** What is Database Backup and Recovery? Explain the various Backup and Recovery Techniques in detail with suitable examples.

---

### Definition

**Database backup** is the process of creating a separate copy of database data so that it can be restored after accidental deletion, hardware failure, corruption, or another disaster. **Database recovery** is the process of bringing the database back to a correct and usable state after a failure.

Backup protects stored data, while recovery uses backups, transaction logs, and recovery procedures to restore the database and, where possible, recover committed transactions.

### Need for Backup and Recovery

1. **Hardware failure:** A disk or storage device may fail and make database files unavailable.
2. **Human error:** A user may accidentally delete or update important records.
3. **Software failure:** A DBMS or application error may corrupt data or interrupt a transaction.
4. **Power failure or system crash:** The system may stop before all changes are safely written.
5. **Security incident or disaster:** Malware, unauthorized changes, fire, or other incidents may destroy or compromise data.

### Backup Techniques

#### 1. Full Backup

A **full backup** copies the entire database, or the complete selected backup scope, at a particular point in time.

- It provides a complete baseline for restoration.
- Restoration is straightforward compared with a long chain of incremental backups.
- It generally requires more storage space and backup time.

#### 2. Incremental Backup

An **incremental backup** copies only the data changed since the most recent backup of the relevant type, commonly the previous full or incremental backup.

- It reduces the amount of data copied during each backup.
- It requires less storage and time for frequent backups.
- Restoration may require the full backup and every required incremental backup in sequence.

#### 3. Differential Backup

A **differential backup** copies all changes made since the last full backup.

- Each differential backup contains changes accumulated since that full backup.
- Restoration normally requires the full backup and the latest differential backup.
- Differential backup size may increase as more changes accumulate after the full backup.

### Example of Backup Types

Assume a full backup is taken on Sunday and data changes occur during the week.

| Day | Full backup | Incremental backup | Differential backup |
|---|---|---|---|
| Sunday | Copies all data | — | — |
| Monday | — | Monday's changes | Changes since Sunday's full backup |
| Tuesday | — | Tuesday's changes since Monday's backup | Changes since Sunday's full backup, including Monday and Tuesday |
| Wednesday | — | Wednesday's changes since Tuesday's backup | Changes since Sunday's full backup, including Monday through Wednesday |

**Restoration:** To restore using Wednesday's incremental chain, the system needs Sunday's full backup and the Monday, Tuesday, and Wednesday incremental backups. To restore using Wednesday's differential backup, it needs Sunday's full backup and Wednesday's differential backup.

#### 4. Transaction Log Backup

A **transaction log backup** saves transaction-log records that describe database changes. Log backups can be used with a full backup to restore a database and apply subsequent changes, depending on the DBMS and backup configuration.

#### 5. Physical and Logical Backup

- A **physical backup** copies database files, data pages, and related storage structures. It is commonly used for full database restoration.
- A **logical backup** exports database objects or data as logical statements or records, such as table definitions and inserted rows. It is useful for moving selected objects or restoring particular logical contents, but restoring a large database may take longer.

#### 6. Cold and Hot Backup

- A **cold backup** is taken while the database is shut down or in a consistent offline state. It is simple to make consistent, but it requires downtime.
- A **hot backup** is taken while the database remains online and serves users. It requires DBMS support and suitable logging or consistency mechanisms.

### Recovery Techniques

#### 1. Log-Based Recovery

A **transaction log** maintains records of database operations. A log record may contain a transaction identifier, the data item changed, and the old and new values.

Example log entries:

```text
<T1, START>
<T1, A, 500, 400>
<T1, COMMIT>
<T2, START>
<T2, B, 200, 250>
```

The record `<T1, A, 500, 400>` indicates that transaction `T1` changed `A` from `500` to `400`.

Log-based recovery commonly uses two operations:

- **UNDO:** Reverses the effects of an incomplete or aborted transaction using old values.
- **REDO:** Reapplies the effects of a committed transaction when its changes may not yet have reached the database files.

#### 2. Write-Ahead Logging (WAL)

Under **Write-Ahead Logging**, the relevant log record must be written to stable storage before the corresponding modified database page is written. This ensures that recovery information is available if a crash occurs while a page is being written.

#### 3. Deferred Database Modification

In **deferred modification**, database changes are not applied to the database until the transaction commits. If a crash occurs before commit, the transaction's changes need not be undone in the database. Committed changes may need to be redone during recovery.

#### 4. Immediate Database Modification

In **immediate modification**, updates may be written to database pages before the transaction commits. Therefore, recovery may need both operations:

- Undo changes made by transactions that did not commit.
- Redo changes made by committed transactions whose updates were not fully reflected in the database files.

#### 5. Checkpointing

A **checkpoint** is a recovery marker that records a known point in the log and the database's recovery status. It helps reduce the amount of log that must be examined after a crash. It does not replace backups or transaction logging.

#### 6. Shadow Paging

In **shadow paging**, the DBMS keeps a shadow page table representing the stable database state and a separate current page table for modifications. Updated pages are written to new locations. At commit, the system atomically changes the pointer to the new page table. If the transaction fails before commit, the original shadow page table remains available.

### Recovery Example

Suppose transactions `T1` and `T2` are recorded in the log:

```text
<T1, START>
<T1, A, 500, 400>
<T1, COMMIT>
<T2, START>
<T2, B, 200, 250>
--- SYSTEM CRASH ---
```

- `T1` committed before the crash. If its updated value was not yet written to the database file, recovery redoes the change so that `A = 400` is reflected.
- `T2` did not commit. Recovery undoes its incomplete update, restoring `B = 200` if the new value had reached the database file.

```text
             SYSTEM CRASH
                   |
                   v
          Examine transaction log
                   |
          +--------+--------+
          |                 |
      Committed         Not committed
          |                 |
          v                 v
        REDO               UNDO
          |                 |
          +--------+--------+
                   |
                   v
          Consistent database
```

The exact recovery procedure depends on the DBMS's logging and recovery algorithm, including its checkpoint and page-flushing policy.

### Backup vs Recovery

| Parameter | Backup | Recovery |
|---|---|---|
| Meaning | Creates a separate copy of data | Restores the database to a usable, consistent state |
| Main purpose | Protect against data loss | Return to operation after a failure |
| Main mechanisms | Full, incremental, differential, log, physical, logical | Restore, log replay, undo, redo, checkpointing, shadow paging |
| When used | At scheduled intervals and before risky changes | After crashes, corruption, accidental changes, or disasters |
| Result | A stored copy of database data | A restored database with recoverable committed changes |

### Good Backup Practices

- Take backups on a schedule appropriate to the value and change rate of the data.
- Keep backup copies separate from the primary database system.
- Protect backup files with access control and encryption where appropriate.
- Retain transaction logs when point-in-time recovery is required and supported.
- Test restoration regularly; a backup is useful only if it can be restored successfully.

### Conclusion

Backup and recovery protect a database against failures and data loss. Full, incremental, and differential backups provide different storage and restoration trade-offs. Transaction logs, write-ahead logging, undo, redo, checkpoints, and shadow paging help restore database consistency after failures.
