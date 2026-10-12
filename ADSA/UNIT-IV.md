# UNIT IV — Dynamic Programming

> **Source:** *Advanced Data Structures & Algorithm Analysis (2501CS10) — Unit-wise Important Questions — Answers | Aditya University*

---

## 1. Dynamic Programming: methodology, optimal substructure, overlapping subproblems, and comparison with Divide and Conquer

**Q1. Explain the general methodology of Dynamic Programming. Discuss optimal substructure and overlapping subproblems. Differentiate DP from Divide and Conquer.**

Dynamic Programming (DP) solves a complex problem by breaking it into overlapping sub-problems, solving each sub-problem only once, and storing its result (in a table) for reuse. It is mainly used for optimisation problems.

### Steps of DP

1. Characterise the structure of an optimal solution.
2. Define the value of an optimal solution recursively (recurrence).
3. Compute values bottom-up (tabulation) or top-down with memoisation.
4. Construct the optimal solution from the table.

### Principles

1. **Optimal substructure:** an optimal solution to the problem contains optimal solutions to its sub-problems.
   - *Example:* in shortest paths, if the shortest path from A to C goes through B, then its `A→B` and `B→C` parts are themselves shortest paths (Floyd–Warshall, Bellman–Ford).
2. **Overlapping subproblems:** the same sub-problems are solved again and again in a naive recursion.
   - *Example:* Fibonacci: $F(5) = F(4) + F(3)$, and $F(4) = F(3) + F(2)$. $F(3)$ is computed twice. DP stores $F(i)$ in a table and reduces $O(2^n)$ to $O(n)$.

### Dynamic Programming vs. Divide and Conquer

| Basis | Dynamic Programming | Divide and Conquer |
|---|---|---|
| **Sub-problems** | Overlapping (same sub-problem appears repeatedly) | Independent (no overlap) |
| **Strategy** | Solves each sub-problem once and stores the answer | Solves each sub-problem recursively, again every time |
| **Approach** | Bottom-up (or memoised top-down) | Top-down |
| **Storage** | Needs a table (extra memory) | No table; uses only recursion stack |
| **Efficiency** | Polynomial time by avoiding recomputation | Efficient only when sub-problems don't overlap; otherwise exponential |
| **Used for** | Optimisation (knapsack, OBST, TSP, shortest paths) | Sorting, searching, matrix multiplication |
| **Examples** | Floyd–Warshall, 0/1 knapsack, LCS | Merge sort, quick sort, binary search |

---

## 2. Bellman–Ford algorithm from source S

**Q2. Apply the Bellman–Ford algorithm to find shortest paths from source S in the given directed weighted graph. Show the distance values after each iteration and check for a negative cycle.**

![Bellman-Ford Directed Weighted Graph](figures/unit4_q2_bellman_ford.png)

> *Note:* the figure refers to an edge list that was not included in the file, so the edge directions below are assumed (left to right as drawn).

**Edges (assumed directions):** `S→A 6, S→E 2, A→B 5, A→E −4, B→C −2, E→C 1, E→D 4, C→D 3`. Vertices: `S, A, B, C, D, E` ($|V| = 6$, so $|V| - 1 = 5$ passes are allowed).

**Relaxation rule:**

$$
\text{if } d[u] + w(u, v) < d[v] \text{ then } d[v] = d[u] + w(u, v).
$$

### Iteration 1 (edges processed in the order listed)

- `S→A`: $d[A] = 6$. `S→E`: $d[E] = 2$.
- `A→B`: $d[B] = 6 + 5 = 11$. `A→E`: $6 - 4 = 2$, no change.
- `B→C`: $d[C] = 11 - 2 = 9$. `E→C`: $2 + 1 = 3$, so $d[C] = 3$.
- `E→D`: $d[D] = 2 + 4 = 6$. `C→D`: $3 + 3 = 6$, no change.

| Iteration | S | A | B | C | D | E |
|---|---:|---:|---:|---:|---:|---:|
| Initial | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |
| 1 | 0 | 6 | 11 | 3 | 6 | 2 |
| 2 | 0 | 6 | 11 | 3 | 6 | 2 |
| 3 to 5 | 0 | 6 | 11 | 3 | 6 | 2 |

No value changes in iteration 2, so the algorithm can stop early.

### Negative cycle check ($|V|$-th pass)

Try to relax every edge once more. No distance decreases, therefore the graph contains **no negative-weight cycle** (all edges go "forward" in the order `S, A, B, E, C, D`, so no cycle exists at all).

