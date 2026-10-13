# Unit 4 — Testing of Hypothesis

---

## Question 7 — Chi-Square Test for Independence of Sampling Techniques

**Question:** Two researchers adopted different sampling techniques while investigating the same group of students to find the number of students falling in different intelligence levels. The results are as follows:

| Researcher | Below Average | Average | Above Average | Genius | Total |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **X** | 86 | 60 | 44 | 10 | 200 |
| **Y** | 40 | 33 | 25 | 2 | 100 |
| **Total** | 126 | 93 | 69 | 12 | 300 |

Would you say that the sampling techniques adopted by the two researchers are significantly different? (Use $\alpha = 0.05$).

---

### Step-by-Step Solution

#### Step 1: Formulate Hypotheses
- **Null Hypothesis ($H_0$):** There is no significant difference between the sampling techniques adopted by the two researchers (the two variables are independent).
- **Alternative Hypothesis ($H_1$):** There is a significant difference between the sampling techniques adopted by the two researchers.

#### Step 2: Level of Significance & Critical Value
- Significance level: $\alpha = 0.05$.
- Degrees of freedom:
  $$df = (r - 1)(c - 1) = (2 - 1)(4 - 1) = 1 \times 3 = \mathbf{3}$$
- Critical table value from $\chi^2$-table:
  $$\chi^2_{\text{tab}} = \mathbf{7.815}$$

#### Step 3: Test Statistic Formula

$$\chi^2_{\text{cal}} = \sum \frac{(O_i - E_i)^2}{E_i}$$

#### Step 4: Expected Frequencies & Calculation

Expected frequency formula:
$$E_i = \frac{\text{Row Total} \times \text{Column Total}}{\text{Grand Total} \; (N = 300)}$$

**(a) Observed Frequencies ($O$):**

| Researcher | Below Average | Average | Above Average | Genius | Total |
|:---|:---:|:---:|:---:|:---:|:---:|
| **X** | 86 | 60 | 44 | 10 | 200 |
| **Y** | 40 | 33 | 25 | 2 | 100 |
| **Total** | 126 | 93 | 69 | 12 | 300 |

**(b) Expected Frequencies ($E$):**

| Researcher | Below Average | Average | Above Average | Genius | Total |
|:---|:---:|:---:|:---:|:---:|:---:|
| **X** | $\frac{200 \times 126}{300} = 84$ | $\frac{200 \times 93}{300} = 62$ | $\frac{200 \times 69}{300} = 46$ | $\frac{200 \times 12}{300} = 8$ | 200 |
| **Y** | $\frac{100 \times 126}{300} = 42$ | $\frac{100 \times 93}{300} = 31$ | $\frac{100 \times 69}{300} = 23$ | $\frac{100 \times 12}{300} = 4$ | 100 |
| **Total** | 126 | 93 | 69 | 12 | 300 |

**(c) Calculation of $\chi^2_{\text{cal}}$:**

$$\begin{aligned}
\chi^2_{\text{cal}} &= \frac{(86 - 84)^2}{84} + \frac{(60 - 62)^2}{62} + \frac{(44 - 46)^2}{46} + \frac{(10 - 8)^2}{8} \\
&\quad + \frac{(40 - 42)^2}{42} + \frac{(33 - 31)^2}{31} + \frac{(25 - 23)^2}{23} + \frac{(2 - 4)^2}{4} \\
&= \frac{4}{84} + \frac{4}{62} + \frac{4}{46} + \frac{4}{8} + \frac{4}{42} + \frac{4}{31} + \frac{4}{23} + \frac{4}{4} \\
&= 0.0476 + 0.0645 + 0.0870 + 0.5000 + 0.0952 + 0.1290 + 0.1739 + 1.0000 \\
&= 2.0972 \approx \mathbf{2.10}
\end{aligned}$$

#### Step 5: Statistical Decision & Conclusion

