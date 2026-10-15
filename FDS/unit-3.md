# Unit III: Data Loading, Storage and File Formats

> **Course Code:** `2501CS34` — Fundamentals of Data Science (FDS) | Aditya University  
> **Exam Scope:** Internal Examinations 2 (Mid-2)  
> **Questions Map:** [`questions.md` — Unit III](questions.md#unit-iii-data-loading-storage-and-file-formats)

---

## Question Overview & Revision Priority

| Q no. | Priority | Marks | Question Topic | Direct Answer Link |
| :---: | :---: | :---: | :--- | :--- |
| 1 | P1 | 8 | Methods to read and write data in text files (`open`, `read_csv`, `to_csv`) | [→ Question 1](#question-1--methods-to-read-and-write-data-in-text-files) |
| 4 | P1 | 8 | Structure and uses of JSON data format with examples (`json.loads/dumps`) | [→ Question 4](#question-4--structure-and-uses-of-json-data-format) |
| 6 | P1 | 8 | Collecting data from web pages using web scraping (`requests`, BeautifulSoup) | [→ Question 6](#question-6--web-scraping-workflow-using-beautifulsoup) |
| 8 | P1 | 8 | NoSQL MongoDB CRUD operations (`pymongo`: insert, find, update, delete) | [→ Question 8](#question-8--nosql-mongodb-crud-operations) |
| 2 | P2 | 6 | Reading large text files in pieces (`chunksize`, `nrows`) | [→ Question 2](#question-2--reading-large-text-files-in-pieces-chunking) |
| 3 | P2 | 6 | Working with delimited data formats (CSV, TSV, custom delimiters) | [→ Question 3](#question-3--working-with-delimited-data-formats) |
| 5 | P2 | 6 | Main features of HTML and XML data formats (comparison & parsing) | [→ Question 5](#question-5--main-features-of-html-and-xml-formats) |
| 7 | P2 | 8 | Binary data formats (HDF5) vs. traditional file formats | [→ Question 7](#question-7--binary-data-formats-hdf5-vs-traditional-formats) |

---

## Question 1 — Methods to Read and Write Data in Text Files

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Describe the methods used to read and write data in text files.

---

### Step-by-Step Solution

#### 1. Core Concepts & Python Built-in File Handling (`open`)
A text file stores data as plain characters. Python reads and writes it with the built-in `open()` function and with pandas functions.

1. **open() modes:** `"r"` reads, `"w"` writes (overwrites), `"a"` appends. Use `with` so the file closes automatically.
2. **Reading methods:** `read()` returns the whole file, `readline()` returns one line, `readlines()` returns a list of lines.
3. **Writing methods:** `write()` writes a string, `writelines()` writes a list of strings.

#### 2. pandas Methods & Delimited Text Handling
4. **read_csv():** Loads comma-separated text into a DataFrame. Useful arguments are `header`, `names`, `index_col`, `usecols` and `na_values`.
5. **read_table():** Same as `read_csv()` but the default separator is a tab.
6. **to_csv():** Writes a DataFrame to a text file. Use `index=False` to skip the index, `sep` to change the delimiter.
7. **Choice:** Use `open()` for free-form text and pandas for tabular text.

#### 3. Python Code Example & Verification
```python
import io, pandas as pd
with open("notes.txt", "w") as f:
    f.write("Asha,85\nRavi,72\n")
with open("notes.txt") as f:
    print(f.read())
df = pd.read_csv(io.StringIO("name,marks\nAsha,85\nRavi,72\n"))
tsv = pd.read_table(io.StringIO("name\tmarks\nAsha\t85\n"))
df.to_csv("out.csv", index=False)
# notes.txt content is printed; df has 2 rows, 2 columns
```

---

## Question 4 — Structure and Uses of JSON Data Format

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Describe the structure and uses of JSON data format with a suitable example.

---

### Step-by-Step Solution

#### 1. JSON Data Structure & Core Rules
JSON (JavaScript Object Notation) is a lightweight, text-based format for exchanging data. It is easy for humans to read and for machines to parse.

1. **Object:** A set of key-value pairs inside `{ }`. Keys are strings.
2. **Array:** An ordered list of values inside `[ ]`.
3. **Values:** string, number, true/false, null, object or array. They can be nested.

#### 2. Python Type Mapping, Uses & Advantages
4. **Python mapping:** object to `dict`, array to `list`, null to `None`, true to `True`.
5. **Uses:** Web APIs, configuration files, data exchange between server and client, and NoSQL storage such as MongoDB.
6. **Advantage:** Language independent and lighter than XML.

#### 3. JSON Sample & Python Implementation (`json` module)
Example:

```json
{"name": "Asha", "marks": [85, 90], "active": true, "address": {"city": "Kakinada"}}
```

```python
import json
d = json.loads('{"name": "Asha", "marks": [85, 90], "active": true}')
print(d["marks"][0])        # 85
s = json.dumps(d, indent=2) # dict to JSON string
with open("s.json", "w") as f:
    json.dump(d, f)         # dict to JSON file
with open("s.json") as f:
    d2 = json.load(f)       # JSON file to dict
```

`loads` and `dumps` work on strings. `load` and `dump` work on files.

---

## Question 6 — Web Scraping Workflow Using BeautifulSoup

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Demonstrate the process of collecting data from a web page using web scraping.

---

### Step-by-Step Solution

#### 1. Web Scraping Lifecycle Steps
Web scraping is the automatic extraction of data from web pages. `requests` fetches the page and BeautifulSoup parses the HTML.

Steps:

1. Choose the target URL and check the site's terms and robots.txt.
2. Send an HTTP GET request with `requests.get()`.
3. Check the status code (200 means success).
4. Parse the HTML with BeautifulSoup.
5. Locate elements by tag, class or id with `find()` and `find_all()`.
6. Extract text, links and table rows.
7. Store the result in a DataFrame or file.

#### 2. Fetching & Parsing HTML (`requests` & BeautifulSoup)
Fetch and parse:

```python
import requests
from bs4 import BeautifulSoup
resp = requests.get("https://example.com", timeout=10)
soup = BeautifulSoup(resp.text, "html.parser")
print(resp.status_code, soup.title.text)
```

#### 3. Extracting Elements (Text, Links & Tables)
Extract text, links and a table (sample HTML used so it runs offline):

```python
from bs4 import BeautifulSoup
html = """<h1>Report</h1><a href="/a">Link A</a>
<table><tr><th>Name</th></tr><tr><td>Asha</td><td>85</td></tr></table>"""
soup = BeautifulSoup(html, "html.parser")
print(soup.h1.text)                                  # Report
print([a["href"] for a in soup.find_all("a")])       # ['/a']
rows = [[c.text for c in r.find_all(["th", "td"])] for r in soup.find_all("tr")]
print(rows)                                          # [['Name', 'Marks'], ['Asha', '85']]
```

The code shows how text comes from tags, links from the `href` attribute, and a table from `tr`, `th` and `td` tags.

---

## Question 8 — NoSQL MongoDB CRUD Operations

**Priority:** Priority 1 (Must Prepare) | **Marks:** 8 Marks  
**Question:** Apply NoSQL Mongo DB CRUD operations to store and retrieve by taking suitable data as an example.

---

### Step-by-Step Solution

#### 1. Overview & Setup
MongoDB is a document-oriented NoSQL database. It stores data as JSON-like documents inside collections. CRUD means Create, Read, Update, Delete. A running MongoDB server on localhost is assumed. Sample data is a `students` collection.

#### 2. CRUD Operations in Python (`pymongo`)
Create:

```python
from pymongo import MongoClient
col = MongoClient("mongodb://localhost:27017/")["college"]["students"]
col.insert_one({"name": "Asha", "age": 20})
col.insert_many([{"name": "Ravi", "age": 21}, {"name": "Meena", "age": 19}])
```

Read:

```python
print(col.find_one({"name": "Asha"}))
for d in col.find({"age": {"$gt": 19}}):
    print(d)   # Asha and Ravi
```

Update:

```python
col.update_one({"name": "Asha"}, {"$set": {"age": 21}})
```

Delete:

```python
col.delete_one({"name": "Ravi"})
```

#### 3. Key MongoDB Points & Rules
Points:

1. **insert_one / insert_many:** add one or many documents. MongoDB adds a unique `_id` automatically.
2. **find / find_one:** retrieve documents using a filter. An empty filter returns all.
3. **$set:** changes only the given fields.
4. **delete_one:** removes the first matching document.
5. **Schema-less:** documents in one collection can have different fields.

---

## Question 2 — Reading Large Text Files in Pieces (Chunking)

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 6 Marks  
**Question:** Explain how a large text file can be read in pieces.

---

### Step-by-Step Solution

#### 1. Chunking Concepts (`nrows` vs. `chunksize`)
A very large file may not fit in memory. pandas can read it in smaller parts instead of loading it whole.

1. **nrows:** Reads only the first n rows. Used to preview a file.
2. **chunksize:** Makes `read_csv` return an iterator of DataFrames, each with the given number of rows.
3. **Processing:** Each chunk is processed and the partial results are combined, so memory use stays low.
4. **Use cases:** Large logs, aggregation, filtering rows before saving.

#### 2. Python Code Implementation & Verification
```python
import io, pandas as pd
data = "id,val\n" + "\n".join(f"{i},{i*2}" for i in range(1, 11))
first = pd.read_csv(io.StringIO(data), nrows=3)       # first 3 rows
total = 0
for chunk in pd.read_csv(io.StringIO(data), chunksize=4):
    total += chunk["val"].sum()
print(total)   # 110
```

The file is read in chunks of 4, 4 and 2 rows. The running total gives the same result as reading it whole.

---

## Question 3 — Working with Delimited Data Formats

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 6 Marks  
**Question:** Demonstrate how to work with delimited data formats using a suitable example.

---

### Step-by-Step Solution

#### 1. Delimited Format Concepts & Python Implementation
A delimited file separates fields with a fixed character: comma (CSV), tab (TSV), pipe or semicolon. In pandas the `sep` argument tells the reader which delimiter to use.

```python
import io, csv, pandas as pd
csv_txt = "name,age\nAsha,20\nRavi,21\n"
df1 = pd.read_csv(io.StringIO(csv_txt))
df2 = pd.read_csv(io.StringIO("name\tage\nAsha\t20\n"), sep="\t")
df3 = pd.read_csv(io.StringIO("name|age\nAsha|20\n"), sep="|")
for row in csv.reader(io.StringIO(csv_txt), delimiter=","):
    print(row)   # ['name', 'age'] then ['Asha', '20'] then ['Ravi', '21']
```

#### 2. Key Delimiter Rules & `csv` Module Methods
Points:

1. **CSV:** default `sep=","`.
2. **TSV:** use `sep="\t"`.
3. **Custom delimiter:** any character, for example `sep="|"`. A regular expression such as `sep=r"\s+"` handles variable spaces.
4. **csv module:** `csv.reader` gives each row as a list. `csv.writer` writes rows. `csv.DictReader` gives each row as a dictionary.

---

## Question 5 — Main Features of HTML and XML Formats

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 6 Marks  
**Question:** Classify the main features of HTML and XML data format with suitable examples.

---

### Step-by-Step Solution

#### 1. Feature Comparison Table (HTML vs. XML)
| Basis | HTML | XML |
|---|---|---|
| Full form | HyperText Markup Language | eXtensible Markup Language |
| Purpose | Display data in a browser | Store and transport data |
| Tags | Predefined (`<p>`, `<a>`, `<table>`) | User-defined |
| Strictness | Lenient, browser tolerates errors | Strict, must be well-formed |
| Closing tags | Some optional | Always required |
| Python tools | BeautifulSoup, `pd.read_html` | `xml.etree.ElementTree`, lxml, `pd.read_xml` |

#### 2. Structural Code Samples & Parsing Characteristics
HTML sample:

```html
<table><tr><th>Name</th></tr><tr><td>Asha</td></tr></table>
```

XML sample:

```xml
<students><student><name>Asha</name><marks>85</marks></student></students>
```

HTML describes how content looks. XML describes what the content means. Both are tree structured and use nested tags.

---

## Question 7 — Binary Data Formats (HDF5) vs. Traditional Formats

**Priority:** Priority 2 (Likely to Appear) | **Marks:** 8 Marks  
**Question:** Distinguish between Binary data formats such as HDF5 and traditional file formats. Indicate their advantages and suitable use cases.

---

### Step-by-Step Solution

#### 1. Architectural Comparison (HDF5 vs. CSV / TXT / JSON)
HDF5 (Hierarchical Data Format) is a binary format for storing large numerical arrays and tables in a hierarchy of groups and datasets. Traditional formats are CSV, TXT and JSON, which store data as readable text.

| Basis | HDF5 (binary) | CSV / TXT / JSON (text) |
|---|---|---|
| Storage | Binary bytes | Plain characters |
| Readability | Not human readable | Human readable |
| Speed | Fast read and write | Slower, needs parsing |
| File size | Compact, supports compression | Larger |
| Partial access | Read a slice without loading all | Must read sequentially |
| Metadata | Stores types and attributes | No built-in types |
| Structure | Groups and datasets | Flat rows or nested text |

#### 2. Key Advantages & Suitable Use Cases
Advantages of HDF5:

1. Handles very large datasets efficiently.
2. Reads only the required slice.
3. Keeps data types and metadata.
4. Supports compression.

Use cases: scientific data, machine learning arrays, sensor data, repeated fast access. Text formats suit small data, sharing and manual editing.

#### 3. Python Implementation Example (`h5py`)
```python
import h5py, numpy as np
with h5py.File("data.h5", "w") as f:
    f.create_dataset("scores", data=np.arange(10))
with h5py.File("data.h5", "r") as f:
    print(f["scores"][2:5])   # [2 3 4]
```

---

## Quick Revision

1. open() modes r, w, a; read() readline() readlines(); write() writelines().
2. read_csv uses comma, read_table uses tab; to_csv(index=False) writes output.
3. chunksize gives an iterator of DataFrames; nrows previews the first rows.
4. JSON: loads/dumps for strings, load/dump for files; object is dict, array is list.
5. Scraping flow: requests.get, BeautifulSoup, find_all, extract, store; MongoDB CRUD: insert_one, find, update_one with $set, delete_one.
