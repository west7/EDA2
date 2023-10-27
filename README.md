# EDA2
Este repositório é dedicado a disciplina de 'Estrutura de dados e algoritmos 2' da Universidade de Brasília.

# Apostila

# 1. Hash Table
É uma estrutura do tipo chave-valor, onde as chaves são usadas como índice para achar o elemento desejado. A chave é passada por uma função (normalmente o módulo) onde é gerado o índice/endereço na tabela. Esta função tem caráter determinístico ou seja, uma mesma chave sempre gera um mesmo endereço. Dessa forma é possível acessar qualquer elemento da tabela em grandeza constante O(1).

- Função de hashing:
---
```
int hash(int k, int m)
{
    return k % m;
}
```
---

## 1.1 Colisões

As colisões são um problema comum das tabelas hash, ocorrem quando duas chaves diferentes resultam no mesmo endereço. Existem várias técnicas para resolver colisões.

### 1.1.1 Endereçamento aberto
---
A estratégia do Endereçamento aberto, consiste basicamente em: se houver colisão, aloque o elemento 1 endereço pro lado. Porém, caso o número de colsões seja muito grande a busca passa a ser <b>linear (O(n))</b>, e não mais <b>constante (O(1))</b>.  

Por isso é interessante definir um número máximo de colisões para a hash, 10 por exemplo. Assim o tempo continuria sendo <b>constante (O(10))</b>. Mas, caso o limite de colisões esteja sendo muito excedido, há a chance de ter de crescer a tabela, que custa O(n).

### 1.1.2 Doouble Hash
---
A estratégia consiste em: quando ocorrer uma colisão, aplicar uma nova  função hash ao elemento desta forma, os elementos colididos ficariam mais espaçados entre si, diferente da estratégia anterior. Também é interessante manter um limite de colisões, para não preencher a tabela de forma rápida.

- Exemplo:
---
```
    #define HASH(K, M) (K % M)
    #define DOUBLE_HASH(K, M) (K % 2M)
```
---
Onde 'K' é a chave e 'M' é o tamanho da hash table.

### 1.1.3 Encadeamento separado
---
Cada posição da hash table seria a cabeça de uma lista encadeada. Ou seja, sempre que ocorresse uma colisão, o elemento simplesmente seria adicionado ao início da lista encadeada. Diferente das outras, nessa estratégia é mais difícil que o número de colisões fique muito grande, já que elementos colididos não ocupam a posição de outros elementos, tal que, mesmo que em uma chave específica o acesso seja linear, em outros endereços ele continuria a ser constante. Logo, vale avaliar cada caso e verificar se um limite de colisões se torna necessário ou não.

### 1.2 Bônus - Discussão sobre complexidades

|   | Inserção | Remoção | Busca | Crescer |
|---|-------------|-------------|-------------|----|
| **Vetor não ordenado** | O(1)| O(1)| O(n) |O(n) |
| **Vetor Ordenado** | O(n)| O(n)| O(log n)| O(n) |
| **Lista encadeada não ordenada** | O(1) | O(n) | O(n) |Dinâmico |
|**Lista encadeada ordenada**| O(n) | O(n) | O(n) |Dinâmico |
|**Hash Table**|O(1) |O(1) |O(1) | O(n) |
|**Árvores binárias**|O(log n) |O(log n) |O(log n) | Dinâmico|


# Árovere Red Black

# Heap

# Grafos
Grafos são um conjunto de vértices e arestas.

## 4.1 Grafos dirigidos
São grafos nos quais as arestas possuem direção, ou seja, se tenho uma aresta de '0' para '1', não necessariamente tenho uma aresta de '1' para '0'.

## 4.2 Grafo Completo
Todos os vértices são ligados entre si, ou seja, todo vértice tem uma aresta para cada outro vértice no grafo. Totalizando no máximo (v-1)/2 arestas, onde 'v' é o número de vértices.

# QuickSelect