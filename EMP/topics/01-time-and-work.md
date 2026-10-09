# 01. Time and Work

A comprehensive, self-contained reference guide covering fundamental principles, mathematical derivations, standard formulas, high-yield exam shortcuts, and 30 fully solved problems covering Time & Work, Chain Rule, Wages, and Pipes & Cisterns.

---

## 1. Comprehensive Theory and Formulas

### 1.1 Fundamental Concepts & Definitions

Time and work problems model the relationship between the time required to complete a given task, the rate of work (productivity), and the total magnitude of work accomplished.

#### 1. The Fundamental Work Equation
$$\text{Total Work} = \text{Rate of Work (Efficiency)} \times \text{Time Taken}$$

- **Rate of Work ($R$):** The fraction of total work completed in one unit of time (per day, per hour, per minute).
$$R = \frac{\text{Total Work}}{\text{Time Taken}}$$
- **Time Taken ($T$):** The total duration required to complete the work at a constant rate.
$$T = \frac{\text{Total Work}}{R}$$

#### 2. The Reciprocal Law (Unitary Method)
If a person completes a piece of work in $n$ days, the fraction of work completed in 1 day is:
$$\text{One Day's Work} = \frac{1}{n}$$
Conversely, if a person finishes $\frac{1}{n}$ part of the work in one day, the entire work will be completed in:
$$\text{Total Time} = n \text{ days}$$

#### 3. The LCM Unit Method (Zero-Fraction Approach)
Instead of assuming total work as $1$ (which introduces fractions), assume total work to be the **Least Common Multiple (LCM)** of the individual completion times:
$$\text{Total Work Units} = \text{LCM}(t_1, t_2, \dots, t_n)$$
$$\text{Efficiency of worker } i = \frac{\text{Total Work Units}}{t_i} \text{ (units/day)}$$
Working in integer units accelerates computation and eliminates arithmetic errors in competitive exams.

#### 4. Efficiency and Time Inversion
For a constant quantum of work, efficiency is inversely proportional to time taken:
$$\text{Efficiency} \propto \frac{1}{\text{Time}}$$
- If the efficiency ratio of two workers A and B is $a : b$, the ratio of time taken by them to complete the same work is:
$$\text{Time}_A : \text{Time}_B = \frac{1}{a} : \frac{1}{b} = b : a$$

---

### 1.2 Combined Work & Multiple Workers

#### 1. Two Workers Working Together
If worker A completes a job in $a$ days and worker B in $b$ days:
$$\text{Combined 1-day work} = \frac{1}{a} + \frac{1}{b} = \frac{a + b}{ab}$$
$$\text{Total time taken together } (T) = \frac{ab}{a + b} \text{ days}$$

#### 2. Three Workers Working Together
If workers A, B, and C complete a job in $a$, $b$, and $c$ days respectively:
$$\text{Combined 1-day work} = \frac{1}{a} + \frac{1}{b} + \frac{1}{c} = \frac{ab + bc + ca}{abc}$$
$$\text{Total time taken together } (T) = \frac{abc}{ab + bc + ca} \text{ days}$$

#### 3. Pairwise Cyclic Combinations
When work rates are given in pairs: $(A + B)$ in $x$ days, $(B + C)$ in $y$ days, and $(C + A)$ in $z$ days:
$$2(A + B + C) = \frac{1}{x} + \frac{1}{y} + \frac{1}{z}$$
$$A + B + C = \frac{1}{2} \left( \frac{1}{x} + \frac{1}{y} + \frac{1}{z} \right)$$
To find individual rates:
- Rate of $A = (A + B + C) - (B + C)$
- Rate of $B = (A + B + C) - (C + A)$
- Rate of $C = (A + B + C) - (A + B)$

---

### 1.3 Leaving and Joining Dynamics

In multistage projects, individuals join or leave after working for some time or before completion.

1. **Worker leaves after $d$ days from start:**
   - Work done in initial $d$ days $= d \times (R_A + R_B)$.
   - Remaining work $= W_{\text{total}} - d(R_A + R_B)$.
   - Remaining time for continuing workers $= \frac{\text{Remaining Work}}{\text{Rate of continuing workers}}$.

2. **Worker leaves $x$ days before completion ("Phantom Work" Technique):**
   - Let total time taken be $T$.
   - Standard equation: $R_A(T - x) + R_B(T) = W_{\text{total}}$.
   - **Shortcut:** If person A had not left, they would have contributed an additional $x \times R_A$ units of work.
   $$T = \frac{W_{\text{total}} + (x \times R_A)}{R_A + R_B}$$

---

### 1.4 Alternate Days / Periodic Cycles

When workers alternate on consecutive days (e.g., A on Day 1, B on Day 2, etc.):
1. **Define one full cycle:** In a 2-person system, 1 cycle $= 2$ days.
2. **Calculate work per cycle:** Work done in 1 cycle $= R_A + R_B$.
3. **Determine completed integer cycles:**
   $$\text{Full cycles} = \left\lfloor \frac{\text{Total Work}}{\text{Work per cycle}} \right\rfloor$$
4. **Evaluate remaining work:** $\text{Remaining Work} = \text{Total Work} - (\text{Full cycles} \times \text{Work per cycle})$.
5. **Allocate remaining work to the active worker:**
   - If $\text{Remaining Work} \le R_{\text{next}}$, extra time $= \frac{\text{Remaining Work}}{R_{\text{next}}}$.
   - If $\text{Remaining Work} > R_{\text{next}}$, the next worker works a full day, and the subsequent worker handles the residual.

---

### 1.5 Efficiency, Ratios, and Percentages

- **Percentage More Efficient:** If A is $p\%$ more efficient than B:
  $$R_A = \left(1 + \frac{p}{100}\right) R_B$$
- **Percentage as Efficient:** If A is $p\%$ as efficient as B:
  $$R_A = \left(\frac{p}{100}\right) R_B$$
- **Time Difference Relation:** If A is $n$ times as efficient as B ($R_A = n R_B$), then A takes $\frac{1}{n}$ of the time B takes ($T_B = n T_A$).
  - If A takes $d$ days less than B:
  $$T_B - T_A = d \implies n T_A - T_A = d \implies T_A = \frac{d}{n - 1}, \quad T_B = \frac{n \cdot d}{n - 1}$$
  - Time together:
  $$T_{\text{together}} = \frac{T_A \cdot T_B}{T_A + T_B} = \frac{n \cdot d}{n^2 - 1}$$

---

### 1.6 Chain Rule & Multi-Variable Work Equivalence

When comparing work across different groups varying in headcount, days, daily hours, and efficiency:

#### 1. The General Chain Rule Equation
$$\frac{M_1 \cdot D_1 \cdot H_1 \cdot E_1}{W_1} = \frac{M_2 \cdot D_2 \cdot H_2 \cdot E_2}{W_2}$$
Where:
- $M$ = Number of workers
- $D$ = Number of days
- $H$ = Working hours per day
- $E$ = Efficiency factor of each worker
- $W$ = Total quantum of work completed (or earnings/wages)

#### 2. Work Equivalence (Men, Women, Children)
If $p$ Men $= q$ Women $= r$ Boys:
- Convert all entities into a single baseline unit (e.g., in terms of 1 Man or 1 Woman) using their relative rates:
$$1M = \frac{q}{p}W = \frac{r}{p}B$$
- If a group equation is given: $D_1 (m_1 M + w_1 W) = D_2 (m_2 M + w_2 W)$, equate total work to solve for the efficiency ratio of $M : W$.

---

### 1.7 Division of Wages

The distribution of remuneration follows a strict economic principle:
$$\text{Wage Share} \propto \text{Actual Work Contributed}$$

1. **Equal Duration:** When all workers work for the same total time, their contributions are strictly proportional to their daily efficiencies:
$$\text{Wage}_A : \text{Wage}_B : \text{Wage}_C = R_A : R_B : R_C = \frac{1}{T_A} : \frac{1}{T_B} : \frac{1}{T_C}$$
2. **Unequal Duration:** When workers work for different numbers of days ($d_A, d_B, d_C$):
$$\text{Wage}_A : \text{Wage}_B : \text{Wage}_C = (R_A \cdot d_A) : (R_B \cdot d_B) : (R_C \cdot d_C)$$
3. **Third Worker Share:** If A and B take help of C to finish a job in $t$ days:
$$\text{Work by C} = 1 - t \left( \frac{1}{T_A} + \frac{1}{T_B} \right)$$
$$\text{C's Wage} = (\text{Work by C}) \times \text{Total Contract Amount}$$

---

### 1.8 Pipes and Cisterns (Hydraulic Analogy)

Pipes and cisterns problems operate on identical principles to Time & Work, with one fundamental distinction: **work can be negative**.

- **Inlet Pipe (Positive Work):** Fills the cistern. If an inlet takes $x$ hours to fill a tank, its 1-hour filling rate is $+\frac{1}{x}$.
- **Outlet Pipe / Leak (Negative Work):** Empties the cistern. If an outlet takes $y$ hours to empty a tank, its 1-hour emptying rate is $-\frac{1}{y}$.
- **Net Work Rate:**
$$\text{Net Rate} = \sum R_{\text{inlets}} - \sum R_{\text{outlets}}$$
- **Condition I (Filling):** If $\sum R_{\text{inlets}} > \sum R_{\text{outlets}}$, the empty tank will be filled in:
$$T_{\text{fill}} = \frac{1}{\text{Net Rate}}$$
- **Condition II (Emptying):** If $\sum R_{\text{outlets}} > \sum R_{\text{inlets}}$, the full tank will be emptied in:
$$T_{\text{empty}} = \frac{1}{|\text{Net Rate}|}$$
- **Capacity with Inflow/Outflow Volume:** If an inlet admits $V_{\text{in}}$ liters per unit time while a leak operates, solve for capacity $C$:
$$\text{Net Emptying Rate} = \frac{C}{T_{\text{leak}}} - V_{\text{in}} = \frac{C}{T_{\text{combined}}}$$

---

## 2. Practice Problems & Step-by-Step Solutions

### Q1. Cyclic Pairwise Work
**Question:**  
A and B can complete a piece of work in 12 days, B and C can do it in 15 days, and C and A can do it in 20 days. If A works alone, how many days will it take him to complete the entire work?  
- a) 40 days  
- b) 60 days  
- c) 50 days  
- d) None of these  

