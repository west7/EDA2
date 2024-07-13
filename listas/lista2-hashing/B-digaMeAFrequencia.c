
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Contagem{
    char c;
    int cont;
}Contagem;

int comparar(const void *a, const void *b)
{
    const Contagem *contA = (const Contagem *)a;
    const Contagem *contB = (const Contagem *)b;

    if(contA->cont > contB->cont){
        return  1;
    }else if(contB->cont > contA->cont){
        return -1;
    }

    if(contA->c > contB->c){
        return 1;
    }else if (contB->c > contA->c){
        return -1;
    }

    return 0;
}


int main(){
    char line[1001];

    while(scanf("%s", line) != EOF)
    {
        Contagem arr[128] = {0};
        int n = strlen(line);
        
        for(int i=0; i < n; i++){
        
            char c = line[i];

            arr[c].c = c;
            arr[c].cont++;       
        }

        qsort(arr, 128, sizeof(Contagem), comparar);        

        for (int i = 0; i < 128; i++) {
            if(arr[i].cont > 0){
                printf("%d %d\n", arr[i].c, arr[i].cont);
            }
        }
        printf("\n");
    }   
    
    
    return 0;
}