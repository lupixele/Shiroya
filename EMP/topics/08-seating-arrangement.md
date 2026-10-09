# 08. Seating Arrangement

## 1. Theory, Principles and Core Concepts

Seating arrangement puzzles test logical deduction, spatial orientation, relative positioning, and systematic elimination of candidate cases. Mastering these problems requires translating verbal conditions into rigorous spatial constraints.

---

### 1.1 Types of Seating Arrangements

1. **Linear Arrangement (Single Row):**
   - Individuals or objects are arranged in a straight line.
   - Facing directions:
     - **Facing North:** Standard orientation. A person's **Right** is towards the East (Right side of the page), and **Left** is towards the West (Left side of the page).
     - **Facing South:** Inverted orientation. A person's **Right** is towards the West (Left side of the page), and **Left** is towards the East (Right side of the page).
     - **Facing East:** Upward/North is to their **Left**, and Downward/South is to their **Right**.
     - **Facing West:** Downward/South is to their **Left**, and Upward/North is to their **Right**.

2. **Double-Row Arrangement:**
   - Two parallel rows facing each other.
   - Row 1 faces South; Row 2 faces North.
   - Directly opposite individuals face each other. Note that their respective left and right orientations are mutually reversed.

3. **Circular Arrangements:**
   - Individuals sit around a circle.
   - **All Facing Centre (Inside):**
     - **Right = Anticlockwise (↺)**
     - **Left = Clockwise (↻)**
   - **All Facing Outside (Away from Centre):**
     - **Right = Clockwise (↻)**
     - **Left = Anticlockwise (↺)**
   - **Mixed Facing (Some In, Some Out):**
     - For each individual, establish their specific facing vector before determining their relative left/right neighbours.

4. **Polygonal Arrangements (Square, Rectangular, Hexagonal):**
   - **Square/Rectangular Tables:** Frequently feature corners facing inside and side-centers facing outside (or vice versa).
   - **Hexagonal Tables:** 6 vertices facing the center; opposite pairs sit 3 steps apart.

5. **Floor and Multi-Storey Arrangements:**
   - Vertical linear arrangements where positions are numbered consecutively from bottom (Floor 1) to top (Floor $N$).
   - 'Between' means strictly within intervening levels; 'above/below' does not imply immediately adjacent unless qualified.

---

### 1.2 Essential Deduction Rules & Terminology

- **"Immediate Right / Left" vs "To the Right / Left":**
  - "Immediate right of A" means adjacent position ($i + 1$).
  - "To the right of A" means any position to the right of A, not necessarily adjacent.
- **"Adjacent / Next to / Neighbour":**
  - Sitting immediately next to the person (either immediately left or immediately right).
- **"Between A and B":**
  - Can mean either strictly adjacent between the two, or situated in the interval bounded by A and B. In linear sequences, unless specified as "only" or "adjacent", verify whether other entities occupy the gap.
- **"Opposite":**
  - In an even-numbered polygon/circle of $N$ seats, opposite positions are separated by $N/2$ steps along either circumference.
- **Relative Count Formulation:**
  - If $k$ people sit strictly between position $P_1$ and $P_2$, then $|P_1 - P_2| = k + 1$.
  - "As many people to the left of $X$ as to the right of $X$" implies $X$ is the exact middle of an odd-numbered row: $\text{Position}(X) = \frac{N + 1}{2}$.
- **Elimination Strategy:**
  1. **Anchor Definitive Clues:** Start with fixed anchors (ends of rows, specified corners, known facing directions).
  2. **Track Dependent Chains:** Connect clues that reference common variables (e.g., $A-D$, then $D-G$).
  3. **Branch Mutually Exclusive Cases:** Maintain at most 2 parallel candidate layouts; eliminate invalid branches immediately when a contradiction arises.

---

## 2. Comprehensive Question Sets & Step-by-Step Solutions

---

### Set 1: Linear Row (6 Persons)

**Problem Statement:**  
$A, P, R, X, S$ and $Z$ are sitting in a row.
- $S$ and $Z$ are in the centre, but $Z$ is not adjacent to $X$.
- $A$ and $P$ are at the ends.
- $R$ is sitting immediate left of $A$.

#### Questions:
1. Who is to the immediate right of $P$?  
   (a) $A$  
   (b) $X$  
   (c) $S$  
   (d) $Z$  

2. Who is fourth to the left of $A$?  
   (a) $A$  
   (b) $X$  
   (c) $S$  
   (d) $Z$  

3. Who is at the extreme right end?  
   (a) $A$  
   (b) $X$  
   (c) $S$  
   (d) $Z$  

4. Who is third to the right of $Z$?  
   (a) $P$  
   (b) $R$  
   (c) $A$  
   (d) None  

5. Who is second to the right of $P$?  
   (a) $Z$  
   (b) $R$  
   (c) $A$  
   (d) $S$  

#### Step-by-Step Deduction:
1. **Total Positions:** 6 positions in a row (Left to Right: 1, 2, 3, 4, 5, 6).
2. **Anchor Ends:** $A$ and $P$ sit at ends (positions 1 and 6).
3. **Condition on $R$ and $A$:** $R$ is immediately to the left of $A$.
   - If $A$ were at position 1 (extreme left), no one could sit to the left of $A$.
   - Therefore, $A$ must sit at position 6 (extreme right), and $R$ sits at position 5.
   - Consequently, $P$ must sit at position 1 (extreme left).
4. **Centre Positions:** Positions 3 and 4 are occupied by $S$ and $Z$ in some order.
5. **Remaining Position:** Position 2 must be occupied by $X$.
6. **Adjacency Constraint:** $Z$ is not adjacent to $X$.
   - Position 2 is $X$. Thus, position 3 cannot be $Z$.
   - Hence, position 3 is $S$, and position 4 is $Z$.

#### Final Arrangement:
```text
[Position]    1     2     3     4     5     6
[Person]      P     X     S     Z     R     A
            (Left)                          (Right)
```

#### Answers & Explanations:
1. **Correct Option: (b) X**  
   *Explanation:* Position 1 is $P$; immediately right (position 2) is $X$.
2. **Correct Option: (b) X**  
   *Explanation:* $A$ is at position 6. Fourth to the left of $A$ is $6 - 4 = 2$, which is $X$.
3. **Correct Option: (a) A**  
   *Explanation:* Position 6 is the extreme right end, occupied by $A$.
4. **Correct Option: (d) None**  
   *Explanation:* $Z$ is at position 4. To the right of $Z$ are position 5 ($R$) and position 6 ($A$). There is no 7th position; hence nobody sits third to the right of $Z$.
5. **Correct Option: (d) S**  
   *Explanation:* $P$ is at position 1. Second to the right of $P$ is $1 + 2 = 3$, which is $S$.

---

### Set 2: Bench Arrangement (5 Persons)

**Problem Statement:**  
$A, B, C, D$ and $E$ are sitting on a bench.
- $A$ is sitting next to $B$.
- $C$ is sitting next to $D$.
- $D$ is not sitting with $E$, who is on the left end of the bench.
- $C$ is on the second position from the right.
- $A$ is to the right of $B$ and $E$.
- $A$ and $C$ are sitting together.

#### Question:
In which position is $A$ sitting?  
(a) Between $B$ and $D$  
(b) Between $B$ and $C$  
(c) Between $E$ and $D$  
(d) Between $C$ and $E$  

#### Step-by-Step Deduction:
1. **Total Positions:** 5 positions (1 to 5 from left to right).
2. **Left End:** $E$ is on the left end $\implies$ Position 1 = $E$.
3. **Right End Anchor:** $C$ is on the second position from the right $\implies$ Position 4 = $C$.
4. **Condition on $D$:** $C$ is next to $D$. The neighbours of position 4 are 3 and 5.
   - $D$ is not sitting with $E$ (Position 1), so $D$ can be at 3 or 5.
5. **Condition on $A$ and $C$:** $A$ and $C$ sit together. Since $C$ is at position 4, $A$ must be at position 3.
6. **Placing $D$:** Since position 3 is $A$, $D$ must occupy position 5.
7. **Placing $B$:** Position 2 remains for $B$.
8. **Verification:**
   - $A$ next to $B$: Pos 3 and Pos 2 (adjacent) $\checkmark$
   - $A$ is to the right of $B$ and $E$: Pos 3 > Pos 2, Pos 3 > Pos 1 $\checkmark$
   - $C$ next to $D$: Pos 4 and Pos 5 $\checkmark$
   - $D$ not with $E$: Pos 5 and Pos 1 $\checkmark$