**Correct Answer:** Option d) None of these (30 days)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Take total work as $\text{LCM}(12, 15, 20) = 60$ units.
   - Efficiency of $(A + B) = \frac{60}{12} = 5$ units/day.
   - Efficiency of $(B + C) = \frac{60}{15} = 4$ units/day.
   - Efficiency of $(C + A) = \frac{60}{20} = 3$ units/day.
2. **Sum of Pairwise Efficiencies:**
   $$2(A + B + C) = 5 + 4 + 3 = 12 \text{ units/day}$$
   $$A + B + C = \frac{12}{2} = 6 \text{ units/day}$$
3. **Efficiency of A alone:**
   $$\text{Efficiency of } A = (A + B + C) - (B + C) = 6 - 4 = 2 \text{ units/day}$$
4. **Time taken by A alone:**
   $$\text{Time} = \frac{\text{Total Work}}{\text{Efficiency of } A} = \frac{60}{2} = 30 \text{ days}$$
   Since 30 days is not among options a, b, or c, the correct choice is **None of these**.

**Shortcut / Exam Tip:**
$$\text{Rate of } A = \frac{(A+B) + (C+A) - (B+C)}{2} = \frac{5 + 3 - 4}{2} = 2 \implies \frac{60}{2} = 30 \text{ days}$$

---

### Q2. Worker Leaving Before Completion
**Question:**  
A can do a piece of work in 10 days and B can do the same work in 15 days. They start working together, but A leaves the job 5 days before the work is scheduled to be completed. How many days in total did it take to finish the work?  
- a) 12 days  
- b) 15 days  
- c) 18 days  
- d) None of these  

**Correct Answer:** Option d) None of these (9 days)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Let total work $= \text{LCM}(10, 15) = 30$ units.
   - Efficiency of $A = \frac{30}{10} = 3$ units/day.
   - Efficiency of $B = \frac{30}{15} = 2$ units/day.
2. **Analyze the Final Stage:**
   - A left 5 days before completion, so B worked alone for the last 5 days.
   - Work done by B in the last 5 days $= 5 \times 2 = 10$ units.
3. **Analyze the Combined Stage:**
   - Remaining work done by A and B together $= 30 - 10 = 20$ units.
   - Combined efficiency of $A + B = 3 + 2 = 5$ units/day.
   - Time spent working together $= \frac{20}{5} = 4$ days.
4. **Total Time:**
   $$\text{Total Duration} = 4 \text{ (together)} + 5 \text{ (B alone)} = 9 \text{ days}$$
   Since 9 days is not listed in (a), (b), or (c), the answer is **None of these**.

**Shortcut ("Phantom Work" Method):**
If A had stayed for the final 5 days, A would have contributed $5 \times 3 = 15$ extra units.
$$\text{Total Augmented Work} = 30 + 15 = 45 \text{ units}$$
$$\text{Total Time} = \frac{45}{3 + 2} = \frac{45}{5} = 9 \text{ days}$$

---

### Q3. Worker Leaving After Initial Days
**Question:**  
A can do a piece of work in 20 days and B in 30 days. They start working together, but A leaves after 4 days. How many more days will B take to finish the remaining work?  
- a) 12 days  
- b) 15 days  
- c) 18 days  
- d) None of these  

**Correct Answer:** Option d) None of these (20 days)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Let total work $= \text{LCM}(20, 30) = 60$ units.
   - Efficiency of $A = \frac{60}{20} = 3$ units/day.
   - Efficiency of $B = \frac{60}{30} = 2$ units/day.
2. **Work Done in Initial 4 Days:**
   - Combined rate of $A + B = 3 + 2 = 5$ units/day.
   - Work completed in 4 days $= 4 \times 5 = 20$ units.
3. **Remaining Work:**
   $$\text{Remaining Work} = 60 - 20 = 40 \text{ units}$$
4. **Time for B to finish remaining work:**
   $$\text{Time for B} = \frac{\text{Remaining Work}}{\text{Efficiency of } B} = \frac{40}{2} = 20 \text{ days}$$
   Since 20 days is not listed in (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
Fraction of work done in 4 days $= 4 \times \left(\frac{1}{20} + \frac{1}{30}\right) = 4 \times \frac{5}{60} = \frac{1}{3}$.  
Remaining work $= 1 - \frac{1}{3} = \frac{2}{3}$.  
Time for B $= \frac{2}{3} \times 30 = 20$ days.

---

### Q4. Alternate Day Working
**Question:**  
A can do a piece of work in 10 days and B in 15 days. They work on alternate days, starting with A on the first day. In how many days will the work be completed?  
- a) 12 days  
- b) 13 days  
- c) 14 days  
- d) None of these  

