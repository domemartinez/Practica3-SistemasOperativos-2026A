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

El proceso padre se ejecuta en este bloque y lo que hace es incrementar su propia copia de la variable en pasos de 10 hasta 100. El padre espera a que el hijo termine de escribir antes de cerrar el programa, esto evita que el archivo se quede corrupto o que el hijo se convierta en un proceso "zombie".

## Resultados Obtenidos

Se puede ver que el proceso imprime en consola el incremento de la variable de 10 en 10 hasta llegar al 100, pero no podemos ver lo que el proceso hijo escribe en la hoja de texto, solo nos llega un mensjae de que ha terminado de escribir. 
<img width="554" height="212" alt="Captura de pantalla 2026-05-11 133210" src="https://github.com/user-attachments/assets/cec1decb-6998-47e1-b138-dcdc773f24a0" />

Al abrir la hoja de texto podemos ver el hijo ha escrito que la variable es 0 en las 10 iteraciones ya que como se mencionó anteriormente la memario no es compartida, por lo que el proceso hijo presenta su propia copia de "variable"
<img width="600" height="209" alt="Captura de pantalla 2026-05-11 133118" src="https://github.com/user-attachments/assets/1251488a-bc4f-47ac-93b8-9bc6dde46b34" />
