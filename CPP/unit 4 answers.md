# Object Oriented Programming through C++ — Unit 4 Answers (`unit 4 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf) *(Typed Unit 4 Answers)*
> - [`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 4 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf` (Page 6)](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 4 Q1)*
>
> **Questions File:** [`question.md` — UNIT 4](question.md#unit-4)

---

## Q1. What is generic programming? Explain how templates support generic programming in C++.

### Generic Programming
**Generic programming** is a programming approach where functions and algorithms are written independently of any specific data type. Instead of writing separate code for `int`, `float`, and `double`, a single generic function works for all of them.

### How Templates Support Generic Programming
C++ implements generic programming through **templates**:
1. **Type Parameterization:** Templates use a placeholder type (such as `T`) using `template <class T>`.
2. **Automatic Code Generation:** The compiler generates the required version of the function based on the data type passed during the call.
3. **Type Safety:** The compiler checks data types at compile time, preventing type mismatch errors.
4. **Code Reusability:** The algorithm is written once and reused for many data types without code duplication.

### Code Example
```cpp
#include <iostream>
using namespace std;

// Generic template function
template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << "Max of (10, 20)   : " << maximum(10, 20) << endl;   // int
    cout << "Max of (5.5, 2.3) : " << maximum(5.5, 2.3) << endl; // double
    cout << "Max of ('A', 'Z') : " << maximum('A', 'Z') << endl; // char
    return 0;
}
```

### Output
```text
Max of (10, 20)   : 20
Max of (5.5, 2.3) : 5.5
Max of ('A', 'Z') : Z
```

---

## Q2. What is a function template? Explain with a general example.

### Function Template
A **function template** is a blueprint for creating generic functions that perform the same operation on different data types.

Instead of writing separate functions for each data type:
- You write one function template with a placeholder `T`.
- The compiler determines the actual data type when the function is called.

### General Syntax
```cpp
template <class T>
T functionName(T a, T b) {
    // statements
}
```

### Code Example
```cpp
#include <iostream>
using namespace std;

template <class T>
T add(T a, T b) {
    return a + b;
}

int main() {
    cout << "Integer Addition : " << add(10, 20) << endl;
    cout << "Double Addition  : " << add(2.5, 3.5) << endl;
    return 0;
}
```

### Output
```text
Integer Addition : 30
Double Addition  : 6
```

---

## Q3. Explain overloading of template functions in C++ with a suitable example.

### Template Function Overloading
Template function overloading means defining more than one template function with the same name, but with different parameter lists (different number or types of parameters).

The compiler automatically selects the appropriate template based on the arguments passed during the function call.

### Code Example
```cpp
#include <iostream>
using namespace std;

// Template function with 2 parameters
template <class T>
T add(T a, T b) {
    return a + b;
}

// Overloaded template function with 3 parameters
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

### Template
A template in C++ is a feature used to write generic and reusable code. It allows functions and classes to work with different data types without rewriting the logic.

### Bubble Sort
Bubble Sort is a simple sorting algorithm that repeatedly compares adjacent elements and swaps them if they are in the wrong order.

Using a function template, Bubble Sort can sort arrays of integers, floats, or characters using the same code.

### Code Example
```cpp
#include <iostream>
using namespace std;

// Bubble sort using template
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

template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int n = 5;

    cout << "Before sorting: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "After sorting : ";
    printArray(arr, n);

    return 0;
}
```

### Output
```text
Before sorting: 5 2 8 1 3 
After sorting : 1 2 3 5 8 
```

---

## Q5. Differentiate between templates and macros in C++.

### Difference Table

| Feature | Templates | Macros (`#define`) |
| :--- | :--- | :--- |
| **Processed By** | Handled by the **compiler**. | Handled by the **preprocessor**. |
| **Type Checking** | Strictly **type-safe**; types are verified. | **No type checking**; simple text substitution. |
| **Scope** | Obeys class and namespace scopes. | Ignores scope; global everywhere. |
| **Debugging** | Easy to debug with meaningful error messages. | Hard to debug; errors can be confusing. |
| **Side Effects** | Safe; arguments evaluated once. | Can cause side effects if arguments are evaluated multiple times. |
| **Keyword** | Uses `template <class T>`. | Uses `#define`. |

### Code Example

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
Templates are preferred because they provide type safety, respect scope, and avoid bugs caused by simple text substitution.
