#include <iostream>
#include <vector>
#include <iterator>
#include "../include/Auxiliar.hpp"


std::vector<int> Erastones(int n) {

    std::vector<int> numeros, primos = retornarPrimosMenoresRaiz(n);
    
    for (int i = 2; i < n; i++)
        numeros.push_back(i);

    for (int primo : primos) {
        for(std::vector<int>::iterator it = numeros.begin(); it != numeros.end(); it++) {
            
            if(!((*it) % primo) && (*(it) != primo)) {
                bool first = it == numeros.begin() ? true : false;
                numeros.erase(it);
                first ? it = numeros.begin() : it--;
                
            }

            
        }
    }


    return numeros;    
        
}   

int contarPrimosNaoExcedentes(int n) { // Calcula a quantidade de primos não excedentes a n usando exclusão e inclussão, não funciona bem com numeros menos que 13

    

    if(n <= 13) return Erastones(n).size();

    else {

        std::vector<int> indices , primos = retornarPrimosMenoresRaiz(n);
        int divisao,soma, produto, total = 0;

        for (int tamanho_subconjuntos = 1; tamanho_subconjuntos <= primos.size(); tamanho_subconjuntos++) { // existem subconjuntos de até primos.size()
            
            indices.push_back(tamanho_subconjuntos -1); // um novo index é adicionado
            for (int k = 0; k < tamanho_subconjuntos - 1; k++)
                indices[k] = k; // esse indice obrigatoriamente é maior que os anteriores

            soma = 0; 
            for (int possivel_combinacao = 0; possivel_combinacao < combinacao(primos.size(),tamanho_subconjuntos); possivel_combinacao++) { // existem combinacao(primos.size(), i +1) de subconjuntos diferenets
                produto = 1;
                
                for (int k = 0; k < tamanho_subconjuntos; k++)
                    produto *= primos[indices[k]];

                divisao = (int) std::floor((n)/produto);
                soma += divisao;
                trocar_indices(indices,tamanho_subconjuntos,primos.size());            
            }

            total += pow(-1,tamanho_subconjuntos+1)*soma;
            
        }

        return (n-1) - (total) + primos.size();
    }
    
}


int main() {

    int n;
    std::cin >> n;
    std::vector<int> primos = Erastones(n);
    std::cout << contarPrimosNaoExcedentes(n) << std::endl;

    for (int i : primos)
        std::cout << i << " ";
    
    std::cout << std::endl;
    std::cout << primos.size() << std::endl;
 

}