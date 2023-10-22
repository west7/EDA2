#include <stdio.h>

int main(){

    int n, contador = 0;
    while(scanf("%d", &n) != EOF){
        contador++;
    }
    printf("%d\n", contador);

    return 0;
}