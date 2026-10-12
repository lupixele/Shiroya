# UNIT V — Backtracking and Branch & Bound

> **Source:** *Advanced Data Structures & Algorithm Analysis (2501CS10) — Unit-wise Important Questions — Answers | Aditya University*

---

## 1. Backtracking: General Methodology, State-Space Tree, Bounding Conditions, and Comparison with Exhaustive Search

**Q1. Explain the general methodology of Backtracking. Discuss the state-space tree, its basic terms and the role of bounding conditions. Distinguish it from exhaustive search.**

Backtracking builds a solution one component at a time (a depth-first search of the solution space). After each choice it checks whether the partial solution can still lead to a complete valid solution; if not, it abandons (prunes) that branch and backtracks to try another choice.

**State-space tree:** a tree whose nodes represent partial solutions. The root $=$ empty solution; each level represents a choice for one component; the leaves are complete solutions (or dead ends).

### Basic terms

| Term | Meaning |
|---|---|
| **Solution space** | All possible tuples $(x_1, \dots, x_n)$ |
| **Explicit constraints** | Rules restricting each $x_i$ to a set of values (e.g. $x_i \in \{0, 1\}$) |
| **Implicit constraints** | Rules describing how the $x_i$ must relate to one another (e.g. no two queens attack) |
| **Live node** | A generated node whose children have not all been generated |
| **E-node (expanding node)** | The live node currently being expanded |
| **Dead node** | A node that is not expanded further (it is infeasible, or all children are done) |
| **Promising node** | A node that may still lead to a solution |
| **Non-promising node** | A node that cannot lead to a solution; it is pruned |

### Role of bounding conditions (promising function)

A bounding function is checked at every node to decide whether it can lead to a solution. If it returns false, the whole subtree is pruned without being explored, which saves enormous effort.

### Generic algorithm

```text
Backtrack(k):
    for each value v in the choices for x[k]:
        x[k] = v
        if Bound(x[1..k]) is true:            // promising
            if x[1..k] is a complete solution: output it
            else Backtrack(k + 1)
```

**Example (4-Queens):** place queens row by row; when a queen in a row has no safe column, return to the previous row and move that queen.

### Backtracking vs. Exhaustive Search

| Backtracking | Exhaustive search (brute force) |
|---|---|
| Builds solutions incrementally and prunes invalid partial solutions | Generates all possible solutions, then tests each |
| Uses bounding/promising functions | No pruning |
| Explores only a fraction of the space | Explores the entire space |
| Much faster in practice (worst case still exponential) | Always the full exponential/factorial cost |
| Example: 4-Queens checks about 26 nodes | $4^4 = 256$ placements (or $4! = 24$ permutations) |

---

## 2. 4-Queens Problem using Backtracking

**Q2. Apply Backtracking to the 4-Queens problem. Draw the state-space tree and show the solutions.**

**Problem:** place 4 queens on a $4 \times 4$ board so that no two share a row, column or diagonal. Place one queen per row. Let $x_i =$ column of the queen in row $i$.

**Promising (safe) test:** queen $k$ at column $x_k$ is safe if for every earlier queen $i < k$:

$$
x_i \ne x_k \quad \text{and} \quad |x_i - x_k| \ne |i - k|.
$$

### Trace of the search (row, column)

- **$Q_1 = (1,1)$.**
  - Row 2: col 1 unsafe (column), col 2 unsafe (diagonal), col 3 safe $\to Q_2 = (2,3)$.
    - Row 3: col 1 (column), col 2 (diagonal with $Q_2$), col 3 (column), col 4 (diagonal with $Q_2$): all unsafe $\to$ backtrack.
  - Row 2: col 4 safe $\to Q_2 = (2,4)$.
    - Row 3: col 1 unsafe (column), col 2 safe $\to Q_3 = (3,2)$.
      - Row 4: col 1 (column), col 2 (column), col 3 (diagonal with $Q_3$), col 4 (column): all unsafe $\to$ backtrack.
    - Row 3: col 3 unsafe (diagonal with $Q_2$), col 4 unsafe (column) $\to$ backtrack to row 1.
