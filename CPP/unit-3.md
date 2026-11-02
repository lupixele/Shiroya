# Object Oriented Programming through C++ — Unit 3 Answers

> **Questions File:** [questions.md — Unit 3](questions.md#unit-3)

---

## Question 1 — Operator Overloading Rules

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

#### 4. Member Function vs Friend Function

| Basis | Member Function | Friend Function |
|---|---|---|
| Left operand | **Must be an object** of the class | **Can be any type** (e.g., `int`) |
| Binary operator args | **One** (right operand) | **Two** |
| Unary operator args | **Zero** | **One** |
| `this` pointer | Available | **Not available** |
| Example | `a + b` → `a.operator+(b)` | `5 + a` → `operator+(5, a)` |
| Must use for | `=`, `()`, `[]`, `->` | `<<`, `>>` (stream operators) |

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Num {
    int v;
public:
    Num(int x = 0) : v(x) {}
    Num operator-() { return Num(-v); }                  // member (unary)
    friend Num operator+(int a, Num n);                  // friend (int on left)
    friend ostream& operator<<(ostream &o, Num n) { return o << n.v; }
};
Num operator+(int a, Num n) { return Num(a + n.v); }

int main() {
    Num n(5);
    cout << -n << " " << 10 + n;     // -5 15
}
```

---

## Question 2 — Binary Operator Overloading

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

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Complex {
    float re, im;
public:
    Complex(float r = 0, float i = 0) : re(r), im(i) {}
    Complex operator+(const Complex &c) const {        // arithmetic
        return Complex(re + c.re, im + c.im);
    }
    bool operator==(const Complex &c) const {          // relational
        return re == c.re && im == c.im;
    }
    void show() const { cout << re << " + " << im << "i\n"; }
};
int main() {
    Complex a(2, 3), b(4, 5);
    Complex c = a + b;
    c.show();                                          // 6 + 8i
    cout << (a == b ? "Equal" : "Not equal");          // Not equal
}
```

---

## Question 3 — Inheritance Types

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

#### Code Example
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

#### Code Example
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

### Step-by-Step Solution

#### 1. Rules
- **Constructors:** **Base → Derived** (top-down).
- **Destructors:** **Derived → Base** (**exact reverse**).
- **Multilevel:** `A → B → C` construct; `C → B → A` destruct.
- **Multiple inheritance:** Base constructors run in the **order of declaration in the derived class's base list** (not the member-initializer order).
- **Virtual bases** are constructed **first**, before non-virtual bases.
- Base-class **parameterized constructor** invoked via **initializer list**: `Derived(int x) : Base(x) { }`.

| Hierarchy | Constructor order | Destructor order |
|---|---|---|
| Multilevel `C : B : A` | A, B, C | C, B, A |
| Multiple `C : A, B` | A, B, C | C, B, A |

#### Code Example
```cpp
#include <iostream>
using namespace std;

class A { public: A() { cout << "A() "; } ~A() { cout << "~A() "; } };
class B : public A { public: B() { cout << "B() "; } ~B() { cout << "~B() "; } };
class C : public B { public: C() { cout << "C() "; } ~C() { cout << "~C() "; } };

class X { public: X() { cout << "X() "; } ~X() { cout << "~X() "; } };
class Y { public: Y() { cout << "Y() "; } ~Y() { cout << "~Y() "; } };
class Z : public X, public Y { public: Z() { cout << "Z() "; } ~Z() { cout << "~Z() "; } };

int main() {
    { C c; }  cout << endl;   // A() B() C() ~C() ~B() ~A()
    { Z z; }  cout << endl;   // X() Y() Z() ~Z() ~Y() ~X()
}
```

---

## Question 6 — Pointers to Objects & Base-Derived Compatibility

### Step-by-Step Solution

#### 1. Pointers to Objects
- Stores **address of an object**; members accessed with **arrow operator `->`**.
- `Class *p = &obj; p->func();` ≡ `(*p).func();`
- Dynamic objects: `Class *p = new Class; ... delete p;`

#### 2. Base–Derived Pointer Compatibility
- **Base pointer can point to a derived object** (implicit upcast; **"is-a"** relationship). ✔
- **Derived pointer cannot point to a base object** without **explicit cast** (unsafe). ✘
- Through a **base pointer**, only **base-class members** are visible (**derived-only members are inaccessible**).
- Without **`virtual`**, the **base version** of an overridden function is called (**early binding**); with `virtual`, the **derived version** is called (**late binding**).

| Pointer type | Object | Allowed? |
|---|---|---|
| `Base*` | `Base` / `Derived` | **Yes** |
| `Derived*` | `Derived` | Yes |
| `Derived*` | `Base` | **No** (needs cast) |

#### Code Example
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    void show()    { cout << "Base show\n"; }
    virtual void v() { cout << "Base v\n"; }
};
class Derived : public Base {
public:
    void show() { cout << "Derived show\n"; }
    void v() override { cout << "Derived v\n"; }
    void only() { cout << "Derived only\n"; }
};
int main() {
    Derived d;
    Base *bp = &d;       // base pointer → derived object
    bp->show();          // Base show   (non-virtual → pointer type)
    bp->v();             // Derived v   (virtual → object type)
    // bp->only();       // ERROR: not a Base member
    ((Derived*)bp)->only();   // explicit cast
}
```

---

## Question 7 — Virtual Functions & vtable/vptr Internals

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

#### Code Example
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

#### Code Example
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
