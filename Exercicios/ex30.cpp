//12347 Binary Search Tree
#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int val;
    Tree *L;
    Tree *R;
};

Tree *Insert(Tree *raiz, int n)
{   
    if(raiz == nullptr || raiz->L == nullptr && raiz->R == nullptr){
        Tree *node = new Tree();
        node->val = n;
        node->L = nullptr;
        node->R = nullptr;
    if(!raiz)
        raiz = node;
    else if(n < raiz->val)
        raiz->L = Insert(raiz->L, n);
    else
        raiz->R = Insert(raiz->R, n);
    }

    return raiz;
}

void Remove(Tree* u)
{
    if(u==nullptr) 
        return;
    Remove(u->L);
    Remove(u->R);
    delete u;
}

void Post_Order(Tree *raiz)
{
    if(!raiz)
        return;

    Post_Order(raiz->L);
    Post_Order(raiz->R);
    printf("%d\n", raiz->val);
}

int main()
{

    Tree *raiz;
    raiz = nullptr;
    int n;

    while(scanf("%d",&n))
        raiz = Insert(raiz, n);
    

    Post_Order(raiz);
    Remove(raiz);
    return 0;
}