# Fundamentals of Data Science (2501CS34) — 2-Marks Short Answers

> **Course Code:** `2501CS34` | **Program:** B.Tech — III Semester | Aditya University  
> **Scope:** Section A (2-Mark Compulsory Questions — All 5 Units)  
> **Master Questions Index:** [`questions.md`](questions.md)

## UNIT I — Introduction to Data Science

### 1. Definition of Data Science

> **Question:** Define Data Science.

**Data Science** is an interdisciplinary field that uses **statistics, mathematics, programming, and domain knowledge** to extract meaningful insights and knowledge from structured and unstructured data. It involves collecting, processing, analyzing, and communicating data-driven findings to support decision-making.

### 2. Applications of Data Science

> **Question:** Mention any two applications of Data Science.

- **Healthcare:** Analyzes medical records and images to support disease prediction, diagnosis, and treatment planning.
- **Recommendation Systems:** Uses user preferences and behavior to recommend products, movies, music, or other relevant content.

### 3. History and Evolution of Data Science

> **Question:** Summarize the history and evolution of Data Science.

Data Science evolved from **statistics, mathematics, and scientific data analysis**, supported by the growth of computer-based data processing and databases. With advances in **machine learning, big data, and cloud computing**, it developed into an interdisciplinary field that extracts insights from large, diverse datasets.

### 4. Stages of the Data Science Lifecycle

> **Question:** List the major stages of the Data Science Lifecycle.

- **Problem Definition:** Identify the objective and define the problem to be solved.
- **Data Collection:** Gather relevant data from suitable sources.
- **Data Cleaning and Preparation:** Handle missing, duplicate, and inconsistent data.
- **Exploratory Data Analysis (EDA):** Examine data distributions, relationships, and patterns.
- **Modeling and Evaluation:** Build a model and assess its performance.
- **Deployment and Monitoring:** Use the solution and monitor its performance over time.

### 5. Types of Data

> **Question:** Classify data into structured, semi-structured and unstructured data.

- **Structured Data:** Organized in a fixed schema, usually rows and columns; for example, relational database tables.
- **Semi-Structured Data:** Does not follow a rigid tabular schema but contains tags or keys that organize it; for example, JSON and XML.
- **Unstructured Data:** Has no predefined data model or fixed structure; for example, images, videos, audio, and free-form text.

### 6. Tools and Technologies in Data Science

> **Question:** Mention any four tools and technologies used in Data Science.

- **Python:** Programming language used for data analysis, automation, and machine learning.
- **R:** Language and environment for statistical computing and visualization.
- **SQL:** Language used to retrieve and manipulate data in relational databases.
- **Apache Spark:** Distributed computing framework for processing large datasets.

## UNIT II — Data Collection and Pre-processing

### 1. Methods of Data Collection

> **Question:** Mention any two methods of data collection.

- **Primary Data Collection:** Collects original data directly through surveys, interviews, observations, or experiments.
- **Secondary Data Collection:** Uses already available data from databases, reports, research papers, or public datasets.

### 2. Purpose of Data Cleaning

> **Question:** State the purpose of data cleaning.

**Data cleaning** identifies and corrects or removes inaccurate, incomplete, duplicate, and inconsistent data. Its purpose is to improve **data quality, reliability, and analysis accuracy** before further processing.

### 3. Methods for Handling Missing Values

> **Question:** Summarize any two methods for handling missing values.

- **Imputation:** Replace missing values with an estimated value, such as the mean, median, or mode of the column.
- **Deletion:** Remove rows or columns with missing values when the amount of missing data is substantial and deletion will not introduce serious bias.

### 4. Normalization vs Standardization

> **Question:** Differentiate between normalization and standardization.

| Basis / Parameter | Normalization | Standardization |
|---|---|---|
| Purpose | Rescales values to a fixed range | Rescales values relative to the mean and standard deviation |
| Common formula | $x' = \frac{x-x_{min}}{x_{max}-x_{min}}$ | $z = \frac{x-\mu}{\sigma}$ |
| Typical result | Often ranges from 0 to 1 | Has mean 0 and standard deviation 1 |
| Sensitivity | Depends strongly on minimum and maximum values | Less dependent on the data range, but affected by outliers |

### 5. Purpose of Feature Engineering

> **Question:** State the purpose of feature engineering.

**Feature engineering** creates, transforms, or selects relevant input variables from raw data so that useful information is represented effectively for a model. It can improve **model accuracy, predictive performance, and interpretability**.

### 6. Data Integration and Data Aggregation

> **Question:** Explain data integration and data aggregation.

- **Data Integration:** Combines data from multiple sources into a unified dataset while resolving differences in format, structure, or naming.
- **Data Aggregation:** Groups and summarizes data using operations such as **sum, count, average, minimum,** or **maximum** to produce a compact view.

## UNIT III — Data Loading, Storage and File Formats

### 1. Operations on Text Files

> **Question:** Mention any two operations performed on text files.

- **Read:** Retrieves existing text content from a file for processing or analysis.
- **Write / Append:** Write creates or replaces file content, whereas append adds new content to the end of an existing file.

### 2. Purpose of Reading Text Files in Pieces

> **Question:** State the purpose of reading text files in pieces.

Reading a text file in **chunks** allows large files to be processed without loading the entire file into memory. It reduces memory usage and supports efficient, incremental data processing.

### 3. JSON, XML and HTML Data Formats

> **Question:** Differentiate between JSON, XML and HTML data formats.

| Basis / Parameter | JSON | XML | HTML |
|---|---|---|---|
| Structure | Key-value pairs, objects, and arrays | Hierarchical elements with tags and attributes | Elements and tags that define webpage content and structure |
| Main purpose | Data storage and exchange | Data representation and exchange | Displaying and structuring web content |
| Syntax | Lightweight and compact | Tag-based and usually more verbose | Tag-based, with predefined and standard elements |
| Typical use | Web APIs and configuration files | Structured document and data exchange | Webpage development and browser rendering |

