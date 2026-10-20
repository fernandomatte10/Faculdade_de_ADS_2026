public class Main {
    public static void main(String[] args) {

    Lanche l1 = new Lanche("L01", "X-Burguer", 20.0, 2);
    Bebida b1 = new Bebida("B01", "Suco", 8.0, true);

    Cozinheiro c1 = new Cozinheiro("Paulo", 2000.0, "Massas");

    Pedido p1 = new Pedido("Ana", 35.0);
    Encomenda e1 = new Encomenda("Bruno", 3.0);


    l1.exibirItem();
    System.out.println("Preco total: " + l1.calcularPrecoFinal() + "R$\n");

    b1.exibirItem();
    System.out.println("Preco total: " + b1.calcularPrecoFinal() + "R$\n");

    c1.exibir();
    c1.Cozinhar();

    p1.entregar();
    e1.entregar();
    }
}