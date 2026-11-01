# UNIT I — Algorithm Analysis and Hashing

> **Course:** Advanced Data Structures & Algorithm Analysis (`2501CS10`) | Aditya University  
> **Exam Priority:** Priority 2 (Foundation & High Yield) · **Unit Difficulty:** Easy (3/10)  
> **Source:** *Unit-wise Important Questions — Answers | Aditya University*

---

## Part A: 2-Mark Questions

### Q1: What is an algorithm?

#### Definition
A finite sequence of well-defined steps that solves a problem. It takes zero or more inputs, produces at least one output, and terminates after a finite number of steps.

#### Key Properties
- **Input:** Zero or more externally supplied quantities.
- **Output:** At least one quantity produced.
- **Definiteness:** Each instruction must be clear and unambiguous.
- **Finiteness:** Must terminate after a finite number of steps for all cases.
- **Effectiveness:** Every operation must be basic enough to be carried out in principle.

---

### Q2: Differentiate between time complexity and space complexity.

#### Comparison
| Basis | Time Complexity | Space Complexity |
|---|---|---|
| **Measures** | Running time as a function of input size $n$ | Total memory required as a function of input size $n$ |
| **Counted by** | Number of basic / elementary operations executed | Input space + extra auxiliary space + call stack |
| **Example (Merge Sort)** | $O(n \log n)$ | $O(n)$ |

---

### Q3: What is the purpose of Asymptotic notations?

#### Definition
Asymptotic notations describe the mathematical rate of growth of an algorithm's running time or memory usage as input size $n \to \infty$, ignoring hardware-specific constants and low-order terms.

#### Core Notations
| Notation | Name | Mathematical Condition | Bound Represented |
|---|---|---|---|
| $O(g(n))$ | Big-O | $f(n) \le c \cdot g(n)$ for $n \ge n_0$ | Upper bound (Worst case) |
| $\Omega(g(n))$ | Big-Omega | $f(n) \ge c \cdot g(n)$ for $n \ge n_0$ | Lower bound (Best case) |
| $\Theta(g(n))$ | Big-Theta | $c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ | Tight bound (Average / Exact order) |

---

### Q4: Define hashing.

#### Definition
Hashing is a technique that transforms a key of arbitrary size into a fixed-size table index using a mathematical hash function $h(k)$, enabling direct $O(1)$ average-time access, insertion, and deletion.

---

### Q5: What is a hash table? State any two desirable properties of a good hash function.

#### Hash Table
A data structure that stores key-value pairs in an array indexed by a hash function $h(k)$.

#### Two Desirable Properties
1. **Uniform Distribution (Low Collisions):** Spreads keys uniformly across all slots so each slot is equally likely.
2. **Fast Computation:** Computes index in $O(1)$ time with minimal arithmetic overhead.

---

### Q6: What is the use of a hash function?

#### Core Purpose
Maps a large search key space into a bounded array index range $[0, m-1]$.
- Achieves $O(1)$ average search, insertion, and deletion.
- Applied in database indexing, symbol tables in compilers, caches, and cryptography.

---

### Q7: Define collision resolution.

#### Definition
A collision occurs when two distinct keys hash to the same table slot ($h(k_1) = h(k_2)$ for $k_1 \neq k_2$). Collision resolution is the systematic algorithm used to allocate an alternative slot or chain multiple keys sharing that slot.

---

### Q8: List out all collision resolution techniques.

#### Classification
| Technique Category | Specific Methods | Working Principle |
|---|---|---|
| **Open Hashing (Chaining)** | Separate Chaining | Each slot maintains a linked list of colliding elements. |
| **Closed Hashing (Open Addressing)** | Linear Probing | Search sequentially: $h(k, i) = (h(k) + i) \bmod m$. |
| | Quadratic Probing | Search quadratic jumps: $h(k, i) = (h(k) + c_1 i + c_2 i^2) \bmod m$. |
| | Double Hashing | Search with second hash step: $h(k, i) = (h_1(k) + i \cdot h_2(k)) \bmod m$. |

---

## Part B: 8-Mark Questions

### 1. Importance of Algorithm Analysis and Time vs. Space Complexity

**Q1. Explain the importance of algorithm analysis. Differentiate between time complexity and space complexity with suitable examples.**

Algorithm analysis is the process of estimating the resources (time and memory) an algorithm needs as a function of the input size $n$, independent of machine and language.

