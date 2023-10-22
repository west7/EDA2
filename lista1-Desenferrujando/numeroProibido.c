#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left[], int right[], int left_s, int right_s){
    int i=0, j=0, k=0;

    while(i < left_s && j < right_s){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }else {
            arr[k++] = right[j++];
        }
    }

    while(i < left_s){
        arr[k++] = left[i++];
    }

    while(j < right_s){
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size){
    if(size <= 1){
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for(int i = 0; i < mid; i++) left[i] = arr[i];

    for(int i = mid; i < size; i++) right[i - mid] = arr[i];

    mergeSort(left, mid);
    mergeSort(right, size - mid);

    merge(arr, left, right, mid, size - mid);
}

int buscaBinaria(int arr[], int size, int key){
    int left = 0;
    int right = size - 1;

    while(left <= right){
    int mid = left + (right - left) / 2;

        if(arr[mid] == key){
            return mid;
        }else if (arr[mid] < key){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return -1;
    
}

int main(){
    
    int n = 0;
    scanf("%d", &n);

    int nmp[n];
    int t;

    for(int i=0; i < n; i++){
        scanf("%d", &nmp[i]);
    }

    mergeSort(nmp, n);

    while(scanf("%d", &t) != EOF){
        if(buscaBinaria(nmp, n, t) < 0){
            printf("nao\n");
        }else{
            printf("sim\n");
        }
    }
    
    return 0;
}