- **$Q_1 = (1,2)$.**
  - Row 2: col 1 (diagonal), col 2 (column), col 3 (diagonal) unsafe; col 4 safe $\to Q_2 = (2,4)$.
    - Row 3: col 1 safe $\to Q_3 = (3,1)$.
      - Row 4: col 1, col 2 (columns), col 4 (column) unsafe; col 3 safe $\to Q_4 = (4,3)$. **Solution 1 found: `(2, 4, 1, 3)`.**
- **$Q_1 = (1,3)$:** by symmetry, finds **Solution 2: `(3, 1, 4, 2)`.**
- **$Q_1 = (1,4)$:** mirror image of $Q_1 = (1,1)$; no solution.

### State-space tree (partial)

```text
                      root
           /        |       |        \
        Q1=1       Q1=2    Q1=3      Q1=4
         |          |       |         |
  Q2=3 x(dead)     Q2=4    Q2=1     (dead)
  Q2=4              |       |
   |               Q3=1    Q3=4
  Q3=2              |       |
   |               Q4=3 *  Q4=2 *
(no Q4: dead)    SOLUTION SOLUTION
```

### The two distinct solutions (`Q` = queen)

```text
Solution 1: (2, 4, 1, 3)      Solution 2: (3, 1, 4, 2)
  .  Q  .  .                    .  .  Q  .
  .  .  .  Q                    Q  .  .  .
  Q  .  .  .                    .  .  .  Q
  .  .  Q  .                    .  Q  .  .
```

**How the promising function eliminates invalid configurations:** as soon as a queen is placed in the same column or on the same diagonal as an earlier queen, that branch is cut off and none of its descendants is generated. This avoids examining the $4^4 = 256$ (or $4! = 24$) complete placements; only about 26 nodes of the state-space tree are generated.

---

## 3. Sum of Subsets using Backtracking

**Q3. Use Backtracking to find all subsets of $S = \{5, 10, 12, 13, 15, 18\}$ whose sum is 30. Draw the state-space tree, mark promising and non-promising nodes, and list all valid subsets.**

*(The set was written as `"51012131518"` in the question paper, read here as `5, 10, 12, 13, 15, 18`, which is already in ascending order.)*

**Setup:** $M = 30$, items in ascending order. Total $= 73$. Each level decides whether to include (`1`) or exclude (`0`) the next element. For a node with current sum $s$ and sum of remaining elements $r$:

### Pruning (bounding) conditions — a node is promising only if

1. $s + w_{\text{next}} \le M$ (to include the next item) — otherwise adding exceeds 30 (prune).
2. $s + r \ge M$ — otherwise even adding all remaining items cannot reach 30 (prune).
3. If $s = M$, a solution is recorded.

### State-space tree (include branch first). Each node shown as $(s, r)$

```text
(0,73)
|-- include 5 --> (5,68)
|   |-- include 10 --> (15,58)
|   |   |-- include 12 --> (27,46)
|   |   |   |-- include 13 --> 40 > 30 X pruned
|   |   |   '-- exclude 13 --> (27,33): 15 -> 42, 18 -> 45 > 30 X (no solution)
|   |   '-- exclude 12 --> (15,46)
|   |       |-- include 13 --> (28,33): add 15 or 18 exceeds 30 X
|   |       '-- exclude 13 --> (15,33)
|   |           |-- include 15 --> (30,18) *** SOLUTION {5,10,15} ***
|   |           '-- exclude 15 --> (15,18): +18 = 33 > 30 X
|   '-- exclude 10 --> (5,58)
|       |-- include 12 --> (17,46)
|       |   |-- include 13 --> (30,33) *** SOLUTION {5,12,13} ***
|       |   '-- exclude 13 --> 17+15 = 32 > 30, 17+18 = 35 > 30 X
|       '-- exclude 12 --> (5,46): 13, 15, 18 combinations give 18, 20, 23, 5+... < 30 or > 30 X
'-- exclude 5 --> (0,68)
    |-- include 10 --> (10,58): every extension is 22, 25, 23, 28, 35+ ... X (no 30)
    '-- exclude 10 --> (0,58)
        |-- include 12 --> (12,46)
        |   |-- include 13 --> (25,33) X (25 + 15 = 40 > 30)
        |   '-- exclude 13 --> (12,33): include 15 -> 27 (no); exclude 15 -> include 18 -> (30,0)
        |                      *** SOLUTION {12,18} ***
        '-- exclude 12 --> (0,46): 13+15 = 28, 13+18 = 31, 15+18 = 33, 13+15+18 = 46 X
```

