#include <bits/stdc++.h>

using namespace std;

struct Tree
{
    int val;
    Tree *R = nullptr;
    Tree *L = nullptr;
};

Tree *Insert(Tree *raiz, int val)
{
    if(raiz==nullptr)
    {
        raiz = new Tree();
        raiz->val = val;
    }
     else
    {
        Tree *aux = raiz;
        Tree *prev;

        while(aux!=nullptr)
        {
            if(aux->val < val){
                prev = aux;
                aux = aux->R;
            }else{
                prev = aux;
                aux = aux->L;
            }

        }
        Tree *new_Tree = new Tree();
        new_Tree->val = val;

        if(prev->val < new_Tree->val)
            prev->R = new_Tree;

        else
            prev->L = new_Tree;
    }
    return raiz;
}
/*
void Remove(Tree* u)
{
    if(u==nullptr) 
        return;
    Remove(u->L);
    Remove(u->R);
    delete u;
}*/

void Post_Order(Tree *raiz)
{
    if(raiz==nullptr)
        return;

    Post_Order(raiz->L);
    Post_Order(raiz->R);
    printf("%d\n", raiz->val);
}
int main()
{
    Tree *raiz = nullptr;
    int n;

    while(scanf("%d",&n)){
	    raiz = Insert(raiz, n);
    }
	Post_Order(raiz);
	//Remove(raiz);
	return 0;
}