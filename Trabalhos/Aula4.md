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

```
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
```

Exemplo: {6, 5, 3, 1, 8, 7, 2, 4}.
#### (1) Determine a sua complexidade de tempo no pior caso utilizando a notação-O.

```

```

#### (1.1) Qual seria a propriedade da instância onde teríamos o pior caso?

```

```

#### (2) Determine a sua complexidade de tempo no melhor caso utilizando a notação-O.

```

```

#### (2.1) Qual seria a propriedade da instância onde teríamos o melhor caso?

```

```

#### (1) A animação representa perfeitamente o algoritmo apresentado do Merge Sort? Justifique sua resposta.

```

```

#### (2) Explique em muito detalhe o funcionamento da implementação fornecida do Merge Sort.

```

```

#### (3) O Bubble Sort é um algoritmo simples de ordenação que percorre uma lista, comparando pares de elementos adjacentes e trocando-os se estiverem na ordem errada. O processo é repetido até que a lista esteja ordenada. Implemente o algoritmo Bubble Sort. Mais detalhes do algoritmo no último slide.

```

```

#### (4) Determine a complexidade de tempo do Bubble Sort no pior caso e no melhor caso utilizando a notação-O.

```

```

#### (5) Qual o melhor caso para o Bubble Sort? Por quê? Qual o pior caso? Por quê?

```

```

#### (6) Por que o Bubble Sort geralmente é considerado menos eficiente que o Insertion Sort?

```

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