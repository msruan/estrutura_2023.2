#include "pilha.h"

void ordena(Pilha A, Pilha B){
    int valor,qtd;
    printf("Quantidade de numeros: ");
    scanf("%d", &qtd);

    for(int i =0; i<qtd;i++){
        printf("Numero: ");
        scanf("%d", &valor);
        if(i==0){// se for o primeiro item, empilha na A
            empilha(valor,A);
        }else{
            if(valor< getTopo(A)){// caso o valor seja menor que o topo, empilha na A
                empilha(valor,A);
            }else{
                while(!emptyp(A) && getTopo(A) < valor){// caso a pilha nao esteja vazia e o valor novo for maior que o topo
                    empilha(desempilha(A),B);// tira da pilha A, e coloca na B
                }

                empilha(valor,A);
                while (!emptyp(B)) {
                    empilha(desempilha(B), A);//se a pilha tiver vazia, ele coloca o novo item e depois desempilha os itens da B
            }
        }
    }
    }
}

int main(){
    
    Pilha A = pilha(100);
    Pilha B = pilha(100);

    ordena(A,B);
    // printf("Elementos ordenados:\n");
    while (!emptyp(A)) {
        printf("%d\n",desempilha(A));
    }

    killp(A);
    killp(B);
    return 0;
}