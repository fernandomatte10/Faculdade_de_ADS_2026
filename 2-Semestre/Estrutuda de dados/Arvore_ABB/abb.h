#ifndef ABB_H                                             // Evita que este cabecalho seja processado duas vezes.
#define ABB_H                                             // Define a macro que protege o conteudo do arquivo.

#include <stdio.h>                                        // Permite utilizar printf(), puts() e perror().
#include <stdlib.h>                                       // Permite utilizar malloc(), free(), exit() e EXIT_FAILURE.

typedef struct No {                                       // Inicia a definicao de um no da arvore binaria.
    int chave;                                            // Armazena o valor inteiro que orienta a busca e a ordenacao.
    struct No* esq;                                       // Guarda o endereco da raiz da subarvore esquerda.
    struct No* dir;                                       // Guarda o endereco da raiz da subarvore direita.
} No;                                                     // Encerra a estrutura e estabelece o apelido No.

typedef struct {                                          // Inicia a estrutura de controle do TAD Arvore.
    No* raiz;                                             // Aponta para o primeiro no da hierarquia, ou NULL.
    int n;                                                // Registra a quantidade efetiva de nos inseridos.
} Arvore;                                                 // Encerra a estrutura e estabelece o apelido Arvore.

Arvore* criaArvore(void);                                 // Aloca e inicializa uma nova ABB vazia.
int arvoreVazia(const Arvore* A);                         // Retorna 1 se A nao existe ou nao contem nos.
int numeroNos(const Arvore* A);                           // Retorna o total de nos ou zero se A for NULL.
int altura(const Arvore* A);                              // Calcula altura em arestas: vazia=-1 e folha=0.
No* busca(const Arvore* A, int chave);                    // Devolve o no da chave buscada ou NULL.
int insere(Arvore* A, int chave);                         // Insere chave nao repetida e devolve 1 no sucesso.
int removeChave(Arvore* A, int chave);                    // Remove chave existente e devolve 1 no sucesso.
No* minimo(No* r);                                        // Localiza a menor chave da subarvore r.
No* maximo(No* r);                                        // Localiza a maior chave da subarvore r.
void imprimeInOrdem(No* r);                               // Visita esquerda, raiz, direita (crescente na ABB).
void imprimePreOrdem(No* r);                              // Visita raiz, esquerda, direita.
void imprimePosOrdem(No* r);                              // Visita esquerda, direita, raiz.
void destroiArvore(Arvore* A);                            // Libera os nos e depois a estrutura de controle.

#endif                                                    // Encerra a protecao contra inclusao repetida.