**Correct Answer:** Option a) 12 days

**Step-by-Step Solution:**
1. **LCM Method:**
   - Total work $= \text{LCM}(10, 15) = 30$ units.
   - Efficiency of $A = \frac{30}{10} = 3$ units/day.
   - Efficiency of $B = \frac{30}{15} = 2$ units/day.
2. **Cycle Analysis:**
   - Day 1 (A): 3 units
   - Day 2 (B): 2 units
   - 1 cycle (2 days) $= 3 + 2 = 5$ units.
3. **Number of Complete Cycles:**
   $$\text{Number of cycles} = \frac{\text{Total Work}}{\text{Work per cycle}} = \frac{30}{5} = 6 \text{ cycles}$$
4. **Total Days:**
   $$\text{Total Days} = 6 \text{ cycles} \times 2 \text{ days/cycle} = 12 \text{ days}$$

**Shortcut / Exam Tip:**
When total work is an exact integer multiple of the 2-day cycle output, simply multiply the quotient by 2. Here $30 / 5 = 6 \implies 6 \times 2 = 12$ days.

---

### Q5. Three Workers with Multiple Departures
**Question:**  
A, B, and C can complete a piece of work in 24 days, 32 days, and 64 days respectively. They all begin the work together, but A leaves after 6 days, and B leaves 6 days before the completion of the work. How many days did the work last?  
- a) 12 days  
- b) 13 days  
- c) 14 days  
- d) None of these  

**Correct Answer:** Option d) None of these (20 days)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Total work $= \text{LCM}(24, 32, 64) = 192$ units.
   - Efficiency of $A = \frac{192}{24} = 8$ units/day.
   - Efficiency of $B = \frac{192}{32} = 6$ units/day.
   - Efficiency of $C = \frac{192}{64} = 3$ units/day.
2. **Formulate by Total Days ($T$):**
   - A worked for exactly 6 days: $W_A = 6 \times 8 = 48$ units.
   - C worked for all $T$ days: $W_C = T \times 3 = 3T$ units.
   - B worked until 6 days before completion, so B worked for $(T - 6)$ days:
     $$W_B = 6(T - 6) = 6T - 36 \text{ units}$$
3. **Equate Total Work:**
   $$W_A + W_B + W_C = 192$$
   $$48 + (6T - 36) + 3T = 192$$
   $$9T + 12 = 192$$
   $$9T = 180 \implies T = 20 \text{ days}$$
   Since 20 days is not an option, the correct choice is **None of these**.

**Shortcut / Exam Tip:**
Work left after A leaves $= 192 - (6 \times 8) = 144$ units.  
B and C must finish 144 units with B leaving 6 days before completion.  
Augment B's work for 6 days: $144 + (6 \times 6) = 180$ units.  
Time for B + C from day 0 if A's part is excluded: $\frac{180}{6 + 3} = 20$ days total.

---

### Q6. Alternate Day Assistance
**Question:**  
A, B, and C can do a piece of work in 11 days, 20 days, and 55 days respectively. A works every day. If A is assisted by B on the first day, by C on the second day, by B on the third day, and so on alternately, in how many days will the work be completed?  
- a) 6 days  
- b) 8 days  
- c) 10 days  
- d) None of these  

**Correct Answer:** Option b) 8 days

**Step-by-Step Solution:**
1. **LCM Method:**
   - Total work $= \text{LCM}(11, 20, 55) = 220$ units.
   - Efficiency of $A = \frac{220}{11} = 20$ units/day.
   - Efficiency of $B = \frac{220}{20} = 11$ units/day.
   - Efficiency of $C = \frac{220}{55} = 4$ units/day.
2. **Cycle Analysis (2-Day Cycle):**
   - Day 1: A is assisted by B $\implies A + B = 20 + 11 = 31$ units.
   - Day 2: A is assisted by C $\implies A + C = 20 + 4 = 24$ units.
   - Work done in 1 cycle (2 days) $= 31 + 24 = 55$ units.
3. **Calculate Required Cycles:**
   $$\text{Number of cycles} = \frac{\text{Total Work}}{\text{Work per cycle}} = \frac{220}{55} = 4 \text{ full cycles}$$
4. **Total Days:**
   $$\text{Total Time} = 4 \text{ cycles} \times 2 \text{ days/cycle} = 8 \text{ days}$$

**Shortcut / Exam Tip:**
Notice that $55 \times 4 = 220$. The work finishes exactly at the end of the 4th cycle. Total days $= 4 \times 2 = 8$ days.

---

### Q7. Efficiency Percentage Comparison
**Question:**  
A is 50% more efficient than B. If B alone takes 30 days to complete a piece of work, how many days will A and B take to complete it working together?  
- a) 12 days  
- b) 7 days  
- c) 10 days  
- d) None of these  

**Correct Answer:** Option a) 12 days

**Step-by-Step Solution:**
1. **Ratio of Efficiencies:**
   - A is $50\%$ more efficient than B $\implies \text{Eff}_A = 1.5 \times \text{Eff}_B$.
   - Let efficiency of $B = 2$ units/day.
   - Then efficiency of $A = 3$ units/day.
2. **Determine Total Work:**
   $$\text{Total Work} = \text{Efficiency of } B \times \text{Time of } B = 2 \times 30 = 60 \text{ units}$$
3. **Combined Time:**
   - Combined efficiency $= 3 + 2 = 5$ units/day.
   $$\text{Time together} = \frac{60}{5} = 12 \text{ days}$$

**Shortcut / Exam Tip:**
$$T_{\text{together}} = \frac{T_B}{1 + \frac{\text{Eff}_A}{\text{Eff}_B}} = \frac{30}{1 + 1.5} = \frac{30}{2.5} = 12 \text{ days}$$

---

### Q8. Multiple Efficiency Multipliers
**Question:**  
A is twice as fast as B, and B is thrice as fast as C. If C alone can finish the work in 54 days, in how many days can all three of them finish the work together?  
- a) 4  
- b) 6  
- c) 4.5  
- d) None of these  

**Correct Answer:** Option d) None of these (5.4 days)

**Step-by-Step Solution:**
1. **Efficiency Ratios:**
   - $B = 3C$ and $A = 2B = 2(3C) = 6C$.
   - Ratio of efficiencies $A : B : C = 6 : 3 : 1$.
2. **Total Work:**
   - Efficiency of $C = 1$ unit/day.
   - C completes the work in 54 days $\implies \text{Total Work} = 1 \times 54 = 54$ units.
3. **Combined Efficiency:**
   $$\text{Eff}_{A+B+C} = 6 + 3 + 1 = 10 \text{ units/day}$$
4. **Time Taken Together:**
   $$\text{Time} = \frac{54}{10} = 5.4 \text{ days } \left(5 \frac{2}{5} \text{ days}\right)$$
   Since 5.4 days is not in (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
$$\text{Time} = \frac{\text{Time}_C}{\sum \text{Ratios}} = \frac{54}{6 + 3 + 1} = \frac{54}{10} = 5.4 \text{ days}$$

---

### Q9. Fractional Efficiency Increase
**Question:**  
A is 40% more efficient than B. If B alone takes 24 days to complete a job, how long will A and B working together take to finish it?  
- a) 4 days  
- b) 10 days  
- c) 15 days  
- d) None of these  

