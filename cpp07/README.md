_This project has been created as part of the 42 curriculum by [telufulu](https://profile.intra.42.fr/users/telufulu)_

# cpp07 (42 Project)

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
- [License](#license)

## Description

`cpp07` is 42's C++ Module 07 focused on **templates**. The objective is to practice writing reusable, type-safe code using function templates and class templates, as well as understanding template compilation constraints (implementations must be visible at compile time, so they commonly live in headers or in included template files such as `.tpp`).

This repository contains:

- `ex00` — basic template utilities (header-only), provided in `Whatever.hpp`
- `ex01` — `iter`: applying a function to each element of an array (template + function pointer / callable)
- `ex02` — `Array`: a small template array class, with implementation in `Array.tpp`

## Installation

### Requirements

- Unix-based operating system (Linux or macOS)
- C++ compiler compatible with **C++98** (e.g., `c++` / `g++`)
- `make`

Check compiler version:

    c++ --version

### Compilation

Each exercise is compiled from its own directory.

Example:

    cd ex00
    make

Available rules (per exercise):

    make clean
    make fclean
    make re

## Usage

Run the program from the exercise folder:

    ./<executable>

Notes:
- The executable name is defined in each exercise `Makefile`.
- Check the `Makefile` (usually the `NAME` variable) if you want the exact binary name.

## Features

- C++98-compatible template implementations
- Exercises split by folders (`ex00`, `ex01`, `ex02`)
- Standard 42 Makefile rules (`make`, `clean`, `fclean`, `re`)
- `ex00`: header-only template utilities in `Whatever.hpp`
- `ex01`: generic iteration helper via templates (`iter.hpp`)
- `ex02`: generic `Array<T>` with template implementation included via `Array.tpp`

## Project Structure

    .
    ├── ex00/
    │   ├── inc/
    │   │   └── Whatever.hpp
    │   ├── srcs/
    │   │   └── main.cpp
    │   └── Makefile
    ├── ex01/
    │   ├── inc/
    │   │   └── iter.hpp
    │   ├── srcs/
    │   │   └── main.cpp
    │   └── Makefile
    ├── ex02/
    │   ├── inc/
    │   │   ├── Array.hpp
    │   │   └── Array.tpp
    │   ├── srcs/
    │   │   └── main.cpp
    │   └── Makefile
    └── README.md

## Known Limitations

- Exact runtime examples depend on each exercise `main.cpp` (the README keeps usage generic to avoid mismatches).
- Template implementations must be visible at compile time; `ex02` addresses this by including `Array.tpp` from the header.

## Resources

### Official Documentation

- C++ templates (cppreference) — https://en.cppreference.com/w/cpp/language/templates
- Function templates — https://en.cppreference.com/w/cpp/language/function_template
- Class templates — https://en.cppreference.com/w/cpp/language/class_template

### README Guidelines

- How to Write a Good README – freeCodeCamp — https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/
- Make a README — https://www.makeareadme.com/
- Choose a license — https://choosealicense.com/

## AI Usage Disclosure

AI tools were used for:

- Structuring the README
- Summarizing the goals of 42 C++ Module 07 (templates)

All architecture decisions, implementation logic, and source code were written and reviewed manually.

## Credits
- [GitHub](https://github.com/telufulu)
- [LinkedIn](https://www.linkedin.com/in/teresa-b-lufuluabo-pastor-659702204/)

## Academic Integrity Notice

> This repository is published for educational purposes only.
> Submitting this work as your own in academic evaluations constitutes academic misconduct.