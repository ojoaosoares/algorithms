#include "../include/Auxiliar.hpp"

int fatorial(int n) {
    int total = 1;

    for (int i = 1; i <= n ; i++)
        total  *= i;
    
    return total;
}

int combinacao(int total, int escolhido) {
    return fatorial(total)/(fatorial(escolhido)*fatorial(total-escolhido));

}


void trocar_indices(std::vector<int> &indices, int tamanho_subconjunto, int quantidade_membros) {
    int limite_tamanho = 1;
    for (int l = tamanho_subconjunto - 1; l >= 0; l--) {
        if(indices[l] < quantidade_membros-limite_tamanho) {
            indices[l]++;
            for (int m = l+1; m < tamanho_subconjunto; m++)
                indices[m] = indices[l] + (m-l);
            
            break;
        }
        limite_tamanho++;

        

    }

}


std::vector<int> retornarPrimosMenoresRaiz(int n) {
    
    std::vector<int> primos;
    bool nao_divisivel;
    for (int i = 2; i <= (int)std::round(std::sqrt(n)); i++) {
            nao_divisivel = true;
            for (int primo : primos)
                if(!(i % primo)) {
                    nao_divisivel = false;
                    break;
                }

            if(nao_divisivel) primos.push_back(i);
        }
    
    return primos;
}