# Object Oriented Programming through C++ — Unit 4 Answers (`unit 4 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf) *(Typed Unit 4 Answers)*
> - [`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 4 Answers — Q2 to Q6)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf) *(Page 6 — Handwritten Unit 4 Q1)*
>
> **Questions File:** [`questions.md` — UNIT 4](questions.md#unit-4)

---

## Q1. What is generic programming? Explain how templates support generic programming in C++.

### Version 1 — Typed Notes ([`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf), Pages 2–3)

#### Generic Programming
Generic programming is a programming technique in which algorithms and functions are written independently of the data type.

It allows the same code to work with different data types such as `int`, `float`, `double`, etc.

#### How Templates Support Generic Programming
C++ supports generic programming using templates.
- A template allows us to write a function or class once.
- The same code can be used for different data types.
- The compiler generates the required version based on the data type.
- It reduces code duplication and improves reusability.

#### Example
```cpp
#include <iostream>
using namespace std;

template <class T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << maximum(10, 20) << endl;
    cout << maximum(5.5, 2.3);

    return 0;
}
```

#### Output
```text
20
5.5
```

#### Conclusion
Templates make C++ programs more flexible, reusable, and type-independent.

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_3_Handwritten_Answers.pdf`](raw/Unit_3_Handwritten_Answers.pdf), Page 6)

#### Generic Programming
Generic programming is a method of writing programs in a general form so that the same code can work with different data types. Instead of writing separate functions or classes for `int`, `float`, `char`, etc., we write a single template and the compiler creates the required version automatically.

#### How templates support generic programming in C++
1. Templates allow us to write one function or one class that can work with many data types.
2. They reduce code duplication because the same logic need not be written again for each type.
3. They improve reusability and make programs easier to maintain.
4. The compiler generates the correct code depending on the type used.
5. Templates provide type safety, unlike macros.

#### Syntax of function template
```cpp
template <class T>
T add(T a, T b)
{
    return a + b;
}
```

#### Example
Program to add two values using function template
```cpp
#include <iostream>
using namespace std;

template <class T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(10, 20) << endl;
    cout << add(2.5, 3.5) << endl;
    return 0;
}
```

#### Output
```text
30
6
```

Thus, templates are the main feature that support generic programming in C++. They help write flexible, reusable, and type-safe code.

---

## Q2. What is a function template? Explain with a general example.

> *(Note: Numbered as Question `3` in `Question Bank_CPP_Unit 3_4_5.pdf` and `UNIT 4(CPP).pdf` Pages 3–5, and as Question `2` in `UNIT 4(CPP).pdf` Page 1 and `Unit_4_Handwritten_Answers (1).pdf` Page 1.)*

### Version 1 — Typed Notes ([`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf), Pages 3–5)

#### Function Template
A function template is a special type of function that can operate with different data types.

Instead of writing separate functions for `int`, `float`, `double`, etc., we can write one function template.

#### Important Points
1. A function template is a generic function.
2. It uses a placeholder such as `T` to represent a data type.
3. The keyword `template` is used to declare it.
4. The compiler determines the actual data type when the function is called.
5. It reduces duplicate code.
6. It provides code reusability.
7. It supports different data types using the same function.

#### General Syntax
```cpp
template <class T>
T functionName(T a, T b)
{
    // statements
}
```

#### Example
```cpp
#include <iostream>
using namespace std;

template <class T>
T add(T a, T b)
{
    return a + b;
}

int main()
{
    cout << add(10, 20) << endl;
    cout << add(2.5, 3.5);

    return 0;
}
```

#### Output
```text
30
6
```

#### Explanation
- `T` is a generic data type.
- `add()` can accept different types of values.
- `add(10, 20)` works with `int`.
- `add(2.5, 3.5)` works with `double`.

#### Conclusion
A function template allows us to create one general function that can work with multiple data types.

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf), Page 1)

#### Function Template
A function template in C++ is a generic function that works with different data types using the same code. Instead of writing separate functions for `int`, `float`, `double`, etc., we write one template function and the compiler creates the required function automatically based on the data type used.

#### Syntax
```cpp
template <class T>
T functionName(T a, T b)
{
    // function body
}
```

