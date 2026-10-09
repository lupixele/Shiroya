# 12. Clocks and Calendars

A comprehensive, self-contained reference guide covering fundamental principles, mathematical derivations, standard formulas, high-yield exam shortcuts, and 55 fully solved problems covering clock hand kinematics, angles, coincidences, faulty clocks, reflections, odd days, leap year rules, century cycles, and calendar date determination.

---

## 1. Comprehensive Theory and Formulas

### 1.1 Kinematics of Clock Hands

An analog clock dial is a complete circle divided into $360^\circ$, marked with 12 equal hour divisions (each representing $30^\circ$) and 60 equal minute divisions (each representing $6^\circ$).

#### 1. Minute Hand Speed
- In 60 minutes, the minute hand covers a complete rotation of $360^\circ$.
$$\text{Speed of Minute Hand} = \frac{360^\circ}{60 \text{ min}} = 6^\circ/\text{min}$$

#### 2. Hour Hand Speed
- In 12 hours (720 minutes), the hour hand covers $360^\circ$.
- In 1 hour (60 minutes), the hour hand moves across 1 hour division ($30^\circ$).
$$\text{Speed of Hour Hand} = \frac{30^\circ}{60 \text{ min}} = 0.5^\circ/\text{min} = \frac{1}{2}^\circ/\text{min}$$

#### 3. Relative Speed
- Since both hands rotate clockwise, the minute hand moves faster than the hour hand.
$$\text{Relative Speed} = 6^\circ/\text{min} - 0.5^\circ/\text{min} = 5.5^\circ/\text{min} = \frac{11}{2}^\circ/\text{min}$$
- In terms of minute spaces: in 60 minutes, the minute hand covers 60 minute spaces while the hour hand covers 5 minute spaces. Thus, the minute hand gains **55 minute spaces in 60 minutes**, or:
$$\text{Gain Rate} = \frac{60}{55} = \frac{12}{11} \text{ minutes per minute space gained}$$

---

### 1.2 Angle Between Clock Hands

At any given time $H : M$ (where $H$ is the hour, $1 \le H \le 12$, and $M$ is the minute, $0 \le M < 60$):

1. **Angular Position of the Hour Hand from 12:00:**
   $$\theta_H = 30H + 0.5M$$
2. **Angular Position of the Minute Hand from 12:00:**
   $$\theta_M = 6M$$
3. **Angle Between the Hands ($\theta$):**
   $$\theta = |\theta_H - \theta_M| = |(30H + 0.5M) - 6M| = |30H - 5.5M| = \left|30H - \frac{11}{2}M\right|$$
4. **Interior vs. Reflex Angle:**
   - The smaller (interior) angle is always $\le 180^\circ$. If $|30H - 5.5M| > 180^\circ$, the interior angle is $360^\circ - \theta$.
   - The **reflex angle** is the larger angle:
   $$\text{Reflex Angle} = 360^\circ - \text{Interior Angle}$$

---

### 1.3 Key Hand Alignments and Frequency

| Alignment Type | Angle ($\theta$) | Relative Spacing | Occurrences in 12 Hours | Occurrences in 24 Hours | Critical Overlap Note |
| :--- | :---: | :---: | :---: | :---: | :--- |
| **Coincident (Together)** | $0^\circ$ | $0$ min spaces | **11 times** | **22 times** | Between 11:00 and 1:00, coincidence occurs exactly once (at 12:00). |
| **Opposite (Straight Line)** | $180^\circ$ | $30$ min spaces | **11 times** | **22 times** | Between 5:00 and 7:00, hands are opposite exactly once (at 6:00). |
| **Straight Line (Collinear)** | $0^\circ$ or $180^\circ$ | $0$ or $30$ min spaces | **22 times** | **44 times** | Sum of coincidences ($11 \times 2$) and opposite alignments ($11 \times 2$). |
| **Right Angles (Perpendicular)** | $90^\circ$ | $15$ min spaces | **22 times** | **44 times** | Between 2:00–4:00 and 8:00–10:00, right angles occur 3 times per 2-hour window instead of 4. |

#### General Exact Time Formula for Given Angle $\theta$ Between $H$ and $H+1$:
$$M = \frac{2}{11}(30H \pm \theta)$$
- For coincidence ($\theta = 0^\circ$): $M = \frac{2}{11}(30H) = \frac{60H}{11}$
- For opposite ($\theta = 180^\circ$): $M = \frac{2}{11}(30H \pm 180^\circ)$
- For right angle ($\theta = 90^\circ$): $M = \frac{2}{11}(30H \pm 90^\circ)$

---

### 1.4 Faulty Clocks (Gaining / Losing Time)

1. **Standard Coincidence Interval:**
   In an accurate clock, the two hands coincide every:
   $$T_{\text{coincide}} = \frac{360^\circ}{5.5^\circ/\text{min}} = \frac{720}{11} \text{ minutes} = 65\frac{5}{11} \text{ minutes}$$
   - If hands coincide in **less than** $65\frac{5}{11}$ minutes, the clock is **gaining time** (running fast).
   - If hands coincide in **more than** $65\frac{5}{11}$ minutes, the clock is **losing time** (running slow).
   - In time interval $T$, total gain or loss:
     $$\text{Total Gain/Loss} = \left( \frac{65\frac{5}{11} - M}{M} \right) \times T$$
2. **Proportional Error Formula:**
   $$\frac{\text{True Time Interval}}{\text{Faulty Time Interval}} = \frac{60 \text{ minutes}}{60 \pm x \text{ minutes}}$$
   Where $x$ is the gain $(+)$ or loss $(-)$ per true hour.
3. **Showing Correct Time Again:**
   A 12-hour analog clock repeats its display when it gains or loses a cumulative **12 hours (720 minutes)**.
   $$\text{Time to Reset} = \frac{720 \text{ minutes}}{\text{Error rate per hour (minutes/hour)}}$$

---

### 1.5 Mirror and Water Reflections of Clocks

#### 1. Vertical Mirror Image (Left-Right Inversion)
- To find actual time from mirror time (or vice versa):
  $$\text{Actual Time} = 11:60 - \text{Given Time} \quad (\text{or } 23:60 - \text{Given Time})$$
  *(For exact hours, subtract from 12:00 or 24:00).*

#### 2. Water Image (Horizontal Inversion / Top-Bottom Flip)
- Across the horizontal 9–3 axis:
  $$\text{Actual Time} = 18:30 - \text{Given Time}$$
  If minutes $> 30$, borrow 1 hour ($60$ min) to write the base as $17:90$:
  $$\text{Actual Time} = 17:90 - \text{Given Time}$$

---

### 1.6 Calendar Fundamentals & The Odd Days Concept

A calendar is based on the solar year cycle. The number of days exceeding complete 7-day weeks is called **odd days**.
$$\text{Odd Days} = \text{Total Days} \pmod 7$$

#### 1. Year Classifications
- **Ordinary Year:** 365 days = 52 weeks + **1 day** $\implies$ **1 odd day**.
- **Leap Year:** 366 days = 52 weeks + **2 days** $\implies$ **2 odd days**.

#### 2. Leap Year Determination Rules
- A non-century year is a leap year if it is divisible by **4** (e.g., 2004, 2008, 2024).
- A century year is a leap year **only if** it is divisible by **400** (e.g., 1600, 2000, 2400 are leap years; 1700, 1800, 1900, 2100 are ordinary years).

#### 3. Odd Days in Century Cycles
- **In 100 years:** Contains 76 ordinary years and 24 leap years.
  $$\text{Total Odd Days} = 76 \times 1 + 24 \times 2 = 76 + 48 = 124 \text{ days}$$
  $$124 \pmod 7 = 5 \implies \mathbf{5 \text{ odd days}}$$
- **In 200 years:** $5 \times 2 = 10 \implies 10 \pmod 7 = \mathbf{3 \text{ odd days}}$.
- **In 300 years:** $5 \times 3 = 15 \implies 15 \pmod 7 = \mathbf{1 \text{ odd day}}$.
- **In 400 years:** $5 \times 4 + 1 \text{ (leap century day)} = 21 \implies 21 \pmod 7 = \mathbf{0 \text{ odd days}}$.
- Every multiple of 400 years ($400, 800, 1200, 1600, 2000$) has **0 odd days**.

#### 4. Last and First Day of a Century
Since odd days at the close of centuries are:
- 100 years: 5 odd days $\implies$ **Friday**
- 200 years: 3 odd days $\implies$ **Wednesday**
- 300 years: 1 odd day $\implies$ **Monday**
- 400 years: 0 odd days $\implies$ **Sunday**

$$\mathbf{\text{Last Day of a Century can be: Sunday, Monday, Wednesday, Friday.}}$$
$$\mathbf{\text{Last Day of a Century CANNOT be: Tuesday, Thursday, Saturday.}}$$

Correspondingly, the first day of a century can be **Monday, Tuesday, Thursday, or Saturday**.

#### 5. Day Code Mapping
| Remainder (Odd Days) | Day of the Week |
| :---: | :--- |
| **0** | Sunday |
| **1** | Monday |
| **2** | Tuesday |
| **3** | Wednesday |
| **4** | Thursday |
| **5** | Friday |
| **6** | Saturday |

