public class Lanche extends Produto {

    int adicionais;

    public Lanche (String codigo, String nome, double preco, int adicionais){
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.adicionais = adicionais;
    }

    public double calcularPrecoFinal() {
        if(adicionais > 0) {
            preco += adicionais * 2.5;
            return preco;
        }
        return preco;
    }
}