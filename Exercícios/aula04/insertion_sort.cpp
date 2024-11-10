#include <iostream>

using namespace std;

void insertion_sort(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int chave = vetor[i + 1];

        int j = i;
        while(j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[] = {5, 2, 4, 6, 1, 3};
    int tamanho = 6;

    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    insertion_sort(vetor, tamanho);

    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
}