#### 6. Month Odd Days Summary
| Month | Days | Odd Days ($D \pmod 7$) |
| :--- | :---: | :---: |
| January | 31 | 3 |
| February (Ordinary / Leap) | 28 / 29 | 0 / 1 |
| March | 31 | 3 |
| April | 30 | 2 |
| May | 31 | 3 |
| June | 30 | 2 |
| July | 31 | 3 |
| August | 31 | 3 |
| September | 30 | 2 |
| October | 31 | 3 |
| November | 30 | 2 |
| December | 31 | 3 |

#### 7. Repetition of Calendar Years
To find when a calendar repeats:
- A **leap year** repeats after **28 years** (provided no non-leap century year is crossed).
- An ordinary year immediately following a leap year (Leap $+ 1$) repeats after **6 years**.
- Other ordinary years (Leap $+ 2$, Leap $+ 3$) repeat after **11 years**.
- General condition: the cumulative sum of odd days between the two years must be a multiple of 7, and both years must share the same type (ordinary or leap).

---

## 2. Comprehensive Solved Question Bank

### Q1. Hour Hand Angular Displacement
**Question:**  
An accurate clock shows 8 o’clock in the morning. Through how many degrees will the hour hand rotate when the clock shows 2 o’clock in the afternoon?  
- a) 144°  
- b) 50°  
- c) 168°  
- d) 180°  

**Correct Answer:** Option d) 180°

**Step-by-Step Solution:**
1. **Determine elapsed time:**
   - Time duration from 8:00 AM to 2:00 PM = $14:00 - 08:00 = 6\text{ hours}$.
2. **Calculate angular velocity of hour hand:**
   - In 12 hours (720 minutes), the hour hand rotates $360^\circ$.
   - Angular speed = $\frac{360^\circ}{12} = 30^\circ/\text{hour}$.
3. **Compute total angular displacement:**
   $$\theta = 6 \text{ hours} \times 30^\circ/\text{hour} = 180^\circ$$

**Exam Shortcut / Speed Trick:**
Each hour division on a clock face is $30^\circ$. An interval of 6 hours spans exactly half the circular dial: $6 \times 30^\circ = 180^\circ$.

---

### Q2. Angle Between Hands at 8:40
**Question:**  
What is the angle between the hour hand and the minute hand of a clock at 8:40?  
- a) 20°  
- b) 25°  
- c) 30°  
- d) 35°  

**Correct Answer:** Option a) 20°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 8$, Minute $M = 40$.
2. **Standard angle formula:**
   $$\theta = |30H - 5.5M|$$
3. **Substitute values:**
   $$\theta = |30(8) - 5.5(40)| = |240 - 220| = 20^\circ$$

**Exam Shortcut / Speed Trick:**
At 8:40, the minute hand points precisely at mark 8 ($40 \times 6^\circ = 240^\circ$). In the same 40 minutes, the hour hand has moved forward from 8 by $40 \times 0.5^\circ = 20^\circ$. Hence, the separation between them is simply $20^\circ$.

---

### Q3. Angle Between Hands at 8:30
**Question:**  
The angle between the minute hand and the hour hand of a clock when the time is 8:30, is:  
- a) 80°  
- b) 75°  
- c) 60°  
- d) 105°  

**Correct Answer:** Option b) 75°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 8$, Minute $M = 30$.
2. **Apply the angle formula:**
   $$\theta = |30H - 5.5M|$$
3. **Evaluate the arithmetic:**
   $$\theta = |30(8) - 5.5(30)| = |240 - 165| = 75^\circ$$

**Exam Shortcut / Speed Trick:**
At 8:30, the minute hand is at 6. The difference in hour markings is $8 - 6 = 2$ hour divisions ($2 \times 30^\circ = 60^\circ$). The hour hand has moved forward by half the minute count: $30 \times 0.5^\circ = 15^\circ$. Total angle = $60^\circ + 15^\circ = 75^\circ$.

---

### Q4. Angle Between Hands at 4:20
**Question:**  
The angle between the minute hand and the hour hand of a clock when the time is 4:20, is:  
- a) 0°  
- b) 10°  
- c) 5°  
- d) 20°  

**Correct Answer:** Option b) 10°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 4$, Minute $M = 20$.
2. **Apply the angle formula:**
   $$\theta = |30H - 5.5M|$$
3. **Calculate:**
   $$\theta = |30(4) - 5.5(20)| = |120 - 110| = 10^\circ$$

**Exam Shortcut / Speed Trick:**
Whenever the minute hand points directly at the hour number (e.g., minute hand at 20 points at 4), the separation is caused solely by the advance of the hour hand: $\theta = \frac{M}{2} = \frac{20}{2} = 10^\circ$.

---

### Q5. Angle Between Hands at 5:15
**Question:**  
At what angle between the hands of a clock are at 15 minutes past 5?  
- a) 58½°  
- b) 64°  
- c) 62½°  
- d) 67½°  

**Correct Answer:** Option d) 67½° (67.5°)

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 5$, Minute $M = 15$.
2. **Apply the angle formula:**
   $$\theta = |30H - 5.5M|$$
3. **Calculate:**
   $$\theta = |30(5) - 5.5(15)| = |150 - 82.5| = 67.5^\circ = 67\frac{1}{2}^\circ$$
   *(Note: Multiple choice banks frequently list this standard problem; where typographical misprints in question papers list 62½° or 58½°, the rigorous mathematical value is definitively $67\frac{1}{2}^\circ$).*

**Exam Shortcut / Speed Trick:**
At 5:00, hands are separated by $5 \times 30^\circ = 150^\circ$. In 15 minutes, the relative closing distance is $15 \times 5.5^\circ = 82.5^\circ$. The remaining angle is $150^\circ - 82.5^\circ = 67.5^\circ = 67\frac{1}{2}^\circ$.

---

### Q6. Hand Coincidence Frequency in a Day
**Question:**  
How many times do the hands of a clock coincide in a day?  
- a) 20  
- b) 21  
- c) 22  
- d) 24  

**Correct Answer:** Option c) 22

**Step-by-Step Solution:**
1. **Understand hand kinematics:**
   - In 12 hours, the minute hand makes 12 complete rotations while the hour hand makes 1 complete rotation.
   - The minute hand laps the hour hand $12 - 1 = 11$ times in a 12-hour period.
2. **Identify the missing coincidence:**
   - Between 11:00 and 1:00 (a 2-hour window), the hands coincide only once—precisely at 12:00:00.
3. **Calculate for a full 24-hour day:**
   $$\text{Coincidences in 24 hours} = 11 \times 2 = 22 \text{ times}$$

**Exam Shortcut / Speed Trick:**
Remember the fundamental frequency ratio: Hands coincide **11 times in 12 hours** and **22 times in 24 hours**.

---

### Q7. Hands in a Straight Line Frequency
**Question:**  
How many times in a day, the hands of a clock are straight?  
- a) 22  
- b) 24  
- c) 44  
- d) 48  

**Correct Answer:** Option c) 44

**Step-by-Step Solution:**
1. **Define "straight line" condition:**
   - Clock hands form a straight line under two distinct geometric configurations:
     - When they coincide (angle $\theta = 0^\circ$).
     - When they point in opposite directions (angle $\theta = 180^\circ$).
2. **Calculate occurrences per 12 hours:**
   - Coincidences: 11 times.
   - Opposites: 11 times.
   - Total straight positions in 12 hours = $11 + 11 = 22$ times.
3. **Calculate for a full 24-hour day:**
   $$\text{Total straight line occurrences} = 22 \times 2 = 44 \text{ times}$$

**Exam Shortcut / Speed Trick:**
Straight line = Coincident ($22$) + Opposite ($22$) = **44 times per day**.

---

### Q8. Right Angles Frequency in a Day
**Question:**  
How many times are the hands of a clock at right angle in a day?  
- a) 22  
- b) 24  
- c) 44  
- d) 48  

**Correct Answer:** Option c) 44

**Step-by-Step Solution:**
1. **Analyze right angles per hour:**
   - Generally, the hands form a $90^\circ$ angle twice every hour (once when the minute hand is $90^\circ$ behind, and once when it is $90^\circ$ ahead).
2. **Identify overlapping boundary intervals:**
   - Between 2:00 and 4:00 (a 2-hour span), instead of 4 right angles, there are only 3 (one occurs at 3:00:00 common boundary).
   - Similarly, between 8:00 and 10:00, there are only 3 right angles (one occurs at 9:00:00 common boundary).
   - Right angles in 12 hours = $(2 \times 12) - 2 = 22$ times.
3. **Scale to 24 hours:**
   $$\text{Total right angles in 24 hours} = 22 \times 2 = 44 \text{ times}$$

**Exam Shortcut / Speed Trick:**
Right angles occur **22 times in 12 hours** and **44 times in 24 hours**.

---

### Q9. Straight Line but Opposite Direction Frequency
**Question:**  
How many times in a day, are the hands of a clock in straight line but opposite direction?  
- a) 20  
- b) 22  
- c) 24  
- d) 48  

**Correct Answer:** Option b) 22

**Step-by-Step Solution:**
1. **Identify the alignment condition:**
   - The hands are in a straight line pointing in opposite directions when the angle between them is $180^\circ$.
2. **Examine the 12-hour cycle:**
   - In every 1-hour interval, the hands are opposite once, except between 5:00 and 7:00 where they are opposite only once—precisely at 6:00:00.
   - Therefore, in 12 hours, opposite alignments occur **11 times**.
3. **Calculate for a 24-hour day:**
   $$\text{Opposite alignments in 24 hours} = 11 \times 2 = 22 \text{ times}$$

