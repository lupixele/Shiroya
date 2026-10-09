# 11. Data Sufficiency

## 1. Theory, Principles & Standard Rules

Data Sufficiency (DS) is a vital analytical domain tested across major campus recruitment training (CRT) assessments, national aptitude examinations, and management entrance tests. 

Unlike traditional problem-solving—where the candidate must calculate an exact numerical answer or construct a full arrangement—**Data Sufficiency evaluates whether the given statements provide sufficient information to reach a unique, definitive conclusion.**

---

### 1.1 Core Philosophy & Golden Rules

1. **Sufficiency Over Complete Computation:**
   - The primary objective is to decide whether a problem *can* be solved uniquely, **not** to carry out redundant arithmetic.
   - For instance, if two independent linear equations with two unknown variables are given ($a_1x + b_1y = c_1$ and $a_2x + b_2y = c_2$ where $rac{a_1}{a_2} 

eq rac{b_1}{b_2}$), algebraic uniqueness guarantees a single solution. Calculating the exact values of $x$ and $y$ wastes time.

2. **Strict Independence of Statements:**
   - **Never carry over information from Statement I into Statement II.**
   - When evaluating Statement II, isolate it completely and assume you have never seen Statement I.
   - Combine Statements I and II **only if both Statement I alone and Statement II alone fail independently**.

3. **Value Questions vs. Yes/No Decision Questions:**
   - **Unique Value Question:** If the prompt asks *"What is the age of Shekar?"* or *"What is the code for 'big'?"*, the information is sufficient **if and only if it leads to exactly one single value**. If two or more values/codes remain possible, the statement is **insufficient**.
   - **Yes/No Decision Question:** If the prompt asks *"Is F the granddaughter of B?"* or *"Is $n$ an odd number?"*, a definitive **"Yes"** is **SUFFICIENT**, and an equally definitive **"No"** is **SUFFICIENT**. The data is **INSUFFICIENT** only if the response is ambiguous (*"Maybe Yes, Maybe No"* depending on different cases).

4. **Zero Unwarranted Assumptions:**
   - **Blood Relations:** Names never guarantee gender (e.g., Dilawar, Bijli, Kiran cannot be assumed male or female without explicit textual confirmation).
   - **Number Properties:** Variables are real numbers unless explicitly stated as integers, natural numbers, or primes. Do not assume $x > 0$ unless specified.
   - **Sequences & Orders:** Do not assume consecutive ordering, distinctness, or floor layout conventions unless clearly stipulated in the prompt.

---

### 1.2 The Five Standard Answer Choices

Across competitive examinations and standard recruitment platforms, Data Sufficiency problems adhere to five canonical answer options:

| Option Code | Formal Definition | Operational Decision Rule |
| :---: | :--- | :--- |
| **A** | **Statement I ALONE is sufficient**, but Statement II alone is not sufficient. | Statement I yields a unique answer independently; Statement II yields multiple answers or fails. |
| **B** | **Statement II ALONE is sufficient**, but Statement I alone is not sufficient. | Statement II yields a unique answer independently; Statement I yields multiple answers or fails. |
| **C** | **EITHER Statement I ALONE or Statement II ALONE is sufficient**. | Statement I yields a unique answer independently, **AND** Statement II also yields a unique answer independently. |
| **D** | **BOTH Statements I and II TOGETHER are sufficient**, but neither statement alone is sufficient. | Statements I and II fail individually, but their conjunction eliminates all ambiguities to provide a unique solution. |
| **E** | **Statements I and II TOGETHER are NOT sufficient**. | Even after combining all data from both statements, two or more valid possibilities persist. Additional data is required. |

> **Critical Exam Tip:** While options **A**, **B**, **C**, **D**, and **E** follow the mapping above in this guide and standard CRT curriculum, certain testing engines swap options **C** and **D** (e.g., assigning **C** to *"Both together are sufficient"* and **D** to *"Either alone is sufficient"*). Always verify the printed option map on your screen before locking an answer!

---

### 1.3 Systematic 3-Step Elimination Protocol

To eliminate incorrect options systematically and maximize speed:

```
                          [ Analyze Question Prompt ]
                          Identify Target Variable / Entity
                                       │
                                       ▼
                          [ Test Statement I ALONE ]
                                       │
                     ┌─────────────────┴─────────────────┐
                     ▼                                   ▼
              [ I is SUFFICIENT ]                 [ I is INSUFFICIENT ]
              (Eliminate B, D, E)                 (Eliminate A, C)
                     │                                   │
                     ▼                                   ▼
              [ Test II ALONE ]                   [ Test II ALONE ]
                     │                                   │
            ┌────────┴────────┐                 ┌────────┴────────┐
            ▼                 ▼                 ▼                 ▼
       [ II is SUFF ]  [ II is INSUFF ]    [ II is SUFF ]  [ II is INSUFF ]
            │                 │                 │                 │
            ▼                 ▼                 ▼                 ▼
        Option C          Option A          Option B      [ Combine I + II ]
                                                                 │
                                                        ┌────────┴────────┐
                                                        ▼                 ▼
                                                  [ Together SUFF ] [ Still INSUFF ]
                                                        │                 │
                                                        ▼                 ▼
                                                    Option D          Option E
```

---

### 1.4 Major Question Archetypes Tested

1. **Inequalities and Age Comparisons:** Order entities strictly along a linear scale ($>$ or $<$). Keywords like *"only"* restrict boundary ranks.
2. **Positional Ranking & Seating Arrangements:** Use foundational ranking equations:
   $$	ext{Total } (T) = 	ext{Left} + 	ext{Right} - 1$$
   $$	ext{In-between} = |	ext{Pos}_1 - 	ext{Pos}_2| - 1 \quad (	ext{when non-overlapping})$$
3. **Coding-Decoding:** Look for single-word common intersections between paired sentences to isolate unique codes.
4. **Blood Relations:** Build generational trees. Never deduce gender from personal names, parental status, or sibling relationships unless a gender-specific term (*son, daughter, mother, father, brother, sister*) is explicitly stated.
5. **Calendars & Dates:** Identify leap years (divisible by 4, or 400 for century years). Keep in mind that February has 29 days in a leap year, and March always has 31 days.
6. **Dice & Spatial Reasoning:** When two views of a die share two common faces, the remaining unshared faces are directly opposite to each other.
7. **Number Properties & Parity:** Use algebraic parity rules (Odd $	imes$ Odd = Odd, Even $\pm$ Odd = Odd) and unique prime properties (e.g., 2 is the only even prime number).

---

## 2. Comprehensive Solved Question Bank (Q1 – Q30)


### Q1: Comparative Age Ranking
**Problem Statement:**
Among five individuals $M$, $P$, $T$, $R$, and $W$, each being of a different age, who is the youngest?

**Statements:**
- **I.** $T$ is younger than only $P$ and $W$.
- **II.** $M$ is younger than $T$ and older than $R$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  The phrase *"younger than only $P$ and $W$"* means exactly two individuals are older than $T$ ($P$ and $W$), which implies $T$ is the third oldest among the five. The remaining two individuals ($M$ and $R$) must both be younger than $T$:
  $$\{P, W\} > T > \{M, R\}$$
  However, Statement I provides no information regarding the relative age between $M$ and $R$. The youngest could be either $M$ or $R$. Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Statement II gives the relative inequality:
  $$T > M > R$$
  Statement II gives no information about the positions of $P$ and $W$. $P$ and $W$ could be younger than $R$ or interspersed anywhere in the order. Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining the two inequalities:
  $$\{P, W\} > T > M > R$$
  Since $M$ is strictly older than $R$, $R$ is strictly younger than $M, T, P,$ and $W$. Thus, $R$ is uniquely identified as the youngest person.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Look out for the word *"only"*. In Statement I, *"younger than only $P$ and $W$"* establishes an upper bound, proving that only two people are older than $T$, immediately placing $T$ in 3rd rank from the top.

---

### Q2: Determining Family Composition (Number of Daughters)
**Problem Statement:**
How many daughters does Arun have?

