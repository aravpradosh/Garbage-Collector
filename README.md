# C Runtime with Mark-and-Sweep Garbage Collector

This project implements a minimal virtual machine and a full mark-and-sweep garbage collector in C.

=======
It demonstrates low-level memory management, object graph traversal, and runtime system design.

---

## Features
>>>>>>> 016c62c (Restructure project into src/include/tests layout and improve README)

- Custom object system
- Frame-based root tracking
- Mark phase
- Trace phase
- Sweep phase

=======
- Supports:
>>>>>>> 016c62c (Restructure project into src/include/tests layout and improve README)
  - Integers
  - Strings
  - Arrays
  - Vector3 objects
- Proper handling of cyclic references
- Memory verified using Valgrind

---

## Concepts Demonstrated

This project showcases understanding of:

- Heap memory management
- Object lifetime tracking
- Root set identification
- Graph traversal (mark phase)
- Recursive tracing of reachable objects
- Safe sweeping of unreachable objects
- Designing a small runtime system in C

---

## Project Structure

src/        → Core runtime implementation  
include/    → Header files  
tests/      → Munit test suite  
external/   → Third-party test library  
Makefile    → Build configuration  

---

## Build

From the project root:

make

---

## Run Tests

./gc_tests

---

## Run with Valgrind (Memory Check)

valgrind --leak-check=full ./gc_tests

You should see:

All heap blocks were freed -- no leaks are possible

---

## Garbage Collection Lifecycle

The garbage collector works in three phases:

1. Mark  
   Objects referenced from active VM frames are marked as reachable.

2. Trace  
   Reachable objects recursively mark any objects they reference (arrays, vectors, etc.).

3. Sweep  
   Unmarked objects are freed from the heap.

This ensures:
- No memory leaks
- Safe cleanup of cyclic references
- Proper object lifetime management

---

## Why This Project Matters

This project demonstrates practical knowledge of:

- Systems programming in C
- Manual memory management
- Runtime architecture
- Garbage collector design
- Debugging memory issues using Valgrind

It reflects understanding of how high-level languages manage memory internally.

---

## Possible Future Improvements

- Generational garbage collection
- Hybrid reference counting model
- Bytecode interpreter
- Full scripting language built on top of this VM
- Performance benchmarking

---

## Author

Arav Pradosh
