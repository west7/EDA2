#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
  char matricula[10];
  double mediaAtividades;
  double mediaProvas;
  struct celula *prox;
} celula;

void relatorioMediaAtividades (celula *le, celula *l1, celula *l2, double media){
    
    celula *aux = le->prox;
    celula *auxl1 = l1;
    celula *auxl2 = l2;

    l1->prox = NULL;
    l2->prox = NULL;
    
    while(aux != NULL){
        if(aux->mediaAtividades > media){
            auxl2->prox = aux;
            auxl2 = aux;
        }else{
            auxl1->prox = aux;
            auxl1 = aux;
        }
        aux = aux->prox;
    }

    auxl1->prox = NULL;
    auxl2->prox = NULL;
}