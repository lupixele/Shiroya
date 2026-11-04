# Object Oriented Programming through C++ — Unit 5 Answers

> **Questions File:** [questions.md — Unit 5](questions.md#unit-5)

---

## Question 1 — Exception Handling Principles & Structured Flow

> **Question:** Explain the principles and structured flow of exception handling in C++ using the try, throw, and catch keywords.

---

### Step-by-Step Solution

#### 1. Principles of Exception Handling
- **Exception:** A runtime error or anomalous condition (e.g., division by zero, out of memory, file not found) encountered during execution.
- **Core Principle:** **Separates error-detection code from error-handling code**.
  - Code that might cause an error is isolated in a `try` block.
  - The error is detected and signaled using `throw`.
  - The error is received and resolved in a `catch` block.

#### 2. Structured Execution Flow
1. **Try Block:** Encloses statements that may throw an exception.
2. **Throw Expression:** When an error condition occurs, an exception object/value is thrown via `throw value;`.
3. **Stack Unwinding:** Normal execution halts; the runtime searches up the call stack for an active, matching `catch` block. Local objects in scope are safely destroyed.
4. **Catch Block:** Receives the thrown value by type matching and executes recovery code. Normal execution resumes after the `catch` block.

```
+------------+       Error occurs
| try block  | ------------------------> throw exception;
+------------+                                  |
      |                                         v
Normal completion                      +-----------------+
(skips catch)                          | Matching catch? |
                                       +-----------------+
                                         | Yes         | No
                                         v             v
                                   Execute catch   terminate()
```

#### Code Example *(Illustrative snippet for question)*
```cpp
#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw "Error: Division by zero!"; // throw exception
    return (double)a / b;
}

int main() {
    int num = 10, den = 0;
    try {
        cout << "Attempting division..." << endl;
        double result = divide(num, den);
        cout << "Result: " << result << endl;
    }
    catch (const char* msg) { // catches thrown string literal
        cout << "Caught Exception: " << msg << endl;
    }
    cout << "Program resumes normally." << endl;
    return 0;
}
```

---

## Question 2 — Multiple Catch Blocks & Catch-All Handler

> **Question:** Write a program demonstrating multiple catch blocks for different exception types, and explain the utility of the catch-all handler (catch(...)).

---

### Step-by-Step Solution

#### 1. Multiple Catch Blocks
- A single `try` block can be followed by **multiple `catch` handlers**, each tailored to catch a specific exception type (`int`, `char`, `double`, `exception`).
- The compiler tests handlers in **top-to-bottom order**; the first handler with a matching type executes, while others are skipped.

#### 2. Catch-All Handler (`catch(...)`)
- **Syntax:** `catch (...) { // handle unknown error }`
- **Utility:** A safety net that catches **any** exception of any data type not caught by preceding blocks.
- **Rule:** Must **always be placed as the LAST catch block**, otherwise it masks all subsequent handlers and triggers a compiler error.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

void testException(int choice) {
    try {
        if (choice == 1) throw 404;                     // int exception
        else if (choice == 2) throw 'E';                // char exception
        else if (choice == 3) throw 3.14;               // double exception
        else throw "Unknown custom error!";             // string literal
    }
    catch (int e) {
        cout << "Caught Integer Exception Code: " << e << endl;
    }
    catch (char c) {
        cout << "Caught Character Exception: " << c << endl;
    }
    catch (double d) {
        cout << "Caught Floating-Point Exception: " << d << endl;
    }
    catch (...) { // Catch-all default handler (must be last)
        cout << "Caught Default/Unknown Exception!" << endl;
    }
}

int main() {
    testException(1); // Caught int
    testException(2); // Caught char
    testException(4); // Caught by catch(...)
    return 0;
}
```

---

## Question 3 — Stream Class Hierarchy & File Opening Modes

> **Question:** Explain the C++ stream class hierarchy (ios, istream, ostream, ifstream, ofstream, fstream) and describe file opening modes (ios::in, ios::out, ios::app).

---

### Step-by-Step Solution

#### 1. C++ Stream Class Hierarchy
- **Stream:** A sequence of bytes acting as an interface between programs and I/O devices/files.
- **Hierarchy Tree:**
```
                     +---------------+
                     |   ios_base    |
                     +---------------+
                             |
                     +---------------+
                     |      ios      |
                     +---------------+
                       /                                 v             v
              +-------------+   +-------------+
              |   istream   |   |   ostream   |
              +-------------+   +-------------+
                /    \                 /                   v      \               /      v
         +----------+  \             /  +----------+
         | ifstream |   v           v   | ofstream |
         +----------+  +-------------+  +----------+
                       |  iostream   |
                       +-------------+
                              |
                              v
                       +-------------+
                       |   fstream   |
                       +-------------+
```
- **`ios_base` & `ios`:** Top-level base classes; manage state flags, formatting flags, and stream buffers.
- **`istream`:** Input stream class; provides extraction operator `>>` (e.g., `cin`).
- **`ostream`:** Output stream class; provides insertion operator `<<` (e.g., `cout`, `cerr`).
- **`ifstream`:** Derived from `istream`; used for **reading** from disk files.
- **`ofstream`:** Derived from `ostream`; used for **writing** to disk files.
- **`fstream`:** Derived from `iostream`; supports **both reading and writing**.

#### 2. File Opening Modes (`ios::` flags)

| Mode | Meaning | Behavior |
|---|---|---|
| **`ios::in`** | Input | Opens file for **reading** (default for `ifstream`). Fails if file does not exist. |
| **`ios::out`** | Output | Opens file for **writing** (default for `ofstream`). Overwrites/truncates existing file. |
| **`ios::app`** | Append | Opens file to **append** at the end. Preserves existing contents; all writes go to EOF. |
| **`ios::binary`** | Binary | Opens file in raw **binary mode** (no newline conversion). |
| **`ios::trunc`** | Truncate | Discards existing content if file exists (default with `ios::out`). |

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Open in write + append mode
    fstream file;
    file.open("sample.txt", ios::out | ios::app);
    if (!file) {
        cout << "File open error!" << endl;
        return 1;
    }
    file << "Appending line into file.\n";
    file.close();
    return 0;
}
```

---

## Question 4 — Sequential Text File Reading & Writing Program

> **Question:** Write a C++ program that reads data from an existing text file and writes/appends formatted output to a target file.

---

### Step-by-Step Solution

#### 1. File Handling Steps
1. **Include Header:** `<fstream>` for file stream classes.
2. **Create Stream Objects:** `ifstream inFile; ofstream outFile;`.
3. **Open Files & Error Check:** Check `if (!inFile.is_open())` before processing.
4. **Read & Write Operations:** Use `getline()` or `>>` to read line-by-line; use `<<` to write formatted data to the target file.
5. **Close Streams:** Invoke `.close()` to flush buffers and release operating system handles.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Step 1: Create sample source file
    ofstream sourceFile("source.txt");
    sourceFile << "101 Alice 85.5\n";
    sourceFile << "102 Bob   92.0\n";
    sourceFile.close();

    // Step 2: Open source file for reading, target file for appending
    ifstream inFile("source.txt");
    ofstream targetFile("target.txt", ios::out | ios::app);

    if (!inFile || !targetFile) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    // Step 3: Read from source, write formatted data to target
    int id;
    string name;
    double marks;

    targetFile << "=== Formatted Student Records ===\n";
    while (inFile >> id >> name >> marks) {
        targetFile << "ID: " << id << " | Name: " << name << " | Marks: " << marks << "\n";
    }

    // Step 4: Close streams
    inFile.close();
    targetFile.close();
    cout << "Data copied and formatted successfully into target.txt" << endl;

    return 0;
}
```

---

## Question 5 — Standard Template Library (STL) Architecture & Functors

> **Question:** Describe the Standard Template Library (STL) programming model and explain the roles of Containers, Algorithms, Iterators, and Functors.

---

### Step-by-Step Solution

#### 1. STL Programming Model
- The **STL** is a generic library of template classes and algorithms providing reusable, highly optimized data structures and algorithms.
- **Decoupled Architecture:** Algorithms do **not** interact directly with containers. Instead, algorithms access container elements solely through **iterators**.

```
+------------+       iterators       +------------+
| Containers | <-------------------> | Algorithms |
+------------+                       +------------+
                                           ^
                                           | calls
                                     +------------+
                                     |  Functors  |
                                     +------------+
