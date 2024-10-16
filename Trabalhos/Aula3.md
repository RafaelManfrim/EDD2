# ED2 - Aula 3.pdf - Rafael Manfrim

#### Considere que temos o seguinte problema: queremos contar o número de pares em um vetor que somam a um valor específico. Modelando computacionalmente, nossa entrada é um vetor de n elementos e nossa saída é um número inteiro representando o número de pares que somam a um valor v.
#### Por exemplo, suponha que o vetor seja [1, 4, 3, 2] e o valor para a soma seja 5. Vamos encontrar todos os pares de elementos que somam 5:
- O par (1, 4) soma 5.
- O par (3, 2) soma 5.
#### Então, neste exemplo, há 2 pares de elementos que somam 5. Vamos criar um algoritmo que resolve esse problema.
```
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

```
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