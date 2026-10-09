# 07. Ranking and Sequence

## 1. Theory and Core Formulas

Ranking and Sequence is a vital area of logical reasoning that tests linear positioning, relative orderings, overlap dynamics, position interchanges, and comparative inequalities. A structured, mathematical approach avoids common off-by-one errors and enables rapid problem-solving.

---

### 1.1 Single-Person Positional Formulas
When considering a single individual whose rank is known from both opposite ends of a linear row:
- **Total Count ($T$):**
  $$T = L + R - 1$$
  $$T = \text{Top} + \text{Bottom} - 1 = \text{Front} + \text{Rear} - 1$$
  *Why subtract 1?* The reference person is counted twice—once when counting from the left and once when counting from the right.

- **Finding Position from an Opposite End:**
  $$L = T - R + 1$$
  $$R = T - L + 1$$
  $$\text{Bottom} = T - \text{Top} + 1$$

- **Exact Middle Position (when $T$ is odd):**
  $$\text{Middle Position} = \frac{T + 1}{2} \quad \text{(from either end)}$$

---

### 1.2 Two Persons: Determining People In-Between
Given two persons, $A$ (ranked $L_A$ from the left) and $B$ (ranked $R_B$ from the right) in a row of total $T$ people:
First, calculate the positional sum:
$$\text{Sum} = L_A + R_B$$

#### Case 1: Simple / Non-Overlapping Arrangement ($\text{Sum} < T$)
$A$ and $B$ sit on their respective sides without crossing each other.
$$\text{Between} = T - (L_A + R_B)$$

#### Case 2: Overlapping / Crossed Arrangement ($\text{Sum} > T$)
$A$ and $B$ cross each other's positions. In the sum $(L_A + R_B)$, the individuals sitting between them are counted twice, and $A$ and $B$ themselves are counted twice.
$$\text{Between} = (L_A + R_B) - T - 2$$
$$\text{Total } T = (L_A + R_B) - \text{Between} - 2$$

#### Case 3: Boundary Conditions
- If $L_A + R_B = T$: $A$ and $B$ are strictly adjacent (0 people between them).
- If $L_A + R_B = T + 1$: Both ranks point to the exact same seat.

---

### 1.3 Maximum and Minimum Strength of a Row
Given $L_A$ (rank from left), $R_B$ (rank from right), and $n$ people between them:
- **Maximum Possible Strength ($T_{\max}$):**
  Occurs in a **non-overlapping** layout where $A$ is to the left of $B$:
  $$T_{\max} = L_A + R_B + n$$

- **Minimum Possible Strength ($T_{\min}$):**
  Occurs in an **overlapping** layout where $A$ and $B$ have crossed:
  $$T_{\min} = L_A + R_B - n - 2$$
  *Validity Criterion for Overlap:* $T_{\min} \ge \max(L_A, R_B)$, which requires $n \le \min(L_A, R_B) - 2$.

- **Difference Between Maximum and Minimum:**
  $$\Delta T = T_{\max} - T_{\min} = (L_A + R_B + n) - (L_A + R_B - n - 2) = 2n + 2$$
  *Note:* The difference is independent of individual ranks; it depends solely on the number of people between them!

---

### 1.4 Position Interchange (Swapping Places)
When Person $A$ and Person $B$ swap places:
1. $A$'s new position is physically identical to $B$'s original position.
2. If $A$'s new position from left is $L_A'$ and $B$'s original position from right was $R_B$:
   $$T = L_A' + R_B - 1$$
3. **Equal Shift Principle:** Both individuals experience the exact same numerical change in rank:
   $$\Delta = |L_A' - L_A| = |R_B' - R_B|$$
   $$R_B' = R_B + (L_A' - L_A)$$
4. **Number of people sitting between them:**
   $$\text{Between} = |L_A' - L_A| - 1$$

---

### 1.5 Comparative Sequences (Inequalities)
For ranking based on height, weight, marks, or age:
- Convert all descriptive statements into consistent strict inequalities ($A > B > C$).
- **"Taller than only $X$ and $Y$":** The person is strictly 3rd from the bottom in a ranking (only two individuals are below them; everyone else is above).
- **"Shorter than only $Z$":** The person is strictly 2nd from the top ($Z$ is the unique maximum).

---

### 1.6 Alphanumeric & Symbol Sequences
- **Preceded by $X$:** $X$ appears immediately to the left ($X \rightarrow \text{Target}$).
- **Followed by $Y$:** $Y$ appears immediately to the right ($\text{Target} \rightarrow Y$).
- **Target Pattern:** $\text{Preceding Element} \rightarrow \text{Target Element} \rightarrow \text{Following Element}$.

---

## 2. Comprehensive Question Bank & Detailed Solutions

### Q1
Rohan ranks 7th from the left end and 14th from the right end of a row. How many people are there in the row?  
A) 19  
B) 20  
C) 21  
D) 22  

**Correct Answer:** **B) 20**

**Step-by-Step Explanation:**
1. Rohan is counted from both the left and right ends.
2. Apply the single-person total formula:
   $$\text{Total} = \text{Left} + \text{Right} - 1$$
3. Substitute the given values:
   $$\text{Total} = 7 + 14 - 1 = 20$$
4. Thus, there are 20 people in the row.

**Shortcut / Trick:**
Whenever both ranks for the same person are given, add them and subtract 1: $7 + 14 - 1 = 20$.

---

### Q2
In a class of 40 students, Priya is ranked 15th from the top. What is her rank from the bottom?  
A) 25  
B) 26  
C) 24  
D) 27  

**Correct Answer:** **B) 26**

