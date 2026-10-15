## Unit V: Data Science Tools

| Q no. | Priority | Marks |
|---|---|---|
| 1 | P1 | 8 |
| 2 | P1 | 8 |
| 3 | P1 | 8 |
| 4 | P2 | 6 |
| 5 | P2 | 8 |

### Q1. Describe Neo4j and its basic features as a graph database. [P1 | 8 marks]

Neo4j is a NoSQL graph database that stores data as nodes connected by relationships. It is designed for highly connected data and uses the Cypher query language.

1. **Nodes:** entities such as a student or a course.
2. **Relationships:** named, directed links between nodes, such as ENROLLED_IN. They are stored directly, so traversal is fast.
3. **Properties:** key-value pairs on nodes and relationships, such as `name` or `year`.
4. **Labels:** tags that group nodes, such as `Student` or `Course`.
5. **ACID:** transactions are atomic, consistent, isolated and durable.
6. **Schema flexibility:** nodes with the same label may have different properties.
7. **Cypher:** a readable, pattern-based query language.

Pattern diagram:

```
(Asha:Student {age: 20}) -[:ENROLLED_IN {year: 2025}]-> (FDS:Course {title: "FDS"})
```

Use cases: social networks, recommendation engines, fraud detection, knowledge graphs, network and route analysis.

### Q2. Demonstrate basic Cypher queries with suitable examples. [P1 | 8 marks]

Cypher describes graph patterns using `()` for nodes and `-[]->` for relationships.

```cypher
CREATE (a:Student {name: "Asha", age: 20})
CREATE (c:Course {title: "FDS"})
```
CREATE adds nodes with a label and properties.

```cypher
MATCH (a:Student {name: "Asha"}), (c:Course {title: "FDS"})
CREATE (a)-[:ENROLLED_IN]->(c)
```
Creates a relationship between two existing nodes.

```cypher
MATCH (s:Student) WHERE s.age > 18 RETURN s.name
```
MATCH finds the pattern, WHERE filters, RETURN gives the result.

```cypher
MATCH (s:Student {name: "Asha"}) SET s.age = 21
```
SET updates or adds a property.

```cypher
MATCH (s:Student)-[:ENROLLED_IN]->(c:Course) RETURN s.name, c.title
```
Relationship query: lists each student with their course.

```cypher
MATCH (:Student {name: "Asha"})-[r:ENROLLED_IN]->() DELETE r
MATCH (s:Student {name: "Asha"}) DETACH DELETE s
```
DELETE removes a relationship. A node with relationships needs DETACH DELETE, which removes the node and its relationships together.

### Q3. Describe the role of NLTK in text mining and analytics with suitable examples. [P1 | 8 marks]

NLTK (Natural Language Toolkit) is a Python library for natural language processing. It supports text mining by providing tools to clean, split and tag text.

Pipeline:

```
Raw text -> Tokenization -> Stop-word removal -> Stemming / Lemmatization -> POS tagging -> Analysis
```

Roles:

1. **Tokenization:** splits text into words or sentences.
2. **Stop-word removal:** drops common words such as "the" and "are".
3. **Stemming:** cuts words to a root form by removing suffixes.
4. **Lemmatization:** converts a word to its dictionary form using WordNet.
5. **POS tagging:** labels each word as noun, verb, adjective and so on.
6. **Corpora:** gives ready text collections and WordNet.

```python
import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
for p in ["punkt", "punkt_tab", "stopwords", "wordnet", "averaged_perceptron_tagger", "averaged_perceptron_tagger_eng"]:
    nltk.download(p)
text = "The cats are running faster than the dogs"
tokens = word_tokenize(text)
clean = [t for t in tokens if t.lower() not in stopwords.words("english")]
print(clean)   # ['cats', 'running', 'faster', 'dogs']
```

```python
from nltk.stem import PorterStemmer, WordNetLemmatizer
print(PorterStemmer().stem("running"))                # run
print(WordNetLemmatizer().lemmatize("running", "v"))  # run
print(WordNetLemmatizer().lemmatize("cats"))          # cat
print(nltk.pos_tag(tokens)[:3])   # [('The', 'DT'), ('cats', 'NNS'), ('are', 'VBP')]
```

### Q4. Analyze the differences between Neo4j and SQLite based on their data models and uses. [P2 | 6 marks]

| Basis | Neo4j | SQLite |
|---|---|---|
| Data model | Graph of nodes and relationships | Relational tables of rows and columns |
| Query language | Cypher | SQL |
| Schema | Flexible, schema-optional | Fixed schema with defined columns |
| Relationships | Stored directly, fast traversal | Foreign keys and JOINs, slower for deep links |
| Scalability | Server database, scales to large connected data | Embedded single-file, small to medium data |
| Setup | Separate server | No server, one file |
| Typical uses | Social networks, recommendations, fraud detection | Mobile apps, small applications, local storage, prototypes |

Use Neo4j when relationships are the main focus. Use SQLite when data is structured, tabular and needs a simple local store.

### Q5. Apply different tools used for text analytics and review the use of SQLite in managing text-based data. [P2 | 8 marks]

Text analytics tools:

1. **NLTK:** tokenization, stemming, tagging and corpora for learning and basic NLP.
2. **spaCy:** fast, production-oriented NLP with tokenization, POS tagging and named entity recognition.
3. **scikit-learn text features:** `CountVectorizer` and `TfidfVectorizer` convert text into numeric features for machine learning.
4. **TextBlob:** simple API for sentiment analysis and POS tagging.
5. **Gensim:** topic modelling and word embeddings such as LDA and Word2Vec.

SQLite for text data: SQLite is a serverless, file-based relational database available in Python through `sqlite3`. It stores text in `TEXT` columns, and SQL queries search it with `LIKE`. It suits small corpora, storing cleaned documents and results, and quick keyword search.

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

### Quick revision

1. Neo4j stores nodes, relationships, labels and properties; it is ACID and queried with Cypher.
2. Cypher: CREATE adds, MATCH finds, WHERE filters, RETURN outputs, SET updates, DELETE removes (DETACH DELETE for nodes).
3. NLTK pipeline: tokenize, remove stop words, stem or lemmatize, POS tag.
4. Neo4j is graph and flexible; SQLite is relational, fixed schema and file based.
5. Text tools: NLTK, spaCy, scikit-learn TF-IDF, TextBlob, Gensim; SQLite uses LIKE for keyword search.
