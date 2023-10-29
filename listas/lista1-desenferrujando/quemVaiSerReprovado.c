#include <stdio.h>
#include <string.h>

int main(){
    
    int n;
    int c = 1;

    while(scanf("%d", &n) != EOF){
        char nome[21];
        int nota;
        char rep[21];
        int minnota = 11;

        for(int i=0; i < n; i++){
            scanf("%s %d", nome, &nota);

            if(nota < minnota || (nota == minnota && strcmp(nome, rep) > 0)){
                minnota = nota;
                strcpy(rep, nome);
            }
        }
        printf("Instancia %d\n", c++);  
        printf("%s\n\n", rep);
    }
    return 0;
}