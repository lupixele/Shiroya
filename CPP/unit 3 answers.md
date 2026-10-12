# Object Oriented Programming through C++ — Unit 3 Answers (`unit 3 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf) *(Typed Unit 3 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 3 Answers)*
>
> **Questions File:** [`question.md` — UNIT 3](question.md#unit-3)

---

## Q1. Distinguish between overloading using a member function and a friend function.

### Concept of Operator Overloading
Operator overloading is a feature of C++ that allows existing operators (such as `+`, `-`, `==`, `<<`) to be given special user-defined meanings when applied to objects of user-defined classes. It enables intuitive, readable expressions like `c1 + c2` instead of cumbersome function calls like `c1.add(c2)`.

An overloaded operator can be implemented using either a **Member Function** or a **Friend Function**.

---

### Detailed Comparison

| S.No. | Parameter | Member Function | Friend Function |
| :---: | :--- | :--- | :--- |
| **1** | **Definition & Scope** | Defined within the class scope as a regular member function. | Declared inside the class using the `friend` keyword, but defined outside the class scope. |
| **2** | **Invocation Mechanism** | Invoked by the left-hand operand object using the implicit `this` pointer: `obj1.operator+(obj2)`. | Invoked like a normal global function with all operands passed explicitly as arguments: `operator+(obj1, obj2)`. |
| **3** | **`this` Pointer** | An implicit `this` pointer is always passed, representing the invoking object. | No `this` pointer is available because the friend function is not a member of the class. |
| **4** | **Number of Arguments** | • **Unary Operator:** Takes **0** explicit arguments (`*this` is the operand).<br>• **Binary Operator:** Takes **1** explicit argument (the right operand). | • **Unary Operator:** Takes **1** explicit argument.<br>• **Binary Operator:** Takes **2** explicit arguments. |
| **5** | **Private Data Access** | Has direct, native access to all `private` and `protected` members of the class. | Can access `private` and `protected` members only because it is explicitly declared a friend. |
| **6** | **Operand Symmetry** | **Asymmetric:** The left-hand operand *must* be an object of the defining class. Expressions like `5 + obj` will fail. | **Symmetric:** Both operands are treated equally. Expressions like `5 + obj` are easily supported. |
| **7** | **Best Used For** | Operators where the left operand is naturally modified, such as assignment (`=`), subscript (`[]`), and compound assignments (`+=`). | Commutative arithmetic operators (`+`, `-`, `*`), comparison operators, and I/O stream operators (`<<`, `>>`). |

---

### Code Demonstration
The following program demonstrates both approaches in a single class: binary `+` overloaded via a **member function** and binary `-` overloaded via a **friend function**.

```cpp
#include <iostream>
using namespace std;

class Demo {
    int val;
public:
    Demo(int v = 0) { val = v; }

    // 1. Member Function: takes 1 explicit parameter
    Demo operator+(Demo d) {
        return Demo(val + d.val);
    }

    // 2. Friend Function: declared inside class, takes 2 explicit parameters
    friend Demo operator-(Demo a, Demo b);

    void display() {
        cout << val << endl;
    }
};

// Friend function defined outside class (no Demo:: scope resolution)
Demo operator-(Demo a, Demo b) {
    return Demo(a.val - b.val);
}

int main() {
    Demo d1(30), d2(10);

    Demo d3 = d1 + d2; // Invokes member function: d1.operator+(d2)
    Demo d4 = d1 - d2; // Invokes friend function: operator-(d1, d2)

    cout << "Sum (Member function)        : ";
    d3.display();

    cout << "Difference (Friend function) : ";
    d4.display();

    return 0;
}
```

### Output
```text
Sum (Member function)        : 40
Difference (Friend function) : 20
```

### Summary
Member functions are concise and natural when the operation modifies the left-hand object, whereas friend functions offer flexibility and symmetry, especially when dealing with mixed-type operations and commutative expressions.

---

## Q2. Explain binary operator overloading with a suitable example.

### Definition & Working Principle
A **binary operator** operates on two operands (for example, `+`, `-`, `*`, `/`, `<`, `==`). In C++, **binary operator overloading** allows programmers to redefine the behavior of these operators when used with class objects.

When overloading a binary operator as a **member function**:
1. The **left-hand operand** becomes the calling object (`*this`).
2. The **right-hand operand** is passed as the single formal parameter to the operator function.
3. The function returns a new object containing the result of the operation.

### Syntax
```cpp
class ClassName {
public:
    ReturnType operator op(const ClassName &rightOperand) {
        // operation logic
        return result;
    }
};
```

### Rules for Operator Overloading
1. Only existing C++ operators can be overloaded; new operators cannot be created.
2. The **precedence**, **associativity**, and **number of operands (arity)** of the operator cannot be altered.
3. Operators that **cannot be overloaded** in C++:
   - Scope resolution operator (`::`)
   - Member access / dot operator (`.`)
   - Pointer-to-member operator (`.*`)
   - Ternary / conditional operator (`?:`)
   - `sizeof` and `typeid` operators

---

### Exam-Ready Program (Adding Complex Numbers)
```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Binary '+' operator overloading as a member function
    Complex operator+(Complex c) {
        Complex temp;
        temp.real = real + c.real; // 'real' belongs to *this; 'c.real' belongs to parameter
        temp.imag = imag + c.imag;
        return temp;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(2, 5);
    Complex c3 = c1 + c2; // Evaluates to c1.operator+(c2)

    cout << "First Complex Number  : "; c1.display();
    cout << "Second Complex Number : "; c2.display();
    cout << "Sum Result            : "; c3.display();

    return 0;
}
```

### Output
```text
First Complex Number  : 3 + 4i
Second Complex Number : 2 + 5i
Sum Result            : 5 + 9i
```

### Explanation of Code
- `c1 + c2` triggers `c1.operator+(c2)`.
- Inside `operator+`, `real` refers to `c1.real` (via `this`), and `c.real` refers to `c2.real`.
- The real parts and imaginary parts are added separately and returned as a new `Complex` object `c3`.

---

## Q3. Explain operator overloading using friend functions with syntax and an example.

### Why Use a Friend Function for Operator Overloading?
While member functions handle most operator overloading needs, a **friend function** is required in two major scenarios:
1. **Commutative / Mixed-Mode Arithmetic:** When adding a primitive value to an object, such as `5 + obj`. A member function cannot handle this because `5` is a primitive integer and cannot invoke a member function (`5.operator+(obj)` is invalid). A friend function receives both operands as parameters and handles `operator+(int, Object)` easily.
2. **I/O Stream Operator Overloading:** The `<<` and `>>` operators have `std::ostream` or `std::istream` as their left-hand operand, which cannot be modified to add member functions. Hence, friend functions are mandatory.

### Syntax
```cpp
class ClassName {
    // Data members
public:
    // Declaration inside the class with 'friend' keyword:
    friend ReturnType operator op(Type1 operand1, Type2 operand2);
};

// Definition outside the class (no ClassName:: scope resolution needed):
ReturnType operator op(Type1 operand1, Type2 operand2) {
    // implementation code
}
```

---

### Exam-Ready Program (Friend Operator Overloading)
```cpp
#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    Distance(int m = 0) { meters = m; }

    // Friend function declaration: takes both operands explicitly
    friend Distance operator+(Distance d1, Distance d2);

    void display() {
        cout << meters << " meters" << endl;
    }
};

// Friend function definition outside the class
Distance operator+(Distance d1, Distance d2) {
    // Accesses private data 'meters' directly
    return Distance(d1.meters + d2.meters);
}

int main() {
    Distance dist1(15), dist2(25);
    Distance total = dist1 + dist2; // Evaluates to operator+(dist1, dist2)

    cout << "Distance 1: "; dist1.display();
    cout << "Distance 2: "; dist2.display();
    cout << "Total     : "; total.display();

    return 0;
}
```

### Output
```text
Distance 1: 15 meters
Distance 2: 25 meters
Total     : 40 meters
```

### Key Points for Full Marks
- The friend function is declared inside the class with the `friend` prefix.
- It is defined outside without the class name and without `::`.
- It receives two explicit arguments for binary operators and one explicit argument for unary operators.

---

## Q4. Explain different types of inheritance supported by C++ with examples.

### Definition of Inheritance
**Inheritance** is an Object-Oriented Programming concept by which a new class (**derived class** or child class) inherits the properties and methods of an existing class (**base class** or parent class).

### Key Advantages
1. **Code Reusability:** Existing, tested logic is reused without rewriting.
2. **Extensibility:** New features can be added without modifying existing classes.
3. **Establishes "is-a" Relationships:** Models real-world hierarchical relationships (e.g., `Dog` is an `Animal`).

---

### The 5 Types of Inheritance in C++

```text
1. Single          2. Multiple          3. Multilevel       4. Hierarchical        5. Hybrid
   [ A ]             [ A ]   [ B ]          [ A ]                [ A ]               [ A ]
     │                 └───┬───┘              │                ┌───┴───┐           ┌───┴───┐
     ▼                     ▼                  ▼                ▼       ▼           ▼       ▼
   [ B ]                 [ C ]              [ B ]            [ B ]   [ C ]       [ B ]   [ C ]
                                              │                                    └───┬───┘
                                              ▼                                        ▼
                                            [ C ]                                    [ D ]
```

#### 1. Single Inheritance
One derived class inherits directly from a single base class.
```cpp
class Animal {
public:
    void eat() { cout << "Eating..." << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking..." << endl; }
};
```

#### 2. Multiple Inheritance
One derived class inherits from more than one base class simultaneously.
```cpp
class Printer {
public:
    void print() { cout << "Printing document" << endl; }
};

class Scanner {
public:
    void scan() { cout << "Scanning document" << endl; }
};

class AllInOne : public Printer, public Scanner {
    // Inherits both print() and scan()
};
```

#### 3. Multilevel Inheritance
A class is derived from another derived class, forming an inheritance chain.
```cpp
class Person {
public:
    void info() { cout << "Person info" << endl; }
};

class Student : public Person {
public:
    void study() { cout << "Studying" << endl; }
};

class GraduateStudent : public Student {
public:
    void research() { cout << "Conducting research" << endl; }
};
```

#### 4. Hierarchical Inheritance
Multiple derived classes inherit from a single common base class.
```cpp
class Shape {
public:
    void color() { cout << "Applying color" << endl; }
};

class Circle : public Shape {
    // Inherits Shape
};

class Rectangle : public Shape {
    // Inherits Shape
};
```

#### 5. Hybrid Inheritance
A combination of two or more types of inheritance (typically combining hierarchical and multiple inheritance).
```cpp
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { }; // Diamond pattern
```
> **Note on Diamond Problem:** In hybrid inheritance, when two derived classes share a base class and are inherited together into a fourth class, ambiguity arises. In C++, this is solved using **`virtual` base classes** (`class B : virtual public A`).

---

### Comparison Summary

| Type | Base Classes | Derived Classes | Description |
| :--- | :---: | :---: | :--- |
| **Single** | 1 | 1 | Simple 1-to-1 derivation. |
| **Multiple** | 2 or more | 1 | Combines capabilities of several base classes. |
| **Multilevel** | 1 per level | 1 per level | Linear ancestor chain ($A \rightarrow B \rightarrow C$). |
| **Hierarchical** | 1 | 2 or more | Single parent with multiple independent children. |
| **Hybrid** | Multiple | Multiple | Composite structure mixing multiple inheritance types. |

---

## Q5. Explain the use of Virtual Functions with an example program.

### What is a Virtual Function?
A **virtual function** is a member function declared in a base class using the `virtual` keyword and redefined (overridden) in one or more derived classes.

When a virtual function is called through a **base class pointer or reference**, C++ determines which version of the function to execute at **run time** based on the actual object being pointed to, rather than the type of the pointer. This capability is called **Runtime Polymorphism**, **Dynamic Binding**, or **Late Binding**.

### Why are Virtual Functions Used?
1. **Achieves Runtime Polymorphism:** Enables the system to decide the appropriate function call dynamically during program execution.
2. **Extensible Architecture:** Base class pointers can process collections of different derived objects uniformly (e.g., an array of `Shape*` holding `Circle`, `Square`, `Triangle`).
3. **Prevents Early Binding:** Without `virtual`, the compiler performs static (compile-time) binding, always executing the base class version regardless of the actual object.

### Internal Mechanism (vtable & vptr)
- For every class containing virtual functions, the compiler creates a **Virtual Table (`vtable`)** containing function pointers to the virtual methods.
- Every object of such a class contains an invisible pointer called **`vptr`** that points to its class's `vtable`.
- At runtime, function calls through pointers are resolved by looking up the correct entry in the `vtable`.

---

### Exam-Ready Program
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    // Virtual function enables late binding
    virtual void display() {
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    // Overriding the virtual function
    void display() override {
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base *ptr;     // Base class pointer
    Derived obj;   // Derived class object

    ptr = &obj;    // Base pointer points to Derived object

    // Because display() is virtual, Derived's version is executed at runtime:
    ptr->display();

    return 0;
}
```

### Output
```text
Display from Derived class
```

### Key Differences: Virtual vs Non-Virtual Binding

| Feature | Non-Virtual Function | Virtual Function |
| :--- | :--- | :--- |
| **Binding Type** | Early / Static (Compile-time) binding. | Late / Dynamic (Run-time) binding. |
| **Decision Factor** | Type of the pointer variable. | Type of the actual object pointed to. |
| **Keyword** | No special keyword. | Declared with `virtual` in base class. |
| **Performance** | Slightly faster (direct jump). | Slight overhead due to `vptr` and `vtable` lookup. |

---

## Q6. What is an abstract class? Demonstrate with an example.

### Definition of an Abstract Class
An **abstract class** in C++ is a class designed specifically to serve as a base class and **cannot be used to instantiate objects directly**.

A class is automatically recognized as abstract if it contains at least one **pure virtual function**.

### Pure Virtual Function
A **pure virtual function** is a function declared in a base class that has no implementation (body) in that base class. It is declared by appending `= 0` to its prototype:
```cpp
virtual ReturnType functionName(parameters) = 0;
```

### Important Characteristics of Abstract Classes
1. **No Instantiation:** Attempting to create an object of an abstract class (`Shape s;`) produces a compilation error.
2. **Pointers & References Allowed:** While objects cannot be instantiated, **pointers and references of an abstract class type are fully allowed** (`Shape *ptr;`), allowing polymorphic manipulation of derived objects.
3. **Obligation to Override:** Any concrete derived class *must* provide an implementation for all pure virtual functions. If it fails to do so, it also becomes an abstract class.
4. **Concrete Members Permitted:** An abstract class can still contain regular variables, constructors, destructors, and non-virtual or normal virtual functions.

---

### Exam-Ready Program (Abstract Base Class `Shape`)
```cpp
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    // Pure virtual function makes Shape an abstract class
    virtual void draw() = 0;

    // Normal concrete function inside abstract class
    void info() {
        cout << "This is a 2D Shape." << endl;
    }
};

// Concrete Derived Class 1
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Circle" << endl;
    }
};

// Concrete Derived Class 2
class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a Rectangle" << endl;
    }
};

int main() {
    // Shape s; // ERROR: Cannot instantiate abstract class Shape

    Shape *shapePtr; // OK: Base class pointer

    Circle c;
    Rectangle r;

    shapePtr = &c;
    shapePtr->info();
    shapePtr->draw();

    shapePtr = &r;
    shapePtr->draw();

    return 0;
}
```

### Output
```text
This is a 2D Shape.
Drawing a Circle
Drawing a Rectangle
```

### Summary
An abstract class enforces a common interface across an entire hierarchy of derived classes while preventing incomplete base abstractions from being instantiated directly.
