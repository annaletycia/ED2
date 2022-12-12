#include <stdio.h>
#define MAX 10000000
int a[2][MAX], t[2][MAX];
int e[2], x[2];

int min(int a, int b) //calculo do menor valor
{
		if(a < b)
			return a;
		else
			return b;
}

int montagem(int a[][MAX], int t[][MAX], int *e, int *x, int estacao)
{
	int T1[estacao], T2[estacao], i;

	T1[0] = e[0] + a[0][0];
    T2[0] = e[1] + a[1][0];

	for (i = 1; i < estacao+1; i++)
	{
		T1[i] = min(T1[i-1] + a[0][i], T2[i-1] + t[1][i] + a[0][i]);
		T2[i] = min(T2[i-1] + a[1][i], T1[i-1] + t[0][i] + a[1][i]);
	}

	return min(T1[estacao-1] + x[0], T2[estacao-1] + x[1]);
}
int main()
{   
    int num, estacao;
    scanf("%d", &num);

    while(num--){
        scanf("%d", &estacao);

        for(int i = 0; i < 2; i++){
            for(int j = 1; j <= estacao; j++){
                scanf("%d", &a[i][j]);
            }
        }

        for(int i = 0; i < 2; i++){
            for(int j = 1; j < estacao; j++){
                scanf("%d", t[i]+j);
        }
            }

        scanf("%d %d", e, e+1);
        scanf("%d %d", x, x+1);


	printf("%d\n", montagem(a, t, e, x, estacao));
    }
	return 0;
}