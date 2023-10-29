#include <stdio.h>
#include <stdlib.h>

void ultrapassaMin(int *v, int ini, int ifi, int ls, int soma){

    if(ini > ifi) return;

    soma += v[ini++];

    if (soma > ls){
        soma = 0;
        ultrapassaMin(v, ini, ifi, ls, soma);
        printf("%d\n", v[ini - 1]);
    }else{
        ultrapassaMin(v, ini, ifi, ls, soma);
    }
    
}

int main(){
    
    int v_size = 1000;
    int *v = malloc(sizeof(int) * v_size);
    int n;
    int i =0;

    while(scanf("%d", &n) == 1 && n != 0){
        v[i] = n;
        i++;
        if(n >= v_size){
            v_size *= 2;
            v = realloc(v, sizeof(int) * v_size);
        }
    }

    int soma_min;
    scanf("%d", &soma_min);

    ultrapassaMin(v, 0, i - 1, soma_min, 0);
    
    return 0;

}