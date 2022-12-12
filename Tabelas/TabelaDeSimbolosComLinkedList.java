public class TabelaDeSimbolosComLinkedList <Chave,Valor> implements TabelaDeSimbolos { //implementação genérica, onde os tipos de dados são especificados depois

    LinkedList <Chave> chave; //sem ordem
    LinkedList <Valor> valor;
    //estruturas de dados: lista encadeada
    public TabelaDeSimbolos(){
        chave = new LinkedList<>();
        valor= new LinkedList<>();
    }
    
    //Custo: N testes de equivalencia para N chaves na tabela
    void put(Chave k, Valor v) {
        
        int i=0;
        for(Chave c: chave) { atribui para a variável c o indíce da posição dos vetores
            if(c.equals(k)) { //se a chave c for igual a chave k, quer dizer que ja existe
                return valor.set(i,v); //atualiza o valor associado a chave
            }
            i++;
            }
        chave.add(c);
        valor.add(v);
    }
    
    //se K não esta na tabela, retorna null
    Valor get(Chave c) {
        Chave ret = null;
    
    int i =0;
    for(Chave c: chave) {
        if(c.equals(k)){
                return valor.set(i,v); //retorna o valor daquela posição
            i++;
        }
        return ret; //null
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
