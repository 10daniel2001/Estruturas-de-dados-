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