**Correct Answer:** Option b) 10 days

**Step-by-Step Solution:**
1. **Efficiency Ratio:**
   - A is $40\%$ more efficient than B $\implies \text{Eff}_A : \text{Eff}_B = 140 : 100 = 7 : 5$.
2. **Total Work:**
   $$\text{Total Work} = \text{Eff}_B \times \text{Time}_B = 5 \times 24 = 120 \text{ units}$$
3. **Combined Efficiency:**
   $$\text{Eff}_{A+B} = 7 + 5 = 12 \text{ units/day}$$
4. **Combined Time:**
   $$\text{Time} = \frac{120}{12} = 10 \text{ days}$$

**Shortcut / Exam Tip:**
$$T = \frac{T_B}{1 + 1.4} = \frac{24}{2.4} = 10 \text{ days}$$

---

### Q10. Efficiency Given Solo Worker A
**Question:**  
A is 30% more efficient than B. How much time will they take together to complete a job that A alone could have done in 23 days?  
- a) 21 days  
- b) 70 days  
- c) 49 days  
- d) 13 days  

**Correct Answer:** Option d) 13 days

**Step-by-Step Solution:**
1. **Efficiency Ratio:**
   - A is $30\%$ more efficient than B $\implies \text{Eff}_A : \text{Eff}_B = 130 : 100 = 13 : 10$.
2. **Total Work:**
   $$\text{Total Work} = \text{Eff}_A \times \text{Time}_A = 13 \times 23 = 299 \text{ units}$$
3. **Combined Efficiency:**
   $$\text{Eff}_{A+B} = 13 + 10 = 23 \text{ units/day}$$
4. **Time Taken Together:**
   $$\text{Time} = \frac{299}{23} = 13 \text{ days}$$

**Shortcut / Exam Tip:**
$$\text{Time} = \frac{\text{Eff}_A}{\text{Eff}_A + \text{Eff}_B} \times T_A = \frac{13}{13 + 10} \times 23 = \frac{13}{23} \times 23 = 13 \text{ days}$$

---

### Q11. Difference in Time Given Efficiency Ratio
**Question:**  
A is three times as efficient as B, and therefore takes 20 days less than B to complete a piece of work. If they work together, in how many days will the work be completed?  
- a) 11 days  
- b) 7 days  
- c) 4 days  
- d) None of these  

**Correct Answer:** Option d) None of these (7.5 days / $7 \frac{1}{2}$ days)  
*(Note: If option (b) was intended as $7\frac{1}{2}$ days in shorthand, it matches; rigorously as integer 7, the exact mathematical choice is None of these).*

**Step-by-Step Solution:**
1. **Time Ratio:**
   - Efficiency ratio $A : B = 3 : 1$.
   - Therefore, time ratio $T_A : T_B = 1 : 3$.
2. **Solve for Individual Times:**
   - Let $T_A = x$ and $T_B = 3x$.
   - Difference $= 3x - x = 2x = 20 \text{ days} \implies x = 10 \text{ days}$.
   - Thus, $T_A = 10$ days and $T_B = 30$ days.
3. **Combined Time:**
   $$T_{\text{together}} = \frac{T_A \times T_B}{T_A + T_B} = \frac{10 \times 30}{10 + 30} = \frac{300}{40} = 7.5 \text{ days } \left(7 \frac{1}{2} \text{ days}\right)$$

**Shortcut / Exam Tip:**
$$T_{\text{together}} = \frac{n \cdot d}{n^2 - 1} = \frac{3 \times 20}{3^2 - 1} = \frac{60}{8} = 7.5 \text{ days}$$

---

### Q12. Periodic Assistance Every Third Day
**Question:**  
A, B, and C can do a piece of work in 20, 30, and 60 days respectively. In how many days can A do the work if he is assisted by B and C on every third day?  
- a) 15 days  
- b) 20 days  
- c) 25 days  
- d) None of these  

**Correct Answer:** Option a) 15 days

**Step-by-Step Solution:**
1. **LCM Method:**
   - Total work $= \text{LCM}(20, 30, 60) = 60$ units.
   - Efficiency of $A = \frac{60}{20} = 3$ units/day.
   - Efficiency of $B = \frac{60}{30} = 2$ units/day.
   - Efficiency of $C = \frac{60}{60} = 1$ unit/day.
2. **Cycle Analysis (3-Day Cycle):**
   - Day 1: A works alone $= 3$ units.
   - Day 2: A works alone $= 3$ units.
   - Day 3: A is assisted by B and C $\implies A + B + C = 3 + 2 + 1 = 6$ units.
   - Total work in 1 cycle (3 days) $= 3 + 3 + 6 = 12$ units.
3. **Number of Complete Cycles:**
   $$\text{Cycles} = \frac{60}{12} = 5 \text{ cycles}$$
4. **Total Days:**
   $$\text{Total Days} = 5 \text{ cycles} \times 3 \text{ days/cycle} = 15 \text{ days}$$

**Shortcut / Exam Tip:**
Work per 3-day block $= 2(3) + (3 + 2 + 1) = 12$ units. Exactly $60 / 12 = 5$ blocks $\implies 5 \times 3 = 15$ days.

---

### Q13. Dependent Efficiency Equations
**Question:**  
A is 50% as efficient as B. C does half of the work done by A and B together. If C alone does the work in 40 days, then in how many days can A, B, and C together do the work?  
- a) 12 days  
- b) 13 (1/3) days  
- c) 20 days  
- d) None of these  

**Correct Answer:** Option b) 13 (1/3) days

**Step-by-Step Solution:**
1. **Efficiency Relations:**
   - Let efficiency of $B = 2$ units/day.
   - A is $50\%$ as efficient as B $\implies \text{Eff}_A = 1$ unit/day.
   - Combined rate of $A + B = 1 + 2 = 3$ units/day.
   - C does half the work of $(A + B) \implies \text{Eff}_C = \frac{3}{2} = 1.5$ units/day.
2. **Total Work:**
   $$\text{Total Work} = \text{Eff}_C \times \text{Time}_C = 1.5 \times 40 = 60 \text{ units}$$
3. **Combined Efficiency of A, B, and C:**
   $$\text{Eff}_{A+B+C} = 1 + 2 + 1.5 = 4.5 \text{ units/day}$$
4. **Time Taken Together:**
   $$\text{Time} = \frac{60}{4.5} = \frac{600}{45} = \frac{40}{3} = 13 \frac{1}{3} \text{ days}$$

**Shortcut / Exam Tip:**
Notice that $\text{Eff}_{A+B} = 2 \cdot \text{Eff}_C$.  
Therefore, $\text{Eff}_{A+B+C} = 3 \cdot \text{Eff}_C$.  
Since efficiency is 3 times that of C alone:
$$\text{Time together} = \frac{\text{Time}_C}{3} = \frac{40}{3} = 13 \frac{1}{3} \text{ days}$$

---

### Q14. Altered Efficiency System of Equations
**Question:**  
A and B working together can complete a work in 12 days. If A works at twice his original efficiency and B works at one-third of his original efficiency, the work is completed in 9 days. In how many days can A alone complete the work?  
- a) 12 days  
- b) 20 days  
- c) 30 days  
- d) None of these  

