import java.util.Scanner;

public class At3 {

    public static void main(String[] args) {
        Scanner numero = new Scanner(System.in);
        System.out.print("Escreva um numero para ver se e par ou impar: ");
        int num = numero.nextInt();
        if (num % 2 == 0) {
            System.out.println("O numero " + num + " e par.");
        } else {
            System.out.println("O numero " + num + " e impar." );
        }
        numero.close();//Limpa a memória
    }
}