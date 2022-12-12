#include <stdio.h>

int max(int a, int b) //calculo do maior valor
{
		if(a > b)
			return a;
		else
			return b;
}

int corte(int *P, int N, int *memo) //recursao com memos
{   
    int L;

    if(memo[N] >= 0)
        return memo[N];

    else if(N==0)
        L = 0;

    else{
        L = -1;
        for(int i=0; i<N; i++)
            L = max(L, P[i]+corte(P, N-i-1, memo));
    }
    memo[N] = L;
    return memo[N];
}

int main()
{
    int num, N;
    
    scanf("%d", &num);
    while(num--){
        
        scanf("%d", &N);

        int memo[N+1];
        int P[N];

        for(int i=0; i<=N;i++)
            memo[i] = -1; //inicializa memos com -1
        
        for(int j=0; j<N; j++){
            scanf("%d", &P[j]);
        }
        
    printf("%d\n", corte(P, N, memo));
        }
    return 0;
}