# UNIT IV

## 1. Dynamic Programming: methodology, optimal substructure, overlapping subproblems, and comparison with Divide and Conquer

### Definition

Dynamic Programming (DP) solves a problem by breaking it into subproblems, storing their solutions, and reusing them to avoid repeated work. It is commonly used for optimization problems.

### General methodology

1. Define the subproblems and state.
2. Identify the relationship between a problem and its smaller subproblems.
3. Write a recurrence relation.
4. Define base cases.
5. Store subproblem answers using memoization or tabulation.
6. Recover the final answer from the stored values.

### Optimal substructure

A problem has optimal substructure if an optimal solution can be built from optimal solutions to its subproblems.

**Example:** If a shortest path from A to C passes through B, the subpath from A to B must also be shortest; otherwise, replacing it with a shorter subpath would improve the full route.

### Overlapping subproblems

Overlapping subproblems occur when a recursive algorithm solves the same subproblem repeatedly.

For Fibonacci numbers:

\[
F(n)=F(n-1)+F(n-2)
\]

A naive recursive calculation of `F(5)` computes `F(3)` more than once. DP stores each Fibonacci value and reuses it.

### DP approaches

- **Memoization (top-down):** Recursion plus a cache of computed results.
- **Tabulation (bottom-up):** Iteratively fills a table from the base cases upward.

### Dynamic Programming vs Divide and Conquer

| Dynamic Programming | Divide and Conquer |
|---|---|
| Often used when subproblems overlap. | Often used when subproblems are independent. |
| Stores results for reuse. | Usually computes and combines independent subproblems. |
| Prevents repeated subproblem calculations. | May repeat work if overlapping subproblems are not cached. |
| Examples: Knapsack, Floyd–Warshall, OBST. | Examples: Merge Sort, Binary Search. |

**Conclusion:** DP is effective when a problem has optimal substructure and overlapping subproblems.

---

## 2. Bellman–Ford algorithm from source S

**Question:** Find shortest paths from S, show distances after iterations, and check for negative-weight cycles. (8 marks)

![Bellman-Ford Directed Weighted Graph](figures/unit4_q2_bellman_ford.png)

### Edge list used

| Directed edge | Weight |
|---|---:|
| S → A | 6 |
| S → E | 2 |
| A → B | 5 |
| A → E | -4 |
| B → C | -2 |
| E → C | 1 |
| E → D | 4 |
| D → C | 3 |

### Definition

Bellman–Ford computes single-source shortest paths in a weighted directed graph and supports negative edge weights. It can detect a negative-weight cycle reachable from the source.

### Initialization

Set `d(S) = 0` and all other distances to infinity.

| Vertex | S | A | B | C | D | E |
|---|---:|---:|---:|---:|---:|---:|
| Initial | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |

### Relaxation rule

For every edge `u → v` of weight `w`:

\[
d(v)=\min(d(v),d(u)+w)
\]

Do not relax an edge if `d(u) = ∞`.

### Iteration 1

Process edges in the order listed:

- S → A: `0 + 6 = 6`, so A = 6.
- S → E: `0 + 2 = 2`, so E = 2.
- A → B: `6 + 5 = 11`, so B = 11.
- A → E: `6 − 4 = 2`, so E remains 2.
- B → C: `11 − 2 = 9`, so C = 9.
- E → C: `2 + 1 = 3`, improving C to 3.
- E → D: `2 + 4 = 6`, so D = 6.
- D → C: `6 + 3 = 9`, so C remains 3.

| After pass | S | A | B | C | D | E |
|---|---:|---:|---:|---:|---:|---:|
| 1 | 0 | 6 | 11 | 3 | 6 | 2 |

### Iterations 2–5

No distances improve in subsequent passes.

| Pass | S | A | B | C | D | E |
|---:|---:|---:|---:|---:|---:|---:|
| 2 | 0 | 6 | 11 | 3 | 6 | 2 |
| 3 | 0 | 6 | 11 | 3 | 6 | 2 |
| 4 | 0 | 6 | 11 | 3 | 6 | 2 |
| 5 | 0 | 6 | 11 | 3 | 6 | 2 |

