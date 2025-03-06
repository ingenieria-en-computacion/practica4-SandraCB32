#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);

    arreglo = (int*)calloc(num , sizeof(int)); // el primer elemento reserva y el segundo
    if(arreglo != NULL){
        printf("Vector reservado:\n\t["); //calloc si garantiza que a cada dato se garantiza un 0 een cada localizacion de memoria
        for(cont =0; cont <num; cont++){
            printf("\t%d, %p", *(arreglo + cont), (arreglo + cont));            
        }
        printf("\t]\n");
        printf("Liberando el espacio reservado\n");
        free(arreglo); 
        arreglo = NULL;       
    }
    return 0;
}
