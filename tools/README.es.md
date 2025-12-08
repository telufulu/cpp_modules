> [🇬🇧 See in english](./README.md)

# CPP Scripts Toolkit

Estos scripts se han creado para agilizar la creación de proyectos y clases en C++ siguiendo la estructura típica de 42.

Incluye:

* `newcpp` → creación de proyectos C++.
* `mkclass` → generación automática de clases en formato canónico.
* `install.sh` → instalador que configura todo el entorno.

---

## Instalación

Desde la carpeta donde está este README ejecuta:

```bash
sh install.sh
```
o
```zsh
zsh install.sh
```

Por defecto, esto realizará:

1. Copia de `newcpp` y `mkclass` a `~/.scripts/`.
2. Asignación de permisos de ejecución.
3. Creación de alias en `~/.zshrc` o `~/.bashrc`.
4. Activación de los comandos:

```
newcpp
mkclass
```

Para recargar la shell:

```bash
source ~/.zshrc
```

---

## Uso

### **1. Crear un nuevo proyecto C++**

```bash
newcpp NombreProyecto
```

Estructura generada:

```
NombreProyecto/
 ├─ inc/
 │   └─ NombreProyecto.hpp
 ├─ srcs/
 │   └─ main.cpp
 ├─ Makefile
```

---

### **2. Crear una nueva clase**

```bash
mkclass NombreClase
```

Se generarán:

```
inc/NombreClase.hpp
srcs/NombreClase.cpp
```

Incluye:

* Constructor y destructor
* Forma canónica completa
* Estructura lista para implementar

---

## Requisitos

* zsh o bash
* Permisos para crear ~/.scripts
* Entorno compatible con C++98 (módulos 42)
