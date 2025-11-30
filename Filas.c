
           /*  INTRODUÇAO A FILAS 
              CONCEITOS E ENTENDIMENTOS

              Fila significa o primeiro a entrar e o primeiro a sair FIFO (First in, first out)
              Inserir = enqueue !
              Retirar = dequeue !
              LOGICA CIRCULAR - Para atualizar a fila sua estrtura e F->fim = (F->fim + 1) % max; F-> total++ para incrementar
              Incrementar - serve para adicionar mais uma indice ao final apos adicionar mais um elemento !
              Para retira tem quer seguir o FiFO retire o primeiro que entrou 
              PEEK - verificaçao sem remoçao apenas para visualizar           
           
           */

#include <stdio.h>
#include <stdlib.h>

           #define max 5  // constante com numero fixo 

      // O primeiro passo para utilizar uma fila com mais significado é definir o tipo de dado que será armazenado.
      // No nosso exemplo, cada item da fila representa uma pessoa

      typedef struct // struct do elemento 
      {
         char nome[50];
         int idade;
      }Pessoa;

      // A struct Fila guarda os dados e controla o estado da fila com índices e contador de elementos.
      typedef struct // struct da fila
      {
         Pessoa itens[max];
         int inicio;  // inicio do indice
         int fim;     // fim do indice
         int total;  // total de elementos no vetor
      }Fila;
      

      //  inicializar a fila e sempre necessario para o programar rodar seguro 
     // Antes de usar a fila, seus índices e contador precisam ser configurados, como podemos ver
      void inicializar(Fila *f){
         f->inicio = 0;
         f->fim = 0;
         f->total = 0;
      }

      // verificar se a fila esta cheia, sempre importante !
      int filacheia(Fila *f){
         return f->total == max; // encerra o programa se estiver cheia
      }
      // Fila cheia impede novas inserções. Logo, essa verificação evita sobreposição de dados. Fila vazia, por sua vez, impede remoções, 
      // o que é importante para evitar acesso a posições inválidas. 
      // Fazer tal verificação também confirma se há elementos disponíveis para remoção
      // Verificar se a fila esta vazia sempre importante !
      int filavazia(Fila *f){
         return f->total == 0; // encerra o programa se a fila estiver vazia sem nada !
      }


                        // Inserir ENQUEUE
                        // Enqueue adiciona um novo item ao final da fila, se houver espaço !
                        void enqueue(Fila *f, Pessoa p){
                              if (f->total == max){  // verifica se a fila esta cheia, se sim encerra o programa!
                                 printf("Fila esta cheia erro\n");
                                 return;
                              }

                              f->itens[f->fim] = p;  // Adicionando um novo item para o final
                              f->fim = (f->fim + 1) % max; // Atualizando a fila 
                              f->total++; // incrementa um novo indice !
                        }

                        // REMOVER DEQUEUE
                        // A remoção retorna o primeiro elemento e ajusta a posição de início da fila.
                        void dequeue(Fila *f, Pessoa *p){
                           if (filavazia(f)){
                              printf("Fila vazia nao e possivel remover\n");
                              return;
                           }
                           *p = f->itens[f->inicio]; // Remove o elemento mais antigo, o primeiro que entrou
                           f->inicio = (f->inicio + 1) % max; // atualiza para n haver espaço sobrando
                           f->total--; // Remove o espaco 
                        }

                        // MOSTRA FILA 
                        // Exibe na ordem que foram inserido !
                        // Essa funçao percorre desde o inicio ate o total de itens contido
                        void mostrar(Fila *f){
                           printf("Fila mostrar\n");
                           for (int i = 0, idx = f->inicio; i < f->total; i++, idx = (idx + 1) % max)
                           {
                              printf("%s --- %d \n", f->itens[idx].nome,f->itens[idx].idade);
                           }
                           printf("\n");
                        }

                        int main(){
                           Fila f;

                           inicializar(&f);   // -> incializando-funçao no main com & para obter o endereco
                            
                           Pessoa p1 = {"A", 0}; // inserindo dados para ser exibido
                           Pessoa p2 = {"B", 1}; 
                           Pessoa p3 = {"C", 2}; 
                           Pessoa p4 = {"D", 3}; 
                           Pessoa p5 = {"E", 4}; 


                           enqueue(&f ,p1);
                           enqueue(&f ,p2);
                           enqueue(&f ,p3);
                           enqueue(&f ,p4);
                           enqueue(&f ,p5);


                           mostrar(&f);

                           Pessoa remo;
                           dequeue(&f, &remo);

                           printf("pessoa removida %s - %d\n", remo.nome,remo.idade);

                           mostrar(&f);
                           return 0;
                        }



                                 

      