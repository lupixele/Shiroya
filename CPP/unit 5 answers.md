# Object Oriented Programming through C++ — Unit 5 Answers (`unit 5 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp 5.pdf`](raw/cpp%205.pdf) *(Typed Unit 5 Answers)*
> - [`CPP/raw/Unit_5_Handwritten_Answers (1).pdf`](raw/Unit_5_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 5 Answers)*
>
> **Questions File:** [`question.md` — UNIT 5](question.md#unit-5)

---

## Q1. Explain the principles of exception handling in C++ with a simple flow example.

### Definition of Exception Handling
**Exception handling** is a built-in mechanism in C++ used to detect, report, and recover from runtime anomalies (errors such as division by zero, memory exhaustion, or file-not-found) without abruptly crashing the application.

Traditional error handling (like returning error codes) forces programs to mix error-checking logic with main computational logic. C++ exception handling separates normal program execution from error recovery.

---

### The Four Principles of Exception Handling

1. **Detecting the Error (`try` block):**
   Code that is suspect or capable of causing a runtime error is enclosed within a `try` block. The program monitors this block during execution.
2. **Throwing the Exception (`throw` statement):**
   When an anomaly occurs, the `throw` statement creates and dispatches an exception object. Program execution in the `try` block is halted immediately, and control transfers outwards.
3. **Catching and Handling (`catch` block):**
   A matching `catch` block intercepts the thrown exception based on data type and executes recovery code (logging, warning the user, or cleaning up resources).
4. **Resuming Normal Execution:**
   Once the catch block completes, control does not jump back to the point of failure; instead, it resumes sequentially after the catch block.

### Flow Diagram
![Exception Handling Simple Flow](figures/unit5_q1_exception_flow.png)

```text
       [ Start ]
           │
           ▼
     [ try Block ] (Risky Code)
           │
      Error occurs?
      ├─── No  ───► [ Continue Normal Execution ] ───┐
      │                                              │
     Yes                                             │
      ▼                                              │
 [ throw Exception ]                                 │
      │                                              │
      ▼                                              │
 [ catch Block ] (Handle Error)                      │
      │                                              │
      ▼                                              │
 [ Resume Execution After catch ] ◄──────────────────┘
      │
      ▼
   [ Stop ]
```

---

### Exam-Ready Program (Divide by Zero)
```cpp
#include <iostream>
using namespace std;

int main() {
    int numerator = 10, denominator = 0;

    try {
        // 1. Guarded region: check for condition that causes runtime error
        if (denominator == 0) {
            throw "Division by zero error!"; // 2. Throw exception
        }
        cout << "Result: " << (numerator / denominator) << endl;
    }
    catch (const char* errorMsg) {
        // 3. Catch and handle exception
        cout << "Caught Exception: " << errorMsg << endl;
    }

    // 4. Normal execution resumes safely
    cout << "Program resumes normal execution past the catch block." << endl;
    return 0;
}
```

### Output
```text
Caught Exception: Division by zero error!
Program resumes normal execution past the catch block.
```

---

## Q2. What are multiple catch statements? Explain with an example.

### Concept of Multiple Catch Blocks
In C++, a single `try` block can be followed by multiple consecutive `catch` blocks. This allows a single section of code to handle different types of exceptions (`int`, `double`, `const char*`, custom exception classes) with specialized recovery logic for each type.

### How Multiple Catch Blocks Work
1. When an exception is thrown, the runtime examines the catch blocks in **strict top-to-bottom order**.
2. The **first** catch block whose parameter type matches the type of the thrown exception is executed.
3. Once a matching catch block finishes, all remaining catch blocks are skipped.
4. **Catch-All Handler (`catch(...)`):** A special catch block using ellipsis `catch(...)` can be placed at the very end to catch any unmatched exception.

### Syntax
```cpp
try {
    // code that might throw different types
}
catch (int errorVal) {
    // handles integer error codes
}
catch (double errorVal) {
    // handles floating-point errors
}
catch (const char* msg) {
    // handles string/message errors
}
catch (...) {
    // default catch-all handler (must be placed last)
}
```

---

### Exam-Ready Program
```cpp
#include <iostream>
using namespace std;

void testException(int code) {
    try {
        if (code == 1)
            throw 404;                   // Throws integer
        else if (code == 2)
            throw 99.99;                 // Throws double
        else if (code == 3)
            throw "Access Denied";       // Throws C-string
        else
            throw 'X';                   // Throws char (caught by catch-all)
    }
    catch (int e) {
        cout << "[Integer Exception] Error Code : " << e << endl;
    }
    catch (double e) {
        cout << "[Double Exception] Value      : " << e << endl;
    }
    catch (const char* msg) {
        cout << "[String Exception] Message     : " << msg << endl;
    }
    catch (...) {
        cout << "[Default Handler] Unknown Exception Caught!" << endl;
    }
}

int main() {
    cout << "Test 1: "; testException(1);
    cout << "Test 2: "; testException(2);
    cout << "Test 3: "; testException(3);
    cout << "Test 4: "; testException(4);
    return 0;
}
```

### Output
```text
Test 1: [Integer Exception] Error Code : 404
Test 2: [Double Exception] Value      : 99.99
Test 3: [String Exception] Message     : Access Denied
Test 4: [Default Handler] Unknown Exception Caught!
```

### Important Exam Rule:
When dealing with inheritance hierarchies, **derived class catch blocks must always be placed before base class catch blocks**. If the base class catch block is placed first, it will catch all derived exceptions, making the derived catch block unreachable dead code.

---

## Q3. Describe the role of try, throw, and catch in exception handling with syntax.

### The Three Key Keywords

### 1. `try` Keyword
- **Role:** Designates a monitored block of statements where exceptions may occur. If any function called within the `try` block throws an exception, the `try` block immediately relinquishes control to an appropriate handler.
- **Syntax:**
  ```cpp
  try {
      // statements to monitor for exceptions
  }
  ```

### 2. `throw` Keyword
- **Role:** Explicitly raises or generates an exception. It takes an operand (an expression, primitive value, or object) and transfers program control directly to the matching catch block. Execution inside the `try` block halts immediately at the `throw` statement.
- **Syntax:**
  ```cpp
  throw exception_value;
  ```

### 3. `catch` Keyword
- **Role:** Defines the exception handler. It accepts an argument specifying the data type it is designed to process. When a matching exception is thrown, the block executes recovery actions (cleaning up, notifying the user).
- **Syntax:**
  ```cpp
  catch (Type parameter) {
      // exception handling and recovery statements
  }
  ```

---

### Complete Program Demonstrating All Three Roles
```cpp
#include <iostream>
using namespace std;

void checkAge(int age) {
    // 1. try: marks the guarded code block
    try {
        if (age < 18) {
            // 2. throw: raises an exception with the age value
            throw age;
        }
        cout << "Access granted: You are eligible to vote." << endl;
    }
    // 3. catch: receives and handles the thrown integer value
    catch (int rejectedAge) {
        cout << "Access denied: Age " << rejectedAge 
             << " is under 18 years old." << endl;
    }
}

int main() {
    cout << "Checking 20: "; checkAge(20);
    cout << "Checking 15: "; checkAge(15);
    return 0;
}
```

### Output
```text
Checking 20: Access granted: You are eligible to vote.
Checking 15: Access denied: Age 15 is under 18 years old.
```

### Summary of Sequence
$$\text{try block executes} \xrightarrow{\text{error detected}} \text{throw raises exception} \xrightarrow{\text{type match}} \text{catch block recovers}$$

---

## Q4. Explain the steps to open, write, read, and close a file in C++ with sample code.

### File Handling Classes in C++
File input/output in C++ is managed through the `<fstream>` standard library header, which provides three primary stream classes:
1. **`ofstream` (Output File Stream):** Used exclusively for **writing** data to files.
2. **`ifstream` (Input File Stream):** Used exclusively for **reading** data from files.
3. **`fstream` (File Stream):** Capable of **both reading and writing** to files.

---

### The Four Sequential Steps

| Step | Operation | Class / Method | Description |
| :---: | :--- | :--- | :--- |
| **1** | **Open File** | `open()` or Constructor | Connects the C++ stream object to a physical file on disk with a specified mode (e.g., `ios::out`, `ios::in`, `ios::app`). |
| **2** | **Write Data** | `<<` operator or `write()` | Transfers data from program memory onto the opened file. |
| **3** | **Read Data** | `>>` or `getline()` | Extracts stored content from the physical file into program variables. |
| **4** | **Close File** | `close()` method | Flushes write buffers to disk and frees the file handle allocated by the operating system. |

---

### Exam-Ready Program (Writing and Reading a File)
```cpp
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // ---------------------------------------------
    // Step 1 & 2: Open and Write to a File
    // ---------------------------------------------
    ofstream outFile("student.txt"); // Opens file in write mode

    if (!outFile) {
        cout << "Error creating file!" << endl;
        return 1;
    }

    outFile << "Aditya University C++ Course" << endl; // Write data
    outFile << "Roll: 101, Subject: OOP" << endl;
    outFile.close(); // Step 4: Close file

    cout << "File written and closed successfully." << endl;

    // ---------------------------------------------
    // Step 3 & 4: Open and Read from the File
    // ---------------------------------------------
    ifstream inFile("student.txt"); // Opens file in read mode

    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    cout << "\n--- Reading File Contents ---" << endl;
    string line;
    // Read file line by line using getline()
    while (getline(inFile, line)) {
        cout << line << endl;
    }

    inFile.close(); // Step 4: Close file
    return 0;
}
```

### Output
```text
File written and closed successfully.

--- Reading File Contents ---
Aditya University C++ Course
Roll: 101, Subject: OOP
```

---

## Q5. What is STL? Explain its components and programming model.

### Definition of STL
The **Standard Template Library (STL)** is a foundational software library included in C++. It provides a set of general-purpose, template-based classes and functions implementing common data structures and algorithms (such as dynamic arrays, linked lists, stacks, sorting, and searching).

### The Four Core Components of STL

1. **Containers:**
   Objects that store collections of data in memory.
   - *Sequence Containers:* Store data sequentially (`vector`, `list`, `deque`).
   - *Associative Containers:* Store sorted key-value pairs (`set`, `map`, `multiset`, `multimap`).
   - *Container Adapters:* Provide restricted interfaces (`stack`, `queue`, `priority_queue`).

2. **Algorithms:**
   Over 100 template functions that carry out computational procedures on containers (`sort()`, `find()`, `reverse()`, `count()`, `binary_search()`).

3. **Iterators:**
   Generalized pointer-like objects used to step through container elements. They act as the **vital link** that connects algorithms to containers.

4. **Function Objects (Functors):**
   Objects of a class that overload the call operator `operator()`, allowing them to be invoked like functions and passed as arguments to customize algorithms.

---

### The STL Programming Model
The defining architecture of the STL is that **Algorithms do not operate on containers directly**. Instead, Algorithms operate via **Iterators**, ensuring that a single algorithm (such as `std::sort`) can work across multiple containers without rewriting code.

```text
┌─────────────┐       Iterators (begin, end)       ┌─────────────┐
│  CONTAINER  │ ◄────────────────────────────────► │  ALGORITHM  │ ──► Output Result
│  (Data)     │                                    │  (Logic)    │
└─────────────┘                                    └─────────────┘
```

---

### Exam-Ready Program (Container + Algorithm + Iterator)
```cpp
#include <iostream>
#include <vector>    // Container
#include <algorithm> // Algorithm
using namespace std;

int main() {
    // 1. Container: vector of integers
    vector<int> numbers = {45, 12, 85, 32, 19};

    // 2. Algorithm: sort() operating through Iterators begin() and end()
    sort(numbers.begin(), numbers.end());

    cout << "Sorted STL Vector: ";
    // 3. Iterators used for traversal
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " "; // dereferencing iterator
    }
    cout << endl;

    return 0;
}
```

### Output
```text
Sorted STL Vector: 12 19 32 45 85 
```

---

## Q6. What are iterators in STL? Explain their types and usage.

### Definition & Purpose of Iterators
An **iterator** is an object in C++ that points to an element within an STL container and provides pointer-like operators (`*`, `++`, `--`, `==`) to navigate and access container elements.

### Why Are Iterators Used?
- **Decoupling:** Decouples algorithms from internal container memory layouts.
- **Uniform Syntax:** Provides a universal traversal syntax (`for (auto it = c.begin(); it != c.end(); ++it)`) regardless of whether the container is an array, tree, or linked list.

---

### The 5 Types of Iterators

```text
[ Input ]  ──┐
             ├──► [ Forward ] ──► [ Bidirectional ] ──► [ Random Access ]
[ Output ] ──┘
```

| Iterator Type | Movement | Access Mode | Supported Operations | Supported Containers |
| :--- | :--- | :--- | :--- | :--- |
| **1. Input Iterator** | Forward only | Read-only | `*it`, `++`, `==`, `!=` | `istream_iterator` |
| **2. Output Iterator** | Forward only | Write-only | `*it = val`, `++` | `ostream_iterator` |
| **3. Forward Iterator** | Forward only | Read & Write | Multi-pass `*it`, `++` | `forward_list`, `unordered_set` |
| **4. Bidirectional Iterator** | Forward & Backward | Read & Write | `++`, `--`, `*it` | `list`, `map`, `set` |
| **5. Random Access Iterator** | Arbitrary Jumps | Read & Write | `++`, `--`, `+n`, `-n`, `[]`, `<`, `>` | `vector`, `deque`, `array` |

---

### Exam-Ready Program
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 20, 30, 40, 50};

    // Declaring iterator explicitly
    vector<int>::iterator it;

    cout << "Forward Traversal using Iterator: ";
    for (it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << " "; // *it accesses the current value
    }
    cout << endl;

    // Random access demonstration:
    it = vec.begin();
    cout << "First Element  : " << *it << endl;
    cout << "Third Element  : " << *(it + 2) << endl; // Random jump (+2)

    return 0;
}
```

### Output
```text
Forward Traversal using Iterator: 10 20 30 40 50 
First Element  : 10
Third Element  : 30
```

---

## Q7. Explain vectors, Lists, and maps in STL with syntax and suitable example.

### 1. `std::vector` (Dynamic Array)
- **Concept:** A sequence container encapsulating dynamic contiguous arrays. It automatically resizes when elements are inserted or deleted.
- **Performance:** Constant-time $O(1)$ random access via index; $O(1)$ insertion/deletion at the end; $O(n)$ insertion in the middle.
- **Syntax:** `vector<DataType> vecName;`

### 2. `std::list` (Doubly Linked List)
- **Concept:** A sequence container implemented as a doubly linked list. Elements are scattered non-contiguously in memory, linked via forward and backward pointers.
- **Performance:** Constant-time $O(1)$ insertion and deletion anywhere once an iterator is obtained; sequential $O(n)$ access (does not support `[]` indexing).
- **Syntax:** `list<DataType> listName;`

### 3. `std::map` (Associative Key-Value Map)
- **Concept:** An associative container that stores key-value pairs sorted by unique keys. Implemented internally as a self-balancing binary search tree (Red-Black Tree).
- **Performance:** Logarithmic-time $O(\log n)$ search, insertion, and deletion.
- **Syntax:** `map<KeyType, ValueType> mapName;`

---

### Detailed Comparison Table

| Feature | `vector` | `list` | `map` |
| :--- | :--- | :--- | :--- |
| **Underlying Structure** | Dynamic contiguous array | Doubly linked list | Balanced Red-Black BST |
| **Access Speed** | $O(1)$ Fast random access | $O(n)$ Sequential only | $O(\log n)$ Key lookup |
| **Insertion / Deletion** | Slow in middle ($O(n)$), fast at end ($O(1)$) | Fast anywhere ($O(1)$) | Logarithmic ($O(\log n)$) |
| **Memory Contiguity** | Strict contiguous memory | Non-contiguous (pointer overhead) | Non-contiguous tree nodes |
| **Key Characteristics** | Replaces static C arrays | Efficient for frequent reordering | Key-to-value dictionaries |

---

### Unified Exam-Ready Program
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <string>
using namespace std;

int main() {
    // ----------------------------------------------------
    // 1. Vector: Dynamic Array
    // ----------------------------------------------------
    vector<int> v = {10, 20, 30};
    v.push_back(40); // Insert at end
    cout << "Vector elements (contiguous) : ";
    for (int x : v) cout << x << " ";
    cout << endl;

    // ----------------------------------------------------
    // 2. List: Doubly Linked List
    // ----------------------------------------------------
    list<int> l = {20, 30};
    l.push_front(10); // Fast insert at front: O(1)
    l.push_back(40);  // Fast insert at back: O(1)
    cout << "List elements (doubly linked) : ";
    for (int x : l) cout << x << " ";
    cout << endl;

    // ----------------------------------------------------
    // 3. Map: Key-Value Pairs
    // ----------------------------------------------------
    map<int, string> studentMap;
    studentMap[101] = "Alice";
    studentMap[102] = "Bob";
    studentMap[103] = "Charlie";

    cout << "Map elements (Key -> Value)  : ";
    for (auto entry : studentMap) {
        cout << "[" << entry.first << " : " << entry.second << "] ";
    }
    cout << endl;

    return 0;
}
```

### Output
```text
Vector elements (contiguous) : 10 20 30 40 
List elements (doubly linked) : 10 20 30 40 
Map elements (Key -> Value)  : [101 : Alice] [102 : Bob] [103 : Charlie] 
```
