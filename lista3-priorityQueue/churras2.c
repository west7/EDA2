#include <stdio.h>
#include <stdlib.h>


#define nota(a) (a->nota)
#define greater(a, b) (nota(a) > nota(b))

#define swap(a, b)  \
    {               \
        Churras t = a; \
        a = b;      \
        b = t;      \
    }

typedef struct Churras{
    int nota;
    int index;
}*Churras;

typedef struct Heap{
    Churras *heap;
    int size;
} Heap;

void fixup(Churras *heap, int size){

    for(int i = size; i > 1 && greater(heap[i/2], heap[i]); i /= 2){
        swap(heap[i], heap[i/2]);
        heap[i]->index = i;
        heap[i/2]->index = i/2;
    }
}

void fixdown(Churras *heap, int size, int i){

    for(int l = i * 2; i * 2 <= size; i = l, l = i * 2){

        if(l < size && greater(heap[l], heap[l + 1])) l++;

        if(!greater(heap[i], heap[l])) break;

        swap(heap[i], heap[l]);
        heap[i]->index = i;
        heap[l]->index = l;
    }
}

Heap PQinit(int k)
{
    Heap hp;
    hp.size = 0;
    hp.heap = malloc(sizeof(Churras) * (k + 1));
    return hp;
}

void PQinsert(Heap *hp, Churras c){

    hp->heap[++hp->size] = c;
    c->index = hp->size;
    fixup(hp->heap, hp->size);
}

Churras PQespia(Heap hp){
    return hp.heap[1];
}

Churras PQremove(Heap *hp, int i){
    Churras r = hp->heap[i];
    hp->heap[i] = hp->heap[hp->size--];
    fixdown(hp->heap, hp->size, i);
    return r;
}

int main(){

    int n, k;
    while (scanf("%d %d", &n, &k) == 2){

        if(n == 0 && k == 0) break;

        Churras c = malloc(n * sizeof(struct Churras));

        for(int i = 0; i < n; i++)
            scanf("%d", &c[i].nota);     

        Heap hp = PQinit(k); 

        for(int i = 0; i < k - 1; i++)
            PQinsert(&hp, &c[i]);
        
        for(int i = k - 1; i < n; i++){
            PQinsert(&hp, &c[i]);
            printf("%d%c", PQespia(hp)->nota, " \n"[i == n - 1]);
            PQremove(&hp, c[i - k + 1].index);
        }
        free(hp.heap);
    }    
    return 0;
}
