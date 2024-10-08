#include <iostream>

using namespace std;

void Merge(int V[], int p, int q, int r) {
    int tamEsq = q - p + 1; // Comprimento de V[p ... q]
    int tamDir = r - q; // Comprimento de V[q + 1 ... r]
    int E[tamEsq], D[tamDir]; // Cria novos vetores E[] e D[]
    for(int i = 0; i < tamEsq; i++) // Copia dados para os vetores temporários E[] e D[] ∗/
        E[i] = V[p + i];
    for(int j = 0; j < tamDir; j++) // Copia V[q + 1 ... r] para D[0 ... tamDir - 1]
        D[j] = V[q + 1 + j];
    int i = 0, j = 0; // Índices iniciais de L e R
    int k = p; // Índice inicial do subvetor mesclado
    while(i < tamEsq && j < tamDir) { // Enquanto L e R tiverem elementos não mesclados
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
        V[k] = E[i];
        i++;
        k++;
    }
    while(j < tamDir) { // Copia o restante de R, se houver
        V[k] = D[j];
        j++;
        k++;
    }
}

void MergeSort(int V[], int p, int r) {
    if(p < r) { // Se há mais de um elemento
        int q = (p + r) / 2; // Calcula o ponto médio
        MergeSort(V, p, q); // Ordena recursivamente o primeiro subvetor
        MergeSort(V, q + 1, r); // Ordena recursivamente o segundo subvetor
        Merge(V, p, q, r); // Combina os subvetores ordenados
    }
}

int main() {

}