public class Cozinheiro extends Funcionario {

    String especialidade;
    static final double ADICIONAL_COZINHA = 150.0;

    public Cozinheiro(String nome, double salario, String especialidade) {
        super(nome, salario);
        this.especialidade = especialidade;
    }
    
    @Override
    public double calcularSalario() {
        return super.salario + ADICIONAL_COZINHA;
    }

    public void Cozinhar() {
        System.out.println(nome + " está preparando pratos de " + especialidade);
    }
    
}
