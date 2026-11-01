# UNIT II — Balanced Trees and Heaps

> **Course:** Advanced Data Structures & Algorithm Analysis (`2501CS10`) | Aditya University  
> **Exam Priority:** Priority 3 (Mechanical Tree Tracing) · **Unit Difficulty:** Medium (5/10)  
> **Source:** *Unit-wise Important Questions — Answers | Aditya University*

---

## Part A: 2-Mark Questions

### Q1: What condition must be satisfied by every node in an AVL tree?

#### Mandatory Conditions
Every node $x$ in an AVL tree must satisfy two conditions simultaneously:
1. **Binary Search Tree Property:** All keys in the left subtree $< key(x) <$ all keys in the right subtree.
2. **Balance Factor Condition:** The difference in height between its left and right subtrees must not exceed 1:
   $$\text{Balance Factor } BF(x) = \text{height}(\text{left}) - \text{height}(\text{right}) \in \{-1, 0, +1\}$$

---

### Q2: What is the purpose of balance factor in an AVL tree?

#### Definition
$$\text{Balance Factor (BF)} = \text{height}(\text{left subtree}) - \text{height}(\text{right subtree})$$

#### Key Points
- Permissible values: $-1, 0, +1$.
- When an insertion or deletion causes $BF = \pm 2$, an imbalance is detected and immediately corrected via rotations ($LL, RR, LR, RL$).
- Guarantees worst-case tree height of $O(\log n)$, preventing degenerate $O(n)$ skewed trees.

```text
      30 (-1)
     /      \
  20 (0)   40 (-1)
              \
             50 (0)
```

---

### Q3: Define the order of a B-Tree.

#### Definition
The **order $m$** of a B-Tree is the maximum number of children any internal node can possess.

#### Structural Bounds
- **Maximum keys per node:** $m - 1$
- **Minimum keys (non-root):** $\lceil m / 2 \rceil - 1$
- **Minimum children (non-root internal):** $\lceil m / 2 \rceil$
- All leaf nodes exist strictly at the same depth.

---

### Q4: What are the applications of B-Trees?

#### Key Applications
1. **Database Indexing:** Primary and secondary indexing in relational databases (MySQL InnoDB, PostgreSQL, Oracle).
2. **File Systems:** Directory and block indexing in modern file systems (NTFS, ext4, Btrfs, HFS+).
3. **Massive Storage Systems:** Minimizes expensive disk I/O reads by packing hundreds of keys into a single disk-block node.

---

### Q5: Define binary heap.

#### Definition
A binary heap is a complete binary tree stored compactly in an array that satisfies the **heap-order property**:
- **Completeness:** Every level is fully filled, except possibly the last level, which is filled from left to right.
- **Array Representation:** For element at index $i$:
  - Parent: $\lfloor (i - 1) / 2 \rfloor$
  - Left Child: $2i + 1$, Right Child: $2i + 2$

---

### Q6: Define Max-Heap and Min-Heap.

#### Comparison
| Property | Max-Heap | Min-Heap |
|---|---|---|
| **Heap-Order Condition** | $key(\text{parent}) \ge key(\text{child})$ | $key(\text{parent}) \le key(\text{child})$ |
| **Root Element** | Always contains the maximum key | Always contains the minimum key |
| **Common Use** | Heapsort (ascending), Max-priority queue | Dijkstra's, Prim's, Min-priority queue |

---

### Q7: Define Priority Queue.

#### Definition
An abstract data type (ADT) where each element has an associated numerical priority. Elements are dequeued strictly by priority rather than arrival order (FIFO).

#### Core Operations & Complexities (Binary Heap)
- `insert(x)`: $O(\log n)$
- `extractMax()` / `extractMin()`: $O(\log n)$
- `peek()` / `getMax()`: $O(1)$

---

### Q8: What is the time complexity of the heapify operation?

#### Complexity Bounds
- **Single-node sink down (`Heapify(i)` on tree of size $n$):** $O(\log n)$ — traverses the height of the tree.
- **Building an entire heap from an unordered array (`Build-Heap`):** $O(n)$ linear time — mathematically bounded by $\sum_{h=0}^{\lfloor\log n\rfloor} \frac{n}{2^{h+1}} O(h) = O(n)$.

---

## Part B: 8-Mark Questions

### 1. Construct an AVL Tree by Step-by-Step Insertion

**Q1. Construct an AVL tree by inserting the keys `50, 25, 12, 80, 90, 37, 45, 18, 19, 6`. Show the required rotations.**

An AVL tree keeps the balance factor ($\text{height of left subtree} - \text{height of right subtree}$) of every node in $\{-1, 0, +1\}$.