**Step-by-Step Explanation:**
1. Total number of students $T = 40$.
2. Priya's rank from top $= 15$.
3. Apply the reverse rank formula:
   $$\text{Bottom Rank} = \text{Total} - \text{Top Rank} + 1$$
4. Calculate:
   $$\text{Bottom Rank} = 40 - 15 + 1 = 25 + 1 = 26$$
5. Priya is ranked 26th from the bottom.

**Shortcut / Trick:**
Total minus known rank plus 1: $40 - 15 + 1 = 26$.

---

### Q3
A is taller than B, but shorter than C. D is taller than C. Who is the tallest among them?  
A) A  
B) B  
C) C  
D) D  

**Correct Answer:** **D) D**

**Step-by-Step Explanation:**
1. Break down each comparative statement:
   - "A is taller than B, but shorter than C": $C > A > B$.
   - "D is taller than C": $D > C$.
2. Combine into a unified inequality chain:
   $$D > C > A > B$$
3. D is at the very top of the chain, making D the tallest.

**Shortcut / Trick:**
Eliminate anyone who is shorter than someone else: B is shorter than A; A is shorter than C; C is shorter than D. Only D has nobody taller than him.

---

### Q4
In a row of 30 people standing in a line for a ticket, X is 5th from the left end and Y is 10th from the right end. How many people are standing between X and Y?  
A) 15  
B) 14  
C) 16  
D) 17  

**Correct Answer:** **A) 15**

**Step-by-Step Explanation:**
1. Given: $T = 30$, $L_X = 5$, $R_Y = 10$.
2. Compute the sum of positions:
   $$\text{Sum} = L_X + R_Y = 5 + 10 = 15$$
3. Since $\text{Sum} (15) < T (30)$, this is a **non-overlapping** arrangement.
4. Apply the non-overlapping formula:
   $$\text{Between} = T - (L_X + R_Y) = 30 - 15 = 15$$
5. There are 15 people standing between X and Y.

**Shortcut / Trick:**
Sum of ranks $= 15 < 30$. People between $= 30 - 15 = 15$.

---

### Q5
P is heavier than Q but lighter than R. S is lighter than Q. Who is the lightest among all of them?  
A) P  
B) Q  
C) R  
D) S  

**Correct Answer:** **D) S**

**Step-by-Step Explanation:**
1. Analyze the given relations:
   - "P is heavier than Q but lighter than R": $R > P > Q$.
   - "S is lighter than Q": $Q > S$.
2. Combine the inequalities:
   $$R > P > Q > S$$
3. S is at the bottom of the weight ordering, hence S is the lightest.

**Shortcut / Trick:**
Eliminate anyone heavier than another person: R, P, and Q are all heavier than at least one person. S is lighter than Q, with nobody lighter than S.

---

### Q6
If you are standing exactly in the middle of a row of 21 people, what is your position from either the left or the right end?  
A) 10th  
B) 11th  
C) 12th  
D) 13th  

**Correct Answer:** **B) 11th**

**Step-by-Step Explanation:**
1. Total people $T = 21$.
2. For an odd total, the exact middle position from either end is:
   $$\text{Middle Position} = \frac{T + 1}{2} = \frac{21 + 1}{2} = 11$$
3. There are 10 people to your left and 10 people to your right:
   $$10 + 1 + 10 = 21$$
4. Therefore, your rank is 11th from both ends.

**Shortcut / Trick:**
$(21 + 1) / 2 = 11\text{th}$.

---

### Q7
A row has 50 trees. A mango tree is 22nd from the left end. What is its position from the right end?  
A) 28th  
B) 29th  
C) 30th  
D) 27th  

**Correct Answer:** **B) 29th**

**Step-by-Step Explanation:**
1. Total trees $T = 50$.
2. Position from left $L = 22$.
3. Apply the position from opposite end formula:
   $$R = T - L + 1 = 50 - 22 + 1 = 28 + 1 = 29$$
4. The mango tree is 29th from the right end.

**Shortcut / Trick:**
$50 - 22 + 1 = 29\text{th}$.

---

### Q8
M runs faster than N. L runs faster than M but slower than O. Who is the slowest runner?  
A) M  
B) N  
C) L  
D) O  

**Correct Answer:** **B) N**

**Step-by-Step Explanation:**
1. Express the statements in speed inequalities:
   - "M runs faster than N": $M > N$.
   - "L runs faster than M but slower than O": $O > L > M$.
2. Combine into a single chain:
   $$O > L > M > N$$
3. N is at the lowest end of the speed ranking, making N the slowest runner.

**Shortcut / Trick:**
O is faster than L, L is faster than M, M is faster than N. N is slower than all others.

---

### Q9
In a class test, Amit ranks 12th from the top and 25th from the bottom. How many students took the test?  
A) 36  
B) 37  
C) 38  
D) 35  

**Correct Answer:** **A) 36**

**Step-by-Step Explanation:**
1. Top rank $= 12$, Bottom rank $= 25$.
2. Apply the total formula for a single person:
   $$\text{Total} = \text{Top} + \text{Bottom} - 1$$
3. Calculate:
   $$\text{Total} = 12 + 25 - 1 = 36$$
4. 36 students took the test.

**Shortcut / Trick:**
$12 + 25 - 1 = 36$.

---

### Q10
In a row of boys, Arun is 10th from the left and Varun is 15th from the right. If they swap their positions, Arun becomes 15th from the left. What is the total number of boys in the row?  
A) 28  
B) 29  
C) 30  
D) 31  

**Correct Answer:** **B) 29**

