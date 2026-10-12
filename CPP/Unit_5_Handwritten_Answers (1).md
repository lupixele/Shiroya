# Object Oriented Programming through C++ — Unit 5 Handwritten Answers (`Unit_5_Handwritten_Answers (1)`)

> **Source PDF:** [`raw/Unit_5_Handwritten_Answers (1).pdf`](raw/Unit_5_Handwritten_Answers%20(1).pdf)  
> **Question Bank:** [`Question Bank_CPP_Unit 3_4_5.md`](Question%20Bank_CPP_Unit%203_4_5.md#unit-5)  
> **Typed Answers Companion:** [`cpp 5.md`](cpp%205.md)

---

## UNIT 5 - Question 1

### Q) Explain the principles of exception handling in C++ with a simple flow example.

### Answer
Exception handling in C++ is a mechanism used to handle runtime errors so that the program does not terminate abnormally.

#### Principles of Exception Handling
1. **`try` block** – code that may cause an error is placed inside the `try` block.
2. **`throw` statement** – when an error occurs, an exception is thrown using `throw`.
3. **`catch` block** – the thrown exception is caught and handled in the `catch` block.
4. **Control transfer** – after an exception is thrown, control moves from `try` to the matching `catch` block.
5. **Program continuation** – after handling the exception, the program can continue normally.

#### Simple Flow
```text
       Start
         ↓
     try block
         ↓
  Exception occurs
         ↓
       throw
         ↓
    catch block
         ↓
Handle error message
         ↓
 Program continues
```

#### Example Program
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10, b = 0;
    try {
        if (b == 0)
            throw "Division by zero";
        cout << "Result = " << a / b;
    }
    catch (const char* msg) {
        cout << "Exception: " << msg;
    }
    return 0;
}
```

#### Output
```text
Exception: Division by zero
```

Thus, exception handling in C++ uses `try`, `throw`, and `catch` to detect and handle runtime errors safely.

---

## UNIT 5 - Question 2

### Q) What are multiple catch statements? Explain with an example.

### Answer
Multiple catch statements in C++ are used to handle different types of exceptions separately. A single `try` block can be followed by more than one `catch` block. When an exception is thrown, the control moves to the `catch` block whose type matches the thrown exception. This makes the program more flexible and helps in handling different errors in different ways.

#### Points to remember
1. One `try` block can have many `catch` blocks.
2. Each `catch` block handles a different type of exception.
3. Only the first matching `catch` block is executed.
4. Multiple `catch` blocks improve error handling and clarity.

#### Syntax
```cpp
try {
    // code that may throw exception
}
catch(type1 variable) {
    // handle type1 exception
}
catch(type2 variable) {
    // handle type2 exception
}
```

#### Example Program
```cpp
#include <iostream>
using namespace std;

int main() {
    try {
        int choice = 2;
        if (choice == 1)
            throw 10;
        else if (choice == 2)
            throw 3.14;
        else
            throw 'A';
    }
    catch (int x) {
        cout << "Caught integer exception: " << x << endl;
    }
    catch (double y) {
        cout << "Caught double exception: " << y << endl;
    }
    catch (char z) {
        cout << "Caught character exception: " << z << endl;
    }
    return 0;
}
```

#### Output
```text
Caught double exception: 3.14
```

Thus, multiple catch statements are useful when a program can generate different types of exceptions. They allow each type of error to be handled separately and properly.

---

## UNIT 5 - Question 3

### Q) Describe the role of try, throw, and catch in exception handling with syntax.

### Answer
Exception handling in C++ is used to detect and handle runtime errors so that the program does not terminate abnormally. The three main keywords used are `try`, `throw`, and `catch`.

#### Role of try, throw and catch
1. **`try` block:** The code that may cause an exception is placed inside the `try` block.
2. **`throw` statement:** When an error occurs, an exception is generated using `throw`. Control immediately leaves the `try` block.
3. **`catch` block:** The thrown exception is received and handled in the `catch` block. It prevents abnormal termination of the program.
4. **Matching:** The type of value thrown must match the type of parameter in the `catch` block.
5. **Benefit:** It separates normal code from error-handling code and improves program reliability.

#### General Syntax
```cpp
try {
    // code that may cause exception
    throw value;
}
catch (data_type variable) {
    // code to handle exception
}
```

#### Example Program
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 20, b = 0;
    try {
        if (b == 0)
            throw "Division by zero";
        cout << "Result = " << a / b;
    }
    catch (const char* msg) {
        cout << "Exception caught: " << msg;
    }
    return 0;
}
```

#### Output
```text
Exception caught: Division by zero
```

Thus, `try` is used to test a block of code, `throw` is used to signal an exception, and `catch` is used to handle the exception. Together they form the basic mechanism of exception handling in C++.

---

## UNIT 5 - Question 4

### Q) Explain the steps to open, write, read, and close a file in C++ with sample code.

### Answer
File handling in C++ is used to store data permanently in a file. The common steps are opening a file, writing data, reading data, and closing the file.

