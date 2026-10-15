## Unit 3

| Q no. | Priority | Marks |
|---|---|---|
| 1 | P1 | 8 |
| 2 | P1 | 8 |
| 3 | P1 | 8 |
| 4 | P2 | 6 |
| 5 | P2 | 8 |

### Q1. Explain the different ways to read and write data in text format using Python. [P1 | 8 marks]

Text format data is stored as plain characters, usually in rows with a separator such as a comma or tab. pandas converts such files into a DataFrame, and a DataFrame can be written back to text.

#### read_csv()
Reads comma-separated text into a DataFrame. It is the most used reader.
```python
import io, pandas as pd
text = "name,marks\nAsha,80\nRavi,72"
df = pd.read_csv(io.StringIO(text))
print(df)   # 2 rows, columns name and marks
```
Useful arguments: `sep`, `header`, `names`, `index_col`, `usecols`, `na_values`, `nrows`, `skiprows`.

#### read_table()
Reads delimited text. The default separator is a tab.
```python
t = "name\tmarks\nAsha\t80\nRavi\t72"
df = pd.read_table(io.StringIO(t))
df2 = pd.read_csv(io.StringIO("a;b\n1;2"), sep=";")   # custom separator
```

#### read_fwf()
Reads fixed-width files, where each column occupies fixed character positions.
```python
df = pd.read_fwf(io.StringIO("Asha  80\nRavi  72"), names=["name", "marks"])
```

#### to_csv()
Writes a DataFrame to a text file.
```python
df.to_csv("out.csv", index=False)               # no row index
df.to_csv("out.txt", sep="\t", header=False)    # tab separated, no header
```

#### Built-in open()
Reads or writes raw text line by line when pandas is not needed.
```python
with open("out.csv") as f:
    for line in f:
        print(line.strip())
```

Points to remember:
1. `read_csv` and `read_table` are the same reader with different default separators.
2. Missing values are detected automatically and can be controlled with `na_values`.
3. Large files can be read in parts using `chunksize`.
4. `index=False` in `to_csv` avoids writing the row index as an extra column.

### Q2. What is JSON data? Describe how to read and write JSON files in Python using suitable examples. [P1 | 8 marks]

JSON (JavaScript Object Notation) is a lightweight text format for storing structured data as key-value pairs and lists. It is the standard format for web APIs.

Key points:
1. **Objects**: Written in braces, as `{"key": value}`. Python reads them as dict.
2. **Arrays**: Written in square brackets. Python reads them as list.
3. **Value types**: string, number, true/false, null. These become str, int/float, True/False, None.
4. **Human readable**: Text based, easy to share between languages.
5. **Nested**: Objects can contain other objects and arrays.

The `json` module has four functions. The ones ending in `s` work with strings. The others work with files.

| Function | Purpose |
|---|---|
| `json.loads(s)` | JSON string to Python object |
| `json.dumps(obj)` | Python object to JSON string |
| `json.load(f)` | JSON file to Python object |
| `json.dump(obj, f)` | Python object to JSON file |

```python
import json
s = '{"name": "Asha", "marks": [80, 72]}'
d = json.loads(s)                      # string -> dict
print(d["name"], d["marks"][0])        # Asha 80
print(json.dumps(d, indent=2))         # dict -> formatted string
with open("data.json", "w") as f:
    json.dump(d, f)                    # write file
with open("data.json") as f:
    d2 = json.load(f)                  # read file
print(d2 == d)                         # True
```

pandas can also handle JSON directly:
```python
import pandas as pd
df = pd.DataFrame(d)
df.to_json("df.json")
df3 = pd.read_json("df.json")
```

### Q3. What is web scraping? Explain how XML and HTML data can be extracted using Python libraries. [P1 | 8 marks]

Web scraping is the automated extraction of data from web pages. A program downloads the page source and picks out the required elements.

Steps:
1. **Request**: `requests.get(url).text` downloads the page.
2. **Parse**: A parser converts the text into a tree of tags.
3. **Select**: Elements are found by tag, attribute or path.
4. **Store**: Extracted values are saved as a list, DataFrame or file.

#### HTML with BeautifulSoup
```python
from bs4 import BeautifulSoup
html = "<body><h1>Prices</h1><a href='/a'>Item A</a><a href='/b'>Item B</a></body>"
soup = BeautifulSoup(html, "html.parser")
print(soup.h1.text)                    # Prices
for a in soup.find_all("a"):
    print(a.text, a["href"])           # Item A /a   then   Item B /b
```
`find_all()` returns all matching tags. `find()` returns the first match.

