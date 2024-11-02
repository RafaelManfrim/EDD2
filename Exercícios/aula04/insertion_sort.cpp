#include <iostream>

using namespace std;

//void insertionSort(int V[], int n) {
//    int j, chave;
//    for(int i = 1; i < n; i++) {
//        chave = V[i];
//        j = i - 1;
//        while(j >= 0 && V[j] > chave) {
//            V[j + 1] = V[j];
//            j = j - 1;
//        }
//        V[j + 1] = chave;
//    }
//}

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