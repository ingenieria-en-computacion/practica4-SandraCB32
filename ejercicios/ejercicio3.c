#include <stdio.h>
#include <stdlib.h>

int main() {
    int size = 2; // Asigna un número pequeño inicialmente
    int *arr = (int *)malloc(size * sizeof(int)); // Reserva memoria con malloc
    if (arr == NULL) {
        printf("Error: No se pudo asignar memoria.\n");
        return 1;
    }

    int count = 0;
    int num;
    printf("Ingrese números (ingrese -1 para terminar):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1) {
            break; // Rompe el ciclo si el usuario ingresa -1
        }

        if (count >= size) {
            size *= 2; // Duplica el tamaño del arreglo
            arr = (int *)realloc(arr, size * sizeof(int)); // Cambia el tamaño del arreglo
            if (arr == NULL) {
                printf("Error: No se pudo reasignar memoria.\n");
                return 1;
            }
        }

        arr[count++] = num; // Agrega el número al arreglo
    }

    printf("La lista ingresada es: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]); // Imprime la lista
    }
    printf("\n");

    free(arr); // Libera la memoria
    return 0;
}
