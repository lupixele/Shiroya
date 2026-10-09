# 05. Permutations and Combinations

A comprehensive, self-contained reference and practice guide for quantitative aptitude examinations, campus recruitment assessments, and competitive entrance tests on **Permutations and Combinations**. This guide details fundamental counting principles, factorial algebra, linear and circular arrangements, word formation with constraints, multiset combinatorics, selection models, geometry counting, and high-speed mental shortcuts.

---

## 1. Comprehensive Theory and Formulas

Permutations and Combinations form the mathematical bedrock of counting discrete structures and evaluating probabilities. The foundational distinction lies in whether the **order of selection matters**:
- **Permutation:** Order **matters** (arrangements, sequences, rankings, positions, words, codes).
- **Combination:** Order **does not matter** (selections, groups, committees, handshakes, teams, collections).

---

### 1.1 Fundamental Principles of Counting

#### 1. The Fundamental Principle of Multiplication (The Product Rule / The AND Rule)
If an operation can be performed in $m$ distinct ways, and following its completion, a second independent operation can be performed in $n$ distinct ways, then both operations in succession can be performed in:
$$\text{Total Ways} = m \times n$$

Extending to $k$ independent sequential stages with $n_1, n_2, \dots, n_k$ choices respectively:
$$\text{Total Ways} = n_1 \times n_2 \times n_3 \times \dots \times n_k$$

*Example:* If a candidate can select 1 shirt out of 4 colors and 1 pair of trousers out of 3 styles, the number of distinct outfits is:
$$4 \times 3 = 12\text{ outfits}$$

#### 2. The Fundamental Principle of Addition (The Sum Rule / The OR Rule)
If two tasks are mutually exclusive (they cannot occur simultaneously), where task A can be performed in $m$ ways and task B can be performed in $n$ ways, then performing either task A or task B can occur in:
$$\text{Total Ways} = m + n$$

*Example:* If a library has 5 mathematics books and 6 physics books, choosing one single book (either math or physics) can be done in:
$$5 + 6 = 11\text{ ways}$$

#### 3. Principle of Inclusion-Exclusion (PIE)
For two non-mutually exclusive events $A$ and $B$:
$$|A \cup B| = |A| + |B| - |A \cap B|$$
For three events $A$, $B$, and $C$:
$$|A \cup B \cup C| = |A| + |B| + |C| - (|A \cap B| + |B \cap C| + |C \cap A|) + |A \cap B \cap C|$$

---

### 1.2 Factorials and Algebraic Properties

The factorial of a non-negative integer $n$, denoted by $n!$, represents the product of all positive integers less than or equal to $n$:
$$n! = n \times (n - 1) \times (n - 2) \times \dots \times 3 \times 2 \times 1$$

#### Axiomatic Conventions and Recursive Definition
- By mathematical definition:
  $$0! = 1, \quad 1! = 1$$
- Recursive identity:
  $$n! = n \times (n - 1)! \implies (n - 1)! = \frac{n!}{n}$$
  Setting $n = 1$: $0! = \frac{1!}{1} = 1$.

#### High-Frequency Factorials Reference Table
| $n$ | Expansion | Value | $n$ | Expansion | Value |
|---|---|---|---|---|---|
| $0!$ | By convention | $1$ | $6!$ | $6 \times 120$ | $720$ |
| $1!$ | $1$ | $1$ | $7!$ | $7 \times 720$ | $5,040$ |
| $2!$ | $2 \times 1$ | $2$ | $8!$ | $8 \times 5040$ | $40,320$ |
| $3!$ | $3 \times 2 \times 1$ | $6$ | $9!$ | $9 \times 40320$ | $362,880$ |
| $4!$ | $4 \times 6$ | $24$ | $10!$ | $10 \times 362880$ | $3,628,800$ |
| $5!$ | $5 \times 24$ | $120$ | $11!$ | $11 \times 3628800$ | $39,916,800$ |

#### Essential Factorial Simplification Rules
1. **Quotient of Consecutive Factorials:**
   $$\frac{n!}{(n - 1)!} = n, \quad \frac{n!}{(n - 2)!} = n(n - 1), \quad \frac{n!}{(n - 3)!} = n(n - 1)(n - 2)$$
2. **Difference of Consecutive Factorials:**
   $$n! - (n - 1)! = (n - 1)! \times (n - 1)$$
   $$(n + 1)! - n! = n! \times n$$
3. **Legendre's Formula (Exponent of Prime $p$ in $n!$):**
   $$E_p(n!) = \left\lfloor \frac{n}{p} \right\rfloor + \left\lfloor \frac{n}{p^2} \right\rfloor + \left\lfloor \frac{n}{p^3} \right\rfloor + \dots$$

---

### 1.3 Permutations (Arrangements Where Order Matters)

A permutation is an ordered arrangement of elements chosen from a given set.

#### 1. Permutations of $n$ Distinct Objects Taken $r$ at a Time (${}^n\text{P}_r$ or $P(n, r)$)
The number of ways to arrange $r$ distinct items out of $n$ available items ($0 \le r \le n$):
$${}^n\text{P}_r = \frac{n!}{(n - r)!} = n \times (n - 1) \times (n - 2) \times \dots \times (n - r + 1)$$

- **All $n$ items arranged ($r = n$):**
  $${}^n\text{P}_n = \frac{n!}{(n - n)!} = \frac{n!}{0!} = n!$$
- **No items arranged ($r = 0$):**
  $${}^n\text{P}_0 = \frac{n!}{(n - 0)!} = \frac{n!}{n!} = 1$$
- **Single item arranged ($r = 1$):**
  $${}^n\text{P}_1 = \frac{n!}{(n - 1)!} = n$$
- **Two items arranged ($r = 2$):**
  $${}^n\text{P}_2 = n(n - 1)$$

#### 2. Permutations with Repetition Allowed
When each of the $r$ available positions can be filled by any of the $n$ distinct objects (reuse permitted):
$$\text{Total Arrangements} = \underbrace{n \times n \times n \times \dots \times n}_{r \text{ times}} = n^r$$

*Example:* Number of ways to post $r$ distinct letters into $n$ distinct letterboxes is $n^r$ (since each letter has $n$ choices).

#### 3. Permutations of Objects Not All Distinct (Multiset Permutations)
The number of distinct linear permutations of $n$ objects, where $p$ objects are of kind 1, $q$ objects are of kind 2, $r$ objects are of kind 3, and the rest are distinct:
$$\text{Total Arrangements} = \frac{n!}{p! \times q! \times r! \times \dots}$$
where $p + q + r + \dots \le n$.

*Word Arrangement Example:* For the word `MANAGEMENT` ($n = 10$ letters: M:2, A:2, N:2, E:2, G:1, T:1):
$$\text{Total Distinct Words} = \frac{10!}{2! \times 2! \times 2! \times 2!} = \frac{3,628,800}{16} = 226,800$$

#### 4. Relative Position Invariance
When arranging a word such that the **relative order of categories** (e.g., vowels occupy the vowel slots, consonants occupy consonant slots) is preserved:
$$\text{Arrangements} = \frac{(\text{Total Consonants})!}{\prod (\text{Consonant repetitions})!} \times \frac{(\text{Total Vowels})!}{\prod (\text{Vowel repetitions})!}$$

---

### 1.4 Specialized Arrangement Techniques

#### 1. The Block / String / Tie Method (Items Must Come Together)
When $k$ specific entities must always appear consecutively:
1. Bundle the $k$ entities into a single composite unit (a "block").
2. The number of entities to arrange becomes:
   $$N_{\text{eff}} = (n - k) + 1$$
3. Arrange the $N_{\text{eff}}$ entities externally in $N_{\text{eff}}!$ ways (adjusting for duplicate items if any).
4. Arrange the $k$ items internally within the block in $k!$ ways (adjusting for duplicate items if any).
5. Apply the Product Rule:
   $$\text{Total Arrangements} = N_{\text{eff}}! \times k!$$

#### 2. The Gap / Insertion Method (Items Must Never Come Together)
When $k$ specific items must be strictly separated so that no two are adjacent:
1. First arrange the remaining $m = (n - k)$ unrestricted items in a row:
   $$\text{Ways to arrange unrestricted items} = m!$$
2. These $m$ items generate exactly $(m + 1)$ potential gaps (including the two ends):
   $$\_ \, X_1 \, \_ \, X_2 \, \_ \, X_3 \, \dots \, X_m \, \_$$
3. The $k$ restricted items must be placed into these $(m + 1)$ distinct gaps such that at most one item occupies any gap:
   $$\text{Ways to place restricted items} = {}^{m + 1}\text{P}_k$$
4. Total arrangements:
   $$\text{Total Arrangements} = m! \times {}^{m + 1}\text{P}_k$$

#### 3. Complementary Counting (Subtraction Method)
When a condition specifies "at least one" or "not all together":
$$\text{Favorable Arrangements} = \text{Total Unrestricted Arrangements} - \text{Unfavorable Arrangements}$$
- *Items not all together:*
  $$\text{Ways} = \text{Total Arrangements} - \text{Ways where all items are together}$$

---

### 1.5 Circular Permutations

Arranging items along a closed loop eliminates absolute starting and ending points; only relative positions matter.

