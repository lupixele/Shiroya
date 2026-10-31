# ADSA Semester Examination Questions (Units 1–5)

> **Course Code:** `2501CS10` — Advanced Data Structures & Algorithm Analysis | Aditya University  
> **Scope:** Semester-End Examinations (Units 1–5)  
> **Structure:** 5 High-Yield Questions Per Unit (Total 25 Core Long-Answer Questions)

---

## Revision Priority & Unit Difficulty Guide

Recommended sequence for maximum revision efficiency and scoring:

| Priority | Unit | Focus Area | Difficulty | Why Prioritize This Way |
| :---: | :---: | :--- | :---: | :--- |
| **P1** | **Unit 3** | Divide & Conquer / Greedy Method | **Easy–Medium (4/10)** | Highly predictable, high-scoring traces (Merge/Quick sort, Job sequencing, Kruskal/Prim). |
| **P2** | **Unit 1** | Algorithm Analysis & Hashing | **Easy (3/10)** | Fast revision; straightforward theory and math (Asymptotic notations, Matrix step-count, Hashing). |
| **P3** | **Unit 2** | Balanced Trees & Heaps | **Medium (5/10)** | Mechanical steps; once rotations ($LL/RR/LR/RL$) and B-tree/heap operations are clear, marks are guaranteed. |
| **P4** | **Unit 4** | Dynamic Programming | **Hard (7.5/10)** | Concept-heavy; requires memorizing recurrences and practicing manual table construction (Floyd, Knapsack). |
| **P5** | **Unit 5** | Backtracking & Branch and Bound | **Hard (8/10)** | Large manual state-space trees; prone to small arithmetic errors under exam pressure. |

---

## Semester Exam Quick-Reference Map

