# 02. Pipes and Cisterns

A comprehensive reference for competitive examinations, campus placement aptitude tests, and quantitative problem-solving on Pipes and Cisterns.

---

## 1. Theory and Fundamental Formulas

Pipes and Cisterns problems are practical applications of the **Time and Work** framework. The cistern or storage tank represents the total quantum of work ($W = 1$ full tank or an assumed integer capacity in LCM units). The principal distinction is the inclusion of **negative work**, introduced by draining conduits or structural leaks.

### 1.1 Inlets, Outlets, and Flow Rates
1. **Inlet Pipe:** A conduit directing fluid into the cistern.
   - Performs **positive work** ($+$).
   - If an inlet fills an empty tank completely in $T_{\text{in}}$ hours, its hourly filling rate is:
     $$\text{Rate}_{\text{in}} = +\frac{1}{T_{\text{in}}} \text{ tank/hour}$$
2. **Outlet Pipe (Waste Pipe / Leak):** A conduit or defect draining fluid out of the cistern.
   - Performs **negative work** ($-$).
   - If an outlet empties a full tank completely in $T_{\text{out}}$ hours, its hourly draining rate is:
     $$\text{Rate}_{\text{out}} = -\frac{1}{T_{\text{out}}} \text{ tank/hour}$$

---

### 1.2 The Net Flow Rate and Resulting States
When multiple inlets and outlets operate simultaneously:
$$\text{Net Rate} = \sum \text{Inlet Rates} - \sum \text{Outlet Rates}$$

- **Net Filling ($\text{Net Rate} > 0$):** An empty cistern will fill.
  $$\text{Time to fill empty tank} = \frac{1}{\text{Net Rate}}$$
- **Net Emptying ($\text{Net Rate} < 0$):** A full cistern will drain.
  $$\text{Time to empty full tank} = \frac{1}{|\text{Net Rate}|}$$
- **Equilibrium ($\text{Net Rate} = 0$):** Fluid level remains static.

---

### 1.3 The Total Capacity (LCM Units) Method
Instead of working with cumbersome fractions, assume the capacity of the tank is the **Least Common Multiple (LCM)** of all individual operational times:
1. **Assume Tank Capacity:** $V = \text{LCM}(t_1, t_2, \dots, t_n)$ units.
2. **Individual Rate / Efficiency:**
   $$\text{Efficiency}_i = \frac{V}{t_i} \text{ units/hour (or units/min)}$$
   - Assign positive values ($+$) to inlets.
   - Assign negative values ($-$) to outlets/leaks.
3. **Net Rate:** Sum the individual rates algebraically.
4. **Time Required:**
   $$\text{Time} = \frac{\text{Target Volume to be Filled/Emptied}}{\text{Net Rate}}$$

---

### 1.4 Flow Dynamics and Pipe Geometry (Scaling Law)
Under constant fluid velocity, discharge volume rate ($Q$) is directly proportional to the cross-sectional area of the conduit:
$$Q \propto A = \pi \left(\frac{d}{2}\right)^2 \propto d^2$$

- If the inner diameter is scaled by a factor $k$ ($d \to k \cdot d$), the flow rate scales by $k^2$.
- Consequently, the time required to complete the same volume scales inversely by $k^2$:
  $$T_2 = \frac{T_1}{k^2}$$

---

### 1.5 Alternating Operations and the Threshold Boundary Rule
When an inlet and an outlet operate in alternating sequence (e.g., 1 minute each):
1. **Two-Step Cycle Progress:** Net fill per cycle = $\text{Rate}_{\text{in}} - \text{Rate}_{\text{out}}$.
2. **The Threshold Rule:** A tank is filled the moment water reaches full capacity. Draining does not occur once full.
   - Subtract the peak single-cycle inlet volume from total capacity:
     $$V_{\text{threshold}} = V_{\text{total}} - \text{Rate}_{\text{in}}$$
   - Determine complete cycles required to reach or exceed $V_{\text{threshold}}$.
   - Allocate the final fractional or whole step exclusively to the inlet pipe.

---

### 1.6 Chemical and Multi-Liquid Inflow Proportions
If pipes discharging distinct chemical solutions run concurrently into an initially empty cistern:
- The ratio of liquid volumes delivered over any time interval equals the ratio of their respective flow rates:
  $$\text{Fraction of Solution } k = \frac{\text{Rate}_k}{\sum \text{Rates of all running inlets}}$$
- The proportion is independent of the elapsed time.

---

## 2. Master Formula Reference Table

| Operational Scenario | Governing Formula | Key Variables |
| :--- | :--- | :--- |
| **Two Inlets Concurrent** | $T = \frac{x \cdot y}{x + y}$ | $x, y$: Filling times of pipes |
| **One Inlet + One Outlet** | $T_{\text{fill}} = \frac{x \cdot y}{y - x}$ | $x$: Inflow time, $y$: Outflow time ($y > x$) |
| **Leak Emptying Time** | $T_{\text{leak}} = \frac{T_{\text{normal}} \cdot T_{\text{with leak}}}{T_{\text{with leak}} - T_{\text{normal}}}$ | $T_{\text{normal}}$: Fill time alone, $T_{\text{with leak}}$: Fill time with leak |
| **Conduit Diameter Scaling** | $T_2 = T_1 \times \left(\frac{d_1}{d_2}\right)^2$ | $d_1, d_2$: Inner diameters; $T_1, T_2$: Completion times |
| **Tank Volume from Leak & Inflow** | $\text{Capacity} = T_{\text{inlet alone (min)}} \times \text{Rate (L/min)}$ | Rate of inlet derived from net drainage rate difference |
| **Replication of Identical Taps** | $T_{\text{rem}} = \frac{T_{\text{single}}}{N} \times V_{\text{rem}}$ | $N$: Total number of active identical taps |

---

## 3. Practice Questions and Detailed Solutions
### Q1
**Question:**
Pipe A fills a tank in 20 hours and Pipe B fills it in 30 hours. How long will they take together to fill the tank?

**Options:**
- A) 12 hrs
- B) 15 hrs
- C) 18 hrs
- D) 11 hrs

**Correct Answer:** A) 12 hrs

**Detailed Mathematical Explanation:**
- **Method 1: LCM Capacity Method**
  - Let total capacity of the tank = $\text{LCM}(20, 30) = 60$ units.
  - Rate of Pipe A = $\frac{60}{20} = +3$ units/hour.
  - Rate of Pipe B = $\frac{60}{30} = +2$ units/hour.
  - Combined rate of (A + B) = $3 + 2 = 5$ units/hour.
  - Time taken together = $\frac{\text{Total Capacity}}{\text{Combined Rate}} = \frac{60}{5} = 12$ hours.
- **Method 2: Fractional Rate Method**
  - $\frac{1}{T} = \frac{1}{20} + \frac{1}{30} = \frac{3 + 2}{60} = \frac{5}{60} = \frac{1}{12} \implies T = 12$ hours.

**Shortcut / Exam Trick:**
$$T = \frac{x \cdot y}{x + y} = \frac{20 \times 30}{20 + 30} = \frac{600}{50} = 12\text{ hours}$$