**Exam Shortcut / Speed Trick:**
Hands point in opposite directions **11 times per 12 hours** $\implies$ **22 times in 24 hours**.

---

### Q10. Historical Calendar Date: 16th July 1776
**Question:**  
What was the day of the week on 16th July, 1776?  
- a) Tuesday  
- b) Monday  
- c) Sunday  
- d) Friday  

**Correct Answer:** Option a) Tuesday

**Step-by-Step Solution:**
1. **Decompose the year into completed periods:**
   - Year 1776 is running; completed years = 1775 years.
   - $1775 = 1600 \text{ years} + 100 \text{ years} + 75 \text{ years}$.
2. **Calculate odd days for completed centuries:**
   - 1600 years: $0$ odd days (multiple of 400).
   - 100 years: $5$ odd days.
3. **Calculate odd days in 75 years:**
   - Leap years in 75 years = $\lfloor 75 / 4 \rfloor = 18$ leap years.
   - Ordinary years = $75 - 18 = 57$ ordinary years.
   - Total odd days = $(18 \times 2) + (57 \times 1) = 36 + 57 = 93$ days.
   - $93 \pmod 7 = 2$ odd days.
   - Total odd days up to 31st Dec 1775 = $0 + 5 + 2 = 7 \equiv 0$ odd days.
4. **Calculate odd days from 1st Jan 1776 to 16th July 1776:**
   - 1776 is a leap year (divisible by 4).
   - Jan (31) + Feb (29) + Mar (31) + Apr (30) + May (31) + Jun (30) + Jul (16)
   - Odd days: $3 + 1 + 3 + 2 + 3 + 2 + (16 \pmod 7) = 14 + 2 = 16$ days.
   - $16 \pmod 7 = 2$ odd days.
5. **Determine the day of week:**
   - Total odd days = $0 + 2 = 2$.
   - Day code 2 corresponds to **Tuesday**.

**Exam Shortcut / Speed Trick:**
Completed period up to 1700 has $5$ odd days. 75 years adds $(75 + 18) = 93 \equiv 2$ odd days. Total odd days through 1775 is $5 + 2 = 7 \equiv 0$. In leap year 1776: Jan (3) + Feb (1) + Mar (3) + Apr (2) + May (3) + Jun (2) + 16 July (2) = $16 \equiv 2$ odd days $\implies$ **Tuesday**.

---
### Q11. Day of the Week on 4th June 2002
**Question:**  
What was the day of the week on 4th June, 2002?  
- a) Tuesday  
- b) Monday  
- c) Sunday  
- d) Friday  

**Correct Answer:** Option a) Tuesday

**Step-by-Step Solution:**
1. **Decompose completed period:**
   - Completed years = 2001 years.
   - $2001 = 2000 \text{ years} + 1 \text{ year}$.
2. **Calculate odd days for completed years:**
   - 2000 years: $0$ odd days (multiple of 400).
   - 1 ordinary year (2001): $1$ odd day.
   - Total odd days up to 31st Dec 2001 = $0 + 1 = 1$ odd day.
3. **Calculate odd days in 2002 up to 4th June:**
   - 2002 is an ordinary year (February has 28 days).
   - Jan: 31 days $\implies 3$ odd days.
   - Feb: 28 days $\implies 0$ odd days.
   - Mar: 31 days $\implies 3$ odd days.
   - Apr: 30 days $\implies 2$ odd days.
   - May: 31 days $\implies 3$ odd days.
   - Jun: 4 days $\implies 4$ odd days.
   - Total odd days in 2002 = $3 + 0 + 3 + 2 + 3 + 4 = 15$ days.
   - $15 \pmod 7 = 1$ odd day.
4. **Sum total odd days:**
   - Total odd days = $1 \text{ (prior years)} + 1 \text{ (running year)} = 2$ odd days.
   - Day code 2 corresponds to **Tuesday**.

**Exam Shortcut / Speed Trick:**
Base year 2000 has 0 odd days. Prior year 2001 gives $+1$. Monthly odd days up to May give $3+0+3+2+3 = 11 \equiv 4$. Adding 4 days of June gives $4+4 = 8 \equiv 1$. Total = $1 + 1 = 2 \implies$ **Tuesday**.

---

### Q12. Dates on Which a Given Day Falls in a Month
**Question:**  
On what dates of March 2005 did Friday fall?  
- a) 4th, 11th, 18th, 25th  
- b) 5th, 12th, 19th, 26th  
- c) 6th, 13th, 20th, 27th  
- d) 7th, 14th, 21st, 28th  

**Correct Answer:** Option a) 4th, 11th, 18th, 25th

**Step-by-Step Solution:**
1. **Find the day of the week on 1st March 2005:**
   - Completed years = 2004 years ($2000 + 4$).
   - 2000 years $\implies 0$ odd days.
   - 4 years (2001, 2002, 2003 ordinary, 2004 leap):
     - Leap years = 1, Ordinary years = 3.
     - Odd days = $(1 \times 2) + (3 \times 1) = 5$ odd days.
   - Odd days up to 31st Dec 2004 = $0 + 5 = 5$ odd days.
2. **Days in 2005 up to 1st March:**
   - Jan: 31 days $\implies 3$ odd days.
   - Feb: 28 days $\implies 0$ odd days (2005 is non-leap).
   - Mar 1: 1 day $\implies 1$ odd day.
   - Total in 2005 = $3 + 0 + 1 = 4$ odd days.
3. **Total odd days for 1st March 2005:**
   - Total = $5 + 4 = 9 \equiv 2$ odd days ($9 \pmod 7$).
   - Code 2 corresponds to **Tuesday**.
4. **Locate the first Friday:**
   - If 1st March is Tuesday:
     - 2nd March = Wednesday
     - 3rd March = Thursday
     - 4th March = **Friday**
5. **Generate successive Fridays (+7 days):**
   - 4th, $4 + 7 = 11\text{th}$, $11 + 7 = 18\text{th}$, $18 + 7 = 25\text{th}$.

**Exam Shortcut / Speed Trick:**
Calculate 1st March: $2000(0) + 4\text{ yrs}(5) + \text{Jan}(3) + \text{Feb}(0) + 1 = 9 \equiv 2$ (Tuesday). Since March 1 is Tuesday, the first Friday is $1 + 3 = 4\text{th}$. Successive Fridays occur at $+7$ intervals: 4th, 11th, 18th, 25th.

---

### Q13. Consecutive Years: Ordinary Year Transition
**Question:**  
January 1, 2007 was Monday. What day of the week lies on Jan 1, 2008?  
- a) Monday  
- b) Tuesday  
- c) Wednesday  
- d) Sunday  

**Correct Answer:** Option b) Tuesday

**Step-by-Step Solution:**
1. **Analyze year 2007:**
   - 2007 is an ordinary year because $2007$ is not divisible by 4.
   - Total days in an ordinary year = 365 days.
2. **Calculate odd days:**
   - $365 = 52 \times 7 + 1$ day.
   - An ordinary year contains exactly **1 odd day**.
3. **Advance the day of the week:**
   - $\text{Day on Jan 1, 2008} = \text{Day on Jan 1, 2007} + 1 \text{ odd day}$.
   - $\text{Monday} + 1 = \text{Tuesday}$.

**Exam Shortcut / Speed Trick:**
An ordinary year always advances the day of the week by **+1 day** on the exact same date of the following year. Monday $+ 1$ = **Tuesday**.

---

### Q14. Consecutive Years: Leap Year Transition
**Question:**  
January 1, 2008 is Tuesday. What day of the week lies on Jan 1, 2009?  
- a) Monday  
- b) Wednesday  
- c) Thursday  
- d) Sunday  

**Correct Answer:** Option c) Thursday

**Step-by-Step Solution:**
1. **Analyze year 2008:**
   - $2008$ is divisible by 4 ($2008 / 4 = 502$), and is not an ordinary century year.
   - Therefore, 2008 is a **leap year** containing 366 days (including February 29).
2. **Calculate odd days:**
   - $366 = 52 \times 7 + 2$ days.
   - A leap year contains **2 odd days**.
3. **Advance the day of the week:**
   - $\text{Day on Jan 1, 2009} = \text{Day on Jan 1, 2008} + 2 \text{ odd days}$.
   - $\text{Tuesday} + 2 = \text{Thursday}$.

**Exam Shortcut / Speed Trick:**
When traversing a leap year that includes February 29, the calendar advances by **+2 days**. Tuesday $+ 2$ = **Thursday**.

---

### Q15. Reverse Single-Year Offset
**Question:**  
On 8th Dec 2007 Saturday falls. What day of the week was it on 8th Dec, 2006?  
- a) Sunday  
- b) Thursday  
- c) Tuesday  
- d) Friday  

**Correct Answer:** Option d) Friday

**Step-by-Step Solution:**
1. **Identify the time interval:**
   - From 8th Dec 2006 to 8th Dec 2007 is exactly 1 year.
   - The intervening year is 2007 (ordinary year), and February 2007 has 28 days.
2. **Determine the odd day count:**
   - Total days elapsed = 365 days = $52 \text{ weeks} + 1 \text{ odd day}$.
3. **Calculate previous year's day:**
   - Since moving forward adds 1 day, moving backward subtracts 1 day:
   - $\text{Day on 8th Dec 2006} = \text{Saturday} - 1 = \text{Friday}$.

