# 06. Quadratic Equations

A comprehensive, self-contained reference guide covering fundamental principles, mathematical derivations, standard algebraic formulas, the 5-second Fast Sign Shortcut Method, two-variable comparison grids ($x$ vs $y$), and 30 fully solved competitive examination problems.

---

## 1. Comprehensive Theory and Formulas

### 1.1 Fundamental Concepts & Standard Form

A quadratic equation is a second-degree polynomial equation in a single variable $x$. Its canonical standard algebraic representation is:

$$ax^2 + bx + c = 0$$

Where:
- $a, b, c \in \mathbb{R}$ are constant numerical coefficients.
- $a \neq 0$ (if $a = 0$, the equation reduces to a first-degree linear equation $bx + c = 0$).
- $x$ represents the unknown variable whose values satisfy the equality.

#### Roots of a Quadratic Equation
The values of $x$ that satisfy $ax^2 + bx + c = 0$ are called the **roots** (or solutions, or zeros) of the quadratic equation. By the Fundamental Theorem of Algebra, a quadratic equation always has exactly two roots (which may be distinct real, equal real, or complex conjugate pairs).

---

### 1.2 The Quadratic Formula & Discriminant Analysis

#### 1. The Quadratic Formula (Sridharacharya's Rule)
For any general quadratic equation $ax^2 + bx + c = 0$ with $a \neq 0$, the two roots $\alpha$ and $\beta$ are given analytically by:

$$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

#### Derivation (Completing the Square):
1. Divide the entire equation by $a$:
   $$x^2 + \frac{b}{a}x + \frac{c}{a} = 0$$
2. Transpose the constant term $\frac{c}{a}$ to the right-hand side:
   $$x^2 + \frac{b}{a}x = -\frac{c}{a}$$
3. Add $\left(\frac{b}{2a}\right)^2 = \frac{b^2}{4a^2}$ to both sides to complete the square on the left-hand side:
   $$x^2 + 2 \cdot x \cdot \frac{b}{2a} + \left(\frac{b}{2a}\right)^2 = \frac{b^2}{4a^2} - \frac{c}{a}$$
   $$\left(x + \frac{b}{2a}\right)^2 = \frac{b^2 - 4ac}{4a^2}$$
4. Take the square root of both sides:
   $$x + \frac{b}{2a} = \frac{\pm \sqrt{b^2 - 4ac}}{2a}$$
5. Isolate $x$:
   $$x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}$$

---

#### 2. The Discriminant ($D$ or $\Delta$) and Nature of Roots
The quantity under the radical sign determines the mathematical character of the roots:

$$D = \Delta = b^2 - 4ac$$

| Value of Discriminant ($D$) | Nature of Roots | Graphical Significance (Parabola $y = ax^2+bx+c$) |
| :--- | :--- | :--- |
| **$D > 0$ and a perfect square** | Real, Rational, and Unequal (distinct) | Intersects $x$-axis at two distinct rational points |
| **$D > 0$ and NOT a perfect square** | Real, Irrational, and Unequal (occur in conjugate pairs $p \pm \sqrt{q}$) | Intersects $x$-axis at two distinct irrational points |
| **$D = 0$** | Real, Rational, and Equal (repeated root $\alpha = \beta = -\frac{b}{2a}$) | Touches $x$-axis at exactly one point (tangent at vertex) |
| **$D < 0$** | Non-real / Complex Conjugate pairs ($u \pm iv$) | Does NOT intersect $x$-axis (entirely above or below) |

---

### 1.3 Relations Between Roots and Coefficients (Vieta's Formulas)

Let $\alpha$ and $\beta$ be the roots of $ax^2 + bx + c = 0$.

1. **Sum of Roots ($S$):**
   $$\alpha + \beta = -\frac{b}{a}$$

2. **Product of Roots ($P$):**
   $$\alpha \cdot \beta = \frac{c}{a}$$

3. **Difference of Roots:**
   $$|\alpha - \beta| = \sqrt{(\alpha + \beta)^2 - 4\alpha\beta} = \frac{\sqrt{b^2 - 4ac}}{|a|} = \frac{\sqrt{D}}{|a|}$$

4. **Reconstructing a Quadratic Equation from Given Roots:**
   If $\alpha$ and $\beta$ are known roots:
   $$x^2 - (\alpha + \beta)x + (\alpha \cdot \beta) = 0$$
   $$\mathbf{x^2 - Sx + P = 0}$$
   Where $S = \text{Sum of roots}$ and $P = \text{Product of roots}$.

5. **Useful Algebraic Symmetric Identities:**
   - $\alpha^2 + \beta^2 = (\alpha + \beta)^2 - 2\alpha\beta = S^2 - 2P$
   - $\alpha^3 + \beta^3 = (\alpha + \beta)^3 - 3\alpha\beta(\alpha + \beta) = S^3 - 3PS$
   - $\frac{1}{\alpha} + \frac{1}{\beta} = \frac{\alpha + \beta}{\alpha\beta} = \frac{S}{P}$
   - $\frac{\alpha}{\beta} + \frac{\beta}{\alpha} = \frac{\alpha^2 + \beta^2}{\alpha\beta} = \frac{S^2 - 2P}{P}$

---

### 1.4 The Fast Sign Method (5-Second Root Finding Shortcut)

In competitive recruitment and aptitude examinations (Aditya University CRT, Banking, Placements), solving quadratics using the full quadratic formula is too slow. The **Fast Sign Method** determines the exact arithmetic signs of the roots instantly and splits the middle term in seconds without trial-and-error factoring.

#### Master Sign Table
Look at the signs of coefficients $b$ and $c$ in the standard form $ax^2 + bx + c = 0$:

| Case | Equation Sign Pattern ($b, c$) | Example Equation | Intermediate Factors Sign | **Final Roots Sign** |
| :---: | :---: | :---: | :---: | :---: |
| **1** | $(+, +)$ | $x^2 + 7x + 12 = 0$ | $(+, +) \to (+4, +3)$ | **$(-, -) \to (-4, -3)$** |
| **2** | $(-, +)$ | $x^2 - 7x + 12 = 0$ | $(-, -) \to (-4, -3)$ | **$(+, +) \to (+4, +3)$** |
| **3** | $(+, -)$ | $x^2 + 4x - 12 = 0$ | $(+, -) \to (+6, -2)$ | **$(-, +) \to (-6, +2)$** |
| **4** | $(-, -)$ | $x^2 - 4x - 12 = 0$ | $(-, +) \to (-6, +2)$ | **$(+, -) \to (+6, -2)$** |

