// Minimum Stocks

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define value(A) A.value
#define higher(A, B) A.priority > B.priority
#define less(A, B) A.priority < B.priority
#define MOD 315931

typedef struct Item {
    int priority;
    int value;
    char *name;
} Item;

typedef struct Priority_Queue {
    Item *array;
    int size;
    int last;
} Priority_Queue;

typedef struct node {
    struct node *next;
    int value;
    char *name;
} node;

void swap(Item *a, Item *b) {
  Item temp = *b;
  *b = *a;
  *a = temp;
}

/* 
* Priority Queue com o 1 indexado
*/

int key(char *value) 
{
    int a = 314159;
    int b = 271828;
    int h = 1;

    for(; *value != 0; value++) 
    {
        a = (a + b *(*value)) % MOD;
        h = (h*a) % MOD; 
    }

    return h < 0 ? h + MOD : h;
}

bool is_equal(char *str1, char *str2) {
    int i;
    for(i = 0; str1[i] != 0 && str2[i] != 0; i++) {
        if(str1[i] != str2[i])
            return false;
    }

    return str1[i] == str2[i];
}

node *search(node *hash, char *item) {
    int k = key(item);
    node aux = hash[k];

    while(aux.next != NULL) {
        if(is_equal(aux.next->name, item))
            return aux.next;

        aux = *aux.next;
    }

    return NULL;
}

void ht_insert(node *hash, char *item, int nv) {
    int k = key(item);

    node *s = search(hash, item);

    if(s == NULL) {
        node *value = malloc(sizeof(node));
        value->name = item;
        value->value = nv;
        value->next = hash[k].next;
        hash[k].next = value;
    }
    else {
        s->value = nv;
    }
}

Priority_Queue *init_pq(int size) {
    Priority_Queue *pq = malloc(sizeof(Priority_Queue));    
    pq->size = 0;
    pq->last = 1;
    pq->array = malloc(sizeof(Item)*(size + 1));

    return pq;
}

void up_heap(Priority_Queue *pq, int k) {
    Item v = pq->array[k];

    while(k > 1 && less(pq->array[k / 2], v)) {
        pq->array[k] = pq->array[k / 2];
        k /= 2;
    }

    pq->array[k] = v;
}

void down_heap(Priority_Queue *pq) {
    int k = 1, n = pq->last - 1, j;
    Item v = pq->array[k];

    while(k <= n / 2) {
        j = k * 2;
        if(j < n && less(pq->array[j], pq->array[j + 1])) j++;
        if(higher(v, pq->array[j])) break;
        pq->array[k] = pq->array[j];
        k = j;
    }

    pq->array[k] = v;
}

void insert(Priority_Queue *pq, Item item) {
    pq->array[pq->last] = item;
    up_heap(pq, pq->last++);
}

void pop(Priority_Queue *pq) {
    swap(&pq->array[pq->last - 1], &pq->array[1]);
    pq->last--;
    down_heap(pq);
}

Item top(Priority_Queue *pq) {
    return pq->array[1];
}

bool is_empty(Priority_Queue *pq) {
    return pq->last == 1;
}

int main() {
    Priority_Queue *pq = init_pq((int)1e6);
    node *ht = malloc(sizeof(node)*MOD);

    int instruction, price, n;
    char str[11];

    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf(" %d %s", &instruction, str);

        if(instruction == 3) {
            Item t = top(pq);

            while(search(ht, t.name)->value != t.value) {
                pop(pq);
                t = top(pq);
            }
            
            printf("%s %d\n", t.name, i);
            pop(pq);
            continue;
        }

        scanf("%d", &price);
        
        char *name = malloc(sizeof(char)*11);
        strcpy(name, str);
        ht_insert(ht, name, price);

        insert(pq, (Item){ -price, price, name });
    }
}