import java.util.Scanner;

public class At2 {

    public static void main(String[] args) {
        Scanner numero = new Scanner(System.in);
        System.out.print("Escreva um numero para ver sua tabuada: ");
        int num = numero.nextInt();
        System.out.println("Sua tabuada é: ");
        for (int i = 1; i <= 10; i++) {
            System.out.println(num + " x " + i + " = " + (num * i));
        }
        numero.close();//Limpa a memória
    }
}