#### Operational Mnemonic & Rule:
1. **Sign of $b$ always changes:** The leading factor flips the sign of $b$.
2. **Sign of $c$ controls the second factor:**
   - If $c$ is **positive (+)**: Both roots have the **same sign** (both $(-)$ if $b$ is $+$; both $(+)$ if $b$ is $-$).
   - If $c$ is **negative (-)**: The roots have **opposite signs** (one positive, one negative). The larger numerical factor takes the opposite sign of $b$, and the smaller factor takes the opposite sign of the larger factor.

#### 3-Step Execution:
1. **Multiply $a \times c$:** Find two factors $f_1, f_2$ ($f_1 \ge f_2$) whose product is $|a \cdot c|$ and whose sum (if $c > 0$) or difference (if $c < 0$) equals $|b|$.
2. **Assign Signs to $(f_1, f_2)$:** Apply the Master Sign Table above.
3. **Divide by $a$:** Divide both values by the leading coefficient $a$:
   $$\text{Roots} = \left( \frac{\text{Signed } f_1}{a}, \frac{\text{Signed } f_2}{a} \right)$$

---

### 1.5 Two-Variable Comparison ($x$ vs $y$)

In competitive aptitude tests, problems present two separate quadratic equations—Equation (I) in $x$ and Equation (II) in $y$—and ask candidates to determine the inequality relationship between all valid values of $x$ and $y$.

#### Standard Examination Options:
- **a) $x > y$:** Every root of $x$ is strictly greater than every root of $y$.
- **b) $x < y$:** Every root of $x$ is strictly less than every root of $y$.
- **c) $x \ge y$:** Every root of $x$ is greater than or equal to every root of $y$ (at least one equal pair, and no $x < y$).
- **d) $x \le y$:** Every root of $x$ is less than or equal to every root of $y$ (at least one equal pair, and no $x > y$).
- **e) $x = y$ or Relationship cannot be determined (CND):** The root ranges overlap, conflicting inequality signs appear ($>$ and $<$), or $x = y$ identically.

#### The 4-Cell Comparison Grid:
With two roots $x \in \{x_1, x_2\}$ and two roots $y \in \{y_1, y_2\}$, compare each of the 4 pairs:
1. Compare $x_1$ with $y_1$
2. Compare $x_1$ with $y_2$
3. Compare $x_2$ with $y_1$
4. Compare $x_2$ with $y_2$

| Outcomes across the 4 pairs | Valid Final Relationship | Correct Option |
| :--- | :--- | :---: |
| All 4 comparisons are $>$ | **$x > y$** | **a** |
| All 4 comparisons are $<$ | **$x < y$** | **b** |
| Outcomes consist of $>$ and $=$ only | **$x \ge y$** | **c** |
| Outcomes consist of $<$ and $=$ only | **$x \le y$** | **d** |
| Both $>$ and $<$ appear in the 4 pairs | **Relationship cannot be determined (CND)** | **e** |
| All 4 comparisons are $=$ | **$x = y$** | **e** |

---

### 1.6 Visual Inspection Rules (Zero-Calculation Shortcuts)

Certain quadratic pairs can be solved in **under 2 seconds** purely by inspecting the coefficient signs without calculating any roots:

#### Shortcut Rule 1: The Opposing Sign Rule
- If Equation (I) in $x$ has pattern $(-, +)$, its roots are **$(+, +)$**.
- If Equation (II) in $y$ has pattern $(+, +)$, its roots are **$(-, -)$**.
- **Conclusion:** Any positive number is strictly greater than any negative number. Therefore, **$x > y$ (Option a)** holds immediately!
- Conversely, if $x$ has $(+, +)$ [roots $(-,-)$] and $y$ has $(-, +)$ [roots $(+,+)$], then **$x < y$ (Option b)** holds immediately!

#### Shortcut Rule 2: Both Constant Terms Negative ($c_1 < 0$ and $c_2 < 0$)
- When the constant term $c$ is negative in both equations:
  - Roots of $x$ have opposite signs: one positive ($+x_1$), one negative ($-x_2$).
  - Roots of $y$ have opposite signs: one positive ($+y_1$), one negative ($-y_2$).
- Cross-comparison:
  - Positive $x_1 >$ negative $y_2$.
  - Negative $x_2 <$ positive $y_1$.
- Because both $>$ and $<$ inevitably occur, the relationship **CAN NEVER BE DETERMINED**.
- **Conclusion:** Mark **Option e (CND)** immediately without calculating roots!

#### Shortcut Rule 3: Equal Leading Coefficients ($a_1 = a_2$)
- When $a_1 = a_2$ (or both equations are monic $a=1$), skip the division step $\frac{f}{a}$. Compare the raw split factors directly to save 10-15 seconds.
- When $a_1 \neq a_2$, equalize them mentally by cross-multiplying the roots by the opposite coefficient rather than dealing with decimals or fractions:
  $$\text{Compare } (a_2 \cdot \text{raw } x) \quad \text{against} \quad (a_1 \cdot \text{raw } y)$$

#### Shortcut Rule 4: Square Root vs Quadratic Power
- **$x^2 = k$:** Produces **two roots**: $x = +\sqrt{k}$ and $x = -\sqrt{k}$.
- **$y = \sqrt{k}$:** The principal radical symbol denotes the non-negative square root only: $y = +\sqrt{k}$ (**single root**).
- **Comparison:**
  - When $x = \pm \sqrt{k}$ and $y = +\sqrt{k}$:
    - $+k^{1/2} = +k^{1/2}$ ($=$)
    - $-k^{1/2} < +k^{1/2}$ ($<$)
  - Relationship is **$x \le y$ (Option d)**.
- **$x^3 = k$ vs $y^2 = k^{2/3}$:**
  - $x^3 = k \implies x$ has a single real root with the same sign as $k$.
  - $y^2 = m \implies y = \pm \sqrt{m}$.

---

## 2. Comprehensive Question Bank (Q1 to Q30)

> **Standard Direction for Questions 1 to 30:**  
> In each of the following questions, two equations numbered I and II are given. You have to solve both equations and mark the correct option:  
> - **a) $x > y$**  
> - **b) $x < y$**  
> - **c) $x \ge y$**  
> - **d) $x \le y$**  
> - **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**  

---

### Q1
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 7x + 12 = 0$
- **II.** $y^2 - 9y + 20 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 7x + 12 = 0$
- Sign pattern of $(b, c)$ is $(-, +) \implies$ both roots are **positive $(+, +)$**.
- Find two numbers whose product is $12$ and sum is $7$: $4 \times 3 = 12$ and $4 + 3 = 7$.
- Factorization: $(x - 4)(x - 3) = 0$
- Roots for $x$: $x = 3, \, 4$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 9y + 20 = 0$
- Sign pattern of $(b, c)$ is $(-, +) \implies$ both roots are **positive $(+, +)$**.
- Find two numbers whose product is $20$ and sum is $9$: $5 \times 4 = 20$ and $5 + 4 = 9$.
- Factorization: $(y - 5)(y - 4) = 0$
- Roots for $y$: $y = 4, \, 5$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $3$ | $4$ | $3 < 4$ | **$x < y$** |
| $3$ | $5$ | $3 < 5$ | **$x < y$** |
| $4$ | $4$ | $4 = 4$ | **$x = y$** |
| $4$ | $5$ | $4 < 5$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- Both equations have sign pattern $(-, +)$, so all roots are positive. The factors of 12 are $(3, 4)$ and factors of 20 are $(4, 5)$. Since $x \in \{3, 4\}$ and $y \in \{4, 5\}$, $x$ is either strictly smaller than $y$ or equal to $y$ at $4$. Hence, $x \le y$ in under 10 seconds.