### Examples of non-promising (pruned) nodes

- $(5+10+12+13) = 40 > 30$ fails condition 1 (sum exceeds $M$).
- $(s = 5,\text{ excluding } 10, 12, 13 \text{ and } 15,\ r = 18)$: $5 + 18 = 23 < 30$ fails condition 2.
- $(s = 10,\text{ excluding } 12, 13, 15,\ r = 18)$: $10 + 18 = 28 < 30$ fails condition 2.
- $(s = 0,\text{ excluding } 10, 12, 13, 15,\ r = 18)$: $18 < 30$ fails condition 2.

### All valid subsets with sum 30

| Subset | Check |
|---|---|
| `{5, 10, 15}` | $5 + 10 + 15 = 30$ |
| `{5, 12, 13}` | $5 + 12 + 13 = 30$ |
| `{12, 18}` | $12 + 18 = 30$ |

**Solution vectors** ($x_1 \dots x_6$ for `5, 10, 12, 13, 15, 18`): `(1,1,0,0,1,0)`, `(1,0,1,1,0,0)`, `(0,0,1,0,0,1)`.

The two pruning rules cut the $2^6 = 64$ leaf combinations down to a small part of the tree.

---

## 4. Graph Coloring using Backtracking (3 Colors)

**Q4. Graph colouring with at most 3 colours using Backtracking (given undirected graph).**

![3-Coloring Undirected Graph](figures/unit5_q4_graph_coloring.png)

The given graph has vertices `A, B, C, D, E`, and every pair of vertices is joined by an edge (all 10 edges: `AB, AC, AD, AE, BC, BD, BE, CD, CE, DE`), so it is the complete graph $K_5$.

**Colouring rule:** adjacent vertices must have different colours. Colours available: $\{1, 2, 3\}$. **Promising test:** vertex $k$ can take colour $c$ only if none of its already-coloured neighbours has colour $c$.

### State-space tree (order A, B, C, D, E)

```text
A = 1 (by symmetry, any colour for A gives the same outcome; 3 choices)
|-- B = 1 : X (adjacent to A)
|-- B = 2
|   |-- C = 1 : X (A)    C = 2 : X (B)
|   |-- C = 3
|       |-- D = 1 : X (A)    D = 2 : X (B)    D = 3 : X (C)
|       '-- no colour available for D -> BACKTRACK
'-- B = 3
    |-- C = 2
        '-- D: 1 X (A), 2 X (C), 3 X (B) -> BACKTRACK
(similarly for the other branches: every branch fails at vertex D)
```

- The first three vertices `A, B, C` are mutually adjacent, so they must use three different colours ($3! = 6$ ways).
- Vertex `D` is adjacent to `A, B` and `C`, so all three colours are already used by its neighbours: no colour is available $\to$ backtrack to the previous levels, try all alternatives, and every path fails at `D`.
- Vertex `E` would also need a 5th distinct colour.

**Number of valid 3-colourings $= 0$.** The graph is **not 3-colourable**. Its chromatic number is 5 (a complete graph on $n$ vertices needs $n$ colours). With 5 colours there would be $5! = 120$ valid colourings.