#### Importance

1. Compare different algorithms for the same problem and choose the best one.
2. Predict performance for large inputs before implementation.
3. Identify the best, average and worst case behaviour.
4. Avoid wasting time and memory (scalability).
5. Gives a machine-independent measure using asymptotic notation.

| Aspect | Time Complexity | Space Complexity |
|---|---|---|
| **Meaning** | Amount of time (number of basic operations) as a function of $n$ | Amount of memory needed as a function of $n$ |
| **Measured by** | Counting steps/operations | Input space + auxiliary (extra) space + recursion stack |
| **Unit** | Number of operations | Number of memory words/bytes |
| **Example 1** | Linear search: $O(n)$ | Linear search: $O(1)$ extra space |
| **Example 2** | Merge sort: $O(n \log n)$ | Merge sort: $O(n)$ auxiliary array |
| **Example 3** | Matrix addition: $O(n^2)$ | Matrix addition: $O(n^2)$ for result |
| **Trade-off** | Can often be reduced by using more memory (e.g. hashing, DP tables) | Can be reduced by recomputation, usually at the cost of time |

---

### 2. Asymptotic Notations: Big-O, Omega, and Theta

**Q2. Describe the asymptotic notations $O$, $\Omega$, and $\Theta$. Illustrate each notation with suitable examples.**

Asymptotic notations are mathematical tools used to characterize the runtime or memory growth of an algorithm as input size $n \to \infty$, independent of specific hardware, compiler, or processor speeds.

![Asymptotic Notations Growth Curves](figures/unit1_q2_asymptotic_notations.png)

#### 1. Big-O Notation ($O$ — Upper Bound / Worst Case)

Big-O represents the upper bound on the growth rate of an algorithm. It specifies that an algorithm will take *at most* this amount of time.

$$
f(n) = O(g(n)) \iff \exists \text{ positive constants } c > 0 \text{ and } n_0 \ge 1 \text{ such that } 0 \le f(n) \le c \cdot g(n) \quad \forall n \ge n_0
$$

- **Mathematical Proof:** Prove $f(n) = 3n + 2 = O(n)$:
  - Given $f(n) = 3n + 2$ and $g(n) = n$.
  - We require $3n + 2 \le c \cdot n$.
  - For $c = 4$ and $n_0 = 2$:
    $$3(2) + 2 = 8 \le 4(2) = 8 \quad (\text{holds for all } n \ge 2)$$
  - Hence, $3n + 2 = O(n)$ with $c = 4, n_0 = 2$.

#### 2. Big-Omega Notation ($\Omega$ — Lower Bound / Best Case)

Big-Omega represents the lower bound on the growth rate. It specifies the minimum amount of time an algorithm will take for large $n$.

$$
f(n) = \Omega(g(n)) \iff \exists \text{ positive constants } c > 0 \text{ and } n_0 \ge 1 \text{ such that } 0 \le c \cdot g(n) \le f(n) \quad \forall n \ge n_0
$$

- **Mathematical Proof:** Prove $f(n) = 5n^2 + 10 = \Omega(n^2)$:
  - Given $f(n) = 5n^2 + 10$ and $g(n) = n^2$.
  - We require $c \cdot n^2 \le 5n^2 + 10$.
  - Choose $c = 5$ and $n_0 = 1$:
    $$5(1)^2 = 5 \le 5(1)^2 + 10 = 15 \quad (\text{holds for all } n \ge 1)$$
  - Hence, $5n^2 + 10 = \Omega(n^2)$ with $c = 5, n_0 = 1$.

#### 3. Big-Theta Notation ($\Theta$ — Tight Bound / Average Case)

Big-Theta bounds the function both from above and below within constant factors. It gives the exact rate of growth.

$$
f(n) = \Theta(g(n)) \iff \exists \text{ constants } c_1, c_2 > 0 \text{ and } n_0 \ge 1 \text{ such that } 0 \le c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n) \quad \forall n \ge n_0
$$

- **Mathematical Proof:** Prove $f(n) = 3n + 2 = \Theta(n)$:
  - We need $c_1 \cdot n \le 3n + 2 \le c_2 \cdot n$.
  - Choose $c_1 = 3, c_2 = 4$, and $n_0 = 2$:
    $$3n \le 3n + 2 \le 4n \quad \forall n \ge 2$$
  - Since $f(n) = O(n)$ and $f(n) = \Omega(n)$ simultaneously, $f(n) = \Theta(n)$.

