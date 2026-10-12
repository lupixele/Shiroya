# Object Oriented Programming through C++ — Unit 3 Answers (`unit 3 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf) *(Typed Unit 3 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 3 Answers)*
>
> **Questions File:** [`question.md` — UNIT 3](question.md#unit-3)

---

## Q1. Distinguish between overloading using a member function and a friend function.

### Operator Overloading
Operator overloading allows C++ operators (such as `+`, `-`, `==`) to work directly with user-defined objects. It can be implemented using either a **Member Function** or a **Friend Function**.

### Differences

| Feature | Member Function | Friend Function |
| :--- | :--- | :--- |
| **Declaration** | Defined inside the class as a member. | Declared inside the class with the `friend` keyword, defined outside. |
| **Calling Object** | Called using the left-hand object (`obj1.operator+(obj2)`). | Called like a normal function with objects passed as arguments (`operator+(obj1, obj2)`). |
| **`this` Pointer** | Has an implicit `this` pointer pointing to the left operand. | Does not have a `this` pointer. |
| **Parameters** | • Unary: **0** explicit arguments<br>• Binary: **1** explicit argument | • Unary: **1** explicit argument<br>• Binary: **2** explicit arguments |
| **Access** | Directly accesses private and protected members. | Can access private and protected members because it is declared a friend. |
| **Operands** | Left operand must be an object of that class. | Allows different types on both sides (e.g., `5 + obj`). |

### Code Example
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a = 0) { x = a; }

    // Member function: takes 1 argument
    Demo operator+(Demo d) {
        return Demo(x + d.x);
    }

    // Friend function: takes 2 arguments
    friend Demo operator-(Demo a, Demo b);

    void display() { cout << x << endl; }
};

Demo operator-(Demo a, Demo b) {
    return Demo(a.x - b.x);
}

int main() {
    Demo d1(30), d2(10);
    Demo d3 = d1 + d2; // Member function
    Demo d4 = d1 - d2; // Friend function

    cout << "Sum: ";        d3.display();
    cout << "Difference: "; d4.display();
    return 0;
}
```

### Output
```text
Sum: 40
Difference: 20
```

---

## Q2. Explain binary operator overloading with a suitable example.

### Binary Operator Overloading
A binary operator works on two operands (such as `+`, `-`, `*`, `/`). In C++, binary operator overloading allows you to define how these operators work with class objects.

When overloaded using a member function:
- The left operand calls the function.
- The right operand is passed as an argument.

### Syntax
```cpp
ReturnType operator op(ClassName obj);
```

### Code Example
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

    // Overloading binary '+' operator
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(2, 5);
    Complex c3 = c1 + c2; // c1 calls operator+(c2)

    cout << "Result: ";
    c3.display();
    return 0;
}
```

### Output
```text
Result: 5 + 9i
```

---

## Q3. Explain operator overloading using friend functions with syntax and an example.

### Friend Function in Operator Overloading
A friend function can access private and protected members of a class even though it is not a member of that class.

It is useful for operator overloading when:
1. Both operands need to be treated symmetrically.
2. The left operand is not an object of the class (for example, `10 + obj`).

### Syntax
```cpp
// Inside class:
friend ReturnType operator op(Type1 a, Type2 b);

// Outside class:
ReturnType operator op(Type1 a, Type2 b) {
    // function body
}
```

### Code Example
```cpp
#include <iostream>
using namespace std;

class Distance {
    int meters;
public:
    Distance(int m = 0) { meters = m; }

    // Friend function declaration
    friend Distance operator+(Distance d1, Distance d2);

    void display() { cout << meters << " m" << endl; }
};

// Friend function definition
Distance operator+(Distance d1, Distance d2) {
    return Distance(d1.meters + d2.meters);
}

int main() {
    Distance d1(15), d2(25);
    Distance d3 = d1 + d2; // calls operator+(d1, d2)

    cout << "Total Distance: ";
    d3.display();
    return 0;
}
```

### Output
```text
Total Distance: 40 m
```

---

## Q4. Explain different types of inheritance supported by C++ with examples.

### Inheritance
Inheritance is a feature of OOP where a derived class acquires the properties and methods of an existing base class. It promotes code reusability.

C++ supports 5 types of inheritance:

### 1. Single Inheritance
One derived class inherits from one base class.
```cpp
class A {
public:
    void showA() { cout << "Base class A\n"; }
};

class B : public A {
public:
    void showB() { cout << "Derived class B\n"; }
};
```

### 2. Multiple Inheritance
One derived class inherits from more than one base class.
```cpp
class A { };
class B { };

class C : public A, public B {
    // Inherits from both A and B
};
```

### 3. Multilevel Inheritance
A class is derived from another derived class, forming a chain.
```cpp
class A { };
class B : public A { }; // B inherits from A
class C : public B { }; // C inherits from B
```

### 4. Hierarchical Inheritance
Multiple derived classes inherit from a single base class.
```cpp
class A { };
class B : public A { }; // B inherits from A
class C : public A { }; // C inherits from A
```

### 5. Hybrid Inheritance
A combination of two or more types of inheritance.
```cpp
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { }; // Combines hierarchical and multiple
```

---

## Q5. Explain the use of Virtual Functions with an example program.

### Virtual Function
A **virtual function** is a member function in a base class declared with the `virtual` keyword and redefined (overridden) in a derived class.

### Purpose
When you call a function using a **base class pointer** that points to a derived class object:
- Without `virtual`, C++ calls the **base class** version (early/compile-time binding).
- With `virtual`, C++ calls the **derived class** version at runtime (late/runtime binding).

This enables **runtime polymorphism**.

### Code Example
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() { // Virtual function
        cout << "Base class show" << endl;
    }
};

class Derived : public Base {
public:
    void show() override { // Overridden function
        cout << "Derived class show" << endl;
    }
};

int main() {
    Base *ptr;     // Base class pointer
    Derived obj;   // Derived class object

    ptr = &obj;    // Pointer points to derived object
    ptr->show();   // Calls Derived's show() because of virtual keyword

    return 0;
}
```

### Output
```text
Derived class show
```

---

## Q6. What is an abstract class? Demonstrate with an example.

### Abstract Class
An **abstract class** is a class designed to be a base class and **cannot be used to create objects directly**.

A class becomes an abstract class when it contains at least one **pure virtual function**.

### Pure Virtual Function
A pure virtual function is declared by assigning `= 0` in the base class and has no body:
```cpp
virtual void functionName() = 0;
```
Derived classes **must** provide an implementation for all pure virtual functions, or they also become abstract.

### Code Example
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
    // Shape s; // Error: cannot create object of abstract class
    Shape *ptr;  // OK: base pointer is allowed
    Circle c;

    ptr = &c;
    ptr->draw(); // Calls Circle's draw()

    return 0;
}
```

### Output
```text
Drawing Circle
```