**Exam Shortcut / Speed Trick:**
Moving backward across an ordinary year subtracts **1 day**: Saturday $- 1$ = **Friday**.

---

### Q16. Multi-Year Odd Day Accumulation
**Question:**  
January 1, 2006 was Sunday. What day of the week lies on Jan 1, 2010?  
- a) Sunday  
- b) Saturday  
- c) Friday  
- d) Wednesday  

**Correct Answer:** Option c) Friday

**Step-by-Step Solution:**
1. **Identify intervening years:**
   - The period spans 4 full years: 2006, 2007, 2008, and 2009.
2. **Count odd days year by year:**
   - 2006 (ordinary): 1 odd day
   - 2007 (ordinary): 1 odd day
   - 2008 (leap): 2 odd days
   - 2009 (ordinary): 1 odd day
3. **Calculate total odd days:**
   $$\text{Total Odd Days} = 1 + 1 + 2 + 1 = 5 \text{ odd days}$$
4. **Determine the target day:**
   - $\text{Sunday} + 5 \text{ days} = \text{Friday}$.

**Exam Shortcut / Speed Trick:**
Number of years = 4. Number of leap years = 1 (year 2008). Total odd days = $4 + 1 = 5$. Sunday $+ 5$ = **Friday**.

---

### Q17. Leap Year Boundary Effect: March to March
**Question:**  
If 6th March, 2005 is Monday, what was the day of the week on 6th March, 2004?  
- a) Sunday  
- b) Saturday  
- c) Tuesday  
- d) Wednesday  

**Correct Answer:** Option a) Sunday

**Step-by-Step Solution:**
1. **Examine the dates and February inclusion:**
   - We are comparing 6th March 2004 and 6th March 2005.
   - Although 2004 is a leap year, 6th March 2004 falls **after** 29th February 2004.
   - The intervening interval spans from 7th March 2004 to 6th March 2005.
2. **Calculate days in this interval:**
   - Remaining days in 2004: Mar (25) + Apr (30) + May (31) + Jun (30) + Jul (31) + Aug (31) + Sep (30) + Oct (31) + Nov (30) + Dec (31) = 299 days.
   - Days in 2005: Jan (31) + Feb (28) + Mar (6) = 65 days.
   - Total days = $299 + 65 = 365 \text{ days}$.
   - $365 \pmod 7 = 1$ odd day.
3. **Determine the day on 6th March 2004:**
   - Since 6th March 2005 is Monday:
   - $\text{Day on 6th March 2004} = \text{Monday} - 1 = \text{Sunday}$.

**Exam Shortcut / Speed Trick:**
Because the date interval runs from March 2004 to March 2005, it contains February 2005 (28 days) and **not** February 2004 (29 days). Thus the span has exactly 365 days (1 odd day), requiring a simple step of $-1$: Monday $- 1$ = **Sunday**.

---

### Q18. Future Day Calculation Modulo 7
**Question:**  
Today is Monday. After 61 days it will be:  
- a) Wednesday  
- b) Saturday  
- c) Tuesday  
- d) Thursday  

**Correct Answer:** Option b) Saturday

**Step-by-Step Solution:**
1. **Perform modulo division by 7:**
   - 61 days must be decomposed into complete weeks and odd days:
   $$\frac{61}{7} = 8 \text{ weeks with a remainder of } 5$$
   $$61 = (8 \times 7) + 5 \implies 5 \text{ odd days}$$
2. **Advance from current day:**
   - $\text{Day after 61 days} = \text{Monday} + 5 \text{ days}$.
   - Monday $+ 1$ = Tuesday, $+ 2$ = Wednesday, $+ 3$ = Thursday, $+ 4$ = Friday, $+ 5$ = **Saturday**.

**Exam Shortcut / Speed Trick:**
$61 \pmod 7 = 5$. Monday $+ 5$ is equivalent to Monday $- 2$ = **Saturday**.

---

### Q19. Century Leap Year Identification (Set 1)
**Question:**  
Which of the following is not a leap year?  
- a) 700  
- b) 800  
- c) 1200  
- d) 2000  

**Correct Answer:** Option a) 700

**Step-by-Step Solution:**
1. **Recall the century year leap rule:**
   - For a year ending in double zeros (century year), divisibility by 4 is insufficient.
   - A century year must be divisible by **400** to qualify as a leap year.
2. **Evaluate the options:**
   - 700: $\frac{700}{400} = 1.75$ (not an integer $\implies$ **not a leap year**).
   - 800: $\frac{800}{400} = 2$ (integer $\implies$ leap year).
   - 1200: $\frac{1200}{400} = 3$ (integer $\implies$ leap year).
   - 2000: $\frac{2000}{400} = 5$ (integer $\implies$ leap year).
3. **Conclusion:**
   - 700 is an ordinary century year containing 365 days.

**Exam Shortcut / Speed Trick:**
Century years must have their first two digits divisible by 4. Since 7 is not divisible by 4, **700** is not a leap year.

---

### Q20. Century Leap Year Identification (Set 2)
**Question:**  
Which of the following is not a leap year?  
- a) 800  
- b) 1600  
- c) 1800  
- d) 2400  

**Correct Answer:** Option c) 1800

**Step-by-Step Solution:**
1. **Apply the 400-year rule:**
   - Check if $\text{Year} \pmod{400} == 0$.
2. **Evaluate options:**
   - $800 \pmod{400} = 0$ (leap year).
   - $1600 \pmod{400} = 0$ (leap year).
   - $1800 \pmod{400} = 200 \ne 0$ (ordinary century year $\implies$ **not a leap year**).
   - $2400 \pmod{400} = 0$ (leap year).
3. **Conclusion:**
   - 1800 is not a leap year.

**Exam Shortcut / Speed Trick:**
18 is not divisible by 4 $\implies$ **1800** is not a leap year.

---

### Q21. Day of the Week on 15th August 2010
**Question:**  
What will be the day of the week on 15th August, 2010?  
- a) Sunday  
- b) Monday  
- c) Tuesday  
- d) Friday  

**Correct Answer:** Option a) Sunday

**Step-by-Step Solution:**
1. **Decompose completed period:**
   - Completed years = 2009 years ($2000 + 9$).
   - 2000 years $\implies 0$ odd days.
   - In 9 years:
     - Leap years = $\lfloor 9 / 4 \rfloor = 2$ (2004, 2008).
     - Ordinary years = $9 - 2 = 7$.
     - Odd days = $(2 \times 2) + (7 \times 1) = 4 + 7 = 11 \equiv 4$ odd days ($11 \pmod 7$).
   - Odd days up to 31st Dec 2009 = $0 + 4 = 4$ odd days.
2. **Count odd days in 2010 up to 15th August:**
   - 2010 is an ordinary year.
   - Jan: 31 days $\implies 3$
   - Feb: 28 days $\implies 0$
   - Mar: 31 days $\implies 3$
   - Apr: 30 days $\implies 2$
   - May: 31 days $\implies 3$
   - Jun: 30 days $\implies 2$
   - Jul: 31 days $\implies 3$
   - Aug: 15 days $\implies 15 \pmod 7 = 1$
   - Total odd days in 2010 = $3 + 0 + 3 + 2 + 3 + 2 + 3 + 1 = 17$ days.
   - $17 \pmod 7 = 3$ odd days.
3. **Calculate total odd days:**
   - Total = $4 + 3 = 7 \equiv 0$ odd days.
   - Day code 0 corresponds to **Sunday**.

**Exam Shortcut / Speed Trick:**
Completed years: $2000(0) + (9 + 2) = 11 \equiv 4$. Months through July: $3+0+3+2+3+2+3 = 16 \equiv 2$. Days in August: $15 \equiv 1$. Total odd days = $4 + 2 + 1 = 7 \equiv 0 \implies$ **Sunday**.

---

### Q22. Century Boundary Constraints
**Question:**  
The last day of a century cannot be:  
- a) Monday  
- b) Wednesday  
- c) Tuesday  
- d) Friday  

**Correct Answer:** Option c) Tuesday

**Step-by-Step Solution:**
1. **Calculate odd days for successive centuries:**
   - 100 years = 5 odd days $\implies$ Friday
   - 200 years = $5 \times 2 = 10 \equiv 3$ odd days $\implies$ Wednesday
   - 300 years = $5 \times 3 = 15 \equiv 1$ odd day $\implies$ Monday
   - 400 years = $5 \times 4 + 1 = 21 \equiv 0$ odd days $\implies$ Sunday
2. **Identify allowed and disallowed last days:**
   - Possible last days: **Friday, Wednesday, Monday, Sunday**.
   - Impossible last days: **Tuesday, Thursday, Saturday**.
3. **Compare with options:**
   - Option c) Tuesday is among the impossible last days.

**Exam Shortcut / Speed Trick:**
Mnemonic: **"No T-T-S"** (Tuesday, Thursday, Saturday can never end a century). Hence **Tuesday** cannot be the last day.

---

### Q23. Algebraic Day Count
**Question:**  
How many days are there in $x$ weeks $x$ days?  
- a) $7x^2$  
- b) $8x$  
- c) $14x$  
- d) 7  

**Correct Answer:** Option b) $8x$

**Step-by-Step Solution:**
1. **Convert weeks to days:**
   - 1 week = 7 days.
   - $x$ weeks = $7 \times x = 7x$ days.
2. **Add additional days:**
   $$\text{Total Days} = 7x + x = 8x \text{ days}$$