---

### Q2
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 11x + 30 = 0$
- **II.** $y^2 - 15y + 56 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **b) $x < y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 11x + 30 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Two factors of $30$ summing to $11$: $6$ and $5$.
- Factorization: $(x - 6)(x - 5) = 0$
- Roots for $x$: $x = 5, \, 6$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 15y + 56 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Two factors of $56$ summing to $15$: $8$ and $7$.
- Factorization: $(y - 8)(y - 7) = 0$
- Roots for $y$: $y = 7, \, 8$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $5$ | $7$ | $5 < 7$ | **$x < y$** |
| $5$ | $8$ | $5 < 8$ | **$x < y$** |
| $6$ | $7$ | $6 < 7$ | **$x < y$** |
| $6$ | $8$ | $6 < 8$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **b) $x < y$**.

##### Shortcut / 5-Second Exam Trick
- Roots of $x$ are $5, 6$. Roots of $y$ are $7, 8$. The maximum value of $x$ ($6$) is strictly less than the minimum value of $y$ ($7$). Therefore, every root of $x$ is strictly less than every root of $y$, yielding $x < y$ immediately.

---

### Q3
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 17x + 72 = 0$
- **II.** $y^2 - 11y + 30 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 17x + 72 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factors of $72$ that sum to $17$: $9 \times 8 = 72$ and $9 + 8 = 17$.
- Factorization: $(x - 9)(x - 8) = 0$
- Roots for $x$: $x = 8, \, 9$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 11y + 30 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factors of $30$ that sum to $11$: $6 \times 5 = 30$ and $6 + 5 = 11$.
- Factorization: $(y - 6)(y - 5) = 0$
- Roots for $y$: $y = 5, \, 6$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $8$ | $5$ | $8 > 5$ | **$x > y$** |
| $8$ | $6$ | $8 > 6$ | **$x > y$** |
| $9$ | $5$ | $9 > 5$ | **$x > y$** |
| $9$ | $6$ | $9 > 6$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- The minimum value of $x$ ($8$) is strictly greater than the maximum value of $y$ ($6$). Thus $x > y$ holds across all possible pairs without needing detailed grid calculation.

---

### Q4
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 + 9x + 20 = 0$
- **II.** $y^2 + 13y + 42 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 + 9x + 20 = 0$
- Sign pattern $(+, +) \implies$ both roots are **negative $(-, -)$**.
- Factors of $20$ summing to $9$: $5$ and $4$.
- Factorization: $(x + 5)(x + 4) = 0$
- Roots for $x$: $x = -5, \, -4$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 + 13y + 42 = 0$
- Sign pattern $(+, +) \implies$ both roots are **negative $(-, -)$**.
- Factors of $42$ summing to $13$: $7$ and $6$.
- Factorization: $(y + 7)(y + 6) = 0$
- Roots for $y$: $y = -7, \, -6$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-5$ | $-7$ | $-5 > -7$ | **$x > y$** |
| $-5$ | $-6$ | $-5 > -6$ | **$x > y$** |
| $-4$ | $-7$ | $-4 > -7$ | **$x > y$** |
| $-4$ | $-6$ | $-4 > -6$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- Remember for negative numbers: the smaller the magnitude, the greater the number. $x \in \{-5, -4\}$ while $y \in \{-7, -6\}$. Both $-5$ and $-4$ lie to the right of $-6$ and $-7$ on the number line. Thus, $x > y$.

---

### Q5
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 + 11x + 30 = 0$
- **II.** $y^2 + 7y + 12 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **b) $x < y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 + 11x + 30 = 0$
- Sign pattern $(+, +) \implies$ roots are **$(-, -)$**.
- Factors of $30$ summing to $11$: $6$ and $5$.
- Factorization: $(x + 6)(x + 5) = 0$
- Roots for $x$: $x = -6, \, -5$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 + 7y + 12 = 0$
- Sign pattern $(+, +) \implies$ roots are **$(-, -)$**.
- Factors of $12$ summing to $7$: $4$ and $3$.
- Factorization: $(y + 4)(y + 3) = 0$
- Roots for $y$: $y = -4, \, -3$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-6$ | $-4$ | $-6 < -4$ | **$x < y$** |
| $-6$ | $-3$ | $-6 < -3$ | **$x < y$** |
| $-5$ | $-4$ | $-5 < -4$ | **$x < y$** |
| $-5$ | $-3$ | $-5 < -3$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **b) $x < y$**.

##### Shortcut / 5-Second Exam Trick
- Here $x \in \{-6, -5\}$ and $y \in \{-4, -3\}$. The largest root of $x$ is $-5$, which is strictly less than the smallest root of $y$ ($-4$). Therefore, $x < y$ unconditionally.

---

### Q6
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 2x - 15 = 0$
- **II.** $y^2 - 4y - 21 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 2x - 15 = 0$
- Sign pattern $(-, -) \implies$ roots are **$(+, -)$**.
- Factors of $15$ with difference $2$: $5$ and $3$.
- Factorization: $(x - 5)(x + 3) = 0$
- Roots for $x$: $x = 5, \, -3$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 4y - 21 = 0$
- Sign pattern $(-, -) \implies$ roots are **$(+, -)$**.
- Factors of $21$ with difference $4$: $7$ and $3$.
- Factorization: $(y - 7)(y + 3) = 0$
- Roots for $y$: $y = 7, \, -3$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $5$ | $7$ | $5 < 7$ | **$x < y$** |
| $5$ | $-3$ | $5 > -3$ | **$x > y$** |
| $-3$ | $7$ | $-3 < 7$ | **$x < y$** |
| $-3$ | $-3$ | $-3 = -3$ | **$x = y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- Notice both constant terms are negative ($c_1 = -15 < 0$, $c_2 = -21 < 0$). By Shortcut Rule 2, whenever both constant terms are negative, both equations produce one positive and one negative root. Cross-comparison inevitably produces both $>$ and $<$, meaning relationship cannot be determined (CND). Mark Option e in 1 second!

---

