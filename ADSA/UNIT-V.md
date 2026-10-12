# UNIT V

## 1. Backtracking: General Methodology, State-Space Tree, Bounding Conditions, and Comparison with Exhaustive Search

**Question:** Explain the general methodology of Backtracking. Discuss the state-space tree, and its basic terms, and the role of bounding conditions. Illustrate the Backtracking approach with a suitable example and distinguish it from the exhaustive search technique. (8 marks)

### Definition and General Methodology

**Backtracking** is a systematic, depth-first search (DFS) algorithm-design strategy used to find one or all solutions to combinatorial and constraint-satisfaction problems.

The desired solution is expressed as an $n$-tuple $(x_1, x_2, \dots, x_n)$ where each component $x_k$ is chosen from a finite set $S_k$. Backtracking constructs the solution tuple one component at a time:
1. At stage $k$, given a partial vector $(x_1, x_2, \dots, x_{k-1})$, select a candidate value for $x_k \in S_k$.
2. Test whether $(x_1, x_2, \dots, x_k)$ satisfies the problem constraints using a **bounding (criterion/promising) function** $B_k(x_1, \dots, x_k)$.
3. If **promising** ($B_k = \text{true}$), advance to stage $k + 1$ (or record the solution if $k = n$).
4. If **non-promising** ($B_k = \text{false}$) or all choices in $S_k$ are exhausted, **backtrack** to stage $k - 1$ and try the next candidate for $x_{k-1}$.

#### Types of Constraints
- **Explicit Constraints:** Rules that restrict each $x_i$ to take values only from a given set $S_i$ (e.g., $x_i \in \{0, 1\}$ in 0/1 Knapsack, or $x_i \in \{1, 2, \dots, n\}$ in $N$-Queens).
- **Implicit Constraints:** Rules that specify how the components $x_i$ must relate to one another to form a valid solution (e.g., no two queens share a column or diagonal; total subset weight $= M$).

---

### State-Space Tree and Basic Terminology

The set of all possible tuples satisfying the explicit constraints is organized into a hierarchical tree structure called the **State-Space Tree**.

| Term | Definition |
|---|---|
| **Problem State** | Every node in the state-space tree, representing a partial tuple $(x_1, \dots, x_k)$ generated so far. |
| **Solution State** | A problem state $S$ for which the path from the root to $S$ defines a tuple in the solution space (satisfying all explicit constraints). |
| **Answer State** | A solution state that also satisfies all **implicit constraints** (i.e., a valid complete solution to the problem). |
| **State-Space Tree** | The tree organization of the solution space; the root is at level $0$, and paths of length $n$ represent complete candidate tuples. |
| **Live Node** | A node that has been generated, but whose children have not yet all been generated. |
| **E-Node (Expanding Node)** | The live node whose children are currently being generated and examined. |
| **Dead Node** | A generated node that is either pruned by the bounding function (non-promising) or has already had all of its children expanded. |

---

### Role of Bounding Conditions (Promising Functions)

A **bounding condition** (or **criterion function** $B_k(x_1, x_2, \dots, x_k)$) evaluates at depth $k$ whether the partial assignment $(x_1, \dots, x_k)$ can possibly be extended to an **answer state**:
- If $B_k(x_1, \dots, x_k) = \text{false}$, the entire subtree rooted at that node is **pruned (killed)** immediately without generating any of its descendants.
- This reduces the number of nodes explored from exponential/factorial ($n^n$ or $2^n$) to a small fraction of the full tree.

### Recursive Control Abstraction

```text
BACKTRACK(k)
// x[1..k-1] have already been assigned values.
1. for each x[k] in S_k do:
2.     if B_k(x[1], x[2], ..., x[k]) is TRUE then:
3.         if (x[1], ..., x[k]) is an Answer State then:
4.             Print(x[1..k])
5.         if k < n then:
6.             BACKTRACK(k + 1)
```

---

### Illustrative Example

**Problem:** Find all 3-element subsets of $\{1, 2, 3\}$ or binary strings $(x_1, x_2, x_3) \in \{0, 1\}^3$ that do **not** contain two consecutive `1`s ($x_i = 1 \text{ and } x_{i+1} = 1$ is forbidden).

- **Bounding condition:** $B_k$ returns `false` as soon as $x_{k-1} = 1$ and $x_k = 1$.

```text
                       Root ()
                      /       \
                 x1=0           x1=1
                /    \         /    \
             x2=0    x2=1   x2=0    x2=1 [PRUNED: consecutive 1s]
             /  \    /  \   /  \
            0    1  0   1  0    1
                    (X)
```
When $(x_1=1, x_2=1)$ is reached at level 2, $B_2$ prunes the node immediately, avoiding generating $(1, 1, 0)$ and $(1, 1, 1)$.

---

### Backtracking vs. Exhaustive Search (Brute Force)

| Feature | Backtracking | Exhaustive Search (Brute Force) |
|---|---|---|
| **Core Idea** | Builds candidate solutions incrementally and abandons invalid partial paths immediately. | Generates every complete candidate solution first and tests each one at the end. |
| **Constraint Checking** | Checks constraints **at every level** ($k = 1, 2, \dots, n$) using bounding functions. | Checks constraints only at the **leaf level** ($k = n$). |
| **Pruning** | Prunes entire subtrees of non-promising nodes early. | No pruning; explores 100% of the state-space tree. |
| **Computational Efficiency** | Much faster in practice due to early subtree elimination. | Extremely slow for large $n$ (always explores all $2^n$ or $n!$ leaves). |
| **Example (4-Queens)** | Explores only a small subset of nodes (prunes invalid column/diagonal placements). | Tests all $\binom{16}{4} = 1820$ or $4^4 = 256$ placements blindly. |

**Conclusion:** Backtracking combines depth-first state-space traversal with bounding conditions to prune invalid subtrees early, making it far superior to blind exhaustive search.

---

## 2. 4-Queens Problem Using Backtracking

**Question:** Apply the Backtracking technique to solve the 4-Queens problem. Draw the state-space tree, demonstrate the placement of queens' row by row, and identify the safe and unsafe positions. Show all distinct solutions and explain how the promising function eliminates invalid configurations. (8 marks)

### Problem Formulation

Place $4$ queens $Q_1, Q_2, Q_3, Q_4$ on a $4 \times 4$ chessboard such that no two queens attack each other (no two queens share the same **row**, **column**, or **diagonal**).

- **Solution Tuple:** $(x_1, x_2, x_3, x_4)$, where $x_k \in \{1, 2, 3, 4\}$ denotes the **column number** of the queen placed in **row $k$** (this automatically prevents any two queens from sharing the same row).

---

### Promising Function (`Place(k, i)`)

