> [🇪🇸 Ver en español](./README.es.md)

# 42 C++ Modules  

This repository contains all my projects from the 42 C++ curriculum.  
Each module introduces new object-oriented programming concepts, gradually increasing in complexity — from basic class design to inheritance, polymorphism and memory management.  

### The Goal

Learn C++ step by step following the 42 philosophy:  
understand memory, encapsulation, inheritance, polymorphism, and clean class design — without relying on external tools or modern libraries.  

Each module focuses on one or two specific concepts, reinforcing previous knowledge through practical exercises that must compile with `-std=c++98`.

---

## CPP00 — Starting with C++

The goal of this module is to introduce the fundamentals of C++ syntax and object-oriented programming.  
It covers the creation and use of classes, the concept of encapsulation, and the use of standard input/output streams.  
The exercises also explore `static` members and their difference from instance attributes, while reinforcing clean and structured program design.

| Exercise | Title | Description |
|-----------|--------|-------------|
| **ex00** | *Megaphone* | A simple program that prints the arguments passed in uppercase letters. Introduces `std::cout` and `argc/argv`. |
| **ex01** | *My Awesome PhoneBook* | Basic use of classes and encapsulation. Builds a small phonebook that stores up to eight contacts, handling input/output via `std::cin` and `std::cout`. |
| **ex02** | *The Account* | Simulation of a banking system introducing `static` attributes and methods, class-wide counters, and formatted output. |

---

## CPP01 — Memory, Pointers, References, and Heap

The goal of this module is to develop an understanding of how memory management works in C++.  
It introduces the difference between stack and heap allocation, the use of pointers and references, and the role of constructors and destructors in object lifetime.  
The exercises also include file manipulation and object composition through relationships between classes.

| Exercise | Title | Description |
|-----------|--------|-------------|
| **ex00** | *The Job of Your Dreams* | Demonstrates the distinction between a pointer and a reference by manipulating the same variable in two different ways. |
| **ex01** | *Zombie* | Defines a `Zombie` class and compares objects created on the stack and on the heap. |
| **ex02** | *Zombie Horde* | Dynamically allocates an array of Zombies using `new[]` and releases memory with `delete[]`. |
| **ex03** | *Weapon, HumanA & HumanB* | Explores composition and the use of references within classes. `HumanA` uses a reference to a `Weapon`, while `HumanB` holds a pointer. |
| **ex04** | *Sed is for losers* | File manipulation exercise that replaces all occurrences of a string with another and writes the output to a new file. |
| **ex05** | *Harl 2.0* | Class that outputs messages corresponding to different log levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`). |

---

## CPP02 — Canonical Form and Operator Overloading

The goal of this module is to learn how to design robust and reusable C++ classes that follow the Orthodox Canonical Form.  
It emphasizes proper handling of constructors, destructors, copy constructors, and assignment operators.  
Operator overloading is also introduced to create intuitive arithmetic and comparison behaviors for user-defined classes.

| Exercise | Title | Description |
|-----------|--------|-------------|
| **ex00** | *My First Class in Orthodox Form* | Implementation of a basic `Fixed` class that follows the Orthodox Canonical Form, including constructors, destructors, and the assignment operator. |
| **ex01** | *Towards a Fixed Point* | Extension of the `Fixed` class to include conversions between integers and floating-point values, and formatted output via `std::cout`. |
| **ex02** | *Now We’re Talking Arithmetic* | Adds overloaded operators for arithmetic (`+`, `-`, `*`, `/`), comparison, and increment/decrement. |
| **ex03** | *BSP (Binary Space Partitioning)* | Uses the `Fixed` and `Point` classes to determine whether a point lies inside a triangle, reinforcing precision and const correctness. |

---