### Shortest distances from S

`A = 6, B = 11, C = 3, D = 6, E = 2`.

| Vertex | Distance | Path |
|---|---:|---|
| A | 6 | `S → A` |
| E | 2 | `S → E` (or `S → A → E`, also 2) |
| C | 3 | `S → E → C` |
| D | 6 | `S → E → D` (or `S → E → C → D`) |
| B | 11 | `S → A → B` |

**Complexity:** $O(V \cdot E)$. Unlike Dijkstra, it handles negative weights and detects negative cycles (if any edge can still be relaxed after $V - 1$ passes).

---

## 3. Floyd–Warshall algorithm for all-pairs shortest paths

**Q3. Compute the all-pairs shortest path distances using Floyd–Warshall algorithm for the following initial cost matrix. Show the distance matrix after considering each intermediate vertex and determine the final shortest path matrix. Explain the significance of the intermediate vertex in each iteration and derive the time complexity.**

$$
D^{(0)} =
\begin{bmatrix}
0 & 4 & \infty & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

![Floyd–Warshall GeeksforGeeks Cross Method](figures/unit4_q3_floyd_warshall.png)

---

### 1. The GeeksforGeeks "Cross-Highlight" Method (Simplifying the Calculation)

Floyd–Warshall is a Dynamic Programming algorithm that solves the **All-Pairs Shortest Path (APSP)** problem in $O(V^3)$ time.

#### Dynamic Programming Recurrence:
$$
D^{(k)}[i][j] = \min\left( D^{(k-1)}[i][j],\ D^{(k-1)}[i][k] + D^{(k-1)}[k][j] \right)
$$

> [!IMPORTANT]
> **What does $(k-1)$ mean? It is NOT a power (`pow`)!**  
> In mathematics, when subscripts $[i][j]$ are already used for **row $i$** and **column $j$**, mathematicians use a superscript in parentheses `(k)` as a **step / version counter**, NOT an exponent.  
> - $D^{(k-1)}$ simply means: **"the value from the PREVIOUS matrix / previous table"**
> - $D^{(k)}$ simply means: **"the value in the CURRENT matrix / current table"**
> 
> In actual code (like on GeeksforGeeks), there is **zero power calculation**. It is literally just:
> ```cpp
> dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
> ```

#### 💡 The 3 GfG Shortcut Rules (Saves 80% Manual Effort):
In each iteration $k$ (where vertex $k$ is treated as the intermediate vertex):

1. **Rule 1 — The Protected Cross & Diagonal (Never Change):**
   - **Row $k$ never changes**: Moving from $k$ to $j$ through $k$ costs $D[k][k] + D[k][j] = 0 + D[k][j]$.
   - **Column $k$ never changes**: Moving from $i$ to $k$ through $k$ costs $D[i][k] + D[k][k] = D[i][k] + 0$.
   - **Main diagonal ($D[i][i] = 0$) never changes**: Self-loops cost $0$.
   - *Action:* Highlight Row $k$ and Column $k$ as a **cross (`+`)** and copy them directly to the next matrix!

2. **Rule 2 — The $\infty$ Shortcut (Zero Work):**
   - If an incoming cell in Column $k$ is $\infty$ ($D[i][k] = \infty$), vertex $i$ cannot reach $k$. Therefore, **Row $i$ can NEVER be improved through $k$**. Copy all entries in Row $i$ directly!
   - If an outgoing cell in Row $k$ is $\infty$ ($D[k][j] = \infty$), vertex $k$ cannot reach $j$. Therefore, **Column $j$ can NEVER be improved through $k$**. Copy all entries in Column $j$ directly!

3. **Rule 3 — The Single Intersection Addition for Remaining Cells:**
   - For any cell $(i, j)$ outside the cross, simply add the intersection values:
     $$\text{New Candidate Cost} = (\text{Row } i \text{ entry in highlighted Col } k) + (\text{Col } j \text{ entry in highlighted Row } k)$$
     $$\text{New } D^{(k)}[i][j] = \min(\text{Current } D^{(k-1)}[i][j],\ \text{New Candidate Cost})$$

---

### 2. Step-by-Step Matrix Execution

#### Initial Graph & Cost Matrix $D^{(0)}$:
Direct edges: $1 \to 2$ (wt 4), $1 \to 4$ (wt 10), $2 \to 3$ (wt 3), $3 \to 4$ (wt 2).

