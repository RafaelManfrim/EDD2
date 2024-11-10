#include <iostream>

using namespace std;

void bubble_sort(int vetor[], int tamanho, int &trocas, int &comparacoes) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            comparacoes++;
            if(vetor[j] > vetor[j+1]) {
                trocas++;
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}


int main() {
    int vetor_aleatorio[] = {5, 2, 9, 1, 5, 6};
    int vetor_ordenado[] = {1, 2, 3, 4, 5, 6};
    int vetor_inversamente_ordenado[] = {6, 5, 4, 3, 2, 1};

    int trocas = 0;
    int comparacoes = 0;
    int tamanho = 6;

    bubble_sort(vetor_aleatorio, tamanho, trocas, comparacoes);
    cout << "Vetor Aleatório: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    bubble_sort(vetor_ordenado, tamanho, trocas, comparacoes);
    cout << "Vetor Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    bubble_sort(vetor_inversamente_ordenado, tamanho, trocas, comparacoes);
    cout << "Vetor Inversamente Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    return 0;
}