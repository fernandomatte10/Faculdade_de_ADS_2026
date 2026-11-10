#include "abb.h"                                           // Disponibiliza estruturas, funcoes e bibliotecas do TAD.

// =============================================================
// CRIACAO DE NO
// =============================================================

static No* novoNo(int chave) {                             // Cria um no; static limita seu uso a abb.c.
    No* p = (No*) malloc(sizeof(No));                      // Aloca exatamente o espaco necessario para um No.

    if (!p) {                                              // Verifica se malloc devolveu NULL.
        perror("malloc");                                  // Exibe a causa do erro de alocacao, quando disponivel.
        exit(EXIT_FAILURE);                                // Encerra a aplicacao para evitar ponteiro invalido.
    }                                                      // Termina o tratamento da falha de memoria.

    p->chave = chave;                                      // Grava o inteiro recebido no novo no.
    p->esq = NULL;                                         // Novo no ainda nao possui filho esquerdo.
    p->dir = NULL;                                         // Novo no ainda nao possui filho direito.

    return p;                                              // Devolve o endereco da memoria alocada.
}                                                          // Finaliza a funcao auxiliar novoNo.

// =============================================================
// CALCULO DE ALTURA
// =============================================================

static int alturaRec(No* r) {                              // Calcula a altura da subarvore por recursao.
    if (r == NULL) return -1;                              // Subarvore vazia: altura -1 na convencao de arestas.

    int he = alturaRec(r->esq);                            // Calcula a altura do ramo esquerdo.
    int hd = alturaRec(r->dir);                            // Calcula a altura do ramo direito.

    return (he > hd ? he : hd) + 1;                        // Seleciona a maior altura e soma a aresta ate o filho.
}                                                          // Finaliza alturaRec e devolve a altura em arestas.

// =============================================================
// LIBERACAO RECURSIVA
// =============================================================

static void liberaRec(No* r) {                             // Libera todos os nos em pos-ordem.
    if (!r) return;                                        // Caso base: subarvore vazia nao exige liberacao.

    liberaRec(r->esq);                                     // Libera completamente a subarvore esquerda.
    liberaRec(r->dir);                                     // Libera completamente a subarvore direita.
    free(r);                                               // Libera o no apenas depois de liberar seus filhos.
}                                                          // Finaliza a rotina auxiliar de destruicao.

// =============================================================
// REMOCAO RECURSIVA
// =============================================================

static No* removeRec(No* r, int chave, int* removido) {    // Remove a chave e retorna a nova raiz local.
    if (r == NULL)                                         // Se alcancou uma referencia vazia, nao encontrou a chave.
        return NULL;                                       // Mantem vazia a subarvore e retorna ao chamador.

    if (chave < r->chave) {                                // Se a chave e menor, a busca deve seguir pela esquerda.
        r->esq = removeRec(r->esq, chave, removido);       // Religa o filho a nova raiz esquerda.
    } else if (chave > r->chave) {                         // Se a chave e maior, a busca segue pela direita.
        r->dir = removeRec(r->dir, chave, removido);       // Religa o filho a nova raiz direita.
    } else {                                               // Igualdade significa que o no a ser removido foi achado.
        *removido = 1;                                     // Avisa a funcao externa que houve uma exclusao logica.

        if (r->esq == NULL) {                              // Trata folha ou no cujo unico filho fica a direita.
            No* aux = r->dir;                              // Preserva o filho direito, que pode ser NULL.
            free(r);                                       // Libera o no que contem a chave removida.
            return aux;                                    // O filho direito passa a ocupar esta posicao na arvore.
        }                                                  // Finaliza o primeiro caso de zero/um filho.

        else if (r->dir == NULL) {                         // Trata no que possui apenas o filho esquerdo.
            No* aux = r->esq;                              // Preserva a subarvore esquerda antes da liberacao.
            free(r);                                       // Libera a memoria do no que sera removido.
            return aux;                                    // Filho esquerdo assume a posicao do no antigo.
        }                                                  // Finaliza o caso de um filho a esquerda.

        No* p = maximo(r->esq);                            // Dois filhos: procura predecessor na subarvore esquerda.
        r->chave = p->chave;                               // Copia a chave do predecessor para o no atual.
        r->esq = removeRec(r->esq, p->chave, removido);    // Exclui fisicamente o predecessor original.
    }                                                      // Finaliza os casos do no localizado.

    return r;                                              // Devolve a raiz atualizada desta subarvore.
}                                                          // Finaliza a remocao recursiva.

