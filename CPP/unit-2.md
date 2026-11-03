# Object Oriented Programming through C++ — Unit 2 Answers

> **Questions File:** [questions.md — Unit 2](questions.md#unit-2)

---

## Question 1 — Class Declaration & Member Function Scope

> **Question:** Explain how classes and objects are declared, and distinguish between defining member functions inside a class versus outside the class using the scope resolution operator.

---

### Step-by-Step Solution

#### 1. Class and Object
- **Class:** User-defined **blueprint** binding **data members + member functions**.
- **Object:** **Instance** of a class; occupies memory.
- Members are **private by default**; use `public` for interface.

```cpp
class ClassName {
private:   // data members
public:    // member functions
};
ClassName obj;     // object creation
obj.func();        // member access with dot operator
```

#### 2. Member Function Inside vs Outside the Class

| Basis | Inside the class | Outside the class |
|---|---|---|
| Definition place | Within class body | After class using `Class::` |
| Operator needed | None | **Scope resolution `::`** |
| Inline? | **Implicitly inline** | Not inline (unless `inline` keyword) |
| Use | Short functions | Long functions; cleaner class |

```cpp
ReturnType ClassName::funcName(params) { /* body */ }
```

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Student {
    int roll;
public:
    void set(int r) { roll = r; }     // inside (implicit inline)
    void show();                      // declaration only
};
void Student::show() { cout << "Roll: " << roll << endl; }   // outside

int main() {
    Student s;
    s.set(21);
    s.show();
}
```

---

## Question 2 — Inline Functions

> **Question:** Define inline functions, explain their advantages over macros, and discuss the specific conditions where the compiler disregards an inline request.

---

### Step-by-Step Solution

#### 1. Inline Function
- **Definition:** Function whose **body is substituted at the call site** by the compiler, avoiding **call overhead** (stack push/pop, jumps).
- Declared with the **`inline`** keyword; it is only a **request**, not a command.

```cpp
inline ReturnType name(params) { body }
```

#### 2. Advantages over Macros

| Feature | Macro (`#define`) | Inline Function |
|---|---|---|
| Processed by | **Preprocessor** (text replacement) | **Compiler** |
| Type checking | **None** | **Yes** |
| Argument evaluation | May evaluate **multiple times** (side effects) | Evaluated **once** |
| Debugging | Difficult | Easier |
| Scope / class members | Cannot access class members | Can be a member function |

#### 3. When the Compiler Ignores Inline
- Function contains **loops** (`for`, `while`, `do-while`).
- Contains **`switch` or `goto`**.
- Contains **`static` variables**.
- Is **recursive**.
- Function is **too large**.
- Address of the function is taken / called via **function pointer** / **virtual** call.

#### Code Example
```cpp
#include <iostream>
using namespace std;

#define SQ(x) x * x                  // macro: SQ(2+3) = 2+3*2+3 = 11 (wrong)
inline int sq(int x) { return x * x; }   // inline: sq(2+3) = 25

int main() {
    cout << SQ(2 + 3) << " " << sq(2 + 3);   // 11 25
}
```

---

## Question 3 — Static Members & Live Counter

> **Question:** Explain static data members and static member functions with a program demonstrating how they track class-wide states and count active live objects.

---

### Step-by-Step Solution

#### 1. Static Data Members
- **Only one copy** shared by **all objects** of the class.
- **Declared inside** the class, **defined outside** with scope resolution.
- Initialized to **0 by default**; lifetime = **entire program**.

```cpp
class A { static int count; };
int A::count = 0;       // mandatory definition
```

#### 2. Static Member Functions
- Can access **only static members**; has **no `this` pointer**.
- Called as **`ClassName::func()`** (no object required).

#### 3. Live Object Counter
- **Constructor** → `count++`; **Destructor** → `count--` ⇒ tracks **active objects**.

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Counter {
    static int live;
public:
    Counter()  { live++; }
    ~Counter() { live--; }
    static int getLive() { return live; }
};
int Counter::live = 0;

int main() {
    Counter a, b;
    cout << Counter::getLive() << endl;      // 2
    { Counter c; cout << Counter::getLive() << endl; }   // 3
    cout << Counter::getLive() << endl;      // 2 (c destroyed)
}
```

---

## Question 4 — Friend Functions

> **Question:** What is a friend function? Analyze how friend functions bridge data sharing between two unrelated classes without violating encapsulation.

---

### Step-by-Step Solution

#### 1. Friend Function
- **Non-member function** granted access to **private and protected** members of a class.
- Declared inside the class with keyword **`friend`**; defined **outside** without `Class::`.
- **Not in the class scope**; called **without object** (like normal function).
- Accesses members via **object passed as argument** (`obj.member`).

```cpp
class A { friend ReturnType func(A obj); };
```

#### 2. Bridging Two Classes
- A **single friend function** declared in **both** classes can read **private data of both**, so they can share data **without making members public**.
- Needs **forward declaration** `class B;` before class `A`.
- **Encapsulation is preserved:** access is **explicitly granted by the class itself**; no one else gains access.

| Property | Friend Function |
|---|---|
| Friendship is | **Not inherited, not mutual, not transitive** |
| Has `this` pointer | **No** |
| Called using | Normal call, no `.` operator |

#### Code Example
```cpp
#include <iostream>
using namespace std;

class B;                                   // forward declaration
class A {
    int x;
public:
    A(int v) : x(v) {}
    friend int sum(A, B);
};
class B {
    int y;
public:
    B(int v) : y(v) {}
    friend int sum(A, B);
};
int sum(A a, B b) { return a.x + b.y; }    // accesses private of both

int main() { cout << sum(A(10), B(20)); }  // 30
```

---

## Question 5 — Object Argument Passing & Return

> **Question:** Demonstrate how objects can be passed as arguments (pass-by-value vs. pass-by-reference) and returned from member functions.

---

### Step-by-Step Solution

#### 1. Passing Objects as Arguments

| Basis | Pass-by-Value | Pass-by-Reference |
|---|---|---|
| Syntax | `void f(Test t)` | `void f(Test &t)` |
| Copy made | **Yes** (copy constructor called) | **No** (alias) |
| Original modified | **No** | **Yes** (unless `const`) |
| Efficiency | Slow for large objects | **Fast** |

- Use **`const Test &t`** for read-only, efficient passing.
- **Pass-by-pointer:** `void f(Test *t)` uses `t->member`.

#### 2. Returning Objects
- Member function can **return an object by value** (a copy/temporary is created) — commonly used for **adding objects**.
- Avoid returning **reference to a local object** (dangling).

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Num {
    int v;
public:
    Num(int x = 0) : v(x) {}
    Num add(Num n) { return Num(v + n.v); }   // pass by value, return object
    void inc(Num &n) { n.v++; }               // pass by reference
    void show() { cout << v << endl; }
};
int main() {
    Num a(5), b(7);
    Num c = a.add(b);       // returns object
    a.inc(b);               // b modified (becomes 8)
    c.show(); b.show();     // 12 8
}
```

---

## Question 6 — Array of Objects & Pointers to Members

> **Question:** Explain the creation and usage of an array of objects, and describe the syntax and visibility scope of nested classes.

---

### Step-by-Step Solution

#### 1. Array of Objects
- Collection of **objects of same class** stored contiguously.
- **Syntax:** `ClassName arr[size];` → needs a **default constructor** (or initializer list for parameterized).
- Access: `arr[i].member`.

```cpp
Student s[3];                         // default ctor for each
Student t[2] = { Student(1), Student(2) };   // parameterized
```

#### 2. Pointers to Members
- Point to a **class member**, not to a specific object's member.
- **Syntax:**
```cpp
int ClassName::*ptr = &ClassName::data;      // pointer to data member
obj.*ptr        // with object
objPtr->*ptr    // with object pointer
void (ClassName::*fp)() = &ClassName::func;  // pointer to member function
(obj.*fp)();
```
- **Visibility constraint:** Address of a member can be taken **only where the member is accessible** — **`private` members cannot be pointed to from outside** the class (only `public` ones, or inside class/friend).

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Item {
public:
    int qty;
    void show() { cout << "Qty: " << qty << endl; }
};
int main() {
    Item arr[2];                              // array of objects
    arr[0].qty = 5; arr[1].qty = 9;

    int Item::*p = &Item::qty;                // pointer to data member
    void (Item::*f)() = &Item::show;          // pointer to member function
    for (int i = 0; i < 2; i++) {
        cout << arr[i].*p << " ";
        (arr[i].*f)();
    }
}
```

---

## Question 7 — Constructors & Destructors Basics

> **Question:** Define constructors and destructors, detail their essential characteristics, and explain why constructors cannot be declared static or virtual.

---

### Step-by-Step Solution

#### 1. Constructor
- **Special member function** called **automatically** when object is created; **initializes** the object.
- **Characteristics:**
  - **Same name as the class**.
  - **No return type** (not even `void`).
  - Should be **public** (usually).
  - Can have **arguments**; can be **overloaded**.
  - **Cannot be `virtual`**, cannot be inherited.

#### 2. Destructor
- Called **automatically** when object goes **out of scope / `delete`**; releases resources.
- **Syntax:** `~ClassName() { }`.
- **Characteristics:** **name = `~Class`**, **no return type**, **no arguments**, **one per class**, called in **reverse order** of construction.

#### 3. Why Destructor Cannot Be Overloaded
- Overloading needs **different parameter lists**, but a destructor **takes no arguments**.
- It is invoked **implicitly by the system**, which cannot supply arguments or choose among versions.
- An object has **only one way to be destroyed** → **exactly one destructor**.

| Basis | Constructor | Destructor |
|---|---|---|
| Name | `Class()` | `~Class()` |
| Arguments | Allowed | **Not allowed** |
| Overloading | Yes | **No** |
| Call order | Declaration order | **Reverse** order |

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Demo {
public:
    Demo()  { cout << "Constructed\n"; }
    ~Demo() { cout << "Destroyed\n"; }
};
int main() {
    Demo d;
    cout << "In main\n";
}   // Constructed, In main, Destroyed
```

---

## Question 8 — Constructor Overloading & Defaults

> **Question:** Illustrate default constructors, parameterized constructors, constructor overloading, and constructors with default arguments with an application.

---

### Step-by-Step Solution

#### 1. Types
- **Default constructor:** Takes **no arguments** (compiler generates one only if **none** is defined).
- **Parameterized constructor:** Takes **arguments** to initialize with given values.
- **Constructor overloading:** **Multiple constructors** with **different parameter lists**; compiler selects by arguments.
- **Constructor with default arguments:** Missing arguments take **preset values**.

```cpp
Box();                    // default
Box(int a);               // parameterized
Box(int a, int b);        // overloaded
Box(int a, int b = 1);    // default argument
```

- **Caution:** `Box()` and `Box(int a = 0)` together cause **ambiguity** for `Box b;`.

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Rect {
    int l, b;
public:
    Rect() : l(0), b(0) {}                       // default
    Rect(int s) : l(s), b(s) {}                  // parameterized (square)
    Rect(int x, int y) : l(x), b(y) {}           // overloaded
    void area() { cout << l * b << endl; }
};
class Circle {
    float r;
public:
    Circle(float x = 1.0) : r(x) {}              // default argument
    void area() { cout << 3.14 * r * r << endl; }
};
int main() {
    Rect r1, r2(4), r3(3, 5);
    r1.area(); r2.area(); r3.area();             // 0 16 15
    Circle c1, c2(2);
    c1.area(); c2.area();                        // 3.14 12.56
}
```

---

## Question 9 — Copy Constructor & Dynamic Initialization

> **Question:** Explain the role and syntax of a copy constructor, distinguish deep copy from shallow copy, and explain the creation and lifespan of anonymous (temporary) objects.

---

### Step-by-Step Solution

#### 1. Copy Constructor
- **Initializes a new object from an existing object** of the same class.
- **Syntax:** `ClassName(const ClassName &obj);` — **must take reference** (by-value would recurse infinitely).
- **Invoked when:** `A b = a;` / `A b(a);`, **passing object by value**, **returning object by value**.

#### 2. Shallow Copy vs Deep Copy

| Basis | Shallow Copy | Deep Copy |
|---|---|---|
| Copies | **Member-wise (pointer values)** | **Pointed-to data** also |
| Memory | Both objects **share** same heap memory | **Separate** heap memory |
| Default? | **Yes** (compiler-generated) | **User-defined** copy constructor |
| Problem | **Dangling pointer / double delete** | Safe |

#### 3. Dynamic Initialization of Constructors
- **Memory allocated at runtime with `new`** inside constructor; freed with **`delete`** in destructor.

#### Code Example
```cpp
#include <iostream>
#include <cstring>
using namespace std;

class Str {
    char *s;
public:
    Str(const char *x) {                    // dynamic initialization
        s = new char[strlen(x) + 1];
        strcpy(s, x);
    }
    Str(const Str &o) {                     // deep copy constructor
        s = new char[strlen(o.s) + 1];
        strcpy(s, o.s);
    }
    ~Str() { delete[] s; }
    void show() { cout << s << endl; }
};
int main() {
    Str a("Hello");
    Str b = a;          // copy constructor
    a.show(); b.show();
}
```