### Q7
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 12x + 35 = 0$
- **II.** $y^2 + 10y + 21 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 12x + 35 = 0$
- Sign pattern $(-, +) \implies$ roots are **positive $(+, +)$**.
- Factors of $35$ summing to $12$: $7$ and $5$.
- Roots for $x$: $x = +5, \, +7$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 + 10y + 21 = 0$
- Sign pattern $(+, +) \implies$ roots are **negative $(-, -)$**.
- Factors of $21$ summing to $10$: $7$ and $3$.
- Roots for $y$: $y = -7, \, -3$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $+5$ | $-7$ | $+5 > -7$ | **$x > y$** |
| $+5$ | $-3$ | $+5 > -3$ | **$x > y$** |
| $+7$ | $-7$ | $+7 > -7$ | **$x > y$** |
| $+7$ | $-3$ | $+7 > -3$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- Visual Sign Rule: $x$ has pattern $(-, +) \implies (+, +)$. $y$ has pattern $(+, +) \implies (-, -)$. Any positive number is strictly greater than any negative number. Thus, $x > y$ without any arithmetic calculation whatsoever!

---

### Q8
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 + 12x + 35 = 0$
- **II.** $y^2 - 8y + 15 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **b) $x < y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 + 12x + 35 = 0$
- Sign pattern $(+, +) \implies$ roots are **negative $(-, -)$**.
- Factors of $35$ summing to $12$: $7$ and $5$.
- Roots for $x$: $x = -7, \, -5$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 8y + 15 = 0$
- Sign pattern $(-, +) \implies$ roots are **positive $(+, +)$**.
- Factors of $15$ summing to $8$: $5$ and $3$.
- Roots for $y$: $y = +3, \, +5$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-7$ | $+3$ | $-7 < +3$ | **$x < y$** |
| $-7$ | $+5$ | $-7 < +5$ | **$x < y$** |
| $-5$ | $+3$ | $-5 < +3$ | **$x < y$** |
| $-5$ | $+5$ | $-5 < +5$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **b) $x < y$**.

##### Shortcut / 5-Second Exam Trick
- Visual Sign Rule: $x$ roots are both negative ($(-, -)$), while $y$ roots are both positive ($(+, +)$). Therefore, every value of $x$ is strictly less than every value of $y$. Hence, $x < y$ instantly.

---

### Q9
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 + 3x - 18 = 0$
- **II.** $y^2 - 5y - 24 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 + 3x - 18 = 0$
- Sign pattern $(+, -) \implies$ roots are **$(-, +)$**.
- Factors of $18$ with difference $3$: $6$ and $3$.
- Roots for $x$: $x = -6, \, +3$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 5y - 24 = 0$
- Sign pattern $(-, -) \implies$ roots are **$(+, -)$**.
- Factors of $24$ with difference $5$: $8$ and $3$.
- Roots for $y$: $y = +8, \, -3$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-6$ | $+8$ | $-6 < +8$ | **$x < y$** |
| $-6$ | $-3$ | $-6 < -3$ | **$x < y$** |
| $+3$ | $+8$ | $+3 < +8$ | **$x < y$** |
| $+3$ | $-3$ | $+3 > -3$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- Shortcut Rule 2: Constant term of Equation I is negative ($-18$), and constant term of Equation II is negative ($-24$). Therefore, one root of each equation is positive and one is negative. Comparing positive $x$ against negative $y$ gives $x > y$, while comparing negative $x$ against positive $y$ gives $x < y$. Direct answer: Option e (CND) in 1 second!

---

### Q10
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 + 5x - 12 = 0$
- **II.** $3y^2 - 7y - 20 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 + 5x - 12 = 0$
- Sign pattern $(+, -) \implies$ roots are **$(-, +)$**.
- Product $a \cdot c = 2 \times 12 = 24$. Factors of $24$ with difference $5$: $8$ and $3$.
- Divide by $a = 2$: $-\frac{8}{2} = -4$, $+\frac{3}{2} = +1.5$.
- Roots for $x$: $x = -4, \, +1.5$

##### Step 2: Solve Equation II for $y$
- Given: $3y^2 - 7y - 20 = 0$
- Sign pattern $(-, -) \implies$ roots are **$(+, -)$**.
- Product $a \cdot c = 3 \times 20 = 60$. Factors of $60$ with difference $7$: $12$ and $5$.
- Divide by $a = 3$: $+\frac{12}{3} = +4$, $-\frac{5}{3} \approx -1.67$.
- Roots for $y$: $y = +4, \, -1.67$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-4$ | $+4$ | $-4 < +4$ | **$x < y$** |
| $-4$ | $-1.67$ | $-4 < -1.67$ | **$x < y$** |
| $+1.5$ | $+4$ | $+1.5 < +4$ | **$x < y$** |
| $+1.5$ | $-1.67$ | $+1.5 > -1.67$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- Both constant terms are negative ($-12$ and $-20$). Regardless of coefficients $a$ or $b$, both equations have opposite-sign roots, guaranteeing conflicting relations ($>$ and $<$). Zero arithmetic needed: Mark Option e.

---

### Q11
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 + 11x + 14 = 0$
- **II.** $2y^2 + 15y + 28 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 + 11x + 14 = 0$
- Sign pattern $(+, +) \implies$ roots are **$(-, -)$**.
- Product $a \cdot c = 2 \times 14 = 28$. Factors of $28$ that sum to $11$: $7$ and $4$.
- Signed factors: $-7, -4$.
- Divide by $a = 2$: $x = -\frac{7}{2} = -3.5, \, -\frac{4}{2} = -2$.

##### Step 2: Solve Equation II for $y$
- Given: $2y^2 + 15y + 28 = 0$
- Sign pattern $(+, +) \implies$ roots are **$(-, -)$**.
- Product $a \cdot c = 2 \times 28 = 56$. Factors of $56$ that sum to $15$: $8$ and $7$.
- Signed factors: $-8, -7$.
- Divide by $a = 2$: $y = -\frac{8}{2} = -4, \, -\frac{7}{2} = -3.5$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-3.5$ | $-4$ | $-3.5 > -4$ | **$x > y$** |
| $-3.5$ | $-3.5$ | $-3.5 = -3.5$ | **$x = y$** |
| $-2$ | $-4$ | $-2 > -4$ | **$x > y$** |
| $-2$ | $-3.5$ | $-2 > -3.5$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Since $a_1 = a_2 = 2$, compare the raw signed factors directly: $x \in \{-3.5, -2\}$ and $y \in \{-4, -3.5\}$. $-2$ is greater than both roots of $y$, and $-3.5$ is greater than $-4$ and equal to $-3.5$. Thus, $x \ge y$.

---

### Q12
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $3x^2 - 10x + 8 = 0$
- **II.** $2y^2 - 11y + 14 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $3x^2 - 10x + 8 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 3 \times 8 = 24$. Factors of $24$ summing to $10$: $6$ and $4$.
- Divide by $a = 3$: $x = +\frac{6}{3} = 2, \, +\frac{4}{3} \approx 1.33$.

