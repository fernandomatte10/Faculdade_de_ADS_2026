public class App {
    public static void main(String[] args) throws Exception {
        Carro c1 = new Carro();

        c1.modelo = "Fiesta";
        c1.cor = "Cinza";
        c1.ano = 2014;
        c1.marca = "Ford";


        System.out.println(c1.modelo);

        c1.acelerar();
        c1.buzinar();
        c1.frear();
    }
}
