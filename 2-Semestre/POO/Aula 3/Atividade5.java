import java.util.Scanner;

public class Atividade5 {
public static void main(String[] args) {
    Scanner escaner = new Scanner(System.in);

    System.out.println("Quantos lados tem a figura? ");
    int lados = escaner.nextInt();

    if(lados == 3){
        System.out.println("Sua figura é um Triângulo");
    } else  if(lados == 4){
        System.out.println("Sua figura é um Quadrado ou um Retângulo");
    } else  if(lados == 5){
        System.out.println("Sua figura é um Pentágono");
    } else if(lados == 6){
        System.out.println("Sua figura é um Hexágono");
    } else {
        System.out.println("Não identificado");
    }
 
}}