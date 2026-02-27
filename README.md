# C Runtime with Mark-and-Sweep Garbage Collector

This project implements a minimal virtual machine and a full mark-and-sweep garbage collector in C.

## ✨ Features

- Custom object system
- Frame-based root tracking
- Mark phase
- Trace phase
- Sweep phase
- Handles:
  - Integers
  - Strings
  - Arrays
  - Vector3 objects
- Cyclic reference handling

## 🧠 Concepts Demonstrated

- Heap memory management
- Object graph traversal
- Manual VM object tracking
- Root set identification
- Garbage collection lifecycle
- Valgrind memory verification

## 🏗 Project Structure

src/ → Core runtime implementation
include/ → Header files
tests/ → Munit test suite
external/ → Third-party test library
