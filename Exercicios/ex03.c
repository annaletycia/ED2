#include <stdio.h>
#include <string.h>

int main(){

    int num, A, T;
    char planet[50];
    char first[50];

    while(scanf("%d", &num) && num != 0)
    {
        int ano = 3211;
        for(int i=0; i<num; i++){
            scanf("%s", planet);
            scanf("%d", &A);
            scanf("%d", &T);

            if(A - T < ano){
                strcpy(first,planet);
                ano = A -T;
            }
        }
        printf("%s\n", first);
    }
    return 0;
}