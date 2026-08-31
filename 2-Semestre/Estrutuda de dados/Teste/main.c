#include "media.h"
#include <stdio.h>

int main(){
    media aluno;
    
    printf("Digite o nome do aluno, e suas duas notas: \n");
    scanf("%s %f %f", aluno.nome, &aluno.nota1, &aluno.nota2);
    
    aluno.mediaf = calcularMedia(aluno);

    exibirMedia(aluno);

    printf("Media final: %.2f\n", aluno.mediaf);

    return 0;
}