#### General Example
Program to find the maximum of two values using a function template.
```cpp
#include <iostream>
using namespace std;

template <class T>
T maximum(T a, T b)
{
    return (a > b) ? a : b;
}

int main()
{
    cout << maximum(10, 20) << endl;
    cout << maximum(4.5, 3.2) << endl;
    return 0;
}
```

#### Output
```text
20
4.5
```

#### Conclusion
Thus, a function template helps us write reusable and type-independent functions in C++. It reduces code duplication and supports generic programming.

---

## Q3. Explain overloading of template functions in C++ with a suitable example.

> *(Note: Numbered as Question `4` in `Question Bank_CPP_Unit 3_4_5.pdf` and `UNIT 4(CPP).pdf` Pages 5–7, and as Question `3` in `UNIT 4(CPP).pdf` Page 1 and `Unit_4_Handwritten_Answers (1).pdf` Page 2.)*

### Version 1 — Typed Notes ([`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf), Pages 5–7)

#### Template Function Overloading
Template function overloading means defining two or more functions with the same name but different parameter lists.

The compiler selects the appropriate function according to the number or type of arguments passed.

#### Important Points
1. Multiple template functions can have the same function name.
2. Their parameter lists must be different.
3. They may differ in the number of parameters.
4. They may also differ in the type of parameters.
5. The compiler determines which function should be called.
6. It provides flexibility and code reusability.
7. It is an example of compile-time polymorphism.

#### Example
```cpp
#include <iostream>
using namespace std;

template <class T>
T add(T a, T b)
{
    return a + b;
}

template <class T>
T add(T a, T b, T c)
{
    return a + b + c;
}

int main()
{
    cout << add(10, 20) << endl;
    cout << add(10, 20, 30);

    return 0;
}
```

#### Output
```text
30
60
```

#### Explanation
- The first `add()` function accepts two arguments.
- The second `add()` function accepts three arguments.
- When two values are passed, the first function is selected.
- When three values are passed, the second function is selected.

#### Conclusion
Template function overloading allows us to use the same function name for different operations, making programs easier to understand and reuse.

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf), Page 2)

Function template overloading means defining more than one function template with the same name but different parameter lists. When a function call is made, the compiler selects the most suitable overloaded template based on the number and type of arguments. This gives flexibility and allows the same function name to work for different forms of data.

#### 1. Need for overloading
1. It allows the same function name to be used for different kinds of operations.
2. It improves code reusability and readability.
3. The compiler chooses the best matching template automatically.

#### 2. Syntax
```cpp
template <class T>
return_type function_name(parameters);
```
We can define another overloaded template with different parameters.

#### 3. Example
Program to overload template functions for finding maximum values.
```cpp
#include <iostream>
using namespace std;

template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

template <class T>
T maximum(T a, T b, T c) {
    T m = (a > b) ? a : b;
    return (m > c) ? m : c;
}

int main() {
    cout << "Max of 10 and 20 = " << maximum(10, 20) << endl;
    cout << "Max of 3, 7 and 5 = " << maximum(3, 7, 5) << endl;
    cout << "Max of 2.5 and 1.8 = " << maximum(2.5, 1.8) << endl;
    return 0;
}
```

#### Output
```text
Max of 10 and 20 = 20
Max of 3, 7 and 5 = 7
Max of 2.5 and 1.8 = 2.5
```

#### 4. Conclusion
Thus, overloaded template functions in C++ allow multiple templates with the same name but different parameter lists. They make generic programming more flexible and reduce repeated code.

---

## Q4. What is Template and implement of bubble sort.

> *(Note: Numbered as Question `5` in `Question Bank_CPP_Unit 3_4_5.pdf` and `UNIT 4(CPP).pdf` Pages 7–10, and as Question `4` in `UNIT 4(CPP).pdf` Page 1 and `Unit_4_Handwritten_Answers (1).pdf` Page 3.)*

### Version 1 — Typed Notes ([`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf), Pages 7–10)

#### Template
A template is a C++ feature used to write generic and reusable code.

It allows the same function or class to work with different data types.

#### Important Points
1. Templates support generic programming.
2. They reduce code duplication.
3. They increase code reusability.
4. Templates can be used for functions and classes.
5. The compiler generates the required code according to the data type.
6. Bubble Sort can be implemented using a function template.

#### Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.

**For example:**
`5 2 8 1 3`

**After sorting:**
`1 2 3 5 8`

