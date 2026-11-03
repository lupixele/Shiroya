# Object Oriented Programming through C++ — Unit 4 Answers

> **Questions File:** [questions.md — Unit 4](questions.md#unit-4)

---

## Question 1 — Generic Programming & Function Templates

> **Question:** Define generic programming and discuss the motivation and need for templates in modern C++.

---

### Step-by-Step Solution

#### 1. Generic Programming
- Writing code **independent of data type**; the **type is a parameter** supplied later.
- C++ implements it using **templates** → **code reusability** with **compile-time type safety**.

#### 2. Function Template
- A **single function definition** that works for **many data types**; compiler **instantiates** the correct version when called.
```cpp
template <class T>            // or: template <typename T>
T func(T a, T b) { /* body */ }
```
- **Type deduced from arguments**; or explicit: `func<int>(3, 4)`.

#### 3. Overloading Template Functions
- A template can be **overloaded** by (i) **another template with a different parameter count/shape**, or (ii) a **non-template (ordinary) function**.
- **Resolution order:** **Exact-match ordinary function** is preferred over template; then the most specialized template.

#### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T>
T maxi(T a, T b) { return (a > b) ? a : b; }          // template 1

template <class T>
T maxi(T a, T b, T c) { return maxi(maxi(a, b), c); } // overloaded template (3 args)

const char* maxi(const char *a, const char *b) { return a; }   // ordinary overload

int main() {
    cout << maxi(3, 7) << " " << maxi(2.5, 1.5) << " " << maxi(1, 9, 4);   // 7 2.5 9
}
```

---

## Question 2 — Class Templates and Generic Stack

> **Question:** Compare and contrast C++ templates with C preprocessor (#define) macros with respect to type-safety, error handling, and debugging.

---

### Step-by-Step Solution

#### 1. Class Template
- A **class blueprint parameterized by type**; objects are created by **specifying the type** in angle brackets.
```cpp
template <class T>
class ClassName { T member; };
ClassName<int> obj;
```
- **Member functions defined outside** need: `template <class T> ReturnType ClassName<T>::func() { }`.

#### 2. Generic Stack
- **LIFO** structure with **`push`** (insert at top), **`pop`** (remove from top), **`display`**.
- Check **overflow** (`top == size-1`) and **underflow** (`top == -1`).

#### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T>
class Stack {
    T arr[50];
    int top = -1;
public:
    void push(T x) {
        if (top == 49) { cout << "Overflow\n"; return; }
        arr[++top] = x;
    }
    void pop() {
        if (top == -1) { cout << "Underflow\n"; return; }
        cout << "Popped: " << arr[top--] << endl;
    }
    void display() {
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};
int main() {
    Stack<int> s;    s.push(10); s.push(20); s.display(); s.pop();
    Stack<string> t; t.push("a"); t.push("b"); t.display();
}
```

---

## Question 3 — Multiple Arguments & Non-Type Parameters

> **Question:** Explain the definition, syntax, and working of a normal function template with an illustrative program.

---

### Step-by-Step Solution

#### 1. Class Template with Multiple Generic Arguments
- Several type parameters separated by commas; **each can be a different type**.
```cpp
template <class T1, class T2>
class Pair { T1 first; T2 second; };
Pair<int, float> p;
```

#### 2. Non-Type Template Parameters
- A **compile-time constant value** (integral, pointer, reference, `enum`) passed as a parameter.
```cpp
template <class T, int N>
class Array { T a[N]; };
Array<int, 5> x;      // N = 5 must be a constant expression
```
- **Used for:** fixed array sizes, buffer capacity. Value **must be known at compile time** (no variables).

| Parameter type | Example | Supplied with |
|---|---|---|
| **Type** | `class T` | A data type (`int`) |
| **Non-type** | `int N` | A constant (`5`) |

#### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T1, class T2, int N>
class Store {
    T1 a[N];
    T2 tag;
public:
    Store(T2 t) : tag(t) { for (int i = 0; i < N; i++) a[i] = i * 2; }
    void show() {
        cout << tag << ": ";
        for (int i = 0; i < N; i++) cout << a[i] << " ";
        cout << endl;
    }
};
int main() {
    Store<int, string, 4> s("Evens");
    s.show();                       // Evens: 0 2 4 6
}
```

---

## Question 4 — Templates vs Macros

> **Question:** Demonstrate how function templates can be overloaded with other template functions or standard non-template functions.

---

### Step-by-Step Solution

#### 1. Comparison Table

| Basis | Templates | Macros (`#define`) |
|---|---|---|
| **Processed by** | **Compiler** | **Preprocessor** (text substitution) |
| **Type safety** | **Yes** (strict type checking) | **No** type checking |
| **Debugging** | Easier (real symbols, compiler errors) | **Hard** (expanded text before compile) |
| **Compilation overhead** | Higher (**instantiation** per type; longer compile time) | Low (simple text replace) |
| **Code expansion** | **Instantiated per type used** (controlled by compiler) | **Textual expansion at every use** |
| **Argument evaluation** | Once | **May evaluate multiple times** (side effects) |
| **Scope** | Obeys scope/namespace rules | **Ignores scope** |
| **Supports classes** | **Yes** (class templates) | No |
| **Specialization** | Supported | Not supported |

#### 2. Key Points
- **Templates** = type-safe, scoped, part of the language.
- **Macros** = blind text replacement, error-prone (`SQ(a++)` increments twice).

#### Code Example
```cpp
#include <iostream>
using namespace std;

#define SQ(x) ((x) * (x))
template <class T> T sq(T x) { return x * x; }

int main() {
    int a = 3;
    cout << sq(a++) << " " << a << endl;   // 9 4   (a++ evaluated once)
    a = 3;
    cout << SQ(a++) << " " << a << endl;   // undefined/unsafe: a++ evaluated twice
}
```

---

## Question 5 — Template Bubble Sort

> **Question:** Explain how class templates are defined and instantiated, and implement a generic Stack<T> class template with basic operations.

---

### Step-by-Step Solution

#### 1. Algorithm
- Repeatedly **compare adjacent elements** and **swap if out of order**.
- After each pass the **largest element moves to the end**; **n−1 passes**.
- **Time complexity:** **O(n²)** worst/average, **O(n)** best (with swapped-flag); **Space:** O(1).

#### 2. Template Use
- One `bubbleSort<T>` works for **`int` and `float`** (any type supporting `>`).

#### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                T t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }
}
template <class T>
void print(T a[], int n) { for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl; }

