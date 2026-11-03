# Object Oriented Programming through C++ — 2-Marks Short Answers (All Units)

## Unit I — C++ Fundamentals & Paradigms

### Q1. Differences between C and C++
- **C** is a **procedural** language (function-driven); **C++** is **multi-paradigm** (procedural + object-oriented + generic).
- C++ supports **classes, objects, inheritance, polymorphism, encapsulation**; C does not.
- C++ provides **function/operator overloading, references, templates, exceptions, namespaces**; C has none of these.
- I/O: C uses `printf/scanf`; C++ uses `cin/cout` (streams).

### Q2. Disadvantages of Procedural Programming
- Focus is on **functions**, not data; data is **global and unprotected** (no **data hiding**).
- Poor **code reusability**; changing a data structure forces changes in all functions using it.
- Does not model **real-world entities** well; **maintenance** is difficult in large programs.
- No support for **inheritance** or **polymorphism**.

### Q3. Evolution of C++
- Developed by **Bjarne Stroustrup** at **AT&T Bell Laboratories** in the early **1979–1980s**.
- First named **"C with Classes"** (adding classes to C, influenced by **Simula67**).
- Renamed **C++** in **1983** (`++` = increment operator, i.e., "next step beyond C").
- Standardized by **ISO** (C++98, C++11, C++14, C++17, C++20).

### Q4. Key OOP Concepts
The four foundational pillars of OOP are:
- **Encapsulation** – binding data and functions together in a class (data hiding).
- **Abstraction** – exposing only essential features, hiding implementation details.
- **Inheritance** – acquiring properties of an existing class (code reuse).
- **Polymorphism** – one name, many forms (compile-time and run-time).

### Q5. C++ Program Structure
A C++ program has these major sections:
1. **Documentation / Comments** (`//`, `/* */`)
2. **Header files** – `#include <iostream>`
3. **Namespace / Global declarations** – `using namespace std;`
4. **Class definitions** (declarations + member functions)
5. **`main()` function** – program entry point

```cpp
#include <iostream>
using namespace std;
int main() { cout << "Hello"; return 0; }
```

### Q6. Advantages of OOP
- **Reusability** through inheritance (write once, reuse many times).
- **Data hiding / security** via encapsulation and access specifiers.
- **Easy maintenance and extensibility**; modular design with classes.
- Models **real-world problems** naturally; supports **polymorphism** and **abstraction**.

### Q7. Scope Resolution Operator (`::`)
The **scope resolution operator `::`** identifies the scope to which a name belongs. Uses:
- **Access global variable** hidden by a local one: `::x`
- **Define member function outside class:** `void A::show() { }`
- **Namespace qualification:** `std::cout`

```cpp
int x = 10;
int main() { int x = 5; cout << ::x; }   // prints 10
```

### Q8. Namespaces & `using` Directive
A **namespace** is a named declarative region that groups identifiers (variables, functions, classes) to **avoid name collisions**.
- Defined using `namespace Name { ... }`.
- The **`using namespace`** directive makes all names of a namespace accessible **without the `::` prefix**.

```cpp
namespace A { int x = 1; }
using namespace A;    // now x can be used directly
```

### Q9. Default Arguments
**Default arguments** are values specified in a function declaration that are used automatically when the caller **omits** the corresponding arguments.
- Must be given **right to left** (trailing parameters only).
- Specified once, in the declaration/prototype.

```cpp
int add(int a, int b = 10);   // add(5) -> a=5, b=10
```

---

## Unit II — Classes, Objects, Functions & Constructors

### Q1. Class and Object Declaration
A **class** is a user-defined data type (blueprint) that binds **data members** and **member functions**; an **object** is an **instance** of a class.

```cpp
class Student { int id; public: void show(); };   // class
Student s1;                                       // object
```
- Memory is allocated when the **object** is created, not the class.

### Q2. Access Specifiers
- **`private`** – accessible only inside the **same class** (default for class).
- **`protected`** – accessible inside the class and its **derived classes**.
- **`public`** – accessible from **anywhere** (outside via object).
- They enforce **data hiding** and **encapsulation**.

### Q3. Member Function Definition
- **Inside class:** defined in the body; treated as **inline** by default.
- **Outside class:** declared inside, defined outside using **scope resolution `::`**.

```cpp
class A { public: void f(); };
void A::f() { cout << "out"; }   // outside definition
```

