# Object Oriented Programming through C++ — 2-Marks Short Answers (All Units)

> **Source:** Aditya University Official 2-Marks Question Bank (`2501CS08`)  
> **Exam Coverage:** Section A (Compulsory 10 × 2M = 20 Marks)  
> **Format:** Simple, direct 2-sentence answers matching the faculty evaluation key.

---

## Unit I — C++ Fundamentals & Paradigms

### Q1. State any two major differences between C and C++.
- **Paradigm:** C is a **procedural language** based on functions and algorithms, whereas C++ is a **multi-paradigm language** supporting Object-Oriented Programming (classes, objects).
- **Data Security:** C lacks encapsulation and data hiding, while C++ provides **access specifiers** (`private`, `protected`, `public`) and **polymorphism**.

### Q2. What are the major disadvantages of conventional (procedural) programming?
- In conventional programming, **data moves globally and openly** between functions without security or data hiding, making systems error-prone.
- It lacks **reusability**, **inheritance**, and real-world modeling capabilities, making large programs difficult to maintain.

### Q3. Trace the evolution of C++ in brief.
- Developed by **Bjarne Stroustrup in 1979** at Bell Laboratories as an enhancement to the C language, initially named **"C with Classes"**.
- In **1983**, it was renamed **C++** (symbolizing the increment operator `++`), adding OOP features, virtual functions, and operator overloading.

### Q4. List the key concepts of Object-Oriented Programming (OOP).
1. **Objects** (runtime entities)
2. **Classes** (user-defined blueprints)
3. **Data Abstraction & Encapsulation** (data hiding)
4. **Inheritance** (code reusability)
5. **Polymorphism** (one interface, multiple implementations)
6. **Dynamic Binding & Message Passing**

### Q5. Explain the general structure of a C++ program.
A standard C++ program consists of:
1. **Include Header Files:** `#include <iostream>`
2. **Namespace Declaration:** `using namespace std;`
3. **Class / Function Declarations**
4. **Main Function:** `int main() { ... return 0; }`

### Q6. State any four advantages of Object-Oriented Programming.
1. **Reusability:** Existing code can be reused through inheritance.
2. **Data Security:** Data hiding prevents unauthorized external modification.
3. **Easy Maintenance:** Modular structure makes debugging and upgrading easy.
4. **Real-World Modeling:** Real-world problems are mapped naturally into objects.

### Q7. Explain the use and syntax of the Scope Resolution Operator (::).
The **Scope Resolution Operator `::`** is used to:
1. **Access a global variable** when shadowed by a local variable with the same name (`::varName`).
2. **Define member functions outside a class:** `ReturnType ClassName::funcName() { ... }`.
3. **Qualify namespace entities:** `std::cout`.

### Q8. Define a Namespace and explain the purpose of the 'using' directive.
- **Namespace:** A declarative region that groups related identifiers to **prevent naming collisions** in large projects.
- **`using` Directive:** Imports names from a namespace so they can be used directly without prefixing (`using namespace std;`).

### Q9. What are default arguments in C++? Give an example.
- **Default arguments** are values assigned to function parameters in the function prototype that are automatically used if the caller omits those arguments.
- Parameters must be assigned from **right to left**:
```cpp
void show(int a, int b = 10);  // show(5) -> a=5, b=10
```

---

## Unit II — Classes, Objects, Functions & Constructors

### Q1. How do you declare a class and an object in C++?
- **Class Declaration:**
```cpp
class Student {
private:
    int roll;
public:
    void set(int r) { roll = r; }
};
```
- **Object Declaration:** `Student s1, s2;` (allocates memory for class instances).

### Q2. Differentiate between private, protected, and public access specifiers.
- **`private`:** Accessible **only within the same class** and friend functions (default in C++ classes).
- **`protected`:** Accessible within the **same class, friends, and derived classes**.
- **`public`:** Accessible from **anywhere** in the program via class objects.

### Q3. How can a member function be defined inside vs outside a class?
- **Inside the class:** Defined directly in the class body; automatically treated as **inline** by default.
- **Outside the class:** Declared inside the class prototype and defined outside using the scope resolution operator:
```cpp
ReturnType ClassName::funcName(parameters) { ... }
```

### Q4. What is an inline function? List any two rules/limitations for inlining.
- An **inline function** is expanded inline at each function call point by the compiler to eliminate function-call overhead.
- **Rules / Limitations:** Inlining is ignored if the function contains **loops**, **switch statements**, **recursion**, or **static variables**.

