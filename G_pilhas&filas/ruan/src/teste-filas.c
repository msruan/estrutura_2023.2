#include "../include/fila_do_livro.h"

void mostrarSemPoparVetorCHEIO(Fila fila){
    printf("\n*** Itens do vetor: [");
    for(int i = 0; i < fila->max; i++){
        printf("%c",fila->item[i]);
    }printf("] *** \n\n");
}

void mostrarPopandoVetor(Fila fila){
    printf("\n*** Itens do vetor: [");
    while(!isEmpty(fila) == 1){
        printf("%c",pop(fila));
    }printf("] *** \n\n");
}


int main() {
    printf("mostra algo krl");
    Fila fila = gerarFila(5);
    getStatus(fila,"antes do push");
    push('c',fila);
    push('o',fila);
    push('r',fila);
    push('t',fila);
    push('e',fila);
    mostrarSemPoparVetorCHEIO(fila);
    printf("%c",pop(fila));
    push('m',fila);
    mostrarSemPoparVetorCHEIO(fila);
    pop(fila);
    push('a',fila);
    mostrarSemPoparVetorCHEIO(fila);
    mostrarPopandoVetor(fila);
    // printf("A porra da letra é %d",fila->item[0]);
    // getStatus(fila,"dps do pop");
    // push('p',fila);
    // mostrarSemPoparVetorCHEIO(fila);
    kill(fila);
}