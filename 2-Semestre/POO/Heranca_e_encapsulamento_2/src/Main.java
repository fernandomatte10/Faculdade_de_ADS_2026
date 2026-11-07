//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {


        Catalogo catalogo = new Catalogo();
        Scanner scanner = new Scanner(System.in);

        System.out.println("Deseja adicionar quantos Filmes/Séries? ");
        int quantidade = scanner.nextInt();

        for (int i = 0; i < quantidade ; i++) {
            System.out.println("Qual tipo quer inserir?");
            System.out.println("1 - Filme");
            System.out.println("2 - Serie");
            int tipo = scanner.nextInt();

            if (tipo == 1) {

                System.out.println("Titulo: ");
                String tituloFilme = scanner.nextLine();

                System.out.println("Duração: ");
                int duracaoFilme = scanner.nextInt();

                System.out.println("Diretor: ");
                String diretorFilme = scanner.nextLine();

                catalogo.adicionar(new Filme(tituloFilme, duracaoFilme, diretorFilme));

            }
            if (tipo == 2) {

                System.out.println("Titulo: ");
                String tituloSerie = scanner.nextLine();

                System.out.println("Duração: ");
                int duracaoSerie = scanner.nextInt();

                System.out.println("Temporadas: ");
                int temporadasSerie = scanner.nextInt();

                catalogo.adicionar(new Serie(tituloSerie, duracaoSerie, temporadasSerie));

            }
            else {
                throw new IllegalArgumentException("Apenas 1 (Filme) ou 2 (Serie)");
            }

        }

        System.out.println("=== Catálogo ===");
        catalogo.listarTodos();

        System.out.println("=== Buscar ===");
        Conteudo encontrado = catalogo.buscarPorTitulo("toy story");
        if(encontrado != null) {
            System.out.println("Encontrado: " + encontrado.exibirDetalhes());
        } else {
            System.out.println("Não encontrado");
        }
    }
}