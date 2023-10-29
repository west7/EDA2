#include <stdio.h>


int main(){

    int n = 0;
    while(scanf("%d", &n) == 1 && n != 0){

        int colors[1000001] = {0};
        int max = 0;
        int colorMax = -1;

        for(int i=0; i<n; i++){
            int color;
            scanf("%d", &color);
            colors[color]++;         //Inicio de conceito de tabela hash

            if(colors[color] > max){
                colorMax = color;
                max = colors[color];
            }

        }
        printf("%d\n", colorMax);
    }

    return 0;
}