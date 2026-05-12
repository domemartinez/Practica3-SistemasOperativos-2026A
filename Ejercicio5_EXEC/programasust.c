#include <stdio.h>

// Programa que va a reemplazar al hijo de figura6.c
void main(){

    printf("Soy el programa que reemplaza el código del hijo y voy a mostrar los número pares que hay del 1 al 10\n");

    for (int i = 1; i <= 10; i++){
        if(i%2 == 0){
            printf("%d\n", i);
        }
    }
}
