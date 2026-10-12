# UNIT I

## 1. Importance of Algorithm Analysis and Time vs. Space Complexity

**Question:** Explain the importance of algorithm analysis. Differentiate between time complexity and space complexity with suitable examples. (8 marks)

### Definition

- **Algorithm:** A step-by-step finite, unambiguous, and effective sequence of instructions designed to solve a problem or perform a specific computation.
- **Algorithm Analysis:** The theoretical evaluation of an algorithm's efficiency in terms of the computing resources (execution time and memory space) it requires as a function of the input size $n$.

---

### Importance of Algorithm Analysis

1. **Performance Prediction:** Determines how an algorithm scales as input size $n$ grows without running it on every possible hardware configuration or dataset.
2. **Resource Optimization:** Helps balance CPU execution time and RAM consumption.
3. **Comparative Evaluation:** Provides a machine-independent yardstick to choose the best algorithm among multiple correct solutions.
4. **Scalability Assurance:** Guarantees that software remains responsive when handling large inputs (e.g., millions of records).
5. **Cost-Effectiveness:** Reduces hardware requirements, cloud compute costs, and energy consumption.

---

### 1. Time Complexity

**Definition:** Time complexity measures how fast an algorithm runs by counting the number of elementary operations executed as a function of input size $n$ (assuming $1\text{ statement/operation} = 1\text{ unit of time}$).

#### Example — Simple Loop

```c
for (int i = 0; i < n; i++) {
    sum += i;
}
```

| Step / Statement | Execution Count | Cost |
|---|---:|---:|
| Initialization (`int i = 0`) | $1$ | $1$ |
| Condition check (`i < n`) | $n + 1$ | $n + 1$ |
| Increment (`i++`) | $n$ | $n$ |
| Loop body (`sum += i`) | $n$ | $n$ |
| **Total Time $T(n)$** | | **$3n + 2 = O(n)$** |

---

### 2. Space Complexity

**Definition:** Space complexity measures the total memory required by an algorithm during execution (including input data, fixed variables, dynamic allocations, and the recursion call stack) as a function of input size $n$:

$$\text{Space Complexity } S(n) = \text{Fixed Part } (c) + \text{Variable Part } (S_p(n))$$

- **Fixed Part:** Constants, simple variables, and program instructions (independent of $n$).
- **Variable Part:** Dynamically sized arrays, linked structures, and recursion stack frames that depend on $n$.

#### Examples

1. **Scalar Variables (`O(1)` Space):**
   ```c
   int a = 5, b = 10; // 2 units of space -> O(1)
   ```
2. **Fixed-Size Array (`O(1)` Space):**
   ```c
   int arr[100]; // 100 units of space (constant) -> O(1)
   ```
3. **Variable-Size Array (`O(n)` Space):**
   ```c
   int arr[n]; // n units of space -> O(n)
   ```

---

### Differentiation: Time Complexity vs. Space Complexity

| Aspect | Time Complexity | Space Complexity |
|---|---|---|
| **Definition** | Measures the number of computational steps relative to input size $n$. | Measures the memory space required during execution relative to input size $n$. |
| **Resource Measured** | CPU time / elementary operations. | Main memory (RAM: variables, heap, recursion stack). |
| **Common Growth Rates** | $O(1), O(\log n), O(n), O(n \log n), O(n^2), O(2^n)$ | $O(1), O(\log n), O(n), O(n^2)$ |
| **Example 1: Linear Search** | $O(n)$ time (checks up to $n$ elements). | $O(1)$ auxiliary space (only loop index variable). |
| **Example 2: Iterative Binary Search** | $O(\log n)$ time (halves search space each step). | $O(1)$ auxiliary space. |
| **Example 3: Recursive Factorial** | $O(n)$ time ($n$ recursive calls). | $O(n)$ space ($n$ activation records on call stack). |
| **Example 4: $n \times n$ Matrix Allocation** | $O(n^2)$ time to initialize all cells. | $O(n^2)$ space to store $n^2$ elements. |

**Conclusion:** Algorithm analysis enables informed trade-offs between time and space so that programs run fast while staying within memory constraints.