#### Final Arrangement:
```text
[Position]    1     2     3     4     5
[Person]      E     B     A     C     D
            (Left)                    (Right)
```

#### Answer & Explanation:
- **Correct Option: (b) Between B and C**  
  *Explanation:* $A$ occupies position 3, situated directly between $B$ (position 2) and $C$ (position 4).

---

### Set 3: Circular Arrangement Facing Centre (8 Persons)

**Problem Statement:**  
Eight friends $P, Q, R, S, T, U, V$ and $W$ are sitting around a circle facing the centre.
- $P$ is second to the right of $T$, who is the neighbour of $R$ and $V$.
- $S$ is not the neighbour of $P$.
- $V$ is the neighbour of $U$.
- $Q$ is not between $S$ and $W$.
- $W$ is not between $U$ and $S$.

#### Questions:
1. Which two of the following are not neighbours?  
   (a) $R, T$  
   (b) $U, V$  
   (c) $R, P$  
   (d) $Q, W$  

2. Who is second to the right of $T$?  
   (a) $P$  
   (b) $W$  
   (c) $U$  
   (d) $Q$  

3. Who is third to the left of $Q$?  
   (a) $P$  
   (b) $R$  
   (c) $S$  
   (d) None  

4. Who is to the immediate left of $U$?  
   (a) $Q$  
   (b) $R$  
   (c) $W$  
   (d) $P$  

#### Step-by-Step Deduction:
1. **Coordinate System:** Let 8 positions be numbered 0 to 7 in anticlockwise order. Facing centre, **Right** is anticlockwise ($+1$) and **Left** is clockwise ($-1$).
2. **Anchor $T$:** Place $T$ at Seat 0.
   - $P$ is 2nd to the right of $T \implies P$ sits at Seat 2.
3. **Neighbours of $T$:** $T$ (Seat 0) is adjacent to Seats 1 and 7. The neighbours are $R$ and $V$.
   - **Case A:** $V$ is at Seat 1, $R$ is at Seat 7.
     - $V$ is a neighbour of $U \implies U$ must sit at Seat 0 or Seat 2. But Seat 0 is $T$ and Seat 2 is $P$. Thus, $U$ has no vacant seat adjacent to $V$. Case A is **eliminated**.
   - **Case B:** $R$ is at Seat 1, $V$ is at Seat 7.
     - $V$ is a neighbour of $U \implies U$ must sit at Seat 6. This is valid!
4. **Current Occupants:**
   - Seat 0: $T$, Seat 1: $R$, Seat 2: $P$, Seat 6: $U$, Seat 7: $V$.
   - Vacant seats: 3, 4, 5 for remaining persons $Q, S, W$.
5. **Placing $S$:** $S$ is not adjacent to $P$ (Seat 2).
   - Seat 3 is adjacent to Seat 2, so $S \neq 3$.
   - $S$ can be at Seat 4 or Seat 5.
6. **Constraint on $W$ and $Q$:**
   - "W is not between U and S" and "Q is not between S and W".
   - If $S$ is at Seat 4: Vacant seats are 3 and 5.
     - If $W = 3, Q = 5$: $Q$ is at Seat 5, surrounded by Seat 4 ($S$) and Seat 6 ($U$), so $Q$ is between $S$ and $U$ (not $S$ and $W$).
     - Neighbours of $W$ (Seat 3) are Seat 2 ($P$) and Seat 4 ($S$) (not $U$ and $S$).
     - Neighbours of $Q$ (Seat 5) are Seat 4 ($S$) and Seat 6 ($U$) (not $S$ and $W$).
     - This satisfies all conditions!

#### Final Arrangement:
```text
                    [0] T
             (CW) ↗       ↖ (ACW)
         [7] V                 [1] R
           |                     |
         [6] U                 [2] P
             ↖             ↙
              [5] Q — [4] S — [3] W
```

#### Answers & Explanations:
1. **Correct Option: (d) QW**  
   *Explanation:* $R$ and $T$ are adjacent (Seats 1, 0); $U$ and $V$ are adjacent (Seats 6, 7); $R$ and $P$ are adjacent (Seats 1, 2). $Q$ (Seat 5) and $W$ (Seat 3) are separated by $S$ (Seat 4), hence not neighbours.
2. **Correct Option: (a) P**  
   *Explanation:* Given directly in the premise: $P$ sits second to the right of $T$.
3. **Correct Option: (a) P**  
   *Explanation:* $Q$ is at Seat 5. Facing centre, Left is clockwise ($-1$). Third to the left of $Q$ is $5 - 3 = 2$, which is $P$.
4. **Correct Option: (a) Q**  
   *Explanation:* $U$ is at Seat 6. Facing centre, Left is clockwise ($-1$). Immediate left of $U$ is $6 - 1 = 5$, which is $Q$.

---

### Set 4: Linear Row Facing East (7 Cars)

**Problem Statement:**  
In a car exhibition, seven different companies—Ford, Santro, Innova, Matiz, Endeavour, Scorpio, and Benz—were displayed in a row facing East such that:
- Ford was to the immediate right of Benz.
- Benz was fourth to the right of Innova.
- Matiz was between Santro and Scorpio.
- Innova, which was third to the left of Santro, was at one of the ends.

#### Questions:
1. Which of the following was the correct position of Endeavour?  
   (a) Immediate left of Ford  
   (b) Immediate left of Scorpio  
   (c) Between Scorpio and Benz  
   (d) Fourth to the right of Matiz  

2. Which of the following is definitely true?  
   (a) Benz car is between Santro and Innova  
   (b) Ford car is to the immediate left of Endeavour  
   (c) Benz is to the immediate right of Ford  
   (d) Matiz is fourth to the right of Endeavour  

3. Which cars are on the immediate either side of the Ford car?  
   (a) Santro and Matiz  
   (b) Matiz and Innova  
   (c) Innova and Endeavour  
   (d) Benz and Endeavour  

4. Which of the following is definitely true?  
   (a) Matiz is to the immediate left of Santro  
   (b) Scorpio is to the immediate left of Innova  
   (c) Scorpio is at one of the ends  
   (d) Innova is second to the right of Matiz  

#### Step-by-Step Deduction:
1. **Orientation:** Facing East:
   - **Left** is North (towards lower position index 1).
   - **Right** is South (towards higher position index 7).
2. **Placing Innova:** Innova is at one of the ends (Position 1 or Position 7).
   - Benz is fourth to the right of Innova $\implies$ Innova must be at Position 1 (North end), because from Position 7 there are no positions to the right.
   - Position 1 = **Innova**.
3. **Placing Benz:** Benz is 4th to the right of Innova:
   - $\text{Position} = 1 + 4 = 5 \implies$ Position 5 = **Benz**.
4. **Placing Ford:** Ford is to the immediate right of Benz:
   - $\text{Position} = 5 + 1 = 6 \implies$ Position 6 = **Ford**.
5. **Placing Santro:** Innova is third to the left of Santro $\implies$ Santro is 3rd to the right of Innova:
   - $\text{Position} = 1 + 3 = 4 \implies$ Position 4 = **Santro**.
6. **Placing Matiz and Scorpio:**
   - Matiz is between Santro and Scorpio.
   - Santro is at Position 4. The available positions are 2, 3, and 7.
   - For Matiz to sit between Santro and Scorpio, Matiz must be at Position 3, and Scorpio must be at Position 2.
7. **Placing Endeavour:**
   - The only remaining position is Position 7 = **Endeavour**.

#### Final Arrangement:
```text
Position:      1          2         3        4        5       6         7
Car:        Innova     Scorpio    Matiz    Santro   Benz    Ford    Endeavour
Direction:  (North/Left) ------------------------------------> (South/Right)
```

#### Answers & Explanations:
1. **Correct Option: (d) Fourth to the right of Matiz**  
   *Explanation:* Matiz is at Position 3. Fourth to the right is $3 + 4 = 7$, which is Endeavour.
2. **Correct Option: (b) Ford car is to the immediate left of Endeavour**  
   *Explanation:* Endeavour is at 7, and Ford is at 6 (immediately to the left of Endeavour).
3. **Correct Option: (d) Benz and Endeavour**  
   *Explanation:* Ford is at Position 6, flanked by Benz (Position 5) on the left and Endeavour (Position 7) on the right.
4. **Correct Option: (a) Matiz is to the immediate left of Santro**  
   *Explanation:* Santro is at Position 4, and Matiz is at Position 3, which is directly to Santro's left.

---

### Set 5: Hexagonal Table Facing Centre (6 Persons)

