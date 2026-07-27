# ModernCpp
### 1. Templates

Templates allow writing generic code that can handle different data types without duplication.

### 1️⃣ **Function Template (Example)**

```c++
#include <iostream>

// Function template to return the maximum of two values
template <typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Max int: " << maxValue(10, 20) << std::endl;
    std::cout << "Max double: " << maxValue(5.5, 2.3) << std::endl;
    return 0;
}
```

📌 **How It Works?**

- `template <typename T>` makes `T` a generic type.
- `maxValue<int>(10, 20)` is automatically instantiated as `maxValue<int>(int a, int b)`.
- Works for `int`, `double`, `float`, etc.

------

## **2️⃣ Class Templates**

A **class template** allows creating generic classes.

### **Class Template Example**

```c++
#include <iostream>

// Template class for storing a value
template <typename T>
class Storage {
private:
    T data;
public:
    // Constructor
    Storage(T value) : data(value) {}

    // Getter function
    T getData() { return data; }

    // Setter function
    void setData(T value) { data = value; }

    // Display function
    void show() { std::cout << "Stored value: " << data << std::endl; }
};

int main() {
    // Using Storage with an integer
    Storage<int> intStorage(10);
    intStorage.show();  // Output: Stored value: 10

    // Using Storage with a double
    Storage<double> doubleStorage(3.14);
    doubleStorage.show();  // Output: Stored value: 3.14

    // Using Storage with a string
    Storage<std::string> stringStorage("Hello");
    stringStorage.show();  // Output: Stored value: Hello

    return 0;
}

```

📌 **How It Works?**

- `Box<int>` creates an integer version of the `Box` class.
- `Box<std::string>` creates a string version of the `Box` class.

----------------

```c++
template <typename T1, typename T2>
class Data {
private:
    T1 firstData;
    T2 secondData;
public:
    Data(T1 a, T2 b) : firstData(a), secondData(b) {}

    void show() {
        std::cout << "Data: (" << firstData << ", " << secondData << ")" << std::endl;
    }
};

int main() {
    Data<int, double> p1(10, 5.5);   // int and double
    p1.show();  // Output: Data: (10, 5.5)

    Data<std::string, char> p2("Hello", 'A');  // string and char
    p2.show();  // Output: Data: (Hello, A)

    return 0;
}

```

------

## **3️⃣ Variadic Templates (C++11)**

A **variadic template** allows passing multiple arguments of different types.

### **Example: Print Multiple Arguments**

```c++
#include <iostream>

// Base case (empty function)
void print() { std::cout << std::endl; }

// Variadic template function
template <typename T, typename... Args>
void print(T first, Args... rest) {
    std::cout << first << " ";
    print(rest...); // Recursively call with remaining arguments
}

int main() {
    print(1, 2.5, "Hello", 'A'); // Output: 1 2.5 Hello A
    return 0;
}
```

📌 **How It Works?**

- `print(T first, Args... rest)` takes multiple arguments.
- It prints the first argument and calls itself recursively.

------

## 

## Smart Pointers

### **Pointers Issues in C and C++**

In both C and C++, raw pointers (`int* ptr;`) are used to manage memory manually. However, they come with several issues, including:

1. **Memory Leaks** – If dynamically allocated memory (`new`) is not explicitly deallocated (`delete`), it leads to memory leaks.
2. **Dangling Pointers** – A pointer pointing to a deallocated or invalid memory location can cause undefined behavior.
3. **Double Deletion** – Deleting the same pointer twice (`delete ptr; delete ptr;`) can cause crashes.
4. **Manual Resource Management** – Managing memory manually is error-prone, making code harder to maintain.
5. **Complexity in Ownership Handling** – Tracking which part of the program owns and should free a pointer is difficult, leading to ownership issues.

------

#### **1. Memory Leaks**

A **memory leak** happens when dynamically allocated memory is not freed, causing the program to consume more memory over time.

**Example:**

```c++
#include <iostream>

void memoryLeak() {
    int* ptr = new int(10); // Allocating memory
    std::cout << "Value: " << *ptr << std::endl;
    // Forgot to delete ptr -> Memory leak
}

int main() {
    memoryLeak();
    // Memory is still allocated even after function exits
    return 0;
}
```

🔹 **Issue:** Memory allocated with `new` is never freed (`delete ptr` is missing), leading to a leak.
🔹 **Fix:** Always use `delete ptr;` after `new`, or use **smart pointers (`std::unique_ptr`)**.

