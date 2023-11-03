#include <stdio.h>
#include <stdlib.h>

typedef struct Placas{
    int *placas;
    int tam;
}Placas;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fixup(int *placas, int i){
    while(i > 1 && placas[i / 2] > placas[i]){
        swap(&placas[i], &placas[i/2]);
        i /= 2;
    }
}

void fixdown(int *placas, int tam, int i){
    while(i * 2 <= tam){
        int menor = i * 2;
        if(menor < tam && placas[menor] > placas[menor + 1]){
            menor++;
        }
        if(placas[i] <= placas[menor]){
            break;
        }

        swap(&placas[i], &placas[menor]);
        i = menor;
    }
}

void PQinsert(Placas *placas, int p){
    placas->placas[++placas->tam] = p;
    fixup(placas->placas, placas->tam);
}

int PQremove(Placas *placas){
    if(placas->tam == 0)
        return -1;

    int topo = placas->placas[1];
    placas->placas[1] = placas->placas[placas->tam--];
    fixdown(placas->placas, placas->tam, 1);

    return topo;
}

int main(){
    
    Placas placas;
    placas.tam = 0;
    placas.placas = (int*)malloc(sizeof(int) * 2000000);

    int op, p, v[100];
    
    while(scanf("%d %d", &op, &p) != EOF){
        if(op == 1){
            PQinsert(&placas, p);
        }
        else{
            int n;
            for(n = 0; n < p; n++){
                int menor = PQremove(&placas);
                if(menor == -1){
                    break;
                }
                v[n] = menor;
            }
            for(int i = 0; i < n; i++){
                printf("%d ", v[i]);
                PQinsert(&placas, v[i]);
            }
            printf("\n");
        }
    }

    return 0;
}