# Object Oriented Programming through C++ — Unit 5 Answers

> **Questions File:** [questions.md — Unit 5](questions.md#unit-5)

---

## Question 1 — Stream Class Hierarchy

> **Question:** Explain the principles and structured flow of exception handling in C++ using the try, throw, and catch keywords.

---

### Step-by-Step Solution

#### 1. Hierarchy
- **Stream** = flow of bytes; C++ provides **class hierarchy** for console and file I/O.
- **`ios`** is the **base class**: stores **format flags, state flags** (`eofbit`, `failbit`, `badbit`).
- **`istream`** (input, `>>`, `get()`, `getline()`) and **`ostream`** (output, `<<`, `put()`, `write()`) derive from `ios`.
- **`iostream`** derives from both `istream` and `ostream`.

```
                 ios
                /   \
          istream   ostream
          /    \    /    \
   ifstream   iostream   ofstream
                 |
              fstream
```

#### 2. File Stream Classes (`<fstream>`)

| Class | Derived from | Purpose |
|---|---|---|
| **`ifstream`** | `istream` | **Read** from files |
| **`ofstream`** | `ostream` | **Write** to files |
| **`fstream`** | `iostream` | **Read and write** |
| `filebuf` | `streambuf` | Low-level file buffer |

- They **inherit** `<<`, `>>`, `get`, `put`, `read`, `write`, `seekg`, `seekp`, plus add **`open()`**, **`close()`**, **`is_open()`**.
- `cin` is object of `istream`; `cout` is object of `ostream`.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("demo.txt");      // ofstream inherits ostream::operator<<
    out << "Hello Streams";
    out.close();
    ifstream in("demo.txt");
    string s;
    in >> s;
    cout << s << endl;             // Hello
}
```

---

## Question 2 — File Operations (Sequential)

> **Question:** Write a program demonstrating multiple catch blocks for different exception types, and explain the utility of the catch-all handler (catch(...)).

---

### Step-by-Step Solution

#### 1. Steps
- **Step 1 — Include** `<fstream>`.
- **Step 2 — Open:** `ofstream out("file.txt");` (write) / `ifstream in("file.txt");` (read) or `obj.open("file.txt");`.
- **Step 3 — Check:** `if (!obj)` / `obj.is_open()` / `obj.fail()` → **error handling**.
- **Step 4 — Write/Read:** `out << data;` / `in >> data;` or `getline(in, line)`.
- **Step 5 — Close:** `obj.close();` (flushes buffer, releases file).

#### 2. Reading until EOF
- Use **`while (getline(in, line))`** or **`while (in >> x)`** — **not** `while(!in.eof())` (reads last value twice).

| Operation | Write | Read |
|---|---|---|
| Class | `ofstream` | `ifstream` |
| Operator | `<<` | `>>` |
| File missing | **Created** | **Fails** (`is_open()` false) |

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream out("data.txt");
    if (!out) { cerr << "Cannot open for writing\n"; return 1; }
    out << "Line 1\nLine 2\n";
    out.close();

    ifstream in("data.txt");
    if (!in.is_open()) { cerr << "Cannot open for reading\n"; return 1; }
    string line;
    while (getline(in, line)) cout << line << endl;
    in.close();
}
```

---

## Question 3 — Open Modes & File Pointers

> **Question:** Explain the C++ stream class hierarchy (ios, istream, ostream, ifstream, ofstream, fstream) and describe file opening modes (ios::in, ios::out, ios::app).

---

### Step-by-Step Solution

#### 1. File Open Modes
```cpp
stream.open("file", mode1 | mode2);
```

| Mode | Meaning |
|---|---|
| **`ios::in`** | Open for **reading** (default for `ifstream`) |
| **`ios::out`** | Open for **writing**; **truncates** existing content (default for `ofstream`) |
| **`ios::app`** | **Append**: all writes go to **end** |
| **`ios::binary`** | **Binary** mode (no newline translation) |
| **`ios::trunc`** | **Delete existing contents** on open |
| **`ios::ate`** | Open and **seek to end** immediately (can still write anywhere) |

#### 2. File Pointers
- **Get pointer** (read position) & **put pointer** (write position).

