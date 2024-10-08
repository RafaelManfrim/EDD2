//
// Created by manfrim on 21/08/24.
//

#include <iostream>

using namespace std;

int pares_soma_2(int* vetor, int quantidade_itens, int soma) {
    int vAux[] = {0, 0, 0, 0, 0, 0, 0, 0};
    int pares = 0;
    for(int i = 0; i < quantidade_itens; i++) {
        int complemento = soma - vetor[i];
        pares += vAux[complemento];
        vAux[vetor[i]]++;
    }
    return pares;
}

int pares_soma(int* vetor, int quantidade_itens, int soma) {
    int metade = soma / 2;
    int quantidade_igual_metade = 0;
    int menores_metade[quantidade_itens];
    int quantidade_menores_metade = 0;
    int maiores_metade[quantidade_itens];
    int quantidade_maiores_metade = 0;

    for(int i = 0; i < quantidade_itens; i++) {
        if(vetor[i] == metade) {
            quantidade_igual_metade++;
        } else if (vetor[i] < metade) {
            menores_metade[quantidade_menores_metade] = vetor[i];
            quantidade_menores_metade++;
        } else {
            maiores_metade[quantidade_maiores_metade] = vetor[i];
            quantidade_maiores_metade++;
        }
    }

    int pares_metade = quantidade_igual_metade * (quantidade_igual_metade - 1) / 2;

    int pares = pares_metade;

    for (int i = 0; i < quantidade_menores_metade; i++) {
        for(int j = 0; j < quantidade_maiores_metade; j++) {
            if (menores_metade[i] + maiores_metade[j] == soma) {
                pares++;
            }
        }
    }

    return pares;
}

int main() {
    int vetor[] = {1, 3, 2, 5, 4, 3, 3, 4};
    int quantiade_items = 8;
    int soma = 6;

    cout << "Quantidade de pares: " << pares_soma_2(vetor, quantiade_items, soma);

    return 0;
}