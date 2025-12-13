> [🇪🇸 Ver en español](./README.es.md)

# CPP05
The goal of this C++ module is primarily to understand how exceptions work in C++ and how classes that contain exceptions communicate with each other.
It also reinforces the understanding of how to create an Orthodox Canonical Form Class and forces you to approach class design correctly by introducing constraints through constant member variables.

## What each exercise does?
### ex00
The goal is to represent a Bureaucrat whose grade is always valid.
>#### **Compilation and execution**
From de root of the project:
``` bash
make
```
To exec:
``` bash
./Bureaucrat
```
>#### **Behaviour of the program**
The behavior of the Bureaucrat class is put to the test. Specifically, the program demonstrates that:

- A Bureaucrat object can only be created with a grade within the allowed limits.
- If an attempt is made to create a bureaucrat with a grade that is too high or too low, the class throws the corresponding exception.
- The operations that modify the grade:
    - Respect the defined limits.
    - Throw exceptions when an operation attempts to exceed those limits.
- The exceptions derive from std::exception, which allows:
    - Uniform exception handling.
    - Clear error messages to be displayed using what().
- The class prevents an object from ever existing in an invalid state.

The `main` function acts solely as a testing environment: it triggers both valid and invalid scenarios to verify that the internal logic of the class is robust and consistent.

---
### ex01

---
### ex02

---
### ex03

