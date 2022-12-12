//1252 uri sort sort sort
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

struct Numero
{
	long int num; 
	long int mod; 
	int impar;
};

int comp(const void *p1, const void *p2)
{
	struct Numero *i = (struct Numero *)p1;
	struct Numero *j = (struct Numero *)p2;
	
	if(i->mod > j->mod)
		return 1;
	else
		if(i->mod < j->mod)
			return -1;
		else
			if((i->impar == 1 && j->impar == 0) || (i->impar == 0 && j->impar == 1))
				if(i->impar > j->impar)
					return -1;
				else
						return 1;
			else
				if(i->impar == 1 && j->impar == 1)
					if(i->num > j->num)
						return -1;
					else
						return 1;
				else
					if(i->num > j->num)
						return 1;
					else
						return -1;						
}

int main ()
{	
	struct Numero nums[10005];
	int N, M;	

	while(scanf("%d %d", &N, &M) && (M != 0 || N != 0))
	{
		for(int i = 0; i < N; i++)
		{
			scanf("%ld", &nums[i].num);
			nums[i].mod = nums[i].num % M;
			if(nums[i].num % 2 == 0) //se é divisível por 2, é par
				nums[i].impar = 0; //false
			else					//se não é divisível, é ímpar
				nums[i].impar = 1; //true
		}	

		qsort(nums,N,sizeof(struct Numero),comp);
		printf("%d %d\n", N, M);

		for(int j = 0; j < N; j++)
			printf("%ld\n", nums[j].num);
	}
	printf("0 0\n");

	return 0;
}