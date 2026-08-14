public class Atividade9 {
public static void main(String[] args) {

    int soma=0;

    for(int i=1; i<500; i++){
        if(i % 3 == 0 && i % 2 != 0){
            soma += i;
        }
    }
    System.out.println("Soma total: " + soma);

}}