#### XML with xml.etree.ElementTree
```python
import xml.etree.ElementTree as ET
xml = "<students><student id='1'><name>Asha</name></student><student id='2'><name>Ravi</name></student></students>"
root = ET.fromstring(xml)
for s in root.findall("student"):
    print(s.get("id"), s.find("name").text)   # 1 Asha   then   2 Ravi
```

#### lxml
lxml is a fast parser that supports XPath for both HTML and XML.
```python
from lxml import html as lh
tree = lh.fromstring("<ul><li>A</li><li>B</li></ul>")
print(tree.xpath("//li/text()"))       # ['A', 'B']
```
pandas offers `read_html()` for tables in a page and `read_xml()` for simple XML files.

Note: Check the website's terms of use and robots.txt before scraping.

### Q4. What are binary data formats? Discuss how the HDF5 format is used for storing large numerical datasets. [P2 | 6 marks]

Binary data formats store data as bytes instead of readable text. They are smaller, faster to read and keep data types exactly.

Common formats: pickle (Python objects), HDF5, Parquet, Feather and Excel (.xlsx).

HDF5 (Hierarchical Data Format) is designed for large numerical data.
1. **Hierarchy**: Data is organised like folders (groups) and files (datasets).
2. **Fast partial access**: A slice can be read without loading the whole file.
3. **Compression**: Datasets can be compressed to save disk space.
4. **Metadata**: Attributes can be attached to groups and datasets.
5. **Cross-platform**: Readable from Python, C, MATLAB and others.

Using h5py:
```python
import h5py, numpy as np
with h5py.File("data.h5", "w") as f:
    f.create_dataset("scores", data=np.arange(10))
with h5py.File("data.h5", "r") as f:
    print(f["scores"][2:5])            # [2 3 4]
```
Using pandas (needs PyTables installed):
```python
import pandas as pd
df = pd.DataFrame({"a": [1, 2, 3]})
store = pd.HDFStore("store.h5")
store["df"] = df
print(store["df"])
store.close()
```

### Q5. How can we read data from Microsoft Excel files and interact with databases using Python? [P2 | 8 marks]

Python reads Excel files through pandas, which uses the openpyxl library for .xlsx files. Databases are accessed through sqlite3 (built in), SQLAlchemy (many databases) and pandas SQL functions.

#### Excel with pandas
```python
import pandas as pd
df = pd.read_excel("data.xlsx", sheet_name="Sheet1")
df.to_excel("out.xlsx", index=False)
xl = pd.ExcelFile("data.xlsx")
print(xl.sheet_names)                  # list of sheets
```
Use `ExcelFile` when one workbook has many sheets.

#### Database with sqlite3
sqlite3 gives direct access to an SQLite database.
```python
import sqlite3
con = sqlite3.connect(":memory:")
con.execute("CREATE TABLE s(name TEXT, marks INT)")
con.execute("INSERT INTO s VALUES ('Asha', 80)")
con.commit()
print(con.execute("SELECT * FROM s").fetchall())   # [('Asha', 80)]
```

#### read_sql
```python
df = pd.read_sql("SELECT * FROM s", con)   # query result as DataFrame
```

#### SQLAlchemy
SQLAlchemy connects to SQLite, MySQL, PostgreSQL and others through one engine.
```python
from sqlalchemy import create_engine
engine = create_engine("sqlite:///college.db")
df.to_sql("s", engine, if_exists="replace", index=False)
print(pd.read_sql("SELECT * FROM s", engine))
```

Points to remember:
1. `commit()` is required to save inserts.
2. `to_sql` writes a DataFrame as a table.
3. Parameterised queries (`?`) prevent SQL injection.

### Quick revision
- read_csv uses comma, read_table uses tab; to_csv writes with index=False to skip the index.
- json.load/dump work with files; json.loads/dumps work with strings.
- BeautifulSoup parses HTML with find_all; ElementTree parses XML with findall; lxml supports XPath.
- HDF5 stores large numeric data in groups and datasets; use h5py or pd.HDFStore.
- read_excel needs openpyxl; sqlite3 uses connect, execute, commit; read_sql returns a DataFrame.
