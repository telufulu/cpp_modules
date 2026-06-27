_This project has been created as part of the 42 curriculum by [telufulu](https://profile.intra.42.fr/users/telufulu)_

# C++ Module 08 — Templated Containers, Iterators, Algorithms (42 Project)

## Table of Contents

- [Description](#description)
- [Installation](#installation)
  - [Requirements](#requirements)
  - [Compilation](#compilation)
- [Usage](#usage)
- [Features](#features)
- [Project Structure](#project-structure)
- [Known Limitations](#known-limitations)
- [Resources](#resources)
- [AI Usage Disclosure](#ai-usage-disclosure)
- [Credits](#credits)
- [Academic Integrity Notice](#academic-integrity-notice)

## Description

C++ Module 08 explores the **Standard Template Library**: generic programming
with templates, STL containers, iterators and algorithms. The goal is to write
type-independent code that works with any standard container and to understand
how iterators expose the contents of a container.

The module is split into three exercises:

- **ex00 — easyfind:** a function template that locates a value inside a container.
- **ex01 — Span:** a class that stores up to N integers and reports the shortest
  and longest distance between them.
- **ex02 — MutantStack:** an iterable `std::stack` built through inheritance.

## Installation

### Requirements

- Unix-based operating system (Linux or macOS)
- A C++ compiler with **C++98** support (`c++` / `g++` / `clang++`)
- `make`

Check your compiler version:

    c++ --version

### Compilation

Each exercise is independent and compiled from its own folder. From the chosen
exercise directory:

    make

Standard 42 rules are available:

    make clean
    make fclean
    make re

## Usage

Each exercise contains its own `main.cpp` with the test cases (no command-line
arguments are required). Run the generated binary from the exercise folder:

    cd ex00 && make && ./easyfind
    cd ex01 && make && ./Span <optional_number>
    cd ex02 && make && ./Mutantstack

For **ex02**, the exercise is validated by running the test once with
`MutantStack<int>` and once replacing it with `std::list<int>` (adapting
`push`→`push_back`, `pop`→`pop_back`, `top`→`back`). Both outputs must be
identical:

    ./mutantstack > out_mutant.txt
    # swap MutantStack for std::list, recompile
    ./mutantstack > out_list.txt
    diff out_mutant.txt out_list.txt   # no output means success

## Features

**ex00 — easyfind**
- Header-only function template (`easyfind.hpp`) that returns an iterator to the
  first occurrence of a value.
- Works with any STL container of integers.
- Throws an exception when the value is not found.
- TODO: confirm exact signature and exception type from the code.

**ex01 — Span**
- Stores a maximum of N integers, fixed at construction.
- `addNumber()` throws when the container is full.
- `shortestSpan()` / `longestSpan()` return the min/max distance between values.
- Both throw when fewer than two numbers are stored.

**ex02 — MutantStack**
- Inherits publicly from `std::stack<T>` and exposes its internal container's
  iterators via `begin()` / `end()`.
- Iterator type borrowed with
  `typedef typename std::stack<T>::container_type::iterator iterator;`.
- Orthodox Canonical Form implemented.

## Project Structure

    cpp08/
    ├── ex00/
    │   ├── inc/
    │   │   └── easyfind.hpp
    │   ├── srcs/
    │   │   └── main.cpp
    │   └── Makefile
    ├── ex01/
    │   ├── inc/
    │   │   └── Span.hpp
    │   ├── srcs/
    │   │   ├── main.cpp
    │   │   └── Span.cpp
    │   └── Makefile
    ├── ex02/
    │   ├── inc/
    │   │   ├── MutantStack.hpp
    │   │   └── MutantStack.tpp
    │   ├── srcs/
    │   │   └── main.cpp
    │   └── Makefile
    └── README.md

## Known Limitations

- None

## Resources

### Official Documentation

- std::stack — https://en.cppreference.com/w/cpp/container/stack
- std::list — https://en.cppreference.com/w/cpp/container/list
- Iterators — https://en.cppreference.com/w/cpp/iterator
- 42 subject (CPP Module 08) — provided on the 42 intranet

### README Guidelines

- How to Write a Good README – freeCodeCamp — https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/
- Make a README — https://www.makeareadme.com/
- Choose a license — https://choosealicense.com/

## AI Usage Disclosure

AI tools were used for:

- Conceptual clarification (templates, iterators, inheritance from container adapters).
- Structuring this documentation.

All architecture decisions, implementation logic, and source code were written
and reviewed manually.

## Credits
- [GitHub](https://github.com/telufulu)
- [LinkedIn](https://www.linkedin.com/in/teresa-b-lufuluabo-pastor-659702204/)

---
---
#### Academic Integrity Notice

> This repository is published for educational purposes only.
> Submitting this work as your own in academic evaluations constitutes academic misconduct.