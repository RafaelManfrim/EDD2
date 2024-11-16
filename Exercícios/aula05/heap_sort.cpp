#include <iostream>

using namespace std;

void Heapify(int vetor[], int tamanho, int index) {
    int esquerda = 2 * index + 1;
    int direita = 2 * index + 2;
    int maior = index;

    if(esquerda < tamanho && vetor[esquerda] > vetor[maior]) {
        maior = esquerda;
    }

    if (direita < tamanho && vetor[direita] > vetor[maior]) {
        maior = direita;
    }

    if (maior != index) {
        int temp = vetor[index];
        vetor[index] = vetor[maior];
        vetor[maior] = temp;

        Heapify(vetor, tamanho, maior);
    }
}

void ConstroiHeapMaximo(int vetor[], int tamanho) {
    for(int i = tamanho/2 - 1; i >= 0; i--) {
        Heapify(vetor, tamanho, i);
    }
}

void HeapSort(int vetor[], int tamanho) {
    ConstroiHeapMaximo(vetor, tamanho);

    for(int i = tamanho - 1; i >= 0; i--) {
        int temp = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = temp;

        Heapify(vetor, i, 0);
    }
}

int main() {
    int vetor_aleatorio[] = {5, 2, 9, 1, 5, 6};
    int tamanho = 6;

    for (int i = 0; i < tamanho; i++) {
        cout << vetor_aleatorio[i] << " ";
    }

    cout << endl;

    HeapSort(vetor_aleatorio, tamanho);

    for (int i = 0; i < tamanho; i++) {
        cout << vetor_aleatorio[i] << " ";
    }

    return 0;
}