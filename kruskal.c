#include <stdio.h>
#include <stdlib.h>

/*
    O algoritmo de Kruskal é usado para encontrar a Árvore Geradora Mínima (AGM) em um grafo ponderado.
    Ele começa ordenando as arestas por peso e, em seguida, seleciona as arestas mais leves que não formam ciclos.
    Essas arestas compõem a AGM, que conecta todos os vértices com o menor custo possível.
    O algoritmo é eficiente, especialmente com estruturas como conjuntos disjuntos (Union-Find), e é útil em otimizações de redes e distribuição de recursos.
    Sua complexidade média é cerca de O(E log E), onde E é o número de arestas.
    Em resumo, o algoritmo de Kruskal é uma abordagem eficaz para encontrar a Árvore Geradora Mínima em grafos ponderados,
    sendo amplamente utilizado em problemas de otimização.

*/

// Definição da estrutura para representar as arestas
struct Aresta {
    int v1, v2, peso;
};

// Função para encontrar o representante (raiz) do conjunto ao qual o elemento pertence
int find(int *v, int x) {
    while(v[x] != x) {
        x = v[x];
    }
    return v[x];
}

// Função para unir dois conjuntos disjuntos
void join(int *v, int x1, int x2) {
    int pai1 = find(v,x1);
    int pai2 = find(v,x2);

    if( pai1 < pai2) v[pai2] = pai1;
    else v[pai1] = pai2;
}

// Algoritmo de Kruskal para encontrar a Árvore Geradora Mínima
// Obs: o arranjo arestas precisa estar ordenado do menor para o maior, caso contrário o algorítimo não funcionará
int kruskal(int *vertices, Aresta *arestas, int n, Aresta *copia) {

    int t = 0;
    
    for (int i = 0; i < n; i++)
        if(find(vertices,arestas[i].v1) != find(vertices,arestas[i].v2)) {
            join(vertices,arestas[i].v1,arestas[i].v2);
            copia[(t++)] = arestas[i];   
        }

    copia = (Aresta*) realloc(copia,t*sizeof(Aresta));
    return t;
    
}
