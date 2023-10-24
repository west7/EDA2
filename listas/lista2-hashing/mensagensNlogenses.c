#include <stdio.h>
#include <stdlib.h> 

#define MAX (int)1e7 + 19

struct Item{
    int k;
    char c;
};

int compare(const void *a, const void *b){
    return ((struct Item *)a)->k - ((struct Item *)b)->k;
}

int main(void){
    struct Item packages[200000];

    int cont = 0;

    while(cont < 200000){
        int num;
        char c;

        if (scanf("%d %c", &num, &c) == EOF) break;

        packages[cont].k = num;
        packages[cont].c = c;
        cont++;
    }

    if (cont > 0){

        qsort(packages, cont, sizeof(struct Item), compare);
    

        for(int i = 0; i < cont; i++){
            if(i == 0 || packages[i].k != packages[i - 1].k){
                printf("%c", packages[i].c);
            }
        }
        printf("\n");
    }

    return 0;
    
}