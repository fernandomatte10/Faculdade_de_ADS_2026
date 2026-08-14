import java.util.Scanner;

public class At8 {
    public static void main(String[] args) {
        Scanner calculadora = new Scanner(System.in);
        System.out.print("Selecione uma operação (1-4) sendo elas: 1-Adição, 2-Subtração, 3-Multiplicação, 4-Divisão: ");
        int opcao = calculadora.nextInt();

        switch (opcao) {
            case 1:
                System.out.println("Operação de adição selecionada.");
                System.out.println("Digite dois números para somar:");
                int num1 = calculadora.nextInt();
                int num2 = calculadora.nextInt();
                int soma = num1 + num2;
                System.out.println("Soma: " + soma);
                break;
            case 2:
                System.out.println("Operação de subtração selecionada.");
                System.out.println("Digite dois números para subtrair:");
                int num3 = calculadora.nextInt();
                int num4 = calculadora.nextInt();
                int subtracao = num3 - num4;
                System.out.println("Subtração: " + subtracao);
                break;
            case 3:
                System.out.println("Operação de multiplicação selecionada.");
                System.out.println("Digite dois números para multiplicar:");
                int num5 = calculadora.nextInt();
                int num6 = calculadora.nextInt();
                int multiplicacao = num5 * num6;
                System.out.println("Multiplicação: " + multiplicacao);
                break;
            case 4:
                System.out.println("Operação de divisão selecionada.");
                System.out.println("Digite dois números para dividir:");
                int num7 = calculadora.nextInt();
                int num8 = calculadora.nextInt();
                if (num8 != 0) {
                    double divisao = (double) num7 / num8;
                    System.out.println("Divisão: " + divisao);
                } else {
                    System.out.println("Erro: Divisão por zero não é permitida.");
                }
                break;
            default:
                System.out.println("Opção inválida.");
        }
        calculadora.close();//Limpa a memória
    }
}