#include "../include/no.h"
#include <stdio.h>

int somar0(No no);
int somar1(No no);

int main() {

    No no = gerarNoP(1,gerarNoP(2,gerarNoP(3,gerarNo(4))));

    printf("\nSomar0 diz q a soma é igual a: %d",somar0(no));
    printf("\nSomar1 diz q a soma é igual a: %d\n\n",somar1(no));
    
    killNo(no);

}

int somar0(No no){

    if(no == NULL) return -RAND_MAX;

    int soma = 0;

    while(no != NULL){

        soma += no->item;
        no = no->prox;
    }
    return soma;
}

int somar1(No no) {

    if(no == NULL) return 0;
    
    return no->item + somar1(no->prox);
}
