# Estruturas de Dados em C

Repositório com implementações de **estruturas de dados e algoritmos clássicos em C**, focado em estudo, prática e refatoração de lógica.

O objetivo é consolidar conceitos fundamentais de forma simples, clara e incremental.

---

## 📌 Conteúdos

* Fila Circular (FIFO)
* Pilha Estática (LIFO)
* Algoritmo de Ordenação Selection Sort

---

## 🔁 Fila Circular em C (FIFO)

Este projeto implementa uma **fila circular estática** em C utilizando um vetor de tamanho fixo.

A fila segue o princípio **FIFO (First In, First Out)**, onde o primeiro elemento inserido é o primeiro a ser removido.

### 🧠 Conceitos Demonstrados

* Estrutura de fila
* Controle de índices
* Lógica circular com operador módulo (%)
* Uso de structs e vetores

---

### 🧱 Estruturas Utilizadas

**Pessoa** – representa um elemento da fila:

```c
typedef struct {
    char nome[50];
    int idade;
} Pessoa;
```

**Fila** – controla a fila circular:

```c
typedef struct {
    Pessoa itens[TAM];
    int inicio;
    int fim;
    int total;
} Fila;
```

---

### ⚙️ Operações Implementadas

* `inicializar` – configura a fila vazia
* `filaCheia` – verifica se a fila atingiu o limite
* `filaVazia` – verifica se não há elementos
* `enqueue` – insere um elemento no final da fila
* `dequeue` – remove o elemento mais antigo
* `mostrar` – exibe os elementos na ordem lógica

---

### ▶️ Exemplo de Saída

```
Fila mostrar
A --- 0
B --- 1
C --- 2
D --- 3
E --- 4

Pessoa removida: A - 0

Fila mostrar
B --- 1
C --- 2
D --- 3
E --- 4
```

---

### 🛠️ Compilação e Execução

```bash
gcc fila.c -o fila
./fila
```

---

## 📚 Pilha Estática em C (LIFO)

Implementação de uma **pilha estática** utilizando vetores em C.

A pilha segue o princípio **LIFO (Last In, First Out)**, onde o último elemento inserido é o primeiro a ser removido.

---

### 🧠 Conceitos da Pilha

Operações clássicas:

* `PUSH` – inserir no topo
* `POP` – remover do topo
* `PEEK` – consultar o topo
* `EMPTY` – verificar se está vazia
* `FULL` – verificar se está cheia

Uso comum em:

* Call Stack (chamadas de função)
* Desfazer ações (Ctrl + Z)
* Expressões matemáticas
* Histórico de navegação

---

### 🧱 Estruturas Utilizadas

```c
typedef struct {
    char nome[49];
    int idade;
} Pessoa;
```

```c
typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;
```

---

### ⚙️ Funções Implementadas

* `inicializarPilha()` – define o topo como -1
* `pilha_vazia()` – verifica se a pilha está vazia
* `pilha_cheia()` – verifica se a pilha está cheia
* `push()` – insere um elemento no topo
* `pop()` – remove o elemento do topo
* `peek()` – consulta o topo
* `mostrar()` – exibe do topo para a base

---

### ▶️ Exemplo de Execução

```
Pilha - Topo -> Base
E -- 4
D -- 3
C -- 2
B -- 1
A -- 0

Removida: E - 4

Pilha - Topo -> Base
D -- 3
C -- 2
B -- 1
A -- 0

Topo atual: D - 3
```

---

### 🛠️ Compilação e Execução

**Linux:**

```bash
gcc pilha.c -o pilha
./pilha
```

**Windows (MinGW):**

```bash
gcc pilha.c -o pilha.exe
pilha.exe
```

---

### 📌 Observações

* Tamanho fixo definido por `#define MAX 5`
* Todas as operações são **O(1)**
* Ideal para estudo de lógica e estruturas de dados

---

## 🔢 Selection Sort em C

Implementação do algoritmo **Selection Sort** em C, voltada para aprendizado.

---

### ❓ O que é Selection Sort?

Algoritmo de ordenação simples que funciona assim:

1. Procura o menor elemento do vetor
2. Coloca esse elemento na primeira posição
3. Repete o processo para o restante do vetor
4. Continua até o vetor estar ordenado

---

### 🧠 Estrutura do Código

* `trocar()` – troca dois valores usando ponteiros
* `selectionSort()` – executa o algoritmo
* `main()` – cria o vetor, ordena e exibe

---

### ⏱️ Complexidade

* Tempo: **O(n²)**
* Espaço: **O(1)**

Algoritmo simples, porém ineficiente para grandes volumes de dados.

---

### 📌 Quando Usar

* Estudo de lógica
* Aprendizado de algoritmos de ordenação
* Vetores pequenos

---

### 🛠️ Compilação e Execução

```bash
gcc selection_sort.c -o selection_sort
./selection_sort
```

---

## 🧮 Tabela Hash em C (Hash Table)

Este projeto implementa uma **tabela hash com tratamento de colisões por encadeamento**, utilizando listas encadeadas.

A tabela hash permite **inserção, busca e remoção eficientes**, mesmo com colisões.

---

### 🧠 Conceitos Demonstrados

* Função hash baseada em strings
* Conversão de chave em índice
* Tratamento de colisões com lista encadeada
* Uso de ponteiros e alocação dinâmica

---

### 🧱 Estruturas Utilizadas

**Nodo** – representa um elemento da lista encadeada:

```c
typedef struct Nodo {
    char nome[50];
    struct Nodo *prox;
} Nodo;
```

**Tabela Hash** – vetor de listas encadeadas:

```c
#define TAM 10
Nodo* tabela_hash[TAM];
```

---

### ⚙️ Funções Implementadas

* `funcao_hash()` – converte uma string em índice
* `inserir()` – insere um elemento na tabela
* `buscar()` – procura um elemento pela chave
* `remover()` – remove um elemento da tabela

---

### ▶️ Exemplo de Execução

```
Buscando 'carlos': Encontrado
Buscando 'da': Encontrado
Buscando 'Car': Nao encontrado
Buscando 'costa': Encontrado

carlos removido
```

---

### ⏱️ Complexidade

* Inserção média: **O(1)**
* Busca média: **O(1)**
* Remoção média: **O(1)**
* Pior caso (muitas colisões): **O(n)**

---

### 🛠️ Compilação e Execução

```bash
gcc tabela_hash.c -o tabela_hash
./tabela_hash
```

---

## 🎯 Objetivo do Repositório

* Consolidar fundamentos de estruturas de dados
* Praticar lógica de programação em C
* Criar base sólida para estruturas mais avançadas
* Facilitar revisões e refatorações futuras