**Time complexity:** $O(m^n)$ in the worst case for $m$ colours and $n$ vertices; pruning stops the search early.

---

## 5. Hamiltonian Cycles using Backtracking

**Q5. Apply Backtracking to find all Hamiltonian cycles in the given undirected graph, starting from vertex A.**

![Hamiltonian Cycles Undirected Graph](figures/unit5_q5_hamiltonian.png)

**Edges of the graph:** `A–B, A–C, A–E, B–C, B–D, B–E, C–E, D–E` (8 edges; there is no `A–D` and no `C–D` edge).

**Adjacency:** `A: B, C, E`; `B: A, C, D, E`; `C: A, B, E`; `D: B, E`; `E: A, B, C, D`.

A Hamiltonian cycle visits every vertex exactly once and returns to the start. At level $k$, vertex $x_k$ is promising only if (i) it is adjacent to $x_{k-1}$ and (ii) it is not already in the path; at the last level it must also be adjacent to the start vertex A.

### State-space tree (paths from A)

```text
A
|-- B
|   |-- C
|   |   '-- E
|   |       '-- D --> D is not adjacent to A X (cannot close the cycle)
|   |-- D
|   |   '-- E
|   |       '-- C --> C adjacent to A *** A-B-D-E-C-A ***
|   '-- E
|       |-- C --> D left, but C-D is not an edge X (dead end)
|       '-- D --> C left, but D-C is not an edge X (dead end)
|-- C
|   |-- B
|   |   |-- D
|   |   |   '-- E --> E adjacent to A *** A-C-B-D-E-A ***
|   |   '-- E
|   |       '-- D --> D not adjacent to A X
|   '-- E
|       |-- D
|       |   '-- B --> B adjacent to A *** A-C-E-D-B-A ***
|       '-- B
|           '-- D --> D not adjacent to A X
'-- E
    |-- B
    |   |-- C --> D unreachable from C X
    |   '-- D --> C unreachable from D X
    |-- C
    |   '-- B
    |       '-- D --> D not adjacent to A X
    '-- D
        '-- B
            '-- C --> C adjacent to A *** A-E-D-B-C-A ***
```

**How invalid paths are rejected:** a partial path is abandoned when the next vertex is not adjacent to the current one, when it was already visited, or when the last vertex has no edge back to A. Vertex D has only two neighbours (B and E), so any Hamiltonian cycle must use both edges `B–D` and `D–E`; every path that visits D in another way is a dead end.

- **Cycles found (4 directed paths):** `A-B-D-E-C-A`, `A-C-B-D-E-A`, `A-C-E-D-B-A`, `A-E-D-B-C-A`.
- **Treating reverse traversals as the same cycle:** `A-B-D-E-C-A` is the reverse of `A-C-E-D-B-A`, and `A-C-B-D-E-A` is the reverse of `A-E-D-B-C-A`.
- **Distinct Hamiltonian cycles $= 2$:**
  1. `A – B – D – E – C – A`
  2. `A – C – B – D – E – A`

---

## 6. 0/1 Knapsack using Least Cost (LC) Branch and Bound

**Q6. Analyze the 0/1 Knapsack problem using Least Cost (LC) Branch and Bound (capacity $= 16$).**

| Item | I1 | I2 | I3 | I4 | I5 |
|---|---:|---:|---:|---:|---:|
| **Weight** | 2 | 5 | 10 | 5 | 4 |
| **Profit** | 40 | 30 | 50 | 10 | 25 |
| **Profit / Weight** | 20 | 6 | 5 | 2 | 6.25 |

### Method

Arrange items in decreasing profit/weight order: `I1 (2, 40), I5 (4, 25), I2 (5, 30), I3 (10, 50), I4 (5, 10)`. Each node decides include or exclude the next item. For a node with weight $W$ and profit $P$:

- **Upper bound $UB$:** $P + \text{profit of the following items taken greedily}$, the last one taken fractionally to fill the capacity. (This is the optimistic estimate.)
- **Cost $c(x) = -UB$** (the algorithm minimises cost, so a larger profit means a more negative cost), and the best feasible profit found so far acts as the lower limit $U$.
- **Pruning rule:** kill a node if its $UB \le$ the best feasible profit already found (equivalently $c(x) > U$). The live node with the least cost (largest $UB$) is expanded next.

### State-space tree (node: weight, profit, UB)

| Node | Decision | Weight | Profit | UB | Status |
|---|---|---:|---:|---|---|
| Root | – | 0 | 0 | $40 + 25 + 30 + 5 \cdot 5 = 120$ | expand |
| 1 | include I1 | 2 | 40 | $120$ | expand (least cost) |
| 2 | exclude I1 | 0 | 0 | $25 + 30 + (7/10) \times 50 = 90$ | pruned later ($UB\ 90 < 115$) |
| 3 | I1, include I5 | 6 | 65 | $120$ | expand |
| 4 | I1, exclude I5 | 2 | 40 | $115$ | pruned ($UB \le 115$) |
| 5 | I1, I5, include I2 | 11 | 95 | $120$ | expand |
| 6 | I1, I5, exclude I2 | 6 | 65 | $115$ | expand, leads to the best solution |
| 7 | I1, I5, I2, include I3 | $21 > 16$ | – | – | infeasible (killed) |
| 8 | I1, I5, I2, exclude I3 | 11 | 95 | $105$ | feasible: add I4 ($w=16$) gives profit 105, so best so far $= 105$; $UB\ 105 \le 115 \to$ pruned later |
| **9** | **I1, I5, exclude I2, include I3** | **16** | **115** | **115** | **feasible, best $= 115$** |
| 10 | I1, I5, exclude I2, exclude I3 | 6 | 65 | $75$ | pruned ($UB\ 75 < 115$) |

Once a feasible solution of profit 115 is found (node 9), every live node with $UB \le 115$ is killed (nodes 2, 4, 8, 10). No live node remains, so the search ends.

- **Optimal solution:** items **I1, I5 and I3** ($x = (1, 0, 1, 0, 1)$ for $I_1 \dots I_5$).
- **Weight:** $2 + 4 + 10 = 16$ (full).
- **Maximum profit:**

$$
40 + 25 + 50 = \boxed{115}
$$

*(Branch and Bound avoided exploring the full tree of $2^5 = 32$ leaves; only about 10 nodes were generated.)*

---

## 7. Travelling Salesperson Problem (TSP) using Branch and Bound

**Q7. Analyze the Travelling Salesperson Problem using Branch and Bound (start at city A).**

### Cost matrix (A, B, C, D, E)

$$
C =
\begin{bmatrix}
\infty & 12 & 10 & 19 & 8 \\
12 & \infty & 3 & 7 & 6 \\
10 & 3 & \infty & 2 & 20 \\
19 & 7 & 2 & \infty & 4 \\
8 & 6 & 20 & 4 & \infty
\end{bmatrix}
$$

### Method (reduced cost matrix)

1. **Root lower bound:** subtract the minimum of every row, then of every column; the total subtracted is the lower bound.
   - Row minima: `8 (A), 3 (B), 2 (C), 2 (D), 4 (E)` $\to \text{sum} = 19$.
   - After row reduction, column minima: `A = 0, B = 1, C = 0, D = 0, E = 0` $\to \text{sum} = 5$. *(Note: in the PDF answer key, column reduction sum is written as 5, giving root lower bound $19 + 5 = 24$; using exact column B minimum 1 gives $19 + 1 = 20$, and both yield the same optimal tour of cost 29.)*
   - Lower bound of root $= 19 + 5 = 24$.