**Correct Answer:** Option b) 20 days

**Step-by-Step Solution:**
1. **Set Up Daily Rate Equations:**
   - Let daily work of A be $a$, and daily work of B be $b$.
   - Condition 1:
     $$a + b = \frac{1}{12} \quad \text{--- (Equation 1)}$$
   - Condition 2:
     $$2a + \frac{b}{3} = \frac{1}{9} \quad \text{--- (Equation 2)}$$
2. **Eliminate $b$:**
   - Multiply Equation 2 by 3:
     $$6a + b = \frac{3}{9} = \frac{1}{3} \quad \text{--- (Equation 3)}$$
   - Subtract Equation 1 from Equation 3:
     $$(6a + b) - (a + b) = \frac{1}{3} - \frac{1}{12}$$
     $$5a = \frac{4 - 1}{12} = \frac{3}{12} = \frac{1}{4}$$
     $$a = \frac{1}{20}$$
3. **Time Taken by A alone:**
   $$\text{Time for A} = \frac{1}{a} = 20 \text{ days}$$

**Shortcut / Exam Tip:**
Let total work $= 36$ units.  
$a + b = 36/12 = 3$.  
$2a + b/3 = 36/9 = 4 \implies 6a + b = 12$.  
Subtract: $5a = 9 \implies a = 1.8$ units/day.  
Time $= 36 / 1.8 = 20$ days.

---

### Q15. "Or" vs "And" Equivalence
**Question:**  
If 1 man or 2 women or 3 boys can do a piece of work in 88 days, then in how many days will 1 man, 1 woman, and 1 boy working together complete the same work?  
- a) 50 days  
- b) 45 days  
- c) 54 days  
- d) None of these  

**Correct Answer:** Option d) None of these (48 days)

**Step-by-Step Solution:**
1. **Equivalence Relation:**
   $$1M = 2W = 3B$$
   Express all workers in terms of Men ($M$):
   $$1W = \frac{1}{2}M, \quad 1B = \frac{1}{3}M$$
2. **Convert Target Group:**
   $$1M + 1W + 1B = 1M + \frac{1}{2}M + \frac{1}{3}M = \left(1 + \frac{1}{2} + \frac{1}{3}\right) M = \frac{11}{6}M$$
3. **Apply Chain Rule ($M_1 D_1 = M_2 D_2$):**
   $$1M \times 88 = \left(\frac{11}{6}M\right) \times D_2$$
   $$D_2 = \frac{88 \times 6}{11} = 8 \times 6 = 48 \text{ days}$$
   Since 48 days is not among options (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
$$D = \frac{\text{Given Days}}{\frac{\text{And}_M}{\text{Or}_M} + \frac{\text{And}_W}{\text{Or}_W} + \frac{\text{And}_B}{\text{Or}_B}} = \frac{88}{\frac{1}{1} + \frac{1}{2} + \frac{1}{3}} = \frac{88}{\frac{11}{6}} = \frac{88 \times 6}{11} = 48 \text{ days}$$

---

### Q16. Simultaneous Group Equations
**Question:**  
4 men and 6 women can complete a work in 8 days, while 3 men and 7 women can complete it in 10 days. In how many days will 10 women working alone complete the same work?  
- a) 22 days  
- b) 24 days  
- c) 25 days  
- d) None of these  

**Correct Answer:** Option d) None of these (40 days)

**Step-by-Step Solution:**
1. **Equate Total Work Equations:**
   $$8(4M + 6W) = 10(3M + 7W)$$
   $$32M + 48W = 30M + 70W$$
   $$32M - 30M = 70W - 48W$$
   $$2M = 22W \implies 1M = 11W$$
2. **Calculate Total Work in Woman-Days:**
   $$\text{Total Work} = 8(4M + 6W) = 8(4(11W) + 6W) = 8(44W + 6W) = 8 \times 50W = 400 \text{ woman-days}$$
3. **Time for 10 Women Alone:**
   $$\text{Time} = \frac{400 \text{ woman-days}}{10 \text{ women}} = 40 \text{ days}$$
   Since 40 days is not among options (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
$$m_1 D_1 - m_2 D_2 \implies 32 - 30 = 2M; \quad 70 - 48 = 22W \implies 1M = 11W$$
Substitute directly into the first group: $(44 + 6) \times 8 = 400$. Divide by 10: $40$ days.

---

### Q17. Headcount Reduction Midway
**Question:**  
40 men can complete a project in 30 days. After 10 days, 10 men leave the job. What is the total time taken to complete the project?  
- a) 22 days  
- b) 32 days  
- c) 36.66 days  
- d) None of these  

**Correct Answer:** Option c) 36.66 days ($36 \frac{2}{3}$ days)

**Step-by-Step Solution:**
1. **Total Quantum of Work:**
   $$\text{Total Work} = 40 \text{ men} \times 30 \text{ days} = 1200 \text{ man-days}$$
2. **Work Done in Initial 10 Days:**
   $$\text{Work Done} = 40 \text{ men} \times 10 \text{ days} = 400 \text{ man-days}$$
3. **Remaining Work and Men:**
   $$\text{Remaining Work} = 1200 - 400 = 800 \text{ man-days}$$
   $$\text{Remaining Men} = 40 - 10 = 30 \text{ men}$$
4. **Time for Remaining Work:**
   $$\text{Additional Days} = \frac{800}{30} = \frac{80}{3} = 26.66 \text{ days } \left(26 \frac{2}{3} \text{ days}\right)$$
5. **Total Time Taken:**
   $$\text{Total Time} = 10 + 26.66 = 36.66 \text{ days } \left(36 \frac{2}{3} \text{ days}\right)$$

**Shortcut / Exam Tip:**
The remaining work represented 20 days of work for 40 men ($40 \times 20$).  
With 30 men, time taken $= \frac{40 \times 20}{30} = \frac{80}{3} = 26.66$ days.  
Total $= 10 + 26.66 = 36.66$ days.

---

### Q18. Multi-Category Equivalent Work
**Question:**  
6 men can do a piece of work in 12 days. 8 women can do the same work in 18 days and 18 children can do it in 10 days. 4 men, 12 women and 20 children work together for 2 days. If only men were to finish the remaining work in 1 day, how many total men are required?  
- a) 24  
- b) 36  
- c) 30  
- d) None of these  

**Correct Answer:** Option b) 36

**Step-by-Step Solution:**
1. **Find Solo Completion Times:**
   - 1 man takes: $6 \times 12 = 72$ days.
   - 1 woman takes: $8 \times 18 = 144$ days.
   - 1 child takes: $18 \times 10 = 180$ days.
2. **LCM Method for Total Work:**
   - Total work $= \text{LCM}(72, 144, 180) = 720$ units.
   - Efficiency of 1 man $= \frac{720}{72} = 10$ units/day.
   - Efficiency of 1 woman $= \frac{720}{144} = 5$ units/day.
   - Efficiency of 1 child $= \frac{720}{180} = 4$ units/day.
3. **Daily Output of Mixed Group:**
   $$\text{Group Rate} = 4(10) + 12(5) + 20(4) = 40 + 60 + 80 = 180 \text{ units/day}$$
4. **Work Done in 2 Days:**
   $$\text{Work Completed} = 180 \times 2 = 360 \text{ units}$$
   $$\text{Remaining Work} = 720 - 360 = 360 \text{ units}$$
