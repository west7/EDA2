#include <stdio.h>
#define less(a, b) (a < b)
#define swap(v, a, b)    \
    {                    \
        int temp = v[a]; \
        v[a] = v[b];     \
        v[b] = temp;     \
    }

int separa(int *v, int l, int r)
{
    int i = l, j = r, pivo = v[l];

    while (1)
    {
        while (less(v[i], pivo))
            i++;

        while (!less(v[j], pivo))
            j--;

        if (i < j)
        {
            swap(v, i, j);
        }
        else
        {
            swap(v, l, j);
            return j;
        }
    }
}

void quickselect(int *v, int l, int r, int k)
{
    if (r <= l)
        return;

    int i = separa(v, l, r);

    if (i > k)
        quickselect(v, l, i - 1, k);
    if (i < k)
        quickselect(v, i + 1, r, k);
}