public class Main {
    public static void main(String[] args) {

    Lanche l1 = new Lanche("L01", "X-Burguer", 20.0, 2);
    Bebida b1 = new Bebida("B01", "Suco", 8.0, true);
    
    l1.exibirItem();
    System.out.println("Preco total: " + l1.calcularPrecoFinal() + "R$\n");

    b1.exibirItem();
    System.out.println("Preco total: " + b1.calcularPrecoFinal() + "R$\n");

    }
}