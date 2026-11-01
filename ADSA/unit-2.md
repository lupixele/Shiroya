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

An AVL tree is a self-balancing Binary Search Tree where every node satisfies:
$$\text{Balance Factor (BF)} = \text{height}(\text{left subtree}) - \text{height}(\text{right subtree}) \in \{-1, 0, +1\}$$
If any node has $BF = \pm 2$, a rotation ($LL, RR, LR, RL$) is performed to restore balance.

---

#### Step-by-Step Construction with Visual Trees

##### Step 1: Insert 50
```text
  50 (0)
```

##### Step 2: Insert 25
```text
    50 (1)
   /
 25 (0)
```

##### Step 3: Insert 12 (LL Imbalance at 50)
- `12` is inserted into the left subtree of left child `25`.
- Node `50` gets $BF = 2$ (Unbalanced $\implies$ **LL Case**).
- **Fix:** Perform **Single Right Rotation** at node `50`:

```text
       50 (2)                      25 (0)
      /                           /      \
    25 (1)         ====>        12 (0)   50 (0)
   /
 12 (0)
```

##### Step 4: Insert 80
`80` is $> 25$ and $> 50$, goes to right of `50`:
```text
      25 (-1)
     /      \
  12 (0)   50 (-1)
              \
              80 (0)
```

##### Step 5: Insert 90 (RR Imbalance at 25)
- `90` goes to right of `80`.
- Node `25` gets $BF = -2$ (Unbalanced $\implies$ **RR Case** at node `50`).
- **Fix:** Perform **Single Left Rotation** at node `50`:

```text
       25 (-2)                              25 (-1)
      /      \                             /      \
   12 (0)    50 (-2)        ====>       12 (0)    80 (0)
                \                                /      \
                80 (-1)                        50 (0)   90 (0)
                   \
                   90 (0)
```

##### Step 6: Insert 37 (RL Imbalance at 25)
- `37` goes to left of `50`. Node `25` gets $BF = -2$ (right-heavy), right child `80` has left subtree $\implies$ **RL Case**.
- **Fix:** **Double Rotation** (Right-rotate at `80`, then Left-rotate at `25`).
- Node `50` rises to become the new root of the entire tree:

```text
               25 (-2)                                 50 (0)
              /      \                               /        \
           12 (0)    80 (1)         ====>         25 (0)      80 (-1)
                    /      \                     /      \           \
                  50 (1)   90 (0)              12 (0)   37 (0)      90 (0)
                 /
               37 (0)
```

##### Step 7: Insert 45
`45` goes to right child of `37`:
```text
               50 (0)
             /        \
         25 (0)       80 (-1)
        /      \            \
      12 (0)   37 (-1)      90 (0)
                 \
                 45 (0)
```
*(All balance factors are within $\{-1, 0, +1\}$; tree remains balanced).*

##### Step 8: Insert 18
`18` goes to right child of `12`:
```text
               50 (1)
             /        \
         25 (1)       80 (-1)
        /      \            \
     12 (-1)   37 (-1)      90 (0)
        \        \
        18 (0)   45 (0)
```

##### Step 9: Insert 19 (RR Imbalance at 12)
- `19` goes to right of `18`. Node `12` gets $BF = -2$ (RR Case).
- **Fix:** Perform **Single Left Rotation** at node `12`:

```text
      12 (-2)                          18 (0)
         \                            /      \
         18 (-1)       ====>       12 (0)    19 (0)
            \
            19 (0)
```

- Resulting tree:
```text
               50 (1)
             /        \
         25 (1)       80 (-1)
        /      \            \
     18 (0)    37 (-1)      90 (0)
    /      \     \
  12 (0)  19(0)  45 (0)
```

##### Step 10: Insert 6 (LL Imbalance at 50)
- `6` goes to left of `12`.
- Left subtree of `50` reaches height 4, right subtree is height 2 $\implies$ Node `50` gets $BF = +2$.
- Left child `25` has $BF = +1$ (left-heavy $\implies$ **LL Case**).
- **Fix:** Perform **Single Right Rotation** at root node `50`. Node `25` becomes the new root!

```text
                  50 (2)                                      25 (0)
                /        \                                  /        \
             25 (1)      80 (-1)                         18 (0)      50 (0)
            /      \           \          ====>         /      \    /      \
         18 (0)    37 (-1)     90 (0)                12 (1)   19(0) 37(-1) 80(-1)
        /      \     \                              /               \       \
      12 (1)  19(0)  45 (0)                        6 (0)            45(0)   90(0)
     /
    6 (0)
```

