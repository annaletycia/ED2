#include <stdio.h>

int somaMax(int a[],int n)
{
  int i,j,k;
  int sum,somaMax = 0;
  for(i=0; i<n; i++)
  {
    for(j=i; j<n; j++)
    {
      sum = 0;
      for(k=i ; k<j; k++)
      {
        sum = sum + a[k];
      }
      if(sum>somaMax)
        somaMax = sum;
    }
   }
   return somaMax;
}

int main()
{
    int num;
    int *vet;

    while(1){
        
    scanf("%d",&num);
        if(num == 0)
            break;

    for(int i=0;i<num;i++){
        scanf("%d", &vet[i]);
    }

    int tam = sizeof(vet)/sizeof(vet[0]);

    int max_sum = somaMax(vet, tam);

    if(max_sum<=0)
        printf("Sequência perdedora.\n");
    else
      printf("Maior sequência ganhadora é %d.\n",max_sum);
    }

return 0;
}