------

#### **2. Dangling Pointer (Use-After-Free)**

A **dangling pointer** is a pointer that refers to memory that has already been freed.

**Example:**

```c++
#include <iostream>

void danglingPointer() {
    int* ptr = new int(5);
    delete ptr; // Memory is freed
    std::cout << "Dangling Pointer: " << *ptr << std::endl; // Undefined behavior!
}

int main() {
    danglingPointer();
    return 0;
}
```

🔹 **Issue:** Accessing `*ptr` after `delete ptr;` causes undefined behavior.
🔹 **Fix:** After `delete`, set `ptr = nullptr;` to prevent accidental access.

**Corrected Version:**

```c++
delete ptr;
ptr = nullptr; // Now, accessing it will be a clear error (nullptr dereference)
```

------

#### **3. Double Deletion (Crash or Undefined Behavior)**

Deleting the same memory twice can lead to crashes.

**Example:**

```c++
#include <iostream>

void doubleDelete() {
    int* ptr = new int(10);
    delete ptr;
    delete ptr; // Undefined behavior (crash)
}

int main() {
    doubleDelete();
    return 0;
}
```

🔹 **Issue:** The second `delete` is trying to free an already freed memory block.
🔹 **Fix:** Set `ptr = nullptr;` after deleting to prevent double deletion.

**Corrected Version:**

```c++
delete ptr;
ptr = nullptr;
```

------

#### **4. Wild Pointer (Uninitialized Pointer)**

A **wild pointer** is an uninitialized pointer that points to an unknown memory location.

**Example:**

```c++
cppCopyEdit#include <iostream>

void wildPointer() {
    int* ptr; // Uninitialized pointer
    *ptr = 10; // Undefined behavior (random memory access)
}

int main() {
    wildPointer();
    return 0;
}
```

🔹 **Issue:** `ptr` is not initialized, so it points to an unknown location, causing a crash or corruption.
🔹 **Fix:** Always initialize pointers with `nullptr` or allocate memory before use.

**Corrected Version:**

```c++
int* ptr = nullptr; // Safe initialization
ptr = new int(10);  // Now it points to valid memory
delete ptr; // Don't forget to free memory
```

-----------------

-------------------

### **What are Smart Pointers?**

Smart pointers are **C++ objects that behave like raw pointers but manage memory automatically**. They ensure proper resource cleanup and prevent common pointer-related issues.

------

### **When Were Smart Pointers Introduced in Modern C++?**

Smart pointers were introduced in **C++11** as part of the `<memory>` standard library. Before C++11, `std::auto_ptr` was available, but it had several limitations and was deprecated in C++17.

------

### **Why Should We Use Smart Pointers Instead of Normal Pointers?**

Smart pointers provide:

1. **Automatic Memory Management** – They free memory automatically when they go out of scope.
2. **Exception Safety** – Memory is safely deallocated even if an exception occurs.
3. **No Memory Leaks** – Ensures that allocated memory is properly freed.
4. **Better Ownership Control** – Defines clear ownership semantics (unique, shared, weak).

------

#### General SmartPtr Impl

```c++
#include <iostream>

template<class T> 
class smartPtr {
    T* ptr;  // Pointer to the object

public:
    // Constructor: Initializes the pointer
    smartPtr(T* p = nullptr) : ptr(p) {}

    // Destructor: Automatically deletes the allocated memory
    ~smartPtr() { delete ptr; }

    // Overloading `*` operator to access the object
    T& operator*() { return *ptr; }

    // Overloading `->` operator to access member functions
    T* operator->() { return ptr; }
};

class Test {
public:
    void show() { std::cout << "Hello from Test!" << std::endl; }
};

int main() {
    // Creating a smart pointer for an integer
    smartPtr<int> sp1(new int(10));
    std::cout << *sp1 << std::endl;  // Output: 10

    // Creating a smart pointer for an object
    smartPtr<Test> sp2(new Test());
    sp2->show();  // Output: Hello from Test!

    return 0;
}

```

-------------

------------

### Types of Smart Pointers

#### 1. Unique Pointer

**`std::unique_ptr` (Exclusive Ownership)**

- Only **one** pointer owns the object at any time.
- **Auto-deletes** the resource when it goes out of scope.
- Prevents **copying** but allows **moving**.

