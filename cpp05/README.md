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
The goal of this exercise is to introduce the interaction between bureaucrats and forms, modeling the signing process under strict validation rules and controlled error handling through exceptions.
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
The program tests the combined behavior of the Bureaucrat and Form classes. Specifically, it demonstrates that:
- A Form object can only be created with valid grades for signing and execution, following the same constraints as Bureaucrat.
- The core attributes of Form (name and required grades) are constant and cannot be modified after construction.
- A form can only change its state from “unsigned” to “signed” through the explicit action of a Bureaucrat with a sufficient grade.
- If a bureaucrat attempts to sign a form without the required grade, the corresponding exception is thrown.
- The signing logic is centralized in Form::beSigned(), while Bureaucrat::signForm() acts as an intermediary that manages the attempt and reports the result.
- All exceptions derive from std::exception, which allows:
    - Uniform exception handling.
	- Clear error messages to be displayed via what().
- The bidirectional relationship between Bureaucrat and Form is implemented without circular header dependencies, using forward declarations and moving the necessary #include directives to the .cpp files.
- At no point can a form be considered signed unless an explicit grade validation by a bureaucrat has taken place.

The `main` function acts solely as a testing environment: it triggers both valid and invalid scenarios to verify that the internal logic of the class is robust and consistent.

---
### ex02
This exercise focuses on abstract classes, polymorphism, and controlled execution flow using exceptions. The goal is to design a robust hierarchy of forms where:

- The base class defines the rules.
- Concrete classes implement specific behaviors.

Execution is only possible when all constraints are satisfied.

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
Creates different forms, created as childs of an AForm class:

- Checks whether the form is signed.
- Checks whether the bureaucrat has sufficient grade.
- Throws the appropriate exception if a rule is violated.
- Delegates the actual action to a virtual function.

Each concrete form implements only its specific action. This avoids duplicated logic and guarantees that no form can be executed in an invalid state.

The `main` function acts solely as a testing environment: it triggers both valid and invalid scenarios to verify that the internal logic of the class is robust and consistent.

---
### ex03
This exercise introduces the Factory pattern through the Intern class. The goal is to dynamically create different concrete forms based solely on a string identifier, while returning them through a common interface.

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
The program demonstrates that:

- The Intern class is capable of creating different forms using only their name.
- The return type is always a pointer to AForm, regardless of the concrete type created.
- The `main` is responsible for:
    - Using the returned object.
    - Managing its lifetime (delete).

The `main` function acts solely as a testing environment: it triggers both valid and invalid scenarios to verify that the internal logic of the class is robust and consistent.