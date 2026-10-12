# UNIT II — Balanced Trees and Heaps

> **Source:** *Advanced Data Structures & Algorithm Analysis (2501CS10) — Unit-wise Important Questions — Answers | Aditya University*

---

## 1. Construct an AVL Tree by Step-by-Step Insertion

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

### Final AVL tree

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

## 2. Four Types of AVL Tree Rotations and Applications

**Q2. Explain the four types of AVL tree rotations with suitable examples. Discuss the applications of AVL trees.**

Let $z$ be the lowest unbalanced node, $y$ its taller child, and $x$ the taller child of $y$.

### 1. LL Rotation (Right rotation) — insertion into left subtree of left child

```text
      z (+2)          y
     /               / \
    y       ->      x   z
   /
  x
```

- *Example:* insert `30, 20, 10` $\to$ root `20 (10, 30)`.

### 2. RR Rotation (Left rotation) — insertion into right subtree of right child

```text
  z (-2)              y
   \                 / \
    y       ->      z   x
     \
      x
```

- *Example:* insert `10, 20, 30` $\to$ root `20 (10, 30)`.

### 3. LR Rotation (Left–Right) — insertion into right subtree of left child

Left rotation at $y$, then right rotation at $z$.

```text
    z            z            x
   /            /            / \
  y     ->     x     ->     y   z
   \          /
    x        y
```

- *Example:* insert `30, 10, 20` $\to$ root `20 (10, 30)`.

### 4. RL Rotation (Right–Left) — insertion into left subtree of right child

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

### Applications of AVL trees

- Databases and indexing where lookups dominate insertions.
- In-memory dictionaries and sets requiring guaranteed $O(\log n)$ search.
- Lookup tables and routing tables; memory management.
- Applications that need ordered data with fast search (e.g. spell-checkers, file systems directories).
- Search, insert and delete are all $O(\log n)$ worst case.

---

## 3. Deletion Procedure in AVL Tree (Delete 15)

**Q3. Explain the deletion procedure in an AVL tree. Show the balancing operations after deletion of `15` from the given AVL tree.**

### Deletion procedure

1. Delete the node as in a BST (leaf: remove; one child: replace by child; two children: replace by inorder successor/predecessor and delete that node).
2. Walk back up to the root, updating heights and balance factors.
3. At the first unbalanced node, perform the suitable rotation (LL, RR, LR, RL). For deletion, the rotation type is chosen by the balance factor of the taller child (if it is $0$, a single rotation is used).
4. Continue upward, because a rotation may reduce the height and cause further imbalance (unlike insertion, more than one rotation may be needed).

### Given tree

Root `50`: `50 (25 (15, 40 (35, –)), 75 (60 (55, 65 (62, –)), 80 (–, 90)))`.

```text
              50
            /    \
          25      75
         /  \    /  \
       15   40  60   80
           /   /  \    \
         35   55  65    90
                 /
               62
```

### Delete 15 (a leaf)

1. Remove `15`. Node `25` now has no left child and right child `40` (height 2): balance factor $= -2$.
2. The right child `40` is left-heavy (it has left child `35`), so this is the RL case. Right rotate at `40`, then left rotate at `25`. Result: `35 (25, 40)`.
3. Moving up, the subtree at `35` now has height 2 while the right subtree of `50` (rooted at `75`) has height 4: node `50` has balance factor $= -2$.
4. The right child `75` is left-heavy (`60` side is taller), so again an RL case: right rotate at `75`, then left rotate at `50`. Node `60` becomes the new root.

### Final tree after deletion of 15

```text
          60
        /    \
      50      75
     /  \    /  \
   35   55  65   80
  /  \     /       \
 25  40   62       90
```

All balance factors are within $\{-1, 0, +1\}$. Two double (RL) rotations were required.

---

## 4. Construct a B-Tree of Order 4

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

### Final B-tree

```text
            [ 5 ]
           /     \
       [ 2 ]     [ 9  12 ]
       /   \     /   |    \
     [1] [3 4] [7 8] [10] [13 21]
```

Height $= 3$ (root + 2 more levels). *(If the 3rd key is chosen as the median for splitting, the shape differs slightly; always state the convention you use.)*

---

## 5. Deletion Operation in a B-Tree and Applications

**Q5. Explain the deletion operation in a B-Tree with a suitable example, and the applications of B-Trees.**

