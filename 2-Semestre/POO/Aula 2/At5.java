import java.util.Scanner;

public class At5 {
    public static void main(String[] args) {
        Scanner numero = new Scanner(System.in);
        System.out.print("Escreva um numero: ");
        int num = numero.nextInt();

        while (num > 1) {
            num -= 1;
            System.out.println(num);
        }
    numero.close();//Limpa a memória
    }
}