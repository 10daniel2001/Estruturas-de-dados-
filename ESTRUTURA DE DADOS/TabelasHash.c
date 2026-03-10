#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10   // Tamanho da tabela hash

// Nó da lista encadeada
typedef struct Nodo {
    char nome[50];
    struct Nodo *prox;
} Nodo;

// Tabela hash (vetor de listas encadeadas)
Nodo* tabela_hash[TAM] = { NULL };

/*
 * Função hash simples
 * Soma os valores ASCII dos caracteres da string
 * e aplica o módulo do tamanho da tabela
 */
int funcao_hash(const char* chave) {
    int soma = 0;

    for (int i = 0; chave[i] != '\0'; i++) {
        soma += chave[i];
    }

    return soma % TAM;
}

/*
 * Insere um nome na tabela hash
 * Usa encadeamento para tratar colisões
 */
void inserir(const char* nome) {
    int indice = funcao_hash(nome);

    Nodo* novo = (Nodo*)malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria\n");
        return;
    }

    strcpy(novo->nome, nome);
    novo->prox = tabela_hash[indice];
    tabela_hash[indice] = novo;
}

/*
 * Busca um nome na tabela hash
 * Retorna o ponteiro do nodo ou NULL se não encontrar
 */
Nodo* buscar(const char* nome) {
    int indice = funcao_hash(nome);
    Nodo* atual = tabela_hash[indice];

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {
            return atual;
        }
        atual = atual->prox;
    }

    return NULL;
}

/*
 * Remove um nome da tabela hash
 */
void remover(const char* nome) {
    int indice = funcao_hash(nome);
    Nodo* atual = tabela_hash[indice];
    Nodo* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->nome, nome) == 0) {

            if (anterior == NULL) {
                tabela_hash[indice] = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }

            free(atual);
            printf("%s removido\n", nome);
            return;
        }

        anterior = atual;
        atual = atual->prox;
    }

    printf("Nao encontrado: %s\n", nome);
}

int main() {
    inserir("carlos");
    inserir("daniell");
    inserir("godoi");
    inserir("da");
    inserir("costa");

    printf("Buscando 'carlos': %s\n", buscar("carlos") ? "Encontrado" : "Nao encontrado");
    printf("Buscando 'da': %s\n", buscar("da") ? "Encontrado" : "Nao encontrado");
    printf("Buscando 'Car': %s\n", buscar("Car") ? "Nao encontrado" : "Encontrado");
    printf("Buscando 'costa': %s\n", buscar("costa") ? "Encontrado" : "Nao encontrado");

    remover("carlos");

    return 0;
}
