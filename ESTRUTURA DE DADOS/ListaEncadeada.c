/*Conceito deste codigo e reforça meus estudos em estruturas de dados 
Buscando melhorar e evoluir 

Intuito do codigo e apenas espelhar oque eu aprendi em c 
Em listas encadeadas com ponteiros e alocaçao de memoria 
Lista encadeadas dinamicas
*/


#include <stdio.h>  // Biblioteca para entrada e saida de dados
#include <stdlib.h>  // Biblioteca para uso de alocaçao de memoria

typedef struct No {
    int dados;
    struct No* proximo;
} No;

int main() {

    No* primeiro = (No*) malloc(sizeof(No)); // criando espaço em memoria para o primeiro
    No* segundo  = (No*) malloc(sizeof(No));
    No* terceiro = (No*) malloc(sizeof(No));

    // Atribuindo os dados
    primeiro->dados = 10;
    segundo->dados  = 20;
    terceiro->dados = 40;

    // Encadeando os nós
    primeiro->proximo = segundo;
    segundo->proximo  = terceiro;
    terceiro->proximo = NULL;

    // Percorrendo a lista
    No* atual = primeiro;

    while (atual != NULL) {   // verifica se atual dado  nao e null ou vazio
        printf("%d\n", atual->dados);
        atual = atual->proximo;
    }

    // Liberando memória
    free(primeiro);
    free(segundo);
    free(terceiro);

    return 0;
}