When placing Queen $k$ in row $k$ and column $i$, it conflicts with a previously placed Queen $j$ ($1 \le j \le k-1$) at $(j, x_j)$ if and only if:
1. **Same Column:** $x_j == i$
2. **Same Diagonal:** $|x_j - i| == |j - k|$

```text
PLACE(k, i)
// Returns true if a queen can be placed in row k and column i.
1. for j = 1 to k - 1 do:
2.     if (x[j] == i) or (abs(x[j] - i) == abs(j - k)) then:
3.         return FALSE
4. return TRUE
```

---

### Row-by-Row Placement Trace (Safe vs. Unsafe Positions)

#### Branch 1: Try Row 1 at Column 1 ($x_1 = 1$)
- **Row 1:** $x_1 = 1$ (Safe).
- **Row 2:**
  - $x_2 = 1$: Unsafe (same column as $Q_1$).
  - $x_2 = 2$: Unsafe (diagonal with $Q_1$: $|1-2| = |1-2| = 1$).
  - $x_2 = 3$: **Safe** $\to (1, 3)$.
    - **Row 3 (from $x_1=1, x_2=3$):**
      - $x_3 = 1$: Unsafe (col 1).
      - $x_3 = 2$: Unsafe (diagonal with $Q_2$ at $(2,3)$).
      - $x_3 = 3$: Unsafe (col 3).
      - $x_3 = 4$: Unsafe (diagonal with $Q_2$ at $(2,3)$).
      - **Dead end!** Backtrack to Row 2.
  - $x_2 = 4$: **Safe** $\to (1, 4)$.
    - **Row 3 (from $x_1=1, x_2=4$):**
      - $x_3 = 1$: Unsafe (col 1).
      - $x_3 = 2$: **Safe** $\to (1, 4, 2)$.
        - **Row 4 (from $1, 4, 2$):**
          - $x_4 = 1$ (col 1), $x_4 = 2$ (col 2), $x_4 = 3$ (diagonal with $Q_3$ at $(3,2)$), $x_4 = 4$ (col 4) $\to$ **All unsafe! Dead end!**
      - $x_3 = 3, 4$: Unsafe.
- **Backtrack to Row 1!** ($x_1 = 1$ yields no solution).

---

#### Branch 2: Try Row 1 at Column 2 ($x_1 = 2$)
- **Row 1:** $x_1 = 2$ (**Safe**).
- **Row 2:**
  - $x_2 = 1$: Unsafe (diagonal with $(1,2)$).
  - $x_2 = 2$: Unsafe (col 2).
  - $x_2 = 3$: Unsafe (diagonal with $(1,2)$).
  - $x_2 = 4$: **Safe** $\to (2, 4)$.
- **Row 3 (from $x_1=2, x_2=4$):**
  - $x_3 = 1$: **Safe** $\to (2, 4, 1)$.
- **Row 4 (from $2, 4, 1$):**
  - $x_4 = 1$: Unsafe (col 1).
  - $x_4 = 2$: Unsafe (col 2 & diagonal with $(3,1)$).
  - $x_4 = 3$: **Safe!** $\to \mathbf{(2, 4, 1, 3)}$ (**Solution 1 Found!**)

---

#### Branch 3: Try Row 1 at Column 3 ($x_1 = 3$)
By mirror symmetry with Branch 2:
- **Row 1:** $x_1 = 3$ (**Safe**).
- **Row 2:** $x_2 = 1$ (**Safe** $\to (3, 1)$).
- **Row 3:** $x_3 = 4$ (**Safe** $\to (3, 1, 4)$).
- **Row 4:** $x_4 = 2$ (**Safe!** $\to \mathbf{(3, 1, 4, 2)}$ (**Solution 2 Found!**)).

---

#### Branch 4: Try Row 1 at Column 4 ($x_1 = 4$)
Symmetric to Branch 1:
- $x_2 = 1 \to x_3 = 3$ (Row 4 has no safe column — pruned).
- $x_2 = 2$ (Row 3 has no safe column — pruned).

---

### State-Space Tree for 4-Queens

```text
                                      Root ()
               /                     /               \                     \
          x1 = 1                 x1 = 2             x1 = 3                 x1 = 4
          /    \                   |                  |                    /    \
       x2=3    x2=4              x2=4               x2=1                x2=1    x2=2
       (X)      |                  |                  |                  |      (X)
              x3=2               x3=1               x3=4               x3=3
              (X)                  |                  |                 (X)
                                 x4=3               x4=2
                               [SOL 1]            [SOL 2]
                             (2, 4, 1, 3)       (3, 1, 4, 2)
```
*(Nodes marked `(X)` are dead ends where all column choices in the next row violate `Place(k, i)`.)*

---

### All Distinct Solutions

#### Solution 1: $X = (2, 4, 1, 3)$
```text
    Col 1   Col 2   Col 3   Col 4
  +-------+-------+-------+-------+
R1|   .   |   Q1  |   .   |   .   |
  +-------+-------+-------+-------+
R2|   .   |   .   |   .   |   Q2  |
  +-------+-------+-------+-------+
R3|   Q3  |   .   |   .   |   .   |
  +-------+-------+-------+-------+
R4|   .   |   .   |   Q4  |   .   |
  +-------+-------+-------+-------+
```

#### Solution 2: $X = (3, 1, 4, 2)$
```text
    Col 1   Col 2   Col 3   Col 4
  +-------+-------+-------+-------+
R1|   .   |   .   |   Q1  |   .   |
  +-------+-------+-------+-------+
R2|   Q2  |   .   |   .   |   .   |
  +-------+-------+-------+-------+
R3|   .   |   .   |   .   |   Q3  |
  +-------+-------+-------+-------+
R4|   .   |   Q4  |   .   |   .   |
  +-------+-------+-------+-------+
```

**Conclusion:** The promising function `Place(k, i)` prunes invalid column and diagonal placements immediately, finding both distinct solutions **`(2, 4, 1, 3)`** and **`(3, 1, 4, 2)`**.

---

## 3. Sum of Subsets Using Backtracking

**Question:** Use the Backtracking method to identify all subsets whose sum is equal to 30 from the following set $S = \{5 \mid 10 \mid 12 \mid 13 \mid 15 \mid 18\}$. Draw the state-space tree, indicate the promising and non-promising nodes, and list all valid subsets. Explain the pruning conditions used to reduce the search space. (8 marks)

### Given Data

- Sorted set of weights ($n = 6$):
  $$w[1..6] = \{5, 10, 12, 13, 15, 18\}$$
- Target sum: $M = 30$
- Total sum of all elements:
  $$R = 5 + 10 + 12 + 13 + 15 + 18 = 73$$

---

### State Representation and Pruning (Bounding) Conditions

Each node at level $k$ in the state-space tree is represented by the triplet **`(s, k, r)`**, where:
- $s = \sum_{i=1}^{k-1} w_i x_i$: Sum of elements selected so far.
- $k$: Index of the current element $w_k$ being decided ($x_k = 1$ to include, $x_k = 0$ to exclude).
- $r = \sum_{i=k}^{n} w_i$: Sum of remaining elements from $w_k$ to $w_n$.

