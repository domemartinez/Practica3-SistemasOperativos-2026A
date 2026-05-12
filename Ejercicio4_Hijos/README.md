# Ejercicio 4: Creación de Procesos Concurrentes 
En este ejercicio se exploró la creación de múltiples procesos hijos que realizan tareas diferentes utilizando un bucle y la función `fork()`.

## Descripción
El programa crea 3 procesos hijos. Cada hijo tiene una tarea específica asignada mediante un `switch`:
* **Hijo 1:** Realiza una suma de dos enteros.
* **Hijo 2:** Realiza un acumulador mediante un bucle.
* **Hijo 3:** Imprime una secuencia de números del 1 al 10.

## Modificaciones clave
* Aplicación de `exit(0)` en el hijo para evitar que cree más hijos.
* Eliminación de `exit(0)` en el padre para que continue el bucle.
