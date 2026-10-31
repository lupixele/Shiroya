# Design and Analysis of Algorithms — 8-Mark Answers

Detailed exam-ready questions and worked answers split by unit in Markdown.

## Map / Contents

| File | Contents |
|---|---|
| [`questions.md`](questions.md) | ADSAA Important Questions for IE 2 (Units 3, 4, 5) with direct answer links |
| [`unit-1.md`](unit-1.md) | Algorithm Analysis, Time vs. Space Complexity, Asymptotic Notations ($O, \Omega, \Theta$), Matrix Multiplication Analysis, Hashing & Hash Functions, Collision Resolution, Static vs. Extendible Hashing |
| [`unit-2.md`](unit-2.md) | AVL Tree Construction, Four AVL Rotations & Applications, AVL Deletion (`15`), B-Tree Order-4 Construction, B-Tree Deletion & Applications, Min/Max Heap Construction, Max Heap Deletion (`90`), Binary Heap Operations & Priority Queues |
| [`unit-3.md`](unit-3.md) | Divide and Conquer, Binary Search, Merge Sort, Quick Sort, Greedy Job Sequencing, Fractional Knapsack, Minimum Spanning Tree (Kruskal & Prim), Dijkstra’s Algorithm |
| [`unit-4.md`](unit-4.md) | Dynamic Programming Methodology, Bellman–Ford, Floyd–Warshall, Optimal Binary Search Tree (OBST), 0/1 Knapsack (DP), Travelling Salesperson Problem (Held–Karp DP) |
| [`unit-5.md`](unit-5.md) | Backtracking Methodology & State-Space Trees, 4-Queens Problem, Sum of Subsets, Graph 3-Coloring, Hamiltonian Cycles, 0/1 Knapsack (LC Branch & Bound), Travelling Salesperson Problem (Branch & Bound), Backtracking vs. Branch & Bound |

---

## Question-to-Answer Map (All `.md`)

