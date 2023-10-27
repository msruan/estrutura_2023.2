#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int item;
    struct no* prox;   
}No;

No *novoNo(int item, No* prox){
    No* novo = (No*)malloc(sizeof(No));
    novo->item = item;
    novo->prox = prox;
    return novo;
}

void inserirNoInicio00(No**inicio, No *novo) {
    if(*inicio == NULL){
        *inicio = novo;
        return;
    }
    novo->prox = *inicio;
    *inicio = novo;
}

No *inserirNoInicio01(No* inicio, No *novo) {
    if(inicio == NULL){
        return novo;
    }
    novo->prox = inicio;
    return novo;
}

No *inserirNoFinal(No *inicio, No *novo){

    if(inicio == NULL) 
        return novo;
        
    No *atual = inicio;
    while(atual->prox!=NULL)
        atual=atual->prox;
    atual->prox = novo;
    return inicio;

}

No *clonarNo(No* no){
    return novoNo(no->item,NULL);
}

No *clonarLista(No *inicio){
    No *nova;
    while(inicio != NULL) {
        inserrirNoFI
    }
}


No *inverter(No* inicio) {
    No *inversa;
    while(inicio != NULL){
        inversa = inserirNoInicio01(inversa,clonarNo(inicio));
    }return inversa;
}

int main(){
    No *inicio = novoNo(1);
}