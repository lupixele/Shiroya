# 01. Time and Work

> **Study guide:** theory and formulas follow the supplied slides; worked problems labeled **PPT** are adapted from the deck, while those labeled **additional** are teaching examples. The separate slide-reference file preserves all available on-slide text and inserted images.

## 1. Theory and formulas

### 1.1 Work, rate and efficiency
A job is treated as **1 complete work**. If A completes it in 12 days, A finishes **1/12 of the job per day**. Never add the days directly; add **work rates**.

**Formulas**
- **Work = Rate × Time**; **Rate = Work / Time**.
- **One-day work = 1 / days required**.
- **Together: 1/T = 1/A + 1/B** (same job, both working all the time).
- **Two workers together: T = AB/(A+B)**.
- **Efficiency ∝ 1/time** for equal work. If efficiency A:B = 3:2, completion time A:B = 2:3.
- **LCM units:** Choose work = LCM of given times; per-day efficiency = total units / days.

### 1.2 Changing workers, shared jobs and alternate days
When someone leaves/joins, split the timeline into stages. Total completed work from every stage must be one whole job.

**Formula:** `A_rate × days_A + B_rate × days_B + ... = 1`.

For alternate days, calculate one whole cycle first, then deal with a partially completed final day.

### 1.3 Chain rule, equivalent work and wages
- For the same type of work under the same conditions: **Work ∝ number of workers × days × hours/day × efficiency**.
- To compare workloads, include every changing variable (workers, hours and efficiency).
- **Wages ratio = actual work contributed**, normally `(efficiency × days worked)` rather than just days.

## 2. Questions and answers
**Q1.** A completes a job in 20 days; B in 30. How long together?
**Answer:** `1/T = 1/20+1/30 = 5/60 = 1/12`; **12 days**.

**Q2 (PPT).** A+B = 12 days, B+C = 15 days, C+A = 20 days. A alone?
**Answer:** `(A+B)+(B+C)+(C+A) = 1/12+1/15+1/20 = 1/5` per day. So `A+B+C = 1/10`. A = `1/10 − 1/15 = 1/30`. **A alone = 30 days** (the given choices may not contain this; choose 'none').

**Q3 (PPT).** A: 20 days; B: 30 days; work together 4 days then A leaves. How much more time for B?
**Answer:** LCM 60 units; A=3/day, B=2/day; first 4 days do 20; 40 remain, so **20 more days**.

**Q4 (PPT).** A: 10 days, B: 15 days; alternate days beginning with A.
**Answer:** 30 units; A=3/day, B=2/day. Two-day cycle=5; six cycles=30. **12 days**.

**Q5 (PPT).** A: 24 days, B: 32 days, C: 64 days. All start; A leaves after 6 days, B leaves 6 days before completion.
**Answer:** 192 units; rates 8,6,3 units/day. For total `x` days: `8×6+6(x−6)+3x=192`; `x=20`. **20 days**.

**Q6 (additional).** A and B have efficiencies 4:3. If A takes 21 days, B takes how long?
**Answer:** inverse ratio; `21×4/3 = 28` days.

## 3. Tricks and tips
1. **LCM trick:** Transform fractions into whole-number daily rates before adding work.
2. **Leaving trick:** Write one term per worker and use their *actual* days.
3. **Last-day trick:** When alternating, stop at full cycles and check who works on the last incomplete day.
4. **Sanity check:** Two positive workers together should finish faster than either alone.

## 4. Additional exam notes
- **Days vs remaining days:** If asked 'how many MORE days', exclude days already worked.
- A worker's wage is based on total contribution, not merely being present.
- **Pipes and cisterns** use the same method, except drainage has a negative rate; see Topic 02.
