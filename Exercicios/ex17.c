//10327 Flip Sort
#include <stdio.h>

long vet[200000], memo[200000];
 
long sort(int a, int b)  //mergesort
{
	if(a<b) 
    {
		long L = sort (a, (a + b)/2);
		long K = sort ((a + b)/2 + 1, b);

		int x, y, z, s;
            x = a;
            y = (a + b)/2;
            z = (a + b)/2 + 1;
            s = a;

		while(x <= y || z <= b)
			if (z <= b && (x>y || vet[x]>vet[z])) {
				memo[s++] = vet[z++]; 
				L = L + y-x + 1L;
			} else 
                memo[s ++] = vet[x ++];
		
		for(int i = a; i <= b; ++ i)
			vet[i] = memo[i];

		return L + K;
	}else 
        return 0L;
}

int main()
{
	int num;
	scanf("%d", &num);
    
		for(int i=0; i<num; i++)
			scanf("%ld", &vet[i]);
		
		printf("%ld\n", sort(0, num-1));

	return 0;
}