There are six vertices, so the standard algorithm needs at most `V − 1 = 5` passes. The distances stabilize after the first pass for this edge order.

### Negative-cycle check

Perform one additional pass over every edge. If any distance can still be reduced, a reachable negative-weight cycle exists. No distance changes here.

Therefore, **no negative-weight cycle reachable from S exists**.

### Final distances and paths

| Destination | Distance | Shortest path |
|---|---:|---|
| S | 0 | S |
| A | 6 | S → A |
| B | 11 | S → A → B |
| C | 3 | S → E → C |
| D | 6 | S → E → D |
| E | 2 | S → E |

### Pseudocode

```text
BELLMAN-FORD(G, S)
1. Set distance[S] = 0; all other distances = infinity.
2. Repeat V - 1 times:
       For every edge (u, v, w):
           If distance[u] is finite and
              distance[u] + w < distance[v]:
                  distance[v] = distance[u] + w
3. Scan all edges once more.
4. If any distance can be reduced, report a reachable negative cycle.
```

**Time complexity:** `O(VE)`.

**Conclusion:** Final distances are `S=0, A=6, B=11, C=3, D=6, E=2`; no reachable negative-weight cycle exists.

---

## 3. Floyd–Warshall algorithm for all-pairs shortest paths

**Question:** Show intermediate matrices, final shortest-distance matrix, paths, and time complexity. (8 marks)

### Definition

Floyd–Warshall is a Dynamic Programming algorithm that computes shortest distances between every pair of vertices in a weighted graph.

### Initial cost matrix

\[
D^{(0)}=
\begin{bmatrix}
0&4&\infty&10\\
\infty&0&3&\infty\\
\infty&\infty&0&2\\
\infty&\infty&\infty&0
\end{bmatrix}
\]

### Recurrence

\[
D_{ij}^{(k)}=\min\left(D_{ij}^{(k-1)},D_{ik}^{(k-1)}+D_{kj}^{(k-1)}\right)
\]

At iteration `k`, vertex `k` is allowed as an intermediate vertex.

### Iteration 1: Allow vertex 1

No distance improves because no other vertex has a path into vertex 1.

\[
D^{(1)}=
\begin{bmatrix}
0&4&\infty&10\\
\infty&0&3&\infty\\
\infty&\infty&0&2\\
\infty&\infty&\infty&0
\end{bmatrix}
\]

### Iteration 2: Allow vertex 2

The path from 1 to 3 through 2 costs `4 + 3 = 7`, improving infinity to 7.

\[
D^{(2)}=
\begin{bmatrix}
0&4&7&10\\
\infty&0&3&\infty\\
\infty&\infty&0&2\\
\infty&\infty&\infty&0
\end{bmatrix}
\]

### Iteration 3: Allow vertex 3

- `1 → 4`: `min(10, 7 + 2) = 9`.
- `2 → 4`: `min(∞, 3 + 2) = 5`.

\[
D^{(3)}=
\begin{bmatrix}
0&4&7&9\\
\infty&0&3&5\\
\infty&\infty&0&2\\
\infty&\infty&\infty&0
\end{bmatrix}
\]

### Iteration 4: Allow vertex 4

No distances improve because vertex 4 has no outgoing edges.

\[
D^{(4)}=
\begin{bmatrix}
0&4&7&9\\
\infty&0&3&5\\
\infty&\infty&0&2\\
\infty&\infty&\infty&0
\end{bmatrix}
\]

### Final shortest distances and paths

| Source | Destination | Distance | Path |
|---|---|---:|---|
| 1 | 2 | 4 | 1 → 2 |
| 1 | 3 | 7 | 1 → 2 → 3 |
| 1 | 4 | 9 | 1 → 2 → 3 → 4 |
| 2 | 3 | 3 | 2 → 3 |
| 2 | 4 | 5 | 2 → 3 → 4 |
| 3 | 4 | 2 | 3 → 4 |

Unreachable pairs retain distance infinity.

### Complexity