### Q5. What are static member variables and static member functions?
- **Static Data Member:** A single variable **shared by all objects** of a class; initialized outside the class in global scope.
- **Static Member Function:** Can access **only static members**; called using the class name without an object: `ClassName::func();`.

### Q6. What is a friend function? State its key characteristics.
A **friend function** is a non-member function granted access to the **private and protected members** of a class.
1. Declared inside the class using the `friend` keyword, but defined outside without class scope.
2. Not called using an object and has **no `this` pointer**; accepts objects as explicit arguments.

### Q7. What is member function overloading in C++?
- **Member function overloading** means having multiple member functions with the **same name but different parameter lists** (number, types, or order of arguments) within the same class scope.
- It is resolved at compile time (**static polymorphism**).

### Q8. Explain the concept of 'Array of Objects' with an example.
- An **array of objects** stores multiple instances of a class contiguously in memory, where each element represents an individual object.
```cpp
Student s[3];       // array of 3 Student objects
s[0].set(101);      // accessing member of first object
```

### Q9. Explain how objects are passed as parameters and returned from functions.
- **Pass-by-Value:** A copy of the object is passed (invokes copy constructor); changes inside do not affect the caller.
- **Pass-by-Reference:** A reference (`&`) is passed; faster, avoids copies, and modifies the original object.
- **Returning Objects:** Functions can return an object by value (`Student get();`) or by reference.

### Q10. What is a Nested Class in C++?
- A **nested class** is a class declared inside the scope of another enclosing class.
- It is scoped within the enclosing class (`Outer::Inner`), but has no special access to the enclosing class's non-static private members unless declared as a `friend`.

### Q11. Define Constructor and Destructor. State their key characteristics.
- **Constructor:** A special member function with the **same name as the class** that automatically initializes objects at creation. Has no return type.
- **Destructor:** A special member function preceded by a tilde (`~ClassName()`) that cleans up resources when an object is destroyed. Cannot be overloaded and takes no parameters.

### Q12. What is a Parameterized Constructor and Constructor Overloading?
- **Parameterized Constructor:** A constructor that accepts arguments to initialize data members with specific user values.
- **Constructor Overloading:** Having multiple constructors in the same class with different parameter lists, allowing objects to be initialized in different ways.

### Q13. What is a Copy Constructor? Give its syntax.
- A **copy constructor** initializes a new object by copying data from an existing object of the same class.
- **Syntax:**
```cpp
ClassName(const ClassName &obj);
```
- Invoked when passing objects by value, returning objects by value, or initializing via `A obj2 = obj1;`.

### Q14. What is an Anonymous Object (Unnamed Temporary Object)?
- An **anonymous object** is a temporary object created on-the-fly during an expression evaluation without assigning it a variable name (e.g., `Point(10, 20).show();`).
- It is automatically destroyed at the end of the full statement.

---

## Unit III — Operator Overloading, Inheritance & Polymorphism

### Q1. What is Operator Overloading? What is the role of the 'operator' keyword?
- **Operator Overloading:** Redefining existing C++ operators to work directly with user-defined types (classes).
- The **`operator` keyword** is used to declare an operator function (e.g., `ReturnType operator+(const ClassName &obj);`).

### Q2. List any four rules for Operator Overloading in C++.
1. **Only existing operators** can be overloaded; new symbols cannot be created.
2. The **arity (number of operands)** and **precedence** cannot be changed.
3. At least one operand must be a **user-defined type**.
4. Operators `::`, `.`, `.*`, `?:`, and `sizeof` **cannot be overloaded**.

### Q3. How does unary operator overloading differ using a member function vs a friend function?
- **Member Function:** Takes **0 explicit arguments** because it operates on the implicit invoking object (`this`).
- **Friend Function:** Takes **1 explicit argument** (the object being operated on): `friend void operator++(Number &n);`.

### Q4. How does binary operator overloading differ using a member function vs a friend function?
- **Member Function:** Takes **1 explicit argument** (the right operand); the left operand is the calling object.
- **Friend Function:** Takes **2 explicit arguments**; necessary when the left-hand operand is not a class object (e.g., `5 + obj`).

### Q5. Explain the concept of Code Reusability in Inheritance.
- **Inheritance** allows a derived class to inherit data members and member functions from an existing base class.
- Existing tested code is **reused without rewriting**, saving development time, eliminating redundancy, and simplifying maintenance.