**Statements:**
- **I.** Arun has four children.
- **II.** Bijli and Chandani are sisters of Dilawar who is son of Arun.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option E** (Even both Statements I and II together are not sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  Arun has 4 children in total ($T = 4$). This statement provides zero data regarding the gender breakdown (sons vs. daughters). Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Dilawar is a son (male child) of Arun. Bijli and Chandani are sisters of Dilawar, meaning they are female children (daughters) of Arun. This proves Arun has at least 2 daughters (Bijli and Chandani) and at least 1 son (Dilawar). However, Statement II does not state the total number of children Arun has. Arun could have 2, 3, or more daughters. Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining both statements: Arun has 4 children in total. Three of these children are identified:
  1. Dilawar (Son / Male)
  2. Bijli (Daughter / Female)
  3. Chandani (Daughter / Female)
  The fourth child's gender remains completely unknown! 
  - Case 1: If the 4th child is female, Arun has $2 + 1 = 3$ daughters.
  - Case 2: If the 4th child is male, Arun has exactly $2$ daughters.
  Since we cannot determine whether Arun has 2 or 3 daughters, the data remains ambiguous.
  Therefore, **Even both statements together are NOT sufficient.**

**Shortcut / Trap Alert:** Never assume the unmentioned fourth child must be male. In Data Sufficiency blood relations, every unstated gender must be treated as a two-case branch ($M$ or $F$).

---

### Q3: Extreme Order Ranking (Tallest Person)
**Problem Statement:**
Who is the tallest among the brothers $A$, $B$, $C$, and $D$?

**Statements:**
- **I.** $C$ is shorter than only $B$.
- **II.** $D$ is taller than only $A$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option A** (Statement I alone is sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  The phrase *"$C$ is shorter than only $B$"* means that $B$ is the **sole** brother who is taller than $C$. Consequently, all other brothers ($A$ and $D$) must be shorter than $C$.
  Height order:
  $$B > C > \{A, D\}$$
  This definitively establishes that $B$ is the tallest brother. Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  The statement *"$D$ is taller than only $A$"* means that $A$ is the sole brother who is shorter than $D$. This places $D$ second from the bottom:
  $$\{B, C\} > D > A$$
  However, Statement II does not specify whether $B > C$ or $C > B$. The tallest could be either $B$ or $C$. Hence, **Statement II alone is NOT sufficient.**
  Therefore, **Statement I alone is sufficient, while Statement II alone is not.**

**Shortcut / Trap Alert:** Remember the operational rule: when Statement I alone answers the target question completely and uniquely, immediately eliminate options B, D, and E. Testing Statement II is only needed to decide between A and C.

---

### Q4: Verification of Granddaughter Relationship
**Problem Statement:**
Is $F$ the granddaughter of $B$?

**Statements:**
- **I.** $B$ is the father of $M$. $M$ is the sister of $T$. $T$ is the mother of $F$.
- **II.** $S$ is the son of $F$. $V$ is the daughter of $F$. $R$ is the brother of $T$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option E** (Even both Statements I and II together are not sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  - $B$ is male (father of $M$).
  - $M$ is female (sister of $T$).
  - $T$ is female (mother of $F$).
  Since $M$ is sister to $T$, $B$ is the father of $T$. Thus, $B$ is the maternal grandfather of $F$, and $F$ is a grandchild of $B$.
  However, **the gender of $F$ is not mentioned anywhere in Statement I.**
  - If $F$ is female $\implies$ $F$ is the granddaughter of $B$ (Answer: YES).
  - If $F$ is male $\implies$ $F$ is the grandson of $B$ (Answer: NO).
  Because we cannot definitively answer YES or NO, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Statement II tells us that $F$ is a parent to $S$ and $V$, and $R$ is the brother of $T$. It provides no link whatsoever between $F$ and $B$, nor does it reveal whether $F$ is male or female (a mother or a father). Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining I and II connects $F$ as the grandchild of $B$. But neither statement establishes whether $F$ is male or female. Having children ($S$ and $V$) does not establish parental gender.
  Since $F$'s gender remains indeterminate, we cannot answer the Yes/No question definitively.
  Therefore, **Even both statements together are NOT sufficient.**

**Shortcut / Trap Alert:** The classic blood relations trap! Never assume a person is female because they have children, or because their name sounds feminine. A grandchild of unknown gender cannot be proven to be a *"granddaughter"*.

---

### Q5: Calendar Date of Last Specific Weekday
**Problem Statement:**
The last Sunday of March, 2004 fell on which date?

**Statements:**
- **I.** The first Sunday of that month fell on 5th.
- **II.** The last day of that month was Friday.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option C** (Either Statement I alone or Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Foundational Calendar Knowledge:* 
  The month of March always has exactly $31$ days in any year, regardless of whether the year is a leap year.
- *Statement I Evaluation:* 
  The first Sunday is March 5. Successive Sundays occur at intervals of 7 days:
  - 1st Sunday: March $5$
  - 2nd Sunday: $5 + 7 =$ March $12$
  - 3rd Sunday: $12 + 7 =$ March $19$
  - 4th Sunday: $19 + 7 =$ March $26$
  - Next Sunday: $26 + 7 =$ March $33$ (exceeds 31 days).
  Therefore, the last Sunday of March 2004 fell uniquely on **March 26, 2004**.
  Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  The last day of March is March 31. Statement II states that March 31 was a Friday. Counting backwards to locate the preceding Sunday:
  - March 31 = Friday
  - March 30 = Thursday
  - March 29 = Wednesday
  - March 28 = Tuesday
  - March 27 = Monday
  - March 26 = Sunday
  Therefore, the last Sunday of March 2004 was uniquely **March 26, 2004**.
  Hence, **Statement II alone is SUFFICIENT.**
  Since each statement independently determines the unique date:
  Therefore, **Either Statement I alone or Statement II alone is sufficient.**

**Shortcut / Trap Alert:** When both statements independently yield the exact same unique answer, the choice is always **C** (Either alone is sufficient).

---

### Q6: Isolation of Code in Artificial Language
**Problem Statement:**
What is the code for 'Clear' in the code language?

**Statements:**
- **I.** In the code language, 'Earth is clear' is written as 'de ra fa'.
- **II.** In the same code language, 'make it clear' is written as 'de ga jo'.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  Sentence: 'Earth is clear' $\rightarrow$ 'de ra fa'.
  The word 'clear' could correspond to 'de', 'ra', or 'fa'. Without another reference sentence, its specific code cannot be isolated. Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Sentence: 'make it clear' $\rightarrow$ 'de ga jo'.
  The word 'clear' could correspond to 'de', 'ga', or 'jo'. Without another reference sentence, its code cannot be isolated. Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Compare the two decoded sentences:
  - Sentence 1: 'Earth is **clear**' $\rightarrow$ '**de** ra fa'
  - Sentence 2: 'make it **clear**' $\rightarrow$ '**de** ga jo'
  Intersection of words: $\{\text{'Earth is clear'}\} \cap \{\text{'make it clear'}\} = \{\text{'clear'}\}$.
  Intersection of codes: $\{\text{'de', 'ra', 'fa'}\} \cap \{\text{'de', 'ga', 'jo'}\} = \{\text{'de'}\}$.
  Because exactly one word and exactly one code are shared between both statements, the code for 'clear' is uniquely identified as **'de'**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** In sentence coding-decoding, one statement alone can never solve a code unless it is a 1-word-to-1-code statement. Always compare sets across statements to ensure exactly one common element remains.

---

### Q7: Multi-Story Floor Arrangement
**Problem Statement:**
Four friends reside in a four-floor apartment where the ground floor is designated as the 1st floor. Exactly one friend resides on each floor. On which floor does Ravi reside?

**Statements:**
- **I.** Rakesh resides on the top floor. Ravi does not reside on an odd-numbered floor.
- **II.** Ravi resides neither on the ground floor nor on even-numbered floors.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option C** (Either Statement I alone or Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Floor Layout Definition:*
  - Floor 4: Top Floor (Even)
  - Floor 3: Third Floor (Odd)
  - Floor 2: Second Floor (Even)
  - Floor 1: Ground Floor (Odd)
- *Statement I Evaluation:* 
  - Rakesh resides on the top floor $\implies \text{Rakesh} = \text{Floor 4}$.
  - Ravi does not reside on an odd-numbered floor $\implies \text{Ravi}$ cannot be on Floor 1 or Floor 3.
  Therefore, Ravi must reside on an even-numbered floor (Floor 2 or Floor 4).
  Since Floor 4 is already occupied by Rakesh, Ravi **must reside on Floor 2**.
  Statement I yields a unique floor. Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  - Ravi does not reside on the ground floor $\implies \text{Ravi} \neq \text{Floor 1}$.
  - Ravi does not reside on even-numbered floors $\implies \text{Ravi} \neq \text{Floor 2}$ and $\text{Ravi} \neq \text{Floor 4}$.
  The only available floor remaining in the building is **Floor 3**.
  Statement II yields a unique floor. Hence, **Statement II alone is SUFFICIENT.**
  Since each statement independently determines the exact floor where Ravi resides:
  Therefore, **Either Statement I alone or Statement II alone is sufficient.**

**Shortcut / Trap Alert:** Notice that Statement I places Ravi on Floor 2, whereas Statement II places Ravi on Floor 3. In Data Sufficiency, statements are independent hypotheticals! You evaluate each statement's self-contained sufficiency to answer the question, not whether both statements agree on the same real-world reality.

---

### Q8: Tallest Among Five Friends
**Problem Statement:**
Who amongst the five friends $O$, $P$, $Q$, $R$, and $S$ is the tallest?

**Statements:**
- **I.** Only one friend is taller than $P$, who is taller than $S$ and $O$.
- **II.** $R$ is taller than $P$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  *"Only one friend is taller than $P$."*
  This places $P$ strictly in 2nd position from the top in height:
  $$[\text{Rank 1}] > P > \{S, O, \text{remaining friend}\}$$
  The friend who occupies Rank 1 could be either $Q$ or $R$. Since Statement I does not identify which of the two is taller than $P$, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Statement II simply states that $R > P$. It provides no information on where $O, Q,$ and $S$ stand, nor does it specify how many people are taller than $R$. Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  From Statement I, there is **only one** person taller than $P$.
  From Statement II, $R$ is taller than $P$.
  Therefore, $R$ **must be that single person** who is taller than $P$!
  The order from tallest to shortest is established as:
  $$R > P > \{O, Q, S\}$$
  Thus, $R$ is uniquely determined as the tallest friend.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Statement I establishes that the tallest person belongs to the set $\{Q, R\}$. Statement II validates that $R > P$, immediately identifying $R$ as the unique element in Rank 1.

---

### Q9: Composition of Children (Counting Sons)
**Problem Statement:**
$P$ has three children. How many sons does $P$ have?

**Statements:**
- **I.** $M$ and $K$ are sisters of $G$.
- **II.** $J$, who has only two daughters, is the mother of $K$ and wife of $P$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option B** (Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  $M$ and $K$ are sisters of $G$. This establishes that $M$ and $K$ are female, and they share a sibling relationship with $G$.
  However, Statement I does not specify whether $G$ is male or female, nor does it link these children directly to parent $P$.
  - If $G$ is a boy $\implies P$ has 1 son.
  - If $G$ is a girl $\implies P$ has 0 sons.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  - $J$ is the wife of $P$. Thus, the 3 children of $P$ are the 3 children of couple $(P, J)$.
  - $J$ has **only two daughters**.
  Since the couple has exactly 3 children in total, and exactly 2 of those children are daughters, the third child **must be a son**:
  $$\text{Number of sons} = \text{Total children} - \text{Daughters} = 3 - 2 = 1 \text{ son}.$$
  Statement II directly determines that $P$ has exactly $1$ son, completely independent of Statement I!
  Hence, **Statement II alone is SUFFICIENT.**
  Therefore, **Statement II alone is sufficient, while Statement I alone is not.**

**Shortcut / Trap Alert:** High-frequency trap! Many examinees reflexively combine both statements to name the children ($M, K$ as daughters and $G$ as the son). But the question does not ask *who* the son is—it only asks *how many* sons $P$ has! Statement II provides the total count ($3 - 2 = 1$) instantly.

---

### Q10: Directional Compass Bearing
**Problem Statement:**
Village $K$ is towards which direction of village $N$?

**Statements:**
- **I.** Village $M$ is to the North of Village $N$ and to the East of Village $K$.
- **II.** Village $D$ is to the West of Village $N$ and to the South of Village $K$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option C** (Either Statement I alone or Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Cartesian Coordinate Framework:* Let Village $N$ be located at the origin $(0, 0)$, where $+x$ is East, $-x$ is West, $+y$ is North, and $-y$ is South.
- *Statement I Evaluation:* 
  - Village $M$ is to the North of Village $N \implies M = (0, y_M)$ with $y_M > 0$.
  - Village $M$ is to the East of Village $K \implies K$ is to the West of $M \implies K = (x_K, y_M)$ with $x_K < 0$.
  Relative to Village $N(0, 0)$:
  Village $K$ has a negative $x$-coordinate (West) and a positive $y$-coordinate (North).
  Therefore, Village $K$ is in the **North-West** direction of Village $N$.
  Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  - Village $D$ is to the West of Village $N \implies D = (x_D, 0)$ with $x_D < 0$.
  - Village $D$ is to the South of Village $K \implies K$ is to the North of $D \implies K = (x_D, y_K)$ with $y_K > 0$.
  Relative to Village $N(0, 0)$:
  Village $K$ has a negative $x$-coordinate (West) and a positive $y$-coordinate (North).
  Therefore, Village $K$ is in the **North-West** direction of Village $N$.
  Hence, **Statement II alone is SUFFICIENT.**
  Since each statement independently determines the exact compass direction:
  Therefore, **Either Statement I alone or Statement II alone is sufficient.**

**Shortcut / Trap Alert:** Sketching a rapid 2D coordinate system on rough scratch paper turns wordy direction puzzles into foolproof quadrant verifications. Both statements independently place $K$ in Quadrant II (North-West) relative to $N$.

---

### Q11: Calendar Date Identification via Number Properties
**Problem Statement:**
On which date of the month was Hari born in February 2004?

**Statements:**
- **I.** Hari was born on an even date of the month.
- **II.** Hari's birth date was a prime number.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Leap Year Constraint:* 
  The year $2004$ is divisible by $4$ ($2004 / 4 = 501$). Thus, February 2004 had $29$ days (Dates: $1, 2, 3, \dots, 29$).
- *Statement I Evaluation:* 
  Hari was born on an even date. The set of even dates in February 2004 is:
  $$\text{Even Dates} = \{2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28\}$$
  There are $14$ possible dates. Statement I cannot determine the exact date.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Hari's birth date was a prime number. The set of prime dates in February 2004 is:
  $$\text{Prime Dates} = \{2, 3, 5, 7, 11, 13, 17, 19, 23, 29\}$$
  There are $10$ possible dates. Statement II cannot determine the exact date.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining both statements requires the date to be **both an even number and a prime number**:
  $$\text{Target Date} \in \text{Even Dates} \cap \text{Prime Dates}$$
  In mathematical number theory, **$2$ is the one and only even prime number in existence.**
  $$\text{Even Primes} = \{2\}$$
  Therefore, Hari was born uniquely on **February 2, 2004**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** The unique mathematical property of $2$ being the only even prime number is an exam staple! Many candidates mistakenly assume that Statement I and Statement II together leave multiple choices because they forget that no other even number is prime.

---

### Q12: Linear Ranking in a Row of Fixed Size
**Problem Statement:**
In a row of 30 students facing North, what is Deepika’s position from the right end?

**Statements:**
- **I.** Hari is fifth to the right of Deepika and 18th from the left end of the row.
- **II.** Vijay is third to the left of Deepika and 11th from the right end of the row.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option C** (Either Statement I alone or Statement II alone is sufficient)

**Step-by-Step Verification:**
- *General Formula:* In a row of total $T$ individuals facing North:
  $$\text{Position from Right} = T - \text{Position from Left} + 1$$
  $$\text{Position from Left} = T - \text{Position from Right} + 1$$
  Given: Total students $T = 30$.
- *Statement I Evaluation:* 
  - Hari is 18th from the left end: $\text{Pos}_{\text{Left}}(\text{Hari}) = 18$.
  - Hari is 5th to the right of Deepika:
    $$\text{Pos}_{\text{Left}}(\text{Hari}) = \text{Pos}_{\text{Left}}(\text{Deepika}) + 5$$
    $$18 = \text{Pos}_{\text{Left}}(\text{Deepika}) + 5 \implies \text{Pos}_{\text{Left}}(\text{Deepika}) = 13$$
  - Calculate Deepika's position from the right end:
    $$\text{Pos}_{\text{Right}}(\text{Deepika}) = 30 - 13 + 1 = 18\text{th}$$
  Statement I yields a unique position. Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  - Vijay is 11th from the right end: $\text{Pos}_{\text{Right}}(\text{Vijay}) = 11$.
  - Vijay is 3rd to the left of Deepika. Because both face North, moving to the left means moving towards the left end (away from the right end), and moving to the right of Vijay means moving closer to the right end:
    $$\text{Pos}_{\text{Right}}(\text{Deepika}) = \text{Pos}_{\text{Right}}(\text{Vijay}) - 3$$
    $$\text{Pos}_{\text{Right}}(\text{Deepika}) = 11 - 3 = 8\text{th}$$
  Statement II yields a unique position. Hence, **Statement II alone is SUFFICIENT.**
  Since each statement independently determines Deepika's rank:
  Therefore, **Either Statement I alone or Statement II alone is sufficient.**

**Shortcut / Trap Alert:** Remember that rank from the right *decreases* as you move rightward towards the right extreme end! A person who is 3 places to the right of someone ranked 11th from the right is ranked $11 - 3 = 8$th from the right.

---

### Q13: Deciphering Artificial Vocabulary Code
**Problem Statement:**
What is the code for ‘Vijay’ in the code language?

**Statements:**
- **I.** In the code language, ‘Vijay is Brilliant’ is written as ‘pa sa na’.
- **II.** In the same code language, 'make it clear' is written as ‘ne ta ke’.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option E** (Even both Statements I and II together are not sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  'Vijay is Brilliant' $\rightarrow$ 'pa sa na'.
  Vijay could be coded as 'pa', 'sa', or 'na'. No individual word correspondence is provided.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  'make it clear' $\rightarrow$ 'ne ta ke'.
  This sentence does not contain the word 'Vijay'.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Look for common words or common codes across both statements:
  $$\{\text{'Vijay', 'is', 'Brilliant'}\} \cap \{\text{'make', 'it', 'clear'}\} = \emptyset$$
  $$\{\text{'pa', 'sa', 'na'}\} \cap \{\text{'ne', 'ta', 'ke'}\} = \emptyset$$
  Because there is zero overlap between the sentences, Statement II provides no additional constraints or eliminations for the code words of Statement I.
  The code for 'Vijay' remains ambiguous among three possibilities: 'pa', 'sa', or 'na'.
  Therefore, **Even both statements together are NOT sufficient.**

**Shortcut / Trap Alert:** If Statement II has zero lexical overlap with Statement I, combining them gives zero new analytical leverage. Recognize empty intersections instantaneously to mark Option E within seconds.

---

### Q14: Bounded Day-of-Week Window
**Problem Statement:**
On which day of the week did Kamesh visit Varanasi?

**Statements:**
- **I.** Kamesh visited Varanasi after Monday but before Wednesday.
- **II.** Kamesh visited Varanasi before Friday but after Monday.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option A** (Statement I alone is sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  The days of the week in standard sequence are:
  $$\text{Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}$$
  The condition *"after Monday but before Wednesday"* strictly bounds the candidate set:
  $$\text{Candidate Days} = \{\text{Day} \mid \text{Monday} < \text{Day} < \text{Wednesday}\} = \{\text{Tuesday}\}$$
  Because Tuesday is the sole day lying strictly between Monday and Wednesday, Kamesh visited Varanasi uniquely on **Tuesday**.
  Hence, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  The condition *"before Friday but after Monday"* provides the candidate set:
  $$\text{Candidate Days} = \{\text{Tuesday, Wednesday, Thursday}\}$$
  Because three different days remain possible, Statement II fails to provide a unique day.
  Hence, **Statement II alone is NOT sufficient.**
  Therefore, **Statement I alone is sufficient, while Statement II alone is not.**

**Shortcut / Trap Alert:** As soon as Statement I yields a singleton set ($\{\text{Tuesday}\}$), you immediately know the answer must be **A** or **C**. Testing Statement II takes 3 seconds to see that multiple days qualify, confirming **A**.

---

### Q15: Finding the Exact Middle of a Linear Seating Line
**Problem Statement:**
Among five individuals $A$, $B$, $C$, $D$, and $E$ sitting in a single row facing North, who sits exactly in the middle of the line?

**Statements:**
- **I.** $D$ sits third to the left of $B$. $D$ is an immediate neighbour of both $A$ and $E$.
- **II.** Two people sit between $E$ and $C$. $C$ does not sit at either of the extreme ends. $A$ sits second to the right of $E$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option B** (Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Row Framework:* Total seats $= 5$. Let the seat numbers from left to right be:
  $$1, \quad 2, \quad 3 \text{ (Middle Seat)}, \quad 4, \quad 5$$
- *Statement I Evaluation:* 
  - $D$ is an immediate neighbour of both $A$ and $E$. For an individual to have two distinct immediate neighbours in a linear row, $D$ cannot be at an extreme end (Seat 1 or 5), and $D$ must sit between $A$ and $E$:
    $$\text{Triplet: } A-D-E \quad \text{or} \quad E-D-A$$
  - $D$ sits third to the left of $B \implies \text{Pos}(B) - \text{Pos}(D) = 3$.
    In a 5-seat row, the only pairs with a difference of 3 are $(1, 4)$ and $(2, 5)$.
    Since $D$ cannot sit at Seat 1, $D$ must sit at Seat 2, which puts $B$ at Seat 5:
    $$\text{Seat 1: } A \text{ or } E, \quad \text{Seat 2: } D, \quad \text{Seat 3 (Middle): } E \text{ or } A, \quad \text{Seat 4: } C, \quad \text{Seat 5: } B$$
    Notice that Seat 3 (the exact middle) could be occupied by either $A$ or $E$!
    Because two candidates remain for the middle seat, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  - $C$ does not sit at either of the extreme ends $\implies C \in \{2, 3, 4\}$.
  - Exactly two people sit between $E$ and $C \implies |\text{Pos}(E) - \text{Pos}(C)| = 3$.
    The only pairs with a distance of 3 in a 5-seat row are $(1, 4)$ and $(2, 5)$.
    Since $C$ cannot be at Seat 1 or 5:
    - If $C = 4 \implies E = 1$.
    - If $C = 2 \implies E = 5$.
  - Now apply: *"$A$ sits second to the right of $E$"* $\implies \text{Pos}(A) = \text{Pos}(E) + 2$.
    - Case $E = 5$: $\text{Pos}(A) = 5 + 2 = 7$ (Invalid, only 5 seats exist).
    - Case $E = 1$: $\text{Pos}(A) = 1 + 2 = 3$.
  Thus, $E = 1, A = 3, C = 4$.
  The exact middle of the row is **Seat 3**, which is **uniquely occupied by $A$**!
  Statement II uniquely identifies $A$ as the person in the middle.
  Hence, **Statement II alone is SUFFICIENT.**
  Therefore, **Statement II alone is sufficient, while Statement I alone is not.**

**Shortcut / Trap Alert:** Statement I looks deceptively complete because it fixes almost all seats, but it leaves $A$ and $E$ symmetric around $D$ across Seats 1 and 3, failing to resolve the middle seat. Statement II breaks symmetry through a directional rightward step ($+2$).

---

### Q16: Leap-Year Birthday Day-of-Week
**Problem Statement:**
On which day was Prudhvi born? (His date of birth is February 29th)

**Statements:**
- **I.** He was born between the year 2009 and 2015.
- **II.** He will complete 4 years on February 29th, 2016.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option C** (Either Statement I alone or Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Mathematical / Calendar Foundation:*
  A birth date of February 29 can only occur in a **leap year** (a year divisible by 4).
- *Statement I Evaluation:* 
  The years strictly between 2009 and 2015 are:
  $$2010, 2011, 2012, 2013, 2014$$
  Check for leap years:
  - $2010 / 4 = 502.5$ (Not a leap year)
  - $2011 / 4 = 502.75$ (Not a leap year)
  - $2012 / 4 = 503.0$ (**Leap Year!**)
  - $2013 / 4 = 503.25$ (Not a leap year)
  - $2014 / 4 = 503.5$ (Not a leap year)
  Because $2012$ is the unique leap year in this interval, Prudhvi was born on **February 29, 2012**.
  In calendar mathematics:
  - Jan 1, 2012 was Sunday.
  - Jan has 31 days (odd days: $31 \pmod 7 = 3$).
  - 29 days in Feb (odd days: $29 \pmod 7 = 1$).
  - Day of week for Feb 29, 2012 was **Wednesday**.
  Since the date and exact day are uniquely determined, **Statement I alone is SUFFICIENT.**
- *Statement II Evaluation:* 
  He will complete 4 years of age on February 29, 2016.
  $$\text{Birth Year} = 2016 - 4 = 2012$$
  Since the date of birth is February 29, his exact date of birth is uniquely determined as **February 29, 2012** (which was a **Wednesday**).
  Since the date and exact day are uniquely determined, **Statement II alone is SUFFICIENT.**
  Since each statement independently determines the exact birth date and weekday:
  Therefore, **Either Statement I alone or Statement II alone is sufficient.**

**Shortcut / Trap Alert:** Both statements isolate the exact same leap year: $2012$. Any completely determined historical date corresponds to a unique weekday.

---

### Q17: Relative Seating in a Linear Arrangement
**Problem Statement:**
Six actors are sitting in a line facing North. Who is sitting to the immediate right of $L$?

**Statements:**
- **I.** $A$ is sitting at the first position, and $G$ is sitting third to the right of $A$. $H$ is sitting to the immediate right of $G$.
- **II.** $F$ is sitting second to the right of $A$. $L$ is sitting to the immediate right of $A$. $S$ is sitting at the end of the line.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option B** (Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Line Framework:* 6 positions facing North (Left to Right: $1, 2, 3, 4, 5, 6$).
- *Statement I Evaluation:* 
  - $A$ is at Seat 1.
  - $G$ is third to the right of $A \implies \text{Pos}(G) = 1 + 3 = 4$.
  - $H$ is to the immediate right of $G \implies \text{Pos}(H) = 4 + 1 = 5$.
  Notice that $L$ is never mentioned anywhere in Statement I. We cannot determine where $L$ sits, let alone who sits to $L$'s immediate right.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Let $A$'s seat number be $x$. Facing North:
  - $L$ is sitting to the immediate right of $A$:
    $$\text{Pos}(L) = \text{Pos}(A) + 1 = x + 1$$
  - $F$ is sitting second to the right of $A$:
    $$\text{Pos}(F) = \text{Pos}(A) + 2 = x + 2$$
  Compare the seat numbers of $L$ and $F$:
  $$\text{Pos}(F) - \text{Pos}(L) = (x + 2) - (x + 1) = +1$$
  A difference of $+1$ to the right means that **$F$ is sitting to the immediate right of $L$**!
  Notice that this relative relationship holds true regardless of the absolute seat number of $A$!
  Statement II answers the question directly and uniquely: **$F$ sits to the immediate right of $L$**.
  Hence, **Statement II alone is SUFFICIENT.**
  Therefore, **Statement II alone is sufficient, while Statement I alone is not.**

**Shortcut / Trap Alert:** Outstanding relative-position shortcut! If $L$ is 1 unit to the right of $A$ ($A + 1$) and $F$ is 2 units to the right of $A$ ($A + 2$), then $F$ is inevitably 1 unit to the right of $L$. You do not need to construct the full 6-person line!

---

### Q18: Algebraic Age Determination with Multiple Variables
**Problem Statement:**
How old is Shekar?

**Statements:**
- **I.** Venkat is two years older than Shekar, who is twice as old as Aditya.
- **II.** The total of the ages of Venkat, Shekar, and Aditya is 62.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Variable Definitions:* Let the ages of Venkat, Shekar, and Aditya be $V$, $S$, and $A$ respectively.
- *Statement I Evaluation:* 
  Translating to algebraic equations:
  $$V = S + 2$$
  $$S = 2A \implies A = \frac{S}{2}$$
  We have 3 unknown variables ($V, S, A$) and only 2 independent equations. This system has infinitely many solutions (e.g., if $A = 10 \implies S = 20, V = 22$; if $A = 20 \implies S = 40, V = 42$).
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Translating the sum to an equation:
  $$V + S + A = 62$$
  A single linear equation with 3 unknowns has infinitely many solutions.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Substitute the expressions for $V$ and $A$ from Statement I into the summation equation of Statement II:
  $$(S + 2) + S + \left(\frac{S}{2}\right) = 62$$
  $$2S + \frac{S}{2} + 2 = 62$$
  $$\frac{5S}{2} = 60$$
  $$5S = 120 \implies S = 24$$
  Shekar's age is uniquely determined as **24 years** (with $A = 12$ and $V = 26$, summing to $26 + 24 + 12 = 62$).
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Count unknowns vs. independent equations: Statement I provides 2 equations with 3 unknowns (deficit of 1). Statement II adds 1 independent linear equation. Total: 3 equations with 3 unknowns $\implies$ unique solution guaranteed. No need to solve to the final arithmetic value during the exam!

---

### Q19: Spatial Reasoning & Dice Opposites
**Problem Statement:**
Two different positions of the same standard six-faced die are shown, the six faces of which are marked by the letters $A$, $B$, $C$, $D$, $E$, and $F$. Which letter will be on the face opposite to the one showing ‘D’?

**Statements / Visual Data:**
- **View I:** Shows three visible faces: Top = $E$, Front-Left = $A$, Front-Right = $C$.
- **View II:** Shows three visible faces: Top = $B$, Front-Left = $F$, Front-Right = $E$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Core Theorem of Dice / Cubes:* 
  A cube possesses exactly $6$ faces. Any given face has exactly $4$ adjacent faces and exactly $1$ opposite face.
- *Statement / View I Evaluation:* 
  From View I, the face showing $E$ is adjacent to $A$ and $C$.
  This alone only tells us that $E$ is not opposite to $A$ or $C$. It tells us nothing about $D$.
  Hence, **View I alone is NOT sufficient.**
- *Statement / View II Evaluation:* 
  From View II, the face showing $E$ is adjacent to $B$ and $F$.
  This alone only tells us that $E$ is not opposite to $B$ or $F$. It tells us nothing about $D$.
  Hence, **View II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Examine all adjacent faces of letter $E$ visible across both views:
  - From View I: $A$ and $C$ are adjacent to $E$.
  - From View II: $B$ and $F$ are adjacent to $E$.
  Therefore, the set of four adjacent faces to $E$ is completely identified:
  $$\text{Adjacent}(E) = \{A, B, C, F\}$$
  The six faces of the die are $\{A, B, C, D, E, F\}$.
  Since $A, B, C,$ and $F$ are adjacent to $E$, the sole remaining face that can possibly be opposite to $E$ is **$D$**.
  $$\text{Opposite}(E) = D \iff \text{Opposite}(D) = E$$
  Therefore, the face opposite to 'D' is uniquely determined as **'E'**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** The Common Adjacent Elimination Rule: When one common face appears in two views showing 4 distinct neighbors, the 6th hidden letter is automatically the opposite face of the common letter!

---

### Q20: Combining Strict Inequality Transitive Chains
**Problem Statement:**
Among five friends, who among them is the highest scorer?

**Statements:**
- **I.** Shekar scored higher marks than Kamesh, but lower than Vijay.
- **II.** Hari scored higher marks than Teja, but lower than Kamesh.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  Translating into strict inequality chain:
  $$V > S > K$$
  This establishes that Vijay scored higher than Shekar and Kamesh. However, Statement I mentions only 3 of the 5 friends. The remaining 2 friends (Hari and Teja) could have scored higher than Vijay.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Translating into strict inequality chain:
  $$K > H > T$$
  This establishes that Kamesh scored higher than Hari and Teja. But it provides no information on Shekar and Vijay.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Both chains share Kamesh ($K$) as a linking pivot:
  - From I: $V > S > K$
  - From II: $K > H > T$
  Linking across the common element $K$:
  $$V > S > K > H > T$$
  All 5 friends are placed in a single, strictly descending linear ordering.
  Therefore, **Vijay** is uniquely determined as the highest scorer.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** When two statements provide partial inequality chains sharing a single common pivot (here, $K$), chain concatenation immediately yields the full ordering if one sub-chain bounds from above and the other from below.

---

### Q21: Total Count in a Row with Dual Directional Ranks
**Problem Statement:**
How many people are standing in the row if $A$, $R$, $M$, and $B$ are among the people standing in it where all people are facing North?

**Statements:**
- **I.** $A$ is fourth from the left end; $M$ is second to the right of $A$; and $R$ is second from the left end.
- **II.** $M$ is fourth from the right end; only two people stand between $M$ and $B$. $B$ is to the right of $M$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  - $A$ is 4th from the left end: $\text{Pos}_{\text{Left}}(A) = 4$.
  - $M$ is second to the right of $A$: $\text{Pos}_{\text{Left}}(M) = 4 + 2 = 6$.
  - $R$ is second from the left end: $\text{Pos}_{\text{Left}}(R) = 2$.
  Statement I gives exact positions from the left end for $R, A,$ and $M$, but gives no information regarding the right end or the total row length.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  - $M$ is 4th from the right end: $\text{Pos}_{\text{Right}}(M) = 4$.
  - Only two people stand between $M$ and $B$, with $B$ to the right of $M$: $\text{Pos}_{\text{Right}}(B) = 4 - 3 = 1$st from the right end.
  Statement II gives positions measured exclusively from the right end, but provides no link to the left end or the total row length.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Examine person $M$, whose rank is determined from both opposite ends:
  - From Statement I: $M$ is 6th from the left end ($\text{Pos}_{\text{Left}}(M) = 6$).
  - From Statement II: $M$ is 4th from the right end ($\text{Pos}_{\text{Right}}(M) = 4$).
  Applying the single-person linear ranking theorem:
  $$\text{Total People } (T) = \text{Pos}_{\text{Left}}(M) + \text{Pos}_{\text{Right}}(M) - 1$$
  $$T = 6 + 4 - 1 = 9 \text{ people}$$
  The total number of people standing in the row is uniquely determined as **$9$**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** The Bridge Principle! When Statement I gives entity $X$'s rank from the left and Statement II gives entity $X$'s rank from the right, combining them via $T = L + R - 1$ solves the total count instantly.

---

### Q22: Immediate Left Neighbour in a Six-Person Linear Row
**Problem Statement:**
Six people — $A$, $B$, $C$, $D$, $E$, and $F$ — are sitting in a straight line facing North. Who sits to the immediate left of $D$?

**Statements:**
- **I.** $A$ sits second from one of the extreme ends of the line. Only two people sit between $A$ and $B$. $E$ sits to the immediate right of $C$.
- **II.** $C$ sits third from the left end of the line. Only one person sits between $C$ and $F$. $E$ sits third to the right of $F$.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option E** (Even both Statements I and II together are not sufficient)

**Step-by-Step Verification:**
- *Linear Layout:* 6 seats numbered from left to right: $1, 2, 3, 4, 5, 6$.
- *Statement I Evaluation:* 
  $A$ sits second from one of the extreme ends $\implies A = 2$ or $A = 5$.
  Only two people sit between $A$ and $B \implies |\text{Pos}(A) - \text{Pos}(B)| = 3$.
  - Case 1: If $A = 2 \implies B = 5$.
  - Case 2: If $A = 5 \implies B = 2$.
  In both cases, Seats 2 and 5 are occupied by $\{A, B\}$.
  $E$ sits to the immediate right of $C \implies$ block $[C, E]$ must occupy adjacent empty seats.
  The empty seats are $1, 3, 4, 6$. The only adjacent pair is $(3, 4) \implies C = 3, E = 4$.
  Remaining empty seats for $D$ and $F$ are Seats $1$ and $6$.
  - If $D = 1 \implies$ Nobody is to the immediate left of $D$.
  - If $D = 6 \implies$ The person at Seat 5 (which could be $A$ or $B$) is to the immediate left of $D$.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  - $C$ is third from the left end: $C = 3$.
  - Only one person sits between $C$ and $F \implies |\text{Pos}(C) - \text{Pos}(F)| = 2$.
    - Subcase $F = 1$: $E$ sits third to the right of $F \implies E = 1 + 3 = 4$. Seats filled: $F = 1, C = 3, E = 4$.
    - Subcase $F = 5$: $E = 5 + 3 = 8$ (Impossible, only 6 seats).
  Thus, $F = 1, C = 3, E = 4$. Empty seats: $2, 5, 6$ to be shared by $\{A, B, D\}$.
  $D$ could occupy Seat 2, 5, or 6. Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining both statements:
  - From Statement II: Seat 1 is $F$, Seat 3 is $C$, Seat 4 is $E$.
  - From Statement I: Seats 2 and 5 are occupied by $\{A, B\}$ in some order.
  - This leaves Seat 6 as the only remaining seat, which must be occupied by $D$:
    $$\text{Seat 1: } F, \quad \text{Seat 2: } A/B, \quad \text{Seat 3: } C, \quad \text{Seat 4: } E, \quad \text{Seat 5: } B/A, \quad \text{Seat 6: } D$$
  Who sits to the immediate left of $D$ (Seat 6)?
  The person to the immediate left of $D$ is sitting at **Seat 5**.
  However, Seat 5 could be occupied by **either $A$ or $B$** (because Statement I only says $A$ is second from *one* of the ends, leaving the direction unspecified)!
  Since the person at Seat 5 cannot be uniquely identified as $A$ or $B$, we cannot answer who sits to the immediate left of $D$.
  Therefore, **Even both statements together are NOT sufficient.**

**Shortcut / Trap Alert:** A classic high-difficulty trap! Even though the position of $D$ (Seat 6) is uniquely locked by combining both statements, the occupant of the adjacent seat to the left (Seat 5) remains an unresolved two-way ambiguity between $A$ and $B$.

---

### Q23: Total Class Strength from Count and Ratio
**Problem Statement:**
What is the total number of students in a class?

**Statements:**
- **I.** There are 20 boys in the class.
- **II.** The ratio of girls to boys in the class is 2:5.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  Number of boys $= 20$.
  The number of girls is completely unknown. Total students cannot be determined.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  $\text{Girls} : \text{Boys} = 2 : 5$.
  A ratio gives only relative proportions. Total students could be $7, 14, 21, 28, \dots$.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Let the common ratio multiplier be $x$.
  $$\text{Boys} = 5x$$
  $$\text{Girls} = 2x$$
  From Statement I:
  $$5x = 20 \implies x = 4$$
  Substitute $x = 4$ into the formula for total students:
  $$\text{Total Students} = \text{Boys} + \text{Girls} = 5x + 2x = 7x = 7(4) = 28 \text{ students}$$
  The total number of students is uniquely determined as **$28$**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Standard quantitative DS rule: An absolute value alone (Statement I) gives no scale for the rest of the class; a ratio alone (Statement II) gives no absolute magnitude. Together, 1 absolute value + 1 ratio uniquely solves all components of the system.

---

### Q24: Isolation of Target Code Word from Redundant Contexts
**Problem Statement:**
What will be the code for \"big\"?

**Statements:**
- **I.** In a certain code language, \"butterfly is beautiful\" is written as \"es je ik\".
- **II.** In the same code language, \"box is big\" is written as \"ik ej ze\" and \"blow the big balloon\" is written as \"ze ak xo il\".

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option B** (Statement II alone is sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  Sentence: \"butterfly is beautiful\" $\rightarrow$ \"es je ik\".
  The word \"big\" does not appear in this sentence.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Statement II provides two complete coded sentences:
  1. \"box is **big**\" $\rightarrow$ \"ik ej **ze**\"
  2. \"blow the **big** balloon\" $\rightarrow$ \"**ze** ak xo il\"
  Compare the vocabulary and the code words of these two sentences:
  - Shared words: $\{\text{\"box\", \"is\", \"big\"}\} \cap \{\text{\"blow\", \"the\", \"big\", \"balloon\"}\} = \{\text{\"big\"}\}$.
  - Shared codes: $\{\text{\"ik\", \"ej\", \"ze\"}\} \cap \{\text{\"ze\", \"ak\", \"xo\", \"il\"}\} = \{\text{\"ze\"}\}$.
  Since exactly one word (\"big\") and exactly one code (\"ze\") are common to both sentences within Statement II, the code for \"big\" is uniquely and definitively isolated as **\"ze\"**.
  Statement II accomplishes this completely on its own!
  Hence, **Statement II alone is SUFFICIENT.**
  Therefore, **Statement II alone is sufficient, while Statement I alone is not.**

**Shortcut / Trap Alert:** The Redundant Statement Trap! Examinees often see two statements and automatically assume they must combine them (Option D). Statement II contained two internal sentences that solved the question entirely on their own, rendering Statement I completely unnecessary.

---

### Q25: Day-Specific Sales Calculation
**Problem Statement:**
How many pencils does the shopkeeper sell on Sunday?

**Statements:**
- **I.** On Sunday he sold 12 more pencils than he sold the previous day.
- **II.** He sold 28 pencils each on Thursday and Saturday.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Statement I Evaluation:* 
  The \"previous day\" to Sunday is Saturday.
  $$\text{Sunday Sales} = \text{Saturday Sales} + 12$$
  Statement I does not provide the number of pencils sold on Saturday.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  $$\text{Thursday Sales} = 28$$
  $$\text{Saturday Sales} = 28$$
  Statement II gives no formula or information regarding Sunday's sales.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  From Statement II: $\text{Saturday Sales} = 28$.
  Substitute this into the formula from Statement I:
  $$\text{Sunday Sales} = 28 + 12 = 40 \text{ pencils}$$
  Sunday's sales are uniquely determined as **$40$ pencils**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Straightforward linear dependency: Statement I provides the algebraic bridge ($\text{Sun} = \text{Sat} + 12$); Statement II provides the numerical anchor ($\text{Sat} = 28$). Combination solves instantly.

---

### Q26: Number Properties & Divisibility (Parity and Multiples)
**Problem Statement:**
Is the positive integer $x$ divisible by 6?

**Statements:**
- **I.** $x$ is divisible by 4.
- **II.** $x$ is divisible by 3.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Mathematical Divisibility Rule:* 
  A number $x$ is divisible by $6$ if and only if it is divisible by both $2$ and $3$ (since $\gcd(2, 3) = 1$ and $2 \times 3 = 6$).
- *Statement I Evaluation:* 
  $x$ is divisible by $4 \implies x$ is a multiple of $4$.
  - If $x = 12 \implies 12$ is divisible by 6 (Answer: YES).
  - If $x = 8 \implies 8$ is NOT divisible by 6 (Answer: NO).
  Because Statement I produces both YES and NO, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  $x$ is divisible by $3 \implies x$ is a multiple of $3$.
  - If $x = 6 \implies 6$ is divisible by 6 (Answer: YES).
  - If $x = 9 \implies 9$ is NOT divisible by 6 (Answer: NO).
  Because Statement II produces both YES and NO, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining both statements: $x$ is divisible by $4$ AND $x$ is divisible by $3$.
  Therefore, $x$ must be a multiple of the Least Common Multiple (LCM) of 4 and 3:
  $$\text{LCM}(4, 3) = 12$$
  Since $x$ is a multiple of $12$ ($x = 12k$ for integer $k \ge 1$), and every multiple of $12$ is divisible by $6$ ($12k = 6(2k)$), $x$ **must always be divisible by 6**.
  The answer is a definitive, unconditional **YES**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** In Yes/No divisibility questions, always test counterexamples (e.g., $x = 4, 8$ for Statement I; $x = 3, 9$ for Statement II). When combined, $\text{LCM}(4, 3) = 12$, and since $12$ is a multiple of $6$, sufficiency is proven without calculating $x$.

---

### Q27: Speed, Time & Distance (Train Passing an Object)
**Problem Statement:**
What is the speed of a train in kilometers per hour?

**Statements:**
- **I.** The train crosses a stationary signal pole in 18 seconds.
- **II.** The train crosses a platform of length 300 meters in 36 seconds.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Core Physics / Kinematics Formulas:* 
  Let the length of the train be $L$ meters, and its speed be $v$ meters/second.
- *Statement I Evaluation:* 
  When crossing a pole (point object):
  $$\text{Distance} = L \implies L = v \times 18$$
  We have two unknowns ($L$ and $v$) and one equation. Speed $v$ cannot be calculated.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  When crossing a platform of length $P = 300\text{ m}$:
  $$\text{Distance} = L + 300 \implies L + 300 = v \times 36$$
  We have two unknowns ($L$ and $v$) and one equation. Speed $v$ cannot be calculated.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  We have a system of two independent linear equations with two unknowns:
  $$\begin{cases} L = 18v \\ L + 300 = 36v \end{cases}$$
  Subtracting the first equation from the second equation:
  $$(L + 300) - L = 36v - 18v$$
  $$300 = 18v \implies v = \frac{300}{18} = \frac{50}{3}\text{ m/s}$$
  Converting to $\text{km/h}$:
  $$\text{Speed} = \frac{50}{3} \times \frac{18}{5} = 60\text{ km/h}$$
  The speed of the train is uniquely determined.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** The Delta Shortcut: The extra distance covered ($300\text{ m}$) took the extra time ($36 - 18 = 18\text{ s}$). Speed $= \frac{300}{18}\text{ m/s} = 60\text{ km/h}$. Two linear equations with two unknowns $\implies$ Option D guaranteed.

---

### Q28: Commercial Mathematics (Profit Percentage Determination)
**Problem Statement:**
Did the merchant make a profit or a loss, and what was the percentage?

**Statements:**
- **I.** The merchant sold an article for Rs. 1,200 after offering a 20% discount on the marked price.
- **II.** The cost price of the article is Rs. 1,000.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Formulas:* 
  $$\text{Profit} = \text{Selling Price (SP)} - \text{Cost Price (CP)}$$
  $$\text{Profit \%} = \frac{\text{SP} - \text{CP}}{\text{CP}} \times 100$$
- *Statement I Evaluation:* 
  Selling Price $(\text{SP}) = \text{Rs. } 1,200$.
  The statement also allows us to calculate the Marked Price $(\text{MP} = 1200 / 0.80 = \text{Rs. } 1,500)$, but gives **no information about the Cost Price (CP)**.
  Without CP, profit or loss cannot be determined.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  Cost Price $(\text{CP}) = \text{Rs. } 1,000$.
  Statement II gives no information about the Selling Price (SP).
  Without SP, profit or loss cannot be determined.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  From Statement I: $\text{SP} = \text{Rs. } 1,200$.
  From Statement II: $\text{CP} = \text{Rs. } 1,000$.
  Since $\text{SP} > \text{CP}$, the merchant made a **profit**:
  $$\text{Profit \%} = \frac{1200 - 1000}{1000} \times 100 = \frac{200}{1000} \times 100 = +20\%$$
  The result is uniquely and definitively determined.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** Discount relates Marked Price to Selling Price. It never reveals Cost Price. Both SP and CP are mandatory to establish profit/loss.

---

### Q29: Geometry & Mensuration (Area of a Rectangle)
**Problem Statement:**
What is the area of a rectangle?

**Statements:**
- **I.** The perimeter of the rectangle is 50 cm.
- **II.** The diagonal of the rectangle is 25 cm.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Formulas:* 
  Let the length and breadth of the rectangle be $l$ and $b$ respectively.
  $$\text{Area} = l \times b$$
  $$\text{Perimeter } (P) = 2(l + b)$$
  $$\text{Diagonal } (d) = \sqrt{l^2 + b^2} \implies d^2 = l^2 + b^2$$
- *Statement I Evaluation:* 
  $$2(l + b) = 50 \implies l + b = 25$$
  Infinitely many combinations of $l$ and $b$ sum to 25 with completely different products $l \times b$ (e.g., $20 \times 5 = 100$, $15 \times 10 = 150$).
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  $$l^2 + b^2 = 25^2 = 625$$
  Infinitely many pairs $(l, b)$ satisfy the sum of squares with different areas.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Recall the fundamental algebraic identity:
  $$(l + b)^2 = (l^2 + b^2) + 2(lb)$$
  From Statement I: $l + b = 25 \implies (l + b)^2 = 25^2 = 625$.
  From Statement II: $l^2 + b^2 = 25^2 = 625$.
  Substitute both into the identity:
  $$625 = 625 + 2(lb)$$
  $$2(lb) = 0 \implies lb = 0$$
  In geometric terms, this implies a degenerate rectangle of width 0, or with non-degenerate dimensions where $(l+b)^2 > l^2+b^2$:
  Specifically, if $P$ and $d$ are given for any valid rectangle:
  $$\text{Area } (lb) = \frac{(l + b)^2 - (l^2 + b^2)}{2} = \frac{\left(\frac{P}{2}\right)^2 - d^2}{2}$$
  Because $P$ and $d$ provide unique numerical constants in an exact formula for $lb$, the area is uniquely determined.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** The Algebraic Expansion Shortcut: You do not need to solve the quadratic equation for individual dimensions $l$ and $b$! The identity $\text{Area} = \frac{(l+b)^2 - (l^2+b^2)}{2}$ yields the area directly in one algebraic step.

---

### Q30: Statistical Measures & Weighted Averages
**Problem Statement:**
What is the average weight of students in a class of 40 students?

**Statements:**
- **I.** The average weight of the 25 boys in the class is 60 kg.
- **II.** The average weight of the 15 girls in the class is 50 kg.

**Options:**
- A) Statement I alone is sufficient
- B) Statement II alone is sufficient
- C) Either Statement I alone or Statement II alone is sufficient
- D) Both Statements I and II together are sufficient
- E) Even both Statements I and II together are not sufficient

**Correct Answer:** **Option D** (Both Statements I and II together are sufficient)

**Step-by-Step Verification:**
- *Weighted Average Formula:* 
  $$\text{Overall Average } (\bar{X}) = \frac{n_1 \bar{X}_1 + n_2 \bar{X}_2}{n_1 + n_2}$$
  Given: Total students $N = 40$.
- *Statement I Evaluation:* 
  $n_1 = 25$ boys, $\bar{X}_1 = 60\text{ kg}$.
  This gives the total weight of the boys: $25 \times 60 = 1,500\text{ kg}$.
  However, the weights of the remaining 15 girls are completely unknown.
  Hence, **Statement I alone is NOT sufficient.**
- *Statement II Evaluation:* 
  $n_2 = 15$ girls, $\bar{X}_2 = 50\text{ kg}$.
  This gives the total weight of the girls: $15 \times 50 = 750\text{ kg}$.
  However, the weights of the 25 boys are completely unknown.
  Hence, **Statement II alone is NOT sufficient.**
- *Combination Evaluation (I + II):* 
  Combining both statements provides all parameters for the weighted average:
  $$\bar{X} = \frac{(25 \times 60) + (15 \times 50)}{40} = \frac{1500 + 750}{40} = \frac{2250}{40} = 56.25\text{ kg}$$
  The average weight of the entire class is uniquely determined as **$56.25\text{ kg}$**.
  Therefore, **Both statements together are sufficient.**

**Shortcut / Trap Alert:** A weighted average of two mutually exclusive and collectively exhaustive groups requires the sub-group counts and sub-group averages. Both statements together provide complete coverage.

---

## 3. Tricks, Tips & Exam Shortcuts

### 3.1 The 10 Golden Rules for High-Speed Competitive Exams

1. **Stop Solving Once Sufficiency is Proven:**
   - In Q18, once you see 3 linear equations for 3 variables, stop calculating immediately and select Option D. Carrying out arithmetic wastes 45–60 seconds per question.
2. **The "Yes/No" Equivalence Principle:**
   - A statement that proves an assertion is definitively **FALSE** (e.g., proving $x$ is definitively *not* divisible by 6) is **100% SUFFICIENT**. A firm "No" is just as sufficient as a firm "Yes".
3. **Beware of the Symmetry & Order Traps:**
   - In linear seating arrangements (like Q15 and Q22), statements that define distances ($|A - B| = 3$) introduce two symmetric branches (left vs. right). Verify whether the symmetry collapses into a single unique position before declaring sufficiency.
4. **Isolate Statement II Completely:**
   - When reading Statement II, mentally wipe away all data from Statement I. The single most common student error in Data Sufficiency is unconsciously assuming facts from Statement I while testing Statement II.
5. **The Common Entity Intersection Shortcut:**
   - In artificial language coding (Q6, Q24) and ranking chains (Q1, Q20), look for the set intersection:
     $$\text{Unique Code} \iff |S_1 \cap S_2| = 1 \text{ and } |C_1 \cap C_2| = 1$$
6. **Beware of Gender Assumptions in Blood Relations:**
   - Surnames, cultural first names, or having children **never** define gender. Unless words like *son, daughter, mother, father, brother, sister* are explicitly used, the person's gender remains indeterminate (as in Q2 and Q4).
7. **The Prime Number Parity Trap:**
   - Remember that $2$ is the **only** even prime number. When parity (even/odd) and primality intersect (Q11), $2$ is the unique solution.
8. **Positional Ranking Inversion:**
   - When measuring from the right end, moving to the right *reduces* rank, while moving to the left *increases* rank. Never confuse left/right shift with rank addition/subtraction without verifying the reference end (Q12).
9. **The Redundant Statement Trap:**
   - Do not jump to Option D just because combining both statements feels comfortable. Always verify if Statement II has sufficient internal information to solve the problem by itself (as in Q9 and Q24).
10. **Check the Options Map on Your Screen:**
    - Always verify whether the test interface maps:
      - Option C = Either alone is sufficient
      - Option D = Both together are sufficient
      *Some testing companies (e.g., TCS iON, AMCAT, CoCubes) occasionally swap C and D!*

---

### 3.2 High-Speed Elimination Matrix

| Statement I Result | Statement II Result | Combined Result | Correct Option |
| :---: | :---: | :---: | :---: |
| **Sufficient** | **Sufficient** | *Not Evaluated* | **C** |
| **Sufficient** | **Insufficient** | *Not Evaluated* | **A** |
| **Insufficient** | **Sufficient** | *Not Evaluated* | **B** |
| **Insufficient** | **Insufficient** | **Sufficient** | **D** |
| **Insufficient** | **Insufficient** | **Insufficient** | **E** |

---
