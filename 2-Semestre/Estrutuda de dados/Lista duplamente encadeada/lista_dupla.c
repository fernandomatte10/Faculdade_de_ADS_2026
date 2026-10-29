#include "lista_dupla.h"                        // Importa os tipos e protótipos do TAD Lista.

// Cria e inicializa uma nova lista vazia.
Lista* criaLista(void) {
    Lista* L = malloc(sizeof(Lista));           // Aloca memória para a estrutura Lista.

    if (L == NULL) {                            // Verifica se a alocação de memória falhou.
        perror("Falha ao criar lista");         // Exibe uma mensagem de erro.
        exit(EXIT_FAILURE);                     // Encerra o programa em caso de falha.
    }

    L->ini = NULL;                              // Inicializa o início da lista como vazio.
    L->fim = NULL;                              // Inicializa o fim da lista como vazio.
    L->n = 0;                                   // Inicializa a quantidade de nós com zero.

    return L;                                   // Retorna o endereço da lista criada.
}

// Verifica se a lista está vazia.
int listaVazia(Lista* L) {
    return (L == NULL || L->n == 0);            // Retorna verdadeiro se a lista não existir ou estiver vazia.
}

// Libera toda a memória alocada pela lista.
void destroiLista(Lista* L) {
    if (L == NULL)                              // Verifica se a estrutura da lista não existe.
        return;                                 // Encerra a função sem realizar alterações.

    No* p = L->ini;                             // Começa a percorrer a lista pelo primeiro nó.

    while (p != NULL) {                         // Percorre todos os nós da lista.
        No* aux = p->prox;                      // Guarda o endereço do próximo nó.
        free(p);                                // Libera a memória do nó atual.
        p = aux;                                // Avança para o próximo nó.
    }

    free(L);                                    // Libera a memória da estrutura principal da lista.
}

// Insere um elemento no início da lista.
void insereInicio(Lista* L, int valor) {
    No* novo = malloc(sizeof(No));              // Aloca memória para o novo nó.

    if (novo == NULL) {                         // Verifica se a alocação de memória falhou.
        perror("malloc falhou");                // Exibe uma mensagem de erro.
        exit(EXIT_FAILURE);                     // Encerra o programa em caso de falha.
    }

    novo->dado = valor;                         // Armazena o valor no novo nó.
    novo->ant = NULL;                           // O novo primeiro nó não possui anterior.
    novo->prox = L->ini;                        // Aponta para o antigo primeiro nó.

    if (L->ini != NULL)                         // Verifica se a lista já possui elementos.
        L->ini->ant = novo;                     // Atualiza o anterior do antigo primeiro nó.
    else                                        // Caso a lista esteja vazia.
        L->fim = novo;                          // O novo nó também será o último.

    L->ini = novo;                              // Atualiza o início da lista.
    L->n++;                                     // Incrementa a quantidade de nós.
}

// Insere um elemento no final da lista.
void insereFim(Lista* L, int valor) {
    No* novo = malloc(sizeof(No));              // Aloca memória para o novo nó.

    if (novo == NULL) {                         // Verifica se a alocação de memória falhou.
        perror("malloc falhou");                // Exibe uma mensagem de erro.
        exit(EXIT_FAILURE);                     // Encerra o programa em caso de falha.
    }

    novo->dado = valor;                         // Armazena o valor no novo nó.
    novo->prox = NULL;                          // O novo último nó não possui próximo.
    novo->ant = L->fim;                         // Aponta para o antigo último nó.

    if (L->fim != NULL)                         // Verifica se a lista já possui elementos.
        L->fim->prox = novo;                    // Atualiza o próximo do antigo último nó.
    else                                        // Caso a lista esteja vazia.
        L->ini = novo;                          // O novo nó também será o primeiro.

    L->fim = novo;                              // Atualiza o final da lista.
    L->n++;                                     // Incrementa a quantidade de nós.
}

// Imprime os elementos da lista do início ao fim.
void imprime(const Lista* L) {
    const No* p = L->ini;                       // Começa pelo primeiro nó.

    printf("[");                                // Inicia a representação da lista.

    while (p != NULL) {                         // Percorre a lista até o final.
        printf("%d", p->dado);                  // Exibe o valor do nó atual.
        p = p->prox;                            // Avança para o próximo nó.
    }

    printf("]\n");                             // Finaliza a representação da lista.
}

// Imprime os elementos da lista do fim ao início.
void imprimeReverso(const Lista* L) {
    const No* p = L->fim;                       // Começa pelo último nó.

    printf("[");                                // Inicia a representação da lista.

    while (p != NULL) {                         // Percorre a lista no sentido inverso.
        printf("%d", p->dado);                  // Exibe o valor do nó atual.
        p = p->ant;                             // Retrocede para o nó anterior.
    }

    printf("]\n");                              // Finaliza a representação da lista.
}

// Busca um nó que contenha o valor especificado.
No* busca(Lista* L, int valor) {
    No* p = L->ini;                             // Começa a busca pelo primeiro nó.

    while (p != NULL) {                         // Percorre a lista até o final.
        if (p->dado == valor) {                 // Verifica se o nó contém o valor procurado.
            return p;                           // Retorna o endereço do nó encontrado.
        }

        p = p->prox;                            // Avança para o próximo nó.
    }

    return NULL;                                // Retorna NULL se o valor não for encontrado.
}

