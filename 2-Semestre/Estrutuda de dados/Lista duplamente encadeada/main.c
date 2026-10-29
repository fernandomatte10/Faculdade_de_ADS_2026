#include "lista_dupla.h"                            // Importa os tipos e protótipos do TAD Lista Dupla.

int main(void) {
    Lista* L = criaLista();                         // Cria uma lista vazia.

    int opcao, valor;                               // Armazena a opção e os valores digitados pelo usuário.

    do {                                            // Repete o menu até que o usuário escolha a opção 0.
        printf("\n===== MENU =====\n");             // Exibe o título do menu.
        printf("1 - Inserir no inicio\n");          // Opção 1.
        printf("2 - Inserir no fim\n");             // Opção 2.
        printf("3 - Imprimir lista\n");             // Opção 3.
        printf("4 - Imprimir reverso\n");           // Opção 4.
        printf("5 - Buscar valor\n");               // Opção 5.
        printf("6 - Remover do inicio\n");          // Opção 6.
        printf("7 - Remover do fim\n");             // Opção 7.
        printf("8 - Remover por valor\n");          // Opção 8.
        printf("9 - Destruir lista\n");             // Opção 9.
        printf("10 - Insere depois de um No especifico\n");
        printf("0 - Sair\n");                       // Opção 0.
        printf("Escolha: ");                        // Solicita a opção desejada.

        scanf("%d", &opcao);                        // Lê a opção escolhida.

        switch (opcao) {                            // Executa a operação selecionada.
            case 1: {                               // Insere um elemento no início da lista.
                printf("Valor: ");                  // Solicita o valor a ser inserido.
                scanf("%d", &valor);                // Lê o valor digitado.

                insereInicio(L, valor);             // Insere o valor no início da lista.

                break;                              // Encerra o caso atual.
            }

            case 2: {                               // Insere um elemento no fim da lista.
                printf("Valor: ");                  // Solicita o valor a ser inserido.
                scanf("%d", &valor);                // Lê o valor digitado.

                insereFim(L, valor);                // Insere o valor no fim da lista.

                break;                              // Encerra o caso atual.
            }

            case 3: {                               // Imprime os elementos do início ao fim.
                imprime(L);                         // Executa a impressão normal da lista.

                break;                              // Encerra o caso atual.
            }

            case 4: {                               // Imprime os elementos do fim ao início.
                imprimeReverso(L);                  // Executa a impressão reversa da lista.

                break;                              // Encerra o caso atual.
            }

            case 5: {                               // Busca um elemento pelo valor.
                printf("Valor: ");                  // Solicita o valor a ser procurado.
                scanf("%d", &valor);                // Lê o valor digitado.

                No* p = busca(L, valor);            // Busca o nó e recebe seu endereço ou NULL.

                if (p != NULL) {                    // Verifica se o valor foi encontrado.
                    printf("Encontrado! Valor = %d | Endereco = %p\n", p->dado, (void*) p); // Exibe o valor e o endereço do nó.
                } else {                            // Executa caso o valor não seja encontrado.
                    printf("Valor nao encontrado.\n"); // Informa que o valor não existe.
                }

                break;                              // Encerra o caso atual.
            }

            case 6: {                               // Remove o primeiro nó da lista.
                removeInicio(L);                    // Remove o elemento do início.

                break;                              // Encerra o caso atual.
            }

            case 7: {                               // Remove o último nó da lista.
                removeFim(L);                       // Remove o elemento do fim.

                break;                              // Encerra o caso atual.
            }

            case 8: {                               // Remove um elemento pelo valor.
                printf("Valor: ");                  // Solicita o valor a ser removido.
                scanf("%d", &valor);                // Lê o valor digitado.

                removeValor(L, valor);              // Remove a primeira ocorrência do valor.

                break;                              // Encerra o caso atual.
            }

            case 9: {                               // Destrói a lista atual.
                destroiLista(L);                    // Libera os nós e a estrutura da lista.
                printf("Lista destruida!\n");       // Confirma a destruição da lista.

                L = criaLista();                    // Cria uma nova lista vazia para continuar usando o menu.

                break;                              // Encerra o caso atual.
            }

            case 10:
            
                printf("Valor: ");                  // Solicita o valor a ser procurado.
                scanf("%d", &valor);                // Lê o valor digitado.

                No* p = busca(L, valor);            // Busca o nó e recebe seu endereço ou NULL.

                if (p != NULL) {                    // Verifica se o valor foi encontrado.
                    printf("Encontrado! Valor = %d | Endereco = %p\n", p->dado, (void*) p); // Exibe o valor e o endereço do nó.
                } else {                            // Executa caso o valor não seja encontrado.
                    printf("Valor nao encontrado.\n"); // Informa que o valor não existe.
                }

            case 0: {                               // Encerra o programa.
                destroiLista(L);                    // Libera a memória da lista.
                printf("Saindo...\n");              // Exibe a mensagem de encerramento.

                break;                              // Encerra o caso atual.
            }

            default: {                              // Trata opções que não existem no menu.
                printf("Opcao invalida!\n");        // Informa que a opção é inválida.

                break;                              // Encerra o caso atual.
            }
        }

    } while (opcao != 0);                           // Repete o menu enquanto a opção for diferente de zero.

    return 0;                                       // Encerra o programa com sucesso.
}