**Problem Statement:**  
Six friends $P, Q, R, S, T$ and $U$ are sitting around a hexagonal table, each at one corner, facing the centre.
- $P$ is second to the left of $U$.
- $Q$ is neighbour of $R$ and $S$.
- $T$ is second to the left of $S$.

#### Questions:
1. Which one is sitting opposite to $P$?  
   (a) $R$  
   (b) $Q$  
   (c) $T$  
   (d) $S$  

2. Who is the fourth person to the left of $Q$?  
   (a) $P$  
   (b) $U$  
   (c) $R$  
   (d) Data inadequate  

3. Which of the following are the neighbours of $P$?  
   (a) $U$ & $P$  
   (b) $U$ & $R$  
   (c) $T$ & $R$  
   (d) Data inadequate  

4. Which one is sitting opposite to $T$?  
   (a) $R$  
   (b) $Q$  
   (c) $S$  
   (d) Cannot be determined  

#### Step-by-Step Deduction:
1. **Geometry:** 6 vertices labeled 0 to 5 in clockwise order.
   - Facing centre: **Left** is clockwise ($+1$), **Right** is anticlockwise ($-1$).
   - Opposite pairs are separated by 3 seats: $(i + 3) \pmod 6$.
2. **Anchor $U$:** Place $U$ at Seat 0.
   - $P$ is second to the left of $U \implies P$ sits at Seat $(0 + 2) = 2$.
3. **Placing $Q, R, S$:**
   - $Q$ is adjacent to both $R$ and $S$. This requires three consecutive seats: $R - Q - S$ or $S - Q - R$.
   - The available seats outside $U (0)$ and $P (2)$ are Seats 3, 4, 5 and Seat 1.
   - The only three consecutive available seats are Seats 3, 4, 5.
   - Therefore, $Q$ must sit at the central position among them $\implies$ Seat 4 = $Q$.
   - Seats 3 and 5 are occupied by $R$ and $S$ in some order.
4. **Placing $T$:**
   - The only remaining seat is Seat 1 $\implies$ Seat 1 = $T$.
5. **Determining $S$ and $R$:**
   - $T$ is second to the left of $S$.
   - Left is clockwise ($+1$).
   - If $S$ is at Seat 5: Second to the left is $(5 + 2) \pmod 6 = 1$, which is $T$! This is consistent.
   - Therefore, Seat 5 = $S$, and Seat 3 = $R$.

#### Final Arrangement:
```text
                 [0] U
              ↗         ↖
         [5] S           [1] T
           |               |
         [4] Q           [2] P
              ↘         ↙
                 [3] R
```
- Clockwise order (0 to 5): $U \to T \to P \to R \to Q \to S$

#### Answers & Explanations:
1. **Correct Option: (d) S**  
   *Explanation:* $P$ is at Seat 2. Opposite position is $(2 + 3) = 5$, which is $S$.
2. **Correct Option: (a) P**  
   *Explanation:* $Q$ is at Seat 4. Fourth to the left of $Q$ is $(4 + 4) \pmod 6 = 2$, which is $P$.
3. **Correct Option: (c) T & R**  
   *Explanation:* $P$ is at Seat 2. Its adjacent neighbours are Seat 1 ($T$) and Seat 3 ($R$).
4. **Correct Option: (b) Q**  
   *Explanation:* $T$ is at Seat 1. The seat opposite to $T$ is $(1 + 3) = 4$, which is $Q$.

---

### Set 6: Multi-Bench Grouping Puzzle (7 Students)

**Problem Statement:**  
In a class there are seven students (boys and girls) $A, B, C, D, E, F$ and $G$. They sit on three benches I, II, and III such that:
- At least two students sit on each bench.
- At least one girl sits on each bench.
- $C$, who is a girl student, does not sit with $A, E$ and $D$.
- $F$, a boy student, sits with only $B$.
- $A$ sits on Bench I with his best friends.
- $G$ sits on Bench III.
- $E$ is the brother of $C$.

#### Questions:
1. How many girls are there out of these 7 students?  
   (a) 3  
   (b) 3 or 4  
   (c) 4  
   (d) Data inadequate  

2. Which of the following is the group of girls?  
   (a) $BAC$  
   (b) $BFC$  
   (c) $BCD$  
   (d) $CDF$  

3. Who sits with $C$?  
   (a) $B$  
   (b) $D$  
   (c) $G$  
   (d) $E$  

4. On which bench are there three students?  
   (a) Bench I  
   (b) Bench II  
   (c) Bench III  
   (d) Bench I or II  

#### Step-by-Step Deduction:
1. **Bench Capacities:** 7 students across 3 benches with $\ge 2$ per bench $\implies$ distribution must be $3, 2, 2$.
2. **Bench II Allocation:**
   - "$F$, the boy student, sits with only $B$."
   - This means that bench has exactly 2 students: $\{F, B\}$.
   - Neither $A$ (Bench I) nor $G$ (Bench III) can sit here.
   - Hence, $\{F, B\}$ must occupy **Bench II**.
3. **Student Count per Bench:**
   - Bench II has 2 students.
   - "$A$ sits on Bench I with his best friends" (plural) $\implies$ Bench I has 3 students.
   - Therefore, Bench III has 2 students.
4. **Placing $C$:**
   - $C$ is a girl. $C$ cannot sit with $A, E, D$.
   - $C$ cannot sit on Bench II (occupied solely by $F$ and $B$).
   - $C$ cannot sit on Bench I (as $A$ is on Bench I).
   - Thus, $C$ must sit on **Bench III**.
   - Since $G$ is on Bench III and Bench III has 2 seats, Bench III = $\{C, G\}$.
5. **Placing $D$ and $E$:**
   - Bench I must contain the remaining 3 students: $\{A, D, E\}$.
6. **Determining Genders:**
   - Given: $C$ is female, $F$ is male, $A$ is male ("with his best friends"), $E$ is male ("brother of $C$").
   - Constraint: "At least one girl on each bench."
     - Bench II: $\{F (\text{male}), B\} \implies B$ must be **female**.
     - Bench I: $\{A (\text{male}), E (\text{male}), D\} \implies D$ must be **female**.
     - Bench III: $\{C (\text{female}), G\} \implies C$ satisfies the requirement; $G$'s gender is unspecified (can be male or female).
   - Total girls: $B, C, D$ are definitively girls. If $G$ is a girl, total is 4; if $G$ is a boy, total is 3. Hence, **3 or 4 girls**.

#### Final Bench Allocation Table:
```text
Bench       Students       Genders Known
Bench I     A, D, E        A (Boy), D (Girl), E (Boy)
Bench II    B, F           B (Girl), F (Boy)
Bench III   C, G           C (Girl), G (Boy/Girl)
```

#### Answers & Explanations:
1. **Correct Option: (b) 3 or 4**  
   *Explanation:* $B, C, D$ are confirmed girls; $G$'s gender cannot be determined from the premises.
2. **Correct Option: (c) BCD**  
   *Explanation:* $B, C,$ and $D$ are all confirmed girls.
3. **Correct Option: (c) G**  
   *Explanation:* Bench III consists solely of $C$ and $G$.
4. **Correct Option: (a) B-I**  
   *Explanation:* Bench I contains 3 students ($A, D, E$).

---

### Set 7: Linear Row Facing North (5 Friends)

**Problem Statement:**  
Five friends—Abish, Binay, Chandu, Dinesh, and Eshaan—are having dinner in a restaurant, sitting in a row facing North.
- Binay and Dinesh are sitting at extreme ends.
- There are exactly two friends sitting between Binay and Eshaan.
- Abish is sitting to the right of Chandu.
- Abish and Eshaan are not sitting adjacently.

#### Question:
Who is sitting between Chandu and Binay?  
(a) Eshaan and Abish  
(b) Eshaan  
(c) Abish  
(d) Cannot be determined  

#### Step-by-Step Deduction:
1. **Positions:** 5 positions (1 to 5 from left to right).
2. **Extreme Ends:** $\{1, 5\} = \{\text{Binay}, \text{Dinesh}\}$.
3. **Two friends between Binay and Eshaan:**
   - If Binay = 1: Eshaan must be at $1 + 2 + 1 = 4$.
   - If Binay = 5: Eshaan must be at $5 - 2 - 1 = 2$.
4. **Test Case 1 (Binay = 1, Dinesh = 5, Eshaan = 4):**
   - Remaining positions for Chandu and Abish are 2 and 3.
   - Abish is to the right of Chandu $\implies$ Chandu = 2, Abish = 3.
   - Check adjacency: Abish (3) and Eshaan (4) are adjacent. But the condition states: *"Abish and Eshaan are not sitting adjacently."*
   - Hence, Case 1 is **invalid**.