**✅ Key Features**

✔ Cannot be copied (ensures unique ownership).
✔ Can be moved using `std::move()`.
✔ Lightweight and faster than `shared_ptr`.
✔ Automatically deletes the resource when out of scope.

**Example1:**

```c++
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> uniquePtr = std::make_unique<int>(42); // Allocate and initialize with 42

    // Access and use the value
    std::cout << "Value: " << *uniquePtr << std::endl;

    // No need to manually delete; memory is automatically released when uniquePtr goes out of scope
    return 0;
}

```

**🔹 Example2: Creating and Using `unique_ptr`**

```c++
#include <iostream>
#include <memory>  // For smart pointers

class Test {
public:
    Test() { std::cout << "Test created\n"; }
    ~Test() { std::cout << "Test destroyed\n"; }
};

int main() {
    std::unique_ptr<Test> uptr = std::make_unique<Test>();  // ✅ Creates a unique_ptr
    return 0;  // Object is automatically destroyed when `uptr` goes out of scope
}
```

**🔹 Output:**

```c++
Test created
Test destroyed
```

**Member Functions of `std::unique_ptr`**

| Function    | Description                                                  |
| ----------- | ------------------------------------------------------------ |
| `get()`     | Returns the raw pointer.                                     |
| `release()` | Releases ownership and returns the raw pointer (manual delete needed). |
| `reset()`   | Deletes the object and optionally assigns a new one.         |
| `swap()`    | Swaps ownership with another `unique_ptr`.                   |

**🔹 Example3:**

```c++
#include <iostream>
#include <memory>

class Test {
public:
    Test() { std::cout << "Test object created\n"; }
    ~Test() { std::cout << "Test object destroyed\n"; }
    void show() { std::cout << "Test object is active\n"; }
};

int main() {
    std::cout << "== Basic Usage ==\n";
    {
        std::unique_ptr<Test> ptr1 = std::make_unique<Test>();  // ✅ Create unique_ptr
        ptr1->show();
    }  // 🔴 `ptr1` goes out of scope, so Test object is destroyed

    std::cout << "\n== Move Semantics ==\n";
    {
        std::unique_ptr<Test> ptr2 = std::make_unique<Test>();
        std::unique_ptr<Test> ptr3 = std::move(ptr2);  // ✅ Transfer ownership

        if (!ptr2) {
            std::cout << "ptr2 is now null after move\n";
        }
        ptr3->show();
    }  // 🔴 `ptr3` goes out of scope, Test object destroyed

    std::cout << "\n== Resetting unique_ptr ==\n";
    {
        std::unique_ptr<Test> ptr4 = std::make_unique<Test>();
        ptr4.reset(new Test());  // ✅ Old object deleted, new one assigned
    }  // 🔴 New Test object destroyed

    std::cout << "\n== Release Ownership ==\n";
    {
        std::unique_ptr<Test> ptr5 = std::make_unique<Test>();
        Test* rawPtr = ptr5.release();  // ✅ ptr5 releases ownership

        if (!ptr5) {
            std::cout << "ptr5 is now null after release\n";
        }

        delete rawPtr;  // ✅ Must manually delete rawPtr
    }

    // ❌ NOT ALLOWED: Copying a unique_ptr
    // std::unique_ptr<Test> ptr7 = ptr6;  // ERROR: Copying is not allowed

    return 0;
}

```

**🔹 Output:**

```c++
==== Basic Usage ====
Test object created
Test object is active
Test object destroyed

==== Move Semantics ====
Test object created
ptr2 is now null after move
Test object is active
Test object destroyed

==== Resetting unique_ptr ====
Test object created
Test object created
Test object destroyed
Test object destroyed

==== Release Ownership ====
Test object created
ptr5 is now null after release
Test object destroyed

```

--------------

--------------------------------------------

#### 2. Shared Pointer

`std::shared_ptr` is a **smart pointer** that allows **multiple shared ownership** of a dynamically allocated object. Unlike `std::unique_ptr`, `std::shared_ptr` keeps a **reference count**, meaning an object is only deleted when the last `shared_ptr` managing it is destroyed or reset.

------

## **🛠️ `std::shared_ptr` Key Features**

✔ Supports **multiple owners** via **reference counting**.
✔ Automatically deallocates memory when **last owner** is destroyed.
✔ Allows **copying** and **moving** unlike `std::unique_ptr`.
✔ Works well with **circular references** when combined with `std::weak_ptr`.



