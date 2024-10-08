#include <iostream>

using namespace std;

void bubble_sort(int V[], int tamanho_vetor) {
    for(int i = 0; i < tamanho_vetor - 1; i++){
        for(int j = 0; j < tamanho_vetor - i - 1; j++) {
            if(V[j] > V[j+1]) {
                int aux = V[j];
                V[j] = V[j+1];
                V[j+1] = aux;
            }
        }
    }
}

int main() {
    int vetor[] = {5, 2, 9, 1, 4, 6};
    int tamanho_vetor = 6;

    bubble_sort(vetor, tamanho_vetor);

    for(int i = 0; i < tamanho_vetor; i++) {
        cout << vetor[i] << " - ";
    }

    return 0;
}