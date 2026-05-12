# Ejercicio 5: Reemplazo de Proceso con EXECL

## Archivos Relacionados
* `figura6.c`: El programa que realiza el `fork`.
* `programasust.c`: El programa que es cargado por el hijo para imprimir números pares.

## Flujo de Ejecución
1. El proceso **Padre** crea un clon (**Hijo**).
2. El **Hijo** anuncia su PID y limpia su memoria para cargar el ejecutable `programasust`.
3. El **Padre** espera a que la nueva tarea termine para reportar el cierre del proceso.

## Uso de EXECL
Parte principal del ejercicio al permitir sustituir el proceso original del hijo por el del ejecutable `programasust`.