// =============================================================
// CRIACAO DA ARVORE
// =============================================================

Arvore* criaArvore(void) {                                 // Cria o objeto de controle da arvore.
    Arvore* A = (Arvore*) malloc(sizeof(Arvore));          // Reserva memoria para raiz e contador.

    if (!A) {                                              // Testa se a memoria nao foi alocada.
        perror("malloc");                                  // Registra o erro de alocacao.
        exit(EXIT_FAILURE);                                // Encerra com codigo de falha.
    }                                                      // Fecha a verificacao de alocacao.

    A->raiz = NULL;                                        // Arvore nova ainda nao possui raiz.
    A->n = 0;                                              // Uma arvore vazia contem zero nos.

    return A;                                              // Retorna o endereco da estrutura Arvore.
}                                                          // Finaliza criaArvore.

// =============================================================
// VERIFICACAO DE ARVORE VAZIA
// =============================================================

int arvoreVazia(const Arvore* A) {                         // Consulta se a estrutura esta vazia.
    return (A == NULL || A->n == 0);                       // Retorna 1 para ponteiro nulo ou contador zero.
}                                                          // Finaliza arvoreVazia.

// =============================================================
// CONSULTA DE QUANTIDADE DE NOS
// =============================================================

int numeroNos(const Arvore* A) {                           // Consulta o tamanho armazenado da ABB.
    return (A ? A->n : 0);                                 // Le n se A existe; caso contrario, devolve zero.
}                                                          // Finaliza numeroNos.

// =============================================================
// CONSULTA DE ALTURA
// =============================================================

int altura(const Arvore* A) {                              // Interface publica para altura da ABB.
    return (A ? alturaRec(A->raiz) : -1);                  // Usa recursao ou -1 se A for NULL.
}                                                          // Finaliza altura.

// =============================================================
// BUSCA DE CHAVE
// =============================================================

No* busca(const Arvore* A, int chave) {                    // Procura uma chave usando as regras da ABB.
    No* p = (A ? A->raiz : NULL);                          // Comeca na raiz ou em NULL se A nao existir.

    while (p != NULL) {                                    // Continua enquanto houver no para comparar.
        if (chave == p->chave)                             // Testa se a chave procurada foi encontrada.
            return p;                                      // Devolve o endereco do no correspondente.

        else if (chave < p->chave)                         // Valor menor deve estar na subarvore esquerda.
            p = p->esq;                                    // Avanca pelo ponteiro esq.

        else                                               // Caso restante: a chave procurada e maior.
            p = p->dir;                                    // Avanca pelo ponteiro dir.
    }                                                      // Termina quando se atinge NULL.

    return NULL;                                           // Retorna NULL quando a chave esta ausente.
}                                                          // Finaliza busca.

// =============================================================
// INSERCAO DE CHAVE
// =============================================================

int insere(Arvore* A, int chave) {                         // Tenta inserir nova chave sem aceitar duplicatas.
    if (!A) return 0;                                      // Evita acessar estrutura de controle inexistente.

    No* pai = NULL;                                        // Guarda o ultimo no valido visitado na descida.
    No* p = A->raiz;                                       // Inicia a busca por posicao na raiz.

    while (p != NULL) {                                    // Desce ate achar um ponteiro de filho NULL.
        pai = p;                                           // O no corrente podera receber o novo filho.

        if (chave == p->chave)                             // Detecta chave ja presente na arvore.
            return 0;                                      // Cancela insercao sem modificar n.

        else if (chave < p->chave)                         // Chaves menores devem seguir pela esquerda.
            p = p->esq;                                    // Desce ao filho esquerdo.

        else                                               // Chaves maiores seguem para a direita.
            p = p->dir;                                    // Desce ao filho direito.
    }                                                      // Encontrou um ponteiro NULL para a insercao.

    No* novo = novoNo(chave);                              // Aloca um no folha apenas depois de evitar duplicata.

    if (pai == NULL) {                                     // Sem pai significa que a arvore estava vazia.
        A->raiz = novo;                                    // O novo no se torna a raiz.
    } else if (chave < pai->chave) {                       // Decide qual ponteiro do pai deve ser atualizado.
        pai->esq = novo;                                   // Liga o novo no como filho esquerdo.
    } else {                                               // Situacao complementar: a chave e maior.
        pai->dir = novo;                                   // Liga o novo no como filho direito.
    }                                                      // Finaliza a atualizacao do pai ou da raiz.

    A->n++;                                                // Aumenta o contador uma unica vez.
    return 1;                                              // Sinaliza insercao realizada com sucesso.
}                                                          // Finaliza insere.