$$\chi^2_{\text{cal}} = 2.10 < \chi^2_{\text{tab}} = 7.815$$

Since the calculated value $\chi^2_{\text{cal}} = 2.10$ is less than the critical table value $\chi^2_{\text{tab}} = 7.815$, we **accept $H_0$** (fail to reject).

**Conclusion:** Therefore, there is **no significant difference** between the sampling techniques adopted by the two researchers.

---

## Question 8 — Two-Sample Large-Sample $Z$-Test for Means

**Question:** The mean yield of wheat from a district was $210\text{ pounds}$ with S.D. $10\text{ pounds}$ per acre from a sample of $100\text{ plots}$. In another district the mean yield was $220\text{ pounds}$ with S.D. $12\text{ pounds}$ from a sample of $50\text{ plots}$. Test whether there is any significant difference between the mean yields of crops in the two districts. (Use $\alpha = 0.05$).

---

### Step-by-Step Solution

#### Step 1: Given Data
- **District 1 (Sample 1):** Size $n_1 = 100$, Sample mean $\bar{x}_1 = 210\text{ lbs}$, Sample S.D. $s_1 = 10\text{ lbs}$ (or $\sigma_1 = 10$).
- **District 2 (Sample 2):** Size $n_2 = 50$, Sample mean $\bar{x}_2 = 220\text{ lbs}$, Sample S.D. $s_2 = 12\text{ lbs}$ (or $\sigma_2 = 12$).

#### Step 2: Formulate Hypotheses
- **Null Hypothesis ($H_0$):** $\mu_1 = \mu_2$ (No significant difference between mean yields).
- **Alternative Hypothesis ($H_1$):** $\mu_1 \neq \mu_2$ (Significant difference — **two-tailed test**).

#### Step 3: Level of Significance & Critical Value
- Significance level: $\alpha = 0.05$.
- Critical value from $Z$-table for a two-tailed test:
  $$Z_{\text{tab}} = \mathbf{1.96}$$

#### Step 4: Test Statistic Calculation
Since $n_1, n_2 \ge 30$, sample variances are unbiased estimates of population variances:

$$Z_{\text{cal}} = \frac{\bar{x}_1 - \bar{x}_2}{\sqrt{\dfrac{s_1^2}{n_1} + \dfrac{s_2^2}{n_2}}} = \frac{210 - 220}{\sqrt{\dfrac{10^2}{100} + \dfrac{12^2}{50}}} = \frac{-10}{\sqrt{1 + 2.88}} = \frac{-10}{\sqrt{3.88}} = \frac{-10}{1.97} \approx \mathbf{-5.08}$$

Taking absolute value:
$$|Z_{\text{cal}}| = \mathbf{5.08}$$

#### Step 5: Statistical Decision & Conclusion

$$|Z_{\text{cal}}| = 5.08 > Z_{\text{tab}} = 1.96$$

Since $|Z_{\text{cal}}| = 5.08$ is significantly greater than the critical value $Z_{\text{tab}} = 1.96$, we **reject the null hypothesis $H_0$**.

**Conclusion:** There is a **highly significant difference** between the mean yields of crops in the two districts. Specifically, the mean yield in District 2 ($220\text{ lbs}$) is significantly higher than that in District 1 ($210\text{ lbs}$).

---

## Question 9 — Paired $t$-Test (Soldiers' Training)

**Question:** Ten soldiers participated in a shooting competition in the first week. After intensive training they participated in the competition in the second week. Their scores before and after training are given as follows:

| Soldier | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **Scores Before ($x_i$)** | 67 | 24 | 57 | 55 | 63 | 54 | 56 | 68 | 33 | 43 |
| **Scores After ($y_i$)** | 70 | 38 | 58 | 58 | 56 | 67 | 68 | 75 | 42 | 38 |

Do the data indicate that the soldiers have been benefited by the training? (Test at $\alpha = 0.05$).

---

### Step-by-Step Solution

