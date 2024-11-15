#include <iostream>

using namespace std;

void Heapify(int A[], int tamanho, int i) {
    int esquerda = 2 * i + 1;
    int direita = 2 * i + 2;
    int maior = i; // A raiz está em i.
    if(esquerda < tamanho && A[esquerda] > A[maior])
        maior = esquerda;
    if(direita < tamanho && A[direita] > A[maior])
        maior = direita;
    if(maior != i) {
        int temp = A[i];
        A[i] = A[maior];
        A[maior] = temp;
        Heapify(A, tamanho, maior);
    }
}

void ConstroiHeapMaximo(int A[], int n) {
    for(int i = n/2 - 1; i >= 0; i--)
        Heapify(A, n, i);
}

void HeapSort(int A[], int tamanho) {
    ConstroiHeapMaximo(A, tamanho);

    // Lógica de Ordenação
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