```c++
#include <iostream>
#include <memory>

class Test {
public:
    Test() { std::cout << "Test object created\n"; }
    ~Test() { std::cout << "Test object destroyed\n"; }
    void show() { std::cout << "Test object is active\n"; }
};

int main() {
    std::cout << "== Basic Shared Ownership ==\n";
    {
        std::shared_ptr<Test> sp1 = std::make_shared<Test>();  // ✅ Shared ownership
        std::shared_ptr<Test> sp2 = sp1;  // ✅ sp2 shares ownership with sp1

        std::cout << "Reference count: " << sp1.use_count() << "\n";  //  Count = 2
    }  // 🔴 sp2 goes out of scope, count = 1

    std::cout << "\n== Resetting Shared Pointer ==\n";
    {
        std::shared_ptr<Test> sp3 = std::make_shared<Test>();
        sp3.reset();  // ✅ Decrements count and destroys object
    }  // 🔴 No references left, object destroyed

    return 0;
}

```

- **Danger Example **

  ```c++
  int* ptr = new int(5);
  std::shared_ptr<int> p(ptr);
  std::shared_ptr<int> p1(ptr); // Dangerous!
  ```

  

----------------

### **Reference Cycle in `std::shared_ptr` (Memory Leak Issue)**

A **reference cycle** happens when two or more `std::shared_ptr` objects own each other, preventing proper deletion and causing a **memory leak**.

**🚨 Problem: Memory Leak Due to Circular Reference**

```c++
#include <iostream>
#include <memory>

class B;  // Forward declaration

class A {
public:
    std::shared_ptr<B> b_ptr;  // A owns B
    A() { std::cout << "A created\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;  // B owns A
    B() { std::cout << "B created\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    {
        std::shared_ptr<A> a = std::make_shared<A>();
        std::shared_ptr<B> b = std::make_shared<B>();

        a->b_ptr = b;  // A owns B
        b->a_ptr = a;  // B owns A (Circular reference)
       
        std::cout << "A: " << a.use_count() << "\n";  
    	std::cout << "B: " << b.use_count() << "\n";  

    } // ⚠️ Memory leak! Objects never destroyed.

    std::cout << "End of main\n";
    return 0;
}
```

**⚠️ Expected Output (Memory Leak)**

```c++
A created
B created
End of main
```

**(But `"A destroyed"` and `"B destroyed"` never appear!)**

📌 **Why?**
Since `std::shared_ptr<A>` and `std::shared_ptr<B>` reference each other, the reference count **never reaches zero**, preventing destruction.

-----------------

#### 3. Weak Pointer

A **weak pointer (`std::weak_ptr`)** is a smart pointer that **does not increase the reference count** of a shared object. It is mainly used to **break reference cycles** that occur with `std::shared_ptr`.

--------------

**🛠 Why Do We Need `std::weak_ptr`?**

When using `std::shared_ptr`, objects can create **cyclic dependencies** (reference cycles), causing **memory leaks** because the reference count never reaches zero.

✅ **Solution:** Use `std::weak_ptr` to refer to an object **without affecting its reference count**.



**📌 How `std::weak_ptr` Works**

- `std::weak_ptr<T>` is **created from a `std::shared_ptr<T>`**.
- **It does not increase the reference count** of the shared object.
- It is used to **check if an object still exists** before using it.
- To access the object, call `.lock()`, which returns a `std::shared_ptr` (if the object is still alive).

------

## **📖 Example 1: Breaking a Reference Cycle**

This example **fixes** the **memory leak** caused by a cyclic dependency.

```c++
#include <iostream>
#include <memory>

class B;  // Forward declaration

class A {
public:
    std::weak_ptr<B> b_ptr;  // ✅ Use weak_ptr to break the cycle
    A() { std::cout << "A created\n"; }
    ~A() { std::cout << "A destroyed\n"; }
};

class B {
public:
    std::shared_ptr<A> a_ptr;
    B() { std::cout << "B created\n"; }
    ~B() { std::cout << "B destroyed\n"; }
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    std::cout << "Reference Count Before Linking:\n";
    std::cout << "A: " << a.use_count() << "\n";  // 🔥 Expect 1
    std::cout << "B: " << b.use_count() << "\n";  // 🔥 Expect 1

    a->b_ptr = b;  // A weakly references B
    b->a_ptr = a;  // B strongly references A

    std::cout << "Reference Count After Linking:\n";
    std::cout << "A: " << a.use_count() << "\n";  // 🔥 Expect 2
    std::cout << "B: " << b.use_count() << "\n";  // 🔥 Expect 1 (No cycle!)

    std::cout << "End of scope...\n";
    return 0;
}  // ✅ No memory leak! Objects are properly destroyed.
```

