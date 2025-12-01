#include <stdlib.h>
#include <stdio.h>
   
   /*PILHAS  
     Pilhas e baseada no conceito de LIFO last in first out -> Ultimo a entrar primeiro a sair

     PUSH - inserir
     REMOVER - Pop
     CONSULTAR TOPO - Peek
     LIBERAR - Free -> caso seja alocaçao dinamica e nao estatica



     Pilhas são estruturas de dados fundamentais que seguem o princípio LIFO, o que resulta em um comportamento 
     reverso ao das filas. Isso as torna úteis em contextos nos quais queremos desfazer ações,
     controlar chamadas de funções, converter expressões matemáticas ou navegar entre páginas em um navegador.
     */

       
                #define max 5

                typedef struct 
                {
                    char nome[49];
                    int idade;
                }Pessoa;
                
                typedef struct 
                {
                    Pessoa itens[max];
                    int topo;
                }Pilha;
                
                // INICIALIZAR PILHA
                // A atribuição de -1 ao topo é uma convenção que facilita a verificação de vazios e inserções futuras.
                // A pilha deve ser inicializada com o valor de topo = -1, indicando que está vazia. Veja!
                void incializarpilha(Pilha *p){
                    p->topo = -1;
                }

                // VERIFICAR SE A PILHA ESTA VAZIA
                // O valor retorna verdadeiro (1) se o topo for igual a -1.
                // A verificação evitar remoções em uma pilha já vazia, o que causaria erro
                int pilha_vazia(Pilha *p){
                    return p->topo == -1;
                }

                // VERIFICAR SE A PILHA ESTA CHEIA
                //O valor retorna verdadeiro (1) se o topo estiver no último índice possível do vetor
                int Pilha_cheia(Pilha *p){
                    return p->topo == max -1;
                }

                // INSERIR (PUSH)
                // Push é uma operação rápida e eficiente, com complexidade constante (O(1)).
                void push(Pilha *p, Pessoa n){
                      if (Pilha_cheia(p)){
                        printf("Pilha cheia nao pode adicionar\n");
                        return;
                      }
                      p->topo++;  // incrementando o topo para apontar para a próxima posição livre.
                      p->itens[p->topo] = n; // Adiciona o novo elemento nesse espaço
                }

                // REMOVER (POP)
                // A função copia o conteúdo do topo para o ponteiro removido, e então reduz o topo

                void pop(Pilha *p, Pessoa *r){
                    if(pilha_vazia(p)){  // Verificaçao por segurança, caso a pilha esteja vazia 
                        printf("Pilha vazia nada para remover\n");
                        return;
                    }
                    *r = p->itens[p->topo];  // Armazena o topo da pilha a ser removido em *r
                    p->topo--;  // Decremento para reduzir o espaço vazio (do elemento que foi removido)
                }


                // VISUALIZAR (PEEK)
                // Consulta sem remover ou adicionar
                // A função é muito útil quando queremos saber quem é o último elemento inserido, mas sem o alterar.
                void peek(Pilha *p, Pessoa *v){
                         if(pilha_vazia(p)){ // Verificaçao de segurança caso a pilha esteja vazia 
                            printf("Pilha vazia sem elementos para visualizar\n");
                            return;
                         }
                       *v = p->itens[p->topo]; // *v e armazenado uma cópia do topo da pilha
                }


                // MOSTRAR PILHA
                // Comeca do topo para o primeiro inserido 
                // util para visualizar 
                void Mostrar(Pilha *p){
                     printf("Pilha-Topo -> Base\n");
                     for (int i = p->topo; i >= 0; i--) 
                     {
                        printf("%s -- %d\n", p->itens[i].nome, p->itens[i].idade);
                     }
                     printf("\n");
                }

                int main(){
                    Pilha p;
                    incializarpilha(&p);

                    Pessoa p1 = {"A", 0};
                    Pessoa p2 = {"B", 1};
                    Pessoa p3 = {"C", 2};
                    Pessoa p4 = {"D", 3};
                    Pessoa p5 = {"E", 4};

                    push(&p, p1);
                    push(&p, p2);
                    push(&p, p3);
                    push(&p, p4);
                    push(&p, p5);

                    Mostrar(&p);

                    Pessoa Rem;
                    pop(&p, &Rem);
                    printf("Removida %s - %d\n", Rem.nome, Rem.idade);

                    Mostrar(&p);
                       
                     Pessoa v;
                     peek(&p, &v);
                     printf("Visualizar topo atual -> %s - %d\n", v.nome,v.idade);

                     return 0;

                }