### Q4. Inline Functions
An **inline function** is one whose body is **substituted at the call site** by the compiler (keyword `inline`), reducing function-call overhead.
- Compiler **may ignore** inlining if the function contains **loops / `switch` / `goto`**, is **recursive**, or contains **`static` variables**.
```cpp
inline int sq(int x) { return x * x; }
```

### Q5. Static Members
- **Static data member:** one copy **shared by all objects**; declared `static`, defined outside the class.
- **Static member function:** accesses **only static members**; called via `Class::fn()` (no `this` pointer).
- **Lifecycle:** created before `main()` (at program start), exists for the **entire program**; independent of objects.

### Q6. Friend Function
A **friend function** is a **non-member** function declared with the keyword `friend` inside a class, allowing access to its **private and protected** members.
- Not in the scope of the class; **called without object** (like a normal function).
- Has **no `this` pointer**; accesses members via an object passed as argument.

### Q7. Member Function Overloading
**Member function overloading** means defining **multiple member functions with the same name** in a class but with **different parameter lists** (number/type/order).
- Resolved at **compile time** (static polymorphism).
- Return type alone cannot differentiate overloads.

### Q8. Array of Objects
An **array of objects** stores multiple objects of the same class in **contiguous memory**.
```cpp
Student s[3];        // 3 objects
s[0].show();         // access via index and dot
```
- Memory = `3 × sizeof(Student)`; each element has its own copy of **non-static** data members.

### Q9. Passing & Returning Objects
- **Pass by value:** a **copy** of the object is made (copy constructor called); original unchanged.
- **Pass by reference/pointer:** the **original** is accessed; efficient, changes reflect.
- **Return:** a function can return an object **by value** (temporary copy) or by reference.
```cpp
Complex add(Complex a, Complex b);   // by value, returns object
```

### Q10. Nested Classes
A **nested class** is a class **declared inside another class** (the enclosing class).
- Its **scope is limited** to the enclosing class; accessed as `Outer::Inner`.
- Nested class has **no special access** to enclosing members (and vice versa) unless granted by `friend`/public access.

### Q11. Constructor & Destructor Basics
- **Constructor:** special member function that **initializes** an object automatically at creation; same name as class, **no return type**.
- **Destructor:** releases resources when object is destroyed; named `~ClassName()`.
- Constructor can be **overloaded**; destructor **cannot** (no arguments, no return type, only one per class).

### Q12. Parameterized Constructor & Overloading
- **Parameterized constructor:** takes arguments to initialize data members with **specific values**: `Box(int l) { len = l; }`
- **Constructor overloading:** multiple constructors in a class with **different parameter lists**; compiler picks by arguments.
```cpp
Box b1; Box b2(5);     // default and parameterized
```

### Q13. Copy Constructor
A **copy constructor** initializes a new object from an **existing object** of the same class.
- **Syntax:** `ClassName(const ClassName &obj);`
- **Invoked when:** (1) object initialized from another (`A b = a;`), (2) object **passed by value**, (3) object **returned by value**.
- Argument must be passed by **reference** to avoid infinite recursion.

### Q14. Anonymous (Unnamed) Objects
An **anonymous object** is a **temporary object without a name**, created for immediate use and **destroyed at the end of the statement**.
```cpp
Box(5).show();     // temporary object, destroyed after this line
```
- Constructor and destructor are both invoked automatically.

---

## Unit III — Operator Overloading, Inheritance & Polymorphism

### Q1. Operator Overloading Definition
**Operator overloading** gives existing operators **additional meaning for user-defined types** (classes) without changing their original meaning.
- The **`operator` keyword** declares the overloading function: `return_type operator op(args)`.
- It is **compile-time polymorphism**.
```cpp
Complex operator+(Complex c);
```

### Q2. Rules of Operator Overloading
- **New operators cannot be created**; only existing ones can be overloaded.
- These **cannot** be overloaded: `::`  `.`  `.*`  `?:`  `sizeof`.
- **Precedence, associativity, and arity** of operators cannot be changed.
- At least one operand must be a **user-defined type**; `= () [] ->` must be **member** functions.

### Q3. Unary Operator Overloading
- **Member function:** takes **no argument** (operand is the invoking object): `void operator-();`
- **Friend function:** takes **one argument** (the object): `friend void operator-(Box &b);`
- Postfix form uses a dummy `int`: `operator++(int)`.

### Q4. Binary Operator Overloading
- **Member function:** takes **one argument** (right operand); left operand is the invoking object: `C operator+(C b);`
- **Friend function:** takes **two arguments**: `friend C operator+(C a, C b);`
- Friend is needed when the **left operand is not an object** (e.g., `5 + obj`).

