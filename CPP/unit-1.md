# Object Oriented Programming through C++ — Unit 1 Answers

> **Questions File:** [questions.md — Unit 1](questions.md#unit-1)

---

## Question 1 — Evolution of C++ & Paradigm Shift

### Step-by-Step Solution

#### 1. Evolution of C++ from C
- **BCPL → B → C:** C was developed by **Dennis Ritchie (1972, Bell Labs)** from B; it is a **procedural**, middle-level language.
- **C with Classes (1979):** **Bjarne Stroustrup** added **classes, inheritance, inline functions, default arguments** to C.
- **C++ (1983):** Renamed C++ (`++` = increment operator, "next step after C"). Added **virtual functions, operator overloading, references, `const`**.
- **Later growth:** Templates, exceptions, namespaces, STL (**C++98**); `auto`, lambda, smart pointers (**C++11**); C++14/17/20/23 refine it.

| Year | Milestone |
|---|---|
| 1972 | C (Ritchie) |
| 1979 | C with Classes (Stroustrup) |
| 1983 | Named C++ |
| 1998 | ISO standard C++98 (templates, STL, exceptions) |
| 2011 | C++11 (modern C++) |

#### 2. Disadvantages of Procedural Programming
- **Function-centric:** Program = sequence of functions; **data is secondary**.
- **Global data is exposed:** Any function can modify it → **no data security / data hiding**.
- **Poor maintainability:** Changing a data structure forces changes in **all** functions using it.
- **No code reusability:** Reuse only by copy-paste; **no inheritance**.
- **Does not model the real world:** Real entities (object = data + behavior) are not represented naturally.

#### Code Example
```cpp
#include <iostream>
using namespace std;

int balance = 1000;                 // global data — visible to every function
void hack() { balance = 0; }        // any function can corrupt it (no security)

int main() {
    hack();
    cout << balance;                // 0  -> unprotected data
}
```

---

## Question 2 — C vs C++ Comparison

### Step-by-Step Solution

#### 1. Comparison Table

| Basis | C | C++ |
|---|---|---|
| **Paradigm** | Procedural (top-down) | Multi-paradigm: procedural + **object-oriented** + generic |
| **Approach** | Function-driven | Object/data-driven (bottom-up) |
| **Data security** | None; data is global/open | **Encapsulation**, access specifiers (`private`, `protected`) |
| **Memory management** | `malloc()`, `calloc()`, `free()` | `new`, `delete` (type-safe, calls ctor/dtor) |
| **Function extensions** | No overloading, no default args, no inline | **Function overloading, default arguments, `inline`**, templates |
| **I/O** | `printf()`, `scanf()` | `cout`, `cin` (streams, `<<`, `>>`) |
| **Reference variables** | Not supported | Supported (`int &r = x;`) |
| **Exception handling** | Not supported | `try`, `throw`, `catch` |
| **Namespaces** | Absent | Supported (`namespace`) |
| **Extension** | `.c` | `.cpp` |

#### 2. Key Points
- C++ is a **superset (almost)** of C.
- C++ adds **classes, inheritance, polymorphism, operator overloading**.
- C++ provides **bool, reference, `new/delete`, STL**.

#### Code Example
```cpp
#include <iostream>
using namespace std;

int add(int a, int b = 0) { return a + b; }   // default arg (C++ only)
double add(double a, double b) { return a + b; } // overloading (C++ only)

int main() {
    int *p = new int(5);          // C++ memory allocation
    cout << add(*p) << " " << add(1.5, 2.5);
    delete p;
}
```

---

## Question 3 — OOP Principles & Advantages

### Step-by-Step Solution

#### 1. Fundamental Principles of OOP
- **Encapsulation:** **Binding data and functions into one unit (class)**; data hidden using `private`.
- **Abstraction:** Showing **only essential features**, hiding implementation details (e.g., `cout`, abstract classes).
- **Inheritance:** A **derived class acquires** properties/behavior of a **base class** → **code reusability**.
- **Polymorphism:** **One name, many forms** — compile-time (overloading) and run-time (virtual functions).

#### 2. Advantages of OOP over Procedural Model

| Feature | Procedural | OOP |
|---|---|---|
| Focus | Functions | Objects (data + functions) |
| Data security | Weak | Strong (**data hiding**) |
| Reusability | Copy-paste | **Inheritance** |
| Maintenance | Difficult | Easy (**modularity**) |
| Real-world modeling | Poor | Natural |
| Extensibility | Hard | Easy (new classes) |

- Other advantages: **faster development, reduced redundancy, easy debugging, scalability**.

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Shape {                         // abstraction
public:
    virtual void draw() { cout << "Shape\n"; }  // polymorphism
};
class Circle : public Shape {         // inheritance
    int r;                            // encapsulation (private data)
public:
    Circle(int x) : r(x) {}
    void draw() override { cout << "Circle r=" << r << "\n"; }
};
int main() { Shape *s = new Circle(5); s->draw(); delete s; }
```

---

## Question 4 — Program Structure & Stream I/O

### Step-by-Step Solution

#### 1. Structure of a C++ Program
- **Documentation section:** Comments (`//`, `/* */`).
- **Preprocessor / Header files:** `#include <iostream>`.
- **Namespace declaration:** `using namespace std;`.
- **Global declarations:** Global variables, class definitions, function prototypes.
- **`main()` function:** Entry point; returns `int`.
- **User-defined functions:** Defined after/before `main()`.

```cpp
// Documentation
#include <iostream>        // header
using namespace std;       // namespace
class A { };               // global declarations
int main() {               // main function
    return 0;
}
```

#### 2. Stream I/O
- **Stream** = sequence of bytes flowing between program and device.
- **`cout`** (object of `ostream`) uses **insertion operator `<<`**.
- **`cin`** (object of `istream`) uses **extraction operator `>>`**.
- `cin`/`cout` are **type-safe** and cascade: `cout << a << b;`.

```cpp
cin >> var;
cout << expr1 << expr2;
```

#### 3. Stream Manipulators (`<iomanip>`)

| Manipulator | Purpose |
|---|---|
| `endl` | Newline **and flushes** buffer |
| `setw(n)` | Sets **field width** of next output to *n* |
| `setprecision(n)` | Sets number of significant digits (decimals with `fixed`) |
| `fixed` | Fixed-point notation |
| `setfill(c)` | Pads field with character *c* |

#### Code Example
```cpp
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double pi = 3.14159265;
    cout << setw(10) << "ID" << setw(10) << "Value" << endl;
    cout << setw(10) << 1 << setw(10) << fixed << setprecision(2) << pi << endl;
}
```

---

## Question 5 — Scope Resolution Operator

### Step-by-Step Solution

#### 1. Scope Resolution Operator `::`
- **Definition:** Operator used to **access a name defined in a different scope**.
- **Syntax:**
```cpp
::variable              // global scope
ClassName::member       // class scope
NamespaceName::entity   // namespace scope
```

#### 2. Use-Cases
- **Access global variable hidden by a local variable:** `::x`.
- **Define member functions outside the class:** `ReturnType Class::func() { }`.
- **Qualify namespace members:** `std::cout`, `A::value`.
- **Access static members / base-class members** (e.g., `Base::show()`).

#### Code Example
```cpp
#include <iostream>
using namespace std;

int x = 100;                         // global
namespace N { int x = 50; }          // namespace variable

class Test {
public:
    void show();
};
void Test::show() { cout << "Defined outside\n"; }   // use 2

int main() {
    int x = 10;                      // local
    cout << x << " " << ::x << " " << N::x << endl;  // 10 100 50
    Test t; t.show();
}
```

---

## Question 6 — Namespaces

### Step-by-Step Solution

#### 1. Namespace
- **Definition:** A **named declarative region** that groups identifiers (variables, functions, classes) to **avoid name collisions**.
- **Syntax:**
```cpp
namespace Name {
    // declarations
}
```
- Members accessed via `Name::member`.

#### 2. Nested Namespaces
```cpp
namespace Outer {
    namespace Inner { int v = 5; }
}
// access: Outer::Inner::v
```

#### 3. `using` Directive vs Declaration

| Feature | `using` Directive | `using` Declaration |
|---|---|---|
| Syntax | `using namespace N;` | `using N::name;` |
| Effect | Brings **all** names into scope | Brings **only one** name |
| Collision risk | Higher | Lower |

#### 4. Resolving Naming Collisions
- Put identically named entities in **different namespaces**.
- Use **fully qualified names** (`A::show()`, `B::show()`).
- Prefer **`using` declaration** over directive.

#### Code Example
```cpp
#include <iostream>
using namespace std;

namespace A { void show() { cout << "A\n"; } }
namespace B {
    void show() { cout << "B\n"; }
    namespace In { int v = 7; }
}
int main() {
    A::show();                 // no collision
    B::show();
    using B::In::v;            // using declaration
    cout << v;                 // 7
}
```

---

## Question 7 — Default Arguments & Access Specifiers

### Step-by-Step Solution

#### 1. Default Arguments vs Function Overloading

| Basis | Default Arguments | Function Overloading |
|---|---|---|
| Definition | Parameter gets a **preset value** if argument omitted | **Same name, different parameter lists** |
| Number of functions | **One** function | **Multiple** functions |
| Purpose | Reduce number of calls/overloads | Different behavior per signature |
| Rule | Defaults assigned **right to left** | Must differ in **type/number/order** of parameters |
| Ambiguity | Possible when mixed with overloads | Possible with similar conversions |

```cpp
int area(int l, int b = 1);     // default: only rightmost params
```

#### 2. Access Specifiers — Scoping Rules

| Specifier | Same class | Derived class | Outside (object) |
|---|---|---|---|
| `private` | Yes | **No** | **No** |
| `protected` | Yes | **Yes** | **No** |
| `public` | Yes | Yes | **Yes** |

- Default access: **`private`** in `class`, **`public`** in `struct`.
- Accessed outside only via **public member functions** → encapsulation.

#### Code Example
```cpp
#include <iostream>
using namespace std;

int vol(int l, int b = 2, int h = 3) { return l * b * h; }  // defaults right-to-left

class A {
private:   int p = 1;
protected: int q = 2;
public:    int r = 3;
};
class B : public A {
public: void f() { cout << q << r; }   // p inaccessible
};
int main() {
    cout << vol(1) << vol(1, 5) << vol(1, 5, 4) << "\n";   // 6 15 20
    B b; b.f();
}
```

---

## Question 8 — Core Programs

### Step-by-Step Solution

#### 1. Quadratic Equation Roots (Real & Imaginary)
- **Discriminant** D = b² − 4ac.
- **D > 0:** two distinct real roots; **D = 0:** equal real roots; **D < 0:** **complex (imaginary)** roots.
- Roots: x = (−b ± √D) / 2a.

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    if (a == 0) { cout << "Not quadratic\n"; return 0; }
    double d = b * b - 4 * a * c;
    if (d > 0)
        cout << "Real roots: " << (-b + sqrt(d)) / (2 * a) << ", "
             << (-b - sqrt(d)) / (2 * a) << endl;
    else if (d == 0)
        cout << "Equal roots: " << -b / (2 * a) << endl;
    else
        cout << "Imaginary roots: " << -b / (2 * a) << " ± "
             << sqrt(-d) / (2 * a) << "i" << endl;
}
```

#### 2. Factorial using Recursion
- **Base case:** `0! = 1! = 1`; **recursive case:** `n! = n × (n−1)!`.

```cpp
#include <iostream>
using namespace std;

unsigned long long fact(int n) {
    if (n <= 1) return 1;          // base case
    return n * fact(n - 1);        // recursive call
}
int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    if (n < 0) cout << "Undefined for negatives\n";
    else cout << n << "! = " << fact(n) << endl;
}
```

#### Code Example
Sample run (factorial): input `5` → output `5! = 120`; (quadratic) `1 -3 2` → `Real roots: 2, 1`.
