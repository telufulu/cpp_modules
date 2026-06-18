> [🇬🇧 See in english](./README.md)

# Módulos de C++ de 42

Este repositorio contiene todos los módulos del currículo de C++ de 42.

Cada módulo introduce nuevos conceptos de programación orientada a objetos, aumentando gradualmente en complejidad — desde el diseño básico de clases hasta la herencia, el polimorfismo, la gestión de memoria y el casting de tipos.

### El objetivo

Aprender C++ paso a paso siguiendo la filosofía de 42: entender la memoria, la encapsulación, la herencia, el polimorfismo y el diseño limpio de clases — sin depender de herramientas externas ni de bibliotecas modernas.

Cada módulo se centra en uno o dos conceptos específicos, reforzando los conocimientos previos mediante ejercicios prácticos que deben compilar con `-std=c++98`.

## Compilación

Cada ejercicio es independiente e incluye su **propio `README.md` dentro de su carpeta**, donde se explica cómo compilarlo e instalarlo. Como regla general, entra en el directorio del ejercicio y ejecuta `make`.

## Uso

Cada ejercicio documenta también cómo se ejecuta en su **propio `README.md`**, incluyendo los argumentos necesarios y ejemplos de uso. Consulta el README dentro de la carpeta de cada ejercicio para los detalles concretos.

## Todos los ejercicios

### CPP00 — Empezando con C++

El objetivo de este módulo es introducir los fundamentos de la sintaxis de C++ y la programación orientada a objetos. Cubre la creación y el uso de clases, el concepto de encapsulación y el uso de los flujos estándar de entrada/salida. Los ejercicios también exploran los miembros `static` y su diferencia con los atributos de instancia, reforzando un diseño de programa limpio y estructurado.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *Megaphone* | Un programa sencillo que imprime en mayúsculas los argumentos recibidos. Introduce `std::cout` y `argc/argv`. |
| **ex01** | *My Awesome PhoneBook* | Uso básico de clases y encapsulación. Construye una pequeña agenda que almacena hasta ocho contactos, gestionando la entrada/salida mediante `std::cin` y `std::cout`. |
| **ex02** | *The Account* | Simulación de un sistema bancario que introduce atributos y métodos `static`, contadores a nivel de clase y salida con formato. |

### CPP01 — Memoria, punteros, referencias y heap

El objetivo de este módulo es entender cómo funciona la gestión de memoria en C++. Introduce la diferencia entre la asignación en la pila (stack) y en el montón (heap), el uso de punteros y referencias, y el papel de los constructores y destructores en el ciclo de vida de un objeto. Los ejercicios incluyen también manipulación de ficheros y composición de objetos mediante relaciones entre clases.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *The Job of Your Dreams* | Muestra la distinción entre un puntero y una referencia manipulando la misma variable de dos formas distintas. |
| **ex01** | *Zombie* | Define una clase `Zombie` y compara objetos creados en la pila y en el montón. |
| **ex02** | *Zombie Horde* | Reserva dinámicamente un array de Zombies usando `new[]` y libera la memoria con `delete[]`. |
| **ex03** | *Weapon, HumanA & HumanB* | Explora la composición y el uso de referencias dentro de las clases. `HumanA` usa una referencia a un `Weapon`, mientras que `HumanB` guarda un puntero. |
| **ex04** | *Sed is for losers* | Ejercicio de manipulación de ficheros que reemplaza todas las apariciones de una cadena por otra y escribe el resultado en un nuevo fichero. |
| **ex05** | *Harl 2.0* | Clase que muestra mensajes correspondientes a distintos niveles de log (`DEBUG`, `INFO`, `WARNING`, `ERROR`). |

### CPP02 — Forma canónica y sobrecarga de operadores

