# Exercícios ED2 - Rafael Manfrim

## Exercícios.pdf

#### Implemente em C/C++ as operações de inserção e remoção em uma lista singularmente ligada.

```c++
    
```

#### Implemente em C/C++ uma fila utilizando duas pilhas. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

#### Implemente em C/C++ uma pilha utilizando duas filas. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

#### Implemente em C/C++ uma pilha usando lista singularmente ligada. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

#### Implemente em C/C++ uma pilha usando lista duplamente ligada. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

#### Implemente em C/C++ uma fila usando lista singularmente ligada. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

#### Implemente em C/C++ uma fila usando lista duplamente ligada. Analise a complexidade computacional das operações de inserção e remoção de seu código.

```c++

```

## Exercícios 2.pdf

#### Além do tempo de execução, quais outras medidas de eficiência você poderia precisar considerar em um cenário do mundo real?

```

```

#### Selecione uma estrutura de dados que você já tenha visto e discuta suas forças e limitações.

```

```

#### Sugira um problema do mundo real em que apenas a melhor solução é aceitável. Em seguida, proponha um em que uma solução aproximada seja boa o suficiente.

```

```

#### Descreva um exemplo do mundo real que requer ordenação de elementos.

```

```

#### Descreva um problema do mundo real em que todos os dados de entrada estão disponíveis antes de você precisar resolver o problema.

```

```

#### Descreva um problema do mundo real em que os dados de entrada não estão inteiramente disponíveis de antemão e chegam ao longo do tempo.

```

```

#### Considere que temos o seguinte problema: queremos contar o número de pares em um vetor que somam a um valor específico. Modelando computacionalmente, nossa entrada é um vetor de n elementos e nossa saída é um número inteiro representando o número de pares que somam a um valor v.
#### Por exemplo, suponha que o vetor seja [1, 4, 3, 2] e o valor para a soma seja 5. Vamos encontrar todos os pares de elementos que somam 5:
- O par (1, 4) soma 5.
- O par (3, 2) soma 5.
#### Então, neste exemplo, há 2 pares de elementos que somam 5. Vamos criar um algoritmo que resolve esse problema.
```c++
#include<iostream>
int conta_pares_sol_um(int *vetor, int n, int soma) {
    int pares = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(vetor[i] + vetor[j] == soma)
                pares++;
        }
    }
    return pares;
}
int main() {
    int vetor[] = {1, 5, 7, 4, 2, 5};
    int n = sizeof(vetor) / sizeof(vetor[0]);
    int soma = 6;
    int pares = conta_pares_sol_um(vetor, n, soma);
    std::cout << "Número de pares:" << pares;
    return 0;
}
```

#### Determine a sua complexidade de tempo no pior caso utilizando a notação-O.

```

```

#### Aqui está outra solução

```c++
#include<iostream>
int conta_pares_sol_dois(int *vetor, int n, int soma) {
    int ocorrencias[1000] = {0}; //Assumindo que os valores estão entre 0 e 999
    int pares = 0;
    for(int i = 0; i < n; i++) {
        int complemento = soma - vetor[i];
        if(complemento >= 0 && ocorrencias[complemento])
            pares += ocorrencias[complemento];
        ocorrencias[vetor[i]]++;
    }
    return pares;
}
```

#### Como ela funciona? Determine a sua complexidade de tempo no pior caso utilizando a notação-O.

```

```

#### Encontrar a soma de subvetores de tamanho fixo em um vetor. Consiste em calcular a soma de todos os subvetores de um determinado tamanho fixo k em um vetor dado. Um subvetor é uma sequência contígua de elementos dentro de um vetor. Por exemplo, vamos considerar o vetor V = [1, 2, 3, 4, 5] e k = 3.
- Subvetor 1: [1, 2, 3] Soma = 1 + 2 + 3 = 6
- Subvetor 2: [2, 3, 4] Soma = 2 + 3 + 4 = 9
- Subvetor 3: [3, 4, 5] Soma = 3 + 4 + 5 = 12
#### Portanto, para o vetor V , com k = 3, o resultado é 6, 9 e 12. Criem um algoritmo que resolva este problema.

