# Unit 5 — Correlation and Regression

---

## Question 11 — Least-Squares Parabola Curve Fitting

**Question:** Fit a parabola of the second degree $y = a + bx + cx^2$ to the following data by the method of least squares:

| $x$ | 0 | 1 | 2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 1 | 1.8 | 3.3 | 4.5 | 6.3 |

---

### Step-by-Step Solution

#### 1. Form the System of Normal Equations
To fit the parabola $y = a + bx + cx^2$ for $n = 5$ data points, the three normal equations are:

$$\begin{aligned}
\sum y &= na + b\sum x + c\sum x^2 \qquad &(1) \\
\sum xy &= a\sum x + b\sum x^2 + c\sum x^3 \qquad &(2) \\
\sum x^2y &= a\sum x^2 + b\sum x^3 + c\sum x^4 \qquad &(3)
\end{aligned}$$

#### 2. Construct the Summation Table

| $x$ | $y$ | $x^2$ | $x^3$ | $x^4$ | $xy$ | $x^2y$ |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 0 | 1.0 | 0 | 0 | 0 | 0.0 | 0.0 |
| 1 | 1.8 | 1 | 1 | 1 | 1.8 | 1.8 |
| 2 | 3.3 | 4 | 8 | 16 | 6.6 | 13.2 |
| 3 | 4.5 | 9 | 27 | 81 | 13.5 | 40.5 |
| 4 | 6.3 | 16 | 64 | 256 | 25.2 | 100.8 |
| **$\sum x = 10$** | **$\sum y = 16.9$** | **$\sum x^2 = 30$** | **$\sum x^3 = 100$** | **$\sum x^4 = 354$** | **$\sum xy = 47.1$** | **$\sum x^2y = 156.3$** |

#### 3. Substitute Sums into Normal Equations

$$\begin{aligned}
5a + 10b + 30c &= 16.9 \qquad &(1) \\
10a + 30b + 100c &= 47.1 \qquad &(2) \\
30a + 100b + 354c &= 156.3 \qquad &(3)
\end{aligned}$$

#### 4. Solving the Normal Equations
Solving the system of simultaneous equations (1), (2), and (3):
$$a \approx \mathbf{0.9629}, \quad b \approx \mathbf{0.8443}, \quad c \approx \mathbf{0.1214}$$

#### 5. Final Fitted Parabola Equation

$$\mathbf{y = 0.9629 + 0.8443x + 0.1214x^2}$$

---

## Question 12 — Exponential Curve Fitting ($y = ae^{bx}$)

**Question:** For the following data, fit the curve of the form $y = ae^{bx}$:

| $x$ | 55 | 56 | 58 | 59 | 60 | 60 | 62 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 35 | 38 | 38 | 39 | 44 | 43 | 45 |

---

### Step-by-Step Solution

#### 1. Linearization Transformation
Taking natural logarithms ($\ln$) of both sides of $y = ae^{bx}$:

$$\ln y = \ln a + bx$$

Let $Y = \ln y$, $A = \ln a$, and $B = b$. The equation becomes:

$$Y = A + Bx$$

The normal equations for $n = 7$ observations are:

$$\begin{aligned}
\sum Y &= nA + B\sum x \qquad &(1) \\
\sum xY &= A\sum x + B\sum x^2 \qquad &(2)
\end{aligned}$$

Once $A$ and $B$ are obtained:
$$a = e^A, \qquad b = B$$

#### 2. Construction of Working Table

| $i$ | $x$ | $y$ | $x^2$ | $Y = \ln y$ | $xY = x\ln y$ |
|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | 55 | 35 | 3025 | 3.555 | 195.54 |
| 2 | 56 | 38 | 3136 | 3.638 | 203.70 |
| 3 | 58 | 38 | 3364 | 3.638 | 210.98 |
| 4 | 59 | 39 | 3481 | 3.664 | 216.15 |
| 5 | 60 | 44 | 3600 | 3.784 | 227.05 |
| 6 | 60 | 43 | 3600 | 3.761 | 225.67 |
| 7 | 62 | 45 | 3844 | 3.807 | 236.01 |
| **Sum** | **410** | **282** | **24050** | **25.846** | **1515.12** |

#### 3. Solving the Normal Equations

$$\begin{aligned}
7A + 410B &= 25.846 \qquad &(1) \\
410A + 24050B &= 1515.12 \qquad &(2)
\end{aligned}$$

Using Cramer's Rule or elimination:

