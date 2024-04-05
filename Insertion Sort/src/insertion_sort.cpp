#include "insertion_sort.hpp"

template<typename T> void insertion_sort(T array[], long long n)
{
    long long i, j, aux;
    for (i = 1; i < n; i++)
    {
        
        j = i - 1;
        aux = array[i];

        while (j >= 0 && aux < array[j])
        {
            array[j + 1] = array[j];
            j--;
        }

        v[j + 1] = aux;
    }

    // Análise
    // INSERTION sort é um método de ordenação ESTÁVEL
    // A complexidade de comparações é Grande O de n ao quadrado no pior caso, e n no melhor caso
    // A complexidade de movimentações é Grande O de n ao quadrado no pior caso, e n no melhor caso 
    // Adaptável


    // Desvantagens
    // Muitas operações de movimentação
}

template void insertion_sort<int>(int array[], long long n);
template void insertion_sort<long long>(long long array[], long long n);
template void insertion_sort<double>(double array[], long long n);