#### Step 1: Formulate Hypotheses
Because the same $10$ soldiers are measured before and after training, observations are paired.
Let difference $d = \text{Score After} - \text{Score Before} = y - x$.
- **Null Hypothesis ($H_0$):** $\mu_d = 0$ (Training has not produced any increase in scores).
- **Alternative Hypothesis ($H_1$):** $\mu_d > 0$ (Training has increased scores — **one-tailed test**).

#### Step 2: Level of Significance & Critical Value
- Significance level: $\alpha = 0.05$.
- Degrees of freedom:
  $$df = n - 1 = 10 - 1 = \mathbf{9}$$
- Critical value from $t$-table for a one-tailed test at $df = 9$:
  $$t_{\text{tab}} = \mathbf{1.833}$$

#### Step 3: Compute Differences ($d$), Mean Difference ($\bar{d}$), and Standard Deviation ($s$)

##### 1. Pairwise Differences Table
For each of the $n = 10$ soldiers, calculate the difference in performance:
$$d_i = \text{Score After } (y_i) - \text{Score Before } (x_i)$$

| Soldier ($i$) | Before ($x_i$) | After ($y_i$) | Difference ($d_i = y_i - x_i$) | Squared Difference ($d_i^2$) |
|:---:|:---:|:---:|:---:|:---:|
| 1 | 67 | 70 | $70 - 67 = \mathbf{+3}$ | $3^2 = 9$ |
| 2 | 24 | 38 | $38 - 24 = \mathbf{+14}$ | $14^2 = 196$ |
| 3 | 57 | 58 | $58 - 57 = \mathbf{+1}$ | $1^2 = 1$ |
| 4 | 55 | 58 | $58 - 55 = \mathbf{+3}$ | $3^2 = 9$ |
| 5 | 63 | 56 | $56 - 63 = \mathbf{-7}$ | $(-7)^2 = 49$ |
| 6 | 54 | 67 | $67 - 54 = \mathbf{+13}$ | $13^2 = 169$ |
| 7 | 56 | 68 | $68 - 56 = \mathbf{+12}$ | $12^2 = 144$ |
| 8 | 68 | 75 | $75 - 68 = \mathbf{+7}$ | $7^2 = 49$ |
| 9 | 33 | 42 | $42 - 33 = \mathbf{+9}$ | $9^2 = 81$ |
| 10 | 43 | 38 | $38 - 43 = \mathbf{-5}$ | $(-5)^2 = 25$ |
| **Total ($\sum$)** | — | — | **$\sum d = 50$** | **$\sum d^2 = 732$** |

##### 2. Mean Difference ($\bar{d}$)
$$\bar{d} = \frac{\sum d}{n} = \frac{50}{10} = \mathbf{5}$$
*(On average, soldiers improved by $5$ marks after training).*

##### 3. Sample Variance ($s^2$) and Standard Deviation ($s$)
Using the standard computational shortcut formula for sample variance:
$$s^2 = \frac{1}{n - 1} \left[\sum d^2 - n(\bar{d})^2\right]$$

Breaking down each term:
- $n - 1 = 10 - 1 = 9$ (degrees of freedom for sample variance)
- $\sum d^2 = 732$ (sum of individual squared differences)
- $n(\bar{d})^2 = 10 \times (5)^2 = 10 \times 25 = 250$

Substituting the values:
$$\begin{aligned}
s^2 &= \frac{1}{9} [732 - 10(5)^2] \\[6pt]
    &= \frac{1}{9} [732 - 250] \\[6pt]
    &= \frac{1}{9} [482] \approx \mathbf{53.56}
\end{aligned}$$

Taking the square root to find sample standard deviation ($s$):
$$s = \sqrt{53.56} \approx \mathbf{7.32} \quad (\text{also denoted as } \sigma = 7.32)$$

