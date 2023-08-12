#include <stdio.h>

// Interativa
int binary_search(int *array,int alvo, int esquerda, int direita) {
    
    while (esquerda <= direita)
    {
        int meio = (esquerda + direita)/2;
        if(array[meio] == alvo) return 1;
        if(alvo > array[meio]) esquerda = meio+1;
        else direita = meio -1;
    }
    

    return 0;
}
