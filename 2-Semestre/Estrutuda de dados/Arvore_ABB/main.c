#include "abb.h"                                           // Importa as operacoes da ABB implementadas no TAD.
#include <ctype.h>                                         // Cabecalho mantido do original; nao e usado neste menu.

int main(void) {                                           // Inicia o programa executado pelo usuario.
    Arvore* A = criaArvore();                              // Cria uma arvore dinamica inicialmente vazia.
    int op, x;                                             // Declara a opcao do menu e a chave digitada.

    do {                                                   // Repete as operacoes ate escolher a opcao zero.
        printf("\n=== MENU ABB ===\n");                    // Mostra o titulo e inicia uma nova linha.
        printf("1 - Inserir\n");                           // Apresenta a opcao de inserir chave.
        printf("2 - Remover\n");                           // Apresenta a opcao de remover chave.
        printf("3 - Buscar\n");                            // Apresenta a opcao de localizar chave.
        printf("4 - In-Ordem (crescente)\n");              // Apresenta o percurso crescente.
        printf("5 - Pre-Ordem\n");                         // Apresenta o percurso raiz-esquerda-direita.
        printf("6 - Pos-Ordem\n");                         // Apresenta o percurso esquerda-direita-raiz.
        printf("7 - Min e Max\n");                         // Apresenta a consulta dos valores extremos.
        printf("8 - Altura e Tamanho\n");                   // Apresenta as estatisticas da arvore.
        printf("9 - Destruir e Recriar\n");                // Apresenta o reinicio da estrutura.
        printf("0 - Sair\n");                              // Apresenta a opcao de encerrar.
        printf("Opcao: ");                                 // Pede a escolha do usuario.

        if (scanf("%d", &op) != 1) {                       // Verifica se foi possivel ler um inteiro.
            puts("Entrada invalida.");                     // Informa que a entrada nao e um inteiro.
            break;                                          // Sai do laco; a arvore sera destruida ao final.
        }                                                  // Fecha a validacao da opcao do menu.

        switch (op) {                                      // Encaminha a execucao para a opcao escolhida.
            case 1:                                        // Trata a insercao.
                printf("Valor: ");                         // Solicita a chave inteira.
                if (scanf("%d", &x) != 1) break;           // Nao usa x se a leitura falhar.
                puts(insere(A, x) ? "Inserido!" : "Duplicado: nao inserido."); // Exibe retorno.
                break;                                     // Termina o caso de insercao.

            case 2:                                        // Trata a remocao.
                printf("Valor: ");                         // Solicita o numero a ser removido.
                if (scanf("%d", &x) != 1) break;           // Interrompe o caso se ler nao funcionar.
                puts(removeChave(A, x) ? "Removido!" : "Nao encontrado."); // Mostra sucesso ou ausencia.
                break;                                     // Termina o caso de remocao.

            case 3:                                        // Trata a busca.
                printf("Valor: ");                         // Solicita o numero a ser procurado.
                if (scanf("%d", &x) != 1) break;           // Impede uso de dado nao inicializado.
                puts(busca(A, x) ? "Encontrado!" : "Nao encontrado."); // Exibe o resultado da busca.
                break;                                     // Termina o caso de busca.

            case 4:                                        // Trata o percurso em ordem.
                printf("In-Ordem: ");                      // Escreve o titulo do percurso.
                imprimeInOrdem(A->raiz);                   // Mostra as chaves em ordem crescente.
                puts("");                                  // Finaliza a linha apos a impressao.
                break;                                     // Termina o caso de percurso em ordem.

            case 5:                                        // Trata o percurso em pre-ordem.
                printf("Pre-Ordem: ");                     // Escreve o titulo do percurso.
                imprimePreOrdem(A->raiz);                  // Visita raiz, esquerda e direita.
                puts("");                                  // Finaliza a linha apos o percurso.
                break;                                     // Termina o caso de pre-ordem.

            case 6:                                        // Trata o percurso em pos-ordem.
                printf("Pos-Ordem: ");                     // Escreve o titulo do percurso.
                imprimePosOrdem(A->raiz);                  // Visita esquerda, direita e raiz.
                puts("");                                  // Finaliza a linha apos o percurso.
                break;                                     // Termina o caso de pos-ordem.

            case 7: {                                      // Abre um bloco local para as variaveis dos extremos.
                No* a = minimo(A->raiz);                   // Recebe o no de menor chave ou NULL.
                No* b = maximo(A->raiz);                   // Recebe o no de maior chave ou NULL.

                printf("Min: ");                           // Imprime o rotulo do menor elemento.
                a ? printf("%d", a->chave) : printf("NA"); // Exibe o minimo ou NA se vazia.

                printf(" | Max: ");                        // Imprime o rotulo do maior elemento.
                b ? printf("%d", b->chave) : printf("NA"); // Exibe o maximo ou NA se vazia.

                puts("");                                  // Encerra a linha de minimo e maximo.
            } break;                                        // Fecha o bloco local e conclui o caso 7.

            case 8:                                        // Trata a consulta de altura e tamanho.
                printf("Altura: %d Tamanho: %d\n", altura(A), numeroNos(A)); // Exibe as metricas.
                break;                                     // Termina o caso 8.

            case 9:                                        // Trata o reinicio da estrutura.
                destroiArvore(A);                          // Libera cada no e a estrutura de controle.
                puts("Arvore destruida.");                 // Informa o resultado da liberacao.

                A = criaArvore();                          // Cria novo objeto valido para continuar o menu.
                puts("Arvore recriada (vazia).");          // Confirma a nova arvore vazia.
                break;                                     // Termina o caso 9.

            case 0:                                        // Trata a solicitacao de encerramento.
                break;                                     // Sai do switch; a condicao do laco terminara.

            default:                                       // Trata qualquer numero fora das opcoes.
                puts("Opcao invalida!");                   // Informa ao usuario a escolha inexistente.
        }                                                  // Fecha a selecao switch.

    } while (op != 0);                                     // Continua enquanto a opcao nao for zero.

    destroiArvore(A);                                      // Evita vazamentos ao sair do programa.

    return 0;                                              // Devolve codigo de termino normal ao sistema.
}                                                          // Encerra a funcao principal.