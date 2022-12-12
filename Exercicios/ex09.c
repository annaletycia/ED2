#include <stdio.h>
#include <stdlib.h>

int min(int a,int b) //calculando o menor valor
  {
		if(a < b)
			return a;
		else
			return b;
	}

int sequencia(int vet[], int n, int* maximo)
{
	if (n == 1) //caso base
		return 1;

	int res, tam_vet = 1;

	for (int i = 1; i < n; i++) {
		res = sequencia(vet, i, maximo);
		if (vet[i - 1] < vet[n - 1] && res + 1 > tam_vet)
			tam_vet = res + 1;
	}

	if (*maximo < tam_vet) //compara o máximo com o tamanho do vetor
		*maximo = tam_vet;

	return tam_vet; //retorna o tamanho do vet[n-1]
}

//utilizando a função sequencia
int seq(int vet[], int n)
{
	int max = 1;

	sequencia(vet, n, &max); //o resultado da chamada da função fica armazenada em 'max'

	return max;
}

//printando a sequência
void print_seq( int *vet, int n )
{
}

int main()
{	
	int num, cont = 0;
	int vet[100];

	scanf("%d", &num);
	printf("\n");

	for(int i=0;i<num;i++){

		while(!EOF){
			scanf("%d", &vet[cont]);
			cont++;
		}
	int n = sizeof(vet) / sizeof(vet[0]);
	printf("Acertos: %d\n", seq(vet, n));
	print_seq(vet, n);

	return 0;
	}
}