#### Final AVL Tree
```text
                 25 (0)
               /        \
           18 (0)       50 (0)
          /      \     /      \
        12 (1)  19(0) 37 (-1) 80 (-1)
       /                \       \
      6 (0)             45 (0)  90 (0)
```

- **Height:** 4 levels.
- **Verification:** Every node has $BF \in \{-1, 0, +1\}$.
- **Rotations Applied:** 2 Single Right (LL at `50`), 2 Single Left (RR at `50` and `12`), 1 Double (RL at `25`).

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

**Tree Immediately After Deleting 15:**
```text
              50 (0)
            /        \
        25 (-2)*     75 (1)
              \     /      \
             40(1) 60 (-1) 80 (-1)
            /     /   \       \
          35(0) 55(0) 65(1)   90(0)
                      /
                    62(0)
```
*Node 25 is unbalanced ($BF = -2$)*

---

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

---

##### Step 3: Identify Imbalance & Apply RL Rotation
- At node `25`: $BF(25) = -2$ (Right heavy).
- Right child `40`: $BF(40) = +1$ (Left heavy).
- **Condition:** Right-Left (RL) Case $\implies$ Requires **Double RL Rotation** at node `25`:

**Sub-step 3.1: Right Rotation at Node 40:**
```text
        25 (-2)                        25 (-2)
           \                              \
          40 (1)         ====>            35 (0)
         /                                  \
       35 (0)                               40 (0)
```

**Sub-step 3.2: Left Rotation at Node 25:**
```text
        25 (-2)                        35 (0)
           \                          /      \
          35 (0)         ====>     25 (0)   40 (0)
            \
            40 (0)
```
Node `35` rises to become the new parent of `25` and `40`!

---

##### Step 4: Final Verification & Balanced Tree

```text
                  50 (0)
                /        \
            35 (0)       75 (1)
           /      \     /      \
         25 (0)  40(0) 60 (-1) 80 (-1)
                      /   \       \
                    55(0) 65(1)   90(0)
                          /
                        62(0)
```

- The restructured subtree rooted at `35 (25, 40)` has height 2.
- At root `50`: left subtree height = 3 (via path `50 → 35 → 25`), right subtree height = 3 (via `50 → 75 → 60 → 65 → 62`).
- Balance factor at root $50 = 3 - 3 = 0$.
- **All nodes satisfy $BF \in \{-1, 0, +1\}$.** Tree is a valid balanced AVL tree.

---

### 4. Construct a B-Tree of Order 4

**Q4. Construct a B-Tree of order 4 by inserting the keys `5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`.**

#### Structural Rules (Order $m = 4$)
- **Maximum children per node:** $m = 4$
- **Maximum keys per node:** $m - 1 = 3$
- **Minimum children (non-root internal):** $\lceil m / 2 \rceil = 2$
- **Minimum keys (non-root):** $\lceil m / 2 \rceil - 1 = 1$
- **Overflow & Splitting:** When a node reaches 4 keys, it splits. The median key (2nd key) is promoted up to its parent.

---

#### Step-by-Step Construction Tracing

##### Step 1: Insert 5, 3, 21
Keys fit into the root node in sorted order:
```text
[ 3  5  21 ]
```

---

##### Step 2: Insert 9 (Root Overflows & Splits)
- Inserting `9` produces `[ 3  5  9  21 ]` (4 keys $\implies$ Overflow!).
- Split at median key `5`. Key `5` moves up to form the new root:
```text
        [ 5 ]
       /     \
    [ 3 ]   [ 9  21 ]
```

---

##### Step 3: Insert 1, 13, 2
- `1` and `2` are $< 5$, inserted into left leaf `[ 3 ]` $\to `[ 1  2  3 ]`.
- `13` is $> 5$, inserted into right leaf `[ 9  21 ]` $\to `[ 9  13  21 ]`.
```text
          [ 5 ]
         /     \
    [ 1  2  3 ]   [ 9  13  21 ]
```

---

##### Step 4: Insert 7 (Right Leaf Overflows & Splits)
- `7` is $> 5$, goes into right leaf $\to `[ 7  9  13  21 ]` (Overflow!).
- Split at median `9`. Key `9` moves up to the root:
```text
          [ 5   9 ]
         /    |    \
   [ 1 2 3 ] [ 7 ] [ 13 21 ]
```

