#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    int votos;
} Candidato;

#define codigo(A) (A.codigo)
#define votos(A) (A.votos)
#define less(A,B) ((votos(A) == votos(B)) ? (codigo(A) > codigo(B)) : (votos(A) > votos(B))) //(votos(A) > votos(B)) 
#define exch(A,B) { Candidato tt; tt = A; A = B; B = tt; }
#define cmpexch(A,B) {if (less(B,A)) exch(A,B)}


int separa(Candidato *v, int l, int r)
{
    Candidato pivo = v[r];
    int j = l;
    for (int k = l; k < r; k++)
        if (less(v[k], pivo))
        {
            exch(v[k], v[j]);
            j++;
        }
    exch(v[j], v[r]);
    return j;
}

void quicksortM3(Candidato *v, int l, int r)
{
    if (r - l <= 16)
        return;

    exch(v[(l + r) / 2], v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(Candidato *v, int l, int r)
{
    for (int i = r; i > l; i--)
        cmpexch(v[i - 1], v[i]);

    for (int i = l + 2; i <= r; i++)
    {
        int j = i;
        Candidato m = v[j];
        while (less(m, v[j - 1]))
        {
            v[j] = v[j - 1];
            j--;
        }
        v[j] = m;
    }
}

void quicksort(Candidato *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}


int main(void)
{
    int S, F, E;
    scanf("%d %d %d", &S, &F, &E);
    
    int candidato;

    Candidato *presidente = calloc(100, sizeof(Candidato)), 
         *senador = calloc(1000, sizeof(Candidato)), 
         *depFed = calloc(10000, sizeof(Candidato)), 
         *depEst = calloc(100000, sizeof(Candidato));
    
    int val = 0, nulos = 0;
    int tot = 0;

    while (scanf("%d", &candidato) == 1)
    {
        if (candidato > 0)
        {
            val++;

            if (candidato >= 10000)
            {
                if (depEst[candidato].codigo == 0) depEst[candidato].codigo = candidato; 
                depEst[candidato].votos++;
            }
            else if (candidato >= 1000)
            {
                if (depFed[candidato].codigo == 0) depFed[candidato].codigo = candidato; 
                depFed[candidato].votos++;
            }

            else if (candidato >= 100)
            {
                if (senador[candidato].codigo == 0) senador[candidato].codigo = candidato; 
                senador[candidato].votos++;
            }
            else
            {
                if (presidente[candidato].codigo == 0) presidente[candidato].codigo = candidato;
                presidente[candidato].votos++;
                tot++;
            }
        }
        else
            nulos++;
    }

    int aux = 0;
    for (int i = 0; i < 100; i++)
        if (presidente[i].votos)
            presidente[aux++] = presidente[i];
    quicksort(presidente, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 1000; i++)
        if (senador[i].votos)
            senador[aux++] = senador[i];
    quicksort(senador, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 10000; i++)
        if (depFed[i].votos)
            depFed[aux++] = depFed[i];
    quicksort(depFed, 0, aux);
    
    aux = 0;
    for (int i = 0; i < 100000; i++)
        if (depEst[i].votos)
            depEst[aux++] = depEst[i];
    quicksort(depEst, 0, aux);

    printf("%d %d\n", val, nulos);

    if ((float) presidente[0].votos/tot >= 0.51)
        printf("%d\n", presidente[0].codigo);
    else
        printf("Segundo turno\n");
    
    for (int i = 0; i < S; i++)
        printf("%d ", senador[i].codigo);   
    printf("\n");

    for (int i = 0; i < F; i++)
        printf("%d ", depFed[i].codigo);   
    printf("\n");

    for (int i = 0; i < E; i++)
        printf("%d ", depEst[i].codigo);   
    printf("\n");
    
    free(presidente);
    free(senador);
    free(depFed);
    free(depEst);

    return 0;
}