### Q5. Code Reusability in Inheritance
**Inheritance** lets a **derived class** acquire data and functions of an existing **base class**, so existing code is **reused** instead of rewritten.
- Derived class can **add new members** or **override** base behavior.
- Reduces **redundancy, development time, and errors**.
```cpp
class Derived : public Base { };
```

### Q6. Types of Inheritance
```
Single:        Multilevel:     Multiple:     Hierarchical:   Hybrid:
  A              A               A   B            A              A
  |              |                \ /           / | \          / \
  B              B                 C           B  C  D        B   C
                 |                                             \ /
                 C                                              D
```
- **Single** (1 base→1 derived), **Multilevel** (chain), **Multiple** (many bases→1 derived), **Hierarchical** (1 base→many derived), **Hybrid** (combination).

### Q7. Protected Access Specifier in Inheritance
`protected` members are **inaccessible to outside code** (like private) but **accessible to derived classes**.
- Allows derived classes to use base data while preserving **data hiding**.
- In public inheritance, protected stays **protected** in the derived class.

### Q8. Modes of Inheritance
| Base member | Public mode | Protected mode | Private mode |
|---|---|---|---|
| **public** | public | protected | private |
| **protected** | protected | protected | private |
| **private** | not accessible | not accessible | not accessible |

### Q9. Base Class Initialization
Base class parameterized constructors are called using the **member initializer list** of the derived constructor.
```cpp
Derived(int a, int b) : Base(a) { y = b; }
```
- Base constructor runs **before** the derived constructor body.
- Without it, the base **default constructor** is invoked.

### Q10. Order of Constructor/Destructor Execution
- **Constructors:** executed from **base → derived**.
  - **Multilevel:** A → B → C (grandparent first).
  - **Multiple** (`class C : A, B`): in **order of declaration** of base classes (A, B), then C.
- **Destructors:** executed in **reverse order** (derived → base).

### Q11. Diamond Problem & Virtual Base Class
The **Diamond Problem** occurs in hybrid inheritance when a derived class inherits the same base via **two paths**, giving **duplicate copies** and **ambiguity**.
- Solved by declaring the base as **`virtual`**, so only **one shared copy** exists.
```cpp
class B : virtual public A { };
class C : virtual public A { };
class D : public B, public C { };
```

### Q12. Pointers to Objects
A **pointer to an object** stores the **address of an object**; members are accessed using the **arrow operator `->`** (or `(*p).member`).
```cpp
Student s, *p = &s;
p->show();       // same as (*p).show()
```
- Objects can also be created dynamically: `p = new Student;`.

### Q13. `this` Pointer
**`this`** is a **hidden constant pointer** holding the **address of the invoking object**.
- **Implicitly passed** to every **non-static** member function.
- Used to resolve name conflicts (`this->x = x;`) and **return the current object** (`return *this;`).
- **Not available** in static and friend functions.

### Q14. Virtual Functions & `vtable`
A **virtual function** is a base class function declared with `virtual` and **overridden** in derived classes; call is resolved at **run time** via a base pointer (**run-time polymorphism**).
- **vtable:** per-class table of **virtual function addresses**.
- **vptr:** hidden pointer in each object pointing to its class's vtable; used to select the correct function at run time.

---

## Unit IV — Generic Programming, Templates & Exceptions

### Q1. Generic Programming & Templates
**Generic programming** writes code **independent of data types**, using types as parameters.
- **Templates** are needed to avoid **duplicate code** for each type (`int`, `float`, ...), giving **reusability and type safety**.
- Types are substituted at **compile time**.

### Q2. Function Template
A **function template** defines a **generic function** that works with any data type.
```cpp
template <class T>
T maxOf(T a, T b) { return (a > b) ? a : b; }
```
- Call: `maxOf(3, 7);` or `maxOf<double>(2.5, 1.2);`.

### Q3. Class Template
A **class template** defines a **generic class** whose data members/functions use a type parameter.
```cpp
template <class T>
class Stack { T arr[10]; int top; public: void push(T x); };
```
- Member functions defined outside use `template <class T> void Stack<T>::push(T x) {...}`.

### Q4. Class Template Instantiation
A class template is instantiated by **specifying the actual type in angle brackets** `<>` when creating an object; the compiler generates a class for that type.
```cpp
Stack<int> s1;        // class for int
Stack<float> s2;      // class for float
```

