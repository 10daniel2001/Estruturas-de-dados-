# 📚 Estruturas de Dados em C

Repositório dedicado ao estudo e implementação de estruturas de dados fundamentais em C, com foco em compreender profundamente o gerenciamento de memória, ponteiros e lógica de baixo nível.

---

## 🗂️ Conteúdo

### Listas

| Arquivo | Descrição |
|---|---|
| `ListaEncadeada.c` | Implementação base de lista encadeada simples |
| `ListaEncadeada-inseri-remover.c` | Lista encadeada com operações de inserção e remoção |
| `ListasESTATICA-X-DINAMICA.c` | Comparativo entre alocação estática e dinâmica de memória |

### Pilhas e Filas

| Arquivo | Descrição |
|---|---|
| `Pilhas.c` | Implementação de pilha (LIFO) com alocação dinâmica |
| `Filas.c` | Implementação de fila (FIFO) com alocação dinâmica |
| `Filas&Pilhas.c` | Estudo comparativo entre pilhas e filas |

### Ordenação

| Arquivo | Descrição |
|---|---|
| `Selectionsort.c` | Algoritmo Selection Sort com análise de complexidade |

### Hash

| Arquivo | Descrição |
|---|---|
| `TabelasHash.c` | Implementação de tabela hash com tratamento de colisões |

### Árvores

| Arquivo | Descrição |
|---|---|
| `ArvoreBinaria.c` | Árvore binária didática com percursos pré-ordem, em-ordem e pós-ordem |

### Fundamentos

| Arquivo | Descrição |
|---|---|
| `Passagem-parametro.c` | Passagem por valor vs. passagem por referência (ponteiros) |

### Threads e Processos

| Pasta | Descrição |
|---|---|
| `Criando-Thread-Processos/` | Introdução a concorrência com threads em C (pthreads) |

---

## 🧠 Objetivo

Este repositório não é apenas uma coleção de código — é um diário de aprendizado. Cada implementação foi feita do zero com o objetivo de entender o que acontece na memória, como os dados se organizam e por que certas estruturas são mais eficientes em determinados contextos.

---

## 🛠️ Como compilar e rodar

Você precisa ter o `gcc` instalado. Em qualquer distribuição Linux:
```bash
# Compilar
gcc NomeDoArquivo.c -o programa

# Rodar
./programa
```

Para arquivos com threads:
```bash
gcc arquivo.c -o programa -lpthread
./programa
```

---

## 📖 O que aprendi

- Como ponteiros realmente funcionam na memória
- Diferença prática entre alocação estática e dinâmica (`malloc`, `free`)
- Por que listas encadeadas existem e quando usar em vez de arrays
- Como pilhas e filas modelam problemas reais
- Como árvores organizam dados hierarquicamente e os três percursos clássicos
- Fundamentos de concorrência com threads POSIX

---

## 🚀 Próximos passos

- [x] Implementar árvore binária didática com percursos
- [ ] Implementar árvore binária de busca (BST) com inserção automática
- [ ] Implementar árvore AVL com balanceamento
- [ ] Implementar grafos com BFS e DFS
- [ ] Adicionar análise de complexidade em cada estrutura
- [ ] Reescrever as estruturas principais em Rust para comparação

---

## 🔗 Outros repositórios

- [Meu-Rust-start](https://github.com/Daniel/Meu-Rust-start) — Aprendizado de Rust com foco em sistemas de baixo nível

---

## 👤 Autor

**Daniel** — Estudante de Engenharia de Software (3º semestre)  
Apaixonado por baixo nível, sistemas operacionais e Rust.