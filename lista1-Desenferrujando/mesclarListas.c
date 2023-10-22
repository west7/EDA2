#include <stdio.h>

typedef struct celula {
   int dado;
   struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){

    l3->prox = NULL;
    celula *auxl1 = l1->prox;
    celula *auxl2 = l2->prox;
    celula *auxl3 = l3;

    while(auxl1 != NULL && auxl2 != NULL){
        if(auxl1->dado <= auxl2->dado){
            auxl3->prox = auxl1;
            auxl1 = auxl1->prox;
        }else{
            auxl3->prox = auxl2;
            auxl2 = auxl2->prox;
        }
        auxl3 = auxl3->prox;
    }

    while (auxl1 != NULL) {
        auxl3->prox = auxl1;
        auxl1 = auxl1->prox;
        auxl3 = auxl3->prox;
    }

    while (auxl2 != NULL) {
        auxl3->prox = auxl2;
        auxl2 = auxl2->prox;
        auxl3 = auxl3->prox;
    }
}