#### 1. Distinct Orientations (Round Table Seating)
When clockwise and counter-clockwise orders are distinct (e.g., people seated around a circular table):
$$\text{Circular Permutations} = (n - 1)!$$
*Mathematical Proof:* In a linear arrangement of $n$ persons, there are $n!$ configurations. On a circular table, rotating all persons by $1, 2, \dots, (n - 1)$ positions generates identical cyclic orders. Thus, each circular configuration corresponds to $n$ linear shifts:
$$\text{Circular Arrangements} = \frac{n!}{n} = (n - 1)!$$

#### 2. Flippable Loops (Necklaces, Garlands, Key Rings)
When the circular ring can be flipped over (inverted), clockwise and counter-clockwise arrangements become indistinguishable:
$$\text{Necklace Arrangements} = \frac{(n - 1)!}{2} \quad (\text{for } n \ge 3)$$

#### 3. Round Table with Gap Constraints
To seat $m$ men and $w$ women around a circular table such that no two women sit together ($w \le m$):
1. First, seat the $m$ men around the round table:
   $$\text{Ways to seat men} = (m - 1)!$$
2. Because the table is circular, $m$ men create exactly $m$ spaces (gaps) between them (unlike a line which has $m + 1$ gaps).
3. Place the $w$ women into these $m$ distinct gaps:
   $$\text{Ways to seat women} = {}^m\text{P}_w$$
4. Total arrangements:
   $$\text{Total Ways} = (m - 1)! \times {}^m\text{P}_w$$
   When $w = m$: $(m - 1)! \times m!$.

---

### 1.6 Combinations (Selections Where Order Does Not Matter)

A combination is an unordered collection or selection of elements chosen from a given set.

#### 1. Fundamental Combination Formula (${}^n\text{C}_r$ or $C(n, r)$)
The number of distinct subsets of size $r$ that can be chosen from a set of size $n$ ($0 \le r \le n$):
$${}^n\text{C}_r = \binom{n}{r} = \frac{n!}{r! \times (n - r)!} = \frac{{}^n\text{P}_r}{r!}$$

#### 2. Essential Combinatorial Identities
1. **Symmetric Complement:**
   $${}^n\text{C}_r = {}^n\text{C}_{n - r}$$
   *Application:* Evaluating ${}^{20}\text{C}_{17}$ is identical to evaluating ${}^{20}\text{C}_3 = \frac{20 \times 19 \times 18}{3 \times 2 \times 1} = 1140$.
2. **Boundary Values:**
   $${}^n\text{C}_0 = 1, \quad {}^n\text{C}_n = 1, \quad {}^n\text{C}_1 = n$$
3. **Pascal's Identity:**
   $${}^n\text{C}_r + {}^n\text{C}_{r - 1} = {}^{n+1}\text{C}_r$$
4. **Sum of Binomial Coefficients (Total Number of Subsets):**
   $$\sum_{r=0}^{n} {}^n\text{C}_r = {}^n\text{C}_0 + {}^n\text{C}_1 + {}^n\text{C}_2 + \dots + {}^n\text{C}_n = 2^n$$
5. **Selection of At Least One Item:**
   $$\sum_{r=1}^{n} {}^n\text{C}_r = 2^n - 1$$
6. **Restricted Selections:**
   - If $k$ specific items must **always be included**:
     $$\text{Ways} = {}^{n - k}\text{C}_{r - k}$$
   - If $k$ specific items must **always be excluded**:
     $$\text{Ways} = {}^{n - k}\text{C}_r$$
   - If $p$ specific items are included and $q$ specific items are excluded:
     $$\text{Ways} = {}^{n - p - q}\text{C}_{r - p}$$

#### 3. Combinations with Repetition (Multisets / Stars and Bars)
The number of ways to choose $r$ items from $n$ distinct categories when items of each category can be chosen multiple times:
$${}^{n + r - 1}\text{C}_r = \binom{n + r - 1}{r} = \frac{(n + r - 1)!}{r! \times (n - 1)!}$$

*Algebraic Equivalent:* The number of non-negative integer solutions to:
$$x_1 + x_2 + \dots + x_n = r, \quad \text{where } x_i \ge 0$$
*Pool Balls Application:* Choosing 4 balls from 5 available distinct colors with repetition permitted:
$${}^{5 + 4 - 1}\text{C}_4 = {}^8\text{C}_4 = \frac{8 \times 7 \times 6 \times 5}{4 \times 3 \times 2 \times 1} = 70\text{ ways}$$

---

### 1.7 Selection Followed by Arrangement (Hybrid Problems)

When forming a word, code, or sequence from subsets chosen from multiple categories:
1. **Step 1:** Select the components from each source pool using combinations (${}^{n_1}\text{C}_{r_1} \times {}^{n_2}\text{C}_{r_2}$).
2. **Step 2:** Arrange all selected elements in the final positions using permutations ($r!$ or multiset permutations).
$$\text{Total Words / Codes} = \left({}^{n_1}\text{C}_{r_1} \times {}^{n_2}\text{C}_{r_2}\right) \times (r_1 + r_2)!$$

---

### 1.8 Geometric and Practical Combinatorics

1. **Handshake Problem & Round-Robin Tournaments:**
   If every person in a gathering of $n$ individuals shakes hands with every other person exactly once:
   $$\text{Total Handshakes} = {}^n\text{C}_2 = \frac{n(n - 1)}{2}$$
2. **Number of Diagonals in an $n$-sided Convex Polygon:**
   Connecting any 2 of the $n$ vertices gives a segment (${}^n\text{C}_2$). Subtracting the $n$ perimeter edges:
   $$\text{Diagonals} = {}^n\text{C}_2 - n = \frac{n(n - 1)}{2} - n = \frac{n(n - 3)}{2}$$
3. **Number of Squares on an $n \times n$ Grid (Chessboard):**
   A chessboard consists of an $8 \times 8$ grid of unit squares. Squares can have side lengths from $1$ to $n$:
   $$\text{Total Squares} = \sum_{k=1}^{n} k^2 = 1^2 + 2^2 + 3^2 + \dots + n^2 = \frac{n(n + 1)(2n + 1)}{6}$$
   For a standard $8 \times 8$ chessboard:
   $$\text{Total Squares} = \frac{8 \times 9 \times 17}{6} = 4 \times 3 \times 17 = 204$$
4. **Number of Rectangles on an $n \times n$ Grid:**
   $$\text{Total Rectangles} = \left({}^{n+1}\text{C}_2\right)^2 = \left(\frac{n(n + 1)}{2}\right)^2$$
   For a standard $8 \times 8$ chessboard: $\left(\frac{8 \times 9}{2}\right)^2 = 36^2 = 1,296$.

---

## 2. High-Yield Exam Shortcuts and Mental Math Tricks

1. **Fast Factorial Cancellation:**
   Never expand factorials completely before dividing.
   - Example: $\frac{11!}{8!} = 11 \times 10 \times 9 = 990$.
   - Example: ${}^{20}\text{C}_3 = \frac{20 \times 19 \times 18}{3 \times 2 \times 1} = 20 \times 19 \times 3 = 1140$.
2. **The Symmetry Rule (${}^n\text{C}_r = {}^n\text{C}_{n-r}$):**
   Whenever $r > \frac{n}{2}$, immediately replace $r$ with $(n - r)$.
   - Example: ${}^{100}\text{C}_{98} = {}^{100}\text{C}_2 = \frac{100 \times 99}{2} = 4950$.
3. **Solving Handshake Equations Mentally:**
   Given $H = \frac{n(n-1)}{2}$, then $n(n-1) = 2H$.
   - If $H = 210$, $n(n-1) = 420$.
   - Since $20^2 = 400$, test integers around $20$: $21 \times 20 = 420 \implies n = 21$.
4. **Independent Choices Model (Voting / Letters):**
   When $v$ voters cast votes for $c$ candidates, each voter has $c$ independent options:
   $$\text{Total Ways} = c^v$$
   Be careful not to invert base and exponent: $\text{Options}^{\text{Decision Makers}}$.
5. **"At Least" Problems $\implies$ Use Complementary Counting:**
   If asked for "at least 1 black marble in 3 draws", calculate:
   $$\text{Total Draws} - \text{Draws with Zero Black Marbles}$$
   This replaces 3 separate combination cases ($1$ black, $2$ black, $3$ black) with a single subtraction.
6. **Arranging Words with Vowels Separated:**
   Always place consonants first, count the gaps, and place vowels in the gaps.
   $$\text{Consonants Arrangements} \times {}^{\text{Gaps}}\text{P}_{\text{Vowels}}$$

---

## 3. Practice Questions and Detailed Solutions

### Q1
**Question:**
Find the value of ${}^{50}\text{P}_2$.

**Options:**
- A) 4500
- B) 3260
- C) 2450
- D) 1470

**Correct Answer:** C) 2450

**Detailed Mathematical Explanation:**
- According to the standard permutation formula:
  $${}^n\text{P}_r = \frac{n!}{(n - r)!}$$
- Substituting $n = 50$ and $r = 2$:
  $${}^{50}\text{P}_2 = \frac{50!}{(50 - 2)!} = \frac{50!}{48!}$$
- Expanding the factorial quotient:
  $${}^{50}\text{P}_2 = \frac{50 \times 49 \times 48!}{48!} = 50 \times 49$$
