#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define NUM_PROC 3

void hijoHasAlgo(int num);

int main(){
    int i, pid;
    for (int i = 1; i <= NUM_PROC; i++){
        pid = fork();
        switch(pid){
            case -1:
                fprintf(stderr, "Error en el proceso.\n");
                break;
            case 0:
                hijoHasAlgo(i);
                exit(0);
                //Cambio de break por exit para no crear hijos dentro del hijo.
                
            default:
                printf("Ejecutando el padre\n");
                wait(0);
                printf("Mi hijo %d ha terminado\n", i);
                
                //Eliminación de exit para que el contador pueda continuar y no acabe en el primer hijo.
        }
    }
}

void hijoHasAlgo(int num){
    // Añadiendo un switch para que cada hijo realice una acción diferente.
    
    switch(num){
        
        //Hijo 1 realiza una suma.
        case 1:
            int a = 10;
            int b = 10;
            int c = a + b;
            printf("Soy el hijo 1 y voy a hacer la suma de %d y %d, con resultado = %d\n", a, b, c);
            break;
            
        //Hijo 2 realiza un acumulador.
        case 2:
            int acc = 0;
            for(int i = 1; i <= 5; i++){
                acc++;
            }
            printf("Soy el hijo 2, y voy a hacer un acumulador que acaba en: %d\n", acc);
            break;
            
        //Hijo 3 imprime números del 1 al 10 mediante un bucle.
        case 3:
            printf("Soy el hijo 3, y voy a contar del 1 al 10:\n");
            for(int i = 1; i <= 10; i++){
                printf("%d ", i);
            }
            printf("\n");
            break;
    }
}
