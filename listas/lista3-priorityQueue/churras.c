#include <stdio.h>

static int qp[100005];
static int pq[100005];
static int N;
int *vetor;

void fixup(int *pq, int k);
void fixdown(int *pq, int k, int N);

#define greater(a, b) (vetor[a] > vetor[b])

int exch(int i, int j){
    int t = qp[i];
    qp[i] = qp[j];
    qp[j] = t;
    pq[qp[i]] = i;
    pq[qp[j]] = j;
}

void PQinit(int c){
    N = 0;
}

int PQespia(){
    return vetor[pq[1]];
}

void PQchange(int k){
    fixup(pq, qp[k]);
    fixdown(pq, qp[k], N);
}

int PQempty(){
    return N == 0;
}

void PQinsert(int k){
    qp[k] = ++N;
    pq[N] = k;
    fixup(pq, N);
}

int PQremove(){
    exch(pq[1], pq[N]);
    fixdown(pq, 1, N - 1);
    return pq[N--];
}

void fixup(int *pq, int k){
    while(k > 1 && greater(pq[k/2], pq[k])){
        exch(pq[k], pq[k/2]);
        k = k/2;
    }
}

void fixdown(int *pq, int k, int N){
    int j;
    while(2 * k <= N){
        j = 2*k;
        if(j < N && greater(pq[j], pq[j + 1])) j++;

        if(!greater(pq[k], pq[j])) break;
        exch(pq[k], pq[j]);
        k = j;
    }
}

void solve(int c, int k, int *v){
    int older = 0;
    int next = k;
    vetor = v;
    PQinit(c);

    for(int i = 0; i<k; i++){
        PQinsert(i);
    }
    while (next <= c){
        printf("%d ", PQespia());
        v[older] = 0;
        PQchange(older);
        PQremove();
        older++;
        PQinsert(next);
        next++; 
    }
    printf("\n");
}

int main(){
    int v[100005];
    int n, k;

    while (scanf("%d %d", &n, &k) == 2 && n != 0 && k != 0)
    {
        for(int i = 0; i < n; i++){
            scanf("%d", &v[i]);
        }
        solve(n, k, v);
    }
}