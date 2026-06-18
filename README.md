> [🇪🇸 Ver en español](./README.es.md)

# 42 C++ Modules

This repository contains all modules from the 42 C++ curriculum.

Each module introduces new object-oriented programming concepts, gradually increasing in complexity — from basic class design to inheritance, polymorphism, memory management and type casting.

### The Goal

Learn C++ step by step following the 42 philosophy: understand memory, encapsulation, inheritance, polymorphism, and clean class design — without relying on external tools or modern libraries.

Each module focuses on one or two specific concepts, reinforcing previous knowledge through practical exercises that must compile with `-std=c++98`.

## Compilation

Each exercise is independent and ships with its **own `README.md` inside its folder**, explaining how to compile and install it. As a general rule, move into the exercise directory and run `make`.

## Usage

Each exercise also documents how it is executed in its **own `README.md`**, including the required arguments and usage examples. Refer to the README inside each exercise folder for the specific details.

## All exercises

### CPP00 — Starting with C++

The goal of this module is to introduce the fundamentals of C++ syntax and object-oriented programming. It covers the creation and use of classes, the concept of encapsulation, and the use of standard input/output streams. The exercises also explore `static` members and their difference from instance attributes, while reinforcing clean and structured program design.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *Megaphone* | A simple program that prints the arguments passed in uppercase letters. Introduces `std::cout` and `argc/argv`. |
| **ex01** | *My Awesome PhoneBook* | Basic use of classes and encapsulation. Builds a small phonebook that stores up to eight contacts, handling input/output via `std::cin` and `std::cout`. |
| **ex02** | *The Account* | Simulation of a banking system introducing `static` attributes and methods, class-wide counters, and formatted output. |

### CPP01 — Memory, Pointers, References, and Heap

The goal of this module is to develop an understanding of how memory management works in C++. It introduces the difference between stack and heap allocation, the use of pointers and references, and the role of constructors and destructors in object lifetime. The exercises also include file manipulation and object composition through relationships between classes.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *The Job of Your Dreams* | Demonstrates the distinction between a pointer and a reference by manipulating the same variable in two different ways. |
| **ex01** | *Zombie* | Defines a `Zombie` class and compares objects created on the stack and on the heap. |
| **ex02** | *Zombie Horde* | Dynamically allocates an array of Zombies using `new[]` and releases memory with `delete[]`. |
| **ex03** | *Weapon, HumanA & HumanB* | Explores composition and the use of references within classes. `HumanA` uses a reference to a `Weapon`, while `HumanB` holds a pointer. |
| **ex04** | *Sed is for losers* | File manipulation exercise that replaces all occurrences of a string with another and writes the output to a new file. |
| **ex05** | *Harl 2.0* | Class that outputs messages corresponding to different log levels (`DEBUG`, `INFO`, `WARNING`, `ERROR`). |

### CPP02 — Canonical Form and Operator Overloading

The goal of this module is to learn how to design robust and reusable C++ classes that follow the Orthodox Canonical Form. It emphasizes proper handling of constructors, destructors, copy constructors, and assignment operators. Operator overloading is also introduced to create intuitive arithmetic and comparison behaviors for user-defined classes.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *My First Class in Orthodox Form* | Implementation of a basic `Fixed` class that follows the Orthodox Canonical Form, including constructors, destructors, and the assignment operator. |
| **ex01** | *Towards a Fixed Point* | Extension of the `Fixed` class to include conversions between integers and floating-point values, and formatted output via `std::cout`. |
| **ex02** | *Now We're Talking Arithmetic* | Adds overloaded operators for arithmetic (`+`, `-`, `*`, `/`), comparison, and increment/decrement. |
| **ex03** | *BSP (Binary Space Partitioning)* | Uses the `Fixed` and `Point` classes to determine whether a point lies inside a triangle, reinforcing precision and const correctness. |

### CPP03 — Inheritance

