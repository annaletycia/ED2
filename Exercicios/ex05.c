#include <stdio.h>

int main(){

    int N, Pi;

    while(scanf("%d", &N) && N != -1)
    {   
        int soma = 0;
        int money = 0;

        for(int i=0; i<N; i++)
        {
            scanf("%d", &Pi);
            soma = soma + Pi;
            if(soma%100 == 0)
                money++;
        }
        printf("%d\n", money);
    }

    return 0;
}