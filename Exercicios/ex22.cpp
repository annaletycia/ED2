//UVa 10226 - Hardwood Species
#include <iostream>
#include <string>
#include <map>

using namespace std;

    int main()
    {
    map <string,int>::iterator iter; //iterador que percorrerá os elementos e os ordenará em ordem alfabética
    string nome;
    int num;
    cin >> num;

    getline(cin,nome);
    getline(cin,nome);

    for(int i=0; i<num; i++)
    {
        map <string,int> mapa; //cria map onde as chaves são strings e que guarda elementos do tipo int
        int tam = 0;
        
        while(getline(cin,nome))
        {
            if(nome == "")
                break;
    
            tam++;
            iter = mapa.find(nome); //retorna um ponteiro para o elemento 'nome' que foi salvo no mapa

            if(iter != mapa.end())
                iter->second = iter->second + 1;
            
            else
                mapa.insert(pair <string,int> (nome,1));         
        }
        
        if(i>0)
            printf("\n");
        
        for(iter = mapa.begin(); iter != mapa.end(); iter++) //inicializa o iterador no primeiro elemento e termina no fim do map
        {
            double res = (double)(iter->second)/(double)tam;
            res = res * 100;
            printf("%s %.4f\n",(iter->first).c_str(), res); //imprime a chave (primeiro elemento) e o res
        }
    }
    return 0;
}