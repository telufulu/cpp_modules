> [🇬🇧 See in english](./README.md)

# CPP05
El objetivo de este módulo de C++ es principalmente comprender cómo funcionan las excepciones en C++ y la comunicación entre clases que contienen excepciones.
Además, se refuerza la comprensión sobre como hacer una *Orthodox Canonical Form Class* y se obliga a plantear desde un buen diseño de una clase al poner limitaciones con variables de tipo constante.

## ¿Qué hace cada ejercicio?
### ex00
El objetivo es representar un burócrata con un grado siempre válido.
>#### Compilación y ejecución
Desde la raíz del ejercicio:
``` bash
make
```
Para ejecutarlo:
``` bash
./Bureaucrat
```
>#### **Comportamiento del programa**
Se pone a prueba el comportamiento de la clase Bureaucrat. En concreto, el programa demuestra que:

- Un objeto Bureaucrat solo puede crearse con un grado dentro de los límites permitidos.
- Si se intenta crear un burócrata con un grado demasiado alto o demasiado bajo, la clase lanza la excepción correspondiente.
- Las operaciones que modifican el grado:
    - Respetan los límites establecidos.
    - Lanzán excepciones cuando una operación intenta sobrepasar dichos límites.
- Las excepciones derivan de std::exception, lo que permite:
    - Capturarlas de forma uniforme.
    - Mostrar mensajes de error claros mediante what().
- La clase impide en todo momento que un objeto exista en un estado inválido.

El `main` actúa únicamente como entorno de prueba: provoca tanto casos válidos como inválidos para verificar que la lógica interna de la clase es robusta y coherente.

---
### ex01
El objetivo es introducir la interacción entre burócratas y formularios, modelando el proceso de firma bajo reglas estrictas de validación y control de errores mediante excepciones.
>#### Compilación y ejecución
Desde la raíz del ejercicio:
``` bash
make
```
Para ejecutarlo:
``` bash
./Bureaucrat
```
>#### **Comportamiento del programa**
Se pone a prueba el comportamiento conjunto de las clases Bureaucrat y Form. En concreto, el programa demuestra que:
- Un objeto Form solo puede crearse con grados válidos para la firma y la ejecución, respetando los mismos límites que Bureaucrat.
- Los atributos fundamentales de Form (nombre y grados requeridos) son constantes y no pueden modificarse tras la construcción.
- Un formulario solo puede cambiar su estado de “no firmado” a “firmado” mediante la acción explícita de un Bureaucrat con el grado adecuado.
- Si un burócrata intenta firmar un formulario sin el nivel requerido, se lanza la excepción correspondiente.
- La lógica de firma está centralizada en Form::beSigned(), mientras que Bureaucrat::signForm() actúa como intermediario que gestiona el intento y comunica el resultado.
- Las excepciones derivan de std::exception, lo que permite:
    - Capturarlas de forma uniforme.
    - Mostrar mensajes de error claros mediante what().
- La relación bidireccional entre Bureaucrat y Form se implementa evitando dependencias circulares entre headers, utilizando forward declarations y moviendo los #include necesarios a los archivos .cpp.
- En ningún caso un formulario puede considerarse firmado sin que se haya producido una validación explícita del grado del burócrata.

El `main` actúa únicamente como entorno de prueba: provoca tanto casos válidos como inválidos para verificar que la lógica interna de la clase es robusta y coherente.

---
### ex02
Este ejercicio se centra en las clases abstractas, el polimorfismo y el control del flujo de ejecución mediante excepciones. El objetivo es diseñar una jerarquía robusta de formularios en la que:
	•	La clase base define las reglas.
	•	Las clases concretas implementan comportamientos específicos.

La ejecución solo es posible cuando todas las restricciones se cumplen.
>#### Compilación y ejecución
Desde la raíz del ejercicio:
``` bash
make
```
Para ejecutarlo:
``` bash
./Bureaucrat
```
>#### **Comportamiento del programa**
Se crean distintos formularios, definidos como clases hijas de AForm:
- Se comprueba si el formulario está firmado.
- Se comprueba si el burócrata tiene el grado suficiente.
- Se lanza la excepción correspondiente si alguna regla se viola.
- Se delega la acción concreta a una función virtual.

Cada formulario concreto implementa únicamente su acción específica. Esto evita la duplicación de lógica y garantiza que ningún formulario pueda ejecutarse en un estado inválido.

La función `main` actúa únicamente como entorno de pruebas: provoca tanto escenarios válidos como inválidos para verificar que la lógica interna de las clases es robusta y coherente.

---
### ex03
Este ejercicio introduce el patrón Factory a través de la clase Intern. El objetivo es crear dinámicamente distintos formularios concretos basándose únicamente en un identificador de tipo cadena, devolviéndolos siempre mediante una interfaz común.

>#### Compilación y ejecución
Desde la raíz del ejercicio:
``` bash
make
```
Para ejecutarlo:
``` bash
./Bureaucrat
```
>#### **Comportamiento del programa**
El programa demuestra que:
- La clase Intern es capaz de crear distintos formularios usando únicamente su nombre.
- El tipo de retorno es siempre un puntero a AForm, independientemente del tipo concreto creado.
- El `main` es responsable de:
    - Utilizar el objeto devuelto.
	- Gestionar su ciclo de vida (delete).

La función `main` actúa únicamente como entorno de pruebas: provoca tanto escenarios válidos como inválidos para verificar que la lógica interna de las clases es robusta y coherente.