# TASK: Generate 2-Marks Exam-Ready Notes for C++ (Aditya University — Shiroya Vault)

You are an expert academic tutor authoring exam-scoring study notes for a 2nd-year B.Tech Data Science student at Aditya University for **Object Oriented Programming through C++ (2501CS08)**.

The exam has a revised question paper blueprint:
- **Total Marks:** 100 Marks (3 Hours)
- **Section A (Compulsory):** 10 Questions × 2 Marks = **20 Marks** (2 questions from each of the 5 Units)
- **Section B (Internal Choice):** 5 Units × 16 Marks = **80 Marks** (Each unit offers an OR choice: either Q_a & Q_b [8M + 8M] or Q_alt_a & Q_alt_b [8M + 8M])

This prompt focuses exclusively on generating crisp, high-scoring **2-Marks Questions & Answers** across all 5 Units.

---

### STRICT WRITING & FORMATTING RULES
1. **Target:** 2 Marks per answer. Evaluators spend 15–30 seconds grading each 2-mark question. They look for **definitions, exact keywords, bullet points, and minimal 1–3 line syntax/code snippets**.
2. **Length:** Exactly 3–6 lines per answer. No long theoretical essays. No conversational intro/outro ("In this question...", "Here is the answer").
3. **Elements per 2-Mark Answer:**
   - **Core Definition / Statement:** 1–2 crisp sentences with bolded technical terms.
   - **Key Points / Rules:** 2 to 4 bullet points.
   - **Syntax / 2-Line Example (where applicable):** Inline code or minimal 2-line snippet.
4. **Obsidian Heading Hierarchy (Strict):**
   - H1: `# Object Oriented Programming through C++ — 2-Marks Short Answers (All Units)`
   - H2: `## Unit <N> — <Unit Name>`
   - H3: `### Q<N>. <Question Title>`
   - Body: Clean Markdown with bullets, bold terms, and syntax blocks.
5. **Output File:** Generate a single, comprehensive markdown file: `2-marks-answers.md`.

---

## 2-MARKS QUESTIONS BANK (55 QUESTIONS ACROSS 5 UNITS)

### UNIT I: C++ Fundamentals & Paradigms (9 Questions)
1. **Differences between C and C++:** State any two major differences between C and C++.
2. **Disadvantages of Procedural Programming:** What are the major disadvantages of conventional (procedural) programming?
3. **Evolution of C++:** Trace the evolution of C++ in brief (Stroustrup, Bell Labs, C with Classes).
4. **Key OOP Concepts:** List the four foundational pillars of Object-Oriented Programming (OOP).
5. **C++ Program Structure:** Explain the general structure and major sections of a C++ program.
6. **Advantages of OOP:** State any four advantages of Object-Oriented Programming over procedural models.
7. **Scope Resolution Operator (`::`):** Explain the use and syntax of the Scope Resolution Operator (global access, out-of-class member definition, namespace qualification).
8. **Namespaces & `using` Directive:** Define a Namespace and explain the purpose of the `using namespace` directive.
9. **Default Arguments:** What are default arguments in C++? Give a brief syntax example.

### UNIT II: Classes, Objects, Functions & Constructors (14 Questions)
1. **Class and Object Declaration:** How do you declare a class and an object in C++? Give standard syntax.
2. **Access Specifiers:** Differentiate between `private`, `protected`, and `public` access specifiers.
3. **Member Function Definition:** How can a member function be defined inside a class vs outside a class using `::`?
4. **Inline Functions:** What is an inline function? List any two rules/conditions where the compiler disregards inlining.
5. **Static Members:** What are static data members and static member functions? State their memory lifecycle.
6. **Friend Function:** What is a friend function? State its two key characteristics regarding access and `this` pointer.
7. **Member Function Overloading:** What is member function overloading in C++?
8. **Array of Objects:** Explain the concept of an Array of Objects with syntax and memory layout.
9. **Passing & Returning Objects:** Explain how objects are passed as parameters (by value vs by reference) and returned from functions.
10. **Nested Classes:** What is a Nested Class in C++ and what are its scoping rules?
11. **Constructor & Destructor Basics:** Define constructor and destructor. State their key characteristics.
12. **Parameterized Constructor & Overloading:** What is a parameterized constructor and constructor overloading?
13. **Copy Constructor:** What is a copy constructor? State its syntax and invocation scenarios.
14. **Anonymous (Unnamed) Objects:** What is an anonymous object (temporary object) in C++?

