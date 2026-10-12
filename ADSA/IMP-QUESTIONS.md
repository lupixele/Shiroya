# ADSA Questions

## Important Questions by Teacher (IE 2)

### Unit 3
1. [Merge Sort](UNIT-III.md#2-merge-sort)
2. [Quick Sort](UNIT-III.md#3-quick-sort)
3. [Kruskal's Algorithm](UNIT-III.md#a-kruskals-algorithm-sort-edges-by-weight-add-an-edge-if-it-does-not-form-a-cycle)
4. [Prim's Algorithm](UNIT-III.md#b-prims-algorithm-start-at-a-repeatedly-add-the-cheapest-edge-connecting-the-tree-to-a-new-vertex)
5. [Fractional Knapsack](UNIT-III.md#5-fractional-knapsack-using-greedy)
6. [Job Sequencing with Deadlines](UNIT-III.md#4-greedy-job-sequencing-with-deadlines)

### Unit 4
1. [0/1 Knapsack – Dynamic Programming (DP)](UNIT-IV.md#5-01-knapsack-using-dynamic-programming)
2. [Optimal Binary Search Tree (OBST)](UNIT-IV.md#4-optimal-binary-search-tree-obst-using-dynamic-programming)
3. [Bellman–Ford Algorithm – Single-Source Shortest Path](UNIT-IV.md#2-bellmanford-algorithm-from-source-s)
4. [Travelling Salesperson Problem (TSP)](UNIT-IV.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming)
5. [All-Pairs Shortest Path](UNIT-IV.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths)

### Unit 5
1. [4 Queens Problem — Backtracking](UNIT-V.md#2-4-queens-problem-using-backtracking)
2. [Graph Coloring — Backtracking](UNIT-V.md#4-graph-coloring-using-backtracking-3-colors)
3. [Difference Between Backtracking and Branch and Bound](UNIT-V.md#8-compare-and-contrast-backtracking-and-branch-and-bound)
4. [Sum of Subsets Problem — Backtracking](UNIT-V.md#3-sum-of-subsets-using-backtracking)
5. [0/1 Knapsack Using LC Branch and Bound (LC-BB)](UNIT-V.md#6-01-knapsack-using-least-cost-lc-branch-and-bound)
6. [Travelling Salesperson Problem Using LC Branch and Bound (LC-BB)](UNIT-V.md#7-travelling-salesperson-problem-tsp-using-branch-and-bound)

### Questions NOT Mentioned by Teacher (Optional / Excluded from IE 2)
The following questions from Units 3, 4, and 5 are in the full question bank but were **not** mentioned by the teacher for IE 2:

- **Unit 3:**
  - [Divide and Conquer Methodology & Binary Search](UNIT-III.md#1-divide-and-conquer-and-binary-search) (Question 1)
  - [Dijkstra's Algorithm from Source A](UNIT-III.md#7-dijkstras-algorithm-from-source-a) (Question 7)
- **Unit 4:**
  - [Dynamic Programming Methodology vs. Divide and Conquer](UNIT-IV.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer) (Question 1)
- **Unit 5:**
  - [Backtracking General Methodology & State-Space Tree](UNIT-V.md#1-backtracking-general-methodology-state-space-tree-bounding-conditions-and-comparison-with-exhaustive-search) (Question 1)
  - [Hamiltonian Cycles using Backtracking](UNIT-V.md#5-hamiltonian-cycles-using-backtracking) (Question 5)

*(Note: Unit 1 and Unit 2 were covered in IE 1.)*

---

## Unit 1

### 1. Importance of Algorithm Analysis and Time vs. Space Complexity
Explain the importance of algorithm analysis. Differentiate between time complexity and space complexity with suitable examples.

- [→ Answer](UNIT-I.md#1-importance-of-algorithm-analysis-and-time-vs-space-complexity)

---

### 2. Asymptotic Notations: Big-O, Omega, and Theta
Describe the asymptotic notations $O$, $\Omega$, and $\Theta$. Illustrate each notation with suitable examples.

- [→ Answer](UNIT-I.md#2-asymptotic-notations-big-o-omega-and-theta)

---

### 3. Time Complexity of Matrix Multiplication
Analyze the time complexity for matrix multiplication algorithm (tabular method) using asymptotic notation and justify your answer.

- [→ Answer](UNIT-I.md#3-time-complexity-of-matrix-multiplication-tabular-step-count-method)

---

### 4. Concept of Hashing and Hash Functions
Explain the concept of hashing. Discuss different hash functions with suitable examples.

- [→ Answer](UNIT-I.md#4-concept-of-hashing-and-hash-functions)

---

### 5. Collision Resolution Techniques
Explain the collision resolution techniques Linear Probing, Quadratic Probing, Double Hashing, and Separate Chaining.

- [→ Answer](UNIT-I.md#5-collision-resolution-techniques)

---

### 6. Static Hashing vs. Dynamic Hashing (Extendible Hashing)
Differentiate between Static Hashing and Dynamic Hashing. Explain the working of Dynamic Hashing (Extendible hashing) with an example.

- [→ Answer](UNIT-I.md#6-static-hashing-vs-dynamic-hashing-extendible-hashing)

---

## Unit 2

### 1. Construct AVL Tree
Construct an AVL Tree by inserting the following keys: `50, 25, 12, 80, 90, 37, 45, 18, 19, 6`. Show the required rotations after each step.

- [→ Answer](UNIT-II.md#1-construct-an-avl-tree-by-step-by-step-insertion)

---

### 2. Four Types of AVL Tree Rotations and Applications
Explain the four types of AVL Tree rotations with suitable examples. Discuss the applications of AVL Trees.

- [→ Answer](UNIT-II.md#2-four-types-of-avl-tree-rotations-and-applications)

---

### 3. Deletion Procedure in AVL Tree (Delete 15)
Explain the deletion procedure in AVL tree. Show the balancing operations after **deletion of 15** from the below AVL tree:

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

- [→ Answer](UNIT-II.md#3-deletion-procedure-in-avl-tree-delete-15)

---

### 4. Construct B-Tree of Order 4
Construct a B-Tree of order 4 by inserting the following keys: `5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`.

- [→ Answer](UNIT-II.md#4-construct-a-b-tree-of-order-4)

---

### 5. Deletion Operation in B-Tree and Applications
Explain the deletion operation in a B-Tree with a suitable example, and discuss practical applications of B-Trees.

- [→ Answer](UNIT-II.md#5-deletion-operation-in-a-b-tree-and-applications)

---

### 6. Construct Min Heap and Max Heap
Construct a Min Heap and Max Heap by inserting the following elements: `40, 15, 30, 10, 12, 6, 25, 18`. Show all intermediate steps.

- [→ Answer](UNIT-II.md#6-construct-a-min-heap-and-max-heap)

---

### 7. Deletion Operation on Max Heap
Perform one deletion operation on given Max Heap and show the step-by-step process for final Max Heap:

```text
               BINARY MAX HEAP

               90  <-- Root (Maximum element)
             /    \
           60      75
          /  \    /  \
        50   40  30  20
       /  \  /
     10   5 8
```

- [→ Answer](UNIT-II.md#7-deletion-operation-on-given-max-heap)

---

### 8. Binary Heap Operations and Priority Queue Applications
Explain the basic operations of a Binary Heap with their time complexities and discuss the applications of Priority Queues.

- [→ Answer](UNIT-II.md#8-basic-operations-of-a-binary-heap-and-applications-of-priority-queues)

---

## Unit 3

### 1. Divide and Conquer & Binary Search
- **A)** Explain the general methodology of the Divide and Conquer strategy. Illustrate its three fundamental steps with suitable examples.
- **B)** Apply the Binary Search algorithm to locate the desired key in the sorted array. Show the low, high, and mid values at every iteration and determine the total number of comparisons *(Consider your own example dataset with minimum 15 keys)*.

- [→ Answer](UNIT-III.md#1-divide-and-conquer-and-binary-search)

---

### 2. Merge Sort
Demonstrate the Merge Sort algorithm on the following dataset. Draw the splitting and merging stages clearly and obtain the final sorted sequence.

**Input:** `42, 17, 8, 33, 25, 61, 14, 50, 9, 37`

Explain the recurrence relation and derive the time complexity of Merge Sort.

- [→ Answer](UNIT-III.md#2-merge-sort)

---

### 3. Quick Sort
Analyze the working of Quick Sort using the following dataset. Consider the first element as the pivot in every partitioning step.

**Input:** `35, 18, 42, 7, 29, 51, 13, 24, 46`

Show the partitioning process, identify the pivot positions after each pass, and obtain the sorted array. Compare the best-case and worst-case time complexities of Quick Sort.

- [→ Answer](UNIT-III.md#3-quick-sort)

---

### 4. Greedy Job Sequencing with Deadlines
Apply the Greedy Job Sequencing algorithm to schedule the following jobs to maximize the total profit. Each job requires one unit of time.

| Job | Deadline | Profit |
| :---: | :---: | :---: |
| J1 | 2 | 100 |
| J2 | 1 | 19 |
| J3 | 2 | 27 |
| J4 | 1 | 25 |
| J5 | 3 | 15 |
| J6 | 2 | 35 |
| J7 | 3 | 40 |

Determine the selected jobs, their execution order, and the maximum achievable profit. Justify your scheduling decisions.

- [→ Answer](UNIT-III.md#4-greedy-job-sequencing-with-deadlines)

---

### 5. Fractional Knapsack
Analyze the Fractional Knapsack problem using the Greedy approach for the following dataset. The knapsack capacity is **50 units**.

| Item | Weight | Profit |
| :---: | :---: | :---: |
| I1 | 10 | 60 |
| I2 | 20 | 100 |
| I3 | 30 | 120 |
| I4 | 15 | 75 |
| I5 | 25 | 125 |

Calculate the profit-to-weight ratio of each item, determine the optimal selection, and compute the maximum profit. Explain why the Greedy strategy is applicable to this problem.

- [→ Answer](UNIT-III.md#5-fractional-knapsack-using-greedy)

---

### 6. Minimum Spanning Tree (Kruskal's and Prim's)
Construct a Minimum Spanning Tree for the following weighted undirected graph using both **Kruskal's** and **Prim's** algorithm. Show each step, identify the edges rejected due to cycle formation, and calculate the total minimum cost.

![Minimum Spanning Tree Weighted Undirected Graph](figures/unit3_q6_mst.png)

- [→ Answer — Kruskal's](UNIT-III.md#a-kruskals-algorithm-sort-edges-by-weight-add-an-edge-if-it-does-not-form-a-cycle)
- [→ Answer — Prim's](UNIT-III.md#b-prims-algorithm-start-at-a-repeatedly-add-the-cheapest-edge-connecting-the-tree-to-a-new-vertex)

---

### 7. Dijkstra's Algorithm
Evaluate the shortest paths from source vertex **A** to all other vertices using Dijkstra's algorithm for the following weighted graph. Show the distance table after every iteration and identify the shortest path to each destination.

![Dijkstra Weighted Graph](figures/unit3_q7_dijkstra.png)

Discuss the limitation of Dijkstra's algorithm when negative edge weights are present.

- [→ Answer](UNIT-III.md#7-dijkstras-algorithm-from-source-a)

---

## Unit 4

### 1. Dynamic Programming Methodology
Explain the Dynamic Programming methodology. Discuss the principles of optimal substructure and overlapping subproblems. Compare Dynamic Programming with the Divide and Conquer approach.

- [→ Answer](UNIT-IV.md#1-dynamic-programming-methodology-optimal-substructure-overlapping-subproblems-and-comparison-with-divide-and-conquer)

---

### 2. Bellman–Ford Algorithm
Apply the Bellman–Ford algorithm to find the shortest paths from source vertex **S** to all other vertices in the following directed weighted graph. Show the distance values after each iteration and verify whether the graph contains a negative-weight cycle.

![Bellman-Ford Directed Weighted Graph](figures/unit4_q2_bellman_ford.png)

- [→ Answer](UNIT-IV.md#2-bellmanford-algorithm-from-source-s)

---

### 3. Floyd–Warshall All-Pairs Shortest Paths
Compute the all-pairs shortest path distances using Floyd–Warshall algorithm for the following initial cost matrix. Show the distance matrix after considering each intermediate vertex and determine the final shortest path matrix.

$$
D^{(0)} = \begin{bmatrix} 0 & 4 & \infty & 10 \\ \infty & 0 & 3 & \infty \\ \infty & \infty & 0 & 2 \\ \infty & \infty & \infty & 0 \end{bmatrix}
$$

Explain the significance of the intermediate vertex in each iteration and derive the time complexity.

- [→ Answer](UNIT-IV.md#3-floydwarshall-algorithm-for-all-pairs-shortest-paths)

---

### 4. Optimal Binary Search Tree (OBST)
Analyze the Optimal Binary Search Tree problem for the following ordered keys and their successful and unsuccessful search probabilities. Given $n = 4$ and $\{a_1, a_2, a_3, a_4\} = \{\text{do}, \text{if}, \text{int}, \text{while}\}$, $p\{1:4\} = \{3, 3, 1, 1\}$ and $q\{0:4\} = \{2, 3, 1, 1, 1\}$.

Construct the Optimal Binary Search Tree using Dynamic Programming. Show the cost table, identify the root at each subproblem, draw the final tree, and calculate the minimum expected search cost.

- [→ Answer](UNIT-IV.md#4-optimal-binary-search-tree-obst-using-dynamic-programming)

---

### 5. 0/1 Knapsack using Dynamic Programming
Solve the 0/1 Knapsack problem using Dynamic Programming for the following dataset. The knapsack capacity is **10 units**.

| Item | Weight | Profit |
| :---: | :---: | :---: |
| I1 | 2 | 12 |
| I2 | 3 | 20 |
| I3 | 4 | 25 |
| I4 | 5 | 30 |
| I5 | 6 | 35 |

Construct the DP table, identify the selected items, and determine the maximum profit. Explain why selecting items solely by profit-to-weight ratio may not produce the optimal solution.

- [→ Answer](UNIT-IV.md#5-01-knapsack-using-dynamic-programming)

---

### 6. Travelling Salesperson Problem (TSP) using Held–Karp DP
Analyze the Travelling Salesperson Problem using Dynamic Programming for the following cost matrix. Consider city **A** as the starting and ending city.

$$
C = \begin{bmatrix} 0 & 10 & 15 & 20 \\ 10 & 0 & 35 & 25 \\ 15 & 35 & 0 & 30 \\ 20 & 25 & 30 & 0 \end{bmatrix}
$$

Determine the optimal tour and minimum travel cost using the Held–Karp approach. Show the relevant subproblem calculations and explain how overlapping subproblems are utilized.

- [→ Answer](UNIT-IV.md#6-travelling-salesperson-problem-tsp-using-heldkarp-dynamic-programming)

---

## Unit 5

### 1. Backtracking Methodology & State-Space Tree
Explain the general methodology of Backtracking. Discuss the state-space tree, and its basic terms, and the role of bounding conditions. Illustrate the Backtracking approach with a suitable example and distinguish it from the exhaustive search technique.

- [→ Answer](UNIT-V.md#1-backtracking-general-methodology-state-space-tree-bounding-conditions-and-comparison-with-exhaustive-search)

---

### 2. 4-Queens Problem
Apply the Backtracking technique to solve the 4-Queens problem. Draw the state-space tree, demonstrate the placement of queens row by row, and identify the safe and unsafe positions. Show all distinct solutions and explain how the promising function eliminates invalid configurations.

- [→ Answer](UNIT-V.md#2-4-queens-problem-using-backtracking)

---

### 3. Sum of Subsets
Use the Backtracking method to identify all subsets whose sum is equal to **30** from the following set $S = \{5, 10, 12, 13, 15, 18\}$. Draw the state-space tree, indicate the promising and non-promising nodes, and list all valid subsets. Explain the pruning conditions used to reduce the search space.

- [→ Answer](UNIT-V.md#3-sum-of-subsets-using-backtracking)

---

### 4. Graph Coloring
Analyze the complete undirected graph $K_5$ using the Backtracking algorithm and determine all valid color assignments using a maximum of **3 colors**. Draw the state-space tree and identify the number of valid colorings.

![3-Coloring Undirected Graph](figures/unit5_q4_graph_coloring.png)

- [→ Answer](UNIT-V.md#4-graph-coloring-using-backtracking-3-colors)

---

### 5. Hamiltonian Cycles
Apply the Backtracking algorithm to identify all Hamiltonian cycles in the following undirected graph. Start from vertex **A** and explain how the algorithm rejects paths that cannot form a Hamiltonian cycle.

![Hamiltonian Cycles Undirected Graph](figures/unit5_q5_hamiltonian.png)

Draw the state-space tree for the possible paths and list the distinct Hamiltonian cycles, treating reverse traversals as the same cycle.

- [→ Answer](UNIT-V.md#5-hamiltonian-cycles-using-backtracking)

---

### 6. 0/1 Knapsack (LC Branch and Bound)
Analyze the 0/1 Knapsack problem using the Least Cost search Branch and Bound technique for the following dataset. The knapsack capacity is **16 units**.

| Item | Weight | Profit |
| :---: | :---: | :---: |
| I1 | 2 | 40 |
| I2 | 5 | 30 |
| I3 | 10 | 50 |
| I4 | 5 | 10 |
| I5 | 4 | 25 |

Construct the state-space tree, calculate the upper bound and cost at each relevant node, identify the nodes pruned, and determine the optimal item selection and maximum profit.

- [→ Answer](UNIT-V.md#6-01-knapsack-using-least-cost-lc-branch-and-bound)

---

### 7. Travelling Salesperson Problem (Branch and Bound)
Analyze the Travelling Salesperson Problem using Branch and Bound for the following cost matrix. Consider city **A** as the starting city.

$$
C = \begin{bmatrix} \infty & 12 & 10 & 19 & 8 \\ 12 & \infty & 3 & 7 & 6 \\ 10 & 3 & \infty & 2 & 20 \\ 19 & 7 & 2 & \infty & 4 \\ 8 & 6 & 20 & 4 & \infty \end{bmatrix}
$$

Construct the state-space tree, calculate lower bounds for promising partial tours, eliminate non-promising branches, and determine the optimal tour and its total cost.

- [→ Answer](UNIT-V.md#7-travelling-salesperson-problem-tsp-using-branch-and-bound)

---

### 8. Backtracking vs. Branch and Bound
Compare and contrast the Backtracking and Branch and Bound methods based on problem type, tree traversal, bounding mechanism, memory requirements, and efficiency.

- [→ Answer](UNIT-V.md#8-compare-and-contrast-backtracking-and-branch-and-bound)