### 4. Web Scraping

> **Question:** Summarize the concept of web scraping.

**Web scraping** is the automated process of extracting required information from websites. It commonly uses HTTP requests to retrieve webpages and parsing tools to identify and collect elements from their **HTML structure**.

### 5. Binary and HDF5 File Formats

> **Question:** Mention the purpose of Binary and HDF5 file formats.

- **Binary Files:** Store data as bytes rather than human-readable characters; they are useful for compact storage and efficient reading or writing of machine-oriented data.
- **HDF5 Files:** Store large and complex datasets in a hierarchical format containing datasets, groups, and metadata; they support efficient access to scientific and numerical data.

### 6. Uses of Excel Files, Databases and MongoDB

> **Question:** Identify the uses of Excel files, databases and Mongo DB in Data Science.

- **Excel Files:** Used to store, organize, inspect, calculate, and visualize small or moderately sized tabular datasets.
- **Databases:** Store and manage structured data and support querying, updating, and retrieving records, commonly using SQL in relational databases.
- **MongoDB:** A document-oriented NoSQL database used to store and query flexible, semi-structured documents in BSON format.

## UNIT IV — Exploratory Data Analysis (EDA)

### 1. Definition of Exploratory Data Analysis

> **Question:** Define Exploratory Data Analysis (EDA).

**Exploratory Data Analysis (EDA)** is the process of examining and summarizing a dataset using **statistical measures and visualizations** before formal modeling. It helps identify distributions, relationships, patterns, missing values, and potential anomalies.

### 2. Descriptive Statistical Measures

> **Question:** Mention any four descriptive statistical measures.

- **Mean:** Arithmetic average of all observations.
- **Median:** Middle value when observations are arranged in order.
- **Mode:** Most frequently occurring value.
- **Standard Deviation:** Measures the spread of observations around the mean.

### 3. Data Visualization Techniques

> **Question:** List any four data visualization techniques.

- **Histogram:** Displays the frequency distribution of numerical data.
- **Bar Chart:** Compares values or frequencies across categories.
- **Scatter Plot:** Shows the relationship between two numerical variables.
- **Box Plot:** Summarizes a distribution using quartiles, median, and potential outliers.

### 4. Correlation vs Covariance

> **Question:** Differentiate between correlation and covariance.

| Basis / Parameter | Correlation | Covariance |
|---|---|---|
| Meaning | Measures the strength and direction of a relationship between two variables | Measures how two variables vary together |
| Scale | Unitless and standardized | Depends on the units of both variables |
| Range | For Pearson correlation, ranges from $-1$ to $+1$ | Has no fixed range |
| Interpretation | Magnitude indicates the strength of a linear relationship | Magnitude is affected by the variables' scales; sign indicates direction |

### 5. Types of EDA

> **Question:** Classify EDA into univariate, bivariate and multivariate analysis.

- **Univariate Analysis:** Examines one variable to understand its distribution and summary statistics.
- **Bivariate Analysis:** Examines the relationship between two variables, such as through a scatter plot or correlation.
- **Multivariate Analysis:** Examines relationships and combined patterns among three or more variables.

### 6. Pattern Detection and Anomaly Identification

> **Question:** Summarize pattern detection and anomaly identification.

- **Pattern Detection:** Finds repeated trends, relationships, clusters, or regularities in data.
- **Anomaly Identification:** Detects observations that differ significantly from normal data behavior, which may indicate errors, unusual events, or potential fraud.

## UNIT V — Data Science Tools

### 1. Purpose of Neo4j

> **Question:** Mention the purpose of Neo4j.

**Neo4j** is a **graph database management system** designed to store, manage, and query highly connected data. It represents entities and their relationships directly, making it useful for social networks, recommendation systems, and fraud detection.

### 2. Basic Components of a Graph Database

> **Question:** State the basic components of a graph database.

- **Nodes:** Represent entities such as people, products, or places.
- **Relationships:** Represent connections between nodes and have a type and direction.
- **Properties:** Store key-value attributes of nodes or relationships.
- **Labels:** Classify nodes into categories, such as `Person` or `Product`.

### 3. Cypher

> **Question:** Define Cypher.

**Cypher** is a **declarative graph query language** used primarily with Neo4j to create, retrieve, update, and delete graph data. It expresses graph patterns using a readable, ASCII-art-like syntax for nodes and relationships.

### 4. Use of Cypher in Neo4j

> **Question:** Summarize the use of Cypher in Neo4j.

Cypher is used in Neo4j to **create nodes and relationships, find connected data, filter query results, and update or delete graph records**. For example:

```cypher
MATCH (p:Person)-[:FRIEND_OF]->(f:Person)
RETURN f;
```

This query finds people connected to a `Person` node through a `FRIEND_OF` relationship.

### 5. Use of NLTK in Text Mining

> **Question:** Mention the use of NLTK in text mining.

**NLTK (Natural Language Toolkit)** is a Python library used for processing and analyzing human language text. It provides tools for **tokenization, stop-word removal, stemming, lemmatization, part-of-speech tagging,** and other natural language processing tasks.

### 6. Neo4j vs SQLite

> **Question:** Differentiate between Neo4j and SQLite.

| Basis / Parameter | Neo4j | SQLite |
|---|---|---|
| Database model | Graph database | Relational database |
| Data representation | Nodes, relationships, and properties | Tables, rows, and columns |
| Query language | Cypher | SQL |
| Best suited for | Highly connected data and relationship traversal | Structured tabular data and lightweight relational applications |