5. **Men Required to Finish in 1 Day:**
   - Required rate $= 360$ units/day.
   $$\text{Men Required} = \frac{360 \text{ units}}{10 \text{ units/man}} = 36 \text{ men}$$

**Shortcut / Exam Tip:**
Work completed in 2 days $= 2 \times \left(\frac{4}{72} + \frac{12}{144} + \frac{20}{180}\right) = 2 \times \left(\frac{1}{18} + \frac{1}{12} + \frac{1}{9}\right) = 2 \times \left(\frac{2 + 3 + 4}{36}\right) = 2 \times \frac{9}{36} = \frac{1}{2}$.  
Remaining work is exactly $\frac{1}{2}$.  
Whole work requires 72 man-days $\implies \frac{1}{2}$ work requires $72 / 2 = 36$ man-days $\implies 36$ men for 1 day.

---

### Q19. Division of Wages (Equal Duration)
**Question:**  
A can complete a piece of work in 12 days and B can complete it in 16 days. They contract to complete the work together for ₹5600. What is B's share of the wages?  
- a) 1080 rupees  
- b) 1350 rupees  
- c) 2400 rupees  
- d) 4320 rupees  

**Correct Answer:** Option c) 2400 rupees

**Step-by-Step Solution:**
1. **Ratio of Wages:**
   - Since both work together for the entire duration, wages are divided strictly in the ratio of their efficiencies.
   $$\text{Ratio} = \text{Eff}_A : \text{Eff}_B = \frac{1}{12} : \frac{1}{16} = 16 : 12 = 4 : 3$$
2. **Calculate B's Share:**
   - Total ratio parts $= 4 + 3 = 7$.
   $$\text{B's Share} = \frac{3}{7} \times 5600 = 3 \times 800 = 2400 \text{ rupees}$$

**Shortcut / Exam Tip:**
$$\text{B's Share} = \frac{T_A}{T_A + T_B} \times \text{Total} = \frac{12}{12 + 16} \times 5600 = \frac{12}{28} \times 5600 = \frac{3}{7} \times 5600 = 2400 \text{ rupees}$$

---

### Q20. Wage Share of an Assisting Worker
**Question:**  
A can do a piece of work in 20 days and B in 30 days. They undertake to do this work for ₹7200. With the help of C, they finish the work in exactly 8 days. How much should C be paid?  
- a) 2300 rupees  
- b) 3200 rupees  
- c) 2400 rupees  
- d) None of these  

**Correct Answer:** Option c) 2400 rupees

**Step-by-Step Solution:**
1. **Work Contributed by A in 8 Days:**
   $$W_A = 8 \times \frac{1}{20} = \frac{8}{20} = \frac{2}{5}$$
2. **Work Contributed by B in 8 Days:**
   $$W_B = 8 \times \frac{1}{30} = \frac{8}{30} = \frac{4}{15}$$
3. **Total Work Contributed by A and B:**
   $$W_A + W_B = \frac{2}{5} + \frac{4}{15} = \frac{6 + 4}{15} = \frac{10}{15} = \frac{2}{3}$$
4. **Work Contributed by C:**
   $$W_C = 1 - \frac{2}{3} = \frac{1}{3}$$
5. **C's Wage Share:**
   $$\text{C's Share} = \frac{1}{3} \times 7200 = 2400 \text{ rupees}$$

**Shortcut / Exam Tip:**
LCM $= 60$ units. In 8 days, total work done $= 60$.  
A does $8 \times 3 = 24$ units.  
B does $8 \times 2 = 16$ units.  
C does $60 - (24 + 16) = 20$ units.  
C's share $= \frac{20}{60} \times 7200 = \frac{1}{3} \times 7200 = 2400$ rupees.

---

### Q21. Three-Way Wage Distribution
**Question:**  
A, B, and C can do a piece of work in 10, 12, and 15 days respectively. They complete it together for ₹6000. What is B's share?  
- a) 1500 rupees  
- b) 1000 rupees  
- c) 1250 rupees  
- d) None of these  

**Correct Answer:** Option d) None of these (2000 rupees)

**Step-by-Step Solution:**
1. **Ratio of Daily Efficiencies:**
   $$\text{Eff}_A : \text{Eff}_B : \text{Eff}_C = \frac{1}{10} : \frac{1}{12} : \frac{1}{15}$$
   Multiply throughout by $\text{LCM}(10, 12, 15) = 60$:
   $$\text{Ratio} = 6 : 5 : 4$$
2. **Calculate Total Ratio Sum:**
   $$\text{Sum of terms} = 6 + 5 + 4 = 15$$
3. **Calculate B's Share:**
   $$\text{B's Share} = \frac{5}{15} \times 6000 = \frac{1}{3} \times 6000 = 2000 \text{ rupees}$$
   Since 2000 rupees is not listed in (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
B's share is $\frac{5}{15} = \frac{1}{3}$ of the total payout. $\frac{1}{3} \times 6000 = 2000$ rupees.

---

### Q22. Wage Division with Unequal Work Days
**Question:**  
A and B undertake to do a piece of work for ₹4500. A alone can do it in 10 days and B alone in 15 days. They start together, but after 3 days A leaves and B finishes the remaining work alone. What is A's share of the total wage?  
- a) 1275 rupees  
- b) 1200 rupees  
- c) 1350 rupees  
- d) None of these  

**Correct Answer:** Option c) 1350 rupees

**Step-by-Step Solution:**
1. **Determine Fraction of Work Done by A:**
   - A works for only 3 days.
   - In 1 day, A completes $\frac{1}{10}$ of the total work.
   - In 3 days, work done by A $= 3 \times \frac{1}{10} = \frac{3}{10}$.
2. **Calculate Wage Share:**
   - Wages are paid in direct proportion to work done:
   $$\text{A's Share} = \frac{3}{10} \times 4500 = 3 \times 450 = 1350 \text{ rupees}$$

**Shortcut / Exam Tip:**
Regardless of how long B takes to finish the rest, A only completed $\frac{3}{10}$ of the total contract. Therefore, A gets exactly $30\%$ of ₹4500 = ₹1350.

---

### Q23. Chain Rule with Differential Wage Rates
**Question:**  
Wages of 20 women for 15 days is 9000 rupees. If the daily wage of a man is one and a half times that of a woman, how many men must work for 30 days to earn 13500 rupees?  
- a) 10 men  
- b) 12 men  
- c) 20 men  
- d) None of these  

**Correct Answer:** Option a) 10 men

**Step-by-Step Solution:**
1. **Determine Daily Wage of 1 Woman:**
   $$\text{Total woman-days} = 20 \times 15 = 300$$
   $$\text{Daily wage of 1 woman} = \frac{9000}{300} = 30 \text{ rupees/day}$$
2. **Determine Daily Wage of 1 Man:**
   $$\text{Daily wage of 1 man} = 1.5 \times 30 = 45 \text{ rupees/day}$$
3. **Calculate Earnings of 1 Man in 30 Days:**
   $$\text{Earnings of 1 man in 30 days} = 30 \times 45 = 1350 \text{ rupees}$$
4. **Number of Men Required:**
   $$\text{Number of men} = \frac{\text{Target Amount}}{\text{Earnings per man}} = \frac{13500}{1350} = 10 \text{ men}$$

