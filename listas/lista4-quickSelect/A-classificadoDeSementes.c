#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define lessNota(a ,b) (a.nota == b.nota ? a.cod < b.cod : a.nota < b.nota)
#define lessCod(a, b) (a.cod == b.cod ? a.nota < b.nota : a.cod < b.cod)
#define swap(a, b)\
    {             \
        Semente temp = a; \
        a = b;    \
        b = temp; \
    }

#define cmpswapNota(a, b)\
   if(lessNota(b, a))    \
        swap(a, b)       

#define cmpswapCod(a, b)\
    if(lessCod(b, a))   \
        swap(a, b)      

typedef struct Semente{
    long long cod;
    int nota;
}Semente;

int separaCod(Semente *v, int l, int r)
{
    Semente pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
        if(lessCod(v[i], pivo))
        {
            swap(v[i], v[j]);
            j++;
        }
        
    swap(v[j], v[r]);
    return j;
}

void quicksortM3(Semente *v, int l, int r)
{
    if(r - l <= 32) return;

    int mid = (l + r) / 2;

    swap(v[mid], v[r - 1]);
    cmpswapCod(v[l], v[r - 1]);
    cmpswapCod(v[l], v[r]);
    cmpswapCod(v[r - 1], v[r]);

    int m = separaCod(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionSort(Semente *v, int l, int r)
{
    int j;
    for(int i = l + 1; i <= r; i++)
    {
        Semente s = v[i];
        for(j = i; j > 0 && lessCod(s, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = s;
    }
}

void quicksort(Semente *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionSort(v, l, r);
}

int separaNota(Semente *v, int l, int r)
{
    Semente pivo = v[r];
    int j = l;

    for(int i = l; i < r; i++)
        if(lessNota(v[i], pivo))
        {
            swap(v[i], v[j]);
            j++;
        }
        
    swap(v[j], v[r]);
    return j;
}

void quickselect(Semente *v, int l, int r, int k)
{
    int mid = (l + r) / 2;
    cmpswapNota(v[mid], v[r]);
    cmpswapNota(v[l], v[mid]);
    cmpswapNota(v[r], v[mid]);

    int m = separaNota(v, l, r);
    if(m > k)
        quickselect(v, l, m - 1, k);
    else if(m < k)
        quickselect(v, m + 1, r, k);
}

Semente v[10000001];

int main(){

    int n;
    scanf(" %d",&n);
    int i;
    for(i = 0; scanf("%lld %d", &v[i].cod, &v[i].nota) == 2; i++);

    quickselect(v, 0, i - 1, n - 1);
    quicksort(v, 0, n - 1);

    for(int j=0; j < n; j++)
        printf("%lld %d\n", v[j].cod, v[j].nota);

    return 0;
}