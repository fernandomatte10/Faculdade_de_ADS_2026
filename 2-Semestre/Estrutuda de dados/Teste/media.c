#include "media.h"
#include <stdio.h>
#include <string.h>

media criarMedia(char nome[], float nota1, float nota2, float mediaf) {
    media m;
    strcpy(m.nome, nome);
    m.nota1 = nota1;
    m.nota2 = nota2;
    m.mediaf = mediaf;

    return m;
}

float calcularMedia(media m) {
    return m.mediaf = (m.nota1 + m.nota2) / 2;
}

void exibirMedia(media m) {
    printf("Aluno: %s\n", m.nome);
    printf("Nota1: %.2f\n", m.nota1);
    printf("Nota2: %.2f\n", m.nota2);
    
    if(m.mediaf > 7) {
        printf("Status do aluno: Aprovado!\n");
    } else {
        printf("Status do aluno: Reprovado!\n");
    }
}