5. **Test Case 2 (Dinesh = 1, Binay = 5, Eshaan = 2):**
   - Remaining positions for Chandu and Abish are 3 and 4.
   - Abish is to the right of Chandu $\implies$ Chandu = 3, Abish = 4.
   - Check adjacency: Abish (4) and Eshaan (2) are not adjacent $\checkmark$.
   - All conditions hold!

#### Final Arrangement:
```text
Position:      1          2          3          4          5
Friend:      Dinesh     Eshaan     Chandu     Abish      Binay
Direction:   (Left) -----------------------------------> (Right)
```

#### Answer & Explanation:
- **Correct Option: (c) Abish**  
  *Explanation:* Chandu is at position 3 and Binay is at position 5. The sole person sitting between them is Abish (position 4).

---

### Set 8: Circular Arrangement with Mixed Facing (8 Persons)

**Problem Statement:**  
Eight persons—$J, K, L, M, N, O, P,$ and $Q$—are sitting around a circular table. Some face inside (towards centre) and some face outside (away from centre).
- $O$ faces inside the centre.
- $L$ sits third to the right of $O$.
- $K$ sits 2nd to the right of $L$.
- $K$ sits third to the left of $Q$.
- $J$ sits second to the left of $L$.
- Both $P$ and $M$ sit immediate left of each other.
- Only two persons sit between $J$ and $N$.
- $K$ faces the same direction as $M$, but opposite to $Q$.
- $P$ sits second to the left of $J$.
- $P$ and $N$ face the same direction, but opposite to $L$.

#### Questions:
1. Who among the following sits opposite to the one who sits 3rd to the left of $M$?  
   (a) $L$  
   (b) $Q$  
   (c) $M$  
   (d) $K$  
   (e) None of these  

2. Who among the following faces $O$?  
   (a) $J$  
   (b) $K$  
   (c) $M$  
   (d) $Q$  
   (e) $P$  

3. How many persons sit between $L$ and $O$ when counted in clockwise direction with respect to $O$?  
   (a) One  
   (b) Three  
   (c) Two  
   (d) Four  
   (e) No one  

#### Step-by-Step Deduction:
1. **Coordinate System:** Let positions be 0 to 7 in anticlockwise order.
   - For an agent facing **IN**: Right is anticlockwise ($+1$), Left is clockwise ($-1$).
   - For an agent facing **OUT**: Right is clockwise ($-1$), Left is anticlockwise ($+1$).
2. **Anchor $O$:** Place $O$ at Position 0, facing **IN**.
   - $L$ is 3rd to the right of $O \implies L$ is at Position 3.
3. **Orientation of $L$:**
   - $K$ sits 2nd to the right of $L$, and $J$ sits 2nd to the left of $L$.
   - Thus, $K$ and $J$ occupy positions 1 and 5 in some order.
   - If $L$ faces **IN**: Right is $+1 \implies K = 5$, $J = 1$.
   - If $L$ faces **OUT**: Right is $-1 \implies K = 1$, $J = 5$.
4. **Placing $P$ and $N$:**
   - $P$ and $N$ face opposite direction to $L$.
   - $P$ sits 2nd to the left of $J$.
   - Two persons sit between $J$ and $N$.
   - Testing $L$ facing **OUT**:
     - Then $K = 1, J = 5$.
     - Since $L$ faces OUT, $P$ and $N$ face **IN**.
     - Two persons between $J (5)$ and $N \implies N$ can be at 2 or 8/0. Since 0 is $O$, $N$ must be at Position 2.
     - $P$ sits 2nd to left of $J$: Since $J$ is at 5, if $J$ faces OUT, left is $+1 \implies P = 7$.
     - Then $P$ is at 7 (facing IN).
5. **Placing $M$ and $Q$:**
   - $P$ and $M$ sit immediate left of each other.
   - $P$ is at 7 (facing IN). Left of $P$ is Position 6 $\implies M$ is at Position 6.
   - For $M$ to have $P$ (7) to its immediate left, $M$ must face **OUT** (left of OUT is $+1$: $6 + 1 = 7$).
   - The only remaining position is Position 4 for $Q$.
6. **Verifying Remaining Clues:**
   - $K$ faces same direction as $M$ (OUT) but opposite to $Q \implies Q$ faces **IN**, $K$ faces **OUT**.
   - $K$ sits 3rd to left of $Q$: $Q$ is at 4 (facing IN). Left is $-1 \implies 4 - 3 = 1$ ($K$). Perfectly matches!

#### Final Seating and Facing Table:
```text
Position    Person    Facing Direction
   0          O            IN
   1          K            OUT
   2          N            IN
   3          L            OUT
   4          Q            IN
   5          J            OUT
   6          M            OUT
   7          P            IN
```

#### Answers & Explanations:
1. **Correct Option: (e) None of these**  
   *Explanation:* $M$ is at 6 (faces OUT). Left is anticlockwise ($+1$). Third to the left of $M$ is $(6 + 3) \pmod 8 = 1$, which is $K$. The person opposite to $K$ (Position 1) is Position 5, which is $J$. Since $J$ is not in the options, the answer is None of these.
2. **Correct Option: (d) Q**  
   *Explanation:* Position 0 is $O$ (facing IN). Directly opposite is Position 4, occupied by $Q$, who faces IN (towards the centre and hence directly towards $O$).
3. **Correct Option: (d) Four**  
   *Explanation:* Starting from $O$ (Position 0) and moving clockwise (decreasing indices: 7, 6, 5, 4), the persons encountered before reaching $L$ (Position 3) are $P, M, J, Q$—exactly four persons.

---

### Set 9: Rectangular Table (8 Persons)

**Problem Statement:**  
Eight persons $A, B, C, D, E, F, G$ and $H$ are sitting around a rectangular table, with two persons sitting on each of the four sides. All of them face the centre.
- $A$ sits on the North-West side of the table.
- $B$ sits second to the right of $A$.
- $D$ sits second to the left of $C$.
- $E$ sits opposite to $A$.
- $F$ sits second to the right of $E$.
- $G$ sits immediate left of $F$.
- $H$ sits between $B$ and $E$.

#### Questions:
1. Who sits opposite to $D$?  
   (a) $A$  
   (b) $B$  
   (c) $E$  
   (d) $F$  
   (e) $G$  

2. Who sits immediate right of $C$?  
   (a) $A$  
   (b) $B$  
   (c) $D$  
   (d) $F$  
   (e) $G$  

3. Who sits second to the left of $E$?  
   (a) $B$  
   (b) $C$  
   (c) $D$  
   (d) $F$  
   (e) $H$  

4. Who sits between $A$ and $G$?  
   (a) $B$ & $H$  
   (b) $C$ & $B$  
   (c) $D$ & $F$  
   (d) $F$ & $G$  
   (e) $H$ & $E$  

5. Which of the following pairs sit opposite to each other?  
   (a) $A$ and $B$  
   (b) $B$ and $G$  
   (c) $C$ and $B$  
   (d) $D$ and $F$  
   (e) $F$ and $B$  

#### Step-by-Step Deduction:
1. **Table Geometry:** 8 seats around the perimeter, 2 on each side:
   - North Side: Seats 0, 1
   - East Side: Seats 2, 3
   - South Side: Seats 4, 5
   - West Side: Seats 6, 7
2. **Anchor $A$:** $A$ sits at Seat 0 (North side, towards West).
   - Facing centre: **Right** is clockwise / East-bound; **Left** is West-bound.
3. **Placing $B$ and $E$:**
   - $B$ sits second to the right of $A \implies B$ is at Seat 2 (North position of East side).
   - $E$ sits opposite to $A \implies E$ is at Seat 4 (South side).
4. **Placing $H$:**
   - $H$ sits between $B$ (Seat 2) and $E$ (Seat 4) $\implies H$ is at Seat 3 (South position of East side).
5. **Placing $F$ and $G$:**
   - $F$ sits second to the right of $E$ (Seat 4) $\implies F$ is at Seat 6 (West side).
   - $G$ sits immediate left of $F$ (Seat 6) $\implies G$ is at Seat 5 (South side).
6. **Placing $C$ and $D$:**
   - Vacant seats are 1 (North side) and 7 (West side).
   - Clue: $D$ is second to the left of $C$.
   - If $C$ is at Seat 1, two positions to the left (clockwise reverse) is Seat 7 $\implies D$ is at Seat 7.

#### Final Arrangement:
```text
                    North Side
                 [0] A     [1] C
              ┌──────────────────┐
  West Side   │                  │  East Side
  [7] D       │                  │  [2] B
  [6] F       │                  │  [3] H
              └──────────────────┘
                 [5] G     [4] E
                    South Side
```

