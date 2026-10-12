## UNIT III

## 1. Divide and Conquer and Binary Search

### 1(A) Explain the general methodology of Divide and Conquer. Illustrate its three fundamental steps with examples. (8 marks)

**Definition:** Divide and Conquer is an algorithm-design technique that breaks a problem into smaller subproblems, solves them recursively, and combines their results to obtain the solution to the original problem.

**Three fundamental steps**

1. **Divide:** Split the original problem into smaller subproblems of the same or a related type.
2. **Conquer:** Solve each subproblem recursively. If a subproblem is small enough, solve it directly as a base case.
3. **Combine:** Combine the subproblem solutions to produce the final answer.

**Example — Merge Sort**

For the array `38, 27, 43, 3`:

- Divide: split into `[38, 27]` and `[43, 3]`.
- Conquer: sort the halves into `[27, 38]` and `[3, 43]`.
- Combine: merge the sorted halves to obtain `[3, 27, 38, 43]`.

**Example — Binary Search**

For a sorted array, compare the key with the middle element. If the key is smaller, continue in the left half; if larger, continue in the right half. Repeating this process halves the search interval each time.

**General recurrence:** A divide-and-conquer algorithm is often described by

\[
T(n)=aT(n/b)+f(n)
\]

where `a` is the number of subproblems, `n/b` is the approximate size of each subproblem, and `f(n)` is the work required to divide and combine.

**Advantages**
- Breaks a large problem into manageable parts.
- Often reduces time complexity.
- Supports recursive and modular implementations.

**Examples:** Binary Search, Merge Sort, Quick Sort, and Strassen’s matrix multiplication.

**Conclusion:** Divide and Conquer follows Divide, Conquer, and Combine. Its efficiency depends on the number, size, and combination cost of the subproblems.

### 1(B) Apply Binary Search to locate a key in a sorted array of at least 15 keys. Show low, high, and mid at every iteration and count comparisons. (8 marks)

**Example sorted array (15 keys):**

`5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75`

Search key: `60`. Use 1-based indexing.

**Algorithm**

```text
BINARY-SEARCH(A, key)
1. low = 1, high = length(A)
2. While low <= high:
       mid = floor((low + high) / 2)
       If A[mid] == key: return mid
       If key < A[mid]: high = mid - 1
       Else: low = mid + 1
3. Return NOT FOUND
```

**Iterations**

| Iteration | Low | High | Mid | A[mid] | Decision |
|---:|---:|---:|---:|---:|---|
| 1 | 1 | 15 | 8 | 40 | 60 > 40; low = 9 |
| 2 | 9 | 15 | 12 | 60 | Key found |

The key `60` is found at position **12**.

**Number of comparisons:** Two key-to-middle-element comparisons are made: `60` vs `40`, then `60` vs `60`. Therefore, the search takes **2 element comparisons** in this example. If loop-bound checks are counted, that is a different counting convention.

**Complexity**
- Best case: `O(1)` when the middle element is the key.
- Average and worst case: `O(log n)`.
- Iterative auxiliary space: `O(1)`.

**Conclusion:** Binary Search works on sorted arrays and halves the remaining search interval after each unsuccessful comparison.

---

## 2. Merge Sort

**Question:** Demonstrate Merge Sort on `42, 17, 8, 33, 25, 61, 14, 50, 9, 37`. Show splitting and merging stages, final sorted sequence, recurrence, and time complexity. (8 marks)

### Definition

Merge Sort is a stable Divide-and-Conquer sorting algorithm. It divides the array into halves, recursively sorts each half, and merges the sorted halves.

### Splitting stages

```text
[42, 17, 8, 33, 25, 61, 14, 50, 9, 37]
                 /                         \
[42, 17, 8, 33, 25]                 [61, 14, 50, 9, 37]
       /          \                       /          \
[42, 17]       [8, 33, 25]           [61, 14]       [50, 9, 37]
 /    \          /     \              /    \          /      \
[42] [17]      [8]   [33, 25]       [61] [14]       [50]   [9, 37]
                         / \                                  / \
                       [33][25]                             [9][37]
```

### Merging stages

1. `[42] + [17] → [17, 42]`
2. `[33] + [25] → [25, 33]`
3. `[8] + [25, 33] → [8, 25, 33]`
4. `[17, 42] + [8, 25, 33] → [8, 17, 25, 33, 42]`
5. `[61] + [14] → [14, 61]`
6. `[9] + [37] → [9, 37]`
7. `[50] + [9, 37] → [9, 37, 50]`
8. `[14, 61] + [9, 37, 50] → [9, 14, 37, 50, 61]`
9. Merge the two five-element sorted halves:

```text
[8, 17, 25, 33, 42] + [9, 14, 37, 50, 61]
→ [8, 9, 14, 17, 25, 33, 37, 42, 50, 61]
```

