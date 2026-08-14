import java.util.Scanner;

public class Atividade8 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    int maior=0, menor=0;

    System.out.println("Quantos numeros deseja digitar? ");
    int quantidade = escan.nextInt();

    for(int i=0 ; i<quantidade ; i++){
        System.out.println("Digite o " + (i+1) + " numero: ");
        int numero = escan.nextInt();

        if(numero > maior){
            maior=numero;
        } if (numero < menor){
            menor=numero;
        }
    }
    System.out.println("Maior numero digitado: " + maior);
    System.out.println("Menor numero digitado: " + menor);
}}