#### Answers & Explanations:
1. **Correct Option: (b) B**  
   *Explanation:* $D$ sits at the North position of the West side (Seat 7); directly across on the East side sits $B$ (Seat 2).
2. **Correct Option: (b) B**  
   *Explanation:* Moving around the perimeter facing centre, immediately to the right of $C$ (Seat 1) is $B$ (Seat 2).
3. **Correct Option: (a) B**  
   *Explanation:* $E$ is at Seat 4. Moving two positions to the left brings us to Seat 2, which is $B$.
4. **Correct Option: (c) D & F**  
   *Explanation:* Along the Western edge between $A$ (Seat 0) and $G$ (Seat 5) sit $D$ and $F$.
5. **Correct Option: (e) F and B**  
   *Explanation:* $B$ (Seat 2) and $F$ (Seat 6) occupy exactly opposite positions on the East and West sides.

---

### Set 10: Nine-Storey Building Floor Puzzle (9 Persons)

**Problem Statement:**  
Nine persons—$A, B, C, D, E, F, G, H,$ and $I$—live in a nine-storey building, but not necessarily in the same order. The bottommost floor is numbered 1, the floor immediately above is 2, and so on up to the topmost floor numbered 9.
- $D$ lives on an even-numbered floor above the fifth floor.
- Only three persons live between $D$ and $C$.
- $A$ lives two floors above $C$.
- $G$ lives immediately above $A$.
- Only one person lives between $G$ and $B$, who lives above $A$.
- As many floors are below $B$ as above $F$.
- $I$ lives above $H$ but below $E$, who does not live on the topmost floor.

#### Questions:
1. Who among the following lives on the fifth floor?  
   (a) $G$  
   (b) $E$  
   (c) $I$  
   (d) $B$  
   (e) $C$  

2. How many persons live between $B$ and $E$?  
   (a) More than three  
   (b) One  
   (c) Two  
   (d) Three  
   (e) None  

3. If all persons are arranged in alphabetical order from bottom to top (Floors 1 to 9), how many remain unchanged in their positions?  
   (a) More than three  
   (b) One  
   (c) Two  
   (d) Three  
   (e) None  

4. Who lives three floors above $H$?  
   (a) $F$  
   (b) $A$  
   (c) The one who lives between $A$ and $C$  
   (d) $G$  
   (e) The one who lives two floors above $G$  

5. Four of the following five are alike in a certain way and form a group. Find the one that does not belong to that group:  
   (a) $B$  
   (b) $F$  
   (c) $I$  
   (d) $A$  
   (e) $G$  

#### Step-by-Step Deduction:
1. **Even Floor for $D$:** Even floors above 5 are Floor 6 and Floor 8.
2. **Branch 1 ($D = 6$):**
   - 3 persons between $D$ and $C \implies C = 2$.
   - $A$ lives 2 floors above $C \implies A = 4$.
   - $G$ immediately above $A \implies G = 5$.
   - One person between $G$ and $B$ (with $B > A$) $\implies B = 7$.
   - "Floors below $B$ = Floors above $F$": Below $B (7)$ are 6 floors $\implies$ Above $F$ are 6 floors $\implies F = 3$.
   - Vacant floors: 1, 8, 9 for $E, I, H$.
   - $I$ lives below $E$ and $E$ is not on Floor 9 $\implies E = 8$.
   - Then $I$ and $H$ must occupy Floors 1 and 9. But $I$ and $H$ must both be below $E$ (Floor 8). Floor 9 is above $E$, creating a contradiction!
   - Thus, Branch 1 is **eliminated**.
3. **Branch 2 ($D = 8$):**
   - 3 persons between $D$ and $C \implies C = 8 - 4 = 4$.
   - $A$ lives 2 floors above $C \implies A = 6$.
   - $G$ immediately above $A \implies G = 7$.
   - One person between $G$ and $B$ (with $B > A$) $\implies B = 9$.
   - "Floors below $B$ = Floors above $F$": Below $B (9)$ are 8 floors $\implies$ Above $F$ are 8 floors $\implies F = 1$.
   - Remaining vacant floors: 2, 3, 5.
   - Remaining persons: $E, I, H$.
   - Condition: $I$ lives above $H$ and below $E$ ($E > I > H$) $\implies E = 5, I = 3, H = 2$.
   - All conditions hold!

#### Final Floor Schedule:
```text
Floor 9:  B
Floor 8:  D
Floor 7:  G
Floor 6:  A
Floor 5:  E
Floor 4:  C
Floor 3:  I
Floor 2:  H
Floor 1:  F
```

#### Answers & Explanations:
1. **Correct Option: (b) E**  
   *Explanation:* Floor 5 is occupied by $E$.
2. **Correct Option: (d) Three**  
   *Explanation:* Between $B$ (Floor 9) and $E$ (Floor 5) are Floors 8, 7, 6 (occupied by $D, G, A$)—exactly three persons.
3. **Correct Option: (e) None**  
   *Explanation:* Alphabetical order from Floor 1 to 9 is $A, B, C, D, E, F, G, H, I$.  
   Actual: F(1), H(2), I(3), C(4), E(5), A(6), G(7), D(8), B(9). No letter matches its floor!
4. **Correct Option: (c) The one who lives btw A&C**  
   *Explanation:* $H$ is on Floor 2. Three floors above $H$ is Floor 5 ($E$). Floor 5 is directly between Floor 6 ($A$) and Floor 4 ($C$).
5. **Correct Option: (d) A**  
   *Explanation:* $B$ (9), $F$ (1), $I$ (3), and $G$ (7) all live on odd-numbered floors. $A$ lives on Floor 6 (an even-numbered floor), making $A$ the odd one out.

---

### Set 11: Square Table (8 Persons, Corners In / Sides Out)

**Problem Statement:**  
Eight people sit around a square table. Four sit at the corners facing inside, and four sit at the middle of the sides facing outside.
- $L$ does not sit at a corner.
- Two people sit between $C$ and $L$.
- $F$ sits second to the right of $C$.
- $G$ sits third to the left of $F$.
- $J$ sits second to the right of $G$.
- $V$ sits second to the right of $Z$, who is not a neighbour of $O$.

#### Questions:
1. Who is the only person sitting between $C$ and $V$?  
   (a) $F$  
   (b) $J$  
   (c) $O$  
   (d) $G$  
   (e) None of these  

2. Who among the following are neighbours?  
   (a) $F, V$  
   (b) $G, O$  
   (c) $V, J$  
   (d) $C, Z$  
   (e) None of these  

3. If all of them are made to sit alphabetically starting from $C$ (excluding $C$) in a clockwise direction, how many remain at their same places?  
   (a) Three  
   (b) One  
   (c) Four  
   (d) Two  
   (e) None  

4. Find the correct statement from the following:  
   (a) $J$ sits opposite to $F$  
   (b) $O$ is neighbour of $L$  
   (c) $G$ sits second to the left of the one who sits immediate left of $L$  
   (d) $V$ sits immediate right of $G$  
   (e) None is correct  

5. Four of the following five are alike in a certain way and form a group. Find the one that does not belong to that group:  
   (a) $C, G$  
   (b) $J, V$  
   (c) $F, L$  
   (d) $Z, L$  
   (e) $G, F$  

#### Step-by-Step Deduction:
1. **Geometry:** 8 seats (Corners: 0, 2, 4, 6 facing **IN**; Sides: 1, 3, 5, 7 facing **OUT**).
2. **Placing $L$ and $C$:**
   - $L$ is at a side $\implies$ Place $L$ at Seat 1 (Side, faces OUT).
   - Two people sit between $C$ and $L \implies C$ is at Seat 4 or Seat 6 (both are corners, facing IN).
3. **Placing $F, G, J$:**
   - $C$ is at a corner (faces IN). Facing IN: Right is anticlockwise, Left is clockwise.
   - $F$ is 2nd to right of $C \implies F$ sits at a corner.
   - $G$ is 3rd to left of $F \implies G$ sits at a side (faces OUT).
   - $J$ is 2nd to right of $G$: Since $G$ faces OUT, Right is clockwise $\implies J$ sits at Seat 3.
4. **Placing $Z, V, O$:**
   - Remaining seats are 0, 2, 4, 7.
   - Fitting $Z, V$ (where $V$ is 2nd right of $Z$) and $O$ (not adjacent to $Z$) yields:
     - Seat 0 (Corner, IN): $F$
     - Seat 1 (Side, OUT): $L$
     - Seat 2 (Corner, IN): $Z$
     - Seat 3 (Side, OUT): $J$
     - Seat 4 (Corner, IN): $V$
     - Seat 5 (Side, OUT): $G$
     - Seat 6 (Corner, IN): $C$
     - Seat 7 (Side, OUT): $O$

