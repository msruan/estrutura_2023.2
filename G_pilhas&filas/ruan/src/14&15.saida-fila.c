#include "../include/fila_do_livro.h"
int main(){
    Fila F = gerarFila(5);
    for(int i = 0; i <= 3; i++)
        push('A'+i,F);

    while (!isEmpty(F)){
        printf("%c\n",pop(F));
    }
    kill(F);
    return 0;
}
/*  A saída será: 

    /=========\
    |    A    |
    |    B    | 
    |    C    |
    |    D    |
    \=========/

    A cada iteração do loop for da linha 4, vai se adicionando uma letra à fila, sendo esse char o resultado da soma do código ASCII de 'A' com o valor de i da iteração.
*/