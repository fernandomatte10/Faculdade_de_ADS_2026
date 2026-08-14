public class At7 {
    public static void main(String[] args) {
        int soma=0;
        for (int num = 100; num >= 0; num--) {
            if (num % 2 == 0) {
                soma += num;
            }
        }
        System.out.println("Soma dos números pares: " + soma);
    }
}