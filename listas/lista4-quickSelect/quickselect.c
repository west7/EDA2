#include <stdio.h>
#include <stdlib.h>

#define less(a, b) (a < b)
#define min(a, b) (a < b ? a : b)
#define swap(a, b)    \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    }
#define cmpswap(a, b) \
    if (less(b, a))   \
    swap(a, b)

int separa(int *v, int l, int r)
{
    int pivo = v[r];
    int j = l;
    for (int i = l; i < r; i++)
        if (less(v[i], pivo))
        {
            swap(v[i], v[j])
                j++;
        }
    swap(v[j], v[r]);
    return j;
}

void quicksortM3(int *v, int l, int r)
{
    if (r - l <= 32)
        return;

    int mid = (l + r) / 2;

    swap(v[mid], v[r - 1]);
    cmpswap(v[l], v[r - 1]);
    cmpswap(v[l], v[r]);
    cmpswap(v[r - 1], v[r]);

    int m = separa(v, l, r);
    quicksortM3(v, l, m - 1);
    quicksortM3(v, m + 1, r);
}

void insertionsort(int *v, int l, int r)
{
    int j;
    for (int i = l + 1; i <= r; i++)
    {
        int temp = v[i];
        for (j = i; j > 0 && less(temp, v[j - 1]); j--)
            v[j] = v[j - 1];
        v[j] = temp;
    }
}

void quicksort(int *v, int l, int r)
{
    quicksortM3(v, l, r);
    insertionsort(v, l, r);
}

void quickselect(int *v, int l, int r, int k)
{
    if (k < l || k > r)
        return;

    int mid = (l + r) / 2;
    cmpswap(v[mid], v[r]);
    cmpswap(v[l], v[mid]);
    cmpswap(v[r], v[mid]);

    int m = separa(v, l, r);
    if (m > k)
        quickselect(v, l, m - 1, k);
    else if (m < k)
        quickselect(v, m + 1, r, k);
}