---

### Q2
**Question:**
Pipes A and B can fill a tank in 5 and 6 hours respectively. Pipe C can empty it in 12 hours. If all the three pipes are opened together, then the tank will be filled in how many hours?

**Options:**
- A) $1\frac{13}{17}$ hours
- B) $2\frac{8}{11}$ hours
- C) $3\frac{9}{17}$ hours
- D) $4\frac{1}{2}$ hours

**Correct Answer:** C) $3\frac{9}{17}$ hours

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(5, 6, 12) = 60$ units.
- Rate of Pipe A (Inlet) = $\frac{60}{5} = +12$ units/hour.
- Rate of Pipe B (Inlet) = $\frac{60}{6} = +10$ units/hour.
- Rate of Pipe C (Outlet) = $-\frac{60}{12} = -5$ units/hour.
- Net Rate = $\text{Rate}_A + \text{Rate}_B - \text{Rate}_C = 12 + 10 - 5 = +17$ units/hour.
- Time required = $\frac{\text{Capacity}}{\text{Net Rate}} = \frac{60}{17} = 3\frac{9}{17}$ hours.

**Shortcut / Exam Trick:**
$$\text{Net Rate} = \frac{1}{5} + \frac{1}{6} - \frac{1}{12} = \frac{12 + 10 - 5}{60} = \frac{17}{60} \implies T = \frac{60}{17} = 3\frac{9}{17}\text{ hours}$$

---

### Q3
**Question:**
A tank is filled by a pipe in 5 hours. After 2 hours, what fraction of the tank is filled?

**Options:**
- A) $1/5$
- B) $3/4$
- C) $3/5$
- D) $2/5$

**Correct Answer:** D) $2/5$

**Detailed Mathematical Explanation:**
- In 1 hour, the pipe fills $\frac{1}{5}$ of the tank.
- In 2 hours, the fraction filled = $2 \times \frac{1}{5} = \frac{2}{5}$ of the tank.

**Shortcut / Exam Trick:**
$$\text{Fraction filled} = \frac{\text{Elapsed Time}}{\text{Total Time required}} = \frac{2}{5}$$

---

### Q4
**Question:**
Three pipes A, B and C can fill a tank from empty to full in 30 minutes, 20 minutes, and 10 minutes respectively. When the tank is empty, all the three pipes are opened. A, B and C discharge chemical solutions P, Q and R respectively. What is the proportion of the solution R in the liquid in the tank after 3 minutes?

**Options:**
- A) $5/12$
- B) $2/15$
- C) $7/18$
- D) $6/11$

**Correct Answer:** D) $6/11$

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(30, 20, 10) = 60$ units.
- Inflow rate of A (Solution P) = $\frac{60}{30} = 2$ units/min.
- Inflow rate of B (Solution Q) = $\frac{60}{20} = 3$ units/min.
- Inflow rate of C (Solution R) = $\frac{60}{10} = 6$ units/min.
- Total influx rate into tank = $2 + 3 + 6 = 11$ units/min.
- Volume of Solution R delivered in 3 minutes = $6 \times 3 = 18$ units.
- Total liquid delivered in 3 minutes = $11 \times 3 = 33$ units.
- Proportion of Solution R = $\frac{18}{33} = \frac{6}{11}$.

**Shortcut / Exam Trick:**
The proportion of any component discharged continuously into an empty tank depends exclusively on the ratio of rates (time cancels out):
$$\text{Proportion of R} = \frac{\text{Rate}_C}{\text{Rate}_A + \text{Rate}_B + \text{Rate}_C} = \frac{\frac{1}{10}}{\frac{1}{30} + \frac{1}{20} + \frac{1}{10}} = \frac{6}{2 + 3 + 6} = \frac{6}{11}$$

---

### Q5
**Question:**
Pipe A fills a tank in 10 hours and pipe B fills it in 15 hours, Pipe C empties it in 30 hours. All are opened together and after 3 hours, pipe C is closed. How much more time is needed?

**Options:**
- A) 3 hr 36 min
- B) 4 hr 35 min
- C) 6 hr 40 min
- D) 7 hr 15 min

**Correct Answer:** A) 3 hr 36 min

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(10, 15, 30) = 30$ units.
- Rate of A = $\frac{30}{10} = +3$ units/hour.
- Rate of B = $\frac{30}{15} = +2$ units/hour.
- Rate of C = $-\frac{30}{30} = -1$ unit/hour.
- Combined initial rate of (A + B - C) = $3 + 2 - 1 = +4$ units/hour.
- In the first 3 hours:
  $$\text{Volume filled} = 3 \text{ hours} \times 4 \text{ units/hour} = 12 \text{ units}$$
- Remaining volume = $30 - 12 = 18$ units.
- After 3 hours, Pipe C is closed. Only A and B continue running:
  $$\text{New combined rate (A + B)} = 3 + 2 = 5 \text{ units/hour}$$
- Additional time required:
  $$t_{\text{additional}} = \frac{18}{5} = 3.6 \text{ hours} = 3 \text{ hours} + (0.6 \times 60) \text{ minutes} = 3 \text{ hr } 36 \text{ min}$$

**Shortcut / Exam Trick:**
$$\text{Work done in 3h} = 3 \left(\frac{1}{10} + \frac{1}{15} - \frac{1}{30}\right) = 3 \left(\frac{4}{30}\right) = \frac{2}{5}$$
$$\text{Work remaining} = 1 - \frac{2}{5} = \frac{3}{5}$$
$$t = \frac{3/5}{1/10 + 1/15} = \frac{3/5}{5/30} = \frac{3/5}{1/6} = \frac{18}{5} = 3.6\text{ h} = 3\text{ hr } 36\text{ min}$$

---

### Q6
**Question:**
How long will it take to empty the tank if both the inlet pipe A and the outlet pipe B are opened simultaneously?
- Statement I: A can fill the tank in 16 minutes.
- Statement II: B can empty the full tank in 8 minutes.

**Options:**
- A) I alone sufficient while II alone not sufficient to answer
- B) II alone sufficient while I alone not sufficient to answer
- C) Either I or II alone sufficient to answer
- D) Both I and II are not sufficient to answer
- E) Both I and II are necessary to answer

**Correct Answer:** E) Both I and II are necessary to answer

**Detailed Mathematical Explanation:**
- To find the time taken to empty the tank, we must determine the net emptying rate:
  $$\text{Net Emptying Rate} = \text{Rate of Outlet B} - \text{Rate of Inlet A}$$
- Using Statement I alone: Gives only the inlet rate of A ($\frac{1}{16}$ tank/min). The outlet rate is unknown. Hence, insufficient.
- Using Statement II alone: Gives only the outlet rate of B ($\frac{1}{8}$ tank/min). The inlet rate is unknown. Hence, insufficient.
- Combining Statements I and II:
  $$\text{Net Emptying Rate} = \frac{1}{8} - \frac{1}{16} = \frac{1}{16} \text{ tank/min}$$
  $$\text{Time to empty} = \frac{1}{1/16} = 16 \text{ minutes}$$
- Since both statements are indispensable to deduce the answer, **Both I and II are necessary to answer**.