### Q6. List the five types of Inheritance supported in C++.
```
1. Single:       2. Multilevel:    3. Multiple:     4. Hierarchical:    5. Hybrid:
     A                A               A    B              A                 A
     |                |                \  /              / \              / \
     B                B                  C               B   C             B   C
                      |                                                     \ /
                      C                                                      D
```
- **Single:** 1 Base -> 1 Derived
- **Multilevel:** Chain of derivation (A -> B -> C)
- **Multiple:** Multiple Bases -> 1 Derived
- **Hierarchical:** 1 Base -> Multiple Derived
- **Hybrid:** Combination of two or more types

### Q7. What is a Virtual Base Class and what problem does it solve?
- Solves the **Diamond Problem** (multipath inheritance) where a derived class inherits duplicate copies of a common ancestor.
- Declaring the base class as `virtual` (`class B : virtual public A`) ensures **only one shared copy** of the base class exists in the derived class.

```
       A (Virtual Base)
      / \
     B   C
      \ /
       D  (Only 1 shared copy of A)
```

### Q8. What is meant by 'Object as a Class Member' (Containership / Composition)?
- **Containership (Composition):** Creating an object of one class as a data member inside another class (a "has-a" relationship).
- Example: An `Employee` class containing a `Date` object for `dateOfBirth`.

### Q9. Define an Abstract Class and Pure Virtual Function.
- **Pure Virtual Function:** A virtual function with no implementation in the base class, equated to zero: `virtual void display() = 0;`.
- **Abstract Class:** Any class containing at least one pure virtual function. Objects of an abstract class **cannot be instantiated**.

### Q10. Explain the role of the 'this' pointer.
- **`this`** is an implicit constant pointer passed to every non-static member function holding the **memory address of the calling object**.
- Used to **resolve naming conflicts** (`this->x = x;`) and **return the current object** (`return *this;`).

### Q11. Explain pointer to base class pointing to derived class object.
- A base class pointer can hold the address of any derived class object (**upcasting**).
- Without `virtual` functions, the pointer can access **only members defined in the base class**.

### Q12. Differentiate between Early (Static) Binding and Late (Dynamic) Binding.
- **Early (Static) Binding:** Function call is linked to code at **compile time** (e.g., normal functions, function overloading).
- **Late (Dynamic) Binding:** Function call is resolved at **run time** using virtual functions and `vtable` pointers.

### Q13. What are Virtual Functions? State two rules for virtual functions.
- A **virtual function** is a member function in a base class declared with `virtual` that is overridden in a derived class to achieve **run-time polymorphism**.
- **Rules:**
  1. Must be members of a class and accessed via **pointers or references**.
  2. Cannot be **static** or **constructors** (though destructors can be virtual).

### Q14. What is a Virtual Destructor and why is it essential?
- A destructor declared with the `virtual` keyword in a base class (`virtual ~Base() { }`).
- **Why essential:** When deleting a derived object through a base pointer (`delete basePtr;`), a virtual destructor ensures that the **derived destructor executes first**, preventing memory leaks.

---

## Unit IV — Generic Programming, Templates & Exceptions

### Q1. What is Generic Programming and why are Templates needed?
- **Generic Programming:** An approach where functions and classes are written **independently of any specific data type**.
- **Templates** allow writing a single generic algorithm that works for `int`, `float`, `char`, etc., eliminating code duplication and ensuring compile-time type safety.

### Q2. Define a Function Template with syntax.
A **function template** is a blueprint for generating type-independent functions:
```cpp
template <class T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}
```

### Q3. Define a Class Template with syntax.
A **class template** is a blueprint for creating classes that operate on generic data types:
```cpp
template <class T>
class Container {
    T data;
public:
    Container(T d) : data(d) {}
};
```

### Q4. How is a Class Template instantiated for a specific data type?
A class template is instantiated by specifying the desired data type inside angle brackets `<>` when declaring an object:
```cpp
Container<int> intObj(10);        // instantiates Container for int
Container<float> floatObj(5.5);   // instantiates Container for float
```

### Q5. Explain Overloading of Template Functions.
- A template function can be overloaded by another template function with different parameters, or by a **normal (non-template) function** with the same name.
- When an exact match exists, the compiler gives preference to the **normal function** over the template.

