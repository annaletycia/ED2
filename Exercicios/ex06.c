#include <stdio.h>

long long int max(long long int a, long long int b) //calculando o maior valor
  {
		if(a > b)
			return a;
		else
			return b;
	}

int main()
	{
		int num;
		scanf("%d", &num);

		for(int j=0; j<num; j++)
			{
				int n;
				long long int vet[10001], memo[10001];

				scanf("%d", &n);

				for(int i = 0; i < n; i++)
					scanf("%lld", &vet[i]);

                // CASOS BASE:
				memo[0] = vet[0];  //a comparação de max começa sempre com o primeiro elemento do vetor
				memo[1] = max(memo[0], vet[1]); //o proximo valor armazenado (memo[0] ou vet[1]), depende de qual for maior

                //RECURSÃO:
				for(int i = 2; i < n; i++)
					memo[i] = max(memo[i-1], vet[i] + memo[i-2]); //compara se o atual memo[i] é maior que o anterior memo[i] + o próximo elemento do vetor 

				printf("Caso %d: %lld\n", j+1,memo[n-1]); //devolde o ultimo elemento do memo[], que armazena o máximo valor acumulado
			}

		return 0;
	}