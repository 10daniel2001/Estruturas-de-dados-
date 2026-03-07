# Execução de Programas com `fork()` e `execve()` em C

## Descrição

Este programa em C demonstra como criar processos filhos no Linux utilizando `fork()` e executar programas externos usando `execve()`.

O processo principal cria **três processos filhos**, e cada filho executa um programa diferente do sistema:

* `xcalc`
* `brave`
* `gedit`

O processo pai aguarda a finalização de cada filho usando `waitpid()` antes de continuar a execução.

---

## Conceitos Utilizados

### `fork()`

Cria um novo processo (processo filho).

Retorno da função:

| Valor retornado | Significado                            |
| --------------- | -------------------------------------- |
| `0`             | Estamos no processo filho              |
| `>0`            | Estamos no processo pai (PID do filho) |
| `<0`            | Erro ao criar processo                 |

---

### `execve()`

Substitui o processo atual por outro programa.

Estrutura:

```
execve(caminho_do_programa, argumentos, ambiente)
```

Exemplo:

```
char *args[] = {"gedit", NULL};
execve("/usr/bin/gedit", args, envp);
```

Se `execve()` for executado com sucesso, **o código após ele não é executado**, pois o processo passa a ser o novo programa.

---

### `waitpid()`

Permite que o processo pai espere o término de um processo filho.

```
waitpid(pid, NULL, 0);
```

Isso evita que vários processos rodem ao mesmo tempo sem controle.

---

## Fluxo de Execução

```
Programa inicia
      │
      ├─ fork() → filho 1 executa xcalc
      │
      ├─ fork() → filho 2 executa brave
      │
      └─ fork() → filho 3 executa gedit
```

Cada processo filho executa um programa diferente.

---

## Código

```c
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char *envp[]) {

    int i, pid;

    for (i = 1; i <= 3; i++) {

        pid = fork();

        if (pid == 0) {

            if (i == 1) {
                char *args[] = {"xcalc", NULL};
                execve("/usr/bin/xcalc", args, envp);
            }

            if (i == 2) {
                char *args[] = {"brave", NULL};
                execve("/usr/bin/brave", args, envp);
            }

            if (i == 3) {
                char *args[] = {"gedit", NULL};
                execve("/usr/bin/gedit", args, envp);
            }

            perror("Erro no execve");
            return 1;
        }
        else {
            waitpid(pid, NULL, 0);
        }
    }

    return 0;
}
```

---

## Compilação

```
gcc programa.c -o programa
```

---

## Execução

```
./programa
```

---

## Observação

Os caminhos dos programas podem variar dependendo da distribuição Linux. Para verificar:

```
which xcalc
which brave
which gedit
```

Use o caminho retornado no `execve()`.

========================================================================================

# C Threads + Mutex Example

Exemplo simples de concorrência em C usando POSIX threads.

## Conceitos demonstrados

- Threads
- Seção crítica
- Race condition
- Mutex (mutual exclusion)

## Como compilar

gcc main.c -o programa -pthread

## Como executar

./programa

## Explicação

Duas threads incrementam uma variável compartilhada (contador).
O mutex garante que apenas uma thread acesse o contador por vez.