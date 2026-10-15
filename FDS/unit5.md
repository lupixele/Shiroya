## Unit 5

| Q no. | Priority | Marks |
|---|---|---|
| 1 | P1 | 8 |
| 2 | P1 | 8 |
| 4 | P1 | 8 |
| 3 | P2 | 6 |
| 5 | P3 | 6 |

### Q1. What is Neo4j? Explain how it is used for dealing with graph databases. [P1 | 8 marks]

Neo4j is an open-source graph database. It stores data as nodes and relationships instead of tables, so connected data can be stored and queried directly. Its query language is Cypher.

Building blocks:
1. **Node**: An entity such as a student or a course.
2. **Label**: A type tag on a node, such as `Student`.
3. **Relationship**: A named, directed link between two nodes, such as `ENROLLED_IN`.
4. **Property**: A key-value pair stored on a node or relationship, such as `name: "Asha"`.

Diagram:
```
(Asha:Student {age: 19}) -[:ENROLLED_IN {year: 2025}]-> (FDS:Course {title: "FDS"})
```

How it is used:
1. **Model**: Identify entities as nodes and their links as relationships.
2. **Create**: Add nodes and relationships with Cypher.
3. **Query**: Traverse relationships with `MATCH` patterns, for example friends of friends.
4. **Update and delete**: Change properties or remove data.
5. **Tools**: Neo4j Browser or Desktop for visual queries, and a Python driver for programs.

Advantages over relational databases: relationships are stored directly, so multi-level joins are fast. The schema is flexible. Typical uses are social networks, recommendation systems, fraud detection and knowledge graphs.

### Q2. What is the Cypher Query Language? Explain its purpose and basic syntax used in Neo4j. [P1 | 8 marks]

Cypher is the declarative query language of Neo4j. Its purpose is to create, read, update and delete graph data by describing patterns. It is similar in role to SQL for tables.

Syntax rules:
1. Nodes are written in round brackets: `(s:Student)`.
2. Relationships are written in square brackets with an arrow: `-[:ENROLLED_IN]->`.
3. Properties are written in braces: `{name: 'Asha'}`.
4. Keywords are written in upper case.

```cypher
// CREATE: add nodes
CREATE (s:Student {name: 'Asha', age: 19})
CREATE (c:Course {title: 'FDS'})

// CREATE a relationship between existing nodes
MATCH (s:Student {name: 'Asha'}), (c:Course {title: 'FDS'})
CREATE (s)-[:ENROLLED_IN]->(c)

// MATCH, WHERE, RETURN: read data
MATCH (s:Student) WHERE s.age > 18 RETURN s.name

// SET: update a property
MATCH (s:Student {name: 'Asha'}) SET s.age = 20

// DELETE: remove a relationship
MATCH (:Student {name: 'Asha'})-[r:ENROLLED_IN]->() DELETE r

// DELETE a node together with its relationships
MATCH (s:Student {name: 'Asha'}) DETACH DELETE s
```

Meaning of keywords:
- `CREATE` adds nodes or relationships.
- `MATCH` finds a pattern in the graph.
- `WHERE` filters the matches.
- `RETURN` gives the output.
- `SET` changes properties.
- `DELETE` removes items. A node with relationships needs `DETACH DELETE`.

### Q3. What is Text Mining and Analytics? Explain its importance in data science. [P2 | 6 marks]

Text mining is the process of extracting useful patterns and knowledge from unstructured text such as reviews, emails, news and social media posts. Text analytics applies statistical and machine learning methods to that text to produce insights.

Pipeline:
```
Collect text -> Preprocess (tokenize, lowercase, remove stop words, stem/lemmatize)
-> Represent (bag of words, TF-IDF) -> Analyse (classify, cluster, topic model)
-> Interpret and report
```

Importance:
1. **Unstructured data**: Most real-world data is text, and it can be converted into usable form.
2. **Sentiment analysis**: Opinions in reviews and posts can be measured.
3. **Classification**: Spam filtering and news categorisation.
4. **Information extraction**: Names, dates and topics can be pulled from documents.
5. **Decision support**: Companies use customer feedback to improve products.

Example: Classifying product reviews as positive or negative.

### Q4. Explain the role of the NLTK (Natural Language Toolkit) library in text mining and analytics. [P1 | 8 marks]

NLTK is a Python library for natural language processing. It provides ready functions and text corpora for preparing and analysing text.

Role in text mining:
1. **Tokenization**: Splits text into words or sentences.
2. **Stop-word removal**: Removes common words such as "the" and "is" that carry little meaning.
3. **Stemming**: Cuts words to a root form by removing endings.
4. **Lemmatization**: Converts words to their dictionary form using vocabulary.
5. **POS tagging**: Labels each word with its part of speech, such as noun or verb.
6. **Corpora and tools**: Provides datasets, WordNet, frequency distribution (`FreqDist`) and classifiers.

Pipeline:
```
Raw text -> Tokenize -> Remove stop words -> Stem/Lemmatize -> POS tag -> Analysis
```

```python
import nltk
from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
for r in ["punkt", "punkt_tab", "stopwords", "wordnet",
          "averaged_perceptron_tagger", "averaged_perceptron_tagger_eng"]:
    nltk.download(r)
text = "The students are studying data science"
tokens = word_tokenize(text)
clean = [w for w in tokens if w.lower() not in stopwords.words("english")]
print(clean)   # ['students', 'studying', 'data', 'science']
```
```python
from nltk.stem import PorterStemmer, WordNetLemmatizer
print(PorterStemmer().stem("studying"))          # studi
print(WordNetLemmatizer().lemmatize("students")) # student
print(nltk.pos_tag(clean))                       # list of (word, tag) pairs
```
Difference: stemming is fast but may give non-words ("studi"). Lemmatization gives real words.

### Q5. What is SQLite? Describe how it can be used to store and manage text data in data analytics projects. [P3 | 6 marks]

SQLite is a lightweight, serverless relational database that stores the whole database in a single file. Python includes it through the `sqlite3` module, so no installation or server is needed.

Use for text data:
1. **Storage**: Reviews, tweets or articles are stored in a table with a TEXT column.
2. **Querying**: SQL filters text with `LIKE`, sorts it and counts it.
3. **Organisation**: Text is kept with metadata such as id and date.
4. **Integration**: Query results load into pandas with `read_sql`.
5. **Portability**: The single file is easy to copy and share.

```python
import sqlite3
con = sqlite3.connect("reviews.db")
con.execute("CREATE TABLE IF NOT EXISTS reviews(id INTEGER PRIMARY KEY, text TEXT)")
con.execute("INSERT INTO reviews(text) VALUES (?)", ("Great course",))
con.commit()
for row in con.execute("SELECT * FROM reviews WHERE text LIKE '%course%'"):
    print(row)   # (1, 'Great course')
con.close()
```

### Quick revision
- Neo4j stores data as nodes, relationships, labels and properties; it is queried with Cypher.
- Cypher keywords: CREATE, MATCH, WHERE, RETURN, SET, DELETE; use DETACH DELETE for nodes with relationships.
- Text mining pipeline: collect, preprocess, represent, analyse, interpret.
- NLTK provides tokenization, stop-word removal, stemming, lemmatization and POS tagging.
- SQLite is a serverless single-file database; use connect, execute, commit and SELECT with LIKE for text.
