// Codigo de refencia de aprendizado sem uso de IA para gerar pois preciso de entender e saber 
// E consolidar tudo que venho aprendendo !

// Código para fins didáticos
// Demonstração de passagem por valor e passagem por referência

#include <stdio.h>


// Passagem por valor: recebe uma cópia da variável.
// Alterações feitas aqui NÃO modificam a variável original.
void somar(int a) {
    a = a + 2;
    printf("Resultado dentro da função somar (valor): %d\n", a);
}

// Passagem por referência: recebe o endereço da variável.
// Permite modificar a variável original usando ponteiro.
void multiplicar(int *b) {
    *b = (*b) * 2;  // * acessa o valor armazenado no endereço
    printf("Resultado dentro da função multiplicar (referência): %d\n", *b);
}

int main() {
    int numero = 15;  // valor original da variável

    printf("Valor inicial: %d\n", numero);

    somar(numero);        // não modifica a variável original
    printf("Após somar (fora da função): %d\n", numero);

    multiplicar(&numero); // modifica a variável original
    printf("Após multiplicar (fora da função): %d\n", numero);

    return 0;
}