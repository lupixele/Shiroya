# Object Oriented Programming through C++ — Unit 4 Answers

> **Questions File:** [questions.md — Unit 4](questions.md#unit-4)

---

## Question 1 — Generic Programming & Motivation for Templates

> **Question:** Define generic programming and discuss the motivation and need for templates in modern C++.

---

### Step-by-Step Solution

#### 1. Generic Programming
- **Definition:** A programming paradigm where algorithms and data structures are written **independently of any specific data type**.
- Uses **type parameterization** (`template <class T>` or `template <typename T>`) so a single algorithm works for `int`, `float`, `char`, or user-defined objects.

#### 2. Motivation & Need for Templates
- **Eliminates Code Duplication:** In C, sorting 3 data types requires 3 separate functions (`sort_int`, `sort_float`, `sort_str`). Templates require **only one generic function**.
- **Compile-Time Type Safety:** The compiler verifies data types during template instantiation at compile time, eliminating dangerous `void*` casts.
- **High Performance:** No runtime overhead; the compiler generates specialized, optimized machine code for each concrete type used.
- **Foundation of STL:** The Standard Template Library (vector, list, sort, find) is built entirely on generic templates.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

// Single generic template function for any type
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << findMax(10, 20) << endl;       // int
    cout << findMax(3.14, 2.71) << endl;   // double
    cout << findMax('A', 'Z') << endl;       // char
    return 0;
}
```

---

## Question 2 — Templates vs C Preprocessor Macros

> **Question:** Compare and contrast C++ templates with C preprocessor (#define) macros with respect to type-safety, error handling, and debugging.

---

### Step-by-Step Solution

#### 1. Comparison Table

| Feature | C++ Templates | C Preprocessor Macros (`#define`) |
|---|---|---|
| **Nature** | Built-in language feature handled by **compiler** | Text-substitution mechanism handled by **preprocessor** |
| **Type Safety** | **Strict type checking** at compile time | **No type checking**; dangerous type mismatches |
| **Debugging** | **Easy to debug**; compiler gives precise file & line errors | **Extremely difficult**; macros do not appear in symbol tables |
| **Side Effects** | Evaluated safely as real functions | Causes unintended side effects (e.g., `SQUARE(x++)` evaluates twice) |
| **Scope Rules** | Obey **class and namespace scopes** | Ignore scoping; global text replacement throughout file |
| **Code Bloat** | Generated once per unique type | Repeated text expansion everywhere macro is invoked |

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

#define SQUARE_MACRO(x) ((x) * (x))

template <typename T>
T squareTemplate(T x) { return x * x; }

int main() {
    int a = 5;
    // Macro bug: incremented twice!
    // cout << SQUARE_MACRO(a++); // ((a++) * (a++)) -> undefined behavior

    int b = 5;
    cout << squareTemplate(b++) << endl; // Safe: 25, b becomes 6
    return 0;
}
```

---

## Question 3 — Function Templates Syntax & Working

> **Question:** Explain the definition, syntax, and working of a normal function template with an illustrative program.

---

### Step-by-Step Solution

#### 1. Function Template Definition & Syntax
- **Definition:** A blueprint for creating functions where one or more types are specified as placeholders.
- **Syntax:**
  ```cpp
  template <class T>
  ReturnType functionName(T parameter1, T parameter2) {
      // function body
  }
  ```
- `template <class T>` tells the compiler that `T` is a generic type placeholder.

#### 2. Working Mechanics (Instantiation)
- When a function template is defined, **no machine code is generated initially**.
- When called with specific types (e.g., `swapValues(a, b)` with `int`), the compiler creates an instance called a **template instantiation**.
- Can be invoked **implicitly** (`swapValues(x, y)`) where the compiler deduces `T`, or **explicitly** (`swapValues<int>(x, y)`).

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

// Generic swap function template
template <typename T>
void swapValues(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    swapValues(x, y); // Instantiates swapValues for int
    cout << "Integers: x=" << x << ", y=" << y << endl;

    double p = 1.5, q = 9.8;
    swapValues(p, q); // Instantiates swapValues for double
    cout << "Doubles:  p=" << p << ", q=" << q << endl;

    return 0;
}
```

