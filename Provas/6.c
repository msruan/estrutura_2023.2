#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INSERIR 1
#define MOSTRAR 2
#define SAIR 0

typedef struct lista {

    char letra[1];// 
    struct lista *prox;

} Lista;

Lista *novo = NULL;
Lista *inicio = NULL;
Lista *fim;
Lista *atual;
Lista *anterior;

void mostrarMenu();
void inserirLetraNoInicio(Lista *letra);
void novaLetra(char letra, Lista *prox);
void mostrar();

void limparConsoleEnter(char *msg);

int main(){

    int opcao;
    char letra[1];

    do {
        mostrarMenu();
        scanf("%d",&opcao);
        fflush(stdin);
        getchar();

        switch (opcao)
        {

            case INSERIR:

                puts("\nDigite uma letra: ");
                letra[0] = getchar();
                fflush(stdin);

                novaLetra(letra[0], NULL);

                inserirLetraNoInicio(novo);
                break;

            case MOSTRAR:

                if(inicio != NULL){
                    mostrar();
                    break;
                }
            
            default:
                printf("Opcao inválida! Tente novamente.\n");

        }
    limparConsoleEnter("\n\n<Enter?>");
    }while (opcao != SAIR);
    
}

void mostrarMenu(){

    printf("*** LETRAS ***\n");
    printf("1 - Inserir letra no início da Lista\n");

    if(inicio != NULL){
        printf("2 - Mostrar letras\n");
    }

    printf("0 - Sair\n");
    printf("\nDigite a opcao desejada\n>>> ");

}

void inserirLetraNoInicio(Lista *novo_inicio){

    novo_inicio->prox = inicio;
    inicio = novo_inicio;

}

void mostrar(){

    printf("As letras armazenadas são { ");
    atual = inicio;
    while(atual!=NULL){
        printf("'%c' ",atual->letra[0]);
        atual = atual->prox;
    }
    printf(" }\n");

}

void novaLetra(char letra, Lista *prox){

    novo = (Lista*)malloc(sizeof(Lista));
    novo->letra[0] = letra;
    novo->prox = prox;

}



void limparConsoleEnter(char *msg){

    printf("%s",msg);
    getchar();
    for(int i = 0; i < 12; i++){
        printf("\n");
    }

}