The goal of this module is to explore inheritance and the organization of class hierarchies in C++. It explains how to reuse functionality from a base class, extend or modify behavior in derived classes, and manage constructor and destructor calls through the inheritance chain. The concept of multiple inheritance is also introduced, including the resolution of ambiguities between parent classes.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *ClapTrap* | Definition of a base class with attributes and methods such as `attack`, `takeDamage`, and `beRepaired`. Establishes the foundation for inheritance. |
| **ex01** | *ScavTrap* | Derived class from `ClapTrap` that introduces a special mode called `guardGate`, demonstrating constructor and destructor chaining. |
| **ex02** | *FragTrap* | Derived class with different attribute values and a new function `highFivesGuys()`. |
| **ex03** | *DiamondTrap* | Example of multiple inheritance combining `ScavTrap` and `FragTrap`, demonstrating ambiguity resolution and constructor order management. |

### CPP04 — Polymorphism, Abstract Classes, and Interfaces

The goal of this module is to master polymorphism and abstraction in C++. It covers virtual functions, virtual destructors, and the implementation of abstract classes that define interfaces. The exercises focus on designing flexible class hierarchies, combining inheritance with composition, and managing resources correctly through deep copies and dynamic binding.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *Polymorphism* | Introduction to virtual functions through a base class `Animal` and derived classes `Dog` and `Cat`. Demonstrates dynamic dispatch. |
| **ex01** | *I don't want to set the world on fire* | Introduction of a `Brain` class as a member of `Dog` and `Cat`, emphasizing composition and proper copy semantics (deep copy). |
| **ex02** | *Abstract Animals* | Conversion of `Animal` into an abstract class (`AAnimal`) with pure virtual functions, illustrating interface-based design. |
| **ex03** | *Materia* | Implementation of a small RPG-inspired system involving `AMateria`, `ICharacter`, `Character`, and `MateriaSource`, applying polymorphism and interface interaction. |

### CPP05 — Repetition and Exceptions

This module introduces the structured handling of exceptions in C++. You will learn to validate states, throw custom errors, and design classes that react correctly to invalid conditions, progressively expanding the architecture created in previous exercises.

| Exercise | Title | Description |
|----------|-------|-------------|
| **ex00** | *Mommy, when I grow up, I want to be a bureaucrat!* | Implementation of the `Bureaucrat` class, with a constant name, strict validation of the grade range (1–150), custom exceptions, and overload of the `<<` operator. |
| **ex01** | *Form up, maggots!* | Creation of the `Form` class, with constant attributes, signature control through `Bureaucrat`, and exceptions when validating grades. Includes overload of the `<<` operator and the `beSigned()` function. |
| **ex02** | *No, you need form 28B, not 28C…* | Conversion of `Form` into the abstract class `AForm`, from which `ShrubberyCreationForm`, `RobotomyRequestForm`, and `PresidentialPardonForm` derive. Adds the execution flow of forms and the validation of permissions before execution. |
| **ex03** | *At least this beats coffee-making* | Implementation of the `Intern` class, capable of dynamically creating forms through `makeForm()`. Unreadable structures are discarded, and a clear method is required to map form names to their corresponding classes. |

## Known Limitations

- All code targets the **C++98** standard; no C++11 or later features are used.
- The repository currently covers modules **CPP00 through CPP07**. Later modules (CPP06–CPP09) are not included yet.
- TODO: list any exercises that are incomplete or were submitted without optional/bonus parts, if applicable.


## Resources

### Official Documentation

- 42 subject PDFs for each C++ module (see the project page on the 42 intranet).
- cppreference — https://en.cppreference.com/
- C++98 standard reference (ISO/IEC 14882:1998).

### README Guidelines

- How to Write a Good README – freeCodeCamp — https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/
- Make a README — https://www.makeareadme.com/

## AI Usage Disclosure

AI tools were used for:

- Conceptual clarification of C++ topics (casting, polymorphism, virtual destructors, RTTI).
- Structuring and writing this documentation.

All architecture decisions, implementation logic, and source code were written and reviewed manually.

## Credits

- Lufu's socials
  - [GitHub](https://github.com/telufulu)
  - [LinkedIn](https://www.linkedin.com/in/teresa-b-lufuluabo-pastor-659702204/)

## Academic Integrity Notice

> This repository is published for educational purposes only.
> Submitting this work as your own in academic evaluations constitutes academic misconduct.