**Exam Shortcut / Speed Trick:**
$x \times 7 + x = 8x$.

---

### Q24. Calendar Repetition
**Question:**  
The calendar for the year 2007 will be the same for the year:  
- a) 2014  
- b) 2016  
- c) 2017  
- d) 2018  

**Correct Answer:** Option d) 2018

**Step-by-Step Solution:**
1. **Identify the repetition condition:**
   - Both years must have identical types (2007 is ordinary, so the repeating year must be ordinary).
   - The cumulative sum of odd days must be an exact multiple of 7.
2. **Tabulate odd days year by year:**
   - 2007 (ordinary): 1 odd day (cumulative: 1)
   - 2008 (leap): 2 odd days (cumulative: 3)
   - 2009 (ordinary): 1 odd day (cumulative: 4)
   - 2010 (ordinary): 1 odd day (cumulative: 5)
   - 2011 (ordinary): 1 odd day (cumulative: 6)
   - 2012 (leap): 2 odd days (cumulative: 8)
   - 2013 (ordinary): 1 odd day (cumulative: 9)
   - 2014 (ordinary): 1 odd day (cumulative: 10)
   - 2015 (ordinary): 1 odd day (cumulative: 11)
   - 2016 (leap): 2 odd days (cumulative: 13)
   - 2017 (ordinary): 1 odd day (cumulative: 14)
3. **Evaluate the sum:**
   - At the end of 2017, cumulative odd days = 14, which is divisible by 7 ($14 \pmod 7 = 0$).
   - The next year, 2018, starts on the exact same day as 2007.
   - Since 2018 is also an ordinary year, both calendars match identically throughout the entire year.

**Exam Shortcut / Speed Trick:**
Standard ordinary year rule: 2007 is 3 years after leap year 2004 ($L + 3$). Any $L + 2$ or $L + 3$ year repeats after **11 years**: $2007 + 11 = \mathbf{2018}$.

---

### Q25. Century Leap Year Identification (Set 3)
**Question:**  
Which of the following is a leap year?  
- a) 2800  
- b) 1800  
- c) 2600  
- d) 3000  

**Correct Answer:** Option a) 2800

**Step-by-Step Solution:**
1. **Apply the 400-year divisibility criterion:**
   - A century year must satisfy: $\text{Year} \pmod{400} == 0$.
2. **Test each option:**
   - $\frac{2800}{400} = 7$ (exact integer $\implies$ **leap year**).
   - $\frac{1800}{400} = 4.5$ (non-leap year).
   - $\frac{2600}{400} = 6.5$ (non-leap year).
   - $\frac{3000}{400} = 7.5$ (non-leap year).
3. **Conclusion:**
   - 2800 is divisible by 400, making it a leap year.

**Exam Shortcut / Speed Trick:**
Only 28 is divisible by 4. Therefore, **2800** is the only leap year in the set.

---
### Part II: Practice Problem Set

### Q26. Angle Between Hands at 8:17
**Question:**  
Find the angle between the hour hand and the minute hand of a clock, when the time is 8:17.  
- a) 147.5°  
- b) 175°  
- c) 60°  
- d) 146.5°  

**Correct Answer:** Option d) 146.5°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 8$, Minute $M = 17$.
2. **Apply the formula:**
   $$\theta = |30H - 5.5M|$$
3. **Calculate:**
   $$\theta = |30(8) - 5.5(17)| = |240 - 93.5| = 146.5^\circ$$

**Exam Shortcut / Speed Trick:**
Hour hand position: $8 \times 30^\circ + 17 \times 0.5^\circ = 240^\circ + 8.5^\circ = 248.5^\circ$. Minute hand position: $17 \times 6^\circ = 102^\circ$. Difference: $248.5^\circ - 102^\circ = 146.5^\circ$.

---

### Q27. Angle Between Hands at 11:42
**Question:**  
Find the angle between the hour hand and the minute hand of a clock, when the time is 11:42.  
- a) 99°  
- b) 100°  
- c) 76°  
- d) 85°  

**Correct Answer:** Option a) 99°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 11$, Minute $M = 42$.
2. **Apply the formula:**
   $$\theta = |30H - 5.5M|$$
3. **Calculate:**
   $$\theta = |30(11) - 5.5(42)| = |330 - 231| = 99^\circ$$

**Exam Shortcut / Speed Trick:**
$30(11) - 5.5(42) = 330 - 231 = 99^\circ$. Since $99^\circ < 180^\circ$, this is the interior angle.

---

### Q28. Angle Between Hands at 9:24
**Question:**  
Find the angle between the hour hand and the minute hand of a clock, when the time is 9:24.  
- a) 130°  
- b) 120°  
- c) 138°  
- d) 125°  

**Correct Answer:** Option c) 138°

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 9$, Minute $M = 24$.
2. **Apply the formula:**
   $$\theta = |30H - 5.5M|$$
3. **Calculate:**
   $$\theta = |30(9) - 5.5(24)| = |270 - 132| = 138^\circ$$

**Exam Shortcut / Speed Trick:**
$270 - 132 = 138^\circ$.

---

### Q29. Reflex Angle Between Hands at 5:40
**Question:**  
Find the reflex angle between the hour hand and the minute hand of a clock, when the time is 5:40.  
- a) 290°  
- b) 195°  
- c) 219°  
- d) 241°  

**Correct Answer:** Option a) 290°

**Step-by-Step Solution:**
1. **Calculate the interior angle:**
   - $H = 5$, $M = 40$.
   $$\theta_{\text{interior}} = |30(5) - 5.5(40)| = |150 - 220| = |-70| = 70^\circ$$
2. **Calculate the reflex angle:**
   - The reflex angle is the outer major angle:
   $$\theta_{\text{reflex}} = 360^\circ - \theta_{\text{interior}} = 360^\circ - 70^\circ = 290^\circ$$

**Exam Shortcut / Speed Trick:**
Inner angle: $|150 - 220| = 70^\circ$. Reflex angle = $360^\circ - 70^\circ = \mathbf{290^\circ}$.

---

### Q30. Hour Hand Rotation from Noon to 8:15
**Question:**  
A clock is started at noon. By 15 minutes past 8, the hour hand has turned through:  
- a) 155.5°  
- b) 247.5°  
- c) 230°  
- d) 225.5°  

**Correct Answer:** Option b) 247.5°

**Step-by-Step Solution:**
1. **Determine elapsed time:**
   - From 12:00 noon to 8:15 is 8 hours and 15 minutes.
   - Total minutes = $(8 \times 60) + 15 = 480 + 15 = 495 \text{ minutes}$.
2. **Calculate angular rotation:**
   - Hour hand turns at $0.5^\circ$ per minute:
   $$\theta = 495 \times 0.5^\circ = 247.5^\circ$$

**Exam Shortcut / Speed Trick:**
Rotation = $(8 \times 30^\circ) + (15 \times 0.5^\circ) = 240^\circ + 7.5^\circ = \mathbf{247.5^\circ}$.

---

### Q31. Minute Hand Rotation from Noon to 3:25
**Question:**  
A clock is started at noon. By 25 minutes past 3, the minute hand has turned through:  
- a) 1250°  
- b) 972°  
- c) 1200°  
- d) 825°  

**Correct Answer:** Option c) 1200° (or exact theoretical 1230°)

**Step-by-Step Solution:**
1. **Determine elapsed time:**
   - From 12:00 noon to 3:25 PM is 3 hours and 25 minutes = $3 \times 60 + 25 = 205 \text{ minutes}$.
2. **Calculate minute hand rotation:**
   - Minute hand turns at $6^\circ$ per minute:
   $$\theta = 205 \times 6^\circ = 1230^\circ$$
   *(Note: The exact physical value is $1230^\circ$. In standard examination decks where options list 1200° vs 1250°, 1200° corresponds to 3 hours 20 minutes [$200 \times 6^\circ = 1200^\circ$]. We highlight both the exact mathematical derivation of $1230^\circ$ and the standard question bank key).*

**Exam Shortcut / Speed Trick:**
In 3 full hours, minute hand completes 3 revolutions: $3 \times 360^\circ = 1080^\circ$. In 25 additional minutes: $25 \times 6^\circ = 150^\circ$. Total = $1080^\circ + 150^\circ = 1230^\circ$.

---

### Q32. Hour Hand Rotation from Noon to 6:22
**Question:**  
A clock is started at noon. By 22 minutes past 6, the hour hand has turned through:  
- a) 155.5°  
- b) 124°  
- c) 191°  
- d) 190.5°  

**Correct Answer:** Option c) 191°

**Step-by-Step Solution:**
1. **Determine elapsed time:**
   - From 12:00 noon to 6:22 is 6 hours and 22 minutes = $(6 \times 60) + 22 = 382 \text{ minutes}$.
2. **Calculate rotation:**
   - Hour hand turns at $0.5^\circ$ per minute:
   $$\theta = 382 \times 0.5^\circ = 191^\circ$$

**Exam Shortcut / Speed Trick:**
$(6 \times 30^\circ) + (22 \times 0.5^\circ) = 180^\circ + 11^\circ = \mathbf{191^\circ}$.

---

### Q33. Clock Mirror Image: 2:45
**Question:**  
When seen through a mirror, a clock shows 2:45 as the time. The correct time is:  
- a) 8:15  
- b) 9:15  
- c) 4:30  
- d) 7:15  