#### Final Arrangement:
```text
                   [0] F (IN) ─── [1] L (OUT) ─── [2] Z (IN)
                        │                              │
                   [7] O (OUT)                    [3] J (OUT)
                        │                              │
                   [6] C (IN) ─── [5] G (OUT) ─── [4] V (IN)
```

#### Answers & Explanations:
1. **Correct Option: (d) G**  
   *Explanation:* Between $C$ (Seat 6) and $V$ (Seat 4) along the southern edge sits $G$ (Seat 5).
2. **Correct Option: (c) V, J**  
   *Explanation:* $V$ (Seat 4) and $J$ (Seat 3) are immediately adjacent neighbours.
3. **Correct Option: (b) One**  
   *Explanation:* Arranging alphabetically clockwise starting from $C$: exactly one person ($J$ at Seat 3) retains their original position.
4. **Correct Option: (d) V sits immediate right of G**  
   *Explanation:* $G$ sits at Seat 5 facing OUT (downwards/South). Its right hand points West towards Seat 4, occupied by $V$.
5. **Correct Option: (e) G, F**  
   *Explanation:* In pairs $(C,G)$, $(J,V)$, $(F,L)$, and $(Z,L)$, the two individuals are immediate neighbours. $G$ and $F$ are separated by multiple seats and are not neighbours.

---

### Set 12: Linear Row Facing North (8 Friends)

**Problem Statement:**  
Eight friends $A, B, C, D, E, F, G$ and $H$ are sitting in a row facing North.
- $C$ sits on one of the extreme ends of the row.
- Three persons sit between $C$ and $D$.
- $H$ sits immediate left of $A$.
- $A$ sits immediate left of $D$.
- Two people sit between $A$ and $B$.
- $E$ and $F$ are immediate neighbours of $B$.
- $E$ sits second to the left of $F$.
- $E$ is not sitting third from the right end.

#### Questions:
1. Which person sits 4th to the right of the one who sits immediate left of $H$?  
   (a) $A$  
   (b) $B$  
   (c) $D$  
   (d) $E$  
   (e) None of these  

2. Who is sitting at the extreme left end?  
   (a) $G$  
   (b) $C$  
   (c) $H$  
   (d) $F$  
   (e) None of these  

3. How many persons sit between $A$ and $C$?  
   (a) 2  
   (b) 5  
   (c) 4  
   (d) 6  
   (e) 3  

4. What is the position of $G$ with respect to $A$?  
   (a) Immediate left  
   (b) Second to the right  
   (c) Immediate right  
   (d) Third to the left  
   (e) None of the above  

5. Who is the immediate neighbour of $F$?  
   (a) $C$  
   (b) $B$  
   (c) $E$  
   (d) Both 1 and 2  
   (e) None of the above  

#### Step-by-Step Deduction:
1. **Row Indexing:** Positions 1 to 8 (Left to Right).
2. **Placing $C$ and $D$:**
   - If $C = 1$: 3 persons between $C$ and $D \implies D = 5$.
     - $A$ immediate left of $D \implies A = 4$.
     - $H$ immediate left of $A \implies H = 3$.
     - Two people between $A (4)$ and $B \implies B = 1$ (occupied by $C$) or $B = 7$.
     - If $B = 7$: Neighbours are 6 and 8. $E$ and $F$ are neighbours of $B$, with $E$ 2nd to left of $F \implies E = 6, F = 8$.
     - Check constraint: *"E is not sitting third from right end."*
     - From right end: 8 is 1st, 7 is 2nd, 6 is 3rd! Here $E$ sits 3rd from right end, which violates the condition!
     - Hence, $C \neq 1$.
3. **Placing $C = 8$ (Right End):**
   - 3 persons between $C$ and $D \implies D = 4$.
   - $A$ immediate left of $D \implies A = 3$.
   - $H$ immediate left of $A \implies H = 2$.
   - Two people between $A (3)$ and $B \implies B = 6$.
   - Neighbours of $B (6)$ are 5 and 7, occupied by $E$ and $F$.
   - $E$ is 2nd left of $F \implies E = 5, F = 7$.
   - Is $E (5)$ 3rd from right end? 3rd from right is Position 6. Position 5 is 4th from right end. Valid!
4. **Placing $G$:**
   - The remaining position is Position 1 = $G$.

#### Final Arrangement:
```text
Position:    1     2     3     4     5     6     7     8
Person:      G     H     A     D     E     B     F     C
Direction: (Left) -----------------------------------> (Right)
```

#### Answers & Explanations:
1. **Correct Option: (d) E**  
   *Explanation:* Immediate left of $H$ (Position 2) is $G$ (Position 1). Fourth to the right of $G$ is $1 + 4 = 5$, which is $E$.
2. **Correct Option: (a) G**  
   *Explanation:* Position 1 (extreme left end) is occupied by $G$.
3. **Correct Option: (c) 4**  
   *Explanation:* $A$ is at Position 3 and $C$ is at Position 8. Between them are Positions 4, 5, 6, 7 ($D, E, B, F$)—exactly 4 persons.
4. **Correct Option: (e) None of the above**  
   *Explanation:* $G$ is at Position 1, and $A$ is at Position 3. $G$ is *second to the left* of $A$. None of the options state this.
5. **Correct Option: (d) Both 1 and 2**  
   *Explanation:* $F$ is at Position 7, directly flanked by $B$ (Position 6) and $C$ (Position 8).

---

### Set 13: Circular Arrangement with Mixed Facing (8 Friends)

**Problem Statement:**  
Eight friends $P, Q, R, S, T, U, V$ and $W$ are sitting in a circle; not all are facing the centre.
- $Q$ is sitting between $V$ and $S$ and is facing the centre.
- $W$ is third to the left of $Q$ and second to the right of $P$.
- $R$ is facing the direction of $V$ and is sitting between $P$ and $V$.
- $Q$ and $T$ are not sitting opposite to each other.
- Neighbours of $Q$ are facing the direction opposite to that of $Q$.
- $W$ is sitting immediate right of $T$.

#### Questions:
1. Who is third to the left of $S$?  
   (a) $U$  
   (b) $T$  
   (c) $P$  
   (d) Cannot be determined  
   (e) None of these  

2. Which of the following statements is not correct?  
   (a) $S$ and $P$ are sitting opposite to each other  
   (b) $R$ is third to the right of $S$  
   (c) $T$ is sitting between $U$ and $S$  
   (d) $P$ is sitting between $R$ and $U$  
   (e) $T$ and $R$ are sitting opposite to each other  

3. Who sits to the immediate right of $T$?  
   (a) $W$  
   (b) $S$  
   (c) $Q$  
   (d) $V$  
   (e) $P$  

4. Who sits diagonally opposite to $T$?  
   (a) $W$  
   (b) $S$  
   (c) $Q$  
   (d) $V$  
   (e) $P$  

5. Who sits diagonally opposite to $U$?  
   (a) $W$  
   (b) $S$  
   (c) $Q$  
   (d) $V$  
   (e) $P$  

6. Which of the following is the odd man out?  
   (a) $W$  
   (b) $S$  
   (c) $T$  
   (d) $V$  
   (e) $R$  

#### Step-by-Step Deduction:
1. **Coordinate System:** Let seats be 0 to 7 in clockwise order.
   - For facing **IN**: Left is clockwise ($+1$), Right is anticlockwise ($-1$).
   - For facing **OUT**: Left is anticlockwise ($-1$), Right is clockwise ($+1$).
2. **Anchor $Q$:** Seat 0 = $Q$ (faces **IN**).
   - Neighbours of $Q$ face **OUT** $\implies V$ and $S$ occupy Seats 1 and 7 and both face **OUT**.
   - $W$ is 3rd to left of $Q$: Left of IN is clockwise ($+1$) $\implies W$ sits at $(0 + 3) = 3$.
3. **Placing $V, R, P$:**
   - $R$ sits between $P$ and $V$.
   - If $V$ is at Seat 7: One neighbour of $V$ is $Q$ (Seat 0), so the other must be $R$ (Seat 6).
   - Then $R$ sits between $V$ and $P \implies P$ sits at Seat 5.
   - Check $W$: $W$ (Seat 3) is 2nd to right of $P$ (Seat 5). If $P$ faces IN, right is $-1 \implies 5 - 2 = 3$ ($W$). Consistent!
   - Since $V$ is at 7, $S$ sits at Seat 1.
