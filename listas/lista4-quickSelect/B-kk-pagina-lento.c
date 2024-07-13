#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n, p, x;
    scanf("%d %d %d", &n, &p, &x);

    int *paginas = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &paginas[i]);
    }

    qsort(paginas, n, sizeof(int), compare);

    int ini = p * x;
    int fim = ini + x;

    if (fim > n)
        fim = n;

    for (int i = ini; i < fim; i++)
    {
        printf("%d\n", paginas[i]);
    }

    free(paginas);
    return 0;
}