| Step | Insert | Result / problem | Rotation |
|---:|---:|---|---|
| 1 | 50 | `50` | none |
| 2 | 25 | `50` (left `25`) | none |
| 3 | 12 | `12` under `25` under `50`: node `50` has balance $+2$ (LL case) | Right rotation at `50` → `25 (12, 50)` |
| 4 | 80 | `80` right of `50` | none |
| 5 | 90 | `90` right of `80`: node `50` has balance $-2$ (RR case) | Left rotation at `50` → `25 (12, 80 (50, 90))` |
| 6 | 37 | `37` left of `50`: node `25` has balance $-2$, right child `80` is left-heavy (RL case) | Right rotation at `80`, then left rotation at `25` → `50 (25 (12, 37), 80 (–, 90))` |
| 7 | 45 | `45` right of `37` | none (all balanced) |
| 8 | 18 | `18` right of `12` | none |
| 9 | 19 | `19` right of `18`: node `12` has balance $-2$ (RR case) | Left rotation at `12` → `18 (12, 19)` |
| 10 | 6 | `6` left of `12`: node `50` has balance $+2$, left child `25` is left-heavy (LL case) | Right rotation at `50` |

#### Final AVL tree

```text
          25
        /    \
      18      50
     /  \    /  \
   12   19  37   80
   /         \     \
  6          45    90
```

Height $= 4$, all balance factors are in $\{-1, 0, +1\}$. Rotations used: 2 single-right (LL), 2 single-left (RR), 1 double (RL).

---

### 2. Four Types of AVL Tree Rotations and Applications

**Q2. Explain the four types of AVL tree rotations with suitable examples. Discuss the applications of AVL trees.**

Let $z$ be the lowest unbalanced node, $y$ its taller child, and $x$ the taller child of $y$.

#### 1. LL Rotation (Right rotation) — insertion into left subtree of left child

```text
      z (+2)          y
     /               / \
    y       ->      x   z
   /
  x
```

- *Example:* insert `30, 20, 10` $\to$ root `20 (10, 30)`.

#### 2. RR Rotation (Left rotation) — insertion into right subtree of right child

```text
  z (-2)              y
   \                 / \
    y       ->      z   x
     \
      x
```

- *Example:* insert `10, 20, 30` $\to$ root `20 (10, 30)`.

#### 3. LR Rotation (Left–Right) — insertion into right subtree of left child

Left rotation at $y$, then right rotation at $z$.

```text
    z            z            x
   /            /            / \
  y     ->     x     ->     y   z
   \          /
    x        y
```

- *Example:* insert `30, 10, 20` $\to$ root `20 (10, 30)`.

#### 4. RL Rotation (Right–Left) — insertion into left subtree of right child

Right rotation at $y$, then left rotation at $z$.

```text
  z            z              x
   \            \            / \
    y   ->       x   ->     z   y
   /              \
  x                y
```

- *Example:* insert `10, 30, 20` $\to$ root `20 (10, 30)`.

| Case | Imbalance | Fix |
|---|---|---|
| LL | Left-Left | Single right rotation |
| RR | Right-Right | Single left rotation |
| LR | Left-Right | Left then right (double) |
| RL | Right-Left | Right then left (double) |

![The Four AVL Tree Rotations](figures/unit2_q2_avl_rotations.png)

#### Applications of AVL trees

- **Database Indexing:** Used in database systems to speed up search, insert, and delete operations where lookups dominate.
- **File Systems:** AVL trees maintain directory structures and symbol tables for fast file access.
- **Compilers & Interpreters:** Used in compiler symbol tables to store identifiers (variables, function names) in sorted order.
- **Memory Management:** Used by operating systems to allocate and deallocate free memory blocks efficiently.
- **Network Routing:** IP address lookup tables and network prefix matching.
- **Dictionaries & Spell Checkers:** Rapid word lookup and autocomplete.
- **Range Queries:** Efficient retrieval of all keys between $K_1$ and $K_2$.
- **Real-Time Systems:** Guarantees strict $O(\log n)$ worst-case execution time, essential for mission-critical predictability.

---

### 3. Deletion Procedure in AVL Tree (Delete 15)

**Q3. Explain the deletion procedure in an AVL tree. Show the balancing operations after deletion of `15` from the given AVL tree.**

#### Deletion Procedure (Step-by-Step)

1. **BST Deletion:** Perform standard BST deletion:
   - If node is a **leaf**, remove it directly.
   - If node has **one child**, replace node with its child.
   - If node has **two children**, replace node with its inorder successor (smallest in right subtree) or inorder predecessor, and delete that successor/predecessor node.