**Step-by-Step Explanation:**
1. Initial positions: Arun $= 10\text{th}$ from left, Varun $= 15\text{th}$ from right.
2. After the swap, Arun occupies Varun's original position.
3. This specific seat is:
   - $15\text{th}$ from the right (Varun's original position).
   - $15\text{th}$ from the left (Arun's new position).
4. Apply the total formula to this single seat:
   $$\text{Total} = \text{Left} + \text{Right} - 1 = 15 + 15 - 1 = 29$$
5. There are 29 boys in the row.

**Shortcut / Trick:**
Total $= (\text{Arun's new left}) + (\text{Varun's original right}) - 1 = 15 + 15 - 1 = 29$.

---

### Q11
In a row of 40 students facing North, Ravi is 25th from the left end and Sumit is 22nd from the right end. How many students are sitting between Ravi and Sumit?  
A) 3  
B) 4  
C) 5  
D) 6  

**Correct Answer:** **C) 5**

**Step-by-Step Explanation:**
1. Given: $T = 40$, $L_{\text{Ravi}} = 25$, $R_{\text{Sumit}} = 22$.
2. Sum of positions:
   $$\text{Sum} = 25 + 22 = 47$$
3. Since $\text{Sum} (47) > T (40)$, the positions **overlap** (Ravi and Sumit have crossed each other).
4. Apply the overlapping formula:
   $$\text{Between} = (L + R) - T - 2$$
5. Calculate:
   $$\text{Between} = 47 - 40 - 2 = 5$$
6. Exactly 5 students are sitting between Ravi and Sumit.

**Shortcut / Trick:**
Overlap case: $(25 + 22) - 40 - 2 = 47 - 42 = 5$.

---

### Q12
In a row of children, A is 12th from the left and B is 18th from the right. If they interchange their positions, A becomes 25th from the left. What is the total number of children in the row?  
A) 41  
B) 42  
C) 43  
D) 44  

**Correct Answer:** **B) 42**

**Step-by-Step Explanation:**
1. When A and B swap positions, A moves to B's original seat.
2. B's seat is known to be:
   - $18\text{th}$ from the right (B's original rank).
   - $25\text{th}$ from the left (A's new rank).
3. Compute total:
   $$\text{Total} = L_A' + R_B - 1 = 25 + 18 - 1 = 42$$
4. There are 42 children in the row.

**Shortcut / Trick:**
Total $= A_{\text{new}} + B_{\text{old}} - 1 = 25 + 18 - 1 = 42$.

---

### Q13
Among five friends, P is heavier than Q but lighter than R. S is lighter than T but heavier than R. Who is exactly in the middle when they are arranged in descending order of their weights?  
A) P  
B) Q  
C) R  
D) S  

**Correct Answer:** **C) R**

**Step-by-Step Explanation:**
1. Translate relationships into inequalities:
   - "P is heavier than Q but lighter than R": $R > P > Q$.
   - "S is lighter than T but heavier than R": $T > S > R$.
2. Connect the two chains via R:
   $$T > S > R > P > Q$$
3. In descending order:
   - 1st (Heaviest): T
   - 2nd: S
   - 3rd (Middle): R
   - 4th: P
   - 5th (Lightest): Q
4. R is exactly in the middle.

**Shortcut / Trick:**
Chain: $T > S > R > P > Q$. The middle (3rd of 5) element is R.

---

### Q14
In a queue of 50 people, X is 15th from the right end. If X shifts 5 places to the left, what will be X's new position from the left end?  
A) 30th  
B) 31st  
C) 32nd  
D) 33rd  

**Correct Answer:** **B) 31st**

**Step-by-Step Explanation:**
- **Method 1 (Tracking position from left):**
  1. Find X's initial position from the left:
     $$L = T - R + 1 = 50 - 15 + 1 = 36\text{th}$$
  2. Shifting 5 places towards the left moves X closer to the left end (decreases rank from left):
     $$L_{\text{new}} = 36 - 5 = 31\text{st}$$
- **Method 2 (Tracking position from right):**
  1. Moving 5 places to the left means moving 5 places further from the right end:
     $$R_{\text{new}} = 15 + 5 = 20\text{th}$$
  2. Convert to position from left:
     $$L_{\text{new}} = 50 - 20 + 1 = 31\text{st}$$

**Shortcut / Trick:**
$L_{\text{new}} = (50 - 15 + 1) - 5 = 36 - 5 = 31\text{st}$.

---

### Q15
Rahul is 14th from the left end of a row and Shyam is 17th from the right end. If there are exactly 5 people sitting between them, what is the minimum possible number of people in the row?  
A) 36  
B) 31  
C) 26  
D) 24  

**Correct Answer:** **D) 24**

**Step-by-Step Explanation:**
1. For minimum row strength, Rahul and Shyam must be in an **overlapping** arrangement.
2. Apply the minimum total formula:
   $$T_{\min} = L + R - \text{Between} - 2$$
3. Substitute $L = 14$, $R = 17$, $\text{Between} = 5$:
   $$T_{\min} = 14 + 17 - 5 - 2 = 31 - 7 = 24$$
4. Verify validity: $\text{Between} \le \min(L, R) - 2 \implies 5 \le 14 - 2 = 12$ (valid). Also $T_{\min} = 24 \ge \max(14, 17) = 17$ (valid).
5. The minimum possible number of people is 24.

**Shortcut / Trick:**
Minimum strength $= L + R - \text{Between} - 2 = 14 + 17 - 5 - 2 = 24$.

---

### Q16
In a class of 47 students, Amit is 12th from the left end and Bimal is 14th from the right end. If Chandan sits exactly in the middle of Amit and Bimal, what is Chandan's position from the left end?  
A) 21st  
B) 22nd  
C) 23rd  
D) 24th  

**Correct Answer:** **C) 23rd**

