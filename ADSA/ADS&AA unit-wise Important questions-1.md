# Advanced Data Structures & Algorithm Analysis (2501CS10)

## Unit-wise Important Questions

---

## UNIT-I

1. Explain the importance of algorithm analysis. Differentiate between time complexity and space complexity with suitable examples.
2. Describe the asymptotic notations $O$, $\Omega$, and $\Theta$. Illustrate each notation with suitable examples.
3. Analyze the time complexity for matrix multiplication algorithm (tabular method) using asymptotic notation and justify your answer.
4. Explain the concept of hashing. Discuss different hash functions with suitable examples.
5. Explain the collision resolution techniques Linear Probing, Quadratic Probing, Double Hashing, and Separate Chaining.
6. Differentiate between Static Hashing and Dynamic Hashing. Explain the working of Dynamic Hashing (Extendable hashing) with an example.

---

## UNIT-II

1. Construct an AVL Tree by inserting the following keys: `50, 25, 12, 80, 90, 37, 45, 18, 19, 6`. Show the required rotations.
2. Explain the four types of AVL Tree rotations with suitable examples. Discuss the applications of AVL Trees.
3. Explain the deletion procedure in AVL tree. Show the balancing operations after **deletion of 15** from the below AVL tree.

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

4. Construct a B-Tree of order 4 by inserting the following keys: `5, 3, 21, 9, 1, 13, 2, 7, 10, 12, 4, 8`.
5. Explain the deletion operation in a B-Tree with a suitable example, and applications of B-Trees.
6. Construct a Min/Max Heap by inserting the following elements: `40, 15, 30, 10, 12, 6, 25, 18`. Show all intermediate steps.
7. Perform one deletion operation on given Max Heap and show the step-by-step process for final Max Heap.

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

8. Explain the basic operations of a Binary Heap with their time complexities and discuss the applications of Priority Queues.

---

## UNIT-III

1. **A)** Explain the general methodology of the Divide and Conquer strategy. Illustrate its three fundamental steps with suitable examples.

   **B)** Apply the Binary Search algorithm to locate the desired key in the sorted array. Show the low, high, and mid values at every iteration and determine the total number of comparisons ***(Consider your own example dataset with minimum 15 keys)***.

2. Demonstrate the Merge Sort algorithm on the following dataset. Draw the splitting and merging stages clearly and obtain the final sorted sequence.

   **Input:** `42, 17, 8, 33, 25, 61, 14, 50, 9, 37`

   Explain the recurrence relation and derive the time complexity of Merge Sort.

3. Analyze the working of Quick Sort using the following dataset. Consider the first element as the pivot in every partitioning step.

   **Input:** `35, 18, 42, 7, 29, 51, 13, 24, 46`

   Show the partitioning process, identify the pivot positions after each pass, and obtain the sorted array. Compare the best-case and worst-case time complexities of Quick Sort.

4. Apply the Greedy Job Sequencing algorithm to schedule the following jobs to maximize the total profit. Each job requires one unit of time.

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

5. Analyze the Fractional Knapsack problem using the Greedy approach for the following dataset. The knapsack capacity is 50 units.

   | Item | Weight | Profit |
   | :---: | :---: | :---: |
   | I1 | 10 | 60 |
   | I2 | 20 | 100 |
   | I3 | 30 | 120 |
   | I4 | 15 | 75 |
   | I5 | 25 | 125 |

   Calculate the profit-to-weight ratio of each item, determine the optimal selection, and compute the maximum profit. Explain why the Greedy strategy is applicable to this problem.

6. Construct a Minimum Spanning Tree for the following weighted undirected graph using both Kruskal's and Prim's algorithm. Show each step, identify the edges rejected due to cycle formation, and calculate the total minimum cost.

   ![Minimum Spanning Tree Weighted Undirected Graph](figures/unit3_q6_mst.png)

7. Evaluate the shortest paths from source vertex **A** to all other vertices using Dijkstra's algorithm for the following weighted graph. Show the distance table after every iteration and identify the shortest path to each destination.

   ![Dijkstra Weighted Graph](figures/unit3_q7_dijkstra.png)

   Discuss the limitation of Dijkstra's algorithm when negative edge weights are present.

---

## UNIT-IV

1. Explain the general methodology of Dynamic Programming. Discuss the principles of optimal substructure and overlapping subproblems with suitable examples. Differentiate between Dynamic Programming and Divide and Conquer based on their problem-solving strategies, storage requirements, and computational efficiency.

2. Apply the Bellman–Ford algorithm to find the shortest paths from source vertex **S** to all other vertices in the following directed weighted graph. Show the distance values after each iteration and verify whether the graph contains a negative-weight cycle.

   ![Bellman-Ford Directed Weighted Graph](figures/unit4_q2_bellman_ford.png)