---

## Question 4 — Overloading Function Templates

> **Question:** Demonstrate how function templates can be overloaded with other template functions or standard non-template functions.

---

### Step-by-Step Solution

#### 1. Overloading Rules for Templates
A function template can be overloaded in two ways:
1. **With another template:** Having a different number or combination of template parameters.
2. **With a standard non-template function:** Having the exact same name with concrete data types.

#### 2. Call Resolution Order
- When resolving a function call, the compiler follows this priority:
  1. **Exact-match non-template function** (always prioritized over template).
  2. **Template specialization / function template** with exact match.
  3. Compiler returns an ambiguity error if two templates match equally.

#### Code Example *(Illustrative snippet for question)*
```cpp
#include <iostream>
using namespace std;

// 1. Generic template function
template <typename T>
void print(T a) {
    cout << "Template: " << a << endl;
}

// 2. Overloaded template with two parameters
template <typename T1, typename T2>
void print(T1 a, T2 b) {
    cout << "Overloaded 2-arg template: " << a << ", " << b << endl;
}

// 3. Exact-match non-template function for int
void print(int a) {
    cout << "Non-template function for int: " << a << endl;
}

int main() {
    print(100);             // Calls non-template int function
    print(3.14);            // Calls 1-arg template (double)
    print("Roll", 101);     // Calls 2-arg template
    print<int>(100);        // Explicit <> forces template version
    return 0;
}
```

---

## Question 5 — Class Templates & Generic Stack<T>

> **Question:** Explain how class templates are defined and instantiated, and implement a generic Stack<T> class template with basic operations.

---

### Step-by-Step Solution

#### 1. Class Template Definition & Instantiation
- **Definition:** A class blueprint parameterized with types, allowing a single class definition to create data structures for any type.
- **Syntax:**
  ```cpp
  template <class T>
  class ClassName {
      T member;
  public:
      void method(T arg);
  };
  ```
- **Instantiation:** Requires explicit type in angle brackets `<>`: `ClassName<int> obj;`.
- **Out-of-class definition syntax:**
  ```cpp
  template <class T>
  void ClassName<T>::method(T arg) { }
  ```

#### 2. Generic Stack<T> Operations
- Follows **LIFO** (Last In, First Out).
- `push(T)`: Inserts element at top (checks overflow `top == capacity - 1`).
- `pop()`: Removes and returns top element (checks underflow `top == -1`).
- `display()`: Traverses from `top` down to `0`.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

template <class T>
class Stack {
    T arr[50];
    int top;
public:
    Stack() : top(-1) {}

    void push(T val) {
        if (top == 49) { cout << "Stack Overflow\n"; return; }
        arr[++top] = val;
    }
    void pop() {
        if (top == -1) { cout << "Stack Underflow\n"; return; }
        cout << "Popped: " << arr[top--] << endl;
    }
    void display() {
        if (top == -1) { cout << "Empty\n"; return; }
        for (int i = top; i >= 0; i--) cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack<int> sInt;
    sInt.push(10); sInt.push(20);
    sInt.display(); // 20 10
    sInt.pop();

    Stack<string> sStr;
    sStr.push("Aditya"); sStr.push("Campus");
    sStr.display(); // Campus Aditya
    return 0;
}
```

---

## Question 6 — Class Templates with Multiple & Non-Type Parameters

> **Question:** Demonstrate how class templates support multiple generic type arguments and non-type template parameters.

---

### Step-by-Step Solution

#### 1. Multiple Generic Type Parameters
- A class template can take more than one type parameter:
  ```cpp
  template <class T1, class T2>
  class Pair { T1 first; T2 second; };
  ```
- Allows storing paired attributes of different types (e.g., `Pair<string, int>` for Student and Roll Number).

#### 2. Non-Type Template Parameters
- In addition to types, a template parameter can be a **constant value** (integral, pointer, or reference):
  ```cpp
  template <class T, int SIZE>
  class StaticArray { T data[SIZE]; };
  ```
- **Rules:** The non-type parameter must be a **compile-time constant**. It allows statically-sized data structures without heap allocation.

#### Code Example *(Illustrative snippet for question)*
```cpp
#include <iostream>
using namespace std;

// Multiple generic types (K, V) + Non-type parameter (int MAX)
template <class K, class V, int MAX>
class KeyValueStore {
    K keys[MAX];
    V values[MAX];
    int count;
public:
    KeyValueStore() : count(0) {}

