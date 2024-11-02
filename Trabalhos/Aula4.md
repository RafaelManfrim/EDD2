# ED2 - Aula 4.pdf - Rafael Manfrim

#### (1) Implemente em C/C++ o algoritmo da Busca Binária de acordo com a explicação anterior. O algoritmo tradicional verifica se o elemento central é igual ao elemento buscado. Mas teremos um algoritmo mais eficiente (não no sentido assintótico) se evitarmos essa comparação até o fim.

```c++
    
```

#### (2) Implemente em C/C++ o algoritmo da Busca Binária realizando essa verificação apenas quando sobrar um único elemento.

```c++

```

#### (3) Demonstre que a Busca Binária executa em O(log2 n).

```

```

#### Insertion Sort

#### (1) Determine a sua complexidade de tempo no pior caso utilizando a notação-O.

```
O pior caso se daria por N verificações e N - 1 trocas, ou seja N * (N - 1) / 2 seguindo a fórmula da soma de uma P.A.
Fazendo com que Soma = (N² - N) / 2, ignorando os termos de ordem inferior, a complexidade de tempo no pior caso é O(N²).
```

#### (1.1) Qual seria a propriedade da instância onde teríamos o pior caso?

```
O pior caso ocorre quando o vetor está ordenado de forma decrescente e o algoritmo faz a troca de todos os elementos com todos os elementos anteriores.
```

#### (2) Determine a sua complexidade de tempo no melhor caso utilizando a notação-O.

```
No melhor caso, o algoritmo faz N - 1 comparações e nenhuma troca, ou seja, O(N), o que é um ótimo resultado, mas não possui sentido prático, pois em raríssimos
casos o algoritmo iria executar com o vetor já ordenado.
```

#### (2.1) Qual seria a propriedade da instância onde teríamos o melhor caso?

```
O melhor caso ocorre quando o vetor já está ordenado em ordem crescente, não sendo necessário fazer nenhuma troca.
```

#### (1) A animação representa perfeitamente o algoritmo apresentado do Merge Sort? Justifique sua resposta.

```

```

#### (2) Explique em muito detalhe o funcionamento da implementação fornecida do Merge Sort.

```

```

#### Bubble Sort

#### (3) O Bubble Sort é um algoritmo simples de ordenação que percorre uma lista, comparando pares de elementos adjacentes e trocando-os se estiverem na ordem errada. O processo é repetido até que a lista esteja ordenada. Implemente o algoritmo Bubble Sort. Mais detalhes do algoritmo no último slide.

```c++
#include <iostream>

using namespace std;

void bubble_sort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j+1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

void imprime_vetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }
}

int main() {
    int vetor[] = {5, 2, 9, 1, 4, 6};
    int tamanho_vetor = 6;

    imprime_vetor(vetor, tamanho_vetor);

    cout << endl;

    bubble_sort(vetor, tamanho_vetor);

    imprime_vetor(vetor, tamanho_vetor);

    return 0;
}
```

#### (4) Determine a complexidade de tempo do Bubble Sort no pior caso e no melhor caso utilizando a notação-O.

```
Assim como no Insertion Sort, o Bubble Sort também tem seu pior caso como O(n²), pois precisará andar por todo o vetor e realizar N - 1 trocas, ou seja, N(N - 1) / 2, resultando em (N² - N) / 2. O melhor caso também é O(n), quando não for necessário fazer nenhuma troca.
```

#### (5) Qual o melhor caso para o Bubble Sort? Por quê? Qual o pior caso? Por quê?

```
O melhor caso seria quando o vetor já estivesse ordenado, pois seria necessário apenas percorrer ele fazendo verificações, sem realizar trocas, ou seja O(n). Já o pior caso ocorre quando o vetor está ordenado em ordem inversa, pois seria necessário realizar N - 1 trocas para cada N.
```

#### (6) Por que o Bubble Sort geralmente é considerado menos eficiente que o Insertion Sort?

```
O Bubble Sort tem como característica sempre realizar as comparações, e realizar trocas à mais do
que o Insertion Sort, pois após posicionar no local correto, o Insertion Sort não verifica e realiza
trocas com os elementos que ele sabe que já estão posicionados na posição correta.
```

#### (7) Em quais situações o Merge Sort é preferível ao Insertion Sort e ao Bubble Sort?

```

```

#### (8) Considere as listas de números abaixo. Para cada lista, aplique o Insertion Sort, Bubble Sort e Merge Sort e conte o número de comparações realizadas por cada algoritmo.
1. [5, 2, 9, 1, 5, 6]
2. [1, 2, 3, 4, 5, 6] (Lista já ordenada)
3. [6, 5, 4, 3, 2, 1] (Lista em ordem inversa)
#### Qual dos três algoritmos realizou o maior número de comparações em cada caso? Explique por que alguns algoritmos realizaram menos comparações em vetores já ordenados ou quase ordenadas.

```

```

#### (9) Considere um algoritmo que precisa ordenar uma lista onde os primeiros 50% dos elementos já estão ordenados, mas os últimos 50% estão em ordem inversa. Qual dos três algoritmos (Insertion Sort, Bubble Sort ou Merge Sort) você escolheria para esse caso? Justifique sua escolha baseando-se no comportamento de cada algoritmo.

```

```

#### (10) Implemente os três algoritmos (Insertion Sort, Merge Sort e Bubble Sort) e modifique o código para contar o número total de trocas e comparações realizadas durante a execução. Execute-os em vetores de diferentes tamanhos e ordens (aleatória, já ordenada, inversa, etc.).

```

```

#### (10.1) Como esses números variam entre os algoritmos e diferentes tipos de listas?

```

```