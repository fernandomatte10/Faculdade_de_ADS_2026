import java.util.Scanner;

public class NomeIdade {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Escreva seu nome: ");
        String name = scanner.nextLine();
        System.out.print("Escreva sua idade: ");
        int age = scanner.nextInt();
        System.out.println("Salve, " + name + "!");
        System.out.println("Sua idade é: " + age);
        scanner.close();//Limpa a memória
    }
}