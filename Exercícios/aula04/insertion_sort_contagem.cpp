#include <iostream>

using namespace std;

void insertion_sort(int vetor[], int tamanho, int &trocas, int &comparacoes) {
    for (int i = 0; i < tamanho - 1; i++) {
        int chave = vetor[i + 1];

        int j = i;

        bool entrou = false;

        while(j >= 0 && vetor[j] > chave) {
            entrou = true;
            comparacoes++;
            vetor[j + 1] = vetor[j];
            trocas++;
            j--;
        }

        if (!entrou)
            comparacoes++;

        if (j > 0 && entrou)
            comparacoes++;

        vetor[j + 1] = chave;
    }
}

int main() {
    int tamanho = 6;

    int vetor_aleatorio[] = {5, 2, 9, 1, 5, 6};
    int vetor_ordenado[] = {1, 2, 3, 4, 5, 6};
    int vetor_inversamente_ordenado[] = {6, 5, 4, 3, 2, 1};

    int trocas = 0;
    int comparacoes = 0;

    insertion_sort(vetor_aleatorio, tamanho, trocas, comparacoes);
    cout << "Vetor Aleatório: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    insertion_sort(vetor_ordenado, tamanho, trocas, comparacoes);
    cout << "Vetor Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    insertion_sort(vetor_inversamente_ordenado, tamanho, trocas, comparacoes);
    cout << "Vetor Inversamente Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    return 0;
}