---

## 2. Asymptotic Notations (Big-O, Omega, and Theta)

**Question:** Describe the asymptotic notations $O$, $\Omega$, and $\Theta$. Illustrate each notation with suitable examples. (8 marks)

### Definition

Asymptotic notations are mathematical tools used to describe the limiting behavior (growth rate) of an algorithm's time or space complexity as the input size $n \to \infty$, abstracting away machine-dependent constants and lower-order terms.

---

### 1. Big-Oh Notation ($O$) — Asymptotic Upper Bound

**Definition:** Big-Oh provides an **upper bound** on the growth rate of a function $f(n)$. It represents the worst-case or maximum resource consumption of an algorithm.

A function $f(n)$ is said to be in $O(g(n))$ if there exist positive constants $c > 0$ and $n_0 \ge 1$ such that:

$$0 \le f(n) \le c \cdot g(n) \quad \forall\, n \ge n_0$$

```text
Cost ^          c * g(n)  (Upper Bound)
     |             /
     |            /   f(n)
     |           /   /
     |          /---/
     |         /|
     +--------+-------------> n
             n0
```

#### Worked Example

Prove that $f(n) = 3n + 2 = O(n)$.

- Here $g(n) = n$. We need $c > 0$ and $n_0 \ge 1$ such that $3n + 2 \le c \cdot n$ for all $n \ge n_0$.
- For $n \ge 2$, $2 \le n$, so:
  $$3n + 2 \le 3n + n = 4n$$
- Choose $c = 4$ and $n_0 = 2$.
- For all $n \ge 2$, $3n + 2 \le 4n$ holds. Therefore, **$f(n) = O(n)$**.

---

### 2. Big-Omega Notation ($\Omega$) — Asymptotic Lower Bound

**Definition:** Big-Omega provides a **lower bound** on the growth rate of a function $f(n)$. It represents the best-case or minimum resource consumption of an algorithm.

A function $f(n)$ is said to be in $\Omega(g(n))$ if there exist positive constants $c > 0$ and $n_0 \ge 1$ such that:

$$0 \le c \cdot g(n) \le f(n) \quad \forall\, n \ge n_0$$

```text
Cost ^            f(n)
     |             /
     |            /   c * g(n) (Lower Bound)
     |           /   /
     |          /---/
     |         /|
     +--------+-------------> n
             n0
```

#### Worked Example

Prove that $f(n) = 5n^2 + 10 = \Omega(n^2)$.

- Here $g(n) = n^2$. Since $10 > 0$ for all $n \ge 1$:
  $$5n^2 \le 5n^2 + 10$$
- Choose $c = 5$ and $n_0 = 1$.
- For all $n \ge 1$, $5n^2 \le f(n)$ holds. Therefore, **$f(n) = \Omega(n^2)$**.

---

### 3. Big-Theta Notation ($\Theta$) — Asymptotically Tight Bound

**Definition:** Big-Theta provides both an upper and a lower bound (a **tight bound**) on the growth rate of $f(n)$.

A function $f(n)$ is said to be in $\Theta(g(n))$ if there exist positive constants $c_1, c_2 > 0$ and $n_0 \ge 1$ such that:

$$0 \le c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \forall\, n \ge n_0$$

```text
Cost ^        c2 * g(n) (Upper)
     |           /
     |          /   f(n)
     |         /   /
     |        /   /   c1 * g(n) (Lower)
     |       /|  /
     +------+------------- > n
           n0
```

#### Worked Example

Prove that $f(n) = 4n - 3 = \Theta(n)$.

- We need $c_1 n \le 4n - 3 \le c_2 n$ for all $n \ge n_0$.
- **Upper bound:** Since $-3 < 0$, $4n - 3 \le 4n$ for all $n \ge 1$ ($c_2 = 4$).
- **Lower bound:** For $n \ge 1$, $4n - 3 \ge 4n - 3n = 1n$ ($c_1 = 1$).
- Choose $c_1 = 1$, $c_2 = 4$, and $n_0 = 1$.
- Then $1n \le 4n - 3 \le 4n$ for all $n \ge 1$. Therefore, **$f(n) = \Theta(n)$**.

