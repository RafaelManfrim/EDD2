#include <iostream>

using namespace std;

int main() {
    int vetor[] = {1, 2, 3, 4, 5};
    int tamanho = 5;

    int k = 3;
    int tamanho_resposta = tamanho - (k - 1);
    int resposta[tamanho_resposta];

    for (int i = 0; i < tamanho_resposta; i++) {
        int final = i + k;

        int soma = 0;

        for(int j = i; j < final; j++) {
            soma += vetor[j];
        }

        resposta[i] = soma;
    }

    for (int i = 0; i < tamanho_resposta; i++) {
        cout << resposta[i] << " ";
    }

    return 0;
}