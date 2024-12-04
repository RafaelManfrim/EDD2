# Aula 8 e 9


#### 1. Qual é a complexidade computacional, no pior caso, do tempo para inserir um novo nó em uma Árvore AVL? Em que situação ocorre o pior caso?

```
A altura h da árvore AVL é mantida aproximadamente em log(n), para encontrar a 
posição correta para inserir o novo nó, percorremos a árvore a partir da raiz até 
uma folha, o que leva no máximo O(h). Caso tenhamos rotações para rebalanceamento, 
não altera o tempo de execução, pois elas executam em O(1).
```

#### 2. Qual é a complexidade computacional, no pior caso, do tempo para buscar um nó em uma Árvore AVL? Em que situação ocorre o pior caso?

```
Em uma árvore AVL, no pior caso, precisamos andar pela altura toda dela para buscar 
um elemento, ou seja, O(h), que é o mesmo que O(log n). O pior caso ocorre quando
o elemento está em uma das folhas ou não está presente na árvore.
```

#### 3. Implemente em C/C++ os códigos para rotação à esquerda e rotação à direita. Garanta que os fatores de balanceamento sejam atualizados durante o processo de rotação.

```

```

#### 4. Implemente em C/C++ as funções ATUALIZACAO-BALANCEAMENTOS e REBALANCEARSUBARVORE. Na função REBALANCEARSUBARVORE, assegure-se de tratar os quatro casos distintos de desbalanceamento que podem ocorrer em uma árvore AVL.

```

```

#### 5. Finalmente, implemente a Árvore AVL e sua operação de inserção balanceada em C/C++. Ou seja, incluindo os códigos de rotação e atualização dos fatores de balanceamento.

```

```

#### 1. Qual é a complexidade computacional, no pior caso, do tempo para deletar um nó em uma Árvore AVL? Em que situação ocorre o pior caso?

```
Assim como na inserção, a deleção também tem complexidade computacional de O(h),
que também pode ser escrita como O(log n), pois é preciso andar pela altura da
árvore em busca do nó desejado. Caso seja necessário fazer o balanceamento 
da árvore a complexidade não é alterada pois as rotações executam em O(1).
```

#### 2. Descrevam os cinco casos simétricos não analisados nos slides anteriores. Descrevam suas soluções.

```

```

#### 3. Implemente em C/C++ a operação de deleção balanceada da Árvore AVL. Adicione esse código aos códigos da aula anterior. Dica: utilize uma abordagem recursiva.

```

```