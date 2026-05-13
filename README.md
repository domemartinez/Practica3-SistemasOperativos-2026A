# Práctica 3: Creación y Gestión de Procesos en C

**Integrantes:** Samuel Crespo, Esteban López, Bryan Magarisca, Doménica Martínez, Esteban Valenzuela

**Grupo:** D

**Fecha:** 09 mayo de 2026

## Descripción del Proyecto 

Este repositorio contiene el desarrollo de la Práctica 3: Creación de Procesos. El propósito fundamental de este trabajo es lograr familiarizarse con el uso de funciones esenciales en lenguaje
C, permitiendo así realizar diversas actividades de creación y gestión de procesos padres e hijos en entornos Unix/Linux.  

El laboratorio cuenta con las siguientes prácticas:

- **Identificación de Jerarquías:** Obtención de los valores PID (Process ID) y PPID (Parent Process ID) para comprender la relación padre-hijo.
- **Comunicación y Control:** Implementación de un flujo donde el proceso padre incrementa una variable 10 veces, mientras el proceso hijo registra cada uno de estos valores en un archivo de texto externo.
- **Gestión de Procesos Huérfanos:** Análisis de la creación de un hijo sin espera (wait).
- **Multiprocesamiento:** Creación de un proceso padre y tres procesos hijos simultáneos, donde cada uno imprime en pantalla del 1 al 10 en pantalla.
- **Sustitución de Imagen de Proceso:** Uso de la función execl para que un proceso hijo realice una tarea externa especializada.

Las carpetas que se usaron para este trabajo son las siguientes: 
- **`Figura1/`**:Identificación de valores PID y PPID.
    - `figura1.c`
    - `README.md`
    - `uso_system.c`
      
- **`Figura2/`**: Incremento de variable y registro en archivo.
    -  `figura2.c`
    -  `README.md`

- **`Figura3/`**: Creación de un proceso hijo sin espera.
    - `Figura3.c`
    - `Figura3_modificado.c`
    - `README.md`

- **`Figura4/`**: Creación de un proceso padre y tres procesos hijos.
    - `Figura4.c`
    - `README.md`

- **`Figura6/`**: Uso de la función `execl` para tareas especializadas.
    - `Figura6.c`
    - `README.md`
    - `programasust.c`
