#include <stdio.h>

/* O algoritmo de Floyd de detecção de ciclos, popularmente conhecido como "Algoritmo da Tartaruga e Lebre",
é frequentemente aplicado para determinar a presença de ciclos em uma estrutura de dados, como uma lista encadeada.
Entretanto, sua aplicação não se limita a encontrar todos os ciclos, mas sim identificar se há pelo menos um ciclo.
Neste contexto, o código em questão emprega o algoritmo para localizar um elemento repetido em uma lista de tamanho n+1.
Os elementos da lista variam de 1 até n e deve haver, necessariamente, um número repetido. O algoritmo trabalha de forma eficiente,
aproveitando o princípio de movimentar dois ponteiros, um mais rápido que o outro, a fim de identificar a existência de um ciclo.
Nesse cenário específico, o algoritmo pode ser adaptado para localizar a duplicação de um número na lista,
o qual é garantido devido à restrição dos elementos no intervalo de 1 até n.
Em resumo, o Algoritmo de Floyd, também conhecido como "Tartaruga e Lebre", é uma ferramenta versátil para detectar ciclos em estruturas de dados,
e o código em questão aplica essa abordagem para encontrar um elemento repetido em uma lista de tamanho n+1, com elementos no intervalo de 1 até n. */

int tortoise_hare(int *vetor) {
    int tortoise = 0, hare = 0;
    // O ponteiro tortoise se movimenta um passo de cada vez, enquanto o hare se movimenta dois a cada vez
    do {
        tortoise = vetor[tortoise];
        hare = vetor[vetor[hare]];
    } while (tortoise != hare);
    // Ao encontrar uma ocorrência idêntica, o ponteiro tortoise volta a sua posição original, e os dois ponteiros começam a se movimentar um passo de cada vez
    tortoise = 0;
    while (tortoise != hare)
    {
        tortoise = vetor[tortoise];
        hare = vetor[hare];
    }
    // De acordo com a prova matemática,a distancia do ponteiro tortoise até o início ciclo é igual ao numero de voltas que o ponteiro hare da da posição em que ele e o tortoise se encontram,
    // mais a a distancia restante que falta pra ele chegar ao ciclo.
    // Por isso, quando se encontram novamente, eles estão no inicio do ciclo, ou seja, o número que se repete.
  

    return tortoise;
}