- Time: `O(V³)`.
- Space: `O(V²)`.

**Conclusion:** The final matrix gives shortest paths between every ordered pair of vertices. In particular, `D[1][4] = 9` and `D[2][4] = 5`.

---

## 4. Optimal Binary Search Tree (OBST) using Dynamic Programming

**Question:** Construct an OBST using the given key and search-probability weights. Show the cost table, roots, tree, and minimum expected cost. (8 marks)

### Given data

Ordered keys:

`do, if, int, while`

Successful-search weights:

\[
p_1,p_2,p_3,p_4=\{3,3,1,1\}
\]

Unsuccessful-search weights:

\[
q_0,q_1,q_2,q_3,q_4=\{2,3,1,1,1\}
\]

These are treated as relative weights, not normalized probabilities.

### Definition

An Optimal Binary Search Tree is a BST arranged to minimize weighted search cost. Keys with larger search weights should generally be placed closer to the root.

### DP variables and recurrence

- `e[i,j]`: minimum weighted cost for keys `i` through `j`.
- `w[i,j]`: total successful and unsuccessful search weight for the interval.
- `root[i,j]`: root index that gives the minimum cost.

Base cases:

\[
e[i,i-1]=q_{i-1},\quad w[i,i-1]=q_{i-1}
\]

Weight recurrence:

\[
w[i,j]=w[i,j-1]+p_j+q_j
\]

Cost recurrence:

\[
e[i,j]=\min_{r=i}^{j}\left(e[i,r-1]+e[r+1,j]+w[i,j]\right)
\]

### Cost and root table

| Interval | Minimum weighted cost | Root |
|---|---:|---|
| `do` | 13 | do |
| `if` | 11 | if |
| `int` | 5 | int |
| `while` | 5 | while |
| `do, if` | 25 | do |
| `if, int` | 17 | if |
| `int, while` | 11 | int |
| `do, if, int` | 32 | if |
| `if, int, while` | 25 | if |
| `do, if, int, while` | **40** | **if** |

The single-key costs include the costs of unsuccessful searches on the dummy leaves. For example, `e[1,1] = q0 + q1 + (q0 + p1 + q1) = 13`.

### Construct the tree

The root for all four keys is `if`.

- Left subtree: `do`.
- Right subtree: `int`.
- Right child of `int`: `while`.

```text
          if
         /  \
       do    int
                \
                while
```

The complete OBST also has unsuccessful-search dummy leaves `d0` through `d4`.

### Minimum expected search cost

The total weight is:

\[
\sum p_i+\sum q_i=8+8=16
\]

The minimum weighted cost is:

\[
e[1,4]=40
\]

Normalizing the weights gives:

\[
\text{Expected cost}=\frac{40}{16}=\boxed{2.5}
\]

**Conclusion:** The optimal root is `if`; the minimum weighted cost is 40, equivalent to 2.5 comparisons per search after normalization.

---

## 5. 0/1 Knapsack using Dynamic Programming

**Question:** For capacity 10, construct the DP table, identify selected items, calculate maximum profit, and explain why ratio-based Greedy selection is not always optimal. (8 marks)

### Given data

| Item | Weight | Profit |
|---|---:|---:|
| I1 | 2 | 12 |
| I2 | 3 | 20 |
| I3 | 4 | 25 |
| I4 | 5 | 30 |
| I5 | 6 | 35 |

Capacity `W = 10`.

### DP state and recurrence

Let `DP[i][w]` be the maximum profit using the first `i` items with capacity `w`.

If item `i` is too heavy:

\[
DP[i,w]=DP[i-1,w]
\]

Otherwise:

\[
DP[i,w]=\max(DP[i-1,w],p_i+DP[i-1,w-w_i])
\]

Base cases: `DP[0][w] = 0` and `DP[i][0] = 0`.

### DP table

