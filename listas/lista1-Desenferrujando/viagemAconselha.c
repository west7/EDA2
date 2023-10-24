#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigo;
    int nota;
}Restaurante;

int main(){

    int dia = 1;
    while(1){
        int n;
        if(scanf("%d", &n) == EOF) break;

        Restaurante *rest = malloc(n * sizeof(Restaurante));

        for(int i=0; i<n; i++){
            scanf("%d %d", &rest[i].codigo, &rest[i].nota);
        }

        int menorCod = -1;
        int maiorNota = -1;

        for(int i=0; i<n; i++){
            if(rest[i].nota > maiorNota || (rest[i].nota == maiorNota && rest[i].codigo < menorCod)){

                maiorNota = rest[i].nota;
                menorCod = rest[i].codigo;
            }
        }

        printf("Dia %d\n", dia++);
        printf("%d\n\n", menorCod);

        free(rest);
    }
    return 0;
}