**Step-by-Step Explanation:**
1. Express both Amit and Bimal's positions from the **left end**:
   - Amit: $L_{\text{Amit}} = 12$
   - Bimal: $L_{\text{Bimal}} = T - R + 1 = 47 - 14 + 1 = 34$
2. Since Chandan sits exactly halfway between Amit ($12$) and Bimal ($34$):
   $$L_{\text{Chandan}} = \frac{L_{\text{Amit}} + L_{\text{Bimal}}}{2} = \frac{12 + 34}{2} = \frac{46}{2} = 23$$
3. Chandan's position from the left end is 23rd.

**Shortcut / Trick:**
Convert both to left: 12 and $(47 - 14 + 1 = 34)$. Midpoint $= (12 + 34)/2 = 23\text{rd}$.

---

### Q17
Six buildings are of different heights. T is taller than U but shorter than S. R is shorter than P but taller than Q. If P is shorter than U, which building is the third tallest?  
A) U  
B) T  
C) P  
D) R  

**Correct Answer:** **A) U**

**Step-by-Step Explanation:**
1. Break down the statements into inequalities:
   - "T is taller than U but shorter than S": $S > T > U$.
   - "R is shorter than P but taller than Q": $P > R > Q$.
   - "P is shorter than U": $U > P$.
2. Chain the inequalities together:
   $$S > T > U > P > R > Q$$
3. Ranking from tallest to shortest:
   - 1st tallest: S
   - 2nd tallest: T
   - **3rd tallest: U**
   - 4th tallest: P
   - 5th tallest: R
   - 6th tallest: Q
4. Building U is the third tallest.

**Shortcut / Trick:**
Chain: $S > T > U > P > R > Q$. The 3rd from the top is U.

---

### Q18
In a row of girls, Neha is 15th from the left and Pooja is 20th from the right. When they swap their positions, Neha becomes 22nd from the left. What is Pooja's new position from the right end?  
A) 25th  
B) 26th  
C) 27th  
D) 28th  

**Correct Answer:** **C) 27th**

**Step-by-Step Explanation:**
- **Method 1 (Shift Principle - Fastest):**
  1. Calculate Neha's shift:
     $$\Delta = \text{New Left} - \text{Old Left} = 22 - 15 = +7 \text{ places}$$
  2. Pooja must shift by the exact same amount in her rank from the right end:
     $$\text{Pooja's New Right} = \text{Old Right} + \Delta = 20 + 7 = 27\text{th}$$
- **Method 2 (Total Calculation):**
  1. Total girls in the row $= \text{Neha's New Left} + \text{Pooja's Old Right} - 1 = 22 + 20 - 1 = 41$.
  2. Pooja is now sitting at Neha's original seat ($15\text{th}$ from left).
  3. Pooja's new rank from right $= 41 - 15 + 1 = 27\text{th}$.

**Shortcut / Trick:**
Equal shift: Neha increased by $22 - 15 = 7$. Pooja increases by $20 + 7 = 27\text{th}$.

---

### Q19
In a class examination, Rohit ranked 16th from the top and 29th from the bottom among the boys who passed. Six boys did not participate in the examination, and five failed. How many boys were there in the class?  
A) 50  
B) 52  
C) 55  
D) 58  

**Correct Answer:** **C) 55**

**Step-by-Step Explanation:**
1. Calculate the number of boys who passed the examination:
   $$\text{Passed} = \text{Top} + \text{Bottom} - 1 = 16 + 29 - 1 = 44$$
2. Identify the other groups of boys:
   - Did not participate $= 6$
   - Failed $= 5$
3. Compute the total strength of boys in the class:
   $$\text{Total Boys} = \text{Passed} + \text{Did Not Participate} + \text{Failed}$$
   $$\text{Total Boys} = 44 + 6 + 5 = 55$$

**Shortcut / Trick:**
$(16 + 29 - 1) + 6 + 5 = 44 + 11 = 55$.

---

### Q20
In a row of 35 children, M is 15th from the right end and N is 11th from the left end. If P sits exactly in the middle of M and N, what is P's position from the right end?  
A) 18th  
B) 19th  
C) 20th  
D) 21st  

**Correct Answer:** **C) 20th**

**Step-by-Step Explanation:**
- **Method 1 (Using Right Positions directly):**
  1. M is $15\text{th}$ from the right end.
  2. Find N's position from the right end:
     $$R_N = T - L_N + 1 = 35 - 11 + 1 = 25\text{th}$$
  3. Since P is exactly in the middle of M and N:
     $$R_P = \frac{R_M + R_N}{2} = \frac{15 + 25}{2} = \frac{40}{2} = 20\text{th}$$
- **Method 2 (Using Left Positions):**
  1. $L_N = 11$, $L_M = 35 - 15 + 1 = 21$.
  2. $L_P = (11 + 21)/2 = 16\text{th}$ from left.
  3. Convert P to right: $R_P = 35 - 16 + 1 = 20\text{th}$ from right.

**Shortcut / Trick:**
Right ranks: M is 15th, N is $35 - 11 + 1 = 25\text{th}$. Midpoint $= (15 + 25)/2 = 20\text{th}$.

---

### Q21
Six friends A, B, C, D, E, and F have different heights. A is taller than B but shorter than C. D is shorter than E but taller than C. F is taller than D but shorter than E. Who is the second tallest among them?  
A) C  
B) D  
C) E  
D) F  

**Correct Answer:** **D) F**

**Step-by-Step Explanation:**
1. Convert each clue into an inequality:
   - "A is taller than B but shorter than C": $C > A > B$.
   - "D is shorter than E but taller than C": $E > D > C$.
   - "F is taller than D but shorter than E": $E > F > D$.
