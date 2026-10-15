# Prompt: Exam-Ready Answers for FDS IE 2 (Units 3, 4, 5)

Copy everything below the line into any AI agent. The questions, priorities and target marks are already included, so nothing else needs to be pasted.

---

You are preparing a student for the **Fundamentals of Data Science (FDS)** IE 2 exam (B.Tech III Sem CSE, Data Science). Write **exam-ready answers** for the 18 questions listed at the bottom. The student will read, memorise and write these in the exam hall.

## Hard rules (do not break these)

1. **No emojis, no icons, no decorative symbols** anywhere. Plain text only.
2. **No chatbot tone.** No greetings, no "Here is your answer", no "Great question", no "In conclusion", no closing summary sentences, no offers of further help.
3. **No filler and no repetition.** Every line must carry an exam point. Do not restate the question.
4. **Do not copy or refer to any existing answer PDF or answer file.** Write every answer fresh from standard course knowledge.
5. **Do not invent facts, function names, parameters or library features.** Use only real, standard Python, pandas, NumPy, h5py/PyTables, BeautifulSoup, lxml, requests, sqlite3, SQLAlchemy, Neo4j/Cypher and NLTK usage. If unsure of an exact detail, use the simpler, certainly correct form.
6. Use simple English. Short sentences. Explain the idea, skip implementation internals.

## Marks and length

Each question has a target mark value (6 or 8) given in the list. Follow it strictly.

| Marks | Length | Structure |
|---|---|---|
| 8 | 250-350 words, plus code where marked | Definition, 5-7 key points, one code or diagram element, a short comparison or use-case line where relevant |
| 6 | 170-250 words, plus code where marked | Definition, 4-5 key points, one short example |

Do not pad a 6-mark answer to look like an 8-mark one, and do not compress an 8-mark answer.

## Structure by question type

Decide from the question verb.

| Question verb | Format |
|---|---|
| What is X / Explain X | One or two line definition, then numbered key points (bold only the key term, then one plain line each) |
| Explain different ways / methods | One heading per method with a one-line purpose and a 2-4 line code snippet each |
| Describe how to read/write with Python | Short theory, then a complete runnable code block with the expected output in a comment |
| Explain difference between A, B and C | A comparison table (Basis / A / B / C), 5-6 rows, then one example per type |
| Role of X in Y | 4-6 points, each as "Point: how it helps" |
| Discuss / How is X used | Definition, working principle, 3-5 uses, one example |
| Demonstrate / Apply | One line of purpose, then a complete runnable code block with sample data and the output as a comment, then 2-3 lines on what the code shows |
| Classify / Distinguish / Analyze differences | A comparison table (Basis / A / B), 6-7 rows, then a short line on when to use each |
| Describe X and its features | Definition, 5-6 features as one-line points, one small example |

## Code rules

- Python 3, pandas style. Short, complete, runnable snippets. No more than 12 lines per snippet.
- Use small inline sample data so the code runs without any external file (for example `io.StringIO` or a small dict). Where a file is unavoidable, name it plainly (`data.csv`).
- Add the output as a short comment under the code only where it helps the examiner see the result.
- Cypher keywords in upper case. Show only the minimal pattern the question needs.
- MongoDB: use `pymongo` (`MongoClient`, `insert_one`, `insert_many`, `find`, `find_one`, `update_one`, `delete_one`). Use a local connection string and a small student or product collection as sample data. State that a running MongoDB server is assumed. Cover Create, Read, Update and Delete, one short snippet each.
- Use fenced code blocks with the language tag. Do not explain code line by line; one sentence above the block is enough.

## Diagrams

Use a diagram only where it truly helps (EDA workflow, Neo4j node-relationship pattern, NLTK pipeline). Draw it as a simple text flow using `->` or a plain ASCII box. No images, no decorative art.

## Priority tags (study order)

Each question carries a priority. Mirror it in the output so the student knows what to revise first.

- **P1 (Must prepare):** very likely to appear, core topic. Give the fullest answer for the assigned marks and include code or a diagram wherever marked.
- **P2 (Likely):** frequently asked, moderate weight. Standard answer for the assigned marks.
- **P3 (If time permits):** lower likelihood. Keep tight, at the lower end of the word range.