2. **For a child node (edge $i \to j$):** $\text{cost}(\text{child}) = \text{cost}(\text{parent}) + M[i][j] + \text{reduction cost of the new matrix}$, where row $i$ and column $j$ are set to $\infty$ and the entry $M[j][A]$ is set to $\infty$ (to prevent early return to A); then the matrix is reduced again.
3. Always expand the live node with the lowest bound; prune any node whose bound $\ge$ the best complete tour found.

### Reduced matrix at root (bound 24)

$$
\begin{bmatrix}
\infty & 3 & 2 & 11 & 0 \\
5 & \infty & 0 & 4 & 3 \\
4 & 0 & \infty & 0 & 18 \\
13 & 4 & 0 & \infty & 2 \\
0 & 1 & 16 & 0 & \infty
\end{bmatrix}
$$

### State-space tree with lower bounds

| Level | Node (path) | Computation | Lower bound | Status |
|---:|---|---|---:|---|
| 0 | `A` (root) | $19 + 5$ | 24 | expand |
| 1 | `A→B` | $24 + 3 + 2$ | 29 | live |
| 1 | `A→C` | $24 + 2 + 5$ | 31 | live |
| 1 | `A→D` | $24 + 11 + 2$ | 37 | live |
| 1 | `A→E` | $24 + 0 + 4$ | 28 | expand (lowest) |
| 2 | `A→E→B` | $28 + 1 + 0$ | 29 | live |
| 2 | `A→E→C` | $28 + 16 + 5$ | 49 | pruned |
| 2 | `A→E→D` | $28 + 0 + 0$ | 28 | expand (lowest) |
| 3 | `A→E→D→B` | $28 + 4 + 0$ | 32 | live |
| 3 | `A→E→D→C` | $28 + 0 + 1$ | 29 | expand |
| **4** | **`A→E→D→C→B`** | **$29 + 0 + 0$** | **29** | **complete tour, `A→E→D→C→B→A` with cost 29** |

After the tour of cost 29 is found, all remaining live nodes with bound $\ge 29$ (`A→C = 31`, `A→D = 37`, `A→E→C = 49`, `A→E→D→B = 32`, and `A→B`, `A→E→B` at 29 which cannot improve) are pruned.

- **Optimal tour:** `A → E → D → C → B → A`
- **Cost:**

$$
8 + 4 + 2 + 3 + 12 = \boxed{29}
$$

*(The reverse tour `A → B → C → D → E → A` has the same cost 29.)*

**Complexity:** worst case $O(n!)$ but pruning makes it far faster in practice; bounds come from matrix reduction ($O(n^2)$ per node).

---

## 8. Compare and Contrast Backtracking and Branch and Bound

**Q8. Compare and contrast Backtracking and Branch and Bound.**

| Aspect | Backtracking | Branch and Bound |
|---|---|---|
| **Used for** | Decision and enumeration problems (find all or any feasible solution) | Optimisation problems (find the best solution: minimum cost or maximum profit) |
| **Tree traversal** | Depth-First Search of the state-space tree | BFS, least-cost (best-first) or DFS (FIFO/LIFO/priority queue) |
| **Pruning basis** | Feasibility: constraints are violated (bounding/promising function) | Bound: the node's best possible value cannot beat the best solution found so far |
| **Bounding function** | Checks only constraint satisfaction | Computes a lower/upper bound of the objective function |
| **Solution** | May generate all solutions | Finds an optimal solution (only the best) |
| **Node selection** | Next child of the current node (stack/recursion) | Live node with the best bound (priority queue) |
| **Memory** | Low (recursion stack, $O(\text{depth})$) | Higher (stores many live nodes) |
| **Speed** | Fast for constraint problems | Faster than backtracking for optimisation |
| **Examples** | N-Queens, Sum of subsets, Graph colouring, Hamiltonian cycle | 0/1 Knapsack, TSP, Job assignment |
| **Worst case** | Exponential | Exponential |

**Similarities:** both explore a state-space tree, both prune non-promising nodes, and both avoid the brute-force enumeration of all possibilities.
