#include "../include/no.h"

No gerarNo(Item item) {

    No novo_no = (No)malloc(sizeof(struct no));
    novo_no->item = item;
    novo_no->prox = NULL;
}

No gerarNoP(Item item, No prox) {

    No novo_no = (No)malloc(sizeof(struct no));
    novo_no->item = item;
    novo_no->prox = prox;
}

int sizeNo(No no){

    if(no == NULL) return 0;
    return 1 + sizeNo(no->prox);
}

void killNo(No no){

    if(no == NULL) return;
    killNo(no->prox);
    free(no);
}
No inverterNo(No anterior, No atual) {

    if(atual != NULL){

        if(atual->prox==NULL){
            atual->prox = anterior;
            return atual;
        } 

        else {

           No inicio = inverterNo(atual,atual->prox);
            atual->prox = anterior;
            return inicio;

        }
    
    }return NULL;
    
    
}