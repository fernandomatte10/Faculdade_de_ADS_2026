public class Bebida {

    String nome;
    double preco;
    boolean gelada;

    public Bebida (String nome, double preco, boolean gelada){
        this.nome = nome;
        this.preco = preco;
        this.gelada = gelada;
    }

    public void exibirItem() {
        System.out.println("Bebida: " +nome+ "\nR$: " +preco);
    }

    public void calcularPrecoFinal() {

        if(gelada=true) {
            System.out.println("Preco final: " + (preco+1.0));
        } else {
            System.out.println("Preco final: " +preco);
        }
    }
}