---

### Summary Table

| Notation | Bound Type | Mathematical Condition ($\forall n \ge n_0$) | Typical Meaning |
| :---: |---|---|---|
| $O(g(n))$ | Upper bound | $f(n) \le c \cdot g(n)$ | Growth is at most as fast as $g(n)$ |
| $\Omega(g(n))$ | Lower bound | $f(n) \ge c \cdot g(n)$ | Growth is at least as fast as $g(n)$ |
| $\Theta(g(n))$ | Tight bound | $c_1 g(n) \le f(n) \le c_2 g(n)$ | Growth is proportional to $g(n)$ |

---

## 3. Time Complexity of Matrix Multiplication (Tabular / Step-Count Method)

**Question:** Analyze the time complexity for matrix multiplication algorithm (tabular method) using asymptotic notation and justify your answer. (8 marks)

### Problem Description

Given two $n \times n$ square matrices $A$ and $B$, the standard matrix multiplication algorithm computes the product matrix $C = A \times B$ of size $n \times n$, where each entry is given by:

$$C[i][j] = \sum_{k=1}^{n} A[i][k] \times B[k][j]$$

### Algorithm / Pseudocode

```text
MATRIX-MULTIPLY(A, B, C, n)
1. for i = 1 to n:
2.     for j = 1 to n:
3.         C[i][j] = 0
4.         for k = 1 to n:
5.             C[i][j] = C[i][j] + (A[i][k] * B[k][j])
```

---

### Tabular Step-Count Analysis

We count the execution frequency and unit cost of each statement:

| Statement | Frequency | Cost per Execution | Total Steps |
|---|---:|---:|---:|
| Outer loop initialization (`i = 1`) | $1$ | $1$ | $1$ |
| Outer loop condition (`i <= n`) | $n + 1$ | $1$ | $n + 1$ |
| Middle loop initialization (`j = 1`) | $n$ | $1$ | $n$ |
| Middle loop condition (`j <= n`) | $n(n + 1)$ | $1$ | $n(n + 1)$ |
| Assignment (`C[i][j] = 0`) | $n^2$ | $1$ | $n^2$ |
| Inner loop initialization (`k = 1`) | $n^2$ | $1$ | $n^2$ |
| Inner loop condition (`k <= n`) | $n^2(n + 1)$ | $1$ | $n^2(n + 1)$ |
| Multiplication & addition (`C[i][j] += A[i][k]*B[k][j]`) | $n^3$ | $1$ | $n^3$ |

*(Note: Grouping loop initializations and condition checks as in the standard tabular method:)*

$$T(n) = 1 + (n + 1) + n + n(n + 1) + n^2 + n^2(n + 1) + n^3$$

Expanding and grouping terms by powers of $n$:

$$T(n) = 2n^3 + 3n^2 + 3n + 2 \quad \text{(or } n^3 + 3n^2 + 4n + 2\text{ depending on statement grouping)}$$

---

### Asymptotic Justification

1. **Dominant Term:** Among $n^3$, $n^2$, $n$, and $1$, the highest-order term is **$n^3$**.
2. **Upper & Lower Bounds:** For all $n \ge 1$:
   $$1 \cdot n^3 \le T(n) \le 10 \cdot n^3$$
3. Ignoring constant coefficients and lower-order terms ($n^2, n, 1$), the tight asymptotic time complexity is:

$$\boxed{T(n) = \Theta(n^3)}$$

**Conclusion:** Standard matrix multiplication uses three nested loops from $1$ to $n$, resulting in cubic time complexity $\Theta(n^3)$ and auxiliary space $O(1)$ (or $O(n^2)$ to store $C$).

---

## 4. Concept of Hashing and Hash Functions

**Question:** Explain the concept of hashing. Discuss different hash functions with suitable examples. (8 marks)

### Concept of Hashing

**Hashing** is a technique used to store, search, and retrieve data in $O(1)$ average time by using a mathematical function called a **hash function** to map a given key $k$ directly to an index (address) in a fixed-size array called a **hash table**.