##### Step 2: Solve Equation II for $y$
- Given: $2y^2 - 11y + 14 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 14 = 28$. Factors of $28$ summing to $11$: $7$ and $4$.
- Divide by $a = 2$: $y = +\frac{7}{2} = 3.5, \, +\frac{4}{2} = 2$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $1.33$ | $2$ | $1.33 < 2$ | **$x < y$** |
| $1.33$ | $3.5$ | $1.33 < 3.5$ | **$x < y$** |
| $2$ | $2$ | $2 = 2$ | **$x = y$** |
| $2$ | $3.5$ | $2 < 3.5$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- Equalizing coefficients: multiply raw $x$-factors by $a_2 = 2$ ($6 \times 2 = 12, 4 \times 2 = 8$) and raw $y$-factors by $a_1 = 3$ ($7 \times 3 = 21, 4 \times 3 = 12$). Compare raw sets: $\{8, 12\}$ vs $\{12, 21\}$. Clearly, every element of $\{8, 12\}$ is $\le$ every element of $\{12, 21\}$. Thus, $x \le y$ without dealing with decimals.

---

### Q13
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 - 13x + 20 = 0$
- **II.** $2y^2 - 7y + 6 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 - 13x + 20 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 20 = 40$. Factors of $40$ summing to $13$: $8$ and $5$.
- Divide by $a = 2$: $x = +\frac{8}{2} = 4, \, +\frac{5}{2} = 2.5$.

##### Step 2: Solve Equation II for $y$
- Given: $2y^2 - 7y + 6 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 6 = 12$. Factors of $12$ summing to $7$: $4$ and $3$.
- Divide by $a = 2$: $y = +\frac{4}{2} = 2, \, +\frac{3}{2} = 1.5$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $2.5$ | $1.5$ | $2.5 > 1.5$ | **$x > y$** |
| $2.5$ | $2$ | $2.5 > 2$ | **$x > y$** |
| $4$ | $1.5$ | $4 > 1.5$ | **$x > y$** |
| $4$ | $2$ | $4 > 2$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- Both leading coefficients are 2. Raw factors: $x \in \{5, 8\}$ and $y \in \{3, 4\}$. Minimum factor of $x$ ($5$) is strictly greater than maximum factor of $y$ ($4$). Therefore, $x > y$ immediately.

---

### Q14
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 - 7x + 6 = 0$
- **II.** $2y^2 - 15y + 28 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **b) $x < y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 - 7x + 6 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 6 = 12$. Factors summing to $7$: $4$ and $3$.
- Divide by $a = 2$: $x = +\frac{4}{2} = 2, \, +\frac{3}{2} = 1.5$.

##### Step 2: Solve Equation II for $y$
- Given: $2y^2 - 15y + 28 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 28 = 56$. Factors summing to $15$: $8$ and $7$.
- Divide by $a = 2$: $y = +\frac{8}{2} = 4, \, +\frac{7}{2} = 3.5$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $1.5$ | $3.5$ | $1.5 < 3.5$ | **$x < y$** |
| $1.5$ | $4$ | $1.5 < 4$ | **$x < y$** |
| $2$ | $3.5$ | $2 < 3.5$ | **$x < y$** |
| $2$ | $4$ | $2 < 4$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **b) $x < y$**.

##### Shortcut / 5-Second Exam Trick
- Both leading coefficients are 2. Maximum factor of $x$ ($4$) is strictly smaller than minimum factor of $y$ ($7$). Hence, $x < y$ instantly.

---

### Q15
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 - 9x + 10 = 0$
- **II.** $3y^2 - 14y + 15 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 - 9x + 10 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 20$. Factors summing to $9$: $5$ and $4$.
- Roots for $x$: $x = \frac{5}{2} = 2.5, \, \frac{4}{2} = 2$.

##### Step 2: Solve Equation II for $y$
- Given: $3y^2 - 14y + 15 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 45$. Factors summing to $14$: $9$ and $5$.
- Roots for $y$: $y = \frac{9}{3} = 3, \, \frac{5}{3} \approx 1.67$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $2$ | $1.67$ | $2 > 1.67$ | **$x > y$** |
| $2$ | $3$ | $2 < 3$ | **$x < y$** |
| $2.5$ | $1.67$ | $2.5 > 1.67$ | **$x > y$** |
| $2.5$ | $3$ | $2.5 < 3$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- The roots of $x$ are $[2, 2.5]$, while the roots of $y$ are $[1.67, 3]$. The range of $x$ is completely nested inside the range of $y$. Hence, $x$ is both greater than some $y$ ($2 > 1.67$) and smaller than another $y$ ($2 < 3$). Contradictory signs $\implies$ CND.

---

### Q16
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 - 9x + 9 = 0$
- **II.** $4y^2 - 12y + 9 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 - 9x + 9 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Product $a \cdot c = 2 \times 9 = 18$. Factors summing to $9$: $6$ and $3$.
- Divide by $a = 2$: $x = \frac{6}{2} = 3, \, \frac{3}{2} = 1.5$.

##### Step 2: Solve Equation II for $y$
- Given: $4y^2 - 12y + 9 = 0$
- Discriminant $D = (-12)^2 - 4(4)(9) = 144 - 144 = 0$ (perfect square trinomial $(2y - 3)^2 = 0$).
- Repeated root: $y = \frac{3}{2} = 1.5, \, 1.5$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $1.5$ | $1.5$ | $1.5 = 1.5$ | **$x = y$** |
| $1.5$ | $1.5$ | $1.5 = 1.5$ | **$x = y$** |
| $3$ | $1.5$ | $3 > 1.5$ | **$x > y$** |
| $3$ | $1.5$ | $3 > 1.5$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Equation II is a perfect square giving identical roots $y = 1.5$. Equation I gives $x = 1.5$ and $x = 3$. Since $3 > 1.5$ and $1.5 = 1.5$, the relation is $x \ge y$.

---

### Q17
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 = 81$
- **II.** $y = \sqrt{81}$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 = 81$
- Taking square root on both sides: $x = \pm \sqrt{81}$
- Roots for $x$: $x = +9, \, -9$

##### Step 2: Solve Equation II for $y$
- Given: $y = \sqrt{81}$
- The radical symbol $\sqrt{}$ denotes the principal (non-negative) square root by mathematical definition.
- Root for $y$: $y = +9$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $+9$ | $+9$ | $+9 = +9$ | **$x = y$** |
| $-9$ | $+9$ | $-9 < +9$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- Golden Rule of Radicals: $x^2 = k \implies x = \pm \sqrt{k}$ (two roots), whereas $y = \sqrt{k} \implies y = +\sqrt{k}$ (one positive root). Comparing $\{+9, -9\}$ with $\{+9\}$: $+9 = +9$ and $-9 < +9$. Result is always $x \le y$.

