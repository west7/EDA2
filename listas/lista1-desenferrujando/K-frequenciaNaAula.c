#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vet[1000001];

int main(){
    
    int n;
    int al = 0;
    int reg;

    scanf("%d", &n);

    for(int i=n; i != 0; i--){
        scanf("%d", &reg);
        vet[reg]++;
    }

    for(int i=0; i < 1000001; i++){
        al += vet[i] > 0;
    }

    printf("%d\n", al);
    
    return 0;
}