    void insert(K k, V v) {
        if (count < MAX) {
            keys[count] = k;
            values[count++] = v;
        }
    }
    void show() {
        for (int i = 0; i < count; i++)
            cout << "[" << keys[i] << " -> " << values[i] << "] ";
        cout << endl;
    }
};

int main() {
    // K = string, V = int, MAX = 5
    KeyValueStore<string, int, 5> marks;
    marks.insert("Math", 95);
    marks.insert("CPP", 98);
    marks.show();
    return 0;
}
```

---

## Question 7 — Template Bubble Sort

> **Question:** Write a generic C++ function template to sort an array of arbitrary data types using the Bubble Sort algorithm.

---

### Step-by-Step Solution

#### 1. Generic Bubble Sort Algorithm
- Compares adjacent elements and swaps them if they are in the wrong order:
  $$\text{if } (arr[j] > arr[j+1]) \implies \text{swap}(arr[j], arr[j+1])$$
- Outer loop runs $n-1$ passes; inner loop compares adjacent pairs up to $n - i - 1$.
- By using `template <typename T>`, the same sorting logic works for `int`, `float`, `char`, or any user-defined object supporting the `>` operator.

#### 2. Complexity
- **Time Complexity:** $O(n^2)$ worst and average case, $O(n)$ best case with a swapped flag.
- **Space Complexity:** $O(1)$ auxiliary memory.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int iArr[] = { 64, 25, 12, 22, 11 };
    bubbleSort(iArr, 5);
    cout << "Sorted Integers: "; printArray(iArr, 5);

    double dArr[] = { 4.5, 1.2, 9.8, 3.3 };
    bubbleSort(dArr, 4);
    cout << "Sorted Doubles:  "; printArray(dArr, 4);

    return 0;
}
```

---

## Question 8 — Generic Singly Linked List (LinkedList<T>)

> **Question:** Design and construct a generic singly linked list data structure (LinkedList<T>) using class templates that supports dynamic node insertion and forward traversal.

---

### Step-by-Step Solution

#### 1. Data Structure Design
- **Generic Node (`Node<T>`):**
  - Contains data of generic type `T`.
  - A pointer to the next node: `Node<T>* next;`.
- **Generic List (`LinkedList<T>`):**
  - Contains a pointer to the first node: `Node<T>* head;`.
  - Supports `insert(T val)` and `display()`.

#### 2. Operations
- **Insertion at Head:** Allocate new node, set its data, point `new_node->next = head`, then update `head = new_node`.
- **Traversal:** Start at `head`, loop while pointer is not `nullptr`, print data and advance `temp = temp->next`.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

template <class T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <class T>
class LinkedList {
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList<int> intList;
    intList.insert(30); intList.insert(20); intList.insert(10);
    cout << "Integer List: "; intList.display(); // 10 -> 20 -> 30 -> NULL

    LinkedList<string> strList;
    strList.insert("DS"); strList.insert("CSE");
    cout << "String List:  "; strList.display();  // CSE -> DS -> NULL
    return 0;
}
```