```c++

```

#### Determine a sua complexidade de tempo no pior caso utilizando a notação-O.

```

```

#### Caso crie um algoritmo de complexidade quadrática ou similar, ponderem: é possível criar um algoritmo mais eficiente? Caso não seja possível, argumente a razão dessa impossibilidade. Caso seja possível, escreva o algoritmo e determine a sua complexidade utilizando a notação-O.

```

```

#### Você pediu uma pizza de mussarela de n fatias para você e seus colegas. Entretanto, vocês possuem gostos diferentes. Alguns gostam de cebola e outros de calabresa. Deste modo, decidiram pedir uma pizza metade cebola e metade calabresa. Infelizmente, o entregador não teve os cuidados necessários no transporte, e a pizza chegou com as coberturas misturadas. Não era possível identificar as metades, sendo que toda a pizza ficou com rodelas de calabresa e tiras de cebola. As tiras grudaram na mussarella e não é possível removê-las. A pizza já veio cortada em 16 pedaços (é uma pizza muito grande). Você gosta bem mais de calabresa do que de cebolas, portanto, deseja pegar os pedaços que tem mais calabresa. Entretanto, seus colegas não gostaram de suas exigências por pedaços específicos, e definiram que se você escolher um pedaço, terá que pegar os outros logo em sequência (para à direita ou à esquerda). Seu objetivo é selecionar k pedaços, k > 0, onde você obtenha a maior diferença possível entre rodelas de calabresa e tiras de cebola. Você deseja maximizar o total das diferenças entre calabresas e cebolas consumidas, independente do número de fatias que comer. Ou seja, cada calabresa no pedaço conta positivamente para o “valor” do pedaço, e cada cebola conta negativamente. Por exemplo, você pode escolher três pedaços em sequência, onde:
- Pedaço 1: 3 calabresas e 1 cebola.
- Pedaço 2: 1 calabresa e 2 cebolas.
- Pedaço 3: 4 calabresas e 2 cebolas.
#### Obtendo uma diferença final de 3. Seu objetivo é maximizar essa diferença, independente do número de fatias consumidas, podendo ser apenas uma fatia, ou a pizza inteira. O número de pedaços consumidos não é relevante, portanto, pode tratar situações de empate como preferir. Criem um algoritmo que resolva este problema.

```c++

```

#### A solução deve ser ótima, ou seja, a melhor solução possível.  Determine a sua complexidade de tempo no pior caso utilizando a  notação-O.

```

```

#### (1) Implemente em C/C++ o algoritmo da Busca Binária de acordo com a explicação anterior. O algoritmo tradicional verifica se o elemento central é igual ao elemento buscado. Mas teremos um algoritmo mais eficiente (não no sentido assintótico) se evitarmos essa comparação até o fim.

```c++
    
```

#### (2) Implemente em C/C++ o algoritmo da Busca Binária realizando essa verificação apenas quando sobrar um único elemento.

```c++

```

#### (3) Demonstre que a Busca Binária executa em O(log2 n).

```

```

```c++
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

#### Aplique manualmente o algoritmo ConstroiHeapMaximo no vetor V = {5, 3, 17, 10, 84, 19, 6, 22, 9} e exiba todos os passos intermediários.

```

```

#### Aplique manualmente o Heap Sort no vetor V = {5, 13, 2, 25, 7, 17, 20, 8, 4} e exiba todos os passos intermediários.

```

```

#### Qual é o tempo de execução do Heap Sort em um vetor de comprimento n que já está ordenado em ordem crescente?

```

```

#### Implemente o Heap Sort em C/C++.

```c++

```

#### É viável a implementação do algoritmo Heap Sort utilizando um Heap Mínimo? Analise as possíveis vantagens e desvantagens dessa abordagem em relação à utilização de um Heap Máximo.

```c++
    
```
