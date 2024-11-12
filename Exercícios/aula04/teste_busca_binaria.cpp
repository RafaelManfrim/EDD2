#include <iostream>
#include <cmath>

using namespace std;

// Retorna a posição do vetor onde está o número buscado
int buscar(int* vetor, int tamanho, int numero) {
    int inicio = 0, fim = tamanho;
    int posicao_atual = fim / 2;

    while(true) {
        cout << "Exec: " << posicao_atual << endl;
        if(vetor[posicao_atual] > numero) {
            fim = posicao_atual;
            posicao_atual = posicao_atual - (int)ceil((fim - inicio) / 2);
        } else if (vetor[posicao_atual] < numero) {
            inicio = posicao_atual;
            posicao_atual = posicao_atual + (int)ceil((fim - inicio) / 2);
        } else {
            return posicao_atual;
        }
    }
}

int main() {
    int vetor[] = {1, 2, 4, 5, 6, 7, 8, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20, 23, 27, 33, 34, 35, 37, 38};
    int tamanho_vetor = 25;
    int numero_buscado = 1;
    cout << "O número " << numero_buscado << " está na posição: " << buscar(vetor, tamanho_vetor, numero_buscado);
    return 0;
}