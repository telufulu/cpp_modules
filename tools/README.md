> [🇪🇸 Ver en español](./README.es.md)

# CPP Scripts Toolkit

These scripts were created to streamline the creation of C++ projects and classes following the typical 42 structure.

Included:
- `newcpp` → generates a full C++ project.
- `mkclass` → automatically creates a canonical-form C++ class.
- `install.sh` → installer that copies the scripts into the system folder.

---

## Installation

From the folder where this README is located, run:

    sh install.sh

By default, this will:
1. Copy `newcpp` and `mkclass` into `/usr/local/scripts`.
2. Assign execution permissions to both scripts.

> ⚠️ The installer uses `sudo` to write into `/usr/local/scripts`, so it may ask for your password.

### Add `/usr/local/scripts` to your `PATH` (one-time setup)

`/usr/local/scripts` is **not** on your `PATH` by default, so the shell will not find `newcpp` or `mkclass` if you call them by name. To fix this permanently, append the directory to your shell's config file:

**zsh** (default on macOS and most 42 setups):

    echo 'export PATH="$PATH:/usr/local/scripts"' >> ~/.zshrc
    source ~/.zshrc

**bash**:

    echo 'export PATH="$PATH:/usr/local/scripts"' >> ~/.bashrc
    source ~/.bashrc

Verify it worked:

    which newcpp
    which mkclass

Both commands should print a path under `/usr/local/scripts/`.

---

## Usage

### 1. Create a new C++ project

    newcpp ProjectName

Generated structure:

    ProjectName/
    ├─ inc/
    │  └─ ProjectName.hpp
    ├─ srcs/
    │  └─ main.cpp
    ├─ Makefile

---

### 2. Create a new class

    mkclass ClassName

This will generate:

    inc/ClassName.hpp
    srcs/ClassName.cpp

Includes:
- Constructor and destructor
- Full canonical form
- Ready-to-implement structure

---

## Requirements
- `zsh` or `bash`
- Permission to write into `/usr/local/scripts` (the installer uses `sudo`)
- C++98-compatible environment (42 modules)
