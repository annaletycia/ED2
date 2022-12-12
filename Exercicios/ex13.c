//Dividing coins - 562.cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[50005][105];
int cont[105];

int max(int x, int y) //calculo do maior valor
{
		if(x > y)
			return x;
		else
			return y;
}
int min(int x, int y) //calculo do menor valor
{
		if(x < y)
			return x;
		else
			return y;
}

int peso(int p,int n) 
{
    if(n<0)
        return 0;

    else if(dp[p][n]!=-1)
        return dp[p][n];

    else
        if(p>=cont[n])
            return dp[p][n] = max(cont[n] + peso(p-cont[n],n-1),peso(p,n-1));
        else
            return peso(p,n-1);
}

int main()
{
    int i,j,k,aux,soma,n;
    scanf("%d", &k);

    while(k--)
    {
        scanf("%d",&n);
        aux = 0;

        while(aux < n){
            scanf("%d",cont+aux);
            aux++;
        }

        soma = 0;
        
        for(i=0; i<n; i++)
            soma = soma + cont[i];

        for(i=0; i<=soma/2; i++)
            for(j=0; j<=n; j++)
                dp[i][j] = -1;

        printf("%d\n", soma - 2 * peso(soma/2,n-1));
    }
    return 0;
}