//UVa 10130 SuperSale

#include <stdio.h>

int main() {

	int T, i, j;
	scanf("%d", &T);

	while(T--) 
	{
		int N, P, W, G, x, max = 0;
		int dp[31] = {};
		scanf("%d", &N);

		for(i = 0; i < N; i++) 
		{
			scanf("%d %d", &P, &W);

			for(j = 30; j >= W; j--)
				if(dp[j] < dp[j-W]+P)
					dp[j] = dp[j-W]+P;
		}
		scanf("%d", &G);
		while(G--) 
		{
			scanf("%d", &x);
			max = max + dp[x];
		}
		printf("%d\n", max);
	}
    return 0;
}