---

### Q18
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x = \sqrt{64}$
- **II.** $y^2 = 64$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x = \sqrt{64}$
- By definition of principal square root: $x = +8$ (single root).

##### Step 2: Solve Equation II for $y$
- Given: $y^2 = 64$
- Solving pure quadratic: $y = \pm \sqrt{64}$
- Roots for $y$: $y = +8, \, -8$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $+8$ | $+8$ | $+8 = +8$ | **$x = y$** |
| $+8$ | $-8$ | $+8 > -8$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Here $x = +8$ and $y = \pm 8$. $+8 = +8$ and $+8 > -8$. Therefore, $x \ge y$ immediately.

---

### Q19
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x = \sqrt{144}$
- **II.** $y^2 - 24y + 144 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x = \sqrt{144}$
- Principal square root: $x = +12$ (single root).

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 24y + 144 = 0$
- Notice this is $(y - 12)^2 = 0$.
- Repeated root: $y = 12, \, 12$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $12$ | $12$ | $12 = 12$ | **$x = y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- Both $x = 12$ and $y = 12$. Since $x$ and $y$ take the exact same value identically, $x = y$. By standard competitive exam instructions, $x = y$ falls under Option e.

---

### Q20
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 = 144$
- **II.** $y^2 - 25y + 156 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 = 144$
- Roots for $x$: $x = \pm 12 \implies x = -12, \, +12$.

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 25y + 156 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factors of $156$ summing to $25$: $13 \times 12 = 156$ and $13 + 12 = 25$.
- Roots for $y$: $y = 12, \, 13$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $-12$ | $12$ | $-12 < 12$ | **$x < y$** |
| $-12$ | $13$ | $-12 < 13$ | **$x < y$** |
| $+12$ | $12$ | $12 = 12$ | **$x = y$** |
| $+12$ | $13$ | $12 < 13$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- $x \in \{-12, +12\}$ and $y \in \{12, 13\}$. $-12$ is less than both roots of $y$, and $+12$ is equal to $12$ and less than $13$. Thus, $x \le y$.

---

### Q21
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 7\sqrt{3}x + 36 = 0$
- **II.** $y^2 - 9\sqrt{3}y + 60 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 7\sqrt{3}x + 36 = 0$
- **Radical Trick:** Divide the constant term $36$ by the radical square $(\sqrt{3})^2 = 3$: $\frac{36}{3} = 12$.
- Find two numbers that multiply to $12$ and add up to $7$: $4$ and $3$.
- Attach $\sqrt{3}$ to each factor: $4\sqrt{3}$ and $3\sqrt{3}$.
- Sign pattern is $(-, +) \implies$ roots are **positive $(+, +)$**.
- Roots for $x$: $x = 3\sqrt{3}, \, 4\sqrt{3}$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 9\sqrt{3}y + 60 = 0$
- Divide the constant term $60$ by $3$: $\frac{60}{3} = 20$.
- Find two numbers that multiply to $20$ and add up to $9$: $5$ and $4$.
- Attach $\sqrt{3}$ to each factor: $5\sqrt{3}$ and $4\sqrt{3}$.
- Sign pattern is $(-, +) \implies$ roots are **positive $(+, +)$**.
- Roots for $y$: $y = 4\sqrt{3}, \, 5\sqrt{3}$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $3\sqrt{3}$ | $4\sqrt{3}$ | $3\sqrt{3} < 4\sqrt{3}$ | **$x < y$** |
| $3\sqrt{3}$ | $5\sqrt{3}$ | $3\sqrt{3} < 5\sqrt{3}$ | **$x < y$** |
| $4\sqrt{3}$ | $4\sqrt{3}$ | $4\sqrt{3} = 4\sqrt{3}$ | **$x = y$** |
| $4\sqrt{3}$ | $5\sqrt{3}$ | $4\sqrt{3} < 5\sqrt{3}$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- Since both equations contain $\sqrt{3}$, cancel $\sqrt{3}$ mentally and compare the base factors directly: $x \in \{3, 4\}$ and $y \in \{4, 5\}$. Clearly, $x \le y$!

---

### Q22
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 5\sqrt{2}x + 12 = 0$
- **II.** $y^2 - 3\sqrt{2}y + 4 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 5\sqrt{2}x + 12 = 0$
- Divide constant $12$ by $(\sqrt{2})^2 = 2$: $\frac{12}{2} = 6$.
- Find two numbers whose product is $6$ and sum is $5$: $3$ and $2$.
- Roots for $x$: $x = 2\sqrt{2}, \, 3\sqrt{2}$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 3\sqrt{2}y + 4 = 0$
- Divide constant $4$ by $2$: $\frac{4}{2} = 2$.
- Find two numbers whose product is $2$ and sum is $3$: $2$ and $1$.
- Roots for $y$: $y = 1\sqrt{2}, \, 2\sqrt{2}$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $2\sqrt{2}$ | $1\sqrt{2}$ | $2\sqrt{2} > 1\sqrt{2}$ | **$x > y$** |
| $2\sqrt{2}$ | $2\sqrt{2}$ | $2\sqrt{2} = 2\sqrt{2}$ | **$x = y$** |
| $3\sqrt{2}$ | $1\sqrt{2}$ | $3\sqrt{2} > 1\sqrt{2}$ | **$x > y$** |
| $3\sqrt{2}$ | $2\sqrt{2}$ | $3\sqrt{2} > 2\sqrt{2}$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Cancel $\sqrt{2}$ from both sets: $x$-factors are $\{2, 3\}$ and $y$-factors are $\{1, 2\}$. Since $2 \ge 1, 2 = 2$ and $3 > 1, 3 > 2$, the result is $x \ge y$.

---

### Q23
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^3 = 512$
- **II.** $y^2 = 64$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^3 = 512$
- An odd-degree power equation $x^{2n+1} = k$ has exactly one real root of the same sign.
- Since $8^3 = 512$: $x = 8$ (single real root).

##### Step 2: Solve Equation II for $y$
- Given: $y^2 = 64$
- An even-degree power equation $y^{2n} = k$ has two real roots: positive and negative.
- Roots for $y$: $y = +8, \, -8$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $8$ | $8$ | $8 = 8$ | **$x = y$** |
| $8$ | $-8$ | $8 > -8$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Odd powers retain single sign: $x^3 = 512 \implies x = 8$. Even powers yield both signs: $y^2 = 64 \implies y = \pm 8$. Clearly $8 = 8$ and $8 > -8$, which means $x \ge y$.

---

### Q24
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 = 49$
- **II.** $y^3 = 343$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **d) $x \le y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 = 49$
- Roots for $x$: $x = +7, \, -7$