2. Combine $E > F > D$ with $D > C > A > B$:
   $$E > F > D > C > A > B$$
3. Identify the ranking from tallest to shortest:
   - 1st (Tallest): E
   - **2nd (Second Tallest): F**
   - 3rd: D
   - 4th: C
   - 5th: A
   - 6th (Shortest): B
4. F is the second tallest.

**Shortcut / Trick:**
Between E and D sits F ($E > F > D$), while D is taller than all remaining friends ($D > C > A > B$). Thus E is 1st and F is 2nd.

---

### Q22
In a row of 60 people facing North, A is 35th from the left end and B is 42nd from the right end. C sits exactly between A and B. What is C's position from the left end?  
A) 26th  
B) 27th  
C) 28th  
D) 29th  

**Correct Answer:** **B) 27th**

**Step-by-Step Explanation:**
1. Convert both positions to the **left end**:
   - A: $L_A = 35$
   - B: $L_B = T - R_B + 1 = 60 - 42 + 1 = 19$
2. In the row, B sits at seat 19 and A sits at seat 35 (an overlapping scenario, since $35 + 42 = 77 > 60$).
3. C is positioned exactly midway between seat 19 and seat 35:
   $$L_C = \frac{L_A + L_B}{2} = \frac{35 + 19}{2} = \frac{54}{2} = 27$$
4. C is 27th from the left end.

**Shortcut / Trick:**
B's left rank $= 60 - 42 + 1 = 19$. Midpoint with A (35) $= (19 + 35)/2 = 27\text{th}$.

---

### Q23
In a class, the ratio of passed students to failed students is 4:1. Among those who passed, Amit ranks 24th from the top and 29th from the bottom. If 5 students did not appear for the exam, what is the total number of students in the class?  
A) 65  
B) 68  
C) 70  
D) 72  

**Correct Answer:** **C) 70**

**Step-by-Step Explanation:**
1. Determine the number of students who passed:
   $$\text{Passed} = \text{Top} + \text{Bottom} - 1 = 24 + 29 - 1 = 52$$
2. Use the given ratio $\text{Passed} : \text{Failed} = 4 : 1$:
   $$\text{Failed} = \frac{\text{Passed}}{4} = \frac{52}{4} = 13$$
3. Account for students who did not appear:
   $$\text{Absent} = 5$$
4. Calculate total strength:
   $$\text{Total Students} = \text{Passed} + \text{Failed} + \text{Absent} = 52 + 13 + 5 = 70$$

**Shortcut / Trick:**
Passed $= 52$. If $4 \text{ units} = 52$, then $1 \text{ unit} = 13$ (failed). Total $= 52 + 13 + 5 = 70$.

---

### Q24
In a row facing North, A is 15th from the left end and B is 22nd from the right end. After they interchange their positions, A shifts 4 places to his left and becomes the 30th person from the left end. What is the total number of people in the row?  
A) 54  
B) 55  
C) 56  
D) 57  

**Correct Answer:** **B) 55**

**Step-by-Step Explanation:**
1. After swapping, A is sitting at B's original seat.
2. From this swapped position, A shifts 4 places to his left (towards the left end, meaning rank decreases by 4) and reaches position 30 from the left:
   $$\text{Seat after shift} = \text{B's original position} - 4 = 30$$
   $$\implies \text{B's original position from left} = 30 + 4 = 34\text{th}$$
3. B's original seat is therefore:
   - $34\text{th}$ from the left end.
   - $22\text{nd}$ from the right end (given originally).
4. Compute total:
   $$\text{Total} = L_B + R_B - 1 = 34 + 22 - 1 = 55$$

**Shortcut / Trick:**
B's seat from left $= 30 + 4 = 34$. Total $= 34 + 22 - 1 = 55$.

---

### Q25
In a queue, P is 18th from the front and Q is 25th from the rear. R is standing exactly in the middle of P and Q. If the total number of people in the queue is a multiple of 10 and is strictly between 45 and 55, what is R's position from the front?  
A) 20th  
B) 21st  
C) 22nd  
D) 23rd  

**Correct Answer:** **C) 22nd**

**Step-by-Step Explanation:**
1. Determine total $T$: The only multiple of 10 strictly between 45 and 55 is $T = 50$.
2. Find positions from the front:
   - P is $18\text{th}$ from front: $\text{Front}_P = 18$.
   - Q is $25\text{th}$ from rear: $\text{Front}_Q = 50 - 25 + 1 = 26\text{th}$.
3. R stands exactly midway between P and Q:
   $$\text{Front}_R = \frac{\text{Front}_P + \text{Front}_Q}{2} = \frac{18 + 26}{2} = \frac{44}{2} = 22$$
4. R is 22nd from the front.

**Shortcut / Trick:**
$T = 50$. Q from front $= 50 - 25 + 1 = 26$. Midpoint of 18 and 26 is $(18 + 26)/2 = 22\text{nd}$.

---

### Q26
In a row of boys, Aman is 12th from the left end. When he is shifted by 4 places towards the right, he becomes 18th from the right end. How many boys are there in the row?  
A) 32  
B) 33  
C) 34  
D) 35  

**Correct Answer:** **B) 33**

**Step-by-Step Explanation:**
1. Aman starts at 12th from the left.
2. Shifting 4 places towards the right increases his rank from the left:
   $$L_{\text{new}} = 12 + 4 = 16\text{th}$$
3. In this new position, he is 18th from the right:
   $$R_{\text{new}} = 18\text{th}$$
4. Apply the total formula to Aman's new position:
   $$\text{Total} = L_{\text{new}} + R_{\text{new}} - 1 = 16 + 18 - 1 = 33$$
5. There are 33 boys in the row.

