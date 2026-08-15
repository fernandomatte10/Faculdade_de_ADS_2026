public class App2 {
    public static void main(String[] args) throws Exception {
        Garrafa g1 = new Garrafa();

        g1.Cor = "Azul";
        g1.Material = "Plástico";
        g1.Modelo = "Garrafa Térmica";
        g1.Capacidade = 500;
        g1.corTampa = "Preto";

        System.out.println(g1.Cor);
        System.out.println(g1.Material);
        System.out.println(g1.Modelo);
        System.out.println(g1.Capacidade);
        System.out.println(g1.corTampa);

        g1.abrir();
        g1.fechar();
        g1.beber();
    }
}
