#include <stdio.h>
#include <stdlib.h>

/* O Merge Sort é um algoritmo de ordenação eficiente que segue o princípio "dividir para conquistar".
Ele divide a lista não ordenada em partes menores, ordena cada parte e depois mescla essas partes em uma única lista ordenada.
Com complexidade de tempo previsível de O(n log n), o Merge Sort é uma escolha popular para ordenar grandes conjuntos de dados,
apesar de exigir espaço extra na memória para a fase de mesclagem. */


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

/* 
    Esta é uma versão interativa do algoritmo de Merge Sort. Ela ordena e mescla pares de tamanho 2^i,
    onde i >= 0 e 2^i é menor que o tamanho total da lista.
    O vetor auxiliar é utilizado para copiar os pares já ordenados e, em seguida, ele é transferido de volta
    para o vetor original ao final de cada loop.
    O loop externo controla a ordenação e mesclagem das partes do array. Ele começa com pares pequenos e gradualmente
    trabalha em direção a pares maiores.
    O loop interno opera sobre cada par de elementos e realiza a ordenação e mesclagem. Ele divide o par em duas partes:
    a primeira parte de esquerda até meio e a segunda de meio até direita. Os índices x e y ajudam a acompanhar a posição
    atual de ambos os lados.
    O processo de mesclagem é feito comparando os elementos nos índices x e y, escolhendo o menor (ou igual) e copiando-o
    para o vetor auxiliar. Isso ocorre até que todos os elementos do par sejam mesclados de volta na ordem correta.
    Após mesclar todos os pares do loop interno, o vetor auxiliar é transferido de volta para o vetor original, efetivamente
    atualizando a parte ordenada.
    Esse processo continua até que todos os elementos estejam totalmente ordenados no vetor original.
    O algoritmo de Merge Sort é eficiente e garante que o vetor esteja ordenado ao final da sua execução.
*/

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
            
            for (int k = j; k <  direita; k++)
                array[k] = auxiliar[k];
        } 
    }     
}

