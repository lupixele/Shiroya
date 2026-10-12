# Object Oriented Programming through C++ — Unit 3 Answers (`unit 3 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf) *(Typed Unit 3 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 3 Answers)*
>
> **Questions File:** [`questions.md` — UNIT 3](questions.md#unit-3)

---

## Q1. Distinguish between overloading using a member function and a friend function.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 2–3)

Operator overloading allows an operator such as `+`, `-`, `==`, etc., to work with user-defined objects.

| Member Function | Friend Function |
| :--- | :--- |
| 1. The operator function is defined inside the class. | 1. The operator function is declared as a friend inside the class but defined outside. |
| 2. It is called using the left-hand object. | 2. It can be called with objects passed as arguments. |
| 3. It accesses private/protected members directly. | 3. It can access private/protected members because it is declared as a friend. |
| 4. It generally requires one less parameter for binary operators. | 4. It generally requires two parameters for binary operators. |
| 5. `*this` represents the left operand. | 5. Both operands are explicitly passed as arguments. |

#### Example
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a) { x = a; }

    // Member function
    Demo operator+(Demo d) {
        return Demo(x + d.x);
    }

    // Friend function
    friend Demo operator-(Demo a, Demo b);

    void show() { cout << x; }
};

Demo operator-(Demo a, Demo b) {
    return Demo(a.x - b.x);
}

int main() {
    Demo d1(20), d2(10);
    Demo d3 = d1 + d2; // Member
    Demo d4 = d1 - d2; // Friend
    d3.show();
    cout << endl;
    d4.show();
}
```

#### Output
```text
30
10
```
*(Note: The PDF prints `Output: 30` at the bottom of page 3.)*

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 1)

Operator overloading in C++ can be done using either a member function or a friend function.

#### 1. Definition
- **Member function:** The operator function is defined inside the class.
- **Friend function:** The operator function is declared with `friend` inside the class and defined outside the class.

#### 2. Left-hand operand
- **Member function:** The left operand must be an object of the class.
- **Friend function:** The left operand need not be a class object; both operands are passed as arguments.

#### 3. Arguments
- **For unary operators:**
  - Member function $\rightarrow$ no explicit argument
  - Friend function $\rightarrow$ one argument
- **For binary operators:**
  - Member function $\rightarrow$ one explicit argument
  - Friend function $\rightarrow$ two arguments

#### 4. Access
- **Member function:** Can access class members directly.
- **Friend function:** Can also access private and protected members because it is a friend of the class.

#### 5. Use
- **Member function:** Best when the left operand is the class object.
- **Friend function:** Useful when symmetry is needed or when the left operand is not a class object.

Hence, both methods are used for operator overloading, but friend functions give more flexibility, while member functions are simpler when the operator naturally belongs to the class object.

#### Example

**Member function:**
```cpp
class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i; }
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
};
```

**Friend function:**
```cpp
class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i; }
    friend Complex operator+(const Complex &a, const Complex &b);
};

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}
```

---

## Q2. Explain binary operator overloading with a suitable example.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 4–5)

Binary operator overloading is the process of giving a special meaning to a binary operator such as `+`, `-`, `*`, `/`, etc., when it is used with objects of a class.

A binary operator works on two operands. In C++, it can be overloaded using a member function or friend function.

#### Example
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a) {
        x = a;
    }

    // Binary + operator overloading
    Demo operator+(Demo d) {
        return Demo(x + d.x);
    }

    void display() {
        cout << "Result = " << x;
    }
};

int main() {
    Demo d1(10), d2(20);
    Demo d3 = d1 + d2;
    d3.display();
    return 0;
}
```

#### Output
```text
30
```

---

### Version 2 — Complex Number Example

#### 1. Syntax (using Member Function)
```cpp
class ClassName {
public:
    ClassName operator op(const ClassName &obj) {
        // perform operation and return result object
    }
};
```

#### 2. Example
Program to overload the binary `'+'` operator using a member function to add two complex numbers:
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

    // Overloading binary '+' operator using member function
    Complex operator+(const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(5, 6), c3;
    c3 = c1 + c2; // equivalent to c1.operator+(c2)
    cout << "Sum = ";
    c3.display();
    return 0;
}
```

#### Output
```text
Sum = 8 + 10i
```

#### 3. Conclusion
Thus, binary operator overloading allows intuitive arithmetic and comparison expressions like `c1 + c2` to work seamlessly with user-defined class objects.

---

## Q3. Explain operator overloading using friend functions with syntax and an example.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 5–6)

Operator overloading using a friend function means defining an overloaded operator as a friend function of a class. A friend function is not a member of the class, but it can access the class's private and protected data members.

#### Syntax
```cpp
class ClassName {
    // data members
    friend ReturnType operator op(ClassName, ClassName);
};
```

#### Example
```cpp
#include <iostream>
using namespace std;

class Demo {
    int x;
public:
    Demo(int a) {
        x = a;
    }

    friend Demo operator+(Demo d1, Demo d2);

    void display() {
        cout << "Result = " << x;
    }
};

// Friend function
Demo operator+(Demo d1, Demo d2) {
    return Demo(d1.x + d2.x);
}

int main() {
    Demo d1(10), d2(20);
    Demo d3 = d1 + d2;
    d3.display();
    return 0;
}
```

#### Output
```text
Result = 30
```

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 2)

Operator overloading in C++ allows us to give special meaning to an existing operator for user-defined data types. A friend function can also be used to overload operators. A friend function is declared inside the class using the keyword `friend`, but it is defined outside the class. It is not a member of the class, yet it can access private and protected members of the class.

#### 1. Syntax
```cpp
class ClassName {
private:
    // data members
public:
    friend return_type operator_symbol(arguments);
};

