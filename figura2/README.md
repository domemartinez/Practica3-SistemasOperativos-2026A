## Descripción del ejercicio

En este ejercicio el proceso padre incremente 10 veces el valor de una variable en pasos de 10, mientras que el proceso hijo registre cada valor en un archivo de texto. Para resolverlo se usó la función fork()

La función ``fork()`` crea un nuevo proceso duplicando el proceso actual. Aunque son copias idénticas al inicio, no comparten memoria. Por esta razon en esta practica el proceso padre recibe el PID del hijo, y el proceso hijo recibe un 0

## Explicación del Código

`` int variable = 0;`` 

Esta variable nace en el proceso original. Al ejecutar ``fork()``, esta dirección de memoria se clona. El Padre tendrá su propia variable y el Hijo la suya. Cualquier cambio en una no afecta a la otra.

`` pid = fork();`` 

En este instante, el sistema operativo divide la ejecución. Se crean dos hilos de ejecución distintos. Usamos el valor de pid para decirle al CPU qué código debe ejecutar el proceso padre y cuál el proceso hijo.


``` 
if (pid == 0) {
    archivo = fopen("log_figura2.txt", "w");
    for(int i = 1; i <= 10; i++) {
        fprintf(archivo, "Registro %d: Valor = %d\n", i, variable);
        sleep(1);
    }
    fclose(archivo);
}
```

El hijo entra en este bloque porque su pid es 0, por lo que abre un archivo llamado log_figura2.txt, en donde intenta registrar el valor de variable 10 veces. Debido a que el rpoceso hijo es una copia del momento de nacimiento su variable vale 0. Además, el hijo "duerme" 1 segundo en cada iteración para esperar a que el padre haga su trabajo, pero al leer su propia memoria, siempre encuentra el valor inicial.

```
else {
    for(int i = 1; i <= 10; i++) {
        variable += 10;
        printf("[PADRE] Incremento: %d\n", variable);
        usleep(500000); 
    }
    wait(NULL);
}
```

El proceso padre se ejecuta en este bloque y lo que hace es incrementar su propia copia de la variable en pasos de 10 ha (10, 20, 30... hasta 100).

Sincronización (wait): El padre espera a que el hijo termine de escribir antes de cerrar el programa. Esto evita que el archivo se quede corrupto o que el hijo se convierta en un proceso "zombie".
