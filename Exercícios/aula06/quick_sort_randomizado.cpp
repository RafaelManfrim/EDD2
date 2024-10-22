#include <iostream>

using namespace std;

void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void troca(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int array[], int inicio, int fim) {
    int indicePivo = inicio + rand() % (fim - inicio + 1);  // Escolhe índice aleatório
    troca(array[indicePivo], array[fim]);

    int pivo = array[fim];
    int posicao_menor_elemento = inicio - 1;

    for (int item = inicio; item < fim; item++) {
        if(array[item] <= pivo) {
            posicao_menor_elemento++;
            troca(array[posicao_menor_elemento], array[item]);
        }
    }

    troca(array[fim], array[posicao_menor_elemento + 1]);

    return posicao_menor_elemento + 1;
}

void quick_sort(int array[], int inicio, int fim) {
    if(fim > inicio) {
        int novaPosicaoPivo = partition(array, inicio, fim);

        quick_sort(array, inicio, novaPosicaoPivo - 1);
        quick_sort(array, novaPosicaoPivo + 1, fim);
    }
}

int main() {
    int arr[] = {10, 3, 8, 9, 1, 5};
    int tamanho = 6;

    cout << "Array original: ";
    imprimeArray(arr, tamanho);

    quick_sort(arr, 0, tamanho - 1);

    cout << "Array ordenado: ";
    imprimeArray(arr, tamanho);

    return 0;
}