#### Bubble Sort using Template
```cpp
#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;

    bubbleSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
```

#### Output
```text
1 2 3 5 8
```

#### Advantages
- The same `bubbleSort()` can work with different data types.
- It avoids writing separate sorting functions.
- It improves reusability and flexibility.

#### Conclusion
A template makes Bubble Sort a generic sorting function that can be reused for different data types.

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf), Page 3)

#### 1. Template
A template in C++ is a feature used for generic programming. It allows us to write a single function or class that can work with different data types. Instead of writing separate code for `int`, `float`, etc., we can use a template and reuse the same logic.

#### 2. Bubble Sort
Bubble sort is a simple sorting technique in which adjacent elements are compared and swapped if they are in the wrong order. After each pass, the largest element moves to its correct position.

#### 3. Syntax
```cpp
template <class T>
return_type function_name(parameters);
```

#### 4. Program to implement bubble sort using function template
```cpp
#include <iostream>
using namespace std;

template <class T>
void bubbleSort(T a[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template <class T>
void display(T a[], int n)
{
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}

int main()
{
    int a[] = {5, 2, 9, 1, 3};
    int n = 5;

    bubbleSort(a, n);

    cout << "Sorted array: ";
    display(a, n);

    return 0;
}
```

#### 5. Output
```text
Sorted array: 1 2 3 5 9
```

#### 6. Conclusion
Thus, templates make programs reusable and type-independent. By using a function template, the same bubble sort logic can be used for different data types.

---

## Q5. Differentiate between templates and macros in C++.

> *(Note: Numbered as Question `6` in `Question Bank_CPP_Unit 3_4_5.pdf` and `UNIT 4(CPP).pdf` Pages 10–11, and as Questions `5` and `6` in `Unit_4_Handwritten_Answers (1).pdf` Pages 4–5.)*

### Version 1 — Typed Notes ([`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf), Pages 10–11)

#### Templates vs Macros

| Templates | Macros |
| :--- | :--- |
| 1. Templates are a feature of the C++ language. | 1. Macros are handled by the preprocessor. |
| 2. They are mainly used for generic programming. | 2. They are mainly used for text substitution. |
| 3. Templates provide type checking. | 3. Macros generally do not provide type checking. |
| 4. Templates are processed by the compiler. | 4. Macros are processed before compilation. |
| 5. Templates can be used to create generic functions and classes. | 5. Macros are commonly used for constants and code substitution. |
| 6. Templates provide better type safety. | 6. Macros can cause unexpected results due to text substitution. |
| 7. Templates provide better code structure and maintainability. | 7. Large macros can make programs difficult to understand and debug. |
| 8. Templates use keywords such as `template` and `class`. | 8. Macros use the `#define` directive. |
| 9. Templates are generally safer and more suitable for generic programming. | 9. Macros are useful for simple preprocessing operations. |

#### Example of Template
```cpp
template <class T>
T square(T x)
{
    return x * x;
}
```

#### Example of Macro
```cpp
#define SQUARE(x) ((x) * (x))
```

#### Conclusion
Templates are preferred for generic programming because they provide type safety, reusability, and better program structure, whereas macros perform simple preprocessor-based text substitution.

---

### Version 2 — Handwritten Notes ([`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf), Pages 4–5)

Both templates and macros are used to write reusable code, but they work in different ways.

| Point | Templates | Macros |
| :--- | :--- | :--- |
| **1. Meaning :** | Feature of C++ for generic programming. | Preprocessor directives using `#define`. |
| **2. Type checking :** | Type-safe and checked by compiler. | No type checking. |
| **3. Working stage :** | Processed during compilation. | Expanded before compilation. |
| **4. Functionality :** | Can be used for functions and classes. | Simple text substitution. |
| **5. Debugging :** | Easier to debug. | Harder to debug. |
| **6. Safety and reliability :** | Safer and more reliable. | May cause unexpected errors. |

#### Example
```cpp
// Template example
template <class T>
T add(T a, T b) {
    return a + b;
}

// Macro example (Page 4)
#define ADD(a,b) a+b

// Macro example (Page 5)
#define ADD(a,b) ((a) + (b))
```

#### Conclusion
Templates are preferred in C++ because they are type-safe, flexible, and better for generic programming. Macros are simpler but less safe.
