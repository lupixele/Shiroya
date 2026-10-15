## Unit IV: Exploratory Data Analysis

| Q no. | Priority | Marks |
|---|---|---|
| 1 | P1 | 8 |
| 2 | P1 | 8 |
| 3 | P1 | 8 |
| 4 | P1 | 8 |
| 5 | P2 | 8 |

### Q1. Describe the commonly used measures of descriptive statistics with suitable examples. [P1 | 8 marks]

Descriptive statistics summarise a dataset using a few numbers. They are grouped into central tendency, dispersion and shape.

1. **Mean:** sum of values divided by count. Affected by outliers.
2. **Median:** middle value of sorted data. Not affected by outliers.
3. **Mode:** most frequent value.
4. **Range:** maximum minus minimum.
5. **Variance and standard deviation:** average squared deviation from the mean, and its square root. They show how spread out the data is.
6. **Quartiles and IQR:** Q1, Q2, Q3 divide sorted data into four parts. IQR = Q3 - Q1.
7. **Skewness and kurtosis:** skewness shows asymmetry of the distribution. Kurtosis shows how heavy the tails are.

Worked example for data 2, 4, 4, 6, 9:

- Mean = 25/5 = 5. Median = 4. Mode = 4. Range = 9 - 2 = 7.
- Squared deviations: 9, 1, 1, 1, 16. Sum = 28.
- Sample variance = 28/4 = 7. Standard deviation = 2.65.

```python
import pandas as pd
s = pd.Series([2, 4, 4, 6, 9])
print(s.describe())
# count 5.0, mean 5.0, std 2.645751, min 2.0, 25% 4.0, 50% 4.0, 75% 6.0, max 9.0
print(s.skew(), s.kurt())
```

`describe()` returns count, mean, std, min, quartiles and max in one call.

### Q2. Demonstrate different data visualization techniques used in Exploratory Data Analysis with suitable examples. [P1 | 8 marks]

Visualization shows the shape, spread, relationships and outliers of data that numbers alone may hide.

1. **Histogram:** shows the distribution of one numeric variable using bins.
2. **Box plot:** shows median, quartiles, spread and outliers.
3. **Scatter plot:** shows the relationship between two numeric variables.
4. **Bar chart:** compares values across categories.
5. **Heatmap:** shows a matrix of values by colour, commonly a correlation matrix.

```python
import numpy as np, pandas as pd, seaborn as sns
import matplotlib.pyplot as plt
a = np.random.normal(50, 10, 100)
df = pd.DataFrame({"a": a, "c": a*0.5 + np.random.normal(0, 3, 100)})
fig, ax = plt.subplots(2, 3, figsize=(12, 7))
ax[0,0].hist(a, bins=10)
ax[0,1].boxplot(a)
ax[0,2].scatter(df["a"], df["c"])
ax[1,0].bar(["X", "Y", "Z"], [5, 8, 3])
sns.heatmap(df.corr(), annot=True, ax=ax[1,1])
plt.show()
```

Reading the output: the histogram is bell shaped, the box plot shows the middle 50 percent of values, the scatter plot rises left to right (positive relationship), the bars show category totals, and the heatmap shows a high correlation between `a` and `c`.

### Q3. Analyze the correlation and covariance techniques by using suitable example. [P1 | 8 marks]

Covariance and correlation measure how two variables change together.

1. **Covariance:** cov(X, Y) = sum((xi - mean X)(yi - mean Y)) / (n - 1).
2. **Covariance sign:** positive means both rise together, negative means one rises as the other falls, near zero means no linear relation.
3. **Covariance limit:** its value depends on units, so the size is hard to compare.
4. **Correlation:** r = cov(X, Y) / (sX x sY). It is covariance scaled by both standard deviations.
5. **Range of r:** -1 to +1. +1 is perfect positive, -1 is perfect negative, 0 is no linear relation.
6. **Strength:** about 0.7 or more in magnitude is strong, 0.3 to 0.7 moderate, below 0.3 weak.
7. **Caution:** correlation does not prove causation. Spearman correlation suits ranked or non-linear monotonic data.

