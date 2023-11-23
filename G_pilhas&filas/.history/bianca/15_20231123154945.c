#include "pilha.h"
#include "fila.h"
#include <ctype.h>

int main(){
    // char frase[200];
    char frase[] = "Amor a roMa";
    Fila f = fila(200);
    Pilha p  = pilha(200);
    fgets(frase,stdin);

    // printf("Frase: ");

    for(int i = 0;frase[i] != '\0';i++){
        if(isalpha(frase[i])){
            // enfileira(frase[i],f);
            enfileira(toupper(frase[i]),f);
            // empilha(frase[i],p);
            empilha(toupper(frase[i]),p);
        }
    }
    while(!emptyf(f) && desinfileira(f)==desempilha(p));

    if(emptyf(f)){
        puts("e palindroma");
    }else{
        puts("nao e palindroma");
    }
    free(p);
    free(f);
}