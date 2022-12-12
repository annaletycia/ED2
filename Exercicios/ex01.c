#include <stdio.h>
#include <math.h>

int main(){
    
    float N, K;
    int num;
    scanf("%d", &num);

    for(int i=0; i<num; i++){
        scanf("%f", &N);
        scanf("%f", &K);
    if(N >= 1 && K > 0)
    {
        float div;
        int res;

        if(N == K)
            div = 29;
        else if(N > 29)
            div = ceil(N/29);
        else 
            div = ceil(29/N);

        if(N == 1 || N == 29)
            res = 1;
        else
            res = ((29 * K) - N ) + 1;

        printf("%.0f %d\n",div, res);
    }
    }
    return 0;
}

/* 
1 1   ->  29 1

29 1  ->  1  1

50 2  ->  2  9

20 1  ->  2 10 
*/