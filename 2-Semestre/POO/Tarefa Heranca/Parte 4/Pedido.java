public class Pedido implements Entregavel {
    
    String cliente;
    double valor;

    public Pedido(String cliente, double valor) {
        this.cliente = cliente;
        this.valor = valor;
    }

    public double calcularEntrega() {
        if (valor > 50.0) {
            return 0.0;
        } else {
            return TAXA_ENTREGA;
        }
    }

    public void entregar() {
        System.out.println("Pedido de " + cliente + " entregue. Taxa de entrega R$ " + calcularEntrega());
    }
}