$$
D^{(0)} =
\begin{bmatrix}
0 & 4 & \infty & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

---

#### Iteration 1: $k = 1$ (Treating Vertex 1 as Intermediate)

- **Highlight Cross:** Row 1 and Column 1.
  - Row 1: `[0, 4, ∞, 10]`
  - Column 1: `[0, ∞, ∞, ∞]ᵀ`
- **Apply Rule 2 (Infinity Shortcut):**
  - Look at Column 1: $D[2][1] = \infty$, $D[3][1] = \infty$, $D[4][1] = \infty$.
  - Since no vertex has a directed path into vertex 1, no path $i \to 1 \to j$ can exist!
  - **Result:** No additions needed; zero cells change!

$$
D^{(1)} = D^{(0)} =
\begin{bmatrix}
0 & 4 & \infty & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

---

#### Iteration 2: $k = 2$ (Treating Vertex 2 as Intermediate)

- **Highlight Cross:** Row 2 and Column 2.
  - Row 2: `[∞, 0, 3, ∞]`
  - Column 2: `[4, 0, ∞, ∞]ᵀ`
- **Copy Unchanged:** Row 2, Column 2, and diagonal ($0$).
- **Evaluate Remaining Cells:**
  - Notice in Column 2, only **Row 1** has a finite incoming value: $D[1][2] = 4$. Rows 3 and 4 have $\infty$ (copy them unchanged by Rule 2).
  - In Row 2, the only finite destination is **Col 3**: $D[2][3] = 3$.
  - Therefore, the **only cell that can update is $(1, 3)$**:
    $$D^{(2)}[1][3] = \min\left(D^{(1)}[1][3],\ D^{(1)}[1][2] + D^{(1)}[2][3]\right)$$
    $$D^{(2)}[1][3] = \min(\infty,\ 4 + 3) = \min(\infty, 7) = \mathbf{7}$$
    *(Path formed: $1 \to 2 \to 3$ with cost 7).*

$$
D^{(2)} =
\begin{bmatrix}
0 & 4 & \mathbf{7}^* & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
\quad (*\text{updated from } \infty \text{ to } 7)
$$

---

#### Iteration 3: $k = 3$ (Treating Vertex 3 as Intermediate)

- **Highlight Cross:** Row 3 and Column 3.
  - Row 3: `[∞, ∞, 0, 2]`
  - Column 3: `[7, 3, 0, ∞]ᵀ`
- **Copy Unchanged:** Row 3, Column 3, and diagonal ($0$).
- **Evaluate Remaining Cells:**
  - Incoming into Column 3: Row 1 ($D[1][3] = 7$) and Row 2 ($D[2][3] = 3$).
  - Outgoing from Row 3: Column 4 ($D[3][4] = 2$).
  - Only two candidate intersections exist:
    1. **Cell $(1, 4)$:**
       $$D^{(3)}[1][4] = \min\left(D^{(2)}[1][4],\ D^{(2)}[1][3] + D^{(2)}[3][4]\right)$$
       $$D^{(3)}[1][4] = \min(10,\ 7 + 2) = \min(10, 9) = \mathbf{9}$$
       *(Path formed: $1 \to 2 \to 3 \to 4$ with cost 9, beating the direct edge $1 \to 4$ of cost 10!)*
    2. **Cell $(2, 4)$:**
       $$D^{(3)}[2][4] = \min\left(D^{(2)}[2][4],\ D^{(2)}[2][3] + D^{(2)}[3][4]\right)$$
       $$D^{(3)}[2][4] = \min(\infty,\ 3 + 2) = \min(\infty, 5) = \mathbf{5}$$
       *(Path formed: $2 \to 3 \to 4$ with cost 5, updated from $\infty$).*

$$
D^{(3)} =
\begin{bmatrix}
0 & 4 & 7 & \mathbf{9}^* \\
\infty & 0 & 3 & \mathbf{5}^* \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
\quad (*\text{updated via node 3})
$$

---

#### Iteration 4: $k = 4$ (Treating Vertex 4 as Intermediate)

- **Highlight Cross:** Row 4 and Column 4.
  - Row 4: `[∞, ∞, ∞, 0]`
  - Column 4: `[9, 5, 2, 0]ᵀ`
- **Apply Rule 2 (Infinity Shortcut):**
  - Look at Row 4: Vertex 4 has **no outgoing edges** to any other vertex ($D[4][j] = \infty$ for all $j \in \{1, 2, 3\}$).
  - Therefore, no path $i \to 4 \to j$ can reach any destination!
  - **Result:** Zero additions needed; no cells change!

