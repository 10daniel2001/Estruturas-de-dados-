# ⚙️ Processos e Threads em C

Repositório dedicado ao estudo de concorrência e comunicação com o sistema operacional em C. Aqui exploro como o SO gerencia processos e como múltiplas threads compartilham recursos de forma segura.

> *“Para entender sistemas operacionais de verdade, você precisa sujar as mãos com fork, exec e mutex.”*

-----

## 🗂️ Projetos

### 🔀 Processos (`Processos.c`)

Demonstração de criação de processos filhos usando `fork()` e substituição de imagem com `execve()`.

**O que faz:**

- Cria 3 processos filhos sequencialmente com `fork()`
- Cada filho executa um programa diferente do sistema via `execve()`
- O processo pai aguarda cada filho terminar com `waitpid()`

**Conceitos praticados:**

- `fork()` — duplica o processo atual em pai e filho
- `execve()` — substitui a imagem do processo filho por outro programa
- `waitpid()` — processo pai espera o filho terminar (evita processos zumbi)
- Passagem de `envp[]` — variáveis de ambiente do sistema

```bash
gcc Processos.c -o processos
./processos
```

-----

### 🔒 Threads com Mutex (`Threads-mutex.c`)

Demonstração do problema de race condition e como resolvê-lo com mutex.

**O que faz:**

- Cria 2 threads que incrementam um contador compartilhado 100x cada
- Usa `pthread_mutex_lock` e `pthread_mutex_unlock` para proteger o acesso
- Resultado sempre correto: **200** — graças ao mutex

**Por que mutex importa:**
Sem o mutex, as duas threads acessariam `contador++` ao mesmo tempo. Como essa operação não é atômica (é leitura + soma + escrita), o resultado seria imprevisível — às vezes 180, às vezes 195, raramente 200. O mutex garante que apenas uma thread por vez modifica o contador.

**Conceitos praticados:**

- `pthread_create()` — cria uma thread
- `pthread_join()` — aguarda a thread terminar
- `pthread_mutex_init/lock/unlock` — controle de acesso a recursos compartilhados
- Race condition e como evitá-la

```bash
gcc Threads-mutex.c -o threads -lpthread
./threads
# Saída esperada: Valor final do contador: 200
```

-----

## 🧠 Por que isso é importante

Processos e threads são a base de qualquer sistema operacional. Entender como o kernel cria e gerencia processos, e como threads competem por recursos, é essencial para:

- Desenvolver sistemas embarcados e de tempo real
- Entender como servidores web atendem múltiplas requisições
- Escrever código seguro em ambientes concorrentes
- Contribuir com o kernel Linux ou sistemas similares

-----

## 📖 O que aprendi

- Como o `fork()` realmente funciona na memória — pai e filho têm espaços separados
- Por que `execve()` substitui a imagem do processo em vez de criar um novo
- O que é uma race condition e por que é difícil de debugar
- Como mutex resolve o problema de acesso concorrente
- A diferença prática entre processos (memória separada) e threads (memória compartilhada)

-----

## 🚀 Próximos passos

- [ ] Implementar comunicação entre processos com `pipe()`
- [ ] Explorar semáforos como alternativa ao mutex
- [ ] Implementar um pool de threads simples
- [ ] Estudar deadlock e como evitá-lo
- [ ] Explorar o mesmo conceito em Rust com `std::thread` e `Arc<Mutex<>>`

-----

## 🔗 Outros repositórios

- [Estruturas-de-dados em C](https://github.com/10daniel2001/Estruturas-de-dados-) — Base de dados e memória em C
- [Meu-Rust-start](https://github.com/10daniel2001/Meu-Rust-start) — Próximo passo: concorrência segura em Rust

-----

## 👤 Autor

**Daniel** — Estudante de Engenharia de Software (3º semestre)  
Foco em sistemas de baixo nível, SO e concorrência.

[![GitHub](https://img.shields.io/badge/GitHub-10daniel2001-black?logo=github)](https://github.com/10daniel2001)