Since the weights are sorted in non-decreasing order ($w_1 \le w_2 \le \dots \le w_n$), a node `(s, k, r)` is **pruned (non-promising)** if either of the following conditions holds:

1. **Pruning Condition 1 (Remaining Elements Insufficient):**
   $$s + r < M$$
   Even if we include **all** remaining elements from $k$ to $n$, the total sum cannot reach $M$.
2. **Pruning Condition 2 (Next Smallest Element Exceeds Target):**
   $$s + w_k > M \quad (\text{when } s \ne M)$$
   Since $w_k$ is the smallest remaining element, adding $w_k$ (or any subsequent element $w_{k+1}, \dots, w_n$) will exceed $M$.

### Algorithm (`SumOfSub(s, k, r)`)

```text
SUM-OF-SUB(s, k, r)
1. x[k] = 1                                  // Include w[k]
2. if (s + w[k] == M) then:
3.     Print subset corresponding to x[1..k]
4. else if (s + w[k] + w[k+1] <= M) then:
5.     SUM-OF-SUB(s + w[k], k + 1, r - w[k])
6. if (s + r - w[k] >= M) and (s + w[k+1] <= M) then:
7.     x[k] = 0                              // Exclude w[k]
8.     SUM-OF-SUB(s, k + 1, r - w[k])
```

---

### State-Space Tree (`(s, k, r)`)

```text
                                     (0, 1, 73)
                              x1=1 (+5) /      \ x1=0
                                      /          \
                                (5, 2, 68)      (0, 2, 68)
                         x2=1(+10)/    \x2=0    x2=1(+10)/   \x2=0
                                /        \             /       \
                         (15, 3, 58)   (5, 3, 58)  (10,3,58)  (0, 3, 58)
                    x3=1(+12)/  \x3=0  x3=1/  \x3=0  /   \    x3=1(+12)/ \x3=0
                           /      \      /      \  22,4  10,4        /     \
                    (27,4,46) (15,4,46)(17,4,46)(5,4,46) (X)     (12,4,46) (0,4,46)
                      (X)    x4=1/ \x4=0  |       |               /    \      (X)
                    27+13>30   /     \   x4=1   x4=1(+13)     x4=1    x4=0
                          (28,5,33)(15,5,33)|     |          (25,5)  (12,5,33)
                            (X)     /      |   (18,5,33)      (X)   x5=1/  \x5=0
                          28+15>30 x5=1    |     (X)               (27,6) (12,6,18)
                                   |       |    18+15>30            (X)      | x6=1(+18)
                                [s=30]  [s=30]                            [s=30]
                              {5,10,15} {5,12,13}                        {12,18}
```

---

### Trace of Promising, Solution, and Non-Promising (Pruned) Nodes

1. **Path `x1=1 (5), x2=1 (10)` $\to (15, 3, 58)$:**
   - Include $w_3 = 12 \to (27, 4, 46)$: **Non-promising (Pruned)** because $s + w_4 = 27 + 13 = 40 > 30$.
   - Exclude $w_3 = 12 \to (15, 4, 46)$:
     - Include $w_4 = 13 \to (28, 5, 33)$: **Non-promising (Pruned)** because $s + w_5 = 28 + 15 = 43 > 30$.
     - Exclude $w_4 = 13 \to (15, 5, 33)$:
       - Include $w_5 = 15 \to s = 15 + 15 = \mathbf{30} \implies$ **Solution 1: $\{5, 10, 15\}$**.
       - Exclude $w_5 = 15 \to (15, 6, 18)$: $15 + 18 = 33 > 30$ (**Pruned**).

2. **Path `x1=1 (5), x2=0` $\to (5, 3, 58)$:**
   - Include $w_3 = 12 \to (17, 4, 46)$:
     - Include $w_4 = 13 \to s = 17 + 13 = \mathbf{30} \implies$ **Solution 2: $\{5, 12, 13\}$**.
     - Exclude $w_4 = 13 \to (17, 5, 33)$: $17 + 15 = 32 > 30$ (**Pruned**).
   - Exclude $w_3 = 12 \to (5, 4, 46)$:
     - Include $w_4 = 13 \to (18, 5, 33)$: $18 + 15 = 33 > 30$ (**Pruned**).
     - Exclude $w_4 = 13 \to (5, 5, 33)$:
       - Include $w_5 = 15 \to (20, 6, 18)$: $20 + 18 = 38 > 30$ (**Pruned**).
       - Exclude $w_5 = 15 \to (5, 6, 18)$: $s + r = 5 + 18 = 23 < 30$ (**Pruned by Condition 1**).

3. **Path `x1=0, x2=1 (10)` $\to (10, 3, 58)$:**
   - Include $w_3 = 12 \to (22, 4, 46)$: $22 + 13 = 35 > 30$ (**Pruned**).
   - Exclude $w_3 = 12 \to (10, 4, 46)$:
     - Include $w_4 = 13 \to (23, 5, 33)$: $23 + 15 = 38 > 30$ (**Pruned**).
     - Exclude $w_4 = 13 \to (10, 5, 33)$:
       - Include $w_5 = 15 \to (25, 6, 18)$: $25 + 18 = 43 > 30$ (**Pruned**).
       - Exclude $w_5 = 15 \to (10, 6, 18)$: $s + r = 10 + 18 = 28 < 30$ (**Pruned**).

4. **Path `x1=0, x2=0` $\to (0, 3, 58)$:**
   - Include $w_3 = 12 \to (12, 4, 46)$:
     - Include $w_4 = 13 \to (25, 5, 33)$: $25 + 15 = 40 > 30$ (**Pruned**).
     - Exclude $w_4 = 13 \to (12, 5, 33)$:
       - Include $w_5 = 15 \to (27, 6, 18)$: $27 + 18 = 45 > 30$ (**Pruned**).
       - Exclude $w_5 = 15 \to (12, 6, 18)$:
         - Include $w_6 = 18 \to s = 12 + 18 = \mathbf{30} \implies$ **Solution 3: $\{12, 18\}$**.
   - Exclude $w_3 = 12 \to (0, 4, 46)$:
     - Include $w_4 = 13 \to (13, 5, 33) \to (28, 6, 18)$ (**Pruned**).
     - Exclude $w_4 = 13 \to (0, 5, 33)$: $15 + 18 = 33 > 30$ (**Pruned**).

---

### All Valid Subsets with Sum $= 30$