---

### Q7
**Question:**
Three pipes A, B and C can fill a tank in 6 hours. After three pipes worked for 2 hours, C is closed. Then A and B filled the remaining part in 7 hours. Calculate the number of hours taken by C alone to fill the tank.

**Options:**
- A) 16 hours
- B) 12 hours
- C) 13 hours
- D) 14 hours

**Correct Answer:** D) 14 hours

**Detailed Mathematical Explanation:**
- Let total capacity = 42 units (or work = $1$).
- Work done by (A + B + C) in 2 hours:
  $$\text{Work done} = 2 \times \frac{1}{6} = \frac{1}{3}$$
- Remaining work = $1 - \frac{1}{3} = \frac{2}{3}$.
- This remaining $\frac{2}{3}$ is completed by (A + B) in 7 hours:
  $$\text{Rate of (A + B)} = \frac{2/3}{7} = \frac{2}{21} \text{ tank/hour}$$
- Now, isolate the rate of C alone:
  $$\text{Rate of C} = \text{Rate of (A + B + C)} - \text{Rate of (A + B)} = \frac{1}{6} - \frac{2}{21}$$
- Taking LCM of 6 and 21 (which is 42):
  $$\text{Rate of C} = \frac{7 - 4}{42} = \frac{3}{42} = \frac{1}{14} \text{ tank/hour}$$
- Time taken by C alone = $\frac{1}{1/14} = 14$ hours.

**Shortcut / Exam Trick:**
$$\text{Fraction left} = \frac{6 - 2}{6} = \frac{2}{3}$$
$$\text{A + B takes } \frac{7}{2/3} = 10.5\text{ h to fill completely}$$
$$T_C = \frac{T_{A+B+C} \times T_{A+B}}{T_{A+B} - T_{A+B+C}} = \frac{6 \times 10.5}{10.5 - 6} = \frac{63}{4.5} = 14\text{ hours}$$

---

### Q8
**Question:**
A pump can fill a tank with water in 2 hours. Because of a leak, it took $2\frac{1}{3}$ hours to fill the tank. The leak can drain all the water of the tank in how many hours?

**Options:**
- A) $4\frac{1}{3}$ hours
- B) 7 hours
- C) $8\frac{2}{3}$ hours
- D) 14 hours

**Correct Answer:** D) 14 hours

**Detailed Mathematical Explanation:**
- Rate of pump without leak = $\frac{1}{2}$ tank/hour.
- Time taken with leak = $2\frac{1}{3} = \frac{7}{3}$ hours.
- Net filling rate with leak = $\frac{1}{7/3} = \frac{3}{7}$ tank/hour.
- Rate of the leak:
  $$\text{Rate}_{\text{leak}} = \text{Rate}_{\text{pump}} - \text{Net Rate} = \frac{1}{2} - \frac{3}{7} = \frac{7 - 6}{14} = \frac{1}{14} \text{ tank/hour}$$
- Time taken by the leak to drain the full tank = $\frac{1}{1/14} = 14$ hours.

**Shortcut / Exam Trick:**
$$T_{\text{leak}} = \frac{x \cdot y}{y - x} = \frac{2 \times \frac{7}{3}}{\frac{7}{3} - 2} = \frac{14/3}{1/3} = 14\text{ hours}$$

---

### Q9
**Question:**
Two pipes A and B can fill a cistern in 75 minutes and 45 minutes respectively. The cistern will be filled in just 30 minutes, if the pipe B is turned off after how many minutes?

**Options:**
- A) 5 min
- B) 9 min
- C) 10 min
- D) 27 min

**Correct Answer:** D) 27 min

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(75, 45) = 225$ units.
- Rate of Pipe A = $\frac{225}{75} = 3$ units/min.
- Rate of Pipe B = $\frac{225}{45} = 5$ units/min.
- Pipe A operates continuously for the full 30 minutes:
  $$\text{Work done by Pipe A} = 30 \text{ min} \times 3 \text{ units/min} = 90 \text{ units}$$
- Remaining volume to be filled by Pipe B:
  $$\text{Remaining units} = 225 - 90 = 135 \text{ units}$$
- Operating time of Pipe B:
  $$t_B = \frac{135}{5} = 27 \text{ minutes}$$
- Therefore, Pipe B must be closed after **27 minutes**.

**Shortcut / Exam Trick:**
$$1 - \frac{30}{75} = 1 - \frac{2}{5} = \frac{3}{5} \implies t_B = \frac{3}{5} \times 45 = 27\text{ minutes}$$

---

### Q10
**Question:**
A large tanker can be filled by two pipes A and B in 60 minutes and 40 minutes respectively. How many minutes will it take to fill the tanker from empty state if pipe B is used for half the time and pipes A and B fill it together for the other half?

**Options:**
- A) 15 min
- B) 20 min
- C) 27.5 min
- D) 30 min

**Correct Answer:** D) 30 min

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(60, 40) = 120$ units.
- Rate of Pipe A = $\frac{120}{60} = 2$ units/min.
- Rate of Pipe B = $\frac{120}{40} = 3$ units/min.
- Combined rate of (A + B) = $2 + 3 = 5$ units/min.
- Let the total operational duration be $T$ minutes.
  - Phase 1 (First half of time = $T/2$ min): Only Pipe B operates $\implies \text{Work} = 3 \times \frac{T}{2}$.
  - Phase 2 (Second half of time = $T/2$ min): Both A and B operate $\implies \text{Work} = 5 \times \frac{T}{2}$.
- Total work done:
  $$3 \left(\frac{T}{2}\right) + 5 \left(\frac{T}{2}\right) = 120$$
  $$8 \left(\frac{T}{2}\right) = 120 \implies 4T = 120 \implies T = 30 \text{ minutes}$$

**Shortcut / Exam Trick:**
Average effective rate across time $T$:
$$\text{Effective Rate} = \frac{\text{Rate}_B + (\text{Rate}_A + \text{Rate}_B)}{2} = \frac{3 + 5}{2} = 4\text{ units/min}$$
$$T = \frac{120}{4} = 30\text{ minutes}$$
---

### Q11
**Question:**
A cistern has two pipes. One can fill it with water in 8 hours and other can empty it in 5 hours. In how many hours will the cistern be emptied if both the pipes are opened together, when $\frac{3}{4}$ of the cistern is already full of water?

**Options:**
- A) 10 hours
- B) 6 hours
- C) $3\frac{1}{3}$ hours
- D) $13\frac{1}{3}$ hours

**Correct Answer:** A) 10 hours

**Detailed Mathematical Explanation:**
- Filling rate of Inlet = $+\frac{1}{8}$ tank/hour.
- Emptying rate of Outlet = $-\frac{1}{5}$ tank/hour.
- Since Outlet rate ($1/5 = 0.20$) > Inlet rate ($1/8 = 0.125$), the tank experiences net drainage:
  $$\text{Net Emptying Rate} = \frac{1}{5} - \frac{1}{8} = \frac{8 - 5}{40} = \frac{3}{40} \text{ tank/hour}$$
