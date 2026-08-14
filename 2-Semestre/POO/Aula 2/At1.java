import java.util.Scanner;

public class At1 {

    public static void main(String[] args) {
        Scanner temperatura = new Scanner(System.in);
        System.out.print("Escreva sua temperatura: ");
        int temp = temperatura.nextInt();
        double tempF = (temp * 9/5) + 32;
        System.out.println("Sua temperatura em Fahrenheit é: " + tempF);
        temperatura.close();//Limpa a memória
    }
}