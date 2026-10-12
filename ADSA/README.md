# Design and Analysis of Algorithms — 8-Mark Answers

Detailed exam-ready questions and worked answers split by unit in Markdown.

## Map / Contents

| File | Contents |
|---|---|
| [`ADS&AA unit-wise Important questions-1.md`](ADS&AA%20unit-wise%20Important%20questions-1.md) | Complete Unit-I to Unit-V Important Questions mapped to each unit's `.md` answer section |
| [`UNIT-I.md`](UNIT-I.md) | Algorithm Analysis, Time vs. Space Complexity, Asymptotic Notations ($O, \Omega, \Theta$), Matrix Multiplication Analysis, Hashing & Hash Functions, Collision Resolution, Static vs. Extendible Hashing |
| [`UNIT-II.md`](UNIT-II.md) | AVL Tree Construction, Four AVL Rotations & Applications, AVL Deletion (`15`), B-Tree Order-4 Construction, B-Tree Deletion & Applications, Min/Max Heap Construction, Max Heap Deletion (`90`), Binary Heap Operations & Priority Queues |
| [`UNIT-III.md`](UNIT-III.md) | Divide and Conquer, Binary Search, Merge Sort, Quick Sort, Greedy Job Sequencing, Fractional Knapsack, Minimum Spanning Tree (Kruskal & Prim), Dijkstra’s Algorithm |
| [`UNIT-IV.md`](UNIT-IV.md) | Dynamic Programming Methodology, Bellman–Ford, Floyd–Warshall, Optimal Binary Search Tree (OBST), 0/1 Knapsack (DP), Travelling Salesperson Problem (Held–Karp DP) |
| [`UNIT-V.md`](UNIT-V.md) | Backtracking Methodology & State-Space Trees, 4-Queens Problem, Sum of Subsets, Graph 3-Coloring, Hamiltonian Cycles, 0/1 Knapsack (LC Branch & Bound), Travelling Salesperson Problem (Branch & Bound), Backtracking vs. Branch & Bound |

---

## Question-to-Answer Map (All `.md`)

