# Object Oriented Programming through C++ — Study Hub (CPP)

Academic exam preparation notes, unit-wise questions, and complete worked answers covering all 5 Units (41 Questions) for Aditya University (Course Code: `2501CS08`).

---

## Examination Blueprint & Course Overview

- **Subject:** Object Oriented Programming through C++ (`2501CS08`)
- **Exam Date:** Wednesday, 04-11-2026 (End-Sem)
- **Exam Format:** 100 Marks (3 Hours)
  - **Section A (Compulsory):** 10 Qs × 2M = 20 Marks (2 Qs from each Unit) → [`2-marks-answers.md`](2-marks-answers.md)
  - **Section B (Internal Choice):** 5 Units × 16M (two 8M Qs per unit) = 80 Marks → [`unit-1.md`](unit-1.md) to [`unit-5.md`](unit-5.md)
- **Official Model Paper:** [`model-paper.md`](model-paper.md) (Complete 100M question paper blueprint matching ADSA standard)

---

## Repository Index & Unit Navigation

| Section / Unit | Title | Questions Count | Answers Document | Syllabus / Source Coverage |
| :---: | :--- | :---: | :--- | :--- |
| **Model Paper** | **100M Exam Blueprint** | Full Paper | [`model-paper.md`](model-paper.md) | Standard Aditya University Model Paper |
| **Section A** | **2-Marks Short Answers** | 55 Qs | [`2-marks-answers.md`](2-marks-answers.md) | Compulsory 20M Section A (All 5 Units) |
| **Index** | **Master Questions Index** | 41 Qs (8M) | [`questions.md`](questions.md) | Official 8-Marks Semester Question Bank |
| **Unit 1** | C++ Fundamentals & Paradigms | 8 Qs | [`unit-1.md`](unit-1.md) | `raw/Unit 1_CPP.pptx`, `Reference Course Material` |
| **Unit 2** | Classes, Objects, Functions & Constructors | 9 Qs | [`unit-2.md`](unit-2.md) | `raw/Unit 2_CPP.pptx`, `Reference Course Material` |
| **Unit 3** | Operator Overloading, Inheritance & Polymorphism | 8 Qs | [`unit-3.md`](unit-3.md) | `raw/Unit 3_CPP_1.pptx`, `raw/cpp-3.pdf` |
| **Unit 4** | Generic Programming, Templates & Exceptions | 8 Qs | [`unit-4.md`](unit-4.md) | `raw/Unit 4.pptx`, `raw/UNIT 4(CPP).pdf` |
| **Unit 5** | File Streams & Standard Template Library (STL) | 8 Qs | [`unit-5.md`](unit-5.md) | `raw/Unit 5.pptx`, `raw/cpp 5.pdf` |

---

## Directory Structure

```text
CPP/
├── archive/
│   └── mid-2/              # Archived Mid-2 partial notes (Units 3, 4, 5)
├── figures/                # Visual diagrams & charts
├── Lab/                    # C++ Lab programs & exercises
├── MICS/                   # Miscellaneous notes & questions
├── raw/                    # Raw PDFs, Question Banks & PPTs
├── model-paper.md          # 100M Semester Exam Blueprint & Model Paper
├── questions.md            # Master 8M question index linking all 41 questions
├── 2-marks-answers.md      # Complete Section A 2-Marks Short Answers (55 Qs)
├── unit-1.md               # Unit 1 worked solutions (Q1–Q8)
├── unit-2.md               # Unit 2 worked solutions (Q1–Q9)
├── unit-3.md               # Unit 3 worked solutions (Q1–Q8)
├── unit-4.md               # Unit 4 worked solutions (Q1–Q8)
├── unit-5.md               # Unit 5 worked solutions (Q1–Q8)
└── README.md               # Subject hub overview
```

---

## Key Question Highlights by Unit

### Unit 1: C++ Fundamentals & Paradigms
- Evolution of C++ from C and procedural vs OOP paradigm comparison
- 4 OOP Pillars (Encapsulation, Abstraction, Inheritance, Polymorphism)
- Streams & Stream Manipulators (`setw`, `setprecision`, `endl`)
- Scope Resolution Operator `::` (3 major use cases)
- Namespaces & conflict resolution; Default arguments vs function overloading
- Factorial recursion & Quadratic roots programs

### Unit 2: Classes, Objects, Functions & Constructors
- In-class vs out-of-class member function definitions
- Inline functions and compiler disregard rules
- Static data members & static member functions (object counter)
- Friend functions and cross-class data bridges
- Object passing (pass-by-value vs pass-by-reference) & array of objects
- Constructors (default, parameterized, overloaded, copy constructor: deep vs shallow)

### Unit 3: Operator Overloading, Inheritance & Polymorphism
- Operator overloading rules & non-overloadable operators (`::`, `.`, `.*`, `?:`, `sizeof`, `typeid`)
- Binary operator overloading (`+` arithmetic and `==` relational)
- 5 types of inheritance with class hierarchies
- Diamond problem and resolution via Virtual Base Classes
- Constructor/Destructor execution ordering in inheritance
- Virtual functions, `vptr`, and `vtable` architecture
- Abstract classes, pure virtual functions, and virtual destructors

### Unit 4: Generic Programming, Templates & Exceptions
- Function templates and template overloading
- Class templates: generic `Stack<T>` implementation
- Non-type template parameters and multi-type templates
- Templates vs Macros comparison
- Bubble Sort template for mixed types
- Generic Singly Linked List class template
- Exception handling architecture (`try`, `throw`, `catch`), propagation, multiple catches, and re-throwing

### Unit 5: File Streams & Standard Template Library (STL)
- C++ Stream class hierarchy (`ios`, `istream`, `ostream`, `fstream`)
- Sequential text file operations (`ofstream`, `ifstream`) with error checks
- File open modes and file pointers (`seekg`, `seekp`, `tellg`, `tellp`)
- Binary file read/write with object records
- STL Architecture (Containers, Iterators, Algorithms)
- Container taxonomy (Sequence vs Associative) and complexity tradeoffs
- 5 Iterator categories (Input, Output, Forward, Bidirectional, Random Access)
- Practical STL demo with `vector`, `list`, `map`, and algorithms (`std::sort`, `std::find`)
