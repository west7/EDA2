#include <stdio.h>
#include <stdlib.h>

typedef struct  Item
{
    int data;
} Item;

// Função para mesclar dois subarrays com a condição de ímpares maiores que pares
void merge(Item *v, int l, int mid, int r){
    Item *v2 = malloc(sizeof(Item) * (r - l + 1));
    int k = 0,  i = l,  j = mid + 1;

    while(i <= mid && j <= r){
        // Verifica se o número à esquerda é par e o à direita é ímpar
         if (v[i].data % 2 == 0 && v[j].data % 2 != 0) {
            v2[k++].data = v[j++].data;
        }
        // Verifica se o número à esquerda é par e menor que o à direita
        else if (v[i].data % 2 == 0 && v[j].data % 2 == 0 && v[i].data <= v[j].data) {
            v2[k++].data = v[i++].data;
        }
        // Verifica se o número à direita é ímpar e menor que o à esquerda
        else if (v[i].data % 2 != 0 && v[j].data % 2 != 0 && v[i].data >= v[j].data) {
            v2[k++].data = v[i++].data;
        }
        // Nos outros casos, incluindo ímpares menores que pares, considera o número ímpar maior
        else {
            v2[k++].data = v[j++].data;
        }
    }

    while(i <= mid)
        v2[k++].data = v[i++].data;

    while(j <= r)
        v2[k++].data = v[j++].data;

    k = 0;
    for(i = l; i <= r; i++)
        v[i].data = v2[k++].data;

    free(v2);
}

void mergesort(Item *v, int l, int r){
    if(l >= r) return;
    int mid = (r + l)/ 2;
    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main() {
    Item arr[] = {{30}, {44}, {1}, {93}, {44}, {77}};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    mergesort(arr, 0, size - 1);

    printf("Array ordenado: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i].data);
    }
    printf("\n");

    return 0;
}
