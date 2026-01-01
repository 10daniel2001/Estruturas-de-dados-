# Estruturas-de-dados-
Lançando códigos de estruturas de dados para melhor entender e refatorar meus conhecimentos em logica 

Fila Circular em C

Este projeto implementa uma fila circular estática em C utilizando um vetor de tamanho fixo.
A estrutura demonstra de forma simples o funcionamento de uma fila do tipo FIFO (First In, First Out) e as operações fundamentais de manipulação.

Descrição

A implementação utiliza duas estruturas:

Pessoa: representa um item da fila, contendo nome e idade.

Fila: contém o vetor de elementos, os índices de início e fim, e o contador total de itens.

O comportamento da fila é circular, usando o operador módulo (%) para retornar ao início do vetor quando o índice chega ao limite.

Operações implementadas

inicializar
Configura a fila deixando início, fim e total igual a zero.

filacheia
Verifica se o número total de elementos atingiu o tamanho máximo.

filavazia
Indica se não há itens na fila.

enqueue
Insere um novo elemento no final da fila, caso haja espaço disponível.

dequeue
Remove o elemento mais antigo da fila (FIFO) e ajusta os índices.

mostrar
Exibe todos os elementos na ordem lógica da fila.

Como compilar
gcc fila.c -o fila

Como executar
./fila

Exemplo de saída
Fila mostrar
A --- 0
B --- 1
C --- 2
D --- 3
E --- 4

pessoa removida A - 0
Fila mostrar
B --- 1
C --- 2
D --- 3
E --- 4

Objetivo do código

Demonstrar de forma prática e clara:

funcionamento de filas

manipulação de índices

lógica circular

estruturação de dados em C

-------------------------------------------------------------------------------------------------
Implementação de Pilha em C (LIFO)

Este projeto apresenta a implementação de uma Pilha estática utilizando vetores em linguagem C.
A Pilha segue o princípio LIFO (Last In, First Out), onde o último elemento inserido é o primeiro a ser removido.

A estrutura foi construída para armazenar elementos do tipo Pessoa, contendo um nome e uma idade.

📌 Conceitos da Pilha

Uma Pilha (Stack) possui as seguintes operações clássicas:

PUSH — Inserir um elemento no topo

POP — Remover o elemento do topo

PEEK — Consultar o topo sem remover

EMPTY — Verificar se está vazia

FULL — Verificar se está cheia

As pilhas são amplamente usadas em:

Chamadas de funções (call stack)

Desfazer ações (Ctrl+Z)

Interpretação de expressões matemáticas

Navegação entre páginas (histórico do navegador)

📁 Estruturas Utilizadas
Estrutura Pessoa
typedef struct {
    char nome[49];
    int idade;
} Pessoa;

Estrutura Pilha
typedef struct {
    Pessoa itens[max];
    int topo;
} Pilha;

⚙️ Funções Implementadas
inicializarpilha()

Define o topo como -1, indicando pilha vazia.

void inicializarpilha(Pilha *p);

pilha_vazia()

Retorna 1 se o topo for igual a -1.

int pilha_vazia(Pilha *p);

pilha_cheia()

Retorna 1 se o topo estiver no último índice do vetor.

int pilha_cheia(Pilha *p);

push()

Insere um elemento no topo da pilha.

void push(Pilha *p, Pessoa n);

pop()

Remove o elemento do topo e o envia para a variável indicada.

void pop(Pilha *p, Pessoa *r);

peek()

Consulta o elemento do topo sem removê-lo.

void peek(Pilha *p, Pessoa *v);

Mostrar()

Exibe a pilha do topo até a base.

void Mostrar(Pilha *p);

▶️ Exemplo de Execução
Pilha - Topo -> Base
E -- 4
D -- 3
C -- 2
B -- 1
A -- 0

Removida E - 4

Pilha - Topo -> Base
D -- 3
C -- 2
B -- 1
A -- 0

Visualizar topo atual -> D - 3

🧾 Arquivo Principal

O main() demonstra o uso completo da pilha: inicialização, inserção, remoção e visualização.

🛠️ Compilar e Executar

No Linux:

gcc pilha.c -o pilha
./pilha


No Windows (MinGW):

gcc pilha.c -o pilha.exe
pilha.exe

📚 Observações

A pilha tem tamanho fixo definido por #define max 5.

Todas as operações são O(1).

Ideal para estudo de estruturas de dados e lógica de pilha.


# Selection Sort em C

Este projeto demonstra a implementação do algoritmo **Selection Sort** na linguagem C, com foco em aprendizado para iniciantes.

---

## O que é Selection Sort?

Selection Sort é um algoritmo de ordenação simples que funciona da seguinte forma:

1. Procura o menor elemento do vetor.
2. Coloca esse elemento na primeira posição.
3. Repete o processo para o restante do vetor.
4. Continua até o vetor ficar totalmente ordenado.

---

## Como o algoritmo funciona

Dado o vetor:

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
./selection_sort
