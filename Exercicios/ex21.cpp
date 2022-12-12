#include <iostream>
#include <stack>
#include <string.h>
#define MAX 100000

using namespace std;

int bemFormada(stack st, string vet)
{
    for(int i=0; vet[i] != '\0'; i++){
        char c;
        switch(vet[i])
        {
            case '}': if(stack_empty(st)) return 0;
                      stack_top(st, &c);
                      if(c != '{') return 0;
                      stack_pop(st);
                      break;
            default: stack_push(st, s[i]);
        }
    }
}

int main(){

    stack <string> chaves;

    string vet[MAX];
    int num, i=0;
    cin >> num;

    while(num+1){
        getline(cin,vet[i]);
        chaves.push(vet[i]);
        i++;
        num--;
    }
    
    

    return 0;
}