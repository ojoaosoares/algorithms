#include <iostream>
#include <algorithm>



/*

O algoritmo da Mochila (Knapsack) resolve um problema de otimização em que você precisa escolher entre diferentes itens,
cada um com um valor e um peso, para maximizar o valor total que pode ser colocado em uma mochila com uma capacidade de peso específica.
A abordagem de programação dinâmica é comumente usada para resolver esse problema.
A ideia central é criar uma tabela em que as linhas representam os itens e as colunas representam os pesos possíveis da mochila.
Inicialmente, a tabela é preenchida com zeros na coluna de peso zero, pois não há valor possível nessa situação.
Em seguida, você preenche a tabela de cima para baixo, calculando o valor máximo que pode ser alcançado ao escolher ou não cada item.
Esse valor é comparado com o valor máximo anterior, e o máximo é escolhido para preencher a célula atual.
Depois de preencher a tabela, você pode retroceder através dela para determinar quais itens foram selecionados para atingir o valor máximo.
Você começa na célula que representa o último item e a capacidade total da mochila. Se o valor na célula atual for maior do que o valor na célula acima,
significa que o item atual foi incluído. Caso contrário, você passa para a célula acima.



*/

struct Obj {
    int peso, valor;
};


int knaspack(Obj *frases , int maximo, int n_objetos) {

    int matriz[n_objetos+1][maximo+1];

    for (int i = 0; i <= n_objetos; i++)
        for (int j = 0; j <= maximo; j++)
            matriz[i][j] = 0;
    

    
    for (int i = 1; i <= n_objetos; i++)
        for (int j = 1; j <= maximo; j++)
        {
            if(frases[i-1].peso > j) matriz[i][j] = matriz[i-1][j];
            else matriz[i][j] = std::max(frases[i-1].valor+ matriz[i-1][j - frases[i-1].peso], matriz[i-1][j]);
        }

    return matriz[n_objetos][maximo];
    
    
}