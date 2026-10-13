# Probability & Statistics — Assignment-II Questions

Comprehensive master question paper for **Probability & Statistics (Assignment-II)**, covering **Unit 3**, **Unit 4**, and **Unit 5**. Each question includes difficulty ranking, topic mapping, and direct clickable links to its complete step-by-step worked solution.

---

## Unit-wise Question Mapping & Difficulty Ranking

| Question | Unit | Topic / Problem Statement | Difficulty | Worked Solution Link |
|:---:|:---:|:---|:---:|:---|
| **Q1** | **Unit 3** | Sampling distribution of means without replacement ($N=5, n=3$) | 🟡 **Medium** | [`Unit 3.md` — Question 1](Unit%203.md#question-1--sampling-distribution-without-replacement) |
| **Q2** | **Unit 3** | Sampling distribution of means with replacement ($N=5, n=2$) | 🟡 **Medium** | [`Unit 3.md` — Question 2](Unit%203.md#question-2--sampling-distribution-with-replacement) |
| **Q3** | **Unit 3** | Median for grouped frequency distribution table ($N=44$) | 🟢 **Easy** | [`Unit 3.md` — Question 3](Unit%203.md#question-3--median-for-grouped-frequency-distribution) |
| **Q4** | **Unit 3** | Types of data and primary/secondary data collection methods | 🟢 **Easy** | [`Unit 3.md` — Question 4](Unit%203.md#question-4--types-of-data-and-methods-of-collection) |
| **Q5** | **Unit 3** | Central Limit Theorem normal distribution sample probabilities ($n=100$) | 🟢 **Easy** | [`Unit 3.md` — Question 5](Unit%203.md#question-5--central-limit-theorem-probabilities) |
| **Q6** | **Unit 3** | 95% Confidence limits for population mean ($n=16$) | 🟡 **Medium** | [`Unit 3.md` — Question 6](Unit%203.md#question-6--95-confidence-limits-for-population-mean) |
| **Q7** | **Unit 4** | Chi-Square ($\chi^2$) test for independence of sampling techniques ($2 \times 4$) | 🟡 **Medium** | [`Unit 4.md` — Question 7](Unit%204.md#question-7--chi-square-test-for-independence-of-sampling-techniques) |
| **Q8** | **Unit 4** | Two-sample large-sample $Z$-test for difference of wheat yield means | 🟢 **Easy** | [`Unit 4.md` — Question 8](Unit%204.md#question-8--two-sample-large-sample-z-test-for-means) |
| **Q9** | **Unit 4** | Paired $t$-test for shooting marks of 10 soldiers | 🟡 **Medium** | [`Unit 4.md` — Question 9](Unit%204.md#question-9--paired-t-test-soldiers-training) |
| **Q10** | **Unit 4** | Single-sample large-sample $Z$-test for student body weight | 🟢 **Easy** | [`Unit 4.md` — Question 10](Unit%204.md#question-10--single-sample-large-sample-z-test-for-mean) |
| **Q11** | **Unit 5** | Least-squares parabola fitting of 2nd degree: $y = a + bx + cx^2$ | 🔴 **Hard** | [`Unit 5.md` — Question 11](Unit%205.md#question-11--least-squares-parabola-curve-fitting) |
| **Q12** | **Unit 5** | Exponential curve fitting: $y = a e^{bx}$ | 🟡 **Medium** | [`Unit 5.md` — Question 12](Unit%205.md#question-12--exponential-curve-fitting-y--aebx) |
| **Q13** | **Unit 5** | Spearman's rank correlation coefficient with tied ranks | 🔴 **Hard** | [`Unit 5.md` — Question 13](Unit%205.md#question-13--spearmans-rank-correlation-with-tied-ranks) |
| **Q14** | **Unit 5** | Karl Pearson's coefficient of correlation ($r$) between $X$ and $Y$ | 🟢 **Easy** | [`Unit 5.md` — Question 14](Unit%205.md#question-14--karl-pearsons-coefficient-of-correlation) |
| **Q15** | **Unit 5** | Regression equations of $Y$ on $X$ & $X$ on $Y$, means, and $r$ | 🟡 **Medium** | [`Unit 5.md` — Question 15](Unit%205.md#question-15--regression-equations-means-and-correlation) |
| **Q16** | **Unit 5** | Rank correlation coefficient between two beauty contest judges | 🟢 **Easy** | [`Unit 5.md` — Question 16](Unit%205.md#question-16--beauty-contest-judges-rank-correlation) |

---

## Difficulty Summary & Exam Preparation Strategy

| Difficulty Tier | Total Questions | Questions List | Exam Strategy |
|:---|:---:|:---|:---|
| 🟢 **Easy** (Quick Wins) | **7** | Q3, Q4, Q5, Q8, Q10, Q14, Q16 | Solve first in exams. Pure formula substitution, single-digit numbers, or theory. |
| 🟡 **Medium** (Moderate Calculations) | **7** | Q1, Q2, Q6, Q7, Q9, Q12, Q15 | Solve next. Multi-step workflows (tables, paired differences, $2 \times 2$ systems). |
| 🔴 **Hard** (Computationally Heavy) | **2** | Q11, Q13 | Solve with high focus. Heavy summation powers ($3 \times 3$ system) or multiple tied ranks. |

---

## Unit 3 — Data Analytics and Sampling Theory

### Question 1 — 🟡 Medium
A population consists of five numbers $3, 6, 9, 15$, and $27$. Consider all possible samples of size $3$ that can be drawn **without replacement** from this population. Find:
1. The population mean ($\mu$).
2. The population standard deviation ($\sigma$).
3. The mean of the sampling distribution of means ($\mu_{\bar{x}}$).
4. The standard deviation of the sampling distribution of means ($\sigma_{\bar{x}}$).

> **Difficulty:** 🟡 **Medium** — Requires listing $\binom{5}{3} = 10$ samples, computing individual means, and applying the finite population correction factor.  
> **Worked Solution:** [See `Unit 3.md` — Question 1](Unit%203.md#question-1--sampling-distribution-without-replacement)

---

### Question 2 — 🟡 Medium
A population consists of five numbers $2, 3, 6, 8$, and $11$. Consider all possible samples of size $2$ that can be drawn **with replacement** from this population. Find:
1. The mean of the population ($\mu$).
2. The standard deviation of the population ($\sigma$).
3. The mean of the sampling distribution of means ($\mu_{\bar{x}}$).
4. The standard deviation of the sampling distribution of means ($\sigma_{\bar{x}}$).

> **Difficulty:** 🟡 **Medium** — Requires generating all $5^2 = 25$ sample pairs in a $5 \times 5$ matrix and calculating their sampling distribution.  
> **Worked Solution:** [See `Unit 3.md` — Question 2](Unit%203.md#question-2--sampling-distribution-with-replacement)

---

### Question 3 — 🟢 Easy
Find the median for the following grouped frequency distribution:

| Group | 50–54 | 55–59 | 60–64 | 65–69 | 70–74 | 75–79 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|
| **Frequency ($f$)** | 4 | 8 | 10 | 9 | 7 | 6 |

> **Difficulty:** 🟢 **Easy** — Direct continuous boundary adjustment and standard median formula application.  
> **Worked Solution:** [See `Unit 3.md` — Question 3](Unit%203.md#question-3--median-for-grouped-frequency-distribution)

---

### Question 4 — 🟢 Easy
What are the types of data? Explain the methods of collection of data.
- **Types of Data:** Primary data vs. Secondary data; Qualitative (nominal, ordinal) vs. Quantitative (discrete, continuous).
- **Collection Methods:** Direct personal investigation, indirect oral examination, questionnaires/schedules, government publications, journals.

> **Difficulty:** 🟢 **Easy** — Descriptive theory question testing basic conceptual knowledge.  
> **Worked Solution:** [See `Unit 3.md` — Question 4](Unit%203.md#question-4--types-of-data-and-methods-of-collection)

---

### Question 5 — 🟢 Easy
A random sample of size $100$ is taken from an infinite population having the mean $\mu = 76$ and variance $\sigma^2 = 256$. Find the probability that the sample mean ($\bar{x}$) will be:
1. Between $75$ and $78$.
2. More than $72$.

> **Difficulty:** 🟢 **Easy** — Standard error $SE = \sigma / \sqrt{n} = 1.6$; straightforward $Z$-score and standard normal area calculation.  
> **Worked Solution:** [See `Unit 3.md` — Question 5](Unit%203.md#question-5--central-limit-theorem-probabilities)

---

### Question 6 — 🟡 Medium
Find $95\%$ confidence limits for the mean of a normally distributed population from which the following sample was taken:
$$15, 17, 10, 18, 16, 9, 7, 11, 13, 14, 20, 13, 19, 25, 18, 16$$

> **Difficulty:** 🟡 **Medium** — Requires computing mean and sample variance from 16 raw data points and applying $t$-table critical values with $df = 15$.  
> **Worked Solution:** [See `Unit 3.md` — Question 6](Unit%203.md#question-6--95-confidence-limits-for-population-mean)

---

## Unit 4 — Testing of Hypothesis

### Question 7 — 🟡 Medium
Two researchers adopted different sampling techniques while investigating the same group of students to find the number of students falling in different intelligence levels. The results are as follows:

| Researcher | Below Average | Average | Above Average | Genius | Total |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **X** | 86 | 60 | 44 | 10 | 200 |
| **Y** | 40 | 33 | 25 | 2 | 100 |
| **Total** | 126 | 93 | 69 | 12 | 300 |

Would you say that the sampling techniques adopted by the two researchers are significantly different? (Use $\alpha = 0.05$).

> **Difficulty:** 🟡 **Medium** — Computing 8 expected cell frequencies ($E_i$) and summing $\frac{(O-E)^2}{E}$ for an $r \times c$ contingency table ($df = 3$).  
> **Worked Solution:** [See `Unit 4.md` — Question 7](Unit%204.md#question-7--chi-square-test-for-independence-of-sampling-techniques)

---

### Question 8 — 🟢 Easy
The mean yield of wheat from a district was $210\text{ pounds}$ with S.D. $10\text{ pounds}$ per acre from a sample of $100\text{ plots}$. In another district the mean yield was $220\text{ pounds}$ with S.D. $12\text{ pounds}$ from a sample of $50\text{ plots}$. Test whether there is any significant difference between the mean yields of crops in the two districts. (Use $\alpha = 0.05$).

> **Difficulty:** 🟢 **Easy** — Two large independent samples ($n_1 = 100, n_2 = 50$); direct two-sample $Z$-test formula with given summary statistics.  
> **Worked Solution:** [See `Unit 4.md` — Question 8](Unit%204.md#question-8--two-sample-large-sample-z-test-for-means)

---

### Question 9 — 🟡 Medium
Ten soldiers participated in a shooting competition in the first week. After intensive training they participated in the competition in the second week. Their scores before and after training are given as follows:

| Soldier | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **Scores Before ($x_i$)** | 67 | 24 | 57 | 55 | 63 | 54 | 56 | 68 | 33 | 43 |
| **Scores After ($y_i$)** | 70 | 38 | 58 | 58 | 56 | 67 | 68 | 75 | 42 | 38 |

Do the data indicate that the soldiers have been benefited by the training? (Test at $\alpha = 0.05$).

> **Difficulty:** 🟡 **Medium** — Paired data requires computing individual differences $d$, variance of differences $s^2$, and one-tailed $t$-test ($df = 9$).  
> **Worked Solution:** [See `Unit 4.md` — Question 9](Unit%204.md#question-9--paired-t-test-soldiers-training)

---

### Question 10 — 🟢 Easy
A sample of $64\text{ students}$ has a mean weight of $70\text{ kgs}$. Can this be regarded as a sample from a population with mean weight $56\text{ kgs}$ and standard deviation $25\text{ kgs}$? (Test at $\alpha = 0.05$).

> **Difficulty:** 🟢 **Easy** — Single-sample large-sample $Z$-test; quick standard error calculation and decision against $Z_{\text{tab}} = 1.96$.  
> **Worked Solution:** [See `Unit 4.md` — Question 10](Unit%204.md#question-10--single-sample-large-sample-z-test-for-mean)

---

## Unit 5 — Correlation and Regression

### Question 11 — 🔴 Hard
Fit a parabola of the second degree $y = a + bx + cx^2$ to the following data by the method of least squares:

| $x$ | 0 | 1 | 2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 1 | 1.8 | 3.3 | 4.5 | 6.3 |

> **Difficulty:** 🔴 **Hard** — Requires a 7-column summation table ($x, y, x^2, x^3, x^4, xy, x^2y$) and setting up/solving a system of 3 linear normal equations.  
> **Worked Solution:** [See `Unit 5.md` — Question 11](Unit%205.md#question-11--least-squares-parabola-curve-fitting)

---

### Question 12 — 🟡 Medium
For the following data, fit the curve of the form $y = ae^{bx}$:

| $x$ | 55 | 56 | 58 | 59 | 60 | 60 | 62 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 35 | 38 | 38 | 39 | 44 | 43 | 45 |

> **Difficulty:** 🟡 **Medium** — Requires logarithmic transformation $Y = \ln y$, setting up a 5-column table, and solving a $2 \times 2$ linear system.  
> **Worked Solution:** [See `Unit 5.md` — Question 12](Unit%205.md#question-12--exponential-curve-fitting-y--aebx)

---

### Question 13 — 🔴 Hard
Calculate Rank correlation coefficient for the following data:

| $x$ | 48 | 33 | 40 | 9 | 16 | 16 | 65 | 24 | 16 | 57 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 13 | 13 | 24 | 6 | 15 | 4 | 20 | 9 | 6 | 19 |

> **Difficulty:** 🔴 **Hard** — Involves multiple tied ranks ($16$ appears 3 times in $x$; $6$ and $13$ appear twice in $y$), requiring fractional average ranking and tie correction factors.  
> **Worked Solution:** [See `Unit 5.md` — Question 13](Unit%205.md#question-13--spearmans-rank-correlation-with-tied-ranks)

---

### Question 14 — 🟢 Easy
Calculate Karl Pearson's coefficient of correlation for the following data:

| $x$ | 12 | 9 | 8 | 10 | 11 | 13 | 7 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 14 | 8 | 6 | 9 | 11 | 12 | 3 |

> **Difficulty:** 🟢 **Easy** — Both means are exact integers ($\bar{x} = 10, \bar{y} = 9$), resulting in small single-digit deviations and fast arithmetic.  
> **Worked Solution:** [See `Unit 5.md` — Question 14](Unit%205.md#question-14--karl-pearsons-coefficient-of-correlation)

---

### Question 15 — 🟡 Medium
The equations of two regression lines are $7x - 16y + 9 = 0$ and $5y - 4x - 3 = 0$. Find:
1. The means of $x$ and $y$ ($\bar{x}$ and $\bar{y}$).
2. The coefficient of correlation ($r$).

> **Difficulty:** 🟡 **Medium** — Requires solving simultaneous linear equations for the point of means, determining slopes $b_{yx}$ and $b_{xy}$, verifying $b_{yx} \cdot b_{xy} \le 1$, and finding $r$.  
> **Worked Solution:** [See `Unit 5.md` — Question 15](Unit%205.md#question-15--regression-equations-means-and-correlation)

---

### Question 16 — 🟢 Easy
Ten persons are assessed by two judges in a beauty contest. Determine the closeness between opinions of judges by rank correlation coefficient:

| Person | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **Score assigned by J-1** | 65 | 70 | 72 | 76 | 77 | 79 | 72 | 80 | 77 | 72 |
| **Score assigned by J-2** | 59 | 71 | 77 | 71 | 69 | 79 | 69 | 65 | 67 | 80 |

> **Difficulty:** 🟢 **Easy** — Direct ranking of scores from 1 to 10, straightforward rank difference computation ($d$), and evaluation via Spearman's formula.  
> **Worked Solution:** [See `Unit 5.md` — Question 16](Unit%205.md#question-16--beauty-contest-judges-rank-correlation)