$$
D^{(4)} = D^{(3)} =
\begin{bmatrix}
0 & 4 & 7 & 9 \\
\infty & 0 & 3 & 5 \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

---

### 3. Summary of Shortest Path Changes

| Node Pair $(i, j)$ | Initial Direct Cost $D^{(0)}$ | Final Shortest Cost $D^{(4)}$ | Intermediate Node Used | Actual Shortest Route |
|:---:|:---:|:---:|:---:|:---|
| **$1 \to 2$** | 4 | **4** | None (direct) | $1 \to 2$ |
| **$1 \to 3$** | $\infty$ | **7** | Node 2 (in $k=2$) | $1 \to 2 \to 3$ |
| **$1 \to 4$** | 10 | **9** | Node 3 (in $k=3$) | $1 \to 2 \to 3 \to 4$ (beats direct edge!) |
| **$2 \to 3$** | 3 | **3** | None (direct) | $2 \to 3$ |
| **$2 \to 4$** | $\infty$ | **5** | Node 3 (in $k=3$) | $2 \to 3 \to 4$ |
| **$3 \to 4$** | 2 | **2** | None (direct) | $3 \to 4$ |
| Other pairs | $\infty$ | $\infty$ | — | No directed path exists |

---

### 4. Significance of the Intermediate Vertex

1. **Subset of Allowed Stepping Stones:**
   In iteration $k$, the matrix element $D^{(k)}[i][j]$ represents the shortest distance from vertex $i$ to vertex $j$ such that **all intermediate vertices belong strictly to the subset $\{1, 2, \dots, k\}$**.
2. **Optimal Substructure Principle:**
   The shortest path using intermediate vertices from $\{1, \dots, k\}$ either:
   - Does **not** pass through vertex $k$ $\implies$ cost is simply $D^{(k-1)}[i][j]$.
   - Passes through vertex $k$ $\implies$ decomposes into shortest path $i \to k$ plus shortest path $k \to j$, both using only intermediate vertices from $\{1, \dots, k-1\}$.
3. **Completeness:**
   After $k = n$, all vertices in the graph have been considered as potential intermediate stepping stones, guaranteeing that $D^{(n)}$ contains the global shortest paths between all pairs of vertices.

---

### 5. Complexity Analysis & Negative Cycles

- **Time Complexity:**
  - The algorithm executes 3 nested loops:
    - Outer loop runs for intermediate vertex $k = 1$ to $n$ ($n$ iterations).
    - Middle loop runs for source vertex $i = 1$ to $n$ ($n$ iterations).
    - Inner loop runs for destination vertex $j = 1$ to $n$ ($n$ iterations).
  - Total elementary operations: $n \times n \times n = \Theta(n^3)$ or $\mathbf{\Theta(V^3)}$.
- **Space Complexity:**
  - $\mathbf{\Theta(V^2)}$ to store the distance matrix of size $n \times n$.
- **Negative-Weight Cycle Detection:**
  - Floyd–Warshall naturally handles negative edge weights.
  - If after $n$ iterations any diagonal entry becomes negative ($D[i][i] < 0$), it proves the graph contains a **negative-weight cycle** reachable from $i$.

---

## 4. Optimal Binary Search Tree (OBST) using Dynamic Programming

**Q4. Optimal Binary Search Tree: $n = 4$, keys $\{\text{do}, \text{if}, \text{int}, \text{while}\}$, $p(1:4) = \{3, 3, 1, 1\}$, $q(0:4) = \{2, 3, 1, 1, 1\}$.**

### Formulas

$$
W(i, i) = q_i; \quad C(i, i) = 0; \quad R(i, i) = 0
$$

$$
W(i, j) = W(i, j-1) + p_j + q_j
$$

$$
C(i, j) = W(i, j) + \min_{i < k \le j} \left[ C(i, k-1) + C(k, j) \right]; \quad R(i, j) = \text{the } k \text{ giving the minimum.}
$$

Keys: $a_1 = \text{do}, a_2 = \text{if}, a_3 = \text{int}, a_4 = \text{while}$.

### Cost table ($W, C, R$ for each $j - i$)