| # | Binary Solution Vector $(x_1, x_2, x_3, x_4, x_5, x_6)$ | Selected Subset | Sum Check |
| :---: | :---: | :---: | :---: |
| **1** | $(1, 1, 0, 0, 1, 0)$ | **$\{5, 10, 15\}$** | $5 + 10 + 15 = 30$ |
| **2** | $(1, 0, 1, 1, 0, 0)$ | **$\{5, 12, 13\}$** | $5 + 12 + 13 = 30$ |
| **3** | $(0, 0, 1, 0, 0, 1)$ | **$\{12, 18\}$** | $12 + 18 = 30$ |

**Conclusion:** Out of $2^6 = 64$ possible subsets, Backtracking prunes non-promising branches early and identifies all **3 valid subsets**: **$\{5, 10, 15\}$**, **$\{5, 12, 13\}$**, and **$\{12, 18\}$**.

---

## 4. Graph Coloring Using Backtracking (3 Colors)

**Question:** Analyze the following undirected graph using the Backtracking algorithm and determine all valid color assignments using a maximum of 3 colors. Draw the state-space tree and identify the number of valid colorings. (8 marks)

![3-Coloring Undirected Graph](figures/unit5_q4_graph_coloring.png)

### Problem Description and Algorithm

The **$m$-Coloring Problem** asks for all assignments of at most $m$ colors $\{1, 2, \dots, m\}$ to the vertices $V = \{A, B, C, D, E\}$ of an undirected graph $G = (V, E)$ such that **no two adjacent vertices receive the same color** ($x[u] \ne x[v]$ for every edge $(u, v) \in E$).

```text
M-COLORING(k)
1. repeat:
2.     NEXT-VALUE(k)          // Assign next legal color in {1..m}, or 0 if none exists
3.     if x[k] == 0 then return
4.     if k == n then Print(x[1..n])
5.     else M-COLORING(k + 1)
6. until false
```

---

### Case 1: Analysis of the Complete Graph $K_5$ (All 10 Edges Shown in Figure)

In the figure as drawn, every vertex among $\{A, B, C, D, E\}$ is connected by an edge to every other vertex (forming the complete graph $K_5$ with $10$ edges: `A–B, A–C, A–D, A–E, B–C, B–D, B–E, C–D, C–E, D–E`).

#### Step-by-Step Backtracking Trace ($m = 3$ colors: `{1, 2, 3}`)

1. **Vertex $A$ ($k = 1$):** Can be assigned any color $c_A \in \{1, 2, 3\}$ ($3$ choices, e.g., $x[A] = 1$).
2. **Vertex $B$ ($k = 2$, adjacent to $A$):** Cannot use $x[A]$. Can be assigned any of the remaining $2$ colors (e.g., $x[B] = 2$).
3. **Vertex $C$ ($k = 3$, adjacent to $A, B$):** Cannot use $x[A]$ or $x[B]$. Must take the $1$ remaining color (e.g., $x[C] = 3$).
4. **Vertex $D$ ($k = 4$, adjacent to $A, B, C$):**
   - Color `1` conflicts with $A$ ($x[A] = 1$).
   - Color `2` conflicts with $B$ ($x[B] = 2$).
   - Color `3` conflicts with $C$ ($x[C] = 3$).
   - **`NextValue(D)` returns `0` (Dead End / Pruned)!**

#### State-Space Tree for $K_5$ with $m = 3$ Colors

```text
                                 Root ()
                    /               |               \
                 A = 1            A = 2            A = 3
                /     \          /     \          /     \
             B = 2   B = 3    B = 1   B = 3    B = 1   B = 2
               |       |        |       |        |       |
             C = 3   C = 2    C = 3   C = 1    C = 2   C = 1
               |       |        |       |        |       |
             D = X   D = X    D = X   D = X    D = X   D = X
           (Pruned) (Pruned) (Pruned) (Pruned) (Pruned) (Pruned)
```

- Because $K_5$ contains a clique of size $5$, its chromatic number is $\chi(K_5) = 5 > 3$.
- Every one of the $3 \times 2 \times 1 = 6$ partial assignments at depth $3$ is pruned at depth $4$ (vertex $D$), never reaching depth $5$ (vertex $E$).
- **Number of valid 3-colorings for $K_5$:** **$\boxed{0}$**.

---

### Case 2: If Diagonal Crossings Are Treated as Planar/Outer Pentagon ($C_5$) or 4-Chromatic Subgraph

*(In case the exam question intends the outer pentagon cycle $C_5$ with edges `A–B, B–D, D–E, E–C, C–A`):*

- For $C_5$ with $m = 3$ colors $\{1, 2, 3\}$:
  - One color is used twice on two non-adjacent vertices, a second color is used twice on two non-adjacent vertices, and the third color is used once.
  - Using chromatic polynomial $P(C_5, m) = (m - 1)^5 - (m - 1)$:
    $$P(C_5, 3) = (3 - 1)^5 - (3 - 1) = 32 - 2 = \boxed{30\text{ valid colorings}}$$
  - Example valid coloring for $C_5$: $(A=1, B=2, C=2, D=1, E=3)$ or $(A=1, B=2, D=3, E=1, C=2)$.

**Conclusion:** For the complete 5-vertex graph $K_5$ drawn in the diagram, all branches prune at vertex $D$ and the number of valid 3-colorings is **$0$** (since $\chi(K_5) = 5$). For the 5-cycle $C_5$, there are **$30$** valid 3-colorings.

---

## 5. Hamiltonian Cycles Using Backtracking

**Question:** Apply the Backtracking algorithm to identify all Hamiltonian cycles in the following undirected graph. Start from vertex A and explain how the algorithm rejects paths that cannot form a Hamiltonian cycle. Draw the state-space tree for the possible paths and list the distinct Hamiltonian cycles, treating reverse traversals as the same cycle. (8 marks)

![Hamiltonian Cycles Undirected Graph](figures/unit5_q5_hamiltonian.png)

### Given Graph Representation

- **Vertices ($n = 5$):** $A, B, C, D, E$
- **Undirected Edges ($8$ edges):**
  `A–B, A–C, A–E, B–C, B–D, B–E, C–E, D–E`
- **Adjacency Lists:**
  - $\text{Adj}(A) = \{B, C, E\}$
  - $\text{Adj}(B) = \{A, C, D, E\}$
  - $\text{Adj}(C) = \{A, B, E\}$
  - $\text{Adj}(D) = \{B, E\}$ *(Note: Vertex $D$ has degree 2, connected only to $B$ and $E$)*
  - $\text{Adj}(E) = \{A, B, C, D\}$

---

### How Backtracking Rejects Invalid Paths

A **Hamiltonian Cycle** is a closed loop that starts at $A$ ($x_1 = A$), visits every other vertex exactly once ($x_2, x_3, x_4, x_5$), and returns to $A$ via an edge $(x_5, A) \in E$.

