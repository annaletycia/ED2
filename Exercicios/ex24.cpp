//dquery spoj
#include<bits/stdc++.h>

using namespace std;

typedef pair <int, pair<int,int>> it;

it seq[200001];
int c[1000001], a[30001], aux;
int res = 0;

bool comp(it a, it b)
{
    int x = a.first/aux;
    int y = b.first/aux;

    if(x!=y)
    return x<y;
    return a.second.first<b.second.first;
}

void soma(int pos)
{
    c[a[pos]]++;
    if(c[a[pos]]==1)
        res++;
}

void sub(int pos)
{
    c[a[pos]]--;
    if(c[a[pos]]==0)
        res--;
}

int main()
{
    int N;
    cin >> N;
    aux = ceil(sqrt(N));

    for(int i=0; i<N; i++) 
        cin >> a[i];

    int cons;
    cin >> cons;

    int i,j;

    for(int k=0; k<cons; k++)
    {
        cin >> i >> j;
        it x = make_pair(i-1,make_pair(j-1,k));
        seq[k] = x;
    }

    sort(seq,seq+cons,comp);
    int resp[cons];
    int ml=0, mr=0;

    for(int k=0; k<cons; k++)
    {
        i = seq[k].first;
        j = seq[k].second.first;

        while(ml<i)
        {
            sub(ml);
            ml++;
        }
        while(ml>i)
        {
            soma(ml-1);
            ml--;
        }
        while(mr<=j)
        {
            soma(mr);
            mr++;
        }
        while(mr>j+1)
        {
            sub(mr-1);
            mr--;
        }
        resp[seq[k].second.second] = res;
    }

    for(int i=0; i<cons; i++)
        cout << resp[i] << endl;
    
    return 0;
}