#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct no{
    int item;
    struct no *prox;
}Lista;

Lista *no(int item, Lista*inicio){
    Lista *saida = (Lista*)malloc(sizeof(Lista));
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

void destruir(Lista *lista){
    Lista *prox;
    while(lista!=NULL){
      prox = lista->prox;
      free(lista);
      lista=prox;
    }
}
int ultimo(Lista *lista){
    while(lista!=NULL){
        if(lista->prox == NULL)
            return lista->item;
        lista = lista->prox;
    }return -1;
}
int somarI(Lista *lista){
    int soma = 0;
    while(lista!=NULL){
        soma += lista->item;
        lista = lista->prox;
    }return soma;
}
int contarOcorrenciasR(int item, Lista *lista){
    if(lista==NULL)
        return 0;
    return (lista->item == item ? 1 : 0) + contarOcorrenciasR(item,lista->prox);
}
int contarOcorrenciasI(int item, Lista *lista){
    int ocorrencias = 0;
    while(lista!=NULL){
        if(lista->item == item)
            ocorrencias++;
        lista = lista->prox;
    }
    return ocorrencias;
}

bool estaEm(int item, Lista *lista){
    if(lista==nullptr)
        return false;
    return lista->item == item || estaEm(item,lista->prox);
}
void mostrarInversa(Lista *lista){
    if(lista==NULL)
        return;
    mostrarInversa(lista->prox);
    printf("%d; ",lista->item);
}
int lenght(Lista *lista){
    if(lista == NULL)
        return 0;
    return 1 + lenght(lista->prox);
}
/*int* inverterArray(int tamanho,int *vetor){
    int *saida = (int *)malloc(sizeof(int)*tamanho);
    int index = 0;
    for(int i = tamanho-1; i>=0; --i){
        saida[index] = vetor[i];
    }return saida;
}*/
Lista *obterItemIndex(Lista *lista, int posicao){
    int i = 0;
    if(posicao < 0)
        return NULL;
    while(lista!=NULL){
        if(i == posicao){
            return lista;
        }lista = lista->prox;
        i++;
    }return NULL;
}
Lista *copia(Lista *lista){
    if(lista==NULL) return NULL;
    return no(lista->item,copia(lista->prox));
}

Lista* inverter(Lista *atual){
    int tamanho = lenght(atual);
    Lista *saida;
    int index_s = 0;
    for(int i = tamanho-1; i >= 0; i--){
        obterItemIndex(atual,)
    }
}

int somarR(Lista *lista){
    if(lista == NULL)
        return 0;
    return lista->item + somarR(lista->prox);
}

int main(){
    Lista *lista = no(8,no(5,NULL));
    printf("\nSoma: %d",somarR(lista));
    destruir(lista);
    //mostra(lista);
}
