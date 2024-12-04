# ED2 - Aula 10.pdf - Rafael Manfrim

#### 1. Considere uma Tabela Hash com 9 posições e a função hash h(k) = k mod 9. Demonstre o que acontece ao inserir as chaves 5, 28, 19, 15, 20, 33, 12, 17, 10, com as colisões resolvidas por encadeamento (Cormen 11.2-2).

```

```

#### 2. O Professor Marley hipotetiza que pode obter ganhos substanciais de desempenho ao modificar o esquema de encadeamento para manter cada lista em ordem crescente. Como a modificação do professor afeta o tempo de execução para buscas bem-sucedidas, buscas malsucedidas, inserções e deleções? (Cormen 11.2-3).

```
Para a inserção, no pior caso teremos O(n) quando a lista está ordenada em ordem crescente, já na lista desordenada, a inserção pode ser O(1) colocando sempre o novo elemento no começo.
Já na busca, ambos são O(n), porém a busca ordenada pode ganhar desempenho ao buscar elementos ausentes caso chegue a um elemento maior do que o elemento buscado, pode-se parar a busca.
Na deleção, segue-se o mesmo ganho da busca.
```

#### 3. Insira as chaves 10, 22, 31, 4, 15, 28, 17, 88, 59 em uma Tabela Hash de tamanho m = 11 utilizando endereçamento aberto. Ilustre o resultado da inserção dessas chaves usando sondagem linear com h(k, i) = (k + i) mod m e usando dupla sondagem com h1 (k) = k e h2 (k) = 1 + (k mod (m − 1)) (Cormen 11.4-1).

```

```