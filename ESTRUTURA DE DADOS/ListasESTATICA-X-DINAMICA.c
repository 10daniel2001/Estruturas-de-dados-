/*
===============================================================================
Autor: Daniel
Descrição:
    Demonstração simples de:
    1) Lista Estática (vetor com tamanho fixo)
    2) Lista Dinâmica (alocação com malloc e expansão com realloc)

Objetivo:
    Mostrar a diferença entre memória Stack (estática)
    e memória Heap (dinâmica).

Observações Importantes:
    - Nunca acessar índices fora do tamanho alocado.
    - Sempre liberar memória alocada com free().
===============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

/*
===============================================================================
FUNÇÃO: Estatica
Descrição:
    Demonstra um vetor estático.
    O tamanho é definido em tempo de compilação.
    A memória é alocada na STACK.
===============================================================================
*/
void Estatica() {

    // Índices:   0   1   2   3   4
    int vetor[5] = {11, 13, 14, 15, 16};

    printf("\n> LISTA ESTATICA\n");

    // Acesso seguro ao índice 2 (valor 14)
    printf("Elemento no indice 2: %d\n", vetor[2]);
}


/*
===============================================================================
FUNÇÃO: Dinamica
Descrição:
    Demonstra alocação dinâmica de memória usando:
        - malloc  (alocar)
        - realloc (expandir)
        - free    (liberar)

    A memória é alocada na HEAP.
===============================================================================
*/
void Dinamica() {

    printf("\n> LISTA DINAMICA\n");

    /*
    ---------------------------------------------------------------------------
    PASSO 1: Alocar memória para 3 inteiros
    ---------------------------------------------------------------------------
    malloc retorna um ponteiro para o primeiro endereço reservado.
    sizeof(int) garante portabilidade.
    */
    int* numero = (int*) malloc(3 * sizeof(int));

    // Verificação obrigatória de segurança
    if (numero == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    /*
    Após malloc(3):

        Indices validos: 0, 1, 2
    */

    numero[0] = 11;
    numero[1] = 13;
    numero[2] = 14;

    printf("Elemento no indice 2: %d\n", numero[2]);

    /*
    ---------------------------------------------------------------------------
    PASSO 2: Expandir memória para 5 inteiros
    ---------------------------------------------------------------------------
    realloc pode:
        - Expandir no mesmo local
        - Mover para outro endereço
    Por isso, sempre atribuímos o retorno novamente ao ponteiro.
    */

    int* temp = (int*) realloc(numero, 5 * sizeof(int));

    // Verificação de segurança
    if (temp == NULL) {
        printf("Erro ao realocar memoria.\n");
        free(numero); // evita vazamento
        return;
    }

    numero = temp;

    /*
    Agora temos:

        Indices validos: 0, 1, 2, 3, 4
    */

    numero[3] = 15;
    numero[4] = 16;

    printf("Elemento recem adicionado no indice 3: %d\n", numero[3]);

    /*
    ---------------------------------------------------------------------------
    PASSO 3: Liberar memória
    ---------------------------------------------------------------------------
    Sempre liberar memória da HEAP para evitar memory leak.
    */
    free(numero);
}


/*
===============================================================================
FUNÇÃO PRINCIPAL
===============================================================================
*/
int main() {

    printf("=================================\n");
    printf(" DEMONSTRACAO: LISTA ESTATICA vs DINAMICA\n");
    printf("=================================\n");

    Estatica();
    Dinamica();

    return 0;
}