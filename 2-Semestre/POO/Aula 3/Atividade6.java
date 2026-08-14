import java.util.Scanner;

public class Atividade6 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    System.out.println("Escolha uma opção de calculo de área, sendo elas:\n1 - Círculo\n2 - Quadrado\n3 - Retângulo");
    int opcao = escan.nextInt();

    double raio=0, area=0, base=0, altura=0, lado=0;

    switch (opcao) {
        case 1:
            System.out.println("Digite o raio do círculo: ");
            raio = escan.nextDouble();
            area = raio * raio * 3.14;
            System.out.println("A área do círculo é: " + area);
            break;
        case 2:
            System.out.println("Digite a base e em seguida a altura do retângulo: ");
            base = escan.nextDouble();
            altura = escan.nextDouble();
            area = base * altura;
            System.out.println("A área do retângulo é: " + area);
            break;
        case 3:
            System.out.println("Digite o valor de um dos lados do quadrado: ");
            lado = escan.nextDouble();
            area = lado * lado;
            System.out.println("A área do quadrado é: " + area);
            break;
        default:
            System.out.println("Opção inválida!");
            break;
}}}