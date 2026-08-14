import java.util.Scanner;

public class At6 {
    public static void main(String[] args) {
        Scanner notas = new Scanner(System.in);
        System.out.print("Escreva uma nota: ");
        int nota1 = notas.nextInt();
        int nota2 = notas.nextInt();
        int nota3 = notas.nextInt();
        int media = (nota1 + nota2 + nota3) / 3;
        System.err.println("Media: " + media);
        if(media >= 6){
            System.out.println("Aprovado");
        } else {
            System.out.println("Reprovado");
        }
        notas.close();//Limpa a memória
    }
}