**Shortcut / Exam Tip:**
Using the compound chain rule:
$$\frac{M_1 \cdot D_1 \cdot W_1}{\text{Earning}_1} = \frac{M_2 \cdot D_2 \cdot W_2}{\text{Earning}_2} \implies \frac{20 \times 15 \times 1}{9000} = \frac{M_2 \times 30 \times 1.5}{13500}$$
$$\frac{300}{9000} = \frac{45 M_2}{13500} \implies \frac{1}{30} = \frac{M_2}{300} \implies M_2 = 10 \text{ men}$$

---

### Q24. Inlets and Outlet Simultaneous Operation
**Question:**  
Pipe A can fill a tank in 12 minutes, and Pipe B can fill it in 15 minutes. A third pipe, Pipe C, can empty the full tank in 20 minutes. If all three pipes are opened simultaneously, how long will it take to fill the empty tank?  
- a) 10 minutes  
- b) 12 minutes  
- c) 15 minutes  
- d) None of these  

**Correct Answer:** Option a) 10 minutes

**Step-by-Step Solution:**
1. **LCM Method:**
   - Let tank capacity $= \text{LCM}(12, 15, 20) = 60$ units.
   - Inlet rate of $A = +\frac{60}{12} = +5$ units/min.
   - Inlet rate of $B = +\frac{60}{15} = +4$ units/min.
   - Outlet rate of $C = -\frac{60}{20} = -3$ units/min.
2. **Net Flow Rate:**
   $$\text{Net Rate} = +5 + 4 - 3 = +6 \text{ units/min}$$
3. **Time to Fill:**
   $$\text{Time} = \frac{60}{6} = 10 \text{ minutes}$$

**Shortcut / Exam Tip:**
$$\text{Net 1-minute rate} = \frac{1}{12} + \frac{1}{15} - \frac{1}{20} = \frac{5 + 4 - 3}{60} = \frac{6}{60} = \frac{1}{10} \implies 10 \text{ minutes}$$

---

### Q25. One Pipe Closed Midway
**Question:**  
Two pipes A and B can fill a cistern in 20 minutes and 30 minutes, respectively. Both pipes are opened together, but Pipe A is closed after 8 minutes. What is the total time required to fill the cistern?  
- a) 10 minutes  
- b) 12 minutes  
- c) 15 minutes  
- d) None of these  

**Correct Answer:** Option d) None of these (18 minutes)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Capacity $= \text{LCM}(20, 30) = 60$ units.
   - Efficiency of $A = \frac{60}{20} = 3$ units/min.
   - Efficiency of $B = \frac{60}{30} = 2$ units/min.
2. **Initial 8 Minutes:**
   - Both pipes open $\implies 3 + 2 = 5$ units/min.
   - Volume filled in 8 minutes $= 8 \times 5 = 40$ units.
3. **Remaining Volume:**
   $$\text{Remaining Capacity} = 60 - 40 = 20 \text{ units}$$
4. **Time for B to Fill Remaining Volume:**
   $$\text{Time} = \frac{20}{2} = 10 \text{ minutes}$$
5. **Total Time:**
   $$\text{Total Time} = 8 \text{ min (both)} + 10 \text{ min (B alone)} = 18 \text{ minutes}$$
   Since 18 minutes is not in (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
Let total time be $T$. Pipe B was open for all $T$ minutes; Pipe A for 8 minutes.
$$3(8) + 2(T) = 60 \implies 24 + 2T = 60 \implies 2T = 36 \implies T = 18 \text{ minutes}$$

---

### Q26. Three Pipes Combined Flow
**Question:**  
Two pipes can fill a tank in 10 hours and 12 hours respectively while a third pipe empties the full tank in 20 hours. If all the three pipes operate together, in how much time will the tank be filled?  
- a) 7 hrs  
- b) 8 hrs  
- c) 7.5 hrs  
- d) None of these  

**Correct Answer:** Option c) 7.5 hrs (7 hours 30 minutes)

**Step-by-Step Solution:**
1. **LCM Method:**
   - Tank capacity $= \text{LCM}(10, 12, 20) = 60$ units.
   - Rate of Pipe 1 $= +\frac{60}{10} = +6$ units/hr.
   - Rate of Pipe 2 $= +\frac{60}{12} = +5$ units/hr.
   - Rate of Pipe 3 (emptying) $= -\frac{60}{20} = -3$ units/hr.
2. **Net Flow Rate:**
   $$\text{Net Rate} = 6 + 5 - 3 = 8 \text{ units/hr}$$
3. **Time to Fill:**
   $$\text{Time} = \frac{60}{8} = 7.5 \text{ hours } (7 \text{ hrs } 30 \text{ min})$$

**Shortcut / Exam Tip:**
$$\text{Rate} = \frac{1}{10} + \frac{1}{12} - \frac{1}{20} = \frac{6 + 5 - 3}{60} = \frac{8}{60} = \frac{2}{15} \implies \text{Time} = \frac{15}{2} = 7.5 \text{ hours}$$

---

### Q27. Delayed Outlet Opening & Emptying
**Question:**  
Two pipes A and B can fill a cistern in 12 minutes and 15 minutes respectively, but a third pipe C can empty the full tank in 6 minutes. A and B are kept open for 5 minutes and then C is also opened. In what time is the cistern emptied?  
- a) 30 minutes  
- b) 40 minutes  
- c) 45 minutes  
- d) None of these  

**Correct Answer:** Option c) 45 minutes

**Step-by-Step Solution:**
1. **LCM Method:**
   - Tank capacity $= \text{LCM}(12, 15, 6) = 60$ units.
   - Rate of $A = +\frac{60}{12} = +5$ units/min.
   - Rate of $B = +\frac{60}{15} = +4$ units/min.
   - Rate of $C = -\frac{60}{6} = -10$ units/min.
2. **Initial 5 Minutes (Filling Stage):**
   - In 5 minutes, A and B fill:
     $$\text{Volume Filled} = 5 \times (5 + 4) = 5 \times 9 = 45 \text{ units}$$
3. **Net Rate when C is Opened:**
   $$\text{Net Rate} = 5 + 4 - 10 = -1 \text{ unit/min (net emptying)}$$
4. **Time to Empty the 45 Units:**
   $$\text{Time to Empty} = \frac{45 \text{ units}}{1 \text{ unit/min}} = 45 \text{ minutes}$$

**Shortcut / Exam Tip:**
Remember: When emptying a partially filled cistern, only empty the **water already filled** (45 units), NOT the total capacity (60 units)!  
Time $= \frac{45}{1} = 45$ minutes.

---

### Q28. Finding Capacity from Discharge Rate
**Question:**  
Pipe A can fill a tank in 15 hours and Pipe B can fill it in 20 hours. A third pipe, C, empties water at a rate of 50 liters per hour. When all three pipes are opened, the tank is filled in exactly 10 hours. What is the total capacity of the tank in liters?  
- a) 3000 L  
- b) 6000 L  
- c) 4500 L  
- d) None of these  

**Correct Answer:** Option a) 3000 L

**Step-by-Step Solution:**
1. **Formulate 1-Hour Work Equations:**
   - Let total capacity of the tank be $C$ liters.
   - Pipe A filling rate $= \frac{C}{15}$ L/hr.
   - Pipe B filling rate $= \frac{C}{20}$ L/hr.
   - Pipe C emptying rate $= 50$ L/hr.
   - Combined rate when filled in 10 hours $= \frac{C}{10}$ L/hr.
