//12347 Binary Search Tree

#include <iostream>
#include <vector>

using namespace std;

typedef struct Node{
    int val;
    Node* esquerda;
    Node* direita;

    Node(){
        esquerda = NULL;
        direita = NULL;
    }
}Node;

int pos_ordem(Node* tree)
{
    if(tree == NULL)
        return -1;

    pos_ordem(tree->esquerda);
    pos_ordem(tree->direita);
    printf("%d\n", tree->val);

    return 0;
}

void insert(Node* tree, Node* newNode)
{
    while(true)
        if(tree->val > newNode->val){
            if(tree->esquerda == NULL){
                tree->esquerda = newNode;
                return;
            }
            else
                tree = tree->esquerda;
        }
        else{
            if(tree->direita == NULL){
                tree->direita = newNode;
                return;
            }
            else
                tree = tree->direita;
        }

    return;
}

int main(void)
{
    Node* tree = NULL;
    int key;
    while(scanf("%d", &key))
    {
        if(tree == NULL){
            tree = new Node();
            tree->val = key;
            continue;
        }

        Node* newNode = new Node();
        newNode->val = key;

        insert(tree, newNode);
    }

    pos_ordem(tree);
    return 0;
}