abstract class Produto {

    String codigo;
    String nome;
    double preco;

    void exibirItem() {
        System.out.println("Produto: " +nome+ "\nR$: " +preco);
    }

    abstract double calcularPrecoFinal();

}
