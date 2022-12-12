#include <bits/stdc++.h>
#define INF 1000000000
#define MAX 1003

using namespace std;

typedef pair<int,int> link;

int n, m;
vector<link> vet[MAX];

int arr[MAX];
void dij(int x, int *d)
{
    priority_queue<link,vector<link>, greater<link>> pqueue;

    pqueue.push(link(0,x));
    fill(d, d+MAX,INF);
    d[x] = 0;
    fill(arr,arr+MAX,0);

    while(!pqueue.empty())
    {
        int u = pqueue.top().second; 
        pqueue.pop();

        if(arr[u]) 
            continue;

        arr[u] = 1;

        for(link z: vet[u])
        {
            int c = z.first;
            int v = z.second;
            if(d[v]>d[u] + c)
            {
                d[v] = d[u] + c;
                pqueue.push(link(d[v], v));
            }
        }
    }
}

int dis[MAX], aux[MAX];

int dp(int u)
{
    int &ans = aux[u];

    if(ans != -1) 
        return ans;
    if(u==2) 
        return ans = 1;
        
    ans = 0;
    int tam = vet[u].size();
    for(int i=0; i<tam; ++i)
    {
        int v = vet[u][i].second;
        if(dis[v]<dis[u])
            ans = ans + dp(v); 
    }
    return ans;
}

void solve()
{
    dij(2,dis);
    memset(aux,-1,sizeof(aux));
    printf("%d\n", dp(1));
}

void inicializa()
{
    for(int j=1; j<=n; j++)
        vet[j].clear();
}

int main()
{
    while(scanf("%d",&n) && n!= 0)
    {
    scanf("%d", &m);

        inicializa();
        for(int i=0; i<m; i++)
        {
            int a, b, c;            
            scanf("%d%d%d", &a, &b, &c);
            
            vet[a].push_back(link(c,b));
            vet[b].push_back(link(c,a));
        }
        solve();
    }
    return 0;
}