El objetivo de este módulo es aprender a diseñar clases de C++ robustas y reutilizables que siguen la Forma Canónica Ortodoxa. Hace hincapié en el manejo correcto de constructores, destructores, constructores de copia y operadores de asignación. También se introduce la sobrecarga de operadores para crear comportamientos aritméticos y de comparación intuitivos en clases propias.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *My First Class in Orthodox Form* | Implementación de una clase `Fixed` básica que sigue la Forma Canónica Ortodoxa, incluyendo constructores, destructor y el operador de asignación. |
| **ex01** | *Towards a Fixed Point* | Extensión de la clase `Fixed` para incluir conversiones entre enteros y valores en coma flotante, y salida con formato mediante `std::cout`. |
| **ex02** | *Now We're Talking Arithmetic* | Añade operadores sobrecargados para aritmética (`+`, `-`, `*`, `/`), comparación e incremento/decremento. |
| **ex03** | *BSP (Binary Space Partitioning)* | Usa las clases `Fixed` y `Point` para determinar si un punto está dentro de un triángulo, reforzando la precisión y la corrección const (const correctness). |

### CPP03 — Herencia

El objetivo de este módulo es explorar la herencia y la organización de jerarquías de clases en C++. Explica cómo reutilizar la funcionalidad de una clase base, extender o modificar el comportamiento en clases derivadas, y gestionar las llamadas a constructores y destructores a lo largo de la cadena de herencia. También se introduce el concepto de herencia múltiple, incluida la resolución de ambigüedades entre clases padre.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *ClapTrap* | Definición de una clase base con atributos y métodos como `attack`, `takeDamage` y `beRepaired`. Establece la base para la herencia. |
| **ex01** | *ScavTrap* | Clase derivada de `ClapTrap` que introduce un modo especial llamado `guardGate`, demostrando el encadenamiento de constructores y destructores. |
| **ex02** | *FragTrap* | Clase derivada con valores de atributos distintos y una nueva función `highFivesGuys()`. |
| **ex03** | *DiamondTrap* | Ejemplo de herencia múltiple que combina `ScavTrap` y `FragTrap`, demostrando la resolución de ambigüedades y la gestión del orden de los constructores. |

### CPP04 — Polimorfismo, clases abstractas e interfaces

El objetivo de este módulo es dominar el polimorfismo y la abstracción en C++. Cubre las funciones virtuales, los destructores virtuales y la implementación de clases abstractas que definen interfaces. Los ejercicios se centran en diseñar jerarquías de clases flexibles, combinando herencia con composición, y gestionando correctamente los recursos mediante copias profundas (deep copy) y enlace dinámico (dynamic binding).

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *Polymorphism* | Introducción a las funciones virtuales mediante una clase base `Animal` y las clases derivadas `Dog` y `Cat`. Demuestra el despacho dinámico (dynamic dispatch). |
| **ex01** | *I don't want to set the world on fire* | Introducción de una clase `Brain` como miembro de `Dog` y `Cat`, haciendo hincapié en la composición y en una semántica de copia correcta (copia profunda). |
| **ex02** | *Abstract Animals* | Conversión de `Animal` en una clase abstracta (`AAnimal`) con funciones virtuales puras, ilustrando el diseño basado en interfaces. |
| **ex03** | *Materia* | Implementación de un pequeño sistema inspirado en los RPG que involucra `AMateria`, `ICharacter`, `Character` y `MateriaSource`, aplicando polimorfismo e interacción entre interfaces. |

### CPP05 — Repetición y excepciones