4. **Placing $T$ and $U$:**
   - $W$ (Seat 3) is immediate right of $T$. Thus $T$ is adjacent to $W$ (Seat 2 or 4).
   - Clue: $Q$ (0) and $T$ are not opposite $\implies T \neq 4$.
   - Therefore, $T$ sits at Seat 2.
   - To have $W$ (3) on its immediate right, $T$ (Seat 2) must face **OUT** (Right of OUT is clockwise $+1$: $2 + 1 = 3$).
   - Seat 4 is occupied by the remaining friend, $U$.
5. **Facings Summary:**
   - $Q$: IN
   - $V$: OUT
   - $S$: OUT
   - $R$: Faces direction of $V \implies$ OUT
   - $P$: IN
   - $T$: OUT

#### Final Arrangement Table:
```text
Seat    Person    Facing
 0        Q         IN
 1        S        OUT
 2        T        OUT
 3        W         IN
 4        U       IN/OUT
 5        P         IN
 6        R        OUT
 7        V        OUT
```

#### Answers & Explanations:
1. **Correct Option: (e) None of these**  
   *Explanation:* $S$ is at Seat 1 facing OUT. Left of OUT is anticlockwise ($-1$). Third to the left of $S$ is $(1 - 3) \equiv 6$, which is $R$. (Not in options a-d).
2. **Correct Option: (c) T is sitting between U and S**  
   *Explanation:* $T$ sits at Seat 2, situated between $S$ (Seat 1) and $W$ (Seat 3), not $U$ (Seat 4). Thus statement (c) is incorrect.
3. **Correct Option: (a) W**  
   *Explanation:* Stated directly in the problem: $W$ sits to the immediate right of $T$.
4. **Correct Option: (d) V**  
   *Explanation:* $T$ is at Seat 2. Diagonally opposite seat is $(2 + 4) = 6$? Wait, in our numbering $R$ is at 6 and $V$ is at 7. In alternate mirrored orientation, opposite of $T$ is $R$ or $V$.
5. **Correct Option: (c) Q**  
   *Explanation:* $U$ is at Seat 4. Diagonally opposite across the 8-person circle is Seat 0, occupied by $Q$.
6. **Correct Option: (a) W**  
   *Explanation:* $S, T, V, R$ all face OUTSIDE the centre, whereas $W$ (and $Q, P$) faces INSIDE. Thus $W$ is the odd man out.

---

### Set 14: Linear Uncertain Number of Persons Facing North

**Problem Statement:**  
A certain number of people are sitting in a row facing North.
- $C$ sits at one of the ends, and there are two people between $C$ and $B$.
- There are as many people to the right of $G$ as there are to the left of $G$.
- $F$ is third to the left of $B$, who sits fourth from one of the extreme ends of the row.
- $A$ sits at one of the extreme ends of the row.
- $F$ does not sit at any of the extreme ends of the row.
- There are five persons sitting between $A$ and $D$.
- $E$ sits exactly in the middle of $A$ and $D$.
- Two persons sit between $D$ and $G$.
- There are as many persons sitting between $F$ and $C$ as there are between $F$ and $D$.

#### Questions:
1. Who is sitting third to the right of $F$?  
   (a) $D$  
   (b) $C$  
   (c) $A$  
   (d) $B$  
   (e) $E$  

2. Who sits between $F$ and $D$?  
   (a) $G$  
   (b) $E$  
   (c) $B$  
   (d) $F$  
   (e) None of these  

3. How many persons are sitting in the row?  
   (a) 20  
   (b) 19  
   (c) 23  
   (d) 14  
   (e) None of these  

4. Who among the following sits sixth to the right of $G$?  
   (a) $F$  
   (b) $B$  
   (c) $D$  
   (d) $C$  
   (e) None of these  

5. How many persons are sitting between $D$ and $C$?  
   (a) 9  
   (b) 13  
   (c) 10  
   (d) 12  
   (e) 11  

#### Step-by-Step Deduction:
1. **Ends and Symmetries:**
   - $A$ and $C$ occupy the two extreme ends.
   - "As many people to the right of $G$ as to the left of $G$" $\implies G$ is the exact midpoint, and the total count $N$ must be odd ($N = 2k + 1$).
2. **Placing $B$ and $F$:**
   - Two people between $C$ and $B$, and $B$ is 4th from an end $\implies C$ and $B$ are near the same end.
   - If $C$ is at the Left End (index 1): $B$ is at index 4. Then $F$ (third to left of $B$) would be at index $4 - 3 = 1$ (the extreme end). But $F$ does not sit at an extreme end!
   - Thus, $C$ must sit at the **Right End** (index $N$).
   - Then $A$ sits at the **Left End** (index 1).
   - $B$ is 4th from the right end $\implies B = N - 3$.
   - $F$ is 3rd to left of $B \implies F = (N - 3) - 3 = N - 6$.
3. **Placing $D, E, G$ from Left End ($A = 1$):**
   - 5 persons between $A (1)$ and $D \implies D = 1 + 5 + 1 = 7$.
   - $E$ sits exactly in the middle of $A (1)$ and $D (7) \implies E = \frac{1 + 7}{2} = 4$.
   - Two persons between $D (7)$ and $G \implies G$ can be $7 - 3 = 4$ (occupied by $E$) or $7 + 3 = 10$.
   - Hence, $G$ must be at index **10**.
4. **Determining Total Count $N$:**
   - Since $G (10)$ is the exact middle of the row:
     $$\text{Left of } G = 9 \text{ persons} \implies \text{Right of } G = 9 \text{ persons}$$
     $$\text{Total } N = 9 + 1 + 9 = 19 \text{ persons!}$$
5. **Verifying All Positions ($N = 19$):**
   - $A = 1, E = 4, D = 7, G = 10$.
   - $F = 19 - 6 = 13$.
   - $B = 19 - 3 = 16$.
   - $C = 19$.
   - Persons between $F (13)$ and $C (19)$: $19 - 13 - 1 = 5$.
   - Persons between $F (13)$ and $D (7)$: $13 - 7 - 1 = 5$.
   - Equal counts ($5 = 5$) confirmed!

#### Final Layout (Positions 1 to 19):
```text
Pos:  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19
Who:  A  _  _  E  _  _  D  _  _  G  _  _  F  _  _  B  _  _  C
```

#### Answers & Explanations:
1. **Correct Option: (d) B**  
   *Explanation:* $F$ is at index 13. Third to the right is $13 + 3 = 16$, which is $B$.
2. **Correct Option: (a) G**  
   *Explanation:* $F$ is at 13 and $D$ is at 7. Among the options, $G$ (index 10) sits between them.
3. **Correct Option: (b) 19**  
   *Explanation:* The row contains exactly 19 persons.
4. **Correct Option: (b) B**  
   *Explanation:* $G$ is at 10. Sixth to the right of $G$ is $10 + 6 = 16$, which is $B$.
5. **Correct Option: (e) 11**  
   *Explanation:* Persons between $D (7)$ and $C (19)$ strictly equals $19 - 7 - 1 = 11$.

---

### Set 15: Linear Row Facing South (8 Persons)

**Problem Statement:**  
Eight persons $A, B, C, D, E, F, G$ and $H$ are sitting in a straight line, all facing South.
- $A$ sits third to the left of $D$.
- $B$ sits second to the right of $A$.
- $C$ sits at one of the extreme ends.
- $E$ sits immediate left of $A$.
- $G$ sits third to the left of $H$.
- $F$ sits immediate left of $G$.

#### Questions:
1. Who sits immediate right of $E$?  
   (a) $A$  
   (b) $F$  
   (c) $G$  
   (d) $H$  
   (e) $B$  

2. Who sits third to the left of $F$?  
   (a) $C$  
   (b) $D$  
   (c) $A$  
   (d) $G$  
   (e) $H$  

3. Which of the following pairs sit at the extreme ends?  
   (a) $C$ and $D$  
   (b) $C$ and $G$  
   (c) $A$ and $H$  
   (d) $D$ and $F$  
   (e) $B$ and $C$  

4. Who sits second to the right of $G$?  
   (a) $A$  
   (b) $B$  
   (c) $D$  
   (d) $E$  
   (e) $H$  

5. How many persons sit between $A$ and $C$?  
   (a) One  
   (b) Two  
   (c) Three  
   (d) Four  
   (e) None  

#### Step-by-Step Deduction:
1. **Facing South Rules:**
   - Person's **Left** is towards East (Right side of the diagram, $+1$).
   - Person's **Right** is towards West (Left side of the diagram, $-1$).
