#include <stdlib.h>
#include <stdio.h>

typedef struct no{
    int item;
    struct no *prox;
}Lista;

Lista *no(int item, Lista*inicio){
    Lista *saida = malloc(sizeof(Lista));
    saida->item = item;
    saida->prox = inicio;
    return saida;
}

void mostra(Lista *inicio){
    if(inicio==NULL)
        printf("Empty list");
    for(Lista*i = inicio; i!=NULL; i=i->prox){
        printf("item: %d\n",i->item);
    }
}

void anexar(Lista**a,Lista*b){
    if(a == NULL){
        *a = b;
    }else if(b!=NULL){
        for(;(*a)->prox != NULL;a = &( (*a)->prox))
        ;
        (*a)->prox = b;
    }
}

/*void destruir(Lista **lista){
    Lista *atual = *lista, *proximo = (atual == NULL ? NULL : atual->prox);
    while(atual != NULL){
        free(atual);
        atual = proximo;
        proximo = atual == NULL ? NULL : atual->prox;
    }*lista= NULL;
}*/
void destruir(Lista **lista){
    for(Lista *prox; *lista != NULL; *lista = prox){
        if(*lista == NULL)
            continue;
        prox = (*lista)->prox;
        free(*lista);
        *lista = prox;   
    }
}
/*void destruir(Lista **lista){
    for(Lista *n;*lista!=NULL;free(n)){
        n = *lista;
        *lista = n->prox;
    }
}*/
    /*
    if((*lista)->prox==NULL){
        free(lista);
        *lista = NULL;
    }
    else if((*lista)->prox == NULL) 
        free((*lista)->prox);
    else
        destruir(&((*lista)->prox)); 
    */

int main(){
    Lista *lista = no(8,no(5,no(9,no(3,no(43,no(56,no(6,NULL)))))));
    destruir(&lista);
    mostra(lista);
}
