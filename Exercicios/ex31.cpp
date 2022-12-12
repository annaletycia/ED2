//Trees on the level uva - 122

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <queue>

using namespace std;

const int MAX=261;
char s[MAX]; 
bool erro;

struct Node{
    bool lido;
    int val;
    Node *L,*R;
    Node()
    {
        lido = false;
        L = nullptr;
        R = nullptr;
    }
};

void remove(Node* u)
{
    if(u == nullptr) 
        return;
    remove(u->L);
    remove(u->R);
    delete u;
}

Node *raiz;
Node* newNode(){
    return new Node();
}

void add(int v, char* s)
{
    int tam = strlen(s);
    Node* pos = raiz;

    for(int i=0; i<tam; i++)
    {
        if(s[i]=='L')
        {
            if(pos->L == nullptr) 
                pos->L = newNode(); //não há novos nós
            pos = pos->L;
        }
        else if(s[i]=='R')
        {
            if(pos->R == nullptr) 
                pos->R = newNode();
            pos = pos->R;
        }

    }
    if(pos->lido) 
        erro = true;
    pos->val = v;
    pos->lido = true;
}

bool read() //leitura dos caracteres
{
    erro = false;
    remove(raiz);  //libera memória
    raiz = newNode(); //cria raiz
    
    while(1)
    {
        if(scanf("%s",s)!=1) 
            return false;

        if(!strcmp(s,"()")) 
            break; //sai do loop quando a árvore chega ao fim

        int v;
        sscanf(&s[1],"%d",&v); //leitura do valor do no
        add(v,strchr(s,',')+1);//
    }
    return true;
}

bool bfs(vector<int>& ans)
{
    queue<Node*> q;
    ans.clear();
    q.push(raiz); //inicia com apenas uma raiz

    while(!q.empty())
    {
        Node* u = q.front();
        q.pop();
        if(!u->lido) 
            return false;
        ans.push_back(u->val);

        if(u->L!=nullptr) 
            q.push(u->L);
        if(u->R!=nullptr) 
            q.push(u->R);
    }
    return true;
}

int main()
{

    while(read())
    {
        vector<int>ans;
        vector<int>::iterator it;

        if(erro || (!bfs(ans))) 
            printf("not complete\n");
        else
        {
            it=ans.begin();
            printf("%d",*it);
            it++;

            while(it!=ans.end()){
                printf(" %d",*it);
                it++;
            }
            printf("\n");
        }

    }

    return 0;
}