| Items considered | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|---|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|---:|
| None | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0 |
| I1 | 0 | 0 | 12 | 12 | 12 | 12 | 12 | 12 | 12 | 12 | 12 |
| I1, I2 | 0 | 0 | 12 | 20 | 20 | 32 | 32 | 32 | 32 | 32 | 32 |
| I1–I3 | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 45 | 57 | 57 |
| I1–I4 | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 50 | 57 | 62 |
| I1–I5 | 0 | 0 | 12 | 20 | 25 | 32 | 37 | 45 | 50 | 57 | **62** |

Therefore:

\[
DP[5,10]=\boxed{62}
\]

### Recover the selected items

The maximum value 62 is obtained by selecting:

- I4: weight 5, profit 30.
- I2: weight 3, profit 20.
- I1: weight 2, profit 12.

Total weight: `5 + 3 + 2 = 10`.

Total profit:

\[
30+20+12=\boxed{62}
\]

### Why a ratio-based Greedy approach may fail

| Item | Weight | Profit | Ratio |
|---|---:|---:|---:|
| I1 | 2 | 12 | 6.00 |
| I2 | 3 | 20 | 6.67 |
| I3 | 4 | 25 | 6.25 |
| I4 | 5 | 30 | 6.00 |
| I5 | 6 | 35 | 5.83 |

A ratio-based choice of I2, I3, then I1 uses weight 9 and earns profit 57, which is less than 62. In 0/1 Knapsack, items cannot be split, so locally best ratios do not guarantee a globally optimal combination.

**Complexity:** Time `O(nW)`; space `O(nW)` for the full table.

**Conclusion:** The optimal selection is I1, I2, and I4, with total weight 10 and profit **62**.

---

## 6. Travelling Salesperson Problem (TSP) using Held–Karp Dynamic Programming

**Question:** Find an optimal tour and minimum cost using Dynamic Programming. (8 marks)

### Given cost matrix

Cities: A, B, C, D. Start and finish at A.

\[
C=
\begin{bmatrix}
0&10&15&20\\
10&0&35&25\\
15&35&0&30\\
20&25&30&0
\end{bmatrix}
\]

### Definition

The Travelling Salesperson Problem seeks the minimum-cost tour that starts at a city, visits every other city exactly once, and returns to the start.

### DP state

`DP[S][j]` is the minimum cost of a path starting at A, visiting the subset `S` of other cities, and ending at city `j`.

Base case:

\[
DP[\{j\}][j]=C[A][j]
\]

Recurrence:

\[
DP[S][j]=\min_{i\in S,\ i\ne j}
\left(DP[S-\{j\}][i]+C[i][j]\right)
\]

After visiting every city, return to A:

\[
\min_j\left(DP[\{B,C,D\}][j]+C[j][A]\right)
\]

### Single-city states

- `DP[{B}][B] = 10`
- `DP[{C}][C] = 15`
- `DP[{D}][D] = 20`

### Two-city states

| Visited subset | Ending city | Cost |
|---|---|---:|
| B, C | B | `15 + 35 = 50` |
| B, C | C | `10 + 35 = 45` |
| B, D | B | `20 + 25 = 45` |
| B, D | D | `10 + 25 = 35` |
| C, D | C | `20 + 30 = 50` |
| C, D | D | `15 + 30 = 45` |

### Three-city states

Ending at B:

\[
DP[\{B,C,D\}][B]=\min(50+35,45+25)=70
\]

Ending at C:

\[
DP[\{B,C,D\}][C]=\min(45+35,35+30)=65
\]

Ending at D:

\[
DP[\{B,C,D\}][D]=\min(45+25,45+30)=70
\]

### Return to A

| Final city before A | Path cost before return | Return edge | Tour cost |
|---|---:|---:|---:|
| B | 70 | 10 | 80 |
| C | 65 | 15 | 80 |
| D | 70 | 20 | 90 |

The minimum tour cost is:

\[
\boxed{80}
\]

One optimal tour is:

`A → B → D → C → A`

Cost:

\[
10+25+30+15=\boxed{80}
\]

The reverse tour `A → C → D → B → A` also costs 80.

### Complexity

- Time: `O(n² 2ⁿ)`.
- Space: `O(n 2ⁿ)`.

**Conclusion:** The Held–Karp algorithm gives a minimum tour cost of **80**.

---
