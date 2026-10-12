# Object Oriented Programming through C++ — Unit 4 Answers (`unit 4 answers.md`)

> **Raw Source PDFs:**
> - [`CPP/raw/UNIT 4(CPP).pdf`](raw/UNIT%204(CPP).pdf) *(Typed Unit 4 Answers)*
> - [`CPP/raw/Unit_4_Handwritten_Answers (1).pdf`](raw/Unit_4_Handwritten_Answers%20(1).pdf) *(Handwritten Unit 4 Answers)*
> - [`CPP/raw/Unit_3_Handwritten_Answers.pdf` (Page 6)](raw/Unit_3_Handwritten_Answers.pdf) *(Handwritten Unit 4 Q1)*
>
> **Questions File:** [`question.md` — UNIT 4](question.md#unit-4)

---

## Q1. What is generic programming? Explain how templates support generic programming in C++.

### Concept of Generic Programming
**Generic programming** is an approach to software design where algorithms and data structures are written in a generalized, type-independent form. Instead of writing separate versions of an algorithm for `int`, `float`, `double`, or custom objects, generic programming allows a single blueprint to operate seamlessly on any data type.

In traditional programming languages, type-independence was either achieved through unsafe pointers (like `void*` in C) or through preprocessor macros. In C++, generic programming is implemented safely and natively using **Templates**.

---

### How Templates Support Generic Programming in C++

1. **Type Parameterization:**
   Templates allow types to be passed as parameters to functions and classes using placeholder identifiers (commonly `T`).
   ```cpp
   template <typename T>
   ```

2. **Compile-Time Code Generation (Template Instantiation):**
   Templates are not compiled into machine code directly. When a template is invoked with a concrete type (e.g., `maximum(10, 20)`), the compiler inspects the arguments and automatically generates (instantiates) a concrete, type-specific version of that function at compile time.

3. **Strict Type Safety:**
   Unlike macros or `void*` pointers, templates are fully type-checked by the compiler. Any incompatible operations (such as comparing types that lack `<` or `>`) are caught immediately at compile time.

4. **Zero Runtime Overhead:**
   Because all template expansion and specialization happens during compilation, there is zero penalty in runtime performance compared to hand-written functions.

5. **Extensibility for User-Defined Types:**
   A template function can immediately work with custom classes (like `Complex`, `Student`), provided the class supports the operations used inside the template.

---

### Exam-Ready Program (Generic Maximum Function)
```cpp
#include <iostream>
using namespace std;

// Generic template function: works with any data type T
template <class T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // 1. Instantiation for integers
    cout << "Max of (10, 25)    : " << maximum(10, 25) << endl;

    // 2. Instantiation for floating-point numbers
    cout << "Max of (5.5, 2.3)  : " << maximum(5.5, 2.3) << endl;

    // 3. Instantiation for characters
    cout << "Max of ('A', 'Z')  : " << maximum('A', 'Z') << endl;

    return 0;
}
```

### Output
```text
Max of (10, 25)    : 25
Max of (5.5, 2.3)  : 5.5
Max of ('A', 'Z')  : Z
```

### Summary of Benefits
- **Eliminates Code Redundancy:** Write the logic once, use it for infinite data types.
- **Improved Maintainability:** Bug fixes and performance enhancements applied to the template automatically benefit all instances.
- **Foundation of STL:** The C++ Standard Template Library (containers, algorithms) is entirely built on templates.

---

## Q2. What is a function template? Explain with a general example.

### Definition of a Function Template
A **function template** is a special function blueprint in C++ that allows the creation of generic functions capable of operating on multiple data types without repeating code.

Instead of writing overloaded functions for every conceivable type:
```cpp
int add(int a, int b);
float add(float a, float b);
double add(double a, double b);
```
a single function template defines the logic using a generic placeholder type `T`.

---

### Important Points
1. **Keyword:** Defined using `template <class T>` or `template <typename T>`. (Both keywords are interchangeable in this context.)
2. **Type Deduction:** The compiler automatically deduces the type of `T` based on the arguments passed during the function call.
3. **Explicit Specification:** The caller can also explicitly specify the intended type using angle brackets: `add<double>(5, 3.2)`.
4. **Multiple Type Parameters:** A template can accept more than one type parameter: `template <class T1, class T2>`.

### General Syntax
```cpp
template <class T>
T functionName(T parameter1, T parameter2) {
    // function body
    return result;
}
```

---

### Exam-Ready Program (Function Template `add`)
```cpp
#include <iostream>
using namespace std;

// Function template with generic type T
template <class T>
T add(T a, T b) {
    return a + b;
}

int main() {
    // Compiler deduces T as int: generates add(int, int)
    int intResult = add(10, 20);
    cout << "Integer Addition : " << intResult << endl;

    // Compiler deduces T as double: generates add(double, double)
    double doubleResult = add(4.5, 3.2);
    cout << "Double Addition  : " << doubleResult << endl;

    // Explicit type specification:
    cout << "Explicit Float   : " << add<float>(2.1f, 3.4f) << endl;

    return 0;
}
```

### Output
```text
Integer Addition : 30
Double Addition  : 7.7
Explicit Float   : 5.5
```

### Explanation
- In `add(10, 20)`, the compiler deduces `T = int` and compiles an `int` version.
- In `add(4.5, 3.2)`, the compiler deduces `T = double` and compiles a `double` version.
- Only one function template was written, but the compiler produced two distinct, type-safe functions behind the scenes.

---

## Q3. Explain overloading of template functions in C++ with a suitable example.

### What is Template Function Overloading?
**Template function overloading** is the capability in C++ to define multiple functions with the same name where at least one is a template, differing in:
1. **Number of parameters** (e.g., a 2-parameter template vs. a 3-parameter template).
2. **Types of parameters** (e.g., generic `T` vs. concrete pointer `T*`).
3. **Template function vs. Non-template (Ordinary) function**.

---

### Resolution Rules (How the Compiler Chooses)
When an overloaded function call is made, the compiler follows a strict priority order:
1. **Exact Non-Template Match First:** If a non-template function exactly matches the argument types, the compiler prefers the non-template function over any template.
2. **Best Template Match:** If no non-template function matches, the compiler looks for a function template that can match with zero type conversions.
3. **Ambiguity Error:** If two or more templates match equally well without a clear distinction, the compiler generates an ambiguity error.

---

### Exam-Ready Program
The following program demonstrates overloading template functions by varying the **number of parameters**:
```cpp
#include <iostream>
using namespace std;

// 1. Template function with TWO arguments
template <class T>
T add(T a, T b) {
    return a + b;
}

// 2. Overloaded template function with THREE arguments
template <class T>
T add(T a, T b, T c) {
    return a + b + c;
}

// 3. Ordinary non-template function (specialized for strings/characters)
void add(string a, string b) {
    cout << "[Non-Template String Concatenation]: " << a + b << endl;
}

int main() {
    // Calls 2-parameter template function:
    cout << "Sum of 2 numbers: " << add(10, 20) << endl;

    // Calls 3-parameter template function:
    cout << "Sum of 3 numbers: " << add(10, 20, 30) << endl;

    // Calls ordinary non-template function:
    add("Hello ", "World!");

    return 0;
}
```

### Output
```text
Sum of 2 numbers: 30
Sum of 3 numbers: 60
[Non-Template String Concatenation]: Hello World!
```

### Key Takeaway for Full Marks
Overloading template functions allows generic algorithms to adapt to different parameter counts and special data types while retaining clean, consistent function names.

---

## Q4. What is Template and implement of bubble sort.

### Definition of Template
A **Template** is a core C++ feature that enables generic programming by allowing functions and classes to operate with generic types. A template acts as a blueprint from which the compiler generates concrete type-specific code during compilation.

There are two primary types of templates in C++:
1. **Function Templates:** For creating generic functions (e.g., sorting, searching, mathematical functions).
2. **Class Templates:** For creating generic classes (e.g., `vector<T>`, `stack<T>`, `queue<T>`).

---

### Working Principle of Bubble Sort
**Bubble Sort** is a comparison-based sorting algorithm:
1. It repeatedly passes through the array, comparing adjacent elements `arr[j]` and `arr[j+1]`.
2. If `arr[j] > arr[j+1]`, they are swapped.
3. After the first pass, the largest element "bubbles up" to the end of the array.
4. After $n-1$ passes, the entire array is sorted in ascending order.
5. **Time Complexity:** Worst/Average Case $O(n^2)$, Best Case $O(n)$ with a swap flag. Space Complexity: $O(1)$ (in-place).

By implementing Bubble Sort as a **function template**, the exact same code can sort an array of integers, doubles, characters, or any custom class that supports the `>` operator.

---

### Exam-Ready Program (Template-Based Bubble Sort)
```cpp
#include <iostream>
using namespace std;

// Generic Bubble Sort function template
template <class T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap adjacent elements
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Generic print function template
template <class T>
void printArray(T arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    // 1. Sorting an Integer Array
    int intArr[] = {64, 25, 12, 22, 11};
    int n1 = sizeof(intArr) / sizeof(intArr[0]);

    cout << "Original Integer Array : ";
    printArray(intArr, n1);

    bubbleSort(intArr, n1); // Instantiates bubbleSort<int>

    cout << "Sorted Integer Array   : ";
    printArray(intArr, n1);

    cout << endl;

    // 2. Sorting a Float Array with the same template
    float floatArr[] = {3.4f, 1.2f, 5.8f, 2.1f};
    int n2 = sizeof(floatArr) / sizeof(floatArr[0]);

    cout << "Original Float Array   : ";
    printArray(floatArr, n2);

    bubbleSort(floatArr, n2); // Instantiates bubbleSort<float>

    cout << "Sorted Float Array     : ";
    printArray(floatArr, n2);

    return 0;
}
```

### Output
```text
Original Integer Array : 64 25 12 22 11 
Sorted Integer Array   : 11 12 22 25 64 

Original Float Array   : 3.4 1.2 5.8 2.1 
Sorted Float Array     : 1.2 2.1 3.4 5.8 
```

---

## Q5. Differentiate between templates and macros in C++.

### Overview
Both **Templates** and **Macros** (`#define`) provide code reusability and can accept parameterized inputs in C++. However, they operate at fundamentally different phases of program compilation and provide drastically different safety and debugging characteristics.

---

### Detailed Comparison Table

| S.No. | Feature | Templates | Macros (`#define`) |
| :---: | :--- | :--- | :--- |
| **1** | **Processing Phase** | Handled by the **C++ Compiler** during semantic analysis. | Handled by the **Preprocessor** before actual compilation begins. |
| **2** | **Type Safety** | **Strictly type-safe:** Compiler performs rigorous data type verification. | **No type safety:** Performs blind textual search-and-replace. |
| **3** | **Scoping Rules** | Respects class, namespace, and block scopes. | Completely ignores scopes; global from point of definition onward. |
| **4** | **Error Detection & Debugging**| Easy to debug: Compiler outputs meaningful line numbers and type error messages. | Very hard to debug: Error messages often point to expanded code rather than macro definition. |
| **5** | **Side Effects / Evaluation** | Arguments are evaluated **once**, safely preserving expressions. | Arguments are re-evaluated **every time** they appear in macro body, causing severe side effects. |
| **6** | **Syntax & Keywords** | Uses native C++ syntax: `template <class T>`. | Uses preprocessor directive: `#define NAME(x)`. |
| **7** | **Code Expansion** | Creates separate specialized functions only when instantiated. | Expands blindly into the source code at every point of invocation. |

---

### Demonstration of Macro Side-Effect Bug vs Template Safety

Consider a macro and a template designed to calculate the square of a number:

```cpp
#include <iostream>
using namespace std;

// Macro definition
#define MACRO_SQUARE(x) (x * x)

// Template definition
template <class T>
T templateSquare(T x) {
    return x * x;
}

int main() {
    int a = 3;

    // Expression: 3 + 1 = 4. Expected square is 16.

    // 1. Macro Bug:
    // Expands textually to: (3 + 1 * 3 + 1) = 3 + 3 + 1 = 7 (INCORRECT!)
    cout << "Macro Square (a + 1)    : " << MACRO_SQUARE(a + 1) << endl;

    // 2. Template Safety:
    // Evaluates argument (3 + 1) -> passes 4 -> returns 4 * 4 = 16 (CORRECT!)
    cout << "Template Square (a + 1) : " << templateSquare(a + 1) << endl;

    return 0;
}
```

### Output
```text
Macro Square (a + 1)    : 7
Template Square (a + 1) : 16
```

### Conclusion
Templates are strongly preferred over macros for generic programming because they are type-safe, respect scoping rules, and avoid hazardous unexpected side effects caused by literal text substitution.
