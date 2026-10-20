public class Encomenda implements Entregavel {
    
    String cliente;
    double pesoKg;

    public Encomenda(String cliente, double pesoKg) {
        this.cliente = cliente;
        this.pesoKg = pesoKg;
    }

    public double calcularEntrega() {
        return TAXA_ENTREGA + pesoKg * 2.0;
    }

    public void entregar() {
        System.out.println("Pedido de " + cliente + " entregue. Taxa de entrega R$ " + calcularEntrega());
    }
}
