class No {
    int valor;
    No proximo;

    No(int valor) {
        this.valor = valor;
        this.proximo = null;
    }
}

public class ListaLi {
    private No head;

    public void inserir(int valor) {
        No novo = new No(valor);

        if (head == null) {
            head = novo;
            return;
        }

        No atual = head;

        while (atual.proximo != null) {
            atual = atual.proximo;
        }

        atual.proximo = novo;
    }

    public void imprimir() {
        if (head == null) {
            System.out.println("Lista vazia");
            return;
        }

        No atual = head;

        while (atual != null) {
            System.out.print(atual.valor + " → ");
            atual = atual.proximo;
        }

        System.out.println("null");
    }

    public static void main(String[] args) {
        ListaLi lista = new ListaLi();  // ← faltava isso

        lista.inserir(10);
        lista.inserir(20);
        lista.inserir(30);

        lista.imprimir();
    }

}  