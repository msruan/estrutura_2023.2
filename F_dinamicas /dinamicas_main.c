#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{

    char *nome;
    int matricula;
    struct no* prox;

}Aluno;

Aluno *novoNo(char *nome, int matricula, Aluno* prox);
Aluno *clonarNo(Aluno* no);

void consultar(Aluno *inicio, int matricula);

void inserirNoInicio00(Aluno**inicio, Aluno *novo);
Aluno *inserirNoInicio01(Aluno*inicio, Aluno *novo);

Aluno *inserirNoFinal00(Aluno *inicio, Aluno *novo);
void *inserirNoFinal01(Aluno **inicio, Aluno *novo);

void remover (Aluno** inicio, int matricula);
void mostrar(Aluno *no);
void listar(Aluno *no);

Aluno *inverter00(Aluno* inicio);
Aluno *inverter01(Aluno* anterior, Aluno *atual);

void liberar(Aluno* inicio);

int main(){

    Aluno *inicio = novoNo("Bianca",2,novoNo("Herminio",3,novoNo("Livia",4,novoNo("Patrocinio",5,novoNo("Ruan",6,NULL)))));
    inserirNoFinal01(&inicio,novoNo("Ryan",7,NULL));
    inserirNoInicio00(&inicio,novoNo("Antonio Meireles",1,NULL));
    inicio = inverter01(NULL,inicio);
    //mostrar(inicio);
    listar(inicio);
    //listar(inversa);
    liberar(inicio);
    //liberar(inversa);

}

Aluno *novoNo(char *nome, int matricula, Aluno* prox){

    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));

    if(nome != NULL){
        novo->nome = malloc( sizeof(char)* (strlen(nome)+1) );
        strcpy(novo->nome,nome);

    }else {
        novo->nome = malloc( sizeof(char)* (strlen("Desconhecido")+1) );
        strcpy(novo->nome,"Desconhecido");
    }
    
    novo->matricula = matricula;
    novo->prox = prox;
    return novo;

}

Aluno *clonarNo(Aluno* no) {
    if(no != NULL)
        return novoNo(no->nome,no->matricula,NULL);
    else
        return NULL;
}

void consultar(Aluno *inicio, int matricula) {

    printf("Buscando aluno...\n\n");
    for( ; inicio!=NULL; inicio = inicio->prox) {

        if(inicio->matricula == matricula) {
            printf("Matricula: %d\n", inicio->matricula);
            printf("Nome: %s\n",(inicio->nome != NULL ? inicio->nome : "Não informado") );
        }

    }printf("\nAluno não encontrado!");
    
}

void inserirNoInicio00(Aluno**inicio, Aluno *novo) {
    if(*inicio == NULL){
        *inicio = novo;
        return;
    }
    novo->prox = *inicio;
    *inicio = novo;
}

Aluno *inserirNoInicio01(Aluno* inicio, Aluno *novo) {
    if(inicio == NULL){
        return novo;
    }
    novo->prox = inicio;
    return novo;
}

Aluno *inserirNoFinal00(Aluno *inicio, Aluno *novo){

    if(inicio == NULL) 
        return novo;
        
    Aluno *atual = inicio;
    while(atual->prox!=NULL)
        atual=atual->prox;
    atual->prox = novo;
    return inicio;

}

void *inserirNoFinal01(Aluno **inicio, Aluno *novo){

    if(*inicio == NULL) 
        *inicio = novo;
        
    Aluno *atual = *inicio;
    while(atual->prox!=NULL)
        atual=atual->prox;
    atual->prox = novo;

}

void remover (Aluno** inicio, int matricula) {

    if( *inicio == NULL) return;

    else if( (*inicio)->matricula == matricula) {  
        liberar(*inicio);
        *inicio = NULL;
    }

    else if ( (*inicio)->prox != NULL){

        Aluno *i = *inicio;
        
        for(; i!=NULL ; i = i->prox) {

            if(i->prox->matricula == matricula) {
                i->prox = i->prox->prox;
            }
        }

    }

}

void mostrar(Aluno *no){
    if(no != NULL) {
        printf("Matricula: %d\n",no->matricula);
        printf("Nome: %s\n\n", no->nome);
    }
}

void listar(Aluno *no) {
    
    printf("\nAtençao para a chamada!\n\n");
    while (no!=NULL)
    {
        mostrar(no);
        no = no->prox;
    }
    
}



Aluno *inverter00(Aluno* inicio) {

    Aluno *inversa = NULL;
    while(inicio != NULL){
        //mostrar(inicio);
        inserirNoInicio00(&inversa,clonarNo(inicio));
        inicio = inicio->prox;
    }return inversa;
}

Aluno *inverter01(Aluno* anterior, Aluno *atual) {

    if(atual != NULL){

        if(atual->prox==NULL){
            atual->prox = anterior;
            return atual;
        } 

        else {

            Aluno *inicio = inverter01(atual,atual->prox);
            atual->prox = anterior;
            return inicio;

        }
    
    }return NULL;
    
    
}

void liberar(Aluno* inicio){
    if(inicio==NULL) return;
    liberar(inicio->prox);
    free(inicio->nome);
    free(inicio);
}