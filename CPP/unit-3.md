# Object Oriented Programming through C++ — Unit 3 Answers

> **Questions File:** [questions.md — Unit 3](questions.md#unit-3)

---

## Question 1 — Operator Overloading Rules

> **Question:** Explain the rules for operator overloading, identify the non-overloadable operators in C++, and write a program to overload unary prefix and postfix increment (++) operators.

---

### Step-by-Step Solution

#### 1. Operator Overloading
- Giving **additional meaning to an existing operator** for **user-defined types** (**compile-time polymorphism**).
- **Syntax:**
```cpp
ReturnType operator<symbol>(parameters) { body }
```

#### 2. Rules
- **Only existing operators** can be overloaded; **new symbols cannot** be created.
- **Precedence, associativity, and number of operands cannot change**.
- **At least one operand must be a user-defined type**.
- Meaning of operators on **built-in types cannot be changed**.
- `=`, `()`, `[]`, `->` **must be member functions**.
- Overloaded operators **cannot have default arguments**.

#### 3. Non-Overloadable Operators

| Operator | Name |
|---|---|
| `::` | Scope resolution |
| `.` | Member access |
| `.*` | Pointer-to-member |
| `?:` | Ternary conditional |
| `sizeof` | Size operator |
| `typeid` | Type identification |

#### 4. Unary Prefix vs Postfix Increment Overloading
- **Prefix (`++obj`):** Takes **no arguments** in member function: `Number operator++()`. Increments value and returns the updated object.
- **Postfix (`obj++`):** Takes a **dummy `int` parameter** by C++ convention to distinguish it from prefix: `Number operator++(int)`. Saves old state, increments value, and returns old state.

#### Code Example *(Mandatory program for question)*
```cpp
#include <iostream>
using namespace std;

class Counter {
    int count;
public:
    Counter(int c = 0) : count(c) {}

    // Prefix increment: ++obj
    Counter operator++() {
        ++count;
        return *this;
    }

    // Postfix increment: obj++ (dummy int parameter)
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }

    void display() { cout << "Count: " << count << endl; }
};

int main() {
    Counter c(5);
    ++c;       // Prefix: count becomes 6
    c.display();

    c++;       // Postfix: count becomes 7
    c.display();
    return 0;
}
```

---

## Question 2 — Binary Operator Overloading

> **Question:** Demonstrate binary operator overloading for arithmetic (+) and relational (==) operators on a user-defined class using: (a) a member function, and (b) a friend function.

---

### Step-by-Step Solution

#### 1. Binary Operator as Member Function
- **Left operand** invokes the function (`this`); **right operand** is the **argument**.
- `c3 = c1 + c2;` ⇒ `c3 = c1.operator+(c2);`

```cpp
ReturnType operator+(const Class &obj);   // arithmetic → returns object
bool operator==(const Class &obj);        // relational → returns bool
```

#### 2. Key Points
- **Arithmetic operators** return a **new object**; **relational operators** return **`bool`**.
- Pass argument as **`const &`** for efficiency.
- Mark function **`const`** if it doesn't modify the object.

#### Member operator 

```cpp
#include <iostream>
using namespace std;

class Number {
    int x;

public:
    Number(int a) {
        x = a;
    }

    // Overload +
    Number operator+(Number n) {
        return Number(x + n.x);
    }

    // Overload ==
    bool operator==(Number n) {
        return x == n.x;
    }

    void display() {
        cout << x << endl;
    }
};

int main() {
    Number a(10), b(20);

    Number c = a + b;
    c.display();

    if (a == b)
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}
```
#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

class Number {
    int x;

public:
    Number(int a) {
        x = a;
    }

    // Friend function for +
    friend Number operator+(Number a, Number b);

    // Friend function for ==
    friend bool operator==(Number a, Number b);

    void display() {
        cout << x << endl;
    }
};

Number operator+(Number a, Number b) {
    return Number(a.x + b.x);
}

bool operator==(Number a, Number b) {
    return a.x == b.x;
}

int main() {
    Number a(10), b(20);

    Number c = a + b;
    c.display();

    if (a == b)
        cout << "Equal";
    else
        cout << "Not Equal";

    return 0;
}
```

---

## Question 3 — Inheritance Types

> **Question:** Explain all types of inheritance (Single, Multiple, Multilevel, Hierarchical, and Hybrid) supported in C++ along with visibility mode effects (public, private, protected).

---

### Step-by-Step Solution

#### 1. Inheritance
- **Mechanism by which a derived class acquires members of a base class** → **reusability**, **extensibility**.
- **Syntax:**
```cpp
class Derived : <access> Base1, <access> Base2 { };   // access = public | protected | private
```

#### 2. Types with Diagrams
```
Single          Multiple        Multilevel      Hierarchical      Hybrid
  A             A     B           A               A                 A
  |              \   /            |             / | \              / \
  B               \ /             B            B  C  D            B   C
                   C              |                                \ /
                                  C                                 D
```

| Type | Description | Syntax |
|---|---|---|
| **Single** | One base → one derived | `class B : public A` |
| **Multiple** | **Two or more bases** → one derived | `class C : public A, public B` |
| **Multilevel** | Chain: A → B → C | `class C : public B` |
| **Hierarchical** | One base → **many derived** | `class B : public A`, `class C : public A` |
| **Hybrid** | **Combination** of two or more types (may cause **diamond problem**) | Mixed |

#### 3. Mode of Inheritance

| Base member | public inheritance | protected inheritance | private inheritance |
|---|---|---|---|
| `public` | public | protected | private |
| `protected` | protected | protected | private |
| `private` | Not accessible | Not accessible | Not accessible |

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

class A { public: void a() { cout << "A\n"; } };
class B : public A { public: void b() { cout << "B\n"; } };          // single
class C : public B { public: void c() { cout << "C\n"; } };          // multilevel

class P { public: void p() { cout << "P\n"; } };
class Q { public: void q() { cout << "Q\n"; } };
class R : public P, public Q { };                                    // multiple

int main() {
    C obj; obj.a(); obj.b(); obj.c();
    R r;   r.p(); r.q();
}
```

---

## Question 4 — Diamond Problem & Virtual Base Classes

> **Question:** What is multipath inheritance (the diamond problem), and how does a virtual base class resolve ambiguity?

---

### Step-by-Step Solution

#### 1. Diamond Problem
- Occurs in **hybrid/multiple inheritance** when a class inherits the **same base through two paths**.
- The **grandchild gets two copies** of the grandparent's members → **ambiguity** (`obj.x` is ambiguous) and **memory duplication**.

```
        A
       / \
      B   C
       \ /
        D     // D has two copies of A
```

#### 2. Solution — Virtual Base Class
- Declare the base as **`virtual`** in the intermediate classes:
```cpp
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };
```
- Ensures **only one shared copy** of `A` in `D` → **ambiguity resolved**.
- The **most derived class (`D`)** directly constructs the virtual base `A`.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

class A { public: int x = 10; };
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };

int main() {
    D d;
    cout << d.x;       // OK: single copy. Without virtual → ambiguous error
}
```

---

## Question 5 — Constructor/Destructor Order

> **Question:** Trace the exact order of execution of constructors and destructors in multiple and multilevel inheritance hierarchies, and compare inheritance ("is-a") with object composition ("has-a").

---

#### 1. Order of Constructors and Destructors in C++

The important rule is:

- Constructors: Parent class executes first, then child class.
    
- Destructors: Child class executes first, then parent class.
    

##### A. Multilevel Inheritance

Example: `A → B → C`

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A Constructor\n";
    }
    ~A() {
        cout << "A Destructor\n";
    }
};

class B : public A {
public:
    B() {
        cout << "B Constructor\n";
    }
    ~B() {
        cout << "B Destructor\n";
    }
};

class C : public B {
public:
    C() {
        cout << "C Constructor\n";
    }
    ~C() {
        cout << "C Destructor\n";
    }
};

int main() {
    C obj;
    return 0;
}
```

Output:

```cpp
A Constructor
B Constructor
C Constructor
C Destructor
B Destructor
A Destructor
```

##### B. Multiple Inheritance

Example: `C` inherits from both `A` and `B`.

```cpp
#include <iostream>
using namespace std;

class A {
public:
    A() { cout << "A Constructor\n"; }
    ~A() { cout << "A Destructor\n"; }
};

class B {
public:
    B() { cout << "B Constructor\n"; }
    ~B() { cout << "B Destructor\n"; }
};

class C : public A, public B {
public:
    C() { cout << "C Constructor\n"; }
    ~C() { cout << "C Destructor\n"; }
};

int main() {
    C obj;
    return 0;
}
```

Output:

```cpp
A Constructor
B Constructor
C Constructor
C Destructor
B Destructor
A Destructor
```

Important: In multiple inheritance, constructors execute according to the order in which base classes are declared in the inheritance list.

```cpp
class C : public A, public B
```

Therefore:

- A constructor executes first.
    
- B constructor executes second.
    
- C constructor executes last.
    

Destructors execute in reverse order.

#### 2. Difference Between Inheritance and Composition

|Inheritance (IS-A)|Composition (HAS-A)|
|---|---|
|One class inherits another|One class contains another object|
|Uses `:` symbol|Uses an object as a data member|
|Represents an IS-A relationship|Represents a HAS-A relationship|
|Example: Dog is an Animal|Example: Car has an Engine|
|Promotes code reuse through inheritance|Promotes code reuse through object composition|


---

## Question 6 — Pointers to Objects & Base-Derived Compatibility

> **Question:** Explain pointers to objects, pointers to base and derived classes, and detail the mechanics and utility of the implicit this pointer in method chaining.

---

### Step-by-Step Solution

#### 1. Pointers to Objects
- Stores **address of an object**; members accessed with **arrow operator `->`**.
- `Class *p = &obj; p->func();` ≡ `(*p).func();`
- Dynamic objects: `Class *p = new Class; ... delete p;`