## Output format

- Markdown. Order: Unit 3, Unit 4, Unit 5.
- One `##` heading per unit. One `###` heading per question in this exact form:
  `### Q1. <question text> [P1 | 8 marks]`
- Keep the student's question numbering and wording.
- At the start of each unit, add a small table: Q no. / Priority / Marks, sorted P1 first, so the student can pick a revision order.
- At the end of each unit, add a section titled `Quick revision` with 5 one-line points, plain text, no emojis.
- If two questions overlap, give the full answer once and for the other write "Refer Q_" plus only the extra points needed.

## Questions

### Unit III: Data Loading, Storage and File Formats

1. Describe the methods used to read and write data in text files. [P1 | 8 marks | code: `open()`, `read_csv()`, `read_table()`, `to_csv()`]
2. Explain how a large text file can be read in pieces. [P2 | 6 marks | code: `chunksize` with `read_csv`, and `nrows`]
3. Demonstrate how to work with delimited data formats using a suitable example. [P2 | 6 marks | code: CSV, TSV and a custom delimiter using `sep`, plus the `csv` module]
4. Describe the structure and uses of JSON data format with a suitable example. [P1 | 8 marks | structure (objects, arrays, key-value), uses, code: `json.loads`, `json.dumps`, `json.load`, `json.dump`]
5. Classify the main features of HTML and XML data format with suitable examples. [P2 | 6 marks | comparison table plus a tiny HTML and XML sample]
6. Demonstrate the process of collecting data from a web page using web scraping. [P1 | 8 marks | steps as a numbered flow, code: `requests` plus BeautifulSoup, extract text, links and a table]
7. Distinguish between Binary data formats such as HDF5 and traditional file formats. Indicate their advantages and suitable use cases. [P2 | 8 marks | comparison table, advantages, use cases, short h5py or `HDFStore` snippet]
8. Apply NoSQL Mongo DB CRUD operations to store and retrieve by taking suitable data as an example. [P1 | 8 marks | code: create, read, update, delete with `pymongo`]

### Unit IV: Exploratory Data Analysis

1. Describe the commonly used measures of descriptive statistics with suitable examples. [P1 | 8 marks | central tendency, dispersion and shape; small worked numeric example and a pandas `describe()` snippet]
2. Demonstrate different data visualization techniques used in Exploratory Data Analysis with suitable examples. [P1 | 8 marks | histogram, box plot, scatter plot, bar chart, heatmap; matplotlib or seaborn snippet and one line on what each shows]
3. Analyze the correlation and covariance techniques by using suitable example. [P1 | 8 marks | formulas, interpretation of sign and range, worked small example, `df.corr()` and `df.cov()` snippet]
4. Differentiate between Univariate, Bivariate and Multivariate analysis with suitable examples. [P1 | 8 marks | comparison table plus one example and typical plot for each]
5. Analyze a dataset to identify possible Anomalies and Pattern Detection. [P2 | 8 marks | small dataset, IQR rule, z-score, box plot and scatter plot, pattern types such as trend and clusters]

### Unit V: Data Science Tools

1. Describe Neo4j and its basic features as a graph database. [P1 | 8 marks | nodes, relationships, properties, labels, ACID, schema flexibility; small node-relationship text diagram]
2. Demonstrate basic Cypher queries with suitable examples. [P1 | 8 marks | code: `CREATE`, `MATCH`, `WHERE`, `RETURN`, `SET`, `DELETE`, relationship query; one line of meaning for each]
3. Describe the role of NLTK in text mining and analytics with suitable examples. [P1 | 8 marks | code: tokenization, stop-word removal, stemming, lemmatization, POS tagging]
4. Analyze the differences between Neo4j and SQLite based on their data models and uses. [P2 | 6 marks | comparison table covering data model, query language, schema, relationships, scalability and typical uses]
5. Apply different tools used for text analytics and review the use of SQLite in managing text-based data. [P2 | 8 marks | list the tools (NLTK, spaCy, scikit-learn text features, TextBlob, Gensim) with one line each, then a short `sqlite3` snippet: create table, insert, select with LIKE]
