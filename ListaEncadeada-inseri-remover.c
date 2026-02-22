#include <stdio.h>
#include <stdlib.h>

/*
    Estrutura do nó da lista encadeada.
    Cada nó possui:
    - dado: valor armazenado
    - proximo: ponteiro para o próximo nó
*/
struct No {
    int dado;
    struct No* proximo;
};

/*
    Insere um novo nó no início da lista.

    Parâmetros:
    - inicio: ponteiro para o ponteiro do primeiro nó
    - valor: valor a ser inserido
*/
void inserirnoinicio(struct No** inicio, int valor) {
    struct No* novo = (struct No*) malloc(sizeof(struct No));

    if (novo == NULL) {
        printf("Erro de alocacao de memoria.\n");
        return;
    }

    novo->dado = valor;
    novo->proximo = *inicio;
    *inicio = novo;
}

/*
    Remove o primeiro nó da lista.
*/
void removerdo(struct No** inicio) {
    if (*inicio != NULL) {
        struct No* temp = *inicio;
        *inicio = (*inicio)->proximo;
        free(temp);
    }
}

/*
    Percorre e imprime todos os elementos da lista.
*/
void Lista(struct No* inicio) {
    struct No* atual = inicio;

    while (atual != NULL) {
        printf("Valor inserido - %d\n", atual->dado);
        atual = atual->proximo;
    }
}

/*
    Realiza busca linear na lista.

    Retorna:
    - posição do elemento se encontrado
    - -1 caso não seja encontrado
*/
int buscalinear(struct No* inicio, int valor) {
    int pos = 0;
    struct No* atual = inicio;

    while (atual != NULL) {
        if (atual->dado == valor) {
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }

    return -1;
}

/*
    Função principal:
    - Cria lista
    - Insere elementos
    - Exibe lista
    - Remove primeiro elemento
    - Exibe novamente
*/
int main() {
    struct No* inicio = NULL;

    inserirnoinicio(&inicio, 10);
    inserirnoinicio(&inicio, 20);
    inserirnoinicio(&inicio, 30);

    printf("Lista inicial:\n");
    Lista(inicio);

    removerdo(&inicio);

    printf("\nLista apos remocao do primeiro elemento:\n");
    Lista(inicio);

    return 0;
}