| $j - i$ | $(i, j)$ | $W$ | $C$ | $R$ (root) |
|---:|---|---|---|---:|
| 0 | $(0,0)\ (1,1)\ (2,2)\ (3,3)\ (4,4)$ | $2, 3, 1, 1, 1$ | $0$ | $0$ |
| 1 | $(0,1)$ | $2 + 3 + 3 = 8$ | $8$ | 1 |
| 1 | $(1,2)$ | $3 + 3 + 1 = 7$ | $7$ | 2 |
| 1 | $(2,3)$ | $1 + 1 + 1 = 3$ | $3$ | 3 |
| 1 | $(3,4)$ | $1 + 1 + 1 = 3$ | $3$ | 4 |
| 2 | $(0,2)$ | $8 + 3 + 1 = 12$ | $12 + \min(k=1: 0+7,\ k=2: 8+0) = 19$ | 1 |
| 2 | $(1,3)$ | $7 + 1 + 1 = 9$ | $9 + \min(k=2: 0+3,\ k=3: 7+0) = 12$ | 2 |
| 2 | $(2,4)$ | $3 + 1 + 1 = 5$ | $5 + \min(k=3: 0+3,\ k=4: 3+0) = 8$ | 3 |
| 3 | $(0,3)$ | $12 + 1 + 1 = 14$ | $14 + \min(k=1: 0+12,\ k=2: 8+3,\ k=3: 19+0) = 25$ | 2 |
| 3 | $(1,4)$ | $9 + 1 + 1 = 11$ | $11 + \min(k=2: 0+8,\ k=3: 7+3,\ k=4: 12+0) = 19$ | 2 |
| 4 | $(0,4)$ | $14 + 1 + 1 = 16$ | $16 + \min(k=1: 0+19,\ k=2: 8+8,\ k=3: 19+3,\ k=4: 25+0) = \mathbf{32}$ | **2** |

*($W(0,4) = W(0,3) + p_4 + q_4 = 14 + 1 + 1 = 16$. For $(2,4)$ the choices $k = 3$ and $k = 4$ tie at 8; $k = 3$ is taken.)*

### Finding the tree

$R(0,4) = 2$, so the root is $a_2 = \text{if}$. Left subtree $=$ keys $(0,1)$, whose root is $R(0,1) = 1$, i.e. $\text{do}$. Right subtree $=$ keys $(2,4)$, whose root is $R(2,4) = 3$, i.e. $\text{int}$; its right subtree is $(3,4)$ with root $R(3,4) = 4$, i.e. $\text{while}$.

### Final Optimal BST

![Optimal Binary Search Tree](figures/unit4_q4_obst_tree.png)