#### 2. Base–Derived Pointer Compatibility
- **Base pointer can point to a derived object** (implicit upcast; **"is-a"** relationship).
- **Derived pointer cannot point to a base object** without explicit cast.
- Through a **base pointer**, only **base-class members** are visible (unless virtual).

#### 3. The `this` Pointer & Method Chaining
- **`this` Pointer:** An implicit constant pointer automatically passed to every non-static member function holding the address of the invoking object (`*this`).
- **Method Chaining:** Returning a reference to the invoking object (`return *this;`) allows cascading member function calls on a single line.

#### Code Example *(Illustrative snippet for question)*
```cpp
#include <iostream>
using namespace std;

class Calc {
    int val;
public:
    Calc(int v = 0) : val(v) {}
    Calc& add(int x) { val += x; return *this; }        // returns *this for chaining
    Calc& mul(int x) { val *= x; return *this; }        // returns *this for chaining
    void show() { cout << "Value: " << val << endl; }
};

int main() {
    Calc c(10);
    c.add(5).mul(2).show();     // Method chaining: (10 + 5) * 2 = 30
    return 0;
}
```

---

## Question 7 — Virtual Functions & vtable/vptr Internals

> **Question:** Differentiate between compile-time binding and run-time binding, state the rules for virtual functions, and explain the internal working of vptr and vtable.

---

### Step-by-Step Solution

#### 1. Virtual Function
- Member function declared with **`virtual`** in the base class; **overridden** in the derived class.
- Enables **run-time polymorphism** (**late/dynamic binding**) when called via **base pointer/reference**.
- **Rules:** Must be a **member function**; **cannot be static**; constructors **cannot** be virtual; destructors **can** (and should) be virtual.

```cpp
class Base { public: virtual void f(); };
```

#### 2. vtable and vptr Internals
- **vtable (Virtual Table):** **Per-class static table** of **function pointers** to that class's virtual function implementations.
- **vptr (Virtual Pointer):** **Hidden pointer in each object** pointing to its class's vtable; **set by the constructor**.
- **Call flow:** `bp->f()` → follow **`vptr`** → look up slot in **vtable** → call **actual function** (runtime resolution).

```
 Object d (Derived)        vtable of Derived
 +----------------+        +---------------------+
 | vptr  ---------+------> | &Derived::f         |
 | data members   |        | &Base::g (inherited)|
 +----------------+        +---------------------+
```

| Basis | vtable | vptr |
|---|---|---|
| Per | **Class** | **Object** |
| Holds | Function addresses | Address of vtable |
| Created | Compile time | Set at object construction |

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void area() { cout << "Shape area\n"; }
};
class Rect : public Shape {
public: void area() override { cout << "Rect area\n"; }
};
class Circle : public Shape {
public: void area() override { cout << "Circle area\n"; }
};
int main() {
    Shape *s[2] = { new Rect, new Circle };
    for (Shape *p : s) { p->area(); delete p; }   // Rect area, Circle area
}
```

---

## Question 8 — Abstract Classes & Virtual Destructors

> **Question:** What is a pure virtual function and an abstract class? Explain why a base class destructor must be declared virtual when deleting derived objects through base pointers.

---

### Step-by-Step Solution

#### 1. Pure Virtual Function
- Virtual function with **no body**, declared with **`= 0`**:
```cpp
virtual ReturnType func() = 0;
```
- A class with **at least one pure virtual function** is an **abstract class**.
- Derived class **must override** all pure virtuals, else it also stays abstract.

#### 2. Abstract vs Concrete Class

| Basis | Abstract Class | Concrete Class |
|---|---|---|
| Pure virtual function | **At least one** | **None** |
| Object creation | **Not allowed** | **Allowed** |
| Pointer/reference | **Allowed** (for polymorphism) | Allowed |
| Purpose | **Interface / base** for derived classes | Fully usable class |

#### 3. Why Virtual Destructor?
- `delete basePtr;` on a derived object with a **non-virtual base destructor** → **only base destructor runs** → **derived resources leak (undefined behavior)**.
- **Virtual destructor** ensures **derived destructor runs first, then base** (correct cleanup).
- **Rule:** Any class with virtual functions meant to be a base → **declare `virtual ~Base()`**.

#### Code Example *(Reference only — not asked in question)*
```cpp
#include <iostream>
using namespace std;

class Shape {                                  // abstract class
public:
    virtual void draw() = 0;                   // pure virtual
    virtual ~Shape() { cout << "~Shape\n"; }   // virtual destructor
};
class Circle : public Shape {
    int *data = new int[10];
public:
    void draw() override { cout << "Circle\n"; }
    ~Circle() { delete[] data; cout << "~Circle\n"; }
};
int main() {
    // Shape s;              // ERROR: abstract
    Shape *p = new Circle;
    p->draw();
    delete p;                // ~Circle then ~Shape
}
```
