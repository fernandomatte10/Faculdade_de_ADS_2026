public class Lanche {

    String nome;
    double preco;
    int adicionais;

    public void exibirItem() {
        System.out.println("Lanche:" +nome+ "R$: " +preco);
    }

    public void calcularPrecoFinal() {
        System.out.println("Preco final: " + (preco+adicionais*2.5));
    }
}