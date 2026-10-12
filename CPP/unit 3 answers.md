# Object Oriented Programming through C++ — Unit 3 Answers (`unit 3 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf) *(Typed Unit 3 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 3 Answers)*
>
> **Questions File:** [`question.md` — UNIT 3](question.md#unit-3)

---

## Q1. Distinguish between overloading using a member function and a friend function.

### Explanation
Operator overloading allows C++ operators (such as `+`, `-`, `==`) to work directly with user-defined class objects. It can be implemented using either a **member function** or a **friend function**.

### Comparison

| Feature | Member Function | Friend Function |
| :--- | :--- | :--- |
| **Declaration & Scope** | Defined inside the class scope. | Declared with keyword `friend` inside the class, defined outside. |
| **Calling Mechanism** | Invoked using the left-hand object (`obj1.operator+(obj2)`). | Invoked like a normal function with objects passed as arguments. |
| **`this` Pointer** | Has an implicit `this` pointer representing the left operand. | Does not have a `this` pointer. |
| **Number of Parameters** | Unary: **0** explicit arguments<br>Binary: **1** explicit argument | Unary: **1** argument<br>Binary: **2** arguments |
| **Access to Data** | Directly accesses private and protected members. | Can access private and protected members only because it is declared a friend. |
| **Symmetry** | Left operand must be an object of the class. | Allows mixed-mode arithmetic (e.g., `5 + obj`). |

### Example Program
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a = 0) { x = a; }

    // Overloading '+' using a Member Function (1 argument)
    Demo operator+(Demo d) {
        return Demo(x + d.x);
    }

    // Overloading '-' using a Friend Function (2 arguments)
    friend Demo operator-(Demo a, Demo b);

    void display() {
        cout << x << endl;
    }
};

// Friend function definition
Demo operator-(Demo a, Demo b) {
    return Demo(a.x - b.x);
}

int main() {
    Demo d1(20), d2(10);

    Demo d3 = d1 + d2; // calls member function: d1.operator+(d2)
    Demo d4 = d1 - d2; // calls friend function: operator-(d1, d2)

    cout << "Sum (Member function)        : ";
    d3.display();

    cout << "Difference (Friend function) : ";
    d4.display();

    return 0;
}
```

### Output
```text
Sum (Member function)        : 30
Difference (Friend function) : 10
```

---

## Q2. Explain binary operator overloading with a suitable example.

### Explanation
**Binary operator overloading** is the process of giving custom meaning to an operator that operates on two operands (such as `+`, `-`, `*`, `/`, `==`) when applied to class objects.

When overloading a binary operator using a member function:
- The left operand calls the operator function.
- The right operand is passed as an argument.

### Syntax
```cpp
class ClassName {
public:
    ReturnType operator op(const ClassName &obj) {
        // operation logic
    }
};
```

### Example Program
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

    // Binary '+' operator overloading
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6);
    Complex c3 = c1 + c2; // Evaluated as c1.operator+(c2)

    cout << "Result: ";
    c3.display();

    return 0;
}
```

### Output
```text
Result: 8 + 10i
```

---

## Q3. Explain operator overloading using friend functions with syntax and an example.

### Explanation
An operator can be overloaded using a **friend function**. A friend function is not a member of the class, but is given special permission to access its `private` and `protected` data members.

Friend functions are especially useful when:
1. Both operands must be treated symmetrically.
2. The left-hand operand is a built-in type or an object of another class (e.g., `5 + obj`).

### Syntax
```cpp
class ClassName {
    // data members
public:
    friend ReturnType operator op(const ClassName &a, const ClassName &b);
};

// Outside class definition
ReturnType operator op(const ClassName &a, const ClassName &b) {
    // implementation
}
```

### Example Program
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a = 0) {
        x = a;
    }

    // Friend function declaration
    friend Demo operator+(Demo d1, Demo d2);

    void display() {
        cout << "Result = " << x << endl;
    }
};

// Friend function definition
Demo operator+(Demo d1, Demo d2) {
    return Demo(d1.x + d2.x);
}

int main() {
    Demo d1(10), d2(20);
    Demo d3 = d1 + d2; // calls operator+(d1, d2)

    d3.display();
    return 0;
}
```

### Output
```text
Result = 30
```

---

## Q4. Explain different types of inheritance supported by C++ with examples.

### Explanation
**Inheritance** is the process where a new class (derived class) inherits data members and member functions from an existing class (base class). It promotes code reusability and creates a hierarchical classification.

C++ supports 5 types of inheritance:

### 1. Single Inheritance
A single derived class inherits from a single base class.
```cpp
class A {
public:
    void showA() { cout << "Base Class A" << endl; }
};

class B : public A {
public:
    void showB() { cout << "Derived Class B" << endl; }
};
```

### 2. Multiple Inheritance
A single derived class inherits from more than one base class.
```cpp
class A { };
class B { };

class C : public A, public B {
    // Inherits members of both A and B
};
```

### 3. Multilevel Inheritance
A class is derived from a class that is already derived from another class (forming an inheritance chain).
```cpp
class A { };
class B : public A { };
class C : public B { }; // C inherits from B, which inherits from A
```

### 4. Hierarchical Inheritance
Multiple derived classes inherit from a single base class.
```cpp
class A { };

class B : public A { };
class C : public A { }; // Both B and C inherit from A
```

### 5. Hybrid Inheritance
A combination of two or more types of inheritance (such as hierarchical and multiple inheritance combined).
```cpp
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { }; // Combines hierarchical and multiple
```

### Summary of Inheritance Types
- **Single:** 1 Base $\rightarrow$ 1 Derived
- **Multiple:** Multiple Bases $\rightarrow$ 1 Derived
- **Multilevel:** Base $\rightarrow$ Intermediate $\rightarrow$ Derived
- **Hierarchical:** 1 Base $\rightarrow$ Multiple Derived
- **Hybrid:** Combination of two or more types

---

## Q5. Explain the use of Virtual Functions with an example program.

### Explanation
A **virtual function** is a member function in a base class that is declared with the keyword `virtual` and redefined (overridden) in a derived class.

When a base class pointer points to a derived class object and calls a virtual function, C++ determines which function to execute at **run time** based on the actual object type, rather than the pointer type. This is known as **Runtime Polymorphism** or **Late Binding**.

### Key Uses
1. Enables runtime polymorphism.
2. Supports function overriding across inheritance hierarchies.
3. Allows a common interface to manipulate different derived class objects dynamically.

### Example Program
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class show()" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class show()" << endl;
    }
};

int main() {
    Base *ptr;     // Base class pointer
    Derived obj;   // Derived class object

    ptr = &obj;    // Pointer points to derived object
    ptr->show();   // Calls Derived's show() at runtime

    return 0;
}
```

### Output
```text
Derived class show()
```

---

## Q6. What is an abstract class? Demonstrate with an example.

### Explanation
An **abstract class** is a class designed specifically to be used as a base class and cannot be instantiated directly (no objects can be created from it).

A class becomes abstract when it contains at least one **pure virtual function**. A pure virtual function has no definition in the base class and is declared by assigning `= 0`.

Derived classes must provide an implementation for all pure virtual functions, otherwise they also become abstract.

### Syntax
```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};
```

### Example Program
```cpp
#include <iostream>
using namespace std;

// Abstract Base Class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

// Concrete Derived Class
class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    // Shape s; // Error: Cannot declare variable of abstract type 'Shape'
    Circle c;
    c.draw();

    Shape *ptr = &c;
    ptr->draw();

    return 0;
}
```

### Output
```text
Drawing Circle
Drawing Circle
```
