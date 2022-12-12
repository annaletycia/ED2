#include <stdio.h>

int main()
{
int N, V, t, vagao[51];

      while(scanf("%d",&N)==1){
         for(int k=0;k<N;k++){
            int aux=0;
              scanf("%d",&V);
              for(int i=0; i<V; i++)
                  scanf("%d",&vagao[i]);

    for(int i=0; i<V-1; i++)
        for(int j=0; j<V-i-1; j++)
            if(vagao[j]>vagao[j+1]){
                aux++;
                t = vagao[j];
                vagao[j] = vagao[j+1];
                vagao[j+1] = t;
                }
    printf("A quantidade ajeitamentos deve ser %d.\n",aux);
    }
}
	return 0;
}