```

#### 2. The Four STL Components
1. **Containers:** Data structures that hold collections of objects in memory (e.g., `vector`, `list`, `map`).
2. **Iterators:** Smart pointer-like objects that traverse container elements (`begin()`, `end()`, `++`, `*it`).
3. **Algorithms:** Generic functions that execute operations on ranges of elements (e.g., `sort()`, `find()`, `count()`).
4. **Functors (Function Objects):** Classes that overload `operator()` so objects act like functions; passed to algorithms to customize comparison/sorting criteria.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Functor (Function Object)
struct GreaterThan {
    bool operator()(int a, int b) const { return a > b; }
};

int main() {
    vector<int> v = { 10, 40, 20, 50, 30 }; // Container

    // Algorithm sort using Functor and Iterators
    sort(v.begin(), v.end(), GreaterThan());

    cout << "Sorted descending: ";
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) { // Iterator
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

---

## Question 6 — std::vector vs std::list Comparison

> **Question:** Compare std::vector and std::list in terms of memory layout, random access, dynamic resizing overhead, and insertion/deletion time complexity.

---

### Step-by-Step Solution

#### 1. Comparison Table

| Dimension | `std::vector` | `std::list` |
|---|---|---|
| **Underlying Data Structure** | **Dynamic Contiguous Array** | **Doubly Linked List** |
| **Memory Layout** | Contiguous memory blocks in heap | Non-contiguous memory; nodes connected by pointers |
| **Random Access** | **$O(1)$ constant time** via index `v[i]` or `at(i)` | **$O(n)$ linear time**; must traverse sequentially |
| **Insertion / Deletion (Middle)** | **$O(n)$ slow**; requires shifting trailing elements | **$O(1)$ fast** once node position is reached |
| **Insertion / Deletion (End)** | **$O(1)$ amortized** fast (`push_back`) | **$O(1)$ fast** (`push_back`, `push_front`) |
| **Dynamic Resizing Overhead** | Reallocates larger array & copies all elements when full | No reallocation; nodes allocated individually |
| **Memory Overhead** | Unused reserved capacity | Stores 2 pointers (`prev`, `next`) per node |
| **Iterator Type** | Random-Access Iterator | Bidirectional Iterator |

#### Code Example *(Illustrative snippet for question)*
```cpp
#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    // std::vector: fast random access
    vector<int> vec = { 10, 20, 30 };
    cout << "Vector element at index 1: " << vec[1] << endl; // O(1)

    // std::list: fast bidirectional insertion
    list<int> lst = { 10, 30 };
    auto it = lst.begin();
    ++it; // point to 30
    lst.insert(it, 20); // O(1) insertion in middle without shifting

    cout << "List contents: ";
    for (int x : lst) cout << x << " "; // 10 20 30
    cout << endl;
    return 0;
}
```

---

## Question 7 — Sequence vs Associative Containers & std::map

> **Question:** Explain std::deque operations, contrast sequence containers with associative containers, and demonstrate key-value storage and retrieval using std::map.

---

### Step-by-Step Solution

#### 1. `std::deque` (Double-Ended Queue)
- Indexed container supporting fast **$O(1)$ insertion and deletion at BOTH ends** (`push_front`, `push_back`, `pop_front`, `pop_back`).
- Unlike `vector`, elements are stored across non-contiguous chunks; avoids full-array reallocation.

#### 2. Sequence Containers vs Associative Containers

| Feature | Sequence Containers (`vector`, `list`, `deque`) | Associative Containers (`map`, `set`, `multimap`) |
|---|---|---|
| **Element Organization** | Linear sequential order based on **insertion order** | Ordered automatically by **key value** |
| **Access Method** | By numeric **position / index** | By lookup **key** |
| **Underlying Structure** | Array / Linked List | Self-balancing binary tree (Red-Black Tree) |
| **Search Time** | Linear $O(n)$ without sorting | Logarithmic **$O(\log n)$** fast search |

#### 3. `std::map` Key-Value Storage
- Stores unique pairs of type `std::pair<const Key, Value>`.
- Automatically keeps keys sorted; accessed via `map[key]`.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
#include <deque>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1. std::deque operations
    deque<int> dq;
    dq.push_back(20);
    dq.push_front(10); // O(1) at front
    dq.push_back(30);  // 10, 20, 30
    cout << "Deque Front: " << dq.front() << ", Back: " << dq.back() << endl;

    // 2. std::map key-value storage and retrieval
    map<int, string> students;
    students[101] = "Alice";
    students[102] = "Bob";
    students[103] = "Charlie";

    cout << "Student with Roll 102: " << students[102] << endl;

    cout << "All Students (Sorted by Key):" << endl;
    for (const auto &pair : students) {
        cout << "  Roll: " << pair.first << " -> Name: " << pair.second << endl;
    }
    return 0;
}
```

