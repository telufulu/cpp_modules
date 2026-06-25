_This project has been created as part of the 42 curriculum by telufulu_

# C++ Module 06 — C++ Casts (42 Project)

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

C++ Module 06 is a deep dive into **type casting and conversion** in C++. The module explores the different cast operators and, more importantly, **when each one is the correct tool**:

- `static_cast` — well-defined conversions between related types (ex00).
- `reinterpret_cast` — low-level bit reinterpretation between unrelated types, such as a pointer and an integer (ex01).
- `dynamic_cast` — safe, runtime-checked downcasting to discover the real type behind a base-class pointer or reference (ex02).

All exercises are written under the **C++98** standard and avoid `<typeinfo>`, forcing the use of `dynamic_cast` for runtime type identification.

## Installation

This module is split into three independent exercises (`ex00`, `ex01`, `ex02`), each with its **own `Makefile`**.

### Requirements

- Unix-based operating system (Linux or macOS)
- A C++ compiler compatible with C++98 (e.g. `g++` or `clang++`)
- make

Check compiler version:

    c++ --version

### Compilation

From the root of the exercise you want to build, run `make`:

    cd ex00
    make

Each exercise provides the standard 42 rules:

    make        # build the executable
    make clean  # remove object files
    make fclean # remove object files and the executable
    make re     # rebuild from scratch

All exercises are compiled with `-Wall -Wextra -Werror -std=c++98`.

## Usage

Each exercise generates its own executable inside its folder.

**ex00 — Conversion of Scalar Types** (takes one string literal as argument):

    ./ScalarConverter 42.0f
    ./ScalarConverter nan
    ./ScalarConverter 0

Example output:

    ./convert 42.0f
    char: '*'
    int: 42
    float: 42.0f
    double: 42.0

    ./convert nan
    char: impossible
    int: impossible
    float: nanf
    double: nan

**ex01 — Serialization** (no arguments, runs its own round-trip test):

    ./Serializer

**ex02 — Identify Real Type** (no arguments, randomly generates objects and identifies them):

    ./Base

## Features

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *Conversion of Scalar Types* | A non-instantiable `ScalarConverter` class with a single `static convert` method that parses a string literal and converts it to `char`, `int`, `float`, and `double`. Handles pseudo-literals (`nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff`) and non-displayable characters, using `static_cast`. |
| **ex01** | *Serialization* | A non-instantiable `Serializer` class that converts a pointer into a `uintptr_t` integer and back with `reinterpret_cast`, proving that `deserialize(serialize(&data)) == &data` recovers the exact same pointer. |
| **ex02** | *Identify Real Type* | A polymorphic `Base` class with a public virtual destructor and empty derived classes `A`, `B`, `C`. A `generate()` function randomly instantiates one of them, and two `identify()` free functions (pointer and reference versions) detect the real type using `dynamic_cast`, without using `<typeinfo>`. |

---

## Project Structure

    CPP06/
    ├── ex00/
    │   ├── inc/
    │   │   └── ScalarConverter.hpp
    │   ├── srcs/
    │   │   ├── ScalarConverter.cpp
    │   │   └── main.cpp
    │   └── Makefile
    ├── ex01/
    │   ├── inc/
    │   │   └── Serializer.hpp
    │   ├── srcs/
    │   │   ├── Serializer.cpp
    │   │   └── main.cpp
    │   └── Makefile
    ├── ex02/
    │   ├── inc/
    │   │   └── Base.hpp
    │   ├── srcs/
    │   │   ├── Base.cpp
    │   │   └── main.cpp
    │   └── Makefile
    └── README.md

## Known Limitations

- All code targets the **C++98** standard; no C++11 or later features are used.
- The header `<typeinfo>` (and `typeid`) is intentionally **not used**, as required by the subject; runtime type identification relies solely on `dynamic_cast`.
- In ex02, randomness depends on seeding `std::srand()` (e.g. with `std::time(NULL)`); running the program several times within the same second may repeat the sequence.

## Resources

### Official Documentation

- 42 subject — C++ Module 06 (intranet)
- cppreference — `static_cast`, `reinterpret_cast`, `dynamic_cast`: https://en.cppreference.com/w/cpp/language/explicit_cast
- cppreference — `uintptr_t`: https://en.cppreference.com/w/cpp/types/integer
- C++98 standard reference (ISO/IEC 14882:1998).

### README Guidelines

- How to Write a Good README – freeCodeCamp — https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/
- Make a README — https://www.makeareadme.com/


## AI Usage Disclosure

AI tools were used for:

- Conceptual clarification of casting, polymorphism, virtual destructors, and runtime type identification (RTTI).
- Structuring and writing this documentation.

All architecture decisions, implementation logic, and source code were written and reviewed manually.

## Credits

- Lufu's socials
  - [GitHub](https://github.com/telufulu)
  - [LinkedIn](https://www.linkedin.com/in/teresa-b-lufuluabo-pastor-659702204/)


## Academic Integrity Notice

> This repository is published for educational purposes only.
> Submitting this work as your own in academic evaluations constitutes academic misconduct.