Este módulo introduce el manejo estructurado de excepciones en C++. Aprenderás a validar estados, lanzar errores personalizados y diseñar clases que reaccionan correctamente ante condiciones inválidas, ampliando progresivamente la arquitectura creada en ejercicios anteriores.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *Mommy, when I grow up, I want to be a bureaucrat!* | Implementación de la clase `Bureaucrat`, con un nombre constante, validación estricta del rango de grado (1–150), excepciones personalizadas y sobrecarga del operador `<<`. |
| **ex01** | *Form up, maggots!* | Creación de la clase `Form`, con atributos constantes, control de firma a través de `Bureaucrat` y excepciones al validar los grados. Incluye la sobrecarga del operador `<<` y la función `beSigned()`. |
| **ex02** | *No, you need form 28B, not 28C…* | Conversión de `Form` en la clase abstracta `AForm`, de la que derivan `ShrubberyCreationForm`, `RobotomyRequestForm` y `PresidentialPardonForm`. Añade el flujo de ejecución de los formularios y la validación de permisos antes de ejecutarlos. |
| **ex03** | *At least this beats coffee-making* | Implementación de la clase `Intern`, capaz de crear formularios dinámicamente mediante `makeForm()`. Las estructuras ilegibles se descartan, y se requiere un método claro para mapear los nombres de los formularios con sus clases correspondientes. |

### CPP06 — Casting y conversión de tipos

El objetivo de este módulo es entender los distintos operadores de cast en C++ y cuándo cada uno es la herramienta adecuada. Cubre la conversión de representaciones en cadena a tipos escalares, la serialización de un puntero a un entero y su recuperación, y la identificación del tipo real detrás de un puntero o referencia a la clase base en tiempo de ejecución. Los ejercicios refuerzan la diferencia entre `static_cast`, `reinterpret_cast` y `dynamic_cast`, siempre bajo el estándar `-std=c++98` y sin recurrir a `<typeinfo>`.

| Ejercicio | Título | Descripción |
|-----------|--------|-------------|
| **ex00** | *Conversion of Scalar Types* | Una clase `ScalarConverter` no instanciable que expone un único método `static convert` que parsea un literal en cadena y lo convierte a `char`, `int`, `float` y `double`. Gestiona los pseudo-literales especiales (`nan`, `+inf`, `-inf`, `nanf`, `+inff`, `-inff`) y los caracteres no imprimibles, usando `static_cast`. |
| **ex01** | *Serialization* | Una clase `Serializer` no instanciable que convierte un puntero en un entero `uintptr_t` y de vuelta usando `reinterpret_cast`, demostrando que `deserialize(serialize(&data)) == &data` recupera exactamente el mismo puntero. |
| **ex02** | *Identify Real Type* | Una clase `Base` polimórfica con un destructor virtual público y clases derivadas vacías `A`, `B`, `C`. Una función `generate()` instancia una de ellas al azar, y las funciones `identify()` (versiones de puntero y de referencia) detectan el tipo real usando `dynamic_cast`, sin usar `<typeinfo>`. |

## Limitaciones conocidas

- Todo el código está dirigido al estándar **C++98**; no se usan características de C++11 ni posteriores.
- El repositorio cubre actualmente los módulos **CPP00 a CPP06**. Los módulos posteriores (CPP07–CPP09) aún no están incluidos.
- TODO: enumera los ejercicios que estén incompletos o que se hayan entregado sin las partes opcionales/bonus, si aplica.

## Recursos

### Documentación oficial

- PDFs del subject de cada módulo de C++ (ver la página del proyecto en la intranet de 42).
- cppreference — https://en.cppreference.com/
- Referencia del estándar C++98 (ISO/IEC 14882:1998).

### Guías de README

- How to Write a Good README – freeCodeCamp — https://www.freecodecamp.org/news/how-to-write-a-good-readme-file/
- Make a README — https://www.makeareadme.com/

## Declaración de uso de IA

Se han usado herramientas de IA para:

- Aclaración conceptual de temas de C++ (casting, polimorfismo, destructores virtuales, RTTI).
- Estructurar y redactar esta documentación.

Todas las decisiones de arquitectura, la lógica de implementación y el código fuente se han escrito y revisado manualmente.

## Créditos

- Redes de Lufu
  - [GitHub](https://github.com/telufulu)
  - [LinkedIn](https://www.linkedin.com/in/teresa-b-lufuluabo-pastor-659702204/)

## Aviso de integridad académica

> *Este repositorio se publica únicamente con fines educativos.*
> *Entregar este trabajo como propio en evaluaciones académicas constituye una falta de integridad académica.*