int main() {
    int   x[] = {5, 2, 9, 1, 7};
    float y[] = {3.5f, 1.2f, 9.9f, 0.5f};
    bubbleSort(x, 5); print(x, 5);     // 1 2 5 7 9
    bubbleSort(y, 4); print(y, 4);     // 0.5 1.2 3.5 9.9
}
```

---

## Question 6 — Generic Singly Linked List

> **Question:** Demonstrate how class templates support multiple generic type arguments and non-type template parameters.

---

### Step-by-Step Solution

#### 1. Design
- **Node<T>:** holds **`T data`** and **`Node<T>* next`**.
- **List<T>:** holds **`head`** pointer; operations:
  - **`insert`** (at end): traverse to last node, link new node.
  - **`display`** (traversal): start at `head`, follow `next` until `nullptr`.
- **Destructor** frees all nodes (no memory leak).

```
head → [10|•] → [20|•] → [30|NULL]
```

#### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T data;
    Node *next;
    Node(T d) : data(d), next(nullptr) {}
};
template <class T>
class List {
    Node<T> *head = nullptr;
public:
    void insert(T x) {                         // insert at end
        Node<T> *n = new Node<T>(x);
        if (!head) { head = n; return; }
        Node<T> *t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
    void display() {                           // traversal
        for (Node<T> *t = head; t; t = t->next) cout << t->data << " -> ";
        cout << "NULL\n";
    }
    ~List() { while (head) { Node<T> *t = head; head = head->next; delete t; } }
};
int main() {
    List<int> a;    a.insert(10); a.insert(20); a.display();
    List<char> b;   b.insert('x'); b.insert('y'); b.display();
}
```

