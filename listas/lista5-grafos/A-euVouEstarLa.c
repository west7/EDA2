#include <stdio.h>

int g[2001][2001];          //matriz de adjacências
int v[2001] = {0};  

int main()
{
    int n, m, j;
    scanf(" %d %d %d", &n, &m, &j);


    for (int i = 0; i < n; i++){
        g[i][i] = 1;            //seta a diagonal principal (conexão do elemento com ele mesmo)

        int x, y;
        scanf(" %d", &x);       //Número de conexões de i

        while(x--){
            scanf(" %d", &y);   //Conexões de i
            g[i][y] = 1;        //seta conexões de i com y
        }
    }

    for (int i = 0; i < m; i++){
        int x;
        scanf(" %d", &x);

        for(int k = 0; k < n; k++){
            if( g[x][k] == 1)
                v[k] = 1;
        }
    }

    while(j--){
        int x;
        scanf(" %d", &x);
        if(v[x] == 1){
            printf("Eu vou estar la\n");
        }else{
            printf("Nao vou estar la\n");
        }
    }

    return 0;
}