- Performing the arithmetic multiplication:
  $$50 \times 49 = 50 \times (50 - 1) = 2500 - 50 = 2450$$

**Shortcut / Exam Trick:**
For any ${}^n\text{P}_2$, multiply $n$ by its predecessor $(n - 1)$:
$${}^n\text{P}_2 = n(n - 1) \implies 50 \times 49 = 2450$$

---

### Q2
**Question:**
Find the number of ways the letters of the word 'RUBBER' can be arranged?

**Options:**
- A) 450
- B) 362
- C) 250
- D) 180

**Correct Answer:** D) 180

**Detailed Mathematical Explanation:**
- Count the total number of letters in the word `RUBBER`:
  - Total letters ($n$) = 6
- Identify the frequencies of repeated letters:
  - Letter `R` appears: 2 times
  - Letter `U` appears: 1 time
  - Letter `B` appears: 2 times
  - Letter `E` appears: 1 time
- Apply the multiset permutation formula for repeated entities:
  $$\text{Total Arrangements} = \frac{n!}{p_1! \times p_2! \times \dots \times p_k!}$$
  $$\text{Total Arrangements} = \frac{6!}{2! \times 2!} = \frac{720}{2 \times 2} = \frac{720}{4} = 180$$

**Shortcut / Exam Trick:**
Memorize $6! = 720$. Since `R` and `B` each repeat twice, the denominator is $2 \times 2 = 4$. Divide directly: $\frac{720}{4} = 180$.

---

### Q3
**Question:**
In how many ways can we sort the letters of the word MANAGEMENT so that the comparative position of vowels and consonants remains the same as in MANAGEMENT?

**Options:**
- A) 1280
- B) 720
- C) 960
- D) 1080

**Correct Answer:** D) 1080

**Detailed Mathematical Explanation:**
- Inspect the 10-letter sequence of `MANAGEMENT`:
  - Position 1: M (Consonant)
  - Position 2: A (Vowel)
  - Position 3: N (Consonant)
  - Position 4: A (Vowel)
  - Position 5: G (Consonant)
  - Position 6: E (Vowel)
  - Position 7: M (Consonant)
  - Position 8: E (Vowel)
  - Position 9: N (Consonant)
  - Position 10: T (Consonant)
- "Comparative position remains the same" means:
  - Consonants must occupy positions {1, 3, 5, 7, 9, 10} (6 consonant slots).
  - Vowels must occupy positions {2, 4, 6, 8} (4 vowel slots).
- **Consonants group:**
  - Letters: M, N, G, M, N, T (total 6 consonants).
  - Frequencies: M appears 2 times, N appears 2 times, G appears 1 time, T appears 1 time.
  - Number of arrangements in consonant slots:
    $$\text{Ways}_{\text{consonants}} = \frac{6!}{2! \times 2!} = \frac{720}{4} = 180$$
- **Vowels group:**
  - Letters: A, A, E, E (total 4 vowels).
  - Frequencies: A appears 2 times, E appears 2 times.
  - Number of arrangements in vowel slots:
    $$\text{Ways}_{\text{vowels}} = \frac{4!}{2! \times 2!} = \frac{24}{4} = 6$$
- By the Fundamental Principle of Multiplication:
  $$\text{Total Ways} = \text{Ways}_{\text{consonants}} \times \text{Ways}_{\text{vowels}} = 180 \times 6 = 1080$$

**Shortcut / Exam Trick:**
Split consonants and vowels completely:
- Consonants: $\frac{6!}{4} = 180$
- Vowels: $\frac{4!}{4} = 6$
- Product: $180 \times 6 = 1080$.

---

### Q4
**Question:**
Find in how many different ways, the letters of the word 'LEADING' can be arranged in such a way that the vowels always come together?

**Options:**
- A) 548
- B) 426
- C) 720
- D) 790

**Correct Answer:** C) 720

**Detailed Mathematical Explanation:**
- Inspect the letters of the word `LEADING` ($n = 7$, all letters distinct):
  - Vowels: {E, A, I} (3 vowels)
  - Consonants: {L, D, N, G} (4 consonants)
- Apply the **Block (Tie) Method**:
  - Tie the 3 vowels together as a single composite unit: `[E, A, I]`.
  - The entities to be arranged are now: 4 individual consonants + 1 vowel block = 5 entities.
- **Step 1: Arrange the 5 entities:**
  $$\text{Ways} = 5! = 120$$
- **Step 2: Arrange the vowels internally within their block:**
  - The block contains 3 distinct vowels {E, A, I}:
  $$\text{Internal Ways} = 3! = 6$$
- **Step 3: Total arrangements:**
  $$\text{Total Ways} = 5! \times 3! = 120 \times 6 = 720$$

**Shortcut / Exam Trick:**
Formula for vowels together:
$$\text{Ways} = (C + 1)! \times V! = (4 + 1)! \times 3! = 5! \times 6 = 120 \times 6 = 720$$

---

### Q5
**Question:**
In how many different ways can the letters of the word 'CYCLE' be arranged?

**Options:**
- A) 30
- B) 40
- C) 80
- D) 60
- E) None of these

**Correct Answer:** D) 60

**Detailed Mathematical Explanation:**
- Inspect the letters in `CYCLE`:
  - Total letters ($n$) = 5
  - Letter frequencies: C appears 2 times, Y appears 1 time, L appears 1 time, E appears 1 time.
- Applying the multiset permutation formula:
  $$\text{Total Arrangements} = \frac{n!}{p!}$$
  $$\text{Total Arrangements} = \frac{5!}{2!} = \frac{120}{2} = 60$$

**Shortcut / Exam Trick:**
$5! = 120$. With one letter repeating twice, halve the total: $\frac{120}{2} = 60$.

---

### Q6
**Question:**
How many different ways can the letters in the word ATTEND be arranged?

**Options:**
- A) 240
- B) 120
- C) 80
- D) 60
- E) None of these

**Correct Answer:** E) None of these (Correct Value = 360)

**Detailed Mathematical Explanation:**
- Inspect the letters in `ATTEND`:
  - Total letters ($n$) = 6
  - Letter frequencies: A: 1, T: 2, E: 1, N: 1, D: 1.
- Apply the multiset permutation formula:
  $$\text{Total Arrangements} = \frac{n!}{p!}$$
  $$\text{Total Arrangements} = \frac{6!}{2!} = \frac{720}{2} = 360$$
- Reviewing the options:
  - A) 240
  - B) 120
  - C) 80
  - D) 60
  - E) None of these
- Since 360 does not match options A through D, the correct choice is **E) None of these**.

**Shortcut / Exam Trick:**
$6! = 720$. Divided by $2!$ gives 360. None of the numeric choices equal 360, so choose E instantly.

---

### Q7
**Question:**
The number of ways in which 6 men and 5 women can dine at a round table if no two women are to sit together is given by:

**Options:**
- A) $5! \times 4!$
- B) 30
- C) $7! \times 5!$
- D) $6! \times 5!$
- E) None of these

**Correct Answer:** D) $6! \times 5!$

**Detailed Mathematical Explanation:**
- This is a circular permutation with a strict separation condition ("no two women sit together"). We apply the **Gap Method** on a circular table:
- **Step 1: Seat the unrestricted persons (6 men) at the round table:**
  - Seating $m$ individuals at a round table has $(m - 1)!$ arrangements:
    $$\text{Ways to seat 6 men} = (6 - 1)! = 5!$$
- **Step 2: Determine the gaps available for the women:**
  - Unlike a linear row where $m$ objects create $(m + 1)$ gaps, in a closed circle of $m$ objects, there are exactly $m$ spaces (gaps) between adjacent people.
  - Thus, the 6 men create exactly **6 gaps**.
- **Step 3: Seat the 5 women in the available gaps:**
  - The 5 women must be arranged in the 6 available gaps so that no two women occupy the same gap:
    $$\text{Ways to arrange women} = {}^6\text{P}_5 = \frac{6!}{(6 - 5)!} = \frac{6!}{1!} = 6!$$
- **Step 4: Combine the arrangements:**
  $$\text{Total Ways} = 5! \times {}^6\text{P}_5 = 5! \times 6! = 6! \times 5!$$

**Shortcut / Exam Trick:**
For $M$ men and $W$ women around a circular table with no two women together ($W \le M$):
$$\text{Ways} = (M - 1)! \times {}^M\text{P}_W = (6 - 1)! \times {}^6\text{P}_5 = 5! \times 6! = 6! \times 5!$$

---

### Q8
**Question:**
The number of ways in which four distinct letters of the word 'MATHEMATICS' can be arranged is:

**Options:**
- A) 1680
- B) 2454
- C) 192
- D) 136
- E) None of these

**Correct Answer:** A) 1680

**Detailed Mathematical Explanation:**
- Inspect the letters of `MATHEMATICS`:
  - Total letters = 11: M, A, T, H, E, M, A, T, I, C, S
  - Frequencies: M (2), A (2), T (2), H (1), E (1), I (1), C (1), S (1)
- The problem states: "four **distinct** letters of the word are arranged".
- Distinct characters available in the word:
  $$\text{Alphabet set} = \{M, A, T, H, E, I, C, S\}$$
  - Total distinct letters available ($n$) = 8.