$$\Delta = 7(24050) - (410)^2 = 168350 - 168100 = \mathbf{250}$$

$$\Delta_B = 7(1515.12) - 410(25.846) = 10605.84 - 10596.86 = \mathbf{8.98}$$

$$B = \frac{8.98}{250} \approx \mathbf{0.0356} \implies \mathbf{b \approx 0.0356}$$

From Equation (1):

$$A = \frac{25.846 - 410(0.0356)}{7} = \frac{25.846 - 14.60}{7} = \frac{11.246}{7} \approx \mathbf{1.607}$$

$$a = e^A = e^{1.607} \approx \mathbf{4.996}$$

#### 4. Final Fitted Curve Equation

$$\mathbf{y = 4.996 \, e^{0.0356x}}$$

---

## Question 13 — Spearman's Rank Correlation with Tied Ranks

**Question:** Calculate Rank correlation coefficient for the following data:

| $x$ | 48 | 33 | 40 | 9 | 16 | 16 | 65 | 24 | 16 | 57 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 13 | 13 | 24 | 6 | 15 | 4 | 20 | 9 | 6 | 19 |

---

### Step-by-Step Solution

#### 1. Identify Tied Values & Compute Correction Factors
Total number of pairs: $n = 10$.

- **Ties in $x$-series:**
  - Value $16$ appears **$3$ times** ($m_1 = 3$).
  - Correction factor:

$$T_{x} = \frac{m_1(m_1^2 - 1)}{12} = \frac{3(3^2 - 1)}{12} = \frac{3 \times 8}{12} = \mathbf{2.0}$$

- **Ties in $y$-series:**
  - Value $6$ appears **$2$ times** ($m_2 = 2$).
    $$T_{y1} = \frac{m_2(m_2^2 - 1)}{12} = \frac{2(2^2 - 1)}{12} = \frac{2 \times 3}{12} = \mathbf{0.5}$$
  - Value $13$ appears **$2$ times** ($m_3 = 2$).
    $$T_{y2} = \frac{m_3(m_3^2 - 1)}{12} = \frac{2(2^2 - 1)}{12} = \frac{2 \times 3}{12} = \mathbf{0.5}$$
  - Total correction for $y$: $T_y = 0.5 + 0.5 = \mathbf{1.0}$.

- **Total Correction Factor ($CF$):**

$$CF = T_x + T_y = 2.0 + 1.0 = \mathbf{3.0}$$

#### 2. Assigning Average Ranks
Using the standard convention (ranking smallest value as 1):
- Sorted $x$: `9 (1), 16, 16, 16 (ranks 2, 3, 4 -> avg 3), 24 (5), 33 (6), 40 (7), 48 (8), 57 (9), 65 (10)`
- Sorted $y$: `4 (1), 6, 6 (ranks 2, 3 -> avg 2.5), 9 (4), 13, 13 (ranks 5, 6 -> avg 5.5), 15 (7), 19 (8), 20 (9), 24 (10)`

#### 3. Rank Differences Table

| $i$ | $x$ | $y$ | Rank $R_x$ | Rank $R_y$ | $d = R_x - R_y$ | $d^2$ |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | 48 | 13 | 8.0 | 5.5 | $+2.5$ | 6.25 |
| 2 | 33 | 13 | 6.0 | 5.5 | $+0.5$ | 0.25 |
| 3 | 40 | 24 | 7.0 | 10.0 | $-3.0$ | 9.00 |
| 4 | 9 | 6 | 1.0 | 2.5 | $-1.5$ | 2.25 |
| 5 | 16 | 15 | 3.0 | 7.0 | $-4.0$ | 16.00 |
| 6 | 16 | 4 | 3.0 | 1.0 | $+2.0$ | 4.00 |
| 7 | 65 | 20 | 10.0 | 9.0 | $+1.0$ | 1.00 |
| 8 | 24 | 9 | 5.0 | 4.0 | $+1.0$ | 1.00 |
| 9 | 16 | 6 | 3.0 | 2.5 | $+0.5$ | 0.25 |
| 10 | 57 | 19 | 9.0 | 8.0 | $+1.0$ | 1.00 |
| **Total** | | | | | **$\sum d = 0$** | **$\sum d^2 = 41.00$** |

#### 4. Formula Application

$$\rho = 1 - \frac{6 \left[\sum d^2 + CF\right]}{n(n^2 - 1)} = 1 - \frac{6 \left[41 + 3\right]}{10(10^2 - 1)}$$