Worked example: X = 1, 2, 3, 4, 5 and Y = 2, 4, 5, 4, 5.

- Mean X = 3, mean Y = 4.
- Products of deviations: 4, 0, 0, 0, 2. Sum = 6. Covariance = 6/4 = 1.5.
- sX = 1.58, sY = 1.22. r = 1.5 / (1.58 x 1.22) = 0.77, a strong positive correlation.

```python
import pandas as pd
df = pd.DataFrame({"X": [1, 2, 3, 4, 5], "Y": [2, 4, 5, 4, 5]})
print(df.cov())    # X-Y covariance 1.5
print(df.corr())   # X-Y correlation 0.774597
```

### Q4. Differentiate between Univariate, Bivariate and Multivariate analysis with suitable examples. [P1 | 8 marks]

| Basis | Univariate | Bivariate | Multivariate |
|---|---|---|---|
| Variables | One | Two | Three or more |
| Aim | Describe one variable | Find relationship between two | Find patterns among many |
| Methods | Mean, median, frequency, spread | Correlation, cross-tabulation, regression | Multiple regression, PCA, clustering |
| Complexity | Lowest | Moderate | Highest |
| Typical plots | Histogram, box plot, bar chart | Scatter plot, grouped bar, line plot | Pair plot, heatmap, 3D plot, bubble chart |
| Question answered | How are marks distributed? | Do study hours affect marks? | How do study hours, attendance and sleep affect marks? |

Examples:

- **Univariate:** distribution of students' marks shown with a histogram.
- **Bivariate:** study hours against marks shown with a scatter plot.
- **Multivariate:** study hours, attendance and sleep against marks shown with a pair plot or correlation heatmap.

### Q5. Analyze a dataset to identify possible Anomalies and Pattern Detection. [P2 | 8 marks]

An anomaly is a value that differs strongly from the rest of the data. A pattern is a regular structure such as a trend or a cluster. Both are found during EDA.

Dataset: 10, 12, 11, 13, 12, 11, 12, 14, 10, 13, 12, 11, 13, 12, 95.

1. **IQR rule:** a value is an outlier if it lies below Q1 - 1.5 x IQR or above Q3 + 1.5 x IQR. Here Q1 = 11, Q3 = 13, IQR = 2, limits are 8 and 16. Only 95 is outside.
2. **Z-score:** z = (x - mean) / standard deviation. A value with |z| above 3 is an outlier. For 95, z is about 3.6.
3. **Box plot:** shows the outlier as a separate point.
4. **Scatter plot:** shows isolated points away from the main group.

```python
import pandas as pd
import matplotlib.pyplot as plt
s = pd.Series([10,12,11,13,12,11,12,14,10,13,12,11,13,12,95])
q1, q3 = s.quantile(0.25), s.quantile(0.75)
iqr = q3 - q1
print(s[(s < q1 - 1.5*iqr) | (s > q3 + 1.5*iqr)].tolist())   # [95]
z = (s - s.mean()) / s.std()
print(s[z.abs() > 3].tolist())                               # [95]
s.plot(kind="box"); plt.show()
```

Pattern types:

- **Trend:** steady rise or fall over time.
- **Seasonality:** repeating rise and fall at fixed intervals.
- **Clusters:** groups of similar points on a scatter plot.
- **Correlation:** two variables moving together.

### Quick revision

1. Mean is sensitive to outliers, median is not; sample variance divides by n - 1.
2. describe() gives count, mean, std, min, quartiles and max.
3. r = cov / (sX x sY), range -1 to +1; correlation is not causation.
4. Univariate uses one variable, bivariate two, multivariate three or more.
5. IQR rule limits are Q1 - 1.5 IQR and Q3 + 1.5 IQR; z-score outlier means |z| above 3.