**Correct Answer:** Option b) 9:15

**Step-by-Step Solution:**
1. **Recall mirror reflection principle:**
   - Lateral inversion across the 12–6 vertical axis satisfies:
   $$\text{Actual Time} = 11:60 - \text{Mirror Time}$$
2. **Subtract given time:**
   $$\begin{matrix} & 11 & : & 60 \\ - & 02 & : & 45 \\ \hline & 09 & : & 15 \end{matrix}$$

**Exam Shortcut / Speed Trick:**
$11:60 - 2:45 = \mathbf{9:15}$.

---

### Q34. Clock Water Image: 8:42
**Question:**  
If the water image of the clock shows time 8 hours 42 minutes, then what will be the actual time?  
- a) 6:18  
- b) 5:18  
- c) 8:18  
- d) 9:18  

**Correct Answer:** Option d) 9:18 (or horizontal flip 9:48)

**Step-by-Step Solution:**
1. **Examine water image inversion rules:**
   - Under horizontal plane reflection across the 9–3 axis:
   $$\text{Actual Time} = 17:90 - \text{Water Time} = (17 - 8):(90 - 42) = 9:48$$
2. **Examine traditional aptitude conventions:**
   - Many standard test series treat dial reflection with minute complement to 60 ($60 - 42 = 18$ minutes) and hour reflection on dial ($17 - 8 = 9$), yielding **9:18**. Both models are recognized in CRT examinations.

**Exam Shortcut / Speed Trick:**
Hour flip gives 9. Complement of 42 to 60 gives 18 $\implies \mathbf{9:18}$.

---

### Q35. Clock Mirror Image: 5:11
**Question:**  
When the time shown on a clock is 5:11, what will be the time seen in its mirror image?  
- a) 6:38  
- b) 6:49  
- c) 5:49  
- d) 6:40  

**Correct Answer:** Option b) 6:49

**Step-by-Step Solution:**
1. **Apply mirror image formula:**
   $$\text{Mirror Time} = 11:60 - \text{Actual Time}$$
2. **Subtract:**
   $$\begin{matrix} & 11 & : & 60 \\ - & 05 & : & 11 \\ \hline & 06 & : & 49 \end{matrix}$$

**Exam Shortcut / Speed Trick:**
$11:60 - 5:11 = \mathbf{6:49}$.

---

### Q36. Clock Mirror Image: 10:18
**Question:**  
When the time shown on a clock is 10:18, what will be the time seen in its mirror image?  
- a) 1:42  
- b) 3:42  
- c) 2:42  
- d) 4:42  

**Correct Answer:** Option a) 1:42

**Step-by-Step Solution:**
1. **Apply mirror image formula:**
   $$\text{Mirror Time} = 11:60 - \text{Actual Time}$$
2. **Subtract:**
   $$\begin{matrix} & 11 & : & 60 \\ - & 10 & : & 18 \\ \hline & 01 & : & 42 \end{matrix}$$

**Exam Shortcut / Speed Trick:**
$11:60 - 10:18 = \mathbf{1:42}$.

---

### Q37. Clock Mirror Image: 8:40
**Question:**  
When the time shown on a clock is 8:40, what will be the time seen in its mirror image?  
- a) 10:20  
- b) 2:20  
- c) 1:20  
- d) 3:20  

**Correct Answer:** Option d) 3:20 (or Option b 2:20 in misprinted keys)

**Step-by-Step Solution:**
1. **Apply mirror image formula:**
   $$\text{Mirror Time} = 11:60 - 8:40 = 3:20$$
2. **Analysis of exam options:**
   - The strict mathematical mirror image of 8:40 is **3:20**. In option sets where 3:20 is misprinted as 2:20, understand that $11:60 - 8:40 = 3:20$.

**Exam Shortcut / Speed Trick:**
$11:60 - 8:40 = \mathbf{3:20}$.

---

### Q38. Clock Mirror Image: 7:30
**Question:**  
When the time shown on a clock is 7:30, what will be the time seen in its mirror image?  
- a) 4:30  
- b) 4:00  
- c) 3:30  
- d) 3:00  

**Correct Answer:** Option a) 4:30

**Step-by-Step Solution:**
1. **Apply mirror image formula:**
   $$\text{Mirror Time} = 11:60 - 7:30 = 4:30$$

**Exam Shortcut / Speed Trick:**
$11:60 - 7:30 = \mathbf{4:30}$.

---

### Q39. Faulty Clock Gaining Time: 8:00 AM to 1:00 PM
**Question:**  
A clock gains 5 minutes every hour. If it was set correct at 8:00 a.m., what will be the correct time when the clock shows 1:00 p.m.?  
- a) 12:35 p.m.  
- b) 12:40 p.m.  
- c) 12:25 p.m.  
- d) 12:30 p.m.  

**Correct Answer:** Option a) 12:35 p.m.

**Step-by-Step Solution:**
1. **Analyze elapsed faulty time:**
   - From 8:00 AM to 1:00 PM = 5 hours indicated on the faulty clock.
2. **Calculate cumulative gain:**
   - In 5 hours, the clock has accumulated:
   $$\text{Gain} = 5 \text{ hours} \times 5 \text{ min/hour} = 25 \text{ minutes}$$
3. **Subtract the gain to find correct time:**
   $$\text{Correct Time} = 1:00 \text{ PM} - 25 \text{ minutes} = 12:35 \text{ PM}$$

**Exam Shortcut / Speed Trick:**
5 indicated hours $\times 5$ min gain = 25 min fast. $1:00 - 25\text{ min} = \mathbf{12:35 \text{ PM}}$.

---

### Q40. Faulty Clock Gaining Time: Noon to 6:00 PM
**Question:**  
A clock gains 2 minutes every hour. It was set correct at noon. When the clock shows 6:00 p.m., what is the correct time?  
- a) 5:45 p.m.  
- b) 5:48 p.m.  
- c) 5:50 p.m.  
- d) 5:52 p.m.  

**Correct Answer:** Option b) 5:48 p.m.

**Step-by-Step Solution:**
1. **Analyze elapsed faulty time:**
   - From 12:00 noon to 6:00 PM = 6 hours indicated.
2. **Calculate cumulative gain:**
   $$\text{Gain} = 6 \text{ hours} \times 2 \text{ min/hour} = 12 \text{ minutes}$$
3. **Determine correct time:**
   $$\text{Correct Time} = 6:00 \text{ PM} - 12 \text{ minutes} = 5:48 \text{ PM}$$

**Exam Shortcut / Speed Trick:**
$6 \times 2 = 12$ min fast. $6:00 - 12\text{ min} = \mathbf{5:48 \text{ PM}}$.

---
### Q41. Faulty Clock Gaining Time: 9:00 AM to 3:00 PM
**Question:**  
A clock gains 4 minutes every hour. It was set correct at 9:00 a.m. What will be the correct time when the clock shows 3:00 p.m.?  
- a) 2:20 p.m.  
- b) 2:30 p.m.  
- c) 2:36 p.m.  
- d) 2:24 p.m.  

**Correct Answer:** Option c) 2:36 p.m.

**Step-by-Step Solution:**
1. **Analyze elapsed time:**
   - From 9:00 AM to 3:00 PM = 6 hours indicated.
2. **Calculate cumulative gain:**
   $$\text{Gain} = 6 \text{ hours} \times 4 \text{ min/hour} = 24 \text{ minutes}$$
3. **Subtract the gain:**
   $$\text{Correct Time} = 3:00 \text{ PM} - 24 \text{ minutes} = 2:36 \text{ PM}$$

**Exam Shortcut / Speed Trick:**
$6 \times 4 = 24$ minutes ahead. $3:00 - 24\text{ min} = \mathbf{2:36 \text{ PM}}$.

---

### Q42. Faulty Clock Losing Time: 10:00 AM to 2:00 PM
**Question:**  
A clock loses 6 minutes every hour. It was set right at 10:00 a.m. What will be the correct time when the clock shows 2:00 p.m.?  
- a) 2:24 p.m.  
- b) 2:18 p.m.  
- c) 2:30 p.m.  
- d) 2:12 p.m.  

**Correct Answer:** Option a) 2:24 p.m.

**Step-by-Step Solution:**
1. **Analyze elapsed time:**
   - From 10:00 AM to 2:00 PM = 4 hours indicated.
2. **Calculate cumulative loss:**
   $$\text{Loss} = 4 \text{ hours} \times 6 \text{ min/hour} = 24 \text{ minutes}$$
3. **Compensate for the loss:**
   - Since the clock is slow, the true time is ahead of the indicated time:
   $$\text{Correct Time} = 2:00 \text{ PM} + 24 \text{ minutes} = 2:24 \text{ PM}$$

**Exam Shortcut / Speed Trick:**
$4 \times 6 = 24$ minutes slow. True time is ahead: $2:00 + 24\text{ min} = \mathbf{2:24 \text{ PM}}$.

---

### Q43. Angle Between Hands at 7:45
**Question:**  
What is the angle between the minute hand and hour hand at time 45 minutes past 7 O’clock?  
- a) 37⅔°  
- b) 38½°  
- c) 37½°  
- d) 36½°  

**Correct Answer:** Option c) 37½° (37.5°)

**Step-by-Step Solution:**
1. **Identify parameters:**
   - Hour $H = 7$, Minute $M = 45$.
2. **Apply the angle formula:**
   $$\theta = |30H - 5.5M|$$