### Merge Sort algorithm

```text
MERGE-SORT(A)
1. If A has zero or one element, return A.
2. Divide A into left and right halves.
3. Recursively sort each half.
4. Merge the two sorted halves.
```

### Recurrence and complexity

Each call sorts two halves and merging requires linear time:

\[
T(n)=2T(n/2)+cn
\]

At each level, the total merge work is `cn`. There are approximately `log₂ n` levels, so:

\[
T(n)=cn\log_2 n+O(n)=O(n\log n)
\]

Best, average, and worst-case time complexity are all **`O(n log n)`**. Auxiliary space is **`O(n)`** for the standard array-based implementation.

**Final sorted sequence:**

`8, 9, 14, 17, 25, 33, 37, 42, 50, 61`

---

## 3. Quick Sort

**Question:** Sort `35, 18, 42, 7, 29, 51, 13, 24, 46` using Quick Sort, choosing the first element as pivot in every partition. Show partitions and pivot positions, then compare best- and worst-case complexities. (8 marks)

### Definition

Quick Sort selects a pivot and partitions the array so that smaller elements appear to its left and larger elements to its right. It recursively sorts the resulting subarrays.

**Partition convention:** This worked trace uses a partition method that places the pivot in its final sorted position. Different valid partition implementations can show different intermediate arrangements, but the final sorted array is the same.

### Partitioning trace

Initial array:

`35, 18, 42, 7, 29, 51, 13, 24, 46`

1. **Pivot 35:** smaller elements are `18, 7, 29, 13, 24`; larger elements are `42, 51, 46`. Conceptually:
   `18, 7, 29, 13, 24 | 35 | 42, 51, 46`
   Pivot 35 finishes at position **6**.

2. **Left subarray; pivot 18:**
   `7, 13 | 18 | 29, 24`
   Pivot 18 finishes at position **3**.

3. **Subarray `[7, 13]`; pivot 7:**
   `7 | 13`
   Pivot 7 finishes at position **1**.

4. **Subarray `[29, 24]`; pivot 29:**
   `24 | 29`
   Pivot 29 finishes at position **5**.

5. **Right subarray `[42, 51, 46]`; pivot 42:**
   `42 | 51, 46`
   Pivot 42 finishes at position **7**.

6. **Subarray `[51, 46]`; pivot 51:**
   `46 | 51`
   Pivot 51 finishes at position **9**.

Pivot positions above use 1-based indexing. The final positions are 1 for 7, 3 for 18, 5 for 29, 6 for 35, 7 for 42, and 9 for 51; the remaining values fill the other positions.

### Final sorted array

`7, 13, 18, 24, 29, 35, 42, 46, 51`

### Pseudocode

```text
QUICKSORT(A, low, high)
1. If low < high:
2.     p = PARTITION(A, low, high)
3.     QUICKSORT(A, low, p - 1)
4.     QUICKSORT(A, p + 1, high)
```

### Time complexity

**Best case:** Each pivot divides the array into approximately equal halves.

\[
T(n)=2T(n/2)+cn=O(n\log n)
\]

**Worst case:** Each pivot creates one subarray of size `n − 1` and one empty subarray.

\[
T(n)=T(n-1)+cn=O(n^2)
\]

| Case | Time complexity |
|---|---|
| Best | `O(n log n)` |
| Average | `O(n log n)` |
| Worst | `O(n²)` |

Quick Sort usually uses `O(log n)` auxiliary stack space on balanced partitions; its worst-case recursion stack can be `O(n)`.

**Conclusion:** Quick Sort sorts the input into ascending order. Its performance depends on the balance of the partitions.

---

## 4. Greedy Job Sequencing with Deadlines

**Question:** Schedule jobs to maximize profit when each job takes one unit of time. Show selected jobs, execution order, and maximum profit. (8 marks)

**Worked example:** The question text did not include a job table, so the following explicit example is used.

| Job | Deadline | Profit |
|---|---:|---:|
| J1 | 2 | 100 |
| J2 | 1 | 19 |
| J3 | 2 | 27 |
| J4 | 1 | 25 |
| J5 | 3 | 15 |
| J6 | 2 | 35 |
| J7 | 3 | 40 |

### Definition and method

Job Sequencing with Deadlines is a Greedy optimization problem. Each job requires one time slot and earns its profit only if completed by its deadline.

1. Sort jobs by descending profit.
2. Create slots from time 1 to the maximum deadline.
3. For each job in profit order, place it in the latest free slot at or before its deadline.
4. Reject it if no such slot is available.

### Jobs in descending profit order

`J1(100), J7(40), J6(35), J3(27), J4(25), J2(19), J5(15)`

### Scheduling decisions

