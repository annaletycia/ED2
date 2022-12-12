public class TabelaDeSimbolosComVetoresParalelos <Chave,Valor> implements TabelaDeSimbolos { //implementação genérica, onde os tipos de dados são especificados depois

    //estruturas de dados:  vetores paralelos
    public TabelaDeSimbolos(){
        Chave[] chave; //com ordem
        Valor[] valor; //
        int M; //número de chaves atualmente na tabela
    }
    
    //Custo: O(1) ideal,mas não aqui, que é:

    void put(Chave k, Valor v) {
        
        int i=M-1; //da ultima posição até a primeira, copiando para a direita
        
        while(i>=0 && k.compareTo(chave[i]) < 0))// pior caso é N operações
        {
            chave[i+1] = chave[i];
            valor[i+1] = valor[i];
            i--;
        }
        chave[i] = k;
        valor[i] = v;
    }
    
    //se K não esta na tabela, retorna null
    //Custo: 
    Valor get(Chave c) 
    {  
       int inf, sup, med;
       
       while(true) {
           med = inf + sup-inf)/2; // == (sup)
       }
    }
    
    void remove(Chave c) {
    
        int i =0;
        for(Chave c: chave) {
            if(c.equals(k)){
                return valor.set(i,null);
            }
            i++;
        }
    }
    
    public static void main(String args[]) {
    
    TabelaDeSimbolos <String,Integer> arvores = new TabelaDeSimbolos<>();
    TabelaDeSimbolos <Integer,Double> outraTabela = new TabelaDeSimbolos<>();
    
    arvores.put("ipe",10);
    arvores.put("mogno",13);
    arvores.put("acaizero",13);
    
    arvore.remove("ipe";
    
    Integer valorDoMogno = arvore.get("mogno");
    
    for(String chave: arvore.keySet()) {
        System.out.println(chave+""+arvore.get(chave));
        }
    }
    
    public interface TabelaDeSimbolos<Chave, Valor> {
        public TabelaDeSimbolos();
    
    //nao permite ter chaves repetidas
    void put(Chave c, Valor v);
    
    //retorna null se chave não é encontrada
    Valor get(Chave c);
    void remove(Chave c);
    }