// =============================================================
// REMOCAO DE CHAVE
// =============================================================

int removeChave(Arvore* A, int chave) {                    // Remove uma chave existente da ABB.
    if (!A || A->raiz == NULL) return 0;                   // Nao ha o que remover se a arvore e vazia.

    int removido = 0;                                      // Inicializa indicador de sucesso como falso.
    A->raiz = removeRec(A->raiz, chave, &removido);        // Atualiza a raiz apos a recursao.

    if (removido) A->n--;                                  // Diminui o tamanho somente se removeu uma chave.

    return removido;                                       // Devolve 1 quando removeu, ou 0 se nao achou.
}                                                          // Finaliza removeChave.

// =============================================================
// LOCALIZACAO DO MENOR VALOR
// =============================================================

No* minimo(No* r) {                                        // Procura o menor valor de uma subarvore.
    if (!r) return NULL;                                   // Subarvore vazia nao tem menor elemento.

    while (r->esq) r = r->esq;                             // Continua descendo enquanto existir filho esquerdo.

    return r;                                              // Retorna o no mais a esquerda.
}                                                          // Finaliza minimo.

// =============================================================
// LOCALIZACAO DO MAIOR VALOR
// =============================================================

No* maximo(No* r) {                                        // Procura o maior valor de uma subarvore.
    if (!r) return NULL;                                   // Subarvore vazia nao tem maior elemento.

    while (r->dir) r = r->dir;                             // Continua descendo enquanto existir filho direito.

    return r;                                              // Retorna o no mais a direita.
}                                                          // Finaliza maximo.

// =============================================================
// PERCURSO EM ORDEM
// =============================================================

void imprimeInOrdem(No* r) {                               // Percorre esquerda, raiz, direita.
    if (r == NULL) return;                                 // Caso base: nenhuma chave a imprimir.

    imprimeInOrdem(r->esq);                                // Mostra primeiro as chaves da esquerda.
    printf("%d ", r->chave);                               // Imprime a chave do no atual.
    imprimeInOrdem(r->dir);                                // Mostra finalmente as chaves da direita.
}                                                          // Finaliza o percurso em ordem.

// =============================================================
// PERCURSO EM PRE-ORDEM
// =============================================================

void imprimePreOrdem(No* r) {                              // Percorre raiz, esquerda, direita.
    if (r == NULL) return;                                 // Caso base interrompe a descida em NULL.

    printf("%d ", r->chave);                               // Imprime primeiro a chave do no atual.
    imprimePreOrdem(r->esq);                               // Percorre a subarvore esquerda.
    imprimePreOrdem(r->dir);                               // Percorre a subarvore direita.
}                                                          // Finaliza o percurso em pre-ordem.

// =============================================================
// PERCURSO EM POS-ORDEM
// =============================================================

void imprimePosOrdem(No* r) {                              // Percorre esquerda, direita, raiz.
    if (r == NULL) return;                                 // Caso base: ramo inexistente.

    imprimePosOrdem(r->esq);                               // Visita todos os nos da esquerda.
    imprimePosOrdem(r->dir);                               // Visita todos os nos da direita.
    printf("%d ", r->chave);                               // Imprime o atual somente apos os filhos.
}                                                          // Finaliza o percurso em pos-ordem.

// =============================================================
// DESTRUICAO COMPLETA DA ARVORE
// =============================================================

void destroiArvore(Arvore* A) {                            // Devolve toda a memoria reservada pela ABB.
    if (!A) return;                                        // Evita desreferenciar ponteiro de controle nulo.

    liberaRec(A->raiz);                                    // Libera os nos da arvore em pos-ordem.
    free(A);                                               // Libera a propria estrutura de controle.
}                                                          // Finaliza destroiArvore; A nao deve mais ser usado.