**Shortcut / Trick:**
New left $= 12 + 4 = 16$. Total $= 16 + 18 - 1 = 33$.

---

### Q27
Six students P, Q, R, S, T, and U scored different marks. P scored more than only Q and U. R scored less than only S. T did not score the least. Who scored the third lowest marks?  
A) P  
B) T  
C) R  
D) Q  

**Correct Answer:** **A) P**

**Step-by-Step Explanation:**
1. Analyze the positional clues among 6 ranks (1 = highest, 6 = lowest):
   - "P scored more than **only** Q and U": Exactly two students scored lower than P (Q and U). Thus, P is ranked 4th from the top (or 3rd from the bottom).
   - "R scored less than **only** S": Only one student scored higher than R (S). Thus, S is 1st (highest) and R is 2nd.
   - The remaining student T must occupy the 3rd rank: $\{S > R > T\}$.
2. The complete score ranking from highest (1st) to lowest (6th) is:
   - 1st: S
   - 2nd: R
   - 3rd: T
   - **4th: P**
   - 5th / 6th: Q or U (interchangeable)
3. Count the lowest marks from the bottom:
   - 1st lowest: 6th rank (Q or U)
   - 2nd lowest: 5th rank (U or Q)
   - **3rd lowest: 4th rank = P**
4. P scored the third lowest marks.

**Shortcut / Trick:**
"More than only 2 people" means there are 2 people below P (the 1st and 2nd lowest). P is directly above them, making P the 3rd lowest!

---

### Q28
In a row of persons, the position of X from the left is 25th and the position of Y from the right is 35th. If there are exactly 10 persons sitting between X and Y, what is the difference between the maximum and minimum possible number of persons in this row?  
A) 20  
B) 21  
C) 22  
D) 24  

**Correct Answer:** **C) 22**

**Step-by-Step Explanation:**
- **Standard Method:**
  1. Calculate maximum strength (non-overlapping):
     $$T_{\max} = L_X + R_Y + n = 25 + 35 + 10 = 70$$
  2. Calculate minimum strength (overlapping):
     $$T_{\min} = L_X + R_Y - n - 2 = 25 + 35 - 10 - 2 = 48$$
  3. Find the difference:
     $$\Delta = T_{\max} - T_{\min} = 70 - 48 = 22$$
- **Direct Formula Shortcut:**
  $$\Delta = 2n + 2 = 2(10) + 2 = 20 + 2 = 22$$

**Shortcut / Trick:**
The difference between maximum and minimum strength is ALWAYS $2n + 2$, where $n$ is the number of people between them: $2(10) + 2 = 22$.

---

### Q29
In a row of parked cars, the Red car is 28th from the left and the Blue car is 36th from the right. If they are shifted towards each other by 4 places each, there are exactly 8 cars left between them. Assuming they do not cross each other after the shift, what is the total number of cars in the row?  
A) 72  
B) 80  
C) 84  
D) 88  

**Correct Answer:** **B) 80**

**Step-by-Step Explanation:**
1. Shifting towards each other means:
   - Red car shifts 4 places to the right: $L_{\text{new}} = 28 + 4 = 32\text{nd from left}$.
   - Blue car shifts 4 places to the left: $R_{\text{new}} = 36 + 4 = 40\text{th from right}$.
2. In their shifted positions, they do not cross and there are 8 cars between them.
3. Compute total:
   $$\text{Total} = L_{\text{new}} + R_{\text{new}} + \text{Between} = 32 + 40 + 8 = 80$$
*(Alternatively, originally the gap between them was $8 + 4 + 4 = 16$ cars. Total $= 28 + 36 + 16 = 80$.)*

**Shortcut / Trick:**
$(28 + 4) + (36 + 4) + 8 = 32 + 40 + 8 = 80$.

---

### Q30
Five people A, B, C, D, and E are sitting in a row facing North. A is to the immediate left of B. C is sitting second to the right of B. E sits exactly between B and C. D sits at one of the extreme ends but is not adjacent to A. What is B's position from the right end?  
A) 2nd  
B) 3rd  
C) 4th  
D) 5th  

**Correct Answer:** **C) 4th**

**Step-by-Step Explanation:**
1. Represent seats 1 to 5 from Left to Right (facing North):
   - "A is to immediate left of B": Block $[A, B]$.
   - "C is second to right of B": Position of C is 2 seats right of B.
   - "E sits exactly between B and C": Form the contiguous 4-seat block: $[A, B, E, C]$.
2. In a 5-seat row, this 4-seat block can sit in two positions:
   - **Case 1:** Seats 1-2-3-4 are $A, B, E, C$. Seat 5 is D.
     - D sits at an extreme end (seat 5).
     - D is adjacent to C (seat 4), NOT A (seat 1). This satisfies all conditions!
   - **Case 2:** Seats 2-3-4-5 are $A, B, E, C$. Seat 1 is D.
     - D is adjacent to A (seat 2), which violates the condition "D is not adjacent to A".
3. The unique valid layout from left to right is:
   $$\text{Seat 1: A} \quad | \quad \text{Seat 2: B} \quad | \quad \text{Seat 3: E} \quad | \quad \text{Seat 4: C} \quad | \quad \text{Seat 5: D}$$
4. Determine B's position from the right end:
   - D is 1st from right
   - C is 2nd from right
   - E is 3rd from right
   - **B is 4th from right**
   - A is 5th from right
5. B's position from the right end is 4th.

**Shortcut / Trick:**
Total $= 5$. B is 2nd from left. From right: $5 - 2 + 1 = 4\text{th}$.

---

