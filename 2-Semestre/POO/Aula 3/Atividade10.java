import java.util.Scanner;

public class Atividade10 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    int opcao = 1;
    double valortotal = 1000.00;

    System.out.println("Nome: Fernando\nNumero da conta: 123321\nSaldo: R$ 1000.00");

    while(opcao != 0){
        System.out.println("Sistema de conta corrente, selecione uma opção:\n1 - Depositar\n2 - Sacar\n3 - Consultar saldo\n0 - Sair");
        int opc = escan.nextInt();

        switch(opc){
            case 0:
                System.out.println("\nPrograma encerrado\n");
                return;
            case 1:
                System.out.println("Opção de deposito selecionada\nDigite o valor a ser depositado: ");
                double valorDeposito = escan.nextDouble();

                valortotal += valorDeposito;

                System.out.println("\nDeposito realizado com sucesso\n");
                break;
            case 2:
                System.out.println("Opção de saque selecionada\nDigite o valor a ser sacado: ");
                double valorSaque = escan.nextDouble();

                if(valorSaque <= valortotal){
                    valortotal -= valorSaque;
                    System.out.println("\nSaque realizado com sucesso\n");
                } else {
                    System.out.println("\nSaldo insuficiente\n");
                }
                break;
            case 3:
                System.out.println("\nSaldo atual: R$" + valortotal);
                break;
            default:
                System.out.println("\nOpção inválida\n");
        }
}}}