- Initial volume present in the cistern = $\frac{3}{4}$ of the full capacity.
- Time required to empty the present volume:
  $$\text{Time} = \frac{\text{Volume Present}}{\text{Net Emptying Rate}} = \frac{3/4}{3/40} = \frac{3}{4} \times \frac{40}{3} = 10 \text{ hours}$$

**Shortcut / Exam Trick:**
$$T = \frac{3/4}{\frac{1}{5} - \frac{1}{8}} = \frac{3/4}{3/40} = 10\text{ hours}$$

---

### Q12
**Question:**
Two Pipes A and B can fill a tank in $1\frac{1}{2}$ hours and $4\frac{1}{2}$ hours respectively. In what time both together can fill the tank?

**Options:**
- A) $1\frac{1}{8}$ hours
- B) $2\frac{1}{4}$ hours
- C) $1\frac{1}{4}$ hours
- D) None of these

**Correct Answer:** A) $1\frac{1}{8}$ hours

**Detailed Mathematical Explanation:**
- Convert times into improper fractions:
  - $T_A = 1\frac{1}{2} = \frac{3}{2}$ hours $\implies \text{Rate}_A = \frac{2}{3}$ tank/hour.
  - $T_B = 4\frac{1}{2} = \frac{9}{2}$ hours $\implies \text{Rate}_B = \frac{2}{9}$ tank/hour.
- Combined rate:
  $$\text{Rate}_{A+B} = \frac{2}{3} + \frac{2}{9} = \frac{6 + 2}{9} = \frac{8}{9} \text{ tank/hour}$$
- Time taken together:
  $$T = \frac{1}{8/9} = \frac{9}{8} = 1\frac{1}{8} \text{ hours}$$

**Shortcut / Exam Trick:**
$$T = \frac{x \cdot y}{x + y} = \frac{\frac{3}{2} \times \frac{9}{2}}{\frac{3}{2} + \frac{9}{2}} = \frac{\frac{27}{4}}{6} = \frac{27}{24} = \frac{9}{8} = 1\frac{1}{8}\text{ hours}$$

---

### Q13
**Question:**
A tap can fill a tank in 6 hours. After half of the tank is filled, three more similar taps are opened. What is the total time taken to fill the tank completely?

**Options:**
- A) 3 hr 15 min
- B) 3 hr 45 min
- C) 4 hr 10 min
- D) 4 hr 15 min

**Correct Answer:** B) 3 hr 45 min

**Detailed Mathematical Explanation:**
- **Phase 1 (First half of the tank):**
  - 1 tap fills the entire tank in 6 hours.
  - Time taken to fill half ($\frac{1}{2}$) of the tank = $\frac{6}{2} = 3$ hours.
- **Phase 2 (Second half of the tank):**
  - 3 more identical taps are opened $\implies$ Total active taps = $1 + 3 = 4$ identical taps.
  - Rate of 1 tap = $\frac{1}{6}$ tank/hour.
  - Combined rate of 4 taps = $4 \times \frac{1}{6} = \frac{2}{3}$ tank/hour.
  - Volume remaining to fill = $\frac{1}{2}$ tank.
  - Time taken for Phase 2:
    $$t_2 = \frac{1/2}{2/3} = \frac{1}{2} \times \frac{3}{2} = \frac{3}{4} \text{ hour} = 45 \text{ minutes}$$
- **Total Time Taken:**
  $$T_{\text{total}} = 3 \text{ hours} + 45 \text{ minutes} = 3 \text{ hr } 45 \text{ min}$$

**Shortcut / Exam Trick:**
$$T_{\text{total}} = 3\text{ h} + \frac{3\text{ h}}{4} = 3\text{ h } 45\text{ min}$$

---

### Q14
**Question:**
A tank is fitted with two taps A and B. A can fill the tank completely in 45 minutes and B can empty the full tank in 1 hour. If both the taps are opened alternately for 1 minute each, how long will it take to fill the empty tank?

**Options:**
- A) 2 hours 55 minutes
- B) 5 hours 53 minutes
- C) 3 hours 40 minutes
- D) 4 hours 48 minutes

**Correct Answer:** B) 5 hours 53 minutes

**Detailed Mathematical Explanation:**
- Convert units: 1 hour = 60 minutes.
- Capacity of the tank = $\text{LCM}(45, 60) = 180$ units.
- Rate of Tap A (Inlet) = $\frac{180}{45} = +4$ units/min.
- Rate of Tap B (Outlet) = $-\frac{180}{60} = -3$ units/min.
- **Alternating 2-minute cycle:**
  - Minute 1 (A opens): $+4$ units.
  - Minute 2 (B opens): $-3$ units.
  - Net work per 2-minute cycle = $4 - 3 = +1$ unit.
- **Applying the Threshold Rule:**
  - The tank becomes full on an inlet turn. Once full, the outlet will not operate.
  - Subtract Tap A's peak surge: $180 - 4 = 176$ units.
  - Number of complete 2-minute cycles to reach 176 units:
    $$176 \text{ cycles} \times 2 \text{ min/cycle} = 352 \text{ minutes}$$
  - At minute 352, the tank contains exactly 176 units.
  - At minute 353 (A's turn): Tap A adds 4 units $\implies 176 + 4 = 180$ units (Tank is full!).
- Total time taken = $353 \text{ minutes} = 5 \text{ hours } 53 \text{ minutes}$.

**Shortcut / Exam Trick:**
$$t_{\text{cycles}} = 2 \times (180 - 4) = 352\text{ min}$$
$$T = 352 + 1 = 353\text{ min} = 5\text{ h } 53\text{ min}$$

---

### Q15
**Question:**
Two pipes A and B can fill a cistern in 37 minutes and 45 minutes and both pipes are opened. The cistern will be filled in just half an hour, if the B is turned off after how many minutes (approx.)?

**Options:**
- A) 5 min
- B) 9 min
- C) 10 min
- D) 15 min

**Correct Answer:** B) 9 min

**Detailed Mathematical Explanation:**
- *Standard Aptitude Note:* In canonical competitive examination problems, Pipe A's filling duration is $37\frac{1}{2}$ minutes ($= \frac{75}{2}$ min), which yields an exact whole integer of 9 minutes. When the problem states $37$ minutes and appends *(approx.)*, both calculations are demonstrated below:
- **Case 1: Using canonical $37.5$ minutes ($75/2$ min):**
  - Total capacity = $\text{LCM}(75/2, 45) = 225$ units.
  - Rate of A = $\frac{225}{75/2} = 6$ units/min; Rate of B = $\frac{225}{45} = 5$ units/min.
  - Cistern fills in half an hour (30 min) $\implies$ Pipe A runs the full 30 minutes.
  - Volume filled by A = $30 \times 6 = 180$ units.
  - Remaining volume filled by B = $225 - 180 = 45$ units.
  - Duration for B = $\frac{45}{5} = 9$ minutes.
- **Case 2: Using literal given text (37 minutes):**
  - Work by A in 30 minutes = $\frac{30}{37} \approx 0.8108$.
  - Remaining work for B = $1 - 0.8108 = 0.1892$.
  - Duration for B = $0.1892 \times 45 = 8.514 \approx 9$ minutes.