##### Step 2: Solve Equation II for $y$
- Given: $y^3 = 343$
- Since $7^3 = 343$, the single real root is $y = +7$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $+7$ | $+7$ | $+7 = +7$ | **$x = y$** |
| $-7$ | $+7$ | $-7 < +7$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **d) $x \le y$**.

##### Shortcut / 5-Second Exam Trick
- $x \in \{-7, +7\}$ and $y = +7$. $+7 = +7$ and $-7 < +7$. The result is $x \le y$ immediately.

---

### Q25
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $\sqrt{x} - 3 = 0$
- **II.** $y^2 - 18y + 81 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $\sqrt{x} - 3 = 0 \implies \sqrt{x} = 3$
- Squaring both sides: $x = 3^2 = 9$ (single root).

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 18y + 81 = 0$
- Factorization: $(y - 9)^2 = 0$
- Repeated root: $y = 9, \, 9$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $9$ | $9$ | $9 = 9$ | **$x = y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- Both equations evaluate to the unique value $9$. Since $x = y$, mark Option e.

---

### Q26
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $2x^2 - 11x + 15 = 0$
- **II.** $2y^2 - 7y + 5 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **c) $x \ge y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $2x^2 - 11x + 15 = 0$
- Product $a \cdot c = 2 \times 15 = 30$. Factors summing to $11$: $6$ and $5$.
- Divide by $a = 2$: $x = \frac{6}{2} = 3, \, \frac{5}{2} = 2.5$.

##### Step 2: Solve Equation II for $y$
- Given: $2y^2 - 7y + 5 = 0$
- Product $a \cdot c = 2 \times 5 = 10$. Factors summing to $7$: $5$ and $2$.
- Divide by $a = 2$: $y = \frac{5}{2} = 2.5, \, \frac{2}{2} = 1$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $2.5$ | $1$ | $2.5 > 1$ | **$x > y$** |
| $2.5$ | $2.5$ | $2.5 = 2.5$ | **$x = y$** |
| $3$ | $1$ | $3 > 1$ | **$x > y$** |
| $3$ | $2.5$ | $3 > 2.5$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **c) $x \ge y$**.

##### Shortcut / 5-Second Exam Trick
- Both leading coefficients are 2. Compare raw factors: $x \in \{5, 6\}$ and $y \in \{2, 5\}$. Since $5 = 5$, $5 > 2$, $6 > 5$, and $6 > 2$, the result is $x \ge y$.

---

### Q27
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $3x + 2y = 22$
- **II.** $2x + 3y = 23$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **b) $x < y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Equation (I): $3x + 2y = 22$
- Equation (II): $2x + 3y = 23$
- **Symmetric Linear Elimination Shortcut:**
- Add (I) and (II): $(3x + 2x) + (2y + 3y) = 22 + 23 \implies 5x + 5y = 45 \implies x + y = 9$ [Eq III]
- Subtract (II) from (I): $(3x - 2x) + (2y - 3y) = 22 - 23 \implies x - y = -1$ [Eq IV]

##### Step 2: Solve Equation II for $y$
- Add Eq III and Eq IV: $(x + y) + (x - y) = 9 + (-1) \implies 2x = 8 \implies x = 4$
- Substitute $x = 4$ into Eq III: $4 + y = 9 \implies y = 5$.

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $4$ | $5$ | $4 < 5$ | **$x < y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **b) $x < y$**.

##### Shortcut / 5-Second Exam Trick
- Symmetric linear system: $(x+y) = \frac{22+23}{5} = 9$ and $(x-y) = \frac{22-23}{1} = -1$. Since $x - y = -1 < 0$, it directly follows that $x < y$ in 5 seconds without even calculating individual values of $x$ and $y$!

---

### Q28
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $5x + 3y = 31$
- **II.** $3x + 5y = 25$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Equation (I): $5x + 3y = 31$
- Equation (II): $3x + 5y = 25$
- **Symmetric Subtraction Trick:**
- Subtract (II) from (I): $(5x - 3x) + (3y - 5y) = 31 - 25$
- $2x - 2y = 6 \implies 2(x - y) = 6 \implies x - y = 3$

##### Step 2: Solve Equation II for $y$
- Since $x - y = 3 > 0$, we have $x = y + 3$.
- (Full check: Adding gives $8(x + y) = 56 \implies x + y = 7$. Adding the two gives $2x = 10 \implies x = 5$, and $y = 2$).

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $5$ | $2$ | $5 > 2$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- Subtract (II) from (I) directly: $(5-3)x - (5-3)y = 31-25 \implies 2(x-y) = 6 \implies x - y = 3 > 0$. Therefore, $x > y$ immediately in 3 seconds!

---

### Q29
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 25x + 156 = 0$
- **II.** $y^2 - 21y + 110 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **a) $x > y$**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 25x + 156 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factoring $156$: Since $\sqrt{156} \approx 12.5$, test factors around $12$: $156 = 12 \times 13$, and $12 + 13 = 25$.
- Roots for $x$: $x = 12, \, 13$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 21y + 110 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factoring $110$: $110 = 10 \times 11$, and $10 + 11 = 21$.
- Roots for $y$: $y = 10, \, 11$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $12$ | $10$ | $12 > 10$ | **$x > y$** |
| $12$ | $11$ | $12 > 11$ | **$x > y$** |
| $13$ | $10$ | $13 > 10$ | **$x > y$** |
| $13$ | $11$ | $13 > 11$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **a) $x > y$**.

##### Shortcut / 5-Second Exam Trick
- Minimum root of $x$ ($12$) is strictly greater than maximum root of $y$ ($11$). Hence, $x > y$ without any ambiguity.

---

### Q30
**Question:**
In the following question, two equations are given. Solve both equations and establish the correct relationship between $x$ and $y$:
- **I.** $x^2 - 32x + 252 = 0$
- **II.** $y^2 - 28y + 195 = 0$

- a) $x > y$
- b) $x < y$
- c) $x \ge y$
- d) $x \le y$
- e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)

**Correct Option:** **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**

---

#### Detailed Step-by-Step Solution

##### Step 1: Solve Equation I for $x$
- Given: $x^2 - 32x + 252 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factoring $252$: $\sqrt{252} \approx 15.8$. Testing numbers near $16$: $252 = 14 \times 18$, and $14 + 18 = 32$.
- Roots for $x$: $x = 14, \, 18$

##### Step 2: Solve Equation II for $y$
- Given: $y^2 - 28y + 195 = 0$
- Sign pattern $(-, +) \implies$ roots are **$(+, +)$**.
- Factoring $195$: $\sqrt{195} \approx 14$. Since it ends in $5$, $195 = 5 \times 39 = 15 \times 13$, and $13 + 15 = 28$.
- Roots for $y$: $y = 13, \, 15$