- To form an arrangement of 4 distinct letters, we select and arrange 4 distinct letters from the 8 available letters:
  $${}^8\text{P}_4 = \frac{8!}{(8 - 4)!} = 8 \times 7 \times 6 \times 5$$
- Calculating the product:
  $$8 \times 7 = 56$$
  $$56 \times 6 = 336$$
  $$336 \times 5 = 1680$$

**Shortcut / Exam Trick:**
8 distinct letters chosen and arranged 4 at a time:
$${}^8\text{P}_4 = 8 \times 7 \times 6 \times 5 = 56 \times 30 = 1680$$

---

### Q9
**Question:**
The letters of the word 'ARTICLE' is arranged in different ways randomly. What is the chance that the vowels occupy the even places?

**Options:**
- A) 4/35
- B) 2/35
- C) 1/35
- D) 3/35

**Correct Answer:** C) 1/35

**Detailed Mathematical Explanation:**
- Inspect the word `ARTICLE`:
  - Total letters ($n$) = 7 (all 7 letters are distinct).
  - Vowels: {A, I, E} $\implies 3$ vowels.
  - Consonants: {R, T, C, L} $\implies 4$ consonants.
- In a 7-letter word, the positions are numbered $1, 2, 3, 4, 5, 6, 7$:
  - **Even positions:** {2, 4, 6} $\implies$ exactly 3 positions.
  - **Odd positions:** {1, 3, 5, 7} $\implies$ exactly 4 positions.
- **Total possible arrangements (Sample space $S$):**
  $$n(S) = 7! = 5040$$
- **Favorable arrangements ($E$):**
  - The 3 vowels must occupy the 3 even positions {2, 4, 6}:
    $$\text{Ways to arrange vowels} = 3! = 6$$
  - The remaining 4 consonants must occupy the 4 odd positions {1, 3, 5, 7}:
    $$\text{Ways to arrange consonants} = 4! = 24$$
  - Applying the multiplication principle:
    $$n(E) = 3! \times 4! = 6 \times 24 = 144$$
- **Probability of the event:**
  $$P(E) = \frac{n(E)}{n(S)} = \frac{3! \times 4!}{7!} = \frac{6 \times 24}{5040} = \frac{6}{7 \times 6 \times 5} = \frac{1}{35}$$

**Shortcut / Exam Trick:**
Direct factorial cancellation:
$$P(E) = \frac{3! \times 4!}{7!} = \frac{3!}{7 \times 6 \times 5} = \frac{6}{210} = \frac{1}{35}$$

---

### Q10
**Question:**
In how many different ways can the letters of the word "COUNTRY" be arranged in such a way that the vowels always come together?

**Options:**
- A) 2880
- B) 1440
- C) 5040
- D) 720
- E) None of these

**Correct Answer:** B) 1440

**Detailed Mathematical Explanation:**
- Inspect the word `COUNTRY`:
  - Total letters ($n$) = 7 (all letters are distinct).
  - Vowels: {O, U} $\implies 2$ vowels.
  - Consonants: {C, N, T, R, Y} $\implies 5$ consonants.
- Apply the **Block (Tie) Method**:
  - Group the 2 vowels as a single block: `[O, U]`.
  - Number of units to arrange: 5 consonants + 1 vowel unit = 6 units.
- **Step 1: Arrange the 6 units:**
  $$\text{Ways} = 6! = 720$$
- **Step 2: Arrange the vowels inside the block:**
  $$\text{Internal Ways} = 2! = 2$$
- **Step 3: Total arrangements:**
  $$\text{Total Ways} = 6! \times 2! = 720 \times 2 = 1440$$

**Shortcut / Exam Trick:**
$$\text{Ways} = (C + 1)! \times V! = 6! \times 2! = 720 \times 2 = 1440$$

---

### Q11
**Question:**
Find the value of ${}^{20}\text{C}_{17}$.

**Options:**
- A) 1260
- B) 1140
- C) 2580
- D) 3200

**Correct Answer:** B) 1140

**Detailed Mathematical Explanation:**
- Apply the symmetric property of combinations:
  $${}^n\text{C}_r = {}^n\text{C}_{n - r}$$
- Therefore:
  $${}^{20}\text{C}_{17} = {}^{20}\text{C}_{20 - 17} = {}^{20}\text{C}_3$$
- Expanding ${}^{20}\text{C}_3$:
  $${}^{20}\text{C}_3 = \frac{20 \times 19 \times 18}{3 \times 2 \times 1}$$
- Simplify terms:
  - $\frac{18}{3 \times 2} = \frac{18}{6} = 3$
  - Result: $20 \times 19 \times 3 = 60 \times 19 = 1140$

**Shortcut / Exam Trick:**
Never expand 17 factorial terms! Immediately convert ${}^{20}\text{C}_{17}$ to ${}^{20}\text{C}_3$:
$$\frac{20 \times 19 \times 18}{6} = 20 \times 19 \times 3 = 1140$$

---

### Q12
**Question:**
Out of 5 consonants and 4 vowels, how many words of 3 consonants and 2 vowels can be formed?

**Options:**
- A) 6000
- B) 1200
- C) 5230
- D) 7200

**Correct Answer:** D) 7200

**Detailed Mathematical Explanation:**
- This is a two-phase **Selection then Arrangement** problem:
- **Phase 1: Selection of Letters (Combinations):**
  - Choose 3 consonants out of 5 available:
    $${}^5\text{C}_3 = {}^5\text{C}_2 = \frac{5 \times 4}{2 \times 1} = 10\text{ ways}$$
  - Choose 2 vowels out of 4 available:
    $${}^4\text{C}_2 = \frac{4 \times 3}{2 \times 1} = 6\text{ ways}$$
  - Total combinations of chosen letters:
    $$\text{Selection Ways} = {}^5\text{C}_3 \times {}^4\text{C}_2 = 10 \times 6 = 60\text{ groups}$$
- **Phase 2: Arrangement into Words (Permutations):**
  - Each selected group contains $3 + 2 = 5$ distinct letters.
  - The 5 letters can be arranged among themselves to form distinct words in:
    $$5! = 120\text{ ways}$$
- **Total Words Formed:**
  $$\text{Total Words} = (\text{Selection Ways}) \times 5! = 60 \times 120 = 7200$$

**Shortcut / Exam Trick:**
$$({}^5\text{C}_3 \times {}^4\text{C}_2) \times 5! = 10 \times 6 \times 120 = 60 \times 120 = 7200$$

---

### Q13
**Question:**
A bag contains 2 white marbles, 3 black marbles and 4 red marbles. Find in how many ways, 3 marbles can be drawn, so that at least one black marble is included in each draw?

**Options:**
- A) 64
- B) 52
- C) 58
- D) 36

**Correct Answer:** A) 64

**Detailed Mathematical Explanation:**
- Total marbles in the bag:
  $$2\text{ white} + 3\text{ black} + 4\text{ red} = 9\text{ marbles}$$
- Total non-black marbles:
  $$2\text{ white} + 4\text{ red} = 6\text{ non-black marbles}$$
- We draw 3 marbles such that **at least one** black marble is included.
- **Method 1: Complementary Counting (Fastest & Standard)**
  - Total unrestricted ways to draw any 3 marbles from 9:
    $$\text{Total Ways} = {}^9\text{C}_3 = \frac{9 \times 8 \times 7}{3 \times 2 \times 1} = 3 \times 4 \times 7 = 84$$
  - Unfavorable ways (drawing 3 marbles with **zero black marbles**, i.e., all 3 from the 6 non-black marbles):
    $$\text{Unfavorable Ways} = {}^6\text{C}_3 = \frac{6 \times 5 \times 4}{3 \times 2 \times 1} = 20$$
  - Favorable ways with at least one black marble:
    $$\text{Favorable Ways} = \text{Total Ways} - \text{Unfavorable Ways} = 84 - 20 = 64$$
- **Method 2: Direct Case Enumeration**
  - Case 1 (Exactly 1 black, 2 non-black):
    $${}^3\text{C}_1 \times {}^6\text{C}_2 = 3 \times 15 = 45$$
  - Case 2 (Exactly 2 black, 1 non-black):
    $${}^3\text{C}_2 \times {}^6\text{C}_1 = 3 \times 6 = 18$$
  - Case 3 (All 3 black, 0 non-black):
    $${}^3\text{C}_3 \times {}^6\text{C}_0 = 1 \times 1 = 1$$
  - Sum of mutually exclusive cases:
    $$\text{Total} = 45 + 18 + 1 = 64$$

**Shortcut / Exam Trick:**
Whenever a problem asks for "at least one", always compute:
$$\text{Total} - \text{None} = {}^9\text{C}_3 - {}^6\text{C}_3 = 84 - 20 = 64$$

---

### Q14
**Question:**
In how many ways can a group of 5 people be chosen from 6 boys and 4 girls so as to include exactly one girl?

**Options:**
- A) 126
- B) 210
- C) 90
- D) 252
- E) 60

**Correct Answer:** E) 60

**Detailed Mathematical Explanation:**
- Pool of available candidates:
  - Boys = 6
  - Girls = 4