2. **Update Heights & Balance Factors:** Trace upward from the parent of the physically deleted node toward the root, updating each ancestor's height and balance factor:
   $$BF(\text{node}) = \text{height}(\text{left}) - \text{height}(\text{right})$$
3. **Check Balance:** If $BF \in \{-1, 0, +1\}$, the node is balanced. Move to its parent.
4. **Rebalance via Rotations:** If $BF = \pm 2$, an imbalance is detected:
   - Identify the rotation case ($LL, RR, LR, RL$) based on the balance factor of the taller child.
   - Apply rotation to restore balance.
5. **Propagate Upward:** Unlike insertion (which needs at most one rotation), deletion can decrease subtree height and cause further imbalances up to the root. Continue until root is balanced.

---

#### Worked Example: Deleting Node 15 from Given AVL Tree

![AVL Tree Deletion of 15](figures/unit2_q3_avl_deletion.png)

##### Step 1: Remove Leaf Node 15
- Node `15` is a leaf child of `25`. Remove `15` directly.

##### Step 2: Trace Ancestor Balance Factors
Trace upwards starting from parent `25`:

| Node | Height (Left) | Height (Right) | Balance Factor ($BF = L - R$) | Status |
| :---: | :---: | :---: | :---: | :---: |
| **25** | 0 | 2 | **$-2$** | **Unbalanced (Needs Rotation)** |
| **40** | 1 | 0 | $+1$ | Balanced |
| **50** | 3 | 3 | 0 | Balanced |
| **75** | 3 | 2 | $+1$ | Balanced |
| **60** | 1 | 2 | $-1$ | Balanced |
| **80** | 0 | 1 | $-1$ | Balanced |
| **65** | 0 | 1 | $-1$ | Balanced |
| **35, 55, 62, 90** | 0 | 0 | 0 | Balanced (Leaves) |

##### Step 3: Identify Imbalance & Apply RL Rotation
- At node `25`: $BF(25) = -2$ (Right heavy).
- Right child `40`: $BF(40) = +1$ (Left heavy).
- **Condition:** Right-Left (RL) Case $\implies$ Requires **Double RL Rotation** at node `25`:
  - **Sub-step 3.1 (Right Rotation at 40):** Right-rotate at node `40`. Node `35` moves up and becomes right child of `25`, with `40` as right child of `35`.
  - **Sub-step 3.2 (Left Rotation at 25):** Left-rotate at node `25`. Node `35` rises to become the new root of the subtree, with `25` as its left child and `40` as its right child!

##### Step 4: Final Verification
- The restructured subtree rooted at `35 (25, 40)` has height 2.
- At root `50`: left subtree height = 3 (via path `50 → 35 → 25` is height 3), right subtree height = 3 (via `50 → 75 → 60 → 65 → 62`).
- Balance factor at root $50 = 3 - 3 = 0$.
- **All nodes satisfy $BF \in \{-1, 0, +1\}$.** Tree is a valid balanced AVL tree.

---

### 4. Construct a B-Tree of Order 4

**Q4. Construct a B-Tree of order 4 by inserting the keys `5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`.**

**B-tree of order 4:** each node has at most 4 children (3 keys) and at least 2 children (1 key) except the root; all leaves are at the same level. When a node overflows (4 keys), it is split and the 2nd key moves up to the parent.

| Insert | Tree after insertion |
|---|---|
| `5, 3, 21` | `[3 5 21]` |
| `9` | Overflow `[3 5 9 21]`, split, `5` goes up: `[5]` with children `[3]` and `[9 21]` |
| `1` | `[5]` → `[1 3]`, `[9 21]` |
| `13` | `[5]` → `[1 3]`, `[9 13 21]` |
| `2` | `[5]` → `[1 2 3]`, `[9 13 21]` |
| `7` | `[7 9 13 21]` overflows, `9` goes up: `[5 9]` → `[1 2 3]`, `[7]`, `[13 21]` |
| `10` | `[5 9]` → `[1 2 3]`, `[7]`, `[10 13 21]` |
| `12` | `[10 12 13 21]` overflows, `12` goes up: `[5 9 12]` → `[1 2 3]`, `[7]`, `[10]`, `[13 21]` |
| `4` | `[1 2 3 4]` overflows, `2` goes up; the parent `[2 5 9 12]` overflows too, `5` goes up: new root `[5]` |
| `8` | goes to leaf `[7]` giving `[7 8]` |

#### Final B-tree

```text
            [ 5 ]
           /     \
       [ 2 ]     [ 9  12 ]
       /   \     /   |    \
     [1] [3 4] [7 8] [10] [13 21]
```

