/*Para fins de estudo e consolidando meus aprendizados estou aprendendo Processos e Threads
  Exemplos simples de Threads com mutex lock e unlock 
  Como eu disse isso e conhecimento e apredizado!

 */

#include <stdio.h>
#include <pthread.h>

int contador = 0;
pthread_mutex_t mutex;

void* tarefa(void* arg) {

    for (int i = 0; i < 100; i++) {

        pthread_mutex_lock(&mutex);
        contador++;
        pthread_mutex_unlock(&mutex);

    }

    return NULL;
}

int main() {

    pthread_mutex_init(&mutex, NULL);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, tarefa, NULL);
    pthread_create(&t2, NULL, tarefa, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Valor final do contador: %d\n", contador);

    return 0;
}