- We must select a group of 5 people such that the group contains **exactly 1 girl**.
- Since the group size is 5 and exactly 1 person is a girl, the remaining $5 - 1 = 4$ persons must be boys.
- **Step 1: Choose 1 girl from 4 girls:**
  $${}^4\text{C}_1 = 4\text{ ways}$$
- **Step 2: Choose 4 boys from 6 boys:**
  $${}^6\text{C}_4 = {}^6\text{C}_2 = \frac{6 \times 5}{2 \times 1} = 15\text{ ways}$$
- **Step 3: Combine selections (Multiplication Principle):**
  $$\text{Total Ways} = {}^4\text{C}_1 \times {}^6\text{C}_4 = 4 \times 15 = 60$$

**Shortcut / Exam Trick:**
$$\text{Ways} = {}^4\text{C}_1 \times {}^6\text{C}_4 = 4 \times 15 = 60$$

---

### Q15
**Question:**
From a group of 6 men and 4 women, a Committee of 4 persons is to be formed. In how many different ways can it be done, so that the committee has at least 2 men?

**Options:**
- A) 195
- B) 225
- C) 185
- D) 210
- E) None of these

**Correct Answer:** C) 185

**Detailed Mathematical Explanation:**
- Available group: 6 men and 4 women (total 10 persons).
- Committee size = 4 persons.
- Condition: The committee must have **at least 2 men**.
- Possible valid compositions of the committee:
  - **Case 1: Exactly 2 men and 2 women**
    $${}^6\text{C}_2 \times {}^4\text{C}_2 = 15 \times 6 = 90\text{ ways}$$
  - **Case 2: Exactly 3 men and 1 woman**
    $${}^6\text{C}_3 \times {}^4\text{C}_1 = 20 \times 4 = 80\text{ ways}$$
  - **Case 3: Exactly 4 men and 0 women**
    $${}^6\text{C}_4 \times {}^4\text{C}_0 = 15 \times 1 = 15\text{ ways}$$
- Summing the mutually exclusive cases:
  $$\text{Total Ways} = 90 + 80 + 15 = 185$$

- **Alternative (Complementary Counting):**
  - Total ways to form any 4-person committee:
    $${}^{10}\text{C}_4 = \frac{10 \times 9 \times 8 \times 7}{4 \times 3 \times 2 \times 1} = 210$$
  - Committees with 0 men (4 women):
    $${}^6\text{C}_0 \times {}^4\text{C}_4 = 1 \times 1 = 1$$
  - Committees with 1 man (1 man and 3 women):
    $${}^6\text{C}_1 \times {}^4\text{C}_3 = 6 \times 4 = 24$$
  - Favorable ways:
    $$210 - (1 + 24) = 210 - 25 = 185$$

**Shortcut / Exam Trick:**
Complementary subtraction is ultra-fast:
$$\text{Total} - (0\text{ men} + 1\text{ man}) = 210 - (1 + 24) = 185$$

---

### Q16
**Question:**
In a party every person shakes hand with every other person. If there was a total of 210 handshakes in a party, find the number of persons who were present in the party?

**Options:**
- A) 19
- B) 21
- C) 20
- D) 40
- E) None of these

**Correct Answer:** B) 21

**Detailed Mathematical Explanation:**
- Let $n$ be the total number of persons present at the party.
- A handshake requires a pair of 2 distinct people.
- The total number of handshakes is the number of ways to choose 2 people out of $n$:
  $$\text{Total Handshakes} = {}^n\text{C}_2 = \frac{n(n - 1)}{2}$$
- Given that the total handshakes = 210:
  $$\frac{n(n - 1)}{2} = 210$$
  $$n(n - 1) = 420$$
- Forming the quadratic equation:
  $$n^2 - n - 420 = 0$$
  $$(n - 21)(n + 20) = 0$$
- Since $n$ must be a positive integer:
  $$n = 21$$

**Shortcut / Exam Trick:**
Notice that $n(n - 1) = 420$. Since $\sqrt{420} \approx 20.5$, test consecutive integers around 20:
$$21 \times 20 = 420 \implies n = 21$$

---

### Q17
**Question:**
The number of ways in which a team of eleven players can be selected from 22 players including 2 of them and excluding 4 of them is:

**Options:**
- A) ${}^{16}\text{C}_9$
- B) ${}^{16}\text{C}_5$
- C) ${}^{20}\text{C}_9$
- D) ${}^{16}\text{C}_{11}$
- E) None of these

**Correct Answer:** A) ${}^{16}\text{C}_9$

**Detailed Mathematical Explanation:**
- Total initial players ($n$) = 22.
- Team size to be selected ($r$) = 11.
- **Condition 1 (Mandatory Inclusion):**
  - 2 specific players are **always included** in the team.
  - Hence, these 2 slots are already fixed.
  - Remaining slots to fill = $11 - 2 = 9$.
- **Condition 2 (Mandatory Exclusion):**
  - 4 specific players are **always excluded** (ineligible / left out).
- **Available Pool Calculation:**
  - Out of 22 players, 2 are selected and 4 are excluded:
    $$\text{Remaining available pool} = 22 - 2 - 4 = 16\text{ players}$$
- **Final Selection:**
  - We must select the remaining 9 players from the remaining pool of 16 eligible players:
    $$\text{Number of Ways} = {}^{16}\text{C}_9$$

**Shortcut / Exam Trick:**
Standard restricted selection formula:
$${}^{n - p - q}\text{C}_{r - p} = {}^{22 - 2 - 4}\text{C}_{11 - 2} = {}^{16}\text{C}_9$$

---

### Q18
**Question:**
From amongst 36 teachers in a school, one principal and one vice-principal are to be appointed. In how many ways can this be done?

**Options:**
- A) 1240
- B) 1250
- C) 1800
- D) 1260
- E) None of these

**Correct Answer:** D) 1260

**Detailed Mathematical Explanation:**
- Total available teachers = 36.
- Two distinct administrative posts need to be appointed: Principal and Vice-Principal.
- Because the roles are distinct (Principal $\neq$ Vice-Principal), **order matters**:
  - Number of choices for Principal = 36.
  - Once the Principal is appointed, the Vice-Principal must be chosen from the remaining 35 teachers.
  - Number of choices for Vice-Principal = 35.
- By the Fundamental Principle of Multiplication:
  $$\text{Total Ways} = 36 \times 35$$
- Calculating the product:
  $$36 \times 35 = 36 \times \frac{70}{2} = 18 \times 70 = 1260$$
- Alternatively, via permutations:
  $${}^{36}\text{P}_2 = \frac{36!}{(36 - 2)!} = 36 \times 35 = 1260$$

**Shortcut / Exam Trick:**
$${}^{36}\text{P}_2 = 36 \times 35 = 18 \times 70 = 1260$$

---

### Q19
**Question:**
A committee should consist of 5 Professors, 6 Teachers and 3 Readers. Find the number of ways to form a committee that consists of 2 Professors, 2 Teachers and 1 Reader?

**Options:**
- A) 55
- B) 225
- C) 90
- D) 450
- E) None of these

**Correct Answer:** D) 450

**Detailed Mathematical Explanation:**
- Available candidate pools:
  - Professors = 5
  - Teachers = 6
  - Readers = 3
- Required committee composition:
  - 2 Professors from 5
  - 2 Teachers from 6
  - 1 Reader from 3
- Evaluate each independent combination:
  1. Choosing 2 Professors from 5:
     $${}^5\text{C}_2 = \frac{5 \times 4}{2 \times 1} = 10$$
  2. Choosing 2 Teachers from 6:
     $${}^6\text{C}_2 = \frac{6 \times 5}{2 \times 1} = 15$$
  3. Choosing 1 Reader from 3:
     $${}^3\text{C}_1 = 3$$
- Applying the Fundamental Principle of Multiplication:
  $$\text{Total Ways} = {}^5\text{C}_2 \times {}^6\text{C}_2 \times {}^3\text{C}_1 = 10 \times 15 \times 3 = 150 \times 3 = 450$$

**Shortcut / Exam Trick:**
$$10 \times 15 \times 3 = 450$$

---

### Q20
**Question:**
A student is to answer 10 out of 13 questions in an examination such that he must choose at least 4 from the first five questions. The number of choices available to him is:

**Options:**
- A) 196
- B) 280
- C) 346
- D) 140
- E) None of these

**Correct Answer:** A) 196

**Detailed Mathematical Explanation:**
- Total questions in examination = 13.
- Split the 13 questions into two distinct sections:
  - **Section A (First five questions):** 5 questions.
  - **Section B (Remaining questions):** $13 - 5 = 8$ questions.
- The student must answer a total of 10 questions, with the constraint:
  $$\text{Questions chosen from Section A} \ge 4$$
- Since Section A contains only 5 questions, the student can choose either 4 or 5 questions from Section A:
  - **Case 1: 4 questions from Section A and 6 questions from Section B**
    - From Section A: ${}^5\text{C}_4 = 5$
    - From Section B: ${}^8\text{C}_6 = {}^8\text{C}_2 = \frac{8 \times 7}{2 \times 1} = 28$
    - Ways for Case 1: $5 \times 28 = 140$
  - **Case 2: 5 questions from Section A and 5 questions from Section B**
    - From Section A: ${}^5\text{C}_5 = 1$
    - From Section B: ${}^8\text{C}_5 = {}^8\text{C}_3 = \frac{8 \times 7 \times 6}{3 \times 2 \times 1} = 56$
    - Ways for Case 2: $1 \times 56 = 56$