#### Steps in File Handling
1. **Open the file** – create a file stream object using `ofstream`, `ifstream`, or `fstream` and open the file.
2. **Write to the file** – use insertion operator `<<` to write data into the file.
3. **Read from the file** – use extraction operator `>>` or `getline()` to read data from the file.
4. **Close the file** – use `close()` to close the file after the operation is completed.

#### Syntax
```cpp
ofstream fout;
fout.open("sample.txt");
fout << "Hello";
fout.close();

ifstream fin;
fin.open("sample.txt");
fin >> data;
fin.close();
```

#### Sample Program
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream fout;
    fout.open("sample.txt");
    fout << "Welcome to C++ File Handling";
    fout.close();

    ifstream fin;
    fin.open("sample.txt");
    string data;
    getline(fin, data);
    cout << "File Content: " << data;
    fin.close();
    return 0;
}
```

#### Output
```text
File Content: Welcome to C++ File Handling
```

Thus, in C++, files are opened using file stream objects, data is written or read, and the file is finally closed using `close()`.

---

## UNIT 5 - Question 5

### Q) What is STL? Explain its components and programming model.

### Answer
STL (Standard Template Library) is a part of C++ that provides ready-made classes and functions to store and process data efficiently. It supports generic programming and helps programmers write reusable and efficient code.

#### 1. Components of STL
- **a) Containers** – Used to store data. Examples: `vector`, `list`, `deque`, `set`, `map`.
- **b) Algorithms** – Functions used to perform operations like `sort`, `search`, `reverse`, `count`, etc.
- **c) Iterators** – Objects that point to elements of containers and connect containers with algorithms.
- **d) Function Objects** – Also called functors; objects that can act like functions.
- **e) Allocators** – Handle memory allocation for containers.

#### 2. Programming Model of STL
- The STL programming model is based on the interaction of containers, algorithms, and iterators.
- Containers store the data.
- Iterators are used to access elements in the containers.
- Algorithms work on the data through iterators.
- This model makes programs flexible, reusable, and independent of data type.

#### 3. Example Program
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 3};
    sort(v.begin(), v.end());
    cout << "Sorted elements: ";
    for (int x : v)
        cout << x << " ";
    return 0;
}
```

#### Output
```text
Sorted elements: 1 2 3 5 8
```

#### 4. Conclusion
Thus, STL provides powerful ready-made components like containers, algorithms, and iterators. Its programming model makes C++ programs simple, reusable, and efficient.

---

## UNIT 5 - Question 6

### Q) What are iterators in STL? Explain their types and usage.

### Answer
Iterators in STL are object-like entities (pointers-like) used to point to elements of containers. They act as a connection between containers and algorithms. Iterators are used to traverse, access, and manipulate elements in STL containers.

#### 1. Types of Iterators
1. **Input Iterator** – Used only for reading data sequentially.
2. **Output Iterator** – Used only for writing data sequentially.
3. **Forward Iterator** – Can move only in forward direction and can read/write.
4. **Bidirectional Iterator** – Can move both forward and backward.
5. **Random Access Iterator** – Can move directly to any position using `+`, `-`, etc.

#### 2. Usage of Iterators
- Used to traverse elements of containers like `vector`, `list`, and `map`.
- Used with STL algorithms such as `sort()`, `find()`, `reverse()`.
- `begin()` returns iterator to first element.
- `end()` returns iterator to the position after the last element.

#### 3. Example Program
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40};
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
    return 0;
}
```

#### Output
```text
10 20 30 40
```

#### 4. Conclusion
Thus, iterators are important components of STL. They help in accessing container elements efficiently and provide a link between containers and algorithms.

---

## UNIT 5 - Question 7

### Q) Explain vectors, lists, and maps in STL with syntax and suitable example.

### Answer
STL provides different containers to store data efficiently. Vector, list, and map are commonly used STL containers.

#### 1. Vector
A vector is a dynamic array. It stores elements in contiguous memory and allows fast random access. It can grow or shrink in size automatically.
- **Syntax:** `vector<int> v;`
- **Example:** `vector<int> v = {10, 20, 30};`

#### 2. List
A list is a doubly linked list. It allows easy insertion and deletion at any position, but does not support direct random access like vector.
- **Syntax:** `list<int> l;`
- **Example:** `list<int> l = {1, 2, 3};`

#### 3. Map
A map stores data in key-value pairs. Each key is unique and elements are stored in sorted order of keys.
- **Syntax:** `map<int, string> m;`
- **Example:**
  ```cpp
  map<int, string> m;
  m[1] = "One";
  m[2] = "Two";
  ```

#### 4. Program Example
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    list<int> l = {1, 2, 3};
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";

    cout << "Vector: ";
    for (int x : v) cout << x << " ";

    cout << "\nList: ";
    for (int x : l) cout << x << " ";

    cout << "\nMap: ";
    for (auto x : m)
        cout << x.first << ":" << x.second << " ";

    return 0;
}
```

#### 5. Output
```text
Vector: 10 20 30
List:   1 2 3
Map:    1:One 2:Two
```

#### 6. Conclusion
Thus, `vector` is used for dynamic arrays, `list` is used for frequent insertion and deletion, and `map` is used to store key-value pairs. These containers make STL powerful and easy to use.
