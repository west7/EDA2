#include <stdio.h>

#define less(a, b) (a < b)
#define swap(a, b)    \
    {                    \
        int temp = v[a]; \
        v[a] = v[b];     \
        v[b] = temp;     \
    }

int quickselect(int *v, int l, int r)
{
    int n = r - l + 1;
    int k = n / 2; // O índice do elemento do meio (ou seja, o possível majoritário)

    while (1)
    {
        int i = l;
        int j = r;
        int pivo = v[l];

        while (i < j)
        {
            while (v[i] < pivo)
                i++;

            while (v[j] > pivo)
                j--;

            if (i <= j)
            {
                swap(i, j);
                i++;
                j--;
            }
        }

        if (j < k)
            l = i;
        if (k < i)
            r = j;
        if (i <= k && k <= j)
            return v[k];
    }
}
int main(){
    int n;
    
    while(scanf("%d", &n) == 1 && n != 0){

        int colors[1000001] = {0};
        int colorMax = -1;

        for(int i = 0; i<n; i++)
            scanf("%d", &colors[i]);
        
        colorMax = quickselect(colors, 0, n - 1);
        printf("%d\n", colorMax);
    }

    return 0;
}