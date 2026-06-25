> [🇬🇧 View in english](./README.md)

# CPP Scripts Toolkit

Estos scripts se crearon para agilizar la creación de proyectos y clases en C++ siguiendo la estructura típica de 42.

Incluye:
- `newcpp` → genera un proyecto C++ completo.
- `mkclass` → crea automáticamente una clase C++ con forma canónica.
- `install.sh` → instalador que copia los scripts en la carpeta del sistema.

---

## Instalación

Desde la carpeta en la que se encuentra este README, ejecuta:

    sh install.sh

Por defecto, esto hará:
1. Copiar `newcpp` y `mkclass` en `/usr/local/scripts`.
2. Dar permisos de ejecución a ambos scripts.

> ⚠️ El instalador usa `sudo` para escribir en `/usr/local/scripts`, así que puede pedirte la contraseña.

### Añadir `/usr/local/scripts` a tu `PATH` (configuración única)

`/usr/local/scripts` **no** está en tu `PATH` por defecto, así que la shell no encontrará `newcpp` ni `mkclass` si los llamas por su nombre. Para arreglarlo de forma permanente, añade el directorio al archivo de configuración de tu shell:

**zsh** (la opción por defecto en macOS y en la mayoría de equipos de 42):

    echo 'export PATH="$PATH:/usr/local/scripts"' >> ~/.zshrc
    source ~/.zshrc

**bash**:

    echo 'export PATH="$PATH:/usr/local/scripts"' >> ~/.bashrc
    source ~/.bashrc

Verifica que ha funcionado:

    which newcpp
    which mkclass

Ambos comandos deberían imprimir una ruta dentro de `/usr/local/scripts/`.

---

## Uso

### 1. Crear un nuevo proyecto C++

    newcpp NombreProyecto

Estructura generada:

    NombreProyecto/
    ├─ inc/
    │  └─ NombreProyecto.hpp
    ├─ srcs/
    │  └─ main.cpp
    ├─ Makefile

---

### 2. Crear una nueva clase

    mkclass NombreClase

Esto generará:

    inc/NombreClase.hpp
    srcs/NombreClase.cpp

Incluye:
- Constructor y destructor
- Forma canónica completa
- Estructura lista para implementar

---

## Requisitos
- `zsh` o `bash`
- Permiso para escribir en `/usr/local/scripts` (el instalador usa `sudo`)
- Entorno compatible con C++98 (módulos de 42)