### UNIT-I — [`unit-1.md`](unit-1.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Importance of Algorithm Analysis, Time vs. Space Complexity | [`unit-1.md` — §1](unit-1.md#1-importance-of-algorithm-analysis-and-time-vs-space-complexity) |
| **Q2** | Asymptotic Notations ($O, \Omega, \Theta$) | [`unit-1.md` — §2](unit-1.md#2-asymptotic-notations-big-o-omega-and-theta) |
| **Q3** | Matrix Multiplication Time Complexity (Tabular Method) | [`unit-1.md` — §3](unit-1.md#3-time-complexity-of-matrix-multiplication-tabular-step-count-method) |
| **Q4** | Concept of Hashing & Hash Functions | [`unit-1.md` — §4](unit-1.md#4-concept-of-hashing-and-hash-functions) |
| **Q5** | Collision Resolution (Linear, Quadratic, Double Hashing, Chaining) | [`unit-1.md` — §5](unit-1.md#5-collision-resolution-techniques) |
| **Q6** | Static vs. Dynamic Hashing (Extendible Hashing) | [`unit-1.md` — §6](unit-1.md#6-static-hashing-vs-dynamic-hashing-extendible-hashing) |

### UNIT-II — [`unit-2.md`](unit-2.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Construct AVL Tree (`50, 25, 12, 80, 90, 37, 45, 18, 19, 6`) | [`unit-2.md` — §1](unit-2.md#1-construct-an-avl-tree-by-step-by-step-insertion) |
| **Q2** | Four Types of AVL Tree Rotations & Applications | [`unit-2.md` — §2](unit-2.md#2-four-types-of-avl-tree-rotations-and-applications) |
| **Q3** | AVL Tree Deletion Procedure (Delete `15`) | [`unit-2.md` — §3](unit-2.md#3-deletion-procedure-in-avl-tree-delete-15) |
| **Q4** | Construct B-Tree of Order 4 (`5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`) | [`unit-2.md` — §4](unit-2.md#4-construct-a-b-tree-of-order-4) |
| **Q5** | B-Tree Deletion Operation & Applications | [`unit-2.md` — §5](unit-2.md#5-deletion-operation-in-a-b-tree-and-applications) |
| **Q6** | Construct Min/Max Heap (`40, 15, 30, 10, 12, 6, 25, 18`) | [`unit-2.md` — §6](unit-2.md#6-construct-a-min-heap-and-max-heap) |
| **Q7** | Max Heap Deletion Operation (Delete `90`) | [`unit-2.md` — §7](unit-2.md#7-deletion-operation-on-given-max-heap) |
| **Q8** | Binary Heap Operations & Priority Queue Applications | [`unit-2.md` — §8](unit-2.md#8-basic-operations-of-a-binary-heap-and-applications-of-priority-queues) |

### UNIT-III — [`unit-3.md`](unit-3.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1(A)** | Divide and Conquer General Methodology | [`unit-3.md` — §1(A)](unit-3.md#1a-explain-the-general-methodology-of-divide-and-conquer-illustrate-its-three-fundamental-steps-with-examples-8-marks) |
| **Q1(B)** | Binary Search (15+ Keys Trace) | [`unit-3.md` — §1(B)](unit-3.md#1b-apply-binary-search-to-locate-a-key-in-a-sorted-array-of-at-least-15-keys-show-low-high-and-mid-at-every-iteration-and-count-comparisons-8-marks) |
| **Q2** | Merge Sort (`42, 17, 8, 33, 25, 61, 14, 50, 9, 37`) | [`unit-3.md` — §2](unit-3.md#2-merge-sort) |
| **Q3** | Quick Sort (`35, 18, 42, 7, 29, 51, 13, 24, 46`) | [`unit-3.md` — §3](unit-3.md#3-quick-sort) |
| **Q4** | Greedy Job Sequencing with Deadlines | [`unit-3.md` — §4](unit-3.md#4-greedy-job-sequencing-with-deadlines) |
| **Q5** | Fractional Knapsack Problem ($W = 50$) | [`unit-3.md` — §5](unit-3.md#5-fractional-knapsack-using-greedy) |
| **Q6** | Minimum Spanning Tree (Kruskal's & Prim's) | [`unit-3.md` — §6](unit-3.md#6-minimum-spanning-tree-using-kruskals-and-prims-algorithms) |
| **Q7** | Dijkstra's Single-Source Shortest Paths | [`unit-3.md` — §7](unit-3.md#7-dijkstras-algorithm-from-source-a) |

### UNIT-IV — [`unit-4.md`](unit-4.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Dynamic Programming Methodology & vs. Divide and Conquer | [`unit-4.md` — §1](unit-4.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer) |
| **Q2** | Bellman–Ford Shortest Paths from Source $S$ | [`unit-4.md` — §2](unit-4.md#2-bellmanford-algorithm-from-source-s) |
| **Q3** | Floyd–Warshall All-Pairs Shortest Paths | [`unit-4.md` — §3](unit-4.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths) |
| **Q4** | Optimal Binary Search Tree (`do, if, int, while`) | [`unit-4.md` — §4](unit-4.md#4-optimal-binary-search-tree-obst-using-dynamic-programming) |
| **Q5** | 0/1 Knapsack using Dynamic Programming ($W = 10$) | [`unit-4.md` — §5](unit-4.md#5-01-knapsack-using-dynamic-programming) |
| **Q6** | Travelling Salesperson Problem (Held–Karp DP) | [`unit-4.md` — §6](unit-4.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming) |

### UNIT-V — [`unit-5.md`](unit-5.md)

| Q# | Topic | Worked Answer Section |
| :---: | :--- | :--- |
| **Q1** | Backtracking General Methodology & State-Space Tree | [`unit-5.md` — §1](unit-5.md#1-backtracking-general-methodology-state-space-tree-bounding-conditions-and-comparison-with-exhaustive-search) |
| **Q2** | 4-Queens Problem using Backtracking | [`unit-5.md` — §2](unit-5.md#2-4-queens-problem-using-backtracking) |
| **Q3** | Sum of Subsets ($S=\{5,10,12,13,15,18\}, M=30$) | [`unit-5.md` — §3](unit-5.md#3-sum-of-subsets-using-backtracking) |
| **Q4** | 3-Coloring Undirected Graph using Backtracking | [`unit-5.md` — §4](unit-5.md#4-graph-coloring-using-backtracking-3-colors) |
| **Q5** | Hamiltonian Cycles using Backtracking | [`unit-5.md` — §5](unit-5.md#5-hamiltonian-cycles-using-backtracking) |
| **Q6** | 0/1 Knapsack (Least Cost Branch and Bound, $W = 16$) | [`unit-5.md` — §6](unit-5.md#6-01-knapsack-using-least-cost-lc-branch-and-bound) |
| **Q7** | Travelling Salesperson Problem (Branch and Bound) | [`unit-5.md` — §7](unit-5.md#7-travelling-salesperson-problem-tsp-using-branch-and-bound) |
| **Q8** | Compare Backtracking and Branch & Bound | [`unit-5.md` — §8](unit-5.md#8-compare-and-contrast-backtracking-and-branch-and-bound) |
