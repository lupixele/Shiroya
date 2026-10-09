# 02. Pipes and Cisterns

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Inlets, outlets and net rate
An **inlet** fills a tank; an **outlet** empties it. Treat a complete tank as **1**.

**Formulas**
- **Inlet rate = +1/filling time**.
- **Outlet rate = −1/emptying time**.
- **Net rate = sum(inlets) − sum(outlets)**.
- **Time = 1/net rate** when net rate is positive and the tank starts empty.
- If net rate is negative, a **full** tank empties in `1/|net rate|`.
- Work done after `t` hours = **t × net rate**, as long as the tank has not already filled/emptied.

### 1.2 Opening and closing pipes
Calculate how much has been filled before the change; then use the **new** combined rate on the remaining part.

### 1.3 Liquid proportions from multiple inlets
If each pipe delivers a different liquid and all run simultaneously for `t` minutes before the tank fills, quantity from pipe A is `t/A` tank volumes. **Fraction of liquid A = its rate / sum of inlet rates.**

## 2. Questions and answers
**Q1 (PPT).** A fills in 20 h; B fills in 30 h. Together?
**Answer:** `1/20+1/30=1/12`; **12 h**.

**Q2 (PPT).** A fills in 5 h, B in 6 h, C empties in 12 h.
**Answer:** `1/5+1/6−1/12=(12+10−5)/60 =17/60`. **60/17 h = 3 9/17 h**.

**Q3 (PPT).** Pipe fills a tank in 5 h; after 2 h what fraction is full?
**Answer:** `2×1/5 = 2/5`.

**Q4 (PPT).** A, B and C fill in 30, 20 and 10 min. Each adds a different solution. Fraction from C?
**Answer:** `rate_C/(rate_A+rate_B+rate_C)=(1/10)/(1/30+1/20+1/10)=6/11`.

**Q5 (PPT).** A fills in 10 h, B in 15 h, C empties in 30 h. All run 3 h, then C is closed. Further time?
**Answer:** Initially `1/10+1/15−1/30=2/15` tank/h. In 3 h: `2/5` done. Remaining `3/5`. A+B=`1/6` tank/h. More time=`(3/5)÷(1/6)=18/5 h` = **3 h 36 min**.

**Q6 (PPT, data sufficiency).** Inlet A takes 16 min; outlet B empties in 8 min. Both together empty a **full** tank in?
**Answer:** `1/8−1/16=1/16` tank/min; **16 min**. Both statements necessary to calculate net rate.

## 3. Tricks and tips
1. **Plus for filling, minus for draining.**
2. Use a common denominator or LCM tank volume for quick integer rates.
3. A full tank with stronger outlet **empties**; an empty tank with stronger inlet **fills**.
4. Do not use a negative final 'filling time'—identify whether the tank fills or empties.

## 4. Additional exam notes
An outlet cannot drain water from an already empty tank; watch the starting condition. A tank cannot exceed 100% capacity in ordinary questions.