### Q6. Differentiate between Templates and Macros in C++.
| Feature | Templates | Macros (`#define`) |
|---|---|---|
| **Type Safety** | Strictly type-checked by compiler | No type checking (blind text substitution) |
| **Debugging** | Easy to trace with clear compiler errors | Difficult to debug |
| **Scope** | Obey class and namespace scoping rules | Global preprocessor directives |

### Q7. Explain the concept of Linked List implementation with Templates.
- Using templates, a single linked list structure handles nodes of any data type (`int`, `string`, `float`):
```cpp
template <class T>
struct Node {
    T data;
    Node* next;
};
```
- Memory is dynamically allocated and type safety is maintained without rewriting insertion and traversal logic.

---

## Unit V — File Streams & Standard Template Library

### Q1. What is Exception Handling? State its fundamental principle.
- **Exception Handling:** A mechanism to detect, transfer, and handle **runtime errors** without crashing the program.
- **Principle:** Separates error-detection code from error-handling code using three keywords: `try`, `throw`, and `catch`.

### Q2. Explain the roles of 'try', 'catch', and 'throw' keywords.
- **`try`:** Encloses code that may throw an exception.
- **`throw`:** Signals (raises) the exception when an error occurs (`throw "Divide by zero";`).
- **`catch`:** Catches and processes the thrown exception.

### Q3. What are Multiple Catch Statements and the 'catch-all' handler?
- **Multiple Catch Statements:** Multiple `catch` blocks associated with a single `try` block to handle different exception types (`catch(int e)`, `catch(char e)`).
- **Catch-All Handler (`catch(...)`):** A universal catch block that catches **any** exception type; must always be placed as the last handler.

### Q4. Explain Stream I/O in C++.
- A **stream** is a sequence of bytes moving between the program and I/O devices.
- **Input Stream (`cin`):** Reads data from input devices using the extraction operator (`>>`).
- **Output Stream (`cout`):** Writes data to output devices using the insertion operator (`<<`).

### Q5. What are ifstream, ofstream, and fstream classes?
- **`ifstream`:** Input file stream used exclusively for **reading** from files.
- **`ofstream`:** Output file stream used exclusively for **writing** to files.
- **`fstream`:** Input/Output file stream supporting **both reading and writing**.

### Q6. How do you open and close a file in C++?
- **Opening a file:**
```cpp
ofstream outFile("data.txt", ios::out);  // via constructor
// or: outFile.open("data.txt");
```
- **Closing a file:** Releases file buffers and closes the file stream:
```cpp
outFile.close();
```

### Q7. What is the Standard Template Library (STL) and its Programming Model?
The **STL** is a software library containing generic, reusable data structures and algorithms.
- **Programming Model (Triad):**
  1. **Containers:** Store objects and data collections (e.g., `vector`, `list`).
  2. **Iterators:** Act as smart pointers to navigate through container elements.
  3. **Algorithms:** Functions that process container data via iterators (e.g., `sort`, `find`).

### Q8. Differentiate between Sequence Containers and Associative Containers with examples.
- **Sequence Containers:** Store elements in linear sequential order; elements are accessed by their **position** (e.g., `vector`, `list`, `deque`).
- **Associative Containers:** Store elements in sorted order (usually balanced binary trees) designed for fast search; elements are accessed by **key** (e.g., `set`, `map`, `multiset`).

### Q9. What are Iterators in STL? List any two types.
- An **iterator** is an object that points to an element in a container and allows sequential traversal of elements like a pointer.
- **Types:**
  1. **Random-Access Iterator** (supports `[]`, pointer arithmetic; e.g., in `vector`)
  2. **Bidirectional Iterator** (supports `++` and `--`; e.g., in `list`)
  3. *Other types:* Input, Output, Forward iterators.

### Q10. Differentiate between std::vector and std::list in STL.
| Feature | `std::vector` | `std::list` |
|---|---|---|
| **Underlying Structure** | Dynamic contiguous array | Doubly linked list |
| **Random Access** | Fast O(1) via index `[]` | Not supported (sequential traversal O(n)) |
| **Insertion / Deletion** | Slow in middle O(n) due to shifting | Fast anywhere O(1) once iterator is found |

### Q11. What is std::map in STL and how does it store data?
- **`std::map`** is an associative container that stores elements as **key-value pairs** (`pair<const Key, Value>`).
- Keys are unique and stored in **automatically sorted order** (typically implemented as a Red-Black Tree), offering logarithmic O(log n) search, insertion, and deletion time.\n