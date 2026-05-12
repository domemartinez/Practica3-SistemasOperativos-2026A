#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/** Modificacion de la figura 2 para que el proceso padre incremente su copia de la variable mientras que el proceso hijo registra la suya en un archivo**/

int main() {
    int variable = 0; // Definimos una variable que será copiada al momento del fork
    int i;
    int pid;

    pid = fork();

    switch(pid) {
        case -1: // Si el Kernel no tiene recursos suficientes, el fork falla
            printf("No se ha podido crear el proceso hijo\n");
            break;

        case 0: { // Cuando pid es cero quiere decir que es el proceso hijo, por lo el hijo abre un flujo de escritura hacia un archivo físico
            FILE *archivo = fopen("log_hijo.txt", "w");

            if (archivo == NULL) {
                printf("Error al abrir el archivo\n");
                exit(1);
            }

            fprintf(archivo, "Registro del proceso hijo (PID: %d)\n", getpid());

            for(i = 1; i <= 10; i++) {
                // Debido a que el proceso hijo accede a su propia copia de 'variable'con el valor que tenía justo antes del fork, en el archivo siempre escribirá 0.                
                fprintf(archivo, "Iteración %d: Valor de la variable = %d\n", i, variable);

                // Dormimos al proceso hijo por 1 segundo para dar tiempo al padre de procesar
                sleep(1);
            }

            fclose(archivo); // Cerramos el archivo para asegurar que los datos se guarden
            printf("Soy el proceso hijo y he terminado de registar 'log_hijo.txt'\n");
            break;
        }

        default: // Cuando el pid es distinto de cero es el proceso padre
            printf("Soy el proceso padre y mi PID es %d. Iniciando incrementos...\n", getpid());

            for(i = 1; i <= 10; i++) {
                variable += 10; // Incremento de l variable en pasos de 10
                printf("%d Soy el padre con PID: %d (Variable = %d)\n", i, getpid(), variable);

                // Pausa de 0.5 segundos para que la salida sea legible
                usleep(500000);
            }

            // La función wait detiene el proceso padre y se queda esperando hasta que termine el hijo
            wait(0);
            break;
    }

    return 0;
}
