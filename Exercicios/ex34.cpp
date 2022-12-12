//UVA 188 - Perfect Hash

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int C, w[30], n;

int funcaoHash()
{
    int i, j;

    for(i=0; i < n; i++){
        for(j=i+1; j < n; j++)
        {
            if((C/w[i])%n == (C/w[j])%n)
            {
                C = min((C/w[i]+1)*w[i], (C/w[j]+1)*w[j]);
                return 0;
            }
        }
    }
    return 1;
}

int main(){

    char str[100];

    while(fgets(str,100,stdin))
    {
        int tam = strlen(str);
        int i, j;
        n = 0;

        for(i=0; i < tam; i++)
        {
            if(isalpha(str[i]))
            {
                char aux[100];
                sscanf(str+i, "%s", aux);

                int subtam = strlen(aux);
                w[n] = 0;

                for(j=0; j < subtam; j++)
                    w[n] = (w[n]<<5) + (aux[j]-'a'+1); //convertendo palavras para números
                
                i = i + subtam;
                n++;
            }
        }
        C = 2147483647; // C sempre caberá em um inteiro de 32 bits
        for(i = 0; i < n; i++)
            C = min(C, w[i]);
        
        while(!funcaoHash());

        printf("%s%d\n\n", str, C);
    }
    return 0;
}