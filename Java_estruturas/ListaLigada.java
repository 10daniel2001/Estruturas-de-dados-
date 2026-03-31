class No {
    int valor;
    No proximo;

    NO (int valor){
        this.valor = valor;
        this.proximo = null;
    }
}

      public class ListaLi {
        private No head;

         
             public void inserir(int valor){
                No novo = new No(valor);

                if (head == null){
                    head = novo;
                    return;
                }

                No atual = head;

             

             }
      }