---

## Question 8 — STL Algorithms & Iterator Interfaces

> **Question:** Demonstrate how STL algorithms (std::sort, std::find, std::count, std::reverse) operate on container elements through iterator interfaces.

---

### Step-by-Step Solution

#### 1. STL Algorithms Mechanism
- Declared in `<algorithm>`.
- Algorithms are **container-independent**: they operate on half-open iterator ranges `[begin, end)`.
- Algorithms query or reorder elements via iterator operations (`*it`, `++it`, `it != end`).

#### 2. The Four Common Algorithms
1. **`std::sort(first, last)`:** Sorts elements in ascending order ($O(n \log n)$ introsort).
2. **`std::find(first, last, val)`:** Linearly searches for `val`; returns iterator to element or `last` if not found.
3. **`std::count(first, last, val)`:** Counts occurrences of `val` in the range.
4. **`std::reverse(first, last)`:** Reverses the sequence in place.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = { 40, 10, 20, 10, 50, 10, 30 };

    // 1. std::count: count occurrences of 10
    int c = count(nums.begin(), nums.end(), 10);
    cout << "Count of 10: " << c << endl; // 3

    // 2. std::sort: sort ascending
    sort(nums.begin(), nums.end());
    cout << "Sorted: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 3. std::reverse: reverse in place
    reverse(nums.begin(), nums.end());
    cout << "Reversed: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    // 4. std::find: search for 50
    auto it = find(nums.begin(), nums.end(), 50);
    if (it != nums.end()) {
        cout << "Found value 50 at index: " << distance(nums.begin(), it) << endl;
    } else {
        cout << "Value 50 not found" << endl;
    }

    return 0;
}
```
