#include <stdio.h>

/* A busca binária é um algoritmo eficiente amplamente utilizado para encontrar um determinado elemento em uma lista ordenada.
Ele opera dividindo repetidamente a lista ao meio e comparando o valor alvo com o elemento no meio da lista.
Com base nessa comparação, a busca continua na metade esquerda ou direita da lista até que
o elemento desejado seja encontrado ou até que se determine queo elemento não está presente na lista.
O processo de busca binária é eficaz para reduzir o intervalo de pesquisa pela metade a cada iteração,
o que resulta em um tempo de execução rápido, especialmente em listas grandes.
No entanto, a busca binária requer que a lista esteja ordenada para funcionar corretamente.
É uma estratégia eficaz para localizar elementos em grandes conjuntos de dados,
e sua abordagem de divisão e conquista o torna uma ferramenta poderosa em algoritmos de busca.
*/
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
