## Unit 4

| Q no. | Priority | Marks |
|---|---|---|
| 1 | P1 | 6 |
| 2 | P1 | 8 |
| 3 | P1 | 8 |
| 4 | P2 | 8 |
| 5 | P2 | 8 |

### Q1. What is Exploratory Data Analysis (EDA)? Explain its importance in the data analysis process. [P1 | 6 marks]

EDA is the process of examining a dataset using summaries and visual methods to understand its structure, quality and patterns before building any model.

Workflow:
```
Collect data -> Inspect (shape, types) -> Clean (missing, duplicates)
-> Summarise (descriptive statistics) -> Visualise (plots)
-> Find relationships, outliers -> Decide next step (features, model)
```

Importance:
1. **Understanding data**: Shows size, types, ranges and distributions.
2. **Quality check**: Finds missing values, duplicates and wrong entries.
3. **Outlier detection**: Unusual values are spotted early.
4. **Relationships**: Reveals links between variables.
5. **Better modelling**: Guides feature selection and the choice of method.

Example: `df.info()` shows missing values, `df.describe()` shows summary statistics, and `df.hist()` shows distributions.

### Q2. What are Descriptive Statistics? Explain how mean, median, mode, variance and standard deviation help in understanding data. [P1 | 8 marks]

Descriptive statistics summarise a dataset using a few numbers. They describe the centre and the spread of the data.

1. **Mean**: Sum of values divided by count. It gives the average level but is affected by outliers.
2. **Median**: Middle value of sorted data. It is not affected by outliers, so it suits skewed data.
3. **Mode**: Most frequent value. It is useful for categories and repeated values.
4. **Variance**: Average squared distance from the mean. It shows how widely values are spread.
5. **Standard deviation**: Square root of variance. It is in the same unit as the data, so it is easier to read.
6. **Together**: Mean and median show the centre. If they differ much, the data is skewed. A large standard deviation means values are scattered.

Worked example, data: 2, 4, 4, 4, 5, 5, 7, 9 (n = 8)
- Mean = 40 / 8 = 5
- Median = (4 + 5) / 2 = 4.5
- Mode = 4
- Sum of squared deviations = 9+1+1+1+0+0+4+16 = 32
- Sample variance = 32 / 7 = 4.57; sample standard deviation = 2.14
- (Population variance = 32 / 8 = 4; standard deviation = 2)

```python
import pandas as pd
s = pd.Series([2, 4, 4, 4, 5, 5, 7, 9])
print(s.mean(), s.median(), s.mode()[0])   # 5.0 4.5 4
print(s.var(), s.std())                    # 4.571... 2.138...
print(s.describe())                        # count, mean, std, min, quartiles, max
```
pandas uses the sample formula (divide by n - 1) by default.

### Q3. Explain the difference between Univariate, Bivariate and Multivariate analysis with suitable examples. [P1 | 8 marks]

| Basis | Univariate | Bivariate | Multivariate |
|---|---|---|---|
| Variables | One | Two | Three or more |
| Purpose | Describe one variable | Find relation between two | Study many variables together |
| Questions answered | Centre, spread, shape | Strength and direction of link | Combined effects, patterns |
| Techniques | Mean, median, frequency | Correlation, cross-tab | Correlation matrix, regression, PCA |
| Typical plots | Histogram, box plot, bar chart | Scatter plot, grouped bar | Heatmap, pair plot, 3D plot |
| Complexity | Lowest | Medium | Highest |

Examples:
1. **Univariate**: Analysing only student marks. Mean and spread are found, and a histogram shows the distribution.
2. **Bivariate**: Study hours against marks. A scatter plot and correlation show whether more study gives higher marks.
3. **Multivariate**: Marks against study hours, attendance and sleep. A correlation heatmap or pair plot shows how all variables relate, and multiple regression predicts marks.

```python
df["marks"].hist()                           # univariate
df.plot.scatter(x="hours", y="marks")        # bivariate
import seaborn as sns
sns.heatmap(df.corr(), annot=True)           # multivariate
```

### Q4. What is the role of Correlation and Covariance analysis in EDA? How do they help in understanding relationships between variables? [P2 | 8 marks]

Covariance measures how two variables change together. Correlation is the standardised form of covariance and measures the strength and direction of a linear relationship.

Formulas:
- Cov(X, Y) = Σ (xi - x̄)(yi - ȳ) / (n - 1)
- r = Cov(X, Y) / (sX × sY)

Role in EDA:
1. **Direction**: Positive means both rise together. Negative means one rises as the other falls.
2. **Strength**: r near +1 or -1 means a strong link. r near 0 means a weak linear link.
3. **Comparable scale**: r ranges from -1 to +1, so it can compare any pair of variables. Covariance depends on units and has no fixed range.
4. **Feature selection**: Variables strongly related to the target are useful. Strongly related predictors are redundant (multicollinearity).
5. **Overview**: A correlation matrix with a heatmap summarises all pairs quickly.
6. **Limit**: Correlation does not prove causation, and it detects only linear relations.

```python
import pandas as pd
df = pd.DataFrame({"hours": [1, 2, 3, 4, 5], "marks": [40, 50, 65, 70, 85]})
print(df.cov())    # hours-marks covariance = 27.5 (hours var 2.5, marks var 307.5)
print(df.corr())   # hours-marks correlation = about 0.99 (strong positive)
```

### Q5. What is Pattern Detection and Anomaly Identification? Explain how EDA techniques help in finding patterns and detecting outliers in a dataset. [P2 | 8 marks]

Pattern detection finds regular structures in data such as trends, clusters, seasonality and relationships. Anomaly identification finds values that differ strongly from the rest. These may be errors or rare real events.

Techniques:
1. **Box plot**: Shows median, quartiles and whiskers. Points beyond the whiskers are possible outliers.
2. **IQR rule**: IQR = Q3 - Q1. A value is an outlier if it is below Q1 - 1.5 × IQR or above Q3 + 1.5 × IQR.
3. **Z-score**: z = (x - mean) / standard deviation. A value with |z| above 3 is usually an outlier (2 is used for small samples).
4. **Scatter plot**: Shows trends, clusters and points far from the main cloud.
5. **Histogram**: Shows skewness and isolated values.

```python
import pandas as pd
s = pd.Series([10, 12, 11, 13, 12, 95])
q1, q3 = s.quantile(0.25), s.quantile(0.75)
iqr = q3 - q1                                    # 1.5
print(s[(s < q1 - 1.5*iqr) | (s > q3 + 1.5*iqr)])   # 95
z = (s - s.mean()) / s.std()
print(s[z.abs() > 2])                            # 95
```
Handling outliers: investigate first, then correct, remove or keep them depending on whether they are errors or genuine.

### Quick revision
- EDA means inspect, clean, summarise, visualise and find relations before modelling.
- Mean and median give the centre; variance and standard deviation give the spread; standard deviation is the square root of variance.
- Univariate uses one variable, bivariate two, multivariate three or more.
- r = Cov / (sX sY), ranges from -1 to +1; correlation is not causation.
- Outliers: IQR fences at Q1 - 1.5 IQR and Q3 + 1.5 IQR, z-score above 3, box plot and scatter plot.
