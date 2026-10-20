public class Bebida extends Produto {

    boolean gelada;

    public Bebida (String codigo, String nome, double preco, boolean gelada){
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.gelada = gelada;
    }

    public double calcularPrecoFinal() {

        if(gelada == true) {
            preco += 1.0;
        }
        return preco;
    }
}