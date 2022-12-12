//10441 Catenyms

#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#define N 30

using namespace std;

vector<string> g[N];
vector<string> ans;

int t, n, prnt[N];
bool visitado[N][1005];

int encontra(int x){
	return prnt[x]==x ? x : prnt[x] = encontra(prnt[x]);
}

int var[N];
int cont, aux, x[N], y[N];

void inicializa()
{ 
	memset(x, 0, sizeof(x));
	memset(y, 0, sizeof(y));
	memset(var, 0, sizeof(var));
	memset(visitado, 0, sizeof(visitado));

	for (int i=0; i<26; i++)
	{
		g[i].clear();
		prnt[i] = i;
	}
	cont = 1; 
	aux = 0;
	scanf("%d", &n);
	string s;

	while(n--)
	{
		cin >> s;
		int u = s[0] - 'a', v = s[s.length() - 1] - 'a';

		if(!var[u]){
			var[u] = 1; 
			aux++;
		}if(!var[v])
		{
			var[v] = 1; 
			aux++;
		}
		x[v]++; 
		y[u]++;
		g[u].push_back(s);
		int pu = encontra(u);
		int pv = encontra(v);
		if (pu != pv) {
			prnt[pu] = pv;
			cont++;
		}
	}
	for (int i=0; i<26; i++)
		sort(g[i].begin(), g[i].end());
}

void dfs(int u)
{
	int tam = g[u].size();
	for (int i=0; i<tam; i++)
	{
		int v = g[u][i][g[u][i].length()-1] - 'a';
		if (visitado[u][i]) 
			continue;
		visitado[u][i] = 1;
		dfs(v);
		ans.push_back(g[u][i]);
	}
}

int solve()
{
	if(cont!=aux) 
		return false;

	int minimo=30, imp=0, st;

	for(int i=0; i<26; i++)
	{
		if(g[i].size()) 
			minimo = min(minimo, i);
		if(x[i]-y[i] == -1)
		{
			imp++;
			st = i;
		}else if(y[i]-x[i] == -1)
			imp++;
		else if(y[i]!=x[i]) 
			return 0;
		if(imp>2) 
			return 0;
	}
	ans.clear();

	if(!imp) 
		dfs(minimo);
	else 
		dfs(st);

	for(int i=ans.size() - 1; i>0; i--)
		cout << ans[i] << ".";

	cout << ans[0] << endl;
	return 1;
}

int main(){

	scanf("%d", &t);

	while(t--)
	{
		inicializa();
		if(!solve()) 
			printf("***\n");
	}
	return 0;
}