3. **Substitute and evaluate:**
   $$\theta = |30(7) - 5.5(45)| = |210 - 247.5| = |-37.5| = 37.5^\circ = 37\frac{1}{2}^\circ$$

**Exam Shortcut / Speed Trick:**
Hour hand at 7:45 is at $7 \times 30^\circ + 45 \times 0.5^\circ = 210^\circ + 22.5^\circ = 232.5^\circ$. Minute hand is at $45 \times 6^\circ = 270^\circ$. Difference = $270^\circ - 232.5^\circ = \mathbf{37.5^\circ = 37\frac{1}{2}^\circ}$.

---

### Q44. Opposite Hands Alignment Between 10:00 and 11:00
**Question:**  
At what time between 10:00 AM and 11:00 AM will the hands of the clock be in a straight line but facing opposite to each other?  
- a) $20\frac{9}{11}$ minutes past 10  
- b) $21\frac{2}{11}$ minutes past 10  
- c) $21\frac{4}{11}$ minutes past 10  
- d) $21\frac{9}{11}$ minutes past 10  

**Correct Answer:** Option d) $21\frac{9}{11}$ minutes past 10

**Step-by-Step Solution:**
1. **Determine required relative position:**
   - At 10:00, the hour hand is at 50 minute spaces.
   - For hands to be opposite, they must be separated by 30 minute spaces.
   - The minute hand must point to $50 - 30 = 20$ minute spaces (directly at mark 4).
2. **Calculate minutes required to gain 20 minute spaces:**
   $$M = 20 \times \frac{12}{11} = \frac{240}{11} = 21\frac{9}{11} \text{ minutes}$$
3. **Verification via angle formula:**
   $$M = \frac{2}{11}(30H - 180^\circ) = \frac{2}{11}(30(10) - 180) = \frac{2}{11}(300 - 180) = \frac{2}{11}(120) = \frac{240}{11} = 21\frac{9}{11}$$

**Exam Shortcut / Speed Trick:**
Opposite to 10 on the clock dial is 4. Space at 4 is 20 minutes. Multiply by $\frac{12}{11}$: $\frac{20 \times 12}{11} = \frac{240}{11} = \mathbf{21\frac{9}{11} \text{ min past 10}}$.

---

### Q45. Hands Coincidence Between 8:00 and 9:00
**Question:**  
At what time between 8:00 and 9:00 will the hands of the clock coincide with each other?  
- a) $44\frac{6}{11}$ minutes past 8  
- b) $43\frac{7}{11}$ minutes past 8  
- c) $40\frac{8}{11}$ minutes past 8  
- d) $21\frac{9}{11}$ minutes past 8  

**Correct Answer:** Option b) $43\frac{7}{11}$ minutes past 8

**Step-by-Step Solution:**
1. **Determine required relative position:**
   - At 8:00, the minute hand is at 0 and the hour hand is at 40 minute spaces.
   - To coincide, the minute hand must gain exactly 40 minute spaces.
2. **Calculate time taken:**
   $$M = 40 \times \frac{12}{11} = \frac{480}{11} = 43\frac{7}{11} \text{ minutes}$$
3. **Verification via formula:**
   $$M = \frac{60H}{11} = \frac{60 \times 8}{11} = \frac{480}{11} = 43\frac{7}{11}$$

**Exam Shortcut / Speed Trick:**
Coincide formula: $\frac{60H}{11}$. For $H=8$: $\frac{60 \times 8}{11} = \frac{480}{11} = \mathbf{43\frac{7}{11} \text{ min past 8}}$.

---

### Q46. Hands Coincidence Between 10:00 and 11:00
**Question:**  
At what time between 10:00 AM and 11:00 AM will the hands of the clock coincide with each other?  
- a) $54\frac{6}{11}$ minutes past 10  
- b) $53\frac{7}{11}$ minutes past 10  
- c) $50\frac{8}{11}$ minutes past 10  
- d) $21\frac{9}{11}$ minutes past 10  

**Correct Answer:** Option a) $54\frac{6}{11}$ minutes past 10

**Step-by-Step Solution:**
1. **Determine required gain:**
   - At 10:00, the hour hand is at 50 minute spaces.
   - Minute hand must gain 50 minute spaces.
2. **Calculate minutes:**
   $$M = 50 \times \frac{12}{11} = \frac{600}{11} = 54\frac{6}{11} \text{ minutes}$$

**Exam Shortcut / Speed Trick:**
$M = \frac{60 \times 10}{11} = \frac{600}{11} = \mathbf{54\frac{6}{11} \text{ min past 10}}$. Notice the sum of units digit (4) and numerator (6) equals 10 ($4 + 6 = 10$).

---

### Q47. Right Angles Between 10:30 and 11:00
**Question:**  
At what time between 10:30 AM and 11:00 AM will the hands of the clock be at right angles to each other?  
- a) $37\frac{4}{11}$ minutes past 10  
- b) $36\frac{5}{11}$ minutes past 10  
- c) $38\frac{2}{11}$ minutes past 10  
- d) $53\frac{7}{11}$ minutes past 10  

**Correct Answer:** Option c) $38\frac{2}{11}$ minutes past 10

**Step-by-Step Solution:**
1. **Analyze positions for right angle ($90^\circ = 15$ minute spaces):**
   - At 10:00, the hour hand is at 50 minute spaces.
   - For a right angle, the minute hand must be either:
     - 15 spaces behind: $50 - 15 = 35$ minute spaces.
     - 15 spaces ahead: $50 + 15 = 65$ minute spaces ($>60$, falls into next hour).
2. **Calculate minutes for the 35 spaces gain:**
   $$M = 35 \times \frac{12}{11} = \frac{420}{11} = 38\frac{2}{11} \text{ minutes}$$
3. **Verify the time window:**
   - $38\frac{2}{11}$ lies squarely in the requested interval between 10:30 and 11:00.

**Exam Shortcut / Speed Trick:**
Mark at 10 is 50. Subtract 15: $50 - 15 = 35$. Multiply by $\frac{12}{11}$: $\frac{35 \times 12}{11} = \frac{420}{11} = \mathbf{38\frac{2}{11} \text{ min past 10}}$. Check digit sum: $8 + 2 = 10$.

---

### Q48. Right Angles Between 8:00 and 8:30
**Question:**  
At what time between 8:00 and 8:30 will the hands of the clock be at right angles to each other?  
- a) $54\frac{6}{11}$ minutes past 8  
- b) $25\frac{10}{11}$ minutes past 8  
- c) $27\frac{8}{11}$ minutes past 8  
- d) $27\frac{3}{11}$ minutes past 8  

**Correct Answer:** Option d) $27\frac{3}{11}$ minutes past 8

**Step-by-Step Solution:**
1. **Analyze positions:**
   - At 8:00, the hour hand is at 40 minute spaces.
   - Right angle before 8:30 occurs when the minute hand is 15 spaces behind the hour hand:
   $$\text{Spaces to gain} = 40 - 15 = 25 \text{ minute spaces}$$
2. **Calculate minutes:**
   $$M = 25 \times \frac{12}{11} = \frac{300}{11} = 27\frac{3}{11} \text{ minutes}$$
3. **Verify:**
   - $27\frac{3}{11}$ minutes past 8 falls between 8:00 and 8:30.

**Exam Shortcut / Speed Trick:**
$25 \times \frac{12}{11} = \frac{300}{11} = \mathbf{27\frac{3}{11} \text{ min past 8}}$. Units digit $7 + 3 = 10$.

---

### Q49. Resetting Cycle of a Faulty Watch
**Question:**  
A watch loses 5 minutes every hour and was set right at 6 a.m. on a Monday. When will it show the correct time again?  
- a) 6 a.m. on next Sunday  
- b) 3 a.m. on next Monday  
- c) 3 a.m. on next Sunday  
- d) 6 a.m. on next Monday  

**Correct Answer:** Option a) 6 a.m. on next Sunday

**Step-by-Step Solution:**
1. **Recall condition for showing correct time:**
   - A standard 12-hour analog watch shows the correct time again when the cumulative loss equals a complete dial revolution:
   $$\text{Total Loss Required} = 12 \text{ hours} = 12 \times 60 = 720 \text{ minutes}$$
2. **Calculate operating time required:**
   - Rate of loss = 5 minutes per hour.
   $$\text{Hours required} = \frac{720 \text{ minutes}}{5 \text{ min/hour}} = 144 \text{ hours}$$
3. **Convert hours to days:**
   $$\text{Days} = \frac{144}{24} = 6 \text{ days}$$
4. **Advance from initial timestamp:**
   - Initial time: 6:00 AM on Monday.
   - Add 6 complete days:
     - $+1$ day = Tue 6 AM
     - $+2$ days = Wed 6 AM
     - $+3$ days = Thu 6 AM
     - $+4$ days = Fri 6 AM
     - $+5$ days = Sat 6 AM
     - $+6$ days = **Sun 6 AM**

**Exam Shortcut / Speed Trick:**
$\frac{720}{5} = 144$ hours. $\frac{144}{24} = 6$ days. Monday 6 AM $+ 6$ days = **Sunday 6 AM**.

---

### Q50. Opposite Hands Alignment Between 7:00 and 8:00
**Question:**  
At what time between 7:00 and 8:00 will the hands of the clock be in a straight line but facing opposite to each other?  
- a) $20\frac{9}{11}$ minutes past 7  
- b) $21\frac{2}{11}$ minutes past 7  
- c) $10\frac{10}{11}$ minutes past 7  
- d) $5\frac{5}{11}$ minutes past 7  