**Shortcut / Exam Trick:**
$$t_B = \left(1 - \frac{30}{37.5}\right) \times 45 = \left(1 - \frac{4}{5}\right) \times 45 = \frac{1}{5} \times 45 = 9\text{ minutes}$$

---

### Q16
**Question:**
A leak in the bottom of a tank can empty it in 6 hours. A pipe fills water at 4 litres per minute. When the tank is full, the inlet is opened but due to the leak, the tank empties in 10 hours. What is the capacity of the tank?

**Options:**
- A) 3600 litres
- B) 4200 litres
- C) 5400 litres
- D) 6000 litres

**Correct Answer:** A) 3600 litres

**Detailed Mathematical Explanation:**
- Rate of leak alone (emptying) = $\frac{1}{6}$ tank/hour.
- Net emptying rate with inlet pipe opened = $\frac{1}{10}$ tank/hour.
- Since the tank empties:
  $$\text{Net Emptying Rate} = \text{Rate of Leak} - \text{Rate of Inlet}$$
  $$\text{Rate of Inlet} = \frac{1}{6} - \frac{1}{10} = \frac{5 - 3}{30} = \frac{2}{30} = \frac{1}{15} \text{ tank/hour}$$
- Time taken by the inlet pipe alone to fill the tank:
  $$T_{\text{inlet}} = 15 \text{ hours} = 15 \times 60 = 900 \text{ minutes}$$
- Given inflow rate = 4 litres/minute:
  $$\text{Capacity of the tank} = 900 \text{ minutes} \times 4 \text{ litres/minute} = 3600 \text{ litres}$$

**Shortcut / Exam Trick:**
$$T_{\text{inlet}} = \frac{6 \times 10}{10 - 6} = \frac{60}{4} = 15\text{ hours}$$
$$\text{Capacity} = 15 \times 60 \times 4 = 3600\text{ litres}$$

---

### Q17
**Question:**
One fill pipe A is 3 times faster than second fill pipe B and takes 32 minutes less than the fill pipe B to fill the tank. When will the tank be full if both pipes are opened together?

**Options:**
- A) 10 minutes
- B) 12 minutes
- C) 15 minutes
- D) 16 minutes

**Correct Answer:** B) 12 minutes

**Detailed Mathematical Explanation:**
- Efficiency ratio: $\text{Eff}_A : \text{Eff}_B = 3 : 1$.
- Since efficiency is inversely proportional to time:
  $$\text{Time}_A : \text{Time}_B = 1 : 3$$
- Let $T_A = x$ minutes and $T_B = 3x$ minutes.
- Difference in time taken:
  $$3x - x = 32 \implies 2x = 32 \implies x = 16 \text{ minutes}$$
  - $T_A = 16$ minutes
  - $T_B = 3 \times 16 = 48$ minutes
- Working together:
  $$T_{\text{together}} = \frac{T_A \cdot T_B}{T_A + T_B} = \frac{16 \times 48}{16 + 48} = \frac{768}{64} = 12 \text{ minutes}$$

**Shortcut / Exam Trick:**
When A is $n$ times faster and takes $D$ minutes less:
$$T_A = \frac{D}{n - 1} = \frac{32}{2} = 16\text{ min}$$
$$T_{\text{together}} = \frac{T_A \times n}{n + 1} = \frac{16 \times 3}{4} = 12\text{ minutes}$$

---

### Q18
**Question:**
Two pipes can fill a tank in 15 and 12 hours respectively and a third pipe can empty it in 4 hours. If the pipes are opened in order at 8 am, 9 am and 11 am respectively, the tank will be emptied at?

**Options:**
- A) 11:40 am
- B) 12:40 pm
- C) 1:40 pm
- D) 2:40 pm

**Correct Answer:** D) 2:40 pm

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(15, 12, 4) = 60$ units.
- Rate of Pipe 1 (Inlet) = $\frac{60}{15} = +4$ units/hour (opened at 8:00 am).
- Rate of Pipe 2 (Inlet) = $\frac{60}{12} = +5$ units/hour (opened at 9:00 am).
- Rate of Pipe 3 (Outlet) = $-\frac{60}{4} = -15$ units/hour (opened at 11:00 am).
- **Timeline Analysis up to 11:00 am:**
  - 8:00 am to 9:00 am (1 hr): Only Pipe 1 runs $\implies 1 \times 4 = 4$ units.
  - 9:00 am to 11:00 am (2 hrs): Pipes 1 and 2 run $\implies 2 \times (4 + 5) = 18$ units.
  - Total volume accumulated by 11:00 am = $4 + 18 = 22$ units.
- **After 11:00 am (All 3 pipes active):**
  $$\text{Net Rate} = +4 + 5 - 15 = -6 \text{ units/hour (Net drainage)}$$
- Time required to drain the 22 accumulated units:
  $$t = \frac{22}{6} = \frac{11}{3} \text{ hours} = 3 \text{ hours } 40 \text{ minutes}$$
- Emptying time:
  $$11:00 \text{ am} + 3 \text{ hours } 40 \text{ minutes} = 2:40 \text{ pm}$$

**Shortcut / Exam Trick:**
$$\text{Volume at 11 am} = (3 \times 4) + (2 \times 5) = 12 + 10 = 22\text{ units}$$
$$t_{\text{empty}} = \frac{22}{15 - 9} = \frac{22}{6}\text{ h} = 3\text{ h } 40\text{ min} \implies 11:00 + 3:40 = 2:40\text{ pm}$$

---

### Q19
**Question:**
Two pipes A and B can fill a tank in 12 and 15 hours respectively. An emptying pipe C can empty the tank in 20 hours. All pipes are opened at 7 am and after 3 hours pipe B is closed. At what time next day will the tank be full?

**Options:**
- A) 2:00 pm
- B) 1:00 pm
- C) 3:00 am
- D) 7:00 am

**Correct Answer:** D) 7:00 am

**Detailed Mathematical Explanation:**
- Let total capacity = $\text{LCM}(12, 15, 20) = 60$ units.
- Rate of A = $\frac{60}{12} = +5$ units/hour.
- Rate of B = $\frac{60}{15} = +4$ units/hour.
- Rate of C = $-\frac{60}{20} = -3$ units/hour.
- **Phase 1: 7:00 am to 10:00 am (3 hours, all open):**
  $$\text{Net Rate} = 5 + 4 - 3 = 6 \text{ units/hour}$$
  $$\text{Volume filled} = 3 \times 6 = 18 \text{ units}$$
- Remaining volume = $60 - 18 = 42$ units.
- **Phase 2: After 10:00 am (Pipe B is closed; only A and C run):**
  $$\text{New Net Rate} = \text{Rate}_A - \text{Rate}_C = 5 - 3 = +2 \text{ units/hour}$$
  $$\text{Time required} = \frac{42}{2} = 21 \text{ hours}$$
- **Determining Clock Time:**
  - $10:00 \text{ am (Day 1)} + 21 \text{ hours}$:
  - $10:00 \text{ am} + 14 \text{ hours} = 12:00 \text{ midnight}$.
  - $12:00 \text{ midnight} + 7 \text{ hours} = 7:00 \text{ am (Next day)}$.

