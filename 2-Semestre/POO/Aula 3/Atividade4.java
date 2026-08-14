import java.util.Scanner;

public class Atividade4 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    System.out.println("Quantas maçãs deseja comprar? ");
    double quantidade = escan.nextDouble();

    double total = 0;
    if(quantidade >= 12){
        total = quantidade * 1.00;
        System.out.println("Valor a pagar: R$ " + total);
    } else {
        total = quantidade * 1.30;
        System.out.println("Valor a pagar: R$ " + total);
    }

}}