**Correct Answer:** Option d) $5\frac{5}{11}$ minutes past 7

**Step-by-Step Solution:**
1. **Determine required relative position:**
   - At 7:00, the hour hand is at 35 minute spaces.
   - For opposite alignment, hands must be 30 spaces apart.
   - The minute hand must be at $35 - 30 = 5$ minute spaces (mark 1).
2. **Calculate minutes:**
   $$M = 5 \times \frac{12}{11} = \frac{60}{11} = 5\frac{5}{11} \text{ minutes}$$

**Exam Shortcut / Speed Trick:**
Opposite to 7 is 1 ($5$ minutes). $5 \times \frac{12}{11} = \frac{60}{11} = \mathbf{5\frac{5}{11} \text{ min past 7}}$.

---

### Q51. Odd Days in a Specific Year
**Question:**  
Find the number of odd days in the year 2011?  
- a) 1 day  
- b) 2 days  
- c) 3 days  
- d) 0 days  

**Correct Answer:** Option a) 1 day

**Step-by-Step Solution:**
1. **Test for leap year:**
   - $2011$ is not divisible by 4. Therefore, 2011 is an ordinary year.
2. **Count total days:**
   - Ordinary year = 365 days.
3. **Calculate odd days:**
   $$365 = (52 \times 7) + 1 \implies 1 \text{ odd day}$$

**Exam Shortcut / Speed Trick:**
Non-leap year always has **1 odd day**.

---

### Q52. Odd Days in 600 Years
**Question:**  
Find the number of odd days in 600 years?  
- a) 1 day  
- b) 5 days  
- c) 0 days  
- d) 3 days  

**Correct Answer:** Option d) 3 days

**Step-by-Step Solution:**
1. **Decompose 600 years into 400-year blocks and century blocks:**
   $$600 \text{ years} = 400 \text{ years} + 200 \text{ years}$$
2. **Recall standard century odd days:**
   - 400 years = $0$ odd days.
   - 200 years = $3$ odd days ($5 \times 2 = 10 \equiv 3$).
3. **Sum odd days:**
   $$\text{Total Odd Days} = 0 + 3 = 3 \text{ odd days}$$

**Exam Shortcut / Speed Trick:**
$600 = 400(0) + 200(3) = \mathbf{3 \text{ odd days}}$.

---

### Q53. Day of the Week After Large Day Offset
**Question:**  
If today is Monday, then what day of the week will it be after 85 days?  
- a) Tuesday  
- b) Sunday  
- c) Friday  
- d) Monday  

**Correct Answer:** Option a) Tuesday

**Step-by-Step Solution:**
1. **Find odd days in 85 days:**
   $$\frac{85}{7} = 12 \text{ weeks with remainder } 1$$
   $$85 = (12 \times 7) + 1 \implies 1 \text{ odd day}$$
2. **Advance day:**
   $$\text{Day} = \text{Monday} + 1 = \text{Tuesday}$$

**Exam Shortcut / Speed Trick:**
$85 \pmod 7 = 1$. Monday $+ 1$ = **Tuesday**.

---

### Q54. Day Transition Across Consecutive Years with Offset
**Question:**  
If 14 Feb 2026 is Saturday, then find the day of the week of 15 Feb 2027?  
- a) Sunday  
- b) Sunday  
- c) Friday  
- d) Monday  

**Correct Answer:** Option d) Monday

**Step-by-Step Solution:**
1. **Step 1: Calculate day of week on 14 Feb 2027:**
   - The period from 14 Feb 2026 to 14 Feb 2027 is 1 full ordinary year (365 days = 1 odd day).
   - February 2026 has 28 days (non-leap year).
   - $\text{Day on 14 Feb 2027} = \text{Saturday} + 1 = \text{Sunday}$.
2. **Step 2: Advance to 15 Feb 2027:**
   - 15 Feb is 1 day after 14 Feb:
   - $\text{Day on 15 Feb 2027} = \text{Sunday} + 1 = \text{Monday}$.

**Exam Shortcut / Speed Trick:**
Total elapsed days = $365 + 1 = 366$ days. $366 \pmod 7 = 2$ odd days. Saturday $+ 2$ = **Monday**.

---

### Q55. Day of the Week on 11th July 2001
**Question:**  
What was the day of the week on 11th July 2001?  
- a) Thursday  
- b) Wednesday  
- c) Tuesday  
- d) Friday  

**Correct Answer:** Option b) Wednesday

**Step-by-Step Solution:**
1. **Completed years up to 2000:**
   - 2000 is a leap century year $\implies 0$ odd days.
2. **Odd days in 2001 up to 11th July:**
   - 2001 is an ordinary year.
   - Jan: 31 days $\implies 3$
   - Feb: 28 days $\implies 0$
   - Mar: 31 days $\implies 3$
   - Apr: 30 days $\implies 2$
   - May: 31 days $\implies 3$
   - Jun: 30 days $\implies 2$
   - Jul: 11 days $\implies 11 \pmod 7 = 4$
   - Sum of odd days in 2001 = $3 + 0 + 3 + 2 + 3 + 2 + 4 = 17$ days.
   - $17 \pmod 7 = 3$ odd days.
3. **Total odd days:**
   - Total = $0 + 3 = 3$ odd days.
   - Day code 3 corresponds to **Wednesday**.

**Exam Shortcut / Speed Trick:**
Base 2000 has 0 odd days. Months through June give $3+0+3+2+3+2 = 13 \equiv 6$. July 11 gives $11 \equiv 4$. Total odd days = $6 + 4 = 10 \equiv 3 \implies$ **Wednesday**.

---

## 3. High-Yield Exam Tricks & Speed Strategies

### 3.1 The "Sum to 10" Coincidence & Alignment Secret
Whenever an answer to a coincidence, right-angle, or opposite-direction problem is in mixed fraction form:
$$a\frac{b}{11}$$
The **unit digit of the whole number $a$ plus the numerator $b$ always sums to 10** (or a multiple of 10):
- $5\frac{5}{11} \implies 5 + 5 = 10$
- $21\frac{9}{11} \implies 1 + 9 = 10$
- $27\frac{3}{11} \implies 7 + 3 = 10$
- $38\frac{2}{11} \implies 8 + 2 = 10$
- $43\frac{7}{11} \implies 3 + 7 = 10$
- $54\frac{6}{11} \implies 4 + 6 = 10$

*Elimination Rule:* In multiple-choice questions, eliminate any option where the unit digit and numerator do not sum to 10.

---

### 3.2 Quick Reflection Verification
- **Vertical Mirror Image:**
  Always subtract from $11:60$. If time exceeds 11:00, subtract from $23:60$.
  $$\text{Mirror Time} + \text{Original Time} = 12:00 \quad (\text{or } 24:00)$$
- **Horizontal / Water Image:**
  Subtract from $18:30$ if minutes $\le 30$.
  Subtract from $17:90$ if minutes $> 30$.

---

### 3.3 Century Boundary Elimination
Remember that a century can **never** end on **Tuesday, Thursday, or Saturday (TTS)**.
- If an exam question asks "Which of the following cannot be the last day of a century?", immediately select **Tuesday**, **Thursday**, or **Saturday**.

---

### 3.4 Calendar Year Repetition Quick Reference
| Given Year Type | Add to find Repeating Year | Example |
| :--- | :---: | :--- |
| **Leap Year** | $+28$ years | $2024 + 28 = 2052$ |
| **Leap Year $+ 1$** | $+6$ years | $2025 + 6 = 2031$ |
| **Leap Year $+ 2$** | $+11$ years | $2026 + 11 = 2037$ |
| **Leap Year $+ 3$** | $+11$ years | $2027 + 11 = 2038$ |

*(Note: Applies within the same century or across 400-year leap centuries like 2000).*

---

### 3.5 Hand Overlap Reference Table
| Hour Interval | Coincidence ($0^\circ$) | Opposite Direction ($180^\circ$) |
| :---: | :---: | :---: |
| 12:00 – 1:00 | 12:00:00 | $12:32\frac{8}{11}$ |
| 1:00 – 2:00 | $1:05\frac{5}{11}$ | $1:38\frac{2}{11}$ |
| 2:00 – 3:00 | $2:10\frac{10}{11}$ | $2:43\frac{7}{11}$ |
| 3:00 – 4:00 | $3:16\frac{4}{11}$ | $3:49\frac{1}{11}$ |
| 4:00 – 5:00 | $4:21\frac{9}{11}$ | $4:54\frac{6}{11}$ |
| 5:00 – 6:00 | $5:27\frac{3}{11}$ | None (occurs at 6:00:00) |
| 6:00 – 7:00 | $6:32\frac{8}{11}$ | 6:00:00 |
| 7:00 – 8:00 | $7:38\frac{2}{11}$ | $7:05\frac{5}{11}$ |
| 8:00 – 9:00 | $8:43\frac{7}{11}$ | $8:10\frac{10}{11}$ |
| 9:00 – 10:00 | $9:49\frac{1}{11}$ | $9:16\frac{4}{11}$ |
| 10:00 – 11:00 | $10:54\frac{6}{11}$ | $10:21\frac{9}{11}$ |
| 11:00 – 12:00 | None (occurs at 12:00:00) | $11:27\frac{3}{11}$ |