3. Compute the all-pairs shortest path distances using the Floyd–Warshall's algorithm for the following initial cost matrix. Show the distance matrix after considering each intermediate vertex and determine the final shortest path matrix.

   $$D^{(0)} = \begin{bmatrix} 0 & 4 & \infty & 10 \\ \infty & 0 & 3 & \infty \\ \infty & \infty & 0 & 2 \\ \infty & \infty & \infty & 0 \end{bmatrix}$$

   Also, explain the significance of the intermediate vertex in each iteration and derive the time complexity.

4. Analyze the Optimal Binary Search Tree problem for the following ordered keys and their successful and unsuccessful search probabilities. Given $n = 4$ and $\{a_1, a_2, a_3, a_4\} = \{\text{do}, \text{if}, \text{int}, \text{while}\}$, $p\{1:4\} = \{3, 3, 1, 1\}$ and $q\{0:4\} = \{2, 3, 1, 1, 1\}$. Construct the Optimal Binary Search Tree using Dynamic Programming. Show the cost table, identify the root at each subproblem, draw the final tree, and calculate the minimum expected search cost.

5. Solve the 0/1 Knapsack problem using Dynamic Programming for the following dataset. The knapsack capacity is 10 units.

   | Item | Weight | Profit |
   | :---: | :---: | :---: |
   | I1 | 2 | 12 |
   | I2 | 3 | 20 |
   | I3 | 4 | 25 |
   | I4 | 5 | 30 |
   | I5 | 6 | 35 |

   Construct the DP table, identify the selected items, and determine the maximum profit. Explain why selecting items solely by profit-to-weight ratio may not produce the optimal solution.

6. Analyze the Travelling Salesperson Problem using Dynamic Programming for the following cost matrix. Consider city A as the starting and ending city.

   $$C = \begin{bmatrix} 0 & 10 & 15 & 20 \\ 10 & 0 & 35 & 25 \\ 15 & 35 & 0 & 30 \\ 20 & 25 & 30 & 0 \end{bmatrix}$$

   Determine the optimal tour and minimum travel cost using the Held–Karp approach. Show the relevant subproblem calculations and explain how overlapping subproblems are utilized.

---

## UNIT-V

1. Explain the general methodology of Backtracking. Discuss the state-space tree, and its basic terms, and the role of bounding conditions. Illustrate the Backtracking approach with a suitable example and distinguish it from the exhaustive search technique.

2. Apply the Backtracking technique to solve the 4-Queens problem. Draw the state-space tree, demonstrate the placement of queens' row by row, and identify the safe and unsafe positions. Show all distinct solutions and explain how the promising function eliminates invalid configurations.

3. Use the Backtracking method to identify all subsets whose sum is equal to 30 from the following set $S = \{5 \mid 10 \mid 12 \mid 13 \mid 15 \mid 18\}$. Draw the state-space tree, indicate the promising and non-promising nodes, and list all valid subsets. Explain the pruning conditions used to reduce the search space.

4. Analyze the following undirected graph using the Backtracking algorithm and determine all valid color assignments using a maximum of 3 colors. Draw the state-space tree and identify the number of valid colorings.

   ![3-Coloring Undirected Graph](figures/unit5_q4_graph_coloring.png)

5. Apply the Backtracking algorithm to identify all Hamiltonian cycles in the following undirected graph. Start from vertex A and explain how the algorithm rejects paths that cannot form a Hamiltonian cycle.

   ![Hamiltonian Cycles Undirected Graph](figures/unit5_q5_hamiltonian.png)

   Draw the state-space tree for the possible paths and list the distinct Hamiltonian cycles, treating reverse traversals as the same cycle.

6. Analyze the 0/1 Knapsack problem using the Least Cost search Branch and Bound technique for the following dataset. The knapsack capacity is 16 units.

   | Item | Weight | Profit |
   | :---: | :---: | :---: |
   | I1 | 2 | 40 |
   | I2 | 5 | 30 |
   | I3 | 10 | 50 |
   | I4 | 5 | 10 |
   | I5 | 4 | 25 |

   Construct the state-space tree, calculate the upper bound and cost at each relevant node, identify the nodes pruned, and determine the optimal item selection and maximum profit.

7. Analyze the Travelling Salesperson Problem using Branch and Bound for the following cost matrix. Consider city **A** as the starting city.

   $$C = \begin{bmatrix} \infty & 12 & 10 & 19 & 8 \\ 12 & \infty & 3 & 7 & 6 \\ 10 & 3 & \infty & 2 & 20 \\ 19 & 7 & 2 & \infty & 4 \\ 8 & 6 & 20 & 4 & \infty \end{bmatrix}$$

   Construct the state-space tree, calculate lower bounds for promising partial tours, eliminate non-promising branches, and determine the optimal tour and its total cost.

8. Compare and contrast the Backtracking and Branch and Bound methods.