| Job considered | Deadline | Decision | Reason |
|---|---:|---|---|
| J1 | 2 | Schedule in slot 2 | Slot 2 is free |
| J7 | 3 | Schedule in slot 3 | Slot 3 is free |
| J6 | 2 | Schedule in slot 1 | Slots 2 is occupied; slot 1 is free |
| J3 | 2 | Reject | Slots 1 and 2 are occupied |
| J4 | 1 | Reject | Slot 1 is occupied |
| J2 | 1 | Reject | Slot 1 is occupied |
| J5 | 3 | Reject | All slots are occupied |

### Final schedule and profit

| Time slot | Job | Profit |
|---:|---|---:|
| 1 | J6 | 35 |
| 2 | J1 | 100 |
| 3 | J7 | 40 |
| **Total** | | **175** |

\[
\text{Maximum profit}=35+100+40=\boxed{175}
\]

Choosing the latest free slot preserves earlier slots for jobs with tighter deadlines. For the standard unit-time job sequencing problem, this Greedy strategy yields an optimal schedule.

**Conclusion:** The selected execution order is J6, J1, J7, giving total profit **175**.

---

## 5. Fractional Knapsack using Greedy

**Question:** For capacity 50, calculate each item's profit-to-weight ratio, select items, and calculate maximum profit. Explain why Greedy works. (8 marks)

**Worked example:** No item table was visible in the question text, so this explicit example is used.

| Item | Weight | Profit |
|---|---:|---:|
| I1 | 10 | 60 |
| I2 | 20 | 100 |
| I3 | 30 | 120 |
| I4 | 15 | 75 |
| I5 | 25 | 125 |

Capacity: `W = 50`.

### Step 1: Calculate ratios

\[
r_i=\frac{\text{profit}_i}{\text{weight}_i}
\]

| Item | Weight | Profit | Profit/weight |
|---|---:|---:|---:|
| I1 | 10 | 60 | 6 |
| I2 | 20 | 100 | 5 |
| I3 | 30 | 120 | 4 |
| I4 | 15 | 75 | 5 |
| I5 | 25 | 125 | 5 |

Select I1 first. I2, I4, and I5 have equal ratios, so any order among them is valid after I1.

### Step 2: Fill the knapsack

1. Take all of I1: weight 10, profit 60; remaining capacity 40.
2. Take all of I2: weight 20, profit 100; remaining capacity 20.
3. Take all of I4: weight 15, profit 75; remaining capacity 5.
4. Take 5 units of I5, which is `5/25 = 1/5` of the item.

Fractional profit from I5:

\[
125\times\frac{5}{25}=25
\]

### Final selection

| Item | Fraction taken | Weight used | Profit |
|---|---:|---:|---:|
| I1 | 100% | 10 | 60 |
| I2 | 100% | 20 | 100 |
| I4 | 100% | 15 | 75 |
| I5 | 20% | 5 | 25 |
| I3 | 0% | 0 | 0 |
| **Total** | | **50** | **260** |

\[
\boxed{\text{Maximum profit}=60+100+75+25=260}
\]

### Why Greedy is applicable

- The ratio indicates profit earned per unit of weight.
- Taking the highest ratio first maximizes profit for the capacity used at each step.
- Fractional selection lets the algorithm fill the remaining capacity exactly.
- For the fractional knapsack problem, sorting by profit-to-weight ratio produces an optimal solution.

**Complexity:** Sorting takes `O(n log n)`; selecting items afterward takes `O(n)`.

**Conclusion:** The capacity is fully used and the maximum profit is **260**.

---

## 6. Minimum Spanning Tree using Kruskal’s and Prim’s algorithms

**Question:** Construct an MST for the given weighted undirected graph using both algorithms. Show selected and rejected edges and total cost. (8 marks)

**Important:** The graph image was unavailable in the text available here. The following solution uses the explicit edge list previously used in this conversation; verify that it matches the original diagram.

### Worked graph

Vertices: `A, B, C, D, E, F`

| Edge | Weight |
|---|---:|
| F–D | 1 |
| D–E | 2 |
| B–C | 3 |
| A–B | 4 |
| F–E | 5 |
| C–D | 6 |
| A–F | 7 |
| A–E | 8 |
| B–F | 9 |
| B–E | 10 |
| B–D | 11 |

A spanning tree with six vertices must contain `V − 1 = 5` edges.

### A. Kruskal’s algorithm

**Method:** Sort all edges by increasing weight. Select the next smallest edge if it does not create a cycle; otherwise reject it. Stop when five edges have been selected.

| Step | Edge | Weight | Decision | Reason |
|---:|---|---:|---|---|
| 1 | F–D | 1 | Select | No cycle |
| 2 | D–E | 2 | Select | No cycle |
| 3 | B–C | 3 | Select | No cycle |
| 4 | A–B | 4 | Select | No cycle |
| 5 | F–E | 5 | Reject | Creates cycle F–D–E–F |
| 6 | C–D | 6 | Select | Connects the two components |