---

##### Step 5: Insert 10, 12 (Rightmost Leaf Overflows & Splits)
- `10` is $> 9$, goes into `[ 13  21 ]` $\to `[ 10  13  21 ]`.
- `12` is $> 9$, goes into `[ 10  13  21 ]` $\to `[ 10  12  13  21 ]` (Overflow!).
- Split at median `12`. Key `12` moves up to the root:
```text
           [ 5   9   12 ]
          /    |   \     \
    [ 1 2 3 ] [ 7 ] [ 10 ] [ 13 21 ]
```

---

##### Step 6: Insert 4 (Double Split: Leaf & Root Overflow)
- `4` is $< 5$, goes into left leaf `[ 1  2  3 ]` $\to `[ 1  2  3  4 ]` (Overflow!).
- **Leaf Split:** Split at median `2`. Key `2` moves up to parent root.
- **Root Overflow:** Root now contains `[ 2  5  9  12 ]` (4 keys $\implies$ Overflows!).
- **Root Split:** Split at median `5`. Key `5` becomes the new root; tree height increases:
```text
                 [ 5 ]
                /     \
            [ 2 ]     [ 9   12 ]
           /     \    /   |    \
        [ 1 ]  [ 3 4 ] [ 7 ] [ 10 ] [ 13 21 ]
```

---

##### Step 7: Insert 8 (Final Insertion)
- `8` falls between `5` and `9`, so it enters leaf `[ 7 ]` to become `[ 7  8 ]` (fits without overflow):

```text
                 [ 5 ]
                /     \
            [ 2 ]     [ 9   12 ]
           /     \    /   |    \
        [ 1 ]  [ 3 4 ] [ 7 8 ] [ 10 ] [ 13 21 ]
```

- **Height:** 3 levels (Root + 1 internal level + Leaves).
- **All B-tree properties hold:** every non-root has 1–3 keys, all leaves are at the exact same depth.

---

### 5. Deletion Operation in a B-Tree and Applications

**Q5. Explain the deletion operation in a B-Tree with a suitable example, and the applications of B-Trees.**

#### Deletion Rules (Order $m = 4$, Minimum Keys $= 1$)
1. **Case 1 (Leaf with $\ge 2$ keys):** Simply remove the key. No rebalancing needed.
2. **Case 2 (Leaf with minimum 1 key — Underflow):**
   - **Case 2A (Borrow from Sibling):** If an immediate sibling has $\ge 2$ keys, borrow a key via rotation through the parent.
   - **Case 2B (Merge with Sibling):** If both immediate siblings have only 1 key, merge the node with a sibling and pull down the separating key from the parent.
3. **Case 3 (Internal Node):** Replace the key with its inorder predecessor (largest in left subtree) or inorder successor (smallest in right subtree), then delete that key from the leaf.
4. **Case 4 (Shrinking Height):** If root loses all keys during a merge, its sole child becomes the new root.

---

#### Step-by-Step Deletion Example (Starting from Q4 Final Tree)

**Initial B-Tree:**
```text
                 [ 5 ]
                /     \
            [ 2 ]     [ 9   12 ]
           /     \    /   |    \
        [ 1 ]  [ 3 4 ] [ 7 8 ] [ 10 ] [ 13 21 ]
```

---

##### Step 1: Delete 4 (Case 1: Leaf with Extra Keys)
- Node `[ 3  4 ]` has 2 keys (minimum required is 1).
- Simply delete `4`. The node retains `[ 3 ]` with no underflow:
```text
                 [ 5 ]
                /     \
            [ 2 ]     [ 9   12 ]
           /     \    /   |    \
        [ 1 ]   [ 3 ]  [ 7 8 ] [ 10 ] [ 13 21 ]
```

---

##### Step 2: Delete 10 (Case 2A: Underflow $\to$ Borrow from Left Sibling)
- Delete `10` from leaf `[ 10 ]` $\implies$ node becomes empty `[ ]` (Underflow!).
- Look at left sibling `[ 7  8 ]`: it has 2 keys (can spare key `8`).
- **Borrow via parent `[ 9  12 ]`:**
  - Sibling's largest key `8` moves up to parent.
  - Parent separator key `9` moves down into the empty leaf:
```text
                 [ 5 ]
                /     \
            [ 2 ]     [ 8   12 ]
           /     \    /   |    \
        [ 1 ]   [ 3 ]  [ 7 ]  [ 9 ] [ 13 21 ]
```

