#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Entrada{
    int qtd;
    char c;
    int pos;
}Entrada;

int compararEntradas(const void *a, const void *b){
    
    const Entrada *entA = (const Entrada *)a;
    const Entrada *entB = (const Entrada *)b;

    if (entA->qtd > entB->qtd){
        return -1;
    }else if(entA->qtd < entB->qtd){
        return 1;
    }

    return 0;
}

int main(){    
    char s[100001];
    fgets(s, sizeof(s), stdin);

    int len = strlen(s);

    //Entrada *entrada = (Entrada *)malloc(sizeof(Entrada) * len);

    Entrada entrada[len];
    if (s[len - 1] == '\n') {
        s[len - 1] = '\0'; 
        len--;
    }

    int i = 0;
    int num = 0;

    while(i < len){
        char c = s[i];
        int tam = 0;
        int ini = i;

        while(i < len && s[i] == c){
            tam++;
            i++;
        }

        entrada[num].c = c;
        entrada[num].pos = ini;
        entrada[num].qtd = tam;
        num++;
    }

    qsort(entrada, num, sizeof(Entrada), compararEntradas);

    for(int i=0; i<num; i++){
        printf("%d %c %d\n", entrada[i].qtd, entrada[i].c, entrada[i].pos);
    }
    
    return 0;
}