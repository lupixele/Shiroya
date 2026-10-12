# Object Oriented Programming through C++ — Unit 4 Answers (`unit 4 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf) *(Typed Unit 4 Answers)*
> - [`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 4 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf` (Page 6)](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 4 Q1)*
>
> **Questions File:** [`question.md` — UNIT 4](question.md#unit-4)

---

## Q1. What is generic programming? Explain how templates support generic programming in C++.

### Explanation
**Generic programming** is an approach to software development where algorithms and data structures are written in a general form, independent of any specific data type. Instead of writing separate code for `int`, `float`, `double`, etc., a single generic implementation works across multiple types.

### How Templates Support Generic Programming
C++ achieves generic programming through **templates**:
1. **Write once, use anywhere:** A function or class template is written once, and the compiler generates the specific type-based version automatically upon instantiation.
2. **Code deduplication:** Eliminates repetitive boilerplate code for different data types.
3. **Type safety:** Unlike preprocessor macros or `void*` pointers, templates are fully type-checked at compile time.
4. **High efficiency:** Because template code generation occurs during compilation, there is zero runtime overhead.

### Example Program
```cpp
#include <iostream>
using namespace std;

// Generic template function
template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max integer : " << maximum(10, 20) << endl;
    cout << "Max double  : " << maximum(5.5, 2.3) << endl;
    cout << "Max char    : " << maximum('A', 'Z') << endl;
    return 0;
}
```

### Output
```text
Max integer : 20
Max double  : 5.5
Max char    : Z
```

---

## Q2. What is a function template? Explain with a general example.

### Explanation
A **function template** is a formula or blueprint for creating generic functions that perform the same algorithmic logic across different data types using placeholder parameters (typically `T`).

### Important Points
1. Defined using the `template <class T>` or `template <typename T>` keyword.
2. The placeholder `T` represents any data type supplied by the caller.
3. The compiler deduces the actual data type from arguments passed at the call site.
4. Promotes code reuse and clean design.

### General Syntax
```cpp
template <class T>
T functionName(T a, T b) {
    // function body
}
```

### Example Program
```cpp
#include <iostream>
using namespace std;

template <class T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Integer sum : " << add(10, 20) << endl;
    cout << "Float sum   : " << add(2.5, 3.5) << endl;
    return 0;
}
```

### Output
```text
Integer sum : 30
Float sum   : 6
```

---

## Q3. Explain overloading of template functions in C++ with a suitable example.

### Explanation
**Template function overloading** occurs when two or more function templates share the same function name but differ in:
1. The number of parameters.
2. The types of parameters.

When a function call is made, the compiler inspects the arguments and automatically calls the best matching overloaded template version.

### Key Points
- It provides flexibility to perform similar operations across varying numbers of arguments.
- It is resolved at compile time (**compile-time polymorphism**).

### Example Program
```cpp
#include <iostream>
using namespace std;

// 1. Template function with two parameters
template <class T>
T add(T a, T b) {
    return a + b;
}

// 2. Overloaded template function with three parameters
template <class T>
T add(T a, T b, T c) {
    return a + b + c;
}

int main() {
    cout << "Sum of 2 numbers : " << add(10, 20) << endl;
    cout << "Sum of 3 numbers : " << add(10, 20, 30) << endl;
    return 0;
}
```

### Output
```text
Sum of 2 numbers : 30
Sum of 3 numbers : 60
```

---

## Q4. What is Template and implement of bubble sort.

### Explanation
- **Template:** A C++ feature that enables generic programming by defining functions or classes that operate on parameterized data types.
- **Bubble Sort:** A simple comparison-based sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order until the array is fully sorted.

Implementing Bubble Sort as a function template allows the same sorting function to sort an array of integers, floating-point numbers, or characters without modification.

### Example Program
```cpp
#include <iostream>
using namespace std;

// Generic Bubble Sort function template
template <class T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Generic display function template
template <class T>
void display(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int intArr[] = {5, 2, 8, 1, 3};
    int n = 5;

    cout << "Before sorting : ";
    display(intArr, n);

    bubbleSort(intArr, n);

    cout << "After sorting  : ";
    display(intArr, n);

    return 0;
}
```

### Output
```text
Before sorting : 5 2 8 1 3 
After sorting  : 1 2 3 5 8 
```

---

## Q5. Differentiate between templates and macros in C++.

### Explanation
Both templates and macros support code reuse in C++, but they operate at fundamentally different stages of compilation and offer vastly different safety guarantees.

### Comparison Table

| Feature | Templates | Macros (`#define`) |
| :--- | :--- | :--- |
| **Processed By** | Processed by the **compiler**. | Processed by the **preprocessor**. |
| **Type Safety** | Strictly **type-safe**; compiler checks types. | **No type safety**; simple text replacement. |
| **Scope Rules** | Respects class and namespace scopes. | Global; ignores scopes. |
| **Debugging** | Easy to debug with descriptive compiler errors. | Difficult to debug due to literal text substitution. |
| **Side Effects** | Safe evaluation (arguments evaluated once). | Prone to side effects (e.g., `#define SQ(x) x*x` on `x+1`). |
| **Syntax** | Uses `template <class T>` keyword. | Uses `#define` preprocessor directive. |

### Code Comparison

**Template:**
```cpp
template <class T>
T square(T x) {
    return x * x;
}
```

**Macro:**
```cpp
#define SQUARE(x) ((x) * (x))
```

### Conclusion
Templates are preferred in modern C++ because they provide strong type safety, respect language scoping rules, and avoid unexpected text-substitution bugs common to macros.
