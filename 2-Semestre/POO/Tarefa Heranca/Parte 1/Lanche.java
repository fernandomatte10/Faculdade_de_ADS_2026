public class Lanche {

    String nome;
    double preco;
    int adicionais;

    public Lanche (String nome, double preco, int adicionais){
        this.nome = nome;
        this.preco = preco;
        this.adicionais = adicionais;
    }

    public void exibirItem() {
        System.out.println("Lanche:" +nome+ "\nR$: " +preco);
    }

    public void calcularPrecoFinal() {
        System.out.println("Preco final: " + (preco+adicionais*2.5));
    }
}