| Notation | Mathematical Definition | Bound Type | Exam / Practical Use |
|---|---|---|---|
| **$O(g(n))$** | $f(n) \le c \cdot g(n)$ | Asymptotic Upper Bound | Worst-case performance guarantee |
| **$\Omega(g(n))$** | $f(n) \ge c \cdot g(n)$ | Asymptotic Lower Bound | Best-case benchmark |
| **$\Theta(g(n))$** | $c_1 \cdot g(n) \le f(n) \le c_2 \cdot g(n)$ | Asymptotic Tight Bound | True average / exact rate of growth |

**Common Orders of Growth (Ascending):**

$$
O(1) < O(\log n) < O(n) < O(n \log n) < O(n^2) < O(n^3) < O(2^n) < O(n!)
$$

---

### 3. Time Complexity of Matrix Multiplication (Tabular / Step-Count Method)

**Q3. Analyze the time complexity for matrix multiplication algorithm (tabular method) using asymptotic notation and justify your answer.**

#### Standard Matrix Multiplication Algorithm (C / Pseudo-code)

```c
void MatrixMultiplication(int A[n][n], int B[n][n], int C[n][n], int n) {
    for (int i = 0; i < n; i++) {              // Line 1
        for (int j = 0; j < n; j++) {          // Line 2
            C[i][j] = 0;                       // Line 3
            for (int k = 0; k < n; k++) {      // Line 4
                C[i][j] += A[i][k] * B[k][j];  // Line 5
            }
        }
    }
}
```

#### Step-Count Table (Tabular Method)

In the step-count method, we evaluate the cost per execution ($s/e$) and the frequency of execution for every statement:

| Line | Statement | Steps / Execution ($s/e$) | Execution Frequency | Total Step Count |
| :---: | :--- | :---: | :---: | :--- |
| **1** | `for (int i = 0; i < n; i++)` | 1 | $n + 1$ | $n + 1$ |
| **2** | `for (int j = 0; j < n; j++)` | 1 | $n \times (n + 1)$ | $n^2 + n$ |
| **3** | `C[i][j] = 0;` | 1 | $n \times n$ | $n^2$ |
| **4** | `for (int k = 0; k < n; k++)` | 1 | $n \times n \times (n + 1)$ | $n^3 + n^2$ |
| **5** | `C[i][j] += A[i][k] * B[k][j];` | 1 | $n \times n \times n$ | $n^3$ |
| **Total** | **Total Step Count $T(n)$** | — | — | **$2n^3 + 3n^2 + 2n + 1$** |

#### Step-by-Step Justification & Dominant Term Analysis

1. **Total Step Count Equation:**
   $$T(n) = 2n^3 + 3n^2 + 2n + 1$$
2. **Dominant Term:**
   - As $n \to \infty$, the term $2n^3$ dominates all lower-order terms ($3n^2$, $2n$, and $1$).
3. **Asymptotic Upper Bound ($O$):**
   - For all $n \ge 1$:
     $$2n^3 + 3n^2 + 2n + 1 \le 2n^3 + 3n^3 + 2n^3 + n^3 = 8n^3$$
   - Thus, with $c = 8$ and $n_0 = 1$, $T(n) \le 8n^3 \implies T(n) = O(n^3)$.
4. **Asymptotic Lower Bound ($\Omega$):**
   - For all $n \ge 1$, $T(n) = 2n^3 + 3n^2 + 2n + 1 \ge 2n^3$.
   - Thus, with $c = 2$ and $n_0 = 1$, $T(n) \ge 2n^3 \implies T(n) = \Omega(n^3)$.
5. **Tight Bound ($\Theta$):**
   - Since $T(n) = O(n^3)$ and $T(n) = \Omega(n^3)$, **$T(n) = \Theta(n^3)$**.
- **Space Complexity:** $\Theta(n^2)$ to store the $n \times n$ matrices in memory.

---

### 4. Concept of Hashing and Hash Functions

**Q4. Explain the concept of hashing. Discuss different hash functions with suitable examples.**

Hashing is a technique that transforms a search key of arbitrary size into a fixed-size index within a hash table of size $m$, enabling direct $O(1)$ average-time search, insertion, and deletion.

