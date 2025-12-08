> [🇪🇸 Ver en español](./README.es.md)

# CPP Scripts Toolkit

These scripts were created to streamline the creation of C++ projects and classes following the typical 42 structure.

Included:
- newcpp → generates a full C++ project.
- mkclass → automatically creates a canonical-form C++ class.
- install.sh → installer that sets up the environment.

---

## Installation

From the folder where this README is located, run:

```bash
sh install.sh
```
or
```zsh
zsh install.sh
```

By default, this will:
1. Copy `newcpp` and `mkclass` into `~/.scripts/`.
2. Assign execution permissions.
3. Create the necessary aliases in `~/.zshrc` or `~/.bashrc`.
4. Enable the commands:

```
newcpp
mkclass
```

To reload your shell:

```bash
source ~/.zshrc
```

---

## Usage

### **1. Create a new C++ project**

```bash
newcpp ProjectName
```

Generated structure:

```
ProjectName/
 ├─ inc/
 │   └─ ProjectName.hpp
 ├─ srcs/
 │   └─ main.cpp
 ├─ Makefile
```

---

### **2. Create a new class**

```bash
mkclass ClassName
```

This will generate:

```
inc/ClassName.hpp
srcs/ClassName.cpp
```

Includes:
- Constructor and destructor
- Full canonical form
- Ready-to-implement structure

---

## Requirements
	•	zsh or bash
	•	Permission to create ~/.scripts
	•	C++98-compatible environment (42 modules)