| Unit | Q# | Core Topic | Difficulty | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **Unit 1** | Q1 | Algorithm Analysis & Time vs. Space Complexity | **Easy (2/10)** | [→ Answer](unit-1.md#1-importance-of-algorithm-analysis-and-time-vs-space-complexity) |
| *(P2)* | Q2 | Asymptotic Notations ($O, \Omega, \Theta$) with Examples | **Easy (3/10)** | [→ Answer](unit-1.md#2-asymptotic-notations-big-o-omega-and-theta) |
| | Q3 | Matrix Multiplication Complexity (Step-Count Method) | **Easy (3/10)** | [→ Answer](unit-1.md#3-time-complexity-of-matrix-multiplication-tabular-step-count-method) |
| | Q4 | Collision Resolution Techniques (Chaining & Open Addressing) | **Medium (4/10)** | [→ Answer](unit-1.md#5-collision-resolution-techniques) |
| | Q5 | Static vs. Dynamic Hashing (Extendible Hashing) | **Medium (5/10)** | [→ Answer](unit-1.md#6-static-hashing-vs-dynamic-hashing-extendible-hashing) |
| **Unit 2** | Q1 | Construct AVL Tree Step-by-Step with Rotations | **Medium (5/10)** | [→ Answer](unit-2.md#1-construct-an-avl-tree-by-step-by-step-insertion) |
| *(P3)* | Q2 | Four AVL Tree Rotations ($LL, RR, LR, RL$) & Applications | **Easy (3/10)** | [→ Answer](unit-2.md#2-four-types-of-avl-tree-rotations-and-applications) |
| | Q3 | Construct B-Tree of Order 4 & Structural Properties | **Medium (5/10)** | [→ Answer](unit-2.md#4-construct-a-b-tree-of-order-4) |
| | Q4 | Construct Min Heap and Max Heap from Given Keys | **Easy (3/10)** | [→ Answer](unit-2.md#6-construct-a-min-heap-and-max-heap) |
| | Q5 | Binary Heap Operations & Applications of Priority Queues | **Easy (3/10)** | [→ Answer](unit-2.md#8-basic-operations-of-a-binary-heap-and-applications-of-priority-queues) |
| **Unit 3** | Q1 | Merge Sort Working Strategy, Recurrence & Trace | **Easy (3/10)** | [→ Answer](unit-3.md#2-merge-sort) |
| *(P1)* | Q2 | Quick Sort Algorithm, Partitioning & Complexity | **Easy (3/10)** | [→ Answer](unit-3.md#3-quick-sort) |
| | Q3 | Greedy Job Sequencing with Deadlines & Feasible Solution | **Medium (4/10)** | [→ Answer](unit-3.md#4-greedy-job-sequencing-with-deadlines) |
| | Q4 | Fractional Knapsack Problem using Greedy Method | **Easy (3/10)** | [→ Answer](unit-3.md#5-fractional-knapsack-using-greedy) |
| | Q5 | Minimum Spanning Tree (Kruskal's and Prim's Algorithms) | **Medium (5/10)** | [→ Answer](unit-3.md#6-minimum-spanning-tree-using-kruskals-and-prims-algorithms) |
| **Unit 4** | Q1 | Dynamic Programming Methodology & DP vs. D&C | **Medium (4/10)** | [→ Answer](unit-4.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer) |
| *(P4)* | Q2 | Floyd–Warshall Algorithm for All-Pairs Shortest Paths | **Hard (7/10)** | [→ Answer](unit-4.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths) |
| | Q3 | Optimal Binary Search Tree (OBST) Dynamic Programming | **Extremely Hard (9/10)** | [→ Answer](unit-4.md#4-optimal-binary-search-tree-obst-using-dynamic-programming) |
| | Q4 | 0/1 Knapsack Problem using Dynamic Programming | **Hard (7/10)** | [→ Answer](unit-4.md#5-01-knapsack-using-dynamic-programming) |
| | Q5 | Travelling Salesperson Problem (TSP) using DP (Held–Karp) | **Hard (8/10)** | [→ Answer](unit-4.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming) |
| **Unit 5** | Q1 | 4-Queens Problem using Backtracking & State-Space Tree | **Medium (5/10)** | [→ Answer](unit-5.md#2-4-queens-problem-using-backtracking) |
| *(P5)* | Q2 | Sum of Subsets Problem using Backtracking | **Medium (5/10)** | [→ Answer](unit-5.md#3-sum-of-subsets-using-backtracking) |
| | Q3 | Graph Coloring Problem using Backtracking (3 Colors) | **Medium (5/10)** | [→ Answer](unit-5.md#4-graph-coloring-using-backtracking-3-colors) |
| | Q4 | 0/1 Knapsack Problem using Least-Cost Branch and Bound | **Hard (8/10)** | [→ Answer](unit-5.md#6-01-knapsack-using-least-cost-lc-branch-and-bound) |
| | Q5 | Compare and Contrast Backtracking and Branch & Bound | **Easy (3/10)** | [→ Answer](unit-5.md#8-compare-and-contrast-backtracking-and-branch-and-bound) |

---

## Unit 1: Algorithm Analysis & Hashing

> **Exam Priority:** Priority 2 | **Unit Difficulty:** Easy (3/10)

### Q1. Algorithm Analysis & Time vs. Space Complexity *(Difficulty: Easy · 2/10)*
Explain the importance of algorithm analysis. Differentiate between time complexity and space complexity with suitable examples.
- [→ Worked Answer](unit-1.md#1-importance-of-algorithm-analysis-and-time-vs-space-complexity)

### Q2. Asymptotic Notations *(Difficulty: Easy · 3/10)*
Describe the asymptotic notations $O$, $\Omega$, and $\Theta$. Illustrate each notation with definitions, graphs, and mathematical examples.
- [→ Worked Answer](unit-1.md#2-asymptotic-notations-big-o-omega-and-theta)

### Q3. Matrix Multiplication Complexity *(Difficulty: Easy · 3/10)*
Analyze the time complexity for standard matrix multiplication algorithm using the step-count / tabular method and justify your answer.
- [→ Worked Answer](unit-1.md#3-time-complexity-of-matrix-multiplication-tabular-step-count-method)

### Q4. Collision Resolution Techniques *(Difficulty: Medium · 4/10)*
Explain the collision resolution techniques: Separate Chaining, Linear Probing, Quadratic Probing, and Double Hashing with comparative tradeoffs.
- [→ Worked Answer](unit-1.md#5-collision-resolution-techniques)

### Q5. Static Hashing vs. Dynamic Hashing *(Difficulty: Medium · 5/10)*
Differentiate between Static Hashing and Dynamic Hashing. Explain the working of Dynamic Hashing (Extendible Hashing) with global/local depth and bucket splitting.
- [→ Worked Answer](unit-1.md#6-static-hashing-vs-dynamic-hashing-extendible-hashing)

---

## Unit 2: Balanced Trees & Priority Queues

> **Exam Priority:** Priority 3 | **Unit Difficulty:** Medium (5/10)

### Q1. Construct AVL Tree *(Difficulty: Medium · 5/10)*
Construct an AVL Tree by inserting the following keys: `50, 25, 12, 80, 90, 37, 45, 18, 19, 6`. Show the required rotations after each step.
- [→ Worked Answer](unit-2.md#1-construct-an-avl-tree-by-step-by-step-insertion)

### Q2. Four Types of AVL Tree Rotations & Applications *(Difficulty: Easy · 3/10)*
Explain the four types of AVL Tree rotations ($LL, RR, LR, RL$) with diagrams and worked examples. Discuss real-world applications of AVL trees.
- [→ Worked Answer](unit-2.md#2-four-types-of-avl-tree-rotations-and-applications)

### Q3. B-Tree Construction (Order 4) *(Difficulty: Medium · 5/10)*
Construct a B-Tree of order 4 by inserting the keys: `5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`. Discuss node splitting and properties.
- [→ Worked Answer](unit-2.md#4-construct-a-b-tree-of-order-4)

### Q4. Construct Min Heap and Max Heap *(Difficulty: Easy · 3/10)*
Construct a Min Heap and a Max Heap by inserting the elements: `40, 15, 30, 10, 12, 6, 25, 18`. Show the intermediate heap representations.
- [→ Worked Answer](unit-2.md#6-construct-a-min-heap-and-max-heap)

### Q5. Binary Heap Operations & Priority Queues *(Difficulty: Easy · 3/10)*
Explain the basic operations of a Binary Heap (`insert`, `deleteMax`/`extractMin`, `heapify`) with their time complexities. Discuss the applications of Priority Queues.
- [→ Worked Answer](unit-2.md#8-basic-operations-of-a-binary-heap-and-applications-of-priority-queues)

---

## Unit 3: Divide and Conquer & Greedy Method

> **Exam Priority:** Priority 1 (Start Here) | **Unit Difficulty:** Easy–Medium (4/10)

### Q1. Merge Sort Algorithm & Analysis *(Difficulty: Easy · 3/10)*
Discuss the working strategy of Merge Sort. Derive its recurrence relation $T(n) = 2T(n/2) + \Theta(n)$ and illustrate with an example array.
- [→ Worked Answer](unit-3.md#2-merge-sort)

### Q2. Quick Sort Algorithm & Analysis *(Difficulty: Easy · 3/10)*
Write the Quick Sort algorithm based on divide-and-conquer strategy. Analyze its best, average, and worst-case time complexities.
- [→ Worked Answer](unit-3.md#3-quick-sort)

### Q3. Greedy Job Sequencing with Deadlines *(Difficulty: Medium · 4/10)*
Explain the Job Sequencing with Deadlines problem. Find the optimal sequence and maximum profit for jobs with given deadlines and profits.
- [→ Worked Answer](unit-3.md#4-greedy-job-sequencing-with-deadlines)

### Q4. Fractional Knapsack using Greedy Method *(Difficulty: Easy · 3/10)*
Explain the Fractional Knapsack problem using Greedy strategy. Formulate the algorithm based on profit-to-weight ratio $p_i / w_i$.
- [→ Worked Answer](unit-3.md#5-fractional-knapsack-using-greedy)

### Q5. Minimum Spanning Tree (Kruskal's & Prim's) *(Difficulty: Medium · 5/10)*
Define Minimum Spanning Tree. Explain Kruskal's algorithm (edge sorting with union-find) and Prim's algorithm (vertex growth) with step-by-step traces.
- [→ Worked Answer](unit-3.md#6-minimum-spanning-tree-using-kruskals-and-prims-algorithms)

---

## Unit 4: Dynamic Programming

> **Exam Priority:** Priority 4 | **Unit Difficulty:** Hard (7.5/10)

### Q1. Dynamic Programming Methodology *(Difficulty: Medium · 4/10)*
Explain the general methodology of Dynamic Programming. Discuss optimal substructure and overlapping subproblems. Differentiate DP from Divide and Conquer.
- [→ Worked Answer](unit-4.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer)

### Q2. Floyd–Warshall Algorithm (All-Pairs Shortest Paths) *(Difficulty: Hard · 7/10)*
Write and explain the Floyd–Warshall algorithm to compute all-pairs shortest paths using dynamic programming. Show the recurrence and iteration matrices.
- [→ Worked Answer](unit-4.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths)

### Q3. Optimal Binary Search Tree (OBST) *(Difficulty: Extremely Hard · 9/10)*
Formulate the Optimal Binary Search Tree problem using Dynamic Programming. Explain the cost recurrence $c(i, j) = w(i, j) + \min_{i < k \le j} \{c(i, k-1) + c(k, j)\}$.
- [→ Worked Answer](unit-4.md#4-optimal-binary-search-tree-obst-using-dynamic-programming)

### Q4. 0/1 Knapsack using Dynamic Programming *(Difficulty: Hard · 7/10)*
Solve the 0/1 Knapsack problem using Dynamic Programming. State the recurrence relation and demonstrate the table filling and item backtracking steps.
- [→ Worked Answer](unit-4.md#5-01-knapsack-using-dynamic-programming)

### Q5. Travelling Salesperson Problem (TSP) *(Difficulty: Hard · 8/10)*
Explain the Travelling Salesperson Problem using Dynamic Programming (Held–Karp algorithm). State the recurrence relation and analyze its time complexity.
- [→ Worked Answer](unit-4.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming)

---

## Unit 5: Backtracking & Branch and Bound

> **Exam Priority:** Priority 5 | **Unit Difficulty:** Hard (8/10)

### Q1. 4-Queens Problem using Backtracking *(Difficulty: Medium · 5/10)*
Solve the 4-Queens problem using Backtracking. Illustrate the complete state-space tree showing promising nodes, pruning of conflicts, and the final solution.
- [→ Worked Answer](unit-5.md#2-4-queens-problem-using-backtracking)

### Q2. Sum of Subsets using Backtracking *(Difficulty: Medium · 5/10)*
Explain the Sum of Subsets problem using Backtracking with a step-by-step state-space tree and bounding conditions.
- [→ Worked Answer](unit-5.md#3-sum-of-subsets-using-backtracking)

### Q3. Graph Coloring using Backtracking *(Difficulty: Medium · 5/10)*
Explain the $m$-Coloring problem for graphs using Backtracking. State the bounding condition and demonstrate finding all valid vertex colorings.
- [→ Worked Answer](unit-5.md#4-graph-coloring-using-backtracking-3-colors)

### Q4. 0/1 Knapsack using LC Branch and Bound *(Difficulty: Hard · 8/10)*
Solve the 0/1 Knapsack problem using Least-Cost Branch and Bound (LC-BB). Explain the upper bound calculation and show the search tree.
- [→ Worked Answer](unit-5.md#6-01-knapsack-using-least-cost-lc-branch-and-bound)

### Q5. Backtracking vs. Branch and Bound *(Difficulty: Easy · 3/10)*
Compare and contrast Backtracking and Branch & Bound across search strategies (DFS vs. BFS/LC), problem domains, pruning mechanisms, and queue structures.
- [→ Worked Answer](unit-5.md#8-compare-and-contrast-backtracking-and-branch-and-bound)
