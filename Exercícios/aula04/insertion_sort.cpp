#include <iostream>

using namespace std;

void insertionSort(int V[], int n) {
    int j, chave;
    for(int i = 1; i < n; i++) {
        chave = V[i];
        j = i - 1;
        while(j >= 0 && V[j] > chave) {
            V[j + 1] = V[j];
            j = j - 1;
        }
        V[j + 1] = chave;
    }
}

int main() {

}