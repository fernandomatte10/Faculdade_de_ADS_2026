import java.util.ArrayList;

public class Catalogo {
    private ArrayList<Conteudo> conteudos = new ArrayList<>();

    public void adicionar(Conteudo conteudo) {
        conteudos.add(conteudo);
    }
    public void listarTodos() {
        for (Conteudo conteudo : conteudos) {
            System.out.println(conteudo.exibirDetalhes());
        }
    }
    public Conteudo buscarPorTitulo(String titulo) {
        for (Conteudo conteudo : conteudos) {
            if (conteudo.getTitulo().equalsIgnoreCase(titulo)) {
                return conteudo;
            }
        }
        return null;
    }
}