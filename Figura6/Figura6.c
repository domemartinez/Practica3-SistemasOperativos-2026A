#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int ejecutarNuevoProc(char *programa, char *nombre_programa);

int main(){

  //Seleccionando la ruta y el nombre del ejecutable del programa sustituto.
    char *programa = "/home/estebanlopez/programasust";
    char *nombre_programa = "programasust";

    int pid = ejecutarNuevoProc(programa, nombre_programa);
    wait(0);

  //Cambio de getpid() por pid para que en la salida devuelva el pid del hijo y no del padre.
    printf("El proceso hijo con pid %d ha terminado su ejecución\n", pid);

    return 0;
}

int ejecutarNuevoProc(char *programa, char *nombre_programa){
    int pid;
    pid = fork();

  //Switch para identificar el proceso.
    switch(pid){
        case -1:
            fprintf(stderr, "Error no se pudo crear el proceso hijo\n");
            exit(0);
        case 0:
            //Informando el código por el cual se va a reemplazar.
            printf("Soy el hijo con pid: %d reemplazando mi código por el de %s\n", getpid(), nombre_programa);
           //Usando la función execl para realizar la sustitución.
            execl(programa, nombre_programa, NULL);
            fprintf(stderr, "Error al ejecutar execl\n");
            exit(0);
        default:
            return pid;
    }
}