### Q31
Refer to the following number series and answer the question that follows (all numbers are single digit numbers only):  
**(Left)** 8 8 4 7 5 5 3 2 9 8 6 4 5 3 8 4 5 8 9 1 5 7 4 9 7 5 1 **(Right)**  

How many such even numbers are there, each of which is immediately preceded by an odd number and also immediately followed by an odd number?  
A) 3  
B) 0  
C) 2  
D) 4  

**Correct Answer:** **A) 3**

**Step-by-Step Explanation:**
1. Pattern required: **[Odd Digit] $\rightarrow$ [Even Digit] $\rightarrow$ [Odd Digit]**.
2. Scan all even numbers in the series:
   - `8 8 4`: preceded by left boundary / even numbers (no).
   - `... 3 2 9 ...`: **Odd (3) — Even (2) — Odd (9)** $\rightarrow$ **Match 1**.
   - `... 9 8 6 ...`: Even (8) followed by even (6) (no).
   - `... 8 6 4 ...`: Even followed by even (no).
   - `... 6 4 5 ...`: Preceded by even (6) (no).
   - `... 3 8 4 ...`: Followed by even (4) (no).
   - `... 8 4 5 ...`: Preceded by even (8) (no).
   - `... 5 8 9 ...`: **Odd (5) — Even (8) — Odd (9)** $\rightarrow$ **Match 2**.
   - `... 7 4 9 ...`: **Odd (7) — Even (4) — Odd (9)** $\rightarrow$ **Match 3**.
3. Total qualifying even numbers $= 3$.

**Shortcut / Trick:**
Target pattern: Odd-Even-Odd. Scanning yields `3-2-9`, `5-8-9`, and `7-4-9` $\implies 3$.

---

### Q32
Refer to the following number series and answer the question that follows (all numbers are single digit numbers only). Counting to be done from left to right only:  
**(Left)** 9 8 7 4 5 3 2 4 5 6 8 1 2 3 5 6 7 6 5 3 9 **(Right)**  

How many such even digits are there, each of which is immediately preceded by a perfect square and immediately followed by an odd digit?  
*(NOTE: 1 is also a perfect square)*  
A) Two  
B) Four  
C) Three  
D) One  

**Correct Answer:** **A) Two**

**Step-by-Step Explanation:**
1. Relevant components:
   - **Even digits:** 2, 4, 6, 8.
   - **Single-digit perfect squares:** 1, 4, 9.
   - **Odd digits:** 1, 3, 5, 7, 9.
2. Required pattern: **[1, 4, or 9] $\rightarrow$ [Even Digit] $\rightarrow$ [Odd Digit]**.
3. Scan through the sequence:
   - Position 2: `9 8 7` $\rightarrow$ Preceded by 9 (sq), Even digit 8, Followed by 7 (odd) $\rightarrow$ **Match 1**.
   - Position 4: `7 4 5` $\rightarrow$ Preceded by 7 (not a square).
   - Position 7: `3 2 4` $\rightarrow$ Preceded by 3 (not a square).
   - Position 8: `2 4 5` $\rightarrow$ Preceded by 2 (not a square).
   - Position 10: `5 6 8` $\rightarrow$ Followed by 8 (even).
   - Position 11: `6 8 1` $\rightarrow$ Preceded by 6 (not a square).
   - Position 13: `1 2 3` $\rightarrow$ Preceded by 1 (sq), Even digit 2, Followed by 3 (odd) $\rightarrow$ **Match 2**.
   - Position 16: `5 6 7` $\rightarrow$ Preceded by 5 (not a square).
   - Position 18: `7 6 5` $\rightarrow$ Preceded by 7 (not a square).
4. Total occurrences $= 2$ (`9-8-7` and `1-2-3`).

**Shortcut / Trick:**
Check only after squares (1, 4, 9):
- After 9: `9 8 7` (Yes)
- After 4: `4 5 3` (5 is not even)
- After 1: `1 2 3` (Yes)
- Count $= 2$ (Two).

---

### Q33
Refer to the following letter series and answer the question that follows. (Counting to be done from left to right only):  
**(Left)** K O P Q W S E D G U J I O P K M N V Y I P O **(Right)**  

How many such consonants are there, each of which is immediately preceded by a vowel and also immediately followed by a vowel?  
A) Two  
B) None  
C) More than two  
D) One  

**Correct Answer:** **A) Two**

**Step-by-Step Explanation:**
1. Vowels: $\{A, E, I, O, U\}$.
2. Target pattern: **[Vowel] $\rightarrow$ [Consonant] $\rightarrow$ [Vowel]**.
3. Locate all vowel occurrences and inspect adjacent letters:
   - `O`: preceded by K (consonant), followed by P (consonant).
   - `E`: preceded by S, followed by D (consonant).
   - `U`: followed by J (consonant), followed by I (vowel) $\rightarrow$ **`U J I`**: J is a consonant between vowels U and I $\rightarrow$ **Match 1**.
   - `I`: followed by O (two vowels adjacent, no consonant between).
   - `O`: followed by P (consonant), followed by K (consonant).
   - `I`: followed by P (consonant), followed by O (vowel) $\rightarrow$ **`I P O`**: P is a consonant between vowels I and O $\rightarrow$ **Match 2**.
4. Exactly 2 consonants (J and P) satisfy the condition.

**Shortcut / Trick:**
Find all pairs of vowels separated by one letter: `U _ I` (J) and `I _ O` (P). Total $= 2$ (Two).

---

### Q34
Refer to the following letter and symbol series and answer the question that follows. Counting to be done from left to right only:  
**(Left)** R L Z T @ $ O D U % W N # * K X V £ Y A & Q P S **(Right)**  

How many such letters are there that are immediately preceded by a letter and also immediately followed by another symbol?  
A) Six  
B) Four  
C) Five  
D) Three  

