#include <bits/stdc++.h>
using namespace std;

vector <int> in, post, Left, Right;
int soma, somaPos;

int createTree(int front, int back, int posFront, int posBack)
{
    if(front >= back)
        return 0;
    int trav = post[posBack - 1];
    int pos = front;
    while(in[pos] != trav)
        pos++;
    int size = pos - front;
    Left[trav] = createTree(front, pos, posFront, posFront + size);
    Right[trav] = createTree(pos+1, back, posFront+size, posBack-1);
    return trav;
}
bool visto(vector<int> &t)
{
    t.clear();
    string str;
    if(!getline(cin, str))
        return false;
    stringstream ss(str);
    int i;
    while(ss >> i)
        t.push_back(i);
    return t.size();
}
void dfs(int var, int somaT)
{
    somaT = somaT + var;
    if(!Left[var] && !Right[var] && (somaT<soma || (somaT==soma && var<somaPos)))
    {
        soma = somaT;
        somaPos = var;
    }
    if(Left[var])
        dfs(Left[var], somaT);
    if(Right[var])
        dfs(Right[var], somaT);
}
int main()
{
    while (visto(in))
    {
        visto(post);
        Left = vector<int> (10000 + 10, 0);
        Right = vector<int> (10000 + 10, 0);
        int N = in.size(), trav = createTree(0, N, 0, N);
        soma = numeric_limits<int>::max();
        dfs(trav, 0);
        cout << somaPos << "\n";
    }
}