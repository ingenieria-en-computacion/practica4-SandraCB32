#include <stdio.h>
#include <stdlib.h>

int main(){
    int *arreglo=NULL, *arreglo2=NULL, num, cont;
    printf("¿Cuántos elementos tiene el conjunto?\n");
    scanf("%d", &num);
    arreglo = (int*)malloc(num *sizeof(int));
    if(arreglo != NULL){        
        for(cont =0; cont <num; cont++){
            printf("Ingresa el elemento %d del conjunto\n", cont+1);
            scanf("%d", (arreglo+cont));
        }
        printf("Vector reservado:\n\t[");
        for(cont =0; cont <num; cont++){
            printf("\t%d", *(arreglo + cont));            
        }
        printf("\t]\n");

        printf("Aumentando el espacio reservado al doble\n");
        num *=2;
        arreglo2 = (int*)realloc(arreglo, num*sizeof(int));//mesirve para modificar el tamaño de un (el que se quiere cambiar, a cuanto se va a iumentar, si todavia tiene espacio donde esta lo deja ahi y lo expande)
        if(arreglo2 != NULL){ 
            arreglo = arreglo2;       
            for(; cont <num; cont++){
                printf("Ingresa el elemento %d del conjunto\n", cont+1);
                scanf("%d", (arreglo2+cont));
            }
            printf("Vector reservado:\n\t[");
            for(cont =0; cont <num; cont++){
                printf("\t%d", *(arreglo2 + cont));            
            }
            printf("\t]\n");    
            arreglo2 = (int*)realloc(arreglo, num*sizeof(int));
            printf("Vector reservado:\n\t[");
            for(cont =0; cont <2; cont++){
                printf("\t%d", *(arreglo + cont));            
            }
             printf("\t]\n");
        }
        printf("Liberando el espacio reservado\n");

        free(arreglo);  
        arreglo = arreglo2 = NULL;      
    }
    return 0;
}