Height $= 3$ (root + 2 more levels). *(If the 3rd key is chosen as the median for splitting, the shape differs slightly; always state the convention you use.)*

---

### 5. Deletion Operation in a B-Tree and Applications

**Q5. Explain the deletion operation in a B-Tree with a suitable example, and the applications of B-Trees.**

#### Deletion cases (order $m$, minimum keys $= \lceil m/2 \rceil - 1$; for order 4 the minimum is 1 key)

1. **Key in a leaf with more than the minimum keys:** simply remove it.
2. **Key in a leaf with minimum keys (underflow):**
   - Borrow from a sibling that has extra keys (rotate through the parent), or
   - Merge with a sibling and the separating key from the parent if no sibling can lend.
3. **Key in an internal node:** replace it with its inorder predecessor or successor (from a leaf) and delete that key from the leaf (then apply case 1 or 2).
4. If merging makes the parent underflow, repeat upward; if the root becomes empty, the tree height shrinks by one.

#### Example (using the tree built in Q4)

Root `[5]`; internal nodes `[2]` and `[9 12]`; leaves `[1]`, `[3 4]`, `[7 8]`, `[10]`, `[13 21]`.

- **Delete `4`:** leaf `[3 4]` has 2 keys, so simply remove `4`, giving `[3]`.
- **Delete `10`:** leaf `[10]` would become empty (underflow). Its left sibling `[7 8]` has a spare key, so borrow through the parent: `9` moves down into the leaf and `8` moves up. Result: parent `[8 12]`, leaves `[7]`, `[9]`, `[13 21]`.
- **Delete `1`:** leaf `[1]` becomes empty and its sibling `[3]` has no spare key, so merge the empty leaf, the separator `2` and `[3]` into the leaf `[2 3]`. The parent `[2]` is now empty (underflow). Its sibling `[8 12]` has a spare key, so borrow through the root: `5` moves down, `8` moves up, and leaf `[7]` becomes the child of the node holding `5`.

#### Final tree after the three deletions

```text
          [ 8 ]
         /     \
     [ 5 ]     [ 12 ]
     /   \     /    \
  [2 3]  [7] [9]  [13 21]
```

#### Applications of B-trees

- Database indexes (MySQL InnoDB uses $\text{B}^+$-trees).
- File systems (NTFS, ext4, HFS+, Btrfs) for directory and metadata indexing.
- Storing large data on disk, since a node corresponds to a disk block, so tree height (disk accesses) is minimal.
- Multilevel indexing, key-value stores and search engines.
- Search, insert, delete: $O(\log n)$.

---

### 6. Construct a Min Heap and Max Heap

**Q6. Construct a Min/Max Heap by inserting the elements `40, 15, 30, 10, 12, 6, 25, 18`. Show all intermediate steps.**

#### Max Heap ($\text{parent} \ge \text{children}$)

Insert at the end, then sift up while larger than the parent.

| Insert | Array representation after insertion | Action |
|---:|---|---|
| 40 | `[40]` | root |
| 15 | `[40, 15]` | $15 < 40$, stays |
| 30 | `[40, 15, 30]` | $30 < 40$, stays |
| 10 | `[40, 15, 30, 10]` | $10 < 15$, stays |
| 12 | `[40, 15, 30, 10, 12]` | $12 < 15$, stays |
| 6 | `[40, 15, 30, 10, 12, 6]` | $6 < 30$, stays |
| 25 | `[40, 15, 30, 10, 12, 6, 25]` | $25 < 30$, stays |
| 18 | `[40, 18, 30, 15, 12, 6, 25, 10]` | $18 > 10$ swap; $18 > 15$ swap; $18 < 40$ stop |

##### Final Max Heap

```text
          40
        /    \
      18      30
     /  \    /  \
   15   12  6   25
   /
 10
```

#### Min Heap ($\text{parent} \le \text{children}$)

Sift up while smaller than the parent.

| Insert | Array after insertion | Action |
|---:|---|---|
| 40 | `[40]` | root |
| 15 | `[15, 40]` | $15 < 40$ swap |
| 30 | `[15, 40, 30]` | $30 > 15$, stays |
| 10 | `[10, 15, 30, 40]` | $10 < 40$ swap; $10 < 15$ swap (becomes root) |
| 12 | `[10, 12, 30, 40, 15]` | $12 < 15$ swap; $12 > 10$ stop |
| 6 | `[6, 12, 10, 40, 15, 30]` | $6 < 30$ swap; $6 < 10$ swap; root |
| 25 | `[6, 12, 10, 40, 15, 30, 25]` | $25 > 10$, stays |
| 18 | `[6, 12, 10, 18, 15, 30, 25, 40]` | $18 < 40$ swap; $18 > 12$ stop |

