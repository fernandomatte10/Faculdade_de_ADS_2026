public class Bebida {

    String nome;
    double preco;
    boolean gelada;

    void exibirItem() {
        System.out.println("Bebida:" +nome+ "R$: " +preco);
    }

    void calcularPrecoFinal() {

        if(gelada=true) {
            System.out.println("Preco final: " + (preco+1.0));
        } else {
            System.out.println("Preco final: " +preco);
        }
    }
}