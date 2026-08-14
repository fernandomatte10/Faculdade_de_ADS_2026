import java.util.Scanner;

public class Atividade3 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    System.out.println("Escreva sua idade e em seguida seu peso em kg: ");
    int idade = escan.nextInt();
    double peso = escan.nextDouble();

    if(idade >= 18 && idade <= 67 && peso > 50){
        System.out.println("Pode doar sangue");
    } else {
        System.out.println("Não pode doar sangue");
    }
    
}}