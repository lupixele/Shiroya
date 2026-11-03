# Object Oriented Programming through C++ — Questions Index (2501CS08)

> **Navigation:** [`model-paper.md` — 100M Exam Blueprint](model-paper.md) · [`2-marks.md` — 55 Short Q&As](2-marks.md)  
> **Worked Answer Files:** [`unit-1.md`](unit-1.md) · [`unit-2.md`](unit-2.md) · [`unit-3.md`](unit-3.md) · [`unit-4.md`](unit-4.md) · [`unit-5.md`](unit-5.md)

---

## Unit 1
**C++ Fundamentals & Paradigms**  
> *Section A Short Answers:* [→ Unit I (2M Q&As)](2-marks.md#unit-i-c-fundamentals-paradigms)

1. [Evolution & Paradigm Shift](unit-1.md#question-1-evolution-of-c-paradigm-shift) — Evolution of C++ from C; disadvantages of procedural programming.
2. [C vs C++ Comparison](unit-1.md#question-2-c-vs-c-comparison) — Paradigms, data security, memory management, function extensions.
3. [OOP Principles & Advantages](unit-1.md#question-3-oop-principles-advantages) — Encapsulation, abstraction, inheritance, polymorphism; advantages over procedural.
4. [Program Structure & Stream I/O](unit-1.md#question-4-program-structure-stream-io) — Program structure; `cin`, `cout`, `setw`, `setprecision`, `endl`.
5. [Scope Resolution Operator](unit-1.md#question-5-scope-resolution-operator) — Global access, out-of-class definitions, namespace qualification.
6. [Namespaces](unit-1.md#question-6-namespaces) — Nested namespaces, `using` directive/declaration, collisions.
7. [Default Arguments & Access Specifiers](unit-1.md#question-7-default-arguments-access-specifiers) — Default args vs overloading; `private`/`public`/`protected`.
8. [Core Programs](unit-1.md#question-8-core-programs) — Quadratic roots; recursive factorial.

---

## Unit 2
**Classes, Objects, Functions & Constructors**  
> *Section A Short Answers:* [→ Unit II (2M Q&As)](2-marks.md#unit-ii-classes-objects-functions-constructors)

1. [Class Declaration & Member Function Scope](unit-2.md#question-1-class-declaration-member-function-scope) — Declaration, syntax, inside vs outside class definitions using `::`.
2. [Inline Functions](unit-2.md#question-2-inline-functions) — Advantages over macros, execution mechanics, conditions where compiler disregards inlining.
3. [Static Members & Live Counter](unit-2.md#question-3-static-members-live-counter) — Static data members, static member functions, and tracking active live objects.
4. [Friend Functions](unit-2.md#question-4-friend-functions) — Non-member friend functions bridging private data between two independent classes.
5. [Object Argument Passing & Return](unit-2.md#question-5-object-argument-passing-return) — Pass-by-value vs pass-by-reference and returning objects from member functions.
6. [Array of Objects & Pointers to Members](unit-2.md#question-6-array-of-objects-pointers-to-members) — Memory organization, pointer-to-member syntax (`.*`, `->*`).
7. [Constructors & Destructors Basics](unit-2.md#question-7-constructors-destructors-basics) — Characteristics, memory management, why destructors cannot be overloaded.
8. [Constructor Overloading & Defaults](unit-2.md#question-8-constructor-overloading-defaults) — Default, parameterized, and constructor overloading with default arguments.
9. [Copy Constructor & Dynamic Initialization](unit-2.md#question-9-copy-constructor-dynamic-initialization) — Copy constructor, shallow vs deep copy, dynamic allocation using `new`.

---

## Unit 3
**Operator Overloading, Inheritance & Polymorphism**  
> *Section A Short Answers:* [→ Unit III (2M Q&As)](2-marks.md#unit-iii-operator-overloading-inheritance-polymorphism)

1. [Operator Overloading Rules](unit-3.md#question-1-operator-overloading-rules) — Operator overloading syntax, restrictions, and member vs friend function comparison.
2. [Binary Operator Overloading](unit-3.md#question-2-binary-operator-overloading) — Overloading binary arithmetic (`+`) and relational (`==`) operators.
3. [Inheritance Types](unit-3.md#question-3-inheritance-types) — Single, multiple, multilevel, hierarchical, and hybrid inheritance with class diagrams.
4. [Diamond Problem & Virtual Base Classes](unit-3.md#question-4-diamond-problem-virtual-base-classes) — Multipath inheritance ambiguity and resolution via `virtual` base classes.
5. [Constructor/Destructor Order](unit-3.md#question-5-constructordestructor-order) — Constructor call and destructor cleanup sequence in multiple/multilevel hierarchies.
6. [Pointers to Objects & Base-Derived Compatibility](unit-3.md#question-6-pointers-to-objects-base-derived-compatibility) — Object pointers and assigning derived class addresses to base pointers.
7. [Virtual Functions & vtable/vptr Internals](unit-3.md#question-7-virtual-functions-vtablevptr-internals) — Runtime polymorphism, dynamic binding, `vptr` pointer and `vtable` dispatch.
8. [Abstract Classes & Virtual Destructors](unit-3.md#question-8-abstract-classes-virtual-destructors) — Pure virtual functions, abstract classes, and why virtual destructors are required.

---

## Unit 4
**Generic Programming, Templates & Exceptions**  
> *Section A Short Answers:* [→ Unit IV (2M Q&As)](2-marks.md#unit-iv-generic-programming-templates-exceptions)

1. [Generic Programming & Function Templates](unit-4.md#question-1-generic-programming-function-templates) — Type parameterization, template instantiation, and function template overloading.
2. [Class Templates and Generic Stack](unit-4.md#question-2-class-templates-and-generic-stack) — Generic class syntax and implementing a `Stack<T>` template with push/pop/display.
3. [Multiple Arguments & Non-Type Parameters](unit-4.md#question-3-multiple-arguments-non-type-parameters) — Multiple generic type parameters and non-type template arguments (e.g., fixed sizes).
4. [Templates vs Macros](unit-4.md#question-4-templates-vs-macros) — Type safety, code bloat, debugging, and scope comparison table.
5. [Template Bubble Sort](unit-4.md#question-5-template-bubble-sort) — Bubble sort template function handling `int`, `float`, and `char` arrays.
6. [Generic Singly Linked List](unit-4.md#question-6-generic-singly-linked-list) — Node template and linked list template supporting insertion and traversal.
7. [Exception Handling Principles](unit-4.md#question-7-exception-handling-principles) — Principles, `try`-`throw`-`catch` mechanics, and call-stack unwinding flow.
8. [Multiple Catch & Re-throwing](unit-4.md#question-8-multiple-catch-re-throwing) — Multiple catch blocks, catch-all `catch(...)`, re-throwing, and exception specifications.

---

## Unit 5
**File I/O Streams & Standard Template Library**  
> *Section A Short Answers:* [→ Unit V (2M Q&As)](2-marks.md#unit-v-file-streams-standard-template-library)

1. [Stream Class Hierarchy](unit-5.md#question-1-stream-class-hierarchy) — `ios`, `istream`, `ostream`, `ifstream`, `ofstream`, `fstream` class hierarchy.
2. [File Operations (Sequential)](unit-5.md#question-2-file-operations-sequential) — Sequential text file operations: open, write, read, and close with error validation.
3. [Open Modes & File Pointers](unit-5.md#question-3-open-modes-file-pointers) — File open mode flags (`ios::in`, `out`, `app`, `binary`) and pointer navigation (`seekg`, `seekp`, `tellg`, `tellp`).
4. [Binary File I/O](unit-5.md#question-4-binary-file-io) — Reading and writing structured binary records using `.read()` and `.write()`.
5. [STL Overview](unit-5.md#question-5-stl-overview) — STL triad: Containers, Iterators, and Algorithms architecture and interaction.
6. [Container Taxonomy](unit-5.md#question-6-container-taxonomy) — Sequence containers (`vector`, `list`, `deque`) vs associative containers (`map`, `set`).
7. [Iterator Categories](unit-5.md#question-7-iterator-categories) — 5 iterator classes (Input, Output, Forward, Bidirectional, Random Access) and operations.
8. [Practical STL Integration](unit-5.md#question-8-practical-stl-integration) — Complete code integrating `vector`, `list`, `map`, and standard algorithms (`sort`, `find`).