- Summing the mutually exclusive cases:
  $$\text{Total Choices} = 140 + 56 = 196$$

**Shortcut / Exam Trick:**
$$\text{Case 1} + \text{Case 2} = ({}^5\text{C}_4 \times {}^8\text{C}_2) + ({}^5\text{C}_5 \times {}^8\text{C}_3) = (5 \times 28) + (1 \times 56) = 140 + 56 = 196$$

---

### Q21
**Question:**
In how many different ways can the letters of the word CORPORATION be arranged?

**Options:**
- A) 831600
- B) 1663200
- C) 415800
- D) 3326400
- E) 207900

**Correct Answer:** D) 3326400

**Detailed Mathematical Explanation:**
- Inspect the word `CORPORATION`:
  - Total letters ($n$) = 11
- Determine letter frequencies:
  - `C`: 1
  - `O`: 3 (repeats 3 times)
  - `R`: 2 (repeats 2 times)
  - `P`: 1
  - `A`: 1
  - `T`: 1
  - `I`: 1
  - `N`: 1
- Apply the multiset permutation formula:
  $$\text{Total Arrangements} = \frac{n!}{p_1! \times p_2!} = \frac{11!}{3! \times 2!}$$
- Expanding the factorials:
  $$11! = 39,916,800$$
  $$3! \times 2! = 6 \times 2 = 12$$
- Dividing:
  $$\text{Total Arrangements} = \frac{39,916,800}{12} = 3,326,400$$

**Shortcut / Exam Trick:**
$$\frac{11 \times 10 \times 9 \times 8 \times 7 \times 6!}{12} = \frac{11 \times 10 \times 9 \times 8 \times 7 \times 720}{12} = 11 \times 10 \times 9 \times 8 \times 7 \times 60 = 3,326,400$$

---

### Q22
**Question:**
In how many ways can 7 persons be seated at a round table if 2 particular persons must not sit next to each other?

**Options:**
- A) 480
- B) 240
- C) 720
- D) 5040
- E) None of these

**Correct Answer:** A) 480

**Detailed Mathematical Explanation:**
- Total persons ($n$) = 7.
- **Method 1: Complementary Counting (Subtraction Method)**
  - **Step 1: Total unrestricted circular arrangements of 7 persons:**
    $$\text{Total Ways} = (7 - 1)! = 6! = 720$$
  - **Step 2: Arrangements where the 2 particular persons SIT TOGETHER:**
    - Bundle the 2 particular persons into 1 single unit: `[P_1, P_2]`.
    - Total units to seat around the table = 5 other persons + 1 unit = 6 units.
    - Seating 6 units in a circle:
      $$(6 - 1)! = 5! = 120$$
    - Arranging the 2 persons internally within the unit:
      $$2! = 2$$
    - Arrangements where they sit together:
      $$120 \times 2 = 240$$
  - **Step 3: Arrangements where they DO NOT sit together:**
    $$\text{Favorable Ways} = \text{Total} - \text{Together} = 720 - 240 = 480$$
- **Method 2: Gap Method in a Circle**
  - First, seat the other 5 persons around the round table:
    $$(5 - 1)! = 4! = 24\text{ ways}$$
  - The 5 seated persons create 5 distinct gaps around the table.
  - The 2 particular persons must be placed into any 2 of these 5 gaps:
    $${}^5\text{P}_2 = 5 \times 4 = 20\text{ ways}$$
  - Total ways:
    $$24 \times 20 = 480$$

**Shortcut / Exam Trick:**
$$\text{Together} = 2! \times 5! = 240 \implies \text{Separated} = 6! - 240 = 720 - 240 = 480$$

---

### Q23
**Question:**
There are 4 candidates for the post of a lecturer in Mathematics and one is to be selected by votes of 5 men. The number of ways in which the votes can be given is:

**Options:**
- A) 1024
- B) 512
- C) 1029
- D) 1224
- E) None of these

**Correct Answer:** A) 1024

**Detailed Mathematical Explanation:**
- We have 5 voters (men) and 4 candidates.
- Each of the 5 men must cast a vote for one of the 4 candidates.
- For each voter, there are independently 4 candidate choices available:
  - Voter 1 has 4 choices.
  - Voter 2 has 4 choices.
  - Voter 3 has 4 choices.
  - Voter 4 has 4 choices.
  - Voter 5 has 4 choices.
- Applying the Fundamental Principle of Multiplication:
  $$\text{Total Ways} = 4 \times 4 \times 4 \times 4 \times 4 = 4^5$$
- Evaluating $4^5$:
  $$4^5 = (2^2)^5 = 2^{10} = 1024$$

**Shortcut / Exam Trick:**
Rule: $\text{Number of Ways} = (\text{Number of Choices})^{(\text{Number of Decision Makers})} = 4^5 = 1024$.
*(Never confuse base and exponent: voters make the choices, so candidate count is the base).*

---

### Q24
**Question:**
In how many different ways can 4 boys and 3 girls be arranged in a row such that all boys stand together and all the girls stand together?

**Options:**
- A) 288
- B) 576
- C) 24
- D) 75
- E) None of these

**Correct Answer:** A) 288

**Detailed Mathematical Explanation:**
- Given: 4 boys and 3 girls.
- Constraints:
  - All 4 boys must stand together $\implies$ form a Boys Block: `[B_1, B_2, B_3, B_4]`.
  - All 3 girls must stand together $\implies$ form a Girls Block: `[G_1, G_2, G_3]`.
- **Step 1: Arrange the 2 blocks:**
  - The two blocks can be arranged in a line (Boys then Girls, OR Girls then Boys):
    $$2! = 2\text{ ways}$$
- **Step 2: Internal arrangement of boys:**
  - The 4 boys can arrange among themselves within their block in:
    $$4! = 24\text{ ways}$$
- **Step 3: Internal arrangement of girls:**
  - The 3 girls can arrange among themselves within their block in:
    $$3! = 6\text{ ways}$$
- **Step 4: Total arrangements:**
  $$\text{Total Ways} = 2! \times 4! \times 3! = 2 \times 24 \times 6 = 2 \times 144 = 288$$

**Shortcut / Exam Trick:**
$$2! \times 4! \times 3! = 2 \times 24 \times 6 = 288$$

---

### Q25
**Question:**
In how many different ways can the letters of the word “DETAIL” be arranged in such a way that the vowels occupy only the odd positions?

**Options:**
- A) 32
- B) 48
- C) 36
- D) 60

**Correct Answer:** C) 36

**Detailed Mathematical Explanation:**
- Inspect the word `DETAIL`:
  - Total letters ($n$) = 6 (all letters distinct: D, E, T, A, I, L).
  - Vowels: {E, A, I} $\implies 3$ vowels.
  - Consonants: {D, T, L} $\implies 3$ consonants.
- The 6 positions in the word are numbered:
  $$\text{Position 1, Position 2, Position 3, Position 4, Position 5, Position 6}$$
- **Odd positions:** Positions 1, 3, 5 (total 3 odd slots).
- **Even positions:** Positions 2, 4, 6 (total 3 even slots).
- **Condition:** Vowels must occupy ONLY the odd positions.
  - Number of ways to place 3 distinct vowels into the 3 odd positions:
    $${}^3\text{P}_3 = 3! = 6\text{ ways}$$
- After placing vowels in the odd positions, the 3 consonants must occupy the remaining 3 even positions:
  - Number of ways to place 3 distinct consonants into the 3 even positions:
    $${}^3\text{P}_3 = 3! = 6\text{ ways}$$
- Applying the Multiplication Principle:
  $$\text{Total Ways} = 3! \times 3! = 6 \times 6 = 36$$

**Shortcut / Exam Trick:**
$$3! \times 3! = 6 \times 6 = 36$$

---

### Q26
**Question:**
How many ways can the word “COMPUTER” be arranged such that no two vowels come together?

**Options:**
- A) ${}^5\text{P}_2 \times 4!$
- B) ${}^6\text{P}_3 \times 5!$
- C) $\frac{{}^5\text{P}_2 \times 4!}{2!}$
- D) $\frac{{}^6\text{P}_3 \times 5!}{3!}$

**Correct Answer:** B) ${}^6\text{P}_3 \times 5!$

**Detailed Mathematical Explanation:**
- Inspect the letters in `COMPUTER`:
  - Total letters ($n$) = 8 (all 8 letters are distinct).
  - Vowels: {O, U, E} $\implies 3$ vowels.
  - Consonants: {C, M, P, T, R} $\implies 5$ consonants.
- Condition: "No two vowels come together" $\implies$ apply the **Gap Method**:
- **Step 1: Arrange the unrestricted letters (5 consonants):**
  - The 5 distinct consonants can be arranged in a line in:
    $$5! = 120\text{ ways}$$
- **Step 2: Identify the gaps between consonants:**
  - In a line of 5 consonants, the available gaps are at the ends and between letters:
    $$\_ \, C_1 \, \_ \, C_2 \, \_ \, C_3 \, \_ \, C_4 \, \_ \, C_5 \, \_$$
  - Total number of gaps = $5 + 1 = 6$ gaps.
