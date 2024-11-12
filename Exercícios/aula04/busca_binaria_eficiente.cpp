#include <iostream>

using namespace std;

int busca_binaria(int arr[], int tamanho, int elemento) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] < elemento) {
            inicio = meio + 1;
        } else {
            fim = meio;
        }
    }

    if (inicio == fim && arr[inicio] == elemento) {
        return inicio;
    }

    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 15, 18, 40};
    int tamanho = 7;
    int elemento = 18;
    int resultado = busca_binaria(arr, tamanho, elemento);

    if (resultado == -1) {
        cout << "Elemento não encontrado no array." << endl;
    } else {
        cout << "Elemento encontrado no índice: " << resultado << endl;
    }

    return 0;
}