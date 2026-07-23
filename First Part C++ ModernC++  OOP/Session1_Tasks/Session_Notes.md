## 1 Why Learn C++?

- **Close to the hardware.** You control memory layout and management directly, which gives
  high performance and deep understanding of how computers actually work.
- **Teaches the fundamentals.** Writing C++ forces you to understand the difference between the
  *compiler*, *linker*, and *loader*; between *declaration* and *definition*; between *stack*
  and *heap*; and how data types map to memory. Those concepts carry over to every other
  language.
- **Real OOP from the ground up.** You learn objects, classes, inheritance, and polymorphism —
  and later, *how* they work under the hood (virtual tables, dynamic dispatch).
- **Evergreen and in demand.** Decades old and still one of the most widely used languages in
  systems and application programming. Strong, well-paid job market.

> "To learn any programming language — not just C++ — you need to code, and code, and code
> again until it becomes second nature."

# 2. How C++ Code Becomes a Program

This is the section the rest of the course quietly depends on. Spend real time here — almost
every confusing error message a beginner sees maps to one of these stages.

C++ is a **compiled** language. Your human-readable source is translated **ahead of time** into
**machine code** (raw CPU instructions) and saved as an executable file. Running the program
just runs that machine code — the compiler is no longer involved. (Contrast with Python, where
an interpreter reads and executes your source every time you run it.)

## 2.1 The Build Pipeline

```
  hello.cpp
     │
     ▼
┌──────────────┐   Handles all #directives: pastes in #include files,
│ Preprocessor │   expands #define macros, strips comments.
└──────────────┘   Output: pure C++ with no # lines (a "translation unit").
     │
     ▼
┌──────────────┐   Translates C++ into assembly for your CPU.
│  Compiler    │   Type checking happens here. Most errors are caught here.
└──────────────┘   Output: assembly (.s)
     │
     ▼
┌──────────────┐   Turns assembly into machine code.
│  Assembler   │   Output: an object file (.o) — machine code, but NOT yet runnable.
└──────────────┘   (Calls like std::cout are still unresolved references.)
     │
     ▼
┌──────────────┐   Combines your .o file(s) with the C++ standard library and
│  Linker      │   resolves every referenced symbol into one executable.
└──────────────┘   Output: an executable (a.out)
     │
     ▼
┌──────────────┐   The OS loads the executable into memory, sets up the
│  Loader (OS) │   stack/heap, and jumps to main(). Your program now runs.
└──────────────┘
```

### Seeing each stage yourself

`g++` normally runs all stages at once, but you can stop after any one of them. Run these live —
they make the abstract pipeline tangible:

```bash
g++ -E hello.cpp -o hello.ii   # 1. Preprocess only  → open it; note <iostream> got pasted in
g++ -S hello.cpp -o hello.s    # 2. Compile to assembly → human-readable CPU instructions
g++ -c hello.cpp -o hello.o    # 3. Assemble to object file → binary, not runnable
g++ hello.cpp -o hello         # 4. Everything: preprocess + compile + assemble + link
```

## 2.2 Which Stage Produced My Error?

This single table saves students hours of confusion all semester:

| Stage | Typical error message | Cause |
|-------|-----------------------|-------|
| **Preprocessor** | `fatal error: xyz.h: No such file or directory` | Bad `#include` / missing header |
| **Compiler** | `expected ';' before ...`, `'x' was not declared in this scope`, type mismatches | Syntax or type error in your code |
| **Linker** | `undefined reference to 'foo'`, `multiple definition of 'bar'` | A function was *declared* but never *defined*, or defined twice |
| **Loader / Runtime** | `Segmentation fault`, wrong output, crash | Logic/memory bug — code compiled fine but behaves wrong |

---

## 3 Declaration, Definition, and Initialization

These three words are used loosely in conversation but mean specific things — worth getting right
early.

```cpp
int x;              // DEFINITION: reserves memory for x (value is garbage until set)
int y = 5;          // DEFINITION + INITIALIZATION: reserve memory AND give it a value
x = 10;             // ASSIGNMENT: store a value into already-existing storage
extern int z;       // DECLARATION only: "z exists somewhere else" — no memory reserved here
```

- **Declaration** tells the compiler a name and its type exist (used across multiple files with
  `extern`). A variable can be declared many times.
- **Definition** actually allocates the storage. A variable must be defined **exactly once**.
- **Initialization** gives it a value *at the moment of definition*.

Modern C++ also supports brace initialization: `int y{5};` (safer — it rejects narrowing
conversions).

---


### Shadowing and the scope resolution operator `::`

If a local and a global share a name, the **local wins** inside the function (it *shadows* the
global). Use the **scope resolution operator `::`** to reach the global:

```cpp
#include <iostream>
using namespace std;

int g = 20;               // global

int main() {
    int g = 10;           // local shadows the global
    cout << "Local  g: " << g   << endl;   // 10
    cout << "Global g: " << ::g << endl;   // 20  (::g reaches the global)
    return 0;
}
```
---

### Find exact limits with `<limits>`

Better than hard-coding ranges: ask the standard library.

```cpp
#include <iostream>
#include <limits>
using namespace std;

int main() {
    cout << "int  min = " << numeric_limits<int>::min() << endl;
    cout << "int  max = " << numeric_limits<int>::max() << endl;
    cout << "uint max = " << numeric_limits<unsigned int>::max() << endl;
    cout << "long max = " << numeric_limits<long int>::max() << endl;
    return 0;
}
```

---


### bool ↔ number conversion

Any **non-zero** number converts to `true`; **zero** converts to `false`. And `true`/`false`
convert to `1`/`0` in arithmetic:

```cpp
#include <iostream>
using namespace std;

int main() {
    int   zero = 0, twelve = 12;
    float pi   = 3.14f;

    bool a = zero;    // 0        -> false
    bool b = twelve;  // non-zero -> true
    bool c = pi;      // non-zero -> true

    cout << a << " " << b << " " << c << endl;   // 0 1 1

    int sum = twelve + true + true;              // 12 + 1 + 1
    cout << "sum = " << sum << endl;             // 14
    return 0;
}
```

### Two ways to write a cast:

```cpp
int x = (int)3.9;              // C-style cast          → 3
int y = static_cast<int>(3.9); // C++ style (preferred) → 3
```

💡 **Teaching tip:** Prefer `static_cast<T>(value)`. It's more explicit, easier to search for,
and the compiler checks it more carefully than the terse C-style `(T)value`.

---

### Reference — an alias (second name) for an existing variable

```cpp
#include <iostream>
using namespace std;

int main() {
    int  c = 11;
    int &ref = c;                  // ref is another name for c
    ref = 121;                     // changing ref changes c
    cout << c << endl;             // 121
    return 0;
}
```

---

### `typedef` / `using` — create an alias for an existing type

```cpp
typedef int Feet;          // classic C style
using   Meters = int;      // modern C++ style (preferred)

Feet   distance = 100;     // just an int, but reads with intent
Meters height   = 2;
```

---