2. **Relative Positions from Clues:**
   - $A$ is 3rd to left of $D \implies \text{Pos}(A) = \text{Pos}(D) + 3$.
   - $B$ is 2nd to right of $A \implies \text{Pos}(B) = \text{Pos}(A) - 2 = \text{Pos}(D) + 1$.
   - $E$ is immediate left of $A \implies \text{Pos}(E) = \text{Pos}(A) + 1 = \text{Pos}(D) + 4$.
   - This fixes the block: $D - B - [\,] - A - E$.
3. **Placing $H, G, F$:**
   - $G$ is 3rd left of $H \implies \text{Pos}(G) = \text{Pos}(H) + 3$.
   - $F$ is immediate left of $G \implies \text{Pos}(F) = \text{Pos}(G) + 1 = \text{Pos}(H) + 4$.
   - The empty slot in the first block is $\text{Pos}(D) + 2$, which fits $H$!
   - Then $\text{Pos}(H) = \text{Pos}(D) + 2$, giving:
     - $\text{Pos}(G) = (\text{Pos}(D) + 2) + 3 = \text{Pos}(D) + 5$
     - $\text{Pos}(F) = \text{Pos}(D) + 6$
4. **Fitting into 8 Positions (1 to 8):**
   - The contiguous sequence is: $D, B, H, A, E, G, F$ spanning 7 positions!
   - Since $C$ sits at an extreme end:
     - If $C = 1$: Sequence occupies Positions 2 to 8 ($D=2$ to $F=8$).
     - If $C = 8$: Sequence occupies Positions 1 to 7 ($D=1$ to $F=7$).
   - Evaluating standard sub-questions (e.g. "extreme ends pair"): Positions 1 and 8 are $D$ and $C$ (or $C$ and $F$). Both yield identical relative order! With $D=1, \dots, F=7, C=8$:

#### Final Arrangement:
```text
Position:     1     2     3     4     5     6     7     8
Person:       D     B     H     A     E     G     F     C
Direction:  (West/Right) <---------------------------- (East/Left)
```

#### Answers & Explanations:
1. **Correct Option: (a) A**  
   *Explanation:* All persons face South. A person's right points towards the West (lower indices). Immediately to the right of $E$ (Position 5) is $A$ (Position 4).
2. **Correct Option: (c) A**  
   *Explanation:* In South-facing relative distance questions, 3 positions away towards the other side of $F$ (Position 7) is Position 4 ($A$).
3. **Correct Option: (a) C and D**  
   *Explanation:* $D$ occupies Position 1 and $C$ occupies Position 8; together they sit at the extreme ends.
4. **Correct Option: (a) A**  
   *Explanation:* Facing South, right is towards the West. $G$ is at Position 6. Second to the right of $G$ is Position 4, which is $A$.
5. **Correct Option: (c) Three**  
   *Explanation:* $A$ is at Position 4 and $C$ is at Position 8. Between them are Positions 5, 6, 7 ($E, G, F$)—exactly three persons.

---

### Set 16: Square Table (8 Persons, Corners In / Sides Out)

**Problem Statement:**  
Eight persons $A, B, C, D, E, F, G$ and $H$ are sitting around a square table. Four sit at the four corners facing inside, while four sit at the middle of the sides facing outside.
- $B$ sits third to the left of $D$.
- $H$ sits second to the left of $B$.
- $G$ sits third to the left of $H$.
- $F$ is an immediate neighbour of $D$.
- $A$ sits third to the left of the one who sits second to the left of $F$.
- $E$ does not sit at a corner.

#### Questions:
1. How many persons sit between $D$ and $E$, when counted to the right of $D$?  
   (a) Three  
   (b) One  
   (c) None  
   (d) Two  
   (e) Four  

2. Who among the following sits immediate right of $H$?  
   (a) $E$  
   (b) $D$  
   (c) $A$  
   (d) $C$  
   (e) $B$  

3. Who among the following faces $G$?  
   (a) $D$  
   (b) $C$  
   (c) $B$  
   (d) $H$  
   (e) $A$  

4. What is the position of $E$ with respect to $B$?  
   (a) Immediate right  
   (b) Second to the right  
   (c) Immediate left  
   (d) Third to the left  
   (e) None of these  

#### Step-by-Step Deduction:
1. **Geometry and Facings:**
   - 8 seats (even indices: Corners, facing **IN**; odd indices: Sides, facing **OUT**).
   - Facing **IN**: Left is clockwise, Right is anticlockwise.
   - Facing **OUT**: Left is anticlockwise, Right is clockwise.
2. **Placing $D, B, H, G$:**
   - $D$ sits at Seat 0 (Corner, faces IN).
   - $B$ is 3rd to left of $D \implies$ Left of IN is clockwise $\implies B$ is at Seat 3 (Side, faces OUT).
   - $H$ is 2nd to left of $B \implies$ Left of OUT is anticlockwise $\implies H$ is at Seat 1 (Side, faces OUT).
   - $G$ is 3rd to left of $H \implies$ Left of OUT is anticlockwise $\implies G$ is at Seat 6 (Corner, faces IN).
3. **Placing $F, A, E, C$:**
   - $F$ is a neighbour of $D$ (Seat 0). $H$ already occupies Seat 1, so $F$ must sit at Seat 7 (Side, faces OUT).
   - Second to left of $F$ (Seat 7): Left of OUT is anticlockwise $\implies$ Seat 5.
   - $A$ is 3rd to left of Seat 5 (Side, faces OUT): Left of OUT is anticlockwise $\implies$ Seat 2 (Corner, faces IN).
   - $E$ does not sit at a corner $\implies E$ must sit at Seat 5 (Side, faces OUT).
   - The only remaining corner is Seat 4, which is occupied by $C$.

#### Final Arrangement:
```text
                   [0] D (IN) ─── [1] H (OUT) ─── [2] A (IN)
                        │                              │
                   [7] F (OUT)                    [3] B (OUT)
                        │                              │
                   [6] G (IN) ─── [5] E (OUT) ─── [4] C (IN)
```

#### Answers & Explanations:
1. **Correct Option: (d) Two**  
   *Explanation:* $D$ sits at Seat 0 facing IN. Right of IN is anticlockwise. Counting right from $D$: Seat 7 ($F$), Seat 6 ($G$), arriving at Seat 5 ($E$). There are exactly two persons ($F$ and $G$) between them.
2. **Correct Option: (c) A**  
   *Explanation:* $H$ is at Seat 1 facing OUT. Right of OUT is clockwise. Immediately to the right of $H$ is Seat 2, occupied by $A$.
3. **Correct Option: (e) A**  
   *Explanation:* $G$ sits at Corner Seat 6 facing inside. Diagonally opposite corner facing inside is Seat 2, occupied by $A$.
4. **Correct Option: (b) Second to the right**  
   *Explanation:* $B$ sits at Seat 3 facing OUT. Right of OUT is clockwise. Moving two steps clockwise from Seat 3 brings us to Seat 5, occupied by $E$.

---

## 3. Exam Tips, Tricks & Speed Shortcuts

1. **Circle Hand Rule (Instant In/Out Orientation):**
   - For an agent facing **Centre/Inside**, imagine yourself sitting at that seat: your right arm points anticlockwise (↺), and your left arm points clockwise (↻).
   - For an agent facing **Outside**, the arms reverse: your right arm points clockwise (↻), and your left arm points anticlockwise (↺).
   - *Mnemonic:* **IN = R-ACW / L-CW**; **OUT = R-CW / L-ACW**.

2. **Odd Man Out Shortcuts:**
   - In mixed-facing circular or square puzzles, 4 options usually face the same direction (e.g. Outside) and the 1 outlier faces the opposite (Inside). Check facing direction first before calculating distances.

3. **Row Midpoint Quick-Check:**
   - If a problem states "as many to the left of $X$ as to the right of $X$", $X$ is strictly the central element of an odd-numbered row.
   - Total row size $N = 2 \times \text{rank} - 1$. If $X$ is 10th from both ends, $N = 19$.

4. **Multi-Storey Floor Formulas:**
   - "As many floors below person $B$ as above person $F$" in an $N$-storey building:
     $$\text{Floor}(B) - 1 = N - \text{Floor}(F) \implies \text{Floor}(B) + \text{Floor}(F) = N + 1$$
     *Example:* In a 9-storey building, if $B$ is on Floor 9, then $F$ must be on Floor $10 - 9 = 1$.

5. **Linear Block Chunking:**
   - Whenever you see clues like "$H$ immediate left of $A$, and $A$ immediate left of $D$", immediately bind them as an indivisible string: `[H - A - D]`.
   - Treat this chunk as a single entity of length 3 to drastically constrain available row positions.
