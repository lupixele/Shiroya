# Fundamentals of Data Science — Unit 5 Answers (`unit 5 answers.md`)

> **Course:** `2501CS34` — Fundamentals of Data Science (FDS)  
> **Unit:** UNIT V – Data Science Tools (Neo4j, Cypher, NLTK, SQLite)  
> **Source Documents in [`raw/`](../raw/):**
> - [`raw/FDS 8M Sem Imp Questions.pdf`](../raw/FDS%208M%20Sem%20Imp%20Questions.pdf) *(8-Mark Important Questions)*
> - [`raw/FDS 2M Sem Imp  Questions.pdf`](../raw/FDS%202M%20Sem%20Imp%20%20Questions.pdf) *(2-Mark Short Questions)*
> - [`raw/III Sem FDS_Model Question Paper.pdf`](../raw/III%20Sem%20FDS_Model%20Question%20Paper.pdf) *(Model Question Paper — Unit V Section)*
> - [`raw/Neo4j_Aura_Colab_Very_Clear_Plain_PDF.pdf`](../raw/Neo4j_Aura_Colab_Very_Clear_Plain_PDF.pdf) *(Step-by-Step Practical Teaching Guide on Neo4j Aura & Colab)*
> - [`raw/nltk library for text analytics - Colab.pdf`](../raw/nltk%20library%20for%20text%20analytics%20-%20Colab.pdf) *(Practical Guide on NLTK Text Processing & POS Tagging)*
>
> **Questions Index:** [`questions.md` — UNIT V](questions.md#unit-v--data-science-tools)

---

## Table of Contents

### 8-Mark Descriptive Questions
1. [8M-Q1: Neo4j Architecture and Basic Features as a Graph Database](#8m-q1-describe-neo4j-and-its-basic-features-as-a-graph-database)
2. [8M-Q2: Demonstrating Basic Cypher Queries with Examples](#8m-q2-demonstrate-basic-cypher-queries-with-suitable-examples)
3. [8M-Q3: The Role of NLTK in Text Mining and Analytics](#8m-q3-describe-the-role-of-nltk-in-text-mining-and-analytics-with-suitable-examples)
4. [8M-Q4: Comparing Neo4j and SQLite (Data Models & Uses)](#8m-q4-analyze-the-differences-between-neo4j-and-sqlite-based-on-their-data-models-and-uses)
5. [8M-Q5: Tools for Text Analytics & Managing Text Data with SQLite](#8m-q5-apply-different-tools-used-for-text-analytics-and-review-the-use-of-sqlite-in-managing-text-based-data)

### 2-Mark Short Questions & Answers
- [2M-Q1: Mention the Purpose of Neo4j](#2m-q1-mention-the-purpose-of-neo4j)
- [2M-Q2: State the Basic Components of a Graph Database](#2m-q2-state-the-basic-components-of-a-graph-database)
- [2M-Q3: Define Cypher](#2m-q3-define-cypher)
- [2M-Q4: Summarize the Use of Cypher in Neo4j](#2m-q4-summarize-the-use-of-cypher-in-neo4j)
- [2M-Q5: Mention the Use of NLTK in Text Mining](#2m-q5-mention-the-use-of-nltk-in-text-mining)
- [2M-Q6: Differentiate Between Neo4j and SQLite](#2m-q6-differentiate-between-neo4j-and-sqlite)

---

## 8M-Q1. Describe Neo4j and its basic features as a graph database.

### 1. What is Neo4j?
**Neo4j** is the world’s leading open-source, highly scalable **native Graph Database Management System (GDBMS)**. Unlike traditional Relational Database Management Systems (RDBMS) that store data in tables and resolve connections through computationally expensive multi-table `JOIN` operations, Neo4j treats **relationships as first-class citizens** stored directly on disk alongside entities.

Neo4j is built on the **Labeled Property Graph (LPG)** model.

```
(Student:Person {name: "Aarav", gpa: 9.1}) ──[:ENROLLED_IN {semester: 3}]──> (Course:Subject {title: "Data Science"})
```

---

### 2. Core Components of the Labeled Property Graph (LPG) Model
1. **Nodes:** Represent discrete entities or domain objects (e.g., a Person, Company, Product, or Location). Analogous to a row in a relational table.
2. **Labels:** Group nodes into explicit categories or roles (e.g., `:Student`, `:Teacher`, `:Department`). A single node can carry multiple labels.
3. **Relationships (Edges):** Connect two nodes together with a direction (`-->`) and an explicit type (e.g., `[:FRIENDS_WITH]`, `[:WORKS_AT]`). Relationships can never be dangling—they always have a start node and an end node.
4. **Properties:** Arbitrary key-value metadata attributes stored on both nodes and relationships (e.g., `{name: "Aarav", since: 2024}`).

---

### 3. Key Architectural Features of Neo4j
* **Index-Free Adjacency (Native Graph Processing):** Each node maintains direct physical memory pointers to its adjacent neighboring nodes. Traversing relationships requires $O(1)$ constant-time pointer dereferencing rather than $O(N \log N)$ relational table scans and index lookups.
* **Declarative Cypher Query Language:** Provides an intuitive ASCII-art query syntax for pattern matching graph paths.
* **Full ACID Compliance:** Guarantees standard transactional reliability (**A**tomicity, **C**onsistency, **I**solation, **D**urability).
* **High Scalability & Cloud Deployment (Neo4j Aura):** Fully managed, zero-maintenance cloud database instances connecting directly to client runtimes (Google Colab, Python drivers, web apps).
* **Rich Data Science Ecosystem:** Built-in Graph Data Science (GDS) library supporting PageRank, Community Detection (Louvain), Shortest Path (Dijkstra), and Node Embeddings.

---

### 4. Real-World Applications of Neo4j
1. **Social Networking:** Calculating degrees of separation, friend recommendations, and mutual connections.
2. **Fraud Detection:** Identifying cyclical money transfers and synthetic identity rings in real time.
3. **Knowledge Graphs & Semantic Search:** Powering modern enterprise AI, ontology mapping, and retrieval-augmented generation (RAG).
4. **Supply Chain & Network Logistics:** Optimizing routing and dependency failure propagation.

---

## 8M-Q2. Demonstrate basic Cypher queries with suitable examples.

### 1. Overview of Cypher
**Cypher** is a declarative graph query language developed specifically for Neo4j. It utilizes visual ASCII-art conventions:
* `(n)` represents a **Node** (enclosed in round parentheses).
* `[r]` represents a **Relationship** (enclosed in square brackets).
* `-->` represents the **Direction** of the relationship.

---

### 2. Basic Cypher CRUD Query Demonstrations

#### A. CREATE (Creating Nodes and Relationships)
```cypher
// Create two student nodes and an instructor node
CREATE (s1:Student {roll_no: "25B11DS001", name: "Aarav", branch: "CSE-DS"})
CREATE (s2:Student {roll_no: "25B11DS002", name: "Bhavya", branch: "CSE-DS"})
CREATE (c:Course {code: "2501CS34", name: "Fundamentals of Data Science"})

// Create relationships between nodes with properties
CREATE (s1)-[:ENROLLED_IN {enrolled_date: "2026-07-15", grade: "A+"}]->(c)
CREATE (s2)-[:ENROLLED_IN {enrolled_date: "2026-07-16", grade: "A"}]->(c)
CREATE (s1)-[:FRIENDS_WITH {since: 2025}]->(s2)
```

#### B. MATCH and RETURN (Reading and Pattern Matching)
```cypher
// 1. Find all students enrolled in Fundamentals of Data Science
MATCH (s:Student)-[r:ENROLLED_IN]->(c:Course {code: "2501CS34"})
RETURN s.name AS Student_Name, s.roll_no AS Roll_Number, r.grade AS Grade;

// 2. Find mutual friends (graph path traversal)
MATCH (s1:Student {name: "Aarav"})-[:FRIENDS_WITH]-(s2:Student)
RETURN s2.name AS Friend;
```

#### C. WHERE (Filtering with Conditional Predicates)
```cypher
MATCH (s:Student)-[r:ENROLLED_IN]->(c:Course)
WHERE s.branch = "CSE-DS" AND r.grade = "A+"
RETURN s.name, c.name, r.grade;
```

#### D. SET (Updating Properties and Adding Labels)
```cypher
// Update student GPA and add HonorStudent label
MATCH (s:Student {roll_no: "25B11DS001"})
SET s.cgpa = 9.4, s:HonorStudent
RETURN s.name, s.cgpa, labels(s);
```

#### E. DELETE and DETACH DELETE (Removing Graph Elements)
```cypher
// Delete relationship only
MATCH (s:Student {name: "Aarav"})-[r:FRIENDS_WITH]->(s2:Student {name: "Bhavya"})
DELETE r;

// Delete a node and all connected incoming/outgoing relationships (DETACH DELETE)
MATCH (s:Student {roll_no: "25B11DS002"})
DETACH DELETE s;
```

#### F. Aggregation and Ordering
```cypher
MATCH (s:Student)-[:ENROLLED_IN]->(c:Course)
RETURN c.name AS Course, count(s) AS Student_Count
ORDER BY Student_Count DESC;
```

---

### 3. Connecting Python to Neo4j Aura (Colab Workflow)
As detailed in [`raw/Neo4j_Aura_Colab_Very_Clear_Plain_PDF.pdf`](../raw/Neo4j_Aura_Colab_Very_Clear_Plain_PDF.pdf):

```python
from neo4j import GraphDatabase

# Connection parameters
URI = "neo4j+s://<your-instance-id>.databases.neo4j.io"
AUTH = ("neo4j", "<your-password>")

# Create driver instance
driver = GraphDatabase.driver(URI, auth=AUTH)

def query_students(tx):
    query = """
    MATCH (s:Student)-[:ENROLLED_IN]->(c:Course)
    RETURN s.name AS name, c.name AS course
    """
    result = tx.run(query)
    return [(record["name"], record["course"]) for record in result]

with driver.session() as session:
    records = session.execute_read(query_students)
    for name, course in records:
        print(f"Student: {name} | Enrolled in: {course}")

driver.close()
```

---

## 8M-Q3. Describe the role of NLTK in text mining and analytics with suitable examples.

### 1. Overview of the Natural Language Toolkit (NLTK)
The **Natural Language Toolkit (NLTK)** is Python’s foundational library for symbolic and statistical Natural Language Processing (NLP) and text analytics. Text data in raw form is unstructured and noisy; NLTK provides standard pipelines to tokenize, normalize, tag, and structure raw human language for machine learning models.

---

### 2. Core Text Mining Pipeline in NLTK

```
Raw Text ──> Tokenization ──> Stopwords Removal ──> Stemming / Lemmatization ──> POS Tagging
```

#### A. Tokenization (Word & Sentence Level)
Breaking raw character sequences into discrete linguistic units (tokens).
* Sentence Tokenization: `nltk.sent_tokenize()`
* Word Tokenization: `nltk.word_tokenize()`

#### B. Stopwords Filtering
Eliminating high-frequency functional words (e.g., "the", "is", "at", "which") that carry minimal semantic weight:
```python
from nltk.corpus import stopwords
stop_words = set(stopwords.words("english"))
filtered_words = [w for w in tokens if w.lower() not in stop_words]
```

#### C. Normalization: Stemming vs. Lemmatization
* **Stemming (Porter/Snowball):** Rule-based chopping of word affixes (often produces non-dictionary words, e.g., `"running"` $\to$ `"run"`, `"studies"` $\to$ `"studi"`).
* **Lemmatization (WordNet):** Uses vocabulary and morphological analysis to return the legitimate dictionary base form known as the **lemma** (e.g., `"better"` $\to$ `"good"`).

#### D. Part-of-Speech (POS) Tagging
Labeling each token with its grammatical category based on contextual syntax.

| Token | POS Tag | Description |
| :---: | :---: | :--- |
| **Data** | `NN` | Noun, singular |
| **Science** | `NN` | Noun, singular |
| **is** | `VBZ` | Verb, 3rd person singular present |
| **rapidly** | `RB` | Adverb |
| **growing** | `VBG` | Verb, gerund/present participle |

---

### 3. Complete Implementation (Matching Colab Practical)

```python
import nltk
from nltk.tokenize import word_tokenize, sent_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

# Download essential NLTK linguistic corpora
nltk.download("punkt")
nltk.download("punkt_tab")
nltk.download("stopwords")
nltk.download("wordnet")
nltk.download("averaged_perceptron_tagger")
nltk.download("averaged_perceptron_tagger_eng")

raw_text = "Data Science transforms modern businesses. Machine Learning algorithms extract valuable insights from huge datasets."

# 1. Sentence Tokenization
sentences = sent_tokenize(raw_text)
print(f"Sentences ({len(sentences)}): {sentences}")

# 2. Word Tokenization
tokens = word_tokenize(raw_text)
print(f"\nTotal Word Tokens: {len(tokens)}")

# 3. Stopword Removal & Lowercasing
stop_words = set(stopwords.words("english"))
filtered_tokens = [w for w in tokens if w.isalnum() and w.lower() not in stop_words]
print(f"Filtered Tokens: {filtered_tokens}")

# 4. Lemmatization
lemmatizer = WordNetLemmatizer()
lemmatized = [lemmatizer.lemmatize(w) for w in filtered_tokens]
print(f"Lemmatized Tokens: {lemmatized}")

# 5. POS Tagging
pos_tags = nltk.pos_tag(filtered_tokens)
print("\nPart-of-Speech Tags:")
for word, tag in pos_tags:
    print(f"  {word:<15} -> {tag}")
```

---

## 8M-Q4. Analyze the differences between Neo4j and SQLite based on their data models and uses.

### 1. Conceptual Contrast
* **SQLite:** A self-contained, serverless, zero-configuration **Relational Database Management System (RDBMS)** that stores tables of rows and columns inside a single disk file.
* **Neo4j:** A distributed, client-server **Native Graph Database (GDBMS)** that stores nodes, directed relationships, and key-value properties.

---

### 2. Comprehensive Comparison Matrix

| Evaluation Parameter | SQLite | Neo4j |
| :--- | :--- | :--- |
| **Data Model** | **Relational Model** (Tables, Rows, Columns, Foreign Keys) | **Labeled Property Graph** (Nodes, Directed Edges, Properties) |
| **Underlying Philosophy** | Schema-first, tabular normalization, sets of tuples | Relationship-first, topological networks, paths |
| **Query Language** | Structured Query Language (**SQL**) | Declarative Graph Query Language (**Cypher**) |
| **Architecture** | **Embedded / Serverless** (runs inside client process memory) | **Client-Server / Cloud Engine** (Neo4j Aura, standalone daemon) |
| **Data Relationships** | Indirect via Foreign Keys; computed at query-time via `JOIN`s | Direct physical pointers on disk (**Index-Free Adjacency**) |
| **Performance on Complex Joins** | Degrades exponentially as `JOIN` depth exceeds 3–4 tables | Constant $O(1)$ pointer traversal independent of graph size |
| **Schema Flexibility** | Rigid schema (`CREATE TABLE` requires predefined column types) | Schema-free / dynamic (nodes can carry arbitrary properties) |
| **Storage Medium** | Single compact `.db` or `.sqlite` file on local filesystem | Multi-file database store directory with transaction logs |
| **Concurrency Support** | File-level locking (single writer, multiple readers) | Enterprise multi-user concurrency with fine-grained locks |

---

### 3. Querying Comparison: Friends of Friends

#### In SQLite (Relational SQL):
Requires a self-referential many-to-many junction table and a double `INNER JOIN`:
```sql
SELECT f2.friend_id 
FROM friendships f1
JOIN friendships f2 ON f1.friend_id = f2.user_id
WHERE f1.user_id = 101;
```

#### In Neo4j (Cypher):
Expressed directly as an intuitive path pattern:
```cypher
MATCH (u:User {id: 101})-[:FRIENDS_WITH]->()-[:FRIENDS_WITH]->(fof:User)
RETURN fof.name;
```

---

### 4. Ideal Use Cases
* **When to Choose SQLite:**
  * Embedded mobile/desktop applications (iOS/Android app local caches).
  * Single-user desktop data analysis and small transactional catalogs.
  * Intermediate staging environments for Pandas DataFrames.
* **When to Choose Neo4j:**
  * Complex connected networks (Social networks, LinkedIn degree paths).
  * Knowledge graphs, fraud ring detection, master data management.
  * Real-time recommendation engines traversing multi-hop relationships.

---

## 8M-Q5. Apply different tools used for text analytics and review the use of SQLite in managing text-based data.

### 1. Landscape of Tools Used for Text Analytics

| Tool / Library | Core Capabilities | Primary Strengths in Data Science |
| :--- | :--- | :--- |
| **NLTK** | Tokenization, POS tagging, WordNet corpus, syntactic parsing | Academic research, granular teaching, linguistic analysis |
| **spaCy** | Industrial-strength NLP, deep learning pipelines, dependency parsing | Production speed, optimized Cython execution, multi-lingual |
| **Scikit-Learn** | `CountVectorizer`, `TfidfVectorizer`, text classifiers (Naive Bayes, SVM) | Machine learning feature extraction and document classification |
| **Gensim** | Word2Vec, FastText, Topic Modeling (LDA - Latent Dirichlet Allocation) | Unsupervised semantic topic extraction from large text corpora |
| **Hugging Face Transformers** | Pretrained LLMs (BERT, RoBERTa, GPT) for contextual embeddings | State-of-the-art sentiment analysis, summarization, Q&A |

---

### 2. Using SQLite for Managing Text-Based Data
While often perceived purely as a numerical relational store, SQLite provides specialized features for text management:
1. **TEXT Storage Class:** Stores arbitrary-length variable strings encoded in UTF-8 without artificial column truncation.
2. **SQLite Full-Text Search (FTS5):** A high-performance virtual table module that builds an inverted keyword index over text columns, enabling millisecond keyword searches over millions of documents.

---

### 3. Practical Implementation: Text Ingestion & Full-Text Search in SQLite

```python
import sqlite3
import pandas as pd

# Connect to in-memory SQLite database
conn = sqlite3.connect("text_warehouse.db")
cursor = conn.cursor()

# 1. Create standard table for text records
cursor.execute("""
CREATE TABLE IF NOT EXISTS articles (
    article_id INTEGER PRIMARY KEY,
    title TEXT,
    author TEXT,
    content TEXT
)
""")

# 2. Create Full-Text Search virtual table (FTS5)
cursor.execute("""
CREATE VIRTUAL TABLE IF NOT EXISTS articles_fts USING fts5(
    title,
    content,
    content='articles',
    content_rowid='article_id'
)
""")

# 3. Insert text data
articles = [
    (1, "Introduction to Data Science", "Aarav", "Data Science uses statistics and machine learning to analyze data."),
    (2, "Graph Databases with Neo4j", "Bhavya", "Neo4j uses Cypher to query nodes and connected graph relationships."),
    (3, "Text Mining with NLTK", "Kiran", "NLTK is a powerful Python library for natural language processing and text analytics.")
]

cursor.executemany("INSERT INTO articles VALUES (?, ?, ?, ?)", articles)
# Populate FTS index
cursor.executemany("INSERT INTO articles_fts(rowid, title, content) VALUES (?, ?, ?)", 
                   [(a[0], a[1], a[3]) for a in articles])
conn.commit()

# 4. Perform ultra-fast keyword matching using FTS MATCH operator
search_query = "Neo4j OR NLTK"
cursor.execute("""
SELECT rowid, title, content 
FROM articles_fts 
WHERE articles_fts MATCH ?
""", (search_query,))

print("Search Results:")
for row in cursor.fetchall():
    print(f"ID: {row[0]} | Title: {row[1]} | Snippet: {row[2]}")

# 5. Seamless interaction with Pandas
df = pd.read_sql_query("SELECT * FROM articles", conn)
print("\nLoaded into Pandas DataFrame:")
print(df[["article_id", "title", "author"]])

conn.close()
```

---

## Unit V — 2-Mark Short Questions & Answers

### 2M-Q1. Mention the purpose of Neo4j.
**Neo4j** is a native graph database designed to **store, manage, and rapidly traverse highly interconnected data** by modeling entities as nodes and direct connections as relationships, avoiding expensive multi-table `JOIN` operations.

---

### 2M-Q2. State the basic components of a graph database.
1. **Nodes:** Domain entities (e.g., Person, Course).
2. **Relationships (Edges):** Directed connections linking nodes (e.g., `[:ENROLLED_IN]`).
3. **Labels:** Classification categories assigned to nodes (e.g., `:Student`).
4. **Properties:** Key-value attributes stored on nodes and relationships (e.g., `{name: "Aarav"}`).

---

### 2M-Q3. Define Cypher.
**Cypher** is a declarative, pattern-matching graph query language developed for Neo4j that uses intuitive ASCII-art syntax (such as `(node)-[:RELATIONSHIP]->(node)`) to create, query, and manipulate graph data.

---

### 2M-Q4. Summarize the use of Cypher in Neo4j.
Cypher is used to express complex topological graph operations—such as path finding, variable-length relationship traversals, node filtering, and pattern aggregation—in a human-readable, declarative syntax without writing procedural tree-search code.

---

### 2M-Q5. Mention the use of NLTK in text mining.
NLTK provides standardized algorithms, linguistic rules, and text corpora for **preprocessing unstructured human language**—including tokenization, stopword removal, stemming, lemmatization, and Part-of-Speech (POS) tagging—making text suitable for analytical modeling.

---

### 2M-Q6. Differentiate between Neo4j and SQLite.
* **Neo4j:** A graph database engine that stores data as nodes and relationships using the Cypher query language, optimized for deep multi-hop network traversals.
* **SQLite:** A lightweight, serverless relational database engine that stores data in structured tables of rows and columns using standard SQL, optimized for embedded tabular storage.