### UNIT-I — [`UNIT-I.md`](UNIT-I.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Importance of Algorithm Analysis, Time vs. Space Complexity | [`UNIT-I.md` — §1](UNIT-I.md#1-importance-of-algorithm-analysis-and-time-vs-space-complexity) |
| **Q2** | Asymptotic Notations ($O, \Omega, \Theta$) | [`UNIT-I.md` — §2](UNIT-I.md#2-asymptotic-notations-big-o-omega-and-theta) |
| **Q3** | Matrix Multiplication Time Complexity (Tabular Method) | [`UNIT-I.md` — §3](UNIT-I.md#3-time-complexity-of-matrix-multiplication-tabular-step-count-method) |
| **Q4** | Concept of Hashing & Hash Functions | [`UNIT-I.md` — §4](UNIT-I.md#4-concept-of-hashing-and-hash-functions) |
| **Q5** | Collision Resolution (Linear, Quadratic, Double Hashing, Chaining) | [`UNIT-I.md` — §5](UNIT-I.md#5-collision-resolution-techniques) |
| **Q6** | Static vs. Dynamic Hashing (Extendible Hashing) | [`UNIT-I.md` — §6](UNIT-I.md#6-static-hashing-vs-dynamic-hashing-extendible-hashing) |

### UNIT-II — [`UNIT-II.md`](UNIT-II.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Construct AVL Tree (`50, 25, 12, 80, 90, 37, 45, 18, 19, 6`) | [`UNIT-II.md` — §1](UNIT-II.md#1-construct-an-avl-tree-by-step-by-step-insertion) |
| **Q2** | Four Types of AVL Tree Rotations & Applications | [`UNIT-II.md` — §2](UNIT-II.md#2-four-types-of-avl-tree-rotations-and-applications) |
| **Q3** | AVL Tree Deletion Procedure (Delete `15`) | [`UNIT-II.md` — §3](UNIT-II.md#3-deletion-procedure-in-avl-tree-delete-15) |
| **Q4** | Construct B-Tree of Order 4 (`5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`) | [`UNIT-II.md` — §4](UNIT-II.md#4-construct-a-b-tree-of-order-4) |
| **Q5** | B-Tree Deletion Operation & Applications | [`UNIT-II.md` — §5](UNIT-II.md#5-deletion-operation-in-a-b-tree-and-applications) |
| **Q6** | Construct Min/Max Heap (`40, 15, 30, 10, 12, 6, 25, 18`) | [`UNIT-II.md` — §6](UNIT-II.md#6-construct-a-min-heap-and-max-heap) |
| **Q7** | Max Heap Deletion Operation (Delete `90`) | [`UNIT-II.md` — §7](UNIT-II.md#7-deletion-operation-on-given-max-heap) |
| **Q8** | Binary Heap Operations & Priority Queue Applications | [`UNIT-II.md` — §8](UNIT-II.md#8-basic-operations-of-a-binary-heap-and-applications-of-priority-queues) |

### UNIT-III — [`UNIT-III.md`](UNIT-III.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1(A)** | Divide and Conquer General Methodology | [`UNIT-III.md` — §1(A)](UNIT-III.md#1a-explain-the-general-methodology-of-divide-and-conquer-illustrate-its-three-fundamental-steps-with-examples-8-marks) |
| **Q1(B)** | Binary Search (15+ Keys Trace) | [`UNIT-III.md` — §1(B)](UNIT-III.md#1b-apply-binary-search-to-locate-a-key-in-a-sorted-array-of-at-least-15-keys-show-low-high-and-mid-at-every-iteration-and-count-comparisons-8-marks) |
| **Q2** | Merge Sort (`42, 17, 8, 33, 25, 61, 14, 50, 9, 37`) | [`UNIT-III.md` — §2](UNIT-III.md#2-merge-sort) |
| **Q3** | Quick Sort (`35, 18, 42, 7, 29, 51, 13, 24, 46`) | [`UNIT-III.md` — §3](UNIT-III.md#3-quick-sort) |
| **Q4** | Greedy Job Sequencing with Deadlines | [`UNIT-III.md` — §4](UNIT-III.md#4-greedy-job-sequencing-with-deadlines) |
| **Q5** | Fractional Knapsack Problem ($W = 50$) | [`UNIT-III.md` — §5](UNIT-III.md#5-fractional-knapsack-using-greedy) |
| **Q6** | Minimum Spanning Tree (Kruskal's & Prim's) | [`UNIT-III.md` — §6](UNIT-III.md#6-minimum-spanning-tree-using-kruskals-and-prims-algorithms) |
| **Q7** | Dijkstra's Single-Source Shortest Paths | [`UNIT-III.md` — §7](UNIT-III.md#7-dijkstras-algorithm-from-source-a) |

### UNIT-IV — [`UNIT-IV.md`](UNIT-IV.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Dynamic Programming Methodology & vs. Divide and Conquer | [`UNIT-IV.md` — §1](UNIT-IV.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer) |
| **Q2** | Bellman–Ford Shortest Paths from Source $S$ | [`UNIT-IV.md` — §2](UNIT-IV.md#2-bellmanford-algorithm-from-source-s) |
| **Q3** | Floyd–Warshall All-Pairs Shortest Paths | [`UNIT-IV.md` — §3](UNIT-IV.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths) |
| **Q4** | Optimal Binary Search Tree (`do, if, int, while`) | [`UNIT-IV.md` — §4](UNIT-IV.md#4-optimal-binary-search-tree-obst-using-dynamic-programming) |
| **Q5** | 0/1 Knapsack using Dynamic Programming ($W = 10$) | [`UNIT-IV.md` — §5](UNIT-IV.md#5-01-knapsack-using-dynamic-programming) |
| **Q6** | Travelling Salesperson Problem (Held–Karp DP) | [`UNIT-IV.md` — §6](UNIT-IV.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming) |

### UNIT-V — [`UNIT-V.md`](UNIT-V.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Backtracking General Methodology & State-Space Tree | [`UNIT-V.md` — §1](UNIT-V.md#1-backtracking-general-methodology-state-space-tree-bounding-conditions-and-comparison-with-exhaustive-search) |
| **Q2** | 4-Queens Problem using Backtracking | [`UNIT-V.md` — §2](UNIT-V.md#2-4-queens-problem-using-backtracking) |
| **Q3** | Sum of Subsets ($S=\{5,10,12,13,15,18\}, M=30$) | [`UNIT-V.md` — §3](UNIT-V.md#3-sum-of-subsets-using-backtracking) |
| **Q4** | 3-Coloring Undirected Graph using Backtracking | [`UNIT-V.md` — §4](UNIT-V.md#4-graph-coloring-using-backtracking-3-colors) |
| **Q5** | Hamiltonian Cycles using Backtracking | [`UNIT-V.md` — §5](UNIT-V.md#5-hamiltonian-cycles-using-backtracking) |
| **Q6** | 0/1 Knapsack (Least Cost Branch and Bound, $W = 16$) | [`UNIT-V.md` — §6](UNIT-V.md#6-01-knapsack-using-least-cost-lc-branch-and-bound) |
| **Q7** | Travelling Salesperson Problem (Branch and Bound) | [`UNIT-V.md` — §7](UNIT-V.md#7-travelling-salesperson-problem-tsp-using-branch-and-bound) |
| **Q8** | Compare Backtracking and Branch & Bound | [`UNIT-V.md` — §8](UNIT-V.md#8-compare-and-contrast-backtracking-and-branch-and-bound) |
