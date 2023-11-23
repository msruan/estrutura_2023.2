#include "stdio.h"
#include "../include/pilha_do_livro.h"

void mostrarMuitaCoisa();

//Qual a saída exibida pelo programa a seguir? Por quê?
int main() {
    
    Pilha P = gerarPilha(3);
    push(1,P);
    push(2,P);

    //mostrarMuitaCoisa(); //-> se for chamado aqui, o 21 continua não aparecendo
    printf("%d",pop(P));
    printf("%d",pop(P));
    //mostrarMuitaCoisa(); //-> 21 aparece

    //fflush(stdout); //-> outra alternativa
    printf("%d",pop(P));
    kill(P);

    return 0;
}

/* R - A saída será "Aborted (core dumped)". Não há nada para ser retornado no pop da linha 14, então o programa chama a função abort.
 Apesar de a chamada da função printf estar correta nas linhas 11 e 12,
 e se esperar que seja mostrado o número 21 no console, o fluxo de saída (stdout) de C geralmente possui um buffer, que espera que um determinado tamanho seja
 atingido ou uma liberação explicítica seja chamada para enviar as mensagens pro console, e portanto apenas "Aborted (core dumped)" é mostrado.
 Uma solução para forçar "21" a sair antes da chamada de abort, é esvaziar o buffer de saída antes de realizar o pop inválido.
*/


void mostrarMuitaCoisa() {
    char nulo = ' ';
    for(int i = 0; i < 10000; i++){
        printf("%c",nulo);
    }
}