#include <stdio.h>


int main(){
    int n;
    scanf("%d", &n);

    int notas[101] = {0};

    int majorNota = -1;
    int notaMax = 0;

    for(int i=0; i < n; i++)
    {
        int nota;
        scanf("%d", &nota);
        notas[nota]++;
    }   

    for(int i=0; i <= 100; i++)
    {
        if(notas[i] >= notaMax)
        {
            notaMax = notas[i];
            majorNota = i;
        }
    } 
    printf("%d\n", majorNota);

    return 0;
}