##### Final Min Heap

```text
          6
        /   \
      12     10
     /  \   /  \
   18   15 30  25
   /
 40
```

---

### 7. Deletion Operation on Given Max Heap

**Q7. Perform one deletion operation on given Max Heap and show the step-by-step process for final Max Heap.**

![Binary Max Heap Deletion](figures/unit2_q7_max_heap_deletion.png)

#### Given Max Heap
- **Tree Structure:** Complete binary tree with root `90`.
- **Level-Order Array Representation (1-based / 0-based):**
  - Indices 0 to 9: `[ 90, 60, 75, 50, 40, 30, 20, 10, 5, 8 ]`

#### Deletion Procedure (Step-by-Step Tracing)

1. **Step 1: Extract Maximum Element (Root):**
   - The root element `90` is removed (saved as the output of `deleteMax()`).
   - The **last leaf element in level-order**, which is `8` (at index 9), is moved to replace the root.
   - Array size shrinks to 9:
     ```text
     Array: [ 8, 60, 75, 50, 40, 30, 20, 10, 5 ]
     ```
2. **Step 2: Sift-Down (Heapify at Root Index 0):**
   - Compare node `8` with its left child `60` (index 1) and right child `75` (index 2).
   - Find the maximum among parent and children: $\max(8, 60, 75) = 75$.
   - Since child `75 > 8`, swap `8` with `75`:
     ```text
     Array: [ 75, 60, 8, 50, 40, 30, 20, 10, 5 ]
     ```
3. **Step 3: Continue Sift-Down (Heapify at Index 2):**
   - Node `8` is now at index 2.
   - Its left child is at index $2(2) + 1 = 5$ (value `30`) and right child at index $2(2) + 2 = 6$ (value `20`).
   - Find maximum among parent and children: $\max(8, 30, 20) = 30$.
   - Since child `30 > 8`, swap `8` with `30`:
     ```text
     Array: [ 75, 60, 30, 50, 40, 8, 20, 10, 5 ]
     ```
4. **Step 4: Termination:**
   - Node `8` is now at index 5. Its left child would be at $2(5) + 1 = 11$, which exceeds array bounds (length 9).
   - Node `8` is now a leaf. The heapify process terminates.

#### Final Verification & Time Complexity
- **Final Level-Order Array:** `[ 75, 60, 30, 50, 40, 8, 20, 10, 5 ]`
- **Heap Property Check:**
  - `75 ≥ 60, 30` (holds)
  - `60 ≥ 50, 40` (holds)
  - `30 ≥ 8, 20` (holds)
  - `50 ≥ 10, 5` (holds)
- **Time Complexity:** $O(\log n)$ (traverses down the tree height $h = \lfloor \log_2 10 \rfloor = 3$).
- **Space Complexity:** $O(1)$ auxiliary space (in-place array swaps).

---

### 8. Basic Operations of a Binary Heap and Applications of Priority Queues

**Q8. Explain the basic operations of a Binary Heap with their time complexities and discuss the applications of priority queues.**

A binary heap is a complete binary tree stored in an array that satisfies the heap property (max-heap: $\text{parent} \ge \text{children}$; min-heap: $\text{parent} \le \text{children}$). For index $i$ (0-based): $\text{parent} = \lfloor(i-1)/2\rfloor$, $\text{left child} = 2i+1$, $\text{right child} = 2i+2$.

| Operation | Description | Time |
|---|---|---|
| Insert | Add at the end, sift up | $O(\log n)$ |
| Delete-max / Delete-min (extract) | Replace root with last element, sift down | $O(\log n)$ |
| Get-max / Get-min (peek) | Return the root | $O(1)$ |
| Heapify | Restore the heap property at a node | $O(\log n)$ |
| Build-heap | Heapify all non-leaf nodes bottom-up | $O(n)$ |
| Increase/Decrease key | Change the key and sift up/down | $O(\log n)$ |
| Heap sort | Build-heap + $n$ extractions | $O(n \log n)$ |

#### Applications of priority queues (implemented with heaps)

1. Dijkstra's shortest path and Prim's MST algorithms.
2. Huffman coding (data compression).
3. Heap sort.
4. CPU/process scheduling in operating systems.
5. Event-driven simulation and load balancing.
6. Finding the $k$-th largest/smallest element; median maintenance.
7. $\text{A}^*$ search in AI and network routing/bandwidth management.
