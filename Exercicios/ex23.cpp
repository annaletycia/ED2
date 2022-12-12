//UVA 11995
#include <bits/stdc++.h>

using namespace std; 
 
int main()
{
    int N;
    while(scanf("%d", &N)!=EOF)
    {
        stack <int> pilha;
        queue <int> fila;
        priority_queue <int> fila_pri;
 
        int y, x;
        bool impossivel = false;
        int f=1, p=1, fp=1; //flags que indicarão o tipo de estrutura

        for(int i=0; i<N; i++)
        {
            cin >> y >> x;

            if(y==1) //insere elemento x na pilha,fila e fila de prioridade
            {
                pilha.push(x);
                fila.push(x);
                fila_pri.push(x);
            }
            if(y==2) //retira um elemento
            {
                if(pilha.empty() || fila.empty() || fila_pri.empty())
                    impossivel = true;
                else
                {
                    int aux = fila.front(); //pega o elemento da 'frente' da fila
                    fila.pop();

                    if(aux!=x)
                        f = 0; //não é fila
                    aux = pilha.top(); //pega o elemento do 'topo' da pilha
                    pilha.pop();

                    if(aux != x)
                        p = 0; //não é pilha
                    aux = fila_pri.top(); //pega o elemento do 'topo' da fila de prioridade
                    fila_pri.pop();

                    if(aux != x)
                       fp = 0; //não é fila de prioridade
                }
            }
        }
        if(impossivel)
            cout << "impossível\n";

        else if(f+fp+p>1) //pode ser mais de uma estrutura
            cout << "não tenho certeza\n";

        else if(f)
            cout << "fila\n";

        else if(p)
            cout << "pilha\n";

        else if(fp)
            cout << "fila de prioridade\n";

        else 
            cout << "impossível\n";
    }
    return 0;
}