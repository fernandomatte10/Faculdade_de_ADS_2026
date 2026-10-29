#ifndef LISTA_DUPLA_H                       // Evita a inclusão duplicada deste cabeçalho.
#define LISTA_DUPLA_H                       // Define a macro de proteção do cabeçalho.

#include <stdio.h>                          // Disponibiliza printf() e perror().
#include <stdlib.h>                         // Disponibiliza malloc(), free(), exit() e EXIT_FAILURE.

// Estrutura de um nó da lista duplamente ligada.
typedef struct No {
    int dado;                               // Valor armazenado no nó.
    struct No* ant;                         // Ponteiro para o nó anterior.
    struct No* prox;                        // Ponteiro para o próximo nó.
} No;                                       // Define o tipo No.

// Estrutura principal de controle da lista.
typedef struct {
    No* ini;                                // Ponteiro para o primeiro nó da lista.
    No* fim;                                // Ponteiro para o último nó da lista.
    int n;                                  // Quantidade de nós armazenados na lista.
} Lista;                                    // Define o tipo Lista.

//***Declaração das funções do TAD Lista***

// Cria e retorna uma lista vazia.
Lista* criaLista(void);

// Verifica se a lista está vazia.
int listaVazia(Lista* L);

// Libera todos os nós e a estrutura da lista.
void destroiLista(Lista* L);

// Insere um novo elemento no início da lista.
void insereInicio(Lista* L, int valor);

// Insere um novo elemento no final da lista.
void insereFim(Lista* L, int valor);

// Busca um valor na lista e retorna o ponteiro para o nó encontrado.
No* busca(Lista* L, int valor);

// Percorre e imprime os elementos do início ao fim da lista.
void imprime(const Lista* L);

// Percorre e imprime os elementos do fim ao início da lista.
void imprimeReverso(const Lista* L);

// Remove o primeiro nó da lista.
void removeInicio(Lista* L);

// Remove o último nó da lista.
void removeFim(Lista* L);

// Remove a primeira ocorrência de um determinado valor.
void removeValor(Lista* L, int valor);



/*------------------------------------------------------------------------
********************************Atividades********************************
------------------------------------------------------------------------*/

// Insere depois de um no especifico
void insereDepois(Lista* L, No* p, int valor);









#endif                                       // Finaliza a proteção contra inclusões duplicadas.