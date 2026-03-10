#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Tamanho máximo da fila e da pilha

// Estrutura Pessoa
typedef struct {
    int numero;
    int idade;
} Pessoa;

// Estrutura Fila (FIFO)
typedef struct {
    Pessoa dados[MAX];
    int inicio;
    int fim;
} Fila;

// Estrutura Pilha (LIFO)
typedef struct {
    Pessoa dadus[MAX]; // nome diferente apenas para identificar a pilha
    int topo;
} Pilha;

// Inicializa fila
void inicializarfila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

// Inicializa pilha
void inicializarpilha(Pilha *p) {
    p->topo = -1;
}

// Verifica se a fila está cheia
int fcheia(Fila *f) {
    return f->fim == MAX;
}

// Verifica se a fila está vazia
int fvazia(Fila *f) {
    return f->inicio == f->fim;
}

// Verifica se a pilha está cheia
int pilhacheia(Pilha *p) {
    return p->topo == MAX - 1;
}

// Verifica se a pilha está vazia
int pilhavazia(Pilha *p) {
    return p->topo == -1;
}

// Insere na fila
void inserir(Fila *f, Pessoa p) {
    if (!fcheia(f)) {
        f->dados[f->fim++] = p;
    }
}

// Remove da fila
Pessoa dequeue(Fila *f) {
    return f->dados[f->inicio++];
}

// Empilha
void push(Pilha *p, Pessoa pex) {
    if (!pilhacheia(p)) {
        p->dadus[++p->topo] = pex;
    }
}

// Desempilha
Pessoa pop(Pilha *p) {
    return p->dadus[p->topo--];
}

// Exibe a fila
void exibirfila(Fila *f) {
    for (int i = f->inicio; i < f->fim; i++) {
        printf("%d -- %d\n", f->dados[i].numero, f->dados[i].idade);
    }
}

int main() {

    Fila fo, fi;
    Pilha auxiliar;

    inicializarfila(&fo);
    inicializarfila(&fi);
    inicializarpilha(&auxiliar);

    Pessoa pessoas[] = {
        {1, 45}, {2, 62}, {3, 30}, {4, 75}
    };

    // Inserindo na fila original
    for (int i = 0; i < 4; i++) {
        inserir(&fo, pessoas[i]);
    }

    // Passa da fila para a pilha
    while (!fvazia(&fo)) {
        push(&auxiliar, dequeue(&fo));
    }

    // Passa da pilha para a nova fila (inverte)
    while (!pilhavazia(&auxiliar)) {
        inserir(&fi, pop(&auxiliar));
    }

    printf("Fila invertida:\n");
    exibirfila(&fi);

    return 0;
}