---

##### Step 3: Delete 1 (Case 2B & Case 4: Merge Siblings & Parent Borrow)
- Delete `1` from leaf `[ 1 ]` $\implies$ node becomes empty `[ ]` (Underflow!).
- Sibling `[ 3 ]` has only 1 key (cannot lend).
- **Action 3.1: Merge Leaves & Parent Key:**
  - Merge empty leaf + parent key `2` + sibling `[ 3 ]` into leaf `[ 2  3 ]`.
  - Parent node `[ 2 ]` loses key `2` and becomes empty `[ ]` (Underflow at parent level!).
- **Action 3.2: Resolve Parent Underflow:**
  - Parent's sibling `[ 8  12 ]` has 2 keys (can spare key `8`).
  - Borrow via root `[ 5 ]`:
    - Root key `5` moves down to left internal node.
    - Sibling's first key `8` moves up to become the new root.
    - Sibling's child `[ 7 ]` moves across to become right child of `[ 5 ]`.

**Final Tree After Deletions:**
```text
            [ 8 ]
           /     \
       [ 5 ]     [ 12 ]
       /   \     /    \
    [ 2 3 ] [ 7 ] [ 9 ] [ 13 21 ]
```

---

#### Real-World Applications of B-Trees
1. **Database Indexing:** Powers primary and secondary B-tree indexes in relational databases (MySQL InnoDB, PostgreSQL, Oracle).
2. **File Systems:** Manages directory hierarchies and file allocation blocks in modern file systems (NTFS, ext4, HFS+, Btrfs).
3. **Minimizing Disk I/O:** Designed specifically for block storage; a single disk block holds a large node, keeping tree height extremely low ($O(\log_m n)$).
4. **Multilevel Indexing:** Ideal for massive datasets that do not fit into RAM.
5. **Guaranteed Efficiency:** Search, insert, and delete operations all complete in $O(\log n)$ worst-case time.

---

### 6. Construct a Min Heap and Max Heap

**Q6. Construct a Min/Max Heap by inserting the elements `40, 15, 30, 10, 12, 6, 25, 18`. Show all intermediate steps.**

#### Max Heap ($\text{parent} \ge \text{children}$)

#### 1. Max Heap Construction ($\text{Parent} \ge \text{Children}$)

In a Max-Heap, each newly inserted element is placed at the next available leaf position (left-to-right at the bottom level) and then **sifted up (heapified up)** by swapping with its parent while it is greater than the parent.

##### Step 1: Insert 40, 15, 30
- `40` is root. `15` and `30` are smaller than `40`, so they stay in place:
```text
      40
     /  \
   15    30
```
*Array: `[ 40, 15, 30 ]`*

---

##### Step 2: Insert 10, 12
- `10` and `12` are added as left and right children of `15`. Since $10 < 15$ and $12 < 15$, no swaps needed:
```text
        40
       /  \
     15    30
    /  \
  10    12
```
*Array: `[ 40, 15, 30, 10, 12 ]`*

---

##### Step 3: Insert 6, 25
- `6` and `25` are added as left and right children of `30`. Since $6 < 30$ and $25 < 30$, no swaps needed:
```text
        40
       /  \
     15    30
    /  \   /  \
  10   12 6   25
```
*Array: `[ 40, 15, 30, 10, 12, 6, 25 ]`*

---

##### Step 4: Insert 18 (Sift-Up Swaps)
1. `18` is placed at index 7 (left child of `10`):
```text
          40
         /  \
       15    30
      /  \   /  \
    10   12 6   25
    /
  18 (greater than parent 10!)
```
2. **Swap 1:** $18 > 10 \implies$ Swap `18` with parent `10`.
3. **Swap 2:** $18 > 15 \implies$ Swap `18` with parent `15`.
4. $18 < 40 \implies$ Sift-up terminates.

##### Final Max Heap Tree
```text
          40
        /    \
      18      30
     /  \    /  \
   15   12  6   25
   /
 10
```
*Final Array: `[ 40, 18, 30, 15, 12, 6, 25, 10 ]`*

---

#### 2. Min Heap Construction ($\text{Parent} \le \text{Children}$)

In a Min-Heap, every parent must be $\le$ its children. Each element is added at the end and **sifted up** while it is smaller than its parent.

