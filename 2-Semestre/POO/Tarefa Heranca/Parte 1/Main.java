public class Main {
    public static void main(String[] args) {

    Lanche l1 = new Lanche("X-Burguer", 20.0, 2);
    Bebida b1 = new Bebida("Suco", 8.0, true);
    
    b1.exibirItem();
    b1.calcularPrecoFinal();

    l1.exibirItem();
    l1.calcularPrecoFinal();

    }
}