> [!NOTE]
> **Why does this formula work?**  
> The basic definition of sample variance is $s^2 = \frac{\sum (d - \bar{d})^2}{n - 1}$.  
> Expanding the numerator:  
> $$\sum (d - \bar{d})^2 = \sum \left(d^2 - 2d\bar{d} + \bar{d}^2\right) = \sum d^2 - 2\bar{d}\sum d + n\bar{d}^2 = \sum d^2 - 2\bar{d}(n\bar{d}) + n\bar{d}^2 = \sum d^2 - n(\bar{d})^2$$  
> If calculated directly by deviations from $\bar{d} = 5$:  
> $(d - 5) = [-2, 9, -4, -2, -12, 8, 7, 2, 4, -10]$  
> Squared deviations: $[4, 81, 16, 4, 144, 64, 49, 4, 16, 100]$, whose sum is exactly $\mathbf{482}$.  
> Thus: $s^2 = \frac{482}{9} \approx 53.56$. Both methods yield the exact same answer!

#### Step 4: Test Statistic Calculation

$$t_{\text{cal}} = \frac{\bar{d}}{s / \sqrt{n}} = \frac{5}{7.32 / \sqrt{10}} = \frac{5}{7.32 / 3.162} = \frac{5}{2.31} \approx \mathbf{2.16}$$

#### Step 5: Statistical Decision & Conclusion

$$t_{\text{cal}} = 2.16 > t_{\text{tab}} = 1.833$$

Since the calculated test statistic $t_{\text{cal}} = 2.16$ is greater than the critical value $t_{\text{tab}} = 1.833$, we **reject the null hypothesis $H_0$**.

**Conclusion:** The data indicates that the soldiers have **significantly benefited from the training** at the $5\%$ level of significance.

---

## Question 10 — Single-Sample Large-Sample $Z$-Test for Mean

**Question:** A sample of $64\text{ students}$ has a mean weight of $70\text{ kgs}$. Can this be regarded as a sample from a population with mean weight $56\text{ kgs}$ and standard deviation $25\text{ kgs}$? (Test at $\alpha = 0.05$).

---

### Step-by-Step Solution

#### Step 1: Given Data
- Sample size: $n = 64$ ($n \ge 30$, large sample)
- Sample mean: $\bar{x} = 70\text{ kgs}$
- Hypothesized population mean: $\mu = 56\text{ kgs}$
- Known population standard deviation: $\sigma = 25\text{ kgs}$

#### Step 2: Formulate Hypotheses
- **Null Hypothesis ($H_0$):** $\mu = 56\text{ kgs}$ (The sample is drawn from the population with mean $56\text{ kgs}$).
- **Alternative Hypothesis ($H_1$):** $\mu \neq 56\text{ kgs}$ (The sample is not from this population — **two-tailed test**).

#### Step 3: Level of Significance & Critical Value
- Significance level: $\alpha = 0.05$.
- Critical value from $Z$-table for a two-tailed test:
  $$Z_{\text{tab}} = \mathbf{1.96}$$

#### Step 4: Test Statistic Calculation

$$Z_{\text{cal}} = \frac{\bar{x} - \mu}{\sigma / \sqrt{n}} = \frac{70 - 56}{25 / \sqrt{64}} = \frac{14}{25/8} = \frac{14 \times 8}{25} = \frac{112}{25} = \mathbf{4.48}$$

Taking absolute value:
$$|Z_{\text{cal}}| = \mathbf{4.48}$$

#### Step 5: Statistical Decision & Conclusion

$$|Z_{\text{cal}}| = 4.48 > Z_{\text{tab}} = 1.96$$

Since $|Z_{\text{cal}}| = 4.48$ is significantly greater than the critical value $Z_{\text{tab}} = 1.96$, we **reject the null hypothesis $H_0$**.

**Conclusion:** No, this sample **cannot be regarded as drawn from a population** with mean weight $56\text{ kgs}$ and standard deviation $25\text{ kgs}$.
