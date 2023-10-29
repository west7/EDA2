#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (){
    
    int n;

    scanf("%d", &n);
    getchar(); //consome new line
    
    for(int i=0; i < n; i++){
        int soma = 0;
        char c;

        while((c = getchar()) != '\n'){
            if(isdigit(c)){
                soma += c - '0'; // converte char para int
            }
        }
        printf("%d\n", soma);  
        }
    return 0;
}