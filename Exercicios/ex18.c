#include <stdio.h>
#include <string.h>
#include <ctype.h>

int vet[1000];

int main()
{
    char str[500];
    int n, i, j ,k;
    scanf("%d", &n);
    getchar();

    int max = 0;
    for(i=0; i<n; i++)
    {
        fgets(str,500,stdin);
        for(j = 'A'; j<='Z'; j++)
        {
            for(k=0; str[k]!='\0'; k++)
            {
                if(toupper(str[k])==j)
                    vet[j]++;
            }
            if(vet[j]>max)
                max = vet[j];
        }
    }
    for(i=max; i>0; i--)
    {
        for(j='A'; j<='Z'; j++)
        {
            if(vet[j] == i)
                printf("%c %d\n", j, i);
        }
    }
    return 0;
}