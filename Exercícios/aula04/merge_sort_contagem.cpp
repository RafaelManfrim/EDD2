#include <iostream>

using namespace std;

void Merge(int V[], int inicio, int meio, int fim, int &trocas, int &comparacoes) {
    int tamEsq = meio - inicio + 1; // Comprimento de V[inicio ... meio]
    int tamDir = fim - meio; // Comprimento de V[meio + 1 ... fim]
    int E[tamEsq], D[tamDir]; // Cria novos vetores E[] e D[]

    for(int i = 0; i < tamEsq; i++) // Copia dados para os vetores temporários E[] e D[] ∗/
        E[i] = V[inicio + i];

    for(int j = 0; j < tamDir; j++) // Copia V[q + 1 ... r] para D[0 ... tamDir - 1]
        D[j] = V[meio + 1 + j];

    int i = 0, j = 0;

    int k = inicio; // Índice inicial do subvetor mesclado

    while(i < tamEsq && j < tamDir) { // Enquanto L e R tiverem elementos não mesclados
        comparacoes++;
        trocas++;
        if(E[i] <= D[j]) {
            V[k] = E[i];
            i++;
        } else {
            V[k] = D[j];
            j++;
        }
        k++;
    }

    while(i < tamEsq) { // Copia o restante de L, se houver
        comparacoes++;
        trocas++;
        V[k] = E[i];
        i++;
        k++;
    }

    while(j < tamDir) { // Copia o restante de R, se houver
        comparacoes++;
        trocas++;
        V[k] = D[j];
        j++;
        k++;
    }
}

void MergeSort(int V[], int inicio, int fim, int &trocas, int &comparecoes) {
    if(inicio < fim) { // Se há mais de um elemento
        int meio = (inicio + fim) / 2;
        MergeSort(V, inicio, meio, trocas, comparecoes); // Ordena recursivamente o primeiro subvetor
        MergeSort(V, meio + 1, fim, trocas, comparecoes); // Ordena recursivamente o segundo subvetor
        Merge(V, inicio, meio, fim, trocas, comparecoes); // Combina os subvetores ordenados
    }
}

int main() {
    int vetor_aleatorio[] = {5, 2, 9, 1, 5, 6};
    int vetor_ordenado[] = {1, 2, 3, 4, 5, 6};
    int vetor_inversamente_ordenado[] = {6, 5, 4, 3, 2, 1};

    int tamanho = 6;
    int trocas = 0;
    int comparacoes = 0;

    MergeSort(vetor_aleatorio, 0, tamanho - 1, trocas, comparacoes);
    cout << "Vetor Aleatório: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    MergeSort(vetor_ordenado, 0, tamanho - 1, trocas, comparacoes);
    cout << "Vetor Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    trocas = 0;
    comparacoes = 0;

    MergeSort(vetor_inversamente_ordenado, 0, tamanho - 1, trocas, comparacoes);
    cout << "Vetor Inversamente Ordenado: " << trocas << " Trocas e " << comparacoes << " Comparações" << endl;

    return 0;
}