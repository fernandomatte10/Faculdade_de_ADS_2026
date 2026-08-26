#include "media.h"
#include <stdio.h>

int main(){
    media aluno;
    
    printf("Digite o nome do aluno, e suas duas notas: \n");
    scanf("%s %f %f", aluno.nome, &aluno.nota1, &aluno.nota2);
    
    exibirMedia(aluno);
    
    printf("Media final: %.2f\n", calcularMedia(aluno));
    
    
    return 0;
}