#include <iostream>

using namespace std;

void bubble_sort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j+1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
}

int main() {
    int vetor[] = {5, 2, 9, 1, 4, 6};
    int tamanho_vetor = 6;

    imprime_vetor(vetor, tamanho_vetor);

    cout << endl;

    bubble_sort(vetor, tamanho_vetor);

    imprime_vetor(vetor, tamanho_vetor);

    return 0;
}