2. **Set Up the Balance Equation:**
   $$\frac{C}{15} + \frac{C}{20} - 50 = \frac{C}{10}$$
   $$\frac{C}{15} + \frac{C}{20} - \frac{C}{10} = 50$$
3. **Solve for Capacity $C$:**
   - $\text{LCM}(15, 20, 10) = 60$.
   $$\frac{4C + 3C - 6C}{60} = 50$$
   $$\frac{C}{60} = 50 \implies C = 3000 \text{ liters}$$

**Shortcut / Exam Tip:**
Pipe C's fraction of capacity per hour $= \left(\frac{1}{15} + \frac{1}{20}\right) - \frac{1}{10} = \frac{7}{60} - \frac{6}{60} = \frac{1}{60}$.  
Since $\frac{1}{60}$ of capacity is 50 liters/hr:
$$\text{Capacity} = 50 \times 60 = 3000 \text{ liters}$$

---

### Q29. Tank Leak with Continuous Inflow
**Question:**  
A leak in the bottom of a tank can empty it in 8 hours. A tap is turned on which admits 6 liters of water per minute into the tank. With both open, the tank is emptied in 12 hours. What is the capacity of the tank?  
- a) 5760L  
- b) 6400L  
- c) 7200L  
- d) None of these  

**Correct Answer:** Option d) None of these (8640 L)  
*(Note: If the inflow had been 4 liters per minute, the capacity would be $4 \times 60 \times 24 = 5760\text{ L}$, which corresponds to option a. Under the verbatim question text of 6 L/min, the exact value is 8640 L).*

**Step-by-Step Solution:**
1. **Convert Inflow Rate to Hours:**
   $$\text{Tap Inflow} = 6 \text{ liters/minute} = 6 \times 60 = 360 \text{ liters/hour}$$
2. **Formulate Emptying Rate Balance:**
   - Let tank capacity be $C$ liters.
   - Leak alone empties tank at: $\frac{C}{8}$ liters/hour.
   - Combined system empties tank at: $\frac{C}{12}$ liters/hour.
3. **Balance Equation:**
   $$\text{Net Emptying Rate} = \text{Leak Rate} - \text{Inflow Rate}$$
   $$\frac{C}{12} = \frac{C}{8} - 360$$
   $$\frac{C}{8} - \frac{C}{12} = 360$$
4. **Solve for $C$:**
   $$\frac{3C - 2C}{24} = 360$$
   $$\frac{C}{24} = 360 \implies C = 24 \times 360 = 8640 \text{ liters}$$
   Since 8640 L is not among options (a), (b), or (c), the answer is **None of these**.

**Shortcut / Exam Tip:**
$$\text{Capacity} = \frac{\text{Inflow rate (in L/hr)} \times T_1 \times T_2}{T_2 - T_1} = \frac{360 \times 8 \times 12}{12 - 8} = \frac{360 \times 96}{4} = 360 \times 24 = 8640 \text{ L}$$

---

### Q30. Multiple Similar Taps Opened Mid-way
**Question:**  
A tap can fill a tank in 6 hours. After half the tank is filled, three more similar taps are opened. What is the total time taken to fill the tank completely?  
- a) 3 hours and 30 minutes  
- b) 3 hours and 40 minutes  
- c) 3 hours and 45 minutes  
- d) None of these  

**Correct Answer:** Option c) 3 hours and 45 minutes

**Step-by-Step Solution:**
1. **First Half of the Tank:**
   - 1 tap fills the entire tank in 6 hours.
   - Time taken to fill the first $\frac{1}{2}$ of the tank:
     $$T_1 = \frac{6}{2} = 3 \text{ hours}$$
2. **Second Half of the Tank:**
   - Remaining volume $= \frac{1}{2}$ of the tank.
   - Three more similar taps are opened $\implies$ total active taps $= 1 + 3 = 4$ identical taps.
   - 4 identical taps fill the full tank in $\frac{6}{4} = 1.5$ hours.
   - Time to fill the remaining half tank with 4 taps:
     $$T_2 = \frac{1.5}{2} = 0.75 \text{ hours} = 0.75 \times 60 = 45 \text{ minutes}$$
3. **Total Time:**
   $$\text{Total Time} = 3 \text{ hours} + 45 \text{ minutes} = 3 \text{ hours and } 45 \text{ minutes}$$

**Shortcut / Exam Tip:**
$$T_{\text{total}} = \left(\frac{1}{2} \times 6\right) + \left(\frac{1/2}{4/6}\right) = 3 + \frac{3}{4} \text{ hrs} = 3 \text{ hrs } 45 \text{ min}$$

---

## 3. Tricks, Tips & Exam Shortcuts

### 3.1 High-Yield Shortcut Formulas

| Scenario | Given Variables | Shortcut Formula |
| :--- | :--- | :--- |
| **Two Workers Together** | $T_A, T_B$ | $T = \frac{T_A \cdot T_B}{T_A + T_B}$ |
| **Three Workers Together** | $T_A, T_B, T_C$ | $T = \frac{T_A \cdot T_B \cdot T_C}{T_A T_B + T_B T_C + T_C T_A}$ |
| **A is $n$ times as efficient as B and takes $d$ days less** | $n, d$ | $T_A = \frac{d}{n - 1}, \quad T_B = \frac{n \cdot d}{n - 1}, \quad T_{\text{together}} = \frac{n \cdot d}{n^2 - 1}$ |
| **"Or" vs "And" Formula** | $M_1$ or $W_1$ or $B_1$ in $D$ days; find $M_2$ and $W_2$ and $B_2$ | $D_{\text{req}} = \frac{D}{\frac{M_2}{M_1} + \frac{W_2}{W_1} + \frac{B_2}{B_1}}$ |
| **Worker leaves $x$ days before completion** | Total work $W$, rates $R_A, R_B$ | $T_{\text{total}} = \frac{W + x \cdot R_A}{R_A + R_B}$ |
| **Tank capacity with leak & tap** | Leak time $T_1$, combined emptying time $T_2$, inflow rate $R$ | $\text{Capacity} = \frac{R \times T_1 \times T_2}{T_2 - T_1}$ |

---

### 3.2 Key Traps and How to Avoid Them

1. **The "Days vs Additional Days" Distinction:**
   - Always read the exact wording: *"How many days did the work last?"* requires the **total duration** ($T_1 + T_2$).
   - *"How many more days will B take?"* requires only the **remaining duration** ($T_2$).
2. **The "Leaving Before Completion" Trap:**
   - When a worker leaves $x$ days *before completion*, DO NOT subtract from total work. Add their hypothetical contribution to total work as if they never left, then divide by combined efficiency.
3. **The Alternate Days Cycle Trap:**
   - Never divide total work by the average rate directly. Work comes in discrete pulses.
   - Always group work by **complete cycles**, compute remainder, and step through the remaining days person by person.
4. **Wages Distribution Misconceptions:**
   - Wages are **never** distributed by time spent unless efficiencies are equal.
   - Wages are **never** distributed by efficiency alone unless everyone worked for the exact same number of days.
   - **Always calculate:** $\text{Share} = \frac{\text{Units of work done by worker}}{\text{Total units of work}}$.
5. **Cistern Emptying vs Filling Confusion:**
   - If an outlet pipe is opened after the tank is partially filled, calculate the time required to empty **only the accumulated water**, not the total tank capacity.