---

## Question 7 — Exception Handling Principles

> **Question:** Write a generic C++ function template to sort an array of arbitrary data types using the Bubble Sort algorithm.

---

### Step-by-Step Solution

#### 1. Principles
- **Exception** = **run-time error/abnormal condition** (divide by zero, invalid input, allocation failure).
- Exception handling **separates error-handling code from normal logic** and gives **controlled recovery**.

#### 2. Role of `try`, `throw`, `catch`
- **`try`:** Block containing **code that may throw** an exception.
- **`throw`:** **Raises** an exception (any type: `int`, `char*`, object).
- **`catch`:** **Handler** that receives and handles the exception; **matches by type**.

```cpp
try { /* risky code */ if (error) throw value; }
catch (Type e) { /* handle */ }
```

#### 3. Exception Propagation Flow
1. Code in **`try`** throws → normal execution **stops immediately**.
2. **Stack unwinding:** Local objects destroyed as control **leaves** each function.
3. Runtime searches the **matching `catch`** in the current function, then **calling functions up the call stack**.
4. If **found** → handler runs, execution continues **after the catch block**.
5. If **not found** → **`terminate()`** called → program aborts.

#### Code Example
```cpp
#include <iostream>
using namespace std;

double divide(int a, int b) {
    if (b == 0) throw "Division by zero";     // throw
    return (double)a / b;
}
int main() {
    try {
        cout << divide(10, 2) << endl;        // 5
        cout << divide(5, 0) << endl;         // throws
        cout << "Not executed\n";
    }
    catch (const char *msg) { cout << "Error: " << msg << endl; }
    cout << "Program continues\n";
}
```

---

## Question 8 — Multiple Catch & Re-throwing

> **Question:** Design and construct a generic singly linked list data structure (LinkedList<T>) using class templates that supports dynamic node insertion and forward traversal.

---

### Step-by-Step Solution

#### 1. Multiple Catch Statements
- **Several `catch` blocks** after one `try`, each handling a **different exception type**.
- Checked **top to bottom**; **first matching type** executes.
- **Derived-class handlers must appear before base-class handlers**.

#### 2. Catch-All Handler
- **`catch(...)`** catches **any exception type**; must be the **last** handler.

#### 3. Re-throwing
- **`throw;`** (no operand) inside a catch block **passes the same exception to an outer handler**.
- Used when a handler **partially handles** (e.g., logs) and an outer block must complete handling.

#### 4. Exception Specifications
- Old syntax: `void f() throw(int, char);` lists allowed exception types — **deprecated in C++11, removed in C++17**.
- **`throw()`** = throws nothing; modern replacement: **`noexcept`**.
- Violating a specification calls **`unexpected()`** → **`terminate()`**.

| Feature | Syntax |
|---|---|
| Specific handler | `catch (int e)` |
| Catch-all | `catch (...)` |
| Re-throw | `throw;` |
| No-throw guarantee | `noexcept` |

#### Code Example
```cpp
#include <iostream>
using namespace std;

void test(int x) {
    try {
        if (x == 1) throw 10;
        if (x == 2) throw 'a';
        if (x == 3) throw 2.5;
    }
    catch (int e)  { cout << "int: " << e << endl; if (x == 1) throw; }  // re-throw
    catch (char e) { cout << "char: " << e << endl; }
    catch (...)    { cout << "unknown exception\n"; }
}
int main() {
    try { test(1); } catch (int) { cout << "Outer caught re-thrown int\n"; }
    test(2);
    test(3);
}
```
