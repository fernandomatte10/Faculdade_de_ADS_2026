import java.util.Scanner;

public class Atividade2 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    System.out.println("Escreva sua idade: ");
    int idade = escan.nextInt();

    if(idade >= 16 && idade <= 17){
        System.out.println("Voto facultativo");
    } else if (idade >= 18 && idade <= 70){
        System.out.println("Voto obrigatório");
    } else {
        System.out.println("Voto facultativo");
    }
}
}