At step $k$, candidate vertex $v$ for $x_k$ is **rejected (pruned)** if:
1. **No Edge Condition:** $(x_{k-1}, v) \notin E$ (not adjacent to the previous vertex).
2. **Duplicate Vertex Condition:** $v \in \{x_1, x_2, \dots, x_{k-1}\}$ ($v$ has already been visited in the current path).
3. **Dead-End Vertex:** All neighbors of $x_k$ have already been visited before $k = n$ (e.g., reaching $D$ when both of its neighbors $B$ and $E$ are already in the path).
4. **Closing-Edge Condition (at $k = n = 5$):** $(x_5, x_1) \notin E$ (the 5th vertex is not connected back to start vertex $A$, e.g., $x_5 = D$ is rejected because edge `D–A` does not exist).

---

### State-Space Tree Starting from Vertex `A`

```text
                                         A
                    /                    |                    \
                   B                     C                     E
             /     |     \            /     \            /     |     \
            C      D      E          B       E          B      C      D
           /       |     / \        / \     / \        / \     |      |
          E        E    C   D      D   E   B   D      C   D    B      B
          |        |    |   |      |   |   |   |      |   |   / \    / \
          D        C   (X) (X)     E   D   D   B      D  (X) D   E  C   E
         (X)       |              /   (X) (X)  |     (X)    (X) (X) |  (X)
        No D-A     A             A             A                    A
                [CYCLE 1]    [CYCLE 2]     [CYCLE 1R]           [CYCLE 2R]
```

---

### Detailed Trace of Paths and Rejections

1. **Start at `A → B`:**
   - **`A → B → C`:** Next unvisited neighbor of $C$ is $E \to$ `A → B → C → E → D`.
     - **Rejected at $D$:** All 5 vertices are visited, but $(D, A) \notin E$ ($D$ has no edge back to $A$).
   - **`A → B → D`:** Only unvisited neighbor of $D$ is $E \to$ `A → B → D → E → C`.
     - Since $(C, A) \in E$, this closes the tour: **`A → B → D → E → C → A` (Valid Hamiltonian Cycle 1!)**
   - **`A → B → E`:**
     - `A → B → E → C`: Remaining unvisited vertex is $D$, but $(C, D) \notin E \to$ **Rejected!**
     - `A → B → E → D`: Only neighbors of $D$ are $B$ and $E$, both already visited before $C \to$ **Rejected!**

2. **Start at `A → C`:**
   - **`A → C → B`:**
     - `A → C → B → D → E`: Since $(E, A) \in E$, this closes the tour: **`A → C → B → D → E → A` (Valid Hamiltonian Cycle 2!)**
     - `A → C → B → E → D`: $(D, A) \notin E \to$ **Rejected!**
   - **`A → C → E`:**
     - `A → C → E → B → D`: $(D, A) \notin E \to$ **Rejected!**
     - `A → C → E → D → B`: Since $(B, A) \in E$, this closes the tour: **`A → C → E → D → B → A`** *(Reverse of Cycle 1)*.

3. **Start at `A → E`:**
   - **`A → E → B`:**
     - `A → E → B → C`: $(C, D) \notin E \to$ **Rejected!**
     - `A → E → B → D`: Both neighbors of $D$ ($B, E$) already visited $\to$ **Rejected!**
   - **`A → E → C → B → D`:** $(D, A) \notin E \to$ **Rejected!**
   - **`A → E → D → B`:**
     - `A → E → D → B → C`: Since $(C, A) \in E$, this closes the tour: **`A → E → D → B → C → A`** *(Reverse of Cycle 2)*.

---

### List of Distinct Hamiltonian Cycles

| Cycle # | Directed Traversal | Reverse Traversal (Same Cycle) |
| :---: | :---: | :---: |
| **1** | **`A → B → D → E → C → A`** | `A → C → E → D → B → A` |
| **2** | **`A → C → B → D → E → A`** | `A → E → D → B → C → A` |

**Conclusion:** The graph has $4$ directed Hamiltonian cycles starting at $A$, which correspond to **2 distinct undirected Hamiltonian cycles** when reverse traversals are treated as the same cycle.

---

## 6. 0/1 Knapsack Using Least Cost (LC) Branch and Bound

**Question:** Analyze the 0/1 Knapsack problem using the Least Cost search Branch and Bound technique for the following dataset. The knapsack capacity is 16 units. Construct the state-space tree, calculate the upper bound and cost at each relevant node, identify the nodes pruned, and determine the optimal item selection and maximum profit. (8 marks)

### Given Dataset ($W = 16$)

| Item | Weight ($w_i$) | Profit ($p_i$) | Profit/Weight Ratio ($p_i / w_i$) |
| :---: | :---: | :---: | :---: |
| **I1** | 2 | 40 | $20.00$ |
| **I2** | 5 | 30 | $6.00$ |
| **I3** | 10 | 50 | $5.00$ |
| **I4** | 5 | 10 | $2.00$ |
| **I5** | 4 | 25 | $6.25$ |

---

### Step 1: Sort Items by Descending Profit-to-Weight Ratio ($p_i / w_i$)

To apply Least Cost (LC) Branch and Bound, we order the items by decreasing $p_i / w_i$:

| Sorted Order ($k$) | Original Item | Weight ($w'_k$) | Profit ($p'_k$) | Ratio ($p'_k / w'_k$) |
| :---: | :---: | :---: | :---: | :---: |
| **1** | **I1** | 2 | 40 | $20.00$ |
| **2** | **I5** | 4 | 25 | $6.25$ |
| **3** | **I2** | 5 | 30 | $6.00$ |
| **4** | **I3** | 10 | 50 | $5.00$ |
| **5** | **I4** | 5 | 10 | $2.00$ |

---

### Step 2: Bound Formulas (Minimization Convention)

Branch and Bound minimizes cost, so we negate profits:
- **Cost (Lower Bound $\hat{c}(X)$, with fractional part allowed):**
  Pack remaining items in ratio order until capacity $W = 16$ is reached, including a **fraction** of the first item that does not fit completely, then negate the sum.
- **Upper Bound ($U(X)$, no fractional part allowed):**
  Pack remaining items in ratio order **without** taking any fraction of the overflowing item, then negate the sum.
- **Global Upper Bound ($UB$):** Initialized to the smallest $U(X)$ seen so far. Any node $X$ with $\hat{c}(X) > UB$ (or non-negated fractional bound $\le$ best integer profit found) is **pruned**.

---

### Step 3: Node-by-Node Bound Calculations

#### Node 1 (Root — nothing decided yet):
- Take $k=1$ (`I1`: $w=2, p=40$), $k=2$ (`I5`: $w=4, p=25$), $k=3$ (`I2`: $w=5, p=30$).
- Total weight so far $= 2 + 4 + 5 = 11$, total profit $= 40 + 25 + 30 = 95$.
- Remaining capacity $= 16 - 11 = 5$. Next item is $k=4$ (`I3`: $w=10, p=50$):
  - **Without fraction ($U$):** Cannot fit `I3` ($w=10 > 5$). So $U(1) = -95$.
  - **With fraction ($\hat{c}$):** $95 + \frac{5}{10} \times 50 = 95 + 25 = 120 \implies \hat{c}(1) = -120$.