$$\rho = 1 - \frac{6 \times 44}{10 \times 99} = 1 - \frac{264}{990}$$

Dividing numerator and denominator by $66$:

$$\rho = 1 - \frac{4}{15} = \frac{11}{15} \approx \mathbf{0.7333}$$

**Conclusion:** The rank correlation coefficient is $\mathbf{+0.7333}$, indicating a **fairly strong positive relationship** between $x$ and $y$.

---

## Question 14 — Karl Pearson's Coefficient of Correlation

**Question:** Calculate Karl Pearson's coefficient of correlation for the following data:

| $x$ | 12 | 9 | 8 | 10 | 11 | 13 | 7 |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **$y$** | 14 | 8 | 6 | 9 | 11 | 12 | 3 |

---

### Step-by-Step Solution

#### 1. Calculate the Means ($\bar{x}, \bar{y}$)
Sample size $n = 7$.

$$\bar{x} = \frac{\sum x}{n} = \frac{70}{7} = \mathbf{10}$$

$$\bar{y} = \frac{\sum y}{n} = \frac{63}{7} = \mathbf{9}$$

#### 2. Deviations from Means Table
Since both means are exact integers, let $u = x - 10$ and $v = y - 9$:

| $i$ | $x$ | $y$ | $u = x - 10$ | $v = y - 9$ | $u^2$ | $v^2$ | $uv$ |
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| 1 | 12 | 14 | $+2$ | $+5$ | 4 | 25 | $+10$ |
| 2 | 9 | 8 | $-1$ | $-1$ | 1 | 1 | $+1$ |
| 3 | 8 | 6 | $-2$ | $-3$ | 4 | 9 | $+6$ |
| 4 | 10 | 9 | 0 | 0 | 0 | 0 | 0 |
| 5 | 11 | 11 | $+1$ | $+2$ | 1 | 4 | $+2$ |
| 6 | 13 | 12 | $+3$ | $+3$ | 9 | 9 | $+9$ |
| 7 | 7 | 3 | $-3$ | $-6$ | 9 | 36 | $+18$ |
| **Sum** | **70** | **63** | **0** | **0** | **28** | **84** | **46** |

#### 3. Correlation Coefficient ($r$)
Applying Karl Pearson's formula:

$$r = \frac{\sum uv}{\sqrt{\sum u^2 \cdot \sum v^2}} = \frac{46}{\sqrt{28 \times 84}} = \frac{46}{\sqrt{2352}} = \frac{46}{48.50} \approx \mathbf{0.9485} \quad (\approx \mathbf{0.95})$$

**Conclusion:** Karl Pearson's correlation coefficient is $\mathbf{+0.95}$, indicating a **very strong positive linear correlation** between $x$ and $y$.

---

## Question 15 — Regression Equations, Means and Correlation

**Question:** The equations of two regression lines are $7x - 16y + 9 = 0$ and $5y - 4x - 3 = 0$. Find:
1. The means of $x$ and $y$ ($\bar{x}$ and $\bar{y}$)
2. The coefficient of correlation ($r$)

---

### Step-by-Step Solution

#### Part 1: Finding the Means $\bar{x}$ and $\bar{y}$
By the fundamental property of regression, the two regression lines intersect at the point of their means $(\bar{x}, \bar{y})$.
Therefore, substituting $\bar{x}$ and $\bar{y}$:

$$\begin{aligned}
7\bar{x} - 16\bar{y} &= -9 \qquad &(1) \\
-4\bar{x} + 5\bar{y} &= 3 \qquad &(2)
\end{aligned}$$

Multiply Equation (1) by $4$ and Equation (2) by $7$:

