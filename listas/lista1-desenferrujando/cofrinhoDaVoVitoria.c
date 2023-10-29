#include <stdio.h>

int main(){

    int n = 0;
    int c = 1;
    
    while(1){

        scanf("%d", &n);
        if (n == 0) break;
        int zt = 0, jt = 0;
        
        for(int i=0; i<n; i++){
            int z, j;
            scanf("%d %d", &j, &z);

                zt += z;
                jt += j;
                
                if(i == 0) printf("Teste %d\n", c++);
                printf("%d\n", jt - zt);
        }
        printf("\n");
    }

    return 0;   
}