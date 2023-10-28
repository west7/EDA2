#include <stdio.h>
#define less(a, b) (a < b)
#define swap(v, a, b)    \
    {                    \
        int temp = v[a]; \
        v[a] = v[b];     \
        v[b] = temp;     \
    }

int separa(int *v, int l, int r){          //left e right
    int tam = r - l + 1;
    int pivo = v[r];

    int j = l;
    for(int k = l; k < r; k++){
        if(less(v[k], pivo) || v[k] == pivo){
            swap(v[k], v[j]);
            j++;
        }
    }
    swap(v[j], v[r]);
    return j;}

int quickselect(int *v, int l, int r, int k)
{
    if (r <= l)
        return v[k];

    int i = separa(v, l, r);

    if (i > k)
        quickselect(v, l, i - 1, k);
    if (i < k)
        quickselect(v, i + 1, r, k);

    return v[k];
}