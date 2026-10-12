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

**Q3. Compute the all-pairs shortest path distances using Floyd–Warshall for the given initial cost matrix.**

### Initial matrix $D^{(0)}$ (vertices 1, 2, 3, 4)

$$
D^{(0)} =
\begin{bmatrix}
0 & 4 & \infty & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

### Recurrence

$$
D^{(k)}[i][j] = \min\left( D^{(k-1)}[i][j],\ D^{(k-1)}[i][k] + D^{(k-1)}[k][j] \right)
$$

- **$k = 1$ (via vertex 1):** no vertex has an edge into vertex 1 (column 1 is all $\infty$), so $D^{(1)} = D^{(0)}$.
- **$k = 2$ (via vertex 2):** $D[1][3] = \min(\infty, D[1][2] + D[2][3]) = 4 + 3 = 7$.

$$
D^{(2)} =
\begin{bmatrix}
0 & 4 & 7 & 10 \\
\infty & 0 & 3 & \infty \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

- **$k = 3$ (via vertex 3):** $D[1][4] = \min(10, D[1][3] + D[3][4]) = \min(10, 7 + 2) = 9$; $D[2][4] = \min(\infty, 3 + 2) = 5$.

$$
D^{(3)} =
\begin{bmatrix}
0 & 4 & 7 & 9 \\
\infty & 0 & 3 & 5 \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

- **$k = 4$ (via vertex 4):** vertex 4 has no outgoing edges, so there is no change. $D^{(4)} = D^{(3)}$.

### Final shortest path matrix

$$
D^{(4)} =
\begin{bmatrix}
0 & 4 & 7 & 9 \\
\infty & 0 & 3 & 5 \\
\infty & \infty & 0 & 2 \\
\infty & \infty & \infty & 0
\end{bmatrix}
$$

### Significance of the intermediate vertex

In iteration $k$, $D^{(k)}[i][j]$ is the shortest path from $i$ to $j$ using only vertices $\{1, \dots, k\}$ as intermediate vertices. Each iteration tests whether passing through vertex $k$ gives a shorter route than the best known so far. After $k = n$, all vertices are allowed, so the matrix is final.

**Time complexity:** three nested loops $(k, i, j)$, each running $n$ times, so each of the $n$ iterations does $n^2$ comparisons: $T(n) = n \times n^2 = \Theta(n^3)$. **Space:** $\Theta(n^2)$.

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

```text
          if
         /  \
       do    int
                \
                while
```

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