Minimum cost $C(0,4) = 32$, i.e. the minimum expected search cost $= C / W = 32 / 16 = \mathbf{2}$ comparisons per search (weighted). **Time:** $O(n^3)$ ($O(n^2)$ with Knuth's optimisation).

---

## 5. 0/1 Knapsack using Dynamic Programming

**Q5. Solve the 0/1 Knapsack problem using Dynamic Programming (capacity $= 10$).**

| Item | I1 | I2 | I3 | I4 | I5 |
|---|---:|---:|---:|---:|---:|
| **Weight** | 2 | 3 | 4 | 5 | 6 |
| **Profit** | 12 | 20 | 25 | 30 | 35 |

### Recurrence

$$
V[i][w] =
\begin{cases}
V[i-1][w] & \text{if } w_i > w, \\
\max\left( V[i-1][w],\ p_i + V[i-1][w - w_i] \right) & \text{otherwise.}
\end{cases}
$$

### DP table $V[i][w]$ (rows $=$ items considered, columns $=$ capacity 0 to 10)

| $i \setminus w$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| **0** | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| **1 (I1)** | 0 | 0 | 12 | 12 | 12 | 12 | 12 | 12 | 12 | 12 | 12 |
| **2 (I2)** | 0 | 0 | 12 | 20 | 20 | 32 | 32 | 32 | 32 | 32 | 32 |
| **3 (I3)** | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 45 | 57 | 57 |
| **4 (I4)** | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 50 | 57 | 62 |
| **5 (I5)** | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 50 | 57 | **62** |

$$
\text{Maximum profit} = V[5][10] = \boxed{62}
$$

### Traceback (selected items)

- $V[5][10] = V[4][10] = 62$, so **I5 is not selected**.
- $V[4][10] = 62 \ne V[3][10] = 57$, so **I4 is selected** ($w = 5$); remaining capacity $= 5$.
- $V[3][5] = 32 = V[2][5]$, so **I3 is not selected**.
- $V[2][5] = 32 \ne V[1][5] = 12$, so **I2 is selected** ($w = 3$); remaining capacity $= 2$.
- $V[1][2] = 12 \ne V[0][2] = 0$, so **I1 is selected** ($w = 2$); remaining capacity $= 0$.

**Selected items:** `I1, I2, I4`. Total weight $= 2 + 3 + 5 = 10$, total profit $= 12 + 20 + 30 = \mathbf{62}$.

### Why ratio-based greedy may fail in 0/1 knapsack

Profit/weight ratios are $I_2 = 6.67, I_3 = 6.25, I_1 = 6.0, I_4 = 6.0, I_5 = 5.83$. Greedy takes `I2, I3, I1` (weight 9, profit 57); the remaining capacity 1 cannot hold any other item. Profit $= 57 < 62$. Items cannot be split, so the highest-ratio picks can leave unusable capacity, while the DP considers all combinations of items. **Time and space:** $O(n \cdot W)$.

---

## 6. Travelling Salesperson Problem (TSP) using Held–Karp Dynamic Programming

**Q6. Analyze the Travelling Salesperson Problem using Dynamic Programming (Held–Karp), starting and ending at city A.**

### Cost matrix (A, B, C, D)

$$
C =
\begin{bmatrix}
0 & 10 & 15 & 20 \\
10 & 0 & 35 & 25 \\
15 & 35 & 0 & 30 \\
20 & 25 & 30 & 0
\end{bmatrix}
$$

### Held–Karp recurrence

$$
g(i, S) = \min_{j \in S} \left[ c(i, j) + g(j, S - \{j\}) \right], \quad \text{with } g(i, \emptyset) = c(i, A).
$$

$g(i, S) =$ the shortest path starting at $i$, visiting all cities in $S$ exactly once and ending at A.

- **Step 1: $S = \emptyset$:**
  - $g(B, \emptyset) = 10,\quad g(C, \emptyset) = 15,\quad g(D, \emptyset) = 20$.
- **Step 2: $|S| = 1$:**
  - $g(B, \{C\}) = c(B,C) + g(C, \emptyset) = 35 + 15 = 50;\quad g(B, \{D\}) = 25 + 20 = 45$
  - $g(C, \{B\}) = 35 + 10 = 45;\quad g(C, \{D\}) = 30 + 20 = 50$
  - $g(D, \{B\}) = 25 + 10 = 35;\quad g(D, \{C\}) = 30 + 15 = 45$
- **Step 3: $|S| = 2$:**
  - $g(B, \{C, D\}) = \min( c(B,C) + g(C,\{D\}),\ c(B,D) + g(D,\{C\}) ) = \min(35 + 50, 25 + 45) = \min(85, 70) = 70$ (via D)
  - $g(C, \{B, D\}) = \min( c(C,B) + g(B,\{D\}),\ c(C,D) + g(D,\{B\}) ) = \min(35 + 45, 30 + 35) = \min(80, 65) = 65$ (via D)
  - $g(D, \{B, C\}) = \min( c(D,B) + g(B,\{C\}),\ c(D,C) + g(C,\{B\}) ) = \min(25 + 50, 30 + 45) = \min(75, 75) = 75$
- **Step 4: final:**

$$
\begin{aligned}
g(A, \{B, C, D\}) &= \min\left( c(A,B) + g(B,\{C,D\}),\ c(A,C) + g(C,\{B,D\}),\ c(A,D) + g(D,\{B,C\}) \right) \\
&= \min( 10 + 70,\ 15 + 65,\ 20 + 75 ) = \min(80, 80, 95) = \boxed{80}
\end{aligned}
$$

**Optimal tour:** `A → B → D → C → A`, cost $= 10 + 25 + 30 + 15 = \mathbf{80}$. *(Its reverse `A → C → D → B → A` also costs 80.)*

### Use of overlapping subproblems

Every $g(i, S)$ is computed once, stored in the table and then reused by all larger subsets that contain it. For example, the stored values $g(B,\{C,D\}) = 70$, $g(C,\{B,D\}) = 65$ and $g(D,\{B,C\}) = 75$ are all reused when computing $g(A,\{B,C,D\})$, instead of re-enumerating the underlying paths. With only 3 cities the sharing is small, but for $n$ cities a value $g(j, S)$ is shared by many different longer paths, which is why DP needs $O(n^2 \cdot 2^n)$ time instead of checking all $(n-1)!$ tours (here $3! = 6$). **Space:** $O(n \cdot 2^n)$.
