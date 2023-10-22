#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n);

    int notas[1001] = {0};
    int nota;
    int majorNota = 0;
    int notaMax = 0;

    for(int i=0; i < n; i++)
    {
        scanf("%d", &nota);
        notas[nota]++;
        if(notas[nota] > notaMax)
        {
            notaMax = notas[nota];
            majorNota = nota;
        }else if(notas[nota] == notaMax && nota > majorNota)
        {
            majorNota = nota;
        }
    }    
    printf("%d\n", majorNota);

    return 0;
}