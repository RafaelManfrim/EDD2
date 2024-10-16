//#include <stdio.h>
//
//int v[10] = {7, 8, 1, 4, 5, 9, 0, 3, 2, 6};
//
//void print() {
//    int i;
//    for (i=0; i<10; i++)
//        printf("%d ",v[i]);
//    printf("\n");
//}
//
//int partition(int lo, int hi, int asc) {
//    int i, j, pivot, aux;
//    int flag=1;
//
//    pivot = v[(hi + lo)/2];
//    i = lo-1;
//    j = hi+1;
//
//    while (flag==1) {
//        if (asc) {
//            do {
//                i=i+1;
//            } while (v[i] < pivot);
//            do {
//                j=j-1;
//            } while (v[j] > pivot);
//        } else {
//            do {
//                i=i+1;
//            } while (v[i] > pivot);
//            do {
//                j=j-1;
//            } while (v[j] < pivot);
//        }
//
//        if (i>=j)
//            return j;
//
//        aux = v[i];
//        v[i] = v[j];
//        v[j] = aux;
//    }
//}
//
//void quicksort(int lo, int hi, int asc) {
//    int p;
//
//    if (lo>=hi)
//        return;
//
//    print();
//
//    p = partition(lo, hi, asc);
//
//    printf("Posição do PIVÔ: %d\n\n", p);
//
//    quicksort(lo, p, asc);
//    quicksort(p+1, hi, asc);
//}
//
//int main() {
//    printf("Vetor inicial: ");
//    print();
//
//    quicksort(0,9,1);
//
//    printf("Vetor final: ");
//    print();
//}

#include <iostream>
using namespace std;

int arr[] = {10, 3, 8, 9, 1, 5};
int tamanho = sizeof(arr) / sizeof(arr[0]);

// Função para trocar dois elementos
void troca(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Função para imprimir o array
void imprimeArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Função para realizar o particionamento
int particiona(int arr[], int baixo, int alto) {
    int pivo = arr[alto];  // Pegamos o último elemento como pivô
    int i = baixo - 1;     // Índice do menor elemento

    for (int j = baixo; j < alto; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++;  // Incrementa o índice do menor elemento
            troca(arr[i], arr[j]);  // Troca os elementos
        }
    }
    troca(arr[i + 1], arr[alto]);  // Coloca o pivô na posição correta
    return (i + 1);  // Retorna o índice do pivô
}

// Função principal do QuickSort
void quickSort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        // partiçãoIndex é o índice de onde o pivô está agora
        int particaoIndex = particiona(arr, baixo, alto);

        imprimeArray(arr, tamanho);

        // Ordena os elementos antes e depois da partição
        quickSort(arr, baixo, particaoIndex - 1);
        quickSort(arr, particaoIndex + 1, alto);
    }
}

// Exemplo de uso
int main() {
    cout << "Array original: ";
    imprimeArray(arr, tamanho);

    quickSort(arr, 0, tamanho - 1);

    cout << "Array ordenado: ";
    imprimeArray(arr, tamanho);

    return 0;
}