##### Step 1: Insert 40, 15, 30
- Insert `40` (root).
- Insert `15`: $15 < 40 \implies$ Swap with `40`. Node `15` becomes root.
- Insert `30`: $30 > 15$, stays as right child:
```text
      15
     /  \
   40    30
```
*Array: `[ 15, 40, 30 ]`*

---

##### Step 2: Insert 10 (Sifts to Root)
- Insert `10` as left child of `40`.
- $10 < 40 \implies$ Swap with `40`.
- $10 < 15 \implies$ Swap with `15`. Node `10` becomes root!
```text
        10
       /  \
     15    30
    /
  40
```
*Array: `[ 10, 15, 30, 40 ]`*

---

##### Step 3: Insert 12
- Insert `12` as right child of `15`.
- $12 < 15 \implies$ Swap with `15`. $12 > 10$, stop:
```text
        10
       /  \
     12    30
    /  \
  40    15
```
*Array: `[ 10, 12, 30, 40, 15 ]`*

---

##### Step 4: Insert 6 (Sifts to Root)
- Insert `6` as left child of `30`.
- $6 < 30 \implies$ Swap with `30`.
- $6 < 10 \implies$ Swap with root `10`. Node `6` becomes root!
```text
        6
       /  \
     12    10
    /  \   /
  40   15 30
```
*Array: `[ 6, 12, 10, 40, 15, 30 ]`*

---

##### Step 5: Insert 25, 18
- Insert `25` as right child of `10`: $25 > 10$, stays.
- Insert `18` as left child of `40`: $18 < 40 \implies$ Swap with `40`. $18 > 12$, stop.

##### Final Min Heap Tree
```text
          6
        /   \
      12     10
     /  \   /  \
   18   15 30  25
   /
 40
```
*Final Array: `[ 6, 12, 10, 18, 15, 30, 25, 40 ]`*

---

### 7. Deletion Operation on Given Max Heap

**Q7. Perform one deletion operation on given Max Heap and show the step-by-step process for final Max Heap.**

![Binary Max Heap Deletion](figures/unit2_q7_max_heap_deletion.png)

#### Given Max Heap
- **Complete Binary Tree with Root `90`:**
```text
             90
          /      \
        60        75
       /  \      /  \
     50    40  30    20
    /  \   /
  10    5 8
```
- **Level-Order Array:** `[ 90, 60, 75, 50, 40, 30, 20, 10, 5, 8 ]`

---

#### Step-by-Step Deletion Procedure (Visual Tracing)

##### Step 1: Remove Root `90` and Move Last Element `8` to Root
- Root `90` is deleted.
- The last element in level-order, `8` (at index 9), replaces the root:
```text
             8 (Root)
          /      \
        60        75
       /  \      /  \
     50    40  30    20
    /  \
  10    5
```
*Array: `[ 8, 60, 75, 50, 40, 30, 20, 10, 5 ]`*

---

##### Step 2: Sift-Down at Root (Compare 8 with Children 60 and 75)
- Children of `8` are `60` and `75`.
- Largest child is `75`. Since $75 > 8$, swap `8` with `75`:
```text
             75
          /      \
        60        8 (swapped)
       /  \      /  \
     50    40  30    20
    /  \
  10    5
```
*Array: `[ 75, 60, 8, 50, 40, 30, 20, 10, 5 ]`*

---

##### Step 3: Continue Sift-Down at Index 2 (Compare 8 with Children 30 and 20)
- Node `8` now has children `30` (index 5) and `20` (index 6).
- Largest child is `30`. Since $30 > 8$, swap `8` with `30`:
```text
             75
          /      \
        60        30
       /  \      /  \
     50    40  8     20
    /  \
  10    5
```
*Array: `[ 75, 60, 30, 50, 40, 8, 20, 10, 5 ]`*

---

##### Step 4: Termination & Final Balanced Max Heap
- Node `8` is now at index 5. Its left child index would be $2(5) + 1 = 11 > 9$ (array length).
- `8` has no children (it is a leaf). The heapify process halts.

```text
             75
          /      \
        60        30
       /  \      /  \
     50    40  8     20
    /  \
  10    5
```

- **Output:** Deleted maximum element = `90`.
- **Final Level-Order Array:** `[ 75, 60, 30, 50, 40, 8, 20, 10, 5 ]`.
- **Time Complexity:** $O(\log n)$ (sifts down along tree height $h = 3$).
- **Space Complexity:** $O(1)$ in-place swaps.

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