### **🟢 Expected Output (No Memory Leak)**

```c++
A created
B created
Reference Count Before Linking:
A: 1
B: 1
Reference Count After Linking:
A: 2
B: 1
End of scope...
B destroyed
A destroyed ✅ (Properly cleaned up!)
```

------

## **📖 Example 2: Checking If a `weak_ptr` is Valid**

Since `std::weak_ptr` doesn’t own the object, we must **check if the object still exists** before using it.

```c++
#include <iostream>
#include <memory>

int main() {
    std::weak_ptr<int> wp;

    {
        std::shared_ptr<int> sp = std::make_shared<int>(42);
        wp = sp;  // Assign shared_ptr to weak_ptr

        std::cout << "Inside scope:\n";
        std::cout << "wp.expired(): " << std::boolalpha << wp.expired() << "\n";  //  false

        // Use .lock() to access the object safely
        if (auto sp2 = wp.lock()) {  
            std::cout << "Accessing value: " << *sp2 << "\n";  // 42
        } else {
            std::cout << "Object no longer exists.\n";
        }
    } // `sp` goes out of scope, deleting the object

    std::cout << "\nOutside scope:\n";
    std::cout << "wp.expired(): " << wp.expired() << "\n";  //  true

    // Try locking again
    if (auto sp2 = wp.lock()) {  
        std::cout << "Accessing value: " << *sp2 << "\n";
    } else {
        std::cout << "Object no longer exists.\n";  //  Prevents invalid access
    }

    return 0;
}

```

------------

**🔹 Key Points About `std::weak_ptr`**

✔ **Does not increase reference count** (unlike `std::shared_ptr`).
✔ **Prevents memory leaks** by breaking circular references.
✔ **Must use `.lock()`** to access the object safely.
✔ **`expired()`** checks if the object still exists.

### **❌ What You Cannot Do With `std::weak_ptr`**

1. **Cannot directly access object with `*` or `->`** (must use `.lock()`).
2. **Does not manage object lifetime** (only observes it).

------

## **⚡ Summary**

| Smart Pointer     | Reference Count | Use Case                 |
| ----------------- | --------------- | ------------------------ |
| `std::unique_ptr` | ❌ No ref count  | Sole ownership (fastest) |
| `std::shared_ptr` | ✅ Has ref count | Shared ownership         |
| `std::weak_ptr`   | ❌ No ref count  | Prevents cycles          |

--------------------------------------------------------------------------------------

--------------------

###  **RAII (Resource Acquisition Is Initialization) in C++**

RAII (**Resource Acquisition Is Initialization**) is a fundamental C++ programming principle that **ensures proper resource management** by binding the **lifetime of resources** (like memory, files, sockets, or locks) to the **lifetime of objects**.

------

## **🔍 Why RAII?**

In C (without RAII), resources must be manually released using `free()`, `fclose()`, `delete`, etc.
If the programmer forgets to release them, **memory leaks, dangling pointers, or resource leaks** occur.

C++ solves this problem using **RAII**, where resources are: ✔ **Acquired in a constructor**
✔ **Released in a destructor** automatically

Thus, **no manual cleanup is needed**, preventing leaks!

------

## **📌 RAII in Action: Managing Memory Safely**

In **C (without RAII)**, we manually allocate and free memory:

```c
#include <stdio.h>
#include <stdlib.h>

void badFunction() {
    int* ptr = (int*)malloc(sizeof(int));  //  Memory allocated
    *ptr = 42;
    printf("Value: %d\n", *ptr);
    // ❌ Forgot to free(ptr) → Memory leak!
}

int main() {
    badFunction();
    return 0;
}
```

If `badFunction()` exits early due to an error, `ptr` **never gets freed**, causing a memory leak.

------

### **✅ C++ RAII: Using `std::unique_ptr`**

With RAII in C++, we let **smart pointers** handle memory cleanup automatically.

