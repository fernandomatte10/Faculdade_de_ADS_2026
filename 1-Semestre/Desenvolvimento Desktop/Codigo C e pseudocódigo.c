#include <stdio.h>

int main()
{

char nome[50];
int idade;
float altura;

printf("Digite seu nome: ");
scanf("%s", nome);
printf("Digite sua idade: ");
scanf("%d", &idade);
printf("Digite sua altura: ");
scanf("%f", &altura);

printf("Olá %s!, você tem %d anos e mede %.2f metros.\n", nome, idade, altura);
return 0;

}




INICIO
LEIA senha
ENQUANTO senha != 4321 FAÇA
ESCREVA "ACESSO NEGADO"
LEIA SENHA
FIMENQUANTO
ESCREVA "ACESSO LIBERADO"
FIM




PEDIR SENHA AO USUARIO
ENQUANTO A SENHA FOR MENOR OU MAIOR QUE 4321
INFORMAR "ACESSO NEGADO"
PEDIR SENHA NOVAMENTE
INFORMAR "ACESSO LIBERADO"
