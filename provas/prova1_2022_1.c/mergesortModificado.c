#include <stdio.h>
#include <stdlib.h>

typedef struct  Item
{
    int data;
}Item;


void merge(Item *v, int l, int mid, int r){
    Item *v2 = malloc(sizeof(Item) * (r - l + 1));
    int k = 0,  i = l,  j = mid + 1;

    while(i <= mid && j <= r){
        if(v[i].data < v[j].data)
            v2[k++].data = v[i++].data;
        else
            v[k++].data = v[j++].data;
       /*  if (v[i].data % 2 == 0 && v[j].data % 2 == 0)
            if(v[i].data < v[j].data)
                v2[k++].data = v[i++].data;
            else
                v2[k++].data = v[j++].data;

        else if(v[i].data % 2 == 0 && v[j].data % 2 != 0)
            v2[k++].data = v[i++].data;

        else if(v[i].data % 2 != 0 && v[j].data % 2 == 0)
            v2[k++].data = v[j++].data;

        else 
            if(v[i].data < v[j].data)
                v2[k++].data = v[i++].data;
            else
                v2[k++].data = v[j++].data; */
    }
    while(i <= mid)
        v2[k++] = v[i++];

    while(j <= r)
        v2[k++] = v[j++];

    k = 0;
    for(i = l; i <= r; i++)
        v[i] = v2[k++];

    free(v2);
}

void mergesort(Item *v, int l, int r){
    if(l >= r) return;
    int mid = (r + l)/ 2;
    mergesort(v, l, mid);
    mergesort(v, mid + 1, r);
    merge(v, l, mid, r);
}

int main(void){

    Item arr[] = {{30}, {1}, {44}, {93}, {44}, {77}};
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int j = 0; j < size; j++){
        printf("%d ", arr[j].data);
    }
    printf("\n");

    mergesort(arr, 0, size);

    for(int j = 0; j < size; j++){
        printf("%d ", arr[j].data);
    }
    printf("\n");

    return 0;
}