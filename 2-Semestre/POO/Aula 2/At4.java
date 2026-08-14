import java.util.Scanner;

public class At4 {

    public static void main(String[] args) {

        Scanner numero = new Scanner(System.in);
        System.out.print("Escreva 3 numeros: ");
        int num1 = numero.nextInt();
        int num2 = numero.nextInt();
        int num3 = numero.nextInt();

        int maior= num1;
        if (num1 > maior) {
            maior = num1;
        }
        if (num2 > maior) {
            maior = num2;
        }
        if (num3 > maior) {
            maior = num3;
        }
        System.out.println("O maior numero é: " + maior);
        numero.close();//Limpa a memória
        }
}