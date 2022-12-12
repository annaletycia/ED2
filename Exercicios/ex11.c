#include <stdio.h>

int main() 
{
    long long int dp[30010];
    int moeda[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

    dp[0] = 1;
    for(int i = 0; i < 11; i++) {
        for(int j = moeda[i]; j <= 30000; j++) {
            dp[j] = dp[j] + dp[j - moeda[i]];
        }
    }
    int  a, b;
    while(scanf("%d.%d", &a, &b), a + b) 
    {
        long long int x = a * 100 + b;
        printf("%6.2f%17lld\n", x * 1.0 / 100, dp[x]);
    }

    return 0;
}