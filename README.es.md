> [🇬🇧 See in english](./README.md)

# Módulos de C++ – 42 School  

Este repositorio contiene todos los módulos de C++ de 42.  
Cada módulo introduce nuevos conceptos de programación orientada a objetos, aumentando progresivamente en dificultad — desde el diseño básico de clases hasta la herencia, el polimorfismo y la gestión de memoria.  

### El objetivo  

Aprender C++ paso a paso siguiendo la filosofía de 42:  
comprender la memoria, la encapsulación, la herencia, el polimorfismo y el diseño limpio de clases, sin depender de librerías externas ni versiones modernas del lenguaje.  

Cada módulo se centra en uno o dos conceptos concretos y refuerza los anteriores mediante ejercicios prácticos que deben compilar con `-std=c++98`.

---

## CPP00 — Primeros pasos con C++

El objetivo de este módulo es introducir los fundamentos de la sintaxis de C++ y la programación orientada a objetos.  
Se abordan la creación y uso de clases, el concepto de encapsulación y el manejo de los flujos estándar de entrada y salida.  
Los ejercicios también exploran los miembros `static` y su diferencia respecto a los atributos de instancia, reforzando el diseño estructurado y limpio de los programas.

| Ejercicio | Título | Descripción |
|------------|---------|-------------|
| **ex00** | *Megaphone* | Programa simple que imprime los argumentos pasados en letras mayúsculas. Introduce `std::cout` y `argc/argv`. |
| **ex01** | *My Awesome PhoneBook* | Primer uso práctico de clases y encapsulación. Implementa una agenda que puede almacenar hasta ocho contactos, gestionando la entrada y salida con `std::cin` y `std::cout`. |
| **ex02** | *The Account* | Simulación de un sistema bancario que introduce atributos y métodos `static`, contadores de clase y salida formateada. |

---

## CPP01 — Memoria, punteros, referencias y heap

El objetivo de este módulo es comprender cómo funciona la gestión de memoria en C++.  
Se introduce la diferencia entre asignación en el stack y en el heap, el uso de punteros y referencias, y el papel de los constructores y destructores en el ciclo de vida de los objetos.  
Los ejercicios también incluyen manipulación de archivos y composición de objetos mediante relaciones entre clases.

| Ejercicio | Título | Descripción |
|------------|---------|-------------|
| **ex00** | *The Job of Your Dreams* | Demuestra la diferencia entre puntero y referencia manipulando una misma variable de dos formas distintas. |
| **ex01** | *Zombie* | Define una clase `Zombie` y compara objetos creados en el stack y en el heap. |
| **ex02** | *Zombie Horde* | Reserva dinámicamente un array de Zombies con `new[]` y libera la memoria con `delete[]`. |
| **ex03** | *Weapon, HumanA & HumanB* | Explora la composición y el uso de referencias en clases. `HumanA` utiliza una referencia a un `Weapon`, mientras que `HumanB` mantiene un puntero. |
| **ex04** | *Sed is for losers* | Ejercicio de manipulación de archivos que reemplaza todas las apariciones de una cadena por otra y escribe el resultado en un nuevo archivo. |
| **ex05** | *Harl 2.0* | Clase que muestra mensajes correspondientes a distintos niveles de registro (`DEBUG`, `INFO`, `WARNING`, `ERROR`). |

---

## CPP02 — Forma canónica y sobrecarga de operadores

El objetivo de este módulo es aprender a diseñar clases robustas y reutilizables en C++ siguiendo la Forma Canónica Ortodoxa.  
Se trabaja el manejo correcto de constructores, destructores, constructores de copia y operadores de asignación.  
También se introduce la sobrecarga de operadores para crear comportamientos aritméticos y de comparación intuitivos en clases definidas por el usuario.

| Ejercicio | Título | Descripción |
|------------|---------|-------------|
| **ex00** | *My First Class in Orthodox Form* | Implementación de una clase básica `Fixed` que sigue la Forma Canónica Ortodoxa, incluyendo constructores, destructores y operador de asignación. |
| **ex01** | *Towards a Fixed Point* | Extensión de la clase `Fixed` para incluir conversiones entre enteros y números en coma flotante, y salida formateada con `std::cout`. |
| **ex02** | *Now We’re Talking Arithmetic* | Añade sobrecarga de operadores aritméticos (`+`, `-`, `*`, `/`), de comparación y de incremento/decremento. |
| **ex03** | *BSP (Binary Space Partitioning)* | Utiliza las clases `Fixed` y `Point` para determinar si un punto se encuentra dentro de un triángulo, reforzando la precisión y el uso correcto de `const`. |

---

## CPP03 — Herencia

El objetivo de este módulo es explorar la herencia y la organización jerárquica de clases en C++.  
Se explica cómo reutilizar funcionalidad de una clase base, extender o modificar su comportamiento en clases derivadas y gestionar correctamente las llamadas a constructores y destructores dentro de la cadena de herencia.  
También se introduce la herencia múltiple y la resolución de ambigüedades entre clases padre.

| Ejercicio | Título | Descripción |
|------------|---------|-------------|
| **ex00** | *ClapTrap* | Definición de una clase base con atributos y métodos como `attack`, `takeDamage` y `beRepaired`. Establece la base de la herencia. |
| **ex01** | *ScavTrap* | Clase derivada de `ClapTrap` que introduce un modo especial llamado `guardGate`, demostrando la llamada en cadena a constructores y destructores. |
| **ex02** | *FragTrap* | Clase derivada con diferentes valores de atributos y una nueva función `highFivesGuys()`. |
| **ex03** | *DiamondTrap* | Ejemplo de herencia múltiple que combina `ScavTrap` y `FragTrap`, mostrando la resolución de ambigüedades y el orden correcto de construcción. |

---


## CPP04 — Polimorfismo, clases abstractas e interfaces

El objetivo de este módulo es dominar el polimorfismo y la abstracción en C++.  
Se trabajan las funciones virtuales, los destructores virtuales y la implementación de clases abstractas que definen interfaces.  
Los ejercicios se centran en diseñar jerarquías de clases flexibles, combinando herencia con composición, y en gestionar correctamente los recursos mediante copias profundas y enlace dinámico.

| Ejercicio | Título | Descripción |
|------------|---------|-------------|
| **ex00** | *Polymorphism* | Introducción a las funciones virtuales mediante una clase base `Animal` y clases derivadas `Dog` y `Cat`. Demuestra el despacho dinámico. |
| **ex01** | *I don’t want to set the world on fire* | Introducción de una clase `Brain` como miembro de `Dog` y `Cat`, destacando la composición y la importancia de las copias profundas. |
| **ex02** | *Abstract Animals* | Conversión de `Animal` en una clase abstracta (`AAnimal`) con funciones virtuales puras, ilustrando el diseño basado en interfaces. |
| **ex03** | *Materia* | Implementación de un pequeño sistema inspirado en los RPG, con `AMateria`, `ICharacter`, `Character` y `MateriaSource`, aplicando polimorfismo e interacción entre interfaces. |

---
