#include <stdio.h>
#include <stdlib.h>


// Recursivo
void intercala(int *resultado,int *xl,int *xr, int s1, int s2) {
    int i, j, k;
    i = j = k = 0;

    while (i < s1 || j < s2) {
        if( (xl[i] < xr[j] && i < s1) || j >= s2) resultado[k++] = xl[i++];
        else if(j < s2) resultado[k++] = xr[j++];
    }

    free(xl);
    free(xr);
}

void merge_sort_recursivo(int *array, int *copia, int t) {
    if (t == 1) {
        copia[0] = array[0];
        return;
    } 

    int *xl = (int*) malloc((t/2)*sizeof(int));
    merge_sort_recursivo(array,xl,t/2);
    int *xr = (int*) malloc((t -t/2)*sizeof(int));
    merge_sort_recursivo(&(array[t/2]),xr,t-t/2);

    intercala(copia,xl,xr,t/2,t -t/2);
    
}


// Interativo 

void merge_sort(int *array, int tamanho) {

    int *auxiliar = (int*) malloc(tamanho*sizeof(int));

    int esquerda,meio, direita, x, y;
    for (int i = 1; i < tamanho; i*=2) {
        for (int j = 0; j + i < tamanho; j+= i*2)
        {
            esquerda = j;
            meio = esquerda + i;
            direita = esquerda + 2*i;
            if (direita > tamanho) direita = tamanho;
            
            x = esquerda;
            y  = meio;
            


            while (esquerda < direita)
            {
                if((array[x] < array[y] || y >= direita) &&  (x < meio)) auxiliar[esquerda++] = array[x++];
                else if((array[y] <= array[x] || x>= meio) && y < direita) auxiliar[esquerda++] = array[y++];
            }
            
        }


        for (int j = 0; j < tamanho; j++)
            array[j] = auxiliar[j];
        
    }
        
}