**Shortcut / Exam Trick:**
$$V_{\text{rem}} = 60 - 3(5 + 4 - 3) = 42\text{ units}$$
$$t_{\text{rem}} = \frac{42}{5 - 3} = 21\text{ hours}$$
$$10:00\text{ am} + 21\text{ h} = 7:00\text{ am next day}$$

---

### Q20
**Question:**
A cistern has 12 pipes connected to it. Some are inlet pipes and the others are outlet pipes. Each inlet pipe can fill the cistern in 6 hours and each outlet pipe can empty it in 12 hours. If all the pipes are opened together, an empty cistern is filled in 4 hours. Find the number of inlet pipes.

**Options:**
- A) 4
- B) 5
- C) 6
- D) 7

**Correct Answer:** B) 5

**Detailed Mathematical Explanation:**
- Let the number of inlet pipes = $n$.
- Number of outlet pipes = $12 - n$.
- Rate of 1 inlet = $+\frac{1}{6}$ tank/hour.
- Rate of 1 outlet = $-\frac{1}{12}$ tank/hour.
- Combined net rate = $\frac{1}{4}$ tank/hour.
- Setting up the algebraic equation:
  $$n \left(\frac{1}{6}\right) - (12 - n) \left(\frac{1}{12}\right) = \frac{1}{4}$$
- Multiply the entire equation by 12:
  $$2n - (12 - n) = 3$$
  $$3n - 12 = 3 \implies 3n = 15 \implies n = 5$$
- Hence, the number of inlet pipes is **5** (and outlet pipes = $12 - 5 = 7$).

**Shortcut / Exam Trick (Alligation Method):**
- If all 12 were inlets: Net rate = $12 \times \frac{1}{6} = +2$ tanks/hour.
- If all 12 were outlets: Net rate = $12 \times \left(-\frac{1}{12}\right) = -1$ tank/hour.
- Target net rate = $+0.25$ tank/hour.
$$\frac{\text{Inlets}}{\text{Outlets}} = \frac{0.25 - (-1)}{2 - 0.25} = \frac{1.25}{1.75} = \frac{5}{7}$$
$$\text{Number of inlets} = \frac{5}{5 + 7} \times 12 = 5$$
---

### Q21
**Question:**
A swimming pool is filled by a pipe. The capacity of the pool is 2400 cubic metres. The emptying capacity of the pool is 10 cubic metres per minute higher than its filling capacity and the emptying time is 8 minutes less than the filling time. What is the filling capacity of the pool?

**Options:**
- A) 40
- B) 50
- C) 60
- D) 70

**Correct Answer:** B) 50

**Detailed Mathematical Explanation:**
- Let the filling capacity = $F$ m$^3$/min.
- The emptying capacity = $(F + 10)$ m$^3$/min.
- Capacity of pool = 2400 m$^3$.
- Formulate the time difference equation:
  $$\frac{2400}{F} - \frac{2400}{F + 10} = 8$$
- Divide throughout by 8:
  $$\frac{300}{F} - \frac{300}{F + 10} = 1$$
  $$\frac{300(F + 10) - 300F}{F(F + 10)} = 1$$
  $$\frac{3000}{F(F + 10)} = 1 \implies F(F + 10) = 3000$$
- Factoring 3000 into two factors differing by 10:
  $$50 \times 60 = 3000 \implies F = 50 \text{ m}^3\text{/min}$$

**Shortcut / Exam Trick:**
Test the given options directly into $F(F + 10) = 3000$:
- For $F = 50$: $50 \times 60 = 3000$ (Satisfies immediately).

---

### Q22
**Question:**
A cistern has 10 pipes connected to it. Some are inlet pipes and the others are outlet pipes. Each inlet pipe can fill the cistern in 8 hours and each outlet pipe can empty it in 6 hours. If all the pipes are opened together, a full cistern is emptied in 2 hours. Find the number of outlet pipes.

**Options:**
- A) 3
- B) 2
- C) 6
- D) 7

**Correct Answer:** C) 6

**Detailed Mathematical Explanation:**
- Let the number of outlet pipes = $y$.
- Number of inlet pipes = $10 - y$.
- Filling rate of 1 inlet = $+\frac{1}{8}$ tank/hour.
- Emptying rate of 1 outlet = $-\frac{1}{6}$ tank/hour.
- Since a full cistern is emptied in 2 hours, the net rate is negative:
  $$\text{Net Rate} = -\frac{1}{2} \text{ tank/hour}$$
- Formulate the rate equation:
  $$(10 - y) \left(\frac{1}{8}\right) - y \left(\frac{1}{6}\right) = -\frac{1}{2}$$
- Multiply the entire equation by 24:
  $$3(10 - y) - 4y = -12$$
  $$30 - 3y - 4y = -12$$
  $$30 - 7y = -12 \implies 7y = 42 \implies y = 6$$
- Therefore, there are **6 outlet pipes** (and $10 - 6 = 4$ inlet pipes).

**Shortcut / Exam Trick (Alligation Method):**
- If all 10 were inlets: Rate = $10 / 8 = +1.25$ tanks/hour.
- If all 10 were outlets: Rate = $-10 / 6 = -1.667$ tanks/hour.
- Target net rate = $-0.5$ tank/hour.
$$\frac{\text{Inlets}}{\text{Outlets}} = \frac{-0.5 - (-1.667)}{1.25 - (-0.5)} = \frac{1.167}{1.75} = \frac{7/6}{7/4} = \frac{4}{6} = \frac{2}{3}$$
$$\text{Outlets} = \frac{3}{2 + 3} \times 10 = 6$$

---

### Q23
**Question:**
A tank has three outlet taps A, B and C. A can empty the tank by filling 4 pots of 7 liters capacity each in 24 minutes. B empties by filling 8 pots of 7 liters capacity each in 1 hour. C empties by filling 2 pots of 7 liters capacity each in 20 minutes. If the tank is full and all three taps are opened together, it gets emptied in 2 hours. Find the capacity of the tank.

**Options:**
- A) 336 L
- B) 332 L
- C) 340 L
- D) 372 L

**Correct Answer:** A) 336 L

**Detailed Mathematical Explanation:**
- Capacity of 1 pot = 7 litres.
- Discharge rate of Tap A:
  $$4 \times 7 = 28 \text{ L in } 24 \text{ min} \implies \text{Rate}_A = \frac{28}{24} = \frac{7}{6} \text{ L/min}$$
- Discharge rate of Tap B:
  $$8 \times 7 = 56 \text{ L in } 60 \text{ min} \implies \text{Rate}_B = \frac{56}{60} = \frac{14}{15} \text{ L/min}$$
- Discharge rate of Tap C:
  $$2 \times 7 = 14 \text{ L in } 20 \text{ min} \implies \text{Rate}_C = \frac{14}{20} = \frac{7}{10} \text{ L/min}$$
- Total discharge rate of (A + B + C):
  $$\text{Total Rate} = \frac{7}{6} + \frac{14}{15} + \frac{7}{10}$$
  $$\text{LCM}(6, 15, 10) = 30$$
  $$\text{Total Rate} = \frac{35 + 28 + 21}{30} = \frac{84}{30} = 2.8 \text{ L/min}$$