- Global $UB = -95$.

---

#### Expand Node 1 (Decision on $k=1$, Item `I1`):
- **Node 2 ($x_1 = 1$, include `I1`: $w=2, p=40$):**
  - Same greedy completion as root: $\hat{c}(2) = -120$, $U(2) = -95$.
- **Node 3 ($x_1 = 0$, exclude `I1`):**
  - Greedy pack from $k=2..5$: `I5` ($4, 25$) + `I2` ($5, 30$) = weight $9$, profit $55$.
  - Remaining capacity $= 16 - 9 = 7$. Take fraction of `I3` ($10, 50$): $55 + \frac{7}{10}\times 50 = 90$.
  - $\hat{c}(3) = -90$, $U(3) = -55$.
  - **Node 3 is PRUNED immediately** because $\hat{c}(3) = -90 > UB = -95$ (maximum possible profit without `I1` is $90 < 95$)!

---

#### Expand Node 2 (Least $\hat{c} = -120$, Decision on $k=2$, Item `I5`):
- **Node 4 ($x_2 = 1$, include `I5`: total $w=6, p=65$):**
  - $\hat{c}(4) = -120$, $U(4) = -95$.
- **Node 5 ($x_2 = 0$, exclude `I5`: total $w=2, p=40$):**
  - Pack `I2` ($5, 30$) $\to w=7, p=70$. Remaining capacity $= 9$.
  - Fraction of `I3` ($10, 50$): $70 + \frac{9}{10}\times 50 = 115$.
  - Without `I3`, check `I4` ($5, 10$): $U(5) = -(40 + 30) = -70$ (or $-80$ with `I4`).
  - $\hat{c}(5) = -115$, $U(5) = -70$.

---

#### Expand Node 4 (Least $\hat{c} = -120$, Decision on $k=3$, Item `I2`):
- **Node 6 ($x_3 = 1$, include `I2`: `{I1, I5, I2}`, total $w=11, p=95$):**
  - $\hat{c}(6) = -120$, $U(6) = -95$.
- **Node 7 ($x_3 = 0$, exclude `I2`: `{I1, I5}`, total $w=6, p=65$):**
  - Remaining capacity $= 16 - 6 = 10$.
  - Next item is $k=4$ (`I3`: $w=10, p=50$), which fits **100% exactly** ($6 + 10 = 16$)!
  - Profit $= 65 + 50 = \mathbf{115}$!
  - $\hat{c}(7) = -115$, $U(7) = \mathbf{-115}$!
  - **Update Global $UB = -115$!**

---

#### Expand Node 6 ($\hat{c} = -120$, Decision on $k=4$, Item `I3`):
- **Node 8 ($x_4 = 1$, include `I3`):**
  - Total weight $= 11 + 10 = 21 > 16 \implies$ **Infeasible (Pruned)!**
- **Node 9 ($x_4 = 0$, exclude `I3`: `{I1, I5, I2}`, $w=11, p=95$):**
  - Remaining capacity $= 5$. Next item $k=5$ (`I4`: $w=5, p=10$) fits exactly:
  - Total weight $= 11 + 5 = 16$, total profit $= 95 + 10 = 105$.
  - $\hat{c}(9) = -105$, $U(9) = -105$.
  - **Node 9 is PRUNED** because $\hat{c}(9) = -105 > UB = -115$.

---

