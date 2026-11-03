# Object Oriented Programming through C++ — Model Question Paper

**Course Code:** `2501CS08`  
**Course Name:** Object Oriented Programming through C++  
**Program:** B.Tech — III Semester End Examinations (Regular)  
**Time:** 3 Hours | **Max. Marks:** 100 Marks  

---

### Instructions to Candidates
1. **Section-A** is compulsory. Answer **all 10 questions** (2 Marks each = **20 Marks**).
2. **Section-B** contains 5 units with internal choice. Answer **one full question** from each unit (**16 Marks each = 80 Marks**; each question consists of two 8-mark sub-questions `a` and `b`).

---

## SECTION – A (Compulsory)
**Answer ALL questions. Each question carries 2 marks.** `[10 × 2M = 20M]`

| Q.No | Sub | Question Statement | Unit | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :---: | :--- |
| **1** | **a** | State any two major differences between C and C++. | **I** | `[2M]` | [→ View Answer](2-marks.md#q1-differences-between-c-and-c) |
|  | **b** | Explain the use and syntax of the Scope Resolution Operator (`::`). | **I** | `[2M]` | [→ View Answer](2-marks.md#q7-scope-resolution-operator) |
|  | **c** | Differentiate between `private`, `protected`, and `public` access specifiers. | **II** | `[2M]` | [→ View Answer](2-marks.md#q2-access-specifiers) |
|  | **d** | What is an inline function? State any two conditions where compiler ignores inlining. | **II** | `[2M]` | [→ View Answer](2-marks.md#q4-inline-functions) |
|  | **e** | List any four non-overloadable operators in C++. | **III** | `[2M]` | [→ View Answer](2-marks.md#q2-rules-of-operator-overloading) |
|  | **f** | What is the Diamond Problem in inheritance and how is it resolved? | **III** | `[2M]` | [→ View Answer](2-marks.md#q11-diamond-problem-virtual-base-class) |
|  | **g** | What is generic programming and why are templates needed in C++? | **IV** | `[2M]` | [→ View Answer](2-marks.md#q1-generic-programming-templates) |
|  | **h** | State any three differences between C++ templates and C preprocessor macros. | **IV** | `[2M]` | [→ View Answer](2-marks.md#q6-templates-vs-macros) |
|  | **i** | Differentiate between `seekg()`/`seekp()` and `tellg()`/`tellp()` in file handling. | **V** | `[2M]` | [→ View Answer](2-marks.md#q7-file-pointers-seekg-seekp-tellg-tellp) |
|  | **j** | Name the three fundamental components of the Standard Template Library (STL). | **V** | `[2M]` | [→ View Answer](2-marks.md#q8-standard-template-library-stl) |

---

## SECTION – B (Unit-Wise Internal Choice)
**Answer ONE question from each Unit. Each question carries 16 marks.** `[5 × 16M = 80M]`

### UNIT – I
| Q.No | Sub | Question Statement | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **2** | **a** | Explain the evolution of C++ from C and state the disadvantages of conventional procedural programming paradigms. | `[8M]` | [→ `unit-1.md#Q1`](unit-1.md#question-1-evolution-of-c-paradigm-shift) |
|  | **b** | Explain the fundamental principles of Object-Oriented Programming (encapsulation, abstraction, inheritance, polymorphism) and detail the advantages OOP offers over procedural models. | `[8M]` | [→ `unit-1.md#Q3`](unit-1.md#question-3-oop-principles-advantages) |
|  |  | **OR** |  |  |
| **3** | **a** | Describe the standard structure of a C++ program and explain how input and output operations are handled using streams and stream manipulators (`setw`, `setprecision`, `endl`). | `[8M]` | [→ `unit-1.md#Q4`](unit-1.md#question-4-program-structure-stream-io) |
|  | **b** | What is a namespace in C++? Explain how to define nested namespaces, use the `using` directive/declaration, and resolve identifier naming collisions. | `[8M]` | [→ `unit-1.md#Q6`](unit-1.md#question-6-namespaces) |

---

### UNIT – II
| Q.No | Sub | Question Statement | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **4** | **a** | Explain how classes and objects are declared, and distinguish between defining member functions inside a class versus outside the class using the scope resolution operator. | `[8M]` | [→ `unit-2.md#Q1`](unit-2.md#question-1-class-declaration-member-function-scope) |
|  | **b** | What is a friend function? Analyze how friend functions bridge data sharing between two independent classes without violating encapsulation. | `[8M]` | [→ `unit-2.md#Q4`](unit-2.md#question-4-friend-functions) |
|  |  | **OR** |  |  |
| **5** | **a** | Define constructors and destructors, detail their essential characteristics, and explain why destructors cannot be overloaded or take arguments. | `[8M]` | [→ `unit-2.md#Q7`](unit-2.md#question-7-constructors-destructors-basics) |
|  | **b** | Explain the role and syntax of a copy constructor, distinguish deep copy from shallow copy, and demonstrate dynamic initialization of constructors using `new`. | `[8M]` | [→ `unit-2.md#Q9`](unit-2.md#question-9-copy-constructor-dynamic-initialization) |

---

### UNIT – III
| Q.No | Sub | Question Statement | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **6** | **a** | Explain the rules for operator overloading, identify the non-overloadable operators in C++, and distinguish between overloading using a member function versus a friend function. | `[8M]` | [→ `unit-3.md#Q1`](unit-3.md#question-1-operator-overloading-rules) |
|  | **b** | Explain different types of inheritance supported by C++ (single, multiple, multi-level, hierarchical, hybrid) with class diagrams, syntax, and examples. | `[8M]` | [→ `unit-3.md#Q3`](unit-3.md#question-3-inheritance-types) |
|  |  | **OR** |  |  |
| **7** | **a** | Detail the execution order of constructors and destructors in multi-level and multiple inheritance hierarchies with an illustrative code example. | `[8M]` | [→ `unit-3.md#Q5`](unit-3.md#question-5-constructordestructor-order) |
|  | **b** | Explain the use of virtual functions with an illustrative program, and analyze the internal working of the Virtual Table (`vtable`) and Virtual Pointer (`vptr`). | `[8M]` | [→ `unit-3.md#Q7`](unit-3.md#question-7-virtual-functions-vtablevptr-internals) |

---

### UNIT – IV
| Q.No | Sub | Question Statement | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **8** | **a** | What is a class template? Implement a generic `Stack<T>` class template with `push`, `pop`, and `display` operations. | `[8M]` | [→ `unit-4.md#Q2`](unit-4.md#question-2-class-templates-and-generic-stack) |
|  | **b** | Write a C++ template program to implement the Bubble Sort algorithm for sorting arrays of both integers and floating-point values. | `[8M]` | [→ `unit-4.md#Q5`](unit-4.md#question-5-template-bubble-sort) |
|  |  | **OR** |  |  |
| **9** | **a** | Design a generic Singly Linked List class template supporting node insertion and traversal. | `[8M]` | [→ `unit-4.md#Q6`](unit-4.md#question-6-generic-singly-linked-list) |
|  | **b** | Explain the principles of exception handling in C++, detail the role of `try`, `throw`, and `catch` blocks, and trace the exception propagation flow. | `[8M]` | [→ `unit-4.md#Q7`](unit-4.md#question-7-exception-handling-principles) |

---

### UNIT – V
| Q.No | Sub | Question Statement | Marks | Direct Answer Link |
| :---: | :---: | :--- | :---: | :--- |
| **10** | **a** | Describe the C++ stream class hierarchy (`ios`, `istream`, `ostream`, `fstream`) and explain how file stream classes handle file operations. | `[8M]` | [→ `unit-5.md#Q1`](unit-5.md#question-1-stream-class-hierarchy) |
|  | **b** | Explain various file open modes and file pointers manipulation using `seekg()`, `seekp()`, `tellg()`, and `tellp()`. | `[8M]` | [→ `unit-5.md#Q3`](unit-5.md#question-3-open-modes-file-pointers) |
|  |  | **OR** |  |  |
| **11** | **a** | Demonstrate reading and writing binary files using `write()` and `read()` member functions with structured record objects. | `[8M]` | [→ `unit-5.md#Q4`](unit-5.md#question-4-binary-file-io) |
|  | **b** | Explain the taxonomy of STL containers: sequence containers vs associative containers, comparing their time complexity and use cases in a table. | `[8M]` | [→ `unit-5.md#Q6`](unit-5.md#question-6-container-taxonomy) |
