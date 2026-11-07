public class Filme extends Conteudo {

    private String diretor;

    public Filme(String titulo, int duracao, String diretor) {
        super(titulo, duracao);
        this.diretor = diretor;
    }

    @Override
    public String exibirDetalhes() {
        return "Filme: " + super.exibirDetalhes() + " - Diretor: " + diretor;
    }
}