#### Check Remaining Live Nodes (Node 5 and Node 7):
- **Node 5 ($\hat{c}(5) = -115$):** Since $\hat{c}(5) = -115 = UB$, it cannot beat $-115$ (and `I1 + I2 + I3` has weight $2 + 5 + 10 = 17 > 16$, so Node 5's children yield at most profit $90 \implies$ **Pruned**).
- **Node 7 ($\hat{c}(7) = -115, U(7) = -115$):**
  - **Node 10 ($x_4 = 1$, include `I3`):** Weight $= 2 + 4 + 10 = 16$, Profit $= 40 + 25 + 50 = \mathbf{115}$ (**Optimal Answer Node!**).
  - **Node 11 ($x_4 = 0$, exclude `I3`):** $\hat{c}(11) = -(65 + 10) = -75 > -115$ (**Pruned**).

---

### State-Space Tree

```text
                                Node 1 (Root)
                             [c = -120, U = -95]
                         I1=1 /                 \ I1=0
                             /                   \
                         Node 2                 Node 3
                    [c=-120, U=-95]         [c=-90, U=-55]
                    I5=1 /     \ I5=0         (PRUNED)
                        /       \
                    Node 4      Node 5
               [c=-120, U=-95] [c=-115, U=-70]
               I2=1 /    \ I2=0   (PRUNED)
                   /      \
               Node 6     Node 7
          [c=-120,U=-95] [c=-115, U=-115]  <-- Updates UB = -115
          I3=1 /   \ I3=0     | I3=1
              /     \         |
          Node 8   Node 9   Node 10 [ANSWER]
          (w=21)  [c=-105]  {I1, I5, I3}
         (PRUNED) (PRUNED)  w = 16, Profit = 115
```

---

### Summary Table of Nodes

| Node | Decisions $(I_1, I_5, I_2, I_3, I_4)$ | Weight ($w$) | Profit ($p$) | Cost $\hat{c}$ | Upper Bound $U$ | Status |
| :---: |---|---:|---:|---:|---:|---|
| **1** | `()` | 0 | 0 | $-120$ | $-95$ | Expanded |
| **2** | `(I1=1)` | 2 | 40 | $-120$ | $-95$ | Expanded |
| **3** | `(I1=0)` | 0 | 0 | $-90$ | $-55$ | **Pruned** ($\hat{c} > -95$) |
| **4** | `(I1=1, I5=1)` | 6 | 65 | $-120$ | $-95$ | Expanded |
| **5** | `(I1=1, I5=0)` | 2 | 40 | $-115$ | $-70$ | **Pruned** ($\hat{c} \ge -115$) |
| **6** | `(I1=1, I5=1, I2=1)` | 11 | 95 | $-120$ | $-95$ | Expanded |
| **7** | `(I1=1, I5=1, I2=0)` | 6 | 65 | $-115$ | **$-115$** | Updates $UB = -115$; Expanded |
| **8** | `(I1=1, I5=1, I2=1, I3=1)` | 21 | — | — | — | **Pruned** ($w = 21 > 16$) |
| **9** | `(I1=1, I5=1, I2=1, I3=0)` | 11 | 95 | $-105$ | $-105$ | **Pruned** ($\hat{c} > -115$) |
| **10** | `(I1=1, I5=1, I2=0, I3=1, I4=0)` | **16** | **115** | **$-115$** | **$-115$** | **Optimal Solution!** |

### Final Optimal Selection (in Original Item Order `I1..I5`)

- **Selected Items:** **`I1`, `I3`, and `I5`** ($X = (1, 0, 1, 0, 1)$)
- **Total Weight:** $2 + 10 + 4 = 16\text{ units}$
- **Maximum Profit:**
  $$\text{Maximum Profit} = 40 + 50 + 25 = \boxed{115}$$

---

## 7. Travelling Salesperson Problem (TSP) Using Branch and Bound

**Question:** Analyze the Travelling Salesperson Problem using Branch and Bound for the following cost matrix. Consider city **A** as the starting city. Construct the state-space tree, calculate lower bounds for promising partial tours, eliminate non-promising branches, and determine the optimal tour and its total cost. (8 marks)

### Given Cost Matrix ($5$ Cities: $A, B, C, D, E$)

$$C = \begin{bmatrix} \infty & 12 & 10 & 19 & 8 \\ 12 & \infty & 3 & 7 & 6 \\ 10 & 3 & \infty & 2 & 20 \\ 19 & 7 & 2 & \infty & 4 \\ 8 & 6 & 20 & 4 & \infty \end{bmatrix}$$

---

### Method: Reduced Cost Matrix (RCM) Branch and Bound

1. A matrix is **reduced** if every row and every column contains at least one `0` (or consists entirely of $\infty$).
2. The sum of all values subtracted from the rows and columns to reduce the initial matrix $C$ gives the **root lower bound** $\hat{c}(\text{Root})$.
3. When branching from node $R$ (with reduced matrix $A$) along edge $(i, j)$ to child node $S$:
   - Set all entries in **row $i$** and **column $j$** to $\infty$.
   - Set $A(j, \text{start})$ (and any edge closing a premature subtour) to $\infty$.
   - Reduce the resulting matrix; let $r$ be the sum of new reductions.
   - The child lower bound is:
     $$\hat{c}(S) = \hat{c}(R) + A(i, j) + r$$

---

### Step 1: Reduce Initial Matrix $C$ at Root (Node 1)

#### Row Reduction
Subtract the minimum of each row:
- Row $A$: $\min = 8$
- Row $B$: $\min = 3$
- Row $C$: $\min = 2$
- Row $D$: $\min = 2$
- Row $E$: $\min = 4$
- **Total Row Reduction** $= 8 + 3 + 2 + 2 + 4 = \mathbf{19}$

Matrix after row reduction:
$$\begin{bmatrix} \infty & 4 & 2 & 11 & 0 \\ 9 & \infty & 0 & 4 & 3 \\ 8 & 1 & \infty & 0 & 18 \\ 17 & 5 & 0 & \infty & 2 \\ 4 & 2 & 16 & 0 & \infty \end{bmatrix}$$

#### Column Reduction
Subtract the minimum of each column:
- Col $A$: $\min = 4$
- Col $B$: $\min = 1$
- Col $C$: $\min = 0$
- Col $D$: $\min = 0$
- Col $E$: $\min = 0$
- **Total Column Reduction** $= 4 + 1 + 0 + 0 + 0 = \mathbf{5}$

#### Root Reduced Matrix $R_0$ and Lower Bound
$$\hat{c}(\text{Node 1}) = 19 + 5 = \mathbf{24}$$

$$R_0 = \begin{bmatrix} \infty & 3 & 2 & 11 & 0 \\ 5 & \infty & 0 & 4 & 3 \\ 4 & 0 & \infty & 0 & 18 \\ 13 & 4 & 0 & \infty & 2 \\ 0 & 1 & 16 & 0 & \infty \end{bmatrix}$$

---

### Step 2: Level 1 — Branch from Start City `A`

We evaluate all 4 possible first edges $(A \to B, A \to C, A \to D, A \to E)$ using $\hat{c}(S) = 24 + R_0(A, j) + r$:

1. **Node 2 (`A → B`):**
   - $R_0(A, B) = 3$. Set Row $A = \infty$, Col $B = \infty$, $R(B, A) = \infty$.
   - Row $C$ min $= 0$, Row $D$ min $= 0$, Row $E$ min $= 0$; Col $A$ has min $= 4$? Wait: Row $E$ has $R(E,A)=0$, so Col $A$ min $= 0$. Row $D$ has $0$ at $(D,C)$, Col $D$ has $0$, Col $E$ has min $= 2$ (at $(D,E)$).
   - Additional reduction $r = 2$.
   - $\hat{c}(A \to B) = 24 + 3 + 2 = \mathbf{29}$.

2. **Node 3 (`A → C`):**
   - $R_0(A, C) = 2$. Set Row $A = \infty$, Col $C = \infty$, $R(C, A) = \infty$.
   - Row $B$ min $= 3$, Col $E$ min $= 2 \implies r = 3 + 2 = 5$.
   - $\hat{c}(A \to C) = 24 + 2 + 5 = \mathbf{31}$.

3. **Node 4 (`A → D`):**
   - $R_0(A, D) = 11$. Set Row $A = \infty$, Col $D = \infty$, $R(D, A) = \infty$.
   - Col $E$ min $= 2 \implies r = 2$.
   - $\hat{c}(A \to D) = 24 + 11 + 2 = \mathbf{37}$.

4. **Node 5 (`A → E`):**
   - $R_0(A, E) = 0$. Set Row $A = \infty$, Col $E = \infty$, $R(E, A) = \infty$.
   - Row $E$ now has $[\infty, 1, 16, 0, \infty]$ (min $= 0$).
   - Col $A$ now has $[\infty, 5, 4, 13, \infty]$ (min $= 4$).
   - Additional reduction $r = 4$.
   - $\hat{c}(A \to E) = 24 + 0 + 4 = \mathbf{28}$ (**Minimum Lower Bound!**)

Reduced matrix at **Node 5 (`A → E`, $\hat{c} = 28$)**:
$$R_{AE} = \begin{bmatrix} \infty & \infty & \infty & \infty & \infty \\ 1 & \infty & 0 & 4 & \infty \\ 0 & 0 & \infty & 0 & \infty \\ 9 & 4 & 0 & \infty & \infty \\ \infty & 1 & 16 & 0 & \infty \end{bmatrix}$$

---

### Step 3: Level 2 — Expand Node 5 (`A → E`, $\hat{c} = 28$)

From $E$, the unvisited cities are $B, C, D$:

1. **Node 6 (`A → E → B`):**
   - $R_{AE}(E, B) = 1$, $r = 0 \implies \hat{c}(A \to E \to B) = 28 + 1 + 0 = \mathbf{29}$.
2. **Node 7 (`A → E → C`):**
   - $R_{AE}(E, C) = 16$, $r = 5 \implies \hat{c}(A \to E \to C) = 28 + 16 + 5 = \mathbf{49}$.
3. **Node 8 (`A → E → D`):**
   - $R_{AE}(E, D) = 0$. Set Row $E = \infty$, Col $D = \infty$, $R(D, A) = \infty$, $R(D, E) = \infty$.
   - Every remaining active row ($B, C, D$) and column ($A, B, C$) still contains a `0`, so $r = 0$!
   - $\hat{c}(A \to E \to D) = 28 + 0 + 0 = \mathbf{28}$ (**Minimum Lower Bound!**)

Reduced matrix at **Node 8 (`A → E → D`, $\hat{c} = 28$)**:
$$R_{AED} = \begin{bmatrix} \infty & \infty & \infty & \infty & \infty \\ 1 & \infty & 0 & \infty & \infty \\ 0 & 0 & \infty & \infty & \infty \\ \infty & 4 & 0 & \infty & \infty \\ \infty & \infty & \infty & \infty & \infty \end{bmatrix}$$

---

### Step 4: Level 3 — Expand Node 8 (`A → E → D`, $\hat{c} = 28$)

From $D$, the unvisited cities are $B$ and $C$:

1. **Node 9 (`A → E → D → B`):**
   - $R_{AED}(D, B) = 4$, $r = 0 \implies \hat{c}(A \to E \to D \to B) = 28 + 4 + 0 = \mathbf{32}$.
2. **Node 10 (`A → E → D → C`):**
   - $R_{AED}(D, C) = 0$. Set Row $D = \infty$, Col $C = \infty$, $R(C, A) = \infty$.
   - Remaining forced path is $C \to B \to A$: Row $B$ has $R(B, A) = 1 \implies r = 1$.
   - $\hat{c}(A \to E \to D \to C) = 28 + 0 + 1 = \mathbf{29}$.
   - Completing the tour with $C \to B \to A$ gives the complete tour **`A → E → D → C → B → A`** of cost **29**!

---

### Step 5: Prune Non-Promising Branches

Since we have found a complete valid tour of cost **$UB = 29$**:
- **Node 3 (`A → C`, $\hat{c} = 31$):** Pruned ($31 > 29$).
- **Node 4 (`A → D`, $\hat{c} = 37$):** Pruned ($37 > 29$).
- **Node 7 (`A → E → C`, $\hat{c} = 49$):** Pruned ($49 > 29$).
- **Node 9 (`A → E → D → B`, $\hat{c} = 32$):** Pruned ($32 > 29$).
- **Node 6 (`A → E → B`, $\hat{c} = 29$):** Cannot improve upon $29$ (expanding it yields cost $33 > 29$, pruned).
- **Node 2 (`A → B`, $\hat{c} = 29$):** Yields the symmetric reverse tour **`A → B → C → D → E → A`** with the same optimal cost **29**.

---

### State-Space Tree for TSP Branch and Bound

```text
                                  Node 1: Root (A)
                                    [LB = 24]
                /                 /              \                 \
           A -> B              A -> C           A -> D            A -> E
          Node 2              Node 3           Node 4            Node 5
         [LB = 29]           [LB = 31]        [LB = 37]         [LB = 28]
      (Reverse Tour)         (PRUNED)         (PRUNED)       /      |      \
                                                        E->B      E->C     E->D
                                                       Node 6    Node 7   Node 8
                                                      [LB=29]   [LB=49]  [LB=28]
                                                     (PRUNED)  (PRUNED)   /    \
                                                                       D->B    D->C
                                                                      Node 9  Node 10
                                                                     [LB=32] [LB=29]
                                                                    (PRUNED)    |
                                                                           C -> B -> A
                                                                          [OPTIMAL: 29]
```

---

### Optimal Tour and Total Cost

- **Optimal Tour:** **`A → E → D → C → B → A`** *(or reverse: **`A → B → C → D → E → A`**)*
- **Edge-by-Edge Cost Verification:**
  $$C(A, E) + C(E, D) + C(D, C) + C(C, B) + C(B, A) = 8 + 4 + 2 + 3 + 12 = \boxed{29}$$

---

## 8. Compare and Contrast Backtracking and Branch and Bound

**Question:** Compare and contrast the Backtracking and Branch and Bound methods. (8 marks)

### Similarities

1. **State-Space Tree Exploration:** Both methods represent the solution space as a **state-space tree** and generate nodes dynamically without storing the entire tree in memory upfront.
2. **Pruning (Bounding Functions):** Both use bounding/criterion functions to identify and prune non-promising subtrees early, avoiding exhaustive brute-force search.
3. **Combinatorial Problem Solving:** Both are used for NP-hard combinatorial problems (such as 0/1 Knapsack and Travelling Salesperson Problem).

---

### Differences: Backtracking vs. Branch and Bound

| Feature | Backtracking | Branch and Bound |
|---|---|---|
| **Primary Problem Type** | Used for **decision**, **constraint-satisfaction**, and **enumeration** problems (finding one or all feasible solutions), as well as some optimization problems. | Used **exclusively for optimization problems** (minimization or maximization). |
| **Tree Traversal Order** | Strictly follows **Depth-First Search (DFS)** (LIFO order). | Can traverse the state-space tree using **BFS (FIFO)**, **DFS (LIFO)**, or **Best-First / Least Cost (LC) Search** using a Priority Queue. |
| **Pruning Mechanism** | Prunes a node when it **violates problem constraints** (feasibility check via a promising/criterion function). | Prunes a node when its **optimistic bound ($\hat{c}$)** is worse than the best solution cost ($UB$) found so far, or when it is infeasible. |
| **State Storage Requirement** | Very low memory ($O(n)$ stack space) since only the active root-to-E-node path is kept in memory. | Higher memory requirement ($O(b^d)$ in worst case) because all live nodes and their bounds must be stored in a queue/priority queue. |
| **Bound Calculation** | Uses a boolean constraint check $B_k(x_1, \dots, x_k) \in \{\text{true}, \text{false}\}$. | Computes numerical **Lower Bounds ($\hat{c}$)** and **Upper Bounds ($U$)** at every node (e.g., via fractional relaxation or matrix reduction). |
| **Speed to Optimal Solution** | May explore many suboptimal feasible solutions before finding the global optimum. | Least-Cost (LC) search guides exploration directly toward the most promising nodes first, often finding the optimal solution much faster. |
| **Classic Examples** | $N$-Queens, Sum of Subsets, Graph $m$-Coloring, Hamiltonian Cycles. | 0/1 Knapsack (LC B&B), Travelling Salesperson Problem (Reduced Cost Matrix B&B), Job Assignment Problem. |

**Conclusion:** Backtracking is a memory-efficient DFS technique ideal for constraint-satisfaction problems and enumerating all valid configurations, whereas Branch and Bound uses numerical lower/upper bounds and priority-guided search (LC/BFS) to find optimal solutions to minimization and maximization problems.
