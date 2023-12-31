# Estrutura de Dados e Algoritmos 2

Este repositório é dedicado a disciplina de "Estrutura de dados e algoritmos 2" da Universidade de Brasília. Tem como objetivo documentar as [Listas de Exercícios](#listas-de-exercícios) disponibilizadas no juiz virtual [CD-MOJ](https://moj.naquadah.com.br/cgi-bin/index.sh). Bem como a [[Sumário|Apostila]] dos conteúdos desenvolvidos durante o semestre, as [provas](/README.md#provas-20232) aplicadas no semestre 2023.2 e o [trabalho final](/README.md#trabalho-final).

Professor: [Bruno Ribas.](https://www.brunoribas.com.br/)


# [Sumário da Apostila](/Apostila/Sumário.md)
### [Capítulo 1 - Hash Table](/Apostila/HashTable.md)

- 1.1 [Colisões](/Apostila/HashTable.md#11-colisões)
	- 1.1.1 [Endereçamento aberto](/Apostila/HashTable.md#111-endereçamento-aberto)
	- 1.1.2 [Double Hash](/Apostila/HashTable.md#112-double-hash)
	- 1.1.3 [Encadeamento Separado](/Apostila/HashTable.md#113-encadeamento-separado)
- 1.2 [Bônus - Discussão sobre complexidades](/Apostila/HashTable.md#12-bônus---discussão-sobre-complexidades)
### [Capítulo 2 - Árvore Red Black](/Apostila/ÁrvoreRedBlack.md)

- 2.1 [Structs](Apostila/ÁrvoreRedBlack.md#21-structs)
- 2.2 [Regras da Red Black](/Apostila/ÁrvoreRedBlack.md#22-regras-da-redblack)
	- 2.2.1 [Algoritmos de Balanceamento](/Apostila/ÁrvoreRedBlack.md#221-algoritmos-de-balanceamento)
	- 2.2.2 [Inserções em Árvore Red Black](/Apostila/ÁrvoreRedBlack.md#222-inserções-em-árvore-red-black)
	- 2.2.3 [Algoritmos de inserção](/Apostila/ÁrvoreRedBlack.md#223-algoritmos-de-inserção)
- 2.3 [Alturas de uma Red Black](/Apostila/ÁrvoreRedBlack.md#23-alturas-de-uma-red-black)
	- 2.3.1 [Altura total](/Apostila/ÁrvoreRedBlack.md#231-altura-total)
	- 2.3.2 [Altura Negra](/Apostila/ÁrvoreRedBlack.md#232-altura-negra)
- 2.4 [Bônus - Árvore 2-3](/Apostila/ÁrvoreRedBlack.md#24-bônus---árvore-2-3)

### [Capítulo 3 - Fila de Prioridades](/Apostila/FiladePrioridades.md)

- 3.1 [Conceitos](/Apostila/FiladePrioridades.md#31-conceitos)
	- 3.1.1 [Fila de Prioridades crescente e decrescente (Min heap e Max Heap)](/Apostila/FiladePrioridades.md#311-fila-de-prioridades-crescente-e-decrescente-min-heap-e-max-heap)
	- 3.1.2 [Item mínimo e item máximo](/Apostila/FiladePrioridades.md#312-item-máximo-e-item-mínimo)
	- 3.1.3 [Complexidades](/Apostila/FiladePrioridades.md#313-complexidades)
- 3.2 [Algoritmos](/Apostila/FiladePrioridades.md#32-algoritmos)
	- 3.2.1 [Structs e macros](/Apostila/FiladePrioridades.md#321-struct-e-macros)
	- 3.2.2 [Conserta para cima (swim)](/Apostila/FiladePrioridades.md#322-conserta-para-cima-swim)
	- 3.2.3 [Conserta para baixo (sink)](/Apostila/FiladePrioridades.md#323-conserta-para-baixo-sink)
	- 3.2.4 [Inserção, remoção e consulta](/Apostila/FiladePrioridades.md#324-inserção-remoção-e-consulta)
### [Capítulo 4 - Grafos](/Apostila/Grafos.md)

- 4.1 [Implementação](/Apostila/Grafos.md#41-implementação)
	- 4.1.1 [Matriz de Adjacência](/Apostila/Grafos.md#411-matriz-de-adjacência)
	- 4.1.2 [Lista de Adjacência](/Apostila/Grafos.md#412-lista-de-adjacência)
	- 4.1.3 [Bônus - Matriz x Lista](/Apostila/Grafos.md#413-bônus---matriz-x-lista)
- 4.2 [Grafo completo](/Apostila/Grafos.md#42-grafo-completo)
- 4.3 [Grafos dirigidos ou digrafos](/Apostila/Grafos.md#43-grafos-dirigidos-ou-digrafos)
- 4.4 [Conceitos](/Apostila/Grafos.md#44-conceitos)
	- 4.4.1 [Classificação de vértices](/Apostila/Grafos.md#441-classificação-de-vértices)
	- 4.4.2 [Caminho](/Apostila/Grafos.md#442-caminho)
	- 4.4.3 [Conectividade](/Apostila/Grafos.md#443-conectividade)
	- 4.4.4 [Grafos dirigidos conexos acíclicos](/Apostila/Grafos.md#444-grafos-dirigidos-conexos-acíclicos)
	- 4.4.5 [Grafo dirigido fortemente conexo](/Apostila/Grafos.md#445-grafo-dirigido-fortemente-conexo)
	- 4.4.6 [Fecho Transitivo](/Apostila/Grafos.md#446-fecho-transitivo)
	- 4.4.7 [Grafos ponderados(peso nas arestas)](/Apostila/Grafos.md#447-grafos-ponderados-peso-nas-arestas)
- 4.5 [Structs e algoritmos iniciais](/Apostila/Grafos.md#45-structs-e-algoritmos-inicias)
- 4.6 [Busca em Largura (BFS)](/Apostila/Grafos.md#46-busca-em-largura-bfs)
- 4.7 [Busca em Profundidade (DFS)](/Apostila/Grafos.md#47-busca-em-profundidade-dfs)
- 4.8 [Problemas Clássicos e Algoritmos Fundamentais](/Apostila/Grafos.md#48-problemas-clássicos-e-algoritmos-fundamentais)
	- 4.8.1 [Problema do Menor caminho](/Apostila/Grafos.md#481-problema-do-menor-caminho)
		- 4.8.1.1 [Dijkstra](/Apostila/Grafos.md#4811-dijkstra)
		- 4.8.1.2 [BellmanFord](/Apostila/Grafos.md#4812-bellman-ford)
	- 4.8.2 [Problema das árvores geradoras e árvores geradoras de custo mínimo (MST)](/Apostila/Grafos.md#problema-das-árvores-geradoras-e-árvores-geradoras-de-custo-mínimo-mst)
		- 4.8.2.1 [Prim](/Apostila/Grafos.md#4821-prim)
		- 4.8.2.2 [Kruskal](/Apostila/Grafos.md#4822-kruskal)
### [Capítulo 5 - Quickselect](/Apostila/Quickselect.md)





# Listas de Exercícios

Esta seção contém as listas de exercícios desenvolvidos na disciplina, para acessar os problemas basta clicar no link relacionado ao nome do exercíco em questão. E para acessar as soluções clique no título da lista desejada.

---
## [Lista I - Desenferrujando para semestre](listas/lista1-desenferrujando)  

A primeira lista é voltada para revisão e familiarização com o formato das listas.

- A : [Olá Mundo](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/olamundo.pdf)
- B : [Soma2](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/soma2.pdf)
- C : [SomaN](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/soma.pdf)
- D : [EOF](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/eof.pdf)
- E : [Viagem Aconselha](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/viagemaconselha.pdf)
- F : [Desfazer No Editor/cntrl z](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/ctrl-z.pdf)
- G : [Cofrinhos da vó Vitória](https://br.spoj.com/problems/COFRE.pdf)
- H : [Ultrapassa Minimamente](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/ultrapassaminimamente.pdf)
- I : [Soma String](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/soma_string.pdf)
- J : [Quem vai ser Reprovado](https://br.spoj.com/problems/PLACAR.pdf)
- K : [Frequência na aula](https://br.spoj.com/problems/FREQUE12.pdf) 
- L : [Analisando dados de degustação](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/sequencia-desgustacao.pdf)
- M : [Número Proibido](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/proibido.pdf)
- N : [Notas da Turma](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/divide-turma.pdf)
- O : [Mescla Listas](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-lista1-relembrando/le-junta.pdf)
---
## [Lista II - hashing](listas/lista2-hashing/)

A segunda lista tinha o objetivo de resolver exercícios relacionados à [Hash Table](/Apostila/HashTable.md).

- A : [Desfile dos Patos](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-hash/desfile.pdf)
- B : [Diga-me a frequência](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-hash/digafrequencia.pdf)
- C : [Eleição U.R.S.A.L](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-hash/eleicao-ursal-big.pdf)
- D : [Notas Curiosas](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-hash/notas.pdf)
- E : [Notas](https://br.spoj.com/problems/NOTAS14.pdf)
- F : [HashIT!](https://www.spoj.com/problems/HASHIT.pdf)
- G : [Hash](https://br.spoj.com/problems/HASHADIQ.pdf) 
- H : [Mensagens Nlogoniences](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-hash/mensagens.pdf)
---
## [Listas III - Priority Queue](listas/lista3-priorityQueue/)

A terceira lista contém exercícios de [Heap](/Apostila/FiladePrioridades.md).

- A : [Menores Placas](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-pq/menores-placas.pdf)
- B : [Churrascarias da Avenida](https://br.spoj.com/problems/CHURRASC.pdf)
- C : [Minimun Stocks](https://www.spoj.com/problems/MINSTOCK.pdf)
---

## [Lista IV - QuickSelect](listas/lista4-quickSelect/)

A quarta lista tem como enfoque o algoritmo [Quickselect](/Apostila/Quickselect.md), um algoritmo de busca baseado no algoritmo de ordenação QuickSort

- A : [Classificados de Sementes](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-quickselect/classificado-agronomia.pdf)
- B : [kk-página](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-quickselect/kk-pagina.pdf)
- C : [Desfile dos Patos - QuickSelect](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-quickselect/desfile.pdf)
- D : [Menores Placas - QuickSelect](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-quickselect/menores-placas.pdf)
---

## [Lista V - Grafos, o início](listas/lista5-grafos/)

A quinta lista introduz os conceitos e algoritmos básicos de [Grafos](/Apostila/Grafos.md).

- A : [Eu vou estar lá!](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos/euvouestarla.pdf)
- B : [Estradas asfaltadas](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos/grafo-nucleos-cidades.pdf)
- C : [Estradas asfaltadas - viagem aérea](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos/grafo-ajude-joao.pdf)
- D : [Natureza](https://br.spoj.com/problems/NATUREZA.pdf)
- E : [Ir e vir](https://br.spoj.com/problems/IREVIR.pdf)
---

## [Lista VI - Busca em Grafos](/listas/listas6-buscasEmGrafos)

A sexta lista coloca em prática alguns dos algoritmos fundamentais de [Grafos](/Apostila/Grafos.md), como o [Algoritmo de Dijkstra](/Apostila/Grafos.md#4811-dijkstra) e o [Algoritmo de BellmanFord](/Apostila/Grafos.md#4812-bellman-ford).

- A: [Estradas asfaltadas - perguntando conexões](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos-busca/grafo-nlogonia-conexoes.pdf)
- B: [Cai fora LAG](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos-busca/grafo-chp.pdf)
- C: [Caminho das Pontes](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos-busca/pontes.pdf)
- D: [O chão virou lava](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos-busca/o_chao_e_lava.pdf)
- E: [Regra dos seis apertos de mão](https://moj.naquadah.com.br/contests/bcr-EDA2-2023_2-grafos-busca/handshakes-rule.pdf)
---

# [Trabalho Final](https://github.com/smmstakes/MicroMouse-2023.2)


O Trabalho final da disciplina é dedicado a solucionar o problema do [Micromouse](https://www.brunoribas.com.br/eda2/2023-2/micromouse-rank.pdf), e possui um [repositório exclusivo](https://github.com/smmstakes/MicroMouse-2023.2).


# Provas-2023.2


## P1

## P2

## P3