- The tank is completely emptied in 2 hours ($= 120$ minutes):
  $$\text{Capacity} = 120 \text{ minutes} \times 2.8 \text{ L/min} = 336 \text{ Litres}$$

**Shortcut / Exam Trick:**
$$\text{Volume in 2h} = 2 \times \left[\left(\frac{60}{24} \times 28\right) + 56 + \left(\frac{60}{20} \times 14\right)\right] = 2 \times [70 + 56 + 42] = 2 \times 168 = 336\text{ L}$$

---

### Q24
**Question:**
A system of $n$ pipes is used to fill a tank. Each fill pipe takes 20 hours to fill the tank, while each drain pipe takes 30 hours to empty it. If the entire system can fill the tank in 5 hours, what is a possible value for $n$ (including both fill and drain pipes)?

**Options:**
- A) 4
- B) 9
- C) 2
- D) 8

**Correct Answer:** B) 9

**Detailed Mathematical Explanation:**
- Let $f$ be the number of fill pipes and $d$ be the number of drain pipes.
- Total pipes: $n = f + d$, where $f \ge 1$ and $d \ge 1$ (since the question specifies including both fill and drain pipes).
- Rate of 1 fill pipe = $+\frac{1}{20}$ tank/hour.
- Rate of 1 drain pipe = $-\frac{1}{30}$ tank/hour.
- System fill rate = $+\frac{1}{5}$ tank/hour.
- Formulate the rate equation:
  $$f \left(\frac{1}{20}\right) - d \left(\frac{1}{30}\right) = \frac{1}{5}$$
- Multiply throughout by 60:
  $$3f - 2d = 12$$
- Express in terms of total pipes $n$ by substituting $d = n - f$:
  $$3f - 2(n - f) = 12$$
  $$5f - 2n = 12 \implies 5f = 12 + 2n$$
- Test the options for $n$:
  - If $n = 4$: $5f = 12 + 8 = 20 \implies f = 4 \implies d = 0$ (Invalid, no drain pipes).
  - If $n = 9$: $5f = 12 + 18 = 30 \implies f = 6 \implies d = 9 - 6 = 3$ (Valid: 6 fill pipes, 3 drain pipes).
  - If $n = 2$: $5f = 16$ (Not an integer).
  - If $n = 8$: $5f = 28$ (Not an integer).
- Therefore, the unique valid integer solution containing both pipe types is **$n = 9$**.

**Shortcut / Exam Trick:**
$$3f - 2d = 12 \implies f = \frac{12 + 2d}{3} = 4 + \frac{2d}{3}$$
For integer $f$, $d$ must be a multiple of 3 ($d = 3, 6, 9 \dots$).
- For $d = 3$: $f = 4 + 2 = 6 \implies n = f + d = 6 + 3 = 9$.

---

### Q25
**Question:**
A cistern has three pipes A, B and C. Pipes A and B can fill it in 20 minutes and 30 minutes respectively, while pipe C can empty the full cistern in 15 minutes. If all the three pipes are opened successively for 1 minute each, how long will it take to fill the cistern?

**Options:**
- A) 167 minutes
- B) 180 minutes
- C) 163 minutes
- D) 171 minutes

**Correct Answer:** A) 167 minutes

**Detailed Mathematical Explanation:**
- Total capacity = $\text{LCM}(20, 30, 15) = 60$ units.
- Rate of A (Minute 1) = $\frac{60}{20} = +3$ units/min.
- Rate of B (Minute 2) = $\frac{60}{30} = +2$ units/min.
- Rate of C (Minute 3) = $-\frac{60}{15} = -4$ units/min.
- **One 3-minute cycle:**
  - Minute 1: A adds $+3$ units.
  - Minute 2: B adds $+2$ units (Cumulative: $+5$).
  - Minute 3: C removes $-4$ units (Cumulative: $+1$).
  - Net work done in 1 cycle (3 minutes) = $+1$ unit.
- **Applying the Threshold Rule:**
  - During the first 2 minutes of any cycle, A and B together can add up to $3 + 2 = 5$ units.
  - Therefore, calculate whole cycles up to:
    $$\text{Target} \le 60 - 5 = 55 \text{ units}$$
  - Number of complete cycles to achieve 55 units = $55$ cycles.
  - Time elapsed for 55 cycles:
    $$55 \text{ cycles} \times 3 \text{ min/cycle} = 165 \text{ minutes}$$
- **Subsequent Step-by-Step Progress:**
  - At $t = 165$ min: Volume = 55 units.
  - Minute 166 (Pipe A's turn): Adds $+3$ units $\implies 55 + 3 = 58$ units.
  - Minute 167 (Pipe B's turn): Adds $+2$ units $\implies 58 + 2 = 60$ units (Tank is full!).
- Total time taken = **167 minutes**.

**Shortcut / Exam Trick:**
$$t = (60 - 5) \times 3 + 2 = 165 + 2 = 167\text{ minutes}$$

---

### Q26
**Question:**
A leak in the bottom of a tank can empty it in 9 hours. A pipe fills water at 5 litres per minute. When the tank is full, the inlet is opened but due to the leak, the tank empties in 12 hours. What is the capacity of the tank?

**Options:**
- A) 17600 litres
- B) 12500 litres
- C) 10800 litres
- D) 13400 litres

**Correct Answer:** C) 10800 litres

**Detailed Mathematical Explanation:**
- Rate of the leak alone = $\frac{1}{9}$ tank/hour.
- Net emptying rate with inlet opened = $\frac{1}{12}$ tank/hour.
- Rate of the inlet pipe:
  $$\text{Rate}_{\text{inlet}} = \text{Leak Rate} - \text{Net Rate} = \frac{1}{9} - \frac{1}{12} = \frac{4 - 3}{36} = \frac{1}{36} \text{ tank/hour}$$
- Time taken by inlet pipe alone to fill the tank:
  $$T_{\text{inlet}} = 36 \text{ hours} = 36 \times 60 = 2160 \text{ minutes}$$
- Inflow rate = 5 litres/minute:
  $$\text{Capacity of the tank} = 2160 \text{ minutes} \times 5 \text{ litres/min} = 10,800 \text{ litres}$$

**Shortcut / Exam Trick:**
$$T_{\text{inlet}} = \frac{9 \times 12}{12 - 9} = \frac{108}{3} = 36\text{ hours}$$
$$\text{Capacity} = 36 \times 60 \times 5 = 10,800\text{ litres}$$

---

### Q27
**Question:**
A tap can fill a tank in 8 hours. After half of the tank is filled, two more similar taps and an emptying tap that can empty the full tank in 12 hours are opened. What is the total time taken to fill the tank completely?

**Options:**
- A) 5 hours
- B) $5\frac{1}{7}$ hours
- C) $5\frac{5}{7}$ hours
- D) $6\frac{6}{7}$ hours

**Correct Answer:** C) $5\frac{5}{7}$ hours

