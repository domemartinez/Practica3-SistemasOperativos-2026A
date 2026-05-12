## Descripción del ejercicio

En este ejercicio el proceso padre incremente 10 veces el valor de una variable en pasos de 10, mientras que el proceso hijo registre cada valor en un archivo de texto. Para resolverlo se usó la función fork()

La función ``fork()`` crea un nuevo proceso duplicando el proceso actual. Aunque son copias idénticas al inicio, no comparten memoria. Por esta razon en esta practica el proceso padre recibe el PID del hijo, y el proceso hijo recibe un 0

## Explicación del Código
### Variable en la memoria
`` int variable = 0;`` 
Esta variable nace en el proceso original. Al ejecutar ``fork()``, esta dirección de memoria se clona. El Padre tendrá su propia variable y el Hijo la suya. Cualquier cambio en una no afecta a la otra.