| Function | Purpose |
|---|---|
| **`seekg(pos)`** / `seekg(off, dir)` | **Move get pointer** |
| **`seekp(pos)`** / `seekp(off, dir)` | **Move put pointer** |
| **`tellg()`** | **Return current get position** |
| **`tellp()`** | **Return current put position** |

- **Direction:** `ios::beg` (start), `ios::cur` (current), `ios::end` (end).

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream f("note.txt", ios::out | ios::trunc);
    f << "ABCDEFGH";
    f.close();

    f.open("note.txt", ios::in | ios::ate);
    cout << "Size: " << f.tellg() << endl;      // 8
    f.seekg(2, ios::beg);
    char c; f.get(c);
    cout << c << endl;                           // C
    f.seekg(-1, ios::end);
    f.get(c); cout << c << endl;                 // H
}
```

---

## Question 4 — Binary File I/O

> **Question:** Write a C++ program that reads data from an existing text file and writes/appends formatted output to a target file.

---

### Step-by-Step Solution

#### 1. Binary I/O Functions
- Writes/reads **raw bytes** exactly as stored in memory (**faster, compact**, no formatting).
```cpp
out.write(reinterpret_cast<const char*>(&obj), sizeof(obj));
in.read(reinterpret_cast<char*>(&obj), sizeof(obj));
```
- Open with **`ios::binary`** flag.
- Use only **POD/fixed-size** records (e.g., `char name[20]`), **not `std::string`** or pointers.

#### 2. Steps
- Define **record structure** → open `ofstream` (`ios::binary`) → **`write()`** → close → open `ifstream` (`ios::binary`) → **`read()`** until fail → close.

| Basis | Text I/O | Binary I/O |
|---|---|---|
| Functions | `<<`, `>>` | `write()`, `read()` |
| Format | Human-readable | Raw bytes |
| Size | Larger | **Compact** |

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    int roll;
    char name[20];
};
int main() {
    Student s1 = {1, "Asha"}, s2 = {2, "Ravi"};
    ofstream out("stud.dat", ios::binary);
    out.write(reinterpret_cast<char*>(&s1), sizeof(Student));
    out.write(reinterpret_cast<char*>(&s2), sizeof(Student));
    out.close();

    Student t;
    ifstream in("stud.dat", ios::binary);
    while (in.read(reinterpret_cast<char*>(&t), sizeof(Student)))
        cout << t.roll << " " << t.name << endl;
    in.close();
}
```

---

## Question 5 — STL Overview

> **Question:** Describe the Standard Template Library (STL) programming model and explain the roles of Containers, Algorithms, Iterators, and Functors.

---

### Step-by-Step Solution

#### 1. Standard Template Library (STL)
- **Collection of generic, reusable template classes and functions** providing **data structures and algorithms**; part of C++ standard library.
- Benefits: **reusability, efficiency, type safety, less code**.

#### 2. Three Fundamental Components
- **Containers:** Objects that **store data** (`vector`, `list`, `set`, `map`).
- **Iterators:** **Pointer-like objects** to **traverse/access** container elements.
- **Algorithms:** **Generic functions** (`sort`, `find`, `reverse`) that **operate on ranges**.

#### 3. Interaction Model
- **Algorithms never touch containers directly** — they work through **iterators**.
- `container.begin()` / `container.end()` give the **range** → algorithm processes `[begin, end)`.
- This **decouples algorithms from containers**: **one algorithm works with many containers**.

