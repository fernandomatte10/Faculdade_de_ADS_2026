import java.util.Scanner;

public class Atividade7 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    double renda = 0, imposto = 0, opcao = 1;
    while(opcao != 0){

        System.out.println("Digite sua renda mensal para o calculo do imposto: ");
        renda = escan.nextDouble();

        if(renda <= 1637.11){
            System.out.println("Insento de pagar impostos");
        } else if(renda >= 1637.12 && renda <= 2453.50) {
            imposto = renda * 0.075;
            System.out.println("Valor do imposto: R$ " + imposto);
        } else if(renda >= 2453.51 && renda <= 3271.38) {
            imposto = renda * 0.15;
            System.out.println("Valor do imposto: R$ " + imposto);
        } else if(renda >= 3271.39 && renda <= 4087.65) {
            imposto = renda * 0.225;
            System.out.println("Valor do imposto: R$ " + imposto);
        } else if(renda >= 4087.66) {
            imposto = renda * 0.275;
            System.out.println("Valor do imposto: R$ " + imposto);
        }

        System.out.println("Deseja continuar? (1 para sim, 0 para não): ");
        opcao = escan.nextInt();

        if(opcao == 0){
            System.out.println("Programa encerrado!");
            break;
        }

}}}