### Q5. Overloading Template Functions
- A template function can be overloaded with **other templates** or **non-template functions** of the same name.
- **Resolution order:** an **exact-match non-template function** is preferred over the template; otherwise the template is instantiated.
- Explicit `<>` call forces the **template** version.

### Q6. Templates vs Macros
| Feature | Template | Macro |
|---|---|---|
| **Type safety** | Type-checked by compiler | **No** type checking |
| **Debugging** | Easy (real compiler errors) | Hard (text substitution by preprocessor) |
| **Code expansion** | Compiler-generated per type; scoped | Blind text replacement; side-effects (`SQ(x++)`) |

### Q7. Non-Type Template Parameters
A **non-type parameter** is a template parameter that is a **constant value** (e.g., `int`) instead of a type.
```cpp
template <class T, int N>
class Array { T a[N]; };
Array<int, 5> arr;      // fixed-size array of 5 ints
```
- Value must be a **compile-time constant**.

---

## Unit V — File Streams & Standard Template Library

### Q1. Exception Handling
**Exception handling** is a mechanism to detect and handle **run-time errors** (e.g., divide by zero) so the program does not terminate abnormally.
- **Principle:** **separate error-handling code** from normal code; an error is **thrown** at the point of detection and **caught** by a handler.
- Keywords: `try`, `throw`, `catch`.

### Q2. Roles of `try`, `catch`, and `throw`
- **`try`** – block enclosing code that **may generate** an exception.
- **`throw`** – **raises** (signals) the exception with a value/object.
- **`catch`** – **handler** that receives and processes the thrown exception.
```cpp
try { if (b == 0) throw 0; }
catch (int e) { cout << "Divide by zero"; }
```

### Q3. Multiple Catch & Catch-All
- **Multiple catch:** several `catch` blocks after one `try`, each handling a **different exception type**; the matching one runs.
- **Catch-all:** `catch(...)` handles **any** exception type; must be placed **last**.
```cpp
try { ... } catch (int e) { } catch (...) { cout << "Unknown"; }
```

### Q4. Stream Classes
A **stream** is a **sequence of bytes** flowing between the program and an I/O device.
- **Input stream (`cin`):** object of `istream`; reads data from keyboard using **extraction `>>`**.
- **Output stream (`cout`):** object of `ostream`; writes data to screen using **insertion `<<`**.

### Q5. File Stream Classes
Defined in `<fstream>`:
- **`ifstream`** – **input** file stream; used to **read** from files.
- **`ofstream`** – **output** file stream; used to **write** to files.
- **`fstream`** – **both** read and write.

### Q6. File Open Modes
- **`ios::in`** – open file for **reading**.
- **`ios::out`** – open for **writing** (truncates existing contents).
- **`ios::app`** – **append**; writes at the end of file.
- **`ios::binary`** – open in **binary** mode (not text).
```cpp
ofstream f("a.txt", ios::out | ios::app);
```

### Q7. File Pointers (`seekg`, `seekp`, `tellg`, `tellp`)
- **`seekg(pos)`** / **`seekp(pos)`** – **move** the get (read) / put (write) pointer to a position.
- **`tellg()`** / **`tellp()`** – **return the current** position of the get / put pointer.
- `g` = **get** (input), `p` = **put** (output). Offsets use `ios::beg`, `ios::cur`, `ios::end`.

### Q8. Standard Template Library (STL)
**STL** is a library of **generic, reusable template classes and functions** for data structures and algorithms.
- Three core components: **Containers**, **Algorithms**, **Iterators**.

### Q9. STL Containers
- **Sequence containers:** store elements in **linear order** by position; e.g., **`vector`, `list`, `deque`**.
- **Associative containers:** store elements as **sorted keys** for fast lookup; e.g., **`set`, `map`, `multiset`, `multimap`**.
- Sequence: access by **position**; Associative: access by **key**.

### Q10. STL Iterators
An **iterator** is an **object that behaves like a pointer**, used to traverse and access elements of a container.
- Five categories: **Input, Output, Forward, Bidirectional, Random Access**.
```cpp
vector<int>::iterator it = v.begin();
```

### Q11. STL Algorithms
**STL algorithms** are **generic functions** in `<algorithm>` that operate on container elements via **iterators** (e.g., searching, sorting).
- Examples: **`sort()`**, **`find()`**, **`reverse()`**, **`count()`** (also `max_element`, `binary_search`).
```cpp
sort(v.begin(), v.end());
```
