#include <stdio.h>
#include <limits.h>
#include <string.h>

int min(int a, int b) //calculo do menor valor
  {
		if(a < b)
			return a;
		else
			return b;
	}

int dp[6110][6110];
 
int MinPalindromo(char str[]) { //encontra a palindromificação ótima

    int length = strlen(str);

    for(int i=0;i<length;i++)
        dp[i][i] = 0;

    for(int i=2;i<=length;i++) {

        for(int j=0;j<length-i+1;j++) {

            int k = j + i - 1;

            if(str[k] == str[j] && i == 2)
                dp[j][k] = 0;

            else if(str[k] == str[j])
                dp[j][k] = dp[j+1][k-1];
            else

                dp[j][k] = 1 + min(dp[j+1][k],dp[j][k-1]);
        }
    }

    return dp[0][length-1];
}
int main() {

    int num;
    scanf("%d",&num);

    char str[6001];
    while(num--) {

        scanf("%s",str);
        int length = strlen(str);

        for(int i=0;i<3+1;i++)
            for(int j=0;j<length+1;j++)
                dp[i][j] = INT_MAX; //inicializando com valores máximos

        printf("%d\n",MinPalindromo(str));
    }

    return 0;
}