Five edges have now been selected, so the MST is complete. The remaining edges need not be examined.

Selected edges: `FD, DE, BC, AB, CD`.

\[
\text{MST cost}=1+2+3+4+6=\boxed{16}
\]

### B. Prim’s algorithm

**Method:** Start at A. Repeatedly select the minimum-weight edge connecting a vertex already in the tree to a vertex outside it.

| Step | Selected edge | Weight | Vertices now in tree |
|---:|---|---:|---|
| 1 | A–B | 4 | A, B |
| 2 | B–C | 3 | A, B, C |
| 3 | C–D | 6 | A, B, C, D |
| 4 | D–F | 1 | A, B, C, D, F |
| 5 | D–E | 2 | A, B, C, D, E, F |

\[
\text{MST cost}=4+3+6+1+2=\boxed{16}
\]

### Comparison

| Kruskal | Prim |
|---|---|
| Chooses the smallest available edge in the whole graph. | Chooses the smallest edge leaving the current tree. |
| Builds a forest and joins components. | Grows one connected tree from a starting vertex. |
| Cycle checking is essential. | Adds only a new, unvisited vertex. |

**Conclusion:** Both algorithms produce a minimum spanning tree of cost **16** for the worked edge list.

---

## 7. Dijkstra’s algorithm from source A

**Question:** Find shortest paths from A to every other vertex. Show the distance table after each iteration and explain the limitation with negative edges. (8 marks)

**Important:** The graph image was unavailable in the text available here. This solution uses the explicit graph previously used in this conversation; verify the edge list against the original diagram.

### Edge list

| Edge | Weight |
|---|---:|
| A–B | 4 |
| A–F | 7 |
| B–F | 8 |
| B–C | 3 |
| B–E | 10 |
| C–D | 6 |
| F–D | 3 |
| F–E | 5 |
| E–D | 2 |

Source: A. All weights are non-negative.

### Definition and initialization

Dijkstra’s algorithm is a Greedy single-source shortest-path algorithm for graphs with non-negative edge weights.

Initialize `d(A) = 0` and all other distances to infinity.

| Stage | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| Initial | 0 | ∞ | ∞ | ∞ | ∞ | ∞ |

### Iteration 1: Visit A

Update B = `0 + 4 = 4` and F = `0 + 7 = 7`.

| After visiting | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| A | 0 | 4 | ∞ | ∞ | ∞ | 7 |

### Iteration 2: Visit B

Update C = `4 + 3 = 7`; E = `4 + 10 = 14`. The route to F through B costs 12, so the existing distance 7 remains.

| After visiting | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| B | 0 | 4 | 7 | ∞ | 14 | 7 |

C and F tie at distance 7; either can be processed first.

### Iteration 3: Visit C

Update D = `7 + 6 = 13`.

| After visiting | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| C | 0 | 4 | 7 | 13 | 14 | 7 |

### Iteration 4: Visit F

Improve D to `7 + 3 = 10` and E to `7 + 5 = 12`.

| After visiting | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| F | 0 | 4 | 7 | 10 | 12 | 7 |

### Iteration 5: Visit D

The route to E through D costs `10 + 2 = 12`, equal to its current distance, so no improvement occurs.

| After visiting | A | B | C | D | E | F |
|---|---:|---:|---:|---:|---:|---:|
| D | 0 | 4 | 7 | 10 | 12 | 7 |

### Iteration 6: Visit E

No distance improves.

### Final distances and paths

| Destination | Distance from A | Shortest path |
|---|---:|---|
| A | 0 | A |
| B | 4 | A → B |
| C | 7 | A → B → C |
| D | 10 | A → F → D |
| E | 12 | A → F → E |
| F | 7 | A → F |

E also has an equal-cost path `A → F → D → E`, with cost `7 + 3 + 2 = 12`.

### Algorithm

```text
DIJKSTRA(G, source)
1. Set source distance to 0 and all others to infinity.
2. Mark all vertices unvisited.
3. Select the unvisited vertex u with minimum distance.
4. For each unvisited neighbor v:
       candidate = distance[u] + weight(u, v)
       If candidate < distance[v]:
           distance[v] = candidate
           predecessor[v] = u
5. Mark u visited.
6. Repeat until all reachable vertices are visited.
```

### Negative-edge limitation

Dijkstra’s algorithm finalizes the closest unvisited vertex on the assumption that no later path can make its distance smaller. A negative edge can violate that assumption and cause incorrect results. Bellman–Ford supports negative edge weights and can detect reachable negative-weight cycles.

### Complexity

- Adjacency matrix with linear minimum search: `O(V²)`.
- Adjacency list with a binary min-heap: `O((V + E) log V)`.

**Conclusion:** The final distances from A are `0, 4, 7, 10, 12, 7` for A, B, C, D, E, F.

---