```c++
#include <iostream>
#include <memory>

void goodFunction() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);  // ✅ Memory managed by unique_ptr
    std::cout << "Value: " << *ptr << "\n";
}  // ✅ `ptr` goes out of scope → Destructor called → Memory freed

int main() {
    goodFunction();  // No memory leaks!
    return 0;
}
```

✔ No `delete` needed!
✔ The memory is freed **automatically** when `ptr` goes out of scope.

------

## **📌 RAII for File Handling**

In **C (without RAII)**:

```c
#include <stdio.h>

void badFileHandling() {
    FILE* file = fopen("data.txt", "r");
    if (!file) return;
    
    // ❌ Forgot to call fclose(file)!
}
```

If an **early return occurs**, `fclose(file)` is **never called**, causing a file resource leak.

------

### **✅ C++ RAII: Using `std::ifstream`**

```c++
#include <iostream>
#include <fstream>

void goodFileHandling() {
    std::ifstream file("data.txt");  // ✅ Open file using RAII
    if (!file) return;  // No need to manually close!

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
}  // ✅ `file` destructor automatically calls `close()`

int main() {
    goodFileHandling();
    return 0;
}
```

✔ **No need to call `close()` manually**.
✔ **If an error occurs, the file still closes properly**.



------

## **✅ Summary: Benefits of RAII**

| **Problem**      | **Without RAII**            | **With RAII**                        |
| ---------------- | --------------------------- | ------------------------------------ |
| Memory leaks     | Manual `malloc/free`        | `std::unique_ptr`, `std::shared_ptr` |
| File leaks       | Manual `fopen/fclose`       | `std::ifstream`, `std::ofstream`     |
| Mutex deadlocks  | Manual `lock/unlock`        | `std::lock_guard`                    |
| Exception safety | Cleanup forgotten on errors | Resources freed automatically        |

----------------------------------------------------------------------------

### Smart Pointers and RAII

Smart pointers are closely related to the RAII (Resource Acquisition Is Initialization) principle. RAII ensures that resources are acquired and released automatically when they go out of scope. Smart pointers, such as `std::unique_ptr` and `std::shared_ptr`, manage dynamic memory automatically, ensuring that memory is released when the smart pointer goes out of scope, aligning perfectly with RAII.

>**RAII (Resource Acquisition Is Initialization)** is a key programming concept in C++ that binds the lifecycle of a resource (like dynamic memory, file handles, mutexes, etc.) to the lifespan of an object. The idea is that resources are acquired (initialized) during object creation and released (cleaned up) when the object goes out of scope, ensuring proper resource management automatically.
>
>### How RAII Works
>
>1. **Resource Acquisition in the Constructor**: When an object is created, the constructor acquires and initializes any resources the object needs. This could involve opening a file, allocating memory, locking a mutex, etc.
>2. **Resource Release in the Destructor**: When the object goes out of scope (e.g., when it is destroyed), the destructor automatically releases the resources. This ensures that resources are freed even if exceptions are thrown or errors occur, reducing the risk of resource leaks.
>
>### RAII Example
>
>Here is a simple RAII implementation using a class that manages dynamic memory:
>
>```c++
>class RAIIExample {
>private:
>   int* data;
>
>public:
>   // Constructor acquires the resource
>   RAIIExample(int size) : data(new int[size]) {
>       std::cout << "Resource acquired." << std::endl;
>   }
>
>   // Destructor releases the resource
>   ~RAIIExample() {
>       delete[] data;
>       std::cout << "Resource released." << std::endl;
>   }
>};
>
>// Usage
>int main() {
>   {
>       RAIIExample example(10); // Resource acquired here
>       // Resource is automatically managed within this scope
>   } // Resource is released automatically here when `example` goes out of scope
>}
>```
>
>### Benefits of RAII
>
>- **Automatic Resource Management**: Resources are managed automatically by the object’s lifecycle, reducing the risk of leaks and errors.
>- **Exception Safety**: Even if an exception is thrown, the destructor is still called, ensuring that resources are properly released.
>- **Simplified Code**: The management of resources is encapsulated, leading to cleaner and more maintainable code.
>
>### RAII and Smart Pointers
>
>Smart pointers like `std::unique_ptr` and `std::shared_ptr` are practical examples of RAII in C++. They automatically acquire memory when initialized and release it when they go out of scope, making memory management safer and easier.
>

### 

----------------------------------------------------
