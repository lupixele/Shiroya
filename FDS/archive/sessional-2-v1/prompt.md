# Prompt: Exam-Ready Answers for FDS Sessional-II (Units 3, 4, 5)

Copy everything below the line into any AI agent. The questions, priorities and target marks are already included, so nothing else needs to be pasted.

---

You are preparing a student for the **Fundamentals of Data Science (FDS)** Sessional-II exam (B.Tech III Sem CSE, Data Science). Write **exam-ready answers** for the 15 questions listed at the bottom. The student will read, memorise and write these in the exam hall.

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

## Code rules

- Python 3, pandas style. Short, complete, runnable snippets. No more than 12 lines per snippet.
- Use small inline sample data so the code runs without any external file (for example `io.StringIO` or a small dict). Where a file is unavoidable, name it plainly (`data.csv`).
- Add the output as a short comment under the code only where it helps the examiner see the result.
- Cypher keywords in upper case. Show only the minimal pattern the question needs.
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

### Unit 3

1. Explain the different ways to read and write data in text format using Python. Hint: include methods like `read_csv()`, `read_table()` and `to_csv()`. [P1 | 8 marks | code required: a snippet for each method]
2. What is JSON data? Describe how to read and write JSON files in Python using suitable examples. [P1 | 8 marks | code required: `json.load`, `json.dump`, `json.loads`, `json.dumps`]
3. What is web scraping? Explain how XML and HTML data can be extracted using Python libraries. [P1 | 8 marks | code required: BeautifulSoup for HTML, `xml.etree.ElementTree` or lxml for XML]
4. What are binary data formats? Discuss how the HDF5 format is used for storing large numerical datasets. [P2 | 6 marks | short h5py or pandas `HDFStore` snippet]
5. How can we read data from Microsoft Excel files and interact with databases using Python? Mention relevant libraries such as pandas, sqlite3 or SQLAlchemy. [P2 | 8 marks | code required: `read_excel`, `sqlite3` connect/query, `read_sql`]

### Unit 4

1. What is Exploratory Data Analysis (EDA)? Explain its importance in the data analysis process. [P1 | 6 marks | include a text workflow diagram]
2. What are Descriptive Statistics? Explain how measures like mean, median, mode, variance and standard deviation help in understanding data. [P1 | 8 marks | include a small worked numeric example and a pandas snippet]
3. Explain the difference between Univariate, Bivariate and Multivariate analysis with suitable examples. [P1 | 8 marks | comparison table plus one example and typical plot for each]
4. What is the role of Correlation and Covariance analysis in EDA? How do they help in understanding relationships between variables? [P2 | 8 marks | include the formulas, the range of correlation, and a `df.corr()` / `df.cov()` snippet]
5. What is Pattern Detection and Anomaly Identification? Explain how EDA techniques help in finding patterns and detecting outliers in a dataset. [P2 | 8 marks | cover box plot, IQR rule, z-score and scatter plot]

### Unit 5

1. What is Neo4j? Explain how it is used for dealing with graph databases. [P1 | 8 marks | nodes, relationships, properties, labels, plus a small node-relationship diagram]
2. What is the Cypher Query Language? Explain its purpose and basic syntax used in Neo4j. [P1 | 8 marks | code required: `CREATE`, `MATCH`, `WHERE`, `RETURN`, `SET`, `DELETE` with one line each]
3. What is Text Mining and Analytics? Explain its importance in data science. [P2 | 6 marks | include the basic pipeline as a text flow]
4. Explain the role of the NLTK (Natural Language Toolkit) library in text mining and analytics. [P1 | 8 marks | code required: tokenization, stop-word removal, stemming or lemmatization, POS tagging]
5. What is SQLite? Describe how it can be used to store and manage text data in data analytics projects. [P3 | 6 marks | short `sqlite3` snippet: create table, insert, select]
