# Mark-and-Sweep Garbage Collector (C)

A custom runtime system implementing:

- Mark phase
- Trace phase
- Sweep phase
- Frame-based root tracking
- Object graph traversal
- Manual VM object tracking

## Features

- Custom VM structure
- Reference stack per frame
- Mark-and-sweep garbage collection
- Support for:
  - Integers
  - Strings
  - Vectors
  - Arrays

## Concepts Demonstrated

- Heap memory management
- Graph traversal (DFS-style marking)
- Handling cyclic references
- Stack frame root tracking
- Object lifetime management

## Build

```bash
gcc src/*.c external/munit/munit.c -Iinclude -o tests