**Correct Answer:** **C) Five**

**Step-by-Step Explanation:**
1. Classification:
   - **Letters:** R, L, Z, T, O, D, U, W, N, K, X, V, Y, A, Q, P, S.
   - **Symbols:** @, $, %, #, *, £, &.
2. Required pattern: **[Letter] $\rightarrow$ [Target Letter] $\rightarrow$ [Symbol]**.
3. Scan through all letter-symbol boundaries:
   - Boundary at `@`: `Z T @` $\rightarrow$ T is preceded by letter Z, followed by symbol @ $\rightarrow$ **Match 1**.
   - Boundary at `%`: `D U %` $\rightarrow$ U is preceded by letter D, followed by symbol % $\rightarrow$ **Match 2**.
   - Boundary at `#`: `W N #` $\rightarrow$ N is preceded by letter W, followed by symbol # $\rightarrow$ **Match 3**.
   - Boundary at `£`: `X V £` $\rightarrow$ V is preceded by letter X, followed by symbol £ $\rightarrow$ **Match 4**.
   - Boundary at `&`: `Y A &` $\rightarrow$ A is preceded by letter Y, followed by symbol & $\rightarrow$ **Match 5**.
   - What about `$`? Preceded by `@` (symbol, not letter).
   - What about `*`? Preceded by `#` (symbol, not letter).
4. Exactly 5 letters (T, U, N, V, A) satisfy the condition.

**Shortcut / Trick:**
Look immediately to the left of each symbol:
- Before `@`: `Z T` (2 letters) $\rightarrow$ Yes
- Before `$`: `@` (symbol) $\rightarrow$ No
- Before `%`: `D U` (2 letters) $\rightarrow$ Yes
- Before `#`: `W N` (2 letters) $\rightarrow$ Yes
- Before `*`: `#` (symbol) $\rightarrow$ No
- Before `£`: `X V` (2 letters) $\rightarrow$ Yes
- Before `&`: `Y A` (2 letters) $\rightarrow$ Yes
Total $= 5$ (Five).

---

### Q35
Refer to the given letter series and answer the question that follows. Counting to be done from left to right:  
**(Left)** C C Q O I S J S M X H U V Q R H D P C H Y **(Right)**  

How many such consonants are there, each of which is immediately preceded by a vowel and also immediately followed by a vowel?  
A) Three  
B) One  
C) None  
D) Two  

**Correct Answer:** **C) None**

**Step-by-Step Explanation:**
1. Target pattern: **[Vowel] $\rightarrow$ [Consonant] $\rightarrow$ [Vowel]**.
2. Identify all vowels in the series:
   - Position 4: `O`
   - Position 5: `I`
   - Position 12: `U`
3. Inspect the environment around every vowel:
   - `O` and `I` are consecutive vowels (`O I`). There is no consonant between them.
   - Letters around `O I`: preceded by consonant `Q`, followed by consonant `S`. Neither is sandwiched between two vowels.
   - Letter around `U`: preceded by consonant `H`, followed by consonant `V` (`H U V`). There is no second vowel adjacent to H or V.
4. No consonant in the entire series is both preceded by a vowel and followed by a vowel.
5. The count is 0 (None).

**Shortcut / Trick:**
To have a consonant sandwiched between two vowels, we need two vowels separated by one letter ($V_1 C V_2$). The only vowels are O, I, U. O and I are adjacent (`O I`), and U is isolated (`H U V`). Thus, 0 instances exist.

---

## 3. Exam Tips, Shortcuts & Pitfalls

### Key Positional Formulas at a Glance
| Scenario | Formula |
| :--- | :--- |
| **Total from same person** | $T = L + R - 1$ |
| **Opposite rank** | $R = T - L + 1$ |
| **Non-overlapping between** | $\text{Between} = T - (L + R)$ |
| **Overlapping between** | $\text{Between} = (L + R) - T - 2$ |
| **Maximum row strength** | $T_{\max} = L + R + n$ |
| **Minimum row strength** | $T_{\min} = L + R - n - 2$ |
| **Difference ($T_{\max} - T_{\min}$)** | $\Delta T = 2n + 2$ |
| **Position Interchange Total** | $T = L_A' + R_B - 1$ |
| **Interchange Shift** | $\Delta = |L_A' - L_A| = |R_B' - R_B|$ |
| **Midpoint seat** | $\text{Mid} = \frac{L_1 + L_2}{2} = \frac{R_1 + R_2}{2}$ |

### High-Yield Exam Tactics
1. **Always verify whether a case overlaps:**
   Compute $L_A + R_B$. Compare with $T$:
   - If $L_A + R_B < T \implies$ Non-overlapping (simple subtraction).
   - If $L_A + R_B > T \implies$ Overlapping (subtract $T + 2$).
2. **Convert all ranks to one standard end for midpoint questions:**
   Never average a left rank with a right rank! Convert both to left ranks first:
   $$L_B = T - R_B + 1$$
   Then calculate:
   $$\text{Midpoint} = \frac{L_A + L_B}{2}$$
3. **Difference between Maximum and Minimum depends ONLY on $n$:**
   If asked for $T_{\max} - T_{\min}$, immediately apply $2n + 2$, saving over a minute of calculation.
4. **Shifting Left vs Right:**
   - Facing North: Left = towards left end (rank from left decreases, rank from right increases).
   - Facing North: Right = towards right end (rank from left increases, rank from right decreases).
5. **Conditional Series Scanning (Preceded / Followed):**
   - Circle or bracket the central target element.
   - Remember: "Preceded by $X$" means $X$ is to the **left**; "Followed by $Y$" means $Y$ is to the **right**.
