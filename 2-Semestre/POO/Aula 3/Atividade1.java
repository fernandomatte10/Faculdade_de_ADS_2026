import java.util.Scanner;

public class Atividade1 {
public static void main(String[] args) {
    Scanner escan = new Scanner(System.in);

    int resultado;
    System.out.println("Escreva um numero: ");
    int numero = escan.nextInt();

    if(numero < 0){
        resultado = numero * numero;
    } else {
        resultado = numero * 3;
    }

    System.out.println("Resultado: " + resultado);
}
}