#include "bubble_sort.hpp"

template<typename T> void bubble_sort(T array[], long long n)
{
    long long i, j;
    int nao_trocou;

    for (i = 0; i < n - 1; i++)
    {
        nao_trocou = 1;
        for (j = 1; j < n - i; j++)
        {
            if (array[j] < array[j-1]) {
                troca(array[j], array[j-1]);
                nao_trocou = 0;
            }
        }

        if (nao_trocou) break;

    }
    // Análise
    // Buble sort é um método de ordenação ESTÁVEL
    // A complexidade de comparações é Grande O de n ao quadrado
    // A complexidade de movimentações no melhor caso também seria GRANDE    O de n ao quadrado, 
    // enquanto que no melhor caso seria O de 1


    // Desvantagens
    // Não adaptável
    // NÃO é estável
        
}

template void bubble_sort<int>(int array[], long long n);
template void bubble_sort<long long>(long long array[], long long n);
template void bubble_sort<double>(double array[], long long n);