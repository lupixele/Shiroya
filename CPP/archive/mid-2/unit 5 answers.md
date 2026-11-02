# Object Oriented Programming through C++ — Unit 5 Answers (`unit 5 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp 5.pdf`](raw/cpp%205.pdf) *(Typed Unit 5 Answers)*
> - [`CPP/raw/Unit_5_Handwritten_Answers (1).pdf`](raw/Unit_5_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 5 Answers)*
>
> **Questions File:** [`question.md` — UNIT 5](question.md#unit-5)

---

## Q1. Explain the principles of exception handling in C++ with a simple flow example.

### Exception Handling
Exception handling in C++ is a mechanism to handle runtime errors (such as division by zero) without abnormally terminating the program.

### Principles of Exception Handling
1. **`try` block:** The code that may cause an error is placed inside the `try` block.
2. **`throw` statement:** When an error occurs, the program throws an exception using `throw`.
3. **`catch` block:** The matching `catch` block receives and handles the exception.
4. **Normal execution:** After the exception is handled, the program continues executing normally past the catch block.

### Flow Diagram
![Exception Handling Simple Flow](figures/unit5_q1_exception_flow.png)

### Code Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;

    try {
        if (b == 0)
            throw "Division by zero error!";
        cout << "Result = " << (a / b) << endl;
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    cout << "Program continues normally." << endl;
    return 0;
}
```

### Output
```text
Exception: Division by zero error!
Program continues normally.
```

---

## Q2. What are multiple catch statements? Explain with an example.

### Multiple Catch Statements
Multiple catch statements are used when a single `try` block can throw different types of exceptions. Each exception type has its own separate `catch` block.

When an exception is thrown:
- C++ inspects the catch blocks in top-to-bottom order.
- The **first matching** catch block is executed.
- All other catch blocks are skipped.

### Syntax
```cpp
try {
    // risky code
}
catch (int e) {
    // handles integer exception
}
catch (double e) {
    // handles double exception
}
catch (const char* e) {
    // handles string exception
}
```

### Code Example
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int choice = 1;

        if (choice == 1)
            throw 10;      // throws int
        else if (choice == 2)
            throw 3.14;    // throws double
        else
            throw "Error"; // throws string
    }
    catch (int e) {
        cout << "Caught integer: " << e << endl;
    }
    catch (double e) {
        cout << "Caught double: " << e << endl;
    }
    catch (const char* e) {
        cout << "Caught string: " << e << endl;
    }

    return 0;
}
```

### Output
```text
Caught integer: 10
```

---

## Q3. Describe the role of try, throw, and catch in exception handling with syntax.

### 1. `try`
- **Role:** Encloses the block of code that may produce an error.
- **Syntax:**
  ```cpp
  try {
      // code that may throw an exception
  }
  ```

### 2. `throw`
- **Role:** Used to throw an exception when a problem is detected. Control immediately leaves the `try` block.
- **Syntax:**
  ```cpp
  throw value;
  ```

### 3. `catch`
- **Role:** Receives and handles the thrown exception based on data type.
- **Syntax:**
  ```cpp
  catch (data_type variable) {
      // handling code
  }
  ```

### Code Example
```cpp
#include <iostream>
using namespace std;

int main() {
    int age = 15;

    try {
        if (age < 18)
            throw age; // throw integer
        cout << "Eligible to vote" << endl;
    }
    catch (int x) {
        cout << "Not eligible to vote. Age: " << x << endl;
    }

    return 0;
}
```

### Output
```text
Not eligible to vote. Age: 15
```

---

## Q4. Explain the steps to open, write, read, and close a file in C++ with sample code.

### File Handling Classes
C++ provides file handling using `<fstream>`:
- `ofstream`: Used for **writing** to files.
- `ifstream`: Used for **reading** from files.
- `fstream`: Used for **both reading and writing**.

### Four Steps
1. **Include `<fstream>`:** Header required for file operations.
2. **Open the file:** Using `ofstream` or `ifstream`.
3. **Write or Read data:** Using `<<` to write, or `getline()` / `>>` to read.
4. **Close the file:** Using `.close()`.

### Code Example
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // 1. Open and write to file
    ofstream fout("sample.txt");
    fout << "Welcome to C++ File Handling";
    fout.close();

    // 2. Open and read from file
    ifstream fin("sample.txt");
    string text;
    getline(fin, text);
    fin.close();

    cout << "File Content: " << text << endl;
    return 0;
}
```

### Output
```text
File Content: Welcome to C++ File Handling
```

---

## Q5. What is STL? Explain its components and programming model.

### Definition of STL
**STL (Standard Template Library)** is a collection of predefined template classes and functions in C++ used for common data structures and algorithms.

### Main Components of STL
1. **Containers:** Store and organize data (e.g., `vector`, `list`, `map`, `set`).
2. **Algorithms:** Predefined procedures that perform operations on containers (e.g., `sort()`, `find()`, `reverse()`).
3. **Iterators:** Pointer-like objects used to access and step through elements in a container.

### STL Programming Model
```text
Container ──► Iterator ──► Algorithm ──► Result
```
- **Containers** store the data.
- **Iterators** access elements in the container.
- **Algorithms** perform operations through iterators.

### Code Example
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Container
    vector<int> v = {30, 10, 20};

    // Algorithm working through iterators
    sort(v.begin(), v.end());

    cout << "Sorted vector: ";
    for (int x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
```