$$\begin{aligned}
28\bar{x} - 64\bar{y} &= -36 \qquad &(1') \\
-28\bar{x} + 35\bar{y} &= 21 \qquad &(2')
\end{aligned}$$

Add the two equations to eliminate $\bar{x}$:

$$(28\bar{x} - 28\bar{x}) + (-64\bar{y} + 35\bar{y}) = -36 + 21$$

$$-29\bar{y} = -15 \implies \mathbf{\bar{y} = \frac{15}{29} \approx 0.5172}$$

Substitute $\bar{y} = \frac{15}{29}$ into Equation (2):

$$-4\bar{x} + 5\left(\frac{15}{29}\right) = 3$$

$$-4\bar{x} = 3 - \frac{75}{29} = \frac{87 - 75}{29} = \frac{12}{29}$$

$$\bar{x} = -\frac{12}{4 \times 29} \implies \mathbf{\bar{x} = -\frac{3}{29} \approx -0.1034}$$

$$\mathbf{\text{Means: } \bar{x} = -\frac{3}{29} \approx -0.1034, \quad \bar{y} = \frac{15}{29} \approx 0.5172}$$

---

#### Part 2: Finding the Coefficient of Correlation ($r$)
We must identify which equation is the regression line of $y$ on $x$ and which is $x$ on $y$.

**Hypothesis A:**
Assume $7x - 16y + 9 = 0$ is the regression line of $y$ on $x$:

$$16y = 7x + 9 \implies y = \frac{7}{16}x + \frac{9}{16} \implies b_{yx} = \mathbf{\frac{7}{16}}$$

Assume $5y - 4x - 3 = 0$ is the regression line of $x$ on $y$:

$$4x = 5y - 3 \implies x = \frac{5}{4}y - \frac{3}{4} \implies b_{xy} = \mathbf{\frac{5}{4}}$$

Check the consistency property $r^2 = b_{yx} \cdot b_{xy} \le 1$:

$$r^2 = b_{yx} \cdot b_{xy} = \frac{7}{16} \times \frac{5}{4} = \frac{35}{64} \approx 0.546875 \le 1 \quad \textbf{[VALID!]} $$

*(Note: If the reverse assumption were made, $b_{yx} = \frac{4}{5}, b_{xy} = \frac{16}{7} \implies r^2 = \frac{64}{35} = 1.8286 > 1$, which is impossible since $|r| \le 1$).*

Since both regression coefficients $b_{yx} = \frac{7}{16}$ and $b_{xy} = \frac{5}{4}$ are positive, $r$ must also be positive:

$$r = +\sqrt{b_{yx} \cdot b_{xy}} = \sqrt{\frac{35}{64}} = \frac{\sqrt{35}}{8} = \frac{5.91608}{8} \approx \mathbf{0.7395}$$

> [!NOTE]
> **Correction Note:** The handwritten notes mistakenly wrote $r^2 = b_{yx} + b_{xy}$ with a plus sign. The correct formula is the geometric mean product: $r^2 = b_{yx} \cdot b_{xy} \implies r = \sqrt{b_{yx} \cdot b_{xy}}$.

---

## Question 16 — Beauty Contest Judges Rank Correlation

**Question:** Ten persons are assessed by two judges in a beauty contest. Determine the closeness between opinions of judges by rank correlation coefficient:

| Person | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **Score assigned by J-1** | 65 | 70 | 72 | 76 | 77 | 79 | 72 | 80 | 77 | 72 |
| **Score assigned by J-2** | 59 | 71 | 77 | 71 | 69 | 79 | 69 | 65 | 67 | 80 |

---

### Step-by-Step Solution

#### 1. Assign Ranks (Highest Score = Rank 1)
Ranking the scores for each judge from highest to lowest:

| Person | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
|:---|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
| **J-1 Score** | 65 | 70 | 72 | 76 | 77 | 79 | 72 | 80 | 77 | 72 |
| **Rank $R_1$** | 10 | 7 | 6 | 5 | 4 | 1 | 6 | 2 | 4 | 6 |
| **J-2 Score** | 59 | 71 | 77 | 71 | 69 | 79 | 69 | 65 | 67 | 80 |
| **Rank $R_2$** | 10 | 5 | 2 | 5 | 7 | 1 | 7 | 9 | 8 | 3 |
| **$d = R_1 - R_2$** | 0 | 2 | 4 | 0 | $-3$ | 0 | $-1$ | $-7$ | $-4$ | 3 |
| **$d^2$** | 0 | 4 | 16 | 0 | 9 | 0 | 1 | 49 | 16 | 9 |

$$\sum d^2 = 0 + 4 + 16 + 0 + 9 + 0 + 1 + 49 + 16 + 9 = \mathbf{104}$$

#### 2. Spearman's Rank Correlation Formula

$$r_s = 1 - \frac{6 \sum d^2}{n(n^2 - 1)}$$

For $n = 10$:

$$r_s = 1 - \frac{6 \times 104}{10(10^2 - 1)} = 1 - \frac{624}{10(99)} = 1 - \frac{624}{990}$$

$$r_s = 1 - 0.6303 \approx \mathbf{0.37}$$

**Conclusion:** The rank correlation coefficient between the two judges is $r_s \approx \mathbf{+0.37}$, indicating a **moderate positive agreement** between the two judges.