```
 Container  ←→  Iterator  ←→  Algorithm
 (stores)       (bridge)      (processes)
```

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {4, 1, 3};                    // container
    sort(v.begin(), v.end());                     // algorithm + iterators
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";                       // 1 3 4
}
```

---

## Question 6 — Container Taxonomy

> **Question:** Compare std::vector and std::list in terms of memory layout, random access, dynamic resizing overhead, and insertion/deletion time complexity.

---

### Step-by-Step Solution

#### 1. Classification
- **Sequence containers:** Store elements in **linear order of insertion** — **`vector`, `list`, `deque`**.
- **Associative containers:** Store elements **sorted by key** (balanced tree) — **`set`** (unique keys), **`map`** (key–value pairs); fast **search by key**.

#### 2. Comparison Table

| Container | Type | Access | Insert/Erase | Search | Best use |
|---|---|---|---|---|---|
| **`vector`** | Sequence | **O(1)** random | End: **O(1)** amortized; middle: O(n) | O(n) | **Dynamic array**, frequent indexing |
| **`list`** | Sequence (doubly linked) | O(n) | **O(1)** at known position | O(n) | **Frequent middle insert/delete** |
| **`deque`** | Sequence | **O(1)** random | **O(1)** at both ends; middle: O(n) | O(n) | **Queue-like**, front/back operations |
| **`set`** | Associative | – | **O(log n)** | **O(log n)** | **Unique, sorted** elements |
| **`map`** | Associative | **O(log n)** by key | **O(log n)** | **O(log n)** | **Key → value dictionary** |

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
using namespace std;

int main() {
    vector<int> v = {1, 2};  v.push_back(3);
    list<int>   l = {1, 2};  l.push_front(0);
    deque<int>  d = {1, 2};  d.push_front(0); d.push_back(3);
    set<int>    s = {3, 1, 3, 2};                   // {1,2,3} unique & sorted
    map<string, int> m; m["A"] = 90;
    cout << v[2] << " " << l.front() << " " << d.size() << " " << s.size() << " " << m["A"];
}
```

---

## Question 7 — Iterator Categories

> **Question:** Explain std::deque operations, contrast sequence containers with associative containers, and demonstrate key-value storage and retrieval using std::map.

---

### Step-by-Step Solution

#### 1. Five Categories
- Iterators form a **hierarchy** — each category **supports all operations of the weaker one**:

```
Input / Output  →  Forward  →  Bidirectional  →  Random-Access
```

#### 2. Operations Table

| Category | Operations supported | Direction | Example containers/uses |
|---|---|---|---|
| **Input** | **Read** (`*it`), `++`, `==`, `!=`; **single pass** | Forward | `istream_iterator` |
| **Output** | **Write** (`*it = x`), `++`; **single pass** | Forward | `ostream_iterator`, `back_inserter` |
| **Forward** | Read/write, `++`; **multi-pass** | Forward | `forward_list`, `unordered_set` |
| **Bidirectional** | Forward ops + **`--`** | Both | **`list`, `set`, `map`** |
| **Random-Access** | Bidirectional + **`it + n`, `it - n`, `it[n]`, `<`, `>`, `it1 - it2`** | Both, jump | **`vector`, `deque`**, arrays |

#### 3. Key Points
- **`std::sort` needs random-access** iterators (so **not** usable on `list`; use `list::sort()`).
- Algorithms **choose efficient implementation** based on iterator category.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};
    auto r = v.begin();
    cout << *(r + 2) << " " << r[3] << endl;       // random access: 30 40

    list<int> l = {1, 2, 3};
    auto b = l.end(); --b;                         // bidirectional: -- allowed
    cout << *b << endl;                            // 3
    // l.begin() + 2;                              // ERROR: no random access
}
```

---

## Question 8 — Practical STL Integration

> **Question:** Demonstrate how STL algorithms (std::sort, std::find, std::count, std::reverse) operate on container elements through iterator interfaces.

---

### Step-by-Step Solution

#### 1. Components Used
- **`std::vector`:** dynamic array; **`push_back`**, indexing.
- **`std::list`:** doubly linked list; **`push_front`**, `sort()` member.
- **`std::map`:** sorted key–value pairs; `m[key] = value`.
- **`std::sort(begin, end)`:** sorts range (random-access iterators, **O(n log n)**).
- **`std::find(begin, end, value)`:** returns **iterator to first match** or **`end()`** if absent.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1};
    sort(v.begin(), v.end());                          // 1 2 5 8
    for (int x : v) cout << x << " ";
    cout << endl;

    auto it = find(v.begin(), v.end(), 5);             // search
    if (it != v.end()) cout << "Found 5 at index " << it - v.begin() << endl;

    list<int> l = {30, 10, 20};
    l.push_front(0);
    l.sort();                                          // list's own sort
    auto p = find(l.begin(), l.end(), 20);
    cout << (p != l.end() ? "20 in list" : "not found") << endl;

    map<string, int> marks = {{"Ravi", 80}, {"Asha", 95}};
    marks["Kiran"] = 70;
    for (auto &kv : marks) cout << kv.first << ": " << kv.second << endl;   // sorted by key
}
```
