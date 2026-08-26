#ifndef MEDIA_H
#define MEDIA_H

typedef struct {
    char nome [50];
    float nota1, nota2, mediaf;
} media;

media criarMedia(char nome[], float nota1, float nota2, float mediaf);
float calcularMedia(media m);
void exibirMedia(media m);

#endif