- **Step 3: Place the 3 distinct vowels into the 6 gaps:**
  - To ensure no two vowels are adjacent, at most one vowel can occupy any gap:
    $$\text{Ways to place vowels} = {}^6\text{P}_3 = \frac{6!}{(6 - 3)!} = 6 \times 5 \times 4 = 120\text{ ways}$$
- **Step 4: Combine arrangements:**
  $$\text{Total Ways} = {}^6\text{P}_3 \times 5! = 120 \times 120 = 14,400$$

**Shortcut / Exam Trick:**
In linear arrangements with separated vowels:
$$\text{Ways} = {}^{C + 1}\text{P}_V \times C! = {}^{5 + 1}\text{P}_3 \times 5! = {}^6\text{P}_3 \times 5!$$

---

### Q27
**Question:**
How many numbers of squares are there in a chess board?

**Options:**
- A) 122
- B) 120
- C) 204
- D) 206

**Correct Answer:** C) 204

**Detailed Mathematical Explanation:**
- A standard chessboard consists of an $8 \times 8$ grid of unit squares.
- Squares of varying dimensions exist on this board:
  - $1 \times 1$ squares: $8 \times 8 = 64 = 8^2$
  - $2 \times 2$ squares: $7 \times 7 = 49 = 7^2$
  - $3 \times 3$ squares: $6 \times 6 = 36 = 6^2$
  - $4 \times 4$ squares: $5 \times 5 = 25 = 5^2$
  - $5 \times 5$ squares: $4 \times 4 = 16 = 4^2$
  - $6 \times 6$ squares: $3 \times 3 = 9 = 3^2$
  - $7 \times 7$ squares: $2 \times 2 = 4 = 2^2$
  - $8 \times 8$ squares: $1 \times 1 = 1 = 1^2$
- Summing the number of squares of all sizes:
  $$\text{Total Squares} = \sum_{k=1}^{8} k^2 = 1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2$$
- Applying the sum of squares of first $n$ natural numbers formula:
  $$\sum_{k=1}^{n} k^2 = \frac{n(n + 1)(2n + 1)}{6}$$
- Substituting $n = 8$:
  $$\text{Total Squares} = \frac{8 \times (8 + 1) \times (2 \times 8 + 1)}{6} = \frac{8 \times 9 \times 17}{6}$$
- Simplifying:
  $$\frac{8 \times 9 \times 17}{6} = \frac{72 \times 17}{6} = 12 \times 17 = 204$$

**Shortcut / Exam Trick:**
Direct formula: $\frac{8 \times 9 \times 17}{6} = 12 \times 17 = 204$.

---

### Q28
**Question:**
How many 3-digit numbers can be formed from the digits 2, 3, 5, 6, 7 and 9, which are divisible by 5 and none of the digits is repeated?

**Options:**
- A) 5
- B) 10
- C) 15
- D) 20

**Correct Answer:** D) 20

**Detailed Mathematical Explanation:**
- Available set of digits:
  $$D = \{2, 3, 5, 6, 7, 9\} \implies 6\text{ distinct digits (no 0 present)}$$
- We must construct a 3-digit number:
  $$\underline{\text{Hundreds}} \quad \underline{\text{Tens}} \quad \underline{\text{Units}}$$
- **Condition 1 (Divisibility by 5):**
  - A number is divisible by 5 if and only if its units digit is 0 or 5.
  - Since 0 is not in the set $D$, the units digit **must be 5**.
  - Choices for the units place = **1 choice** (digit 5).
- **Condition 2 (No repetition of digits):**
  - The digit 5 is now fixed in the units position.
  - Remaining available digits for hundreds and tens places:
    $$\{2, 3, 6, 7, 9\} \implies 5\text{ digits remaining}$$
- **Filling Hundreds and Tens places:**
  - Hundreds place: Any of the 5 remaining digits $\implies$ **5 choices**.
  - Tens place: Any of the 4 remaining digits $\implies$ **4 choices**.
- **Applying the Fundamental Principle of Multiplication:**
  $$\text{Total 3-digit Numbers} = 5 \times 4 \times 1 = 20$$

**Shortcut / Exam Trick:**
Fix units digit as 5 (1 way). Remaining 2 slots filled from 5 digits without repetition:
$${}^5\text{P}_2 = 5 \times 4 = 20$$

---

### Q29
**Question:**
There are five coloured balls in a pool. All balls are of different colours. In how many ways can we choose four pool balls?

**Options:**
- A) 70
- B) 80
- C) 60
- D) 90

**Correct Answer:** A) 70

**Detailed Mathematical Explanation:**
- In standard combinatorial curriculum and this specific aptitude problem, this problem evaluates **combinations with repetition** (multiset combinations / choosing with replacement from categories):
  - Number of distinct color categories ($n$) = 5.
  - Number of balls to choose ($r$) = 4.
  - Selection allows choosing balls of the same color repeatedly from the pool.
- **The Combinations with Repetition Formula:**
  $$\text{Ways} = {}^{n + r - 1}\text{C}_r = \binom{n + r - 1}{r}$$
- Substituting $n = 5$ and $r = 4$:
  $$\text{Ways} = {}^{5 + 4 - 1}\text{C}_4 = {}^8\text{C}_4$$
- Expanding ${}^8\text{C}_4$:
  $${}^8\text{C}_4 = \frac{8 \times 7 \times 6 \times 5}{4 \times 3 \times 2 \times 1}$$
- Simplifying:
  $${}^8\text{C}_4 = \frac{1680}{24} = 70$$

*(Note on simple selection without repetition: If balls were selected without repetition from exactly 5 balls, the selection would simply be ${}^5\text{C}_4 = 5$. Since the available options are 70, 80, 60, and 90, the problem strictly tests the multiset combinations with repetition formula ${}^{n+r-1}\text{C}_r = 70$.)*

**Shortcut / Exam Trick:**
Whenever options exceed $n$, it is selection with repetition (Stars & Bars):
$${}^{n+r-1}\text{C}_r = {}^{5+4-1}\text{C}_4 = {}^8\text{C}_4 = 70$$

---

### Q30
**Question:**
In how many ways can a necklace with 8 beads of different colors be made?

**Options:**
- A) 5,040
- B) 2,880
- C) 2,520
- D) 1,440

**Correct Answer:** C) 2,520

**Detailed Mathematical Explanation:**
- Number of beads ($n$) = 8 (all of distinct colors).
- A necklace is a closed circular loop.
- **Key Geometric Principle (Flip Invariance):**
  - In a standard round-table seating of people, facing the center establishes a distinct left-hand side and right-hand side, making clockwise and counter-clockwise arrangements distinguishable $\implies (n - 1)!$.
  - In a necklace or garland, there is no assigned front or back; the entire necklace can be flipped over (inverted in 3D space).
  - Flipping turns a clockwise arrangement into a counter-clockwise arrangement, making them visually and physically indistinguishable.
- **Formula for Necklaces / Garlands:**
  $$\text{Arrangements} = \frac{(n - 1)!}{2}$$
- Substituting $n = 8$:
  $$\text{Arrangements} = \frac{(8 - 1)!}{2} = \frac{7!}{2}$$
- Expanding $7!$:
  $$7! = 7 \times 6 \times 5 \times 4 \times 3 \times 2 \times 1 = 5,040$$
- Dividing by 2:
  $$\text{Arrangements} = \frac{5,040}{2} = 2,520$$

**Shortcut / Exam Trick:**
Necklace / Garland rule: Halve the circular permutation:
$$\frac{(n - 1)!}{2} = \frac{7!}{2} = \frac{5040}{2} = 2520$$

---

### Q31
**Question:**
In how many different ways can the letters of the word 'MATHEMATICS' be arranged such that all the vowels never come together?

**Options:**
- A) 4,838,400
- B) 4,868,640
- C) 4,989,600
- D) 4,717,440

**Correct Answer:** B) 4,868,640

**Detailed Mathematical Explanation:**
- Inspect the word `MATHEMATICS`:
  - Total letters ($n$) = 11.
  - Frequencies: M: 2, A: 2, T: 2, H: 1, E: 1, I: 1, C: 1, S: 1.
  - Vowels: {A, E, A, I} $\implies$ total 4 vowels (with A repeating 2 times).
  - Consonants: {M, T, H, M, T, C, S} $\implies$ total 7 consonants (with M repeating 2 times, T repeating 2 times).
- Apply **Complementary Counting**:
  $$\text{Vowels Never Together} = \text{Total Arrangements} - \text{Vowels All Together}$$
- **Step 1: Total Unrestricted Arrangements:**
  $$\text{Total} = \frac{11!}{2! \times 2! \times 2!} = \frac{39,916,800}{8} = 4,989,600$$
- **Step 2: Arrangements where all Vowels are Together:**
  - Treat the 4 vowels as a single composite unit: `[A, E, A, I]`.
  - Number of items to arrange = 7 consonants + 1 vowel block = 8 units.
  - Among the 7 consonants, M repeats 2 times and T repeats 2 times:
    $$\text{External Arrangements} = \frac{8!}{2! \times 2!} = \frac{40,320}{4} = 10,080$$
  - Inside the vowel block, 4 vowels (with A repeating 2 times) can arrange internally in:
    $$\text{Internal Arrangements} = \frac{4!}{2!} = \frac{24}{2} = 12$$
  - Arrangements with vowels together:
    $$\text{Together} = 10,080 \times 12 = 120,960$$
