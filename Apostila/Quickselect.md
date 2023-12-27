voltar para [Sumário](/Apostila/Sumário.md).

# QuickSelect

QuickSelect é um algoritmo de busca inspirado no QuickSort (ordenação). Ele é usado para encontrar o k-ésimo menor elemento em um array não ordenado. Após uma passagem do algoritmo ele garante que: todos os elementos a direita de um pivô serão maiores que ele, e que todos a esquerda serão menores que ele.

```C
#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k) {
    if (low <= high) {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, high, k);
        }
    }
    return -1;
}
```