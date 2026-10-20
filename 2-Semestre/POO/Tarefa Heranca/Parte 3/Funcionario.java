abstract class Funcionario {

    String nome;
    double salario;

    public Funcionario(String nome, double salario) {
        this.nome = nome;
        this.salario = salario;
    }

    public double calcularSalario() {
        return salario;
    }

    public void exibir() {
        System.out.println(nome + " - Salario R$ " + calcularSalario());
    }
    
}