// Remove o primeiro nó da lista.
void removeInicio(Lista* L) {
    if (listaVazia(L)) {                        // Verifica se existe algum nó para remover.
        printf("Lista vazia!\n");               // Informa que a lista está vazia.
        return;                                 // Encerra a função sem realizar alterações.
    }

    No* p = L->ini;                             // Guarda o endereço do primeiro nó.
    L->ini = p->prox;                           // Atualiza o início para o próximo nó.

    if (L->ini != NULL)                         // Verifica se ainda existem elementos.
        L->ini->ant = NULL;                     // Remove a referência ao nó anterior.
    else                                        // Caso a lista fique vazia.
        L->fim = NULL;                          // Atualiza o final da lista.

    free(p);                                    // Libera a memória do nó removido.
    L->n--;                                     // Decrementa a quantidade de nós.
}

// Remove o último nó da lista.
void removeFim(Lista* L) {
    if (listaVazia(L)) {                        // Verifica se existe algum nó para remover.
        printf("Lista vazia!\n");               // Informa que a lista está vazia.
        return;                                 // Encerra a função sem realizar alterações.
    }

    No* p = L->fim;                             // Guarda o endereço do último nó.
    L->fim = p->ant;                            // Atualiza o final para o nó anterior.

    if (L->fim != NULL)                         // Verifica se ainda existem elementos.
        L->fim->prox = NULL;                    // Remove a referência ao próximo nó.
    else                                        // Caso a lista fique vazia.
        L->ini = NULL;                          // Atualiza o início da lista.

    free(p);                                    // Libera a memória do nó removido.
    L->n--;                                     // Decrementa a quantidade de nós.
}

// Remove a primeira ocorrência do valor especificado.
void removeValor(Lista* L, int valor) {
    if (listaVazia(L)) {                        // Verifica se a lista possui elementos.
        printf("Lista vazia!\n");               // Informa que a lista está vazia.
        return;                                 // Encerra a função sem realizar alterações.
    }

    No* p = busca(L, valor);                    // Busca a primeira ocorrência do valor.

    if (p == NULL) {                            // Verifica se o valor não foi encontrado.
        printf("Valor não encontrado!\n");      // Informa que o valor não existe na lista.
        return;                                 // Encerra a função sem alterar a lista.
    }

    if (p->ant != NULL)                         // Verifica se existe um nó anterior.
        p->ant->prox = p->prox;                 // Conecta o anterior ao próximo nó.
    else                                        // Caso o nó removido seja o primeiro.
        L->ini = p->prox;                       // Atualiza o início da lista.

    if (p->prox != NULL)                        // Verifica se existe um próximo nó.
        p->prox->ant = p->ant;                  // Conecta o próximo ao nó anterior.
    else                                        // Caso o nó removido seja o último.
        L->fim = p->ant;                        // Atualiza o final da lista.

    free(p);                                    // Libera a memória do nó removido.
    L->n--;                                     // Decrementa a quantidade de nós.
}



/*------------------------------------------------------------------------
********************************Atividades********************************
------------------------------------------------------------------------*/



void insereDepois(Lista* L, No* p, int valor) { // Insere depois de um No especifico

    if (listaVazia(L)) {                        // Verifica se a lista possui elementos.
        printf("Lista vazia!\n");               // Informa que a lista está vazia.
        return;                                 // Encerra a função sem realizar alterações.
    }

    p = busca(L, valor);                        // Busca a primeira ocorrência do valor.

    if (p == NULL) {                            // Verifica se o valor não foi encontrado.
        printf("Valor não encontrado!\n");      // Informa que o valor não existe na lista.
        return;                                 // Encerra a função sem alterar a lista.
    }
        
    No* novo = malloc(sizeof(No));              // Aloca memória para o novo nó.

    if (novo == NULL) {                         // Verifica se a alocação de memória falhou.
        perror("malloc falhou");                // Exibe uma mensagem de erro.
        exit(EXIT_FAILURE);                     // Encerra o programa em caso de falha.
    }
    
    novo->dado = valor;                         // Armazena o valor no novo nó.
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        void insereInicio(Lista* L, int valor) {
    No* novo = malloc(sizeof(No));              // Aloca memória para o novo nó.

    if (novo == NULL) {                         // Verifica se a alocação de memória falhou.
        perror("malloc falhou");                // Exibe uma mensagem de erro.
        exit(EXIT_FAILURE);                     // Encerra o programa em caso de falha.
    }

    novo->dado = valor;                         // Armazena o valor no novo nó.
    novo->ant = NULL;                           // O novo primeiro nó não possui anterior.
    novo->prox = L->ini;                        // Aponta para o antigo primeiro nó.

    if (L->ini != NULL)                         // Verifica se a lista já possui elementos.
        L->ini->ant = novo;                     // Atualiza o anterior do antigo primeiro nó.
    else                                        // Caso a lista esteja vazia.
        L->fim = novo;                          // O novo nó também será o último.

    L->ini = novo;                              // Atualiza o início da lista.
    L->n++;                                     // Incrementa a quantidade de nós.
}