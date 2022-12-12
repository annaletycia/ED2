//a different way to sort
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct fat
{
    int fatorial, ordem;
};

bool comp(fat a, fat b)
{
    if(a.fatorial  == b.fatorial) 
        return a.ordem < b.ordem;
    else
        return a.fatorial  < b.fatorial; 
}

vector<fat> numfact;

int conta_fat(int num)
{
    int fat=0,pot;
    for(int i=2; i*i<=num; i = (i==2? 3 : i+2))
    {
        if(num%i == 0){
            pot=0;
            while(num%i == 0){
                pot++;
                num/=i;
            }
            fat = fat + pot;
        }
    }
    if(num != 1)
        fat++;

    return fat;
}
int main()
{
    int N, aux=0;
    fat F;

    for(int i=1; i<=2000000; i++)
    {
        int num = conta_fat(i);
            F.fatorial = num; F.ordem = i;
            numfact.push_back(F);
    }
    sort(numfact.begin(),numfact.end(),comp);

    while(scanf("%d",&N)==1)
    {
        if(N==0)
            break;

        printf("Caso %d: ", ++aux);
        cout<<numfact[N-1].ordem<<"\n";

    }
    return 0;
}