return_type operator_symbol(arguments) {
    // function body
}
```

#### 2. Example
Program to overload `'+'` operator using a friend function to add two complex numbers.
```cpp
#include <iostream>
using namespace std;

class Complex {
    int real, imag;
public:
    Complex(int r = 0, int i = 0) { real = r; imag = i; }
    friend Complex operator+(const Complex &a, const Complex &b);
    void display() {
        cout << real << " + " << imag << "i";
    }
};

Complex operator+(const Complex &a, const Complex &b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex c1(2, 3), c2(4, 5), c3;
    c3 = c1 + c2;
    cout << "Sum = ";
    c3.display();
    return 0;
}
```

#### Output
```text
Sum = 6 + 8i
```

#### 3. Conclusion
Thus, friend functions are useful in operator overloading when both operands need to be treated equally and when the function needs access to private data of the class.

---

## Q4. Explain different types of inheritance supported by C++ with examples.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 6–8)

Inheritance is an OOP concept in which a new class (derived class) acquires the properties and functions of an existing class (base class). It promotes code reusability.

C++ supports the following types of inheritance:

#### 1. Single Inheritance
One derived class inherits from one base class.
```cpp
class A {
public:
    void show() {
        cout << "Base class";
    }
};

class B : public A {
};
```

#### 2. Multiple Inheritance
One derived class inherits from more than one base class.
```cpp
class A { };
class B { };
class C : public A, public B {
};
```

#### 3. Multilevel Inheritance
A class is derived from another derived class, forming a chain.
```cpp
class A { };
class B : public A { };
class C : public B { };
```

#### 4. Hierarchical Inheritance
Multiple derived classes inherit from one base class.
```cpp
class A { };
class B : public A { };
class C : public A { };
```

#### 5. Hybrid Inheritance
It is a combination of two or more types of inheritance, such as multiple and multilevel inheritance.
```cpp
class A { };
class B : public A { };
class C : public A { };
class D : public B, public C { };
```

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 3)

Inheritance is the process by which one class acquires the properties and behavior of another class. The existing class is called the base class and the new class is called the derived class. C++ supports the following types of inheritance.

1. **Single Inheritance:** In single inheritance, one derived class inherits from one base class.
2. **Multiple Inheritance:** In multiple inheritance, one derived class inherits from more than one base class.
3. **Multilevel Inheritance:** In multilevel inheritance, a derived class becomes the base class for another class.
4. **Hierarchical Inheritance:** In hierarchical inheritance, more than one derived class inherit from the same base class.
5. **Hybrid Inheritance:** In hybrid inheritance, it is a combination of two or more types of inheritance.

#### Summary
- **Single** $\rightarrow$ one base, one derived
- **Multiple** $\rightarrow$ many bases, one derived
- **Multilevel** $\rightarrow$ inheritance in levels
- **Hierarchical** $\rightarrow$ one base, many derived
- **Hybrid** $\rightarrow$ combination of inheritance types

Thus, inheritance promotes code reusability and helps in building relationships among classes in C++.

---

## Q5. Explain the use of Virtual Functions with an example program.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 8–9)

A virtual function is a member function in a base class that is declared using the keyword `virtual`. It allows function overriding and supports runtime polymorphism.

#### Uses of Virtual Functions
- They allow the derived class function to be called using a base class pointer.
- They provide runtime polymorphism.
- They allow different derived classes to provide their own implementation of the same function.

#### Example Program
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Base class";
    }
};

class Derived : public Base {
public:
    void show() {
        cout << "Derived class";
    }
};

int main() {
    Base *ptr;
    Derived obj;
    ptr = &obj;
    ptr->show();
    return 0;
}
```

#### Output
```text
Derived class
```

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 4)

#### Virtual Function
A virtual function is a member function in a base class that is declared using the keyword `virtual`. It is redefined in the derived class. When a base class pointer points to a derived class object, the virtual function helps call the derived class version at run time. This is called runtime polymorphism or late binding.

#### Use of Virtual Functions
1. To achieve runtime polymorphism.
2. To allow function overriding in derived classes.
3. To decide at run time which function should be executed.
4. Useful when the same interface is used for different types of objects.

#### Example
Program to demonstrate virtual function in C++
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {
        cout << "Display from Base class" << endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Display from Derived class" << endl;
    }
};

int main() {
    Base *ptr;
    Derived d;
    ptr = &d;
    ptr->show();
    return 0;
}
```

#### Output
```text
Display from Derived class
```

Thus, virtual functions are used to implement runtime polymorphism in C++. They ensure that the correct function is called based on the object type, not the pointer type.

---

## Q6. What is an abstract class? Demonstrate with an example.

### Version 1 — Typed Notes ([`CPP/raw/cpp-3.pdf`](raw/cpp-3.pdf), Pages 9–11)

An abstract class is a class that contains at least one pure virtual function. It is used as a base class and cannot be used to create objects directly.

A pure virtual function is declared by assigning `= 0`.

#### Syntax
```cpp
class ClassName {
public:
    virtual void functionName() = 0;
};
```

#### Example Program
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle";
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}
```

#### Output
```text
Drawing Circle
```

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 5)

An abstract class in C++ is a class that contains at least one pure virtual function. A pure virtual function is declared using `= 0`. Objects of an abstract class cannot be created. Abstract classes are used as base classes and derived classes must implement the pure virtual function.

#### Syntax
```cpp
class Base {
public:
    virtual void show() = 0;
};
```

#### Example
```cpp
#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

int main() {
    Circle c;
    c.draw();
    return 0;
}
```

#### Output
```text
Drawing Circle
```

Thus, an abstract class provides a common interface for derived classes and supports runtime polymorphism in C++.