```text
Key (k)  ───►  [ Hash Function h(k) ]  ───►  Index ∈ [0, m - 1] in Hash Table
```

#### Properties of a Good Hash Function
1. **Uniform Distribution:** Distributes keys evenly across all table slots to prevent clustering.
2. **Deterministic:** For any key $k$, $h(k)$ must always return the exact same index.
3. **Fast Computation:** Computes index in $O(1)$ time with minimal arithmetic operations.
4. **Minimizes Collisions:** Avoids assigning multiple keys to the same index.

#### The 6 Major Hash Functions (with Examples)

1. **Division (Remainder) Method:**
   - **Formula:** $h(k) = k \bmod m$ (where $m$ is chosen as a prime number not close to a power of 2).
   - **Example:** $k = 127, m = 11 \implies h(127) = 127 \bmod 11 = 6$.
2. **Multiplication Method:**
   - **Formula:** $h(k) = \lfloor m \cdot (k \cdot A \bmod 1) \rfloor$ (Knuth recommends $A \approx \frac{\sqrt{5}-1}{2} \approx 0.618033$).
   - **Example:** $k = 123, m = 100, A = 0.618033 \implies k \cdot A = 76.018 \implies \text{fractional part } 0.018 \implies h(k) = \lfloor 100 \times 0.018 \rfloor = 1$.
3. **Mid-Square Method:**
   - **Steps:** (1) Square the key $k^2$, (2) Extract the middle $r$ digits as the index.
   - **Example:** $k = 45 \implies k^2 = 2025$. Middle two digits are `02` $\implies h(45) = 2$.
4. **Folding Method:**
   - **Steps:** Split the key into equal-sized parts matching table index width, sum the parts, and take modulo $m$.
   - **Example:** $k = 123456$, parts = $12, 34, 56$. Sum $= 12 + 34 + 56 = 102 \implies h(k) = 102 \bmod 100 = 2$.
5. **Digit Extraction Method:**
   - **Steps:** Pre-selected digit positions from keys known to be uniformly distributed are extracted to form the address.
   - **Example:** Employee ID `98234567`. Extract 3rd, 5th, and 7th digits $\to `2, 4, 6` \implies \text{Index} = 246$.
6. **String Hash Functions (ASCII Sum Method):**
   - **Steps:** Sum the ASCII values of all characters in the string and take modulo $m$.
   - **Example:** `"CAT"`: $\text{ASCII}(C)=67, \text{ASCII}(A)=65, \text{ASCII}(T)=84$. Sum $= 67 + 65 + 84 = 216$. For $m = 10$, $h(\text{"CAT"}) = 216 \bmod 10 = 6$.

---

### 5. Collision Resolution Techniques

**Q5. Explain the collision resolution techniques: Linear Probing, Quadratic Probing, Double Hashing, and Separate Chaining.**

A collision occurs when two distinct keys produce the same hash index: $h(k_1) = h(k_2)$ for $k_1 \neq k_2$.

![Collision Resolution Techniques](figures/unit1_q5_collision_resolution.png)

#### 1. Separate Chaining (Open Hashing)
Each slot in the hash table points to a linked list of elements that hash to that same index.
- **Example:** $m = 10$, keys: `10, 70, 32, 52, 12, 23` with $h(k) = k \bmod 10$.
  - Slot `0`: `10 → 70 → NULL`
  - Slot `2`: `32 → 52 → 12 → NULL`
  - Slot `3`: `23 → NULL`
- **Advantages:** Never overflows (load factor $\alpha$ can exceed 1); simple deletion.
- **Disadvantages:** Pointer overhead; cache-unfriendly linked lists.

#### 2. Open Addressing (Closed Hashing)
All keys reside directly within the array table. If a slot is occupied, probe for the next available slot.

1. **Linear Probing:**
   - **Probe Sequence:** $h(k, i) = (h(k) + i) \bmod m$ for $i = 0, 1, 2, \dots$
   - **Example ($m = 10$, keys `23, 43, 13, 27` with $h(k) = k \bmod 10$):**
     - `Insert 23`: $h(23, 0) = 3$ (Empty $\to$ placed at `3`).
     - `Insert 43`: $h(43, 0) = 3$ (Collision! Probe $i=1 \to 4$, empty $\to$ placed at `4`).
     - `Insert 13`: $h(13, 0) = 3$ (Collision!), $i=1 \to 4$ (Collision!), $i=2 \to 5$ (placed at `5`).
     - `Insert 27`: $h(27, 0) = 7$ (Empty $\to$ placed at `7`).
     - **Final Table:** `3: 23, 4: 43, 5: 13, 7: 27`.
   - **Limitation:** Suffers from **Primary Clustering** (long contiguous blocks of occupied slots build up, degrading lookup time).
