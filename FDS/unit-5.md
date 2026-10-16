# Unit V: Data Science Tools

> **Course Code:** `2501CS34` — Fundamentals of Data Science (FDS) | Aditya University  
> **Exam Scope:** Internal Examinations 2 (Mid-2)  
> **Questions Map:** [`questions.md` — Unit V](questions.md#unit-v-data-science-tools)

---

## Question Overview & Revision Priority

| Q no. | Priority | Marks | Question Topic | Direct Answer Link |
| :---: | :---: | :---: | :--- | :--- |
| 1 | P1 | 8 | Neo4j architecture and features as a graph database | [→ Question 1](#question-1--neo4j-architecture-and-features-as-a-graph-database) |
| 2 | P1 | 8 | Demonstrating basic Cypher queries (`CREATE`, `MATCH`, `WHERE`, `SET`, `DELETE`) | [→ Question 2](#question-2--demonstrating-basic-cypher-queries-with-examples) |
| 3 | P1 | 8 | Role of NLTK in text mining and analytics (tokenization, stopwords, stemming, POS) | [→ Question 3](#question-3--role-of-nltk-in-text-mining-and-analytics) |
| 4 | P2 | 6 | Differences between Neo4j and SQLite (graph vs. relational models) | [→ Question 4](#question-4--differences-between-neo4j-and-sqlite) |
| 5 | P2 | 8 | Text analytics tools and using SQLite for text-based data management | [→ Question 5](#question-5--text-analytics-tools-and-sqlite-for-text-based-data) |

---

## Question 1 — Neo4j Architecture and Features as a Graph Database

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Describe Neo4j and its basic features as a graph database.

---

### Step-by-Step Solution

#### 1. Core Architectural Concepts & Components
Neo4j is a NoSQL graph database that stores data as nodes connected by relationships. It is designed for highly connected data and uses the Cypher query language.

1. **Nodes:** entities such as a student or a course.
2. **Relationships:** named, directed links between nodes, such as ENROLLED_IN. They are stored directly, so traversal is fast.
3. **Properties:** key-value pairs on nodes and relationships, such as `name` or `year`.
4. **Labels:** tags that group nodes, such as `Student` or `Course`.
5. **ACID:** transactions are atomic, consistent, isolated and durable.
6. **Schema flexibility:** nodes with the same label may have different properties.
7. **Cypher:** a readable, pattern-based query language.

#### 2. Graph Pattern Diagram
Pattern diagram:

```
(Asha:Student {age: 20}) -[:ENROLLED_IN {year: 2025}]-> (FDS:Course {title: "FDS"})
```

#### 3. Real-World Use Cases
Use cases: social networks, recommendation engines, fraud detection, knowledge graphs, network and route analysis.

---

## Question 2 — Demonstrating Basic Cypher Queries with Examples

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Demonstrate basic Cypher queries with suitable examples.

---

### Step-by-Step Solution

#### 1. Syntax Basics & Node Creation (CREATE)
Cypher describes graph patterns using `()` for nodes and `-[]->` for relationships.

```cypher
CREATE (a:Student {name: "Asha", age: 20})
CREATE (c:Course {title: "FDS"})
```
CREATE adds nodes with a label and properties.

#### 2. Creating Relationships (MATCH & CREATE)
```cypher
MATCH (a:Student {name: "Asha"}), (c:Course {title: "FDS"})
CREATE (a)-[:ENROLLED_IN]->(c)
```
Creates a relationship between two existing nodes.

#### 3. Filtering and Updating Properties (WHERE & SET)
```cypher
MATCH (s:Student) WHERE s.age > 18 RETURN s.name
```
MATCH finds the pattern, WHERE filters, RETURN gives the result.

```cypher
MATCH (s:Student {name: "Asha"}) SET s.age = 21
```
SET updates or adds a property.

#### 4. Pattern Matching and Relationships (RETURN)
```cypher
MATCH (s:Student)-[:ENROLLED_IN]->(c:Course) RETURN s.name, c.title
```
Relationship query: lists each student with their course.

#### 5. Deleting Elements (DELETE vs. DETACH DELETE)
```cypher
MATCH (:Student {name: "Asha"})-[r:ENROLLED_IN]->() DELETE r
MATCH (s:Student {name: "Asha"}) DETACH DELETE s
```
DELETE removes a relationship. A node with relationships needs DETACH DELETE, which removes the node and its relationships together.

---

## Question 3 — Role of NLTK in Text Mining and Analytics

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Describe the role of NLTK in text mining and analytics with suitable examples.

---

### Step-by-Step Solution

#### 1. Text Analytics Pipeline Overview
NLTK (Natural Language Toolkit) is a Python library for natural language processing. It supports text mining by providing tools to clean, split and tag text.

Pipeline:

```
Raw text -> Tokenization -> Stop-word removal -> Stemming / Lemmatization -> POS tagging -> Analysis
```

#### 2. Core NLTK Capabilities & Roles
Roles:

1. **Tokenization:** splits text into words or sentences.
2. **Stop-word removal:** drops common words such as "the" and "are".
3. **Stemming:** cuts words to a root form by removing suffixes.
4. **Lemmatization:** converts a word to its dictionary form using WordNet.
5. **POS tagging:** labels each word as noun, verb, adjective and so on.
6. **Corpora:** gives ready text collections and WordNet.

#### 3. Python Code Implementation & Verification
```python
import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords

text = "The cats are running faster than the dogs"
tokens = word_tokenize(text)

clean = [
    t for t in tokens
    if t.lower() not in stopwords.words("english")
]

print(clean)
```

##### Output

```
['cats', 'running', 'faster', 'dogs']
```

---

## Question 4 — Differences Between Neo4j and SQLite

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 6 Marks  
**Question:** Analyze the differences between Neo4j and SQLite based on their data models and uses.

---

### Step-by-Step Solution

#### 1. Comprehensive Comparison Table (Graph vs. Relational)
| Basis | Neo4j | SQLite |
|---|---|---|
| Data model | Graph of nodes and relationships | Relational tables of rows and columns |
| Query language | Cypher | SQL |
| Schema | Flexible, schema-optional | Fixed schema with defined columns |
| Relationships | Stored directly, fast traversal | Foreign keys and JOINs, slower for deep links |
| Scalability | Server database, scales to large connected data | Embedded single-file, small to medium data |
| Setup | Separate server | No server, one file |
| Typical uses | Social networks, recommendations, fraud detection | Mobile apps, small applications, local storage, prototypes |

#### 2. Architectural Selection & Use Cases
Use Neo4j when relationships are the main focus. Use SQLite when data is structured, tabular and needs a simple local store.

---

## Question 5 — Text Analytics Tools and SQLite for Text-Based Data

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 8 Marks  
**Question:** Apply different tools used for text analytics and review the use of SQLite in managing text-based data.

---

### Step-by-Step Solution

#### 1. Survey of Text Analytics Tools (NLTK, spaCy, scikit-learn, TextBlob, Gensim)
Text analytics tools:

1. **NLTK:** tokenization, stemming, tagging and corpora for learning and basic NLP.
2. **spaCy:** fast, production-oriented NLP with tokenization, POS tagging and named entity recognition.
3. **scikit-learn text features:** `CountVectorizer` and `TfidfVectorizer` convert text into numeric features for machine learning.
4. **TextBlob:** simple API for sentiment analysis and POS tagging.
5. **Gensim:** topic modelling and word embeddings such as LDA and Word2Vec.

#### 2. Managing Text Data with SQLite (`sqlite3`)
SQLite for text data: SQLite is a serverless, file-based relational database available in Python through `sqlite3`. It stores text in `TEXT` columns, and SQL queries search it with `LIKE`. It suits small corpora, storing cleaned documents and results, and quick keyword search.

#### 3. Python Code Implementation & Querying
```python
import sqlite3
con = sqlite3.connect(":memory:")
con.execute("CREATE TABLE docs (id INTEGER PRIMARY KEY, body TEXT)")
con.executemany("INSERT INTO docs (body) VALUES (?)",
                [("data science is fun",), ("big data tools",), ("hello world",)])
con.commit()
rows = con.execute("SELECT id, body FROM docs WHERE body LIKE ?", ("%data%",)).fetchall()
print(rows)   # [(1, 'data science is fun'), (2, 'big data tools')]
```

The query returns the documents that contain the word "data".

---

## Quick Revision

1. Neo4j stores nodes, relationships, labels and properties; it is ACID and queried with Cypher.
2. Cypher: CREATE adds, MATCH finds, WHERE filters, RETURN outputs, SET updates, DELETE removes (DETACH DELETE for nodes).
3. NLTK pipeline: tokenize, remove stop words, stem or lemmatize, POS tag.
4. Neo4j is graph and flexible; SQLite is relational, fixed schema and file based.
5. Text tools: NLTK, spaCy, scikit-learn TF-IDF, TextBlob, Gensim; SQLite uses LIKE for keyword search.