### Output
```text
Sorted vector: 10 20 30 
```

---

## Q6. What are iterators in STL? Explain their types and usage.

### Iterators
An **iterator** is a pointer-like object used to point to and traverse elements of an STL container.

### Types of Iterators

| Iterator Type | Movement | Access Mode | Example Containers |
| :--- | :--- | :--- | :--- |
| **Input Iterator** | Forward only | Read-only | Input streams |
| **Output Iterator** | Forward only | Write-only | Output streams |
| **Forward Iterator** | Forward only | Read & Write | `forward_list` |
| **Bidirectional Iterator** | Forward & Backward (`++`, `--`) | Read & Write | `list`, `map`, `set` |
| **Random Access Iterator** | Direct jumps (`+n`, `-n`, `[]`) | Read & Write | `vector`, `deque` |

### Code Example
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};

    // Traversal using iterator
    vector<int>::iterator it;
    cout << "Elements: ";
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}
```

### Output
```text
Elements: 10 20 30 40 
```

---

## Q7. Explain vectors, Lists, and maps in STL with syntax and suitable example.

### 1. Vector
A **vector** is a dynamic array that stores elements in contiguous memory.
- Fast random access using index.
- **Syntax:** `vector<int> v;`

### 2. List
A **list** is a doubly linked list.
- Fast insertion and deletion at any position.
- **Syntax:** `list<int> l;`

### 3. Map
A **map** stores data in sorted key-value pairs where each key is unique.
- **Syntax:** `map<int, string> m;`

### Comparison Table

| Container | Type | Access Mode | Main Feature |
| :--- | :--- | :--- | :--- |
| **Vector** | Dynamic array | Direct index (`[]`) | Fast random access, resizes dynamically |
| **List** | Doubly linked list | Sequential (`iterator`) | Fast insertion & deletion at any position |
| **Map** | Key-value pairs | Key lookup (`m[key]`) | Stores unique keys in sorted order |

### Code Example
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main() {
    // 1. Vector
    vector<int> v = {10, 20, 30};
    v.push_back(40);
    cout << "Vector: ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // 2. List
    list<int> l = {20, 30};
    l.push_front(10);
    l.push_back(40);
    cout << "List  : ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // 3. Map
    map<int, string> m;
    m[1] = "C++";
    m[2] = "Python";
    cout << "Map   : ";
    for (auto x : m)
        cout << "[" << x.first << ": " << x.second << "] ";
    cout << endl;

    return 0;
}
```

### Output
```text
Vector: 10 20 30 40 
List  : 10 20 30 40 
Map   : [1: C++] [2: Python] 
```