2. **Quadratic Probing:**
   - **Probe Sequence:** $h(k, i) = (h(k) + c_1 i + c_2 i^2) \bmod m$ (Standard: $i^2$).
   - **Advantage:** Eliminates primary clustering by making increasingly larger quadratic jumps ($1, 4, 9, 16\dots$).
   - **Limitation:** Can cause **Secondary Clustering** (keys hashing to the same initial slot follow identical probe paths).
3. **Double Hashing:**
   - **Probe Sequence:** $h(k, i) = (h_1(k) + i \cdot h_2(k)) \bmod m$.
   - Here $h_2(k)$ computes an individualized step size (e.g. $h_2(k) = 7 - (k \bmod 7)$).
   - **Advantage:** Completely avoids both primary and secondary clustering; yields optimal uniform distribution in open addressing.

| Feature | Separate Chaining | Linear Probing | Quadratic Probing | Double Hashing |
|---|---|---|---|---|
| **Storage Strategy** | Linked list per slot | Contiguous array | Contiguous array | Contiguous array |
| **Clustering** | None | Severe (Primary) | Mild (Secondary) | None |
| **Can Table Overflow?** | No (limited by RAM) | Yes (when full) | Yes | Yes |
| **Cache Performance** | Poor (pointer chasing) | Excellent (linear) | Good | Moderate |

---

### 6. Static Hashing vs. Dynamic Hashing (Extendible Hashing)

**Q6. Differentiate between Static Hashing and Dynamic Hashing. Explain the working of Dynamic (Extendable) Hashing with an example.**

| Feature | Static Hashing | Dynamic Hashing |
|---|---|---|
| **Table size** | Fixed number of buckets | Grows and shrinks with the data |
| **Hash function** | Fixed, $h(k) = k \bmod m$ | Uses a variable number of bits of the hash value |
| **Overflow** | Needs overflow chains/probing; performance degrades | Handled by splitting buckets |
| **Reorganisation** | Costly full rehashing when the table is full | Only one bucket is split at a time |
| **Space** | Wasted if the file is small, overflow if large | Efficient use of space |
| **Example** | Simple hash table | Extendable hashing, linear hashing |

#### Extendable Hashing — working

- A directory of $2^d$ pointers is indexed by the first/last $d$ bits of $h(k)$ ($d =$ global depth).
- Each bucket has a local depth $d' \le d$ and a fixed capacity.
- Several directory entries may point to the same bucket.
- **Insert:** find the bucket using $d$ bits. If there is space, insert. If the bucket is full:
  - If $d' < d$: split the bucket, increase its local depth, redistribute keys.
  - If $d' = d$: double the directory ($d = d + 1$), then split the bucket.

#### Example

Bucket capacity $= 2$, using the last bits of the binary key. Initial global depth $d = 1$.

1. Insert `4` (`100`) goes to bucket `"0"`: `{4}`. Insert `1` (`001`) goes to bucket `"1"`: `{1}`. Insert `5` (`101`) goes to bucket `"1"`: `{1, 5}` (now full).
2. Insert `7` (`111`): bucket `"1"` is full and $d' = d = 1$, so double the directory ($d = 2$) and split the bucket using 2 bits.
3. Keys with last two bits `01` are `1` and `5`; key with `11` is `7`.

| Directory (last 2 bits) | Points to bucket | Local depth |
|---|---|---:|
| `00` | $B_0 = \{4\}$ | 1 |
| `10` | $B_0 = \{4\}$ (shared) | 1 |
| `01` | $B_1 = \{1, 5\}$ | 2 |
| `11` | $B_2 = \{7\}$ | 2 |

![Extendible Hashing Directory and Split Buckets](figures/unit1_q6_extendible_hashing.png)

- **Advantages:** no full rehash, grows gracefully, at most two disk accesses.
- **Disadvantage:** the directory itself can become large.
