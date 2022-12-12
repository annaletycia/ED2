//URI 1257 Array Hash

#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int N, num, aux = 0, i, j, tam;
    string str;
    cin >> N;
    
    while(N--)
    {      
        cin >> num;
        aux = 0;
        
        for (i=0; i<num; i++)
        {         
            cin >> str;
            tam = str.size();   
                  
            for (j=0; j<tam; j++)
                aux = aux + (int)str[j] + i + j - 65;          
        }
        
        cout << aux << endl;        
    }
    return 0;
}