**Detailed Mathematical Explanation:**
- **Phase 1 (First half of the tank):**
  - 1 tap fills the whole tank in 8 hours.
  - Time taken to fill half ($\frac{1}{2}$) tank = $\frac{8}{2} = 4$ hours.
- **Phase 2 (Second half of the tank):**
  - Active pipes: Original tap + 2 similar taps (total 3 fill taps, each rate $\frac{1}{8}$) + 1 drain tap (rate $-\frac{1}{12}$).
  - Combined filling rate:
    $$\text{Net Rate} = 3 \left(\frac{1}{8}\right) - \frac{1}{12} = \frac{3}{8} - \frac{1}{12} = \frac{9 - 2}{24} = \frac{7}{24} \text{ tank/hour}$$
  - Volume remaining to fill = $\frac{1}{2}$ tank.
  - Time for Phase 2:
    $$t_2 = \frac{1/2}{7/24} = \frac{1}{2} \times \frac{24}{7} = \frac{12}{7} = 1\frac{5}{7} \text{ hours}$$
- **Total Time Taken:**
  $$T_{\text{total}} = 4 + 1\frac{5}{7} = 5\frac{5}{7} \text{ hours}$$

**Shortcut / Exam Trick:**
$$T = 4 + \frac{1/2}{\frac{3}{8} - \frac{1}{12}} = 4 + \frac{12}{7} = 5\frac{5}{7}\text{ hours}$$

---

### Q28
**Question:**
A pipe of diameter $d$ can drain a certain water tank in 40 minutes. The time taken by a pipe of diameter $2d$ for doing the same job is?

**Options:**
- A) 10 min
- B) 15 min
- C) 5 min
- D) 20 min

**Correct Answer:** A) 10 min

**Detailed Mathematical Explanation:**
- Flow rate ($Q$) through a cylindrical pipe is directly proportional to its cross-sectional area:
  $$Q \propto A = \pi r^2 = \pi \left(\frac{d}{2}\right)^2 \propto d^2$$
- Ratio of flow rates:
  $$\frac{Q_2}{Q_1} = \left(\frac{d_2}{d_1}\right)^2 = \left(\frac{2d}{d}\right)^2 = 4$$
- The pipe with diameter $2d$ empties at 4 times the speed of the pipe with diameter $d$.
- Since time is inversely proportional to discharge rate:
  $$T_2 = \frac{T_1}{4} = \frac{40 \text{ min}}{4} = 10 \text{ minutes}$$

**Shortcut / Exam Trick:**
$$T_2 = T_1 \times \left(\frac{d_1}{d_2}\right)^2 = 40 \times \left(\frac{1}{2}\right)^2 = \frac{40}{4} = 10\text{ minutes}$$

---

### Q29
**Question:**
A pipe can fill a tank in 8 hours. Due to a leak in the bottom, it is filled in 10 hours. If the tank is full, how much time will the leak take to empty it?

**Options:**
- A) 18 hours
- B) 8 hours
- C) 40 hours
- D) 10 hours

**Correct Answer:** C) 40 hours

**Detailed Mathematical Explanation:**
- Filling rate of pipe without leak = $+\frac{1}{8}$ tank/hour.
- Net filling rate with leak active = $+\frac{1}{10}$ tank/hour.
- Emptying rate of the leak:
  $$\text{Rate}_{\text{leak}} = \frac{1}{8} - \frac{1}{10} = \frac{5 - 4}{40} = \frac{1}{40} \text{ tank/hour}$$
- Time taken by the leak alone to empty the full tank:
  $$T_{\text{leak}} = \frac{1}{1/40} = 40 \text{ hours}$$

**Shortcut / Exam Trick:**
$$T_{\text{leak}} = \frac{x \cdot y}{y - x} = \frac{8 \times 10}{10 - 8} = \frac{80}{2} = 40\text{ hours}$$

---

### Q30
**Question:**
A pipe can fill $\frac{1}{3}$ of a cistern in 10 minutes. How much time will it take to fill $\frac{5}{6}$ of the cistern?

**Options:**
- A) 20 min
- B) 25 min
- C) 30 min
- D) 18 min

**Correct Answer:** B) 25 min

**Detailed Mathematical Explanation:**
- Time taken to fill the entire tank ($1$ full cistern):
  $$T_{\text{full}} = 10 \text{ min} \times 3 = 30 \text{ minutes}$$
- Filling rate = $\frac{1}{30}$ cistern/minute.
- Time required to fill $\frac{5}{6}$ of the cistern:
  $$\text{Time} = \frac{5}{6} \times T_{\text{full}} = \frac{5}{6} \times 30 = 25 \text{ minutes}$$

**Shortcut / Exam Trick:**
$$\text{Time} = 10 \times \frac{5/6}{1/3} = 10 \times \frac{5}{2} = 25\text{ minutes}$$
---

## 4. Key Exam Tricks, Tips, and Mental Math Shortcuts

1. **The LCM Framework for Instant Calculations:**
   - Avoid dealing with fractions by setting the total capacity to the LCM of given times.
   - Example: Pipes take 10, 15, and 30 hours. Tank = 30 units. Rates are $+3, +2, -1$ units/hr. Net rate = $+4$ units/hr.

2. **The Product-Over-Difference Formula for Single Inlets with Leaks:**
   - When a tap takes $T_1$ hours to fill normally and $T_2$ hours ($T_2 > T_1$) due to a leak, the leak empties the full cistern in:
     $$T_{\text{leak}} = \frac{T_1 \times T_2}{T_2 - T_1}$$
   - When an outlet drains in $T_{\text{drain}}$ and with an inlet open empties in $T_{\text{net}}$ ($T_{\text{net}} > T_{\text{drain}}$):
     $$T_{\text{inlet}} = \frac{T_{\text{drain}} \times T_{\text{net}}}{T_{\text{net}} - T_{\text{drain}}}$$

3. **Cistern Capacity Derivation:**
   - If a problem gives an inflow or outflow rate in litres per minute (e.g., $r$ L/min), compute the isolated operational time $T$ (in minutes) of that conduit.
   - $\text{Tank Capacity} = r \times T$.

4. **Alternating Operation Threshold Rule:**
   - In alternating positive-negative cycles, the tank will be declared filled as soon as it touches 100% capacity during a filling turn.
   - Always deduct the peak influx of one step before determining the number of full cycles:
     $$\text{Target for cycles} = \text{Capacity} - \text{Rate}_{\text{inlet}}$$
   - Run complete cycles until this target is reached or passed, then compute the exact remaining time on the final inlet step.

5. **Pipe Diameter Scaling Rule ($d^2$ Rule):**
   - Fluid flow rate $Q \propto d^2$ (cross-sectional area).
   - If diameter doubles ($2d$), rate quadruples ($4\times$), and filling/draining time drops to $\frac{1}{4}$ of the original.
   - If diameter triples ($3d$), rate increases by $9\times$, and time drops to $\frac{1}{9}$.

6. **Alligation Method for Mixed Conduit Networks:**
   - When a total of $N$ pipes consist of identical inlets and identical outlets producing a net fill/drain rate, treat it as an alligation between the all-inlet extreme rate and the all-outlet extreme rate to find the exact ratio of inlet to outlet pipes without algebra.