##### Step 3: Comparison Grid ($x$ vs $y$)
| Value of $x$ | Value of $y$ | Arithmetic Comparison | Resulting Relation |
| :---: | :---: | :---: | :---: |
| $14$ | $13$ | $14 > 13$ | **$x > y$** |
| $14$ | $15$ | $14 < 15$ | **$x < y$** |
| $18$ | $13$ | $18 > 13$ | **$x > y$** |
| $18$ | $15$ | $18 > 15$ | **$x > y$** |

**Conclusion:** Combining all 4 pairwise comparisons confirms **e) $x = y$ or Relationship between $x$ and $y$ cannot be determined (CND)**.

##### Shortcut / 5-Second Exam Trick
- The root $x = 14$ lies strictly between the roots of $y$ ($13$ and $15$). Since $14 > 13$ but $14 < 15$, opposing relations appear immediately. Hence, relationship cannot be determined (CND).

---

## 3. High-Yield Tricks, Tips & Exam Shortcuts

### 3.1 The 2-Second Visual Inspection Checklist

When attempting Quadratic Inequality questions in competitive placement and recruitment exams (TCS, Infosys, Wipro, Cognizant, Banking IBPS/SBI PO, Aditya University CRT), run through this sequential visual checklist before doing any paper calculations:

```
                  ┌────────────────────────────────────────┐
                  │ Are both constant terms negative?      │
                  │              (c1 < 0 & c2 < 0)         │
                  └───────────────────┬────────────────────┘
                                      │
                         YES ─────────┴───────── NO
                          │                       │
                          ▼                       ▼
                  ┌───────────────┐     ┌───────────────────────────────────┐
                  │ Mark Option e │     │ Are the sign patterns opposite?   │
                  │     (CND)     │     │   (x: -,+ -> +,+) & (y: +,+ -> -,-)│
                  └───────────────┘     └─────────────────┬─────────────────┘
                                                          │
                                             YES ─────────┴───────── NO
                                              │                       │
                                              ▼                       ▼
                                      ┌───────────────┐     ┌───────────────────┐
                                      │ Mark Option a │     │ Apply Fast Sign   │
                                      │    (x > y)    │     │ Splitting Method  │
                                      └───────────────┘     └───────────────────┘
```

1. **Both Constant Terms Negative ($c_1 < 0$ and $c_2 < 0$):**
   - **Action:** Mark **Option e (CND)** immediately.
   - **Reason:** Both equations will yield one positive root and one negative root. Cross-comparing positive against negative always creates contradictory inequality signs.

2. **Opposing Pure Sign Patterns:**
   - If Equation I is $(-, +) \implies$ roots are $(+, +)$
   - If Equation II is $(+, +) \implies$ roots are $(-, -)$
   - **Action:** Mark **Option a ($x > y$)** immediately.
   - If Equation I is $(+, +)$ and Equation II is $(-, +)$, mark **Option b ($x < y$)** immediately.

---

### 3.2 Cross-Multiplication for Unequal Leading Coefficients ($a_1 \neq a_2$)

When $a_1 \neq a_2$, dividing by $a$ creates decimals or unwieldy fractions that slow down comparison.
Instead of:
$$x = \frac{f_{x1}}{a_1}, \, \frac{f_{x2}}{a_1} \quad \text{vs} \quad y = \frac{f_{y1}}{a_2}, \, \frac{f_{y2}}{a_2}$$

Multiply through by $a_2$ and $a_1$:
$$\text{Compare } \left( a_2 \cdot f_{x} \right) \quad \text{against} \quad \left( a_1 \cdot f_{y} \right)$$

#### Example:
- Equation I: $2x^2 - 11x + 14 = 0 \implies a_1 = 2$, raw split roots $= +7, +4$.
- Equation II: $3y^2 - 13y + 12 = 0 \implies a_2 = 3$, raw split roots $= +9, +4$.
- Multiply $x$-roots by $a_2 = 3$: $\{7 \times 3, 4 \times 3\} = \{21, 12\}$.
- Multiply $y$-roots by $a_1 = 2$: $\{9 \times 2, 4 \times 2\} = \{18, 8\}$.
- Compare $\{21, 12\}$ vs $\{18, 8\}$:
  - $21 > 18, \quad 21 > 8$
  - $12 < 18 \implies$ Stop! Contradictory signs appear ($21 > 18$ but $12 < 18$).
  - Result: **Option e (CND)** determined in pure integers without calculating $\frac{7}{2} = 3.5$ or $\frac{13}{3} = 4.33$.

---

### 3.3 The Radical / Square-Root Coefficient Shortcut

When the linear term contains a square root, such as $x^2 - b\sqrt{k}x + c = 0$:
1. **Divide the constant $c$ by $k$:** Let $c' = \frac{c}{k}$.
2. **Find two factors of $c'$ that add or subtract to $b$:** Let these be $f_1, f_2$.
3. **Multiply both factors by $\sqrt{k}$:** The required roots are $(f_1\sqrt{k}, f_2\sqrt{k})$.
4. **Fast Comparison:** When both $x$ and $y$ equations contain the same radical $\sqrt{k}$, cancel $\sqrt{k}$ and compare $f_x$ directly against $f_y$.

---

### 3.4 Summary Table: Common Trap Formats & Solutions

| Trap Problem Format | Mathematical Nature | Root Structure | Instant Decision Rule |
| :--- | :--- | :--- | :--- |
| **$x^2 = k$ vs $y = \sqrt{k}$** | Pure quadratic vs Principal square root | $x = \pm \sqrt{k}$, $y = +\sqrt{k}$ | **$x \le y$ (Option d)** |
| **$x = \sqrt{k}$ vs $y^2 = k$** | Principal square root vs Pure quadratic | $x = +\sqrt{k}$, $y = \pm \sqrt{k}$ | **$x \ge y$ (Option c)** |
| **$x^3 = k$ vs $y^2 = k^{2/3}$** | Odd power vs Even power ($k > 0$) | $x = +k^{1/3}$, $y = \pm k^{1/3}$ | **$x \ge y$ (Option c)** |
| **$x^2 + px + q = 0$ (perfect sq) vs $y = \text{root}$** | Equal repeated roots | $\alpha_x = \beta_x$, $\alpha_y$ | Check single pair comparison |
| **$c_1 < 0$ and $c_2 < 0$** | Both constant terms negative | $(+,-)$ vs $(+,-)$ | **CND (Option e)** |
| **$x$-signs $(-,+)$ and $y$-signs $(+,+)$** | Opposing coefficient signs | $(+,+)$ vs $(-,-)$ | **$x > y$ (Option a)** |
| **$x$-signs $(+,+)$ and $y$-signs $(-,+)$** | Opposing coefficient signs | $(-,-)$ vs $(+,+)$ | **$x < y$ (Option b)** |

---