- **Step 3: Vowels Never Together:**
  $$\text{Never Together} = 4,989,600 - 120,960 = 4,868,640$$

**Shortcut / Exam Trick:**
$$\text{Total} - \text{Together} = \frac{11!}{8} - \left(\frac{8!}{4} \times \frac{4!}{2}\right) = 4,989,600 - 120,960 = 4,868,640$$

---

### Q32
**Question:**
How many 3-digit numbers can be formed using the digits 0, 1, 2, 3, 4, and 5 without repetition?

**Options:**
- A) 120
- B) 150
- C) 100
- D) 180

**Correct Answer:** C) 100

**Detailed Mathematical Explanation:**
- Given digits: $\{0, 1, 2, 3, 4, 5\}$ (total 6 digits, including 0).
- We must form a 3-digit number:
  $$\underline{\text{Hundreds}} \quad \underline{\text{Tens}} \quad \underline{\text{Units}}$$
- **Constraint on the Hundreds Digit:**
  - A 3-digit number cannot have 0 in the hundreds place (otherwise it becomes a 2-digit number).
  - Eligible digits for hundreds place: $\{1, 2, 3, 4, 5\} \implies$ **5 choices**.
- **Constraint on the Tens Digit:**
  - Zero is now eligible.
  - Out of 6 total digits, 1 digit has been used in the hundreds place.
  - Eligible digits remaining for tens place: $6 - 1 = $ **5 choices**.
- **Constraint on the Units Digit:**
  - Two digits have now been used.
  - Eligible digits remaining for units place: $6 - 2 = $ **4 choices**.
- Applying the Fundamental Principle of Multiplication:
  $$\text{Total 3-digit Numbers} = 5 \times 5 \times 4 = 100$$

**Shortcut / Exam Trick:**
Slot method:
$$\text{Hundreds} \times \text{Tens} \times \text{Units} = 5 \times 5 \times 4 = 100$$
*(Never forget: Hundreds slot cannot take 0, but Tens slot CAN take 0).*

---

### Q33
**Question:**
How many diagonals can be drawn in a regular decagon (a polygon with 10 sides)?

**Options:**
- A) 45
- B) 35
- C) 40
- D) 30

**Correct Answer:** B) 35

**Detailed Mathematical Explanation:**
- A decagon has $n = 10$ vertices.
- **Understanding Diagonals:**
  - Any pair of two vertices chosen from the 10 vertices defines a line segment.
  - Total possible line segments connecting pairs of vertices:
    $${}^{10}\text{C}_2 = \frac{10 \times 9}{2 \times 1} = 45$$
  - These 45 segments include both the perimeter sides of the polygon and the internal diagonals.
  - A 10-sided polygon has exactly 10 perimeter sides.
- Therefore, the number of diagonals is:
  $$\text{Diagonals} = {}^{10}\text{C}_2 - 10 = 45 - 10 = 35$$
- **Algebraic Formula Verification:**
  $$\text{Diagonals} = \frac{n(n - 3)}{2} = \frac{10 \times (10 - 3)}{2} = \frac{10 \times 7}{2} = 35$$

**Shortcut / Exam Trick:**
Use $\frac{n(n - 3)}{2}$ directly:
$$\frac{10 \times 7}{2} = 35$$

---

### Q34
**Question:**
In how many ways can 5 distinct prizes be distributed among 4 boys when each boy is eligible to receive any number of prizes?

**Options:**
- A) 625
- B) 1024
- C) 256
- D) 120

**Correct Answer:** B) 1024

**Detailed Mathematical Explanation:**
- We have 5 distinct prizes: $P_1, P_2, P_3, P_4, P_5$.
- We have 4 boys: $B_1, B_2, B_3, B_4$.
- Each prize must be awarded to one of the 4 boys.
- For each prize, there are independently 4 possible recipient choices:
  - Prize 1 can go to any of the 4 boys $\implies 4$ ways.
  - Prize 2 can go to any of the 4 boys $\implies 4$ ways.
  - Prize 3 can go to any of the 4 boys $\implies 4$ ways.
  - Prize 4 can go to any of the 4 boys $\implies 4$ ways.
  - Prize 5 can go to any of the 4 boys $\implies 4$ ways.
- Applying the Fundamental Principle of Multiplication:
  $$\text{Total Distribution Ways} = 4 \times 4 \times 4 \times 4 \times 4 = 4^5$$
- Evaluating $4^5$:
  $$4^5 = 1024$$

**Shortcut / Exam Trick:**
Remember the decision rule:
$$\text{Ways} = (\text{Number of Recipients})^{(\text{Number of Items})} = 4^5 = 1024$$

---

### Q35
**Question:**
Out of 7 consonants and 4 vowels, how many words of 3 consonants and 2 vowels can be formed such that the vowels are always together?

**Options:**
- A) 5,040
- B) 10,080
- C) 2,520
- D) 20,160

**Correct Answer:** B) 10,080

**Detailed Mathematical Explanation:**
- This combines **Sub-selection**, **Block Method**, and **Permutations**:
- **Step 1: Selection of Letters:**
  - Choose 3 consonants out of 7 available:
    $${}^7\text{C}_3 = \frac{7 \times 6 \times 5}{3 \times 2 \times 1} = 35\text{ ways}$$
  - Choose 2 vowels out of 4 available:
    $${}^4\text{C}_2 = \frac{4 \times 3}{2 \times 1} = 6\text{ ways}$$
  - Total combinations of chosen letters:
    $$\text{Selection Ways} = {}^7\text{C}_3 \times {}^4\text{C}_2 = 35 \times 6 = 210$$
- **Step 2: Arrangement with Vowels Always Together:**
  - Each selected set has 3 consonants and 2 vowels.
  - Bundle the 2 vowels into a single unit: `[V_1, V_2]`.
  - Entities to arrange: 3 consonants + 1 vowel block = 4 entities.
  - Arrange 4 entities:
    $$4! = 24\text{ ways}$$
  - Arrange the 2 vowels internally within the block:
    $$2! = 2\text{ ways}$$
  - Arrangements per selected set:
    $$4! \times 2! = 24 \times 2 = 48\text{ ways}$$
- **Step 3: Total Words Formed:**
  $$\text{Total Words} = (\text{Selection Ways}) \times (\text{Arrangements per set})$$
  $$\text{Total Words} = 210 \times 48 = 10,080$$

**Shortcut / Exam Trick:**
$$({}^7\text{C}_3 \times {}^4\text{C}_2) \times (4! \times 2!) = (35 \times 6) \times (24 \times 2) = 210 \times 48 = 10,080$$


---

## 4. Advanced Strategy & Common Traps to Avoid

### 1. Base vs. Exponent Confusion ($n^r$ vs. $r^n$)
- **The Golden Rule:** $\text{Total Ways} = (\text{Number of Choices available to each item})^{(\text{Number of Items making choices})}$.
- *Letters into Letterboxes:* Each letter has $B$ boxes to choose from $\implies B^L$.
- *Prizes to Boys:* Each prize has $N$ boys it can go to $\implies N^P$.
- *Voters to Candidates:* Each voter has $C$ candidates to choose $\implies C^V$.

### 2. Dividing Circular Permutations by 2
- Only divide $(n - 1)!$ by 2 when **clockwise and anticlockwise orientations are physically indistinguishable** (e.g., beads on a necklace, flowers on a garland, keys on a keyring that can be flipped upside down).
- For people seated at a round table, clockwise and counter-clockwise are **distinct** (a person sitting on your right is different from sitting on your left). Never divide by 2 for human seating unless explicitly stated that direction does not matter.

### 3. Gap Method on a Circle vs. Line
- In a **linear line** of $m$ objects, there are $m + 1$ gaps.
- In a **circular ring** of $m$ objects, there are exactly $m$ gaps.
- Example: Seating 6 men and 5 women such that no two women sit together:
  - Line: Seat 6 men ($6!$), create 7 gaps, place women (${}^7\text{P}_5$).
  - Circle: Seat 6 men ($(6 - 1)! = 5!$), create 6 gaps, place women (${}^6\text{P}_5 = 6!$).

### 4. Overcounting in Committee / Team Selections
- When selecting "at least 1 woman" for a 4-person committee from 5 men and 4 women:
  - **Wrong Method:** Choose 1 woman (${}^4\text{C}_1$), then choose any 3 people from the remaining 8 (${}^8\text{C}_3$). This grossly overcounts because the same committee can be chosen in multiple orders.
  - **Correct Method:** Always partition into disjoint cases:
    $$({}^4\text{C}_1 \times {}^5\text{C}_3) + ({}^4\text{C}_2 \times {}^5\text{C}_2) + ({}^4\text{C}_3 \times {}^5\text{C}_1) + ({}^4\text{C}_4 \times {}^5\text{C}_0)$$
    Or use Complementary Subtraction:
    $${}^9\text{C}_4 - {}^5\text{C}_4 = 126 - 5 = 121$$

### 5. Digits with Zero in Leading Position
- When forming an $n$-digit number from a set containing the digit 0, the leading (highest place-value) slot can never take 0.
- Always fill the leading slot first with the non-zero choices, and then allow 0 in the subsequent slots.