### UNIT III: Operator Overloading, Inheritance & Polymorphism (14 Questions)
1. **Operator Overloading Definition:** What is operator overloading? What is the role of the `operator` keyword?
2. **Rules of Operator Overloading:** List any four strict rules for operator overloading in C++.
3. **Unary Operator Overloading:** How does unary operator overloading differ using a member function vs a friend function?
4. **Binary Operator Overloading:** How does binary operator overloading differ using a member function vs a friend function?
5. **Code Reusability in Inheritance:** Explain the concept of code reusability in inheritance.
6. **Types of Inheritance:** List the five types of inheritance supported in C++ with simple ASCII inheritance diagrams.
7. **Protected Access Specifier in Inheritance:** Explain the role and visibility of the `protected` access specifier during derivation.
8. **Modes of Inheritance:** Distinguish between public, protected, and private inheritance modes in a comparison table.
9. **Base Class Initialization:** How are base class parameterized constructors invoked from a derived class constructor?
10. **Order of Constructor/Destructor Execution:** State the exact execution order of constructors and destructors in multi-level and multiple inheritance.
11. **Diamond Problem & Virtual Base Class:** What is the Diamond Problem and how does the `virtual` base class keyword resolve it?
12. **Pointers to Objects:** What is a pointer to an object and how are members accessed through it (`->`)?
13. **`this` Pointer:** What is the `this` pointer in C++ and when is it implicitly passed?
14. **Virtual Functions & `vtable`:** What is a virtual function and what role do the `vtable` and `vptr` play in runtime polymorphism?

### UNIT IV: Generic Programming, Templates & Exceptions (7 Questions)
1. **Generic Programming & Templates:** What is generic programming and why are templates needed in C++?
2. **Function Template:** Define a function template with clear C++ syntax.
3. **Class Template:** Define a class template with clear C++ syntax.
4. **Class Template Instantiation:** How is a class template instantiated for specific data types? Give an example.
5. **Overloading Template Functions:** How does template function overloading work when a regular non-template function matches?
6. **Templates vs Macros:** State three critical differences between C++ templates and C preprocessor macros (type safety, debugging, code expansion).
7. **Non-Type Template Parameters:** What is a non-type template parameter? Give an example (e.g., fixed-size array).

### UNIT V: File Streams & Standard Template Library (11 Questions)
1. **Exception Handling:** What is exception handling in C++? State its fundamental principle.
2. **Roles of `try`, `catch`, and `throw`:** Explain the distinct roles of the `try`, `catch`, and `throw` keywords.
3. **Multiple Catch & Catch-All:** What are multiple catch statements and what is the syntax of the catch-all `catch(...)` handler?
4. **Stream Classes:** What is a stream in C++? Differentiate between input streams (`cin`) and output streams (`cout`).
5. **File Stream Classes:** What are the specific roles of `ifstream`, `ofstream`, and `fstream` classes?
6. **File Open Modes:** List and define any four file open mode flags (`ios::in`, `ios::out`, `ios::app`, `ios::binary`).
7. **File Pointers (`seekg`, `seekp`, `tellg`, `tellp`):** Differentiate between `seekg()` / `seekp()` and `tellg()` / `tellp()`.
8. **Standard Template Library (STL):** What is STL? Name its three core foundational components.
9. **STL Containers:** Distinguish between Sequence Containers (`vector`, `list`) and Associative Containers (`set`, `map`).
10. **STL Iterators:** What is an iterator in STL? List the five iterator categories.
11. **STL Algorithms:** What are STL algorithms? Name four standard algorithms provided in `<algorithm>`.

---

### OUTPUT DELIVERY
Deliver the completed content formatted as `2-marks-answers.md` ready to be placed in `P:\Magnanimity\Projects\Shiroya\CPP\`.
