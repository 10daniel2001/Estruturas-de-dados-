/*
---

## Estrutura do código

### Função `trocar`
Responsável por trocar dois valores de posição usando ponteiros.

### Função `selectionSort`
Implementa o algoritmo Selection Sort:
- Usa dois laços `for`
- Procura o menor valor
- Faz apenas uma troca por iteração

### Função `main`
- Cria o vetor
- Chama a função de ordenação
- Mostra o vetor ordenado na tela

---

## Complexidade

- Tempo: **O(n²)**
- Espaço: **O(1)**

Isso significa que o algoritmo é simples, porém lento para vetores grandes.

---

## Quando usar

- Para estudar lógica de programação
- Para aprender algoritmos de ordenação
- Para vetores pequenos

---

## Como compilar e executar

No terminal Linux:

```bash
gcc selection_sort.c -o selection_sort
./selection_sort */

// Carlos daniel 

#include <stdio.h>

// Função responsável por trocar dois valores de lugar
// Recebe os ENDEREÇOS das variáveis (ponteiros)
void trocar(int* a, int* b) {
    int temp = *a;   // guarda o valor de 'a' temporariamente
    *a = *b;         // coloca o valor de 'b' em 'a'
    *b = temp;       // coloca o valor guardado em 'b'
}

// Função de ordenação Selection Sort
void selectionSort(int vetor[], int tamanho) {

    // Percorre o vetor da primeira até a penúltima posição
    for (int i = 0; i < tamanho - 1; i++) {

        // Assume que o menor valor está na posição i
        int indic = i;

        // Percorre o restante do vetor procurando um valor menor
        for (int j = i + 1; j < tamanho; j++) {

            // Se encontrar um valor menor que o atual mínimo
            if (vetor[j] < vetor[indic]) {
                indic = j; // atualiza o índice do menor valor
            }
        }

        // Se o menor valor não estiver na posição correta
        if (indic != i) {
            // Troca o valor atual com o menor encontrado
            trocar(&vetor[i], &vetor[indic]);
        }
    }
}

int main() {

    // Criação do vetor desordenado
    int vetor[5] = {3, 5, 2, 1, 4};

    // Tamanho do vetor
    int tamanho = 5;

    // Chamada da função de ordenação
    selectionSort(vetor, tamanho);

    // Impressão do vetor já ordenado
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0; // Finaliza o programa
}