### Deletion cases (order $m$, minimum keys $= \lceil m/2 \rceil - 1$; for order 4 the minimum is 1 key)

1. **Key in a leaf with more than the minimum keys:** simply remove it.
2. **Key in a leaf with minimum keys (underflow):**
   - Borrow from a sibling that has extra keys (rotate through the parent), or
   - Merge with a sibling and the separating key from the parent if no sibling can lend.
3. **Key in an internal node:** replace it with its inorder predecessor or successor (from a leaf) and delete that key from the leaf (then apply case 1 or 2).
4. If merging makes the parent underflow, repeat upward; if the root becomes empty, the tree height shrinks by one.

### Example (using the tree built in Q4)

Root `[5]`; internal nodes `[2]` and `[9 12]`; leaves `[1]`, `[3 4]`, `[7 8]`, `[10]`, `[13 21]`.

- **Delete `4`:** leaf `[3 4]` has 2 keys, so simply remove `4`, giving `[3]`.
- **Delete `10`:** leaf `[10]` would become empty (underflow). Its left sibling `[7 8]` has a spare key, so borrow through the parent: `9` moves down into the leaf and `8` moves up. Result: parent `[8 12]`, leaves `[7]`, `[9]`, `[13 21]`.
- **Delete `1`:** leaf `[1]` becomes empty and its sibling `[3]` has no spare key, so merge the empty leaf, the separator `2` and `[3]` into the leaf `[2 3]`. The parent `[2]` is now empty (underflow). Its sibling `[8 12]` has a spare key, so borrow through the root: `5` moves down, `8` moves up, and leaf `[7]` becomes the child of the node holding `5`.

### Final tree after the three deletions

```text
          [ 8 ]
         /     \
     [ 5 ]     [ 12 ]
     /   \     /    \
  [2 3]  [7] [9]  [13 21]
```

### Applications of B-trees

- Database indexes (MySQL InnoDB uses $\text{B}^+$-trees).
- File systems (NTFS, ext4, HFS+, Btrfs) for directory and metadata indexing.
- Storing large data on disk, since a node corresponds to a disk block, so tree height (disk accesses) is minimal.
- Multilevel indexing, key-value stores and search engines.
- Search, insert, delete: $O(\log n)$.

---

## 6. Construct a Min Heap and Max Heap

**Q6. Construct a Min/Max Heap by inserting the elements `40, 15, 30, 10, 12, 6, 25, 18`. Show all intermediate steps.**

### Max Heap ($\text{parent} \ge \text{children}$)

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

#### Final Max Heap

```text
          40
        /    \
      18      30
     /  \    /  \
   15   12  6   25
   /
 10
```

### Min Heap ($\text{parent} \le \text{children}$)

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

#### Final Min Heap

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

## 7. Deletion Operation on Given Max Heap

**Q7. Perform one deletion operation on the given Max Heap and show the step-by-step process for the final Max Heap.**

**Given Max Heap (array form):** `[90, 60, 75, 50, 40, 30, 20, 10, 5, 8]`

The standard deletion is **delete-max** (remove the root `90`):

1. Remove the root `90` and replace it with the last element `8`; reduce the size by 1.
   - Array: `[8, 60, 75, 50, 40, 30, 20, 10, 5]`
2. **Heapify down (sift down):** compare `8` with its children `60` and `75`. The larger is `75`, so swap.
   - Array: `[75, 60, 8, 50, 40, 30, 20, 10, 5]`
3. `8` is now at index 2 with children `30` and `20`. The larger is `30`, so swap.
   - Array: `[75, 60, 30, 50, 40, 8, 20, 10, 5]`
4. `8` has no children now; stop.

### Final Max Heap

```text
          75
        /    \
      60      30
     /  \    /  \
   50   40  8   20
  /  \
10    5
```

Every parent is greater than or equal to its children. Deleted element: `90`. Time $= O(\log n)$.

---

## 8. Basic Operations of a Binary Heap and Applications of Priority Queues

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

### Applications of priority queues (implemented with heaps)

1. Dijkstra's shortest path and Prim's MST algorithms.
2. Huffman coding (data compression).
3. Heap sort.
4. CPU/process scheduling in operating systems.
5. Event-driven simulation and load balancing.
6. Finding the $k$-th largest/smallest element; median maintenance.
7. $\text{A}^*$ search in AI and network routing/bandwidth management.