$$\text{index} = h(k)$$

- **Key ($k$):** Unique identifier of the record (e.g., student roll number, employee ID).
- **Hash Function ($h$):** Converts key $k$ into a table index in the range $[0, m-1]$.
- **Hash Table:** An array of $m$ buckets/slots where records are stored.

**Properties of a Good Hash Function:**
- Easy and fast ($O(1)$) to compute.
- Distributes keys uniformly across all $m$ slots.
- Minimizes collisions.
- Deterministic (always produces the same index for the same key).

---

### Common Hash Functions with Examples

#### 1. Division (Remainder) Method
Divides the key $k$ by the table size $m$ and takes the remainder:

$$h(k) = k \bmod m$$

- **Best choice of $m$:** A prime number not close to an exact power of 2 or 10.
- **Example:** For $m = 10$ and key $k = 37$:
  $$h(37) = 37 \bmod 10 = 7$$
  Record $37$ is stored at index **7**.

#### 2. Multiplication Method
Multiplies the key $k$ by a constant fraction $A \in (0, 1)$, extracts the fractional part, and multiplies by $m$:

$$h(k) = \lfloor m \cdot (kA \bmod 1) \rfloor$$

- Knuth suggests $A \approx \frac{\sqrt{5}-1}{2} \approx 0.618$.
- **Example:** Let $m = 16$, $A = 0.618$, and $k = 25$:
  1. $k \cdot A = 25 \times 0.618 = 15.45$
  2. Fractional part: $15.45 \bmod 1 = 0.45$
  3. Multiply by $m$: $\lfloor 16 \times 0.45 \rfloor = \lfloor 7.2 \rfloor = \mathbf{7}$

#### 3. Mid-Square Method
Squares the key $k$ and extracts the middle digits/bits as the hash address.

- **Example:** Let $k = 25$, table size $m = 10$:
  1. $k^2 = 25^2 = 625$
  2. Middle digit $= \mathbf{2}$ (so index $= 2 \bmod 10 = 2$).

#### 4. Folding Method
Partitions the key $k$ into equal-sized parts and adds them together.

- **Shift Folding:** Add the parts directly.
  - *Example:* For $k = 123456$ split into pairs: $12 + 34 + 56 = 102 \implies 102 \bmod m$.
- **Boundary Folding:** Reverse alternate parts before adding.
  - *Example:* For $k = 123456$, reverse $34 \to 43$: $12 + 43 + 56 = 111 \implies 111 \bmod m$.

#### 5. Digit Extraction Method
Extracts specific digit positions that show uniform distribution across keys.

- **Example:** For $k = 987654$, extracting the 2nd, 4th, and 6th digits gives `864` $\implies 864 \bmod m$.

#### 6. String Hash Function (ASCII Sum / Polynomial Rolling)
Sums the ASCII values of characters in a string key modulo $m$.

- **Example:** For key `"ABC"`:
  $$\text{ASCII}(A)=65,\ \text{ASCII}(B)=66,\ \text{ASCII}(C)=67 \implies (65 + 66 + 67) \bmod m = 198 \bmod m$$

---

## 5. Collision Resolution Techniques

**Question:** Explain the collision resolution techniques Linear Probing, Quadratic Probing, Double Hashing, and Separate Chaining. (8 marks)

### What is a Collision?

A **collision** occurs when two distinct keys $k_1 \ne k_2$ map to the same hash table index:

$$h(k_1) = h(k_2)$$

For example, with $h(k) = k \bmod 10$, both $12 \bmod 10 = 2$ and $22 \bmod 10 = 2$ collide at index `2`.

Collision resolution techniques are divided into two categories:
1. **Separate Chaining (Open Hashing / Closed Addressing)**
2. **Open Addressing (Closed Hashing):** Linear Probing, Quadratic Probing, Double Hashing.

---

### 1. Separate Chaining

**Method:** Each slot of the hash table stores a pointer to a singly linked list (chain) containing all keys that hash to that index.

#### Example
Insert keys `15, 25, 35, 12` into a table of size $m = 10$ using $h(k) = k \bmod 10$:

```text
Index
 [0] -> NULL
 [1] -> NULL
 [2] -> [12] -> NULL
  ...
 [5] -> [15] -> [25] -> [35] -> NULL
```

- **Advantages:** Simple to implement; no clustering; table never overflows as long as free memory exists; deletion is easy.
- **Disadvantages:** Extra memory overhead for pointers; worst-case search degrades to $O(n)$ if all keys land in one chain.

---

### 2. Open Addressing Techniques

All elements are stored directly inside the hash table array. When a collision occurs, the table is probed systematically until an empty slot is found.

#### (i) Linear Probing
Searches sequentially for the next available slot:

$$h(k, i) = (h'(k) + i) \bmod m \quad \text{for } i = 0, 1, 2, \dots, m-1$$

where $h'(k) = k \bmod m$.

- **Example ($m = 10$):** Insert `12, 22, 32`:
  - `12`: $h(12, 0) = 2$ (stored at index `2`).
  - `22`: $h(22, 0) = 2$ (occupied) $\to h(22, 1) = (2 + 1) \bmod 10 = \mathbf{3}$.
  - `32`: Probes `2` (occupied), `3` (occupied) $\to h(32, 2) = (2 + 2) \bmod 10 = \mathbf{4}$.
- **Drawback — Primary Clustering:** Contiguous blocks of occupied slots form and grow, increasing probe lengths for future insertions.

#### (ii) Quadratic Probing
Probes slots at quadratic offsets from the original hash position to eliminate primary clustering:

$$h(k, i) = (h'(k) + i^2) \bmod m \quad \text{for } i = 0, 1, 2, \dots, m-1$$

- **Example ($m = 10$):** Insert `12, 22, 32`:
  - `12`: stored at index `2`.
  - `22`: collides at `2` $\to (2 + 1^2) \bmod 10 = \mathbf{3}$.
  - `32`: collides at `2` $\to (2 + 1^2) = 3$ (occupied) $\to (2 + 2^2) \bmod 10 = \mathbf{6}$.
- **Drawback — Secondary Clustering:** Keys that hash to the same initial index follow the exact same probe sequence; also may not probe every slot unless $m$ is prime and load factor $\alpha < 0.5$.

#### (iii) Double Hashing
Uses a **second hash function** $h_2(k)$ to determine the step size for each key:

$$h(k, i) = (h_1(k) + i \cdot h_2(k)) \bmod m \quad \text{for } i = 0, 1, 2, \dots, m-1$$

Common choice: $h_1(k) = k \bmod m$ and $h_2(k) = R - (k \bmod R)$ where $R < m$ is prime ($h_2(k)$ must never be $0$).

- **Example ($m = 10, R = 7$):** Insert `12` and `22`:
  - `12`: $h_1(12) = 2 \to$ stored at index `2`.
  - `22`: $h_1(22) = 2$ (collision). Compute $h_2(22) = 7 - (22 \bmod 7) = 7 - 1 = 6$.
  - Next probe ($i=1$): $(2 + 1 \times 6) \bmod 10 = \mathbf{8}$.
- **Advantage:** Eliminates both primary and secondary clustering because different colliding keys have different step sizes $h_2(k)$.

---

### Comparison Summary

| Technique | Probe Formula | Clustering | Extra Memory |
|---|---|---|---|
| **Separate Chaining** | Linked list at $h(k)$ | None | Yes (pointers) |
| **Linear Probing** | $(h(k) + i) \bmod m$ | Primary clustering | No |
| **Quadratic Probing** | $(h(k) + i^2) \bmod m$ | Secondary clustering | No |
| **Double Hashing** | $(h_1(k) + i \cdot h_2(k)) \bmod m$ | None | No |

---

## 6. Static Hashing vs. Dynamic Hashing (Extendible Hashing)

**Question:** Differentiate between Static Hashing and Dynamic Hashing. Explain the working of Dynamic Hashing (Extendible hashing) with an example. (8 marks)

### Static Hashing vs. Dynamic Hashing

| Feature | Static Hashing | Dynamic Hashing |
|---|---|---|
| **Number of Buckets** | Fixed at creation time ($m$ is constant). | Variable; grows and shrinks dynamically with data size. |
| **Directory / Table Size** | Constant. | Expands (e.g., doubles) or contracts on demand. |
| **Collision & Overflow Handling** | Degrades to long overflow chains or full-table rehashing. | Splits only the overflowing bucket locally. |
| **Performance as Data Grows** | Degrades as load factor $\alpha$ increases. | Remains consistently fast ($O(1)$ bucket access). |
| **Implementation Complexity** | Simple. | More complex (maintains directory and depth metadata). |
| **Best Suited For** | Databases with predictable, fixed record counts. | Large, dynamic databases that grow and shrink frequently. |

---

### Working of Extendible Hashing

**Extendible Hashing** is a dynamic hashing technique that uses an in-memory **directory** of pointers to disk **buckets**, indexing the directory using bits of the binary hash value $h(k)$.

#### Key Terms
1. **Global Depth ($GD$):** Number of bits used by the directory to index buckets. A directory with global depth $GD$ has $2^{GD}$ entries.
2. **Local Depth ($LD$):** Number of bits used to determine membership in a specific bucket ($LD \le GD$ always).
3. **Bucket Capacity ($B$):** Maximum number of keys a single bucket can hold before overflowing.
4. **Bucket Splitting:** When a bucket overflows:
   - If $LD < GD$: Split the bucket into two, increment its $LD$ by 1, and update the directory pointers without growing the directory.
   - If $LD == GD$: First **double the directory** (increment $GD$ by 1), then split the overflowing bucket and increment its $LD$.

---

### Worked Example of Extendible Hashing

Assume **bucket capacity $B = 2$** and we use the **first (or last) $GD$ bits** of the binary hash values below (using prefixes):

| Key | Binary Hash |
| :---: | :---: |
| $k_1$ | `000` |
| $k_2$ | `010` |
| $k_3$ | `100` |
| $k_4$ | `101` |
| $k_5$ | `110` |

#### Step 1: Initial State ($GD = 1$) after inserting $k_1(`000`), k_2(`010`), k_3(`100`)$

- Directory uses 1 bit (`0` and `1`):
  - Bucket `0` ($LD=1$): holds $k_1(`000`), k_2(`010`)$ (full).
  - Bucket `1` ($LD=1$): holds $k_3(`100`)$.

```text
Directory (GD = 1)
 [0] ------------> Bucket A (LD = 1): [ 000, 010 ]
 [1] ------------> Bucket B (LD = 1): [ 100 ]
```

#### Step 2: Insert $k_4(`101`)$

- First bit is `1`, so $k_4$ goes into Bucket B:

```text
Directory (GD = 1)
 [0] ------------> Bucket A (LD = 1): [ 000, 010 ]
 [1] ------------> Bucket B (LD = 1): [ 100, 101 ] (Full)
```

#### Step 3: Insert $k_5(`110`)$ — Overflow & Directory Doubling

- First bit of `110` is `1`, mapping to Bucket B (`[100, 101]`), which is already full!
- Since Bucket B has $LD = 1 = GD$, we:
  1. **Double the directory:** Increase $GD$ from $1 \to 2$ (directory entries `00, 01, 10, 11`).
  2. **Split Bucket B** into Bucket B0 (`10`) and Bucket B1 (`11`) with $LD = 2$, redistributing `100`, `101`, and `110`:
     - `10` $\to [100, 101]$
     - `11` $\to [110]$
  3. Bucket A ($LD = 1$) does not split; both directory entries `00` and `01` point to Bucket A.

```text
Directory (GD = 2)
 [00] ---+
         +-------> Bucket A  (LD = 1): [ 000, 010 ]
 [01] ---+
 [10] -----------> Bucket B0 (LD = 2): [ 100, 101 ]
 [11] -----------> Bucket B1 (LD = 2): [ 110 ]
```

**Conclusion:** Extendible hashing avoids full-table reorganization by splitting only overflowing buckets and doubling only the lightweight pointer directory when $LD = GD$.
