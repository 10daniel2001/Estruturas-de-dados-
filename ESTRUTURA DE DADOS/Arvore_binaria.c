#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Arvore binaria didatica — nos conectados manualmente no main.
   Sem insercao automatica; estrutura serve para demonstrar
   os tres percursos classicos: pre-ordem, em-ordem e pos-ordem. */

typedef struct Nod {
    char dados[50];       /* buffer fixo; strings acima de 49 chars causam overflow */
    struct Nod* esquerdo; /* filho esquerdo; NULL se nao existe */
    struct Nod* direito;  /* filho direito;  NULL se nao existe */
} Nod;


/* Aloca e inicializa um no na heap.
   Retorna NULL se malloc falhar — caller deve verificar antes de usar. */
Nod* criar_no(const char* palavra) {
    Nod* novo = (Nod*)malloc(sizeof(Nod));
    if (!novo) return NULL;
    strncpy(novo->dados, palavra, sizeof(novo->dados) - 1);
    novo->dados[sizeof(novo->dados) - 1] = '\0'; /* garante terminador se palavra >= 50 chars */
    novo->esquerdo = NULL;
    novo->direito  = NULL;
    return novo;
}

/* Visita: raiz → esquerdo → direito.
   Util para copiar ou serializar a arvore, pois a raiz aparece primeiro. */
void preOrdem(Nod* raiz) {
    if (raiz != NULL) {
        printf("%s\n", raiz->dados);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

/* Visita: esquerdo → raiz → direito.
   Em uma BST produziria os nos em ordem alfabetica/crescente. */
void emOrdem(Nod* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerdo);
        printf("%s\n", raiz->dados);
        emOrdem(raiz->direito);
    }
}

/* Visita: esquerdo → direito → raiz.
   Util para deletar a arvore, pois filhos sao processados antes do pai. */
void posOrdem(Nod* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%s\n", raiz->dados);
    }
}

/* Libera toda a memoria alocada em pos-ordem:
   filhos sao liberados antes do pai, evitando ponteiros pendentes. */
void liberar(Nod* raiz) {
    if (raiz != NULL) {
        liberar(raiz->esquerdo);
        liberar(raiz->direito);
        free(raiz);
    }
}

int main() {
    Nod* raiz = criar_no("01-DONO");
    raiz->esquerdo = criar_no("02-Gerente");
    raiz->direito  = criar_no("03-Supervisor");

    printf("-- Pre-ordem --\n");
    preOrdem(raiz);

    printf("-- Em ordem --\n");
    emOrdem(raiz);

    printf("-- Pos-ordem --\n");
    posOrdem(raiz);

    liberar(raiz);
    return 0;
}