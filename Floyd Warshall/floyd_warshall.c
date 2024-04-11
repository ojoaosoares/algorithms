#include <stdio.h>

/* 
    O algoritmo Floyd-Warshall é uma técnica poderosa na teoria dos grafos,
    usada para encontrar os caminhos mais curtos entre todos os pares de vértices em um grafo ponderado, mesmo que haja arestas de peso negativo.
    Seu nome deriva dos matemáticos Robert Floyd e Stephen Warshall, que contribuíram para o desenvolvimento desse algoritmo.
    O algoritmo utiliza uma abordagem de programação dinâmica para calcular os caminhos mais curtos.
    Ele cria uma matriz de distâncias que armazena as distâncias mínimas entre cada par de vértices.
    A ideia principal é iterar por todos os vértices intermediários possíveis para determinar se eles podem encurtar o caminho entre quaisquer dois vértices.
    Dessa forma, ele constrói progressivamente as distâncias mínimas.
    Embora seja eficaz na determinação de caminhos mais curtos em um grafo, o algoritmo Floyd-Warshall pode ser menos eficiente em termos de tempo e espaço
    , especialmente para grafos maiores, devido à sua complexidade de tempo de O(N^3), onde V é o número de vértices.
    No entanto, sua versatilidade e capacidade de lidar com arestas de peso negativo o tornam uma ferramenta valiosa em situações onde outros algoritmos,
    como Dijkstra ou Bellman-Ford, podem não ser aplicáveis.

*/


// Função para aplicar o algoritmo de Floyd-Warshall em uma matriz de adjacência.
void floyd_warshal(int **array, int n) {
    for (int i = 0; i < n; i++) // Loop para iterar sobre todos os vértices como potenciais intermediários.
            for (int j = 0; j < n; j++) { // Loop para iterar sobre os vértices de origem.
                if (array[j][i] == -1 || j == i ) continue; // Se não houver conexão direta, pule para a próxima iteração.

                for (int k = 0; k < n; k++) { // Loop para iterar sobre os vértices de destino.
                    if(j == k  || k == i || array[i][k] == -1) continue; // Atualize o caminho mínimo se o caminho atual for maior do que a soma dos caminhos intermediários.
                    if(array[j][k] == -1 || array[j][k] > array[j][i] + array[i][k]) array[j][k] = array[j][i] + array[i][k];
                    
                }
            }
}