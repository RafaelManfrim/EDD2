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

// Função para realizar o particionamento e posicionar o pivô na posição correta
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
        // partiçãoIndex é o índice de onde o pivô foi colocado
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