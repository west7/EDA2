    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define price(a) (a.price)
    #define less(a, b) (price(a) < price(b))
    #define swap(a, b)\
        {             \
            Stock t = a;\
            a = b;    \
            b = t;    \
        }             

    typedef struct Stock{
        char name[11];
        int price;
    }Stock;

    typedef struct Heap{
        Stock *data;
        int size;
    }Heap;

    Heap* PQinit(int n){
        Heap *hp = malloc(sizeof(Heap));
        hp->size = 0;
        hp->data = malloc(sizeof(Stock) * (n + 1));
        return hp;
    }   

    void fixup(Heap *hp, int i){
        int p = (i - 1) / 2;
        while(i > 0 && hp->data[i].price < hp->data[p].price){
            swap(hp->data[i], hp->data[p]);
            i = p;
            p = (i - 1) / 2;
        }
    }


    void fixdown(Heap *hp, int i){
        int small = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < hp->size && hp->data[left].price < hp->data[small].price)
            small = left;
        if(right < hp->size && hp->data[right].price < hp->data[small].price)
            small = right;

        if(small != i){
            swap(hp->data[i], hp->data[small]);
            fixdown(hp, small);
        }
    }

    void PQinsert(Heap *hp, Stock stock){
        hp->data[hp->size] = stock;
        fixup(hp, hp->size);
        hp->size++;
    }

    void PQatualiza(Heap *hp, char *name, int newprice){
        for(int i = 0; i < hp->size; i++){
            if(strcmp(hp->data[i].name, name) == 0){
                hp->data[i].price = newprice;
                fixup(hp, i);
                fixdown(hp, i);
                break;
            }
        }
    }

    Stock PQremove(Heap *hp){
        if(hp->size == 0){
            Stock empty = {"", 0};
            return empty;
        }
        Stock minStock = hp->data[0];
        hp->size--;

        if(hp->size > 0){
            hp->data[0] = hp->data[hp->size];
            fixdown(hp, 0);
        }

        return minStock;
    }

    int main(){
        
        int inst, n;
        scanf("%d", &n);
        
        Heap *hp = PQinit(n);
        
        for(int i = 1; i <= n; i++){

            Stock stock;

            scanf("%d", &inst);
            if(inst == 1){
                scanf("%s %d", stock.name, &stock.price);
                PQinsert(hp, stock); 

            }else if (inst == 2){
                scanf("%s %d", stock.name, &stock.price);
                PQatualiza(hp, stock.name, stock.price);
                
            }else{
                char buy[3];
                scanf("%s", buy);
                Stock r = PQremove(hp);
                if(r.price > 0)
                    printf("%s %d\n", r.name, i);
            }
        }
        free(hp->data);
        free(hp);
        
        return 0;
    }